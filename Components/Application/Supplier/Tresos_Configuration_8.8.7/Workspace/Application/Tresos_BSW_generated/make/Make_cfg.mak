#
# \file
#
# \brief AUTOSAR Make
#
# This file contains the implementation of the AUTOSAR
# module Make.
#
# \version 4.0.30
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2022 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# This makefile exports parameters derived from the
# project configuration into variables for make

# Only include these variables once
ifndef TRESOS2_ECU_ID

# project name in workspace
TRESOS2_PROJECT_NAME := eCS_Application
TRESOS2_ECU_ID       := ECU_Application

# target and derivate
TARGET   := CORTEXM
DERIVATE := S32K14X

ifeq (,$(ENABLED_PLUGINS))
# In case enabled modules are NOT specified explicitly
# use all enabled modules (including modules, that are NOT generated)
PROJECT_MODULES := Adc Atomics BaseNXP Base BswM CanIf CanSM CanTp Can ComM Com Compiler Crc Dcm Dem Det Dio EcuC EcuM Fee Fls Gpt Make McalExt Mcl Mcu MemIf MemMap NvM Os PduR Platforms Port Pwm Resource Rte Spi
else
# otherwise only use generated modules
PROJECT_MODULES := Adc Atomics BaseNXP Base BswM CanIf CanSM CanTp Can ComM Com Compiler Crc Dcm Dem Det Dio EcuC EcuM Fee Fls Gpt Make McalExt Mcl Mcu MemIf MemMap NvM Os PduR Platforms Port Pwm Resource Rte Spi
endif

# add tresos2 make plugin if not yet contained in SOFTWARE_MODULES
SOFTWARE_MODULES := $(strip $(filter-out tresos2,$(SOFTWARE_MODULES)) tresos2)

# There might already modules added to SOFTWARE_MODULES. So add only what's
# not yet contained SOFTWARE_MODULES.
# Duplicated entries are removed by the sort function.
SOFTWARE_MODULES += $(sort $(filter-out $(SOFTWARE_MODULES),$(PROJECT_MODULES)))

# variables defining module versions and locations of the plugins
Adc_VARIANT   := TS_T40D2M10I1R0
Atomics_VARIANT   := TS_TxDxM1I0R0
Atomics_CORE_PATH := $(TRESOS_BASE)/plugins/Atomics_TS_TxDxM1I0R0
BaseNXP_VARIANT   := TS_T40D2M10I1R0
Base_VARIANT   := TS_TxDxM5I2R0
Base_CORE_PATH := $(TRESOS_BASE)/plugins/Base_TS_TxDxM5I2R0
BswM_VARIANT   := TS_TxDxM1I17R0
BswM_CORE_PATH := $(TRESOS_BASE)/plugins/BswM_TS_TxDxM1I17R0
CanIf_VARIANT   := TS_TxDxM6I10R0
CanIf_CORE_PATH := $(TRESOS_BASE)/plugins/CanIf_TS_TxDxM6I10R0
CanSM_VARIANT   := TS_TxDxM3I7R0
CanSM_CORE_PATH := $(TRESOS_BASE)/plugins/CanSM_TS_TxDxM3I7R0
CanTp_VARIANT   := TS_TxDxM6I8R0
CanTp_CORE_PATH := $(TRESOS_BASE)/plugins/CanTp_TS_TxDxM6I8R0
Can_VARIANT   := TS_T40D2M10I1R0
ComM_VARIANT   := TS_TxDxM5I21R0
ComM_CORE_PATH := $(TRESOS_BASE)/plugins/ComM_TS_TxDxM5I21R0
Com_VARIANT   := TS_TxDxM6I3R0
Com_CORE_PATH := $(TRESOS_BASE)/plugins/Com_TS_TxDxM6I3R0
Compiler_VARIANT   := TS_TxDxM1I0R0
Compiler_CORE_PATH := $(TRESOS_BASE)/plugins/Compiler_TS_TxDxM1I0R0
Crc_VARIANT   := TS_TxDxM6I11R0
Crc_CORE_PATH := $(TRESOS_BASE)/plugins/Crc_TS_TxDxM6I11R0
Dcm_VARIANT   := TS_TxDxM5I0R0
Dcm_CORE_PATH := $(TRESOS_BASE)/plugins/Dcm_TS_TxDxM5I0R0
Dem_VARIANT   := TS_TxDxM6I4R0
Dem_CORE_PATH := $(TRESOS_BASE)/plugins/Dem_TS_TxDxM6I4R0
Det_VARIANT   := TS_TxDxM6I5R0
Det_CORE_PATH := $(TRESOS_BASE)/plugins/Det_TS_TxDxM6I5R0
Dio_VARIANT   := TS_T40D2M10I1R0
EcuC_VARIANT   := TS_TxDxM5I0R0
EcuC_CORE_PATH := $(TRESOS_BASE)/plugins/EcuC_TS_TxDxM5I0R0
EcuM_VARIANT   := TS_TxDxM5I15R0
EcuM_CORE_PATH := $(TRESOS_BASE)/plugins/EcuM_TS_TxDxM5I15R0
Fee_VARIANT   := TS_T40D2M10I1R0
Fls_VARIANT   := TS_T40D2M10I1R0
Gpt_VARIANT   := TS_T40D2M10I1R0
Make_VARIANT   := TS_TxDxM4I0R0
Make_CORE_PATH := $(TRESOS_BASE)/plugins/Make_TS_TxDxM4I0R0
McalExt_VARIANT   := TS_T40DxM1I0R0
McalExt_CORE_PATH := $(TRESOS_BASE)/plugins/McalExt_TS_T40DxM1I0R0
Mcl_VARIANT   := TS_T40D2M10I1R0
Mcu_VARIANT   := TS_T40D2M10I1R0
MemIf_VARIANT   := TS_TxDxM5I11R0
MemIf_CORE_PATH := $(TRESOS_BASE)/plugins/MemIf_TS_TxDxM5I11R0
MemMap_VARIANT   := TS_TxDxM1I3R0
MemMap_CORE_PATH := $(TRESOS_BASE)/plugins/MemMap_TS_TxDxM1I3R0
NvM_VARIANT   := TS_TxDxM6I17R0
NvM_CORE_PATH := $(TRESOS_BASE)/plugins/NvM_TS_TxDxM6I17R0
Os_VARIANT   := TS_T40D2M6I1R0_AS45
Os_CORE_PATH := $(TRESOS_BASE)/plugins/Os_TS_T40D2M6I1R0_AS45
PduR_VARIANT   := TS_TxDxM5I3R0
PduR_CORE_PATH := $(TRESOS_BASE)/plugins/PduR_TS_TxDxM5I3R0
Platforms_VARIANT   := TS_T40DxM4I0R0
Platforms_CORE_PATH := $(TRESOS_BASE)/plugins/Platforms_TS_T40DxM4I0R0
Port_VARIANT   := TS_T40D2M10I1R0
Pwm_VARIANT   := TS_T40D2M10I1R0
Resource_VARIANT   := TS_T40D2M10I1R0
Resource_CORE_PATH := $(TRESOS_BASE)/plugins/Resource_TS_T40D2M10I1R0
Rte_VARIANT   := TS_TxDxM6I9R0
Rte_CORE_PATH := $(TRESOS_BASE)/plugins/Rte_TS_TxDxM6I9R0
Spi_VARIANT   := TS_T40D2M10I1R0

# variables defining module generation output paths
Adc_OUTPUT_PATH := S:/Components/Application/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/Tresos_BSW_generated_mcal
Dio_OUTPUT_PATH := S:/Components/Application/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/Tresos_BSW_generated_mcal
Gpt_OUTPUT_PATH := S:/Components/Application/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/Tresos_BSW_generated_mcal
Mcu_OUTPUT_PATH := S:/Components/Application/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/Tresos_BSW_generated_mcal
Port_OUTPUT_PATH := S:/Components/Application/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/Tresos_BSW_generated_mcal
Pwm_OUTPUT_PATH := S:/Components/Application/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/Tresos_BSW_generated_mcal
Spi_OUTPUT_PATH := S:/Components/Application/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/Tresos_BSW_generated_mcal
# default output path for generated files
override GEN_OUTPUT_PATH  := $(subst \,/,S:/Components/Application/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/Tresos_BSW_generated)
# list of all output paths of generated files
override GEN_OUTPUT_PATHS := $(subst \,/,\
 $(GEN_OUTPUT_PATH) \
 $(Adc_OUTPUT_PATH) \
 $(Dio_OUTPUT_PATH) \
 $(Gpt_OUTPUT_PATH) \
 $(Mcu_OUTPUT_PATH) \
 $(Port_OUTPUT_PATH) \
 $(Pwm_OUTPUT_PATH) \
 $(Spi_OUTPUT_PATH)\
)

# output path for files created by the build environment
PROJECT_OUTPUT_PATH ?= $(abspath $(GEN_OUTPUT_PATH)/..)

# for compatibility reasons we need the AUTOSAR_BASE_OUTPUT_PATH
AUTOSAR_BASE_OUTPUT_PATH ?= $(GEN_OUTPUT_PATH)
override AUTOSAR_BASE_OUTPUT_PATH := $(subst \,/,$(AUTOSAR_BASE_OUTPUT_PATH))

endif
# Set Os Vendor to EB
OS_VENDOR := EB
