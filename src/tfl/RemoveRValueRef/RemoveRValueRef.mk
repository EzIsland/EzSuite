MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.RemoveRValueRef test.ezs.tfl.RemoveRValueRef
ezs.tfl.RemoveRValueRef_INTERFACE_FILE := $(MODULE_DIR)/RemoveRValueRef.hxx
ezs.tfl.RemoveRValueRef_INTERFACE_DEPS := 
test.ezs.tfl.RemoveRValueRef_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRemoveRValueRef.cpp
test.ezs.tfl.RemoveRValueRef_IMPLEMENTATION_DEPS := ezs.tfl.RemoveRValueRef ezs.tfl.SameAs
