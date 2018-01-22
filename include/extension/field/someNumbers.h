/// \file
/// \brief Contains definition of \ref extension::field::someNumbers field.

#pragma once

#include <cstdint>

#include "comms/field/ArrayList.h"
#include "comms/field/IntValue.h"

#include "FieldBase.h"

#include <cstdint>

namespace extension
{

namespace field
{

/// \brief Element of \ref someNumbers list field.
/// \tparam TOpt Extra options from \b comms::option namespace.
template <typename... TOpt>
class someNumbersElement : public
    comms::field::IntValue<
        extension::field::FieldBase,
        std::uint32_t,
        TOpt...,
        comms::option::ValidNumValueRange<0, 0xfffffffeLL>
    >
{
    using Base =
        comms::field::IntValue<
            extension::field::FieldBase,
            std::uint32_t,
            TOpt...,
            comms::option::ValidNumValueRange<0, 0xfffffffeLL>
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

/// \brief Definition of "someNumbers" field.
/// \tparam TOpt Extra options from \b comms::option namespace.
template <typename... TOpt>
class someNumbers : public
    comms::field::ArrayList<
        extension::field::FieldBase,
        someNumbersElement<>,
        TOpt...,
        comms::option::SequenceFixedSize<5>
    >
{
    using Base =
        comms::field::ArrayList<
            extension::field::FieldBase,
            someNumbersElement<>,
            TOpt...,
            comms::option::SequenceFixedSize<5>
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

