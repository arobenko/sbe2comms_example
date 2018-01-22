/// \file
/// \brief Contains definition of implicitly defined \ref extension::sbe2comms::openFramingHeader


#pragma once

#include <cstdint>

#include "comms/Field.h"
#include "comms/field/Bundle.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"

namespace extension
{

namespace sbe2comms
{

/// \brief Simple Open Framing Header definition.
/// \headerfile "extension/sbe2comms/openFramingHeader.h"
struct openFramingHeader : public
    comms::field::Bundle<
        comms::Field<comms::option::BigEndian>,
        std::tuple<
            comms::field::IntValue<
                comms::Field<comms::option::BigEndian>,
                std::uint32_t,
                comms::option::NumValueSerOffset<sizeof(std::uint32_t) + sizeof(std::uint16_t)>
            >,
            comms::field::IntValue<
                comms::Field<comms::option::BigEndian>,
                std::uint16_t,
                comms::option::ValidNumValue<0xeb50>,
                comms::option::DefaultNumValue<0xeb50>,
                comms::option::FailOnInvalid<comms::ErrorStatus::ProtocolError>
            >
        >
    >
{
    using Base =
        comms::field::Bundle<
            comms::Field<comms::option::BigEndian>,
            std::tuple<
                comms::field::IntValue<
                    comms::Field<comms::option::BigEndian>,
                    std::uint32_t,
                    comms::option::NumValueSerOffset<sizeof(std::uint32_t) + sizeof(std::uint16_t)>
                >,
                comms::field::IntValue<
                    comms::Field<comms::option::BigEndian>,
                    std::uint16_t,
                    comms::option::ValidNumValue<0xeb50>,
                    comms::option::DefaultNumValue<0xeb50>,
                    comms::option::FailOnInvalid<comms::ErrorStatus::ProtocolError>
                >
            >
        >;

public:
    /// \brief Allow access to internal fields.
    /// \details See definition of \b COMMS_FIELD_MEMBERS_ACCESS macro
    ///     related to \b comms::field::Bundle class from COMMS library
    ///     for details.\n
    COMMS_FIELD_MEMBERS_ACCESS(
        messageLength,
        encodingType
    );
};

} // namespace sbe2comms

} // namespace extension

