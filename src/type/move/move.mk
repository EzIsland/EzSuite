MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.move test.ezs.type.move
ezs.type.move_INTERFACE_FILE := $(MODULE_DIR)/move.hxx
ezs.type.move_INTERFACE_DEPS := ezs.type.RemoveLValueRef ezs.type.ForwardRef
test.ezs.type.move_IMPLEMENTATION_FILE := $(MODULE_DIR)/tmove.cpp
test.ezs.type.move_IMPLEMENTATION_DEPS := ezs.type.move
