MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.tfl.declval test.ezs.tfl.declval
ezs.tfl.declval_INTERFACE_FILE := $(MODULE_DIR)/declval.hxx
ezs.tfl.declval_INTERFACE_DEPS := 
test.ezs.tfl.declval_IMPLEMENTATION_FILE := $(MODULE_DIR)/tdeclval.cpp
test.ezs.tfl.declval_IMPLEMENTATION_DEPS := ezs.tfl.declval ezs.test.TEST
