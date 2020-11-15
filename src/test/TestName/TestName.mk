SRC_TEST_TESTNAME_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.test.TestName

ezs.test.TestName_INTERFACE_FILE := $(SRC_TEST_TESTNAME_DIR)/TestName.hxx
ezs.test.TestName_IMPLEMENTATION_FILE := $(SRC_TEST_TESTNAME_DIR)/TestName.cxx

ezs.test.TestName_INTERFACE_DEPS := ezs.adt.String
