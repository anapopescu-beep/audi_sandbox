# \file
#
# \brief AUTOSAR Resource
#
# This file contains the implementation of the AUTOSAR
# module Resource.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2019 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# DEFINITIONS

Resource_CORE_PATH      ?= $(SSC_ROOT)/Resource_$(Resource_VARIANT)
Resource_OUTPUT_PATH    ?= $(AUTOSAR_BASE_OUTPUT_PATH)

Resource_GEN_FILES     += $(wildcard $(Resource_OUTPUT_PATH)/include/modules.h)
Resource_GEN_FILES     += $(wildcard $(Resource_OUTPUT_PATH)/include/Reg_eSys.h)

TRESOS_GEN_FILES   += $(Resource_GEN_FILES)

CC_INCLUDE_PATH    += $(Resource_CORE_PATH)/include
CC_INCLUDE_PATH    += $(Resource_OUTPUT_PATH)/include

# Add mandatory defines to compiler options
CC_OPT          += -DDISABLE_MCAL_INTERMODULE_ASR_CHECK
DEPEND_GCC_OPTS += -DDISABLE_MCAL_INTERMODULE_ASR_CHECK

CC_OPT          += -DCOMPILERCFG_EXTENSION_MCAL_FILE
DEPEND_GCC_OPTS += -DCOMPILERCFG_EXTENSION_MCAL_FILE

