####################
# TEMPLATE VERSION #
####################

# \file
#
# \brief AUTOSAR Flash
#
# This file contains the implementation of the AUTOSAR
# module Flash.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2018 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# DEFINITIONS

#################################################################
# REGISTRY

Flash_src_FILES      := \
     $(Flash_CORE_PATH)\src\FLASH_Prg.c \
     $(Flash_OUTPUT_PATH)\src\FLASH_Cfg.c \
     $(Flash_CORE_PATH)\src\FLASH_LLD.c
	 
# Add here the library source code file if it exists
Flash_src_FILES += $(Flash_CORE_PATH)\src\FLS_S32K14X.c
	 
#ASM_FILES_TO_BUILD  := \

LIBRARIES_TO_BUILD += Flash_src

#################################################################
# DEPENDENCIES (only for assembler files)
#


#################################################################
# RULES




