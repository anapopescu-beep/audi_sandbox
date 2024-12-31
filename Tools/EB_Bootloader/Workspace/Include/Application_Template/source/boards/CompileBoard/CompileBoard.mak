# \file
#
# \brief AUTOSAR ApplTemplates
#
# This file contains the implementation of the AUTOSAR
# module ApplTemplates.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2018 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.


ifeq ($(OS_BOARD_DIR), )
OS_BOARD_DIR=$(BOARD_PROJECT_PATH)
endif

CC_INCLUDE_PATH      += $(OS_BOARD_DIR)
CPP_INCLUDE_PATH     += $(OS_BOARD_DIR)
ASM_INCLUDE_PATH     += $(OS_BOARD_DIR)

CC_FILES_TO_BUILD    += $(OS_BOARD_DIR)\board.c
ASM_FILES_TO_BUILD   +=
EXCLUDE_MAKE_DEPEND  +=

LOC_FILE= $(BOARD_PROJECT_PATH)\$(BOARD).ldscript

