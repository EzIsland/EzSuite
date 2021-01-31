MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.SameAs test.ezs.tfl.SameAs
ezs.tfl.SameAs_INTERFACE_FILE := $(MODULE_DIR)/SameAs.hxx
ezs.tfl.SameAs_INTERFACE_DEPS := 
test.ezs.tfl.SameAs_IMPLEMENTATION_FILE := $(MODULE_DIR)/tSameAs.cpp
test.ezs.tfl.SameAs_IMPLEMENTATION_DEPS := ezs.tfl.SameAs
