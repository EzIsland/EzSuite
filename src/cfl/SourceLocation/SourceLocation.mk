MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.cfl.SourceLocation test.ezs.cfl.SourceLocation

ezs.cfl.SourceLocation_INTERFACE_FILE := $(MODULE_DIR)/SourceLocation.hxx
ezs.cfl.SourceLocation_INTERFACE_DEPS := ezs.uint_t
test.ezs.cfl.SourceLocation_IMPLEMENTATION_FILE := $(MODULE_DIR)/tSourceLocation.cpp
test.ezs.cfl.SourceLocation_IMPLEMENTATION_DEPS := ezs.test.TEST
