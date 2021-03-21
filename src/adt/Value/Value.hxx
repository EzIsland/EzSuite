///
/// \file Value.hxx
/// \brief Module interface file for the ezs::adt::Value concept.
///
export module ezs.adt.Value;

import <type_traits>;

///
/// \brief Concept representing non cv-qualified non-reference types.
///
export template <typename T>
concept Value = true;
//!std::is_const_v<T> && !std::is_volatile_v<T> && !std::is_reference_v<T>;
