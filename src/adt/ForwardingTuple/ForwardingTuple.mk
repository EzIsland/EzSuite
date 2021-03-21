MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.adt.ForwardingTuple test.ezs.adt.ForwardingTuple
ezs.adt.ForwardingTuple_INTERFACE_FILE := $(MODULE_DIR)/ForwardingTuple.hxx
ezs.adt.ForwardingTuple_INTERFACE_DEPS := ezs.tfl.Value ezs.tfl.ForwardRefOf ezs.tfl.forward \
	ezs.uint_t ezs.tfl.ForwardRef ezs.tfl.SelectType ezs.adt.NotStandardLayout \
	ezs.tfl.move ezs.tfl.SameAs ezs.tfl.ValueTag
test.ezs.adt.ForwardingTuple_IMPLEMENTATION_FILE := $(MODULE_DIR)/tForwardingTuple.cpp
test.ezs.adt.ForwardingTuple_IMPLEMENTATION_DEPS := ezs.adt.ForwardingTuple ezs.test.TEST ezs.uint_t ezs.tfl.forward ezs.tfl.ValueTag
