MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.tfl.MoveConstructible test.ezs.tfl.MoveConstructible
ezs.tfl.MoveConstructible_INTERFACE_FILE := $(MODULE_DIR)/MoveConstructible.hxx
ezs.tfl.MoveConstructible_INTERFACE_DEPS := 
test.ezs.tfl.MoveConstructible_IMPLEMENTATION_FILE := $(MODULE_DIR)/tMoveConstructible.cpp
test.ezs.tfl.MoveConstructible_IMPLEMENTATION_DEPS := ezs.tfl.MoveConstructible ezs.test.TEST

