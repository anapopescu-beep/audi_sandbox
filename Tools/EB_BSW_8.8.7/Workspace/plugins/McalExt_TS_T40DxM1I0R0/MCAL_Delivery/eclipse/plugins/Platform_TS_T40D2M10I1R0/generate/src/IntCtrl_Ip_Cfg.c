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
#include "IntCtrl_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C                          43
#define PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C                   1
#define PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C                   0
#define PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C                   1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same vendor */
#if (PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C != PLATFORM_INTCTRL_IP_CFG_VENDOR_ID)
    #error "IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h have different vendor ids"
#endif

/* Check if current file and IntCtrl_Ip_Cfg header file are of the same Software version */
#if ((PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C != PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION) || \
     (PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C != PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION) || \
     (PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C != PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
[!NOCODE!]

[!IF "./GeneralConfiguration/PlatformMulticoreSupport = 'true'"!]


/* Variable storing number of maximum partitions using in configuration */
[!VAR "numPartition" = "0"!]

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
        [!VAR "CurrentPartitionRefName" = "node:value(.)"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionRefName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
            [!IF "$CurrentPartitionRefName = node:value(./OsAppEcucPartitionRef)"!]
                [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                    [!IF "$CurrentCoreId = node:value(./EcucCoreId)"!]                    
                        [!VAR "CoreIdConfigured" = "1"!]
                        [!VAR "PartitionShortName" = "$CurrentPartitionShortName"!]
                        [!VAR "PartitionRefName" = "$CurrentPartitionRefName"!]
                    [!ENDIF!]
                [!ENDSELECT!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]
[!IF "$CoreIdConfigured = 1"!]
[!CODE!]
/*================================== Partition [!"$PartitionShortName"!] ==================================*/
[!ENDCODE!]

[!LOOP "IntCtrlConfig/*"!]
    [!IF "./PlatformNvicEcucPartitionRef = $PartitionRefName "!]
        [!CODE!]


/* List of configurations for interrupts */
static const IntCtrl_Ip_IrqConfigType aIrqConfiguration[!"$PartitionShortName"!][] = {
[!NOCODE!]
[!LOOP "./PlatformIsrConfig/*"!]
[!CODE!]    {[!"IsrName"!], (boolean)[!IF "IsrEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!], [!"IsrPriority"!]U},
[!ENDCODE!]
[!ENDLOOP!]
[!ENDNOCODE!]};

/* Configuration structure for interrupt controller */
const IntCtrl_Ip_CtrlConfigType intCtrlConfig[!"$PartitionShortName"!] = {
    [!"ecu:get('Platform.irqCount')"!]U,
    [!IF "(./../../GeneralConfiguration/PlatformEnableVtorConfiguration = 'true')"!]
    [!"./PlatformVtorAddressConfig"!]U [!ENDIF!]
    aIrqConfiguration[!"$PartitionShortName"!]
};



        [!ENDCODE!]
    [!ENDIF!] [!//  [!IF "./PlatformNvicEcucPartitionRef = $PartitionRefName "!]
[!ENDLOOP!] [!//  [!LOOP "IntCtrlConfig/*"!]

[!IF "(GeneralConfiguration/PlatformMscmConfigurable = 'true') and (MscmConfig/PlatformGenericInterruptEcucPartitionRef = $PartitionRefName)"!]
    [!CODE!]
/* List of configurations for routing interrupts */
static const IntCtrl_Ip_IrqRouteConfigType aIrqRouteConfig[!"$PartitionShortName"!][] = {
    [!ENDCODE!]
[!NOCODE!]
[!LOOP "MscmConfig/PlatformIsrConfig/*"!]
    [!VAR "tempTargetCores" = "0"!]
[!IF "ecu:get('Platform.mscmIrqRouter') = 'STD_ON'"!]       
    [!IF "text:contains(string(ecu:list('Platform.targetCoresArrayList')[position() = 1]), 'True')"!]
    [!IF "IsrTargetCore0"!]
        [!VAR "tempTargetCores" = "num:dectoint($tempTargetCores) + 1"!]
    [!ENDIF!]
    [!ENDIF!]
    [!IF "text:contains(string(ecu:list('Platform.targetCoresArrayList')[position() = 2]),'True')"!]
    [!IF "IsrTargetCore1"!]
        [!VAR "tempTargetCores" = "num:dectoint($tempTargetCores) + 2"!]
    [!ENDIF!]
    [!ENDIF!]
    [!IF "text:contains(string(ecu:list('Platform.targetCoresArrayList')[position() = 3]),'True')"!]
    [!IF "IsrTargetCore2"!]
        [!VAR "tempTargetCores" = "num:dectoint($tempTargetCores) + 4"!]
    [!ENDIF!]
    [!ENDIF!]
    [!IF "text:contains(string(ecu:list('Platform.targetCoresArrayList')[position() = 4]),'True')"!]
    [!IF "IsrTargetCore3"!]
        [!VAR "tempTargetCores" = "num:dectoint($tempTargetCores) + 8"!]
    [!ENDIF!]
    [!ENDIF!]   
    [!IF "text:contains(string(ecu:list('Platform.targetCoresArrayList')[position() = 5]),'True')"!]
    [!IF "IsrTargetCore4"!]
        [!VAR "tempTargetCores" = "num:dectoint($tempTargetCores) + 16"!]
    [!ENDIF!]
    [!ENDIF!]    
[!ENDIF!]    
    [!CODE!]    {[!"IsrName"!], [!"num:dectoint($tempTargetCores)"!]U, [!"IsrHandler"!]},
    [!ENDCODE!]

[!ENDLOOP!] [!//MscmConfig/PlatformIsrConfig/*
[!ENDNOCODE!]
[!CODE!]};[!ENDCODE!]
[!CODE!]
/* Configuration structure for routing interrupt */
const IntCtrl_Ip_GlobalRouteConfigType intRouteConfig[!"$PartitionShortName"!] = {
    [!"ecu:get('Platform.irqCount')"!]U,
    aIrqRouteConfig[!"$PartitionShortName"!]
};
[!ENDCODE!]
[!ENDIF!] [!// [!IF "GeneralConfiguration/PlatformMscmConfigurable"!]

[!CODE!]

/*===============================END Partition [!"$PartitionShortName"!] ==================================*/
[!ENDCODE!]
[!ENDIF!]
[!ENDFOR!]
[!ELSE!] [!// [!IF "./GeneralConfiguration/PlatformMulticoreSupport = 'true'"!]
[!IF "count(IntCtrlConfig/*) > 0"!]
    [!CODE!]
/* List of configurations for interrupts */
static const IntCtrl_Ip_IrqConfigType aIrqConfiguration[] = {
[!NOCODE!]
[!LOOP "IntCtrlConfig/*[1]/PlatformIsrConfig/*"!]
[!CODE!]    {[!"IsrName"!], (boolean)[!IF "IsrEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!], [!"IsrPriority"!]U},
[!ENDCODE!]
[!ENDLOOP!]
[!ENDNOCODE!]};

/* Configuration structure for interrupt controller */
const IntCtrl_Ip_CtrlConfigType intCtrlConfig = {
    [!"ecu:get('Platform.irqCount')"!]U,
    [!IF "(GeneralConfiguration/PlatformEnableVtorConfiguration = 'true')"!] [!LOOP "IntCtrlConfig/*[1]"!]
    [!CODE!][!"PlatformVtorAddressConfig"!]U, [!ENDCODE!] [!ENDLOOP!]
    [!ENDIF!]
    aIrqConfiguration
    
};
    [!ENDCODE!]
[!ENDIF!] [!// count(IntCtrlConfig/*) > 0
    
[!IF "GeneralConfiguration/PlatformMscmConfigurable"!]
    [!CODE!]
/* List of configurations for routing interrupts */
static const IntCtrl_Ip_IrqRouteConfigType aIrqRouteConfig[] = {
    [!ENDCODE!]
[!NOCODE!]
[!LOOP "MscmConfig/PlatformIsrConfig/*"!]
    [!VAR "tempTargetCores" = "0"!]
[!IF "ecu:get('Platform.mscmIrqRouter') = 'STD_ON'"!]    
    [!IF "text:contains(string(ecu:list('Platform.targetCoresArrayList')[position() = 1]), 'True')"!]
    [!IF "IsrTargetCore0"!]
        [!VAR "tempTargetCores" = "num:dectoint($tempTargetCores) + 1"!]
    [!ENDIF!]
    [!ENDIF!]
    [!IF "text:contains(string(ecu:list('Platform.targetCoresArrayList')[position() = 2]),'True')"!]
    [!IF "IsrTargetCore1"!]
        [!VAR "tempTargetCores" = "num:dectoint($tempTargetCores) + 2"!]
    [!ENDIF!]
    [!ENDIF!]

    [!IF "text:contains(string(ecu:list('Platform.targetCoresArrayList')[position() = 3]),'True')"!]
    [!IF "IsrTargetCore2"!]
        [!VAR "tempTargetCores" = "num:dectoint($tempTargetCores) + 4"!]
    [!ENDIF!]
    [!ENDIF!]
    [!IF "text:contains(string(ecu:list('Platform.targetCoresArrayList')[position() = 4]),'True')"!]
    [!IF "IsrTargetCore3"!]
        [!VAR "tempTargetCores" = "num:dectoint($tempTargetCores) + 8"!]
    [!ENDIF!]
    [!ENDIF!]
    [!IF "text:contains(string(ecu:list('Platform.targetCoresArrayList')[position() = 5]),'True')"!]
    [!IF "IsrTargetCore4"!]
        [!VAR "tempTargetCores" = "num:dectoint($tempTargetCores) + 16"!]
    [!ENDIF!]
    [!ENDIF!]    
[!ENDIF!]    

    [!CODE!]    {[!"IsrName"!], [!"num:dectoint($tempTargetCores)"!]U, [!"IsrHandler"!]},
    [!ENDCODE!]

[!ENDLOOP!] [!//MscmConfig/PlatformIsrConfig/*
[!ENDNOCODE!]
[!CODE!]};[!ENDCODE!]
[!CODE!]
/* Configuration structure for routing interrupt */
const IntCtrl_Ip_GlobalRouteConfigType intRouteConfig = {
    [!"ecu:get('Platform.irqCount')"!]U,
    aIrqRouteConfig
};
[!ENDCODE!]
[!ENDIF!] [!// [!IF "GeneralConfiguration/PlatformMscmConfigurable"!]
[!ENDIF!] [!// multicore
[!ENDNOCODE!]

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
