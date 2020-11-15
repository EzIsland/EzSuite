MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.RValueRef test.ezs.type.RValueRef
ezs.type.RValueRef_INTERFACE_FILE := $(MODULE_DIR)/RValueRef.hxx
ezs.type.RValueRef_INTERFACE_DEPS := 
test.ezs.type.RValueRef_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRValueRef.cpp
test.ezs.type.RValueRef_IMPLEMENTATION_DEPS := ezs.type.RValueRef
