#ifndef EZS_PP_UNIQUE_HPP_
#define EZS_PP_UNIQUE_HPP_
#include "ezs/pp/EXPAND_CONCAT.hpp"
#define UNIQUE() EXPAND_CONCAT(EZS_UNIQUE_NAME_, __COUNTER__)
#endif
