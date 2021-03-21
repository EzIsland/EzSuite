SRC_TFL_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.tfl test.ezs.tfl
ezs.tfl_INTERFACE_FILE := $(SRC_TFL_DIR)/tfl.hxx
ezs.tfl_INTERFACE_DEPS := ezs.tfl.Value ezs.tfl.Object ezs.tfl.CVQualified ezs.tfl.ForwardRefOf \
	ezs.tfl.Const ezs.tfl.Volatile ezs.tfl.LValueRef ezs.tfl.RValueRef ezs.tfl.forward \
	ezs.tfl.move ezs.tfl.SameAs ezs.tfl.RemoveConst ezs.tfl.RemoveVolatile \
	ezs.tfl.RemoveLValueRef ezs.tfl.RemoveRValueRef ezs.tfl.RemoveRef ezs.tfl.Ref \
	ezs.tfl.ForwardRef ezs.tfl.NonDeduced ezs.tfl.SelectType ezs.tfl.Tag \
	ezs.tfl.ValueTag ezs.tfl.IndexSequence ezs.tfl.InstantiationOf ezs.tfl.ConstructibleFrom \
	ezs.tfl.declval ezs.tfl.ForwardConstructibleFrom ezs.tfl.CopyConstructible ezs.tfl.MoveConstructible \
	ezs.tfl.CopyAssignable ezs.tfl.MoveAssignable

test.ezs.tfl_IMPLEMENTATION_DEPS := test.ezs.tfl.Value test.ezs.tfl.Object \
	test.ezs.tfl.CVQualified test.ezs.tfl.ForwardRefOf test.ezs.tfl.Const \
	test.ezs.tfl.Volatile test.ezs.tfl.LValueRef test.ezs.tfl.RValueRef \
	test.ezs.tfl.forward test.ezs.tfl.move test.ezs.tfl.SameAs test.ezs.tfl.RemoveConst \
	test.ezs.tfl.RemoveVolatile test.ezs.tfl.RemoveLValueRef test.ezs.tfl.RemoveRValueRef \
	test.ezs.tfl.RemoveRef test.ezs.tfl.Ref test.ezs.tfl.ForwardRef test.ezs.tfl.move \
	test.ezs.tfl.forward test.ezs.tfl.NonDeduced test.ezs.tfl.SelectType test.ezs.tfl.Tag \
	test.ezs.tfl.ValueTag test.ezs.tfl.IndexSequence test.ezs.tfl.InstantiationOf \
	test.ezs.tfl.ConstructibleFrom test.ezs.tfl.declval ezs.tfl.ForwardConstructibleFrom \
	test.ezs.tfl.CopyConstructible test.ezs.tfl.MoveConstructible test.ezs.tfl.CopyAssignable \
	test.ezs.tfl.MoveAssignable

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
include $(SRC_TFL_DIR)/Tag/Tag.mk
include $(SRC_TFL_DIR)/ValueTag/ValueTag.mk
include $(SRC_TFL_DIR)/IndexSequence/IndexSequence.mk
include $(SRC_TFL_DIR)/InstantiationOf/InstantiationOf.mk
include $(SRC_TFL_DIR)/ConstructibleFrom/ConstructibleFrom.mk
include $(SRC_TFL_DIR)/declval/declval.mk
include $(SRC_TFL_DIR)/ForwardConstructibleFrom/ForwardConstructibleFrom.mk
include $(SRC_TFL_DIR)/CopyConstructible/CopyConstructible.mk
include $(SRC_TFL_DIR)/MoveConstructible/MoveConstructible.mk
include $(SRC_TFL_DIR)/CopyAssignable/CopyAssignable.mk
include $(SRC_TFL_DIR)/MoveAssignable/MoveAssignable.mk
