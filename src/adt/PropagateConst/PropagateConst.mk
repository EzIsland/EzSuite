SRC_ADT_PROPAGATECONST_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.adt.PropagateConst

ezs.adt.PropagateConst_INTERFACE_FILE := $(SRC_ADT_PROPAGATECONST_DIR)/PropagateConst.hxx
ezs.adt.PropagateConst_INTERFACE_DEPS := ezs.uint_t ezs.adt.ObjectPtr ezs.adt.ArrayPtr ezs.type.forward ezs.type.ForwardRefOf ezs.type.move ezs.type.ForwardRef
