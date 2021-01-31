MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.RemoveVolatile test.ezs.tfl.RemoveVolatile
ezs.tfl.RemoveVolatile_INTERFACE_FILE := $(MODULE_DIR)/RemoveVolatile.hxx
ezs.tfl.RemoveVolatile_INTERFACE_DEPS := 
test.ezs.tfl.RemoveVolatile_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRemoveVolatile.cpp
test.ezs.tfl.RemoveVolatile_IMPLEMENTATION_DEPS := ezs.tfl.RemoveVolatile ezs.tfl.SameAs
