#
# \file
#
# \brief AUTOSAR ETS
#
# This file contains the implementation of the AUTOSAR
# module ETS.
#
# \version 2.5.0
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2022 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.


#################################################################
# DEFINITIONS

ifeq ($(BUILD_MODE),LIB)
ifeq ($(MODULE),ETS)
LIB_VARIANTS                  += ETS_BASE
endif
endif

ETS_CORE_PATH                 ?= $(PLUGINS_BASE)/ETS_$(ETS_VARIANT)
ETS_OUTPUT_PATH               := $(AUTOSAR_BASE_OUTPUT_PATH)

ETS_GEN_FILES                 :=                                    \
  $(ETS_CORE_PATH)/generate/include/ETS_Cfg.h

ETS_lib_LIB_OUTPUT_PATH       := $(ETS_CORE_PATH)/lib

#################################################################
# REGISTRY

SSC_PLUGINS                   += ETS
ETS_DEPENDENT_PLUGINS      := base_make tresos
ETS_VERSION                := 1.00.00
ETS_DESCRIPTION            := ETS Basic Software Makefile PlugIn for Autosar

CC_INCLUDE_PATH               += \
  $(ETS_CORE_PATH)/include    \
  $(ETS_OUTPUT_PATH)/include

ASM_INCLUDE_PATH              +=
CPP_INCLUDE_PATH              +=
