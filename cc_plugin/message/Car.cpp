#include "Car.h"

#include <cassert>
#include <QtCore/QVariantList>
#include "cc_plugin/field.h"

namespace extension
{

namespace cc_plugin
{

namespace message
{

namespace
{

QVariantMap createFieldProps_serialNumber()
{
    using Field_extension_message_CarFields_serialNumber = extension::message::CarFields<>::serialNumber;
    auto props_extension_message_CarFields_serialNumber = 
        comms_champion::property::field::ForField<Field_extension_message_CarFields_serialNumber>()
            .name("serialNumber")
            .asMap();

    return props_extension_message_CarFields_serialNumber;
}

QVariantMap createFieldProps_modelYear()
{
    auto props_extension_message_CarFields_modelYear =
        cc_plugin::field::createProps_ModelYear("modelYear");

    return props_extension_message_CarFields_modelYear;
}

QVariantMap createFieldProps_available()
{
    auto props_extension_message_CarFields_available =
        cc_plugin::field::createProps_BooleanType("available");

    return props_extension_message_CarFields_available;
}

QVariantMap createFieldProps_code()
{
    auto props_extension_message_CarFields_code =
        cc_plugin::field::createProps_Model("code");

    return props_extension_message_CarFields_code;
}

QVariantMap createFieldProps_someNumbers()
{
    auto props_extension_message_CarFields_someNumbers =
        cc_plugin::field::createProps_someNumbers("someNumbers");

    return props_extension_message_CarFields_someNumbers;
}

QVariantMap createFieldProps_vehicleCode()
{
    auto props_extension_message_CarFields_vehicleCode =
        cc_plugin::field::createProps_VehicleCode("vehicleCode");

    return props_extension_message_CarFields_vehicleCode;
}

QVariantMap createFieldProps_extras()
{
    auto props_extension_message_CarFields_extras =
        cc_plugin::field::createProps_OptionalExtras("extras");

    return props_extension_message_CarFields_extras;
}

QVariantMap createFieldProps_discountedModel()
{
    using Field_extension_message_CarFields_discountedModel = extension::message::CarFields<>::discountedModel;
    auto props_extension_message_CarFields_discountedModel =
        comms_champion::property::field::ForField<Field_extension_message_CarFields_discountedModel>(
                cc_plugin::field::createProps_Model("discountedModel"))
            .serialisedHidden()
            .readOnly()
            .asMap();

    return props_extension_message_CarFields_discountedModel;
}

QVariantMap createFieldProps_engine()
{
    auto props_extension_message_CarFields_engine =
        cc_plugin::field::createProps_Engine("engine");

    return props_extension_message_CarFields_engine;
}

QVariantMap createFieldProps_cupHolderCount()
{
    auto props_extension_message_CarFields_cupHolderCount =
        cc_plugin::field::createProps_cupHolderCount_t("cupHolderCount");

    return props_extension_message_CarFields_cupHolderCount;
}

QVariantMap createFieldProps_fuelFigures()
{
    using Field_extension_message_CarFields_fuelFigures_Element = extension::message::CarFields<>::fuelFiguresElement;
    comms_champion::property::field::ForField<Field_extension_message_CarFields_fuelFigures_Element> props_extension_message_CarFields_fuelFigures_Element;

    using Field_extension_message_CarFields_fuelFiguresMembers_speed = extension::message::CarFields<>::fuelFiguresMembers::speed;
    auto props_extension_message_CarFields_fuelFiguresMembers_speed = 
        comms_champion::property::field::ForField<Field_extension_message_CarFields_fuelFiguresMembers_speed>()
            .name("speed")
            .serialisedHidden()
            .asMap();

    props_extension_message_CarFields_fuelFigures_Element.add(props_extension_message_CarFields_fuelFiguresMembers_speed);

    using Field_extension_message_CarFields_fuelFiguresMembers_mpg = extension::message::CarFields<>::fuelFiguresMembers::mpg;
    auto props_extension_message_CarFields_fuelFiguresMembers_mpg = 
        comms_champion::property::field::ForField<Field_extension_message_CarFields_fuelFiguresMembers_mpg>()
            .name("mpg")
            .serialisedHidden()
            .asMap();

    props_extension_message_CarFields_fuelFigures_Element.add(props_extension_message_CarFields_fuelFiguresMembers_mpg);

    auto props_extension_message_CarFields_fuelFiguresMembers_usageDescription =
        cc_plugin::field::createProps_varStringEncoding("usageDescription", true);

    props_extension_message_CarFields_fuelFigures_Element.add(props_extension_message_CarFields_fuelFiguresMembers_usageDescription);

    using Field_extension_message_CarFields_fuelFigures = extension::message::CarFields<>::fuelFigures;
    auto props_extension_message_CarFields_fuelFigures =
        comms_champion::property::field::ForField<Field_extension_message_CarFields_fuelFigures>()
            .name("fuelFigures")
            .add(props_extension_message_CarFields_fuelFigures_Element.asMap())
            .asMap();

    return props_extension_message_CarFields_fuelFigures;
}

QVariantMap createFieldProps_performanceFigures()
{
    using Field_extension_message_CarFields_performanceFigures_Element = extension::message::CarFields<>::performanceFiguresElement;
    comms_champion::property::field::ForField<Field_extension_message_CarFields_performanceFigures_Element> props_extension_message_CarFields_performanceFigures_Element;

    auto props_extension_message_CarFields_performanceFiguresMembers_octaneRating =
        cc_plugin::field::createProps_Ron("octaneRating", true);

    props_extension_message_CarFields_performanceFigures_Element.add(props_extension_message_CarFields_performanceFiguresMembers_octaneRating);

    using Field_extension_message_CarFields_performanceFiguresMembers_acceleration_Element = extension::message::CarFields<>::performanceFiguresMembers::accelerationElement;
    comms_champion::property::field::ForField<Field_extension_message_CarFields_performanceFiguresMembers_acceleration_Element> props_extension_message_CarFields_performanceFiguresMembers_acceleration_Element;

    using Field_extension_message_CarFields_performanceFiguresMembers_accelerationMembers_mph = extension::message::CarFields<>::performanceFiguresMembers::accelerationMembers::mph;
    auto props_extension_message_CarFields_performanceFiguresMembers_accelerationMembers_mph = 
        comms_champion::property::field::ForField<Field_extension_message_CarFields_performanceFiguresMembers_accelerationMembers_mph>()
            .name("mph")
            .serialisedHidden()
            .asMap();

    props_extension_message_CarFields_performanceFiguresMembers_acceleration_Element.add(props_extension_message_CarFields_performanceFiguresMembers_accelerationMembers_mph);

    using Field_extension_message_CarFields_performanceFiguresMembers_accelerationMembers_seconds = extension::message::CarFields<>::performanceFiguresMembers::accelerationMembers::seconds;
    auto props_extension_message_CarFields_performanceFiguresMembers_accelerationMembers_seconds = 
        comms_champion::property::field::ForField<Field_extension_message_CarFields_performanceFiguresMembers_accelerationMembers_seconds>()
            .name("seconds")
            .serialisedHidden()
            .asMap();

    props_extension_message_CarFields_performanceFiguresMembers_acceleration_Element.add(props_extension_message_CarFields_performanceFiguresMembers_accelerationMembers_seconds);

    using Field_extension_message_CarFields_performanceFiguresMembers_acceleration = extension::message::CarFields<>::performanceFiguresMembers::acceleration;
    auto props_extension_message_CarFields_performanceFiguresMembers_acceleration =
        comms_champion::property::field::ForField<Field_extension_message_CarFields_performanceFiguresMembers_acceleration>()
            .name("acceleration")
            .add(props_extension_message_CarFields_performanceFiguresMembers_acceleration_Element.asMap())
            .serialisedHidden()
            .asMap();

    props_extension_message_CarFields_performanceFigures_Element.add(props_extension_message_CarFields_performanceFiguresMembers_acceleration);

    using Field_extension_message_CarFields_performanceFigures = extension::message::CarFields<>::performanceFigures;
    auto props_extension_message_CarFields_performanceFigures =
        comms_champion::property::field::ForField<Field_extension_message_CarFields_performanceFigures>()
            .name("performanceFigures")
            .add(props_extension_message_CarFields_performanceFigures_Element.asMap())
            .asMap();

    return props_extension_message_CarFields_performanceFigures;
}

QVariantMap createFieldProps_manufacturer()
{
    auto props_extension_message_CarFields_manufacturer =
        cc_plugin::field::createProps_varStringEncoding("manufacturer");

    return props_extension_message_CarFields_manufacturer;
}

QVariantMap createFieldProps_model()
{
    auto props_extension_message_CarFields_model =
        cc_plugin::field::createProps_varStringEncoding("model");

    return props_extension_message_CarFields_model;
}

QVariantMap createFieldProps_activationCode()
{
    auto props_extension_message_CarFields_activationCode =
        cc_plugin::field::createProps_varStringEncoding("activationCode");

    return props_extension_message_CarFields_activationCode;
}

QVariantList createFieldsProperties()
{
    QVariantList props;
    props.append(createFieldProps_serialNumber());
    props.append(createFieldProps_modelYear());
    props.append(createFieldProps_available());
    props.append(createFieldProps_code());
    props.append(createFieldProps_someNumbers());
    props.append(createFieldProps_vehicleCode());
    props.append(createFieldProps_extras());
    props.append(createFieldProps_discountedModel());
    props.append(createFieldProps_engine());
    props.append(createFieldProps_cupHolderCount());
    props.append(createFieldProps_fuelFigures());
    props.append(createFieldProps_performanceFigures());
    props.append(createFieldProps_manufacturer());
    props.append(createFieldProps_model());
    props.append(createFieldProps_activationCode());

    assert(props.size() == Car::FieldIdx_numOfValues);
    return props;
}

} // namespace

const char* Car::nameImpl() const
{
    static const char* Str = "Car";
    return Str;
}

const QVariantList& Car::fieldsPropertiesImpl() const
{
    static const auto Props = createFieldsProperties();
    return Props;
}

} // namespace message

} // namespace cc_plugin

} // namespace extension

