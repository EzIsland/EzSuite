SRC_DIR := $(GET_CURRENT_DIR)

MODULES += ezs test.ezs

ezs_INTERFACE_FILE := $(SRC_DIR)/ezs.hxx
ezs_INTERFACE_DEPS := ezs.adt ezs.test ezs.tfl ezs.cfl ezs.ranges

test.ezs_IMPLEMENTATION_DEPS := test.ezs.adt test.ezs.tfl test.ezs.pp test.ezs.cfl test.ezs.ranges

include $(SRC_DIR)/adt/adt.mk
include $(SRC_DIR)/main/main.mk
include $(SRC_DIR)/test/test.mk
include $(SRC_DIR)/uint_t/uint_t.mk
include $(SRC_DIR)/tfl/tfl.mk
include $(SRC_DIR)/pp/pp.mk
include $(SRC_DIR)/cfl/cfl.mk
include $(SRC_DIR)/ranges/ranges.mk
