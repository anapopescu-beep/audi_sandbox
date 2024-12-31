include Makefile.wers.mk
include gmsl

PROJECT_STEM := eCS
PROJECT_NAME := $(PROJECT_STEM)_$(if $(call sne,Application,$(TARGET_KEY)),$(call uc,$(TARGET_KEY)),APPLICATION)

PRINT_WARNINGS := FALSE
GENERATE_LST_FILES := FALSE

ifeq ($(BUILD_MODE),RELEASE)
REPORT_GENERATION ?= TRUE
else
REPORT_GENERATION ?= FALSE
endif

ifeq ($(MAKECMDGOALS),$(TARGET)-eclipse)
PARSE_HEADER_FILES := TRUE
endif
ifeq ($(REPORT_GENERATION),TRUE)
PARSE_HEADER_FILES := TRUE
endif

LINKER_FILE_STEM := Bootloader_updater

SOURCES_DIR := ../../../../../Components/Bootloader_updater
OUTPUT_DIR := ../../Outputs
TOOLS_DIR := ../../../../../Tools

ECLIPSE_WORKSPACE_DIR := ../../../../../Tools/Eclipse/Workspace

COPY_TO_DELIVERIES_DIR := TRUE
ifeq ($(COPY_TO_DELIVERIES_DIR),TRUE)
DELIVERIES_DIR := ../../../../../Deliveries/$(APPL_VERSION_REV2)
endif

BASE_RELEASE_DIR := ../../../../../Release

RELEASE_DIR := $(BASE_RELEASE_DIR)/$(TARGET_KEY)

DEP_DIR := $(OUTPUT_DIR)/$(TARGET)/Dep
ERR_DIR := $(OUTPUT_DIR)/$(TARGET)/Err
LST_DIR := $(OUTPUT_DIR)/$(TARGET)/Lst
OBJ_DIR := $(OUTPUT_DIR)/$(TARGET)/Obj
OUT_DIR := $(OUTPUT_DIR)/$(TARGET)/Out

COMPONENTS_LIST := BSW TGEN EBSW NXPMCAL 

BSW_SOURCES_DIR = $(SOURCES_DIR)/Autoliv/$(1)/Implementation/src \
                  $(SOURCES_DIR)/Autoliv/$(1)/Implementation/cfg \

BSW_INCLUDES_DIR = $(if $(call containing,Stubs,$(1)),,$(SOURCES_DIR)/Autoliv/$(1)/Implementation/inc) \
                   $(if $(call containing,Stubs,$(1)),,$(SOURCES_DIR)/Autoliv/$(1)/Implementation/cfg) \
                   $(if $(call containing,Stubs,$(1)),$(SOURCES_DIR)/Autoliv/AsrStubs/Implementation/inc/$(1),)
  
BSW_COMPONENTS_LIST := FblUpdUsr SchM SpiIf SBC AsrStubs Atomics_TS_TxDxM1I0R0_Stubs Base_TS_TxDxM5I1R0_Stubs Compiler_TS_TxDxM1I0R0_Stubs Platforms_TS_T40D2M1I0R0_Stubs Dem_TS_TxDxM5I18R0_Stubs

BSW_IGNORE_SOURCES_LIST += 

# Electrobit Plugins
#ATOMICS_VERSION := Atomics_TS_TxDxM1I0R0
# BM_VERSION := BM_TS_TxDxM1I13R0
# BASE_VERSION := Base_TS_TxDxM5I1R0 
# BLPDUR_VERSION := BlPduR_TS_TxDxM0I23R0
# CAL_VERSION := Cal_TS_TxDxM1I2R0
# CANIF_VERSION := CanIf_TS_TxDxM6I9R0
# CANSM_VERSION := CanSM_TS_TxDxM3I6R0
# CANTP_VERSION := CanTp_TS_TxDxM6I8R0
# CAN_VERSION := Can_TS_T40D2M10I2R0
# COMPILER_VERSION := Compiler_TS_TxDxM1I0R0
# CPL_VERSION := Cpl_TS_TxDxM1I3R0
# CRC_VERSION := Crc_TS_TxDxM6I11R0
# CRY_VERSION := Cry_TS_TxDxM2I6R0
# CSM_VERSION := Csm_TS_TxDxM2I0R0
# DET_VERSION := Det_TS_TxDxM6I5R0
# ECUC_VERSION := EcuC_TS_TxDxM5I0R0
FEE_VERSION := Fee_TS_T40D2M10I2R0
# FLASH_VERSION := Flash_TS_T40D2M7I0R0
FLS_VERSION := Fls_TS_T40D2M10I2R0
MCU_VERSION := Mcu_TS_T40D2M10I2R0
MEMIF_VERSION := MemIf_TS_TxDxM5I11R0
# NVM_VERSION := NvM_TS_TxDxM6I17R0
# PDUR_VERSION := PduR_TS_TxDxM5I3R0
PLATFORM_VERSION := Platforms_TS_T40D2M1I0R0
PORT_VERSION := Port_TS_T40D2M10I2R0
# PROGVAG_VERSION := ProgVAG_TS_TxDxM0I13R0
# PROG_VERSION := Prog_TS_TxDxM2I48R0
RESOURCE_VERSION := Resource_TS_T40D2M10I2R0
# SA_VERSION := SA_TS_TxDxM1I17R0
SPI_VERSION := Spi_TS_T40D2M10I2R0
# UDS_VERSION := Uds_TS_TxDxM3I17R0
EBSW_SOURCES_DIR = $(TOOLS_DIR)/EB_Bootloader/Workspace/plugins/$(1)/lib_src \
                   $(TOOLS_DIR)/EB_Bootloader/Workspace/plugins/$(1)/src
EBSW_INCLUDES_DIR = $(TOOLS_DIR)/EB_Bootloader/Workspace/plugins/$(1)/include \
                    $(if $(call containing,$(strip $(PLATFORM_VERSION)),$(strip $(1))),$(TOOLS_DIR)/EB_Bootloader/Workspace/plugins/$(1)/include/CORTEXM $(TOOLS_DIR)/EB_Bootloader/Workspace/plugins/$(1)/include/CORTEXM/S32K14X,) \
                  #  $(if $(call containing,$(strip $(COMPILER_VERSION)),$(strip $(1))),$(TOOLS_DIR)/EB_Bootloader/Workspace/plugins/$(1)/include/CORTEXM $(TOOLS_DIR)/EB_Bootloader/Workspace/plugins/$(1)/include/CORTEXM/iar,)


EBSW_COMPONENTS_LIST :=  $(PLATFORM_VERSION) $(MEMIF_VERSION) $(FEE_VERSION)
EBSW_IGNORE_SOURCES_LIST += src/CanSM_Merged.c                                 \
							src/CanTp_Merged.c                                 \
							src/PduR_Merged.c                                  \
# MCAL Files
NXPMCAL_SOURCES_DIR = $(TOOLS_DIR)/EB_Bootloader/Workspace/plugins/$(1)/lib_src \
                      $(TOOLS_DIR)/EB_Bootloader/Workspace/plugins/$(1)/src
NXPMCAL_INCLUDES_DIR = $(TOOLS_DIR)/EB_Bootloader/Workspace/plugins/$(1)/include 
NXPMCAL_COMPONENTS_LIST := $(MCU_VERSION) $(PORT_VERSION) $(RESOURCE_VERSION) $(SPI_VERSION)  $(FLS_VERSION)
NXPMCAL_IGNORE_SOURCES_LIST += 
# Tresos Workspace Generated Files
TGEN_SOURCES_DIR = $(SOURCES_DIR)/Supplier/Tresos_Configuration_Bootloader_Updater/Workspace/demoBoot_VAG_SigCompCRC_can_asr/$(1)/src
TGEN_INCLUDES_DIR = $(SOURCES_DIR)/Supplier/Tresos_Configuration_Bootloader_Updater/Workspace/demoBoot_VAG_SigCompCRC_can_asr/$(1)/include \
                    $(SOURCES_DIR)/Supplier/Tresos_Configuration_Bootloader_Updater/Workspace/demoBoot_VAG_SigCompCRC_can_asr/$(1)/output
TGEN_COMPONENTS_LIST := Tresos_BSW_generated
TGEN_IGNORE_SOURCES_LIST += 
FBL_UPD_CROP_RANGE := 0x20000 0x7CFF0

$(eval BOOTMANAGER_FILE := $(BASE_RELEASE_DIR)/Bootmanager/fbm.s19)
$(eval BOOTLOADER_FILE := $(BASE_RELEASE_DIR)/Bootloader/fbl.s19)
# filename    : Makefile.config
# description : Makefile contains project specific targets and module(source file) selection
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018-2022, Autoliv Romania
# version     : 2.0.0
# email       : dan.dustinta@autoliv.com
# status      : Released
