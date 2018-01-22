/// \file
/// \brief Contains definition of extension::message::Car message and its fields.

#pragma once

#include <iterator>

#include "comms/Assert.h"
#include "comms/MessageBase.h"
#include "comms/util/Tuple.h"

#include "extension/DefaultOptions.h"
#include "extension/MsgId.h"
#include "extension/field/BooleanType.h"
#include "extension/field/Engine.h"
#include "extension/field/FieldBase.h"
#include "extension/field/Model.h"
#include "extension/field/ModelYear.h"
#include "extension/field/OptionalExtras.h"
#include "extension/field/Ron.h"
#include "extension/field/VehicleCode.h"
#include "extension/field/cupHolderCount_t.h"
#include "extension/field/groupSizeEncoding.h"
#include "extension/field/someNumbers.h"
#include "extension/field/varStringEncoding.h"
#include "extension/sbe2comms/VersionSetter.h"
#include "extension/sbe2comms/float.h"
#include "extension/sbe2comms/groupList.h"
#include "extension/sbe2comms/uint16.h"
#include "extension/sbe2comms/uint64.h"

#include <iterator>

namespace extension
{

namespace message
{

/// \brief Accumulates details of all the Car message fields.
/// \tparam TOpt Extra options to be passed to all fields.
/// \see \ref Car
/// \headerfile "extension/message/Car.h"
template <typename TOpt = DefaultOptions>
struct CarFields
{
    /// \brief Definition of "serialNumber" field.
    using serialNumber = sbe2comms::uint64<
        extension::field::FieldBase,
        typename TOpt::message::CarFields::serialNumber
    >;

    /// \brief Definition of "modelYear" field.
    using modelYear = field::ModelYear<
        typename TOpt::field::ModelYear,
        typename TOpt::message::CarFields::modelYear
    >;

    /// \brief Definition of "available" field.
    using available = field::BooleanType<
        typename TOpt::field::BooleanType,
        typename TOpt::message::CarFields::available
    >;

    /// \brief Definition of "code" field.
    using code = field::Model<
        typename TOpt::field::Model,
        typename TOpt::message::CarFields::code
    >;

    /// \brief Definition of "someNumbers" field.
    using someNumbers = field::someNumbers<
        typename TOpt::field::someNumbers,
        typename TOpt::message::CarFields::someNumbers
    >;

    /// \brief Definition of "vehicleCode" field.
    using vehicleCode = field::VehicleCode<
        typename TOpt::field::VehicleCode,
        typename TOpt::message::CarFields::vehicleCode
    >;

    /// \brief Definition of "extras" field.
    using extras = field::OptionalExtras<
        typename TOpt::field::OptionalExtras,
        typename TOpt::message::CarFields::extras
    >;

    /// \brief Definition of "discountedModel" field.
    using discountedModel =
        field::Model<
            typename TOpt::field::Model,
            typename TOpt::message::CarFields::discountedModel,
            comms::option::DefaultNumValue<(std::intmax_t)field::ModelVal::C>,
            comms::option::EmptySerialization
        >;

    /// \brief Definition of "engine" field.
    using engine = field::Engine<
        typename TOpt::field::EngineMembers::capacity,
        typename TOpt::field::EngineMembers::numCylinders,
        typename TOpt::field::EngineMembers::maxRpm,
        typename TOpt::field::EngineMembers::manufacturerCode,
        typename TOpt::field::EngineMembers::fuel,
        typename TOpt::field::Percentage,
        typename TOpt::field::BooleanType,
        typename TOpt::field::BoosterMembers::BoostType,
        typename TOpt::field::BoosterMembers::horsePower
    >;

    /// \brief Definition of "cupHolderCount" field.
    using cupHolderCount = field::cupHolderCount_t<
        typename TOpt::field::cupHolderCount_t,
        typename TOpt::message::CarFields::cupHolderCount
    >;

    /// \brief Scope for all the members of the \ref fuelFigures field.
    struct fuelFiguresMembers
    {
        /// \brief Definition of "speed" field.
        using speed = sbe2comms::uint16<
            extension::field::FieldBase,
            typename TOpt::message::CarFields::fuelFiguresMembers::speed
        >;

        /// \brief Definition of "mpg" field.
        using mpg = sbe2comms::float_<
            extension::field::FieldBase,
            typename TOpt::message::CarFields::fuelFiguresMembers::mpg
        >;

        /// \brief Definition of "usageDescription" field.
        using usageDescription = 
            field::varStringEncoding<
                typename TOpt::field::varStringEncodingMembers::length_,
                typename TOpt::field::varStringEncodingMembers::varData,
                typename TOpt::message::CarFields::fuelFiguresMembers::usageDescription
            >;

        /// \brief Bundling all the defined member types into a single std::tuple.
        using All = std::tuple<
            speed,
            mpg,
            usageDescription
        >;
    };

    /// \brief Element of \ref fuelFigures list.
    class fuelFiguresElement : public
        comms::field::Bundle<
            extension::field::FieldBase,
            typename fuelFiguresMembers::All
        >
    {
        using Base =
            comms::field::Bundle<
                extension::field::FieldBase,
                typename fuelFiguresMembers::All
            >;

    public:
        /// \brief Allow access to internal fields.
        /// \details See definition of \b COMMS_FIELD_MEMBERS_ACCESS macro
        ///     related to \b comms::field::Bundle class from COMMS library
        ///     for details.
        COMMS_FIELD_MEMBERS_ACCESS(
            speed,
            mpg,
            usageDescription
        );
    };

    /// \brief Definition of "fuelFigures" field.
    using fuelFigures =
        sbe2comms::groupList<
            extension::field::FieldBase,
            fuelFiguresElement,
            field::groupSizeEncoding<
                typename TOpt::field::groupSizeEncodingMembers::blockLength,
                typename TOpt::field::groupSizeEncodingMembers::numInGroup
            >,
            2,
            typename TOpt::message::CarFields::fuelFigures
        >;

    /// \brief Scope for all the members of the \ref performanceFigures field.
    struct performanceFiguresMembers
    {
        /// \brief Definition of "octaneRating" field.
        using octaneRating = field::Ron<
            typename TOpt::field::Ron,
            typename TOpt::message::CarFields::performanceFiguresMembers::octaneRating
        >;

        /// \brief Scope for all the members of the \ref acceleration field.
        struct accelerationMembers
        {
            /// \brief Definition of "mph" field.
            using mph = sbe2comms::uint16<
                extension::field::FieldBase,
                typename TOpt::message::CarFields::performanceFiguresMembers::accelerationMembers::mph
            >;

            /// \brief Definition of "seconds" field.
            using seconds = sbe2comms::float_<
                extension::field::FieldBase,
                typename TOpt::message::CarFields::performanceFiguresMembers::accelerationMembers::seconds
            >;

            /// \brief Bundling all the defined member types into a single std::tuple.
            using All = std::tuple<
                mph,
                seconds
            >;
        };

        /// \brief Element of \ref acceleration list.
        class accelerationElement : public
            comms::field::Bundle<
                extension::field::FieldBase,
                typename accelerationMembers::All
            >
        {
            using Base =
                comms::field::Bundle<
                    extension::field::FieldBase,
                    typename accelerationMembers::All
                >;

        public:
            /// \brief Allow access to internal fields.
            /// \details See definition of \b COMMS_FIELD_MEMBERS_ACCESS macro
            ///     related to \b comms::field::Bundle class from COMMS library
            ///     for details.
            COMMS_FIELD_MEMBERS_ACCESS(
                mph,
                seconds
            );
        };

        /// \brief Definition of "acceleration" field.
        using acceleration =
            sbe2comms::groupList<
                extension::field::FieldBase,
                accelerationElement,
                field::groupSizeEncoding<
                    typename TOpt::field::groupSizeEncodingMembers::blockLength,
                    typename TOpt::field::groupSizeEncodingMembers::numInGroup
                >,
                2,
                typename TOpt::message::CarFields::performanceFiguresMembers::acceleration
            >;

        /// \brief Bundling all the defined member types into a single std::tuple.
        using All = std::tuple<
            octaneRating,
            acceleration
        >;
    };

    /// \brief Element of \ref performanceFigures list.
    class performanceFiguresElement : public
        comms::field::Bundle<
            extension::field::FieldBase,
            typename performanceFiguresMembers::All
        >
    {
        using Base =
            comms::field::Bundle<
                extension::field::FieldBase,
                typename performanceFiguresMembers::All
            >;

    public:
        /// \brief Allow access to internal fields.
        /// \details See definition of \b COMMS_FIELD_MEMBERS_ACCESS macro
        ///     related to \b comms::field::Bundle class from COMMS library
        ///     for details.
        COMMS_FIELD_MEMBERS_ACCESS(
            octaneRating,
            acceleration
        );
    };

    /// \brief Definition of "performanceFigures" field.
    using performanceFigures =
        sbe2comms::groupList<
            extension::field::FieldBase,
            performanceFiguresElement,
            field::groupSizeEncoding<
                typename TOpt::field::groupSizeEncodingMembers::blockLength,
                typename TOpt::field::groupSizeEncodingMembers::numInGroup
            >,
            1,
            typename TOpt::message::CarFields::performanceFigures
        >;

    /// \brief Definition of "manufacturer" field.
    using manufacturer = 
        field::varStringEncoding<
            typename TOpt::field::varStringEncodingMembers::length_,
            typename TOpt::field::varStringEncodingMembers::varData,
            typename TOpt::message::CarFields::manufacturer
        >;

    /// \brief Definition of "model" field.
    using model = 
        field::varStringEncoding<
            typename TOpt::field::varStringEncodingMembers::length_,
            typename TOpt::field::varStringEncodingMembers::varData,
            typename TOpt::message::CarFields::model
        >;

    /// \brief Definition of "activationCode" field.
    using activationCode = 
        field::varStringEncoding<
            typename TOpt::field::varStringEncodingMembers::length_,
            typename TOpt::field::varStringEncodingMembers::varData,
            typename TOpt::message::CarFields::activationCode
        >;

    /// \brief All the fields bundled in std::tuple.
    using All = std::tuple<
        serialNumber,
        modelYear,
        available,
        code,
        someNumbers,
        vehicleCode,
        extras,
        discountedModel,
        engine,
        cupHolderCount,
        fuelFigures,
        performanceFigures,
        manufacturer,
        model,
        activationCode
    >;

}; // CarFields

/// \brief Definition of Car message
/// \details Description of a basic Car\n
///     Inherits from \b comms::MessageBase
///     while providing \b TMsgBase as common interface class as well as
///     various implementation options.
///     \n See \ref CarFields for definition of the fields this message contains
///         and COMMS_MSG_FIELDS_ACCESS() for fields access details.
/// \tparam TMsgBase Common interface class for all the messages.
/// \tparam TOpt Extra options to be passed to all fields.
/// \headerfile "extension/message/Car.h"
template <typename TMsgBase, typename TOpt = DefaultOptions>
class Car : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<extension::MsgId_Car>,
        comms::option::MsgType<Car<TMsgBase, TOpt> >,
        comms::option::FieldsImpl<typename CarFields<TOpt>::All>,
        comms::option::HasDoRefresh
    >
{
    using Base =
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<extension::MsgId_Car>,
        comms::option::MsgType<Car<TMsgBase, TOpt> >,
        comms::option::FieldsImpl<typename CarFields<TOpt>::All>,
        comms::option::HasDoRefresh
    >;

public:
    /// \brief Allow access to internal fields.
    /// \details See definition of \b COMMS_MSG_FIELDS_ACCESS macro
    ///     related to \b comms::MessageBase class from COMMS library
    ///     for details.
    ///     
    ///     The field names are:
    ///     \li \b serialNumber for \ref CarFields::serialNumber field.
    ///     \li \b modelYear for \ref CarFields::modelYear field.
    ///     \li \b available for \ref CarFields::available field.
    ///     \li \b code for \ref CarFields::code field.
    ///     \li \b someNumbers for \ref CarFields::someNumbers field.
    ///     \li \b vehicleCode for \ref CarFields::vehicleCode field.
    ///     \li \b extras for \ref CarFields::extras field.
    ///     \li \b discountedModel for \ref CarFields::discountedModel field.
    ///     \li \b engine for \ref CarFields::engine field.
    ///     \li \b cupHolderCount for \ref CarFields::cupHolderCount field.
    ///     \li \b fuelFigures for \ref CarFields::fuelFigures field.
    ///     \li \b performanceFigures for \ref CarFields::performanceFigures field.
    ///     \li \b manufacturer for \ref CarFields::manufacturer field.
    ///     \li \b model for \ref CarFields::model field.
    ///     \li \b activationCode for \ref CarFields::activationCode field.
    COMMS_MSG_FIELDS_ACCESS(
        serialNumber,
        modelYear,
        available,
        code,
        someNumbers,
        vehicleCode,
        extras,
        discountedModel,
        engine,
        cupHolderCount,
        fuelFigures,
        performanceFigures,
        manufacturer,
        model,
        activationCode
    );

    /// \brief Default constructor.
    /// \details Sets the \"blockLength\" value.
    Car()
    {
        Base::setBlockLength(Base::template doMaxLengthUntil<FieldIdx_fuelFigures>());
    }

    /// \brief Copy constructor.
    Car(const Car&) = default;

    /// \brief Move constructor.
    Car(Car&&) = default;

    /// \brief Copy assignment.
    Car& operator=(const Car&) = default;

    /// \brief Move assignment.
    Car& operator=(Car&&) = default;

    /// \brief Custom read functionality.
    template <typename TIter>
    comms::ErrorStatus doRead(TIter& iter, std::size_t len)
    {
        GASSERT(Base::getBlockLength() <= len);
        updateFieldsVersion();
        auto iterTmp = iter;
        std::size_t rootBlockLen = Base::getBlockLength();
        auto es = Base::template doReadFieldsUntil<FieldIdx_fuelFigures>(iterTmp, rootBlockLen);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }

        std::advance(iter, Base::getBlockLength());
        auto remLen = len - rootBlockLen;
        return Base::template doReadFieldsFrom<FieldIdx_fuelFigures>(iter, remLen);
    }

    /// \brief Custom refresh functionality.
    bool doRefresh()
    {
        bool updated = updateFieldsVersion();
        std::size_t currBlockLength = Base::template doLengthUntil<FieldIdx_fuelFigures>();
        if (currBlockLength == Base::getBlockLength()) {
            return updated;
        }

        Base::setBlockLength(currBlockLength);
        return true;
    }

private:
    bool updateFieldsVersion()
    {
        return comms::util::tupleAccumulate(Base::fields(), false, sbe2comms::VersionSetter(Base::getVersion()));
    }
;};

} // namespace message

} // namespace extension

