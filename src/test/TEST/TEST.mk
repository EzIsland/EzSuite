MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.test.TEST

ezs.test.TEST_HEADER_FILE := $(MODULE_DIR)/TEST.hpp
ezs.test.TEST_HEADER_DEPS := ezs.pp.UNIQUE ezs.test
