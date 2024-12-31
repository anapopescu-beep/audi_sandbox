/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,FLEXIO
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
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
**/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcl_Cfg.h"

#if (STD_ON == MCL_DEM_IS_AVAILABLE)
#include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_MCL_CFG_VENDOR_ID_C                     43
#define CDD_MCL_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define CDD_MCL_CFG_AR_RELEASE_MINOR_VERSION_C      4
#define CDD_MCL_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define CDD_MCL_CFG_SW_MAJOR_VERSION_C              1
#define CDD_MCL_CFG_SW_MINOR_VERSION_C              0
#define CDD_MCL_CFG_SW_PATCH_VERSION_C              1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if CDD_Mcl_Cfg.c file and CDD_Mcl_Cfg.h file are of the same vendor */
#if (CDD_MCL_CFG_VENDOR_ID_C != CDD_MCL_CFG_VENDOR_ID)
    #error "CDD_Mcl_Cfg.c and CDD_Mcl_Cfg.h have different vendor ids"
#endif

/* Check if CDD_Mcl_Cfg.c file and CDD_Mcl_Cfg.h file are of the same Autosar version */
#if ((CDD_MCL_CFG_AR_RELEASE_MAJOR_VERSION_C != CDD_MCL_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_AR_RELEASE_MINOR_VERSION_C != CDD_MCL_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_MCL_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg.c and CDD_Mcl_Cfg.h are different"
#endif

/* Check if CDD_Mcl_Cfg.c file and CDD_Mcl_Cfg.h file are of the same Software version */
#if ((CDD_MCL_CFG_SW_MAJOR_VERSION_C != CDD_MCL_CFG_SW_MAJOR_VERSION) || \
     (CDD_MCL_CFG_SW_MINOR_VERSION_C != CDD_MCL_CFG_SW_MINOR_VERSION) || \
     (CDD_MCL_CFG_SW_PATCH_VERSION_C != CDD_MCL_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl_Cfg.c and CDD_Mcl_Cfg.h are different"
#endif

#if (STD_ON == MCL_DEM_IS_AVAILABLE)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if CDD_Mcl_Cfg.c file and Dem header file are of the same Autosar version */
#if ((CDD_MCL_CFG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Mcl_Cfg.c and Dem.h are different"
#endif
#endif
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
[!IF "node:value(./MclGeneral/MclEnableDemReportErrorStatus)"!][!//
#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Mcl_MemMap.h"

[!NOCODE!]
    [!VAR "MclDemEventParameter"!]MCL_E_TIMEOUT_FAILURE[!ENDVAR!]
    [!VAR "DemErrorCount" = "num:i(count(text:split($MclDemEventParameter, ',')))"!]
[!CODE!]
/**
* @brief        DEM error reporting configuration
* @details      Set the state and id for Mcal_DemErrorType.
*/
const Mcl_DemConfigType Mcl_Dem_Config =
{
[!ENDCODE!]
    [!FOR "Index" = "1" TO "num:i($DemErrorCount)"!]
        [!VAR "ErrorName" = "normalize-space(text:split($MclDemEventParameter, ',')[num:i($Index)])"!]
        [!IF "node:exists(MclConfig/MclDemEventParameterRefs)"!]
            [!VAR "DemRefNode" = "concat('MclConfig/MclDemEventParameterRefs/',$ErrorName)"!]
            [!IF "node:exists($DemRefNode)"!]
                [!IF "node:refvalid($DemRefNode)"!]
[!CODE!]
    /* DEM error reporting [!"$ErrorName"!] */
    {(uint32)STD_ON, DemConf_DemEventParameter_[!"node:ref(node:value($DemRefNode))/@name"!]}[!IF "$Index < $DemErrorCount"!],[!ENDIF!]
[!ENDCODE!]
                [!ELSE!]
                     [!ERROR "Invalid reference for $ErrorName"!]
                [!ENDIF!]
            [!ELSE!]
[!CODE!]
    /* DEM error reporting [!"$ErrorName"!] */
    {(uint32)STD_OFF, 0U}[!IF "$Index < $DemErrorCount"!],[!ENDIF!]
[!ENDCODE!]
            [!ENDIF!]
        [!ELSE!]
[!CODE!]
    /* DEM error reporting [!"$ErrorName"!] */
    {(uint32)STD_OFF, 0U}[!IF "$Index < $DemErrorCount"!],[!ENDIF!]
[!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!]
};
[!ENDCODE!]
[!ENDNOCODE!]

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Mcl_MemMap.h"
[!ENDIF!][!//

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

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
