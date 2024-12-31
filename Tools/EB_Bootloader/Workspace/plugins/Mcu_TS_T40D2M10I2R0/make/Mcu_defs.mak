# \file
#
# \brief AUTOSAR Mcu
#
# This file contains the implementation of the AUTOSAR
# module Mcu.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2019 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# DEFINITIONS

Mcu_CORE_PATH      ?= $(SSC_ROOT)/Mcu_$(Mcu_VARIANT)
Mcu_OUTPUT_PATH    ?= $(AUTOSAR_BASE_OUTPUT_PATH)

Mcu_GEN_FILES  += $(wildcard $(Mcu_OUTPUT_PATH)/include/Mcu_*.h)
Mcu_GEN_FILES += $(wildcard $(Mcu_OUTPUT_PATH)/src/Mcu_*.c)

TRESOS_GEN_FILES   += $(Mcu_GEN_FILES)

CC_INCLUDE_PATH    += $(Mcu_CORE_PATH)/include
CC_INCLUDE_PATH    += $(Mcu_OUTPUT_PATH)/include

