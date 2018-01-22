#include "cc_plugin/MessageHeaderFramePlugin.h"
#include "cc_plugin/Protocol.h"

namespace cc = comms_champion;

namespace extension
{

namespace cc_plugin
{

MessageHeaderFramePlugin::MessageHeaderFramePlugin()
{
    pluginProperties()
        .setProtocolCreateFunc(
            [this]() -> cc::ProtocolPtr
            {
                return cc::ProtocolPtr(new Protocol());
            });
}

MessageHeaderFramePlugin::~MessageHeaderFramePlugin() = default;

} // namespace cc_plugin

} // namespace extension

