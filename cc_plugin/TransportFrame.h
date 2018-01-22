#pragma once

#include "extension/TransportFrame.h"
#include "cc_plugin/Message.h"
#include "cc_plugin/AllMessages.h"

namespace extension
{

namespace cc_plugin
{

using MessageHeaderFrame = 
    extension::MessageHeaderFrame<
        cc_plugin::Message<>,
        cc_plugin::AllMessages
    >;

using OpenFramingHeaderFrame = 
    extension::OpenFramingHeaderFrame<
        cc_plugin::Message<>,
        cc_plugin::AllMessages
    >;

} // namespace cc_plugin

} // namespace extension

