/// \file
/// \brief Contains definition of implicitly defined \ref sbe_example::sbe2comms::float_


#pragma once

#include "comms/Field.h"
#include "comms/field/FloatValue.h"
#include "comms/options.h"

namespace sbe_example
{

namespace sbe2comms
{

/// \brief Definition of built-in "float" type
/// \tparam TFieldBase Base class of the field type.
/// \tparam TOpt Extra options from \b comms::option namespace 
/// \headerfile "sbe_example/sbe2comms/float.h"
template <typename TFieldBase, typename... TOpt>
struct float_ : public
    comms::field::FloatValue<
        TFieldBase,
        float,
        TOpt...
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

