MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.Ref test.ezs.tfl.Ref
ezs.tfl.Ref_INTERFACE_FILE := $(MODULE_DIR)/Ref.hxx
ezs.tfl.Ref_INTERFACE_DEPS := ezs.tfl.LValueRef ezs.tfl.RValueRef
test.ezs.tfl.Ref_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRef.cpp
test.ezs.tfl.Ref_IMPLEMENTATION_DEPS := ezs.tfl.Ref 
