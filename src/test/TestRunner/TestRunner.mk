MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.test.TestRunner 
ezs.test.TestRunner_INTERFACE_FILE := $(MODULE_DIR)/TestRunner.hxx
ezs.test.TestRunner_INTERFACE_DEPS := ezs.test.TestSingleton ezs.test.TestName ezs.test.TestPoint \
	ezs.test.TestResult ezs.test.TestFailure ezs.uint_t
