#pragma once

#include "comms_champion/comms_champion.h"
#include "cc_plugin/Message.h"
#include "extension/message/Car.h"

namespace extension
{

namespace cc_plugin
{

namespace message
{

class Car : public
    comms_champion::ProtocolMessageBase<
        extension::message::Car<extension::cc_plugin::Message<> >,
        Car>
{
protected:
    virtual const char* nameImpl() const override;
    virtual const QVariantList& fieldsPropertiesImpl() const override;
};

} // namespace message

} // namespace cc_plugin

} // namespace extension

