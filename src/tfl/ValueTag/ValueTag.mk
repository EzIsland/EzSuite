MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.ValueTag test.ezs.tfl.ValueTag
ezs.tfl.ValueTag_INTERFACE_FILE := $(MODULE_DIR)/ValueTag.hxx
ezs.tfl.ValueTag_INTERFACE_DEPS :=
test.ezs.tfl.ValueTag_IMPLEMENTATION_FILE := $(MODULE_DIR)/tValueTag.cpp
test.ezs.tfl.ValueTag_IMPLEMENTATION_DEPS := ezs.tfl.ValueTag ezs.test.TEST ezs.uint_t
