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
#if (!defined PDUR_BLPDUR_H)
#define PDUR_BLPDUR_H

/*==================[includes]==============================================*/
#include <TSAutosar.h> /* EB specific standard types */
#include <ComStack_Types.h> /* AUTOSAR Communication Stack types */
/* Exclude post-build-time configuration include file if requested to do so */
#if (!defined PDUR_NO_PBCFG_REQUIRED) && (!defined PDUR_NO_CFG_REQUIRED)
#include <PduR_SymbolicNames_PBcfg.h>
#endif /* PDUR_NO_PBCFG_REQUIRED */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function declarations]========================*/
#define PDUR_START_SEC_CODE
#include <PduR_MemMap.h>

/** \brief This function is called by BlPduR module to request transmission of an I-PDU.
 **
 ** \param[in]  TxPduId      Identification of the Tx-PDU ID.
 ** \param[in]  PduInfoPtr   Length and pointer to the buffer of the I-PDU
 **
 ** \return Function execution success status
 ** \retval E_OK        Request is accepted by the destination module.
 ** \retval E_NOT_OK    Request is not accepted by the destination module.
 **
 ** \ServiceID{0x14}
 ** \Reentrancy{Reentrant for different PduIds. Non reentrant for the same PduId.}
 ** \Synchronicity{Synchronous}
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_BlPduRTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);

/**
 ** \brief  This service is called by the BlPduR module to request to change a specific transport
 ** protocol parameter (e.g. block-size). The affected transport protocol module is selected using the Rx I-PDU ID.
 **
 ** \param[in]  RxPduId           Identification of the Rx I-PDU to which the parameter the request shall affect.
 ** \param[in]  TPParameter       The selected parameter that the request shall changed.
 ** \param[in]  TPParameterValue  The value that the request shall change to.
 **
 ** \return Function execution success status
 ** \retval E_OK        Request is accepted.
 ** \retval E_NOT_OK    Request is not accepted.
 **
 ** \ServiceID{0x1D}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Asynchronous}
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_BlPduRTpChangeParameter
(
    PduIdType RxPduId,
    TPParameterType TPParameter,
    uint16 TPParameterValue
);

#define PDUR_STOP_SEC_CODE
#include <PduR_MemMap.h>

/*==================[internal function declarations]========================*/

#endif /* if !defined( PDUR_BLPDUR_H ) */
/*==================[end of file]===========================================*/
