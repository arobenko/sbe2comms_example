#pragma once

#include "comms_champion/comms_champion.h"
#include "extension/Message.h"

namespace extension
{

namespace cc_plugin
{

template <typename... TOptions>
class Message : public comms_champion::MessageBase<extension::Message, TOptions...>
{
protected:
    const QVariantList& extraTransportFieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createExtraTransportFields();
        return Props;
    }

private:
    static QVariantMap createFieldProps_blockLength()
    {
        return
            comms_champion::property::field::IntValue()
                .name("blockLength")
                .readOnly()
                .hidden()
                .asMap();
    }

    static QVariantMap createFieldProps_version()
    {
        return
            comms_champion::property::field::IntValue()
                .name("version")
                .serialisedHidden()
                .hiddenWhenReadOnly()
                .asMap();
    }

    static QVariantList createExtraTransportFields()
    {
        QVariantList props;
        props.append(createFieldProps_blockLength());
        props.append(createFieldProps_version());

        assert(props.size() == extension::Message<>::TransportFieldIdx_numOfValues);
        return props;
    }
};
} // namespace cc_plugin

} // namespace extension

