MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.SelectType test.ezs.tfl.SelectType
ezs.tfl.SelectType_INTERFACE_FILE := $(MODULE_DIR)/SelectType.hxx
ezs.tfl.SelectType_INTERFACE_DEPS := ezs.uint_t
test.ezs.tfl.SelectType_IMPLEMENTATION_FILE := $(MODULE_DIR)/tSelectType.cpp
test.ezs.tfl.SelectType_IMPLEMENTATION_DEPS := ezs.tfl.SelectType ezs.tfl.SameAs ezs.uint_t
