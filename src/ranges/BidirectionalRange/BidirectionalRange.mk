MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.ranges.BidirectionalRange test.ezs.ranges.BidirectionalRange
ezs.ranges.BidirectionalRange_INTERFACE_FILE := $(MODULE_DIR)/BidirectionalRange.hxx
ezs.ranges.BidirectionalRange_INTERFACE_DEPS := ezs.ranges.OrderedRange ezs.ranges.BidirectionalIterator
test.ezs.ranges.BidirectionalRange_IMPLEMENTATION_FILE := $(MODULE_DIR)/tBidirectionalRange.cpp
test.ezs.ranges.BidirectionalRange_IMPLEMENTATION_DEPS :=
