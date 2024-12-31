# \file
#
# \brief AUTOSAR Spi
#
# This file contains the implementation of the AUTOSAR
# module Spi.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2019 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# DEFINITIONS

Spi_CORE_PATH      ?= $(SSC_ROOT)/Spi_$(Spi_VARIANT)
Spi_OUTPUT_PATH    ?= $(AUTOSAR_BASE_OUTPUT_PATH)

Spi_GEN_FILES  += $(wildcard $(Spi_OUTPUT_PATH)/include/Spi_*.h)
Spi_GEN_FILES += $(wildcard $(Spi_OUTPUT_PATH)/src/Spi_*.c)

TRESOS_GEN_FILES   += $(Spi_GEN_FILES)

CC_INCLUDE_PATH    += $(Spi_CORE_PATH)/include
CC_INCLUDE_PATH    += $(Spi_OUTPUT_PATH)/include

