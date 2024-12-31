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

#ifndef INTCTRL_IP_CFG_H_
#define INTCTRL_IP_CFG_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "IntCtrl_Ip_TypesDef.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_INTCTRL_IP_CFG_VENDOR_ID                          43
#define PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION                   1
#define PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION                   0
#define PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION                   1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Ip_TypesDef header file are of the same vendor */
#if (PLATFORM_INTCTRL_IP_CFG_VENDOR_ID != PLATFORM_INTCTRL_IP_TYPESDEF_TYPES_VENDOR_ID)
    #error "IntCtrl_Ip_Cfg.h and IntCtrl_Ip_TypesDef.h have different vendor ids"
#endif

/* Check if current file and Fls header file are of the same Software version */
#if ((PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION != PLATFORM_INTCTRL_IP_TYPESDEF_SW_MAJOR_VERSION) || \
     (PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION != PLATFORM_INTCTRL_IP_TYPESDEF_SW_MINOR_VERSION) || \
     (PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION != PLATFORM_INTCTRL_IP_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip_Cfg.h and IntCtrl_Ip_TypesDef.h are different"
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
[!NOCODE!]
[!VAR "NvicVectorAvailable" = "0"!]
[!LOOP "IntCtrlConfig/*"!]
    [!IF "./PlatformNvicEcucPartitionRef = $PartitionRefName "!]
        [!VAR "NvicVectorAvailable" = "1"!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]
  
[!IF "$NvicVectorAvailable = 1"!]
/* Definition of the configuration structure for Platform IPW */
extern const IntCtrl_Ip_CtrlConfigType intCtrlConfig[!"$PartitionShortName"!];
[!ENDIF!]

[!IF "(GeneralConfiguration/PlatformMscmConfigurable = 'true') and (MscmConfig/PlatformGenericInterruptEcucPartitionRef = $PartitionRefName)"!]
/* Definition of the configuration structure for non core Platform IPW */
extern const IntCtrl_Ip_GlobalRouteConfigType intRouteConfig[!"$PartitionShortName"!];
[!ENDIF!]

/* Declaration of interrupt handlers 
 * NOTE: For application specific handlers, these functions must be implemented in the application code!
 */
[!NOCODE!]

[!VAR "tempHandlersList"!][!ENDVAR!]
[!LOOP "MscmConfig/PlatformIsrConfig/*"!]
    [!VAR "tempHandlersList" = "concat($tempHandlersList, IsrHandler, ' ')"!]
[!ENDLOOP!]

[!VAR "uniqueHandlers"!][!ENDVAR!]
[!LOOP "text:split($tempHandlersList)"!]
    [!IF "contains(text:split($uniqueHandlers), . ) = 0"!]     
        [!VAR "uniqueHandlers" = "concat($uniqueHandlers, . , ' ')"!]      
            [!IF "(contains(. , 'NULL_PTR') = 0)"!]
                [!CODE!]extern void [!"."!](void);[!CR!][!ENDCODE!]
            [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]

/*================================== End Partition [!"$PartitionShortName"!] ==============================*/
[!ENDCODE!]
[!ENDIF!]
[!ENDFOR!]
[!ELSE!]
[!IF "count(IntCtrlConfig/*) > 0"!]
[!CODE!]
/* Definition of the configuration structure for Platform IPW */
extern const IntCtrl_Ip_CtrlConfigType intCtrlConfig;
[!ENDCODE!]
[!ENDIF!] [!// count(IntCtrlConfig/*) > 0
[!CODE!]
[!IF "GeneralConfiguration/PlatformMscmConfigurable"!]
/* Definition of the configuration structure for non core Platform IPW */
extern const IntCtrl_Ip_GlobalRouteConfigType intRouteConfig;
[!ENDIF!]
/* Declaration of interrupt handlers 
 * NOTE: For application specific handlers, these functions must be implemented in the application code!
 */
[!NOCODE!]

[!VAR "tempHandlersList"!][!ENDVAR!]
[!LOOP "MscmConfig/PlatformIsrConfig/*"!]
    [!VAR "tempHandlersList" = "concat($tempHandlersList, IsrHandler, ' ')"!]
[!ENDLOOP!]

[!VAR "uniqueHandlers"!][!ENDVAR!]
[!LOOP "text:split($tempHandlersList)"!]
    [!IF "contains(text:split($uniqueHandlers), . ) = 0"!]     
        [!VAR "uniqueHandlers" = "concat($uniqueHandlers, . , ' ')"!]
        [!IF "contains(. , 'NULL_PTR') and (contains(text:split($uniqueHandlers), 'undefined_handler') = 0) or (contains(. , 'undefined_handler') and contains(text:split($uniqueHandlers), 'NULL_PTR') = 0)"!]  
            [!CODE!]extern void undefined_handler(void);[!CR!][!ENDCODE!]           
        [!ELSE!]
            [!IF "contains(. , 'undefined_handler') = 0 and (contains(. , 'NULL_PTR') = 0)"!]
                [!CODE!]extern void [!"."!](void);[!CR!][!ENDCODE!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]

[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#endif /* INTCTRL_IP_CFG_H_ */

