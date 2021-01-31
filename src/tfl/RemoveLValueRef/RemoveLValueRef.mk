MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.RemoveLValueRef test.ezs.tfl.RemoveLValueRef
ezs.tfl.RemoveLValueRef_INTERFACE_FILE := $(MODULE_DIR)/RemoveLValueRef.hxx
ezs.tfl.RemoveLValueRef_INTERFACE_DEPS := 
test.ezs.tfl.RemoveLValueRef_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRemoveLValueRef.cpp
test.ezs.tfl.RemoveLValueRef_IMPLEMENTATION_DEPS := ezs.tfl.RemoveLValueRef ezs.tfl.SameAs
