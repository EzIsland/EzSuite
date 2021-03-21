SRC_CFL_ASSERT_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.cfl.assert test.ezs.cfl.assert

ezs.cfl.assert_INTERFACE_FILE := $(SRC_CFL_ASSERT_DIR)/assert.hxx
ezs.cfl.assert_IMPLEMENTATION_FILE := $(SRC_CFL_ASSERT_DIR)/assert.cxx
test.ezs.cfl.assert_IMPLEMENTATION_FILE := $(SRC_CFL_ASSERT_DIR)/tassert.cpp
test.ezs.cfl.assert_IMPLEMENTATION_DEPS := ezs.test.TEST
