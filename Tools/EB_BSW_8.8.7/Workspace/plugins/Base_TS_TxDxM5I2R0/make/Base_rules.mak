#
# \file
#
# \brief AUTOSAR Base
#
# This file contains the implementation of the AUTOSAR
# module Base.
#
# \version 5.2.1
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

Base_src_FILES      := \
  $(Base_CORE_PATH)/src/TSMem.c \
  $(Base_CORE_PATH)/src/TSMemS.c \
  $(Base_CORE_PATH)/src/TSPBConfig.c \
  $(Base_CORE_PATH)/src/ComStack_Helpers.c

LIBRARIES_TO_BUILD   += Base_src

#################################################################
# RULES
