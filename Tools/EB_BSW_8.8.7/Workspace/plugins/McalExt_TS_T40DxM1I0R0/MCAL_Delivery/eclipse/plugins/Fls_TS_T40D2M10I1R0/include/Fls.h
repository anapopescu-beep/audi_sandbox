/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FTFC_FLS_IP IPV_QSPI
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
/*==================================================================================================
==================================================================================================*/

#ifndef FLS_H
#define FLS_H

/**
*   @file Fls.h
*
*   @addtogroup FLS FLS Driver
*   @{
*/

/* implements Fls.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf.h"
#include "Fls_Cfg.h"
#include "Fls_Api.h"



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID                    43
#define FLS_AR_RELEASE_MAJOR_VERSION     4
#define FLS_AR_RELEASE_MINOR_VERSION     4
#define FLS_AR_RELEASE_REVISION_VERSION  0
#define FLS_SW_MAJOR_VERSION             1
#define FLS_SW_MINOR_VERSION             0
#define FLS_SW_PATCH_VERSION             1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Mcal.h header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls.h and Mcal.h are different"
    #endif
    /* Check if header file and OsIf.h header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls.h and OsIf.h are different"
    #endif
#endif

/* Check if header file and Fls_Cfg.h header file are of the same vendor */
#if (FLS_VENDOR_ID != FLS_VENDOR_ID_CFG)
    #error "Fls.h and Fls_Cfg.h have different vendor ids"
#endif
/* Check if header file and Fls_Cfg.h header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION    != FLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_MINOR_VERSION    != FLS_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_REVISION_VERSION != FLS_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fls.h and Fls_Cfg.h are different"
#endif
/* Check if header file and Fls_Cfg.h header file are of the same software version */
#if ((FLS_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls.h and Fls_Cfg.h are different"
#endif

/* Check if header file and Fls_Api.h header file are of the same vendor */
#if (FLS_VENDOR_ID != FLS_API_VENDOR_ID)
    #error "Fls.h and Fls_Api.h have different vendor ids"
#endif
/* Check if header file and Fls_Api.h header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION    != FLS_API_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION    != FLS_API_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION != FLS_API_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls.h and Fls_Api.h are different"
#endif
/* Check if header file and Fls_Api.h header file are of the same software version */
#if ((FLS_SW_MAJOR_VERSION != FLS_API_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION != FLS_API_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION != FLS_API_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls.h and Fls_Api.h are different"
#endif



/*==================================================================================================
                                          CONSTANTS
==================================================================================================*/
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"
FLS_CONFIG_EXT
#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

/*! Invalid device instance */
#define FLS_DEVICE_INSTANCE_INVALID       (0xFFU)


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#if ( STD_ON == FLS_AC_LOAD_ON_JOB_START )
#define FLS_START_SEC_VAR_CLEARED_BOOLEAN
#include "Fls_MemMap.h"

extern boolean Fls_bACloaded;

#define FLS_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Fls_MemMap.h"
#endif

#define FLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fls_MemMap.h"

/**
 * @brief Logical address of data block currently processed by Fls_MainFunction
 */
extern Fls_AddressType Fls_u32JobAddrIt;
/**
 * @brief Last logical address to be processed by a job
 */
extern Fls_AddressType Fls_u32JobAddrEnd;
/**
 * @brief Index of flash sector currently processed by a job
 * @details Used by all types of job
 */
extern volatile Fls_SectorIndexType Fls_u32JobSectorIt;
/**
 * @brief Index of last flash sector by current job
 * @details Used to check status of all external flash chips before start jobs
 * or is the last sector in Erease job
 */
extern Fls_SectorIndexType Fls_u32JobSectorEnd;
/**
 * @brief Result of last flash hardware job
 */
extern volatile MemIf_JobResultType Fls_eLLDJobResult;
/**
 * @brief Type of current flash hardware job - used for asynchronous operating mode.
 */
extern Fls_LLDJobType Fls_eLLDJob;

/**
 * @brief Pointer to current flash module configuration set
 */
extern const Fls_ConfigType * Fls_pConfigPtr;

#define FLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLS_H */
