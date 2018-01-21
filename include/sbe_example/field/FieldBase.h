/// \file
/// \brief Contains definition of \ref sbe_example::field::FieldBase type.

#pragma once

#include "comms/Field.h"
#include "comms/options.h"

namespace sbe_example
{

namespace field
{

/// \brief Definition of common base class of all the fields.
using FieldBase = comms::Field<comms::option::LittleEndian>;

} // namespace field

} // namespace sbe_example

