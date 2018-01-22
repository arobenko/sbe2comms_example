/// \file
/// \brief Contains definition of \ref extension::DefaultOptions default options class.


#pragma once

#include "comms/options.h"

namespace extension
{

/// \brief Default options for the protocol.
/// \details Defines \b comms::option::EmptyOption to be extra option
///     of every defined field. To customize the protocol options, just
///     inherith from this struct and redefine relevant types.
/// \headerfile "extension/DefaultOptions.h"
struct DefaultOptions
{
    /// \brief Scope for the options relevant to fields from
    ///     extension::field namespace.
    struct field
    {
        /// \brief Default options for \ref extension::field::BooleanType field.
        using BooleanType = comms::option::EmptyOption;

        /// \brief Scope for the options of the fields defined in \ref extension::field::BoosterMembers.
        struct BoosterMembers
        {
            /// \brief Default options for \ref extension::field::BoosterMembers::BoostType field.
            using BoostType = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::field::BoosterMembers::horsePower field.
            using horsePower = comms::option::EmptyOption;

        };

        /// \brief Scope for the options of the fields defined in \ref extension::field::EngineMembers.
        struct EngineMembers
        {
            /// \brief Default options for \ref extension::field::EngineMembers::capacity field.
            using capacity = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::field::EngineMembers::numCylinders field.
            using numCylinders = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::field::EngineMembers::maxRpm field.
            using maxRpm = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::field::EngineMembers::manufacturerCode field.
            using manufacturerCode = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::field::EngineMembers::fuel field.
            using fuel = comms::option::EmptyOption;

        };

        /// \brief Default options for \ref extension::field::Model field.
        using Model = comms::option::EmptyOption;

        /// \brief Default options for \ref extension::field::ModelYear field.
        using ModelYear = comms::option::EmptyOption;

        /// \brief Default options for \ref extension::field::OptionalExtras field.
        using OptionalExtras = comms::option::EmptyOption;

        /// \brief Default options for \ref extension::field::Percentage field.
        using Percentage = comms::option::EmptyOption;

        /// \brief Default options for \ref extension::field::Ron field.
        using Ron = comms::option::EmptyOption;

        /// \brief Default options for \ref extension::field::VehicleCode field.
        using VehicleCode = comms::option::EmptyOption;

        /// \brief Default options for \ref extension::field::cupHolderCount_t field.
        using cupHolderCount_t = comms::option::EmptyOption;

        /// \brief Scope for the options of the fields defined in \ref extension::field::groupSizeEncodingMembers.
        struct groupSizeEncodingMembers
        {
            /// \brief Default options for \ref extension::field::groupSizeEncodingMembers::blockLength field.
            using blockLength = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::field::groupSizeEncodingMembers::numInGroup field.
            using numInGroup = comms::option::EmptyOption;

        };

        /// \brief Scope for the options of the fields defined in \ref extension::field::messageHeaderMembers.
        struct messageHeaderMembers
        {
            /// \brief Default options for \ref extension::field::messageHeaderMembers::blockLength field.
            using blockLength = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::field::messageHeaderMembers::templateId field.
            using templateId = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::field::messageHeaderMembers::schemaId field.
            using schemaId = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::field::messageHeaderMembers::version field.
            using version = comms::option::EmptyOption;

        };

        /// \brief Default options for \ref extension::field::someNumbers field.
        using someNumbers = comms::option::EmptyOption;

        /// \brief Scope for the options of the fields defined in \ref extension::field::varDataEncodingMembers.
        struct varDataEncodingMembers
        {
            /// \brief Default options for \ref extension::field::varDataEncodingMembers::length_ field.
            using length_ = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::field::varDataEncodingMembers::varData field.
            using varData = comms::option::EmptyOption;

        };

        /// \brief Scope for the options of the fields defined in \ref extension::field::varStringEncodingMembers.
        struct varStringEncodingMembers
        {
            /// \brief Default options for \ref extension::field::varStringEncodingMembers::length_ field.
            using length_ = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::field::varStringEncodingMembers::varData field.
            using varData = comms::option::EmptyOption;

        };

    }; // field

    /// \brief Scope for all the options relevant to messages' fields.
    struct message
    {
        /// \brief Scope for all the options for the fields of
        ///     \ref extension::message::Car message.
        struct CarFields
        {
            /// \brief Default options for \ref extension::message::CarFields::serialNumber field.
            using serialNumber = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::message::CarFields::modelYear field.
            using modelYear = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::message::CarFields::available field.
            using available = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::message::CarFields::code field.
            using code = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::message::CarFields::someNumbers field.
            using someNumbers = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::message::CarFields::vehicleCode field.
            using vehicleCode = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::message::CarFields::extras field.
            using extras = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::message::CarFields::discountedModel field.
            using discountedModel = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::message::CarFields::engine field.
            using engine = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::message::CarFields::cupHolderCount field.
            using cupHolderCount = comms::option::EmptyOption;

            /// \brief Scope for the options of \ref extension::message::CarFields::fuelFigures field members.
            struct fuelFiguresMembers
            {
                /// \brief Default options for \ref extension::message::CarFields::fuelFiguresMembers::speed field.
                using speed = comms::option::EmptyOption;

                /// \brief Default options for \ref extension::message::CarFields::fuelFiguresMembers::mpg field.
                using mpg = comms::option::EmptyOption;

                /// \brief Default options for \ref extension::message::CarFields::fuelFiguresMembers::usageDescription field.
                using usageDescription = comms::option::EmptyOption;

            };

            /// \brief Default options for \ref extension::message::CarFields::fuelFigures field.
            using fuelFigures = comms::option::EmptyOption;

            /// \brief Scope for the options of \ref extension::message::CarFields::performanceFigures field members.
            struct performanceFiguresMembers
            {
                /// \brief Default options for \ref extension::message::CarFields::performanceFiguresMembers::octaneRating field.
                using octaneRating = comms::option::EmptyOption;

                /// \brief Scope for the options of \ref extension::message::CarFields::performanceFiguresMembers::acceleration field members.
                struct accelerationMembers
                {
                    /// \brief Default options for \ref extension::message::CarFields::performanceFiguresMembers::accelerationMembers::mph field.
                    using mph = comms::option::EmptyOption;

                    /// \brief Default options for \ref extension::message::CarFields::performanceFiguresMembers::accelerationMembers::seconds field.
                    using seconds = comms::option::EmptyOption;

                };

                /// \brief Default options for \ref extension::message::CarFields::performanceFiguresMembers::acceleration field.
                using acceleration = comms::option::EmptyOption;

            };

            /// \brief Default options for \ref extension::message::CarFields::performanceFigures field.
            using performanceFigures = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::message::CarFields::manufacturer field.
            using manufacturer = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::message::CarFields::model field.
            using model = comms::option::EmptyOption;

            /// \brief Default options for \ref extension::message::CarFields::activationCode field.
            using activationCode = comms::option::EmptyOption;

        }; // CarFields

    }; // message

}; // DefaultOptions

} // namespace extension

