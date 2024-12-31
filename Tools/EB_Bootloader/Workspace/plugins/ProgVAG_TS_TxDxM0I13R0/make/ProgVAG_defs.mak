# \file
#
# \brief ProgVAG
#
# This file contains the implementation of the 
# module ProgVAG.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2010 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# DEFINITIONS

ProgVAG_CORE_PATH         := $(SSC_ROOT)\ProgVAG_$(ProgVAG_VARIANT)

ProgVAG_OUTPUT_PATH       := $(AUTOSAR_BASE_OUTPUT_PATH)

#################################################################
# REGISTRY
SSC_PLUGINS           += ProgVAG
ProgVAG_DEPENDENT_PLUGINS := base_make tresos
ProgVAG_VERSION           := 2.00.00
ProgVAG_DESCRIPTION       := ProgVAG Basic Software Makefile PlugIn
CC_INCLUDE_PATH       +=    \
   $(ProgVAG_CORE_PATH)\include \
   $(ProgVAG_OUTPUT_PATH)\include
