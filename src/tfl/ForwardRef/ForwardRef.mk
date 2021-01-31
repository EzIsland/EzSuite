MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.ForwardRef test.ezs.tfl.ForwardRef
ezs.tfl.ForwardRef_INTERFACE_FILE := $(MODULE_DIR)/ForwardRef.hxx
ezs.tfl.ForwardRef_INTERFACE_DEPS := ezs.tfl.LValueRef ezs.tfl.Ref
test.ezs.tfl.ForwardRef_IMPLEMENTATION_FILE := $(MODULE_DIR)/tForwardRef.cpp
test.ezs.tfl.ForwardRef_IMPLEMENTATION_DEPS := ezs.tfl.ForwardRef
