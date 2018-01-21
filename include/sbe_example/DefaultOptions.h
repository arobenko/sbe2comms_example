/// \file
/// \brief Contains definition of \ref sbe_example::DefaultOptions default options class.


#pragma once

#include "comms/options.h"

namespace sbe_example
{

/// \brief Default options for the protocol.
/// \details Defines \b comms::option::EmptyOption to be extra option
///     of every defined field. To customize the protocol options, just
///     inherith from this struct and redefine relevant types.
/// \headerfile "sbe_example/DefaultOptions.h"
struct DefaultOptions
{
    /// \brief Scope for the options relevant to fields from
    ///     sbe_example::field namespace.
    struct field
    {
        /// \brief Default options for \ref sbe_example::field::BooleanType field.
        using BooleanType = comms::option::EmptyOption;

        /// \brief Scope for the options of the fields defined in \ref sbe_example::field::BoosterMembers.
        struct BoosterMembers
        {
            /// \brief Default options for \ref sbe_example::field::BoosterMembers::BoostType field.
            using BoostType = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::field::BoosterMembers::horsePower field.
            using horsePower = comms::option::EmptyOption;

        };

        /// \brief Scope for the options of the fields defined in \ref sbe_example::field::EngineMembers.
        struct EngineMembers
        {
            /// \brief Default options for \ref sbe_example::field::EngineMembers::capacity field.
            using capacity = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::field::EngineMembers::numCylinders field.
            using numCylinders = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::field::EngineMembers::maxRpm field.
            using maxRpm = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::field::EngineMembers::manufacturerCode field.
            using manufacturerCode = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::field::EngineMembers::fuel field.
            using fuel = comms::option::EmptyOption;

        };

        /// \brief Default options for \ref sbe_example::field::Model field.
        using Model = comms::option::EmptyOption;

        /// \brief Default options for \ref sbe_example::field::ModelYear field.
        using ModelYear = comms::option::EmptyOption;

        /// \brief Default options for \ref sbe_example::field::OptionalExtras field.
        using OptionalExtras = comms::option::EmptyOption;

        /// \brief Default options for \ref sbe_example::field::Percentage field.
        using Percentage = comms::option::EmptyOption;

        /// \brief Default options for \ref sbe_example::field::Ron field.
        using Ron = comms::option::EmptyOption;

        /// \brief Default options for \ref sbe_example::field::VehicleCode field.
        using VehicleCode = comms::option::EmptyOption;

        /// \brief Default options for \ref sbe_example::field::cupHolderCount_t field.
        using cupHolderCount_t = comms::option::EmptyOption;

        /// \brief Scope for the options of the fields defined in \ref sbe_example::field::groupSizeEncodingMembers.
        struct groupSizeEncodingMembers
        {
            /// \brief Default options for \ref sbe_example::field::groupSizeEncodingMembers::blockLength field.
            using blockLength = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::field::groupSizeEncodingMembers::numInGroup field.
            using numInGroup = comms::option::EmptyOption;

        };

        /// \brief Scope for the options of the fields defined in \ref sbe_example::field::messageHeaderMembers.
        struct messageHeaderMembers
        {
            /// \brief Default options for \ref sbe_example::field::messageHeaderMembers::blockLength field.
            using blockLength = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::field::messageHeaderMembers::templateId field.
            using templateId = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::field::messageHeaderMembers::schemaId field.
            using schemaId = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::field::messageHeaderMembers::version field.
            using version = comms::option::EmptyOption;

        };

        /// \brief Default options for \ref sbe_example::field::someNumbers field.
        using someNumbers = comms::option::EmptyOption;

        /// \brief Scope for the options of the fields defined in \ref sbe_example::field::varDataEncodingMembers.
        struct varDataEncodingMembers
        {
            /// \brief Default options for \ref sbe_example::field::varDataEncodingMembers::length_ field.
            using length_ = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::field::varDataEncodingMembers::varData field.
            using varData = comms::option::EmptyOption;

        };

        /// \brief Scope for the options of the fields defined in \ref sbe_example::field::varStringEncodingMembers.
        struct varStringEncodingMembers
        {
            /// \brief Default options for \ref sbe_example::field::varStringEncodingMembers::length_ field.
            using length_ = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::field::varStringEncodingMembers::varData field.
            using varData = comms::option::EmptyOption;

        };

    }; // field

    /// \brief Scope for all the options relevant to messages' fields.
    struct message
    {
        /// \brief Scope for all the options for the fields of
        ///     \ref sbe_example::message::Car message.
        struct CarFields
        {
            /// \brief Default options for \ref sbe_example::message::CarFields::serialNumber field.
            using serialNumber = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::message::CarFields::modelYear field.
            using modelYear = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::message::CarFields::available field.
            using available = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::message::CarFields::code field.
            using code = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::message::CarFields::someNumbers field.
            using someNumbers = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::message::CarFields::vehicleCode field.
            using vehicleCode = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::message::CarFields::extras field.
            using extras = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::message::CarFields::discountedModel field.
            using discountedModel = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::message::CarFields::engine field.
            using engine = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::message::CarFields::cupHolderCount field.
            using cupHolderCount = comms::option::EmptyOption;

            /// \brief Scope for the options of \ref sbe_example::message::CarFields::fuelFigures field members.
            struct fuelFiguresMembers
            {
                /// \brief Default options for \ref sbe_example::message::CarFields::fuelFiguresMembers::speed field.
                using speed = comms::option::EmptyOption;

                /// \brief Default options for \ref sbe_example::message::CarFields::fuelFiguresMembers::mpg field.
                using mpg = comms::option::EmptyOption;

                /// \brief Default options for \ref sbe_example::message::CarFields::fuelFiguresMembers::usageDescription field.
                using usageDescription = comms::option::EmptyOption;

            };

            /// \brief Default options for \ref sbe_example::message::CarFields::fuelFigures field.
            using fuelFigures = comms::option::EmptyOption;

            /// \brief Scope for the options of \ref sbe_example::message::CarFields::performanceFigures field members.
            struct performanceFiguresMembers
            {
                /// \brief Default options for \ref sbe_example::message::CarFields::performanceFiguresMembers::octaneRating field.
                using octaneRating = comms::option::EmptyOption;

                /// \brief Scope for the options of \ref sbe_example::message::CarFields::performanceFiguresMembers::acceleration field members.
                struct accelerationMembers
                {
                    /// \brief Default options for \ref sbe_example::message::CarFields::performanceFiguresMembers::accelerationMembers::mph field.
                    using mph = comms::option::EmptyOption;

                    /// \brief Default options for \ref sbe_example::message::CarFields::performanceFiguresMembers::accelerationMembers::seconds field.
                    using seconds = comms::option::EmptyOption;

                };

                /// \brief Default options for \ref sbe_example::message::CarFields::performanceFiguresMembers::acceleration field.
                using acceleration = comms::option::EmptyOption;

            };

            /// \brief Default options for \ref sbe_example::message::CarFields::performanceFigures field.
            using performanceFigures = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::message::CarFields::manufacturer field.
            using manufacturer = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::message::CarFields::model field.
            using model = comms::option::EmptyOption;

            /// \brief Default options for \ref sbe_example::message::CarFields::activationCode field.
            using activationCode = comms::option::EmptyOption;

        }; // CarFields

    }; // message

}; // DefaultOptions

} // namespace sbe_example

