/// \file
/// \brief Contains definition of extension::MessageHeaderLayer transport layer.

#pragma once

#include "comms/MsgFactory.h"
#include "comms/protocol/ProtocolLayerBase.h"
#include "comms/util/Tuple.h"

#include "extension/DefaultOptions.h"
#include "extension/field/messageHeader.h"

namespace extension
{

/// \brief Re-definition of the \"messageHeader\" field to be used in \ref MessageHeaderLayer
/// \tparam TOpt Protocol definition options, expected to be \ref DefaultOptions or
///     deriving class.
template <typename TOpt>
using MessageHeaderLayerField=
    field::messageHeader<
        typename TOpt::field::messageHeaderMembers::blockLength,
        typename TOpt::field::messageHeaderMembers::templateId,
        typename TOpt::field::messageHeaderMembers::schemaId,
        typename TOpt::field::messageHeaderMembers::version
    >;

/// \brief Protocol layer that uses \ref field::messageHeader field as a prefix to all the
///        subsequent data written by other (next) layers.
/// \details The main purpose of this layer is to process the message header information.
///     Holds instance of \b comms::MsgFactory as its private member and uses it
///     to create message with the required ID. Inherits from \b comms::protocol::ProtocolLayerBase.
///     Please read the documentation of the latter for details on inherited public
///     interface. Please also read <b>Protocol Stack Tutorial</b> page from the \b COMMS
///     library documentation.
/// \tparam TMessage Interface class for the \b input messages, expected to be
///     a variant of \ref Message class.
/// \tparam TAllMessages Types of all \b input messages, bundled in std::tuple,
///     that this protocol stack must be able to \b read() as well as create (using createMsg()).
/// \tparam TNextLayer Next transport layer type.
/// \tparam TField Field of message header.
/// \tparam TFactoryOpt All the options that will be forwarded to definition of
///     message factory type (comms::MsgFactory).
/// \headerfile "extension/MessageHeaderLayer.h"
template <
    typename TMessage,
    typename TAllMessages,
    typename TNextLayer,
    typename TField = MessageHeaderLayerField<DefaultOptions>,
    typename TFactoryOpt = comms::option::EmptyOption
>
class MessageHeaderLayer : public
    comms::protocol::ProtocolLayerBase<
        TField,
        TNextLayer,
        MessageHeaderLayer<TMessage, TAllMessages, TNextLayer, TField, TFactoryOpt>
    >
{
    static_assert(comms::util::IsTuple<TAllMessages>::Value,
        "TAllMessages must be of std::tuple type");

    using BaseImpl =
        comms::protocol::ProtocolLayerBase<
            TField,
            TNextLayer,
            MessageHeaderLayer<TMessage, TAllMessages, TNextLayer, TField, TFactoryOpt>
        >;

    using Factory = comms::MsgFactory<TMessage, TAllMessages, TFactoryOpt>;

    static_assert(TMessage::InterfaceOptions::HasMsgIdType,
        "Usage of MessageHeaderLayer requires support for ID type. "
        "Use comms::option::MsgIdType option in message interface type definition.");

public:
    /// \brief All supported message types bundled in std::tuple.
    /// \see comms::MsgFactory::AllMessages.
    using AllMessages = typename Factory::AllMessages;

    /// \brief Type of smart pointer that will hold allocated message object.
    /// \details Same as \b comms::MsgFactory::MsgPtr.
    using MsgPtr = typename Factory::MsgPtr;

    /// \brief Type of the \b input message interface.
    using Message = TMessage;

    /// \brief Type of message ID
    using MsgIdType = typename Message::MsgIdType;

    /// \brief Type of message ID when passed by the parameter
    using MsgIdParamType = typename Message::MsgIdParamType;

    /// \brief Type of the field object used to read/write message ID value.
    using Field = typename BaseImpl::Field;

    /// \brief Default constructor.
    MessageHeaderLayer() = default;

    /// \brief Copy constructor.
    MessageHeaderLayer(const MessageHeaderLayer&) = default;

    /// \brief Move constructor.
    MessageHeaderLayer(MessageHeaderLayer&&) = default;

    /// \brief Copy assignment.
    MessageHeaderLayer& operator=(const MessageHeaderLayer&) = default;

    /// \brief Move assignment.
    MessageHeaderLayer& operator=(MessageHeaderLayer&&) = default;

    /// \brief Destructor
    ~MessageHeaderLayer() noexcept = default;

    /// \brief Deserialise message from the input data sequence.
    /// \details The function will read message header from the data sequence first,
    ///     generate appropriate message object based on the read ID and
    ///     forward the read() request to the next layer.
    ///     If the message object cannot be generated (the message type is not
    ///     provided inside \b TAllMessages template parameter), but
    ///     the \b comms::option::SupportGenericMessage option has beed used,
    ///     the \b comms::GenericMessage may be generated instead.
    /// \tparam TIter Type of iterator used for reading.
    /// \tparam TNextLayerReader next layer reader object type.
    /// \param[out] header Message header field object to read.
    /// \param[in, out] msgPtr Reference to smart pointer that will hold
    ///                 allocated message object
    /// \param[in, out] iter Input iterator used for reading.
    /// \param[in] size Size of the data in the sequence
    /// \param[out] missingSize If not nullptr and return value is
    ///             comms::ErrorStatus::NotEnoughData it will contain
    ///             minimal missing data length required for the successful
    ///             read attempt.
    /// \param[in] nextLayerReader Next layer reader object.
    /// \return Status of the operation.
    /// \pre msgPtr doesn't point to any object:
    ///      \code assert(!msgPtr); \endcode
    /// \pre Iterator must be valid and can be dereferenced and incremented at
    ///      least "size" times;
    /// \post The iterator will be advanced by the number of bytes was actually
    ///       read. In case of an error, distance between original position and
    ///       advanced will pinpoint the location of the error.
    /// \post Returns comms::ErrorStatus::Success if and only if msgPtr points
    ///       to a valid object.
    /// \post missingSize output value is updated if and only if function
    ///       returns comms::ErrorStatus::NotEnoughData.
    template <typename TIter, typename TNextLayerReader>
    comms::ErrorStatus doRead(
        Field& header,
        MsgPtr& msgPtr,
        TIter& iter,
        std::size_t size,
        std::size_t* missingSize,
        TNextLayerReader&& nextLayerReader)
    {
        auto es = header.read(iter, size);
        if (es == comms::ErrorStatus::NotEnoughData) {
            BaseImpl::updateMissingSize(header, size, missingSize);
        }

        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        auto id = header.field_templateId().value();
        do {
            msgPtr = createMsg(id);
            if (msgPtr) {
                break;
            }

            msgPtr = factory_.createGenericMsg(id);
            if (msgPtr) {
                break;
            }

            return comms::ErrorStatus::InvalidMsgId;
        } while (false);

        auto remLen = size - header.length();
        if (remLen < header.field_blockLength().value()) {
            return comms::ErrorStatus::NotEnoughData;
        }

        msgPtr->setBlockLength(header.field_blockLength().value());
        msgPtr->setVersion(header.field_version().value());
        es = nextLayerReader.read(msgPtr, iter, remLen, missingSize);
        if (es != comms::ErrorStatus::Success) {
            msgPtr.reset();
        }
        return es;
    }

    /// \brief Serialise message into output data sequence.
    /// \details The function will write \ref field::messageHeader to the data
    ///     sequence, then call write() member function of the next
    ///     protocol layer. If \b TMsg type is recognised to be actual message
    ///     type (inherited from comms::MessageBase while using
    ///     comms::option::StaticNumIdImpl option to specify its numeric ID),
    ///     its defined \b doGetId() member function (see \b comms::MessageBase::doGetId())
    ///     non virtual function is called. Otherwise polymorphic \b getId()
    ///     member function is used to retrieve the message ID information, which
    ///     means the message interface class must use \b comms::option::IdInfoInterface
    ///     option to define appropriate interface.
    /// \tparam TMsg Type of the message being written.
    /// \tparam TIter Type of iterator used for writing.
    /// \tparam TNextLayerWriter next layer writer object type.
    /// \param[out] header Message header field object to update and write.
    /// \param[in] msg Reference to message object
    /// \param[in, out] iter Output iterator used for writing.
    /// \param[in] size Max number of bytes that can be written.
    /// \param[in] nextLayerWriter Next layer writer object.
    /// \return Status of the write operation.
    /// \pre Iterator must be valid and can be dereferenced and incremented at
    ///      least "size" times;
    /// \post The iterator will be advanced by the number of bytes was actually
    ///       written. In case of an error, distance between original position
    ///       and advanced will pinpoint the location of the error.
    /// \return Status of the write operation.
    template <typename TMsg, typename TIter, typename TNextLayerWriter>
    comms::ErrorStatus doWrite(
        Field& header,
        const TMsg& msg,
        TIter& iter,
        std::size_t size,
        TNextLayerWriter&& nextLayerWriter) const
    {
        using MsgType = typename std::decay<decltype(msg)>::type;

        auto blockLength = 
            static_cast<typename field::messageHeaderMembers::blockLength<>::ValueType>(
                msg.getBlockLength());
        auto version = 
            static_cast<typename field::messageHeaderMembers::version<>::ValueType>(
                msg.getVersion());

        header.field_blockLength().value() = blockLength;
        header.field_templateId().value() = getMsgId(msg, IdRetrieveTag<MsgType>());
        header.field_version().value() = version;

        auto es = header.write(iter, size);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        return nextLayerWriter.write(msg, iter, size - header.length());
    }

    /// \brief Create message object given message id
    /// \details Hides and overrides createMsg() function inherited from
    ///     \b comms::protocol::ProtocolLayerBase. This function forwards the request to the
    ///     message factory object (\b comms::MsgFactory) embedded as a private
    ///     data member of this class.
    /// \param[in] id ID of the message
    /// \param[in] idx Relative index of the message with the same ID.
    /// \return Smart pointer to the created message object.
    /// \see comms::MsgFactory::createMsg()
    MsgPtr createMsg(MsgIdParamType id, unsigned idx = 0)
    {
        return factory_.createMsg(id, idx);
    }

private:
    struct PolymorphicIdTag {};
    struct DirectIdTag {};

    template <typename TMsg>
    using IdRetrieveTag =
        typename std::conditional<
            comms::protocol::details::ProtocolLayerHasDoGetId<TMsg>::Value,
            DirectIdTag,
            PolymorphicIdTag
        >::type;

    template <typename TMsg>
    static MsgIdParamType getMsgId(const TMsg& msg, PolymorphicIdTag)
    {
        using MsgType = typename std::decay<decltype(msg)>::type;
        static_assert(comms::protocol::details::ProtocolLayerHasInterfaceOptions<MsgType>::Value,
            "The message class is expected to inherit from comms::Message");
        static_assert(MsgType::InterfaceOptions::HasMsgIdInfo,
            "The message interface class must expose polymorphic ID retrieval functionality, "
            "use comms::option::IdInfoInterface option to define it.");

            return msg.getId();
        }

    template <typename TMsg>
    static constexpr MsgIdParamType getMsgId(const TMsg& msg, DirectIdTag)
    {
        return msg.doGetId();
    }

    Factory factory_;
};

} // namespace extension

