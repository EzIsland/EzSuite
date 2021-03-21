MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.test.Tester

ezs.test.Tester_INTERFACE_FILE := $(MODULE_DIR)/Tester.hxx
ezs.test.Tester_INTERFACE_DEPS := ezs.uint_t ezs.test.TestResult ezs.adt.String ezs.cfl.SourceLocation ezs.test.TestFailure
