# #############################################################################
#
# $Id: FRDMPK144_Q100_NoOS.mak 1.2.1.2 2022/09/01 06:53:03CEST Andrei Anca (andrei.anca) in_work  $
#
# This makefile contains board-specific definitions and rules.
#
# Copyright Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.
#
# #############################################################################

# TOOLCHAIN mapping ###########################################################

LIB_INCLUDE_PATH+=$(TOOLPATH_COMPILER)\lib\ 

# DEFINITIONS #################################################################

CC_INCLUDE_PATH      += $(BOARD_PROJECT_PATH)
CPP_INCLUDE_PATH     += $(BOARD_PROJECT_PATH)
ASM_INCLUDE_PATH     += $(BOARD_PROJECT_PATH)

CC_FILES_TO_BUILD    += $(BOARD_PROJECT_PATH)\board.c
CC_FILES_TO_BUILD    += $(BOARD_PROJECT_PATH)\board_reset_vector.c
CC_FILES_TO_BUILD    += $(BOARD_PROJECT_PATH)\board_irq.c

ASM_FILES_TO_BUILD   += $(BOARD_PROJECT_PATH)\boardStartup.s
ASM_FILES_TO_BUILD   += $(BOARD_PROJECT_PATH)\interruptvectors.s
ASM_FILES_TO_BUILD   += $(BOARD_PROJECT_PATH)\exceptiontable.s

# defines #####################################################################
LINK_CONST_CODE_TARGET ?= FLASH

# setup config parameter ######################################################
# boot from ROM or RAM ?
ifeq ($(LINK_CONST_CODE_TARGET),RAM)
LINK_VARIANT := ram
OS_GENLD_OPT += -disableRomInit
else
LINK_VARIANT := flash
endif

# toolchain specific configs
ifeq ($(TOOLCHAIN),multi)
  LOC_FILE_SUFFIX ?= ld
  LINK_OPT += -entry=main
endif
ifeq ($(TOOLCHAIN),gnu)
OS_GENLD = $(AutosarOS_CORE_PATH)/bin/genld$(OS_HYPHEN)$(CPU).pl
LOC_FILE_SUFFIX=ldscript
LINK_OPT += -Wl,--undefined=CORTEXMExceptionTable
LINK_OPT += -Wl,--undefined=CORTEXMInterruptTable
LINK_OPT += -Wl,--entry=boardResetStart
endif

ifeq ($(TOOLCHAIN),iar)
  LOC_FILE_SUFFIX ?= ldscript
endif

LOC_FILE = $(BOARD_PROJECT_PATH)\board_flash-$(TOOLCHAIN).$(LOC_FILE_SUFFIX)
# Editor settings - DO NOT DELETE
# vi:set ts=4:
#################################################################
# TRACE32_PATH
# Path to the Trace32 Debugger
TRACE32_PATH ?= C:\tools\T32
TRACE32_APP_PATH ?= $(TRACE32_PATH)\bin\windows64