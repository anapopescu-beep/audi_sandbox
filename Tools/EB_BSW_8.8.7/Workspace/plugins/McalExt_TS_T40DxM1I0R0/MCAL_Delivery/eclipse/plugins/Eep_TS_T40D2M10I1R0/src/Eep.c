
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

/**
* @file
*
* @addtogroup EEP_DRIVER Eeprom Driver
* @{
*/
/* implements Eep.c_Artifact */
#ifdef __cplusplus
extern "C"{
#endif

/* Compiler warning eep_c_REF_CW_01: explicit cast discards volatile qualifier.
   The cast is explicit, intended and the casted value is treated properly.
   Sizes of the pointers and integral types for all the supported platforms/compilers are well known
   and the volatile keyword is not needed when using the pointer value as a eeprom address counter,
   as the pointer value is not updated in the DSI interrupt context or by other hardware means.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Eep.h"
#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif

#include "Det.h"

#include "Eep_IPW.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_VENDOR_ID_C                      43
#define EEP_AR_RELEASE_MAJOR_VERSION_C       4
#define EEP_AR_RELEASE_MINOR_VERSION_C       4
#define EEP_AR_RELEASE_REVISION_VERSION_C    0
#define EEP_SW_MAJOR_VERSION_C               1
#define EEP_SW_MINOR_VERSION_C               0
#define EEP_SW_PATCH_VERSION_C               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep header file are of the same vendor */
#if (EEP_VENDOR_ID_C != EEP_VENDOR_ID)
    #error "Eep.c and Eep.h have different vendor ids"
#endif
/* Check if current file and Eep header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION_C    != EEP_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_AR_RELEASE_MINOR_VERSION_C    != EEP_AR_RELEASE_MINOR_VERSION) || \
     (EEP_AR_RELEASE_REVISION_VERSION_C != EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep.c and Eep.h are different"
#endif
/* Check if current file and Eep header file are of the same Software version */
#if ((EEP_SW_MAJOR_VERSION_C != EEP_SW_MAJOR_VERSION) || \
     (EEP_SW_MINOR_VERSION_C != EEP_SW_MINOR_VERSION) || \
     (EEP_SW_PATCH_VERSION_C != EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep.c and Eep.h are different"
#endif

/* Check if current file and Eep_IPW header file are of the same vendor */
#if (EEP_VENDOR_ID_C != EEP_IPW_VENDOR_ID_H)
    #error "Eep.c and Eep_IPW.h have different vendor ids"
#endif
/* Check if current file and Eep_IPW header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION_C    != EEP_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (EEP_AR_RELEASE_MINOR_VERSION_C    != EEP_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (EEP_AR_RELEASE_REVISION_VERSION_C != EEP_IPW_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Eep.c and Eep_IPW.h are different"
#endif
/* Check if current file and Eep_IPW header file are of the same Software version */
#if ((EEP_SW_MAJOR_VERSION_C != EEP_IPW_SW_MAJOR_VERSION_H) || \
     (EEP_SW_MINOR_VERSION_C != EEP_IPW_SW_MINOR_VERSION_H) || \
     (EEP_SW_PATCH_VERSION_C != EEP_IPW_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Eep.c and Eep_IPW.h are different"
#endif

#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((EEP_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Eep.c and Dem.h are different"
    #endif
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((EEP_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Eep.c and Det.h are different"
    #endif
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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

#define EEP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eep_MemMap.h"

/**
* @brief Maximum number of bytes to read or compare in one cycle of Eep_MainFunction
*/
static Eep_LengthType Eep_u32MaxRead;
/**
* @brief Maximum number of bytes to write in one cycle of Eep_MainFunction
*/
static Eep_LengthType Eep_u32MaxWrite;
/**
* @brief Logical address of data block currently processed by Eep_MainFunction
*/
static Eep_AddressType Eep_u32EepromAddrIt;
/**
* @brief Remainin length to be transfered until the end of the job
*/
static  Eep_LengthType Eep_u32RemainingLength;
/**
* @brief Result of last eeprom module job
*
*/
static MemIf_JobResultType Eep_eJobResult;
/**
* @brief Type of currently executed job (erase, write, read, or compare)
*/
static Eep_JobType Eep_eJob;
/**
* @brief Pointer to current eeprom module configuration set
*/
static const Eep_ConfigType * Eep_pConfigPtr;
/**
* @brief Pointer to current eeprom module configuration set
*/


#define EEP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eep_MemMap.h"

#define EEP_START_SEC_VAR_CLEARED_8
#include "Eep_MemMap.h"
/**
* @brief Pointer to current position in source data buffer
* @details Used by both write and compare jobs
*/
static const uint8 * Eep_pu8JobSrcAddrPtr;
/**
* @brief Pointer to current position in target data buffer
* @details Used only by read job
*/
static uint8 * Eep_pu8JobDataDestPtr;

#define EEP_STOP_SEC_VAR_CLEARED_8
#include "Eep_MemMap.h"
#define EEP_START_SEC_VAR_CLEARED_16
#include "Eep_MemMap.h"

/* If FTFC IP is present on the platform */
#if (EEP_QUICK_WRITES_API == STD_ON)
/**
* @brief Requested urgency length to set up number of bytes used for quick writes
* @details Used only by the Eep_QuickWrite, Eep_MainFunction
*/
static uint16 Eep_u16QuickWritesLength;
#endif /* EEP_QUICK_WRITES_API */


#define EEP_STOP_SEC_VAR_CLEARED_16
#include "Eep_MemMap.h"
#define EEP_START_SEC_VAR_CLEARED_32
#include "Eep_MemMap.h"
/**
* @brief Pointer to current eeprom module configuration set
*
*/
static uint32 Eep_u32AccCRCremainder;


#define EEP_STOP_SEC_VAR_CLEARED_32
#include "Eep_MemMap.h"

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define EEP_START_SEC_CODE
#include "Eep_MemMap.h"

static void Eep_InitAllVarriable(void);
static void Eep_AccumulateCRC(uint32 InputData);
static void Eep_ResetCRC(void);
static uint32 Eep_FinalizeCRC (void);
static void Eep_UpdateCRCreminder(Eep_CrcDataSizeType DataSize);
static Eep_CrcType Eep_CalcCfgCRC(void);

#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
static void Eep_ReportDemErrors(void);
static void Eep_ReportDemPasses(void);
#endif
static MemIf_JobResultType Eep_ProcessWriteJob(void);
#if (EEP_QUICK_WRITES_API == STD_ON)
static MemIf_JobResultType Eep_ProcessQuickWriteJob(void);
#endif
static MemIf_JobResultType Eep_ProcessReadJob(void);
#if (EEP_COMPARE_API == STD_ON)
static MemIf_JobResultType Eep_ProcessCompareJob(void);
#endif
static MemIf_JobResultType Eep_ProcessRequestedJobs(Eep_JobType Job);
static void Eep_CallNotification(MemIf_JobResultType JobResult);
static void Eep_EndJobs(void);

#define EEP_STOP_SEC_CODE
#include "Eep_MemMap.h"

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define EEP_START_SEC_CODE
#include "Eep_MemMap.h"

/**
* @brief         Eep_InitAllVarriable
* @details       Initialize global variables to their default values
*
* @param[in]     void
*
* @return        void
* @pre           N/A
*/
static void Eep_InitAllVarriable(void)
{
    /* Initialize all global variable */
    Eep_u32MaxRead         = 0UL;
    Eep_u32MaxWrite        = 0UL;
    Eep_u32EepromAddrIt    = 0UL;
    Eep_u32RemainingLength = 0UL;
    Eep_eJobResult         = MEMIF_JOB_OK;
    Eep_eJob               = EEP_JOB_ERASE;
    Eep_pConfigPtr         = NULL_PTR;
    Eep_pu8JobSrcAddrPtr   = NULL_PTR;
    Eep_pu8JobDataDestPtr  = NULL_PTR;

/* If FTFC IP is present on the platform */
#if (EEP_QUICK_WRITES_API == STD_ON)
    Eep_u16QuickWritesLength = 0U;
#endif

    /* Initialize CRC remainder */
    Eep_u32AccCRCremainder = 0U;
}

/**
* @brief        Function to handle cumulative CRC calculation over input data.
*
* @details      Handles cumulative CRC calculation over input 32-bit data, .
*
* @param[in]    inputData ... data to be CRC-ed
*
* @return       void
* @retval       None.
*
* @pre          Eep_ResetCRC() was executed before the first call of
*               Eep_AccumulateCRC().
*
*
*/
static void Eep_AccumulateCRC(uint32 InputData)
{
    if (0xFFFFU < InputData)
    {
        /* preparation for accumulation of higher 16 bits of the InputData */
        Eep_u32AccCRCremainder = (Eep_u32AccCRCremainder << 16U) | (InputData >> 16U);
        /* make 16-bit accumulated result (in lower 16-bits of Eep_u32AccCRCremainder) */
        Eep_UpdateCRCreminder(EEP_CRC_16_BITS);
    }

    if (0xFFU < InputData)
    {
        /* preparation for accumulation of lower 16 bits of the InputData */
        Eep_u32AccCRCremainder = (Eep_u32AccCRCremainder << 16U) | (InputData & 0x0000FFFFU);
        /* make 16-bit accumulated result (in lower 16-bits of Eep_u32AccCRCremainder) */
        Eep_UpdateCRCreminder(EEP_CRC_16_BITS);
    }
    else
    {
        /* optimization: only 8 LSB bits are processed */
        /* preparation for accumulation of lower 8 bits of the InputData */
        Eep_u32AccCRCremainder = (Eep_u32AccCRCremainder << 8U) | InputData;
        /* make 16-bit accumulated result (in lower 16-bits of Eep_u32AccCRCremainder) */
        Eep_UpdateCRCreminder(EEP_CRC_8_BITS);
    }
}


/**
* @brief        Function to reset CRC calculation.
*
* @details      Resets accumulated Eep_u32AccCRCremainder.
*
* @param[in]    void
*
* @return       void
* @retval       None.
*
* @pre          None.
*
*
*/
static void Eep_ResetCRC(void)
{
    Eep_u32AccCRCremainder = 0U;
}

/**
* @brief        Function to finalize CRC calculation.
*
* @details      Finalizes accumulated CRC computation and resturns the final
*               CRC checksum.
*
* @param[in]    void
*
* @return       uint32
* @retval       The final CRC checksum in the lower 16 bits.
*
* @pre          Eep_AccumulateCRC() was executed at least once before
*               calling Eep_FinalizeCRC().
*
*/
static uint32 Eep_FinalizeCRC(void)
{
    /* add the final 0x0000 to the remainder */
    Eep_u32AccCRCremainder = (Eep_u32AccCRCremainder << 16U);
    /* make the final 16-bit CRC */
    Eep_UpdateCRCreminder(EEP_CRC_16_BITS);

    return Eep_u32AccCRCremainder;
}

/**
* @brief        Function to perfom CRC calculation over input 32-bit data.
*
* @details      Process 32-bit data to 16-bit reminder.
*
* @param[in]    accDataPtr ... ptr to data to be processed
*
* @return       void
* @retval       None.
*
* @pre          Can be called only from Eep_AccumulateCRC().
*
*/

static void Eep_UpdateCRCreminder(Eep_CrcDataSizeType DataSize)
{
    uint32 CrcPolynomSft;
    uint32 LeadingOne;
    uint32 AccDataLoc;
    uint32 LeadingOneInitial;

    switch (DataSize)
    {
        case EEP_CRC_8_BITS:
            CrcPolynomSft = 0x11021U << 7U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 7U;
            break;
        case EEP_CRC_16_BITS:
        default:
            CrcPolynomSft = 0x11021U << 15U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 15U;
            break;
    }

    /* copy static variable to auto (computation over static may be slow) */
    AccDataLoc = Eep_u32AccCRCremainder;

    /* CRC computation */
    for (LeadingOne = LeadingOneInitial; LeadingOne >= 0x00010000U; LeadingOne >>= 1U)
    {
        if ((AccDataLoc & LeadingOne) != 0U)
        {
            AccDataLoc ^= CrcPolynomSft;
        }
        CrcPolynomSft >>= 1U;
    }

    /* copy back to static variable */
    Eep_u32AccCRCremainder = AccDataLoc;
}

/**
* @brief        Calculates CRC over Eep configuration.
*
* @details      Calculates CRC over selected items of Eep configuration set
*               pointed to by ConfigPtr.
*
* @param[in]    ConfigPtr        Pointer to eeprom driver configuration set.
*
* @return       uint32
* @retval       0 .. 0xFFFF (16-bit CRC using CRC-16-CCITT polynomial)
*
* @pre          Eep_pConfigPtr must not be properly initialized.
*
*/

static Eep_CrcType Eep_CalcCfgCRC(void)
{
    /* Reset the accumulated CRC value */
    Eep_ResetCRC();

    /* Accumulate the rest of the params (common for all sectors within a config set) */
    /* CRC - Accumulate eDefaultMode */
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->eDefaultMode);
    /* CRC - Accumulate u32MaxReadFastMode */
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->u32MaxReadFastMode);
    /* CRC - Accumulate u32MaxReadNormalMode */
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->u32MaxReadNormalMode);
    /* CRC - Accumulate u32MaxWriteFastMode */
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->u32MaxWriteFastMode);
    /* CRC - Accumulate u32MaxWriteNormalMode */
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->u32MaxWriteNormalMode);
#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* CRC - Accumulate EEP_E_COMPARE_FAILED */
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_CompareFailedCfg.state);
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_CompareFailedCfg.id);
    /* CRC - Accumulate EEP_E_ERASE_FAILED */
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_EraseFailedCfg.state);
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_EraseFailedCfg.id);
    /* CRC - Accumulate EEP_E_READ_FAILED */
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_ReadFailedCfg.state);
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_ReadFailedCfg.id);
    /* CRC - Accumulate EEP_E_WRITE_FAILED */
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_WriteFailedCfg.state);
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_WriteFailedCfg.id);
    /* CRC - Accumulate EEP_E_BO_MAINTENANCE */
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_BOMaintenanceCfg.state);
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_BOMaintenanceCfg.id);
    /* CRC - Accumulate EEP_E_BO_QUICK_WRITES */
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_BOQuickWritesCfg.state);
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_BOQuickWritesCfg.id);
    /* CRC - Accumulate EEP_E_BO_NORMAL_WRITES */
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_BONormalWritesCfg.state);
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_BONormalWritesCfg.id);
#if (EEP_HIGH_TEMP_CHIP == STD_ON)
    /* CRC - Accumulate EEP_E_MGSTAT_BLOCK */
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_MGSTAT_BlockCfg.state);
    Eep_AccumulateCRC((uint32)Eep_pConfigPtr->Eep_E_MGSTAT_BlockCfg.id);
#endif
#endif


    return ((Eep_CrcType)Eep_FinalizeCRC());
}

/**
* @brief        Function to call notifications
*
* @details      The Eep module shall call the callback function defined in the configuration parameter
*               - EepJobEndNotification when a job has been completed with a positive result:  Read or Write or Erase or
*                Compare finished & data blocks are equal.
*               - EepJobErrorNotification when a job has been canceled or aborted with negative result:read or write or earse or
*                Compare aborted or data blocks are not equal
*
* @param[in]    JobResult ... data
*
* @return       void
* @retval       None.
*
*/
static void Eep_CallNotification(MemIf_JobResultType JobResult)
{
    if (MEMIF_JOB_OK == JobResult)
    {
        if (NULL_PTR != Eep_pConfigPtr->jobEndNotificationPtr)
        {
            /* Call EepJobEndNotification function if configured */
            Eep_pConfigPtr->jobEndNotificationPtr();
        }
        else
        {
            /* Callback notification configured as null pointer */
        }
    }
    else if ((MEMIF_JOB_FAILED  == JobResult) || (MEMIF_BLOCK_INCONSISTENT == JobResult) ||
            (MEMIF_JOB_CANCELED == JobResult) || (MEMIF_JOB_PENDING        == JobResult))
    {
        if (NULL_PTR != Eep_pConfigPtr->jobErrorNotificationPtr)
        {
            /* Call EepJobErrorNotification function if configured */
            Eep_pConfigPtr->jobErrorNotificationPtr();
        }
        else
        {
            /* Callback notification configured as null pointer */
        }
    }
    else
    {
        ;/* Not done yet. There is more data to transfer in following Eep_MainFunction call .*/
    }
}

#if (EEP_COMPARE_API == STD_ON)
/**
* @brief        Pocess the compare job
*
* @details      Compares data from Eep_pu8JobSrcAddrPtr to data from Eep_u32EepromAddrIt
*               of lenth equal to Eep_u32MaxRead or Eep_u32RemainingLength.
*
* @param[in]
*
* @pre          The module must be initialized
*
*
*
*/
static MemIf_JobResultType Eep_ProcessCompareJob(void)
{
    MemIf_JobResultType RetVal    = MEMIF_JOB_PENDING;
    Eep_ReturnType TransferRetVal = EEP_E_OK;
    Eep_LengthType TransfLength;

    /* the function will compare Eep_u32MaxRead or the remaining length */
    /* compute length of transfer */
    if (Eep_u32RemainingLength > Eep_u32MaxRead)
    {
        /* Eep_u32MaxWrite must be transferred */
        TransfLength = Eep_u32MaxRead;
    }
    else
    {
        /* Eep_u32RemainingLength must be transferred */
        TransfLength = Eep_u32RemainingLength;
    }

    /* if there is something to transfer */
    if (TransfLength > 0UL)
    {
        TransferRetVal = Eep_Ipw_CompareSync(Eep_u32EepromAddrIt, Eep_pu8JobSrcAddrPtr, TransfLength);
    }

    /* update variables to be used for the next iteration */
    Eep_pu8JobSrcAddrPtr   = &Eep_pu8JobSrcAddrPtr[TransfLength];
    Eep_u32EepromAddrIt    = Eep_u32EepromAddrIt    + TransfLength;
    Eep_u32RemainingLength = Eep_u32RemainingLength - TransfLength;

    /* check status */
    if (EEP_E_FAILED == TransferRetVal)
    {
        /* job has failed */
        RetVal = MEMIF_JOB_FAILED;
    }

    if (EEP_E_BLOCK_INCONSISTENT == TransferRetVal)
    {
        /* comparison failed */
        RetVal = MEMIF_BLOCK_INCONSISTENT;
    }
    else if ((0UL == Eep_u32RemainingLength) && (EEP_E_OK == TransferRetVal))
    {
        /* the job is finished successfully */
        RetVal = MEMIF_JOB_OK;
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}
#endif

/**
* @brief        Pocess a read job
*
* @details      Reads data from Eep_u32EepromAddrIt to Eep_pu8JobDataDestPtr
*               of lenth equal to Eep_u32MaxRead or Eep_u32RemainingLength.
*
* @param[in]
*
* @pre          The module must be initialized
*
*
*
*/
static MemIf_JobResultType Eep_ProcessReadJob(void)
{
    MemIf_JobResultType RetVal    = MEMIF_JOB_PENDING;
    Eep_ReturnType TransferRetVal = EEP_E_OK;
    Eep_LengthType TransfLength;

    /* transfer information to low level driver */
    /* the function will read Eep_u32MaxRead or the remaining length */
    /* compute length of transfer */
    if (Eep_u32RemainingLength > Eep_u32MaxRead)
    {
        /* Eep_u32MaxWrite must be transferred */
        TransfLength = Eep_u32MaxRead;
    }
    else
    {
        /* Eep_u32RemainingLength must be transferred */
        TransfLength = Eep_u32RemainingLength;
    }

    /* if there is something to transfer */
    if (TransfLength > 0UL)
    {
        TransferRetVal = Eep_Ipw_Read(Eep_u32EepromAddrIt, Eep_pu8JobDataDestPtr, TransfLength);
    }

    /* update variables to be used for the next iteration */
    Eep_pu8JobDataDestPtr  = &Eep_pu8JobDataDestPtr[TransfLength];
    Eep_u32EepromAddrIt    = Eep_u32EepromAddrIt    + TransfLength;
    Eep_u32RemainingLength = Eep_u32RemainingLength - TransfLength;

    /* check status */
    if (EEP_E_FAILED == TransferRetVal)
    {
        /* job has failed */
        RetVal = MEMIF_JOB_FAILED;
    }
    else if ((0UL == Eep_u32RemainingLength) && (EEP_E_OK == TransferRetVal))
    {
        /* the job is finished */
        RetVal = MEMIF_JOB_OK;
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}

/**
* @brief        Pocess a write job
*
* @details      Performs the write operation for a main function call.
*                Calls low level drivers for async or snc behavior.
*
* @param[in]
*
* @pre          The module must be initialized
*
*
*
*/
static MemIf_JobResultType Eep_ProcessWriteJob(void)
{
    MemIf_JobResultType RetVal    = MEMIF_JOB_PENDING;
    Eep_ReturnType TransferRetVal = EEP_E_OK;

#if (EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_OFF)
    Eep_LengthType TransfLength;

    /* transfer information to low level driver */
    /* the function will write Eep_u32MaxWrite or the remaining length */
    /* compute length of transfer */
    if (Eep_u32RemainingLength > Eep_u32MaxWrite)
    {
        /* Eep_u32MaxWrite must be transferred */
        TransfLength = Eep_u32MaxWrite;
    }
    else
    {
        /* Eep_u32RemainingLength must be transferred */
        TransfLength = Eep_u32RemainingLength;
    }

    /* if there is something to transfer */
    if (TransfLength > 0UL)
    {
        TransferRetVal = Eep_Ipw_Write(Eep_u32EepromAddrIt, Eep_pu8JobSrcAddrPtr, TransfLength);
    }

    /* update variables to be used for the next iteration */
    Eep_pu8JobSrcAddrPtr   = &Eep_pu8JobSrcAddrPtr[TransfLength];
    Eep_u32EepromAddrIt    = Eep_u32EepromAddrIt    + TransfLength;
    Eep_u32RemainingLength = Eep_u32RemainingLength - TransfLength;
#else
    /* in asynchronous mode in one main function call EEP
    * will trigger a hardware write operation for a 1,2, or 4 bytes page and return,
    * it will not wait for operation to finish */
    TransferRetVal = Eep_Ipw_Write(Eep_u32EepromAddrIt, Eep_pu8JobSrcAddrPtr, Eep_u32RemainingLength);
    /* Clear unused variable */
    (void)Eep_u32MaxWrite;

#endif /*#if (EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_OFF)  */

    if (EEP_E_FAILED == TransferRetVal)
    {
        /* job has failed */
        RetVal = MEMIF_JOB_FAILED;
    }
#if (EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_OFF)
    else if ((0UL == Eep_u32RemainingLength) && (EEP_E_OK == TransferRetVal))
#else
    else if (EEP_E_OK == TransferRetVal)
#endif /*#if (EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_OFF)  */
    {
        /* the job is finished */
        RetVal = MEMIF_JOB_OK;
        /* job is done */
        Eep_u32RemainingLength = 0UL;
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}

/* If FTFC IP is present on the platform */
#if (EEP_QUICK_WRITES_API == STD_ON)

/**
* @brief        Pocess a quick write job
*
* @details      Performs the quick write operation for a main function call.
*               Calls low level drivers for async or snc behavior.
*
* @pre          The module must be initialized
*/
static MemIf_JobResultType Eep_ProcessQuickWriteJob(void)
{
    MemIf_JobResultType RetVal    = MEMIF_JOB_FAILED;
    Eep_ReturnType TransferRetVal = EEP_E_OK;
    uint16 Length                 = Eep_u16QuickWritesLength;

    /* if there is something to transfer */
    if (Eep_u32RemainingLength > 0UL)
    {
        TransferRetVal = Eep_Ipw_QuickWrite(Eep_u32EepromAddrIt, Eep_pu8JobSrcAddrPtr, Length);

        Eep_pu8JobSrcAddrPtr = (uint8*)((uint32)Eep_pu8JobSrcAddrPtr + Length);
        Eep_u32EepromAddrIt += Length;
        Eep_u32RemainingLength -= Length;
    }

    if (EEP_E_OK == TransferRetVal)
    {
        if (0UL == Eep_u32RemainingLength)
        {
            RetVal = MEMIF_JOB_OK;
        }
        else
        {
            RetVal = MEMIF_JOB_PENDING;
        }
    }

    return RetVal;
}

#endif /* EEP_QUICK_WRITES_API */

/**
* @brief        Pocess a erase job
*
* @details      Performs the erase operation for a main function call.
*                Calls low level drivers for async or snc behavior.
*
* @param[in]
*
* @pre          The module must be initialized
*/
static MemIf_JobResultType Eep_ProcessEraseJob(void)
{
    MemIf_JobResultType RetVal    = MEMIF_JOB_PENDING;
    Eep_ReturnType TransferRetVal = EEP_E_OK;

#if (EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_OFF)
    Eep_LengthType u32TransfLength = 0UL;

    /* transfer information to low level driver */
    /* the function will write Eep_u32MaxWrite or the remaining length */
    /* compute length of transfer */
    if (Eep_u32RemainingLength > Eep_u32MaxWrite)
    {
        /* Eep_u32MaxWrite must be transferred */
        u32TransfLength = Eep_u32MaxWrite;
    }
    else
    {
        /* Eep_u32RemainingLength must be transferred */
        u32TransfLength = Eep_u32RemainingLength;
    }
    /* if there is something to transfer */
    if (u32TransfLength > 0UL)
    {
        TransferRetVal = Eep_Ipw_Erase(Eep_u32EepromAddrIt, u32TransfLength);
    }

    /* update variables to be used for the next iteration */
    Eep_u32EepromAddrIt = Eep_u32EepromAddrIt + u32TransfLength;
    Eep_u32RemainingLength = Eep_u32RemainingLength - u32TransfLength;
#else
    TransferRetVal = Eep_Ipw_Erase(Eep_u32EepromAddrIt, Eep_u32RemainingLength);
    /* Clear unused variable */
    (void)Eep_u32MaxWrite;

#endif /*#if (EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_OFF)  */

    if (EEP_E_FAILED == TransferRetVal)
    {
        /* job has failed */
        RetVal = MEMIF_JOB_FAILED;
    }
    #if (EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_OFF)
    else if ((0UL == Eep_u32RemainingLength) && (EEP_E_OK == TransferRetVal))
    #else
    else if (EEP_E_OK == TransferRetVal)
    #endif /*#if (EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_OFF)  */
    {
        /* the job is finished */
        RetVal = MEMIF_JOB_OK;
        /* job is done */
        Eep_u32RemainingLength = 0UL;
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

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
*
* @implements     Eep_Init_Activity
*
*/

void Eep_Init(const Eep_ConfigType * ConfigPtr)
{
    Eep_ReturnType RetVal = EEP_E_OK;

#if (EEP_DEV_ERROR_DETECT == STD_ON)
    /* check DET error codes */
#if defined(EEP_PRECOMPILE_SUPPORT)
    if (NULL_PTR != ConfigPtr)
#else
    if (NULL_PTR == ConfigPtr)
#endif
    {
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_INIT_ID, EEP_E_INIT_FAILED);
    }
    else if (MEMIF_JOB_PENDING == Eep_eJobResult)
    {
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_INIT_ID, EEP_E_BUSY);
    }
    else
    {
#endif /* EEP_DEV_ERROR_DETECT */

        Eep_InitAllVarriable();

        /* set the configuration pointer according to the config variant */
    #if defined(EEP_PRECOMPILE_SUPPORT)
        Eep_pConfigPtr = &Eep_PBCfgVariantPredefined;
    #if (EEP_DEV_ERROR_DETECT == STD_OFF)
        (void)ConfigPtr;
    #endif
    #else
        Eep_pConfigPtr = ConfigPtr;
    #endif

        /* check configuration CRC */
        if (Eep_pConfigPtr->u16ConfigCrc != Eep_CalcCfgCRC())
        {
        #if (EEP_DEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_INIT_ID, EEP_E_INIT_FAILED);
            Eep_pConfigPtr = NULL_PTR;
        #endif
            Eep_eJobResult = MEMIF_JOB_FAILED;
        }
        else
        {
            /* Set the max number of bytes to read/write
                during Eep_MainFunction call */
            if (MEMIF_MODE_SLOW == Eep_pConfigPtr->eDefaultMode)
            {
                Eep_u32MaxRead = Eep_pConfigPtr->u32MaxReadNormalMode;
                Eep_u32MaxWrite = Eep_pConfigPtr->u32MaxWriteNormalMode;
            }
            else
            {
                Eep_u32MaxRead = Eep_pConfigPtr->u32MaxReadFastMode;
                Eep_u32MaxWrite = Eep_pConfigPtr->u32MaxWriteFastMode;
            }

            RetVal = Eep_Ipw_Init(Eep_pConfigPtr);
            if (EEP_E_FAILED == RetVal)
            {
                Eep_eJobResult = MEMIF_JOB_FAILED;
            #if (EEP_DEV_ERROR_DETECT == STD_ON)
                Eep_pConfigPtr = NULL_PTR;
            #endif
            }
            else
            {
                Eep_eJobResult = MEMIF_JOB_OK;
            }
        }
#if (EEP_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

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
*
* @implements       Eep_Erase_Activity
*
*/
Std_ReturnType Eep_Erase(Eep_AddressType EepromAddress,
                         Eep_LengthType Length
                        )
{
    Std_ReturnType RetVal = E_NOT_OK;

    /* Check driver was initialized */
#if (EEP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Eep_pConfigPtr)
    {
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_ERASE_ID, EEP_E_UNINIT);
    }
    else
    {
#endif
    if ((Std_ReturnType)E_OK == Eep_Ipw_CheckEraseParams(EepromAddress, Length))
    {
        SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_01();
        if (MEMIF_JOB_PENDING == Eep_eJobResult)
        {
        #if (EEP_DEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_ERASE_ID, EEP_E_BUSY);
        #endif
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_01();
        }
        else
        {
            /* Configure the erase job */
            Eep_u32EepromAddrIt    = EepromAddress;
            Eep_u32RemainingLength = Length;
            Eep_eJob               = EEP_JOB_ERASE;
            Eep_eJobResult         = MEMIF_JOB_PENDING;
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_01();

            RetVal = E_OK;
        }
    }
#if (EEP_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return RetVal;
}

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
*
* @implements       Eep_Write_Activity
*
*/
Std_ReturnType Eep_Write(Eep_AddressType EepromAddress,
                         const uint8 * DataBufferPtr,
                         Eep_LengthType Length
                        )
{
    Std_ReturnType RetVal = E_NOT_OK;

#if (EEP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Eep_pConfigPtr)
    {
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_WRITE_ID, EEP_E_UNINIT);
    }
    else
    {
#endif
    if ((Std_ReturnType)E_OK == Eep_Ipw_CheckWriteParams(EepromAddress, DataBufferPtr, Length))
    {
        /* enter EA to protect global variables */
        SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_02();

        if (MEMIF_JOB_PENDING == Eep_eJobResult)
        {
        #if (EEP_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_WRITE_ID, EEP_E_BUSY);
        #endif
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_02();
        }
        else
        {
            /* Configure the write job */
            /* uint32 destination address which will be incremented during job processing */
            Eep_u32EepromAddrIt    = EepromAddress;
            /* uint8 source pointer which will be incremented during job processing */
            Eep_pu8JobSrcAddrPtr   = DataBufferPtr;
            /* remaining length to be transfered */
            Eep_u32RemainingLength = Length;
            Eep_eJob               = EEP_JOB_WRITE;
            Eep_eJobResult         = MEMIF_JOB_PENDING;
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_02();

            RetVal = E_OK;
        }
    }
#if (EEP_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return RetVal;
}

/* If FTFC IP is present on the platform */
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
* @pre              The module has to be initialized and not busy.
* @implements       Eep_QuickWrite_Activity
*/
Std_ReturnType Eep_QuickWrite(Eep_AddressType u32TargetAddress,
                              uint8 const * pSourceAddressPtr,
                              Eep_LengthType u32Length,
                              uint16 u16QuickWritesLength
                             )
{
    Std_ReturnType  RetVal          = E_NOT_OK;
    Eep_ReturnType  EepIpwReturn    = EEP_E_OK;
    uint8 const   * SourceAdd       = pSourceAddressPtr;
    Eep_LengthType  LengthRemaining = u32Length;
    Eep_AddressType DestAdd         = u32TargetAddress;

    /* in the quick writes mode only 4 bytes alligned writes are allowed */
#if (EEP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Eep_pConfigPtr)
    {
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_QUICK_WRITE_ID, EEP_E_UNINIT);
    }
    else
    {
#endif
    if ((Std_ReturnType)E_OK == Eep_Ipw_CheckQuickWriteParams(DestAdd, SourceAdd, LengthRemaining, u16QuickWritesLength))
    {
        SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_05();
        if (MEMIF_JOB_PENDING == Eep_eJobResult)
        {
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_05();
        #if (EEP_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_QUICK_WRITE_ID, EEP_E_BUSY);
        #endif
        }
        else
        {
            EepIpwReturn     = Eep_Ipw_QuickWrite(DestAdd, SourceAdd, u16QuickWritesLength);
            SourceAdd        = (uint8*)((uint32)SourceAdd + u16QuickWritesLength);
            DestAdd         += u16QuickWritesLength;
            LengthRemaining -= u16QuickWritesLength;

            if (LengthRemaining == 0U)
            {
                if (EEP_E_OK == EepIpwReturn)
                {
                    Eep_eJobResult = MEMIF_JOB_OK;
                    RetVal = E_OK;
                }
                else
                {
                    Eep_eJobResult = MEMIF_JOB_FAILED;
                }
            }
            else
            {
                if (EEP_E_OK == EepIpwReturn)
                {
                    /* uint8 source pointer which will be incremented during job processing */
                    Eep_pu8JobSrcAddrPtr     = SourceAdd;
                    /* uint32 destination address which will be incremented during job processing */
                    Eep_u32EepromAddrIt      = DestAdd;
                    Eep_u32RemainingLength   = LengthRemaining;
                    Eep_u16QuickWritesLength = u16QuickWritesLength;
                    Eep_eJob                 = EEP_JOB_QUICK_WRITE;
                    Eep_eJobResult           = MEMIF_JOB_PENDING;
                    RetVal                   = E_OK;
                }
                else
                {
                    Eep_eJobResult = MEMIF_JOB_FAILED;
                }
            }

            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_05();
        }
    }
#if (EEP_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return RetVal;
}

#endif /* EEP_QUICK_WRITES_API */

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
*
* @implements       Eep_Cancel_Activity
*/
void Eep_Cancel(void)
{
#if (EEP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Eep_pConfigPtr)
    {
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_CANCEL_ID, EEP_E_UNINIT);
    }
    else
    {
#endif
        if (MEMIF_JOB_PENDING == Eep_eJobResult)
        {
                /* If underlying hardware job was successfully canceled */
                if (EEP_E_OK == Eep_Ipw_Cancel())
                {
                    /* Update global job result status */
                    Eep_eJobResult = MEMIF_JOB_CANCELED;
                }
            /* Call the error notification function if configured */
            Eep_CallNotification(Eep_eJobResult);
        }
        else
        {
            /* Leave the job result unchanged */
        }
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
    }
    #endif    /* EEP_DEV_ERROR_DETECT == STD_ON */
}
#endif    /* EEP_CANCEL_API == STD_ON */


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
*
* @implements       Eep_GetStatus_Activity
*/
MemIf_StatusType Eep_GetStatus(void)
{
    MemIf_StatusType RetVal;

    /* Check the driver was initialized */
    if (NULL_PTR == Eep_pConfigPtr)
    {
        RetVal = MEMIF_UNINIT;
    }
    /* There is a pending job */
    else if (MEMIF_JOB_PENDING == Eep_eJobResult)
    {
        RetVal = MEMIF_BUSY;
    }
    else
    {
        RetVal = MEMIF_IDLE;
    }

    return RetVal;
}
#endif    /* EEP_GET_STATUS_API == STD_ON */


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
*
* @implements       Eep_GetJobResult_Activity
*/
MemIf_JobResultType Eep_GetJobResult(void)
{
    MemIf_JobResultType RetVal;

    /* Check the driver was initialized */
    if (NULL_PTR == Eep_pConfigPtr)
    {
        #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_GETJOBRESULT_ID, EEP_E_UNINIT);
        #endif
        RetVal = (MemIf_JobResultType)MEMIF_JOB_FAILED;
    }
    else
    {
        /* Get the job result */
        RetVal = Eep_eJobResult;
    }

    return RetVal;
}
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
*
* @implements       Eep_Read_Activity
*
*/
Std_ReturnType Eep_Read(Eep_AddressType EepromAddress,
                        uint8 * DataBufferPtr,
                        Eep_LengthType Length
                       )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    /* Check driver was initialized */
    if (NULL_PTR == Eep_pConfigPtr)
    {
#if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_READ_ID, EEP_E_UNINIT);
#endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((Std_ReturnType)E_NOT_OK == Eep_Ipw_CheckReadParams(EepromAddress, DataBufferPtr, Length))
    {
        RetVal = E_NOT_OK;
    }
    else
    {
        SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_03();

        if (MEMIF_JOB_PENDING == Eep_eJobResult)
        {
#if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_READ_ID, EEP_E_BUSY);
#endif    /* EEP_DEV_ERROR_DETECT == STD_ON */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Configure the read job */
            Eep_u32EepromAddrIt    = EepromAddress;
            Eep_pu8JobDataDestPtr  = DataBufferPtr;
            Eep_u32RemainingLength = Length;
            Eep_eJob               = EEP_JOB_READ;
            /* Execute the read job */
            Eep_eJobResult         = MEMIF_JOB_PENDING;
        }
        SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_03();
    }

    return RetVal;
}


#if (EEP_COMPARE_API == STD_ON)
/**
* @brief           Compares a eeprom memory area with an application data buffer.
* @details         Starts a compare job asynchronously. The actual job is performed by
*                  Eep_MainFunction.
*
* @param[in]        EepromAddress          Source address in eeprom memory.
* @param[in]        DataBufferPtr          Pointer to source data buffer.
* @param[in]        Length                 Number of bytes to compare.
*
* @return           Std_ReturnType
* @retval           E_OK                      Compare command has been accepted.
* @retval           E_NOT_OK                   Compare command has not been accepted.
*
* @api
*
* @pre            The module has to be initialized and not busy.
*
* @implements       Eep_Compare_Activity
*/
Std_ReturnType Eep_Compare(Eep_AddressType EepromAddress,
                           const uint8 * DataBufferPtr,
                           Eep_LengthType Length
                          )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    /* Check driver was initialized */
    if (NULL_PTR == Eep_pConfigPtr)
    {
        #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_COMPARE_ID, EEP_E_UNINIT);
        #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((Std_ReturnType)E_NOT_OK == Eep_Ipw_CheckCompareParams(EepromAddress, DataBufferPtr, Length))
    {
        RetVal = E_NOT_OK;
    }
    else
    {
        SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_04();

        if (MEMIF_JOB_PENDING == Eep_eJobResult)
        {
#if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_COMPARE_ID, EEP_E_BUSY);
#endif    /* EEP_DEV_ERROR_DETECT == STD_ON */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Set job for compare operation */
            Eep_u32EepromAddrIt    = EepromAddress;
            Eep_pu8JobSrcAddrPtr   = DataBufferPtr;
            Eep_u32RemainingLength = Length;
            Eep_eJob               = EEP_JOB_COMPARE;
            Eep_eJobResult         = MEMIF_JOB_PENDING;
        }
        SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_04();
    }

    return RetVal;
}
#endif /* EEP_COMPARE_API == STD_ON */

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
*
* @implements       Eep_SetMode_Activity
*/
void Eep_SetMode(MemIf_ModeType Mode)
{
#if (EEP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Eep_pConfigPtr)
    {
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_SETMODE_ID, EEP_E_UNINIT);
    }
    else if (MEMIF_JOB_PENDING == Eep_eJobResult)
    {
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_SETMODE_ID, EEP_E_BUSY);
    }
    else
    {
#endif  /* EEP_DEV_ERROR_DETECT == STD_ON */
        /* Set the max number of bytes to read/write
            during Eep_MainFunction call */
        switch (Mode)
        {
            case MEMIF_MODE_FAST:
                Eep_u32MaxRead  = Eep_pConfigPtr->u32MaxReadFastMode;
                Eep_u32MaxWrite = Eep_pConfigPtr->u32MaxWriteFastMode;
                break;

            case MEMIF_MODE_SLOW:
                Eep_u32MaxRead  = Eep_pConfigPtr->u32MaxReadNormalMode;
                Eep_u32MaxWrite = Eep_pConfigPtr->u32MaxWriteNormalMode;
                break;

            default:
                /* Do nothing - should not happen in Fully Trusted Environment;
                   'default' clause added to fulfill MISRA Rule 15.3 */
                break;
        }
#if (EEP_DEV_ERROR_DETECT == STD_ON)
    }
#endif    /* EEP_DEV_ERROR_DETECT == STD_ON */
}
#endif /* EEP_SET_MODE_API == STD_ON */

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
*
* @implements       Eep_GetVersionInfo_Activity
*
*/
void Eep_GetVersionInfo(Std_VersionInfoType * versioninfo)
{
#if (EEP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_GETVERSIONINFO_ID, EEP_E_PARAM_POINTER);
    }
    else
    {
#endif /* EEP_DEV_ERROR_DETECT == STD_ON */
        versioninfo->moduleID = (uint16)EEP_MODULE_ID;
        versioninfo->vendorID = (uint16)EEP_VENDOR_ID;
        versioninfo->sw_major_version = (uint8)EEP_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)EEP_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)EEP_SW_PATCH_VERSION;
#if (EEP_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* EEP_DEV_ERROR_DETECT == STD_ON */
}
#endif

#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
 /**
* @brief        Reports DEM errors
* @details      Reports production errors.
*
* @param[in,out] -
*
* @api
*
*/
static void Eep_ReportDemErrors (void)
{
    switch (Eep_eJob)
    {
        case EEP_JOB_WRITE:
            if ((uint32)STD_ON == Eep_pConfigPtr->Eep_E_WriteFailedCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eep_pConfigPtr->Eep_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED);
            }
            break;

        case EEP_JOB_READ:
            if ((uint32)STD_ON == Eep_pConfigPtr->Eep_E_ReadFailedCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eep_pConfigPtr->Eep_E_ReadFailedCfg.id, DEM_EVENT_STATUS_FAILED);
            }
            break;

    #if (EEP_COMPARE_API == STD_ON)
        case EEP_JOB_COMPARE:
            if ((uint32)STD_ON == Eep_pConfigPtr->Eep_E_CompareFailedCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eep_pConfigPtr->Eep_E_CompareFailedCfg.id, DEM_EVENT_STATUS_FAILED);
            }
            break;
    #endif

    #if (EEP_QUICK_WRITES_API == STD_ON)
        case EEP_JOB_QUICK_WRITE:
            if ((uint32)STD_ON == Eep_pConfigPtr->Eep_E_BOQuickWritesCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eep_pConfigPtr->Eep_E_BOQuickWritesCfg.id, DEM_EVENT_STATUS_FAILED);
            }
            break;
    #endif

        default:
            /* EEP_JOB_ERASE */
            if ((uint32)STD_ON == Eep_pConfigPtr->Eep_E_EraseFailedCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eep_pConfigPtr->Eep_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
            }
            break;
    }
}
/**
* @brief        Reports DEM passes
* @details      Reports production passes.
*
* @param[in,out] -
*
* @api
*
*/
static void Eep_ReportDemPasses (void)
{
    switch (Eep_eJob)
    {
        case EEP_JOB_WRITE:
            if ((uint32)STD_ON == Eep_pConfigPtr->Eep_E_WriteFailedCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eep_pConfigPtr->Eep_E_WriteFailedCfg.id, DEM_EVENT_STATUS_PASSED);
            }
            break;

        case EEP_JOB_READ:
            if ((uint32)STD_ON == Eep_pConfigPtr->Eep_E_ReadFailedCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eep_pConfigPtr->Eep_E_ReadFailedCfg.id, DEM_EVENT_STATUS_PASSED);
            }
            break;

    #if (EEP_COMPARE_API == STD_ON)
        case EEP_JOB_COMPARE:
            if ((uint32)STD_ON == Eep_pConfigPtr->Eep_E_CompareFailedCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eep_pConfigPtr->Eep_E_CompareFailedCfg.id, DEM_EVENT_STATUS_PASSED);
            }
            break;
    #endif

    #if (EEP_QUICK_WRITES_API == STD_ON)
        case EEP_JOB_QUICK_WRITE:
            if ((uint32)STD_ON == Eep_pConfigPtr->Eep_E_BOQuickWritesCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eep_pConfigPtr->Eep_E_BOQuickWritesCfg.id, DEM_EVENT_STATUS_PASSED);
            }
            break;
    #endif
        default:
            /* EEP_JOB_ERASE */
            if ((uint32)STD_ON == Eep_pConfigPtr->Eep_E_EraseFailedCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eep_pConfigPtr->Eep_E_EraseFailedCfg.id, DEM_EVENT_STATUS_PASSED);
            }
            break;
    }
}
#endif

/**
* @brief            Performs actual eeprom read, write, erase and compare jobs.
* @pre              The module has to be initialized.
* @param[in]        Job  Currently executed job (erase, write, read, or compare)
*
* @return           MemIf_JobResultType
* @retval           MEMIF_JOB_OK              Successfully completed job.
* @retval           MEMIF_JOB_FAILED          Not successfully completed job.
* @retval           MEMIF_JOB_PENDING         Still pending job (not yet completed).
* @retval           MEMIF_JOB_CANCELED        Job has been canceled.
* @retval           MEMIF_BLOCK_INCONSISTENT  Inconsistent block requested, it may
*                                             contains corrupted data.
* @retval           MEMIF_BLOCK_INVALID       Invalid block requested.

*/
static MemIf_JobResultType Eep_ProcessRequestedJobs(Eep_JobType Job)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_FAILED;

    switch (Job)
    {
        case EEP_JOB_ERASE:
            /* Process erase job */
            RetVal = Eep_ProcessEraseJob();
            break;

        case EEP_JOB_WRITE:
            /* Process write job */
            RetVal = Eep_ProcessWriteJob();
            break;

        case EEP_JOB_READ:
            /* Process read job */
            RetVal = Eep_ProcessReadJob();
            break;

    #if (EEP_COMPARE_API == STD_ON)
        case EEP_JOB_COMPARE:
            /* Process compare job */
            RetVal = Eep_ProcessCompareJob();
            break;
    #endif

    #if (EEP_QUICK_WRITES_API == STD_ON)
        case EEP_JOB_QUICK_WRITE:
            RetVal = Eep_ProcessQuickWriteJob();
            break;
    #endif

        default:
            /* Do nothing - should not happen in Fully Trusted Environment;
               'default' clause added to fulfill MISRA Rule 15.3 */
            break;
    }

    return RetVal;
}

/**
* @brief            Only executed at the end of a new job
*
* @param[in]        None
*
* @pre              The module has to be initialized.
*
*/
static void Eep_EndJobs(void)
{
#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* if job failed report errors */
    if (MEMIF_JOB_FAILED == Eep_eJobResult)
    {
        Eep_ReportDemErrors();
    }
    else if (MEMIF_JOB_OK == Eep_eJobResult)
    {
        Eep_ReportDemPasses();
    }
    else
    {
       /* Not report any dems */
    }
#endif

    /* call notifications when job was finished */
    if ((MEMIF_JOB_FAILED == Eep_eJobResult) || (MEMIF_BLOCK_INCONSISTENT == Eep_eJobResult) || (MEMIF_JOB_OK == Eep_eJobResult))
    {
        Eep_CallNotification(Eep_eJobResult);
    }
}

/**
* @brief            Performs actual eeprom read, write, erase and compare jobs.
* @details          Bytes number processed per cycle depends by job type (erase, write, read, compare)
*                   current EEP module's operating mode (normal, fast)
*                   and write, erase Mode of Execution (sync, async).
*
* @api
*
* @pre              The module has to be initialized.
*
*
* @note             This function have to be called ciclically by the Basic Software Module;
*                   it will do nothing if there aren't pending job.
* @implements       Eep_MainFunction_Activity
*/
void Eep_MainFunction(void)
{

    /* Check if Eep is initialized*/
    /* SWS_BSW_00037 - If the module is not initialized and the main function is executed then no error shall be reported and the main function shall return immediately. */
    if (NULL_PTR != Eep_pConfigPtr)
    {
        if (MEMIF_JOB_PENDING == Eep_eJobResult)
        {

                /* Process the requested jobs : write, compare, erase, read */
                Eep_eJobResult = Eep_ProcessRequestedJobs(Eep_eJob);


            if (MEMIF_JOB_PENDING != Eep_eJobResult)
            {

                /* only executed at the end of a new job */
                Eep_EndJobs();
            }
        }
        else
        {
            /* Nothing to do since no job is pending */
        }
    }
}


#define EEP_STOP_SEC_CODE
#include "Eep_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
