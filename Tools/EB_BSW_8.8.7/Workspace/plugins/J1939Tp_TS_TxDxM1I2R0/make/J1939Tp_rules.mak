#################################################################
##
## AUTOSAR J1939Tp J1939 Transport Protocol
##
## This makefile contains the rules to built the module.
##
## project      AUTOSAR Standard Core
## author       Nikolaus Donath
## author       3SOFT GmbH, 91058 Erlangen, Germany
##
## $Id: J1939Tp_rules.mak 1.1 2023/04/18 07:00:29CEST Dan Dustinta (dan.dustinta) in_work  $
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



LIBRARIES_TO_BUILD      += J1939Tp_src

J1939Tp_lib_FILES            +=

J1939Tp_src_FILES            +=                                          \
                             $(J1939Tp_CORE_PATH)/src/J1939Tp.c          \
                             $(J1939Tp_OUTPUT_PATH)/src/J1939Tp_Cfg.c    


CPP_FILES_TO_BUILD      +=
ASM_FILES_TO_BUILD      +=


MAKE_CLEAN_RULES        +=
MAKE_GENERATE_RULES     +=
MAKE_COMPILE_RULES      +=
#MAKE_DEBUG_RULES       +=
MAKE_CONFIG_RULES       +=
#MAKE_ADD_RULES         +=



#################################################################
# DEPENDENCIES (only for assembler files)
#

#################################################################
# RULES