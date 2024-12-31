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
/*%%   _____________________________   %%  \file PROG_DowngradeProtection.c      */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 0.13.0 BL3              */
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
/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 11.3 (required)
 * A cast shall not be performed between a pointer to object type and a pointer to a different
 * object type.
 *
 *   Reason:
 * The memory routines are optimized for dealing with aligned memory
 * and the correct alignment has been checked before converting
 * to different object types
 */
/* NOCOV List
 *
 * NOCOV-EMPTYDEFAULT:
 *   defensive code.
 *
 * Reason:
 * Defensive case which shall never happen.
 *
 */

/*=============================== FILE INCLUSION ================================*/
/*                                                                               */

#include "EB_Prj.h"
#include "PROG_Priv.h"
#include "PROG_Hsm.h"
#include "PROG_HsmPROG.h"
#include "PROG_DowngradeProtectionTrace.h"
#include "PROG_VAG_Cbk.h"
#include "PROG_DowngradeProtection.h"

#if PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON

/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */

/*-------------------------------------------------------------------------------*/
/* - Public Callback Prototypes                                                  */

/*                                                                               */
/*===============================================================================*/

/*============================ PRIVATE DEFINITIONS ==============================*/

/*-------------------------------------------------------------------------------*/
/* - Private Variables                                                           */
/*                                                                               */
/* Content of the pseudo flash driver in ASCII ("RFSV1.0") */
const u8 m_aubTextPTID[PROG_DGP_PTI_LENGTH] = {0x52, 0x46, 0x53, 0x56, 0x31, 0x2E, 0x30};

/* Store pseudo plash driver status */
/* Will be checked at reception of erase routine or request download */
NCS_PRI_VAR tProgStatus m_ePseudoFlashDriverStatus;

NCS_PRI_VAR tProgDowngradeProtectionTable m_stPseudoFlashDriver;

/*===============================================================================*/

/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */

/*                                                                               */
/*===============================================================================*/

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */

/** \brief Check that all fields of the pseudo driver lies within the defined value
 **        ranges
 **
 ** This function is called on the check memory of the pseudo flash driver
 **
 ** \param[in] pstDgpTable pointer to the pseudo flash driver
 **
 ** \return Result of treatment
 ** \retval PROG_TRUE  All fields are in valid range
 ** \retval PROG_FALSE At least one field is outside its defined range
 **
 **/
NCS_PRI_FCT tProgBoolean PROG_DowngradeProtection_CheckValidRanges_Impl40(const tProgDowngradeProtectionTable* pstDowngradeProtectTable);

/** \brief Verify that the pseudo flash driver contains at least one logical block
 **        and every block ID in it occurs only once
 **
 ** This function is called on the check memory of the pseudo flash driver
 **
 ** \param[in] pstDgpTable pointer to the pseudo flash driver
 **
 ** \return Result of treatment
 ** \retval PROG_TRUE  All blocks ID in the PFT occurs exactly once
 ** \retval PROG_FALSE At least one block ID in the PFT occurs more than once
 **
 **/
NCS_PRI_FCT tProgBoolean PROG_DowngradeProtection_CheckUniqueBlockID_Impl40(const tProgDowngradeProtectionTable* pstDowngradeProtectTable);

/** \brief Verify that every block ID in the pseudo flash driver has a correspondance
 **        in the ECU
 **
 ** This function is called on the check memory of the pseudo flash driver
 **
 ** \param[in] pstDgpTable pointer to the pseudo flash driver
 **
 ** \return Result of treatment
 ** \retval PROG_TRUE  All announced blocks have a correspondance in the ECU
 ** \retval PROG_FALSE At least one block ID hasn't a correspondance in the ECU
 **
 **/
NCS_PRI_FCT tProgBoolean PROG_DowngradeProtection_CheckBlockIDCorrespondence_Impl40(const tProgDowngradeProtectionTable* pstDowngradeProtectTable);

/** \brief Verify the compliance with the specification requirements
 **
 ** This function is called on the check memory of the pseudo flash driver
 **
 ** \param[in] pstDgpTable pointer to the pseudo flash driver
 **
 ** \return Result of treatment
 ** \retval PROG_TRUE  Pseudo flash driver is compliant
 ** \retval PROG_FALSE Pseudo flash driver is not compliant
 **
 **/
NCS_PRI_FCT tProgBoolean PROG_DowngradeProtection_CheckPFTCompliance_Impl40(const tProgDowngradeProtectionTable* pstDowngradeProtectTable);

/** \brief Verify that the new Rfs version is higher than the old Rfs version
 **
 ** This function is called at each RFS version number comparison
 **
 ** \param[in] pNewRfsVersion pointer to the new RFS Version number
 ** \param[in] pOldRfsVersion pointer to the old RFS Version number
 **
 ** \return Result of treatment
 ** \retval PROG_TRUE  New Rfs version number is higher or equal to the old one
 ** \retval PROG_FALSE New Rfs version number is less than the old one
 **
 **/
NCS_PRI_FCT tProgBoolean PROG_DowngradeProtection_CompareRfsVersion_Impl40(const u8* pNewRfsVersion, const u8* pOldRfsVersion);

/** \brief API that checks the validation criteria of the pseudo flash driver
 **
 ** This API is called during the check memory of the pseudo flash driver
 **
 ** \return Result of validation criteria verification
 ** \retval PROG_E_OK valid pseudo flash driver
 ** \retval PROG_E_RFS_DRIVER_FAIL Error on the received pseudo flash driver (one
 **         criterion among 1 to 4 or 6 has failed)
 ** \retval PROG_E_RFS_VERSION_FAIL Error on RFS version number (criteria 5 has failed)
 **/
NCS_PRI_FCT tProgStatus PROG_DowngradeProtection_CheckValidationCriteria_Impl40(void);


/** \brief API that compares RfsV in the logical block against RfsV in the pseudo flash driver (PFT)
 **
 ** This API is called during check memory of a logical block (different from PFT block)
 ** If the verification is successful it allows updating the RfsV current with the new value
 **
 ** \param[in] ubLogicalBlock logical block identifier generated by tresos
 **
 ** \return Result of the comparison
 ** \retval PROG_E_OK RfsV in the logical block is exactly the same as the announced in the PFT
 ** \retval PROG_E_RFS_DRIVER_FAIL the pseudo flash driver is not available
 ** \retval PROG_E_RFS_VERSION_FAIL RfsV in the logical block is different from the announced in the PFT
 **/
NCS_PRI_FCT tProgStatus PROG_DowngradeProtection_CompareNewBlockRfsVersusRfsPFT_Impl40(u8 ubLogicalBlock);

/** \brief API that compares RfsV current against RfsV in the pseudo flash driver (PFT)
 **
 ** This API is called during erase or request download for a logical block (different from PFT block)
 **
 ** \param[in] ubLogicalBlock logical block identifier generated by tresos
 **
 ** \return Result of the comparison
 ** \retval PROG_E_OK RfsV in the PFT higher or equal to RfsV current
 ** \retval PROG_E_RFS_DRIVER_FAIL the pseudo flash driver is not available
 ** \retval PROG_E_RFS_VERSION_FAIL RfsV in the PFT less than RfsV current
 **/
NCS_PRI_FCT tProgStatus PROG_DowngradeProtection_CompareCurrentRfsVersusRfsPFT_Impl40(u8 ubLogicalBlock);

/** \brief Check that each character is in the input range
 **
 ** This function is called during flashing process
 **
 ** \param[in] ubInputText pointer to the string
 ** \param[in] uwLength length of the string
 ** \param[in] ubStartValue start value of the range
 ** \param[in] ubEndValue end value of the range
 **
 ** \return Result of treatment
 ** \retval PROG_TRUE  Each character from input string is in the range [ubStartValue, ubEndValue]
 ** \retval PROG_FALSE At least one character from input string is outside the range
 **
 **/
NCS_PRI_FCT tProgBoolean PROG_DowngradeProtection_CheckRangeASCII_Impl40(const u8* ubInputText, u16 uwLength, u8 ubStartValue, u8 ubEndValue);

/** \brief Retrieve the pseudo flash driver from the memory
 **
 ** This function is called during validation criteria verification
 **
 ** \param[out] pstDowngradeProtectTable pointer to pseudo flash driver
 **
 ** \return void
 **
 **/
NCS_PRI_FCT tProgStatus PROG_DowngradeProtection_GetPseudoFlashDriver_Impl40(tProgDowngradeProtectionTable* pstDowngradeProtectTable);

/* Declared here after function declaration */
/* Set of functions for checking validity of RFS driver */
/* Corresponds to verification criteria 1 to 4 and 6    */
const ptValidRfsDriver m_aptValidRfsDriverFct[PROG_DGP_VALID_RFS_DRIVER_FCT_NBR] =
{
    &PROG_DowngradeProtection_CheckValidRanges_Impl40,
    &PROG_DowngradeProtection_CheckUniqueBlockID_Impl40,
    &PROG_DowngradeProtection_CheckBlockIDCorrespondence_Impl40,
    &PROG_DowngradeProtection_CheckPFTCompliance_Impl40,
};

/*===============================================================================*/

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

/*--------------------{PROG_DowngradeProtection_CheckValidRanges_Impl40}----------------------*/
NCS_PRI_FCT tProgBoolean PROG_DowngradeProtection_CheckValidRanges_Impl40(const tProgDowngradeProtectionTable* pstDowngradeProtectTable)
{
    tProgBoolean eProgBoolStatus;
    tProgBoolean eProgRangesValid;
    u8           ubBlockIdx;

    eProgRangesValid = PROG_FALSE;

    /* Check the range of the pseudo flash driver identification (PTI) */
    /* No check performed on the maximum as PROG_DGP_PTI_LENGTH_MAX equal to unsigned 2 bytes (65535) */
    if (pstDowngradeProtectTable->uwPTILength >= PROG_DGP_PTI_LENGTH_MIN)
    {
        /* Check content of the PFT identification is in the range ascii [32, 126] */
        eProgBoolStatus = PROG_DowngradeProtection_CheckRangeASCII_Impl40(pstDowngradeProtectTable->ubPTIDContent,
                                                                          pstDowngradeProtectTable->uwPTILength,
                                                                          PROG_DGP_ASCII_FIRST_PRINTABLE_CHAR,
                                                                          PROG_DGP_ASCII_LAST_PRINTABLE_CHAR);
        if (PROG_TRUE == eProgBoolStatus)
        {
            /* Check at least one logical block in the flash container */
            if (  (pstDowngradeProtectTable->uwBVTA >= PROG_DGP_MIN_BLOCK_NBR)
                &&(pstDowngradeProtectTable->uwBVTA <= PROG_BLOCK_NB) )
            {
                for (ubBlockIdx = 0U; (ubBlockIdx < pstDowngradeProtectTable->uwBVTA) && (PROG_TRUE == eProgBoolStatus); ubBlockIdx++)
                {
                    eProgBoolStatus = PROG_DowngradeProtection_CheckRangeASCII_Impl40(pstDowngradeProtectTable->stRfsVersionNumber[ubBlockIdx].aubRfsVersionPFT,
                                                                                      PROG_DGP_RFS_VERSION_SIZE,
                                                                                      PROG_DGP_ASCII_FIRST_NUMBER,
                                                                                      PROG_DGP_ASCII_LAST_NUMBER);
                }
                eProgRangesValid = eProgBoolStatus;
            }
        }
    }
    return eProgRangesValid;
}
/*-------------------------------{end PROG_DowngradeProtection_CheckValidRanges_Impl40}----------------------------------*/

/*-------------------{PROG_DowngradeProtection_CheckRangeASCII_Impl40}--------------------*/
NCS_PRI_FCT tProgBoolean PROG_DowngradeProtection_CheckRangeASCII_Impl40(const u8* ubInputText, u16 uwLength, u8 ubStartValue, u8 ubEndValue)
{
    tProgBoolean eRangeCheck;
    u8           ubLoopIndex;

    eRangeCheck = PROG_TRUE;

    for (ubLoopIndex = 0U; (ubLoopIndex < uwLength) && (PROG_TRUE == eRangeCheck); ubLoopIndex++)
    {
        /* Is input text out of the input range */
        if ((ubInputText[ubLoopIndex] < ubStartValue) || (ubInputText[ubLoopIndex] > ubEndValue))
        {
            eRangeCheck = PROG_FALSE;
        }
    }
    return eRangeCheck;
}
/*-------------------------------{end PROG_DowngradeProtection_CheckRangeASCII_Impl40}----------------------------------*/

/*-------------------{PROG_DowngradeProtection_CheckUniqueBlockID_Impl40}--------------------*/
NCS_PRI_FCT tProgBoolean PROG_DowngradeProtection_CheckUniqueBlockID_Impl40(const tProgDowngradeProtectionTable* pstDowngradeProtectTable)
{
    tProgBoolean eProgUniqueBlockID;
    u16          uwBlockIdentifier;
    u8           ubBlockIdx_i;
    u8           ubBlockIdx_j;

    eProgUniqueBlockID = PROG_TRUE;

    for (ubBlockIdx_i = 0U; (ubBlockIdx_i < pstDowngradeProtectTable->uwBVTA) && (PROG_TRUE == eProgUniqueBlockID); ubBlockIdx_i++)
    {
        /* Block for which searching occurrences */
        uwBlockIdentifier = pstDowngradeProtectTable->stRfsVersionNumber[ubBlockIdx_i].uwBID;

        for (ubBlockIdx_j = (ubBlockIdx_i + 1U); (ubBlockIdx_j < pstDowngradeProtectTable->uwBVTA) && (PROG_TRUE == eProgUniqueBlockID); ubBlockIdx_j++)
        {
            if (uwBlockIdentifier == pstDowngradeProtectTable->stRfsVersionNumber[ubBlockIdx_j].uwBID)
            {
                eProgUniqueBlockID = PROG_FALSE;
            }
        }
    }
    return eProgUniqueBlockID;
}
/*-------------------------------{end PROG_DowngradeProtection_CheckUniqueBlockID_Impl40}----------------------------------*/

/*---------------{PROG_DowngradeProtection_CheckBlockIDCorrespondence_Impl40}----------------*/
NCS_PRI_FCT tProgBoolean PROG_DowngradeProtection_CheckBlockIDCorrespondence_Impl40(const tProgDowngradeProtectionTable* pstDowngradeProtectTable)
{
    tProgBoolean eProgValidBlockID;
    tProgStatus  eIndexFound;
    u8           ubBlockIdentifier;
    u8           ubBvtBlockIdx;

    eProgValidBlockID = PROG_TRUE;

    for (ubBvtBlockIdx = 0U; (ubBvtBlockIdx < pstDowngradeProtectTable->uwBVTA) && (PROG_TRUE == eProgValidBlockID); ubBvtBlockIdx++)
    {
        /* Search the corresponding block ID in configuration */
        eIndexFound = PROG_FindBlockIndexInTable(pstDowngradeProtectTable->stRfsVersionNumber[ubBvtBlockIdx].uwBID, &ubBlockIdentifier);

        if (PROG_E_OK != eIndexFound)
        {
            eProgValidBlockID = PROG_FALSE;
        }
    }
    return eProgValidBlockID;
}
/*-------------------------------{end PROG_DowngradeProtection_CheckBlockIDCorrespondence_Impl40}----------------------------------*/

/*-------------------{PROG_DowngradeProtection_CheckPFTCompliance_Impl40}--------------------*/
NCS_PRI_FCT tProgBoolean PROG_DowngradeProtection_CheckPFTCompliance_Impl40(const tProgDowngradeProtectionTable* pstDowngradeProtectTable)
{
    tProgBoolean eProgPftCompliant;
    u8           ubIndex;

    /* Initialize status */
    eProgPftCompliant = PROG_TRUE;

    /* Check PTI length */
    if (PROG_DGP_PTI_LENGTH == pstDowngradeProtectTable->uwPTILength)
    {
        /* Check PTID content */
        for (ubIndex = 0U; (ubIndex < PROG_DGP_PTI_LENGTH) && (eProgPftCompliant == PROG_TRUE); ubIndex++)
        {
            if (m_aubTextPTID[ubIndex] != pstDowngradeProtectTable->ubPTIDContent[ubIndex])
            {
                eProgPftCompliant = PROG_FALSE;
            }
        }
    }
    else
    {
        eProgPftCompliant = PROG_FALSE;
    }
    return eProgPftCompliant;
}
/*-------------------------------{end PROG_DowngradeProtection_CheckPFTCompliance_Impl40}----------------------------------*/

/*-------------------{PROG_DowngradeProtection_CompareRfsVersion_Impl40}--------------------*/
NCS_PRI_FCT tProgBoolean PROG_DowngradeProtection_CompareRfsVersion_Impl40(const u8* pNewRfsVersion, const u8* pOldRfsVersion)
{
    tProgBoolean eProgRfsVersionOk;
    tProgBoolean eProgLeaveLoop;
    u8           ubRfsIdex;

    if ((NULL_PTR != pNewRfsVersion) && (NULL_PTR != pOldRfsVersion))
    {
        eProgRfsVersionOk = PROG_TRUE;
        eProgLeaveLoop    = PROG_FALSE;

        /* MSB is saved first */
        for (ubRfsIdex = 0; (ubRfsIdex < PROG_DGP_RFS_VERSION_SIZE) && (PROG_FALSE == eProgLeaveLoop); ubRfsIdex++)
        {
            if (pNewRfsVersion[ubRfsIdex] > pOldRfsVersion[ubRfsIdex])
            {
                /* New version is higher */
                eProgLeaveLoop = PROG_TRUE;
            }
            else if (pOldRfsVersion[ubRfsIdex] > pNewRfsVersion[ubRfsIdex])
            {
                /* Old version is higher */
                eProgRfsVersionOk = PROG_FALSE;
                eProgLeaveLoop    = PROG_TRUE;
            }
            else
            {
                /* Nothing to do */
            }
        }
    }
    else
    {
        eProgRfsVersionOk = PROG_FALSE;
    }
    return eProgRfsVersionOk;
}
/*-------------------------------{end PROG_DowngradeProtection_CompareRfsVersion_Impl40}----------------------------------*/

/*-------------------{PROG_DowngradeProtection_CheckValidationCriteria_Impl40}-------------------*/
NCS_PRI_FCT tProgStatus PROG_DowngradeProtection_CheckValidationCriteria_Impl40(void)
{
    tProgBoolean eProgValidRfs;
    tProgStatus  eProgStatus;
    tProgStatus  eRfsMinGetStatus;
    u8           ubLoopIndex;
    u8           ubLogicalBlock;
    u8           aubRfsVMinimum[PROG_DGP_RFS_VERSION_SIZE];

    /* Get the pseudo flash driver structure */
    eProgStatus = PROG_DowngradeProtection_GetPseudoFlashDriver_Impl40(&m_stPseudoFlashDriver);

    if (PROG_E_OK == eProgStatus)
    {
        eProgValidRfs = PROG_TRUE;
        ubLoopIndex   = 0U;
        /* Check validation criteria 1 to 4 and criterion 6*/
        while ((ubLoopIndex < PROG_DGP_VALID_RFS_DRIVER_FCT_NBR) && (PROG_TRUE == eProgValidRfs))
        {
            eProgValidRfs = m_aptValidRfsDriverFct[ubLoopIndex](&m_stPseudoFlashDriver);
            ubLoopIndex++;
        }
        /* Is RFS driver valid */
        if (PROG_TRUE == eProgValidRfs)
        {
            for (ubLoopIndex = 0U; (ubLoopIndex < m_stPseudoFlashDriver.uwBVTA) && (PROG_TRUE == eProgValidRfs); ubLoopIndex++)
            {
                /* Find the index of the block in the configuration */
                /* No need to check if it is found because if it was missing the previous validation criteria would detect it */
                (void)PROG_FindBlockIndexInTable(m_stPseudoFlashDriver.stRfsVersionNumber[ubLoopIndex].uwBID, &ubLogicalBlock);

                /* Get RfsV minimum */
                eRfsMinGetStatus = PROG_CustomGetRfsVMinimum(ubLogicalBlock, &aubRfsVMinimum[0U]);
                if (PROG_E_OK == eRfsMinGetStatus)
                {
                    /* Compare RFS versions */
                    eProgValidRfs = PROG_DowngradeProtection_CompareRfsVersion_Impl40(
                                                    &m_stPseudoFlashDriver.stRfsVersionNumber[ubLoopIndex].aubRfsVersionPFT[0U],
                                                    &aubRfsVMinimum[0U]);
                }
                else
                {
                    eProgValidRfs = PROG_FALSE;
                }
            }
            if (PROG_TRUE == eProgValidRfs)
            {
                /* Pseudo Flash Driver valid */
                m_ePseudoFlashDriverStatus = PROG_E_OK;
            }
            else
            {
                /* Invalid RFS Version */
                m_ePseudoFlashDriverStatus = PROG_E_RFS_VERSION_FAIL;
            }
        }
        else
        {
            /* Invalid RFS driver */
            m_ePseudoFlashDriverStatus = PROG_E_RFS_DRIVER_FAIL;
        }
    }
    else
    {
        /* Invalid RFS driver */
        m_ePseudoFlashDriverStatus = PROG_E_RFS_DRIVER_FAIL;
    }
    return m_ePseudoFlashDriverStatus;
}
/*-------------------------------{end PROG_DowngradeProtection_CheckValidationCriteria_Impl40}----------------------------------*/

/*-------------------{PROG_DowngradeProtection_CompareCurrentRfsVersusRfsPFT_Impl40}-------------------*/
NCS_PRI_FCT tProgStatus PROG_DowngradeProtection_CompareCurrentRfsVersusRfsPFT_Impl40(u8 ubLogicalBlock)
{
    tProgStatus  eProgStatus;
    tProgStatus  eRfsGetStatus;
    tProgBoolean eIndexFound;
    tProgBoolean eProgValidRfs;
    u16          uwBlockIdentifier;
    u8           ubLoopIndex;
    u8           ubTargetIndex;
    u8           aubRfsVCurrent[PROG_DGP_RFS_VERSION_SIZE];

    /* Invalid RFS Version at init */
    eProgStatus = PROG_E_RFS_VERSION_FAIL;

    /* If driver not missing then check version for requested logical block */
    if ((PROG_E_RFS_DRIVER_FAIL != m_ePseudoFlashDriverStatus) && (ubLogicalBlock < PROG_BLOCK_NB))
    {
        eIndexFound   = PROG_FALSE;
        ubTargetIndex = 0U;

        /* Search index in the BVT to identify which element is to compare */
        for (ubLoopIndex = 0U; (ubLoopIndex < m_stPseudoFlashDriver.uwBVTA) && (PROG_FALSE == eIndexFound); ubLoopIndex++)
        {
            uwBlockIdentifier = (u16)PROG_GetBlockIdByIndex(ubLogicalBlock);
            if (m_stPseudoFlashDriver.stRfsVersionNumber[ubLoopIndex].uwBID == uwBlockIdentifier)
            {
                eIndexFound = PROG_TRUE;
                ubTargetIndex = ubLoopIndex;
            }
        }
        if (PROG_TRUE == eIndexFound)
        {
            /* Get RfsV current */
            eRfsGetStatus = PROG_CustomGetRfsVCurrent(ubLogicalBlock, &aubRfsVCurrent[0U]);
            if (PROG_E_OK == eRfsGetStatus)
            {
                /* Compare RFS versions: PFT versus Current */
                eProgValidRfs = PROG_DowngradeProtection_CompareRfsVersion_Impl40(
                                                &m_stPseudoFlashDriver.stRfsVersionNumber[ubTargetIndex].aubRfsVersionPFT[0U],
                                                &aubRfsVCurrent[0U]);
                if (PROG_TRUE == eProgValidRfs)
                {
                    /* Valid RFS version number */
                    eProgStatus = PROG_E_OK;
                }
            }
        }
    }
    else
    {
        /* pseudo flash driver missing */
        eProgStatus = PROG_E_RFS_DRIVER_FAIL;
    }
    return eProgStatus;
}
/*-------------------------------{end PROG_DowngradeProtection_CompareCurrentRfsVersusRfsPFT_Impl40}----------------------------------*/

/*-------------------{PROG_DowngradeProtection_CompareNewBlockRfsVersusRfsPFT_Impl40}-------------------*/
NCS_PRI_FCT tProgStatus PROG_DowngradeProtection_CompareNewBlockRfsVersusRfsPFT_Impl40(u8 ubLogicalBlock)
{
    tProgStatus  eProgStatus;
    tProgStatus  eProgGetRfsStatus;
    tProgBoolean eProgValidRfs;
    tProgBoolean eIndexFound;
    u16          uwBlockIdentifier;
    u8           ubLoopIndex;
    u8           ubTargetIndex;
    u8           aubRfsVLB[PROG_DGP_RFS_VERSION_SIZE];
    u8           aubRfsVOnDelivery[PROG_DGP_RFS_VERSION_SIZE] = {0x30, 0x30, 0x30, 0x31};

    if (PROG_E_RFS_DRIVER_FAIL != m_ePseudoFlashDriverStatus)
    {
        /* Invalid RFS Version at init */
        eProgStatus = PROG_E_RFS_VERSION_FAIL;

        if ((ubLogicalBlock != PROG_PFT_BLOCK) && (ubLogicalBlock < PROG_BLOCK_NB))
        {
            eIndexFound   = PROG_FALSE;
            ubTargetIndex = 0U;

            /* Search index in the BVT to identify which element is to compare */
            for (ubLoopIndex = 0U; (ubLoopIndex < m_stPseudoFlashDriver.uwBVTA) && (PROG_FALSE == eIndexFound); ubLoopIndex++)
            {
                uwBlockIdentifier = PROG_GetBlockIdByIndex(ubLogicalBlock);
                if (m_stPseudoFlashDriver.stRfsVersionNumber[ubLoopIndex].uwBID == uwBlockIdentifier)
                {
                    eIndexFound = PROG_TRUE;
                    ubTargetIndex = ubLoopIndex;
                }
            }
            if (PROG_TRUE == eIndexFound)
            {
                /* Compare RFS versions: PFT versus On delivery */
                eProgValidRfs = PROG_DowngradeProtection_CompareRfsVersion_Impl40(
                                                &aubRfsVOnDelivery[0U],
                                                &m_stPseudoFlashDriver.stRfsVersionNumber[ubTargetIndex].aubRfsVersionPFT[0U]);
                /* Downgrade protection not activated */
                if (PROG_TRUE == eProgValidRfs)
                {
                    eProgStatus = PROG_E_OK;
                }
                else
                {
                    /* Get RfsV from LB */
                    eProgGetRfsStatus = PROG_CustomGetRfsVLB(ubLogicalBlock, &aubRfsVLB[0U]);
                    /* Compare RFS versions: PFT versus LB values */
                    if ( (m_stPseudoFlashDriver.stRfsVersionNumber[ubTargetIndex].aubRfsVersionPFT[0U] == aubRfsVLB[0U]) &&
                         (m_stPseudoFlashDriver.stRfsVersionNumber[ubTargetIndex].aubRfsVersionPFT[1U] == aubRfsVLB[1U]) &&
                         (m_stPseudoFlashDriver.stRfsVersionNumber[ubTargetIndex].aubRfsVersionPFT[2U] == aubRfsVLB[2U]) &&
                         (m_stPseudoFlashDriver.stRfsVersionNumber[ubTargetIndex].aubRfsVersionPFT[3U] == aubRfsVLB[3U]) &&
                         (PROG_E_OK == eProgGetRfsStatus) )
                    {
                        /* Update value of current RFS version */
                        eProgStatus = PROG_CustomStoreRfsVCurrent(ubLogicalBlock, &aubRfsVLB[0U]);
                    }
                }
            }
        }
    }
    else
    {
        eProgStatus = PROG_E_RFS_DRIVER_FAIL;
    }
    return eProgStatus;
}
/*-------------------------------{end PROG_DowngradeProtection_CompareNewBlockRfsVersusRfsPFT_Impl40}----------------------------------*/

/*-------------------{PROG_DowngradeProtection_CompareRfsForCoherencyCheck_Impl40}-------------------*/
tProgStatus PROG_DowngradeProtection_CompareRfsForCoherencyCheck_Impl40(u8 * pubRoutineStatus)
{
    tProgStatus  eProgStatus;
    tProgStatus  eRfsGetStatus;
    tProgStatus  eRfsMinGetStatus;
    tProgBoolean eProgValidRfs;
    tProgBoolean eIndexFound;
    tProgBoolean ubLogicalBlockDowngradeFlag;
    u8           ubLogicalBlock;
    u8           ubLoopIndex;
    u8           aubRfsVCurrent[PROG_DGP_RFS_VERSION_SIZE];
    u8           aubRfsVMinimum[PROG_DGP_RFS_VERSION_SIZE];
    u8           aubRfsVLB[PROG_DGP_RFS_VERSION_SIZE];

    DBG_PROG_DOWNGRADEPROTECTION_COMPARERFSFORCOHERENCYCHECK_IMPL40_ENTRY(pubRoutineStatus);

    if (PROG_E_RFS_DRIVER_FAIL != m_ePseudoFlashDriverStatus)
    {
        /* Invalid RFS Version at init */
        eProgStatus       = PROG_E_RFS_VERSION_FAIL;
        eProgValidRfs     = PROG_TRUE;
        *pubRoutineStatus = PROG_DGP_ROUTINE_CHECKDEP_INVALID_RFS_VERSION;

        /* Evaluate RfsV current versus minimum for all blocks in the server */
        for (ubLogicalBlock = 0U; (ubLogicalBlock < PROG_DGP_BVT_NUMBER_OF_BLOCKS) && (PROG_TRUE == eProgValidRfs); ubLogicalBlock++)
        {
            /* Evaluate the RfsV current versus minimum of the block only if the block should be downgrade protected*/
            ubLogicalBlockDowngradeFlag = PROG_GetBlockDowngradeFlagByIndex(ubLogicalBlock);
            if ((PROG_PFT_BLOCK != ubLogicalBlock) &&  (ubLogicalBlockDowngradeFlag == PROG_TRUE))
            {
                /* Get RfsV current */
                eRfsGetStatus = PROG_CustomGetRfsVCurrent(ubLogicalBlock, &aubRfsVCurrent[0U]);
                /* Get RfsV minimum */
                eRfsMinGetStatus = PROG_CustomGetRfsVMinimum(ubLogicalBlock, &aubRfsVMinimum[0U]);
                if ((PROG_E_OK == eRfsGetStatus) && (PROG_E_OK == eRfsMinGetStatus))
                {
                    /* Compare RFS versions: current versus minimum */
                    eProgValidRfs = PROG_DowngradeProtection_CompareRfsVersion_Impl40(&aubRfsVCurrent[0U], &aubRfsVMinimum[0U]);
                }
                else
                {
                    eProgValidRfs = PROG_FALSE;
                }
            }
        }
        if (PROG_TRUE == eProgValidRfs)
        {
            eProgStatus       = PROG_E_OK;
            *pubRoutineStatus = 0x00U;

            /* Evaluate RfsV current */
            for (ubLoopIndex = 0U; (ubLoopIndex < m_stPseudoFlashDriver.uwBVTA) && (PROG_TRUE == eProgValidRfs); ubLoopIndex++)
            {
                /* Search corresponding index in the configuration */
                eIndexFound = PROG_FindBlockIndexInTable(m_stPseudoFlashDriver.stRfsVersionNumber[ubLoopIndex].uwBID, &ubLogicalBlock);
                if (PROG_E_OK == eIndexFound)
                {
                    /* The RfsV current of the block is evaluated only if the block is downgrade protected*/
                    ubLogicalBlockDowngradeFlag = PROG_GetBlockDowngradeFlagByIndex(ubLogicalBlock);
                    if (ubLogicalBlockDowngradeFlag == PROG_TRUE)
                    {
                        /* Get RfsV LB */
                        eRfsGetStatus = PROG_CustomGetRfsVLB(ubLogicalBlock, &aubRfsVLB[0U]);
                        /* Compare RFS versions: PFT versus current values */
                        if ( (m_stPseudoFlashDriver.stRfsVersionNumber[ubLoopIndex].aubRfsVersionPFT[0U] != aubRfsVLB[0U]) ||
                             (m_stPseudoFlashDriver.stRfsVersionNumber[ubLoopIndex].aubRfsVersionPFT[1U] != aubRfsVLB[1U]) ||
                             (m_stPseudoFlashDriver.stRfsVersionNumber[ubLoopIndex].aubRfsVersionPFT[2U] != aubRfsVLB[2U]) ||
                             (m_stPseudoFlashDriver.stRfsVersionNumber[ubLoopIndex].aubRfsVersionPFT[3U] != aubRfsVLB[3U]) ||
                             (PROG_E_OK != eRfsGetStatus) )
                        {
                            eProgValidRfs     = PROG_FALSE;
                            eProgStatus       = PROG_E_RFS_VERSION_FAIL;
                            *pubRoutineStatus = PROG_DGP_ROUTINE_CHECKDEP_INVALID_RFS_VERSION;
                        }
                    }
                }
                else
                {
                    eProgValidRfs     = PROG_FALSE;
                    eProgStatus       = PROG_E_RFS_VERSION_FAIL;
                    *pubRoutineStatus = PROG_DGP_ROUTINE_CHECKDEP_INVALID_RFS_VERSION;
                }
            }
        }
    }
    else
    {
        /* Pseudo flash driver not available */
        eProgStatus       = PROG_E_RFS_DRIVER_FAIL;
        *pubRoutineStatus = PROG_DGP_ROUTINE_CHECKDEP_MISSING_RFS_DRIVER;
    }

    DBG_PROG_DOWNGRADEPROTECTION_COMPARERFSFORCOHERENCYCHECK_IMPL40_EXIT(eProgStatus);

    return eProgStatus;
}
/*-------------------------------{end PROG_DowngradeProtection_CompareRfsForCoherencyCheck_Impl40}----------------------------------*/

/*-------------------{PROG_DowngradeProtection_GetPseudoFlashDriver_Impl40}-------------------*/
NCS_PRI_FCT tProgStatus PROG_DowngradeProtection_GetPseudoFlashDriver_Impl40(tProgDowngradeProtectionTable* pstDowngradeProtectTable)
{
    tProgStatus      eProgStatus;
    tProgAddressType ulStartAddr;
    u8               ubLoopIndex;
    u8               ubBvtIndex;
    u8               aubPftData[PROG_DGP_TOTAL_PFT_LENGTH];

    ulStartAddr = PROG_GetPseudoFlashDriverAddress();
    /* Read the pseudo flash driver from RAM */
    eProgStatus = PROG_MemDataAccess(PROG_MEM_TYPE_RAM,
                                     PROG_MEM_OPERATION_TYPE_READ,
                                     ulStartAddr,
                                     PROG_DGP_TOTAL_PFT_LENGTH,
                                     &aubPftData[0U]);

    if (PROG_E_OK == eProgStatus)
    {
        /* Retrieve the pseudo flash driver identification */
        pstDowngradeProtectTable->uwPTILength = (u16)((((u16)aubPftData[0U]) << 8U)| (u16)aubPftData[1U]);
        for (ubLoopIndex = 0U; ubLoopIndex < PROG_DGP_PTI_LENGTH; ubLoopIndex++)
        {
            pstDowngradeProtectTable->ubPTIDContent[ubLoopIndex] = aubPftData[ubLoopIndex + 2U];
        }

        /* Retrieve number of entries */
        pstDowngradeProtectTable->uwBVTA = (u16)((((u16)aubPftData[PROG_DGP_PTI_LENGTH + 2U]) << 8U)| (u16)aubPftData[PROG_DGP_PTI_LENGTH + 3U]);
        ubBvtIndex = PROG_DGP_PTI_LENGTH + 4U;
        for (ubLoopIndex = 0U; ubLoopIndex < pstDowngradeProtectTable->uwBVTA; ubLoopIndex++)
        {
#if (PROG_DGP_BID_LENGTH == PROG_DGP_BID_LENGTH_1_BYTE)
            /* Copy block identifier one byte */
            pstDowngradeProtectTable->stRfsVersionNumber[ubLoopIndex].uwBID = (u16)aubPftData[ubLoopIndex + ubBvtIndex];
#else
            /* Copy block identifier two bytes */
            pstDowngradeProtectTable->stRfsVersionNumber[ubLoopIndex].uwBID = (((u16)aubPftData[ubLoopIndex + ubBvtIndex]) << 8U);
            ubBvtIndex++;
            pstDowngradeProtectTable->stRfsVersionNumber[ubLoopIndex].uwBID |= (u16)aubPftData[ubLoopIndex + ubBvtIndex];
#endif /* (PROG_DGP_BID_LENGTH == PROG_DGP_BID_LENGTH_1_BYTE) */

            /* Copy the RfsV of this block identifier */
            pstDowngradeProtectTable->stRfsVersionNumber[ubLoopIndex].aubRfsVersionPFT[0U] = aubPftData[ubLoopIndex + ubBvtIndex + 1U];
            pstDowngradeProtectTable->stRfsVersionNumber[ubLoopIndex].aubRfsVersionPFT[1U] = aubPftData[ubLoopIndex + ubBvtIndex + 2U];
            pstDowngradeProtectTable->stRfsVersionNumber[ubLoopIndex].aubRfsVersionPFT[2U] = aubPftData[ubLoopIndex + ubBvtIndex + 3U];
            pstDowngradeProtectTable->stRfsVersionNumber[ubLoopIndex].aubRfsVersionPFT[3U] = aubPftData[ubLoopIndex + ubBvtIndex + 4U];
            /* next index in the BVT */
            ubBvtIndex = ubBvtIndex + 4U;
        }
    }
    else
    {
        /* Error while reading */
        eProgStatus = PROG_E_NOT_OK;
    }
    return eProgStatus;
}
/*-------------------------------{end PROG_DowngradeProtection_GetPseudoFlashDriver_Impl40}----------------------------------*/

/*-------------------{PROG_DowngradeProtection_CheckForEraseAndRD_Impl40}-------------------*/
tProgStatus PROG_DowngradeProtection_CheckForEraseAndRD_Impl40(u8 ubBlockId)
{
    tProgStatus  eProgStatus;
    tProgBoolean ubLogicalBlockDowngradeFlag;
#if (PROG_PRELIM_ERASING_ENABLE == STD_ON)
    u16         uwBlockIdent;
    u8          ubBlockIndex;
#endif /* (PROG_PRELIM_ERASING_ENABLE == STD_ON) */

    DBG_PROG_DOWNGRADEPROTECTION_CHECKFORERASEANDRD_IMPL40_ENTRY(ubBlockId);
    /* Downgrade protection applies only for protected blocks */
    ubLogicalBlockDowngradeFlag = PROG_GetBlockDowngradeFlagByIndex(ubBlockId);
    if ((PROG_PFT_BLOCK != ubBlockId) &&  (ubLogicalBlockDowngradeFlag == PROG_TRUE))
    {
#if (PROG_PRELIM_ERASING_ENABLE == STD_ON)
        eProgStatus  = PROG_E_OK;
        uwBlockIdent = PROG_GetBlockIdByIndex(ubBlockId);

        if(uwBlockIdent == PROG_MAX_BLOCK_ID)
        {
            /* If preliminary erasing then check for all blocks */
            for (ubBlockIndex = 0U; (ubBlockIndex < (PROG_BLOCK_NB - 1U)) && (PROG_E_OK == eProgStatus); ubBlockIndex++)
            {
                /* Check the block for downgrade protection only if the block should be downgrade protected*/
                ubLogicalBlockDowngradeFlag = PROG_GetBlockDowngradeFlagByIndex(ubBlockIndex);
                if ((PROG_PFT_BLOCK != ubBlockIndex) && (ubLogicalBlockDowngradeFlag == PROG_TRUE))
                {
                    /* Check the status of the pseudo flash driver and the RfsV of the block */
                    eProgStatus = PROG_DowngradeProtection_CompareCurrentRfsVersusRfsPFT_Impl40(ubBlockIndex);
                }
            }
        }
        else
#endif /* (PROG_PRELIM_ERASING_ENABLE == STD_ON) */
        {
            /* Check the status of the pseudo flash driver and the RfsV of the block */
            eProgStatus = PROG_DowngradeProtection_CompareCurrentRfsVersusRfsPFT_Impl40(ubBlockId);
        }
    }
    else
    {
        eProgStatus = PROG_E_OK;
    }

    DBG_PROG_DOWNGRADEPROTECTION_CHECKFORERASEANDRD_IMPL40_EXIT(eProgStatus);

    return eProgStatus;
}
/*-------------------------------{end PROG_DowngradeProtection_CheckForEraseAndRD_Impl40}----------------------------------*/

/*-------------------{PROG_DowngradeProtection_CheckForCheckMemory_Impl40}-------------------*/
tProgStatus PROG_DowngradeProtection_CheckForCheckMemory_Impl40(u8 ubBlockId, u8 * ubDgpStatus)
{
    tProgStatus  eProgStatus;
    tProgBoolean ubLogicalBlockDowngradeFlag;

    DBG_PROG_DOWNGRADEPROTECTION_CHECKFORCHECKMEMORY_IMPL40_ENTRY(ubBlockId, ubDgpStatus);

    if (PROG_PFT_BLOCK == ubBlockId)
    {
        /* Validation criteria verification of the pseudo flash driver */
        eProgStatus = PROG_DowngradeProtection_CheckValidationCriteria_Impl40();
    }
    else
    {
        /* Downgrade protection is performed only if the block is downgrade protected */
        ubLogicalBlockDowngradeFlag = PROG_GetBlockDowngradeFlagByIndex(ubBlockId);
        if(ubLogicalBlockDowngradeFlag == PROG_FALSE)
        {
            /* By-Pass downgrade protection for the block*/
            eProgStatus = PROG_E_OK;
        }
        else
        {
            /* Donwgrade protection verification */
            eProgStatus = PROG_DowngradeProtection_CompareNewBlockRfsVersusRfsPFT_Impl40(ubBlockId);
        }
    }

    /* Invalid RFS driver */
    if (PROG_E_RFS_DRIVER_FAIL == eProgStatus)
    {
        *ubDgpStatus = (u8)PROG_DGP_ROUTINE_CHECKMEMORY_INVALID_RFS_DRIVER;
    }
    /* Invalid RFS version */
    else if (PROG_E_OK != eProgStatus)
    {
        eProgStatus  = PROG_E_RFS_VERSION_FAIL;
        *ubDgpStatus = (u8)PROG_DGP_ROUTINE_CHECKMEMORY_INVALID_RFS_VERSION;
    }
    else
    {
        *ubDgpStatus = (u8)PROG_ROUTINE_FINISHED_OK;
    }

    DBG_PROG_DOWNGRADEPROTECTION_CHECKFORCHECKMEMORY_IMPL40_EXIT(eProgStatus);

    return eProgStatus;
}
/*-------------------------------{end PROG_DowngradeProtection_CheckForCheckMemory_Impl40}----------------------------------*/

/*-------------------{PROG_DowngradeProtection_ResetPFTStatus_Impl40}-------------------*/
void PROG_DowngradeProtection_ResetPFTStatus_Impl40(void)
{
    DBG_PROG_DOWNGRADEPROTECTION_RESETPFTSTATUS_IMPL40_ENTRY();

    m_ePseudoFlashDriverStatus = PROG_E_RFS_DRIVER_FAIL;

    DBG_PROG_DOWNGRADEPROTECTION_RESETPFTSTATUS_IMPL40_EXIT();
}
/*-------------------------------{end PROG_DowngradeProtection_ResetPFTStatus_Impl40}----------------------------------*/

#endif /* PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON */
