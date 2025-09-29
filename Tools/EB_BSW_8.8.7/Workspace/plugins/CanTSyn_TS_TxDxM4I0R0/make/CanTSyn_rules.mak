#
# \file
#
# \brief AUTOSAR CanTSyn
#
# This file contains the implementation of the AUTOSAR
# module CanTSyn.
#
# \version 4.0.1
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2022 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.


#################################################################
# DEFINITIONS


#################################################################
# REGISTRY

LIBRARIES_TO_BUILD     += CanTSyn_src

CanTSyn_src_FILES      := \
    $(CanTSyn_CORE_PATH)/src/CanTSyn.c \
    $(CanTSyn_OUTPUT_PATH)/src/CanTSyn_Cfg.c \
    $(CanTSyn_OUTPUT_PATH)/src/CanTSyn_Multicore.c \

#################################################################
# DEPENDENCIES (only for assembler files)
#

#################################################################
# RULES