MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.SameAs test.ezs.type.SameAs
ezs.type.SameAs_INTERFACE_FILE := $(MODULE_DIR)/SameAs.hxx
ezs.type.SameAs_INTERFACE_DEPS := 
test.ezs.type.SameAs_IMPLEMENTATION_FILE := $(MODULE_DIR)/tSameAs.cpp
test.ezs.type.SameAs_IMPLEMENTATION_DEPS := ezs.type.SameAs
