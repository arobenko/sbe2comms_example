#pragma once

#include <tuple>

#include "cc_plugin/message/Car.h"

namespace sbe_example
{

namespace cc_plugin
{

using AllMessages =
    std::tuple<
        cc_plugin::message::Car
    >;

} // namespace cc_plugin

} // namespace sbe_example

