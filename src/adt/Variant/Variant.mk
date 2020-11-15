MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.adt.Variant test.ezs.adt.Variant
ezs.adt.Variant_INTERFACE_FILE := $(MODULE_DIR)/Variant.hxx
ezs.adt.Variant_INTERFACE_DEPS := 
test.ezs.adt.Variant_IMPLEMENTATION_FILE := $(MODULE_DIR)/tVariant.cpp
test.ezs.adt.Variant_IMPLEMENTATION_DEPS := ezs.adt.Variant
