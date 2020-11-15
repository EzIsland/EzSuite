SRC_MAIN_DIR := $(GET_CURRENT_DIR)

MODULES += ezs.main.Main ezs.main.Test ezs.main.bh
MAIN_MODULES += ezs.main.Main ezs.main.Test ezs.main.bh

ezs.main.Main_IMPLEMENTATION_FILE := $(SRC_MAIN_DIR)/Main.cpp
ezs.main.Main_IMPLEMENTATION_DEPS := ezs 

ezs.main.Test_IMPLEMENTATION_FILE := $(SRC_MAIN_DIR)/Test.cpp
ezs.main.Test_IMPLEMENTATION_DEPS := ezs.test.TestSingleton test.ezs ezs.test.TestName ezs.test.TestResult ezs.test.TestRunner

ezs.main.bh_IMPLEMENTATION_FILE := $(SRC_MAIN_DIR)/bh.cpp
