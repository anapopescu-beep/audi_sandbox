/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=================================================================*/
#include <ComStack_Types.h>                               /* AUTOSAR standard types */
#include <Dcm_Dsl_CommunicationServices.h>                /* Dcm Communication Stack header file */
#include <Dcm_Int.h>
/*==================[macros]=====================================================================*/

/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/

/*==================[internal function declarations]=============================================*/

/*==================[internal constants]=========================================================*/

/*==================[internal data]==============================================================*/

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/* The configuration array for RxPduIDs.
*
* A Dcm Connection basically receives data from a number of RxPduIDs and transmits it to only ONE TxPduId.
* In order to identify which Connection to use we will always need to use the RxPduId of the incoming
* reception and from this infer all the data which we need to further handle reception, processing and transmission.
*
*/

/* !LINKSTO Dcm.Dsn.BufferManager.ConfigurationDataElements,1 */
/* Initialize global array holding the configuration for each buffer which is referenced from anywhere */
CONST(Dcm_BufferConfigType, DCM_CONST) Dcm_BufferConfig[DCM_NUM_CONFIGURED_BUFFERS] =
{
/* The index used for pointer to buffer  */
  {
    512U, /* Size of buffer*/
    &Dcm_Buffers[0] /* Pointer to buffer */
  },
/* The index used for pointer to buffer  */
  {
    512U, /* Size of buffer*/
    &Dcm_Buffers[512] /* Pointer to buffer */
  },
/* The index used for pointer to buffer  */
  {
    512U, /* Size of buffer*/
    &Dcm_Buffers[1024] /* Pointer to buffer */
  },
/* The index used for pointer to buffer  */
  {
    512U, /* Size of buffer*/
    &Dcm_Buffers[1536] /* Pointer to buffer */
  },
};

/* !LINKSTO Dcm.Dsn.RxConncetion.ConfigurationDataElements,1 */
/* Initialize global array holding the configuration for each RxPduId */
CONST(Dcm_RxPduIdConfigType, DCM_CONST) Dcm_RxPduIdConfig[DCM_NUM_RX_PDU_ID] =
{
  {
    /* This is the configuration of RxPduId 0 */
    DCM_PHYSICAL_TYPE, /* AddressingType */
    0U, /* BufferIndex */
    0U, /* MainConnectionIndex */
    0U /* ChannelIdConfigIndex */
  },
  {
    /* This is the configuration of RxPduId 1 */
    DCM_PHYSICAL_TYPE, /* AddressingType */
    0U, /* BufferIndex */
    1U, /* MainConnectionIndex */
    0U /* ChannelIdConfigIndex */
  },
  {
    /* This is the configuration of RxPduId 2 */
    DCM_PHYSICAL_TYPE, /* AddressingType */
    0U, /* BufferIndex */
    2U, /* MainConnectionIndex */
    0U /* ChannelIdConfigIndex */
  },
  {
    /* This is the configuration of RxPduId 3 */
    DCM_FUNCTIONAL_TYPE, /* AddressingType */
    3U, /* BufferIndex */
    3U, /* MainConnectionIndex */
    0U /* ChannelIdConfigIndex */
  },
};

/* !LINKSTO Dcm.Dsn.DiagnosticSessionLayer.ConfigurationDataElements,1 */
/* Initialize global array holding the protocol configuration */
CONST(Dcm_ProtocolConfigType, DCM_CONST) Dcm_ProtocolConfig[DCM_NUM_PROTOCOLS] =
{
  {
    1U, /*P2ServerAdjustTime*/
    1U, /*P2StarServerAdjustTime */
    2U, /* Protocol preemption timeout */
    1U, /* Tx buffer Index */
    DCM_UDS_ON_CAN, /* Protocol ID */
    2U, /* Protocol priority */
    /* !LINKSTO Dcm.LinktoServiceTable.ProtocolInit,2 */
    0U, /* Dcm_SidTabConfigType */
    FALSE, /* endianness Conversion */
    TRUE /* Send RP OnTransToBoot */
  },
  {
    1U, /*P2ServerAdjustTime*/
    1U, /*P2StarServerAdjustTime */
    1U, /* Protocol preemption timeout */
    2U, /* Tx buffer Index */
    DCM_OBD_ON_CAN, /* Protocol ID */
    2U, /* Protocol priority */
    /* !LINKSTO Dcm.LinktoServiceTable.ProtocolInit,2 */
    0U, /* Dcm_SidTabConfigType */
    FALSE, /* endianness Conversion */
    TRUE /* Send RP OnTransToBoot */
  },
};

/* !LINKSTO Dcm.Dsn.TxConnection.ConfigurationDataElements,1 */
/* !LINKSTO Dcm.Eb.MainConnectionConfig,1 */
/* !LINKSTO Dcm.Eb.Virtual.TxConnectionPduId,1 */
/* Initialize global array holding the configuration for each DcmDslMainConnection */
CONST(Dcm_MainConnectionConfigType, DCM_CONST) Dcm_MainConnectionConfig[DCM_NUM_MAIN_CONNECTIONS] =
{
  {
    1U, /* TxPduId */
    0U, /* TxConfirmationPduId*/
    0, /* TesterSourceAddress */
    0, /* ProtocolIndex */
  },
  {
    0U, /* TxPduId */
    1U, /* TxConfirmationPduId*/
    0, /* TesterSourceAddress */
    0, /* ProtocolIndex */
  },
  {
    2U, /* TxPduId */
    2U, /* TxConfirmationPduId*/
    0, /* TesterSourceAddress */
    0, /* ProtocolIndex */
  },
  {
    3U, /* TxPduId */
    3U, /* TxConfirmationPduId*/
    3, /* TesterSourceAddress */
    1, /* ProtocolIndex */
  },
};


#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/* Array holding the channel identifiers configured and the current state the channel is in */
CONST(NetworkHandleType, DCM_CONST) Dcm_RxComMChannelIDs[DCM_NUM_RX_COMM_CHANNELS] =
{
  0U,
};

#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>
/*==================[external constants]=========================================================*/

/*==================[external data]==============================================================*/


/*==================[external function definitions]==============================================*/

/*==================[internal function definitions]==============================================*/

/*==================[end of file]================================================================*/
