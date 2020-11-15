MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.RemoveRValueRef test.ezs.type.RemoveRValueRef
ezs.type.RemoveRValueRef_INTERFACE_FILE := $(MODULE_DIR)/RemoveRValueRef.hxx
ezs.type.RemoveRValueRef_INTERFACE_DEPS := 
test.ezs.type.RemoveRValueRef_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRemoveRValueRef.cpp
test.ezs.type.RemoveRValueRef_IMPLEMENTATION_DEPS := ezs.type.RemoveRValueRef ezs.type.SameAs
