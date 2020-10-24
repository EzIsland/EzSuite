SRC_ADT_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.adt ezs.adt_test

ezs.adt_INTERFACE_FILE := $(SRC_ADT_DIR)/adt.hxx
ezs.adt_INTERFACE_DEPS := ezs.adt.Ptr ezs.adt.Ptr.fwd ezs.adt.Value

ezs.adt_test_IMPLEMENTATION_DEPS := ezs.adt.Ptr_test

include $(SRC_ADT_DIR)/Ptr/Makefile
include $(SRC_ADT_DIR)/Value/Makefile
