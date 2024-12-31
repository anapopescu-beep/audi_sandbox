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
## $Id: Cpl_rules.mak 1.1 2023/04/18 07:08:42CEST Dan Dustinta (dan.dustinta) in_work  $
## Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
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


#################################################################
# REGISTRY

Cpl_lib_FILES         :=

Cpl_src_FILES         +=                                                      $(wildcard $(subst \,/,$(Cpl_CORE_PATH))/src/Cpl*.c)           \
                         $(subst $(Cpl_CORE_PATH)/generate,$(Cpl_OUTPUT_PATH),$(wildcard $(subst \,/,$(Cpl_CORE_PATH))/generate/src/Cpl*.c))

LIBRARIES_TO_BUILD    += Cpl_src

DIRECTORIES_TO_CREATE += $(Cpl_lib_LIB_OUTPUT_PATH)

CC_FILES_TO_BUILD     +=
CPP_FILES_TO_BUILD    +=
ASM_FILES_TO_BUILD    +=

MAKE_CLEAN_RULES      +=
MAKE_GENERATE_RULES   +=
MAKE_COMPILE_RULES    +=
#MAKE_DEBUG_RULES      +=
MAKE_CONFIG_RULES     +=
#MAKE_ADD_RULES        +=


define defineCplLibOutputPATH
$(1)_OBJ_OUTPUT_PATH    := $(Cpl_lib_LIB_OUTPUT_PATH)
endef
$(foreach SRC,$(basename $(notdir $(subst \,/,$(Cpl_lib_FILES)))),\
$(eval $(call defineCplLibOutputPATH,$(SRC))))

#################################################################
# DEPENDENCIES (only for assembler files)
#

#################################################################
# RULES
