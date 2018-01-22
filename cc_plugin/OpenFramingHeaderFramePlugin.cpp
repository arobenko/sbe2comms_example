#include "cc_plugin/OpenFramingHeaderFramePlugin.h"
#include "cc_plugin/Protocol.h"

namespace cc = comms_champion;

namespace extension
{

namespace cc_plugin
{

OpenFramingHeaderFramePlugin::OpenFramingHeaderFramePlugin()
{
    pluginProperties()
        .setProtocolCreateFunc(
            [this]() -> cc::ProtocolPtr
            {
                return cc::ProtocolPtr(new Protocol());
            });
}

OpenFramingHeaderFramePlugin::~OpenFramingHeaderFramePlugin() = default;

} // namespace cc_plugin

} // namespace extension

