
/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : IPV_FTFC
* Dependencies : 
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 1.0.1
* Build Version : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
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

#ifndef EEP_H
#define EEP_H

/**
* @file
*
* @addtogroup EEP_DRIVER Eeprom Driver
* @{
*/
/* implements Eep.h_Artifact */
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eep_Cfg.h"
#include "SchM_Eep.h"
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_VENDOR_ID            43
#define EEP_MODULE_ID            90
#define EEP_INSTANCE_ID          0U
#define EEP_AR_RELEASE_MAJOR_VERSION     4
#define EEP_AR_RELEASE_MINOR_VERSION     4
#define EEP_AR_RELEASE_REVISION_VERSION  0
#define EEP_SW_MAJOR_VERSION             1
#define EEP_SW_MINOR_VERSION             0
#define EEP_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Eep_Cfg.h header file are of the same vendor */
#if (EEP_VENDOR_ID != EEP_VENDOR_ID_CFG)
    #error "Eep.h and Eep_Cfg.h have different vendor ids"
#endif
/* Check if header file and Eep_Cfg.h header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION    != EEP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (EEP_AR_RELEASE_MINOR_VERSION    != EEP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (EEP_AR_RELEASE_REVISION_VERSION != EEP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Eep.h and Eep_Cfg.h are different"
#endif
/* Check if header file and Eep_Cfg.h header file are of the same software version */
#if ((EEP_SW_MAJOR_VERSION != EEP_SW_MAJOR_VERSION_CFG) || \
     (EEP_SW_MINOR_VERSION != EEP_SW_MINOR_VERSION_CFG) || \
     (EEP_SW_PATCH_VERSION != EEP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Eep.h and Eep_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h file are of the same version */
    #if ((EEP_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Eep.h and StandardTypes.h are different"
    #endif
    /* Check if current file and SchM_Eep.h file are of the same version */
    #if ((EEP_AR_RELEASE_MAJOR_VERSION != SCHM_EEP_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_AR_RELEASE_MINOR_VERSION != SCHM_EEP_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Eep.h and SchM_Eep.h are different"
    #endif
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eep_MemMap.h"

EEP_CONFIG_EXT

#define EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eep_MemMap.h"

/**
* @brief          Development error codes (passed to DET).
*
*/

/**
*   @brief service ID of function: Eep_Init. (passed to DET)
*/
#define EEP_E_INIT_FAILED            0x10U
/**
*   @brief service ID of error: TargetAddress is not in range and aligned to first byte of eeprom sector. (passed to DET)
*/
#define EEP_E_PARAM_ADDRESS          0x11U
/**
*   @brief service ID of error: NULL_PTR == SourceAddressPtr. (passed to DET)
*/
#define EEP_E_PARAM_DATA             0x12U
/**
*   @brief service ID of error: TargetAddress is not in range and aligned to last byte of eeprom sector. (passed to DET)
*/
#define EEP_E_PARAM_LENGTH           0x13U
/**
*   @brief service ID of error: API service called without module initialization. (passed to DET)
*/
#define EEP_E_UNINIT                 0x20U
/**
*   @brief service ID of error: API service called while driver still busy. (passed to DET)
*/
#define EEP_E_BUSY                   0x21U
/**
*   @brief service ID of error: The hardware operation did not finish before timeout expired. (passed to DET)
*/
#define EEP_E_TIMEOUT                0x22U
/**
*   @brief service ID of error:  NULL_PTR passed. (passed to DET)
*/
#define EEP_E_PARAM_POINTER          0x23U

/**
* @brief          All service IDs (passed to DET).
*
*/
#define EEP_INIT_ID                  0x00U
#define EEP_SETMODE_ID               0x01U
#define EEP_READ_ID                  0x02U
#define EEP_WRITE_ID                 0x03U
#define EEP_ERASE_ID                 0x04U
#define EEP_COMPARE_ID               0x05U
#define EEP_CANCEL_ID                0x06U
#define EEP_GETJOBRESULT_ID          0x08U
#define EEP_MAINFUNCTION_ID          0x09U
#define EEP_GETVERSIONINFO_ID        0x0AU
#define EEP_QUICK_WRITE_ID           0x0BU

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/**
* @brief    Start of Eep section CODE
*/
#define EEP_START_SEC_CODE
#include "Eep_MemMap.h"

/**
* @brief        The function initializes Eep module.
* @details      The function sets the internal module variables according to given
*               configuration set.
*
* @param[in]    ConfigPtr        Pointer to eeprom driver configuration set.
*
* @api
*
* @pre          @p ConfigPtr must not be @p NULL_PTR and the module status must not
*               be @p MEMIF_BUSY.
**
*/
void Eep_Init(const Eep_ConfigType * ConfigPtr);

/**
* @brief            Write one or more complete eeprom pages to the eeprom device.
* @details          Starts a write job asynchronously. The actual job is performed by
*                   Eep_MainFunction.
*
* @param[in]        EepromAddress        Target address in eeprom memory.
* @param[in]        DataBufferPtr        Pointer to source data buffer.
* @param[in]        Length               Number of bytes to write.
*
* @return           Std_ReturnType
* @retval           E_OK                 Write command has been accepted.
* @retval           E_NOT_OK             Write command has not been accepted.
*
* @api
*
* @pre              The module has to be initialized and not busy.
**
*/
Std_ReturnType Eep_Write(Eep_AddressType EepromAddress,
                         const uint8 * DataBufferPtr,
                         Eep_LengthType Length
                        );

#if (EEP_QUICK_WRITES_API == STD_ON)

/**
* @brief            Write one or more complete eeprom pages to the eeprom device in quick write mode.
* @details          Starts a write job asynchronously. The actual job is performed by
*                   Eep_MainFunction.
*
* @param[in]        TargetAddress               Target address in eeprom memory.
* @param[in]        SourceAddressPtr            Pointer to source data buffer.
* @param[in]        Length                      Number of bytes to write.
* @param[in]        u16QuickWritesLength        Number of bytes to allocated for quick write
*
* @return           Std_ReturnType
* @retval           E_OK                 Write command has been accepted.
* @retval           E_NOT_OK             Write command has not been accepted.
*
* @api
*
* @pre              The module has to be initialized and not busy.*/
Std_ReturnType Eep_QuickWrite(Eep_AddressType u32TargetAddress,
                              uint8 const * pSourceAddressPtr,
                              Eep_LengthType u32Length,
                              uint16 u16QuickWritesLength
                             );

#endif /* EEP_QUICK_WRITES_API */

/**
* @brief            Erase memory by writing erase value.
* @details          Starts an erase job asynchronously. The actual job is performed
 *                  by the Eep_MainFunction.
*
* @param[in]        EepromAddress        Target address in eeprom memory.
* @param[in]        Length               Number of bytes to erase by writing the erased value.
*
* @return           Std_ReturnType
* @retval           E_OK                    Erase command has been accepted.
* @retval           E_NOT_OK                Erase command has not been accepted.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post
**
*/
Std_ReturnType Eep_Erase(Eep_AddressType EepromAddress,
                         Eep_LengthType Length
                        );

#if (EEP_CANCEL_API == STD_ON)
/**
* @brief            Cancel an ongoing eeprom read, write, erase or compare job.
* @details          Abort a running job synchronously so that directly after returning
*                   from this function a new job can be started.
*
* @api
*
* @pre              The module must be initialized.
* @post             @p Eep_Cancel changes module status and @p Eep_eJobResult
*                   internal variable.
**/
void Eep_Cancel(void);
#endif

#if (EEP_GET_STATUS_API == STD_ON)
/**
* @brief            Returns the EEP module status.
* @details          Returns the EEP module status synchronously.
*
* @return           MemIf_StatusType
* @retval           MEMIF_UNINIT        Module has not been initialized (yet).
* @retval           MEMIF_IDLE          Module is currently idle.
* @retval           MEMIF_BUSY          Module is currently busy.
*
* @api
**/
MemIf_StatusType Eep_GetStatus(void);
#endif

#if (EEP_GET_JOB_RESULT_API == STD_ON)
/**
* @brief            Returns the result of the last job.
* @details          Returns synchronously the result of the last job.
*
* @return           MemIf_JobResultType
* @retval           MEMIF_JOB_OK              Successfully completed job.
* @retval           MEMIF_JOB_FAILED          Not successfully completed job.
* @retval           MEMIF_JOB_PENDING         Still pending job (not yet completed).
* @retval           MEMIF_JOB_CANCELED        Job has been canceled.
* @retval           MEMIF_BLOCK_INCONSISTENT  Inconsistent block requested, it may
*                                             contains corrupted data.
* @retval           MEMIF_BLOCK_INVALID       Invalid block requested.
*
* @api
**/
MemIf_JobResultType Eep_GetJobResult(void);
#endif

/**
* @brief            Reads from eeprom memory.
* @details          Starts a read job asynchronously. The actual job is performed by
*                   @p Eep_MainFunction.
*
* @param[in]        EepromAddress        Source address in eeprom memory.
* @param[in]        Length               Number of bytes to read.
* @param[out]       DataBufferPtr        Pointer to target data buffer.
*
* @return           MemIf_JobResultType
* @retval           MEMIF_JOB_OK              Successfully completed job.
* @retval           MEMIF_JOB_FAILED          Not successfully completed job.
* @retval           MEMIF_JOB_PENDING         Still pending job (not yet completed).
* @retval           MEMIF_JOB_CANCELED        Job has been canceled.
* @retval           MEMIF_BLOCK_INCONSISTENT  Inconsistent block requested, it may
*                                             contains corrupted data.
* @retval           MEMIF_BLOCK_INVALID       Invalid block requested.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post
**
*/
Std_ReturnType Eep_Read(Eep_AddressType EepromAddress,
                        uint8 * DataBufferPtr,
                        Eep_LengthType Length
                       );

#if (EEP_COMPARE_API == STD_ON)
/**
* @brief           Compares a eeprom memory area with an application data buffer.
* @details         Starts a compare job asynchronously. The actual job is performed by
*                  Eep_MainFunction.
*
* @param[in]        EepromAddress          Source address in eeprom memory.
* @param[in]        DataBufferPtr       Pointer to source data buffer.
* @param[in]        Length                 Number of bytes to compare.
*
* @return           Std_ReturnType
* @retval           E_OK                      Compare command has been accepted.
* @retval           E_NOT_OK                   Compare command has not been accepted.
*
* @api
*
* @pre            The module has to be initialized and not busy.
**/
Std_ReturnType Eep_Compare(Eep_AddressType EepromAddress,
                           const uint8 * DataBufferPtr,
                           Eep_LengthType Length
                          );
#endif

#if (EEP_SET_MODE_API == STD_ON)
/**
* @brief           Sets the EEP module's operation mode to the given Mode.
* @details         Every given mode determinates maximum bytes for read-write
 *                 operations. Every mode has a set of pre-configured values.
*
* @param[in]        Mode        MEMIF_MODE_FAST or MEMIF_MODE_SLOW.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post           @p Eep_SetMode changes internal variables @p Eep_u32MaxRead and
*                 @p Eep_u32MaxWrite.
**/
void Eep_SetMode(MemIf_ModeType Mode);
#endif

#if (EEP_VERSION_INFO_API == STD_ON)
/**
* @brief        Returns version information about EEP module.
* @details      Version information includes:
*               - Module Id
*               - Vendor Id
*               - Vendor specific version numbers (BSW00407).
*
* @param[in,out] versioninfo  Pointer to where to store the version information of this module.
*
* @api
**
*/
void Eep_GetVersionInfo(Std_VersionInfoType * versioninfo);
#endif

/**
* @brief    Stop of Eep section CODE
*/
#define EEP_STOP_SEC_CODE
#include "Eep_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif /* EEP_H */

/** @} */
