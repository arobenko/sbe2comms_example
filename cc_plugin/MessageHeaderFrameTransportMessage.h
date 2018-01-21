#pragma once

#include "comms_champion/comms_champion.h"

#include "sbe_example/TransportFrame.h"
#include "cc_plugin/Message.h"
#include "cc_plugin/TransportFrame.h"

namespace sbe_example
{

namespace cc_plugin
{

class MessageHeaderFrameTransportMessage : public
    comms_champion::TransportMessageBase<
        cc_plugin::Message<>,
        cc_plugin::MessageHeaderFrame::AllFields
    >
{
protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override;
};

} // namespace cc_plugin

} // namespace sbe_example

