MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.tfl.CopyConstructible test.ezs.tfl.CopyConstructible
ezs.tfl.CopyConstructible_INTERFACE_FILE := $(MODULE_DIR)/CopyConstructible.hxx
ezs.tfl.CopyConstructible_INTERFACE_DEPS := 
test.ezs.tfl.CopyConstructible_IMPLEMENTATION_FILE := $(MODULE_DIR)/tCopyConstructible.cpp
test.ezs.tfl.CopyConstructible_IMPLEMENTATION_DEPS := ezs.tfl.CopyConstructible ezs.test.TEST
