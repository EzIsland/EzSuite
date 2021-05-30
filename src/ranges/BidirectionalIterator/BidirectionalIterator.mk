MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.ranges.BidirectionalIterator test.ezs.ranges.BidirectionalIterator
ezs.ranges.BidirectionalIterator_INTERFACE_FILE := $(MODULE_DIR)/BidirectionalIterator.hxx
ezs.ranges.BidirectionalIterator_INTERFACE_DEPS := ezs.tfl.SameAs ezs.uint_t
test.ezs.ranges.BidirectionalIterator_IMPLEMENTATION_FILE := $(MODULE_DIR)/tBidirectionalIterator.cpp
test.ezs.ranges.BidirectionalIterator_IMPLEMENTATION_DEPS :=

