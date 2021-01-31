MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.tfl.ForwardRefOf test.ezs.tfl.ForwardRefOf
ezs.tfl.ForwardRefOf_INTERFACE_FILE := $(MODULE_DIR)/ForwardRefOf.hxx
ezs.tfl.ForwardRefOf_INTERFACE_DEPS := ezs.tfl.Ref ezs.tfl.SameAs
test.ezs.tfl.ForwardRefOf_IMPLEMENTATION_FILE := $(MODULE_DIR)/tForwardRefOf.cpp
test.ezs.tfl.ForwardRefOf_IMPLEMENTATION_DEPS := ezs.tfl.ForwardRefOf ezs.tfl.SameAs
