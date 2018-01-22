/// \file
/// \brief Contains definition of extension::OpenFramingHeaderLayer transport layer.

#pragma once

#include <iterator>
#include <type_traits>

#include "comms/protocol/ProtocolLayerBase.h"
#include "extension/DefaultOptions.h"
#include "sbe2comms/openFramingHeader.h"

namespace extension
{

/// \brief Re-definition of the Simple Open Framing Header field to be used in \ref OpenFramingHeaderLayer
/// \tparam TOpt Protocol definition options, expected to be \ref DefaultOptions or
///     deriving class.
template <typename TOpt>
using OpenFramingHeaderLayerField = sbe2comms::openFramingHeader;

/// \brief Protocol layer that uses \ref OpenFramingHeaderLayerField field as a prefix to all the
///        subsequent data written by other (next) layers.
/// \details The main purpose of this layer is to provide information about
///     the remaining size of the serialised message. Inherits from \b comms::protocol::ProtocolLayerBase.
///     Please read the documentation of the latter for details on inherited public
///     interface. Please also read <b>Protocol Stack Tutorial</b> page from the \b COMMS
///     library documentation.
/// \tparam TNextLayer Next transport layer in protocol stack.
/// \tparam TField Field of the Simple Open Framing Header.
/// \headerfile "extension/OpenFramingHeaderLayer.h"
template <
    typename TNextLayer,
    typename TField = OpenFramingHeaderLayerField<DefaultOptions>
>
class OpenFramingHeaderLayer : public
    comms::protocol::ProtocolLayerBase<
        TField,
        TNextLayer,
        OpenFramingHeaderLayer<TNextLayer, TField>
    >
{
    using BaseImpl =
        comms::protocol::ProtocolLayerBase<
            TField,
            TNextLayer,
            OpenFramingHeaderLayer<TNextLayer, TField>
        >;

public:
    /// \brief Type of the field object used to read/write header.
    using Field = typename BaseImpl::Field;

    /// \brief Default constructor
    OpenFramingHeaderLayer() = default;

    /// \brief Copy constructor
    OpenFramingHeaderLayer(const OpenFramingHeaderLayer&) = default;

    /// \brief Move constructor
    OpenFramingHeaderLayer(OpenFramingHeaderLayer&&) = default;

    /// \brief Destructor.
    ~OpenFramingHeaderLayer() noexcept = default;

    /// \brief Copy assignment.
    OpenFramingHeaderLayer& operator=(const OpenFramingHeaderLayer&) = default;

    /// \brief Move assignment.
    OpenFramingHeaderLayer& operator=(OpenFramingHeaderLayer&&) = default;

    /// \brief Deserialise message from the input data sequence.
    /// \details Reads the header data from the input data sequence
    ///          and calls read() member function of the next layer with
    ///          the size specified in the "messageLength" field.The function will also
    ///          compare the provided size of the data with size of the
    ///          message read from the buffer. If the latter is greater than
    ///          former, \b comms::ErrorStatus::NotEnoughData will be returned.
    ///          However, if buffer contains enough data, but the next layer
    ///          reports it's not enough (returns comms::ErrorStatus::NotEnoughData),
    ///          \b comms::ErrorStatus::ProtocolError will be returned.
    /// \tparam TMsgPtr Type of smart pointer that holds message object.
    /// \tparam TIter Type of iterator used for reading.
    /// \tparam TNextLayerReader next layer reader object type.
    /// \param[out] field Field object to read.
    /// \param[in, out] msgPtr Reference to smart pointer that already holds or
    ///     will hold allocated message object.
    /// \param[in, out] iter Input iterator used for reading.
    /// \param[in] size Size of the data in the sequence
    /// \param[out] missingSize If not nullptr and return value is
    ///     comms::ErrorStatus::NotEnoughData it will contain
    ///     minimal missing data length required for the successful
    ///     read attempt.
    /// \param[in] nextLayerReader Next layer reader object.
    /// \return Status of the read operation.
    /// \pre Iterator must be valid and can be dereferenced and incremented at
    ///      least "size" times.
    /// \post The iterator will be advanced by the number of bytes was actually
    ///       read. In case of an error, distance between original position and
    ///       advanced will pinpoint the location of the error.
    /// \post missingSize output value is updated if and only if function
    ///       returns comms::ErrorStatus::NotEnoughData.
    template <typename TMsgPtr, typename TIter, typename TNextLayerReader>
    comms::ErrorStatus doRead(
        Field& field,
        TMsgPtr& msgPtr,
        TIter& iter,
        std::size_t size,
        std::size_t* missingSize,
        TNextLayerReader&& nextLayerReader)
    {
        using IterType = typename std::decay<decltype(iter)>::type;
        using IterTag = typename std::iterator_traits<IterType>::iterator_category;
        static_assert(
            std::is_base_of<std::random_access_iterator_tag, IterTag>::value,
            "Current implementation of OpenFramingHeaderLayer requires iterator"
            "used for reading to be random-access one.");

        auto es = field.read(iter, size);
        if (es == comms::ErrorStatus::NotEnoughData) {
            BaseImpl::updateMissingSize(field, size, missingSize);
        }

        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        auto fromIter = iter;
        auto actualRemainingSize = (size - field.length());
        auto requiredRemainingSize = static_cast<std::size_t>(field.field_messageLength().value());

        if (actualRemainingSize < requiredRemainingSize) {
            if (missingSize != nullptr) {
                *missingSize = requiredRemainingSize - actualRemainingSize;
            }
            return comms::ErrorStatus::NotEnoughData;
        }

        // not passing missingSize farther on purpose
        es = nextLayerReader.read(msgPtr, iter, requiredRemainingSize, nullptr);
        if (es == comms::ErrorStatus::NotEnoughData) {
            return comms::ErrorStatus::ProtocolError;
        }

        auto consumed =
            static_cast<std::size_t>(std::distance(fromIter, iter));
        if (consumed < requiredRemainingSize) {
            auto diff = requiredRemainingSize - consumed;
            std::advance(iter, diff);
        }
        return es;
    }

    /// \brief Serialise message into the output data sequence.
    /// \details The function will write header data,
    ///     then invoke the write() member function of the next
    ///     layer. The calculation of the required message length is performed by invoking
    ///     "length(msg)".
    /// \tparam TMsg Type of message object.
    /// \tparam TIter Type of iterator used for writing.
    /// \tparam TNextLayerWriter next layer writer object type.
    /// \param[out] field Field object to update and write.
    /// \param[in] msg Reference to message object
    /// \param[in, out] iter Output iterator.
    /// \param[in] size Max number of bytes that can be written.
    /// \param[in] nextLayerWriter Next layer writer object.
    /// \return Status of the write operation.
    /// \pre Iterator must be valid and can be dereferenced and incremented at
    ///      least "size" times.
    /// \post The iterator will be advanced by the number of bytes was actually
    ///       written. In case of an error, distance between original position
    ///       and advanced will pinpoint the location of the error.
    template <typename TMsg, typename TIter, typename TNextLayerWriter>
    comms::ErrorStatus doWrite(
        Field& field,
        const TMsg& msg,
        TIter& iter,
        std::size_t size,
        TNextLayerWriter&& nextLayerWriter) const
    {
        using MsgType = typename std::decay<decltype(msg)>::type;
        return
            writeInternal(
                field,
                msg,
                iter,
                size,
                std::forward<TNextLayerWriter>(nextLayerWriter),
                MsgLengthTag<MsgType>());
    }

    /// \brief Update written dummy size with proper value.
    /// \details Should be called when \ref doWrite() returns \b comms::ErrorStatus::UpdateRequired.
    /// \tparam TIter Type of iterator used for updating.
    /// \tparam TNextLayerWriter next layer updater object type.
    /// \param[out] field Field object to update.
    /// \param[in, out] iter Any random access iterator.
    /// \param[in] size Number of bytes that have been written using write().
    /// \param[in] nextLayerUpdater Next layer updater object.
    /// \return Status of the update operation.
    template <typename TIter, typename TNextLayerUpdater>
    comms::ErrorStatus doUpdate(
        Field& field,
        TIter& iter,
        std::size_t size,
        TNextLayerUpdater&& nextLayerUpdater) const
    {
        field.field_messageLength().value() = size - Field::maxLength();

        auto es = field.write(iter, size);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        return nextLayerUpdater.update(iter, size - field.length());
    }

private:

    struct MsgHasLengthTag {};
    struct MsgNoLengthTag {};

    template<typename TMsg>
    using MsgLengthTag =
        typename std::conditional<
            comms::protocol::details::ProtocolLayerHasFieldsImpl<TMsg>::Value || TMsg::InterfaceOptions::HasLength,
            MsgHasLengthTag,
            MsgNoLengthTag
        >::type;

    template <typename TMsg, typename TIter, typename TWriter>
    comms::ErrorStatus writeInternalHasLength(
        Field& field,
        const TMsg& msg,
        TIter& iter,
        std::size_t size,
        TWriter&& nextLayerWriter) const
    {
        auto& messageLengthValue = field.field_messageLength().value();
        using MessageLengthValueType = typename std::decay<decltype(messageLengthValue)>::type;
        messageLengthValue = 
            static_cast<MessageLengthValueType>(BaseImpl::nextLayer().length(msg));
        auto es = field.write(iter, size);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        return nextLayerWriter.write(msg, iter, size - field.length());
    }

    template <typename TMsg, typename TIter, typename TWriter>
    comms::ErrorStatus writeInternalRandomAccess(
        Field& field,
        const TMsg& msg,
        TIter& iter,
        std::size_t size,
        TWriter&& nextLayerWriter) const
    {
        auto valueIter = iter;

        auto& messageLengthValue = field.field_messageLength().value();
        messageLengthValue = 0U;
        auto es = field.write(iter, size);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        auto dataIter = iter;
        es = nextLayerWriter.write(msg, iter, size - field.length());
        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        using MessageLengthValueType = typename std::decay<decltype(messageLengthValue)>::type;
        messageLengthValue = static_cast<MessageLengthValueType>(std::distance(dataIter, iter));
        return field.write(valueIter, Field::minLength());
    }

    template <typename TMsg, typename TIter, typename TWriter>
    comms::ErrorStatus writeInternalOutput(
        Field& field,
        const TMsg& msg,
        TIter& iter,
        std::size_t size,
        TWriter&& nextLayerWriter) const
    {
        field.field_messageLength().value() = 0;
        auto es = field.write(iter, size);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        es = nextLayerWriter.write(msg, iter, size - field.length());
        if ((es != comms::ErrorStatus::Success) &&
            (es != comms::ErrorStatus::UpdateRequired)) {
            return es;
        }

        return comms::ErrorStatus::UpdateRequired;
    }

    template <typename TMsg, typename TIter, typename TWriter>
    comms::ErrorStatus writeInternalNoLengthTagged(
        Field& field,
        const TMsg& msg,
        TIter& iter,
        std::size_t size,
        TWriter&& nextLayerWriter,
        std::random_access_iterator_tag) const
    {
        return writeInternalRandomAccess(field, msg, iter, size, std::forward<TWriter>(nextLayerWriter));
    }

    template <typename TMsg, typename TIter, typename TWriter>
    comms::ErrorStatus writeInternalNoLengthTagged(
        Field& field,
        const TMsg& msg,
        TIter& iter,
        std::size_t size,
        TWriter&& nextLayerWriter,
        std::output_iterator_tag) const
    {
        return writeInternalOutput(field, msg, iter, size, std::forward<TWriter>(nextLayerWriter));
    }

    template <typename TMsg, typename TIter, typename TWriter>
    comms::ErrorStatus writeInternalNoLength(
        Field& field,
        const TMsg& msg,
        TIter& iter,
        std::size_t size,
        TWriter&& nextLayerWriter) const
    {
        using IterType = typename std::decay<decltype(iter)>::type;
        using Tag = typename std::iterator_traits<IterType>::iterator_category;
        return writeInternalNoLengthTagged(field, msg, iter, size, std::forward<TWriter>(nextLayerWriter), Tag());
    }

    template <typename TMsg, typename TIter, typename TWriter>
    comms::ErrorStatus writeInternal(
        Field& field,
        const TMsg& msg,
        TIter& iter,
        std::size_t size,
        TWriter&& nextLayerWriter,
        MsgHasLengthTag) const
    {
        return writeInternalHasLength(field, msg, iter, size, std::forward<TWriter>(nextLayerWriter));
    }
    template <typename TMsg, typename TIter, typename TWriter>
    comms::ErrorStatus writeInternal(
        Field& field,
        const TMsg& msg,
        TIter& iter,
        std::size_t size,
        TWriter&& nextLayerWriter,
        MsgNoLengthTag) const
    {
        return writeInternalNoLength(field, msg, iter, size, std::forward<TWriter>(nextLayerWriter));
    }

    static_assert(Field::minLength() == Field::maxLength(),
        "sbe2comms::openFramingHeader field is expected to have fixed length.");

};

} // namespace extension

