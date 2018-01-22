/// \file
/// \brief Contains definition of \ref sbe_example::field::varDataEncoding field.

#pragma once

#include <cstdint>

#include "comms/field/ArrayList.h"
#include "comms/field/Bundle.h"
#include "comms/field/IntValue.h"
#include "comms/util/Tuple.h"

#include "FieldBase.h"
#include "sbe_example/sbe2comms/VersionSetter.h"

#include <cstdint>

namespace sbe_example
{

namespace field
{

/// \brief Scope for all the members of the \ref varDataEncoding field.
struct varDataEncodingMembers
{
    /// \brief Definition of "length" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class length_ : public
        comms::field::IntValue<
            sbe_example::field::FieldBase,
            std::uint32_t,
            TOpt...,
            comms::option::ValidNumValueRange<0, 1073741824L>
        >
    {
        using Base =
            comms::field::IntValue<
                sbe_example::field::FieldBase,
                std::uint32_t,
                TOpt...,
                comms::option::ValidNumValueRange<0, 1073741824L>
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

    /// \brief Definition of "varData" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class varData : public
        comms::field::ArrayList<
            sbe_example::field::FieldBase,
            std::uint8_t,
            TOpt...
        >
    {
        using Base =
            comms::field::ArrayList<
                sbe_example::field::FieldBase,
                std::uint8_t,
                TOpt...
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

    /// \brief Bundling all the defined member types into a single std::tuple.
    /// \tparam TOpt_length Extra options for \ref length_ from \b comms::option namespace.
    /// \tparam TOpt_varData Extra options for \ref varData from \b comms::option namespace.
    template<
        typename TOpt_length = comms::option::EmptyOption,
        typename TOpt_varData = comms::option::EmptyOption
    >
    using All = std::tuple<
        length_<TOpt_length>,
        varData<TOpt_varData>
    >;
};

/// \brief Definition of "varDataEncoding" field.
/// \tparam TOpt_length Extra options for \ref varDataEncodingMembers::length_ from \b comms::option namespace.
/// \tparam TOpt_varData Extra options for \ref varDataEncodingMembers::varData from \b comms::option namespace.
template<
    typename TOpt_length = comms::option::EmptyOption,
    typename TOpt_varData = comms::option::EmptyOption
>
class varDataEncoding : public
    comms::field::Bundle<
        sbe_example::field::FieldBase,
        varDataEncodingMembers::All<
            TOpt_length,
            TOpt_varData
        >
    >
{
    using Base =
        comms::field::Bundle<
            sbe_example::field::FieldBase,
            varDataEncodingMembers::All<
                TOpt_length,
                TOpt_varData
            >
        >;

public:
    /// \brief Allow access to internal fields.
    /// \details See definition of \b COMMS_FIELD_MEMBERS_ACCESS macro
    ///     related to \b comms::field::Bundle class from COMMS library
    ///     for details.\n
    ///     The names are:
    ///     \li \b length for \ref varDataEncodingMembers::length.
    ///     \li \b varData for \ref varDataEncodingMembers::varData.
    COMMS_FIELD_MEMBERS_ACCESS(
        length,
        varData
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

} // namespace sbe_example

