MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.type.Const test.ezs.type.Const
ezs.type.Const_INTERFACE_FILE := $(MODULE_DIR)/Const.hxx
ezs.type.Const_INTERFACE_DEPS :=
test.ezs.type.Const_IMPLEMENTATION_FILE := $(MODULE_DIR)/tConst.cpp
test.ezs.type.Const_IMPLEMENTATION_DEPS := ezs.type.Const
