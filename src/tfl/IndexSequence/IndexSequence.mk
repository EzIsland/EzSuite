MODULE_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.tfl.IndexSequence test.ezs.tfl.IndexSequence
ezs.tfl.IndexSequence_INTERFACE_FILE := $(MODULE_DIR)/IndexSequence.hxx
ezs.tfl.IndexSequence_INTERFACE_DEPS := ezs.uint_t
test.ezs.tfl.IndexSequence_IMPLEMENTATION_FILE := $(MODULE_DIR)/tIndexSequence.cpp
test.ezs.tfl.IndexSequence_IMPLEMENTATION_DEPS := ezs.tfl.IndexSequence
