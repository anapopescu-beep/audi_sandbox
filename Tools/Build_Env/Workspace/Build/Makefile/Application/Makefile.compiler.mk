ASM_SUFFIX := s
C_SUFFIX := c
H_SUFFIX := h
DEP_SUFFIX := d
LST_SUFFIX := lst
ERR_SUFFIX := err
WARN_SUFFIX := warn
DEP_WARN_SUFFIX := dwarn
OBJ_SUFFIX := o
MAP_SUFFIX := map
LNK_SUFFIX := icf
BINARY_SUFFIX := elf
SYM_SUFFIX := sym
SYMBOL_SUFFIX :=
SREC_SUFFIX := s19
HEX_SUFFIX := hex
VBF_SUFFIX := vbf

PFLASH_PATT_FILE_SUFFIX := debug
FINAL_FILE_SUFFIX := customer

COMPILER_LICENSE_MANAGER_PRODUCT := ARM.EW

ifeq ($(BUILD_MODE),RELEASE)
override COMPILER_DIR := $(subst Embedded Workbench 8.3,Embedded Workbench 8.3 EWARM FS 8.40.3,$(COMPILER_DIR))
override COMPILER_LICENSE_MANAGER_PRODUCT := ARMFS840.EW
$(info COMPILER_DIR set to $(COMPILER_DIR))
endif

COMPILER_LICENSE_MANAGER_BIN := $(subst /arm/bin,/common/bin,$(subst \,/,$(COMPILER_DIR)))

COMP := $(subst \,/,$(COMPILER_DIR))/iccarm.exe
AS := $(subst \,/,$(COMPILER_DIR))/iasmarm.exe
CPP = $(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/Make_TS_TxDxM4I0R0/tools/gcc/bin/cpp.exe 
LINK := $(subst \,/,$(COMPILER_DIR))/ilinkarm.exe
LIB := 
CELF := $(subst \,/,$(COMPILER_DIR))/ielftool.exe
CHEX := $(subst \,/,$(COMPILER_DIR))/ielftool.exe
CPRD :=
PARSER :=
CODE_OPTIMIZER :=
CODE_GEN :=
LICENSE_SERVER := IAR License Manager
IMAGE_CREATOR := csapacmpz.exe

DEP := $(subst \,/,$(COMPILER_DIR))/iccarm.exe

COMPILER_INC  = $(COMPILER_DIR)/../inc/c/
COMPILER_LIB  = 

# filename    : Makefile.compiler
# description : Compiler specific variable setup
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018-2022, Autoliv Romania
# version     : 2.0.0
# email       : dan.dustinta@autoliv.com
# status      : Released
