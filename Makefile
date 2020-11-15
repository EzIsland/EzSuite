# This makefile will recursively include other Makefiles under
# the src/ directory. Each Makefile under src/ should take responsibility
# for including the Makefiles in their respective subdirectories.
# These Makefiles can add new cxx modules into this build system
# by defining various MACROS which specify the module's source files
# dependencies, etc. For example, if ezs.test.Module
# is the name of a particular module, then
#
# Hooks in the module to the build system
#    MODULE += ezs.test.Module
#
# Specifies that this module has an interface at the appropriate absolute path
#    ezs.test.Module_INTERFACE_FILE := /abs/path/to/Module.hxx
#
# Specifies that this module has an implementation file at the appropriate absolute path
#    ezs.test.Module_IMPLEMENTATION_FILE := /abs/path/to/Module.cxx
#
# Specifies that this module's interface file directly imports ezs.adt.Vector and ezs.adt.Stack
#    ezs.test.Module_INTERFACE_DEPS := ezs.adt.Vector ezs.adt.Stack
#
# Specifies that this module's implementation file directly imports ezs.adt.Vector and ezs.adt.Stack
#    ezs.test.Module_IMPLEMENTATION_DEPS := ezs.adt.Vector ezs.adt.Stack

# Retrieve the directory part of a path without the trailing slash.
# /home/user/dir/file.txt -> /home/user/dir
getDir =$(foreach path,$(1),$(patsubst %/,%,$(dir $(path))))

# Retrieve the directory of the makefile in which this macro is expanded.
# Requires that that the macro is expanded before any include directives.
GET_CURRENT_DIR =$(call getDir,$(abspath $(lastword $(MAKEFILE_LIST))))

# Retrieve root directory before include directive
ROOT_DIR :=$(GET_CURRENT_DIR)

# Include src Makefile to populate MODULES, *_INTERFACE_FILE, *_IMPLEMENTATION_FILE,
# *_INTERFACE_DEPS and *_IMPLEMENTATION_DEPS
MODULES =

# Modules appending to this macro should be implementation only modules with main methods
# These modules will be named targets which generate the corresponding EXEs
MAIN_MODULES =

include $(ROOT_DIR)/src/ezs.mk


# UTILITY FUNCTIONS

# Removes duplicates from the input list
unique=$(if $(1),$(firstword $(1)) $(call unique,$(filter-out $(firstword $(1)),$(1))))

# DIRECTORY MANIPULATION

# Retrieve the file name from the input file path without any trailing file extension.
# For example, /home/user/MyFile.txt -> MyFile
getBaseFileName =$(basename $(notdir $(1)))

# Retrieve the name of the parent directory of the input file path.
getParentDirName =$(notdir $(call getDir,$(1)))



# MODULE MACRO VAR NAMES

# Retrieve the name of the INTERFACE_FILE macro for the given module name.
getModuleInterfaceFileVar =$(1)_INTERFACE_FILE

# Retrieve the name of the IMPLEMENTATION_FILE macro for the given module names.
getModuleImplementationFileVar =$(1)_IMPLEMENTATION_FILE

# Retrieves the macro variable name which contains the HEADER_FILE macro for the given module.
getModuleSourceHeaderFileVar =$(1)_HEADER_FILE

# Retrieves the macro variable name which contains the interface dependencies for the given module.
getModuleInterfaceDepsVar =$(1)_INTERFACE_DEPS

# Retrieves the macro variable name which contains the implementation dependencies of the given
# module.
getModuleImplementationDepsVar =$(1)_IMPLEMENTATION_DEPS

# Retrieves the macro variable name for header dependencies.
getModuleHeaderDepsVar =$(1)_HEADER_DEPS

# MODULE MACRO VAR EXPANSIONS

# Retrieves interface dependencies for the given module. Outputs zero, one, or many space separated
# module names.
getModuleInterfaceDeps=$(call getModuleHeaderDepsTransitiveClosure,$($(call getModuleInterfaceDepsVar,$(1))))

# Retrieves implementation dependencies for the given module. Outputs zero, one, or many space separated
# module names.
getModuleImplementationDeps=$(call getModuleHeaderDepsTransitiveClosure,$($(call getModuleImplementationDepsVar,$(1))))

# Retrieves the interface file path for the input module name. May be empty if the module
# does not specify an interface file.
getModuleInterfaceFile=$($(call getModuleInterfaceFileVar,$(1)))

# Retrieves the implementation file path for the input module name. May be empty if the module
# does not specify an implementation file.
getModuleImplementationFile=$($(call getModuleImplementationFileVar,$(1)))

# Retrieves the header file path for the input module name. May be empty if no such file is specified.
getModuleSourceHeaderFile=$($(call getModuleSourceHeaderFileVar,$(1)))

# Retrieves the set of direct header dependencies for the given module.
getModuleHeaderDeps=$($(call getModuleHeaderDepsVar,$(1)))

# For a given module with a set of header dependencies, retrieves the transitive closure of all
# its recursive header dependencies.
getModuleHeaderDepsTransitiveClosure =$(call unique,$(1) $(foreach module,$(1),$(call getModuleHeaderDepsTransitiveClosure,$(call getModuleHeaderDeps,$(module)))))

# Retrieves the set of direct module dependencies for the input module. This is the set of
# direct interface dependenices and direct implementation dependencies.
getModuleDeps=$(call getModuleInterfaceDeps,$(1)) $(call getModuleImplementationDeps,$(1))

# Retrieves the transitive closure of dependencies of the given input modules.
# The original modules plus all of its direct and and indirect dependencies
# (interface or implementation) is returned.
getModuleDepsTransitiveClosure =$(call unique,$(1) $(foreach module,$(1),$(call getModuleDepsTransitiveClosure,$(call getModuleDeps,$(module)))))

# Retrieves the complete set of direct or indirect interface and implementation
# dependencies for the given module.
getTransitiveModuleDeps=$(call getModuleDepsTransitiveClosure,$(call getModuleDeps,$(1)))


# MODULE to BUILD FILES

MODULE_BUILD_DIR=$(BUILD_DIR)/module

# Retrieves the build directory for the given module name.
# The build directory's location is dependent on the current build type
getModuleBuildDir=$(MODULE_BUILD_DIR)/$(1)

# Retrieves the base level include directory under which a module's header file is copied into.
getModuleBaseIncludeDir=$(call getModuleBuildDir,$(1))/include

# Converts a module of the form a.b.c.D to a/b/c representing the directory structure for including
# the module.
getModuleIncludeDirHierarchy=$(call getDir,$(subst .,/,$(1)))

# Retrieves the path to the full include directory in which the module's header file will be copied
# into.
getModuleFullIncludeDir=$(call getModuleBaseIncludeDir,$(1))/$(call getModuleIncludeDirHierarchy,$(1))

# Retrieves the full path to the header file location that the module's header file is copied to.
# Empty if the module does not have a header file.
getModuleHeaderFile=$(foreach filename,$(call getModuleSourceHeaderFile,$(1)),$(call getModuleFullIncludeDir,$(1))/$(notdir $(filename)))

# Retrieves the list of module header files for a set of input modules.
getModuleHeaderFileList=$(foreach module,$(1),$(call getModuleHeaderFile,$(module)))

# Retrieves the list of header files for the interface dependencies of the input module
getModuleInterfaceDepsHeaderFiles=$(call getModuleHeaderFileList,$(call getModuleInterfaceDeps,$(1)))

# Retrieves the list of header files for the implementation dependencies of the input module
getModuleImplementationDepsHeaderFiles=$(call getModuleHeaderFileList,$(call getModuleImplementationDeps,$(1)))

# Retrieves the module name from the build file
getModuleNameFromHeaderFile=$(firstword $(subst /, ,$(patsubst $(MODULE_BUILD_DIR)/%,%,$(1))))

BIN_DIR_NAME := bin

# Retrieve the location to place executables
getExeLocation=$(BUILD_DIR)/$(BIN_DIR_NAME)/$(1)
getExeLocationList=$(foreach module,$(1),$(call getExeLocation,$(module)))

getModuleFromExeLocation=$(patsubst $(BUILD_DIR)/$(BIN_DIR_NAME)/%,%,$(1))

# Retrieves the path to the object bmi file for the given module. If the module does not have a
# module interface file, returns empty.
getModuleBmiFile=$(foreach file,$(call getModuleInterfaceFile,$(1)),$(call getModuleBuildDir,$(1))/$(call getBaseFileName,$(file)).$(BMI_EXT))

# Retrieves the set of bmi files for the set of input modules, skipping modules which
# have no interface files.
getModuleBmiFileList=$(foreach module,$(1),$(call getModuleBmiFile,$(module)))

# Retrieves the location of the compiled object bmi files to generate for the given module.
# Returns empty if no interface file for the module exists.
getModuleBmiObjFile=$(foreach file,$(call getModuleBmiFile,$(1)),$(file).$(OBJ_EXT))

# Retrieves the set of object bmi files for the set of input modules, skipping modules which
# have no interface files.
getModuleBmiObjFileList=$(foreach module,$(1),$(call getModuleBmiObjFile,$(module)))

# Retrieves the path to the object file for the module implementation.
# Returns empty if the input module does not have an implementation.
getModuleObjFile=$(foreach file,$(call getModuleImplementationFile,$(1)),$(call getModuleBuildDir,$(1))/$(call getBaseFileName,$(file)).$(OBJ_EXT))

# Retrieves the set of implementation object files for the set of input modules, skipping modules which
# have no implementation file.
getModuleObjFileList=$(foreach module,$(1),$(call getModuleObjFile,$(module)))

# Retrieves all the object files which are to be linked into an executable for the input
# set of modules.
getModuleAllObjFileList=$(call getModuleBmiObjFileList,$(1)) $(call getModuleObjFileList,$(1))

# Retrieves the list of module bmi files for the interface dependencies of the input module.
getModuleInterfaceDepsBmi=$(call getModuleBmiFileList,$(call getModuleInterfaceDeps,$(1)))

# Retrieves the list of module bmi files for the implementation dependencies of the input module.
getModuleImplementationDepsBmi=$(call getModuleBmiFileList,$(call getModuleImplementationDeps,$(1)))





# FLAGS FOR MODULE DEPS

# For the input module, retrieves the include flag which marks the parent directory
# of the module's header file. Returns nothing if the module does not specify a header file.
getModuleIncludeFlag=$(foreach file,$(call getModuleHeaderFile,$(1)),-I$(call getModuleBaseIncludeDir,$(1)))

# For the input module, generates the -fmodule-file=file flag to its BMI file.
# Returns nothing if the module does not have an interface file
getModuleBmiFlag=$(foreach file,$(call getModuleBmiFile,$(1)),-fmodule-file=$(file))

getModuleBmiFlagFromBuildFile=$(call getModuleBmiFlag,$(call getModuleNameFromBuildFile,$(1)))

# For the input module, generates the -fmodule-file=name=file flag for its BMI file.
# Returns nothing if the module does not have an interface file
getModuleNamedBmiFlag=$(foreach file,$(call getModuleBmiFile,$(1)),-fmodule-file=$(1)=$(file))

# Retrieves the list of bmi flags for each interface module dependency of the input
getModuleInterfaceDepsBmiFlags=$(foreach module,$(call getModuleInterfaceDeps,$(1)),$(call getModuleBmiFlag,$(module)))

# Retrieves the list of bmi flags for each implementation module dependency of the input
getModuleImplementationDepsBmiFlags=$(foreach module,$(call getModuleImplementationDeps,$(1)),$(call getModuleBmiFlag,$(module)))

# Retrieves the list of bmi flags for each interface module dependency of the input
getModuleInterfaceDepsNamedBmiFlags=$(foreach module,$(call getModuleInterfaceDeps,$(1)),$(call getModuleNamedBmiFlag,$(module)))

# Retrieves the list of bmi flags for each interface module dependency. Determines the desired
# module from a build file input.
getModuleInterfaceDepsNamedBmiFlagsFromBuildFile=$(call getModuleInterfaceDepsNamedBmiFlags,$(call getModuleNameFromBuildFile,$(1)))

# Retrieves the list of bmi flags for each implementation module dependency of the input
getModuleImplementationDepsNamedBmiFlags=$(foreach module,$(call getModuleImplementationDeps,$(1)),$(call getModuleNamedBmiFlag,$(module)))

# Retrieves the list of bmi flags for each implementation module dependency. Determines the desired
# module from a build file input.
getModuleImplementationDepsNamedBmiFlagsFromBuildFile=$(call getModuleImplementationDepsNamedBmiFlags,$(call getModuleNameFromBuildFile,$(1)))

# Retrieves the list of include flags for each implementation module dependency of the input module.
getModuleImplementationDepsIncludeFlags=$(foreach module,$(call getModuleImplementationDeps,$(1)),$(call getModuleIncludeFlag,$(module)))

# Retrieves the list of include flags for each implementation module dependency for the module
# containing the build file specified in the input
getModuleImplementationDepsIncludeFlagsFromBuildFile=$(call getModuleImplementationDepsIncludeFlags,$(call getModuleNameFromBuildFile,$(1)))

# Retrieves the list of include flags for each interface module dependency of the input module.
getModuleInterfaceDepsIncludeFlags=$(foreach module,$(call getModuleInterfaceDeps,$(1)),$(call getModuleIncludeFlag,$(module)))

# Retrieves the list of include flags for each interface module dependency for the module
# containing the build file specified in the input
getModuleInterfaceDepsIncludeFlagsFromBuildFile=$(call getModuleInterfaceDepsIncludeFlags,$(call getModuleNameFromBuildFile,$(1)))



# PREREQ COMPUTATION

# Retrieves the set of module bmi prereqs
getModuleBmiPrereqs=$(call getModuleInterfaceFile,$(1))\
		    $(call getModuleInterfaceDepsBmi,$(1))\
		    $(call getModuleInterfaceDepsHeaderFiles,$(1))

# Retrieves the set of module bmi prereqs
getModuleObjPrereqs=$(call getModuleImplementationFile,$(1))\
		    $(call getModuleBmiFile,$(1))\
		    $(call getModuleImplementationDepsBmi,$(1))\
                    $(call getModuleImplementationDepsHeaderFiles,$(1))

# Retrieves the set of bmi obj prereqs
getModuleBmiObjPrereqs=$(call getModuleBmiFile,$(1))

# Retrieves the module name associated to the input build file path.
getModuleNameFromBuildFile =$(call getParentDirName,$(1))

# Retrieves the associated prerequisites using a build file as input to determine the
# appropriate module name
getModuleBmiPrereqsFromBuildFile=$(call getModuleBmiPrereqs,$(call getModuleNameFromBuildFile,$(1)))
getModuleObjPrereqsFromBuildFile=$(call getModuleObjPrereqs,$(call getModuleNameFromBuildFile,$(1)))
getModuleBmiObjPrereqsFromBuildFile=$(call getModuleBmiObjPrereqs,$(call getModuleNameFromBuildFile,$(1)))



# DIRECTORY STRUCTURE

SRC_DIR := $(ROOT_DIR)/src
BUILD_BASE_DIR := $(ROOT_DIR)/build
DEBUG_BUILD_DIR := $(BUILD_BASE_DIR)/debug
RELEASE_BUILD_DIR := $(BUILD_BASE_DIR)/release
SANITIZE_MEMORY_BUILD_DIR := $(BUILD_BASE_DIR)/sanitize-memory
SANITIZE_THREAD_BUILD_DIR := $(BUILD_BASE_DIR)/sanitize-thread
SANITIZE_UNDEFINED_BUILD_DIR := $(BUILD_BASE_DIR)/sanitize-undefined
SANITIZE_ADDRESS_BUILD_DIR := $(BUILD_BASE_DIR)/sanitize-address
BMI_EXT := bmi
OBJ_EXT := o

# Platform specific commands for adding/removing directories
MAKE_DIR := mkdir -p
RM_DIR := rm -r
cat = printf '$(1)' > $(2)



# CXX FLAGS
LLVM-PROJECT_ROOT:=/home/ezra/Documents/llvm-project/build/master/release
MSAN-LIBCXX_ROOT:=/home/ezra/Documents/llvm-project/build/master/msan-libcxx

CXX :=$(LLVM-PROJECT_ROOT)/bin/clang++

# Flags for each of the various build types
CXX_DEBUG_FLAGS := -O0 -ggdb
CXX_RELEASE_FLAGS := -O3 -flto
CXX_SANITIZE_ADDRESS_FLAGS := -g -O0 -fsanitize=address -fno-omit-frame-pointer
CXX_SANITIZE_THREAD_FLAGS := -g -O0 -fsanitize=thread -fno-omit-frame-pointer
CXX_SANITIZE_UNDEFINED_FLAGS := -g -O0 -fsanitize=undefined -fsanitize=implicit-conversion -fsanitize=nullability -fsanitize=integer -fno-omit-frame-pointer
CXX_SANITIZE_MEMORY_FLAGS := -g -O0 -fsanitize=memory -fsanitize-memory-track-origins -fno-omit-frame-pointer -nostdinc++ -I$(MSAN-LIBCXX_ROOT)/include/c++/v1 -nostdlib++ -L$(MSAN-LIBCXX_ROOT)/lib -lc++msan -lc++abi

# Set build location and flags for particular build type
BUILD_TYPE := DEBUG
ifeq ($(BUILD_TYPE),DEBUG)
  BUILD_DIR := $(DEBUG_BUILD_DIR)
  CXX_BUILD_TYPE_FLAGS := $(CXX_DEBUG_FLAGS)
else ifeq ($(BUILD_TYPE),RELEASE)
  BUILD_DIR :=$(RELEASE_BUILD_DIR)
  CXX_BUILD_TYPE_FLAGS := $(CXX_RELEASE_FLAGS)
else ifeq ($(BUILD_TYPE),SANITIZE_MEMORY)
  BUILD_DIR :=$(SANITIZE_MEMORY_BUILD_DIR)
  CXX_BUILD_TYPE_FLAGS := $(CXX_SANITIZE_MEMORY_FLAGS)
else ifeq ($(BUILD_TYPE),SANITIZE_THREAD)
  BUILD_DIR :=$(SANITIZE_THREAD_BUILD_DIR)
  CXX_BUILD_TYPE_FLAGS := $(CXX_SANITIZE_THREAD_FLAGS)
else ifeq ($(BUILD_TYPE),SANITIZE_ADDRESS)
  BUILD_DIR :=$(SANITIZE_ADDRESS_BUILD_DIR)
  CXX_BUILD_TYPE_FLAGS := $(CXX_SANITIZE_ADDRESS_FLAGS)
else ifeq ($(BUILD_TYPE),SANITIZE_UNDEFINED)
  BUILD_DIR :=$(SANITIZE_UNDEFINED_BUILD_DIR)
  CXX_BUILD_TYPE_FLAGS := $(CXX_SANITIZE_UNDEFINED_FLAGS)
else
  BUILD_DIR := $(DEBUG_BUILD_DIR)
  CXX_BUILD_TYPE_FLAGS := $(CXX_DEBUG_FLAGS)
  $(warning Unkown build type '$(BUILD_TYPE)'. Defaulting to DEBUG build.)
endif

# Flags common to all build types
CXX_COMMON_FLAGS = -std=c++20 -fmodules -fbuiltin-module-map \
 -fno-autolink -Wall -Wextra -Wpedantic -Werror -Wconversion \
 -pthread -fretain-comments-from-system-headers -stdlib=libc++ -Wno-unused-command-line-argument \
 -Wno-error=unused-variable -Wno-error=unneeded-internal-declaration -fuse-ld=lld

# Flags for the build type currently selected
CXX_FLAGS := $(CXX_COMMON_FLAGS) $(CXX_BUILD_TYPE_FLAGS)

# Command to be executed with appropriate flags
CXX_COMMAND := $(CXX) $(CXX_FLAGS)

# Flags for building a BMI file from a c++ module file
BUILD_BMI_FLAGS := -x c++-module --precompile 

# Flags for building an object file from a BMI file 
BUILD_BMI_OBJ_FLAGS := -x pcm 

# Flags for building an object file from a module implementation file
BUILD_OBJ_FLAGS := -x c++ 

# Flags for linking all object files together
LINK_OBJ_FLAGS := 


# COMPILE COMMANDS

COMMA:=,

lastword=$(word $(words text),$(1))
head=$(filter-out $(call lastword,$(1)),$(1))

# Assembles the inputs into a quotated, comman-separated list.
assembleArguments= \n\t$(foreach arg,$(call head,$(1)),"$(arg)",\n\t) "$(lastword $(1))"\n\t

# Retrieves arguments for building a module interface
getInterfaceArgs=$(CXX) $(CXX_FLAGS) $(call getModuleInterfaceDepsNamedBmiFlags,$(1)) $(call getModuleInterfaceDepsIncludeFlags,$(1)) -x c++-module --precompile $(call getModuleInterfaceFile,$(1)) 

assembleInterfaceArgs=$(call assembleArguments,$(call getInterfaceArgs,$(1)))

# Retrieves arguments for building a module implementation
getImplementationArgs=$(CXX) $(CXX_FLAGS) $(call getModuleImplementationDepsNamedBmiFlags,$(1)) $(call getModuleBmiFlag,$(1)) $(call getModuleImplementationDepsIncludeFlags,$(1)) -x c++ -c $(call getModuleImplementationFile,$(1))

assembleImplementationArgs=$(call assembleArguments,$(call getImplementationArgs,$(1)))


getInterfaceCompileCommand=$(foreach file,$(call getModuleInterfaceFile,$(1)),\
			{\n\t"arguments":[$(call assembleInterfaceArgs,$(1))],\
			\n\t"directory":"$(ROOT_DIR)",\
			\n\t"file":"$(patsubst $(ROOT_DIR)/%,%,$(file))"\n},)

getImplementationCompileCommand=$(foreach file,$(call getModuleImplementationFile,$(1)),\
			{\n\t"arguments":[$(call assembleImplementationArgs,$(1))],\
			\n\t"directory":"$(ROOT_DIR)",\
			\n\t"file":"$(patsubst $(ROOT_DIR)/%,%,$(file))"\n},)

getModuleCompileCommand=$(call getInterfaceCompileCommand,$(1))\
			$(call getImplementationCompileCommand,$(1))

COMPILE_COMMANDS = $(patsubst %}$(COMMA)],%}],[$(foreach module,$(MODULES),$(call getModuleCompileCommand,$(module)))])


# Used the target to build for the recipe that this appears in
PRINT_TARGET = $(info Building $(patsubst $(BUILD_DIR)/%,%,$@))

# Copy file
COPY := cp

# Enable secondary expansion of dependency expressions in recipes
.SECONDEXPANSION:

# Disable built-in and implicit rules
MAKEFLAGS += --no-builtin-rules --no-builtin-variables
.SUFFIXES:


all: $(MAIN_MODULES)

clean:
	@$(RM_DIR) $(BUILD_BASE_DIR)

# Builds the header files for the modules by copying them to the build location
$(call getModuleHeaderFileList,$(MODULES)) : $$(call getModuleSourceHeaderFile,$$(call getModuleNameFromHeaderFile,$$@))
	$(PRINT_TARGET)
	@$(MAKE_DIR) $(call getDir, $@)
	@$(COPY) $< $@

# Builds the module BMI files
$(call getModuleBmiFileList,$(MODULES)) : $$(call getModuleBmiPrereqsFromBuildFile,$$@)
	$(PRINT_TARGET)
	@$(MAKE_DIR) $(call getDir, $@)
	@$(CXX_COMMAND) $(BUILD_BMI_FLAGS) \
	$(call getModuleInterfaceDepsNamedBmiFlagsFromBuildFile,$@) \
        $(call getModuleInterfaceDepsIncludeFlagsFromBuildFile,$@) \
	-o $@ -c $<

# Builds the module BMI object files
$(call getModuleBmiObjFileList,$(MODULES)) : $$(call getModuleBmiObjPrereqsFromBuildFile,$$@)
	$(PRINT_TARGET)
	@$(MAKE_DIR) $(call getDir, $@)
	@$(CXX_COMMAND) $(BUILD_BMI_OBJ_FLAGS) -o $@ -c $<

# Builds the module implementation object files
$(call getModuleObjFileList,$(MODULES)) : $$(call getModuleObjPrereqsFromBuildFile,$$@)
	$(PRINT_TARGET)
	@$(MAKE_DIR) $(call getDir, $@)
	@$(CXX_COMMAND) $(BUILD_OBJ_FLAGS) \
	$(call getModuleBmiFlagFromBuildFile,$@) \
	$(call getModuleImplementationDepsNamedBmiFlagsFromBuildFile,$@) \
        $(call getModuleImplementationDepsIncludeFlagsFromBuildFile,$@) \
	-o $@ -c $<

# Links all object files into the executable
$(call getExeLocationList,$(MAIN_MODULES)) : $$(call getModuleAllObjFileList,$$(call getModuleFromExeLocation,$$@) $$(call getTransitiveModuleDeps,$$(call getModuleFromExeLocation,$$@)))
	$(PRINT_TARGET)
	$(info $(call getModuleFromExeLocation,$@))
	@$(MAKE_DIR) $(call getDir, $@)
	@$(CXX_COMMAND) $(LINK_OBJ_FLAGS) -o $@ $^

# Alias the main modules with the executable location
$(MAIN_MODULES) : $$(call getExeLocation,$$@)

# Alias each modules with the bmi, bmi object, and object files associated to it
$(MODULES) : $$(call getModuleBmiFile,$$@)
$(MODULES) : $$(call getModuleBmiObjFile,$$@)
$(MODULES) : $$(call getModuleObjFile,$$@)
$(MODULES) : $$(call getModuleHeaderFile,$$@)

compile-commands: 
	@$(call cat,$(COMPILE_COMMANDS),compile_commands.json)

dep-graph:
	@make -Bnd | grep -Ev *.mk | make2graph -b | dot -Tpng -o dep-graph.png

doc:
	@$(MAKE_DIR) $(BUILD_BASE_DIR)/doc
	doxygen $(ROOT_DIR)/Doxyfile


info:
	@$(CXX_COMMAND) -x c++ /dev/null -v -Xclang -fsyntax-only -c

test: export MSAN_SYMBOLIZER_PATH = $(LLVM-PROJECT_ROOT)/bin/llvm-symbolizer
test: ezs.main.Test
	@$(call getExeLocation,ezs.main.Test)

debug-test: export MSAN_SYMBOLIZER_PATH = $(LLVM-PROJECT_ROOT)/bin/llvm-symbolizer
debug-test: ezs.main.Test
	gdb $(call getExeLocation,ezs.main.Test)

.PHONY: info clean dep-graph compile-commands doc $(MAIN_MODULES)
