# \file
#
# \brief Autosar Flash
#
# This file contains the implementation of the Autosar
# module Flash.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2010 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# DEFINITIONS

#################################################################
# REGISTRY

Flash_src_FILES      := $(Flash_CORE_PATH)/src/Flash_Prg.c\
                        $(Flash_CORE_PATH)/src/FlashWrapper.c\
                        $(Flash_CORE_PATH)/src/FlsLoaderWrapper.c \
                        $(Flash_OUTPUT_PATH)/src/Flash_Cfg.c   

LIBRARIES_TO_BUILD += Flash_src

#################################################################
# DEPENDENCIES (only for assembler files)
#


#################################################################
# RULES




