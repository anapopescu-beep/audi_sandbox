#
# \file
#
# \brief AUTOSAR Os
#
# This file contains the implementation of the AUTOSAR
# module Os.
#
# \version 6.1.144
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 1998 - 2023 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.


#################################################################
# DEFINITIONS
ifeq ($(Os_CORE_PATH),)
  AutosarOS_CORE_PATH    = $(PLUGINS_BASE)/Os_TS_T40D2M6I1R0
  AutosarOS_LIB_PATH     = $(PLUGINS_BASE)/Os_$(Os_VARIANT)/lib
else
  AutosarOS_CORE_PATH    = $(realpath $(Os_CORE_PATH)/..)/Os_TS_T40D2M6I1R0
  AutosarOS_LIB_PATH     = $(Os_CORE_PATH)/lib
endif

OS_ARCH := CORTEXM
OS_CPU := S32K14X

include $(AutosarOS_CORE_PATH)/make/Os_definitions.mak
#########################
# Editor settings: DO NOT DELETE
# vi:set ts=4:
