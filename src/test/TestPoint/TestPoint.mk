SRC_TEST_TESTPOINT_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.test.TestPoint

ezs.test.TestPoint_INTERFACE_FILE := $(SRC_TEST_TESTPOINT_DIR)/TestPoint.hxx
ezs.test.TestPoint_IMPLEMENTATION_FILE := $(SRC_TEST_TESTPOINT_DIR)/TestPoint.cxx

ezs.test.TestPoint_INTERFACE_DEPS := ezs.test.TestName ezs.test.TestResult ezs.adt.String \
	ezs.uint_t ezs.test.TestFailure ezs.adt.String ezs.test.Tester
