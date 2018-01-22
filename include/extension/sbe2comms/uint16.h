/// \file
/// \brief Contains definition of implicitly defined \ref extension::sbe2comms::uint16


#pragma once

#include <cstdint>
#include "comms/Field.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"

namespace extension
{

namespace sbe2comms
{

/// \brief Definition of built-in "uint16" type
/// \tparam TFieldBase Base class of the field type.
/// \tparam TOpt Extra options from \b comms::option namespace 
/// \headerfile "extension/sbe2comms/uint16.h"
template <typename TFieldBase, typename... TOpt>
struct uint16 : public
    comms::field::IntValue<
        TFieldBase,
        std::uint16_t,
        TOpt...,
        comms::option::ValidNumValueRange<0, 65534L>
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

} // namespace extension

