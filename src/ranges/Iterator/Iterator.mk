MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.ranges.Iterator test.ezs.ranges.Iterator
ezs.ranges.Iterator_INTERFACE_FILE := $(MODULE_DIR)/Iterator.hxx
ezs.ranges.Iterator_INTERFACE_DEPS := ezs.tfl.SameAs
test.ezs.ranges.Iterator_IMPLEMENTATION_FILE := $(MODULE_DIR)/tIterator.cpp
test.ezs.ranges.Iterator_IMPLEMENTATION_DEPS :=

