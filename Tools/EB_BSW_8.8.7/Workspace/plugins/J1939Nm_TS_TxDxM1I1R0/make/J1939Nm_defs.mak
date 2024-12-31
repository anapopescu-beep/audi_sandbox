#
# \file
#
# \brief AUTOSAR J1939Nm
#
# This file contains the implementation of the AUTOSAR
# module J1939Nm.
#
# \version 1.1.7
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2022 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.


#################################################################
# DEFINITIONS
J1939Nm_CORE_PATH             ?= $(PLUGINS_BASE)/J1939Nm_$(J1939Nm_VARIANT)
J1939Nm_OUTPUT_PATH           ?= $(AUTOSAR_BASE_OUTPUT_PATH)
J1939Nm_Wrapper_OUTPUT_PATH   := $(AUTOSAR_BASE_OUTPUT_PATH)

#################################################################
# REGISTRY

J1939Nm_DEPENDENT_PLUGINS := base_make tresos
J1939Nm_VERSION           := 1.00.00
J1939Nm_DESCRIPTION       := J1939Nm Basic Software Makefile PlugIn for Autosar
CC_INCLUDE_PATH       +=    \
   $(J1939Nm_CORE_PATH)/include \
   $(J1939Nm_OUTPUT_PATH)/include
