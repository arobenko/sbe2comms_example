/// \file
/// \brief Contains definition of \ref extension::field::OptionalExtras field.

#pragma once

#include "comms/field/BitmaskValue.h"

#include "FieldBase.h"

namespace extension
{

namespace field
{

/// \brief Definition of "OptionalExtras" field.
/// \tparam TOpt Extra options from \b comms::option namespace.
template <typename... TOpt>
class OptionalExtras : public
    comms::field::BitmaskValue<
        extension::field::FieldBase,
        TOpt...,
        comms::option::FixedLength<1>,
        comms::option::BitmaskReservedBits<0xf8>
    >
{
    using Base =
        comms::field::BitmaskValue<
            extension::field::FieldBase,
            TOpt...,
            comms::option::FixedLength<1>,
            comms::option::BitmaskReservedBits<0xf8>
        >;

public:
    /// \brief Provide names and convenience access functions for internal bits.
    /// \details See definition of \b COMMS_BITMASK_BITS_SEQ macro
    ///     related to \b comms::field::BitmaskValue class from COMMS library
    ///     for details.
    COMMS_BITMASK_BITS_SEQ(
        sunRoof,
        sportsPack,
        cruiseControl
    );

    /// \brief Update current message version.
    /// \details Does nothing.
    /// \return \b false to indicate nothing has changed.
    static bool setVersion(unsigned)
    {
        return false;
    }
};

} // namespace field

} // namespace extension

