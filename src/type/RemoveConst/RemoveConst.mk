MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.RemoveConst test.ezs.type.RemoveConst
ezs.type.RemoveConst_INTERFACE_FILE := $(MODULE_DIR)/RemoveConst.hxx
ezs.type.RemoveConst_INTERFACE_DEPS := 
test.ezs.type.RemoveConst_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRemoveConst.cpp
test.ezs.type.RemoveConst_IMPLEMENTATION_DEPS := ezs.type.RemoveConst ezs.type.SameAs
