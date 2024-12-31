include Makefile.wers.mk
include gmsl

PROJECT_STEM := eCS
PROJECT_NAME := $(PROJECT_STEM)_$(if $(call sne,Application,$(TARGET_KEY)),$(call uc,$(TARGET_KEY)),APPLICATION)

PRINT_WARNINGS := FALSE
PRINT_QAC_WARNINGS := FALSE
PARSE_LINKER_FILE := FALSE
GENERATE_LST_FILES := FALSE

AEC_CALIBRATION_SUPPORT := FALSE
DYNAMIC_E2P_SUPPORT := FALSE
E2P_STUDY_SUPPORT := TRUE
E2P_SYMBOL_SUPPORT := FALSE
FAB_FILE_SUPPORT := FALSE

BOLO_FLASH_VALIDATION := TRUE

BOOTMANAGER_SUPPORT := TRUE
BOOTLOADER_SUPPORT := TRUE
BOOTLOADER_UPDATER_SUPPORT := TRUE

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

LINKER_FILE_STEM := App

SOURCES_DIR := ../../../../../Components/Application
OUTPUT_DIR := ../../Outputs
TOOLS_DIR := ../../../../../Tools
CYCLONE_UNIV_TOOLS_DIR := ../../../../../Tools/Cyclone_Universal
CYCLONE_UNIV_CONFIG_DIR := $(CYCLONE_UNIV_TOOLS_DIR)/Config

CYCLONE_UNIV_NVP_SAP_GENERATION := FALSE 
CYCLONE_UNIV_FLASH_ALGORITHM := $(CYCLONE_INSTALLATION_DIR)/supportFiles_ARM/NXP/S32K1xx/freescale_s32k144f512m150N77P_all.arp
CYCLONE_UNIV_FLASH_ALGORITHM_VARIANT := $(CYCLONE_INSTALLATION_DIR)/supportFiles_ARM/NXP/S32K1xx/freescale_s32k146f1m0m11_pflash_dflash_eeprom.arp

ECLIPSE_WORKSPACE_DIR := ../../../../../Tools/Eclipse/Workspace

COPY_TO_DELIVERIES_DIR := TRUE
ifeq ($(COPY_TO_DELIVERIES_DIR),TRUE)
DELIVERIES_DIR := ../../../../../Deliveries/$(APPL_VERSION_REV2)
endif

BASE_RELEASE_DIR := ../../../../../Release

RELEASE_DIR := $(BASE_RELEASE_DIR)/$(TARGET_KEY)

POST_PROSESSING_DIR = ../../../../../Tools/Build_Env/Workspace/Build

DEP_DIR := $(OUTPUT_DIR)/$(TARGET)/Dep
ERR_DIR := $(OUTPUT_DIR)/$(TARGET)/Err
LST_DIR := $(OUTPUT_DIR)/$(TARGET)/Lst
OBJ_DIR := $(OUTPUT_DIR)/$(TARGET)/Obj
OUT_DIR := $(OUTPUT_DIR)/$(TARGET)/Out

COMPONENTS_LIST := BSW T1 TGEN TGENMCAL EBSW NXPMCAL NXPSCST

BSW_SOURCES_DIR = $(SOURCES_DIR)/Autoliv/$(1)/Implementation/src \
                  $(SOURCES_DIR)/Autoliv/$(1)/Implementation/cfg 

BSW_INCLUDES_DIR = $(SOURCES_DIR)/Autoliv/$(1)/Implementation/inc \
                   $(SOURCES_DIR)/Autoliv/$(1)/Implementation/cfg

BSW_COMPONENTS_LIST := ACC ATM CIL DIA eCS EFX FSM MIC NVP  RCM SAD SBC STM TL_LIB EIM McuIf\
                       AdcIf IoHwAb BswMIf CompilerIf DcmIf DemIf DioIf ECUMIf LPM NmIf NvmIf OsIf PlatformsIf RteIf SpiIf Startup PwmIf 

BSW_IGNORE_SOURCES_LIST += 

# Electrobit Plugins
OS_VERSION := Os_TS_T40D2M6I1R0
DEM_VERSION := Dem_TS_TxDxM6I4R0
DCM_VERSION := Dcm_TS_TxDxM5I0R0
COM_VERSION := Com_TS_TxDxM6I3R0
COMM_VERSION := ComM_TS_TxDxM5I21R0
CRC_VERSION := Crc_TS_TxDxM6I11R0
BASE_VERSION := Base_TS_TxDxM5I2R0
BASE_MCAL_VERSION := Base_TS_T40D2M10I1R0
PDUR_VERSION := PduR_TS_TxDxM5I3R0
ADC_VERSION := Adc_TS_T40D2M10I1R0
CAN_VERSION := Can_TS_T40D2M10I1R0
# CANNM_VERSION := CanNm_TS_TxDxM6I17R0
CANSM_VERSION := CanSM_TS_TxDxM3I7R0
CANIF_VERSION := CanIf_TS_TxDxM6I10R0
CANTP_VERSION := CanTp_TS_TxDxM6I8R0
ATOMICS_VERSION := Atomics_TS_TxDxM1I0R0
MCU_VERSION := Mcu_TS_T40D2M10I1R0
BSWM_VERSION := BswM_TS_TxDxM1I17R0
IPDUM_VERSION := IpduM_TS_TxDxM3I3R0
# NM_VERSION := Nm_TS_TxDxM5I11R0
RTE_VERSION := Rte_TS_TxDxM6I9R0
COMPILER_VERSION := Compiler_TS_TxDxM1I0R0
PLATFORM_VERSION := Platforms_TS_T40DxM4I0R0
MEMIF_VERSION := MemIf_TS_TxDxM5I11R0
ECUM_VERSION := EcuM_TS_TxDxM5I15R0
RESOURCE_VERSION := Resource_TS_T40D2M10I1R0
SPI_VERSION := Spi_TS_T40D2M10I1R0
NVM_VERSION := NvM_TS_TxDxM6I17R0
MCL_VERSION := Mcl_TS_T40D2M10I1R0
PWM_VERSION := Pwm_TS_T40D2M10I1R0
PORT_VERSION := Port_TS_T40D2M10I1R0
DIO_VERSION := Dio_TS_T40D2M10I1R0
FLS_VERSION := Fls_TS_T40D2M10I1R0
FEE_VERSION := Fee_TS_T40D2M10I1R0
GPT_VERSION := Gpt_TS_T40D2M10I1R0
MCALEXT_VERSION := McalExt_TS_T40DxM1I0R0
DET_VERSION := Det_TS_TxDxM6I5R0

EBSW_SOURCES_DIR = $(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/$(1)/lib_src \
                   $(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/$(1)/src

EBSW_INCLUDES_DIR = $(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/$(1)/include \
					$(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/$(1)/include/BaseNXP \
					$(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/$(1)/header \
                    $(if $(call containing,$(strip $(PLATFORM_VERSION)),$(strip $(1))),$(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/$(1)/include/CORTEXM $(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/$(1)/include/CORTEXM/S32K14X,) \
                    $(if $(call containing,$(strip $(COMPILER_VERSION)),$(strip $(1))),$(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/$(1)/include/CORTEXM $(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/$(1)/include/CORTEXM/iar,)

EBSW_COMPONENTS_LIST := $(OS_VERSION) $(DEM_VERSION) $(DCM_VERSION) $(COM_VERSION) $(COMM_VERSION) $(CRC_VERSION) \
                        $(BASE_VERSION) $(PDUR_VERSION) $(CANNM_VERSION) $(CANSM_VERSION) $(CANIF_VERSION) $(CANTP_VERSION) $(ATOMICS_VERSION) \
                        $(BSWM_VERSION) $(IPDUM_VERSION) $(NM_VERSION) $(RTE_VERSION) $(COMPILER_VERSION) $(PLATFORM_VERSION) \
                        $(MEMIF_VERSION) $(ECUM_VERSION) $(NVM_VERSION) $(DET_VERSION)

EBSW_IGNORE_SOURCES_LIST += lib_src/error/kern-erruni                          \
							lib_src/error/kern-errstd                          \
							lib_src/user/lib-getresscheduler.c                 \
							lib_src/kernel/kern-leavekernel.c                  \
							lib_src/kernel/kern-triggerinterrupt.c             \
							lib_src/kernel/kern-enqueuelink.c                  \
							lib_src/CORTEXM/CORTEXM-timer-st-eft.c             \
							lib_src/CORTEXM/CORTEXM-timer-st-mtu.c             \
							lib_src/CORTEXM/CORTEXM-mpu.c                      \
							lib_src/CORTEXM/CORTEXM-timer-arm-dtm.c            \
							lib_src/CORTEXM/CORTEXM-timer-tc.c                 \
							lib_src/CORTEXM/CORTEXM-timer-os.c                 \
							lib_src/CORTEXM/CORTEXM-errstd-ArchTrapHandler.c   \
							lib_src/CORTEXM/CORTEXM-timer-N.c                  \
							lib_src/CORTEXM/CORTEXM-timer-fs-stm.c             \
							lib_src/CORTEXM/CORTEXM-erruni-ArchTrapHandler.c   \
							lib_src/CORTEXM/CORTEXM-timer-rti.c                \
							lib_src/CORTEXM/CORTEXM-timer-tbt.c                \
							lib_src/CORTEXM/CORTEXM-timer-bcm-cct.c            \
							lib_src/ioc/kern-ioccheckmemoryaccess.c            \
							lib_src/CORTEXM/CORTEXM-user-setrelalarm.s         \
							src/Os_configuration_cx.c                          \
							src/Os_configuration_user.c                        \
							src/Os_configuration_microkernel.c                 \
							src/Com_CopyRxData.c                               \
							src/Com_StartOfReception.c                         \
							src/Com_Merged.c                                   \
							src/Com_CopyTxData.c                               \
							src/FlexIO_Common.c                                \
							src/Lptmr_Common.c                                 \
							src/ComStack_Helpers.c                             \
							src/PduR_Merged.c                                  \
							src/CanSM_Merged.c                                 \
							src/CanTp_Merged.c                                 \
							src/IpduM.c                                        \
							src/IpduM_ComCallout.c                             \
							CORTEXM-savefpcontextanddispatch.s                 \
							CORTEXM-fpcontextload.s                            \
							src/vector_iar.s

# MCAL Files
NXPMCAL_SOURCES_DIR = $(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/McalExt_TS_T40DxM1I0R0/MCAL_Delivery/eclipse/plugins/$(1)/lib_src \
                      $(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/McalExt_TS_T40DxM1I0R0/MCAL_Delivery/eclipse/plugins/$(1)/src

NXPMCAL_INCLUDES_DIR = $(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/McalExt_TS_T40DxM1I0R0/MCAL_Delivery/eclipse/plugins/$(1)/include \
					   $(TOOLS_DIR)/EB_BSW_8.8.7/Workspace/plugins/McalExt_TS_T40DxM1I0R0/MCAL_Delivery/eclipse/plugins/$(1)/header

NXPMCAL_COMPONENTS_LIST := $(BASE_MCAL_VERSION) $(ADC_VERSION) $(CAN_VERSION) $(DIO_VERSION) $(FLS_VERSION) $(MCL_VERSION) $(MCU_VERSION) \
                           $(PORT_VERSION) $(RESOURCE_VERSION) $(SPI_VERSION) $(GPT_VERSION) $(FEE_VERSION) $(PWM_VERSION)

NXPMCAL_IGNORE_SOURCES_LIST += src/FlexIO_Common.c                          \
                         src/Lptmr_Common.c                                 \
                         Mcu_RCM_Irq.c                                      \
                         Pwm_FlexIO.c                                       \
                         Spi_FlexIO.c                                       \
                         Spi_FlexIO_Irq.c                                   \
                         src/FlexIO_Common.c                                \
                         src/Lptmr_Common.c                                 


# Tresos Workspace Generated Files
TGEN_SOURCES_DIR = $(SOURCES_DIR)/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/$(1)/src
TGEN_INCLUDES_DIR = $(SOURCES_DIR)/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/$(1)/include \
                    $(SOURCES_DIR)/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/$(1)/epc

TGEN_COMPONENTS_LIST := Tresos_BSW_generated

TGEN_IGNORE_SOURCES_LIST += CanIf_MultiMF.c \
                            EcuC_Cfg.c \
							Ioc_gen.c \
							CanTrcv_1_T03_Lcfg.c \
							Ioc_configuration.c	\
							Adc_ST_4G_PBcfg.c \
							Adc_PBcfg.c \
							Can_PBcfg.c \
							Can_ST_4G_PBcfg.c \
							CanIf_PBCfg.c \
							CanIf_ST_2G_PBcfg.c \
							CanIf_TDK_2G_PBcfg.c \
							CanNm_PBCfg.c \
							CanNm_ST_2G_PBcfg.c \
							CanNm_TDK_2G_PBcfg.c \
							CanTp_GptST_2G_Cbk.c \
							CanTp_GptTDK_2G_Cbk.c \
							CanTp_GptTDK_4G_Cbk.c \
							CanTp_PBCfg.c \
							CanTp_ST_2G_PBcfg.c \
							CanTp_TDK_2G_PBcfg.c \
							CDD_Mcl_PBcfg.c \
							CDD_Mcl_ST_4G_PBcfg \
							ComM_PBCfg.c \
							ComM_ST_2G_PBcfg.c \
							ComM_TDK_2G_PBcfg.c \
							Fls_PBcfg.c \
							Fls_ST_4G_PBcfg.c \
							Gpt_PBcfg.c \
							Gpt_ST_4G_PBcfg.c \
							Gpt_Cfg.c \
							Port_ST_4G_PBcfg.c \
							Port_PBcfg.c \
							Pwm_ST_4G_PBcfg.c \
							Mcu_PBcfg.c \
							Mcu_ST_4G_PBcfg \
							Adc_ST_4G_PBcfg.c \
							Spi_TDK_2G_PBcfg.c \
							Spi_ST_2G_PBcfg.c \
							Spi_ST_4G_PBcfg.c \
							CanIf_TDK_4G_PBcfg.c \
							CanSM_TDK_4G_PBcfg.c \
							CanTp_TDK_4G_PBcfg.c \
							Com_TDK_4G_PBcfg.c \
							ComM_TDK_4G_PBcfg.c \
							EcuM_TDK_4G_PBcfg.c \
							PduR_TDK_4G_PBcfg.c \
							CanNm_TDK_4G_PBcfg.c
							
							
TGENMCAL_SOURCES_DIR = $(SOURCES_DIR)/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/$(1)/src
TGENMCAL_INCLUDES_DIR = $(SOURCES_DIR)/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/$(1)/include \
                    $(SOURCES_DIR)/Supplier/Tresos_Configuration_8.8.7/Workspace/Application/$(1)/epc

TGENMCAL_COMPONENTS_LIST := Tresos_BSW_generated_mcal

TGENMCAL_IGNORE_SOURCES_LIST += CanIf_MultiMF.c \
                            EcuC_Cfg.c \
							Ioc_gen.c \
							CanTrcv_1_T03_Lcfg.c \
							Ioc_configuration.c	\
							Adc_ST_4G_PBcfg.c \
							Adc_PBcfg.c \
							Can_PBcfg.c \
							Can_ST_4G_PBcfg.c \
							CanIf_PBCfg.c \
							CanIf_ST_2G_PBcfg.c \
							CanIf_TDK_2G_PBcfg.c \
							CanNm_PBCfg.c \
							CanNm_ST_2G_PBcfg.c \
							CanNm_TDK_2G_PBcfg.c \
							CanTp_GptST_2G_Cbk.c \
							CanTp_GptTDK_2G_Cbk.c \
							CanTp_GptTDK_4G_Cbk.c \
							CanTp_PBCfg.c \
							CanTp_ST_2G_PBcfg.c \
							CanTp_TDK_2G_PBcfg.c \
							CDD_Mcl_PBcfg.c \
							CDD_Mcl_ST_4G_PBcfg \
							ComM_PBCfg.c \
							ComM_ST_2G_PBcfg.c \
							ComM_TDK_2G_PBcfg.c \
							Fls_PBcfg.c \
							Fls_ST_4G_PBcfg.c \
							Gpt_PBcfg.c \
							Gpt_ST_4G_PBcfg.c \
							Gpt_Cfg.c \
							Port_ST_4G_PBcfg.c \
							Port_PBcfg.c \
							Pwm_ST_4G_PBcfg.c \
							Mcu_PBcfg.c \
							Mcu_ST_4G_PBcfg \
							Adc_ST_4G_PBcfg.c \
							Spi_TDK_2G_PBcfg.c \
							Spi_ST_2G_PBcfg.c \
							Spi_ST_4G_PBcfg.c \
							CanNm_TDK_4G_PBcfg.c

#Gliwa Files
T1_SOURCES_DIR = $(SOURCES_DIR)/Supplier/$(1)/src

T1_INCLUDES_DIR = $(SOURCES_DIR)/Supplier/$(1)/interface \
                   $(SOURCES_DIR)/Supplier/$(1)/src

T1_COMPONENTS_LIST := T1

T1_IGNORE_SOURCES_LIST += 

#NXP Structural Core Self-Test Library
NXPSCST_SOURCES_DIR = $(SOURCES_DIR)/Supplier/$(1)/src

NXPSCST_INCLUDES_DIR = $(SOURCES_DIR)/Supplier/$(1)/src/h

NXPSCST_COMPONENTS_LIST := SCST

NXPSCST_IGNORE_SOURCES_LIST += 

S19_CRC_CALCULATION := FALSE
ALV_CRC_SUPPORTED := FALSE
HEXVIEW_CRC_SUPPORTED := FALSE

APPL_CRC_ADDR :=
APPL_CRC_RANGES :=
APPL_EXCLUSION_RANGE := 0x1FFF6000-0x20009000

APPL_CROP_RANGE := 0x20000 0xFCFF0
APPL_FILL_RANGE_INTV := 0x20000-0x20FFF
APPL_FILL_RANGE_BSW := 0x21000-0xFCFF0
CALIBRATION_RANGE := 0xFE000 0xFEFF0
DEFAULT_NVP_RANGE := 0xFF000 0xFFFF0

FULL_FLASH_FILL_RANGE := 0x00 0xFFFFF

ifeq ($(BOLO_FLASH_VALIDATION),TRUE)
	FLASH_VALIDATION_START_ADDR_APPL := 0xFCFF0
	FLASH_VALIDATION_END_ADDR_APPL := 0xFD000
# The validation flag pattern is specific to AUDI_TR6
	FLASH_VALIDATION_FLAG_APPL := 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0x50 0x52 0x4F 0x47 0x52 0x41 0x4d 0x4d

	FLASH_VALIDATION_START_ADDR_DEFAULT := 0xFFFF0 
	FLASH_VALIDATION_END_ADDR_DEFAULT := 0x100000
# The validation flag pattern is specific to AUDI_TR6
	FLASH_VALIDATION_FLAG_DEFAULT := 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0x50 0x52 0x4F 0x47 0x52 0x41 0x4d 0x4d

	FLASH_VALIDATION_START_ADDR_FBL := 0x1FFF0
	FLASH_VALIDATION_END_ADDR_FBL := 0x20000
# The validation flag pattern is specific to PP4G
	FLASH_VALIDATION_FLAG_FBL := 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0x50 0x52 0x4F 0x47 0x52 0x41 0x4d 0x4d
endif

ifneq (,$(findstring Application,$(TARGET_KEY)))
ifeq ($(AEC_CALIBRATION_SUPPORT),TRUE)
$(eval AEC_CALIBRATION_FILE :=)
endif
$(eval CALIBRATION_FLASH_FILE := $(OUTPUT_DIR)/nvp/CalibrationFlash.S00)
$(eval DEFAULT_FILE := $(OUTPUT_DIR)/nvp/NvmDefaultValue.S00)
ifeq ($(DYNAMIC_E2P_SUPPORT),TRUE)
$(eval DYNAMIC_E2P_FILE :=)
endif
ifeq ($(E2P_SYMBOL_SUPPORT),TRUE)
$(eval E2P_SYMBOL_FILE :=)
endif
ifeq ($(E2P_STUDY_SUPPORT),TRUE)
$(eval E2P_STUDY_FILE := $(OUTPUT_DIR)/nvp/Fee_D_Flash.srec)
endif
ifeq ($(FAB_FILE_SUPPORT),TRUE)
$(eval FAB_FILE :=)
endif
$(eval FULL_MEMORY_FILE := $(OUT_DIR)/FullFlash.$(SREC_SUFFIX))
$(eval FULL_MEMORY_FILE_NO_EEP  := $(OUT_DIR)/FullFlash_NoEEP.$(SREC_SUFFIX))
$(eval UNIFIED_CALIBRATION_FILE := $(OUT_DIR)/Unified_Calibration.$(SREC_SUFFIX))

ifeq ($(BOOTLOADER_SUPPORT),TRUE)
$(eval BOOTLOADER_FILE := $(BASE_RELEASE_DIR)/Bootloader/fbl.s19)
endif

ifeq ($(BOOTMANAGER_SUPPORT),TRUE)
$(eval BOOTMANAGER_FILE := $(BASE_RELEASE_DIR)/Bootmanager/fbm.s19)
endif

ifeq ($(BOOTLOADER_UPDATER_SUPPORT),TRUE)
$(eval BOOTLOADER_UPDATER_FILE := $(BASE_RELEASE_DIR)/Bootloader_updater/fbl_upd.s19)
endif

endif

# filename    : Makefile.config
# description : Makefile contains project specific targets and module(source file) selection
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018-2022, Autoliv Romania
# version     : 2.0.0
# email       : dan.dustinta@autoliv.com
# status      : Released
