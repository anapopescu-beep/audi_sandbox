/**
*   @file    Adc_PBcfg.c
*   @version 1.0.2
*
*   @brief   AUTOSAR Adc - Post Build configuration Adc source file.
*   @details Post Build configuration file for Adc driver.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ADC12BSARV2
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.2
*   Build Version        : S32K14xS32K14X_MCAL_1_0_2_RTM_ASR_REL_4_2_REV_0002_20190426
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2019 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_TDK_4G_PBcfg_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include'
* This is an Autosar memory management requirement.
*
* @section Adc_TDK_4G_PBcfg_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Adc_TDK_4G_PBcfg_C_REF_3
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_TDK_4G_PBcfg_C_REF_4
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_TDK_4G_PBcfg_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions 
* at file scope shall have internal linkage unless external linkage is required.
* This violation is due to Autosar files and structures definitions.
*
* @section Adc_TDK_4G_PBcfg_C_REF_6
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared
* in one and only one file.
* These notifications are declared as external in each variant configuration file.
* 
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. All compilers used support more than 31 chars for
* identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc.h"
/**  @violates @ref Adc_TDK_4G_PBcfg_C_REF_4 Repeated include file */
#include "Adc_Reg_eSys_Adc12bsarv2.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_PBCFG_C                    43
/**
* @violates @ref Adc_TDK_4G_PBcfg_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MAJOR_VERSION_PBCFG_C     4
/**
* @violates @ref Adc_TDK_4G_PBcfg_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_ERLEASE_MINOR_VERSION_PBCFG_C     2
/**
* @violates @ref Adc_TDK_4G_PBcfg_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_REVISION_VERSION_PBCFG_C  2
#define ADC_SW_MAJOR_VERSION_PBCFG_C             1
#define ADC_SW_MINOR_VERSION_PBCFG_C             0
#define ADC_SW_PATCH_VERSION_PBCFG_C             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC header file are of the same vendor */
#if (ADC_VENDOR_ID_PBCFG_C != ADC_VENDOR_ID)
    #error "Adc_PBcfg.c and Adc.h have different vendor ids"
#endif

/* Check if source file and ADC header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_PBCFG_C != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_ERLEASE_MINOR_VERSION_PBCFG_C != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_PBCFG_C != ADC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_PBcfg.c and Adc.h are different"
#endif

/* Check if source file and ADC header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_PBCFG_C != ADC_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_PBCFG_C != ADC_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_PBCFG_C != ADC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_PBcfg.c and Adc.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Adc12bsarv2 header file are of the same vendor */
#if (ADC_VENDOR_ID_PBCFG_C != ADC_VENDOR_ID_REG)
    #error "Adc_PBcfg.c and Adc_Reg_eSys_Adc12bsarv2.h have different vendor ids"
#endif

/* Check if source file and Adc_Reg_eSys_Adc12bsarv2 header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_PBCFG_C != ADC_AR_RELEASE_MAJOR_VERSION_REG) || \
     (ADC_AR_ERLEASE_MINOR_VERSION_PBCFG_C != ADC_AR_RELEASE_MINOR_VERSION_REG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_PBCFG_C != ADC_AR_RELEASE_REVISION_VERSION_REG) \
    )
    #error "AutoSar Version Numbers of Adc_PBcfg.c and Adc_Reg_eSys_Adc12bsarv2.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Adc12bsarv2 header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_PBCFG_C != ADC_SW_MAJOR_VERSION_REG) || \
     (ADC_SW_MINOR_VERSION_PBCFG_C != ADC_SW_MINOR_VERSION_REG) || \
     (ADC_SW_PATCH_VERSION_PBCFG_C != ADC_SW_PATCH_VERSION_REG) \
    )
    #error "Software Version Numbers of Adc_PBcfg.c and Adc_Reg_eSys_Adc12bsarv2.h are different"
#endif
/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/

/** 
* @brief           Number of channels configured for each group.
*/

#define ADC_CFGSET_TDK_4G_GROUP_0_CHANNELS      12
#define ADC_CFGSET_TDK_4G_GROUP_1_CHANNELS      15
#define ADC_CFGSET_TDK_4G_GROUP_2_CHANNELS      2
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/**
* @brief          Total number of groups in Config.
*
*/
#define ADC_GROUPS_TDK_4G           3


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
/**
 * @violates @ref Adc_TDK_4G_PBcfg_C_REF_1 only preprocessor statements and comments before "#include"
 * @violates @ref Adc_TDK_4G_PBcfg_C_REF_2 Repeated include file Memmap.h
 */
#include "Adc_MemMap.h"

/**
* @brief         ADC Notification functions.
* @details       ADC Notification functions defined inside the Plugin.
*
*/





#define ADC_STOP_SEC_CODE
/**
 * @violates @ref Adc_TDK_4G_PBcfg_C_REF_1 only preprocessor statements and comments before "#include"
 * @violates @ref Adc_TDK_4G_PBcfg_C_REF_2 Repeated include file Memmap.h
 */
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/**
* @violates @ref Adc_TDK_4G_PBcfg_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Adc_TDK_4G_PBcfg_C_REF_1 only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_TDK_4G_PBcfg_C_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

/**
* @brief          Group 0 Assignments on ADC Hardware unit 0 TDK_4G.
*
*/
static CONST(Adc_ChannelType, ADC_CONST) Adc_Group0_Assignment_0_TDK_4G[ADC_CFGSET_TDK_4G_GROUP_0_CHANNELS] =
{
    6U,
    7U,
    2U,
    3U,
    0U,
    1U,
    4U,
    5U,
    6U,
    7U,
    6U,
    7U
};
/**
* @brief          Group 2 Assignments on ADC Hardware unit 0 TDK_4G.
*
*/
static CONST(Adc_ChannelType, ADC_CONST) Adc_Group2_Assignment_0_TDK_4G[ADC_CFGSET_TDK_4G_GROUP_2_CHANNELS] =
{
    2U,
    3U
};
/**
* @brief          Group 1 Assignments on ADC Hardware unit 1 TDK_4G.
*
*/
static CONST(Adc_ChannelType, ADC_CONST) Adc_Group1_Assignment_1_TDK_4G[ADC_CFGSET_TDK_4G_GROUP_1_CHANNELS] =
{
    0U,
    1U,
    2U,
    3U,
    4U,
    5U,
    6U,
    0U,
    1U,
    2U,
    3U,
    0U,
    1U,
    2U,
    3U
};


/**
* @brief          Group Channel Delays on ADC Hardware unit 0.
*
*/
static CONST(uint16, ADC_CONST) Adc_Group0_Delays_0_TDK_4G[ADC_CFGSET_TDK_4G_GROUP_0_CHANNELS] =
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
    53780U
};
static CONST(uint16, ADC_CONST) Adc_Group2_Delays_0_TDK_4G[ADC_CFGSET_TDK_4G_GROUP_2_CHANNELS] =
{
    0U,
    400U
};
/**
* @brief          Group Channel Delays on ADC Hardware unit 1.
*
*/
static CONST(uint16, ADC_CONST) Adc_Group1_Delays_1_TDK_4G[ADC_CFGSET_TDK_4G_GROUP_1_CHANNELS] =
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
    54780U
};


/**
* @brief          Definition of ADC Hw units for Configuration variant  TDK_4G.
*/
static CONST(Adc_Adc12bsarv2_HwUnitConfigurationType, ADC_CONST) Adc_HwUnitCfg_TDK_4G[] =
{
    /**< @brief Hardware Unit ADC0 */
    {
        /**< @brief Hardware unit id */
        (Adc_HwUnitType)0,
        /** Main configuration of CFG1 registers */
        /* Clock Divide Select */
        ADC12BSARV2_CFG1_CLOCK_DIV4_U32 |

        /* Conversion Mode Selection */
        ADC12BSARV2_CFG1_10_BITS_RESOLUTION_U32 |
        /* Input Clock Select */
        ADC12BSARV2_CFG1_ALTCLK1_U32,
#if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
        /** Main configuration of CFG2 registers */
        /* Sample time duration */
        (uint32)15U,
#endif /*(STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)*/
        /** Main configuration of SC2 registers */
        ADC12BSARV2_SC2_ADTRG_HW_U32 |
        ADC12BSARV2_SC2_ACFE_DIS_U32 |
        ADC12BSARV2_SC2_ACFGT_LESS_U32 |
        ADC12BSARV2_SC2_ACREN_DIS_U32 |
        ADC12BSARV2_SC2_DMA_DIS_U32 |
        /** Voltage Reference Selection */
        ADC12BSARV2_SC2_REFSEL_VREFH_VREFL_U32,
        /** Main configuration of SC3 registers */
        ADC12BSARV2_SC3_CAL_DIS_U32 |
        ADC12BSARV2_SC3_ONESHOT_U32 |
        ADC12BSARV2_SC3_AVGE_DIS_U32 |
        /** Hardware average select */
        ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32,
#if (STD_ON == ADC_DUAL_CLOCK_MODE)
        /** Alternate configuration of CFG1 registers */
        (uint32)0U,
#if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
        /** Alternate configuration of CFG2 registers */
        /* Sample time duration */
        (uint32)0U,
#endif /*(STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)*/
        /** Alternate configuration of SC2 registers */
        (uint32)0U,
#if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
        /** Alternate configuration of SC3 registers */
        (uint32)0U,
#endif /*(STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)*/
#endif /* (STD_ON == ADC_DUAL_CLOCK_MODE) */
        /** ===== OFS register ===== */
        0U,
        /** ===== Bitmask for converted data ===== */
        ADC12BSARV2_RESULT_DATA_MASK_10_BIT_U32,
        /** ===== Adc bit resolution ===== */
        ADC_BITS_RESOLUTION_10_U8,
        /** ===== PDB Clock Settings ===== */
        ((0UL << 12U) | 
        (0UL << 2U)) |         0x0UL
#if (defined(ADC_UNIT_0_PDB_ERR_ISR_USED) || defined(ADC_UNIT_1_PDB_ERR_ISR_USED))
        ,
        /**< @brief Pdb error notification function */

        NULL_PTR
#endif /* (defined(ADC_UNIT_0_PDB_ERR_ISR_USED) || defined(ADC_UNIT_1_PDB_ERR_ISR_USED)) */
    },    /**< @brief Hardware Unit ADC1 */
    {
        /**< @brief Hardware unit id */
        (Adc_HwUnitType)1,
        /** Main configuration of CFG1 registers */
        /* Clock Divide Select */
        ADC12BSARV2_CFG1_CLOCK_DIV4_U32 |

        /* Conversion Mode Selection */
        ADC12BSARV2_CFG1_10_BITS_RESOLUTION_U32 |
        /* Input Clock Select */
        ADC12BSARV2_CFG1_ALTCLK1_U32,
#if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
        /** Main configuration of CFG2 registers */
        /* Sample time duration */
        (uint32)15U,
#endif /*(STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)*/
        /** Main configuration of SC2 registers */
        ADC12BSARV2_SC2_ADTRG_HW_U32 |
        ADC12BSARV2_SC2_ACFE_DIS_U32 |
        ADC12BSARV2_SC2_ACFGT_LESS_U32 |
        ADC12BSARV2_SC2_ACREN_DIS_U32 |
        ADC12BSARV2_SC2_DMA_DIS_U32 |
        /** Voltage Reference Selection */
        ADC12BSARV2_SC2_REFSEL_VREFH_VREFL_U32,
        /** Main configuration of SC3 registers */
        ADC12BSARV2_SC3_CAL_DIS_U32 |
        ADC12BSARV2_SC3_ONESHOT_U32 |
        ADC12BSARV2_SC3_AVGE_DIS_U32 |
        /** Hardware average select */
        ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32,
#if (STD_ON == ADC_DUAL_CLOCK_MODE)
        /** Alternate configuration of CFG1 registers */
        (uint32)0U,
#if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
        /** Alternate configuration of CFG2 registers */
        /* Sample time duration */
        (uint32)0U,
#endif /*(STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)*/
        /** Alternate configuration of SC2 registers */
        (uint32)0U,
#if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
        /** Alternate configuration of SC3 registers */
        (uint32)0U,
#endif /*(STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)*/
#endif /* (STD_ON == ADC_DUAL_CLOCK_MODE) */
        /** ===== OFS register ===== */
        0U,
        /** ===== Bitmask for converted data ===== */
        ADC12BSARV2_RESULT_DATA_MASK_10_BIT_U32,
        /** ===== Adc bit resolution ===== */
        ADC_BITS_RESOLUTION_10_U8,
        /** ===== PDB Clock Settings ===== */
        ((0UL << 12U) | 
        (0UL << 2U)) |         0x0UL
#if (defined(ADC_UNIT_0_PDB_ERR_ISR_USED) || defined(ADC_UNIT_1_PDB_ERR_ISR_USED))
        ,
        /**< @brief Pdb error notification function */

        NULL_PTR
#endif /* (defined(ADC_UNIT_0_PDB_ERR_ISR_USED) || defined(ADC_UNIT_1_PDB_ERR_ISR_USED)) */
    }};


/**
* @brief          Definition of channels on ADC Hardware unit for configuration variant TDK_4G.
* @details        Array of conversion command messages
*/
static CONST(Adc_Adc12bsarv2_ChannelConfigurationType, ADC_CONST) Adc_ChannelsCfg_0_TDK_4G[] =
{
    /**< @brief Hardware Unit ADC0  --  VREFH */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(29))
    },
    /**< @brief Hardware Unit ADC0  --  VREFL */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(30))
    },
    /**< @brief Hardware Unit ADC0  --  AN_1 */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(1))
    },
    /**< @brief Hardware Unit ADC0  --  AN_0 */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(0))
    },
    /**< @brief Hardware Unit ADC0  --  BAND_GAP */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(27))
    },
    /**< @brief Hardware Unit ADC0  --  MCU_TEMP */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(26))
    },
    /**< @brief Hardware Unit ADC0  --  AN_2 */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(2))
    },
    /**< @brief Hardware Unit ADC0  --  AN_3 */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(3))
    }
};
/**
* @brief          Definition of channels on ADC Hardware unit for configuration variant TDK_4G.
* @details        Array of conversion command messages
*/
static CONST(Adc_Adc12bsarv2_ChannelConfigurationType, ADC_CONST) Adc_ChannelsCfg_1_TDK_4G[] =
{
    /**< @brief Hardware Unit ADC1  --  AN_8 */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(8))
    },
    /**< @brief Hardware Unit ADC1  --  AN_7 */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(7))
    },
    /**< @brief Hardware Unit ADC1  --  AN_6 */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(6))
    },
    /**< @brief Hardware Unit ADC1  --  AN_3 */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(3))
    },
    /**< @brief Hardware Unit ADC1  --  AN_0 */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(0))
    },
    /**< @brief Hardware Unit ADC1  --  AN_4 */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(4))
    },
    /**< @brief Hardware Unit ADC1  --  AN_1 */
    {
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(1))
    }
};


/**
* @violates @ref Adc_TDK_4G_PBcfg_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Adc_TDK_4G_PBcfg_C_REF_1 only preprocessor statements and comments before "#include" */
/**  @violates @ref Adc_TDK_4G_PBcfg_C_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/**
* @violates @ref Adc_TDK_4G_PBcfg_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_TDK_4G_PBcfg_C_REF_1 only preprocessor statements and comments before "#include" */
/**  @violates @ref Adc_TDK_4G_PBcfg_C_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

/**
* @brief          Adc Result Buffer RAM initializations.
* @details        Array for all ADC group result ram buffers.
*/
static P2VAR(Adc_ValueGroupType, ADC_VAR, ADC_APPL_DATA) Adc_aResultsBufferPtr[] =
{
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
};


/**
* @brief          Definition of channels' pointer structure for variant  TDK_4G  Configuration.
*
*/
static P2CONST(Adc_Adc12bsarv2_ChannelConfigurationType, ADC_VAR, ADC_APPL_CONST) Adc_ChannelsCfg_TDK_4G[] =
{
    Adc_ChannelsCfg_0_TDK_4G,
    Adc_ChannelsCfg_1_TDK_4G
};


/**
* @violates @ref Adc_TDK_4G_PBcfg_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_TDK_4G_PBcfg_C_REF_1 only preprocessor statements and comments before "#include" */
/**  @violates @ref Adc_TDK_4G_PBcfg_C_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/**
* @violates @ref Adc_TDK_4G_PBcfg_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Adc_TDK_4G_PBcfg_C_REF_1 only preprocessor statements and comments before "#include" */
/**  @violates @ref Adc_TDK_4G_PBcfg_C_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"



/**
* @brief          Definition of all ADC groups for configuration varaint TDK_4G .
*/
static CONST(Adc_GroupConfigurationType, ADC_CONST) Adc_GroupsCfg_TDK_4G[] =
{
    /**< @brief Group0 -- Hardware Unit ADC0 */
    {
        /**< @brief Hardware unit configured */
        (Adc_HwUnitType)0,
        /**< @brief Access mode */
        ADC_ACCESS_MODE_SINGLE,
        /**< @brief Conversion mode */
        ADC_CONV_MODE_ONESHOT,
        /**< @brief Conversion type */
        ADC_CONV_TYPE_NORMAL,
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        /**< @brief Priority configured */
        ((Adc_GroupPriorityType)(0U)),
#endif
        /**< @brief Replacement mode */
        ADC_GROUP_REPL_ABORT_RESTART,
        /**< @brief Trigger source configured */
        ADC_TRIGG_SRC_SW,
#if (STD_ON==ADC_HW_TRIGGER_API)
        /**< @brief Hardware trigger signal */
        ADC_HW_TRIG_BOTH_EDGES,
        /**< @brief Hardware resource for the group*/
        0U,
#endif /* (STD_ON==ADC_HW_TRIGGER_API) */
#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
        /**< @brief Notification function */

        NULL_PTR,
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /**< @brief Extra notification function */

        NULL_PTR,
#endif
        /**< @brief ADC Group Result Buffers RAM array */
        Adc_aResultsBufferPtr,
        /**< @brief Group Streaming Buffer Mode */
        ADC_STREAM_BUFFER_LINEAR,
        /**< @brief Number of streaming samples */
        ((Adc_StreamNumSampleType)(1)),
        /**< @brief Channels assigned to the group*/
        Adc_Group0_Assignment_0_TDK_4G,
        /**< @brief Channel Delays assigned to the group*/
        Adc_Group0_Delays_0_TDK_4G,
        /**< @brief Number of channels in the group*/
        (Adc_ChannelIndexType)ADC_CFGSET_TDK_4G_GROUP_0_CHANNELS,
#if (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE)
         /* Group Normal Conversion Timings */
        (uint32)15UL,
        (uint32)(ADC12BSARV2_SC3_AVGE_DIS_U32 | ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32),
        (uint32)ADC12BSARV2_CFG1_CLOCK_DIV2_U32,
         /* Group Alternate Conversion Timings */
        #if (ADC_DUAL_CLOCK_MODE == STD_ON)
        2UL,
        (uint32)(ADC12BSARV2_SC3_AVGE_DIS_U32 | ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32),
        ADC12BSARV2_CFG1_CLOCK_DIV1_U32,
        #endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE) */
        /**< @brief Enables or Disables the ADC Back to Back configuration for Group channels */  
        (uint8)STD_OFF,
        /**< @brief Enables or Disables the ADC pre-trigger delay configuration for each Group Channel */
        (uint8)STD_ON,
        /**< @brief Enables or Disables the ADC and DMA interrupts */
        (uint8)STD_ON
#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
        ,
        /**< @brief Enables or Disables the ADC double buffering feature */
        (boolean)STD_OFF,
        /**< @brief Enable/disable half interrupt  for group with double bufferring*/
        (boolean)STD_OFF
#endif /* (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING) */
        ,
        (uint16)0
#ifdef ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED
        ,
        (uint16)16000
#endif /* ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        ,
        /**< @brief Enables or disables the usage of limit checking for an ADC group. */
        (boolean)STD_OFF
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
    },
    /**< @brief Group1 -- Hardware Unit ADC1 */
    {
        /**< @brief Hardware unit configured */
        (Adc_HwUnitType)1,
        /**< @brief Access mode */
        ADC_ACCESS_MODE_SINGLE,
        /**< @brief Conversion mode */
        ADC_CONV_MODE_ONESHOT,
        /**< @brief Conversion type */
        ADC_CONV_TYPE_NORMAL,
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        /**< @brief Priority configured */
        ((Adc_GroupPriorityType)(0U)),
#endif
        /**< @brief Replacement mode */
        ADC_GROUP_REPL_ABORT_RESTART,
        /**< @brief Trigger source configured */
        ADC_TRIGG_SRC_SW,
#if (STD_ON==ADC_HW_TRIGGER_API)
        /**< @brief Hardware trigger signal */
        ADC_HW_TRIG_BOTH_EDGES,
        /**< @brief Hardware resource for the group*/
        0U,
#endif /* (STD_ON==ADC_HW_TRIGGER_API) */
#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
        /**< @brief Notification function */

        NULL_PTR,
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /**< @brief Extra notification function */

        NULL_PTR,
#endif
        /**< @brief ADC Group Result Buffers RAM array */
        Adc_aResultsBufferPtr,
        /**< @brief Group Streaming Buffer Mode */
        ADC_STREAM_BUFFER_LINEAR,
        /**< @brief Number of streaming samples */
        ((Adc_StreamNumSampleType)(1)),
        /**< @brief Channels assigned to the group*/
        Adc_Group1_Assignment_1_TDK_4G,
        /**< @brief Channel Delays assigned to the group*/
        Adc_Group1_Delays_1_TDK_4G,
        /**< @brief Number of channels in the group*/
        (Adc_ChannelIndexType)ADC_CFGSET_TDK_4G_GROUP_1_CHANNELS,
#if (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE)
         /* Group Normal Conversion Timings */
        (uint32)15UL,
        (uint32)(ADC12BSARV2_SC3_AVGE_DIS_U32 | ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32),
        (uint32)ADC12BSARV2_CFG1_CLOCK_DIV2_U32,
         /* Group Alternate Conversion Timings */
        #if (ADC_DUAL_CLOCK_MODE == STD_ON)
        2UL,
        (uint32)(ADC12BSARV2_SC3_AVGE_DIS_U32 | ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32),
        ADC12BSARV2_CFG1_CLOCK_DIV1_U32,
        #endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE) */
        /**< @brief Enables or Disables the ADC Back to Back configuration for Group channels */  
        (uint8)STD_OFF,
        /**< @brief Enables or Disables the ADC pre-trigger delay configuration for each Group Channel */
        (uint8)STD_ON,
        /**< @brief Enables or Disables the ADC and DMA interrupts */
        (uint8)STD_ON
#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
        ,
        /**< @brief Enables or Disables the ADC double buffering feature */
        (boolean)STD_OFF,
        /**< @brief Enable/disable half interrupt  for group with double bufferring*/
        (boolean)STD_OFF
#endif /* (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING) */
        ,
        (uint16)0
#ifdef ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED
        ,
        (uint16)65535
#endif /* ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        ,
        /**< @brief Enables or disables the usage of limit checking for an ADC group. */
        (boolean)STD_OFF
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
    },
    /**< @brief Group2 -- Hardware Unit ADC0 */
    {
        /**< @brief Hardware unit configured */
        (Adc_HwUnitType)0,
        /**< @brief Access mode */
        ADC_ACCESS_MODE_SINGLE,
        /**< @brief Conversion mode */
        ADC_CONV_MODE_ONESHOT,
        /**< @brief Conversion type */
        ADC_CONV_TYPE_NORMAL,
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        /**< @brief Priority configured */
        ((Adc_GroupPriorityType)(0U)),
#endif
        /**< @brief Replacement mode */
        ADC_GROUP_REPL_ABORT_RESTART,
        /**< @brief Trigger source configured */
        ADC_TRIGG_SRC_SW,
#if (STD_ON==ADC_HW_TRIGGER_API)
        /**< @brief Hardware trigger signal */
        ADC_HW_TRIG_BOTH_EDGES,
        /**< @brief Hardware resource for the group*/
        0U,
#endif /* (STD_ON==ADC_HW_TRIGGER_API) */
#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
        /**< @brief Notification function */

        NULL_PTR,
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /**< @brief Extra notification function */

        NULL_PTR,
#endif
        /**< @brief ADC Group Result Buffers RAM array */
        Adc_aResultsBufferPtr,
        /**< @brief Group Streaming Buffer Mode */
        ADC_STREAM_BUFFER_LINEAR,
        /**< @brief Number of streaming samples */
        ((Adc_StreamNumSampleType)(1)),
        /**< @brief Channels assigned to the group*/
        Adc_Group2_Assignment_0_TDK_4G,
        /**< @brief Channel Delays assigned to the group*/
        Adc_Group2_Delays_0_TDK_4G,
        /**< @brief Number of channels in the group*/
        (Adc_ChannelIndexType)ADC_CFGSET_TDK_4G_GROUP_2_CHANNELS,
#if (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE)
         /* Group Normal Conversion Timings */
        (uint32)15UL,
        (uint32)(ADC12BSARV2_SC3_AVGE_DIS_U32 | ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32),
        (uint32)ADC12BSARV2_CFG1_CLOCK_DIV2_U32,
         /* Group Alternate Conversion Timings */
        #if (ADC_DUAL_CLOCK_MODE == STD_ON)
        2UL,
        (uint32)(ADC12BSARV2_SC3_AVGE_DIS_U32 | ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32),
        ADC12BSARV2_CFG1_CLOCK_DIV1_U32,
        #endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE) */
        /**< @brief Enables or Disables the ADC Back to Back configuration for Group channels */  
        (uint8)STD_OFF,
        /**< @brief Enables or Disables the ADC pre-trigger delay configuration for each Group Channel */
        (uint8)STD_ON,
        /**< @brief Enables or Disables the ADC and DMA interrupts */
        (uint8)STD_ON
#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
        ,
        /**< @brief Enables or Disables the ADC double buffering feature */
        (boolean)STD_OFF,
        /**< @brief Enable/disable half interrupt  for group with double bufferring*/
        (boolean)STD_OFF
#endif /* (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING) */
        ,
        (uint16)0
#ifdef ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED
        ,
        (uint16)16000
#endif /* ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        ,
        /**< @brief Enables or disables the usage of limit checking for an ADC group. */
        (boolean)STD_OFF
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
    }
};



/**
* @brief          ADC driver Configuration structure TDK_4G.
*/
/** @violates @ref Adc_TDK_4G_PBcfg_C_REF_5 MISRA-C:2004 Rule 8.10: External linkage.*/
CONST(Adc_ConfigType, ADC_CONST) Adc_PBCfgVariantPredefined =
{
    /**< @brief pointer to Hw unit configurations */
    Adc_HwUnitCfg_TDK_4G,
    /**< @brief pointer to group configurations */
    Adc_GroupsCfg_TDK_4G,
    /**< @brief pointer to channel configurations */
    Adc_ChannelsCfg_TDK_4G,
    /**< @brief total number of groups */
    (Adc_GroupType)ADC_GROUPS_TDK_4G,
    /**< @brief Miscellaneous configuration parameters. - Adc_Adc12bsarv2_MultiConfigType */
    {
        {

            ADC_INTERRUPT,

            ADC_INTERRUPT

        },
        /**< @brief number of the maximum groups in the current configuration */
        3U,
        /**< @brief number of the maximum hardware units in the current configuration */
        2U,
        {
            /** The DMA channel number for ADC 0 */
            (uint8)255U,
            /** The DMA channel number for ADC 1 */
            (uint8)255U
        },
#ifdef ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL
#if (STD_ON == ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL)
        {
            /** The DMA channel number for ADC use double bufferring 0 */
            (uint8)255U,
            /** The DMA channel number for ADC use double bufferring 1 */
            (uint8)255U
        },
#endif
#endif
        {
            /**< @brief ADC_UNIT_0 - ON/OFF */
            (uint8)STD_ON,
            /**< @brief ADC_UNIT_1 - ON/OFF */
            (uint8)STD_ON
        },
        {
            0U,
            1U
        }
    }
};


/**
* @violates @ref Adc_TDK_4G_PBcfg_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Adc_TDK_4G_PBcfg_C_REF_1 only preprocessor statements and comments before "#include" */
/**  @violates @ref Adc_TDK_4G_PBcfg_C_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

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

