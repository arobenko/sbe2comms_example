/// \file
/// \brief Contains definition of implicitly defined \ref sbe_example::sbe2comms::groupList


#pragma once

#include <cstdint>
#include <type_traits>

#include "comms/Field.h"
#include "comms/field/ArrayList.h"
#include "comms/field/Optional.h"
#include "comms/options.h"
#include "comms/util/Tuple.h"

#include "VersionSetter.h"

namespace sbe_example
{

namespace sbe2comms
{

/// \brief Generic list type to be used to defaine a "group" list.
/// \tparam TFieldBase Common base class of all the fields.
/// \tparam TElement Element of the list, expected to be a variant of \b comms::field::Bundle.
/// \tparam TDimensionType Dimention type field with "blockLength" and "numInGroup" members.
/// \tparam TRootCount Number of root block fields in the element.
/// \tparam TOpt Extra options for the list class.
/// \headerfile "sbe_example/sbe2comms/groupList.h"
template <
    typename TFieldBase,
    typename TElement,
    typename TDimensionType,
    std::size_t TRootCount,
    typename... TOpt
>
struct groupList : public
    comms::field::ArrayList<
        TFieldBase,
        TElement,
        TOpt...
    >
{
    /// \brief Get length of serialised data.
    constexpr std::size_t length() const
    {
        using Base = typename std::decay<decltype(toFieldBase(*this))>::type;
        return TDimensionType::maxLength() + Base::length();
    }

    /// \brief Read field value from input data sequence.
    template <typename TIter>
    comms::ErrorStatus read(TIter& iter, std::size_t len)
    {
        TDimensionType dimType;
        auto es = dimType.read(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        auto count = dimType.field_numInGroup().value();
        auto remLen = len - dimType.length();
        for (decltype(count) idx = 0; idx < count; ++idx) {
            using IterType = typename std::decay<decltype(iter)>::type;
            using IterCategory = typename std::iterator_traits<IterType>::iterator_category;
            static_assert(
                std::is_copy_constructible<IterType>::value &&
                std::is_base_of<std::forward_iterator_tag, IterCategory>::value,
                "Used iterator type is not supported for read operation");
            IterType iterTmp(iter);
            auto blockLength = static_cast<std::size_t>(dimType.field_blockLength().value());
            if (remLen < blockLength) {
                return comms::ErrorStatus::NotEnoughData;
            }

            using Base = typename std::decay<decltype(toFieldBase(*this))>::type;
            Base::value().emplace_back();
            auto& lastElem = Base::value().back();
            comms::util::tupleAccumulate(lastElem.value(), false, VersionSetter(m_version));
            es = lastElem.template readUntil<TRootCount>(iterTmp, blockLength);
            if (es != comms::ErrorStatus::Success) {
                Base::value().pop_back();
                return es;
            }

            std::advance(iter, blockLength);
            remLen -= blockLength;

            es = lastElem.template readFrom<TRootCount>(iter, remLen);
            if (es != comms::ErrorStatus::Success) {
                Base::value().pop_back();
                return es;
            }

            remLen -= Base::value().back().template lengthFrom<TRootCount>();
        }

        return checkFailOnInvalid();
    }

    /// \brief Read field value from input data sequence without error check and status report.
    template <typename TIter>
    void readNoStatus(TIter& iter) = delete; // not supported

    /// \brief Write current field value to output data sequence.
    template <typename TIter>
    comms::ErrorStatus write(TIter& iter, std::size_t len) const
    {
        if (len < length()) {
            return comms::ErrorStatus::BufferOverflow;
        }

        writeNoStatus(iter);
        return comms::ErrorStatus::Success;
    }

    /// \brief Write current field value to output data sequence  without error check and status report.
    template <typename TIter>
    void writeNoStatus(TIter& iter) const
    {
        using Base = typename std::decay<decltype(toFieldBase(*this))>::type;
        TDimensionType dimType;
        auto& blockLengthVal = dimType.field_blockLength().value();
        using BlockLengthValType = typename std::decay<decltype(blockLengthVal)>::type;
        blockLengthVal = static_cast<BlockLengthValType>(TElement::template maxLengthUntil<TRootCount>());

        auto& numInGroupVal = dimType.field_numInGroup().value();
        using NumInGroupValType = typename std::decay<decltype(numInGroupVal)>::type;
        numInGroupVal = static_cast<NumInGroupValType>(Base::value().size());
        dimType.writeNoStatus(iter);

        Base::writeNoStatus(iter);
    }

    /// \brief Check validity of the field value.
    bool valid() const
    {
        using Base = typename std::decay<decltype(toFieldBase(*this))>::type;
        TDimensionType dimType;
        auto& blockLengthVal = dimType.field_blockLength().value();
        using BlockLengthValType = typename std::decay<decltype(blockLengthVal)>::type;
        blockLengthVal = static_cast<BlockLengthValType>(TElement::template maxLengthUntil<TRootCount>());

        auto& numInGroupVal = dimType.field_numInGroup().value();
        using NumInGroupValType = typename std::decay<decltype(numInGroupVal)>::type;
        numInGroupVal = static_cast<NumInGroupValType>(Base::value().size());
        return Base::valid() && dimType.valid();
    }

    /// \brief Get minimal length that is required to serialise field of this type.
    static constexpr std::size_t minLength()
    {
        return TDimensionType::minLength();
    }

    bool setVersion(unsigned value)
    {
        m_version = value;

        using Base = typename std::decay<decltype(toFieldBase(*this))>::type;
        auto& list = Base::value();
        bool updated = false;
        for (auto& elem : list) {
            updated = comms::util::tupleAccumulate(elem.value(), updated, VersionSetter(m_version));
        }
        return updated;
    }

private:
    struct NoFailOnInvalidTag {};
    struct FailOnInvalidTag {};

    comms::ErrorStatus checkFailOnInvalid() const
    {
        using Base = typename std::decay<decltype(toFieldBase(*this))>::type;
        static_assert(!Base::ParsedOptions::HasFailOnInvalid,
            "comms::option::IgnoreInvalid option is not supported for \"groupList\"");
        using Tag = typename std::conditional<
            Base::ParsedOptions::HasFailOnInvalid,
            FailOnInvalidTag,
            NoFailOnInvalidTag>::type;
        return checkFailOnInvalid(Tag());
    }

    static comms::ErrorStatus checkFailOnInvalid(NoFailOnInvalidTag)
    {
        return comms::ErrorStatus::Success;
    }

    comms::ErrorStatus checkFailOnInvalid(FailOnInvalidTag) const
    {
        using Base = typename std::decay<decltype(toFieldBase(*this))>::type;
        if (!valid()) {
            return Base::ParsedOptions::FailOnInvalidStatus;
        }

        return comms::ErrorStatus::Success;
    }

    unsigned m_version = 1;
};

} // namespace sbe2comms

} // namespace sbe_example

