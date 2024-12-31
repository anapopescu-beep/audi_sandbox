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
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.48.0 BL3 */
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
#include "PROG_Hsm.h"
#include "PROG_HsmPROG.h"
#include "board.h"

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */


/** \brief API that check if a programming request has been received by the application
 **
 ** Callback is called: at Bootloader startup to know if a programming request has
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
    return 0U;
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

}

/** \brief API that returns information if a programming request has been received by the application
 **
 ** Callback is called: at reception of a request in BlPduR module to ignore the request if Rx simulation  
 **                           request is ongoing (programming request has been received by the application)
 **
 ** Callback shall implement: returns information from application if a programming
 **                          request has been received or not (e.g: from PROG_CheckProgRequest API)
 **
 ** \return Information checked in PROG_CheckProgRequest API
 ** \retval TRUE Reprogramming request has been received in Application
 ** \retval FALSE Reprogramming request has been received in Application
 **/
tProgBoolean PROG_ReturnsIsReProgRequestFromAppli(void)
{
    return FALSE;
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

/** \brief Callback that shall request data decryption before writing them to memory
 ** Callback is called: receiving a TransferData before the decompression (if activated)
 **
 ** Callback shall implement: If needed, it shall decrypt the received data according to the EncryptingMethod.
 **
 ** \param[in] ubEncryptionMethod Encrypting method  indicator (from RequestDownload dataFormatIdentifier field)
 ** \param[in,out] pubData received data pointer (points to the encrypted data and callback implementation shall copy decrypted data at the same location than the encrypted one.)
 ** \param[in] DataLength received data length
 **
 ** \return Result of the decryption
 ** \retval PROG_E_OK Decryption finish successfully
 ** \retval PROG_E_NOT_OK Error happened during decryption
 **/
tProgStatus PROG_CustomDecryptData(u8 ubEncryptionMethod, u8 * pubData, PduLengthType DataLength)
{
    OSC_PARAM_UNUSED(ubEncryptionMethod);
    OSC_PARAM_UNUSED(pubData);
    OSC_PARAM_UNUSED(DataLength);

    return PROG_E_OK;
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
    return FALSE;
}



/*------------------------------{PROG_CustomSetOpenProgSession}---------------------------*/

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
    OSC_PARAM_UNUSED(ubBlockId);

    return PROG_E_OK;
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
    return FALSE;
}

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
 **                         are located
 **
 ** \return Result
 ** \retval PROG_E_OK Write Fingerprint ok
 ** \retval PROG_E_NOT_OK Write Fingerprint failed
 ** \retval PROG_E_BUSY Write Fingerprint in progress
 **/
tProgStatus PROG_CustomWriteFingerprint(u8 * pubRamBuffer)
{
    OSC_PARAM_UNUSED(pubRamBuffer);
    return PROG_E_OK;
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
    OSC_PARAM_UNUSED(ubResetCause);
    OSC_PARAM_UNUSED(ubSendResp);
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
    OSC_PARAM_UNUSED(pubResetCause);
    OSC_PARAM_UNUSED(pubSendResp);
}
/** \brief Check if all the programming pre-conditions are met
 **
 ** Callback is called: On Programming precondition check
 **
 ** Callback shall implement: programming precondition check. Inform Bootloader
 **                           if the ECU is in a state where programming can be
 **                           performed. It shall check for the error condition Security access 
 **                           if locked and update error list (m_aubPreProgErrorList).
 **                           If condition are not correct programming will be rejected by Bootloader 
 **                           and negative response will be sent on the network.
 **
 ** \return state
 ** \retval PROG_E_OK All the programming pre-conditions are met
 ** \retval PROG_E_NOT_OK At least one programming pre-condition is NOT met
 **
 **/
tProgStatus PROG_CustCheckProgPrecond(tUdsStatus * ubDiagStatus)
{
    tProgStatus eProgStatus = PROG_E_OK;
    OSC_PARAM_UNUSED(ubDiagStatus);
    return eProgStatus;
}
/** \brief Callback called after comparing the expected checksum or signature and the calculated one.
 **
 ** Callback is called: After a successful or unsuccessful download verification
 **
 ** Callback shall implement: update the external global variable m_aubBlockDownloadStatus for the logical block validity status
 **                           If Dual bank feature is used, this call back can be used to know that a complete, 
 **                           and successful application download happened and therefore allow bank swaps
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
    OSC_PARAM_UNUSED(ubLogicalBlockId);
    OSC_PARAM_UNUSED(ubLogicalSegmentId);
    OSC_PARAM_UNUSED(ubCompareSuccess);

    return PROG_E_OK;
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
 ** Callback shall implement: the algorithm performing the coherency check of the previously programmed blocks (E.g.: checking of blocks versions compatibility).
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
    OSC_PARAM_UNUSED(eCohChkResult);
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
/*---------------------------{PROG_CustomGetProgCounter}-----------------------------*/
u16 PROG_CustomGetProgCounter(u8 ubBlockId)
{
    OSC_PARAM_UNUSED(ubBlockId);
    return 0x0000U;
}
/*------------------------{end PROG_CustomGetProgCounter}--------------------------*/


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
    OSC_PARAM_UNUSED(ubBlockId);
    return PROG_E_OK;
}
/*------------------------{end PROG_CustomIncrementProgCounter}--------------------------*/


/** \brief This API allows the integrator to store information regarding the partial software download for a specific blockId.
        The callback is called after each successful CheckMemory routine processing.
 **
 ** \param[in] ubBlockId block Id for which the information is stored
 ** \param[out] aulSegProgSize pointer to an array containing the size of programmed data for each segment in the block
 ** \param[out] ubSegNbr number of the segments programmed
 **
 **/
/*---------------------------{PROG_CustomGetPartProgSegList}-----------------------------*/
void PROG_CustomGetPartProgSegList(u8 ubBlockId,u32* aulSegProgSize,u8* ubSegNbr)
{
    OSC_PARAM_UNUSED(ubBlockId);
    OSC_PARAM_UNUSED(aulSegProgSize);
    OSC_PARAM_UNUSED(ubSegNbr);
}
/*------------------------{end PROG_CustomGetPartProgSegList}--------------------------*/

/** \brief This API allows the integrator to store information regarding the partial software download for a specific blockId.
        The callback is called after each successful CheckMemory routine processing.
 **
 ** \param[in] ubBlockId block Id for which the information is stored
 ** \param[in] aulSegProgSize pointer to an array containing the size of programmed data for each segment in the block
 ** \param[in] ubSegNbr number of the segments programmed
 **
 **/
/*---------------------------{PROG_CustomSetPartProgSegList}-----------------------------*/
void PROG_CustomSetPartProgSegList(u8 ubBlockId,u32* aulSegProgSize,u8* ubSegNbr)
{
    OSC_PARAM_UNUSED(ubBlockId);
    OSC_PARAM_UNUSED(aulSegProgSize);
    OSC_PARAM_UNUSED(ubSegNbr);
}
/*------------------------{end PROG_CustomSetPartProgSegList}--------------------------*/

/** \brief This API allows the integrator to clear information stored in the non-volatile memory regarding the partial software download for a specific block.
        The callback is called at every block erase
 **
 ** \param[in] ubBlockId block Id for which the information is stored
 **
 **/
/*---------------------------{PROG_CustomClearPartProgSegList}-----------------------------*/
void PROG_CustomClearPartProgSegList(u8 ubBlockId)
{
    OSC_PARAM_UNUSED(ubBlockId);
}
/*------------------------{end PROG_CustomClearPartProgSegList}--------------------------*/




/** \brief Get the public key modulus and exponent when using asymmetric cryptography. Used in SA_InitCrypto
 **
 ** \param[out] paubPublicModulus Pointer to asymmetric cryptography public key modulus array
 ** \param[out] pulPublicExponent Pointer to asymmetric cryptography public key exponent
 **
 **/
/*---------------------------{PROG_CustomGetAsymPublicKey}-----------------------------*/
void PROG_CustomGetAsymPublicKey(const u8** paubPublicModulus, u32* pulPublicExponent)
{
    OSC_PARAM_UNUSED(paubPublicModulus);
    OSC_PARAM_UNUSED(pulPublicExponent);
}
/*------------------------{end PROG_CustomGetAsymPublicKey}--------------------------*/






                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
/** \brief Get the TP Blocksize value
 **
 ** Callback is called:  On bootloader startup or on demand of reprogramming, in order to get the TP Blocksize value used in application
 **
 ** Callback shall implement: The get of the TP Blocksize value used in application. If no valid value is available PROG_E_NOT_OK shall be returned.
 **
 ** \param[in,out] ubTpBsValue Blocksize value
 **
 ** \return return Get TP value status
 ** \retval PROG_E_OK
 ** \retval PROG_E_NOT_OK
 **/
tProgStatus PROG_CustomGetTpBsValue(u8* ubTpBsValue)
{
    OSC_PARAM_UNUSED(ubTpBsValue);

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
 ** \param[in] ubBlockId ID of the Memory block to be erased
 **
 ** \return state
 ** \retval PROG_E_NOT_ERASED
 ** \retval PROG_E_ERASED
 **/
tProgEraseStatus PROG_CustomGetEraseStatus(u8 ubBlockId)
{
    OSC_PARAM_UNUSED(ubBlockId);

    return PROG_E_NOT_ERASED;
}

/** \brief Set the erase status of the memory block
 **
 ** Callback is called: After successful logical block erasing and
 **                     RequestDownload request reception
 **
 ** Callback shall implement: storage of the logical block erase status
 **
 ** \param[in] ubBlockId ID of the Memory block to be erased
 ** \param[in] eEraseStatus New erase status
 **
 ** \return eProgStatus success of the erase status update
 ** \retval PROG_E_OK
 ** \retval PROG_E_NOT_OK
 **/
tProgStatus PROG_CustomSetEraseStatus(u8 ubBlockId,tProgEraseStatus eEraseStatus)
{
    OSC_PARAM_UNUSED(ubBlockId);
    OSC_PARAM_UNUSED(eEraseStatus);

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
 ** \param[in] ulLength Data length
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
    tDataLength ulLength,
    tDataBufferType PROG_FAR_POINTER paubDataBuffer
)
{
    OSC_PARAM_UNUSED(eMemType);
    OSC_PARAM_UNUSED(eOperationType);
    OSC_PARAM_UNUSED(uMemAddress);
    OSC_PARAM_UNUSED(ulLength);
    OSC_PARAM_UNUSED(paubDataBuffer);

    return PROG_E_OK;
}









/** \brief Get initialization vector and its length for decryption
 **
 ** \param[out] pubInitVect pointer to IV array location
 ** \param[out] pulInitVectLength to IV length location
 **
 ** Callback shall implement: Retrieve the IV and its length for decryption
 **
 **/
void PROG_CustomDecryptGetInitVector(const u8** pubInitVect, u32 * pulInitVectLength)
{
    OSC_PARAM_UNUSED(pubInitVect);
    OSC_PARAM_UNUSED(pulInitVectLength);
}

/** \brief Get symetrical decryption key and its length
 **
 ** \param[out] pubKey pointer to key array location
 ** \param[out] pulKeyLength pointer to key length location
 **
 ** Callback shall implement: Retrieve the symetrical decryption key and its length
 **
 **/
void PROG_CustomGetSymDecryptionKey(const u8** pubKey, u32 * pulKeyLength)
{
    OSC_PARAM_UNUSED(pubKey);
    OSC_PARAM_UNUSED(pulKeyLength);
}




