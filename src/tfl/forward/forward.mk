MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.forward test.ezs.tfl.forward
ezs.tfl.forward_INTERFACE_FILE := $(MODULE_DIR)/forward.hxx
ezs.tfl.forward_INTERFACE_DEPS := ezs.tfl.NonDeduced ezs.tfl.ForwardRef ezs.tfl.LValueRef
test.ezs.tfl.forward_IMPLEMENTATION_FILE := $(MODULE_DIR)/tforward.cpp
test.ezs.tfl.forward_IMPLEMENTATION_DEPS := ezs.tfl.forward ezs.tfl.ForwardRefOf
