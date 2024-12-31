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
TRESOS2_PROJECT_NAME := Application
TRESOS2_ECU_ID       := ECU_Application

# target and derivate
TARGET   := CORTEXM
DERIVATE := S32K14X

ifeq ($(ENABLED_PLUGINS),)
# In case enabled modules are NOT specified explicitly
# use all enabled modules (including modules, that are NOT generated)
PROJECT_MODULES := Adc Atomics Base BswM CanIf CanSM CanTp Can ComM Com Compiler Crc Dcm Dem Dio EcuC EcuM Fee Fls Gpt Make Mcl Mcu MemIf MemMap NvM Os PduR Platforms Port Pwm Resource Rte Spi
else
# otherwise only use generated modules
PROJECT_MODULES := Adc Atomics Base BswM CanIf CanSM CanTp Can ComM Com Compiler Crc Dcm Dem Dio EcuC EcuM Fee Fls Gpt Make Mcl Mcu MemIf MemMap NvM Os PduR Platforms Port Pwm Resource Rte Spi
endif

# add tresos2 make plugin if not yet contained in SOFTWARE_MODULES
SOFTWARE_MODULES := $(filter-out tresos2,$(SOFTWARE_MODULES))
SOFTWARE_MODULES += tresos2

# There might already modules added to SOFTWARE_MODULES. So add only what's
# not yet contained SOFTWARE_MODULES.
# Duplicated entries are removed by the sort function.
SOFTWARE_MODULES += $(sort $(filter-out $(SOFTWARE_MODULES),$(PROJECT_MODULES)))

# variables defining module versions and locations of the plugins
Adc_VARIANT   := TS_T40D2M10I2R0
Adc_CORE_PATH := $(TRESOS_BASE)/plugins/Adc_TS_T40D2M10I2R0
Atomics_VARIANT   := TS_TxDxM1I0R0
Atomics_CORE_PATH := $(TRESOS_BASE)/plugins/Atomics_TS_TxDxM1I0R0
Base_VARIANT   := TS_TxDxM5I0R0
Base_CORE_PATH := $(TRESOS_BASE)/plugins/Base_TS_TxDxM5I0R0
BswM_VARIANT   := TS_TxDxM1I14R0
BswM_CORE_PATH := $(TRESOS_BASE)/plugins/BswM_TS_TxDxM1I14R0
CanIf_VARIANT   := TS_TxDxM6I9R0
CanIf_CORE_PATH := $(TRESOS_BASE)/plugins/CanIf_TS_TxDxM6I9R0
CanSM_VARIANT   := TS_TxDxM3I6R0
CanSM_CORE_PATH := $(TRESOS_BASE)/plugins/CanSM_TS_TxDxM3I6R0
CanTp_VARIANT   := TS_TxDxM6I8R0
CanTp_CORE_PATH := $(TRESOS_BASE)/plugins/CanTp_TS_TxDxM6I8R0
Can_VARIANT   := TS_T40D2M10I2R0
Can_CORE_PATH := $(TRESOS_BASE)/plugins/Can_TS_T40D2M10I2R0
ComM_VARIANT   := TS_TxDxM5I17R0
ComM_CORE_PATH := $(TRESOS_BASE)/plugins/ComM_TS_TxDxM5I17R0
Com_VARIANT   := TS_TxDxM6I3R0
Com_CORE_PATH := $(TRESOS_BASE)/plugins/Com_TS_TxDxM6I3R0
Compiler_VARIANT   := TS_TxDxM1I0R0
Compiler_CORE_PATH := $(TRESOS_BASE)/plugins/Compiler_TS_TxDxM1I0R0
Crc_VARIANT   := TS_TxDxM6I11R0
Crc_CORE_PATH := $(TRESOS_BASE)/plugins/Crc_TS_TxDxM6I11R0
Dcm_VARIANT   := TS_TxDxM4I14R0
Dcm_CORE_PATH := $(TRESOS_BASE)/plugins/Dcm_TS_TxDxM4I14R0
Dem_VARIANT   := TS_TxDxM5I18R0
Dem_CORE_PATH := $(TRESOS_BASE)/plugins/Dem_TS_TxDxM5I18R0
Dio_VARIANT   := TS_T40D2M10I2R0
Dio_CORE_PATH := $(TRESOS_BASE)/plugins/Dio_TS_T40D2M10I2R0
EcuC_VARIANT   := TS_TxDxM5I0R0
EcuC_CORE_PATH := $(TRESOS_BASE)/plugins/EcuC_TS_TxDxM5I0R0
EcuM_VARIANT   := TS_TxDxM5I14R0
EcuM_CORE_PATH := $(TRESOS_BASE)/plugins/EcuM_TS_TxDxM5I14R0
Fee_VARIANT   := TS_T40D2M10I2R0
Fee_CORE_PATH := $(TRESOS_BASE)/plugins/Fee_TS_T40D2M10I2R0
Fls_VARIANT   := TS_T40D2M10I2R0
Fls_CORE_PATH := $(TRESOS_BASE)/plugins/Fls_TS_T40D2M10I2R0
Gpt_VARIANT   := TS_T40D2M10I2R0
Gpt_CORE_PATH := $(TRESOS_BASE)/plugins/Gpt_TS_T40D2M10I2R0
Make_VARIANT   := TS_TxDxM4I0R0
Make_CORE_PATH := $(TRESOS_BASE)/plugins/Make_TS_TxDxM4I0R0
Mcl_VARIANT   := TS_T40D2M10I2R0
Mcl_CORE_PATH := $(TRESOS_BASE)/plugins/Mcl_TS_T40D2M10I2R0
Mcu_VARIANT   := TS_T40D2M10I2R0
Mcu_CORE_PATH := $(TRESOS_BASE)/plugins/Mcu_TS_T40D2M10I2R0
MemIf_VARIANT   := TS_TxDxM5I11R0
MemIf_CORE_PATH := $(TRESOS_BASE)/plugins/MemIf_TS_TxDxM5I11R0
MemMap_VARIANT   := TS_TxDxM1I3R0
MemMap_CORE_PATH := $(TRESOS_BASE)/plugins/MemMap_TS_TxDxM1I3R0
NvM_VARIANT   := TS_TxDxM6I17R0
NvM_CORE_PATH := $(TRESOS_BASE)/plugins/NvM_TS_TxDxM6I17R0
Os_VARIANT   := TS_T40D2M6I0R0_AS403
Os_CORE_PATH := $(TRESOS_BASE)/plugins/Os_TS_T40D2M6I0R0_AS403
PduR_VARIANT   := TS_TxDxM5I3R0
PduR_CORE_PATH := $(TRESOS_BASE)/plugins/PduR_TS_TxDxM5I3R0
Platforms_VARIANT   := TS_T40D2M1I0R0
Platforms_CORE_PATH := $(TRESOS_BASE)/plugins/Platforms_TS_T40D2M1I0R0
Port_VARIANT   := TS_T40D2M10I2R0
Port_CORE_PATH := $(TRESOS_BASE)/plugins/Port_TS_T40D2M10I2R0
Pwm_VARIANT   := TS_T40D2M10I2R0
Pwm_CORE_PATH := $(TRESOS_BASE)/plugins/Pwm_TS_T40D2M10I2R0
Resource_VARIANT   := TS_T40D2M10I2R0
Resource_CORE_PATH := $(TRESOS_BASE)/plugins/Resource_TS_T40D2M10I2R0
Rte_VARIANT   := TS_TxDxM6I2R0
Rte_CORE_PATH := $(TRESOS_BASE)/plugins/Rte_TS_TxDxM6I2R0
Spi_VARIANT   := TS_T40D2M10I2R0
Spi_CORE_PATH := $(TRESOS_BASE)/plugins/Spi_TS_T40D2M10I2R0

# variables defining module generation output paths

# default output path for generated files
GEN_OUTPUT_PATH  ?= S:/Components/Application/Supplier/Tresos_Configuration_8.5.1/Workspace/Application/Tresos_BSW_generated
# list of all output paths of generated files
GEN_OUTPUT_PATHS ?= \
 $(GEN_OUTPUT_PATH)

# output path for files created by the build environment
PROJECT_OUTPUT_PATH ?= $(realpath $(GEN_OUTPUT_PATH)/..)

# for compatibility reasons we need the AUTOSAR_BASE_OUTPUT_PATH
AUTOSAR_BASE_OUTPUT_PATH ?= $(GEN_OUTPUT_PATH)

endif

# Set Os Vendor to EB
OS_VENDOR := EB
