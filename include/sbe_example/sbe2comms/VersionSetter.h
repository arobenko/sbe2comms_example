/// \file
/// \brief Contains definition of helper class \ref sbe_example::sbe2comms::VersionSetter


#pragma once

namespace sbe_example
{

namespace sbe2comms
{

/// \brief Helper class to update version of the fields in tuple.
/// \details Expected to be used with \b comms::util::tupleAccumulate() function.
/// \headerfile "sbe_example/sbe2comms/VersionSetter.h"
struct VersionSetter
{
    VersionSetter(unsigned version) : m_version(version) {}

    template <typename TField>
    bool operator()(bool soFar, TField& field)
    {
        return field.setVersion(m_version) || soFar;
    }

private:
    unsigned m_version = 0U;
};

} // namespace sbe2comms

} // namespace sbe_example

