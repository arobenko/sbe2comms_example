/// \file
/// \brief Contains definition of transport frames.

#pragma once

#include <cstdint>

#include "comms/protocol/MsgDataLayer.h"
#include "comms/options.h"
#include "MessageHeaderLayer.h"
#include "OpenFramingHeaderLayer.h"
#include "DefaultOptions.h"

namespace extension
{

/// \brief Definition of transport frame involving only message header
///     (\ref field::messageHeader).
/// \tparam TMsgBase Common base (interface) class of all the \b input messages.
/// \tparam TMessages All the message types that need to be recognized in the
///     input and created.
/// \tparam TOpt Protocol definition options, expected to be \ref DefaultOptions or
///     derived class with similar types inside.
/// \tparam TFactoryOpt Options from \b comms::option namespace 
///     to be passed to \b comms::MsgFactory object
///     contained by \ref MessageHeaderLayer. It controls the way the message
///     objects are created.
/// \tparam TDataStorageOpt Extra options from \b comms::option namespace
///     to be passed to raw data storage field used by \b comms::protocol::MsgDataLayer.
///     \b NOTE, that this field is used only when "cached" read write operations
///     are performed, where the read/written raw data needs to be stored for
///     future reference or display. It is not used in normal read/write operations.
template <
    typename TMsgBase,
    typename TMessages,
    typename TOpt = DefaultOptions,
    typename TFactoryOpt = comms::option::EmptyOption,
    typename TDataStorageOpt = comms::option::EmptyOption
>
using MessageHeaderFrame =
    MessageHeaderLayer<
        TMsgBase,
        TMessages,
        comms::protocol::MsgDataLayer<TDataStorageOpt>,
        MessageHeaderLayerField<TOpt>,
        TFactoryOpt
    >;

/// \brief Definition of transport frame involving both message header
///     and simple open framing header.
/// \tparam TMsgBase Common base (interface) class of all the \b input messages.
/// \tparam TMessages All the message types that need to be recognized in the
///     input and created.
/// \tparam TOpt Protocol definition options, expected to be \ref DefaultOptions or
///     derived class with similar types inside.
/// \tparam TFactoryOpt Options from \b comms::option namespace 
///     to be passed to \b comms::MsgFactory object
///     contained by \ref MessageHeaderLayer. It controls the way the message
///     objects are created.
/// \tparam TDataStorageOpt Extra options from \b comms::option namespace
///     to be passed to raw data storage field used by \b comms::protocol::MsgDataLayer.
///     \b NOTE, that this field is used only when "cached" read write operations
///     are performed, where the read/written raw data needs to be stored for
///     future reference or display. It is not used in normal read/write operations.
template <
    typename TMsgBase,
    typename TMessages,
    typename TOpt = DefaultOptions,
    typename TFactoryOpt = comms::option::EmptyOption,
    typename TDataStorageOpt = comms::option::EmptyOption
>
using OpenFramingHeaderFrame =
    OpenFramingHeaderLayer<
        MessageHeaderFrame<TMsgBase, TMessages, TOpt, TFactoryOpt, TDataStorageOpt>,
        OpenFramingHeaderLayerField<TOpt>
    >;

} // namespace extension

