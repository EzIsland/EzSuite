MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.tfl.MoveAssignable test.ezs.tfl.MoveAssignable
ezs.tfl.MoveAssignable_INTERFACE_FILE := $(MODULE_DIR)/MoveAssignable.hxx
ezs.tfl.MoveAssignable_INTERFACE_DEPS := ezs.tfl.move ezs.tfl.declval
test.ezs.tfl.MoveAssignable_IMPLEMENTATION_FILE := $(MODULE_DIR)/tMoveAssignable.cpp
test.ezs.tfl.MoveAssignable_IMPLEMENTATION_DEPS := ezs.tfl.MoveAssignable ezs.test.TEST
