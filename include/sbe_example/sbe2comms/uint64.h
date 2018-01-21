/// \file
/// \brief Contains definition of implicitly defined \ref sbe_example::sbe2comms::uint64


#pragma once

#include <cstdint>
#include "comms/Field.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"

namespace sbe_example
{

namespace sbe2comms
{

/// \brief Definition of built-in "uint64" type
/// \tparam TFieldBase Base class of the field type.
/// \tparam TOpt Extra options from \b comms::option namespace 
/// \headerfile "sbe_example/sbe2comms/uint64.h"
template <typename TFieldBase, typename... TOpt>
struct uint64 : public
    comms::field::IntValue<
        TFieldBase,
        std::uint64_t,
        TOpt...,
        comms::option::ValidBigUnsignedNumValueRange<0, 0xfffffffffffffffeLL>
    >
{
    /// \brief Update current message version.
    /// \details Does nothing.
    /// \return \b false to indicate nothing has changed.
    static bool setVersion(unsigned)
    {
        return false;
    }
};

} // namespace sbe2comms

} // namespace sbe_example

