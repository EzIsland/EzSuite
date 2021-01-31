#ifndef EZS_PP_EXPAND_STRINGIFY_HPP_
#define EZS_PP_EXPAND_STRINGIFY_HPP_
#include "ezs/pp/STRINGIFY.hpp"
#include "ezs/pp/APPLY.hpp"
#define EXPAND_STRINGIFY(X) APPLY(STRINGIFY, X)
#endif
