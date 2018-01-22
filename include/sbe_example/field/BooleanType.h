/// \file
/// \brief Contains definition of \ref sbe_example::field::BooleanType field.

#pragma once

#include "comms/field/EnumValue.h"

#include "FieldBase.h"

namespace sbe_example
{

namespace field
{

/// \brief Enumeration for \ref BooleanType field.
enum class BooleanTypeVal : std::uint8_t
{
    F = static_cast<std::uint8_t>(0), ///< \b F value.
    T = static_cast<std::uint8_t>(1), ///< \b T value.
};

/// \brief Definition of "BooleanType" field.
/// \tparam TOpt Extra options from \b comms::option namespace.
/// \see \ref BooleanTypeVal
template <typename... TOpt>
class BooleanType : public
    comms::field::EnumValue<
        sbe_example::field::FieldBase,
        BooleanTypeVal,
        TOpt...,
        comms::option::ValidNumValueRange<0, 1>
    >
{
    using Base =
        comms::field::EnumValue<
            sbe_example::field::FieldBase,
            BooleanTypeVal,
            TOpt...,
            comms::option::ValidNumValueRange<0, 1>
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

} // namespace field

} // namespace sbe_example

