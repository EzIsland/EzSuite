MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.Volatile test.ezs.tfl.Volatile
ezs.tfl.Volatile_INTERFACE_FILE := $(MODULE_DIR)/Volatile.hxx
ezs.tfl.Volatile_INTERFACE_DEPS :=
test.ezs.tfl.Volatile_IMPLEMENTATION_FILE := $(MODULE_DIR)/tVolatile.cpp
test.ezs.tfl.Volatile_IMPLEMENTATION_DEPS := ezs.tfl.Volatile
