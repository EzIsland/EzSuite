MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.NonDeduced test.ezs.tfl.NonDeduced
ezs.tfl.NonDeduced_INTERFACE_FILE := $(MODULE_DIR)/NonDeduced.hxx
ezs.tfl.NonDeduced_INTERFACE_DEPS := 
test.ezs.tfl.NonDeduced_IMPLEMENTATION_FILE := $(MODULE_DIR)/tNonDeduced.cpp
test.ezs.tfl.NonDeduced_IMPLEMENTATION_DEPS := ezs.tfl.NonDeduced
