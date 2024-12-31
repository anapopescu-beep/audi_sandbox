#################################################################
##
## AUTOSAR J1939Tp J1939 Transport Protocol
##
## This makefile included definitions used by other modules.
##
## project      AUTOSAR Standard Core
## author       Nikolaus Donath
## author       3SOFT GmbH, 91058 Erlangen, Germany
##
## $Id: J1939Tp_defs.mak 1.1 2023/04/18 07:00:29CEST Dan Dustinta (dan.dustinta) in_work  $
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
J1939Tp_CORE_PATH      = $(SSC_ROOT)/J1939Tp_$(J1939Tp_VARIANT)
J1939Tp_OUTPUT_PATH    = $(AUTOSAR_BASE_OUTPUT_PATH)



J1939Tp_GEN_FILES      = \
                    $(J1939Tp_OUTPUT_PATH)/src/J1939Tp_Cfg.c


TRESOS_GEN_FILES  += $(J1939Tp_GEN_FILES)



#################################################################
# REGISTRY
PLUGINS_BASE          += J1939Tp
J1939Tp_DEPENDENT_PLUGINS = base_make tresos
J1939Tp_VERSION           = 1.00.00
J1939Tp_DESCRIPTION       = J1939Tp Basic Software Makefile PlugIn for Autosar


CC_INCLUDE_PATH      += \
    $(J1939Tp_CORE_PATH)/include                          \
    $(J1939Tp_CORE_PATH)/src                              \

                     

ASM_INCLUDE_PATH     +=