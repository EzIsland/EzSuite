MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.adt.Variant test.ezs.adt.Variant
ezs.adt.Variant_INTERFACE_FILE := $(MODULE_DIR)/Variant.hxx
ezs.adt.Variant_INTERFACE_DEPS := ezs.tfl ezs.uint_t ezs.cfl.assert
test.ezs.adt.Variant_IMPLEMENTATION_FILE := $(MODULE_DIR)/tVariant.cpp
test.ezs.adt.Variant_IMPLEMENTATION_DEPS := ezs.adt.Variant ezs.test.TEST ezs.tfl.ValueTag ezs.uint_t ezs.tfl.forward ezs.cfl.assert ezs.tfl
