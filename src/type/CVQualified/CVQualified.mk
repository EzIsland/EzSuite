MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.type.CVQualified test.ezs.type.CVQualified
ezs.type.CVQualified_INTERFACE_FILE := $(MODULE_DIR)/CVQualified.hxx
ezs.type.CVQualified_INTERFACE_DEPS := ezs.type.Const ezs.type.Volatile
test.ezs.type.CVQualified_IMPLEMENTATION_FILE := $(MODULE_DIR)/tCVQualified.cpp
test.ezs.type.CVQualified_IMPLEMENTATION_DEPS := ezs.type.CVQualified
