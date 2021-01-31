#ifndef EZS_TEST_TEST_HPP_
#define EZS_TEST_TEST_HPP_
#include "ezs/pp/UNIQUE.hpp"
import ezs.test;
import<string>;
import<vector>;
#define TEST(...) TEST_IMPL(UNIQUE(), UNIQUE(), __VA_ARGS__)
#define TEST_IMPL(TEST_NAME, FUNC_NAME, ...)                            \
  static void FUNC_NAME(ezs::test::TestResult& test);                   \
  static ezs::test::Test TEST_NAME({#__VA_ARGS__}, &FUNC_NAME);         \
  static void FUNC_NAME(ezs::test::TestResult& test)                    
#endif
