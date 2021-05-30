SRC_RANGES_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.ranges test.ezs.ranges

ezs.ranges_INTERFACE_FILE := $(SRC_RANGES_DIR)/ranges.hxx
ezs.ranges_INTERFACE_DEPS := ezs.ranges.Range ezs.ranges.Collection ezs.ranges.BidirectionalRange ezs.ranges.OrderedRange ezs.ranges.Iterator ezs.ranges.BidirectionalIterator ezs.ranges.IndexedRange

test.ezs.ranges_IMPLEMENTATION_DEPS := test.ezs.ranges.Range 

include $(SRC_RANGES_DIR)/Range/Range.mk
include $(SRC_RANGES_DIR)/Collection/Collection.mk
include $(SRC_RANGES_DIR)/OrderedRange/OrderedRange.mk
include $(SRC_RANGES_DIR)/BidirectionalRange/BidirectionalRange.mk
include $(SRC_RANGES_DIR)/IndexedRange/IndexedRange.mk

include $(SRC_RANGES_DIR)/Iterator/Iterator.mk
include $(SRC_RANGES_DIR)/BidirectionalIterator/BidirectionalIterator.mk
