#include "MessageHeaderFrameTransportMessage.h"

#include <cassert>

#include "cc_plugin/field.h"

namespace extension
{

namespace cc_plugin
{

namespace
{

QVariantMap createFieldProps_messageHeader()
{
    return field::createProps_messageHeader("Message Header");
}

QVariantMap createFieldProps_data()
{
    return comms_champion::property::field::ArrayList().name("Data").asMap();
}

QVariantList createFieldsProperties()
{
    QVariantList props;
    props.append(createFieldProps_messageHeader());
    props.append(createFieldProps_data());

    return props;
}

} // namespace 

const QVariantList& MessageHeaderFrameTransportMessage::fieldsPropertiesImpl() const
{
    static const auto Props = createFieldsProperties();
    return Props;
}

} // namespace cc_plugin

} // namespace extension

