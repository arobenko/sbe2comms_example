/// \file
/// \brief Contains definition of all the message classes bundled in std::tuple.

#pragma once

#include <tuple>

#include "DefaultOptions.h"
#include "sbe_example/message/Car.h"


namespace sbe_example
{

/// \brief All the protocol messages bundled in std::tuple.
/// \tparam TMsgBase Common base (interface) class of all the messages.
/// \tparam TOpt Extra options, expected to be of the same format as \ref DefaultOptions.
template <typename TMsgBase, typename TOpt = DefaultOptions>
using AllMessages = std::tuple<
    message::Car<TMsgBase, TOpt>
>;

} // namespace sbe_example

