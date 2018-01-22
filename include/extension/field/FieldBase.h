/// \file
/// \brief Contains definition of \ref extension::field::FieldBase type.

#pragma once

#include "comms/Field.h"
#include "comms/options.h"

namespace extension
{

namespace field
{

/// \brief Definition of common base class of all the fields.
using FieldBase = comms::Field<comms::option::LittleEndian>;

} // namespace field

} // namespace extension

