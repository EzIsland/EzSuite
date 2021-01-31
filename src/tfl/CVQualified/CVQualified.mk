MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.tfl.CVQualified test.ezs.tfl.CVQualified
ezs.tfl.CVQualified_INTERFACE_FILE := $(MODULE_DIR)/CVQualified.hxx
ezs.tfl.CVQualified_INTERFACE_DEPS := ezs.tfl.Const ezs.tfl.Volatile
test.ezs.tfl.CVQualified_IMPLEMENTATION_FILE := $(MODULE_DIR)/tCVQualified.cpp
test.ezs.tfl.CVQualified_IMPLEMENTATION_DEPS := ezs.tfl.CVQualified
