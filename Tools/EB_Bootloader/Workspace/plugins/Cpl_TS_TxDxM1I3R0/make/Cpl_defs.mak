#################################################################
##
## AUTOSAR Cpl
##
## This makefile contains the rules to built the module.
##
## project      AUTOSAR Standard Core
## author       Alexander Much
## author       3SOFT GmbH, 91058 Erlangen, Germany
##
## $Id: Cpl_defs.mak 1.3.1.2 2022/09/01 06:52:51CEST Andrei Anca (andrei.anca) in_work  $
## Release: VSC_ACG8_CORTEXM_S32K14X
##
## controller   <Microcontroller, family, derivative, stepping>
## compiler     <Supported compiler and version>
## hardware     <Supported hardware, e.g. external EEPROM>
##
## Copyright 2005,2006 by 3SOFT GmbH
## All rights exclusively reserved for 3SOFT GmbH,
## unless expressly agreed to otherwise
##
#################################################################

#################################################################
# DEFINITIONS

ifeq ($(BUILD_MODE),LIB)
ifeq ($(MODULE),Cpl)
LIB_VARIANTS            += Cpl_BASE
endif
endif

Cpl_CORE_PATH           := $(SSC_ROOT)\Cpl_$(Cpl_VARIANT)

Cpl_OUTPUT_PATH         := $(AUTOSAR_BASE_OUTPUT_PATH)

Cpl_GEN_FILES           := $(subst $(Cpl_CORE_PATH)\generate,$(Cpl_OUTPUT_PATH),$(subst /,\,$(wildcard $(subst \,/,$(Cpl_CORE_PATH))/generate/include/Cpl*.h)))

Cpl_lib_LIB_OUTPUT_PATH := $(Cpl_CORE_PATH)\lib

#################################################################
# REGISTRY
SSC_PLUGINS             += Cpl
Cpl_DEPENDENT_PLUGINS   := base_make tresos
Cpl_VERSION             := 2.00.00
Cpl_DESCRIPTION         := Cpl Basic Software Makefile PlugIn for Autosar

CC_INCLUDE_PATH         +=      \
   $(Cpl_CORE_PATH)\include     \
   $(Cpl_CORE_PATH)\lib_include \
   $(Cpl_OUTPUT_PATH)\include

ASM_INCLUDE_PATH        +=
CPP_INCLUDE_PATH        +=
