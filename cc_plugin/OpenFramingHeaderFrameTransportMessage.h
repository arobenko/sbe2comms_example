#pragma once

#include "comms_champion/comms_champion.h"

#include "extension/TransportFrame.h"
#include "cc_plugin/Message.h"
#include "cc_plugin/TransportFrame.h"

namespace extension
{

namespace cc_plugin
{

class OpenFramingHeaderFrameTransportMessage : public
    comms_champion::TransportMessageBase<
        cc_plugin::Message<>,
        cc_plugin::OpenFramingHeaderFrame::AllFields
    >
{
protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override;
};

} // namespace cc_plugin

} // namespace extension

