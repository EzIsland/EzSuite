SRC_TEST_DIR := $(GET_CURRENT_DIR)


MODULES += ezs.test

ezs.test_INTERFACE_FILE := $(SRC_TEST_DIR)/test.hxx
ezs.test_INTERFACE_DEPS := ezs.test.Test ezs.test.TestPoint ezs.test.TestResult ezs.test.TestName \
	ezs.test.TestSingleton ezs.test.TestFailure ezs.test.TestRunner

include $(SRC_TEST_DIR)/Test/Test.mk
include $(SRC_TEST_DIR)/TestSingleton/TestSingleton.mk
include $(SRC_TEST_DIR)/TestPoint/TestPoint.mk
include $(SRC_TEST_DIR)/TestResult/TestResult.mk
include $(SRC_TEST_DIR)/TestName/TestName.mk
include $(SRC_TEST_DIR)/TestFailure/TestFailure.mk
include $(SRC_TEST_DIR)/TestRunner/TestRunner.mk
include $(SRC_TEST_DIR)/TEST/TEST.mk
