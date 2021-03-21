SRC_CFL_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.cfl test.ezs.cfl

ezs.cfl_INTERFACE_FILE := $(SRC_CFL_DIR)/cfl.hxx
ezs.cfl_INTERFACE_DEPS := ezs.cfl.assert ezs.cfl.SourceLocation

test.ezs.cfl_IMPLEMENTATION_DEPS := test.ezs.cfl.assert test.ezs.cfl.SourceLocation

include $(SRC_CFL_DIR)/assert/assert.mk
include $(SRC_CFL_DIR)/SourceLocation/SourceLocation.mk
