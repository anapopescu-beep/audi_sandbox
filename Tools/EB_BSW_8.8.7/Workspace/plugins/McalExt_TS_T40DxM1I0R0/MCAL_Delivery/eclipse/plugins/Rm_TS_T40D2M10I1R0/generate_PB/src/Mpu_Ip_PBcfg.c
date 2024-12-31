/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
*
*   (c) Copyright 2020-2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file Mpu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*
*   @addtogroup MPU_IP MPU IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mpu_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MPU_IP_CFG_VENDOR_ID_C                     43
#define RM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION_C      4
#define RM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define RM_MPU_IP_CFG_SW_MAJOR_VERSION_C              1
#define RM_MPU_IP_CFG_SW_MINOR_VERSION_C              0
#define RM_MPU_IP_CFG_SW_PATCH_VERSION_C              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mpu_Ip_Cfg.h */
#if (RM_MPU_IP_CFG_VENDOR_ID_C != RM_MPU_IP_CFG_VENDOR_ID)
    #error "Mpu_Ip_Cfg.c and Mpu_Ip_Cfg.h have different vendor ids"
#endif
#if ((RM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != RM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != RM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION_C != RM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_Cfg.h are different"
#endif
#if ((RM_MPU_IP_CFG_SW_MAJOR_VERSION_C != RM_MPU_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_MPU_IP_CFG_SW_MINOR_VERSION_C != RM_MPU_IP_CFG_SW_MINOR_VERSION) || \
     (RM_MPU_IP_CFG_SW_PATCH_VERSION_C != RM_MPU_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip_Cfg.c and Mpu_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
[!NOCODE!]
    [!IF "RmGeneral/RmMpuConfigurable"!] /* System settings */
/* Check  available master in resource */
[!VAR "Master0Support" = "ecu:get('Rm.Mpu.Master0.CoreSupport')"!]
[!VAR "Master1Support" = "ecu:get('Rm.Mpu.Master1.DebuggerSupport')"!]
[!VAR "Master2Support" = "ecu:get('Rm.Mpu.Master2.DMASupport')"!]
[!VAR "Master3Support" = "ecu:get('Rm.Mpu.Master3.EnetSupport')"!]
[!CODE!]
[!SELECT "RmConfigSet/Mpu_Configuration"!][!//
const Mpu_Ip_RegionConfigType [!"@name"!]_RegionConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(MpuRegionConfig/*))"!]] =
{
[!VAR "MpuLoopIt" = "count(node:current()/MpuRegionConfig/*)"!][!//
[!LOOP "node:current()/MpuRegionConfig/*"!][!//
[!NOCODE!]
    [!/* Get the MxUM, MxSM values which are depended on the available master */!]
    [!IF "$Master0Support = 'true'"!]
        [!VAR "M0UM" = "node:current()/UserModeAccessBusMaster0"!]
        [!VAR "M0SM" = "node:current()/SupervisorModeAccessBusMaster0"!]
    [!ELSE!]
        [!IF "node:current()/RegionNumber = '0'"!]
            [!VAR "M0UM" = "'MPU_USER_MODE_RWX'"!]
            [!VAR "M0SM" = "'MPU_SUPERVISOR_MODE_AS_USER_MODE'"!]
        [!ELSE!]
            [!VAR "M0UM" = "'MPU_USER_MODE_NONE'"!]
            [!VAR "M0SM" = "'MPU_SUPERVISOR_MODE_RWX'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$Master1Support = 'true'"!]
        [!VAR "M1UM" = "node:current()/UserModeAccessBusMaster1"!]
        [!VAR "M1SM" = "node:current()/SupervisorModeAccessBusMaster1"!]
    [!ELSE!]
        [!IF "node:current()/RegionNumber = '0'"!]
            [!VAR "M1UM" = "'MPU_USER_MODE_RWX'"!]
            [!VAR "M1SM" = "'MPU_SUPERVISOR_MODE_AS_USER_MODE'"!]
        [!ELSE!]
            [!VAR "M1UM" = "'MPU_USER_MODE_NONE'"!]
            [!VAR "M1SM" = "'MPU_SUPERVISOR_MODE_RWX'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$Master2Support = 'true'"!]
        [!VAR "M2UM" = "node:current()/UserModeAccessBusMaster2"!]
        [!VAR "M2SM" = "node:current()/SupervisorModeAccessBusMaster2"!]
    [!ELSE!]
        [!IF "node:current()/RegionNumber = '0'"!]
            [!VAR "M2UM" = "'MPU_USER_MODE_RWX'"!]
            [!VAR "M2SM" = "'MPU_SUPERVISOR_MODE_AS_USER_MODE'"!]
        [!ELSE!]
            [!VAR "M2UM" = "'MPU_USER_MODE_NONE'"!]
            [!VAR "M2SM" = "'MPU_SUPERVISOR_MODE_RWX'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$Master3Support = 'true'"!]
        [!VAR "M3UM" = "node:current()/UserModeAccessBusMaster3"!]
        [!VAR "M3SM" = "node:current()/SupervisorModeAccessBusMaster3"!]
    [!ELSE!]
        [!IF "node:current()/RegionNumber = '0'"!]
            [!VAR "M3UM" = "'MPU_USER_MODE_RWX'"!]
            [!VAR "M3SM" = "'MPU_SUPERVISOR_MODE_AS_USER_MODE'"!]
        [!ELSE!]
            [!VAR "M3UM" = "'MPU_USER_MODE_NONE'"!]
            [!VAR "M3SM" = "'MPU_SUPERVISOR_MODE_RWX'"!]
        [!ENDIF!]
    [!ENDIF!]

[!ENDNOCODE!][!//
[!VAR "MpuLoopIt" = "$MpuLoopIt - 1"!][!//
    /* Region Configuration [!"node:current()/RegionNumber"!] */
    {
        [!"node:current()/StartAddress"!]UL,
        [!"node:current()/EndAddress"!]UL,
[!IF "(node:current()/ProcessIdentifierEnableMaster0 = 'true') and ($Master0Support = 'true')"!][!//
        (MPU_RGD_WORD2_M0PE_MASK) | \
[!ENDIF!][!//
[!IF "(node:current()/ProcessIdentifierEnableMaster1 = 'true') and ($Master1Support = 'true')"!][!//
        (MPU_RGD_WORD2_M1PE_MASK) | \
[!ENDIF!][!//
        ([!"$M0SM"!] << MPU_RGD_WORD2_M0SM_SHIFT) | \
        ([!"$M1SM"!] << MPU_RGD_WORD2_M1SM_SHIFT) | \
        ([!"$M2SM"!] << MPU_RGD_WORD2_M2SM_SHIFT) | \
        ([!"$M3SM"!] << MPU_RGD_WORD2_M3SM_SHIFT) | \
        ([!"$M0UM"!] << MPU_RGD_WORD2_M0UM_SHIFT) | \
        ([!"$M1UM"!] << MPU_RGD_WORD2_M1UM_SHIFT) | \
        ([!"$M2UM"!] << MPU_RGD_WORD2_M2UM_SHIFT) | \
        ([!"$M3UM"!] << MPU_RGD_WORD2_M3UM_SHIFT),
        ([!"node:current()/ProcessIdentifier"!]U),
        ([!"node:current()/ProcessIdentifierMask"!]U)
    }[!IF "$MpuLoopIt != 0"!],[!ENDIF!]
[!ENDLOOP!][!//
};

static const uint8 [!"@name"!]_RegionNumber[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(MpuRegionConfig/*))"!]] =
{
[!VAR "MpuLoopIt" = "count(node:current()/MpuRegionConfig/*)"!][!//
[!LOOP "node:current()/MpuRegionConfig/*"!][!//
[!VAR "MpuLoopIt" = "$MpuLoopIt - 1"!][!//
    [!"node:current()/RegionNumber"!]U[!IF "$MpuLoopIt != 0"!],[!ENDIF!]
[!ENDLOOP!][!//
};

const Mpu_Ip_ConfigType Mpu_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    [!"num:i(count(MpuRegionConfig/*))"!]U,
    [!"@name"!]_RegionConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    [!"@name"!]_RegionNumber[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDSELECT!][!//

[!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

