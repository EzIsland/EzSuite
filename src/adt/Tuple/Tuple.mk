MODULE_DIR := $(GET_CURRENT_DIR)
MODULES += ezs.adt.Tuple test.ezs.adt.Tuple
ezs.adt.Tuple_INTERFACE_FILE := $(MODULE_DIR)/Tuple.hxx
ezs.adt.Tuple_INTERFACE_DEPS := ezs.type.Value ezs.type.ForwardRefOf ezs.type.forward \
	ezs.uint_t ezs.type.ForwardRef ezs.type.SelectType ezs.adt.NotStandardLayout 
test.ezs.adt.Tuple_IMPLEMENTATION_FILE := $(MODULE_DIR)/tTuple.cpp
test.ezs.adt.Tuple_IMPLEMENTATION_DEPS := ezs.adt.Tuple ezs.test ezs.uint_t ezs.type.forward
