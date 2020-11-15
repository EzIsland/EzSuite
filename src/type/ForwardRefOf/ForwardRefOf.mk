MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.type.ForwardRefOf test.ezs.type.ForwardRefOf
ezs.type.ForwardRefOf_INTERFACE_FILE := $(MODULE_DIR)/ForwardRefOf.hxx
ezs.type.ForwardRefOf_INTERFACE_DEPS := ezs.type.Ref ezs.type.SameAs
test.ezs.type.ForwardRefOf_IMPLEMENTATION_FILE := $(MODULE_DIR)/tForwardRefOf.cpp
test.ezs.type.ForwardRefOf_IMPLEMENTATION_DEPS := ezs.type.ForwardRefOf ezs.type.SameAs
