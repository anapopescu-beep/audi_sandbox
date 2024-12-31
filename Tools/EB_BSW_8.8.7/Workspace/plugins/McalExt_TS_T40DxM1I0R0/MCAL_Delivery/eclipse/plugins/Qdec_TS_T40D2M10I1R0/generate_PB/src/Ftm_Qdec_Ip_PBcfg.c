[!AUTOSPACING!]
[!NOCODE!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "VS_number" = "concat('_',$postBuildVariant)"!]
    [!ELSE!]
        [!VAR "VS_number" = "''"!]
    [!ENDIF!]
[!ENDNOCODE!]
[!CODE!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm
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
 *   @file       Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg.c
 *
 *   @brief      Qdec - contains information about IP PB configuration.
 *   @details    
 *
 *   @addtogroup ftm_qdec_ip Qdec IPL
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

#include "Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/

#define FTM_QDEC_IP[!"$VS_number"!]_PBCFG_VENDOR_ID_C                       43
#define FTM_QDEC_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define FTM_QDEC_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C        4
#define FTM_QDEC_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C     0
#define FTM_QDEC_IP[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION_C                1
#define FTM_QDEC_IP[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION_C                0
#define FTM_QDEC_IP[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION_C                1

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/

/* Check if source file and Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg header file are of the same vendor */
#if (FTM_QDEC_IP[!"$VS_number"!]_PBCFG_VENDOR_ID_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_VENDOR_ID)
    #error "Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg.c and Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg.h have different vendor IDs"
#endif
/* Check if source file and Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg header file are of the same AutoSar version */
#if ((FTM_QDEC_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_QDEC_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (FTM_QDEC_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg.c and Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg.h are different"
#endif
/* Check if source file and Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg header file are of the same Software version */
#if ((FTM_QDEC_IP[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION) || \
     (FTM_QDEC_IP[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION) || \
     (FTM_QDEC_IP[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg.c and Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg.h are different"
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
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

[!IF "QdecGeneral/QdecOverFlowNotificationSupported"!]
#define QDEC_START_SEC_CODE
#include "Qdec_MemMap.h"

/** @brief Signature of report events interrupt function. */
extern void Qdec_ReportEvents(uint8 HwInstance);

#define QDEC_STOP_SEC_CODE
#include "Qdec_MemMap.h"
[!ENDIF!]

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/


#define QDEC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Qdec_MemMap.h"

/**
* @brief    Configurations for QDEC modules which use FTM
*/

[!VAR "NumberOfFtmUsed" = "0"!]
[!LOOP "QdecInstanceConfig/*"!]
    [!IF "text:split(QdecFtmModule,'_')[1] = 'FTM'"!]
        [!VAR "NumberOfFtmUsed"="$NumberOfFtmUsed + 1"!]
    [!ENDIF!]
[!ENDLOOP!]
    
const Ftm_Qdec_Ip_ConfigType Ftm_Qdec_Ip_InstanceConfig[!"$VS_number"!][[!"num:i($NumberOfFtmUsed)"!]U] = 
{
    [!VAR "Comma" = "1"!]
    [!LOOP "QdecInstanceConfig/*"!]
        [!IF "text:split(QdecFtmModule,'_')[1] = 'FTM'"!]
        [!NOCODE!]
            /* Get hw information: clock source */
            [!IF "(node:exists('QdecFtmClockSource'))"!]
                [!IF "node:value(QdecFtmClockSource) = 'SYSTEM_CLOCK'"!]
                    [!VAR "SourceClock" = "'((uint8)(FTM_CLOCK_SOURCE_SYSTEMCLK) << QDEC_FTM_CLOCK_SOURCE_SHIFT)'"!]
                    [!VAR "QdecFtmClockSourceValue" = "'FTM_CLOCK_SOURCE_SYSTEMCLK'"!]
                [!ELSEIF "node:value(QdecFtmClockSource) = 'EXTERNAL_CLOCK'"!]
                    [!VAR "SourceClock" = "'((uint8)(FTM_CLOCK_SOURCE_EXTERNALCLK) << QDEC_FTM_CLOCK_SOURCE_SHIFT)'"!]
                    [!VAR "QdecFtmClockSourceValue" = "'FTM_CLOCK_SOURCE_EXTERNALCLK'"!]
                [!ELSE!]
                    [!VAR "SourceClock" = "'((uint8)(FTM_CLOCK_SOURCE_FIXEDCLK) << QDEC_FTM_CLOCK_SOURCE_SHIFT)'"!]
                    [!VAR "QdecFtmClockSourceValue" = "'FTM_CLOCK_SOURCE_FIXEDCLK'"!]
                [!ENDIF!]
            [!ELSE!]
                [!VAR "SourceClock" = "'((uint8)(FTM_CLOCK_SOURCE_SYSTEMCLK) << QDEC_FTM_CLOCK_SOURCE_SHIFT)'"!]
                [!VAR "QdecFtmClockSourceValue" = "'FTM_CLOCK_SOURCE_SYSTEMCLK'"!]
            [!ENDIF!]

            /* Get hw information: prescaler */
            [!IF "(node:exists('QdecFtmPrescaler'))"!]
                [!VAR "Prescaler" = "node:value(QdecFtmPrescaler)"!]
            [!ELSE!]
                [!VAR "Prescaler" = "'DIV1'"!]
            [!ENDIF!]

            [!VAR "Prescaler" = "concat('FTM_SC_PS_', $Prescaler,'_U32')"!]
            [!VAR "Prescaler" = "concat('(uint8)((uint32)(', $Prescaler, ') << QDEC_FTM_CLOCK_DIV_SHIFT)')"!]

            /* Get hw information: alternate prescaler */
            [!IF "(node:exists('QdecFtmPrescale_Alternate'))"!]
                [!VAR "AltPrescaler" = "QdecFtmPrescale_Alternate"!]
            [!ELSE!]
                [!VAR "AltPrescaler" = "'DIV1'"!]
            [!ENDIF!]

            [!VAR "AltPrescaler" = "concat('FTM_SC_PS_', $AltPrescaler,'_U32')"!]
            [!VAR "AltPrescaler" = "concat('(uint8)((uint32)(', $AltPrescaler, ') << QDEC_FTM_ALT_CLOCK_DIV_SHIFT)')"!]
        [!ENDNOCODE!]
    /* [!"@name"!] -> [!"QdecFtmModule"!] */
    {
        (Ftm_Qdec_Ip_EncodingModeType) FTM_[!"node:value(./QdecEncodingMode)"!],    /** @brief Encoding mode used by FTM in the QDEC mode */     
        (uint16) [!"node:value(./QdecMinCounterValue)"!],       /** @brief Minimum counter value */
        (uint16) [!"node:value(./QdecMaxCounterValue)"!],       /** @brief Maximum counter value */
        (boolean)[!"text:toupper(node:value(./QdecEnTofIsr))"!],         /** @brief Timer Overflow Interrupt */
        /** @brief Configuration of input phase A */
        {
            (boolean)[!"text:toupper(node:value(./QdecmEnAPhaseFilter))"!],      /** @brief Enables the filter for the quadrature decoder phase A,B inputs */ 
            (uint8) [!"node:value(./QdecmAPhaseFilterVal)"!],           /** @brief Filter value (if input filter is enabled) */
            (Ftm_Qdec_Ip_PhasePolarityType) FTM_[!"node:value(./QdecmAPhasePolarity)"!]        /** @brief Phase polarity */
        },
        /** @brief Configuration of input phase B */
        {
            (boolean)[!"text:toupper(node:value(./QdecmEnBPhaseFilter))"!],       /** @brief Enables the filter for the quadrature decoder phase A,B inputs */
            (uint8) [!"node:value(./QdecmBPhaseFilterVal)"!],           /** @brief Filter value (if input filter is enabled) */
            (Ftm_Qdec_Ip_PhasePolarityType) FTM_[!"node:value(./QdecmBPhasePolarity)"!]        /** @brief Phase polarity */
        },
        {
        /** @brief Callback function for instances. */
        [!IF "../../QdecGeneral/QdecOverFlowNotificationSupported"!]
        &Qdec_ReportEvents,
        [!ELSE!]
        NULL_PTR,
        [!ENDIF!]
        /** @brief Parameters used by callback function. */
        (uint8)[!"node:value(./QdecHardwareModuleId)"!]U
        },
#if (FTM_QDEC_SET_CLOCK_MODE_API == STD_ON)    
        /** @brief Ftm instance Alternate Prescaler parameters */
        [!"$AltPrescaler"!],
        /** @brief  Ftm Control Value */
        (uint8)
        (
        [!WS "12"!][!"$SourceClock"!] | /* Clock source */
        [!WS "12"!][!"$Prescaler"!]    /* Timer clock prescaler configuration */
        ),
#endif
        (Ftm_Qdec_Ip_ClockSourceType) [!"$QdecFtmClockSourceValue"!]               /** @brief FlexTimer Clock Source */
    }[!IF "(num:i($Comma))<(num:i($NumberOfFtmUsed))"!],[!ENDIF!][!CR!][!VAR "Comma"="$Comma + 1"!]
        [!ENDIF!]
    [!ENDLOOP!]
};

#define QDEC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Qdec_MemMap.h"

/*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]