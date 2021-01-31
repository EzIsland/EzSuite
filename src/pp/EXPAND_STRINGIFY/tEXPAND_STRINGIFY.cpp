#include "ezs/pp/EXPAND_STRINGIFY.hpp"

import ezs.test;
import<string>;
import<vector>;

#define MY_MACRO HELLO WORLD

ezs::test::Test t({"ezs", "pp", "EXPAND_STRINGIFY"}, [](auto& test) {
  test.assert(std::string(EXPAND_STRINGIFY(MY_MACRO)) == std::string("HELLO WORLD"));
});

