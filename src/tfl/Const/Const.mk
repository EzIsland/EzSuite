MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.tfl.Const test.ezs.tfl.Const
ezs.tfl.Const_INTERFACE_FILE := $(MODULE_DIR)/Const.hxx
ezs.tfl.Const_INTERFACE_DEPS :=
test.ezs.tfl.Const_IMPLEMENTATION_FILE := $(MODULE_DIR)/tConst.cpp
test.ezs.tfl.Const_IMPLEMENTATION_DEPS := ezs.tfl.Const
