#HELPER: ## app : builds the Application software 
#HELPER: ## app-clean : cleans the Application software 
#HELPER: ## fbm : builds the Bootmanager software
#HELPER: ## fbm-clean : cleans the Bootmanager software
VALID_TARGETS := fbm fbl fbl_upd app
TARGET_KEYWORD_app := Application
#^ target keyword specifies the name of the folder in which the config Makefiles for this software component are located
TARGET_KEYWORD_fbm := Bootmanager
 #^ target keyword specifies the name of the folder in which the config Makefiles for this software component are located
TARGET_KEYWORD_fbl := Bootloader
 #^ target keyword specifies the name of the folder in which the config Makefiles for this software component are located
 TARGET_KEYWORD_fbl_upd := Bootloader_updater
 #^ target keyword specifies the name of the folder in which the config Makefiles for this software component are located
TARGET_TYPE_app := ALV_BUILD
#^ target type option signals that Application software will be compiled using this build environment	
TARGET_TYPE_fbm := ALV_BUILD
#^ target type option signals that binaries will be copied to Release folder
TARGET_TYPE_fbl := ALV_BUILD
#^ target type option signals that binaries will be copied to Release folder
TARGET_TYPE_fbl_upd := ALV_BUILD
#^ target type option signals that binaries will be copied to Release folder

#^ example for Application Variant Build
# VALID_TARGETS := app1 app2 app3 #^ add different suffix for each Application variant
# TARGET_KEYWORD_app1 := Application1
# TARGET_KEYWORD_app2 := Application2
# TARGET_KEYWORD_app3 := Application3
# NB_AREA_app1 := 2 #^ specify the variant defines with the appropriate suffix
# NB_AREA_app2 := 3
# NB_AREA_app3 := 4
# NB_AREA=$(NB_AREA_$(VALID_TARGET)) #^ Must be added on each "make -s -e -j -f Makefile.main.mk ..." command in the Makefile file

# filename    : Makefile.target.config
# description : Makefile that defines what types of Application software will be built
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018-2022, Autoliv Romania
# version     : 2.0.0
# email       : dan.dustinta@autoliv.com
# status      : Released
