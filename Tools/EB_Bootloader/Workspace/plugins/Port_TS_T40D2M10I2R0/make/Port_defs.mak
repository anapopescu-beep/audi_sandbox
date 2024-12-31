# \file
#
# \brief AUTOSAR Port
#
# This file contains the implementation of the AUTOSAR
# module Port.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2019 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# DEFINITIONS

Port_CORE_PATH      ?= $(SSC_ROOT)/Port_$(Port_VARIANT)
Port_OUTPUT_PATH    ?= $(AUTOSAR_BASE_OUTPUT_PATH)

Port_GEN_FILES  += $(wildcard $(Port_OUTPUT_PATH)/include/Port_*.h)
Port_GEN_FILES += $(wildcard $(Port_OUTPUT_PATH)/src/Port_*.c)

TRESOS_GEN_FILES   += $(Port_GEN_FILES)

CC_INCLUDE_PATH    += $(Port_CORE_PATH)/include
CC_INCLUDE_PATH    += $(Port_OUTPUT_PATH)/include

