#include "OpenFramingHeaderFrameTransportMessage.h"

#include <cassert>

#include "cc_plugin/field.h"
#include "extension/sbe2comms/openFramingHeader.h"

namespace extension
{

namespace cc_plugin
{

namespace
{

QVariantMap createFieldProps_openFramingHeader()
{
    using Field = sbe2comms::openFramingHeader;
    return 
        comms_champion::property::field::ForField<Field>()
            .name("Open Framing Header")
            .add(
                comms_champion::property::field::IntValue()
                    .name("messageLength")
                    .displayOffset(6)
                    .asMap())
            .add(
                comms_champion::property::field::IntValue()
                    .name("encodingType")
                    .readOnly()
                    .asMap())
            .asMap();
}

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
    props.append(createFieldProps_openFramingHeader());
    props.append(createFieldProps_messageHeader());
    props.append(createFieldProps_data());

    return props;
}

} // namespace 

const QVariantList& OpenFramingHeaderFrameTransportMessage::fieldsPropertiesImpl() const
{
    static const auto Props = createFieldsProperties();
    return Props;
}

} // namespace cc_plugin

} // namespace extension

