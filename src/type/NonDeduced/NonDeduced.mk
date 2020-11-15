MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.NonDeduced test.ezs.type.NonDeduced
ezs.type.NonDeduced_INTERFACE_FILE := $(MODULE_DIR)/NonDeduced.hxx
ezs.type.NonDeduced_INTERFACE_DEPS := 
test.ezs.type.NonDeduced_IMPLEMENTATION_FILE := $(MODULE_DIR)/tNonDeduced.cpp
test.ezs.type.NonDeduced_IMPLEMENTATION_DEPS := ezs.type.NonDeduced
