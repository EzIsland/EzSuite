SRC_TYPE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.type test.ezs.type
ezs.type_INTERFACE_FILE := $(SRC_TYPE_DIR)/type.hxx
ezs.type_INTERFACE_DEPS := ezs.type.Value ezs.type.Object ezs.type.CVQualified ezs.type.ForwardRefOf \
	ezs.type.Const ezs.type.Volatile ezs.type.LValueRef ezs.type.RValueRef ezs.type.forward \
	ezs.type.move ezs.type.SameAs ezs.type.RemoveConst ezs.type.RemoveVolatile \
	ezs.type.RemoveLValueRef ezs.type.RemoveRValueRef ezs.type.RemoveRef ezs.type.Ref \
	ezs.type.ForwardRef ezs.type.NonDeduced ezs.type.SelectType

test.ezs.type_IMPLEMENTATION_DEPS := test.ezs.type.Value test.ezs.type.Object \
	test.ezs.type.CVQualified test.ezs.type.ForwardRefOf test.ezs.type.Const \
	test.ezs.type.Volatile test.ezs.type.LValueRef test.ezs.type.RValueRef \
	test.ezs.type.forward test.ezs.type.move test.ezs.type.SameAs test.ezs.type.RemoveConst \
	test.ezs.type.RemoveVolatile test.ezs.type.RemoveLValueRef test.ezs.type.RemoveRValueRef \
	test.ezs.type.RemoveRef test.ezs.type.Ref test.ezs.type.ForwardRef test.ezs.type.move \
	test.ezs.type.forward test.ezs.type.NonDeduced test.ezs.type.SelectType

include $(SRC_TYPE_DIR)/Object/Object.mk
include $(SRC_TYPE_DIR)/Value/Value.mk
include $(SRC_TYPE_DIR)/CVQualified/CVQualified.mk
include $(SRC_TYPE_DIR)/ForwardRefOf/ForwardRefOf.mk 
include $(SRC_TYPE_DIR)/Const/Const.mk
include $(SRC_TYPE_DIR)/Volatile/Volatile.mk
include $(SRC_TYPE_DIR)/LValueRef/LValueRef.mk
include $(SRC_TYPE_DIR)/RValueRef/RValueRef.mk
include $(SRC_TYPE_DIR)/forward/forward.mk
include $(SRC_TYPE_DIR)/move/move.mk
include $(SRC_TYPE_DIR)/SameAs/SameAs.mk
include $(SRC_TYPE_DIR)/RemoveConst/RemoveConst.mk
include $(SRC_TYPE_DIR)/RemoveVolatile/RemoveVolatile.mk
include $(SRC_TYPE_DIR)/RemoveRValueRef/RemoveRValueRef.mk
include $(SRC_TYPE_DIR)/RemoveLValueRef/RemoveLValueRef.mk
include $(SRC_TYPE_DIR)/RemoveRef/RemoveRef.mk
include $(SRC_TYPE_DIR)/Ref/Ref.mk
include $(SRC_TYPE_DIR)/ForwardRef/ForwardRef.mk
include $(SRC_TYPE_DIR)/NonDeduced/NonDeduced.mk
include $(SRC_TYPE_DIR)/SelectType/SelectType.mk
