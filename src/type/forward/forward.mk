MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.forward test.ezs.type.forward
ezs.type.forward_INTERFACE_FILE := $(MODULE_DIR)/forward.hxx
ezs.type.forward_INTERFACE_DEPS := ezs.type.NonDeduced ezs.type.ForwardRef ezs.type.LValueRef
test.ezs.type.forward_IMPLEMENTATION_FILE := $(MODULE_DIR)/tforward.cpp
test.ezs.type.forward_IMPLEMENTATION_DEPS := ezs.type.forward ezs.type.ForwardRefOf
