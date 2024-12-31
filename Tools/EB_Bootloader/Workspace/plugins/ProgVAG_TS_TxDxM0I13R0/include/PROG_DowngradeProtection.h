
/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               PROG VWAG layer                                 */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_DowngradeProtection.h      */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 0.13.0 BL3 */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/* Copyright 2021 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/

#ifndef PROG_DOWNGRADEPROTECTION_H
#define PROG_DOWNGRADEPROTECTION_H

#include "PROG_VAG_Types.h"

#if PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON
/*============================ PRIVATE DEFINITIONS ==============================*/

/*-------------------------------------------------------------------------------*/
/* - Private Variables                                                           */
/*                                                                               */

/*===============================================================================*/

/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */

/* Pseudo Flash Driver Identification */
#define PROG_DGP_PTI_LENGTH_MIN                         0x01U
#define PROG_DGP_PTI_LENGTH_MAX                         0xFFFFU

/* Define ASCII ranges for validation criteria */
#define PROG_DGP_ASCII_FIRST_PRINTABLE_CHAR             0x20U
#define PROG_DGP_ASCII_LAST_PRINTABLE_CHAR              0x7EU
#define PROG_DGP_ASCII_FIRST_NUMBER                     0x30U
#define PROG_DGP_ASCII_LAST_NUMBER                      0x39U

/* Minimum expected number of blocks */
#define PROG_DGP_MIN_BLOCK_NBR                          0x01U

/* Number of functions checking validation criteria 1 to 4 and 6 */
#define PROG_DGP_VALID_RFS_DRIVER_FCT_NBR               0x04U

/* Routine status */
#define PROG_DGP_ROUTINE_CHECKMEMORY_INVALID_RFS_DRIVER        0x80U
#define PROG_DGP_ROUTINE_CHECKMEMORY_INVALID_RFS_VERSION       0x81U
#define PROG_DGP_ROUTINE_CHECKDEP_MISSING_RFS_DRIVER           0x05U
#define PROG_DGP_ROUTINE_CHECKDEP_INVALID_RFS_VERSION          0x06U

/*                                                                               */
/*===============================================================================*/

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */
/*                                                                               */

/*===============================================================================*/

/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */
/* Declared here to comply MISRA-C:2012 Rule 8.4 */
extern const u8 m_aubTextPTID[PROG_DGP_PTI_LENGTH];
extern const ptValidRfsDriver m_aptValidRfsDriverFct[PROG_DGP_VALID_RFS_DRIVER_FCT_NBR];

/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */

/** \brief API that compares RfsV current against RfsV in the pseudo falsh driver (PFT)
 **
 ** This API is called during erase or request download for a logical block (different from PFT block)
 **
 ** \param[in] ubBlockId index of the logical block
 **
 ** \return Result of the comparison
 ** \retval PROG_E_OK RfsV in the PFT higher or equal to RfsV current
 ** \retval PROG_E_RFS_DRIVER_FAIL the pseudo flash driver is not available
 ** \retval PROG_E_RFS_VERSION_FAIL RfsV in the PFT less than RfsV current
 **/
extern tProgStatus PROG_DowngradeProtection_CheckForEraseAndRD_Impl40(u8 ubBlockId);

/** \brief API that verifies downgrade protection for during check memory
 **        1. Verify the validation criteria if the logical block is the PFT block
 **        2. Compares RfsV in the server (admin table) against RfsV in the pseudo falsh driver (PFT) for a logical block
 **           different than the PFT block
 **
 ** This API is called during check memory execution
 **
 ** \param[in]  ubBlockId index of the logical block
 ** \param[out] ubDgpStatus downgrade verification status
 **
 ** \return Result of the comparison
 ** \retval PROG_E_OK all checks are successful
 ** \retval PROG_E_RFS_DRIVER_FAIL the pseudo flash driver is not available
 ** \retval PROG_E_RFS_VERSION_FAIL at least one check has failed
 **/
extern tProgStatus PROG_DowngradeProtection_CheckForCheckMemory_Impl40(u8 ubBlockId, u8 * ubDgpStatus);

/** \brief API that compares RfsV current versus RfsV in the pseudo falsh driver (PFT) (for all blocks in BVT)
 **        and RfsV current versus RfsV minimum for all blocks in the server
 **
 ** This API is called during check programming dependencies execution
 **
 ** \param[out]  pubRoutineStatus downgrade verification status
 **
 ** \return Result of the comparison
 ** \retval PROG_E_OK all checks are successful
 ** \retval PROG_E_RFS_DRIVER_FAIL the pseudo flash driver is not available
 ** \retval PROG_E_RFS_VERSION_FAIL at least one check has failed
 **/
extern tProgStatus PROG_DowngradeProtection_CompareRfsForCoherencyCheck_Impl40(u8 * pubRoutineStatus);

/** \brief API that invalidate the pseudo flash driver
 **
 ** This API is called at initialization
 ** It allows setting the status of the driver to RFS driver fail
 **
 ** \return void
 **/
extern void PROG_DowngradeProtection_ResetPFTStatus_Impl40(void);

#endif /* PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON */

/*                                                                               */
/*-------------------------------------------------------------------------------*/

#endif /* PROG_DOWNGRADEPROTECTION_H */
