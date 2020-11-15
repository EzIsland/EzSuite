MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.ForwardRef test.ezs.type.ForwardRef
ezs.type.ForwardRef_INTERFACE_FILE := $(MODULE_DIR)/ForwardRef.hxx
ezs.type.ForwardRef_INTERFACE_DEPS := ezs.type.LValueRef ezs.type.Ref
test.ezs.type.ForwardRef_IMPLEMENTATION_FILE := $(MODULE_DIR)/tForwardRef.cpp
test.ezs.type.ForwardRef_IMPLEMENTATION_DEPS := ezs.type.ForwardRef
