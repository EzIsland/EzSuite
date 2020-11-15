SRC_TEST_TEST_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.test.Test

ezs.test.Test_INTERFACE_FILE := $(SRC_TEST_TEST_DIR)/Test.hxx
ezs.test.Test_IMPLEMENTATION_FILE := $(SRC_TEST_TEST_DIR)/Test.cxx

ezs.test.Test_INTERFACE_DEPS := ezs.test.TestSingleton ezs.test.TestPoint ezs.adt.String \
	ezs.test.TestName ezs.uint_t ezs.test.TestResult
