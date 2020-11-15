MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.adt.NotStandardLayout test.ezs.adt.NotStandardLayout
ezs.adt.NotStandardLayout_INTERFACE_FILE := $(MODULE_DIR)/NotStandardLayout.hxx
ezs.adt.NotStandardLayout_INTERFACE_DEPS :=
ezs.adt.NotStandardLayout_HEADER_FILE := $(MODULE_DIR)/NOT_STANDARD_LAYOUT.hpp
ezs.adt.NotStandardLayout_HEADER_DEPS := ezs.pp.STRINGIFY
test.ezs.adt.NotStandardLayout_IMPLEMENTATION_FILE := $(MODULE_DIR)/tNotStandardLayout.cpp
test.ezs.adt.NotStandardLayout_IMPLEMENTATION_DEPS := ezs.adt.NotStandardLayout
