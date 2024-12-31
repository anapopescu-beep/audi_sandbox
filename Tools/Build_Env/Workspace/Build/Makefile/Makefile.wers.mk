# Number of supported solenoids
ECS_NB_OF_SOLENOIDS := 6
# APPL_VERSION_REV1 - Old strategy software revision
APPL_VERSION_REV1 := XXXXXXXX.XXX
ifeq ($(BUILD_MODE),RELEASE)
# APPL_VERSION_REV2 - New strategy software revision
APPL_VERSION_REV2 := ES01400H.R20
else
APPL_VERSION_REV2 := ES0140$(shell date +'%m').B$(shell date +'%d')
endif
# APPL_FAB_VERSION - NVP fab file revision
APPL_FAB_VERSION :=
ifeq ($(BUILD_MODE),RELEASE)
# SAP_NAME - Name for SAP file
SAP_NAME := eCS_0HR2.0
SAP_NAME_VARIANT := eCS_S32K146_0HR2.0
else
SAP_NAME := eCS_R$(shell date +'%m').B$(shell date +'%d')
SAP_NAME_VARIANT := eCS_S32K146_R$(shell date +'%m').B$(shell date +'%d')
endif
# Versioning information for ODX - Application block
OEM_APPL_VERSION_REV := E020
# Versioning information for ODX - Calibration block
OEM_CALIB_VERSION_REV := C013
# Versioning information for ODX - Bootloader block
OEM_BTLD_VERSION_REV := B213
# Versioning information for ODX - Bootloader Updater block
OEM_BTLD_UPD_VERSION_REV := B910
# Versioning information for ODX - Container revision nb.
OEM_CONTAINER_VERSION_REV := 001

# filename    : Makefile.wers
# description : Contains versioning information
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018-2022, Autoliv Romania
# version     : 2.0.0
# email       : dan.dustinta@autoliv.com
# status      : Released
