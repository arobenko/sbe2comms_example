#include "field.h"

#include <QtCore/QString>
#include <QtCore/QVariantList>

#include "comms_champion/comms_champion.h"

#include "extension/field/BooleanType.h"
#include "extension/field/Booster.h"
#include "extension/field/Engine.h"
#include "extension/field/Model.h"
#include "extension/field/ModelYear.h"
#include "extension/field/OptionalExtras.h"
#include "extension/field/Percentage.h"
#include "extension/field/Ron.h"
#include "extension/field/VehicleCode.h"
#include "extension/field/cupHolderCount_t.h"
#include "extension/field/groupSizeEncoding.h"
#include "extension/field/messageHeader.h"
#include "extension/field/someNumbers.h"
#include "extension/field/varDataEncoding.h"
#include "extension/field/varStringEncoding.h"

namespace extension
{

namespace cc_plugin
{

namespace field
{

QVariantMap createProps_BooleanType(const char* fieldName, bool serialishedHidden)
{
    using Field_BooleanType = extension::field::BooleanType<>;
    auto props_BooleanType = 
        comms_champion::property::field::ForField<Field_BooleanType>()
            .name(fieldName)
            .add("F", 0)
            .add("T", 1);

    if (serialishedHidden) {
        props_BooleanType.serialisedHidden();
    }

    return props_BooleanType.asMap();
}

QVariantMap createProps_Booster(const char* fieldName, bool serialishedHidden)
{
    using Field_Booster = extension::field::Booster<>;
    auto props_Booster = 
        comms_champion::property::field::ForField<Field_Booster>().name(fieldName);

    using Field_BoosterMembers_BoostType = extension::field::BoosterMembers::BoostType<>;
    auto props_BoosterMembers_BoostType = 
        comms_champion::property::field::ForField<Field_BoosterMembers_BoostType>()
            .name("BoostType")
            .add("KERS", 75)
            .add("NITROUS", 78)
            .add("SUPERCHARGER", 83)
            .add("TURBO", 84);

    if (serialishedHidden) {
        props_BoosterMembers_BoostType.serialisedHidden();
    }

    props_Booster.add(props_BoosterMembers_BoostType.asMap());

    using Field_BoosterMembers_horsePower = extension::field::BoosterMembers::horsePower<>;
    auto props_BoosterMembers_horsePower = 
        comms_champion::property::field::ForField<Field_BoosterMembers_horsePower>()
            .name("horsePower");

    if (serialishedHidden) {
        props_BoosterMembers_horsePower.serialisedHidden();
    }

    props_Booster.add(props_BoosterMembers_horsePower.asMap());

    return props_Booster.asMap();
}

QVariantMap createProps_Engine(const char* fieldName, bool serialishedHidden)
{
    using Field_Engine = extension::field::Engine<>;
    auto props_Engine = 
        comms_champion::property::field::ForField<Field_Engine>().name(fieldName);

    using Field_EngineMembers_capacity = extension::field::EngineMembers::capacity<>;
    auto props_EngineMembers_capacity = 
        comms_champion::property::field::ForField<Field_EngineMembers_capacity>()
            .name("capacity");

    if (serialishedHidden) {
        props_EngineMembers_capacity.serialisedHidden();
    }

    props_Engine.add(props_EngineMembers_capacity.asMap());

    using Field_EngineMembers_numCylinders = extension::field::EngineMembers::numCylinders<>;
    auto props_EngineMembers_numCylinders = 
        comms_champion::property::field::ForField<Field_EngineMembers_numCylinders>()
            .name("numCylinders");

    if (serialishedHidden) {
        props_EngineMembers_numCylinders.serialisedHidden();
    }

    props_Engine.add(props_EngineMembers_numCylinders.asMap());

    using Field_EngineMembers_maxRpm = extension::field::EngineMembers::maxRpm<>;
    auto props_EngineMembers_maxRpm = 
        comms_champion::property::field::ForField<Field_EngineMembers_maxRpm>()
            .name("maxRpm")
            .serialisedHidden()
            .readOnly()
;

    if (serialishedHidden) {
        props_EngineMembers_maxRpm.serialisedHidden();
    }

    props_Engine.add(props_EngineMembers_maxRpm.asMap());

    using Field_EngineMembers_manufacturerCode = extension::field::EngineMembers::manufacturerCode<>;
    auto props_EngineMembers_manufacturerCode = 
        comms_champion::property::field::ForField<Field_EngineMembers_manufacturerCode>()
            .name("manufacturerCode");

    if (serialishedHidden) {
        props_EngineMembers_manufacturerCode.serialisedHidden();
    }

    props_Engine.add(props_EngineMembers_manufacturerCode.asMap());

    using Field_EngineMembers_fuel = extension::field::EngineMembers::fuel<>;
    auto props_EngineMembers_fuel = 
        comms_champion::property::field::ForField<Field_EngineMembers_fuel>()
            .name("fuel")
            .serialisedHidden()
            .readOnly()
;

    if (serialishedHidden) {
        props_EngineMembers_fuel.serialisedHidden();
    }

    props_Engine.add(props_EngineMembers_fuel.asMap());

    using Field_EngineMembers_efficiency = extension::field::EngineMembers::efficiency<>;
    comms_champion::property::field::ForField<Field_EngineMembers_efficiency> props_EngineMembers_efficiency(
        createProps_Percentage("efficiency", serialishedHidden));

    props_Engine.add(props_EngineMembers_efficiency.asMap());

    using Field_EngineMembers_boosterEnabled = extension::field::EngineMembers::boosterEnabled<>;
    comms_champion::property::field::ForField<Field_EngineMembers_boosterEnabled> props_EngineMembers_boosterEnabled(
        createProps_BooleanType("boosterEnabled", serialishedHidden));

    props_Engine.add(props_EngineMembers_boosterEnabled.asMap());

    using Field_EngineMembers_booster = extension::field::EngineMembers::booster<>;
    comms_champion::property::field::ForField<Field_EngineMembers_booster> props_EngineMembers_booster(
        createProps_Booster("booster", serialishedHidden));

    props_Engine.add(props_EngineMembers_booster.asMap());

    return props_Engine.asMap();
}

QVariantMap createProps_Model(const char* fieldName, bool serialishedHidden)
{
    using Field_Model = extension::field::Model<>;
    auto props_Model = 
        comms_champion::property::field::ForField<Field_Model>()
            .name(fieldName)
            .add("A", 65)
            .add("B", 66)
            .add("C", 67);

    if (serialishedHidden) {
        props_Model.serialisedHidden();
    }

    return props_Model.asMap();
}

QVariantMap createProps_ModelYear(const char* fieldName, bool serialishedHidden)
{
    using Field_ModelYear = extension::field::ModelYear<>;
    auto props_ModelYear = 
        comms_champion::property::field::ForField<Field_ModelYear>()
            .name(fieldName);

    if (serialishedHidden) {
        props_ModelYear.serialisedHidden();
    }

    return props_ModelYear.asMap();
}

QVariantMap createProps_OptionalExtras(const char* fieldName, bool serialishedHidden)
{
    using Field_OptionalExtras = extension::field::OptionalExtras<>;
    auto props_OptionalExtras = 
        comms_champion::property::field::ForField<Field_OptionalExtras>()
            .name(fieldName)
            .add(0, "sunRoof")
            .add(1, "sportsPack")
            .add(2, "cruiseControl");

    if (serialishedHidden) {
        props_OptionalExtras.serialisedHidden();
    }

    return props_OptionalExtras.asMap();
}

QVariantMap createProps_Percentage(const char* fieldName, bool serialishedHidden)
{
    using Field_Percentage = extension::field::Percentage<>;
    auto props_Percentage = 
        comms_champion::property::field::ForField<Field_Percentage>()
            .name(fieldName);

    if (serialishedHidden) {
        props_Percentage.serialisedHidden();
    }

    return props_Percentage.asMap();
}

QVariantMap createProps_Ron(const char* fieldName, bool serialishedHidden)
{
    using Field_Ron = extension::field::Ron<>;
    auto props_Ron = 
        comms_champion::property::field::ForField<Field_Ron>()
            .name(fieldName);

    if (serialishedHidden) {
        props_Ron.serialisedHidden();
    }

    return props_Ron.asMap();
}

QVariantMap createProps_VehicleCode(const char* fieldName, bool serialishedHidden)
{
    using Field_VehicleCode = extension::field::VehicleCode<>;
    auto props_VehicleCode = 
        comms_champion::property::field::ForField<Field_VehicleCode>()
            .name(fieldName);

    if (serialishedHidden) {
        props_VehicleCode.serialisedHidden();
    }

    return props_VehicleCode.asMap();
}

QVariantMap createProps_cupHolderCount_t(const char* fieldName, bool serialishedHidden)
{
    using Field_cupHolderCount_tField = extension::field::cupHolderCount_tField<>;
    auto props_cupHolderCount_tField = 
        comms_champion::property::field::ForField<Field_cupHolderCount_tField>()
            .name(fieldName);

    if (serialishedHidden) {
        props_cupHolderCount_tField.serialisedHidden();
    }

    using Field_cupHolderCount_t = extension::field::cupHolderCount_t<>;
    auto props_cupHolderCount_t = 
        comms_champion::property::field::ForField<Field_cupHolderCount_t>()
            .name(fieldName)
            .uncheckable()
            .field(props_cupHolderCount_tField.asMap());

    return props_cupHolderCount_t.asMap();
}

QVariantMap createProps_groupSizeEncoding(const char* fieldName, bool serialishedHidden)
{
    using Field_groupSizeEncoding = extension::field::groupSizeEncoding<>;
    auto props_groupSizeEncoding = 
        comms_champion::property::field::ForField<Field_groupSizeEncoding>().name(fieldName);

    using Field_groupSizeEncodingMembers_blockLength = extension::field::groupSizeEncodingMembers::blockLength<>;
    auto props_groupSizeEncodingMembers_blockLength = 
        comms_champion::property::field::ForField<Field_groupSizeEncodingMembers_blockLength>()
            .name("blockLength");

    if (serialishedHidden) {
        props_groupSizeEncodingMembers_blockLength.serialisedHidden();
    }

    props_groupSizeEncoding.add(props_groupSizeEncodingMembers_blockLength.asMap());

    using Field_groupSizeEncodingMembers_numInGroup = extension::field::groupSizeEncodingMembers::numInGroup<>;
    auto props_groupSizeEncodingMembers_numInGroup = 
        comms_champion::property::field::ForField<Field_groupSizeEncodingMembers_numInGroup>()
            .name("numInGroup");

    if (serialishedHidden) {
        props_groupSizeEncodingMembers_numInGroup.serialisedHidden();
    }

    props_groupSizeEncoding.add(props_groupSizeEncodingMembers_numInGroup.asMap());

    return props_groupSizeEncoding.asMap();
}

QVariantMap createProps_messageHeader(const char* fieldName, bool serialishedHidden)
{
    using Field_messageHeader = extension::field::messageHeader<>;
    auto props_messageHeader = 
        comms_champion::property::field::ForField<Field_messageHeader>().name(fieldName);

    using Field_messageHeaderMembers_blockLength = extension::field::messageHeaderMembers::blockLength<>;
    auto props_messageHeaderMembers_blockLength = 
        comms_champion::property::field::ForField<Field_messageHeaderMembers_blockLength>()
            .name("blockLength");

    if (serialishedHidden) {
        props_messageHeaderMembers_blockLength.serialisedHidden();
    }

    props_messageHeader.add(props_messageHeaderMembers_blockLength.asMap());

    using Field_messageHeaderMembers_templateId = extension::field::messageHeaderMembers::templateId<>;
    auto props_messageHeaderMembers_templateId = 
        comms_champion::property::field::ForField<Field_messageHeaderMembers_templateId>()
            .name("templateId")
            .add("Car", 1);

    if (serialishedHidden) {
        props_messageHeaderMembers_templateId.serialisedHidden();
    }

    props_messageHeader.add(props_messageHeaderMembers_templateId.asMap());

    using Field_messageHeaderMembers_schemaId = extension::field::messageHeaderMembers::schemaId<>;
    auto props_messageHeaderMembers_schemaId = 
        comms_champion::property::field::ForField<Field_messageHeaderMembers_schemaId>()
            .name("schemaId");

    if (serialishedHidden) {
        props_messageHeaderMembers_schemaId.serialisedHidden();
    }

    props_messageHeader.add(props_messageHeaderMembers_schemaId.asMap());

    using Field_messageHeaderMembers_version = extension::field::messageHeaderMembers::version<>;
    auto props_messageHeaderMembers_version = 
        comms_champion::property::field::ForField<Field_messageHeaderMembers_version>()
            .name("version");

    if (serialishedHidden) {
        props_messageHeaderMembers_version.serialisedHidden();
    }

    props_messageHeader.add(props_messageHeaderMembers_version.asMap());

    return props_messageHeader.asMap();
}

QVariantMap createProps_someNumbers(const char* fieldName, bool serialishedHidden)
{
    using Field_someNumbersElement0 = extension::field::someNumbersElement<>;
    auto props_someNumbersElement0 = 
        comms_champion::property::field::ForField<Field_someNumbersElement0>()
            .name("0");

    if (serialishedHidden) {
        props_someNumbersElement0.serialisedHidden();
    }

    using Field_someNumbersElement1 = extension::field::someNumbersElement<>;
    auto props_someNumbersElement1 = 
        comms_champion::property::field::ForField<Field_someNumbersElement1>()
            .name("1");

    if (serialishedHidden) {
        props_someNumbersElement1.serialisedHidden();
    }

    using Field_someNumbersElement2 = extension::field::someNumbersElement<>;
    auto props_someNumbersElement2 = 
        comms_champion::property::field::ForField<Field_someNumbersElement2>()
            .name("2");

    if (serialishedHidden) {
        props_someNumbersElement2.serialisedHidden();
    }

    using Field_someNumbersElement3 = extension::field::someNumbersElement<>;
    auto props_someNumbersElement3 = 
        comms_champion::property::field::ForField<Field_someNumbersElement3>()
            .name("3");

    if (serialishedHidden) {
        props_someNumbersElement3.serialisedHidden();
    }

    using Field_someNumbersElement4 = extension::field::someNumbersElement<>;
    auto props_someNumbersElement4 = 
        comms_champion::property::field::ForField<Field_someNumbersElement4>()
            .name("4");

    if (serialishedHidden) {
        props_someNumbersElement4.serialisedHidden();
    }

    using Field_someNumbers = extension::field::someNumbers<>;
    auto props_someNumbers = 
        comms_champion::property::field::ForField<Field_someNumbers>()
            .serialisedHidden()
            .name(fieldName)
            .add(props_someNumbersElement0.asMap())
            .add(props_someNumbersElement1.asMap())
            .add(props_someNumbersElement2.asMap())
            .add(props_someNumbersElement3.asMap())
            .add(props_someNumbersElement4.asMap());

    return props_someNumbers.asMap();
}

QVariantMap createProps_varDataEncoding(const char* fieldName, bool serialishedHidden)
{
    using Field_varDataEncoding = extension::field::varDataEncoding<>;
    auto props_varDataEncoding = 
        comms_champion::property::field::ForField<Field_varDataEncoding>().name(fieldName);

    using Field_varDataEncodingMembers_length = extension::field::varDataEncodingMembers::length_<>;
    auto props_varDataEncodingMembers_length = 
        comms_champion::property::field::ForField<Field_varDataEncodingMembers_length>()
            .name("length");

    if (serialishedHidden) {
        props_varDataEncodingMembers_length.serialisedHidden();
    }

    props_varDataEncoding.add(props_varDataEncodingMembers_length.asMap());

    using Field_varDataEncodingMembers_varData = extension::field::varDataEncodingMembers::varData<>;
    auto props_varDataEncodingMembers_varData = 
        comms_champion::property::field::ForField<Field_varDataEncodingMembers_varData>()
            .name("varData");

    if (serialishedHidden) {
        props_varDataEncodingMembers_varData.serialisedHidden();
    }

    props_varDataEncoding.add(props_varDataEncodingMembers_varData.asMap());

    return props_varDataEncoding.asMap();
}

QVariantMap createProps_varStringEncoding(const char* fieldName, bool serialishedHidden)
{
    using Field_varStringEncoding = extension::field::varStringEncoding<>;
    auto props_varStringEncoding =
        comms_champion::property::field::ForField<Field_varStringEncoding>()
            .name(fieldName);

    if (serialishedHidden) {
        props_varStringEncoding.serialisedHidden();
    }

    return props_varStringEncoding.asMap();
}

} // namespace field

} // namespace cc_plugin

} // namespace extension

