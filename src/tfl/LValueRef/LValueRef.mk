MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.LValueRef test.ezs.tfl.LValueRef
ezs.tfl.LValueRef_INTERFACE_FILE := $(MODULE_DIR)/LValueRef.hxx
ezs.tfl.LValueRef_INTERFACE_DEPS := 
test.ezs.tfl.LValueRef_IMPLEMENTATION_FILE := $(MODULE_DIR)/tLValueRef.cpp
test.ezs.tfl.LValueRef_IMPLEMENTATION_DEPS := ezs.tfl.LValueRef
