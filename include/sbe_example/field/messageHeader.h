/// \file
/// \brief Contains definition of \ref sbe_example::field::messageHeader field.

#pragma once

#include <cstdint>

#include "comms/field/Bundle.h"
#include "comms/field/EnumValue.h"
#include "comms/field/IntValue.h"
#include "comms/util/Tuple.h"

#include "FieldBase.h"
#include "sbe_example/MsgId.h"
#include "sbe_example/sbe2comms/VersionSetter.h"

#include <cstdint>

namespace sbe_example
{

namespace field
{

/// \brief Scope for all the members of the \ref messageHeader field.
struct messageHeaderMembers
{
    /// \brief Definition of "blockLength" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class blockLength : public
        comms::field::IntValue<
            FieldBase,
            std::uint16_t,
            TOpt...,
            comms::option::ValidNumValueRange<0, 65534L>
        >
    {
        using Base =
            comms::field::IntValue<
                FieldBase,
                std::uint16_t,
                TOpt...,
                comms::option::ValidNumValueRange<0, 65534L>
            >;

    public:
        /// \brief Update current message version.
        /// \details Does nothing.
        /// \return \b false to indicate nothing has changed.
        static bool setVersion(unsigned)
        {
            return false;
        }
    };

    /// \brief Definition of "templateId" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    /// \see \ref sbe_example::MsgId
    template <typename... TOpt>
    class templateId : public
        comms::field::EnumValue<
            FieldBase,
            sbe_example::MsgId,
            TOpt...,
            comms::option::DefaultNumValue<1>,
            comms::option::ValidNumValue<1>
        >
    {
        using Base =
            comms::field::EnumValue<
                FieldBase,
                sbe_example::MsgId,
                TOpt...,
                comms::option::DefaultNumValue<1>,
                comms::option::ValidNumValue<1>
            >;

    public:

        /// \brief Update current message version.
        /// \details Does nothing.
        /// \return \b false to indicate nothing has changed.
        static bool setVersion(unsigned)
        {
            return false;
        }
    };

    /// \brief Definition of "schemaId" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class schemaId : public
        comms::field::IntValue<
            FieldBase,
            std::uint16_t,
            TOpt...,
            comms::option::DefaultNumValue<1>,
            comms::option::FailOnInvalid<comms::ErrorStatus::ProtocolError>,
            comms::option::ValidNumValue<1>
        >
    {
        using Base =
            comms::field::IntValue<
                FieldBase,
                std::uint16_t,
                TOpt...,
                comms::option::DefaultNumValue<1>,
                comms::option::FailOnInvalid<comms::ErrorStatus::ProtocolError>,
                comms::option::ValidNumValue<1>
            >;

    public:
        /// \brief Update current message version.
        /// \details Does nothing.
        /// \return \b false to indicate nothing has changed.
        static bool setVersion(unsigned)
        {
            return false;
        }
    };

    /// \brief Definition of "version" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class version : public
        comms::field::IntValue<
            FieldBase,
            std::uint16_t,
            TOpt...,
            comms::option::DefaultNumValue<1>,
            comms::option::ValidNumValueRange<0, 65534L>
        >
    {
        using Base =
            comms::field::IntValue<
                FieldBase,
                std::uint16_t,
                TOpt...,
                comms::option::DefaultNumValue<1>,
                comms::option::ValidNumValueRange<0, 65534L>
            >;

    public:
        /// \brief Update current message version.
        /// \details Does nothing.
        /// \return \b false to indicate nothing has changed.
        static bool setVersion(unsigned)
        {
            return false;
        }
    };

    /// \brief Bundling all the defined member types into a single std::tuple.
    /// \tparam TOpt_blockLength Extra options for \ref blockLength from \b comms::option namespace.
    /// \tparam TOpt_templateId Extra options for \ref templateId from \b comms::option namespace.
    /// \tparam TOpt_schemaId Extra options for \ref schemaId from \b comms::option namespace.
    /// \tparam TOpt_version Extra options for \ref version from \b comms::option namespace.
    template<
        typename TOpt_blockLength = comms::option::EmptyOption,
        typename TOpt_templateId = comms::option::EmptyOption,
        typename TOpt_schemaId = comms::option::EmptyOption,
        typename TOpt_version = comms::option::EmptyOption
    >
    using All = std::tuple<
        blockLength<TOpt_blockLength>,
        templateId<TOpt_templateId>,
        schemaId<TOpt_schemaId>,
        version<TOpt_version>
    >;
};

/// \brief Definition of "messageHeader" field.
/// \details Message identifiers and length of message root
/// \tparam TOpt_blockLength Extra options for \ref messageHeaderMembers::blockLength from \b comms::option namespace.
/// \tparam TOpt_templateId Extra options for \ref messageHeaderMembers::templateId from \b comms::option namespace.
/// \tparam TOpt_schemaId Extra options for \ref messageHeaderMembers::schemaId from \b comms::option namespace.
/// \tparam TOpt_version Extra options for \ref messageHeaderMembers::version from \b comms::option namespace.
template<
    typename TOpt_blockLength = comms::option::EmptyOption,
    typename TOpt_templateId = comms::option::EmptyOption,
    typename TOpt_schemaId = comms::option::EmptyOption,
    typename TOpt_version = comms::option::EmptyOption
>
class messageHeader : public
    comms::field::Bundle<
        FieldBase,
        messageHeaderMembers::All<
            TOpt_blockLength,
            TOpt_templateId,
            TOpt_schemaId,
            TOpt_version
        >
    >
{
    using Base =
        comms::field::Bundle<
            FieldBase,
            messageHeaderMembers::All<
                TOpt_blockLength,
                TOpt_templateId,
                TOpt_schemaId,
                TOpt_version
            >
        >;

public:
    /// \brief Allow access to internal fields.
    /// \details See definition of \b COMMS_FIELD_MEMBERS_ACCESS macro
    ///     related to \b comms::field::Bundle class from COMMS library
    ///     for details.\n
    ///     The names are:
    ///     \li \b blockLength for \ref messageHeaderMembers::blockLength.
    ///     \li \b templateId for \ref messageHeaderMembers::templateId.
    ///     \li \b schemaId for \ref messageHeaderMembers::schemaId.
    ///     \li \b version for \ref messageHeaderMembers::version.
    COMMS_FIELD_MEMBERS_ACCESS(
        blockLength,
        templateId,
        schemaId,
        version
    );

    /// \brief Update current message version.
    /// \details Calls setVersion() of every member.
    /// \return \b true if any of the fields returns \b true.
    bool setVersion(unsigned value)
    {
        return comms::util::tupleAccumulate(Base::value(), false, sbe2comms::VersionSetter(value));
    }
};

} // namespace field

} // namespace sbe_example

