SRC_ADT_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.adt test.ezs.adt

ezs.adt_INTERFACE_FILE := $(SRC_ADT_DIR)/adt.hxx
ezs.adt_INTERFACE_DEPS := ezs.adt.Ptr ezs.adt.Value ezs.adt.String \
	ezs.adt.ObjectPtr ezs.adt.ArrayPtr ezs.adt.PropagateConst ezs.adt.RawObjectPtr \
	ezs.adt.RawArrayPtr ezs.adt.Tuple ezs.adt.Variant ezs.adt.NotStandardLayout

test.ezs.adt_IMPLEMENTATION_DEPS := test.ezs.adt.Tuple test.ezs.adt.Variant \
	test.ezs.adt.NotStandardLayout

include $(SRC_ADT_DIR)/Ptr/Ptr.mk
include $(SRC_ADT_DIR)/Value/Value.mk
include $(SRC_ADT_DIR)/String/String.mk
include $(SRC_ADT_DIR)/ObjectPtr/ObjectPtr.mk
include $(SRC_ADT_DIR)/ArrayPtr/ArrayPtr.mk
include $(SRC_ADT_DIR)/PropagateConst/PropagateConst.mk
include $(SRC_ADT_DIR)/RawObjectPtr/RawObjectPtr.mk
include $(SRC_ADT_DIR)/RawArrayPtr/RawArrayPtr.mk
include $(SRC_ADT_DIR)/Tuple/Tuple.mk
include $(SRC_ADT_DIR)/Variant/Variant.mk
include $(SRC_ADT_DIR)/NotStandardLayout/NotStandardLayout.mk
