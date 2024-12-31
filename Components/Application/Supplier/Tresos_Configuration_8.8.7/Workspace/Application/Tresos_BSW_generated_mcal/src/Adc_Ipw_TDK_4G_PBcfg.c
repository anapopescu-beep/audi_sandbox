/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ADC
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
*   @file
*
*   @addtogroup adc_ipw_config Adc Ipw Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Adc_Ipw_CfgDefines.h"
#include "Adc_Ipw_TDK_4G_PBcfg.h"
#include "Adc_Ip_TDK_4G_PBcfg.h"
#include "Pdb_Adc_Ip_TDK_4G_PBcfg.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ADC_IPW_VENDOR_ID_TDK_4G_PBCFG_C                      43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_TDK_4G_PBCFG_C       4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_TDK_4G_PBCFG_C       4
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_TDK_4G_PBCFG_C    0
#define ADC_IPW_SW_MAJOR_VERSION_TDK_4G_PBCFG_C               1
#define ADC_IPW_SW_MINOR_VERSION_TDK_4G_PBCFG_C               0
#define ADC_IPW_SW_PATCH_VERSION_TDK_4G_PBCFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if Adc_Ipw_TDK_4G_PBcfg.c file and Adc_Ipw_CfgDefines.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TDK_4G_PBCFG_C != ADC_IPW_VENDOR_ID_CFGDEFINES)
    #error "Adc_Ipw_TDK_4G_PBcfg.c and Adc_Ipw_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Ipw_TDK_4G_PBcfg.c file and Adc_Ipw_CfgDefines.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TDK_4G_PBCFG_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TDK_4G_PBCFG_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TDK_4G_PBCFG_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_TDK_4G_PBcfg.c and Adc_Ipw_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_TDK_4G_PBcfg.c file and Adc_Ipw_CfgDefines.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TDK_4G_PBCFG_C != ADC_IPW_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_MINOR_VERSION_TDK_4G_PBCFG_C != ADC_IPW_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_PATCH_VERSION_TDK_4G_PBCFG_C != ADC_IPW_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Ipw_TDK_4G_PBcfg.c and Adc_Ipw_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_TDK_4G_PBcfg.c file and Adc_Ipw_TDK_4G_PBcfg.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TDK_4G_PBCFG_C != ADC_IPW_VENDOR_ID_TDK_4G_PBCFG)
    #error "Adc_Ipw_TDK_4G_PBcfg.c and Adc_Ipw_TDK_4G_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Ipw_TDK_4G_PBcfg.c file and Adc_Ipw_TDK_4G_PBcfg.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TDK_4G_PBCFG_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_TDK_4G_PBCFG) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TDK_4G_PBCFG_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_TDK_4G_PBCFG) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TDK_4G_PBCFG_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_TDK_4G_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_TDK_4G_PBcfg.c and Adc_Ipw_TDK_4G_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_TDK_4G_PBcfg.c file and Adc_Ipw_TDK_4G_PBcfg.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TDK_4G_PBCFG_C != ADC_IPW_SW_MAJOR_VERSION_TDK_4G_PBCFG) || \
     (ADC_IPW_SW_MINOR_VERSION_TDK_4G_PBCFG_C != ADC_IPW_SW_MINOR_VERSION_TDK_4G_PBCFG) || \
     (ADC_IPW_SW_PATCH_VERSION_TDK_4G_PBCFG_C != ADC_IPW_SW_PATCH_VERSION_TDK_4G_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Ipw_TDK_4G_PBcfg.c and Adc_Ipw_TDK_4G_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_TDK_4G_PBcfg.c file and Adc_Ip_TDK_4G_PBcfg.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TDK_4G_PBCFG_C != ADC_IP_VENDOR_ID_TDK_4G_PBCFG)
    #error "Adc_Ipw_TDK_4G_PBcfg.c and Adc_Ip_TDK_4G_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Ipw_TDK_4G_PBcfg.c file and Adc_Ip_TDK_4G_PBcfg.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TDK_4G_PBCFG_C != ADC_IP_AR_RELEASE_MAJOR_VERSION_TDK_4G_PBCFG) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TDK_4G_PBCFG_C != ADC_IP_AR_RELEASE_MINOR_VERSION_TDK_4G_PBCFG) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TDK_4G_PBCFG_C != ADC_IP_AR_RELEASE_REVISION_VERSION_TDK_4G_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_TDK_4G_PBcfg.c and Adc_Ip_TDK_4G_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_TDK_4G_PBcfg.c file and Adc_Ip_TDK_4G_PBcfg.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TDK_4G_PBCFG_C != ADC_IP_SW_MAJOR_VERSION_TDK_4G_PBCFG) || \
     (ADC_IPW_SW_MINOR_VERSION_TDK_4G_PBCFG_C != ADC_IP_SW_MINOR_VERSION_TDK_4G_PBCFG) || \
     (ADC_IPW_SW_PATCH_VERSION_TDK_4G_PBCFG_C != ADC_IP_SW_PATCH_VERSION_TDK_4G_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Ipw_TDK_4G_PBcfg.c and Adc_Ip_TDK_4G_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_TDK_4G_PBcfg.c file and Pdb_Adc_Ip_TDK_4G_PBcfg.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TDK_4G_PBCFG_C != PDB_ADC_IP_VENDOR_ID_TDK_4G_PBCFG)
    #error "Adc_Ipw_TDK_4G_PBcfg.c and Pdb_Adc_Ip_TDK_4G_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Ipw_TDK_4G_PBcfg.c file and Pdb_Adc_Ip_TDK_4G_PBcfg.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TDK_4G_PBCFG_C != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_TDK_4G_PBCFG) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TDK_4G_PBCFG_C != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_TDK_4G_PBCFG) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TDK_4G_PBCFG_C != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_TDK_4G_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_TDK_4G_PBcfg.c and Pdb_Adc_Ip_TDK_4G_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_TDK_4G_PBcfg.c file and Pdb_Adc_Ip_TDK_4G_PBcfg.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TDK_4G_PBCFG_C != PDB_ADC_IP_SW_MAJOR_VERSION_TDK_4G_PBCFG) || \
     (ADC_IPW_SW_MINOR_VERSION_TDK_4G_PBCFG_C != PDB_ADC_IP_SW_MINOR_VERSION_TDK_4G_PBCFG) || \
     (ADC_IPW_SW_PATCH_VERSION_TDK_4G_PBCFG_C != PDB_ADC_IP_SW_PATCH_VERSION_TDK_4G_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Ipw_TDK_4G_PBcfg.c and Pdb_Adc_Ip_TDK_4G_PBcfg.h are different"
#endif


/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONFIG_DATA_16
#include "Adc_MemMap.h"
/**
* @brief          Group Channel Delays for configuration variant TDK_4G.
*
*/
static const uint16 Adc_GroupChannelDelays0_TDK_4G[] =
{
    0U,
    500U,
    1000U,
    1500U,
    2000U,
    2500U,
    3000U,
    3500U,
    26640U,
    27140U,
    53280U,
    53780U,
};
static const uint16 Adc_GroupChannelDelays1_TDK_4G[] =
{
    0U,
    500U,
    1000U,
    1500U,
    2000U,
    2500U,
    3000U,
    26640U,
    27140U,
    27640U,
    28140U,
    53280U,
    53780U,
    54280U,
    54780U,
};
static const uint16 Adc_GroupChannelDelays2_TDK_4G[] =
{
    0U,
    400U,
};

#define ADC_STOP_SEC_CONFIG_DATA_16
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
* @brief          Adc Ipw Config configuration variant TDK_4G.
*/
const Adc_Ipw_Config AdcIpwCfg_TDK_4G =
{
    { &AdcIpConfig_0_TDK_4G, &AdcIpConfig_1_TDK_4G }, /* AdcConfigPtrArr */
    { &PdbAdcIpConfig_0_TDK_4G, &PdbAdcIpConfig_1_TDK_4G }, /* PdbConfig */
    { 0U, 1U }, /* AdcPhysicalIdArr */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    { NULL_PTR, NULL_PTR }, /* AdcAltClockConfig */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    { NULL_PTR, NULL_PTR }, /* ChannelLimitCheckingConfigs */
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    /* Mapping */
    {
        { ADC_INTERRUPT, ADC_INTERRUPT }, /* AdcDmaInterruptSoftware */
        /**< @brief number of groups per hw unit > */
        { 2U, 1U }, /* AdcGroups */
        /**< @brief number of channels per hw unit > */
        { 8U, 7U }, /* AdcChannels */
        { ADC_IPW_INVALID_DMA_CHANNEL_ID, ADC_IPW_INVALID_DMA_CHANNEL_ID }, /* AdcDmaChannelLogicId */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        { ADC_IPW_INVALID_DMA_CHANNEL_ID, ADC_IPW_INVALID_DMA_CHANNEL_ID }, /* AdcCountingDmaChanLogicId */
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        { STD_ON, STD_ON }, /* AdcHwUnitArr */
        { 0U, 1U } /* HwLogicalId */
    }
};

/**
* @brief          ADC Ipw Group 0 Config TDK_4G.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_0_TDK_4G =
{
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelect */
    16U, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
    ADC_IP_DEFAULT_SAMPLE_TIME, /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    0U, /* PdbPeriod */
    0U, /* PdbDelay */
    (boolean)FALSE, /* AdcGroupEnableBackToBack */
    (boolean)TRUE, /* AdcGroupEnableChannelDelays */
    Adc_GroupChannelDelays0_TDK_4G /* DelayPtr */
};

/**
* @brief          ADC Ipw Group 1 Config TDK_4G.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_1_TDK_4G =
{
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelect */
    16U, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
    ADC_IP_DEFAULT_SAMPLE_TIME, /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    0U, /* PdbPeriod */
    0U, /* PdbDelay */
    (boolean)FALSE, /* AdcGroupEnableBackToBack */
    (boolean)TRUE, /* AdcGroupEnableChannelDelays */
    Adc_GroupChannelDelays1_TDK_4G /* DelayPtr */
};

/**
* @brief          ADC Ipw Group 2 Config TDK_4G.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_2_TDK_4G =
{
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelect */
    16U, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
    ADC_IP_DEFAULT_SAMPLE_TIME, /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    0U, /* PdbPeriod */
    0U, /* PdbDelay */
    (boolean)FALSE, /* AdcGroupEnableBackToBack */
    (boolean)TRUE, /* AdcGroupEnableChannelDelays */
    Adc_GroupChannelDelays2_TDK_4G /* DelayPtr */
};


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

