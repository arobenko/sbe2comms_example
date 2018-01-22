#pragma once

#include <QtCore/QObject>
#include <QtCore/QtPlugin>

#include "comms_champion/comms_champion.h"

namespace extension
{

namespace cc_plugin
{

class OpenFramingHeaderFramePlugin : public comms_champion::Plugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "extension.OpenFrame" FILE "plugin_OpenFramingHeaderFrame.json")
    Q_INTERFACES(comms_champion::Plugin)

public:
    OpenFramingHeaderFramePlugin();
    ~OpenFramingHeaderFramePlugin();
};

} // namespace cc_plugin

} // namespace extension

