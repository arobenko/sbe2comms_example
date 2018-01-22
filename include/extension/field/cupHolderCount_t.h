/// \file
/// \brief Contains definition of \ref extension::field::cupHolderCount_t field.

#pragma once

#include <cstdint>

#include "comms/field/IntValue.h"
#include "comms/field/Optional.h"

#include "FieldBase.h"

#include <cstdint>

namespace extension
{

namespace field
{

/// \brief Definition of inner field of the optional \ref cupHolderCount_t field.
/// \tparam TOpt Extra options from \b comms::option namespace.
template <typename... TOpt>
class cupHolderCount_tField : public
    comms::field::IntValue<
        extension::field::FieldBase,
        std::uint8_t,
        TOpt...,
        comms::option::ValidNumValueRange<0, 254>,
        comms::option::ValidNumValue<255>,
        comms::option::DefaultNumValue<255>
    >
{
    using Base=
        comms::field::IntValue<
            extension::field::FieldBase,
            std::uint8_t,
            TOpt...,
            comms::option::ValidNumValueRange<0, 254>,
            comms::option::ValidNumValue<255>,
            comms::option::DefaultNumValue<255>
        >;

public:
    /// \brief Check the value is equivalent to \b nullValue.
    bool isNull() const
    {
        return Base::value() == static_cast<typename Base::ValueType>(255);
    }

    /// \brief Update field's value to be \b nullValue.
    void setNull()
    {
        Base::value() = static_cast<typename Base::ValueType>(255);
    }

    /// \brief Update current message version.
    /// \details Does nothing.
    /// \return \b false to indicate nothing has changed.
    static bool setVersion(unsigned)
    {
        return false;
    }
};

/// \brief Definition of "cupHolderCount_t" field.
/// tparam TOpt Extra options from \b comms::option namespace.
template <typename... TOpt>
struct cupHolderCount_t : public
    comms::field::Optional<
        cupHolderCount_tField<TOpt...>,
        comms::option::DefaultOptionalMode<comms::field::OptionalMode::Exists>
    >
{
    /// \brief Update current version.
    /// \return \b true if field's content has been updated.
    bool setVersion(unsigned val)
    {
        using Base = typename std::decay<decltype(toFieldBase(*this))>::type;
        bool updated = Base::field().setVersion(val);
        auto mode = comms::field::OptionalMode::Exists;
        if (val < 1U) {
            mode = comms::field::OptionalMode::Missing;
        }

        if (Base::getMode() != mode) {
            Base::setMode(mode);
            updated = true;
        }

        return updated;
    }
};

} // namespace field

} // namespace extension

