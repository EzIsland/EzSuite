MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.LValueRef test.ezs.type.LValueRef
ezs.type.LValueRef_INTERFACE_FILE := $(MODULE_DIR)/LValueRef.hxx
ezs.type.LValueRef_INTERFACE_DEPS := 
test.ezs.type.LValueRef_IMPLEMENTATION_FILE := $(MODULE_DIR)/tLValueRef.cpp
test.ezs.type.LValueRef_IMPLEMENTATION_DEPS := ezs.type.LValueRef
