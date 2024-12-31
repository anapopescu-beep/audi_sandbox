/*********************************************************************************/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                                BLPDUR configuration                              */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file BLPDUR_Types.h                     */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 0.9.0 BL-3.X                */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*********************************************************************************/
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*********************************************************************************/
#ifndef BLPDUR_TYPES_H
#define BLPDUR_TYPES_H

typedef u8 tRxPduType;
#define BLPDUR_STANDARD_CAN_ID 0U
#define BLPDUR_EXTENDED_CAN_ID 1U
#define BLPDUR_NOT_CAN_ID      2U

typedef u8 tBlPduRStatus;
#define BLPDUR_E_NOT_OK       0U
#define BLPDUR_E_OK           1U
#define BLPDUR_E_IDLE         2U
#define BLPDUR_E_BUSY         3U

typedef u8 tAddressingType;
#define BLPDUR_PHYSICAL       UDS_ADDR_PHYSICAL
#define BLPDUR_FUNCTIONAL     UDS_ADDR_FUNCTIONAL

typedef u8 tTpParameterId;
/*Should be in accordance with PduR type TPParameterType*/
/* Separation Time */
#define BLPDUR_TP_STMIN     0U
/* Block Size */
#define BLPDUR_TP_BS        1U
/* The Band width control parameter used in FlexRay transport protocol module. */
#define BLPDUR_TP_BC        2U


/** \brief State of a buffer in the TP_UDS module **/
typedef enum
{
  /** \brief Buffer is not in use right now */
    BLPDUR_BUFF_IDLE,
  /** \brief Buffer is used for reception */
    BLPDUR_BUF_RX_IN_PROGRESS,
    /** \brief Buffer is used for processing the request */
    BLPDUR_BUFF_PROCESSING,
    /** \brief Buffer is used for processing while the response is already sent */
    BLPDUR_BUFF_LOCK
} tBufferStateType;

typedef struct
{
  /** \brief Length of valid data in bytes stored in this buffer
   *
   * The length information is used for reception and transmission.*/
  PduLengthType       filledLen;

  /** \brief Holds index of valid data in bytes to be transmitted in this buffer */
  PduLengthType       dataMark;

  /** \brief Holds index of Confirmed data in bytes in this buffer */
  PduLengthType       confirmedDataMark;

  /** \brief State of this buffer */
  tBufferStateType state;

  /** \brief RxPduId which was used to fill the buffer
   *
   * Only valid if the buffer state is BUF_RX  */
  PduIdType           originatingRxPduId;

} tBufferInfoType;

typedef struct
{
  /** \brief location of buffer **/
  uint8 *ptrBuffer;
  /** \brief status information for this buffer configuration **/
  tBufferInfoType *bufferInfo;
  /** \brief Size of this buffer **/
  PduLengthType size;
} tBufferConfigType;

typedef struct
{
    /** \brief Connection number of the Rx PDU **/
    u8 ConnectionNum;
    /** \brief Addressing type of the PDU : Physical, Functional **/
    tAddressingType AddressingType;
    /** \brief Rx PDU Id**/
    u8 RxPduId;
    /** \brief Rx PDU Type **/
    tRxPduType RxPduType;
} tRxPdu;

typedef struct
{
    /** \brief Tx Pdu value for the connection **/
    u8 TxPdu;
    /** \brief Tester address linked to the Tx connection **/
    u8 TestAddress;
} tPduConnection;


/* Patch for compile version */
typedef u8 tTpMsgIdx;
#define TP_MSG_STATUS_OK        BLPDUR_E_OK
#define EB_Send_TPFrame         BlPduR_Send_TPFrame
#define EB_Init                 BlPduR_Init
#define EB_SetTesterAddress     BlPduR_SetTesterAddress
#define EB_Com_Deactivate       BlPduR_Custom_Com_Deactivate
#define EB_SimulateRxRequest    BlPduR_SimulateRxRequest

#endif      /* BLPDUR_TYPES_H */

