MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.ranges.OrderedRange test.ezs.ranges.OrderedRange
ezs.ranges.OrderedRange_INTERFACE_FILE := $(MODULE_DIR)/OrderedRange.hxx
ezs.ranges.OrderedRange_INTERFACE_DEPS := ezs.ranges.Range
test.ezs.ranges.OrderedRange_IMPLEMENTATION_FILE := $(MODULE_DIR)/tOrderedRange.cpp
test.ezs.ranges.OrderedRange_IMPLEMENTATION_DEPS :=
