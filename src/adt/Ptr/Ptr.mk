MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.adt.Ptr ezs.adt.Ptr.fwd ezs.adt.Ptr_test

ezs.adt.Ptr_INTERFACE_FILE := $(MODULE_DIR)/Ptr.hxx
ezs.adt.Ptr_INTERFACE_DEPS := ezs.adt.Value
