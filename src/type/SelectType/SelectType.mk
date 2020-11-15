MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.SelectType test.ezs.type.SelectType
ezs.type.SelectType_INTERFACE_FILE := $(MODULE_DIR)/SelectType.hxx
ezs.type.SelectType_INTERFACE_DEPS := ezs.uint_t
test.ezs.type.SelectType_IMPLEMENTATION_FILE := $(MODULE_DIR)/tSelectType.cpp
test.ezs.type.SelectType_IMPLEMENTATION_DEPS := ezs.type.SelectType ezs.type.SameAs ezs.uint_t
