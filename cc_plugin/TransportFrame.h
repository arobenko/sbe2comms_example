#pragma once

#include "sbe_example/TransportFrame.h"
#include "cc_plugin/Message.h"
#include "cc_plugin/AllMessages.h"

namespace sbe_example
{

namespace cc_plugin
{

using MessageHeaderFrame = 
    sbe_example::MessageHeaderFrame<
        cc_plugin::Message<>,
        cc_plugin::AllMessages
    >;

using OpenFramingHeaderFrame = 
    sbe_example::OpenFramingHeaderFrame<
        cc_plugin::Message<>,
        cc_plugin::AllMessages
    >;

} // namespace cc_plugin

} // namespace sbe_example

