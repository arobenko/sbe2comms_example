/// \file
/// \brief Contains definition of \ref extension::field::VehicleCode field.

#pragma once

#include "comms/field/String.h"

#include "FieldBase.h"

namespace extension
{

namespace field
{

/// \brief Definition of "VehicleCode" field.
/// \tparam TOpt Extra options from \b comms::option namespace.
template <typename... TOpt>
class VehicleCode : public
    comms::field::String<
        extension::field::FieldBase,
        comms::option::SequenceFixedSize<6>,
        TOpt...
    >

{
    using Base =
        comms::field::String<
            extension::field::FieldBase,
            comms::option::SequenceFixedSize<6>,
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

} // namespace field

} // namespace extension

