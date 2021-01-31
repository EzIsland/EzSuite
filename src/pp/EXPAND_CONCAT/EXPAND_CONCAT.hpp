#ifndef EZS_PP_EXPAND_CONCAT_HPP_
#define EZS_PP_EXPAND_CONCAT_HPP_
#include "ezs/pp/CONCAT.hpp"
#include "ezs/pp/APPLY.hpp"
#define EXPAND_CONCAT(X, Y) APPLY(CONCAT, X, Y)
#endif
