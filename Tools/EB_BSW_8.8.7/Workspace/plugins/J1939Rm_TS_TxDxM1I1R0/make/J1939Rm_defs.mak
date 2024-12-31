#
# \file
#
# \brief AUTOSAR J1939Rm
#
# This file contains the implementation of the AUTOSAR
# module J1939Rm.
#
# \version 1.1.9
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2022 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.


#################################################################
# DEFINITIONS
J1939Rm_CORE_PATH             ?= $(PLUGINS_BASE)/J1939Rm_$(J1939Rm_VARIANT)
J1939Rm_OUTPUT_PATH           ?= $(AUTOSAR_BASE_OUTPUT_PATH)
J1939Rm_Wrapper_OUTPUT_PATH   := $(AUTOSAR_BASE_OUTPUT_PATH)

#################################################################
# REGISTRY
SSC_PLUGINS           += J1939Rm
J1939Rm_DEPENDENT_PLUGINS := base_make tresos
J1939Rm_VERSION           := 1.00.00
J1939Rm_DESCRIPTION       := J1939Rm Basic Software Makefile PlugIn for Autosar
CC_INCLUDE_PATH       +=    \
   $(J1939Rm_CORE_PATH)/include \
   $(J1939Rm_OUTPUT_PATH)/include
