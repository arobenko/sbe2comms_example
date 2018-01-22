#pragma once

#include <tuple>

#include "cc_plugin/message/Car.h"

namespace extension
{

namespace cc_plugin
{

using AllMessages =
    std::tuple<
        cc_plugin::message::Car
    >;

} // namespace cc_plugin

} // namespace extension

