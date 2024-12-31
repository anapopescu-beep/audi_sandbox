/*==================================================================================================
* Project              : RTD AUTOSAR 4.4
* Platform             : CORTEXM
* Peripheral           : none
* Dependencies         : Fls
*
* Autosar Version      : 4.4.0
* Autosar Revision     : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version           : 1.0.1
* Build Version        : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
*
* (c) Copyright 2020-2022 NXP Semiconductors
* All Rights Reserved.
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef FEE_CBK_H
#define FEE_CBK_H

/**
*   @file
*
*   @addtogroup FEE
*   @{
*/
/*   @implements Fee_Cbk.h_Artifact*/
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

#define FEE_CBK_VENDOR_ID                       43
#define FEE_CBK_AR_RELEASE_MAJOR_VERSION        4
#define FEE_CBK_AR_RELEASE_MINOR_VERSION        4
#define FEE_CBK_AR_RELEASE_REVISION_VERSION     0
#define FEE_CBK_SW_MAJOR_VERSION                1
#define FEE_CBK_SW_MINOR_VERSION                0
#define FEE_CBK_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

extern void Fee_JobEndNotification(void);
extern void Fee_JobErrorNotification(void);

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _FEE_CBK_H_ */
