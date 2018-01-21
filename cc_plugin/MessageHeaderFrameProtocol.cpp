#include "Protocol.h"

#include "cc_plugin/TransportFrame.h"
#include "cc_plugin/MessageHeaderFrameTransportMessage.h"

namespace cc = comms_champion;

namespace sbe_example
{

namespace cc_plugin
{

class ProtocolImpl : public
    cc::ProtocolBase<
        cc_plugin::MessageHeaderFrame,
        cc_plugin::MessageHeaderFrameTransportMessage
    >
{
    using Base =
        cc::ProtocolBase<
            cc_plugin::MessageHeaderFrame,
            cc_plugin::MessageHeaderFrameTransportMessage
        >;
public:
    friend class sbe_example::cc_plugin::Protocol;

    ProtocolImpl() = default;
    virtual ~ProtocolImpl() = default;

protected:
    virtual const QString& nameImpl() const override
    {
        static const QString Str("extension");
        return Str;
    }

    using Base::createInvalidMessageImpl;
    using Base::createRawDataMessageImpl;
    using Base::createExtraInfoMessageImpl;};

Protocol::Protocol()
  : m_pImpl(new ProtocolImpl())
{
}

Protocol::~Protocol() = default;
const QString& Protocol::nameImpl() const
{
    return m_pImpl->name();
}

Protocol::MessagesList Protocol::readImpl(const comms_champion::DataInfo& dataInfo, bool final)
{
    return m_pImpl->read(dataInfo, final);
}

cc::DataInfoPtr Protocol::writeImpl(cc::Message& msg)
{
    return m_pImpl->write(msg);
}

Protocol::MessagesList Protocol::createAllMessagesImpl()
{
    return m_pImpl->createAllMessages();
}

cc::MessagePtr Protocol::createMessageImpl(const QString& idAsString, unsigned idx)
{
    return static_cast<cc::Protocol*>(m_pImpl.get())->createMessage(idAsString, idx);
}

Protocol::UpdateStatus Protocol::updateMessageImpl(cc::Message& msg)
{
    return m_pImpl->updateMessage(msg);
}

cc::MessagePtr Protocol::cloneMessageImpl(const cc::Message& msg)
{
    return m_pImpl->cloneMessage(msg);
}

cc::MessagePtr Protocol::createInvalidMessageImpl()
{
    return m_pImpl->createInvalidMessageImpl();
}

cc::MessagePtr Protocol::createRawDataMessageImpl()
{
    return m_pImpl->createRawDataMessageImpl();
}

cc::MessagePtr Protocol::createExtraInfoMessageImpl()
{
    return m_pImpl->createExtraInfoMessageImpl();
}

} // namespace cc_plugin

} // namespace sbe_example

