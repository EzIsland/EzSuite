MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.adt.Vector test.ezs.adt.Vector

ezs.adt.Vector_INTERFACE_FILE := $(MODULE_DIR)/Vector.hxx
ezs.adt.Vector_INTERFACE_DEPS := ezs.tfl.ForwardRef ezs.cfl.assert ezs.uint_t\
	ezs.tfl.forward ezs.adt.ForwardingTuple ezs.tfl.Value ezs.tfl.ForwardRefOf \
	ezs.tfl.InstantiationOf ezs.tfl.ConstructibleFrom ezs.tfl.ForwardConstructibleFrom \
	ezs.tfl.CopyConstructible ezs.tfl.CopyAssignable ezs.tfl.move
test.ezs.adt.Vector_IMPLEMENTATION_FILE := $(MODULE_DIR)/tVector.cpp
test.ezs.adt.Vector_IMPLEMENTATION_DEPS := ezs.test.TEST ezs.test.Tester ezs.cfl.SourceLocation ezs.adt.String ezs.adt.Vector ezs.uint_t ezs.adt.ForwardingTuple ezs.tfl.forward ezs.tfl.move 
