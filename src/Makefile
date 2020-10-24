SRC_DIR := $(GET_CURRENT_DIR)

MODULES += ezs ezs_test

ezs_INTERFACE_FILE := $(SRC_DIR)/ezs.hxx
ezs_INTERFACE_DEPS := ezs.adt ezs.test

ezs_test_IMPLEMENTATION_DEPS := ezs.adt_test

include $(SRC_DIR)/adt/Makefile
include $(SRC_DIR)/main/Makefile
include $(SRC_DIR)/test/Makefile
