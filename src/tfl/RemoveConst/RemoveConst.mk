MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.RemoveConst test.ezs.tfl.RemoveConst
ezs.tfl.RemoveConst_INTERFACE_FILE := $(MODULE_DIR)/RemoveConst.hxx
ezs.tfl.RemoveConst_INTERFACE_DEPS := 
test.ezs.tfl.RemoveConst_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRemoveConst.cpp
test.ezs.tfl.RemoveConst_IMPLEMENTATION_DEPS := ezs.tfl.RemoveConst ezs.tfl.SameAs
