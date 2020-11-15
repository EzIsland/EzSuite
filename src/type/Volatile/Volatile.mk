MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.Volatile test.ezs.type.Volatile
ezs.type.Volatile_INTERFACE_FILE := $(MODULE_DIR)/Volatile.hxx
ezs.type.Volatile_INTERFACE_DEPS :=
test.ezs.type.Volatile_IMPLEMENTATION_FILE := $(MODULE_DIR)/tVolatile.cpp
test.ezs.type.Volatile_IMPLEMENTATION_DEPS := ezs.type.Volatile
