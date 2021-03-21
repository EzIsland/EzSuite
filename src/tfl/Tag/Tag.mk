MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.Tag test.ezs.tfl.Tag
ezs.tfl.Tag_INTERFACE_FILE := $(MODULE_DIR)/Tag.hxx
ezs.tfl.Tag_INTERFACE_DEPS :=
test.ezs.tfl.Tag_IMPLEMENTATION_FILE := $(MODULE_DIR)/tTag.cpp
test.ezs.tfl.Tag_IMPLEMENTATION_DEPS := ezs.tfl.Tag
