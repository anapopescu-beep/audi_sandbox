#
# \file
#
# \brief AUTOSAR Compiler
#
# This file contains the implementation of the AUTOSAR
# module Compiler.
#
# \version 1.0.12
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2017 - 2022 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.


EXE_FILE_SUFFIX ?=.exe

PROJECT_BINARY  = $(BIN_OUTPUT_PATH)/$(PROJECT)$(EXE_FILE_SUFFIX)
FIRST_BUILD_TARGET := $(PROJECT_BINARY)
MAPFILE         = $(BIN_OUTPUT_PATH)/$(PROJECT).map

TOOLPATH_COMPILER_INTERN:= $(PLUGINS_BASE)/Platforms_$(Platforms_VARIANT)/tools/mingw-gcc-4.5.1/bin
COMPILER_SFXARCHIVE     := $(PLUGINS_BASE)/Platforms_$(Platforms_VARIANT)/tools/mingw-gcc-4.5.1/MinGw$(EXE_FILE_SUFFIX)

# check is necessary, TOOLPATH_COMPILER is always set on CC, for WINDOWS it is set empty
ifeq (,$(strip $(TOOLPATH_COMPILER)))
  TOOLPATH_COMPILER       := $(TOOLPATH_COMPILER_INTERN)
endif

CC              = $(TOOLPATH_COMPILER)/gcc$(EXE_FILE_SUFFIX)
CCLIB           = $(TOOLPATH_COMPILER)/ar$(EXE_FILE_SUFFIX)
LINK            = $(TOOLPATH_COMPILER)/gcc$(EXE_FILE_SUFFIX)
ASM             = $(TOOLPATH_COMPILER)/gcc$(EXE_FILE_SUFFIX)
OBJCOPY         = $(TOOLPATH_COMPILER)/objcopy$(EXE_FILE_SUFFIX)
GCC             = $(MAKE_ROOT)/tools/gcc/bin/cpp$(EXE_FILE_SUFFIX)
COMPILER_DIR    = $(TOOLPATH_COMPILER)
DEBUGGER        = $(TOOLPATH_COMPILER)/gdb$(EXE_FILE_SUFFIX)

# check if internal compiler is used
ifeq ($(TOOLPATH_COMPILER),$(TOOLPATH_COMPILER_INTERN))
  ifeq (,$(realpath $(CC)))
    # compiler not found: unzip it
    OUTPUT_SHELL:= $(shell $(COMPILER_SFXARCHIVE) -y)
  endif
endif

ifeq (,$(realpath $(GCC)))
  $(error FILE DOES NOT EXIST GCC $(GCC))
endif

# ensure the compiler directory is in the path!
ifeq (,$(realpath $(subst ;,/libgmp-10.dll ,$(subst \,/,$(PATH));)))
  export PATH:=$(TOOLPATH_COMPILER);$(PATH)
endif