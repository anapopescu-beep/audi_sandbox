# \file
#
# \brief AUTOSAR Fls
#
# This file contains the implementation of the AUTOSAR
# module Fls.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2019 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# DEFINITIONS

Fls_CORE_PATH      ?= $(SSC_ROOT)/Fls_$(Fls_VARIANT)
Fls_OUTPUT_PATH    ?= $(AUTOSAR_BASE_OUTPUT_PATH)

Fls_GEN_FILES  += $(wildcard $(Fls_OUTPUT_PATH)/include/Fls_*.h)
Fls_GEN_FILES += $(wildcard $(Fls_OUTPUT_PATH)/src/Fls_*.c)

TRESOS_GEN_FILES   += $(Fls_GEN_FILES)

CC_INCLUDE_PATH    += $(Fls_CORE_PATH)/include
CC_INCLUDE_PATH    += $(Fls_OUTPUT_PATH)/include

