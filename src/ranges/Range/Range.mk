MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.ranges.Range test.ezs.ranges.Range
ezs.ranges.Range_INTERFACE_FILE := $(MODULE_DIR)/Range.hxx
ezs.ranges.Range_INTERFACE_DEPS := ezs.ranges.Iterator
test.ezs.ranges.Range_IMPLEMENTATION_FILE := $(MODULE_DIR)/tRange.cpp
test.ezs.ranges.Range_IMPLEMENTATION_DEPS :=
