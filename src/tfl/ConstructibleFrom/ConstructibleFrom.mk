MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.tfl.ConstructibleFrom test.ezs.tfl.ConstructibleFrom
ezs.tfl.ConstructibleFrom_INTERFACE_FILE := $(MODULE_DIR)/ConstructibleFrom.hxx
ezs.tfl.ConstructibleFrom_INTERFACE_DEPS := 
test.ezs.tfl.ConstructibleFrom_IMPLEMENTATION_FILE := $(MODULE_DIR)/tConstructibleFrom.cpp
test.ezs.tfl.ConstructibleFrom_IMPLEMENTATION_DEPS := ezs.tfl.ConstructibleFrom ezs.test.TEST

