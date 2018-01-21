/// \file
/// \brief Contains definition of \ref sbe_example::MsgId enumeration.

#pragma once

#include <cstdint>

namespace sbe_example
{

/// \brief Enumeration of message ID value.
enum MsgId : std::uint16_t
{
    MsgId_Car = 1, ///< ID of message \ref message::Car
}; // MsgId

} // namespace sbe_example

