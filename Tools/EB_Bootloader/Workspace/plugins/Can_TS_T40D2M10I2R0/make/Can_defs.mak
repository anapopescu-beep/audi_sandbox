# \file
#
# \brief AUTOSAR Can
#
# This file contains the implementation of the AUTOSAR
# module Can.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2019 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# DEFINITIONS

Can_CORE_PATH      ?= $(SSC_ROOT)/Can_$(Can_VARIANT)
Can_OUTPUT_PATH    ?= $(AUTOSAR_BASE_OUTPUT_PATH)

Can_GEN_FILES  += $(wildcard $(Can_OUTPUT_PATH)/include/Can_*.h)
Can_GEN_FILES += $(wildcard $(Can_OUTPUT_PATH)/src/Can_*.c)

TRESOS_GEN_FILES   += $(Can_GEN_FILES)

CC_INCLUDE_PATH    += $(Can_CORE_PATH)/include
CC_INCLUDE_PATH    += $(Can_OUTPUT_PATH)/include

