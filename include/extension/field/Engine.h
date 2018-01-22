/// \file
/// \brief Contains definition of \ref extension::field::Engine field.

#pragma once

#include <cstdint>

#include "comms/field/Bundle.h"
#include "comms/field/IntValue.h"
#include "comms/field/String.h"
#include "comms/util/Tuple.h"

#include "BooleanType.h"
#include "Booster.h"
#include "FieldBase.h"
#include "Percentage.h"
#include "extension/sbe2comms/VersionSetter.h"

#include <cstdint>

namespace extension
{

namespace field
{

/// \brief Scope for all the members of the \ref Engine field.
struct EngineMembers
{
    /// \brief Definition of "capacity" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class capacity : public
        comms::field::IntValue<
            extension::field::FieldBase,
            std::uint16_t,
            TOpt...,
            comms::option::ValidNumValueRange<0, 65534L>
        >
    {
        using Base =
            comms::field::IntValue<
                extension::field::FieldBase,
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

    /// \brief Definition of "numCylinders" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class numCylinders : public
        comms::field::IntValue<
            extension::field::FieldBase,
            std::uint8_t,
            TOpt...,
            comms::option::ValidNumValueRange<0, 254>
        >
    {
        using Base =
            comms::field::IntValue<
                extension::field::FieldBase,
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

    /// \brief Definition of "maxRpm" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class maxRpm : public
        comms::field::IntValue<
            extension::field::FieldBase,
            std::uint16_t,
            TOpt...,
            comms::option::ValidNumValue<9000>,
            comms::option::DefaultNumValue<9000>,
            comms::option::EmptySerialization
        >
    {
        using Base=
            comms::field::IntValue<
                extension::field::FieldBase,
                std::uint16_t,
                TOpt...,
                comms::option::ValidNumValue<9000>,
                comms::option::DefaultNumValue<9000>,
                comms::option::EmptySerialization
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

    /// \brief Definition of "manufacturerCode" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class manufacturerCode : public
        comms::field::String<
            extension::field::FieldBase,
            comms::option::SequenceFixedSize<3>,
            TOpt...
        >

    {
        using Base =
            comms::field::String<
                extension::field::FieldBase,
                comms::option::SequenceFixedSize<3>,
                TOpt...
            >
;

    public:
        /// \brief Value validity check function.
        bool valid() const
        {
            if (!Base::valid()) {
                return false;
            }

            auto& str = Base::value();
            for (auto ch : str) {
                if ((ch < 32) ||
                    (126 < ch)) {
                    return false;
                }

            }
            return true;
        }

        /// \brief Update current message version.
        /// \details Does nothing.
        /// \return \b false to indicate nothing has changed.
        static bool setVersion(unsigned)
        {
            return false;
        }
    };

    /// \brief Definition of "fuel" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class fuel : public 
        comms::field::String<
            extension::field::FieldBase,
            TOpt...,
            comms::option::EmptySerialization
        >
    {
        using Base =
            comms::field::String<
                extension::field::FieldBase,
                TOpt...,
                comms::option::EmptySerialization
            >;

    public:
        /// \brief Default constructor
        fuel()
        {
            static const char Chars[6] = {
                'P', 'e', 't', 'r', 'o', 'l'
            };

            Base::value() = Chars;
        }

        /// \brief Update current message version.
        /// \details Does nothing.
        /// \return \b false to indicate nothing has changed.
        static bool setVersion(unsigned)
        {
            return false;
        }
    };

    /// \brief Definition of "efficiency" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    using efficiency = field::Percentage<TOpt...>;

    /// \brief Definition of "boosterEnabled" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    using boosterEnabled = field::BooleanType<TOpt...>;

    /// \brief Definition of "booster" field.
    /// \tparam TOpt_booster_Booster_BoostType Extra options for \ref field::BoosterMembers::BoostType
    /// \tparam TOpt_booster_Booster_horsePower Extra options for \ref field::BoosterMembers::horsePower
    template<
        typename TOpt_booster_Booster_BoostType = comms::option::EmptyOption,
        typename TOpt_booster_Booster_horsePower = comms::option::EmptyOption
    >
    using booster = field::Booster<
        TOpt_booster_Booster_BoostType,
        TOpt_booster_Booster_horsePower
    >;

    /// \brief Bundling all the defined member types into a single std::tuple.
    /// \tparam TOpt_capacity Extra options for \ref capacity from \b comms::option namespace.
    /// \tparam TOpt_numCylinders Extra options for \ref numCylinders from \b comms::option namespace.
    /// \tparam TOpt_maxRpm Extra options for \ref maxRpm from \b comms::option namespace.
    /// \tparam TOpt_manufacturerCode Extra options for \ref manufacturerCode from \b comms::option namespace.
    /// \tparam TOpt_fuel Extra options for \ref fuel from \b comms::option namespace.
    /// \tparam TOpt_efficiency_Percentage Extra options for \ref field::Percentage from \b comms::option namespace.
    /// \tparam TOpt_boosterEnabled_BooleanType Extra options for \ref field::BooleanType from \b comms::option namespace.
    /// \tparam TOpt_booster_Booster_BoostType Extra options for \ref field::BoosterMembers::BoostType from \b comms::option namespace.
    /// \tparam TOpt_booster_Booster_horsePower Extra options for \ref field::BoosterMembers::horsePower from \b comms::option namespace.
    template<
        typename TOpt_capacity = comms::option::EmptyOption,
        typename TOpt_numCylinders = comms::option::EmptyOption,
        typename TOpt_maxRpm = comms::option::EmptyOption,
        typename TOpt_manufacturerCode = comms::option::EmptyOption,
        typename TOpt_fuel = comms::option::EmptyOption,
        typename TOpt_efficiency_Percentage = comms::option::EmptyOption,
        typename TOpt_boosterEnabled_BooleanType = comms::option::EmptyOption,
        typename TOpt_booster_Booster_BoostType = comms::option::EmptyOption,
        typename TOpt_booster_Booster_horsePower = comms::option::EmptyOption
    >
    using All = std::tuple<
        capacity<TOpt_capacity>,
        numCylinders<TOpt_numCylinders>,
        maxRpm<TOpt_maxRpm>,
        manufacturerCode<TOpt_manufacturerCode>,
        fuel<TOpt_fuel>,
        efficiency<TOpt_efficiency_Percentage>,
        boosterEnabled<TOpt_boosterEnabled_BooleanType>,
        booster<
            TOpt_booster_Booster_BoostType,
            TOpt_booster_Booster_horsePower
        >
    >;
};

/// \brief Definition of "Engine" field.
/// \tparam TOpt_capacity Extra options for \ref EngineMembers::capacity from \b comms::option namespace.
/// \tparam TOpt_numCylinders Extra options for \ref EngineMembers::numCylinders from \b comms::option namespace.
/// \tparam TOpt_maxRpm Extra options for \ref EngineMembers::maxRpm from \b comms::option namespace.
/// \tparam TOpt_manufacturerCode Extra options for \ref EngineMembers::manufacturerCode from \b comms::option namespace.
/// \tparam TOpt_fuel Extra options for \ref EngineMembers::fuel from \b comms::option namespace.
/// \tparam TOpt_efficiency_Percentage Extra options for \ref field::Percentage from \b comms::option namespace.
/// \tparam TOpt_boosterEnabled_BooleanType Extra options for \ref field::BooleanType from \b comms::option namespace.
/// \tparam TOpt_booster_Booster_BoostType Extra options for \ref field::BoosterMembers::BoostType from \b comms::option namespace.
/// \tparam TOpt_booster_Booster_horsePower Extra options for \ref field::BoosterMembers::horsePower from \b comms::option namespace.
template<
    typename TOpt_capacity = comms::option::EmptyOption,
    typename TOpt_numCylinders = comms::option::EmptyOption,
    typename TOpt_maxRpm = comms::option::EmptyOption,
    typename TOpt_manufacturerCode = comms::option::EmptyOption,
    typename TOpt_fuel = comms::option::EmptyOption,
    typename TOpt_efficiency_Percentage = comms::option::EmptyOption,
    typename TOpt_boosterEnabled_BooleanType = comms::option::EmptyOption,
    typename TOpt_booster_Booster_BoostType = comms::option::EmptyOption,
    typename TOpt_booster_Booster_horsePower = comms::option::EmptyOption
>
class Engine : public
    comms::field::Bundle<
        extension::field::FieldBase,
        EngineMembers::All<
            TOpt_capacity,
            TOpt_numCylinders,
            TOpt_maxRpm,
            TOpt_manufacturerCode,
            TOpt_fuel,
            TOpt_efficiency_Percentage,
            TOpt_boosterEnabled_BooleanType,
            TOpt_booster_Booster_BoostType,
            TOpt_booster_Booster_horsePower
        >
    >
{
    using Base =
        comms::field::Bundle<
            extension::field::FieldBase,
            EngineMembers::All<
                TOpt_capacity,
                TOpt_numCylinders,
                TOpt_maxRpm,
                TOpt_manufacturerCode,
                TOpt_fuel,
                TOpt_efficiency_Percentage,
                TOpt_boosterEnabled_BooleanType,
                TOpt_booster_Booster_BoostType,
                TOpt_booster_Booster_horsePower
            >
        >;

public:
    /// \brief Allow access to internal fields.
    /// \details See definition of \b COMMS_FIELD_MEMBERS_ACCESS macro
    ///     related to \b comms::field::Bundle class from COMMS library
    ///     for details.\n
    ///     The names are:
    ///     \li \b capacity for \ref EngineMembers::capacity.
    ///     \li \b numCylinders for \ref EngineMembers::numCylinders.
    ///     \li \b maxRpm for \ref EngineMembers::maxRpm.
    ///     \li \b manufacturerCode for \ref EngineMembers::manufacturerCode.
    ///     \li \b fuel for \ref EngineMembers::fuel.
    ///     \li \b efficiency for \ref EngineMembers::efficiency.
    ///     \li \b boosterEnabled for \ref EngineMembers::boosterEnabled.
    ///     \li \b booster for \ref EngineMembers::booster.
    COMMS_FIELD_MEMBERS_ACCESS(
        capacity,
        numCylinders,
        maxRpm,
        manufacturerCode,
        fuel,
        efficiency,
        boosterEnabled,
        booster
    );

    /// \brief Update current message version.
    /// \details Calls setVersion() of every member.
    /// \return \b true if any of the fields returns \b true.
    bool setVersion(unsigned val)
    {
        return comms::util::tupleAccumulate(Base::value(), false, sbe2comms::VersionSetter(val));
    }
};

} // namespace field

} // namespace extension

