/**
*    @file        MemIf_Types.h
*    @version     1.0.1
*
*    @brief       AUTOSAR MemIf - module interface.
*    @details     Stub for MemIf module - contains some typedefs needed by other components.
*                 This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup   MEMIF_TYPES
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : S32K14X
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

#ifndef MEMIF_TYPES_H
#define MEMIF_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           MemIf_Types.h
* @requirements   BSW00374, BSW00379, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#define MEMIF_VENDOR_ID                          43
#define MEMIF_MODULE_ID                          22
#define MEMIF_AR_RELEASE_MAJOR_VERSION           4
#define MEMIF_AR_RELEASE_MINOR_VERSION           4
#define MEMIF_AR_RELEASE_REVISION_VERSION        0
#define MEMIF_SW_MAJOR_VERSION                   1
#define MEMIF_SW_MINOR_VERSION                   0
#define MEMIF_SW_PATCH_VERSION                   1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/
/** 
* @brief            This type denotes the current status of the underlying abstraction module and device driver. 
* @details          It shall be used as the return value of the corresponding driver's "GetStatus" function. 
*
* @pre
* @post
*
* @requirements     MemIf015
* @implements
* @note
*
* @violates 
*/
typedef enum
{
    MEMIF_UNINIT = 0,           /**< @brief The underlying abstraction module or device driver has not been initialized (yet)*/
    MEMIF_IDLE,                 /**< @brief The underlying abstraction module or device driver is currently idle */
    MEMIF_BUSY,                 /**< @brief The underlying abstraction module or device driver is currently busy */
    MEMIF_BUSY_INTERNAL         /**< @brief The underlying abstraction module is busy with internal management operations.
                                            The underlying device driver can be busy or idle */
}MemIf_StatusType;


/** 
* @brief            This type denotes the result of the last job.
* @details          It shall be used as the return value of the job. 
*
* @pre
* @post
*
* @requirements     MemIf016
* @implements
* @note
*
* @violates 
*/
typedef enum
{
    MEMIF_JOB_OK = 0,               /**< @brief The job has been finished succesfully */
    MEMIF_JOB_FAILED,               /**< @brief The job has not been finished succesfully */
    MEMIF_JOB_PENDING,              /**< @brief The job has not yet been finished */
    MEMIF_JOB_CANCELED,             /**< @brief The job has been canceled */
    MEMIF_BLOCK_INCONSISTENT,       /**< @brief The requested block is inconsistent, it may contain corrupted data */
    MEMIF_BLOCK_INVALID             /**< @brief The requested block has been marked as invalid, the requested operation can not be performed */
}MemIf_JobResultType;


/** 
* @brief            This type denotes the operation mode.
* @details          This type denotes the operation mode of the underlying abstraction modules and device drivers. 
*
* @pre
* @post
*
* @requirements     MemIf021
* @implements
* @note
*
* @violates 
*/
typedef enum
{
    MEMIF_MODE_SLOW = 0,        /**< @brief The underlying memory abstraction modules and drivers are working in slow mode */
    MEMIF_MODE_FAST             /**< @brief The underlying memory abstraction modules and drivers are working in fast mode */
}MemIf_ModeType;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* MEMIF_TYPES_H */

/** @} */

