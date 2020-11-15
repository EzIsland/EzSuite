#ifndef EZS_ADT_NOT_STANDARD_LAYOUT_HPP_
#define EZS_ADT_NOT_STANDARD_LAYOUT_HPP_
#include "ezs/pp/STRINGIFY.hpp"
#define NOT_STANDARD_LAYOUT(T) [[no_unique_address]] ezs::adt::NotStandardLayout<T> \
  NOT_STANDARD_LAYOUT_MEMBER; static_assert(sizeof(NOT_STANDARD_LAYOUT_MEMBER) == 1)
#endif
