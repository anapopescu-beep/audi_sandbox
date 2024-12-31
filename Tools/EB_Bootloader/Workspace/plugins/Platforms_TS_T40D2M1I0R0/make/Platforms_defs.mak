# \file
#
# \brief AUTOSAR Platforms
#
# This file contains the implementation of the AUTOSAR
# module Platforms.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2019 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

##################################################################
# DEFINITIONS

Platforms_CORE_PATH   ?= $(PLUGINS_BASE)\Platforms_$(Platforms_VARIANT)
Platforms_OUTPUT_PATH ?= $(AUTOSAR_BASE_OUTPUT_PATH)

#################################################################
# REGISTRY
SSC_PLUGINS          += Platforms

CC_INCLUDE_PATH      += \
   $(Platforms_CORE_PATH)\include \
   $(Platforms_CORE_PATH)\include\$(TARGET) \
   $(Platforms_CORE_PATH)\include\$(TARGET)\$(DERIVATE)

-include $(AUTOSAR_BASE_PATH)\make\$(CPU)\Platforms_defs_$(CPU).mak
