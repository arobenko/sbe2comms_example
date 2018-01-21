/// \file
/// \brief Contains definition of common \ref sbe_example::Message interface class.

#pragma once

#include "comms/Message.h"
#include "comms/options.h"
#include "sbe_example/field/messageHeader.h"
#include "MsgId.h"

namespace sbe_example
{

/// \brief Extra transport fields for every message.
using ExtraTransportFields =
    std::tuple<
        sbe_example::field::messageHeaderMembers::blockLength<>,
        sbe_example::field::messageHeaderMembers::version<>
    >;

/// \brief Common interface class for all the messages.
/// \tparam TOpt Extra options from \b comms::option namespace.
/// \see \ref ExtraTransportFields
/// \headerfile "sbe_example/Message.h"
template <typename... TOpt>
class Message : public
    comms::Message<
        comms::option::MsgIdType<MsgId>,
        comms::option::LittleEndian,
        comms::option::ExtraTransportFields<ExtraTransportFields>,
        TOpt...
    >
{
    using Base =
        comms::Message<
            comms::option::MsgIdType<MsgId>,
            comms::option::LittleEndian,
            comms::option::ExtraTransportFields<ExtraTransportFields>,
            TOpt...
        >;

public:
    /// \brief Allow access to extra transport fields.
    /// \details See definition of \b COMMS_MSG_TRANSPORT_FIELDS_ACCESS macro
    ///     related to \b comms::Message class from COMMS library
    ///     for details.
    COMMS_MSG_TRANSPORT_FIELDS_ACCESS(blockLength, version);

    /// \brief Set the value of the root block length.
    void setBlockLength(std::size_t value)
    {
        auto& blockLengthField = transportField_blockLength();
        using BlockLengthFieldType = typename std::decay<decltype(blockLengthField)>::type;
        using BlockLengthValueType = typename BlockLengthFieldType::ValueType;
        blockLengthField.value() = static_cast<BlockLengthValueType>(value);
    }

    /// \brief Get the value of the root block length.
    std::size_t getBlockLength() const
    {
        return transportField_blockLength().value();
    }

    /// \brief Set the value of the schema version.
    void setVersion(unsigned value)
    {
        auto& versionField = transportField_version();
        using VersionFieldType = typename std::decay<decltype(versionField)>::type;
        using VersionValueType = typename VersionFieldType::ValueType;
        versionField.value() = static_cast<VersionValueType>(value);
    }

    /// \brief Get the value of the schema version.
    unsigned getVersion() const
    {
        return transportField_version().value();
    }

};

} // namespace sbe_example

