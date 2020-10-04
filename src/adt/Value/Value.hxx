///
/// \file Value.hxx
/// \brief Module interface file for the ezs::adt::Value concept.
///
module;

#include <type_traits>

export module ezs.adt.Value;

///
/// \brief Concept representing non cv-qualified non-reference types.
///
export template <typename T>
concept Value =
    !std::is_const_v<T> && !std::is_volatile_v<T> && !std::is_reference_v<T>;
