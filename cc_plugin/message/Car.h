#pragma once

#include "comms_champion/comms_champion.h"
#include "cc_plugin/Message.h"
#include "sbe_example/message/Car.h"

namespace sbe_example
{

namespace cc_plugin
{

namespace message
{

class Car : public
    comms_champion::ProtocolMessageBase<
        sbe_example::message::Car<sbe_example::cc_plugin::Message<> >,
        Car>
{
protected:
    virtual const char* nameImpl() const override;
    virtual const QVariantList& fieldsPropertiesImpl() const override;
};

} // namespace message

} // namespace cc_plugin

} // namespace sbe_example

