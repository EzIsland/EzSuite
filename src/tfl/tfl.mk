SRC_TFL_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.tfl test.ezs.tfl
ezs.tfl_INTERFACE_FILE := $(SRC_TFL_DIR)/tfl.hxx
ezs.tfl_INTERFACE_DEPS := ezs.tfl.Value ezs.tfl.Object ezs.tfl.CVQualified ezs.tfl.ForwardRefOf \
	ezs.tfl.Const ezs.tfl.Volatile ezs.tfl.LValueRef ezs.tfl.RValueRef ezs.tfl.forward \
	ezs.tfl.move ezs.tfl.SameAs ezs.tfl.RemoveConst ezs.tfl.RemoveVolatile \
	ezs.tfl.RemoveLValueRef ezs.tfl.RemoveRValueRef ezs.tfl.RemoveRef ezs.tfl.Ref \
	ezs.tfl.ForwardRef ezs.tfl.NonDeduced ezs.tfl.SelectType

test.ezs.tfl_IMPLEMENTATION_DEPS := test.ezs.tfl.Value test.ezs.tfl.Object \
	test.ezs.tfl.CVQualified test.ezs.tfl.ForwardRefOf test.ezs.tfl.Const \
	test.ezs.tfl.Volatile test.ezs.tfl.LValueRef test.ezs.tfl.RValueRef \
	test.ezs.tfl.forward test.ezs.tfl.move test.ezs.tfl.SameAs test.ezs.tfl.RemoveConst \
	test.ezs.tfl.RemoveVolatile test.ezs.tfl.RemoveLValueRef test.ezs.tfl.RemoveRValueRef \
	test.ezs.tfl.RemoveRef test.ezs.tfl.Ref test.ezs.tfl.ForwardRef test.ezs.tfl.move \
	test.ezs.tfl.forward test.ezs.tfl.NonDeduced test.ezs.tfl.SelectType

include $(SRC_TFL_DIR)/Object/Object.mk
include $(SRC_TFL_DIR)/Value/Value.mk
include $(SRC_TFL_DIR)/CVQualified/CVQualified.mk
include $(SRC_TFL_DIR)/ForwardRefOf/ForwardRefOf.mk 
include $(SRC_TFL_DIR)/Const/Const.mk
include $(SRC_TFL_DIR)/Volatile/Volatile.mk
include $(SRC_TFL_DIR)/LValueRef/LValueRef.mk
include $(SRC_TFL_DIR)/RValueRef/RValueRef.mk
include $(SRC_TFL_DIR)/forward/forward.mk
include $(SRC_TFL_DIR)/move/move.mk
include $(SRC_TFL_DIR)/SameAs/SameAs.mk
include $(SRC_TFL_DIR)/RemoveConst/RemoveConst.mk
include $(SRC_TFL_DIR)/RemoveVolatile/RemoveVolatile.mk
include $(SRC_TFL_DIR)/RemoveRValueRef/RemoveRValueRef.mk
include $(SRC_TFL_DIR)/RemoveLValueRef/RemoveLValueRef.mk
include $(SRC_TFL_DIR)/RemoveRef/RemoveRef.mk
include $(SRC_TFL_DIR)/Ref/Ref.mk
include $(SRC_TFL_DIR)/ForwardRef/ForwardRef.mk
include $(SRC_TFL_DIR)/NonDeduced/NonDeduced.mk
include $(SRC_TFL_DIR)/SelectType/SelectType.mk
