SRC_TEST_TESTRESULT_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.test.TestResult

ezs.test.TestResult_INTERFACE_FILE := $(SRC_TEST_TESTRESULT_DIR)/TestResult.hxx
ezs.test.TestResult_IMPLEMENTATION_FILE := $(SRC_TEST_TESTRESULT_DIR)/TestResult.cxx
ezs.test.TestResult_INTERFACE_DEPS := ezs.uint_t ezs.test.TestFailure
