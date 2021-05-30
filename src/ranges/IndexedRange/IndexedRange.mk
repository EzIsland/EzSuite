MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.ranges.IndexedRange test.ezs.ranges.IndexedRange
ezs.ranges.IndexedRange_INTERFACE_FILE := $(MODULE_DIR)/IndexedRange.hxx
ezs.ranges.IndexedRange_INTERFACE_DEPS := ezs.ranges.BidirectionalRange ezs.tfl.SameAs ezs.uint_t
test.ezs.ranges.IndexedRange_IMPLEMENTATION_FILE := $(MODULE_DIR)/tIndexedRange.cpp
test.ezs.ranges.IndexedRange_IMPLEMENTATION_DEPS :=
