SRC_TEST_TESTSINGLETON_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.test.TestSingleton

ezs.test.TestSingleton_INTERFACE_FILE := $(SRC_TEST_TESTSINGLETON_DIR)/TestSingleton.hxx
ezs.test.TestSingleton_IMPLEMENTATION_FILE := $(SRC_TEST_TESTSINGLETON_DIR)/TestSingleton.cxx

ezs.test.TestSingleton_INTERFACE_DEPS := ezs.test.TestPoint ezs.test.TestName ezs.test.TestResult
ezs.test.TestSingleton_IMPLEMENTATION_DEPS := ezs.test.TestPoint ezs.test.TestName ezs.test.TestResult
