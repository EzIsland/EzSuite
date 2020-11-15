MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.Ref test.ezs.type.Ref
ezs.type.Ref_INTERFACE_FILE := $(MODULE_DIR)/Ref.hxx
ezs.type.Ref_INTERFACE_DEPS := ezs.type.LValueRef ezs.type.RValueRef
test.ezs.type.Ref_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRef.cpp
test.ezs.type.Ref_IMPLEMENTATION_DEPS := ezs.type.Ref 
