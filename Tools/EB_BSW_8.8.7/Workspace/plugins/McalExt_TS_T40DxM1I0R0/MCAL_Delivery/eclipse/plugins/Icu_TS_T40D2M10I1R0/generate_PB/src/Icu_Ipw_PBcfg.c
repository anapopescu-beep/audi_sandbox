[!AUTOSPACING!][!//
[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm Lpit Lptmr Port_Ci LpCmp
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
 *   @file       Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c
 *   @version    1.0.1
 *
 *   @brief      AUTOSAR Icu - contains the data exported by the Icu module
 *   @details    Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup icu_ipw
 *   @{
 */
 
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
*================================================================================================*/
[!NOCODE!][!//

[!INCLUDE "Icu_Ipw_PluginMacros.m"!][!//

[!ENDNOCODE!][!//
#include "StandardTypes.h"
#include "Icu_Ipw_Types.h"
#include "Ftm_Icu_Ip.h"
#include "Lpit_Icu_Ip.h"
#include "Lptmr_Icu_Ip.h"
#include "Port_Ci_Icu_Ip.h"
#include "Cmp_Ip.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C                   43
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C    4
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C    4
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C 0
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C            1
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C            0
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C            1

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes.h file are of the same Autosar version */
    #if ((ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and StandardTypes.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Icu_Ipw_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C  != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C  != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C   != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Icu_Ipw_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C  != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C  != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C  != ICU_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Icu_Ipw_Types.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C != LPTMR_ICU_IP_VENDOR_ID)
    #error "Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Lptmr_Icu_Ip.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C  != LPTMR_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C  != LPTMR_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C   != LPTMR_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Lptmr_Icu_Ip.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C  != LPTMR_ICU_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C  != LPTMR_ICU_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C  != LPTMR_ICU_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Lptmr_Icu_Ip.h are different"
#endif

#if (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C != LPIT_ICU_IP_VENDOR_ID)
    #error "Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Lpit_Icu_Ip.h have different vendor ids"
#endif

/* Check if  source file and Lpit_Icu_Ip.h file are of the same Autosar version */
#if ((ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C != LPIT_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C != LPIT_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C != LPIT_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Lpit_Icu_Ip.h are different"
#endif

/* Check if source file and Lpit_Icu_Ip.h file are of the same Software version */
#if ((ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C != LPIT_ICU_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C != LPIT_ICU_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C != LPIT_ICU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Lpit_Icu_Ip.h are different"
#endif

#if (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C != FTM_ICU_IP_VENDOR_ID)
    #error "Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Ftm_Icu_Ip.h have different vendor ids"
#endif

/* Check if  source file and Ftm_Icu_Ip.h file are of the same Autosar version */
#if ((ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C != FTM_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C != FTM_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C != FTM_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Ftm_Icu_Ip.h are different"
#endif

/* Check if source file and Ftm_Icu_Ip.h file are of the same Software version */
#if ((ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C != FTM_ICU_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C != FTM_ICU_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C != FTM_ICU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Ftm_Icu_Ip.h are different"
#endif

#if (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C != PORT_CI_ICU_IP_VENDOR_ID)
    #error "Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Port_Ci_Icu_Ip.h have different vendor ids"
#endif

/* Check if  source file and Port_Ci_Icu_Ip.h file are of the same Autosar version */
#if ((ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C != PORT_CI_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C != PORT_CI_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C != PORT_CI_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Port_Ci_Icu_Ip.h are different"
#endif

/* Check if source file and Port_Ci_Icu_Ip.h file are of the same Software version */
#if ((ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C != PORT_CI_ICU_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C != PORT_CI_ICU_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C != PORT_CI_ICU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Port_Ci_Icu_Ip.h are different"
#endif

#if (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C != CMP_IP_VENDOR_ID)
    #error "Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Cmp_Ip.h have different vendor ids"
#endif
/* Check if  source file and Cmp_Ip.h file are of the same Autosar version */
#if ((ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C != CMP_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C != CMP_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C != CMP_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Cmp_Ip.h are different"
#endif

/* Check if source file and Cmp_Ip.h file are of the same Software version */
#if ((ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C != CMP_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C != CMP_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C != CMP_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCfg.c and Cmp_Ip.h are different"
#endif

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
 *================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
/**
 *   @brief This index relates the Hardware channels with the respective ICU channel. *
 *   When an normal interrupt is asserted this index is used to locate the corresponding ICU channel
 */[!//

[!NOCODE!]

[!FOR "PartitionIdx" = "1" TO "$IcuEcucPartitionRefNum"!]
    [!IF "$IcuEcucPartitionRefCount != 0 "!]
        [!VAR "PartitionIndex" = "node:name(node:value(IcuGeneral/IcuEcucPartitionRef/*[num:i($PartitionIdx)]))"!]
        [!VAR "IcuEcucPartitionRefName" = "node:value(IcuGeneral/IcuEcucPartitionRef/*[num:i($PartitionIdx)])"!]
    [!ENDIF!]
    [!SELECT "IcuConfigSet"!][!//
        [!CALL "ICU_VARIABLES"!]
        [!IF "num:i($OutNumChannelInPartition)!=0"!]
            [!CODE!]/** @brief ICU channels IP related configuration array */[!CR!][!ENDCODE!]
            [!CODE!]const Icu_Ipw_ChannelConfigType Icu_Ipw_IpChannelConfig_[!"$PBCfg_Variant"!][!IF "$IcuEcucPartitionRefCount != 0 "!]_P_[!"$PartitionIndex"!][!ENDIF!][[!"num:i($OutNumChannelInPartition)"!]U] =[!CR!]{[!CR!][!ENDCODE!]
            [!VAR "CurIcuChannelUsingFtm"  = "0"!]
            [!VAR "CurIcuChannelUsingLpit" = "0"!]
            [!VAR "CurIcuChannelUsingLptmr"    = "0"!]
            [!VAR "CurIcuChannelUsingPort"    = "0"!]
            [!VAR "CurIcuChannelUsingCmp"    = "0"!]
            [!VAR "comma" = "1"!]
            [!VAR "NumIcuChannels" = "num:i(count(IcuChannel/*))"!]
            [!FOR "Idx" = "0" TO "$NumIcuChannels - 1"!]
                [!LOOP "IcuChannel/*"!]
                    [!IF "num:i($Idx) = num:i(IcuChannelId)"!]
                        [!IF "(($IcuEcucPartitionRefCount = 0) or (node:value(./IcuChannelEcucPartitionRef/*[1]) = $IcuEcucPartitionRefName)) "!]
                            [!CODE!][!WS "4"!]/** @brief [!"@name"!] */[!CR!][!ENDCODE!]
                            [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                            [!IF "contains(node:path(node:ref(IcuChannelRef)), 'IcuFtm')"!]
                                [!CODE!][!WS "8"!]/** @brief IP type of this channel */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]ICU_FTM_MODULE,[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Instance number */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!](uint8)[!"node:value(node:ref(IcuChannelRef)/../../IcuFtmModule)"!],[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief FTM IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]&Ftm_Icu_Ip_[!"node:ref(IcuChannelRef)/../../IcuFtmModule"!]_ChannelConfig_[!"$PBCfg_Variant"!][[!"node:ref(IcuChannelRef)/@index"!]U],[!CR!][!ENDCODE!]                                              
                                
                                [!CODE!][!WS "8"!]/** @brief LPIT IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]  
                            
                                [!CODE!][!WS "8"!]/** @brief LPTMR IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                            
                                [!CODE!][!WS "8"!]/** @brief Port Ci IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Cmp IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Index in the configuration table of the FTM channels */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!](uint8)[!"num:i($CurIcuChannelUsingFtm)"!][!CR!][!ENDCODE!]
                                [!VAR "CurIcuChannelUsingFtm" = "$CurIcuChannelUsingFtm + 1"!]
                            
                            [!ELSEIF "contains(node:path(node:ref(IcuChannelRef)), 'IcuPort')"!]
                                [!CODE!][!WS "8"!]/** @brief IP type of this channel */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]ICU_PORT_CI_MODULE,[!CR!][!ENDCODE!]
                            
                                [!CODE!][!WS "8"!]/** @brief Instance number */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!](uint8)[!"node:value(node:ref(IcuChannelRef)/../../IcuPortModule)"!],[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Ftm IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief LPIT IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]  
                                
                                [!CODE!][!WS "8"!]/** @brief LPTMR IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Port Ci IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]&Port_Ci_Icu_Ip_[!"node:ref(IcuChannelRef)/../../IcuPortModule"!]_ChannelConfig_[!"$PBCfg_Variant"!][[!"node:ref(IcuChannelRef)/@index"!]U],[!CR!][!ENDCODE!]                                              

                                [!CODE!][!WS "8"!]/** @brief Cmp IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Index in the configuration table of the Port Ci channels */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!](uint8)[!"num:i($CurIcuChannelUsingPort)"!][!CR!][!ENDCODE!]
                                [!VAR "CurIcuChannelUsingPort" = "$CurIcuChannelUsingPort + 1"!]

                            [!ELSEIF "contains(node:path(node:ref(IcuChannelRef)), 'IcuLptmr')"!]
                                [!CODE!][!WS "8"!]/** @brief IP type of this channel */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]ICU_LPTMR_MODULE,[!CR!][!ENDCODE!]
                            
                                [!CODE!][!WS "8"!]/** @brief Instance number */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!](uint8)[!"node:value(node:ref(IcuChannelRef)/../../IcuLptmrModule)"!],[!CR!][!ENDCODE!]
                            
                                [!CODE!][!WS "8"!]/** @brief Ftm IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                            
                                [!CODE!][!WS "8"!]/** @brief LPIT IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]  
                            
                                [!CODE!][!WS "8"!]/** @brief LPTMR IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]&Lptmr_Icu_Ip_[!"node:ref(IcuChannelRef)/../../IcuLptmrModule"!]_ChannelConfig_[!"$PBCfg_Variant"!][[!"node:ref(IcuChannelRef)/@index"!]U],[!CR!][!ENDCODE!]                                              
                                
                                [!CODE!][!WS "8"!]/** @brief Port Ci IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Cmp IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Index in the configuration table of the LPTMR channels */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!](uint8)[!"num:i($CurIcuChannelUsingLptmr)"!][!CR!][!ENDCODE!]
                                [!VAR "CurIcuChannelUsingLptmr" = "$CurIcuChannelUsingLptmr + 1"!]
                            
                            [!ELSEIF "contains(node:path(node:ref(IcuChannelRef)), 'IcuLpit')"!]
                                [!CODE!][!WS "8"!]/** @brief IP type of this channel */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]ICU_LPIT_MODULE,[!CR!][!ENDCODE!]
                                    
                                [!CODE!][!WS "8"!]/** @brief Instance number */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!](uint8)[!"node:value(node:ref(IcuChannelRef)/../../IcuLpitModule)"!],[!CR!][!ENDCODE!]

                                [!CODE!][!WS "8"!]/** @brief FTM IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]   
                                
                                [!CODE!][!WS "8"!]/** @brief LPIT IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]&Lpit_Icu_Ip_[!"node:ref(IcuChannelRef)/../../IcuLpitModule"!]_ChannelConfig_[!"$PBCfg_Variant"!][[!"node:ref(IcuChannelRef)/@index"!]U],[!CR!][!ENDCODE!]                                              

                                [!CODE!][!WS "8"!]/** @brief LPTMR IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                            
                                [!CODE!][!WS "8"!]/** @brief Port Ci IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Cmp IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Index in the configuration table of the LPIT channels */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!](uint8)[!"num:i($CurIcuChannelUsingLpit)"!][!CR!][!ENDCODE!]
                                [!VAR "CurIcuChannelUsingLpit" = "$CurIcuChannelUsingLpit + 1"!]
                                
                            [!ELSEIF "contains(node:path(node:ref(IcuChannelRef)), 'IcuLpCmp')"!]
                                [!CODE!][!WS "8"!]/** @brief IP type of this channel */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]ICU_CMP_MODULE,[!CR!][!ENDCODE!]
                            
                                [!CODE!][!WS "8"!]/** @brief Instance number */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!](uint8)[!"node:value(node:ref(IcuChannelRef)/IcuCmpInstanceNumber)"!],[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Ftm IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief LPIT IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]  
                                
                                [!CODE!][!WS "8"!]/** @brief LPTMR IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Port Ci IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Cmp IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]&Cmp_Ip_[!"node:ref(IcuChannelRef)/IcuCmpInstanceNumber"!]_Config_[!"$PBCfg_Variant"!],[!CR!][!ENDCODE!]
                                
                                [!CODE!][!WS "8"!]/** @brief Index in the configuration table of the CMP channels */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!](uint8)[!"num:i($CurIcuChannelUsingCmp)"!][!CR!][!ENDCODE!]
                                [!VAR "CurIcuChannelUsingCmp" = "$CurIcuChannelUsingCmp + 1"!]
                            [!ENDIF!]
                            
                            [!CODE!][!WS "4"!]}[!ENDCODE!]
            
                            [!IF "(num:i($comma))<(num:i($OutNumChannelInPartition))"!]
                                [!CODE!],[!CR!][!ENDCODE!]
                            [!ELSE!]
                                [!CODE!][!CR!][!ENDCODE!]
                            [!ENDIF!]
                            [!VAR "comma"="$comma + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!ENDFOR!]
            [!CODE!][!CR!]};[!CR!][!CR!][!ENDCODE!]
        [!ENDIF!]
    [!ENDSELECT!]
[!ENDFOR!]

[!FOR "PartitionIdx" = "1" TO "$IcuEcucPartitionRefNum"!]
    [!IF "$IcuEcucPartitionRefCount != 0 "!]
        [!VAR "PartitionIndex" = "node:name(node:value(IcuGeneral/IcuEcucPartitionRef/*[num:i($PartitionIdx)]))"!]
        [!VAR "IcuEcucPartitionRefName" = "node:value(IcuGeneral/IcuEcucPartitionRef/*[num:i($PartitionIdx)])"!]
    [!ENDIF!]
    [!SELECT "IcuConfigSet"!][!//
        [!CALL "ICU_VARIABLES"!]
        
        [!CODE!]const Icu_Ipw_IpConfigType Icu_Ipw_IpConfig_[!"$PBCfg_Variant"!][!IF "$IcuEcucPartitionRefCount != 0 "!]_P_[!"$PartitionIndex"!][!ENDIF!][[!"num:i($OutNumInstancesInPartition)"!]U] =[!CR!]{[!CR!][!ENDCODE!]
      
        [!IF "$OutNumIcuChannelsUsingFtm > 0"!]
            [!FOR "Instance" = "0" TO "num:i(count(ecu:list('Icu.Ftm_Hw_Modules'))) - 1"!]
                [!IF "($IcuEcucPartitionRefCount = 0) and node:exists(IcuFtm/*/IcuFtmModule[contains(., num:i($Instance))])"!]
                    [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief IP type */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]ICU_FTM_MODULE,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief IP instance number */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Ftm HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]&Ftm_Icu_Ip_[!"$Instance"!]_Config_[!"$PBCfg_Variant"!],[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief Pointer to Lpit HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]            
                    [!CODE!][!WS "8"!]/** @brief pointer to Lptmr HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]             
                    [!CODE!][!WS "8"!]/** @brief pointer to Port Ci HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Cmp HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR[!CR!][!ENDCODE!]
                    [!CODE!][!WS "4"!]}[!ENDCODE!]
                    [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                [!ELSE!]
                    [!IF "node:exists(IcuFtm/*/IcuFtmModule[contains(., num:i($Instance))]) and 
                        (node:exists(IcuChannel/*[(node:refs(IcuChannelRef)/../../IcuFtmModule = num:i($Instance)) and
                        (node:value(./IcuChannelEcucPartitionRef/*[1]) = $IcuEcucPartitionRefName)]))"!]
                        [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP type */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]ICU_FTM_MODULE,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance number */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Ftm HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]&Ftm_Icu_Ip_[!"$Instance"!]_Config_[!"$PBCfg_Variant"!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief Pointer to Lpit HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]     
                        [!CODE!][!WS "8"!]/** @brief pointer to Lptmr HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Port Ci HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Cmp HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR[!CR!][!ENDCODE!]
                        [!CODE!][!WS "4"!]}[!ENDCODE!]
                        [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                        [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDIF!]

        [!IF "$OutNumIcuChannelsUsingLptmr > 0"!]
            [!FOR "Instance" = "0" TO "num:i(count(ecu:list('Icu.Lptmr_Hw_Modules'))) - 1"!]
                [!IF "($IcuEcucPartitionRefCount = 0) and node:exists(IcuLptmr/*/IcuLptmrModule[contains(., num:i($Instance))])"!]
                    [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief IP type */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]ICU_LPTMR_MODULE,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief IP instance number */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Ftm HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Lpit HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]     
                    [!CODE!][!WS "8"!]/** @brief pointer to Lptmr HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]&Lptmr_Icu_Ip_[!"$Instance"!]_Config_[!"$PBCfg_Variant"!],[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Port Ci HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Cmp HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR[!CR!][!ENDCODE!]
                    [!CODE!][!WS "4"!]}[!ENDCODE!]
                    [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                [!ELSE!]
                    [!IF "node:exists(IcuFtm/*/IcuLptmrModule[contains(., num:i($Instance))]) and 
                        (node:exists(IcuChannel/*[(node:refs(IcuChannelRef)/../../IcuLptmrModule = num:i($Instance)) and
                        (node:value(./IcuChannelEcucPartitionRef/*[1]) = $IcuEcucPartitionRefName)]))"!]
                        [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP type */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]ICU_LPTMR_MODULE,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance number */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Ftm HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Lpit HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!] 
                        [!CODE!][!WS "8"!]/** @brief pointer to Lptmr HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]&Lptmr_Icu_Ip_[!"$Instance"!]_Config_[!"$PBCfg_Variant"!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Port Ci HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Cmp HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR[!CR!][!ENDCODE!]
                        [!CODE!][!WS "4"!]}[!ENDCODE!]
                        [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                     [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDIF!]
        
        [!IF "$OutNumIcuChannelsUsingLpit > 0"!]
            [!FOR "Instance" = "0" TO "num:i(count(ecu:list('Icu.Lpit_Hw_Modules'))) - 1"!]
                [!IF "($IcuEcucPartitionRefCount = 0) and node:exists(IcuLpit/*/IcuLpitModule[contains(., num:i($Instance))])"!]
                    [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief IP type. */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]ICU_LPIT_MODULE,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief IP instance number. */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief Pointer to FTM HW configuration of instance. */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]    
                    [!CODE!][!WS "8"!]/** @brief Pointer to LPIT HW configuration of instance. */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]&Lpit_Icu_Ip_[!"$Instance"!]_InstanceConfig_[!"$PBCfg_Variant"!],[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Lptmr HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Port Ci HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Cmp HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR[!CR!][!ENDCODE!]                    
                    [!CODE!][!WS "4"!]}[!ENDCODE!]
                    [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                [!ELSE!]
                    [!IF "node:exists(IcuLpit/*/IcuLpitModule[contains(., num:i($Instance))]) and 
                        (node:exists(IcuChannel/*[(node:refs(IcuChannelRef)/../../IcuLpitModule = num:i($Instance)) and
                        (node:value(./IcuChannelEcucPartitionRef/*[1]) = $IcuEcucPartitionRefName)]))"!]
                        [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP type. */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]ICU_LPIT_MODULE,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance number. */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief Pointer to FTM HW configuration of instance. */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]    
                        [!CODE!][!WS "8"!]/** @brief Pointer to LPIT HW configuration of instance. */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]&Lpit_Icu_Ip_[!"$Instance"!]_InstanceConfig_[!"$PBCfg_Variant"!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Lptmr HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Port Ci HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Cmp HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR[!CR!][!ENDCODE!]
                        [!CODE!][!WS "4"!]}[!ENDCODE!]
                        [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                        [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDIF!]
        
        [!IF "$OutNumIcuChannelsUsingPort > 0"!]
            [!FOR "Instance" = "0" TO "num:i(count(ecu:list('Icu.Port_Hw_Modules'))) - 1"!]
                [!IF "($IcuEcucPartitionRefCount = 0) and node:exists(IcuPort/*/IcuPortModule[contains(., num:i($Instance))])"!]
                    [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief IP type */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]ICU_PORT_CI_MODULE,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief IP instance number */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Ftm Ci HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Lpit HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]                     
                    [!CODE!][!WS "8"!]/** @brief pointer to Lptmr HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]  
                    [!CODE!][!WS "8"!]/** @brief pointer to Port Ci HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]&Port_Ci_Icu_Ip_[!"$Instance"!]_Config_[!"$PBCfg_Variant"!],[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Cmp HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR[!CR!][!ENDCODE!]                    
                    [!CODE!][!WS "4"!]}[!ENDCODE!]
                    [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                [!ELSE!]
                    [!IF "node:exists(IcuPort/*/IcuPortModule[contains(., num:i($Instance))]) and 
                        (node:exists(IcuChannel/*[(node:refs(IcuChannelRef)/../../IcuPortModule = num:i($Instance)) and
                        (node:value(./IcuChannelEcucPartitionRef/*[1]) = $IcuEcucPartitionRefName)]))"!]
                        [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP type */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]ICU_PORT_CI_MODULE,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance number */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Ftm Ci HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Lpit HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Lptmr HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Port Ci HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]&Port_Ci_Icu_Ip_[!"$Instance"!]_Config_[!"$PBCfg_Variant"!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Cmp HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR[!CR!][!ENDCODE!]
                        [!CODE!][!WS "4"!]}[!ENDCODE!]
                        [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                        [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDIF!]
        
        
        [!IF "$OutNumIcuChannelsUsingCmp > 0"!]
            [!FOR "Instance" = "0" TO "num:i(count(ecu:list('Icu.Cmp_Hw_Modules'))) - 1"!]
                [!IF "($IcuEcucPartitionRefCount = 0) and node:exists(IcuLpCmp/*/IcuCmpInstanceNumber[contains(., num:i($Instance))])"!]
                    [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief IP type */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]ICU_CMP_MODULE,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief IP instance number */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Ftm HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]/** @brief pointer to Lpit HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]     
                    [!CODE!][!WS "8"!]/** @brief pointer to Lptmr HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!] 
                    [!CODE!][!WS "8"!]/** @brief pointer to Port Ci HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]  
                    [!CODE!][!WS "8"!]/** @brief pointer to Cmp HW configuration of instance */[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]&Cmp_Ip_[!"$Instance"!]_Config_[!"$PBCfg_Variant"!][!CR!][!ENDCODE!]                    
                    [!CODE!][!WS "4"!]}[!ENDCODE!]
                    [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                [!ELSE!]
                    [!IF "node:exists(IcuFtm/*/IcuCmpInstanceNumber[contains(., num:i($Instance))]) and 
                        (node:exists(IcuChannel/*[(node:refs(IcuChannelRef)/../../IcuCmpInstanceNumber = num:i($Instance)) and
                        (node:value(./IcuChannelEcucPartitionRef/*[1]) = $IcuEcucPartitionRefName)]))"!]
                        [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP type */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]ICU_CMP_MODULE,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance number */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Ftm HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Lpit HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!] 
                        [!CODE!][!WS "8"!]/** @brief pointer to Lptmr HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Port Ci HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief pointer to Cmp HW configuration of instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]&Cmp_Ip_[!"$Instance"!]_Config_[!"$PBCfg_Variant"!][!CR!][!ENDCODE!]
                        [!CODE!][!WS "4"!]}[!ENDCODE!]
                        [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                     [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDIF!]

        [!CODE!][!CR!]};[!CR!][!CR!][!ENDCODE!]
    [!ENDSELECT!]
[!ENDFOR!]

[!ENDNOCODE!]

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]
