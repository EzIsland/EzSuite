MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.move test.ezs.tfl.move
ezs.tfl.move_INTERFACE_FILE := $(MODULE_DIR)/move.hxx
ezs.tfl.move_INTERFACE_DEPS := ezs.tfl.RemoveLValueRef ezs.tfl.ForwardRef
test.ezs.tfl.move_IMPLEMENTATION_FILE := $(MODULE_DIR)/tmove.cpp
test.ezs.tfl.move_IMPLEMENTATION_DEPS := ezs.tfl.move
