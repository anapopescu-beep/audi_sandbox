# \file
#
# \brief AUTOSAR Make
#
# This file contains the implementation of the AUTOSAR
# module Make.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2018 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.
#################################################################
# This makefile exports parameters derived from the
# project configuration into variables for make

# Only include these variables once
ifndef PROJECT_MODULES

# project name in workspace
TRESOS2_PROJECT_NAME := demoBoot_VAG_SigCompCRC_can_asr
TRESOS2_ECU_ID       := demoBoot_VAG_SigCompCRC_can_asr

# target and derivate
TARGET   := CORTEXM
DERIVATE := S32K14X

ifeq ($(ENABLED_PLUGINS),)
# In case enabled modules are NOT specified explicitly
# use all enabled modules (including modules, that are NOT generated)
PROJECT_MODULES := APP Atomics BM Base BlPduR Cal CanIf CanSM CanTp Can ComM Compiler Cpl Cry Csm Det EcuC Flash Make Mcu MemMap PduR Platforms Port ProgVAG Prog Resource SA Uds
else
# otherwise only use generated modules
PROJECT_MODULES := APP Atomics BM Base BlPduR Cal CanIf CanSM CanTp Can ComM Compiler Cpl Cry Csm Det EcuC Flash Make Mcu MemMap PduR Platforms Port ProgVAG Prog Resource SA Uds
endif

# add tresos2 make plugin if not yet contained in SOFTWARE_MODULES
SOFTWARE_MODULES := $(filter-out tresos2,$(SOFTWARE_MODULES))
SOFTWARE_MODULES += tresos2

# There might already modules added to SOFTWARE_MODULES. So add only what's
# not yet contained SOFTWARE_MODULES.
# Duplicated entries are removed by the sort function.
SOFTWARE_MODULES += $(sort $(filter-out $(SOFTWARE_MODULES),$(PROJECT_MODULES)))

# variables defining module versions and locations of the plugins
APP_VARIANT   := TS_TxDxM3I6R0
APP_CORE_PATH := $(TRESOS_BASE)/plugins/APP_TS_TxDxM3I6R0
Atomics_VARIANT   := TS_TxDxM1I0R0
Atomics_CORE_PATH := $(TRESOS_BASE)/plugins/Atomics_TS_TxDxM1I0R0
BM_VARIANT   := TS_TxDxM1I1R0
BM_CORE_PATH := $(TRESOS_BASE)/plugins/BM_TS_TxDxM1I1R0
Base_VARIANT   := TS_TxDxM5I0R0
Base_CORE_PATH := $(TRESOS_BASE)/plugins/Base_TS_TxDxM5I0R0
BlPduR_VARIANT   := TS_TxDxM0I9R0
BlPduR_CORE_PATH := $(TRESOS_BASE)/plugins/BlPduR_TS_TxDxM0I9R0
Cal_VARIANT   := TS_TxDxM1I2R0
Cal_CORE_PATH := $(TRESOS_BASE)/plugins/Cal_TS_TxDxM1I2R0
CanIf_VARIANT   := TS_TxDxM6I9R0
CanIf_CORE_PATH := $(TRESOS_BASE)/plugins/CanIf_TS_TxDxM6I9R0
CanSM_VARIANT   := TS_TxDxM3I6R0
CanSM_CORE_PATH := $(TRESOS_BASE)/plugins/CanSM_TS_TxDxM3I6R0
CanTp_VARIANT   := TS_TxDxM6I8R0
CanTp_CORE_PATH := $(TRESOS_BASE)/plugins/CanTp_TS_TxDxM6I8R0
Can_VARIANT   := TS_T40D2M10I1R0
Can_CORE_PATH := $(TRESOS_BASE)/plugins/Can_TS_T40D2M10I1R0
ComM_VARIANT   := TS_T0D1M4I0R0
ComM_CORE_PATH := $(TRESOS_BASE)/plugins/ComM_TS_T0D1M4I0R0
Compiler_VARIANT   := TS_TxDxM1I0R0
Compiler_CORE_PATH := $(TRESOS_BASE)/plugins/Compiler_TS_TxDxM1I0R0
Cpl_VARIANT   := TS_TxDxM1I3R0
Cpl_CORE_PATH := $(TRESOS_BASE)/plugins/Cpl_TS_TxDxM1I3R0
Cry_VARIANT   := TS_TxDxM2I6R0
Cry_CORE_PATH := $(TRESOS_BASE)/plugins/Cry_TS_TxDxM2I6R0
Csm_VARIANT   := TS_TxDxM2I0R0
Csm_CORE_PATH := $(TRESOS_BASE)/plugins/Csm_TS_TxDxM2I0R0
Det_VARIANT   := TS_TxDxM6I4R0
Det_CORE_PATH := $(TRESOS_BASE)/plugins/Det_TS_TxDxM6I4R0
EcuC_VARIANT   := TS_TxDxM5I0R0
EcuC_CORE_PATH := $(TRESOS_BASE)/plugins/EcuC_TS_TxDxM5I0R0
Flash_VARIANT   := TS_T40D2M7I0R0
Flash_CORE_PATH := $(TRESOS_BASE)/plugins/Flash_TS_T40D2M7I0R0
Make_VARIANT   := TS_TxDxM4I0R0
Make_CORE_PATH := $(TRESOS_BASE)/plugins/Make_TS_TxDxM4I0R0
Mcu_VARIANT   := TS_T40D2M10I1R0
Mcu_CORE_PATH := $(TRESOS_BASE)/plugins/Mcu_TS_T40D2M10I1R0
MemMap_VARIANT   := TS_TxDxM1I3R0
MemMap_CORE_PATH := $(TRESOS_BASE)/plugins/MemMap_TS_TxDxM1I3R0
PduR_VARIANT   := TS_TxDxM5I3R0
PduR_CORE_PATH := $(TRESOS_BASE)/plugins/PduR_TS_TxDxM5I3R0
Platforms_VARIANT   := TS_T40D2M1I0R0
Platforms_CORE_PATH := $(TRESOS_BASE)/plugins/Platforms_TS_T40D2M1I0R0
Port_VARIANT   := TS_T40D2M10I1R0
Port_CORE_PATH := $(TRESOS_BASE)/plugins/Port_TS_T40D2M10I1R0
ProgVAG_VARIANT   := TS_TxDxM0I4R0
ProgVAG_CORE_PATH := $(TRESOS_BASE)/plugins/ProgVAG_TS_TxDxM0I4R0
Prog_VARIANT   := TS_TxDxM2I14R0
Prog_CORE_PATH := $(TRESOS_BASE)/plugins/Prog_TS_TxDxM2I14R0
Resource_VARIANT   := TS_T40D2M10I1R0
Resource_CORE_PATH := $(TRESOS_BASE)/plugins/Resource_TS_T40D2M10I1R0
SA_VARIANT   := TS_TxDxM1I6R0
SA_CORE_PATH := $(TRESOS_BASE)/plugins/SA_TS_TxDxM1I6R0
Uds_VARIANT   := TS_TxDxM3I9R0
Uds_CORE_PATH := $(TRESOS_BASE)/plugins/Uds_TS_TxDxM3I9R0

# variables defining module generation output paths

# default output path for generated files
GEN_OUTPUT_PATH  ?= $(PROJECT_ROOT)/output/generated
# list of all output paths of generated files
GEN_OUTPUT_PATHS ?= \
 $(GEN_OUTPUT_PATH)

# output path for files created by the build environment
PROJECT_OUTPUT_PATH ?= $(realpath $(GEN_OUTPUT_PATH)/..)

# for compatibility reasons we need the AUTOSAR_BASE_OUTPUT_PATH
AUTOSAR_BASE_OUTPUT_PATH ?= $(GEN_OUTPUT_PATH)

endif


# No Os configuration found, declare Os Vendor empty
OS_VENDOR :=
