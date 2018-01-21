/// \file
/// \brief Contains definition of \ref sbe_example::field::varStringEncoding field.

#pragma once

#include <cstdint>

#include "comms/field/Bundle.h"
#include "comms/field/IntValue.h"
#include "comms/field/String.h"
#include "comms/util/Tuple.h"

#include "FieldBase.h"
#include "sbe_example/sbe2comms/VersionSetter.h"

#include <cstdint>

namespace sbe_example
{

namespace field
{

/// \brief Scope for all the members of the \ref varStringEncoding field.
struct varStringEncodingMembers
{
    /// \brief Definition of "length" field.
    /// \tparam TOpt Extra options from \b comms::option namespace.
    template <typename... TOpt>
    class length_ : public
        comms::field::IntValue<
            FieldBase,
            std::uint32_t,
            TOpt...,
            comms::option::ValidNumValueRange<0, 1073741824L>
        >
    {
        using Base =
            comms::field::IntValue<
                FieldBase,
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
         comms::field::String<
            FieldBase,
            TOpt...
        >
    {
            using Base =
             comms::field::String<
                FieldBase,
                TOpt...
            >;

    public:        /// \brief Value validity check function.
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

/// \brief Definition of "varStringEncoding" field.
/// \tparam TOpt_length Extra options for \ref varStringEncodingMembers::length_ from \b comms::option namespace.
/// \tparam TOpt_varData Extra options for \ref varStringEncodingMembers::varData from \b comms::option namespace.
/// \tparam TOpt Extra options from \b comms::option namespace.
template<
    typename TOpt_length = comms::option::EmptyOption,
    typename TOpt_varData = comms::option::EmptyOption,
    typename TOpt = comms::option::EmptyOption
>
class varStringEncoding : public
    varStringEncodingMembers::varData<
        comms::option::SequenceSerLengthFieldPrefix<
            varStringEncodingMembers::length_<TOpt_length>
        >,
        TOpt_varData,
        TOpt
    >
{
    using Base =
        varStringEncodingMembers::varData<
            comms::option::SequenceSerLengthFieldPrefix<
                varStringEncodingMembers::length_<TOpt_length>
            >,
            TOpt_varData,
            TOpt
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

} // namespace sbe_example

