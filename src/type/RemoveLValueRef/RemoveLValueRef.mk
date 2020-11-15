MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.RemoveLValueRef test.ezs.type.RemoveLValueRef
ezs.type.RemoveLValueRef_INTERFACE_FILE := $(MODULE_DIR)/RemoveLValueRef.hxx
ezs.type.RemoveLValueRef_INTERFACE_DEPS := 
test.ezs.type.RemoveLValueRef_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRemoveLValueRef.cpp
test.ezs.type.RemoveLValueRef_IMPLEMENTATION_DEPS := ezs.type.RemoveLValueRef ezs.type.SameAs
