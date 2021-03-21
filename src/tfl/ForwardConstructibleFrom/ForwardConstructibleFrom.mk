MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.tfl.ForwardConstructibleFrom test.ezs.tfl.ForwardConstructibleFrom
ezs.tfl.ForwardConstructibleFrom_INTERFACE_FILE := $(MODULE_DIR)/ForwardConstructibleFrom.hxx
ezs.tfl.ForwardConstructibleFrom_INTERFACE_DEPS := ezs.tfl.forward
test.ezs.tfl.ForwardConstructibleFrom_IMPLEMENTATION_FILE := $(MODULE_DIR)/tForwardConstructibleFrom.cpp
test.ezs.tfl.ForwardConstructibleFrom_IMPLEMENTATION_DEPS := ezs.tfl.ForwardConstructibleFrom ezs.test.TEST

