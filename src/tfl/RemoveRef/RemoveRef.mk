MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.RemoveRef test.ezs.tfl.RemoveRef
ezs.tfl.RemoveRef_INTERFACE_FILE := $(MODULE_DIR)/RemoveRef.hxx
ezs.tfl.RemoveRef_INTERFACE_DEPS := ezs.tfl.RemoveRValueRef ezs.tfl.RemoveLValueRef
test.ezs.tfl.RemoveRef_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRemoveRef.cpp
test.ezs.tfl.RemoveRef_IMPLEMENTATION_DEPS := ezs.tfl.RemoveRef ezs.tfl.SameAs
