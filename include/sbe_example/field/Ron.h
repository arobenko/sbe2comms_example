/// \file
/// \brief Contains definition of \ref sbe_example::field::Ron field.

#pragma once

#include <cstdint>

#include "comms/field/IntValue.h"

#include "FieldBase.h"

#include <cstdint>

namespace sbe_example
{

namespace field
{

/// \brief Definition of "Ron" field.
/// \tparam TOpt Extra options from \b comms::option namespace.
template <typename... TOpt>
class Ron : public
    comms::field::IntValue<
        FieldBase,
        std::uint8_t,
        TOpt...,
        comms::option::ValidNumValueRange<90, 110>,
        comms::option::DefaultNumValue<90>
    >
{
    using Base =
        comms::field::IntValue<
            FieldBase,
            std::uint8_t,
            TOpt...,
            comms::option::ValidNumValueRange<90, 110>,
            comms::option::DefaultNumValue<90>
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

