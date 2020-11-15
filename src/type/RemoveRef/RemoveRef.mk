MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.RemoveRef test.ezs.type.RemoveRef
ezs.type.RemoveRef_INTERFACE_FILE := $(MODULE_DIR)/RemoveRef.hxx
ezs.type.RemoveRef_INTERFACE_DEPS := ezs.type.RemoveRValueRef ezs.type.RemoveLValueRef
test.ezs.type.RemoveRef_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRemoveRef.cpp
test.ezs.type.RemoveRef_IMPLEMENTATION_DEPS := ezs.type.RemoveRef ezs.type.SameAs
