MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.pp.EXPAND_STRINGIFY test.ezs.pp.EXPAND_STRINGIFY

ezs.pp.EXPAND_STRINGIFY_HEADER_FILE := $(MODULE_DIR)/EXPAND_STRINGIFY.hpp
ezs.pp.EXPAND_STRINGIFY_HEADER_DEPS := ezs.pp.APPLY ezs.pp.STRINGIFY
test.ezs.pp.EXPAND_STRINGIFY_IMPLEMENTATION_FILE := $(MODULE_DIR)/tEXPAND_STRINGIFY.cpp
test.ezs.pp.EXPAND_STRINGIFY_IMPLEMENTATION_DEPS := ezs.pp.EXPAND_STRINGIFY ezs.test
