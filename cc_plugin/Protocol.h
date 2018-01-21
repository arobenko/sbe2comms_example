#pragma once

#include <memory>

#include "comms_champion/comms_champion.h"

namespace sbe_example
{

namespace cc_plugin
{

class ProtocolImpl;
class Protocol : public comms_champion::Protocol
{
public:
    Protocol();
    virtual ~Protocol();

protected:
    virtual const QString& nameImpl() const override;
    virtual MessagesList readImpl(const comms_champion::DataInfo& dataInfo, bool final) override;
    virtual comms_champion::DataInfoPtr writeImpl(comms_champion::Message& msg) override;
    virtual MessagesList createAllMessagesImpl() override;
    virtual comms_champion::MessagePtr createMessageImpl(const QString& idAsString, unsigned idx) override;
    virtual UpdateStatus updateMessageImpl(comms_champion::Message& msg) override;
    virtual comms_champion::MessagePtr cloneMessageImpl(const comms_champion::Message& msg) override;
    virtual comms_champion::MessagePtr createInvalidMessageImpl() override;
    virtual comms_champion::MessagePtr createRawDataMessageImpl() override;
    virtual comms_champion::MessagePtr createExtraInfoMessageImpl() override;

private:
    std::unique_ptr<ProtocolImpl> m_pImpl;
};

} // namespace cc_plugin

} // namespace sbe_example

