/// \file
/// \brief Contains definition of \ref extension::field::groupSizeEncoding field.

#pragma once

#include <cstdint>

#include "comms/field/Bundle.h"
#include "comms/field/IntValue.h"
#include "comms/util/Tuple.h"

#include "FieldBase.h"
#include "extension/sbe2comms/VersionSetter.h"

#include <cstdint>

namespace extension
{

namespace field
{

/// \brief Scope for all the members of the \ref groupSizeEncoding field.
struct groupSizeEncodingMembers
{
    /// \brief Definition of "blockLength" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class blockLength : public
        comms::field::IntValue<
            extension::field::FieldBase,
            std::uint16_t,
            TOpt...,
            comms::option::ValidNumValueRange<0, 65534L>
        >
    {
        using Base =
            comms::field::IntValue<
                extension::field::FieldBase,
                std::uint16_t,
                TOpt...,
                comms::option::ValidNumValueRange<0, 65534L>
            >;

    public:
        /// \brief Update current message version.
        /// \details Does nothing.
        /// \return \b false to indicate nothing has changed.
        static bool setVersion(unsigned)
        {
            return false;
        }
    };

    /// \brief Definition of "numInGroup" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class numInGroup : public
        comms::field::IntValue<
            extension::field::FieldBase,
            std::uint16_t,
            TOpt...,
            comms::option::ValidNumValueRange<0, 65534L>
        >
    {
        using Base =
            comms::field::IntValue<
                extension::field::FieldBase,
                std::uint16_t,
                TOpt...,
                comms::option::ValidNumValueRange<0, 65534L>
            >;

    public:
        /// \brief Update current message version.
        /// \details Does nothing.
        /// \return \b false to indicate nothing has changed.
        static bool setVersion(unsigned)
        {
            return false;
        }
    };

    /// \brief Bundling all the defined member types into a single std::tuple.
    /// \tparam TOpt_blockLength Extra options for \ref blockLength from \b comms::option namespace.
    /// \tparam TOpt_numInGroup Extra options for \ref numInGroup from \b comms::option namespace.
    template<
        typename TOpt_blockLength = comms::option::EmptyOption,
        typename TOpt_numInGroup = comms::option::EmptyOption
    >
    using All = std::tuple<
        blockLength<TOpt_blockLength>,
        numInGroup<TOpt_numInGroup>
    >;
};

/// \brief Definition of "groupSizeEncoding" field.
/// \details Repeating group dimensions
/// \tparam TOpt_blockLength Extra options for \ref groupSizeEncodingMembers::blockLength from \b comms::option namespace.
/// \tparam TOpt_numInGroup Extra options for \ref groupSizeEncodingMembers::numInGroup from \b comms::option namespace.
template<
    typename TOpt_blockLength = comms::option::EmptyOption,
    typename TOpt_numInGroup = comms::option::EmptyOption
>
class groupSizeEncoding : public
    comms::field::Bundle<
        extension::field::FieldBase,
        groupSizeEncodingMembers::All<
            TOpt_blockLength,
            TOpt_numInGroup
        >
    >
{
    using Base =
        comms::field::Bundle<
            extension::field::FieldBase,
            groupSizeEncodingMembers::All<
                TOpt_blockLength,
                TOpt_numInGroup
            >
        >;

public:
    /// \brief Allow access to internal fields.
    /// \details See definition of \b COMMS_FIELD_MEMBERS_ACCESS macro
    ///     related to \b comms::field::Bundle class from COMMS library
    ///     for details.\n
    ///     The names are:
    ///     \li \b blockLength for \ref groupSizeEncodingMembers::blockLength.
    ///     \li \b numInGroup for \ref groupSizeEncodingMembers::numInGroup.
    COMMS_FIELD_MEMBERS_ACCESS(
        blockLength,
        numInGroup
    );

    /// \brief Update current message version.
    /// \details Calls setVersion() of every member.
    /// \return \b true if any of the fields returns \b true.
    bool setVersion(unsigned val)
    {
        return comms::util::tupleAccumulate(Base::value(), false, sbe2comms::VersionSetter(val));
    }
};

} // namespace field

} // namespace extension

