/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined PDUR_INT_CFG_H)
#define PDUR_INT_CFG_H

/*==================[includes]==============================================*/

#include <TSAutosar.h>              /* EB specific standard types */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/** \brief This function is called by the TP gateway for reception of an I-PDU by the <ModuleName>.
**
** \param[in]  RxPduId     Identification of the Target-PDU ID.
** \param[in]  PduInfoPtr  Length and pointer to the buffer of the I-PDU
**
** \return Function execution success status
** \retval E_OK        Request is accepted by the destination module.
** \retval E_NOT_OK    Request is not accepted by the destination module.
**
** \Reentrancy{Reentrant for different PDU IDs. Non reentrant for the same PDU ID.}
** \Synchronicity{Synchronous}
**/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_GateTpDcmReception
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);


/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( PDUR_INT_CFG_H ) */
/*==================[end of file]===========================================*/
