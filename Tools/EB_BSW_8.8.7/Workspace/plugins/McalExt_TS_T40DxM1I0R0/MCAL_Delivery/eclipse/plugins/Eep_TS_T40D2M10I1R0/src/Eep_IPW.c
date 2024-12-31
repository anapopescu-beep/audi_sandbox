/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IPV_FTFC
*   Dependencies         : 
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

/**
*   @file Eep_IPW.c
*
*   @addtogroup EEP_IPW
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf.h"
#include "Eep.h"
#include "Eep_IPW.h"
#include "Det.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_IPW_VENDOR_ID_C                      43
#define EEP_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define EEP_IPW_AR_RELEASE_MINOR_VERSION_C       4
#define EEP_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define EEP_IPW_SW_MAJOR_VERSION_C               1
#define EEP_IPW_SW_MINOR_VERSION_C               0
#define EEP_IPW_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Version checks for OsIf.h */
    #if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_IPW_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Eep_IPW.c and OsIf.h are different"
    #endif
#endif

/* Version checks for Eep.h */
#if (EEP_IPW_VENDOR_ID_C != EEP_VENDOR_ID)
    #error "Eep_IPW.c and Eep.h have different vendor ids"
#endif
#if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_C    != EEP_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_IPW_AR_RELEASE_MINOR_VERSION_C    != EEP_AR_RELEASE_MINOR_VERSION) || \
     (EEP_IPW_AR_RELEASE_REVISION_VERSION_C != EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep_IPW.c and Eep.h are different"
#endif
#if ((EEP_IPW_SW_MAJOR_VERSION_C != EEP_SW_MAJOR_VERSION) || \
     (EEP_IPW_SW_MINOR_VERSION_C != EEP_SW_MINOR_VERSION) || \
     (EEP_IPW_SW_PATCH_VERSION_C != EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_IPW.c and Eep.h are different"
#endif

/* Version checks for Eep_IPW.h */
#if (EEP_IPW_VENDOR_ID_C != EEP_IPW_VENDOR_ID_H)
    #error "Eep_IPW.c and Eep_IPW.h have different vendor ids"
#endif
#if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_C    != EEP_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (EEP_IPW_AR_RELEASE_MINOR_VERSION_C    != EEP_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (EEP_IPW_AR_RELEASE_REVISION_VERSION_C != EEP_IPW_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Eep_IPW.c and Eep_IPW.h are different"
#endif
#if ((EEP_IPW_SW_MAJOR_VERSION_C != EEP_IPW_SW_MAJOR_VERSION_H) || \
     (EEP_IPW_SW_MINOR_VERSION_C != EEP_IPW_SW_MINOR_VERSION_H) || \
     (EEP_IPW_SW_PATCH_VERSION_C != EEP_IPW_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Eep_IPW.c and Eep_IPW.h are different"
#endif

/* Version checks for Det.h */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_IPW_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Eep_IPW.c and Det.h are different"
    #endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#if ((EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_ON) || \
     (EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_ON))
typedef struct
{
    Eep_AddressType DestAddress;
    uint8 const * SrcAddress;
    Eep_LengthType Length;
    boolean InProgress;
} Eep_Ipw_xAsyncJobType;
#endif

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

#define EEP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eep_MemMap.h"

#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    static Eep_ConfigType const * Eep_Ipw_pxEepConfig;
#endif

#if ((EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_ON) || \
     (EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_ON))
    static Eep_Ipw_xAsyncJobType Eep_Ipw_xAsyncJob;
#endif

#define EEP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eep_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define EEP_START_SEC_CODE
#include "Eep_MemMap.h"

#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
static void Eep_Ipw_ReportBrownOut (
    void
);
#endif

static void Eep_Ipw_ReportFailure (Ftfc_Eep_Ip_StatusType FtfcStatus,
                                   uint32 ApiID
                                  );

static Ftfc_Eep_Ip_PageSizeType Eep_Ipw_AlignedPageSize (Ftfc_Eep_Ip_AddressType FlexramAddress,
                                                         Ftfc_Eep_Ip_AddressType RamAddress,
                                                         Ftfc_Eep_Ip_LengthType Length
                                                        );

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief   Initialize the FTFC IP
 * @details FTFC is the only EEPROM available on this platform.
 *
 * @return  FTFC initialization status
 * @retval  EEP_E_OK on success
 * @retval  EEP_E_FAILED on failure
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Eep_ReturnType Eep_Ipw_Init (Eep_ConfigType const * pxEepConfig)
{
    Eep_ReturnType RetVal = EEP_E_OK;
    Ftfc_Eep_Ip_StatusType FtfcStatus = FTFC_EEP_IP_STATUS_OK;

    /* reinitialize the global variables */
#if ((EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_ON) || \
     (EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_ON))
    Eep_Ipw_xAsyncJob.DestAddress = 0U;
    Eep_Ipw_xAsyncJob.SrcAddress = NULL_PTR;
    Eep_Ipw_xAsyncJob.Length = 0U;
    Eep_Ipw_xAsyncJob.InProgress = FALSE;
#endif

    /* Call Ip init function */
    FtfcStatus = Ftfc_Eep_Ip_Init(pxEepConfig->pxFtfcEepIpConfig);

#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    Eep_Ipw_pxEepConfig = pxEepConfig;
    Eep_Ipw_ReportBrownOut();
#endif

    /* Check the status after finishing */
    if (FTFC_EEP_IP_STATUS_OK != FtfcStatus)
    {
        Eep_Ipw_ReportFailure(FtfcStatus, (uint32)EEP_INIT_ID);
        RetVal = EEP_E_FAILED;
    }

    return RetVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Check parameters for the Read job.
 *
 * @param[in] SrcAddress
 * @param[in] pu8DestAddress
 * @param[in] Length
 *
 * @return Ok / not ok to proceed with the read operation.
 * @retval E_OK
 * @retval E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Eep_Ipw_CheckReadParams (Eep_AddressType SrcAddress,
                                        uint8 const * pu8DestAddress,
                                        Eep_LengthType Length
                                       )
{
    Std_ReturnType RetVal = E_NOT_OK;

    /* Check the validity of Source Address */
    if (SrcAddress >= FTFC_EEP_IP_EEP_SIZE)
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_READ_ID, EEP_E_PARAM_ADDRESS);
    #endif
    }
    /* Check the validity of Length */
    else if ((0U == Length) || ((SrcAddress + Length) > FTFC_EEP_IP_EEP_SIZE))
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_READ_ID, EEP_E_PARAM_LENGTH);
    #endif
    }
    /* Check the validity of destination address */
    else if (NULL_PTR == pu8DestAddress)
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_READ_ID, EEP_E_PARAM_DATA);
    #endif
    }
    else
    {
        RetVal = E_OK;
    }

    return RetVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Synchronous read.
 *
 * @param[out] pu8DestAddress
 *
 * @return Synchronous read op status.
 * @retval EEP_E_OK
 * @retval EEP_E_FAILED
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

Eep_ReturnType Eep_Ipw_Read (Eep_AddressType SrcAddress,
                             uint8 * pu8DestAddress,
                             Eep_LengthType Length
                            )
{
    Eep_ReturnType RetVal = EEP_E_FAILED;
    Ftfc_Eep_Ip_StatusType FtfcStatus = FTFC_EEP_IP_STATUS_OK;

    /* Call Ip read function */
    FtfcStatus = Ftfc_Eep_Ip_Read(SrcAddress, pu8DestAddress, Length);

    /* Check status of read operation */
    if (FTFC_EEP_IP_STATUS_OK == FtfcStatus)
    {
        RetVal = EEP_E_OK;
    }

    return RetVal;
}

#if (EEP_COMPARE_API == STD_ON)

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief  Check the params given for a Compare job.
 *
 * @param[in] SrcAddress
 * @param[in] pu8DestAddress
 * @param[in] Length
 *
 * @return Ok / not ok to proceed to the compare operation with the given params.
 * @retval E_OK
 * @retval E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Eep_Ipw_CheckCompareParams (Eep_AddressType SrcAddress,
                                           uint8 const * pu8DestAddress,
                                           Eep_LengthType Length
                                          )
{
    Std_ReturnType retVal = E_NOT_OK;

    /* Check the validity of source address */
    if (SrcAddress >= FTFC_EEP_IP_EEP_SIZE)
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError ((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_COMPARE_ID, EEP_E_PARAM_ADDRESS);
    #endif
    }
    /* Check the validity of length */
    else if ((0U == Length) || ((SrcAddress + Length) > FTFC_EEP_IP_EEP_SIZE))
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError ((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_COMPARE_ID, EEP_E_PARAM_LENGTH);
    #endif
    }
    /* Check the validity of destination address */
    else if (NULL_PTR == pu8DestAddress)
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError ((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_COMPARE_ID, EEP_E_PARAM_DATA);
    #endif
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Compare an EEPROM area with a given buffer.
 *
 * @param[in] SrcAddress
 * @param[in] pu8DestAddress
 * @param[in] Length
 *
 * @return the comparison result:
 * @retval EEP_E_OK                 memory contents match
 * @retval EEP_E_BLOCK_INCONSISTENT memory contents do not match
 * @retval EEP_E_FAILED             compare operation failed
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Eep_ReturnType Eep_Ipw_CompareSync (Eep_AddressType SrcAddress,
                                    uint8 const * pu8DestAddress,
                                    Eep_LengthType Length
                                   )
{
    Eep_ReturnType RetVal = EEP_E_OK;
    Ftfc_Eep_Ip_StatusType FtfcStatus  = FTFC_EEP_IP_STATUS_OK;

    /* Call Ip compare function */
    FtfcStatus = Ftfc_Eep_Ip_Compare(SrcAddress, pu8DestAddress, Length);

    /* Check the status after compare operation */
    switch (FtfcStatus)
    {
        case FTFC_EEP_IP_STATUS_OK:
            RetVal = EEP_E_OK;
        break;

        case FTFC_EEP_IP_STATUS_BLOCK_INCONSISTENT:
            RetVal = EEP_E_BLOCK_INCONSISTENT;
        break;

        default:
            RetVal = EEP_E_FAILED;
        break;
    }

    return RetVal;
}

#endif /* EEP_COMPARE_API */

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief       Check if the parameters are ok and the HLD can start the erase job.
 *
 * @param[in]   Address
 * @param[in]   Length
 *
 * @return      Ok / Not ok to start the erase job.
 * @retval      E_OK
 * @retval      E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Eep_Ipw_CheckEraseParams (Eep_AddressType Address,
                                         Eep_LengthType Length
                                        )
{
    Std_ReturnType retVal = E_NOT_OK;

    /* Check the address */
    if (Address >= FTFC_EEP_IP_EEP_SIZE)
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_ERASE_ID, EEP_E_PARAM_ADDRESS);
    #endif
    }
    /* Check the length */
    else if ((0U == Length) || ((Address + Length) > FTFC_EEP_IP_EEP_SIZE))
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_ERASE_ID, EEP_E_PARAM_LENGTH);
    #endif
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Erase starting from @p Address up to Length bytes.
 *
 * @param[in] address
 * @param[in] length
 *
 * @return Erase status
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Eep_ReturnType Eep_Ipw_Erase (Eep_AddressType Address,
                              Eep_LengthType Length
                             )
{
    Eep_AddressType EraseAdd = Address;
    Eep_LengthType LengthRemaining = Length;

    Eep_ReturnType RetVal = EEP_E_FAILED;
    Ftfc_Eep_Ip_StatusType FtfcStatus = FTFC_EEP_IP_STATUS_OK;

#if (EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_ON)
    Ftfc_Eep_Ip_PageSizeType PageSize = FTFC_EEP_IP_PAGE_BYTE;

    if (FALSE == Eep_Ipw_xAsyncJob.InProgress)
    {
        Eep_Ipw_xAsyncJob.DestAddress = EraseAdd;
        Eep_Ipw_xAsyncJob.SrcAddress = NULL_PTR;
        Eep_Ipw_xAsyncJob.Length = LengthRemaining;

        PageSize = Eep_Ipw_AlignedPageSize(Eep_Ipw_xAsyncJob.DestAddress, 0U, Eep_Ipw_xAsyncJob.Length);
        FtfcStatus = Ftfc_Eep_Ip_Erase(Eep_Ipw_xAsyncJob.DestAddress, PageSize, TRUE);

        if (FTFC_EEP_IP_STATUS_PENDING == FtfcStatus)
        {
            Eep_Ipw_xAsyncJob.DestAddress += (Ftfc_Eep_Ip_AddressType)PageSize;
            Eep_Ipw_xAsyncJob.Length -= (Ftfc_Eep_Ip_LengthType)PageSize;

            Eep_Ipw_xAsyncJob.InProgress = TRUE;
            RetVal = EEP_E_PENDING;
        }
    }
    else
    {
        FtfcStatus = Ftfc_Eep_Ip_GetJobResult();
        switch (FtfcStatus)
        {
            case FTFC_EEP_IP_STATUS_PENDING:
                RetVal = EEP_E_PENDING;
            break;

            case FTFC_EEP_IP_STATUS_OK:
                if (Eep_Ipw_xAsyncJob.Length > 0U)
                {
                    PageSize = Eep_Ipw_AlignedPageSize(Eep_Ipw_xAsyncJob.DestAddress, 0U, Eep_Ipw_xAsyncJob.Length);
                    FtfcStatus = Ftfc_Eep_Ip_Erase(Eep_Ipw_xAsyncJob.DestAddress, PageSize, TRUE);

                    if (FTFC_EEP_IP_STATUS_PENDING == FtfcStatus)
                    {
                        Eep_Ipw_xAsyncJob.DestAddress += (Ftfc_Eep_Ip_AddressType)PageSize;
                        Eep_Ipw_xAsyncJob.Length -= (Ftfc_Eep_Ip_LengthType)PageSize;
                        RetVal = EEP_E_PENDING;
                    }
                    else
                    {
                        Eep_Ipw_xAsyncJob.InProgress = FALSE;
                    }
                }
                else
                {
                    Eep_Ipw_xAsyncJob.InProgress = FALSE;
                    RetVal = EEP_E_OK;
                }
            break;

            default:
                Eep_Ipw_xAsyncJob.InProgress = FALSE;
            break;
        }
    }

#else /* EEP_ASYNC_ERASE_OPERATIONS_ENABLED */

    Ftfc_Eep_Ip_PageSizeType PageSize = FTFC_EEP_IP_PAGE_BYTE;

    while ((LengthRemaining > 0U) && (FTFC_EEP_IP_STATUS_OK == FtfcStatus))
    {
        PageSize = Eep_Ipw_AlignedPageSize(EraseAdd, 0U, LengthRemaining);
        FtfcStatus = Ftfc_Eep_Ip_Erase(EraseAdd, PageSize, FALSE);
        LengthRemaining -= (Eep_LengthType)PageSize;
        EraseAdd += (Eep_AddressType)PageSize;
    }

    if (FTFC_EEP_IP_STATUS_OK == FtfcStatus)
    {
        RetVal = EEP_E_OK;
    }

#endif /* EEP_ASYNC_ERASE_OPERATIONS_ENABLED */

    /* Repor the status after finishing */
    Eep_Ipw_ReportFailure(FtfcStatus, (uint32)EEP_MAINFUNCTION_ID);
    return RetVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief       Check the parameters given for a Write job.
 *
 * @param[in]   DestAddress
 * @param[in]   pu8SrcAddress
 * @param[in]   Length
 *
 * @return Ok / not ok to start the write job with those parameters.
 * @retval E_OK
 * @retval E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Eep_Ipw_CheckWriteParams (Eep_AddressType DestAddress,
                                         uint8 const * pu8SrcAddress,
                                         Eep_LengthType Length
                                        )
{
    Std_ReturnType retVal = E_NOT_OK;

    /* Check the validity of destination address */
    if (DestAddress >= FTFC_EEP_IP_EEP_SIZE)
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError ((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_WRITE_ID, EEP_E_PARAM_ADDRESS);
    #endif
    }
    /* Check the validity of length */
    else if ((0U == Length) || ((DestAddress + Length) > FTFC_EEP_IP_EEP_SIZE))
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError ((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_WRITE_ID, EEP_E_PARAM_LENGTH);
    #endif
    }
    /* Check the validity of source address */
    else if (NULL_PTR == pu8SrcAddress)
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError ((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_WRITE_ID, EEP_E_PARAM_DATA);
    #endif
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Write operation.
 *
 * @param[in] DestAddress
 * @param[in] pu8SrcAddress
 * @param[in] Length
 *
 * @return The write call may end in one of the following states:
 * @retval EEP_E_OK       job jas finished successfully
 * @retval EEP_E_PENDING  async: the job is in progress
 * @retval EEP_E_FAILED   an error has occurred
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Eep_ReturnType Eep_Ipw_Write (Eep_AddressType DestAddress,
                              uint8 const * pu8SrcAddress,
                              Eep_LengthType Length
                             )
{
    Eep_ReturnType RetVal = EEP_E_FAILED;
    Ftfc_Eep_Ip_StatusType FtfcStatus = FTFC_EEP_IP_STATUS_OK;
    Eep_AddressType DestAdd = DestAddress;
    uint8 const * pu8SrcAdd = pu8SrcAddress;
    Eep_LengthType LengthRemaining = Length;

#if (EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_ON)
    Ftfc_Eep_Ip_PageSizeType PageSize = FTFC_EEP_IP_PAGE_BYTE;

    if (FALSE == Eep_Ipw_xAsyncJob.InProgress)
    {
        Eep_Ipw_xAsyncJob.DestAddress = DestAdd;
        Eep_Ipw_xAsyncJob.SrcAddress = pu8SrcAdd;
        Eep_Ipw_xAsyncJob.Length = LengthRemaining;

        PageSize = Eep_Ipw_AlignedPageSize(Eep_Ipw_xAsyncJob.DestAddress, (Eep_AddressType)Eep_Ipw_xAsyncJob.SrcAddress, Eep_Ipw_xAsyncJob.Length);
        FtfcStatus = Ftfc_Eep_Ip_Write(Eep_Ipw_xAsyncJob.DestAddress, Eep_Ipw_xAsyncJob.SrcAddress, PageSize, TRUE);

        if (FTFC_EEP_IP_STATUS_PENDING == FtfcStatus)
        {
            Eep_Ipw_xAsyncJob.DestAddress += (Ftfc_Eep_Ip_AddressType)PageSize;
            Eep_Ipw_xAsyncJob.SrcAddress = (uint8 const *)((Eep_AddressType)Eep_Ipw_xAsyncJob.SrcAddress + (uint8)PageSize);
            Eep_Ipw_xAsyncJob.Length -= (Ftfc_Eep_Ip_LengthType)PageSize;

            Eep_Ipw_xAsyncJob.InProgress = TRUE;
            RetVal = EEP_E_PENDING;
        }
    }
    else
    {
        FtfcStatus = Ftfc_Eep_Ip_GetJobResult();
        switch (FtfcStatus)
        {
            case FTFC_EEP_IP_STATUS_PENDING:
                RetVal = EEP_E_PENDING;
            break;

            case FTFC_EEP_IP_STATUS_OK:
                if (Eep_Ipw_xAsyncJob.Length > 0U)
                {
                    PageSize = Eep_Ipw_AlignedPageSize(Eep_Ipw_xAsyncJob.DestAddress, (Eep_AddressType)Eep_Ipw_xAsyncJob.SrcAddress, Eep_Ipw_xAsyncJob.Length);
                    FtfcStatus = Ftfc_Eep_Ip_Write(Eep_Ipw_xAsyncJob.DestAddress, Eep_Ipw_xAsyncJob.SrcAddress, PageSize, TRUE);

                    if (FTFC_EEP_IP_STATUS_PENDING == FtfcStatus)
                    {
                        Eep_Ipw_xAsyncJob.DestAddress += (Ftfc_Eep_Ip_AddressType)PageSize;
                        Eep_Ipw_xAsyncJob.SrcAddress = (uint8 const *)((Eep_AddressType)Eep_Ipw_xAsyncJob.SrcAddress + (uint8)PageSize);
                        Eep_Ipw_xAsyncJob.Length -= (Ftfc_Eep_Ip_LengthType)PageSize;
                        RetVal = EEP_E_PENDING;
                    }
                    else
                    {
                        Eep_Ipw_xAsyncJob.InProgress = FALSE;
                    }
                }
                else
                {
                    Eep_Ipw_xAsyncJob.InProgress = FALSE;
                    RetVal = EEP_E_OK;
                }
            break;

            default:
                Eep_Ipw_xAsyncJob.InProgress = FALSE;
            break;
        }
    }

#else /* EEP_ASYNC_WRITE_OPERATIONS_ENABLED */

    Ftfc_Eep_Ip_PageSizeType PageSize = FTFC_EEP_IP_PAGE_BYTE;

    while ((LengthRemaining > 0U) && (FTFC_EEP_IP_STATUS_OK == FtfcStatus))
    {
        PageSize = Eep_Ipw_AlignedPageSize(DestAdd, (Eep_AddressType)pu8SrcAdd, LengthRemaining);
        FtfcStatus = Ftfc_Eep_Ip_Write(DestAdd, pu8SrcAdd, PageSize, FALSE);
        LengthRemaining -= (Eep_LengthType)PageSize;
        DestAdd += (Eep_AddressType)PageSize;
        pu8SrcAdd = (uint8*)((Eep_AddressType)pu8SrcAdd + (Eep_AddressType)PageSize);
    }

    if (FTFC_EEP_IP_STATUS_OK == FtfcStatus)
    {
        RetVal = EEP_E_OK;
    }

#endif /* EEP_ASYNC_WRITE_OPERATIONS_ENABLED */

    /* Report the status of write operation */
    Eep_Ipw_ReportFailure(FtfcStatus, (uint32)EEP_MAINFUNCTION_ID);
    return RetVal;
}

#if (EEP_QUICK_WRITES_API == STD_ON)

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief       Check the parameters given for a QuickWrite job.
 *
 * @param[in]   DestAddress
 * @param[in]   pu8SrcAddress
 * @param[in]   Length
 * @param[in]   QuickWritesLength
 *
 * @return Ok / not ok to start the quick write job with those parameters.
 * @retval E_OK
 * @retval E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Eep_Ipw_CheckQuickWriteParams (Eep_AddressType DestAddress,
                                              uint8 const * pu8SrcAddress,
                                              Eep_LengthType Length,
                                              Eep_LengthType QuickWritesLength
                                             )
{
    Std_ReturnType retVal = E_NOT_OK;
    /* Both the lowest two bits are zero: 4 bytes aligned */
    Eep_AddressType CheckAddress = (DestAddress | (uint32)pu8SrcAddress) & 3U;
    /* Check the validity of destination address */
    if ((DestAddress >= FTFC_EEP_IP_EEP_SIZE) || (CheckAddress != 0U))
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_QUICK_WRITE_ID, EEP_E_PARAM_ADDRESS);
    #endif
    }
    /* Check the validity of length */
    else if ((0U == Length) || ((DestAddress + Length) > FTFC_EEP_IP_EEP_SIZE) ||
        (QuickWritesLength < 16U) || (QuickWritesLength > 512U) ||
        ((QuickWritesLength % 4U) != 0U) || ((Length % QuickWritesLength) != 0U))
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_QUICK_WRITE_ID, EEP_E_PARAM_LENGTH);
    #endif
    }
    /* Check the validity of source add */
    else if (NULL_PTR == pu8SrcAddress)
    {
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_QUICK_WRITE_ID, EEP_E_PARAM_DATA);
    #endif
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Quick Write operation.
 *
 * @param[in] DestAddress
 * @param[in] pu8SrcAddress
 * @param[in] Length
 *
 * @return The quick write call may end in one of the following states:
 * @retval EEP_E_OK
 * @retval EEP_E_FAILED
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Eep_ReturnType Eep_Ipw_QuickWrite (Eep_AddressType DestAddress,
                                   uint8 const * pu8SrcAddress,
                                   Eep_LengthType Length
                                  )
{
    Eep_ReturnType RetVal = EEP_E_OK;
    Ftfc_Eep_Ip_StatusType FtfcStatus = FTFC_EEP_IP_STATUS_OK;

    FtfcStatus = Ftfc_Eep_Ip_QuickWrite(DestAddress, pu8SrcAddress, Length);

    /* Check status after operation finish  */
    if (FTFC_EEP_IP_STATUS_OK != FtfcStatus)
    {
        RetVal = EEP_E_FAILED;
        Eep_Ipw_ReportFailure(FtfcStatus, (uint32)EEP_MAINFUNCTION_ID);
    }

    return RetVal;
}

#endif /* EEP_QUICK_WRITES_API */

#if (EEP_CANCEL_API == STD_ON)

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief  Cancel the current operation.
 *
 * @return the status of the IP HW
 * @retval EEP_E_OK       the FTFC operation finished
 * @retval EEP_E_PENDING  a timeout has occured while waiting for the HW IP
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Eep_ReturnType Eep_Ipw_Cancel (
    void)
{
    Eep_ReturnType Status = EEP_E_OK;
    uint32 Timeout = OsIf_MicrosToTicks(FTFC_EEP_IP_ABORT_TIMEOUT, FTFC_EEP_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(FTFC_EEP_IP_TIMEOUT_TYPE);
    uint32 ElapsedTicks = 0U;

    /* wait until FlexRam is ready or abort if timeout is reached */
    while (FTFC_EEP_IP_STATUS_PENDING == Ftfc_Eep_Ip_GetJobResult())
    {
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, FTFC_EEP_IP_TIMEOUT_TYPE);
        if (ElapsedTicks >= Timeout)
        {
            Status = EEP_E_PENDING;
            break;
        }
    }

#if ((EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_ON) || \
     (EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_ON))
    Eep_Ipw_xAsyncJob.InProgress = FALSE;
#endif

    return Status;
}

#endif /* EEP_CANCEL_API */

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief   Reports the brownout code to DEM.
 * @details The brownout code is read at init.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static void Eep_Ipw_ReportBrownOut (void)
{
    switch (Ftfc_Eep_Ip_GetBrownOutCode())
    {
        case FTFC_EEP_IP_BO_DURING_MAINTENANCE:
            if (TRUE == Eep_Ipw_pxEepConfig->Eep_E_BOMaintenanceCfg.state)
            {
                (void) Dem_SetEventStatus((Dem_EventIdType)Eep_Ipw_pxEepConfig->Eep_E_BOMaintenanceCfg.id, DEM_EVENT_STATUS_FAILED);
            }
        break;

        case FTFC_EEP_IP_BO_DURING_QUICK_WRITES:
            if (TRUE == Eep_Ipw_pxEepConfig->Eep_E_BOQuickWritesCfg.state)
            {
                (void) Dem_SetEventStatus((Dem_EventIdType)Eep_Ipw_pxEepConfig->Eep_E_BOQuickWritesCfg.id, DEM_EVENT_STATUS_FAILED);
            }
        break;

        case FTFC_EEP_IP_BO_DURING_NORMAL_WRITES:
            if (TRUE == Eep_Ipw_pxEepConfig->Eep_E_BONormalWritesCfg.state)
            {
                (void) Dem_SetEventStatus((Dem_EventIdType)Eep_Ipw_pxEepConfig->Eep_E_BONormalWritesCfg.id, DEM_EVENT_STATUS_FAILED);
            }
        break;

        case FTFC_EEP_IP_NO_BO_DETECTED:
            /* Nothing to report */
        break;

        default:
            /* corrupted value */
        break;
    }
}

#endif /* (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Report failures coming from IPL to DET / DEM.
 *
 * @param[in] FtfcStatus
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static void Eep_Ipw_ReportFailure (Ftfc_Eep_Ip_StatusType FtfcStatus,
                                   uint32 ApiID
                                  )
{
    switch (FtfcStatus)
    {
        case FTFC_EEP_IP_STATUS_TIMEOUT:
            (void) Det_ReportRuntimeError((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, (uint8)ApiID, EEP_E_TIMEOUT);
        break;

    #if (FTFC_EEP_IP_HIGH_TEMP_CHIP == STD_ON)
        case FTFC_EEP_IP_STATUS_FAILED_MGSTAT:
        #if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if (TRUE == Eep_Ipw_pxEepConfig->Eep_E_MGSTAT_BlockCfg.state)
            {
                (void) Dem_SetEventStatus((Dem_EventIdType)Eep_Ipw_pxEepConfig->Eep_E_MGSTAT_BlockCfg.id, DEM_EVENT_STATUS_FAILED);
            }
        #endif
        break;
    #endif

        default:
            /* nothing to report */
        break;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Compute the page size, considering the addresses alignment and the remaining bytes.
 *
 * @param[in]  FlexramAddress the FlexRAM address
 * @param[in]  RamAddress the RAM address
 * @param[in]  Length how many bytes are left to process
 *
 * @return the page size
 * @retval FTFC_EEP_IP_PAGE_BYTE     for unaligned operations
 * @retval FTFC_EEP_IP_PAGE_WORD     16-bit aligned operations
 * @retval FTFC_EEP_IP_PAGE_LONGWORD 32-bit aligned operations
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static Ftfc_Eep_Ip_PageSizeType Eep_Ipw_AlignedPageSize (Ftfc_Eep_Ip_AddressType FlexramAddress,
                                                         Ftfc_Eep_Ip_AddressType RamAddress,
                                                         Ftfc_Eep_Ip_LengthType Length
                                                        )
{
    Ftfc_Eep_Ip_PageSizeType PageSize = FTFC_EEP_IP_PAGE_BYTE;

#if (FTFC_EEP_IP_ALIGNED_RAM_ACCESS == STD_OFF)
    (void) RamAddress; /* avoid compiler warning */
#endif

    if ((0U == (FlexramAddress % (Ftfc_Eep_Ip_AddressType)FTFC_EEP_IP_PAGE_LONGWORD))
    #if (FTFC_EEP_IP_ALIGNED_RAM_ACCESS == STD_ON)
        && (0U == (RamAddress  % (Ftfc_Eep_Ip_AddressType)FTFC_EEP_IP_PAGE_LONGWORD))
    #endif
    )
    {
        if (Length >= (Ftfc_Eep_Ip_LengthType)FTFC_EEP_IP_PAGE_LONGWORD)
        {
            /* 4 bytes aligned and length >= 4 bytes: 4 bytes operation */
            PageSize = FTFC_EEP_IP_PAGE_LONGWORD;
        }
        else if (Length >= (Ftfc_Eep_Ip_LengthType)FTFC_EEP_IP_PAGE_WORD)
        {
            /* 4 bytes aligned and 4bytes > length >= 2 bytes : 2 bytes operation */
            PageSize = FTFC_EEP_IP_PAGE_WORD;
        }
        else
        {
            /* 4 bytes aligned and length < 2 bytes : 1 byte operation */
            PageSize = FTFC_EEP_IP_PAGE_BYTE;
        }
    }
    else if ((0U == (FlexramAddress % (Ftfc_Eep_Ip_AddressType)FTFC_EEP_IP_PAGE_WORD))
        #if (FTFC_EEP_IP_ALIGNED_RAM_ACCESS == STD_ON)
             && (0U == (RamAddress  % (Ftfc_Eep_Ip_AddressType)FTFC_EEP_IP_PAGE_WORD))
        #endif
            )
    {
        if (Length >= (Ftfc_Eep_Ip_LengthType)FTFC_EEP_IP_PAGE_WORD)
        {
            /* 2 bytes aligned and length >= 2 bytes : 2 bytes operation */
            PageSize = FTFC_EEP_IP_PAGE_WORD;
        }
        else
        {
            /* 2 bytes aligned and length < 2 bytes : 1 byte operation */
            PageSize = FTFC_EEP_IP_PAGE_BYTE;
        }
    }
    else
    {
        /* unaligned operation */
        PageSize = FTFC_EEP_IP_PAGE_BYTE;
    }

    return PageSize;
}

#define EEP_STOP_SEC_CODE
#include "Eep_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/
