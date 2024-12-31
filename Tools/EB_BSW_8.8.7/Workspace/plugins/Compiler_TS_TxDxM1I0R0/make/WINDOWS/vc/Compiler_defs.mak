# --------{ EB Automotive Makefile }--------

##################################################################
# REQUIRED DEFINITIONS
#

EXE_FILE_SUFFIX ?=.exe

TOOLCHAIN               = vc

OBJ_FILE_SUFFIX         = obj
OBJ_FILE_SUFFIX_2       =

LIB_FILE_SUFFIX         = lib

ASM_FILE_SUFFIX         = S
ASM_FILE_SUFFIX_2       = s

CC_FILE_SUFFIX          = c
CC_FILE_SUFFIX_2        =

CPP_FILE_SUFFIX         = cpp
CPP_FILE_SUFFIX_2       =

PREP_FILE_SUFFIX        = i
H_FILE_SUFFIX           = h
H_FILE_SUFFIX_2         =

INCLUDE_PREFIX          = /I
MACRO_PREFIX            = /D

HEX_FILE_SUFFIX         = exe

FIRST_BUILD_TARGET      = $(BIN_OUTPUT_PATH)\$(PROJECT).$(HEX_FILE_SUFFIX)

LIB_DIR                 = $(OUTPUT_DIR)/lib
COMPILER_DIR            = $(TOOLPATH_COMPILER)/bin

build-prep-file-PROVIDED := true

DEPEND_GCC_OPTS         += \
                   -I$(SSC_ROOT)\Make_$(Make_VARIANT)\tools\gcc\include
PROJECT_BINARY  = $(BIN_OUTPUT_PATH)/$(PROJECT)$(EXE_FILE_SUFFIX)
FIRST_BUILD_TARGET := $(PROJECT_BINARY)
MAPFILE         = $(BIN_OUTPUT_PATH)/$(PROJECT).map
# set the path for Visual Studio C++
OLDPATH                 := $(PATH)
PATH                    = $(TOOLPATH_COMPILER)\..\Common7\IDE;$(TOOLPATH_COMPILER)\BIN;$(TOOLPATH_COMPILER)\..\Common7\Tools;$(TOOLPATH_COMPILER)\..\Common7\Tools\bin\prerelease;$(TOOLPATH_COMPILER)\..\Common7\Tools\bin;$(OLDPATH)
export PATH


#################################################################
# This macro returns a list of all macros e.g.: -DXXX -DXXX.
# The abstract definition of macros in PREPROCESSOR_DEFINES will
# be transformed in the compiler specific macro definition.
GET_PREPROCESSOR_DEFINES = $(foreach DEF,$(PREPROCESSOR_DEFINES),$(MACRO_PREFIX)$($(DEF)_KEY)=$($(DEF)_VALUE))


#################################################################
# Name of the C-compiler
ifneq ($(DISABLE_DEFAULT_CC),YES)
CC                      = $(TOOLPATH_COMPILER)/bin/cl$(EXE_FILE_SUFFIX)
endif

#################################################################
# Name of the assembler
ifneq ($(DISABLE_DEFAULT_ASM),YES)
ASM                     = $(TOOLPATH_COMPILER)/bin/ml64$(EXE_FILE_SUFFIX)
endif


CCLIB                     = $(TOOLPATH_COMPILER)/bin/lib$(EXE_FILE_SUFFIX)

#################################################################
# Name of the linker
ifneq ($(DISABLE_DEFAULT_LINK),YES)
LINK                    = $(TOOLPATH_COMPILER)/bin/link$(EXE_FILE_SUFFIX)
endif

#################################################################
# Name of the preprocessor and the c compiler
ifneq ($(DISABLE_DEFAULT_CPRE),YES)
CPRE                    = $(TOOLPATH_COMPILER)/bin/cl$(EXE_FILE_SUFFIX)
endif

#################################################################
# Name of the archiver
ifneq ($(DISABLE_DEFAULT_LIB),YES)
LIB                     = $(TOOLPATH_COMPILER)/bin/lib$(EXE_FILE_SUFFIX)
endif

MAKE_CLEAN_RULES        += compiler_clean
