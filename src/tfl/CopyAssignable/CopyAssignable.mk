MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.tfl.CopyAssignable test.ezs.tfl.CopyAssignable
ezs.tfl.CopyAssignable_INTERFACE_FILE := $(MODULE_DIR)/CopyAssignable.hxx
ezs.tfl.CopyAssignable_INTERFACE_DEPS := ezs.tfl.declval
test.ezs.tfl.CopyAssignable_IMPLEMENTATION_FILE := $(MODULE_DIR)/tCopyAssignable.cpp
test.ezs.tfl.CopyAssignable_IMPLEMENTATION_DEPS := ezs.tfl.CopyAssignable ezs.test.TEST
