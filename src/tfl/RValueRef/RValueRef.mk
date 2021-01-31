MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.RValueRef test.ezs.tfl.RValueRef
ezs.tfl.RValueRef_INTERFACE_FILE := $(MODULE_DIR)/RValueRef.hxx
ezs.tfl.RValueRef_INTERFACE_DEPS := 
test.ezs.tfl.RValueRef_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRValueRef.cpp
test.ezs.tfl.RValueRef_IMPLEMENTATION_DEPS := ezs.tfl.RValueRef
