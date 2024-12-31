/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               PROG layer                                      */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_Cbk.c                      */
/*%%  |                             |  %%  \brief PROG layer source plugin file  */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: M4_MODULE_VERSION_MAJOR.M4_MODULE_VERSION_MINOR.M4_MODULE_VERSION_PATCH M4_MODULE_VERSION_SUFFIX */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/* Copyright 2015 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/

/*=============================== FILE INCLUSION ================================*/
/*                                                                               */
#include "EB_Prj.h"
#include "PROG_Priv.h"
#include "PROG_Hsm.h"
#include "PROG_HsmPROG.h"
#include "board.h"
#include "Target_Specific_Definition.h"

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

NCS_PRI_VAR ptAPPL_START_ADDR pAPPL_START_ADDR;
NCS_PRI_VAR u8 m_aubFingerPrint[PROG_FINGERPRINT_LENGTH];

#define PROG_REPROG_FLAG_START_SEC_VAR_NO_INIT_8
#include <MemMap.h>
/*
 * Shared variable between bootlaoder and application
 * Shall be stored in a NoInit area known by both software
 */
tNoInitShareVar stNoIntShareVar;
#define PROG_REPROG_FLAG_STOP_SEC_VAR_NO_INIT_8
#include <MemMap.h>

#define PROG_START_SEC_VAR_RAM_NO_INIT
#include <MemMap.h>
/* RAM structure of NVM mirror */
tNVMBootloaderData stNVMBootloaderData;
#define PROG_STOP_SEC_VAR_RAM_NO_INIT
#include <MemMap.h>


static tProgBoolean PROG_IsBlockValid(u16 ubBlockID);

#define PROG_MAGIC_NUM_SIZE 8U

/* Programmed magic number value */
static const u8 m_aMagicNumProgrammedValue[PROG_MAGIC_NUM_SIZE] =
{
   /* "PROGRAMM" in ASCII */
   0x50U,
   0x52U,
   0x4FU,
   0x47U,
   0x52U,
   0x41U,
   0x4dU,
   0x4dU,
};
/* Revoked PSI value */
static const u8 m_aMagicNumRevokedValue[PROG_MAGIC_NUM_SIZE] =
{
   /* "REVOKED " in ASCII */
   0x52U,
   0x45U,
   0x56U,
   0x4FU,
   0x4BU,
   0x45U,
   0x44U,
   0x20U,
};

/*Example for 3072 bit key:
Modulus: 9c213ea373631f572e5e46225b95a0f5ea8ab0a5ec7090a3b0181c5906dc22fd1bd73d11471242a2ed1824e601017f5b5354b92fdb43d4da00a82427d05366a4d552c40d69d200485d5d5db83cf523e61a834b40ccd401087fbb93d81dbed7b2ee2381a1241ac68f2afc02157ee0c73cc66c02a6c6eb2dc35145ae55d7708412a3410f204c492376d6315cedf253af91f31dcab34f72c206ad81e800509864fe9255d046ac25dbdf4954d2350324722e73c1f25d089f87542ad907fb37eceaefb330f4325e97f5eabc04096a8fabba978589e355445d9543274c1c38ff849ba8c2911f07030634c132ccaf4e4f57a5ad9244f5df0ee25af8ef2fc7b29fdf7cc18404e20efaaffa451ec41ab838d594906ff2cad52dcbd0e9a68ef7b06c253710e1318d09ad07012767a89124177df50d1684679e14306889d9a7ac5143d4861b7d6ae77992efa73e0aba9da0ad9a6888bc804dbd07bc26a8a5dfbd292a0efa96867fdb92e845c36e3433cf292e0e31662480257fcf466f7f65d814bb3e33992f
Public exponent: 00efabb9
*/

const u32 m_ulPROGPublicExponent = 0x00EFABB9UL;

const u8 m_aubPROGPublicModulus[384] =
    {
        0x9C, 0x21, 0x3E, 0xA3, 0x73, 0x63, 0x1F, 0x57,
        0x2E, 0x5E, 0x46, 0x22, 0x5B, 0x95, 0xA0, 0xF5,
        0xEA, 0x8A, 0xB0, 0xA5, 0xEC, 0x70, 0x90, 0xA3,
        0xB0, 0x18, 0x1C, 0x59, 0x06, 0xDC, 0x22, 0xFD,
        0x1B, 0xD7, 0x3D, 0x11, 0x47, 0x12, 0x42, 0xA2,
        0xED, 0x18, 0x24, 0xE6, 0x01, 0x01, 0x7F, 0x5B,
        0x53, 0x54, 0xB9, 0x2F, 0xDB, 0x43, 0xD4, 0xDA,
        0x00, 0xA8, 0x24, 0x27, 0xD0, 0x53, 0x66, 0xA4,
        0xD5, 0x52, 0xC4, 0x0D, 0x69, 0xD2, 0x00, 0x48,
        0x5D, 0x5D, 0x5D, 0xB8, 0x3C, 0xF5, 0x23, 0xE6,
        0x1A, 0x83, 0x4B, 0x40, 0xCC, 0xD4, 0x01, 0x08,
        0x7F, 0xBB, 0x93, 0xD8, 0x1D, 0xBE, 0xD7, 0xB2,
        0xEE, 0x23, 0x81, 0xA1, 0x24, 0x1A, 0xC6, 0x8F,
        0x2A, 0xFC, 0x02, 0x15, 0x7E, 0xE0, 0xC7, 0x3C,
        0xC6, 0x6C, 0x02, 0xA6, 0xC6, 0xEB, 0x2D, 0xC3,
        0x51, 0x45, 0xAE, 0x55, 0xD7, 0x70, 0x84, 0x12,
        0xA3, 0x41, 0x0F, 0x20, 0x4C, 0x49, 0x23, 0x76,
        0xD6, 0x31, 0x5C, 0xED, 0xF2, 0x53, 0xAF, 0x91,
        0xF3, 0x1D, 0xCA, 0xB3, 0x4F, 0x72, 0xC2, 0x06,
        0xAD, 0x81, 0xE8, 0x00, 0x50, 0x98, 0x64, 0xFE,
        0x92, 0x55, 0xD0, 0x46, 0xAC, 0x25, 0xDB, 0xDF,
        0x49, 0x54, 0xD2, 0x35, 0x03, 0x24, 0x72, 0x2E,
        0x73, 0xC1, 0xF2, 0x5D, 0x08, 0x9F, 0x87, 0x54,
        0x2A, 0xD9, 0x07, 0xFB, 0x37, 0xEC, 0xEA, 0xEF,
        0xB3, 0x30, 0xF4, 0x32, 0x5E, 0x97, 0xF5, 0xEA,
        0xBC, 0x04, 0x09, 0x6A, 0x8F, 0xAB, 0xBA, 0x97,
        0x85, 0x89, 0xE3, 0x55, 0x44, 0x5D, 0x95, 0x43,
        0x27, 0x4C, 0x1C, 0x38, 0xFF, 0x84, 0x9B, 0xA8,
        0xC2, 0x91, 0x1F, 0x07, 0x03, 0x06, 0x34, 0xC1,
        0x32, 0xCC, 0xAF, 0x4E, 0x4F, 0x57, 0xA5, 0xAD,
        0x92, 0x44, 0xF5, 0xDF, 0x0E, 0xE2, 0x5A, 0xF8,
        0xEF, 0x2F, 0xC7, 0xB2, 0x9F, 0xDF, 0x7C, 0xC1,
        0x84, 0x04, 0xE2, 0x0E, 0xFA, 0xAF, 0xFA, 0x45,
        0x1E, 0xC4, 0x1A, 0xB8, 0x38, 0xD5, 0x94, 0x90,
        0x6F, 0xF2, 0xCA, 0xD5, 0x2D, 0xCB, 0xD0, 0xE9,
        0xA6, 0x8E, 0xF7, 0xB0, 0x6C, 0x25, 0x37, 0x10,
        0xE1, 0x31, 0x8D, 0x09, 0xAD, 0x07, 0x01, 0x27,
        0x67, 0xA8, 0x91, 0x24, 0x17, 0x7D, 0xF5, 0x0D,
        0x16, 0x84, 0x67, 0x9E, 0x14, 0x30, 0x68, 0x89,
        0xD9, 0xA7, 0xAC, 0x51, 0x43, 0xD4, 0x86, 0x1B,
        0x7D, 0x6A, 0xE7, 0x79, 0x92, 0xEF, 0xA7, 0x3E,
        0x0A, 0xBA, 0x9D, 0xA0, 0xAD, 0x9A, 0x68, 0x88,
        0xBC, 0x80, 0x4D, 0xBD, 0x07, 0xBC, 0x26, 0xA8,
        0xA5, 0xDF, 0xBD, 0x29, 0x2A, 0x0E, 0xFA, 0x96,
        0x86, 0x7F, 0xDB, 0x92, 0xE8, 0x45, 0xC3, 0x6E,
        0x34, 0x33, 0xCF, 0x29, 0x2E, 0x0E, 0x31, 0x66,
        0x24, 0x80, 0x25, 0x7F, 0xCF, 0x46, 0x6F, 0x7F,
        0x65, 0xD8, 0x14, 0xBB, 0x3E, 0x33, 0x99, 0x2F,
    };
/** \brief API that check if a programming request has been received by the application
 **
 ** Callback is called: at Bootloader startup to know if a programing request has
 **                     been received in Application
 **
 ** Callback shall implement: get information from application if a programming
 **                          request has been received (e.g: read a flag from
 **                          noinit RAM shared between Bootloader and
 **                           Application)
 **
 ** \return Result of check
 ** \retval PROG_BOOT_REPROG Reprogramming request has been received
 ** \retval PROG_BOOT_NO_REPROG No reprogramming request received
 **/
u8 PROG_CheckProgRequest(void)
{
    u8 ubRetVal = PROG_BOOT_NOREPROG;

       /* Check if the signature is set */
    if (0x55AA55AA == stNoIntShareVar.ulProgSig)
    {
        /* coming from application must stay in boot */
        ubRetVal = PROG_BOOT_REPROG;
    }
    else
    {
        /* Prog signature is clear must jump in application after tested it */
    }

    /* Clear the prog signature*/
    stNoIntShareVar.ulProgSig = 0U;

    return ubRetVal;
}

/** \brief Callback performing jump to application software
 **
 ** Callback is called: at Bootloader startup if application is valid and shall
 **                    be executed
 **
 ** Callback shall implement: jump to application start address
 **
 **/
void PROG_JumpToApplication(void)
{
  /* get the address of the application to jump in */
  pAPPL_START_ADDR = (ptAPPL_START_ADDR)APP_START_ADDR;

  /* Jump in application */
  pAPPL_START_ADDR();
}


/** \brief Callback that shall disable ECC if needed
 ** Callback is called: When Bootloader perform read access on Flash that can be
 **                     unprogrammed and can cause ECC error
 **
 ** Callback shall implement: If needed, disabling of ECC check
 **                           Hardware specific)
 **/
void PROG_DisableECCCheck(void)
{

}


/** \brief Callback that shall enable ECC if needed
 ** Callback is called: After Bootloader has performed a read access on Flash
 **                    that can be unprogrammed and can cause ECC error
 **
 ** Callback shall implement: If needed, enabling of ECC check
 **                          (Hardware specific)
 **/
void PROG_EnableECCCheck(void)
{

}


/** \brief Callback checking if the application is valid or not
 **
 ** Callback is called: at startup and on some routine.
 **
 ** Callback shall implement: It shall verify that the application
 ** with all its dependencies are correctly flashed
 ** and return the result of the check
 **
 ** \return Result of check
 ** \retval TRUE Application is valid
 ** \retval FALSE Application is not valid or not present
 **/

tProgBoolean PROG_IsValidApplication(void)
{
    tProgBoolean ubIsValidApp = PROG_TRUE;
    u8 ubIdx;

    for (ubIdx = 0U; ((ubIdx < PROG_BLOCK_NBR) && (ubIsValidApp == PROG_TRUE)); ubIdx++)
    {
        if (PROG_IsBlockValid(ubIdx) != PROG_BLOCK_VALID)
        {
            ubIsValidApp = PROG_FALSE;
        }
    }

    return ubIsValidApp;
}

/** \brief API that invalidate the application marker
 **
 ** Callback is called: On Erase routine reception
 **
 ** Callback shall implement: 1- customer code that shall be executed before
 **                           performing an erasing of a logical block
 **
 **                           2- It shall invalidate the logical block that will be erased
 **                           to make sure no jump to the application will be done if an error occurred
 **                           and the application is not fully erased or reprogrammed
 **
 ** \param[in] ubBlockId The ID of the block that will be erased
 **
 ** \return Result application invalidation
 ** \retval PROG_E_OK Treatment finish successfully
 ** \retval PROG_E_NOT_OK Error happened during treatment
 **/
tProgStatus PROG_InvalidateSection_BlockID(u8 ubBlockId)
{
    tProgStatus eProgStatus = PROG_E_OK;
    tProgMemType eMemType;
    u32 ulAddress;
    u8 aubFlag[PROG_MAGIC_NUM_SIZE];
    u8 ubIdx;
    u8 ubAlreadyInval = PROG_FALSE;

    /* Invalidate the block to be erased */
    /* Retrieve revoked flag of the block */
    ulAddress = (stConfigSegment[(stCfgBlock[ubBlockId].ubFirstSegmentId + stCfgBlock[ubBlockId].ubSegmentNbr) - 1U].ulEraseEndAddress - (2*PROG_MIN_VAL_TO_WRITE) + 1U);
    eMemType = m_astCfgMemory[stConfigSegment[(stCfgBlock[ubBlockId].ubFirstSegmentId + stCfgBlock[ubBlockId].ubSegmentNbr) - 1U].ubMemoryIdx].eMemoryType;

    eProgStatus = PROG_MemDataAccess(eMemType,PROG_MEM_OPERATION_TYPE_READ,ulAddress,PROG_MAGIC_NUM_SIZE, aubFlag);

    if(eProgStatus == PROG_E_OK)
    {
        /* A: 80126-A107 */
        for(ubIdx = 0U; ((ubIdx < PROG_MAGIC_NUM_SIZE) && (ubAlreadyInval == PROG_FALSE)) ; ubIdx++)
        {
            if(aubFlag[ubIdx] != PROG_FLASH_ERASE_VALUE)
            {
                ubAlreadyInval = PROG_TRUE;
            }
        }

        if(ubAlreadyInval == PROG_FALSE)
        {
            eProgStatus = PROG_MemDataAccess(eMemType,PROG_MEM_OPERATION_TYPE_WRITE,ulAddress,PROG_MAGIC_NUM_SIZE, (u8*)m_aMagicNumRevokedValue);
        }

        if(eProgStatus == PROG_E_OK)
        {
            for(ubIdx = 0U; ubIdx < PROG_FINGERPRINT_LENGTH; ubIdx++)
            {
                stNVMBootloaderData.stNVMBlockData[ubBlockId].aubFingerPrintInfo[ubIdx] = m_aubFingerPrint[ubIdx];
            }
        }
    }

    /* Invalidate coherency since on block is not valid anymore */
    stNVMBootloaderData.stNVMEcuData.ubECUProgInfo = PROG_ECUPROGINFO_INCONSISTENT;


    return eProgStatus;
}

/** \brief Called before Bootloader perform a jump to application
 **
 ** Callback is called: Before jumping to Application
 **
 **  Callback shall implement: customer code that shall be executed before
 **  jumping to application
**/
void PROG_SwitchApplicationModeInd(void)
{

}

/** \brief Get the status of the suppress positive response bit from the last reprogramming request in application
 **
 ** Callback is called: At startup when Bootloader shall send a response to a request that
 **                     has been received in application
 **
 ** Callback shall implement: get from application information if the
 **                          suppressPositiveResponse bit was set in the
 **                           received request (e.g: read a flag from noinit RAM
 **                           shared between Bootloader and  Application)
 **
 ** \return Suppression bit value
 ** \retval TRUE The suppress positive response bit was set (response will not be sent)
 ** \retval FALSE The suppress positive response bit was not set (response will be sent)
 **/
u8 PROG_GetSuppressBitFromAppli(void)
{
    u8 ubSupRespBit;

    if(stNoIntShareVar.ubResponseRequired == TRUE)
    {
        ubSupRespBit = FALSE;
    }
    else
    {
        ubSupRespBit = TRUE;
    }
    return ubSupRespBit;
}

/** \cond **/
/** \endcond **/
/** \brief Start the Fingerprint Writing
 **
 ** Callback is called: On reception of WriteDataByIdentifier service for Fingerprint
 **                     DID
 **
 ** Callback shall implement:
 **
 **                           1- Check the validity of FingerPrint data
 **
 **                           2- the writing in non-volatile memory of the
 **                            Fingerprint data (pubRamBuffer points on the
 **                            dataIdentifier field of the WriteDataByIdentifier
 **                            request)
 **                            Asynchronous management can be implemented, in this case
 **                            PROG_E_BUSY value is returned and further call to
 **                            PROG_CustomGetWriteFingerprintStatus will allow
 **                            Bootloader to get writing status
 **
 ** \param[in] pubRamBuffer pointer to a RAM buffer where the DID identifier and fingerprint data
**                          are located
 **
 ** \return Result
 ** \retval PROG_E_OK Write Fingerprint ok
 ** \retval PROG_E_NOT_OK Write Fingerprint failed
 ** \retval PROG_E_BUSY Write Fingerprint in progress
 **/
tProgStatus PROG_CustomWriteFingerprint(u8 * pubRamBuffer)
{
    tProgStatus eProgStatus = PROG_E_OK;
    u8 ubIdx;

    for(ubIdx = 0U; ubIdx < PROG_FINGERPRINT_LENGTH; ubIdx++)
    {
        m_aubFingerPrint[ubIdx] = pubRamBuffer[(2U + ubIdx)];
    }

    return eProgStatus;
}

/** \brief Get the status of the fingerprint writing
 **
 ** Callback is called: After PROG_CustomWriteFingerprint returns PROG_E_BUSY, this
 **                     callback is called periodically until getting a status
 **                     different from PROG_E_BUSY
 **
 ** Callback shall implement: provide status of the fingerprint writing
 **
 ** \return Result
 ** \retval PROG_E_OK Write Fingerprint ok
 ** \retval PROG_E_NOT_OK Write Fingerprint failed
 ** \retval PROG_E_BUSY Write Fingerprint in progress
 **/
tProgStatus PROG_CustomGetWriteFingerprintStatus(void)
{
    /* Writting of fingerprint is synchronous this API will never be called */
    return PROG_E_OK;
}

/** \brief Store the reset cause and the need of response
 **
 ** Callback is called: Before Bootloader perform a reset to set reset cause
 **                     (UDS request that has caused the reset).
 **
 ** Callback shall implement: storage of the reset cause (UDS request)
 **
 ** \param[in] ubResetCause the reset cause
 ** \param[in] ubSendResp the need of response according to suppressPositiveResponse bit
 **            from the request
 **
 **/
void PROG_CustomStoreResetCause(tProgResCause ubResetCause, tProgBoolean ubSendResp)
{
    stNoIntShareVar.ubResetCause = ubResetCause;
    stNoIntShareVar.ubResponseRequired = ubSendResp;
}
/** \brief Restore the reset cause and the need of response
 **
 ** Callback is called: At Bootloader startup to get the UDS request that has caused
 **                    the reset.
 **
 ** Callback shall implement: provide the cause of the reset (UDS request) that has been
 **                           set by application or Bootloader (by call to
 **                           PROG_CustomStoreResetCause)
 **
 ** \param[out] pubResetCause pointer to the reset cause
 ** \param[out] pubSendResp Provide information if positive response shall be sent
 **             depending of the value of the suppressPositiveResponse bit from the request
 **             TRUE: response shall be sent / FALSE: no response shall be sent
 **
 **/
void PROG_CustomGetResetCause(tProgResCause* pubResetCause, tProgBoolean* pubSendResp)
{
    *pubResetCause = stNoIntShareVar.ubResetCause;
    *pubSendResp = stNoIntShareVar.ubResponseRequired;
}

/** \brief Check if all the programming pre-conditions are met
 **
 ** Callback is called: On Programming precondition check
 **
 ** Callback shall implement: programming precondition check. Inform Bootloader
 **                           if the ECU is in a state where programming can be
 **                           performed. If condition are not correct programming
 **                           will be rejected by Bootloader and negative response
 **                           will be sent on the network.
 **
 ** \return state
 ** \retval PROG_E_OK All the programming pre-conditions are met
 ** \retval PROG_E_NOT_OK At least one programming pre-condition is NOT met
 **
 **/
tProgStatus PROG_CustCheckProgPrecond(void)
{

    return PROG_E_OK;
}

/** \brief Callback called after comparing the expected checksum or signature and the calculated one.
 **
 ** Callback is called: After a successful or unsuccessful download verification
 **
 ** Callback shall implement: update of the logical block validity status
 **
 ** \param[in] ubLogicalBlockId The id of the logical block for which the compare was done
 ** \param[in] ubLogicalSegmentId The id of the logical segment  for which the compare was done
 **            (ignore if the full logical block is verified)
 ** \param[in] ubCompareSuccess TRUE if the 2 elements of the comparison are identical
 **
 ** \return state
 ** \retval PROG_E_OK Treatment finish successfully
 ** \retval PROG_E_NOT_OK Error happened during treatment
 **/
tProgStatus PROG_CustomSetDownloadVerificationSuccess(u8 ubLogicalBlockId, u8 ubLogicalSegmentId, tProgBoolean ubCompareSuccess)
{
    /* Parameter not needed here */
    tProgStatus eProgStatus;
    tProgMemType eMemType;
    u32 ulAddress;

    OSC_PARAM_UNUSED(ubLogicalSegmentId);

    eProgStatus = PROG_E_NOT_OK;
    if(PROG_TRUE == ubCompareSuccess)
    {
        /* Retrieve revoked flag of the block */
        ulAddress = (stConfigSegment[(stCfgBlock[ubLogicalBlockId].ubFirstSegmentId + stCfgBlock[ubLogicalBlockId].ubSegmentNbr) - 1U].ulEraseEndAddress - PROG_MIN_VAL_TO_WRITE + 1U);
        eMemType = m_astCfgMemory[stConfigSegment[(stCfgBlock[ubLogicalBlockId].ubFirstSegmentId + stCfgBlock[ubLogicalBlockId].ubSegmentNbr) - 1U].ubMemoryIdx].eMemoryType;

        eProgStatus = PROG_MemDataAccess(eMemType,PROG_MEM_OPERATION_TYPE_WRITE,ulAddress,PROG_MAGIC_NUM_SIZE, (u8*)m_aMagicNumProgrammedValue);

    }


    return eProgStatus;
}

/** \brief Callback for CRC storage
 **
 ** Callback is called: After CRC calculation
 **
 ** Callback shall implement: storage of the CRC value for further use
 **
 ** \param[in] ulCrcVal CRC value
 **
 **/
void PROG_CustomWriteCRC(u32 ulCrcVal)
{
    OSC_PARAM_UNUSED(ulCrcVal);
}

/** \brief This API is called  to do the coherency check treatment
 **
 ** Callback is called: on the coherency check request reception
 **
 ** Callback shall implement: the algorithm performing the coherency check of the previously programmed blocks (E.g.: checking of blocks verions compatibility).
 **
 ** \param[out] eCohChkResult The result of the coherency check.
 **             Can be: 0-correct, 1-incorrect, 2-incorrect error SW-HW, 3-incorrect error SW-SW, 4-incorrect other error
 **
 ** \return Coherency Check result
 ** \retval PROG_E_OK when the check has finished
 ** \retval PROG_E_BUSY if the check is on going
 **/
tProgStatus PROG_CustomCoherencyCheck(tProgCohChkResult* eCohChkResult)
{
    u8 ubIdx;

    *eCohChkResult = PROG_COHERENCY_OK;

    /* return value set following DRECU-III-268 requirement */

    /* Check if all block have are valid */
    for(ubIdx = 0U; (ubIdx < PROG_BLOCK_NBR) ; ubIdx++)
    {
        if(PROG_IsBlockValid(ubIdx) == PROG_BLOCK_INVALID)
        {
            *eCohChkResult = PROG_COHERENCY_ERR_INVALID_BLOCK;
        }
    }

    if(*eCohChkResult == PROG_COHERENCY_OK)
    {
        /* Here check if SW/HW are matching, return PROG_COHERENCY_ERR_HW_SW and set ubStatusInformation Bit 2 ? Software/Hardware mismatch */
        /* Then check if SW/HW are matching, return PROG_COHERENCY_ERR_SW_SW and set ubStatusInformation Bit 1 ? Software/Software mismatch */
        /* Then check if internal error occured, return PROG_COHERENCY_ERR */

        /* if all check OK Set Reprogramming Process State to Block valid */
        stNVMBootloaderData.stNVMEcuData.ubECUProgInfo = PROG_ECUPROGINFO_CONSISTENT;
    }

    /* coherency is for now synchronous Ok is return in the first call*/
    return PROG_E_OK;
}


/** \brief API to get the stored value of the programming counter.
 **
 ** \param[in] ubBlockId BlockID
 **
 ** Callback is called: Before erasing the block
 **
 ** Callback shall implement: return the current value of the programming counter
 **
 ** \return programming counter on 16 bits
 **/
u16 PROG_CustomGetProgCounter(u8 ubBlockId)
{
    return stNVMBootloaderData.stNVMBlockData[ubBlockId].uwProgCounter;
}

/** \brief API to increment the programming counter for the erased logical block.
 **
 ** This API is called to increment the programming counter of the block.
 ** The maximum value shall be limited at 0xFFFF and it shall not overflow.
 **
 ** \param[in] ubBlockId BlockID
 **
 ** Callback is called: Before erasing the block
 **
 ** Callback shall implement: increment the current value of the programming counter
 **
 ** \return Result of incrementation operation
 ** \retval PROG_E_OK incrementation operation finished successfully
 ** \retval PROG_E_NOT_OK incrementation operation error happened
 **
 **/
/*---------------------------{PROG_CustomIncrementProgCounter}-----------------------------*/
tProgStatus PROG_CustomIncrementProgCounter(u8 ubBlockId)
{
    stNVMBootloaderData.stNVMBlockData[ubBlockId].uwProgCounter++;
    return PROG_E_OK;
}
/*------------------------{end PROG_CustomIncrementProgCounter}--------------------------*/

/** \brief This API allows the integrator to store the informations regarding the partial software download for a specific blockId.
        The callback is called after each successfull CheckMemory routine processing.
 **
 ** \param[in] ubBlockId block Id for which the information is stored
 ** \param[out] aulSegProgSize pointer to an array containining the size of programmed data for each segment in the block
 ** \param[out] ubSegNbr number of the segments programmed
 **
 **/
/*---------------------------{PROG_CustomGetPartProgSegList}-----------------------------*/
void PROG_CustomGetPartProgSegList(u8 ubBlockId,u32* aulSegProgSize,u8* ubSegNbr)
{
    u8 i;

    *ubSegNbr = stNVMBootloaderData.stNVMBlockData[ubBlockId].stSegmentList.ubNbSegNbr;
    
    for (i=0; i<stNVMBootloaderData.stNVMBlockData[ubBlockId].stSegmentList.ubNbSegNbr; i++)
    {
      aulSegProgSize[i] = stNVMBootloaderData.stNVMBlockData[ubBlockId].stSegmentList.aulSegProgSize[i];
    }
}

/** \brief This API allows the integrator to store the informations regarding the partial software download for a specific blockId.
        The callback is called after each successfull CheckMemory routine processing.
 **
 ** \param[in] ubBlockId block Id for which the information is stored
 ** \param[in] aulSegProgSize pointer to an array containining the size of programmed data for each segment in the block
 ** \param[in] ubSegNbr number of the segments programmed
 **
 **/
/*---------------------------{PROG_CustomSetPartProgSegList}-----------------------------*/
void PROG_CustomSetPartProgSegList(u8 ubBlockId,u32* aulSegProgSize,u8* ubSegNbr)
{
    u8 ubSegIndex;

    stNVMBootloaderData.stNVMBlockData[ubBlockId].stSegmentList.ubNbSegNbr = *ubSegNbr;

    for (ubSegIndex = 0; ubSegIndex < stNVMBootloaderData.stNVMBlockData[ubBlockId].stSegmentList.ubNbSegNbr; ubSegIndex++)
    {
      stNVMBootloaderData.stNVMBlockData[ubBlockId].stSegmentList.aulSegProgSize[ubSegIndex] = aulSegProgSize[ubSegIndex];
    }
}


/** \brief This API allows the integrator to clear the informations stored in the non-volatile memory regarding the partial software download for a specific block.
        The callback is called at every block erase
 **
 ** \param[in] ubBlockId block Id for which the information is stored
 **
 **/
void PROG_CustomClearPartProgSegList(u8 ubBlockId)
{
    u8 i;

    stNVMBootloaderData.stNVMBlockData[ubBlockId].stSegmentList.ubNbSegNbr = 0U;
    
    for (i=0; i < PROG_SEGMENT_NB; i++)
    {
        stNVMBootloaderData.stNVMBlockData[ubBlockId].stSegmentList.aulSegProgSize[i] = 0U;
    }
}

tUdsStatus PROG_CustomGetFingerprint(u16 *puwLen, u8 *aubUdsData)
{
    u8 ubBlockIdx;
    u8 ubIdx;

    for(ubBlockIdx = 0U; ubBlockIdx < PROG_BLOCK_NBR; ubBlockIdx++)
    {
        /* Dummy length to allow positive response */
        for(ubIdx = 0U; ubIdx < PROG_FINGERPRINT_LENGTH; ubIdx++)
        {
            aubUdsData[(PROG_FINGERPRINT_LENGTH * ubBlockIdx) + ubIdx + 3U] = stNVMBootloaderData.stNVMBlockData[0].aubFingerPrintInfo[ubIdx];
        }
        
        aubUdsData[(PROG_FINGERPRINT_LENGTH * ubBlockIdx) + PROG_FINGERPRINT_LENGTH + 4U] = stNVMBootloaderData.stNVMBlockData[0].aubFingerPrintInfo[ubIdx];
    }

    *puwLen = (PROG_BLOCK_NBR*(PROG_FINGERPRINT_LENGTH + 1)) + 3U;

    return UDS_ACK;
}

/** \brief Get the public key modulus and exponent when using asymmetric cryptography. Used in SA_InitCrypto
 **
 ** \param[out] paubPublicModulus Pointer to asymmetric cryptography public key modulus array
 ** \param[out] pulPublicExponent Pointer to asymmetric cryptography public key exponent
 **
 **/
/*---------------------------{PROG_CustomGetAsymPublicKey}-----------------------------*/
void PROG_CustomGetAsymPublicKey(const u8** paubPublicModulus, u32* pulPublicExponent)
{
    *paubPublicModulus = m_aubPROGPublicModulus;
    *pulPublicExponent = m_ulPROGPublicExponent;
}
/*------------------------{end PROG_CustomGetAsymPublicKey}--------------------------*/


/** \brief Get the TP Blocksize value
 **
 ** \param[inout] ubTpBsValue Blocksize value
 **
 ** \return return Get TP value status
 ** \retval PROG_E_OK
 ** \retval PROG_E_NOT_OK
 **/
tProgStatus PROG_CustomGetTpBsValue(u8* ubTpBsValue)
{
    *ubTpBsValue = 0x00U;

    return PROG_E_OK;
}



/** \brief Notification of a download event
 **
 ** Callback is called: On reception of RequestDownload routine
 **
 ** Callback shall implement: provide information that the Flash Memory was programmed and should be erased before a new writing and customer specific implementation on download event
 **
 ** \param[in] ulStartAddress received start address value
 ** \param[in] ulMemorySize received memory size value
 **
 ** \return eProgStatus success of the operation
 ** \retval PROG_E_OK
 ** \retval PROG_E_NOT_OK
 **/
tProgStatus PROG_CustomDownloadNotification(u32 ulStartAddress, u32 ulMemorySize)
{
    OSC_PARAM_UNUSED(ulStartAddress);
    OSC_PARAM_UNUSED(ulMemorySize);
    return PROG_E_OK;
}

/** \brief Get the erase status of the memory block
 **
 ** Callback is called: On reception of Erase routine
 **
 ** Callback shall implement: provide information if logical block is already
 **                           erase and that erase shall be skipped
 **
 ** \param[in] ulBlockId ID of the Memory block to be erased
 **
 ** \return state
 ** \retval PROG_E_ERASED Memory block is erased
 ** \retval PROG_E_NOT_ERASED Memory block is not erased
 **/
tProgEraseStatus PROG_CustomGetEraseStatus(u8 ubBlockId)
{
    tProgEraseStatus eEraseStatus;

    eEraseStatus = PROG_E_NOT_ERASED;

    if((stNVMBootloaderData.stNVMBlockData[ubBlockId].ubStatusInformation & PROG_INFO_MEMORY_STATUS)
            != 0U)
    {
        eEraseStatus = PROG_E_ERASED;
    }

    return eEraseStatus;
}
/** \brief Set the status of the memory block erase
 **
 ** Callback is called: After successful logical block erasing and
 **                     RequestDownload request reception
 **
 ** Callback shall implement: storage of the logical block erase status
 **
 ** \param[in] ubBlockId ID of the Memory block to be erased
 ** \param[in] eEraseStatus The result of the erase
 **
 ** \return status
 ** \retval PROG_E_OK Erase status set
 ** \retval PROG_E_NOT_OK Erase status not set
 **/
tProgStatus PROG_CustomSetEraseStatus(u8 ubBlockId, tProgEraseStatus eEraseStatus)
{
    /* If notification of erased */
    if(eEraseStatus == PROG_E_ERASED)
    {
        /* Set Memory status of block as erased */
        stNVMBootloaderData.stNVMBlockData[ubBlockId].ubStatusInformation |= PROG_INFO_MEMORY_STATUS;

        /* Set Reprogramming Process State to Memory erase finished */
        stNVMBootloaderData.stNVMBlockData[ubBlockId].ubStatusInformation &= (u8)(~PROG_INFO_REPROG_STATE_MASK);
        stNVMBootloaderData.stNVMBlockData[ubBlockId].ubStatusInformation |= PROG_INFO_REPROG_STATE_ERASED_END;
    }
    /* Notification of reprogramming start */
    else
    {
        /* Set Memory status of block as not erased */
        stNVMBootloaderData.stNVMBlockData[ubBlockId].ubStatusInformation &= (u8)(~PROG_INFO_MEMORY_STATUS);

        /* Set Reprogramming Process State to Reprogramming started */
        stNVMBootloaderData.stNVMBlockData[ubBlockId].ubStatusInformation &= (u8)(~PROG_INFO_REPROG_STATE_MASK);
        stNVMBootloaderData.stNVMBlockData[ubBlockId].ubStatusInformation |= PROG_INFO_REPROG_STATE_REPROG_START;
    }

    return PROG_E_OK;
}

/** \brief Notification of memory access to allow customers to place their routines
 **
 ** Callback is called: After successful memory data access
 **
 ** Callback shall implement: Operation that need to be performed after a memory data access
 **
 ** \param[in] eMemType Memory type (RAM, Flash and Flash Ext)
 ** \param[in] eOperationType Operation type (Read, write and erase)
 ** \param[in] uMemAddress Start address
 ** \param[in] uLength Data length
 ** \param[in] paubDataBuffer Data buffer
 **
 ** \return eProgStatus success of the operation(s)
 ** \retval PROG_E_OK
 ** \retval PROG_E_NOT_OK
 **/
tProgStatus PROG_CustomMemoryAccessNotification
(
    tProgMemType eMemType,
    tOperationType eOperationType,
    tProgAddressType uMemAddress,
    tDataLength uLength,
    tDataBufferType PROG_FAR_POINTER paubDataBuffer
)
{
    OSC_PARAM_UNUSED(eMemType);
    OSC_PARAM_UNUSED(eOperationType);
    OSC_PARAM_UNUSED(uMemAddress);
    OSC_PARAM_UNUSED(uLength);
    OSC_PARAM_UNUSED(paubDataBuffer);

    return PROG_E_OK;
}


static tProgBoolean PROG_IsBlockValid(u16 ubBlockID)
{
    tProgBoolean eProgBool = PROG_BLOCK_VALID;
    tProgStatus eProgStatus;
    tProgMemType eMemType;
    u8 aubFlag[PROG_MAGIC_NUM_SIZE];
    u32 ulAddress;
    u8 ubIdx;

    /* Retrieve revoked flag of the block */
    ulAddress = (stConfigSegment[(stCfgBlock[ubBlockID].ubFirstSegmentId + stCfgBlock[ubBlockID].ubSegmentNbr) - 1U].ulEraseEndAddress - (2*PROG_MIN_VAL_TO_WRITE) + 1U);
    eMemType = m_astCfgMemory[stConfigSegment[(stCfgBlock[ubBlockID].ubFirstSegmentId + stCfgBlock[ubBlockID].ubSegmentNbr) - 1U].ubMemoryIdx].eMemoryType;

    eProgStatus = PROG_MemDataAccess(eMemType,PROG_MEM_OPERATION_TYPE_READ,ulAddress,PROG_MAGIC_NUM_SIZE, aubFlag);

    if(eProgStatus == PROG_E_OK)
    {
        for(ubIdx = 0U; ((ubIdx <PROG_MAGIC_NUM_SIZE) && (eProgBool == PROG_BLOCK_VALID)); ubIdx++)
        {
            /* Check if the block is invalidate */
            if(aubFlag[ubIdx] != PROG_FLASH_ERASE_VALUE)
            {
                eProgBool = PROG_BLOCK_INVALID;
            }
        }
        if(eProgBool == PROG_TRUE)
        {
            /* Retrieve valid flag of the block */
            ulAddress = (stConfigSegment[(stCfgBlock[ubBlockID].ubFirstSegmentId + stCfgBlock[ubBlockID].ubSegmentNbr) - 1U].ulEraseEndAddress - (PROG_MIN_VAL_TO_WRITE) + 1U);
            eMemType = m_astCfgMemory[stConfigSegment[(stCfgBlock[ubBlockID].ubFirstSegmentId + stCfgBlock[ubBlockID].ubSegmentNbr) - 1U].ubMemoryIdx].eMemoryType;

            eProgStatus = PROG_MemDataAccess(eMemType,PROG_MEM_OPERATION_TYPE_READ,ulAddress,PROG_MAGIC_NUM_SIZE, aubFlag);

            if(eProgStatus == PROG_E_OK)
            {
                for(ubIdx = 0U; ((ubIdx <PROG_MAGIC_NUM_SIZE) && (eProgBool == PROG_BLOCK_VALID)); ubIdx++)
                {
                    /* Check if the block is invalidate */
                    if(aubFlag[ubIdx] != m_aMagicNumProgrammedValue[ubIdx])
                    {
                        eProgBool = PROG_BLOCK_INVALID;
                    }
                }
            }
        }
    }

    return eProgBool;
}
