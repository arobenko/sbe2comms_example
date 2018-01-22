/// \file
/// \brief Contains definition of \ref extension::field::ModelYear field.

#pragma once

#include <cstdint>

#include "comms/field/IntValue.h"

#include "FieldBase.h"

#include <cstdint>

namespace extension
{

namespace field
{

/// \brief Definition of "ModelYear" field.
/// \tparam TOpt Extra options from \b comms::option namespace.
template <typename... TOpt>
class ModelYear : public
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

} // namespace field

} // namespace extension

