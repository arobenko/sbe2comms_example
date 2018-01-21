#pragma once

#include <QtCore/QObject>
#include <QtCore/QtPlugin>

#include "comms_champion/comms_champion.h"

namespace sbe_example
{

namespace cc_plugin
{

class MessageHeaderFramePlugin : public comms_champion::Plugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "extension" FILE "plugin_MessageHeaderFrame.json")
    Q_INTERFACES(comms_champion::Plugin)

public:
    MessageHeaderFramePlugin();
    ~MessageHeaderFramePlugin();
};

} // namespace cc_plugin

} // namespace sbe_example

