MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.RemoveVolatile test.ezs.type.RemoveVolatile
ezs.type.RemoveVolatile_INTERFACE_FILE := $(MODULE_DIR)/RemoveVolatile.hxx
ezs.type.RemoveVolatile_INTERFACE_DEPS := 
test.ezs.type.RemoveVolatile_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRemoveVolatile.cpp
test.ezs.type.RemoveVolatile_IMPLEMENTATION_DEPS := ezs.type.RemoveVolatile ezs.type.SameAs
