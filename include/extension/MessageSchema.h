/// \file
/// \brief Contains compile time constants and types relevant to the schema.

#pragma once

#include "comms/traits.h"

#include "extension/field/messageHeader.h"
#include "extension/sbe2comms/openFramingHeader.h"

namespace extension
{

class MessageSchema
{
    /// \brief Endianness tag ussed by the COMMS library
    using Endian = comms::traits::endian::Little;

    /// \brief Message header field type
    using MessageHeader = extension::field::messageHeader;

    /// \brief Simple open framing header field type
    using SimpleOpenFramingHeader = extension::sbe2comms::openFramingHeader;

    /// \brief Version of the schema
    static const unsigned version()
    {
        return 1U;
    }

    /// \brief ID of the schema
    static const unsigned id()
    {
        return 1U;
    }
};

} // namespace extension

