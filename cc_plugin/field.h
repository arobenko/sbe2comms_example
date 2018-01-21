#pragma once

#include <QtCore/QVariantMap>


namespace sbe_example
{

namespace cc_plugin
{

namespace field
{

QVariantMap createProps_BooleanType(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_Booster(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_Engine(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_Model(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_ModelYear(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_OptionalExtras(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_Percentage(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_Ron(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_VehicleCode(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_cupHolderCount_t(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_groupSizeEncoding(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_messageHeader(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_someNumbers(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_varDataEncoding(const char* fieldName, bool serialishedHidden = false);
QVariantMap createProps_varStringEncoding(const char* fieldName, bool serialishedHidden = false);

} // namespace field

} // namespace cc_plugin

} // namespace sbe_example

