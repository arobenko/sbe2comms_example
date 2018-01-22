/// \file
/// \brief Contains definition of \ref sbe_example::field::Model field.

#pragma once

#include "comms/field/EnumValue.h"

#include "FieldBase.h"

namespace sbe_example
{

namespace field
{

/// \brief Enumeration for \ref Model field.
enum class ModelVal : char
{
    A = static_cast<char>(65), ///< \b A value.
    B = static_cast<char>(66), ///< \b B value.
    C = static_cast<char>(67), ///< \b C value.
};

/// \brief Definition of "Model" field.
/// \tparam TOpt Extra options from \b comms::option namespace.
/// \see \ref ModelVal
template <typename... TOpt>
class Model : public
    comms::field::EnumValue<
        sbe_example::field::FieldBase,
        ModelVal,
        TOpt...,
        comms::option::DefaultNumValue<65>,
        comms::option::ValidNumValueRange<65, 67>
    >
{
    using Base =
        comms::field::EnumValue<
            sbe_example::field::FieldBase,
            ModelVal,
            TOpt...,
            comms::option::DefaultNumValue<65>,
            comms::option::ValidNumValueRange<65, 67>
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

