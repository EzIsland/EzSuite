MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.tfl.InstantiationOf test.ezs.tfl.InstantiationOf
ezs.tfl.InstantiationOf_INTERFACE_FILE := $(MODULE_DIR)/InstantiationOf.hxx
ezs.tfl.InstantiationOf_INTERFACE_DEPS := 
test.ezs.tfl.InstantiationOf_IMPLEMENTATION_FILE := $(MODULE_DIR)/tInstantiationOf.cpp
test.ezs.tfl.InstantiationOf_IMPLEMENTATION_DEPS := ezs.tfl.InstantiationOf ezs.test.TEST
