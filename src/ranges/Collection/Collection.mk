MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.ranges.Collection test.ezs.ranges.Collection
ezs.ranges.Collection_INTERFACE_FILE := $(MODULE_DIR)/Collection.hxx
ezs.ranges.Collection_INTERFACE_DEPS := ezs.tfl.SameAs ezs.uint_t
test.ezs.ranges.Collection_IMPLEMENTATION_FILE := $(MODULE_DIR)/tCollection.cpp
test.ezs.ranges.Collection_IMPLEMENTATION_DEPS :=
