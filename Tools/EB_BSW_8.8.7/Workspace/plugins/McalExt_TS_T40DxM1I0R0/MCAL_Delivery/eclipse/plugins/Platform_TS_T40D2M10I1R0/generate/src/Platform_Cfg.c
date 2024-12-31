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

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Platform_Cfg.h"
#include "Platform_Ipw_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_CFG_VENDOR_ID_C                     43
#define PLATFORM_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define PLATFORM_CFG_AR_RELEASE_MINOR_VERSION_C      4
#define PLATFORM_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define PLATFORM_CFG_SW_MAJOR_VERSION_C              1
#define PLATFORM_CFG_SW_MINOR_VERSION_C              0
#define PLATFORM_CFG_SW_PATCH_VERSION_C              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_Cfg header file are of the same vendor */
#if (PLATFORM_CFG_VENDOR_ID_C != PLATFORM_CFG_VENDOR_ID)
    #error "Platform_Cfg.c and Platform_TypesDef.h have different vendor ids"
#endif
/* Check if current file and Platform_Cfg header file are of the same Autosar version */
#if ((PLATFORM_CFG_AR_RELEASE_MAJOR_VERSION_C    != PLATFORM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_CFG_AR_RELEASE_MINOR_VERSION_C    != PLATFORM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_CFG_AR_RELEASE_REVISION_VERSION_C != PLATFORM_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Cfg.c and Platform_Cfg.h are different"
#endif
/* Check if current file and Platform_Cfg header file are of the same Software version */
#if ((PLATFORM_CFG_SW_MAJOR_VERSION_C != PLATFORM_CFG_SW_MAJOR_VERSION) || \
     (PLATFORM_CFG_SW_MINOR_VERSION_C != PLATFORM_CFG_SW_MINOR_VERSION) || \
     (PLATFORM_CFG_SW_PATCH_VERSION_C != PLATFORM_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Cfg.c and Platform_Cfg.h are different"
#endif


/* Check if current file and Platform_Ipw_Cfg header file are of the same vendor */
#if (PLATFORM_CFG_VENDOR_ID_C != PLATFORM_IPW_CFG_VENDOR_ID)
    #error "Platform_Cfg.c and Platform_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if current file and Platform_Ipw_Cfg header file are of the same Autosar version */
#if ((PLATFORM_CFG_AR_RELEASE_MAJOR_VERSION_C    != PLATFORM_IPW_CFG_AR_MAJOR_VERSION) || \
     (PLATFORM_CFG_AR_RELEASE_MINOR_VERSION_C    != PLATFORM_IPW_CFG_AR_MINOR_VERSION) || \
     (PLATFORM_CFG_AR_RELEASE_REVISION_VERSION_C != PLATFORM_IPW_CFG_AR_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Cfg.c and Platform_Ipw_Cfg.h are different"
#endif
/* Check if current file and Platform_Cfg header file are of the same Software version */
#if ((PLATFORM_CFG_SW_MAJOR_VERSION_C != PLATFORM_IPW_CFG_SW_MAJOR_VERSION) || \
     (PLATFORM_CFG_SW_MINOR_VERSION_C != PLATFORM_IPW_CFG_SW_MINOR_VERSION) || \
     (PLATFORM_CFG_SW_PATCH_VERSION_C != PLATFORM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Cfg.c and Platform_Ipw_Cfg.h are different"
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
[!NOCODE!]
[!IF "./GeneralConfiguration/PlatformMulticoreSupport = 'true'"!]
[!LOOP "GeneralConfiguration/PlatformEcucPartitionRef/*"!]
[!VAR "partitionRef" = "node:value(.)"!]
    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
        [!IF "$partitionRef = node:value(./OsAppEcucPartitionRef)"!]
            [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                [!VAR "CurrentCoreId" = "node:value(./EcucCoreId)"!]
            [!ENDSELECT!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!LOOP "../*"!]
        [!VAR "innerPartitionRef" = "node:value(.)"!]
        [!IF "$innerPartitionRef != $partitionRef"!]
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                [!IF "$innerPartitionRef = node:value(./OsAppEcucPartitionRef)"!]
                    [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                        [!VAR "innerCurrentCoreId" = "node:value(./EcucCoreId)"!]
                    [!ENDSELECT!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!IF "$innerCurrentCoreId = $CurrentCoreId"!]
                [!ERROR!][!"$innerPartitionRef"!] and [!"$partitionRef"!] reference to same core [!"$CurrentCoreId"!] in PlatformEcucPartitionRef[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!VAR "FoundReference" = "0"!]
    [!LOOP "../../../McmConfig/*"!]
        [!IF "PlatformMcmEcucPartitionRef = $partitionRef"!]
            [!VAR "FoundReference" = "1"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!LOOP "../../../IntCtrlConfig/*"!]
        [!IF "PlatformNvicEcucPartitionRef = $partitionRef"!]
            [!VAR "FoundReference" = "1"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!LOOP "../../../IntmConfig/IntmChannel/*"!]
        [!IF "PlatformIntmChannelEcucPartitionRef = $partitionRef"!]
            [!VAR "FoundReference" = "1"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!SELECT "../../../MscmConfig"!]
        [!IF "PlatformGenericInterruptEcucPartitionRef = $partitionRef"!]
            [!VAR "FoundReference" = "1"!]
        [!ENDIF!]
    [!ENDSELECT!]
    [!SELECT "../../../IntmConfig/IntmGenericSettings"!]
        [!IF "PlatformIntmGenericEcucPartitionRef = $partitionRef"!]
            [!VAR "FoundReference" = "1"!]
        [!ENDIF!]
    [!ENDSELECT!]
    [!IF "$FoundReference = 0"!]
        [!ERROR!] Partition Reference [!"$partitionRef"!] is not used neither in McmConfig, MscmConfig nor IntCtrlConfig[!ENDERROR!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDIF!]



/* Variable indicate multicore feature enabled */
[!VAR "MulticoreEnabled" = "0"!]

[!IF "./GeneralConfiguration/PlatformMulticoreSupport = 'true'"!]
    [!VAR "MulticoreEnabled" = "1"!]
[!ENDIF!]

/* Variable storing number of maximum partitions using in configuration */
[!VAR "numPartition" = "0"!]


[!IF "$MulticoreEnabled = 1"!]
[!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
    [!SELECT "node:ref(./OsApplicationCoreRef)"!]
        [!IF "$numPartition < node:value(./EcucCoreId)"!]
            [!VAR "numPartition" = "node:value(./EcucCoreId)"!]
        [!ENDIF!]
    [!ENDSELECT!]
[!ENDLOOP!]

[!VAR "numPartition" = "$numPartition + 1"!]

[!FOR "CurrentCoreId" = "0" TO "$numPartition - 1"!]
    [!VAR "CoreIdConfigured" = "0"!]
    [!LOOP "GeneralConfiguration/PlatformEcucPartitionRef/*"!]
        [!VAR "PartitionRefName" = "node:value(.)"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($PartitionRefName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
            [!IF "$PartitionRefName = node:value(./OsAppEcucPartitionRef)"!]
                [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                    [!IF "$CurrentCoreId = node:value(./EcucCoreId)"!]                    
                        [!VAR "CoreIdConfigured" = "1"!]
                        [!VAR "PartitionShortName" = "$CurrentPartitionShortName"!]
                    [!ENDIF!]
                [!ENDSELECT!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]
    [!IF "$CoreIdConfigured = 1"!]
        [!CODE!]
/*================================== Partition [!"$PartitionShortName"!] ==================================*/
static const Platform_ConfigType Platform_uConfiguration[!"$PartitionShortName"!] = 
{
    &ipwConfig[!"$PartitionShortName"!],
    [!IF "GeneralConfiguration/PlatformMscmConfigurable"!]&ipwNonCoreConfig[!"$PartitionShortName"!][!ELSE!]NULL_PTR[!ENDIF!]
};
        [!ENDCODE!]
    [!ENDIF!]
[!ENDFOR!] 
[!ENDIF!]
[!ENDNOCODE!]   


[!IF "$MulticoreEnabled = 1"!]
const Platform_ConfigType *const Platform_Config[PLATFORM_MAX_PARTITIONS]=
{
[!NOCODE!]
[!FOR "CurrentCoreId" = "0" TO "$numPartition - 1"!]
    [!VAR "CoreIdConfigured" = "0"!]
    [!LOOP "GeneralConfiguration/PlatformEcucPartitionRef/*"!]
        [!VAR "PartitionRefName" = "node:value(.)"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($PartitionRefName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
            [!IF "$PartitionRefName = node:value(./OsAppEcucPartitionRef)"!]
                [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                    [!IF "$CurrentCoreId = node:value(./EcucCoreId)"!]                    
                        [!VAR "CoreIdConfigured" = "1"!]
                        [!VAR "PartitionShortName" = "$CurrentPartitionShortName"!]
                    [!ENDIF!]
                [!ENDSELECT!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]
    [!IF "$CoreIdConfigured = 1"!]
        [!CODE!]
    &Platform_uConfiguration[!"$PartitionShortName"!][!IF "$CurrentCoreId < ($numPartition - 1)"!], [!ENDIF!]
        [!ENDCODE!]
    [!ELSE!]
        [!CODE!]
    NULL_PTR[!IF "$CurrentCoreId < ($numPartition - 1)"!], [!ENDIF!]
        [!ENDCODE!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDNOCODE!]    
};
[!ELSE!]
static const Platform_ConfigType Platform_uConfiguration = {
    &ipwConfig,
    [!IF "GeneralConfiguration/PlatformMscmConfigurable"!]&ipwNonCoreConfig[!ELSE!]NULL_PTR[!ENDIF!]
};
const Platform_ConfigType *const Platform_Config[1U]=
{
    &Platform_uConfiguration
};
[!ENDIF!]

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

