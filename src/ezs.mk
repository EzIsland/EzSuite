SRC_DIR := $(GET_CURRENT_DIR)

MODULES += ezs test.ezs

ezs_INTERFACE_FILE := $(SRC_DIR)/ezs.hxx
ezs_INTERFACE_DEPS := ezs.adt ezs.test ezs.type

test.ezs_IMPLEMENTATION_DEPS := test.ezs.adt test.ezs.type test.ezs.pp

include $(SRC_DIR)/adt/adt.mk
include $(SRC_DIR)/main/main.mk
include $(SRC_DIR)/test/test.mk
include $(SRC_DIR)/uint_t/uint_t.mk
include $(SRC_DIR)/type/type.mk
include $(SRC_DIR)/pp/pp.mk
