/// \file
/// \brief Contains definition of \ref extension::MsgId enumeration.

#pragma once

#include <cstdint>

namespace extension
{

/// \brief Enumeration of message ID value.
enum MsgId : std::uint16_t
{
    MsgId_Car = 1, ///< ID of message \ref message::Car
}; // MsgId

} // namespace extension

