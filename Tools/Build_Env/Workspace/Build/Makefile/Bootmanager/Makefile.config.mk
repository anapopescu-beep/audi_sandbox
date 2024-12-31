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

LINKER_FILE_STEM := BootManager_Linker

SOURCES_DIR := ../../../../../Components/Bootmanager
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

COMPONENTS_LIST := BSW

BSW_SOURCES_DIR = $(SOURCES_DIR)/Autoliv/$(1)/Implementation/src \
                  $(if $(call containing,$(1),$(strip $(1))),$(SOURCES_DIR)/Autoliv/$(1)/Implementation/cfg,) \

BSW_INCLUDES_DIR = $(SOURCES_DIR)/Autoliv/$(1)/Implementation/inc \
                   $(if $(call containing,$(1),$(strip $(1))),$(SOURCES_DIR)/Autoliv/$(1)/Implementation/cfg,) \

BSW_COMPONENTS_LIST := BmUsr

BSW_IGNORE_SOURCES_LIST += 

FBM_CROP_RANGE := 0x0000 0x1000

$(eval BOOTMANAGER_FILE := $(BASE_RELEASE_DIR)/Bootmanager/fbm.s19)

# filename    : Makefile.config
# description : Makefile contains project specific targets and module(source file) selection
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018-2022, Autoliv Romania
# version     : 2.0.0
# email       : dan.dustinta@autoliv.com
# status      : Released
