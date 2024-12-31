/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
 *
 * \version 5.3.44
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2020 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/*==================[includes]==============================================*/


#include <TSAutosar.h> /* EB specific standard types */
#include <ComStack_Types.h> /* AUTOSAR Communication Stack types */
#include <PduR_Internal_Static.h> /* Internal API (static part) */
#define PDUR_NO_PBCFG_REQUIRED /* This prevents the inclusion of the symbolic name value header */
#include <PduR_BlPduR.h> /* Header provided to Generic Upper Layer */
#define PDUR_NO_PBCFG_REQUIRED /* This prevents the inclusion of the symbolic name value header */
#include <PduR_CanTp.h> /* Header provided to Generic Upper Layer */
#include <PduR_Lcfg.h> /* Link-time configurable data */
#include <PduR_Types.h> /* PduR specific types */

/*==================[macros]================================================*/
/*==================[type definitions]======================================*/

typedef P2VAR(PduInfoType, AUTOMATIC, TYPEDEF) PduR_PduInfoPtrType;
typedef P2VAR(RetryInfoType, AUTOMATIC, TYPEDEF) PduR_RetryInfoPtrType;

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/


/*==================[external function definitions]=========================*/

/* AUTOSAR Memory Mapping - start section for code */
#define PDUR_START_SEC_CODE
#include <PduR_MemMap.h>

/*****************************************************************************
    TP API for generic layer BlPduR
*****************************************************************************/

FUNC(Std_ReturnType, PDUR_CODE) PduR_BlPduRTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType RetVal;

    /* Call generic Transmit function with index PduR_BlPduRRTabUpTpConfigIdx
     * to select the proper configuration */
    RetVal = PduR_GenericTpTransmit(TxPduId, PduInfoPtr, PduR_BlPduRRTabUpTpConfigIdx);

    return RetVal;
}

FUNC(Std_ReturnType, PDUR_CODE) PduR_BlPduRTpChangeParameter
(
    PduIdType RxPduId,
    TPParameterType TPParameter,
    uint16 TPParameterValue
)
{
    Std_ReturnType RetVal;

    /* Call generic ChangeParameter function with index PduR_BlPduRRTabUpTpConfigIdx
     * to select the proper configuration */
    RetVal = PduR_GenericTpChangeParameter(RxPduId, TPParameter, TPParameterValue,
                                                  PduR_BlPduRRTabUpTpConfigIdx);

    return RetVal;
}

/*****************************************************************************
    TP API for generic layer CanTp
*****************************************************************************/

FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpStartOfReception
(
    PduIdType RxPduId,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr
)
{
    BufReq_ReturnType RetVal;

    /* Call generic StartOfReception function with index PduR_CanTpRTabLoTpConfigIdx
     * to select the proper configuration */
    RetVal = PduR_GenericTpStartOfReception(RxPduId, TpSduLength, BufferSizePtr, PduR_CanTpRTabLoTpConfigIdx);

    return RetVal;
}

FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyRxData
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr
)
{
    BufReq_ReturnType RetVal;

    /* Call generic CopyRxData function with index PduR_CanTpRTabLoTpConfigIdx for
     * selecting the proper configuration */
    RetVal = PduR_GenericTpCopyRxData(RxPduId, PduInfoPtr, BufferSizePtr, PduR_CanTpRTabLoTpConfigIdx);

    return RetVal;
}


FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyTxData
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) RetryInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) AvailableDataPtr
)
{
    BufReq_ReturnType RetVal;

    /* Call generic CopyTxData function with index PduR_CanTpRTabLoTpConfigIdx
     * for selecting the proper configuration */
    RetVal = PduR_GenericTpCopyTxData(TxPduId, PduInfoPtr, RetryInfoPtr, AvailableDataPtr, PduR_CanTpRTabLoTpConfigIdx);

    return RetVal;
}



FUNC(void, PDUR_CODE) PduR_CanTpRxIndication
(
    PduIdType    RxPduId,
    NotifResultType  Result
)
{
    /* Call generic RxIndication function with index PduR_CanTpRTabLoTpConfigIdx
     * to select the proper configuration */
    PduR_GenericTpRxIndication(RxPduId, Result, PduR_CanTpRTabLoTpConfigIdx);
}



FUNC(void, PDUR_CODE) PduR_CanTpTxConfirmation
(
    PduIdType    TxPduId,
    NotifResultType  Result
)
{
    /* Call generic TxConfirmation function with index PduR_CanTpRTabLoTpConfigIdx
     * for selecting the proper configuration */
    PduR_GenericTpTxConfirmation(TxPduId, Result, PduR_CanTpRTabLoTpConfigIdx);
}



/* AUTOSAR Memory Mapping - stop section for code */
#define PDUR_STOP_SEC_CODE
#include <PduR_MemMap.h>

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
