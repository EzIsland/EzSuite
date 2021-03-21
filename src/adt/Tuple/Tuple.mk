MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.adt.Tuple test.ezs.adt.Tuple
ezs.adt.Tuple_INTERFACE_FILE := $(MODULE_DIR)/Tuple.hxx
ezs.adt.Tuple_INTERFACE_DEPS := ezs.tfl.Value ezs.tfl.ForwardRefOf ezs.tfl.forward \
	ezs.uint_t ezs.tfl.ForwardRef ezs.tfl.SelectType ezs.adt.NotStandardLayout \
	ezs.tfl.move ezs.tfl.InstantiationOf ezs.adt.ForwardingTuple ezs.tfl.IndexSequence \
	ezs.tfl.ConstructibleFrom
test.ezs.adt.Tuple_IMPLEMENTATION_FILE := $(MODULE_DIR)/tTuple.cpp
test.ezs.adt.Tuple_IMPLEMENTATION_DEPS := ezs.adt.Tuple ezs.test.TEST ezs.uint_t ezs.tfl.forward ezs.adt.ForwardingTuple ezs.tfl.IndexSequence ezs.tfl.declval
