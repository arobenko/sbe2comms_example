/// \file
/// \brief Contains definition of \ref sbe_example::field::Booster field.

#pragma once

#include <cstdint>

#include "comms/field/Bundle.h"
#include "comms/field/EnumValue.h"
#include "comms/field/IntValue.h"
#include "comms/util/Tuple.h"

#include "FieldBase.h"
#include "sbe_example/sbe2comms/VersionSetter.h"

#include <cstdint>

namespace sbe_example
{

namespace field
{

/// \brief Scope for all the members of the \ref Booster field.
struct BoosterMembers
{
    /// \brief Enumeration for \ref BoostType field.
    enum class BoostTypeVal : char
    {
        KERS = static_cast<char>(75), ///< \b KERS value.
        NITROUS = static_cast<char>(78), ///< \b NITROUS value.
        SUPERCHARGER = static_cast<char>(83), ///< \b SUPERCHARGER value.
        TURBO = static_cast<char>(84), ///< \b TURBO value.
    };

    /// \brief Definition of "BoostType" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    /// \see \ref BoostTypeVal
    template <typename... TOpt>
    class BoostType : public
        comms::field::EnumValue<
            FieldBase,
            BoostTypeVal,
            TOpt...,
            comms::option::DefaultNumValue<75>,
            comms::option::ValidNumValue<75>,
            comms::option::ValidNumValue<78>,
            comms::option::ValidNumValueRange<83, 84>
        >
    {
        using Base =
            comms::field::EnumValue<
                FieldBase,
                BoostTypeVal,
                TOpt...,
                comms::option::DefaultNumValue<75>,
                comms::option::ValidNumValue<75>,
                comms::option::ValidNumValue<78>,
                comms::option::ValidNumValueRange<83, 84>
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

    /// \brief Definition of "horsePower" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class horsePower : public
        comms::field::IntValue<
            FieldBase,
            std::uint8_t,
            TOpt...,
            comms::option::ValidNumValueRange<0, 254>
        >
    {
        using Base =
            comms::field::IntValue<
                FieldBase,
                std::uint8_t,
                TOpt...,
                comms::option::ValidNumValueRange<0, 254>
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
    /// \tparam TOpt_BoostType Extra options for \ref BoostType from \b comms::option namespace.
    /// \tparam TOpt_horsePower Extra options for \ref horsePower from \b comms::option namespace.
    template<
        typename TOpt_BoostType = comms::option::EmptyOption,
        typename TOpt_horsePower = comms::option::EmptyOption
    >
    using All = std::tuple<
        BoostType<TOpt_BoostType>,
        horsePower<TOpt_horsePower>
    >;
};

/// \brief Definition of "Booster" field.
/// \tparam TOpt_BoostType Extra options for \ref BoosterMembers::BoostType from \b comms::option namespace.
/// \tparam TOpt_horsePower Extra options for \ref BoosterMembers::horsePower from \b comms::option namespace.
template<
    typename TOpt_BoostType = comms::option::EmptyOption,
    typename TOpt_horsePower = comms::option::EmptyOption
>
class Booster : public
    comms::field::Bundle<
        FieldBase,
        BoosterMembers::All<
            TOpt_BoostType,
            TOpt_horsePower
        >
    >
{
    using Base =
        comms::field::Bundle<
            FieldBase,
            BoosterMembers::All<
                TOpt_BoostType,
                TOpt_horsePower
            >
        >;

public:
    /// \brief Allow access to internal fields.
    /// \details See definition of \b COMMS_FIELD_MEMBERS_ACCESS macro
    ///     related to \b comms::field::Bundle class from COMMS library
    ///     for details.\n
    ///     The names are:
    ///     \li \b BoostType for \ref BoosterMembers::BoostType.
    ///     \li \b horsePower for \ref BoosterMembers::horsePower.
    COMMS_FIELD_MEMBERS_ACCESS(
        BoostType,
        horsePower
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

