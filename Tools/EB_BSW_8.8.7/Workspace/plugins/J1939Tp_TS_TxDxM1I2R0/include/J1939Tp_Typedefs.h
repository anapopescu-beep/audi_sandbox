/**
 * \file
 *
 * \brief AUTOSAR J1939Tp
 *
 * This file contains the implementation of the AUTOSAR
 * module J1939Tp.
 *
 * \version 1.2.6
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2023 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef J1939TP_TYPEDEFS_H                                /* To avoid double inclusion */
#define J1939TP_TYPEDEFS_H

/*==============================================================================*/
/* Include Files Section                                                        */
/*==============================================================================*/
/* !LINKSTO J1939Tp.EB.Header.ComStack,1 */
/* !LINKSTO EB_Ref.SWS_J1939Tp_00230.ComStack_Types,1 */
/* !LINKSTO EB_Ref.SWS_J1939Tp_00230.Std_Types,1 */
#include <ComStack_Types.h>
#include <J1939Tp_Version.h>

/*======================Macro Definitions========================================*/
/* !LINKSTO J1939Tp.SWS_J1939Tp_00019,1 */
#define J1939TP_OFF                                            (uint8)0x00U      /**< The feature is switched OFF */
#define J1939TP_ON                                             (uint8)0x01U      /**< The feature is switched ON */
#define J1939TP_INSTANCE_ID                                    (uint8)0x00U
#define J1939TP_MAX_DT_MSGLENGTH                               7U
#define J1939TP_DT_OVERHEAD_LENGTH                             1U
#define J1939TP_DT_CANFD_OVERHEAD_LENGTH                       4U
#define J1939TP_MAX_CANFD_DT_MSGLENGTH                         60U
#define J1939TP_MAX_CAN_FRAME_LENGTH                           8U
#define J1939TP_MAX_CANFD_FRAME_LENGTH                         64U
#define J1939TP_MAX_SAE_ALLOWED_MSGLENGTH                      1785U
#define J1939TP_MAX_SAE_22_BAM_ALLOWED_MSGLENGTH               15300U
#define J1939TP_MAX_SAE_22_CMDT_ALLOWED_MSGLENGTH              16777215U
#define J1939TP_CANFD_BAM_MAX_CONCURRENT_SESSIONS              4U
#define J1939TP_CANFD_CMDT_MAX_CONCURRENT_SESSIONS             8U
#define J1939TP_INVALID_SESSION_NUMBER                         0xFFU
#define J1939TP_INVALID_FC                                     0xFFU
#define J1939TP_INVALID_IPDU                                   0xFFU
#define J1939TP_INVALID_ECUC_ID                                0xFFFFU
#define J1939TP_INVALID_ADDRESS                                0xFFU
#define J1939TP_INVALID_SEQUENCE_NUMBER                        0xFFFFFFFFU
#define J1939TP_TPCM_RTS                                       0x10U
#define J1939TP_TPCM_CTS                                       0x11U
#define J1939TP_TPCM_ENDOFMSGACK                               0x13U
#define J1939TP_TPCM_ABORT                                     0xFFU
#define J1939TP_TPCM_BAM                                       0x20U
#define J1939TP_CANFD_TPCM_RTS                                 0x00U
#define J1939TP_CANFD_TPCM_CTS                                 0x01U
#define J1939TP_CANFD_TPCM_ENDOFMSGSTATUS                      0x02U
#define J1939TP_CANFD_TPCM_ENDOFMSGACK                         0x03U
#define J1939TP_CANFD_TPCM_ABORT                               0x0FU
#define J1939TP_CANFD_TPCM_BAM                                 0x04U
#define J1939TP_CANFD_PADDING                                  0xAAU
#define J1939TP_DYNAMIC_ASSURANCE_DATA_LENGTH                  0xFFU
#define J1939TP_SN_MAX                                         0xFFU                   /** Maximum value for sequence number */
#define J1939TP_UNUSED_BYTE_PADDING                            0xFFU                   /** unused byte for the data frame should be always padded with 0xFF */
/* J1939Tp Assurance Data Types */
#define J1939TP_NO_ASSURANCE_DATA                                           0x00U      /** Assurance Data Type */
#define J1939TP_CYBERSECURITY_ASSURANCE_DATA                                0x01U      /** Assurance Data Type */
#define J1939TP_FUNCTIONAL_SAFETY_ASSURANCE_DATA                            0x02U      /** Assurance Data Type */
#define J1939TP_COMBINED_CYBERSECURITY_FUNCTIONAL_SAFETY_ASSURANCE_DATA     0x03U      /** Assurance Data Type */
/* J1939Tp ABORT Reasons */
#define J1939TP_TPCM_ABORT_REASON_CONNECTION                   0x01U         /** Abort Reason */
#define J1939TP_TPCM_ABORT_REASON_RESOURCES                    0x02U         /** Abort Reason */
#define J1939TP_TPCM_ABORT_REASON_TIMEOUT                      0x03U         /** Abort Reason */
#define J1939TP_TPCM_ABORT_REASON_UNDEFINED                    0xFFU         /** Abort Reason */
#define J1939TP_TPCM_ABORT_REASON_CTS_RX_WHEN_DATA_TRANSMIT    0x04U         /** Abort Reason */
#define J1939TP_TPCM_ABORT_REASON_MAX_RETRANSMIT_REACHED       0x05U         /** Abort Reason */
#define J1939TP_TPCM_ABORT_REASON_UNEXPECTED_DATA_PACKET       0x06U         /** Abort Reason */
#define J1939TP_TPCM_ABORT_REASON_BAD_SEQUENCE_NUMBER          0x07U         /** Abort Reason */
#define J1939TP_TPCM_ABORT_REASON_DUPLICATE_SEQUENCE_NUMBER    0x08U         /** Abort Reason */
#define J1939TP_TPCM_ABORT_REASON_GREATER_TOTAL_MSG_SIZE       0x09U         /** Abort Reason */
#define J1939TP_TPCM_ABORT_REASON_ASSURANCE_DATA_MISMATCH      0x0AU         /** Abort Reason */
#define J1939TP_TPCM_ABORT_REASON_ASSURANCE_DATA_NOT_RECEIVED  0x0BU         /** Abort Reason */
#define J1939TP_TPCM_ABORT_REASON_UNLISTED                     0xFAU         /** Abort Reason */
/* !LINKSTO J1939Tp.SWS_J1939Tp_00200,1 */
#define J1939TP_FRAME_LENGTH                                   8U         /** Length for the frame */
#define J1939TP_CANFD_CONTROL_FRAME_LENGTH                     12U        /** Length for the CanFD control frame */
#define J1939TP_DATA_LENGTH                                    7U         /** Length of the data in the data frame with out padding */
#define J1939TP_IDLE                                           0U         /** IDLE state */
#define J1939TP_TX_IDLE                                        0U         /** IDLE state for transmit direction */
#define J1939TP_RX_IDLE                                        0U         /** IDLE state for receive direction */
/* J1939TP DIRECTPG TX States */
#define J1939TP_DIRECTPG_TX_STATE_REQ                          0x01U
#define J1939TP_DIRECTPG_TX_STATE_WAIT_CONFIRMATION            0x02U
/* J1939TP BAM TX States */
#define J1939TP_BAM_TX_STATE_REQ                               0x10U
#define J1939TP_BAM_TX_STATE_WAIT_CONFIRMATION_DT              0x11U
#define J1939TP_BAM_TX_STATE_DATA_TRANSMISSION                 0x12U
#define J1939TP_BAM_TX_STATE_WAIT_CONFIRMATION_CM              0x13U
#define J1939TP_BAM_TX_STATE_ABORT                             0x14U
#define J1939TP_BAM_TX_STATE_WAIT_CONFIRMATION_ABORT           0x15U
#define J1939TP_BAM_TX_STATE_EOMS_TRANSMISSION                 0x52U
#define J1939TP_BAM_TX_STATE_WAIT_CONFIRMATION_EOMS            0x53U

/* J1939TP BAM RX States */
#define J1939TP_BAM_RX_STATE_NOTIFY_PDUR                       0x20U
#define J1939TP_BAM_RX_STATE_WAIT_DATA                         0x21U
/* J1939TP CANFD RX States */
#define J1939TP_RX_STATE_BAM_WAIT_EOMS                         0x22U
#define J1939TP_RX_STATE_CMDT_WAIT_EOMS                        0x23U
#define J1939TP_RX_STATE_CMDT_WAIT_CONFIRMATION_EOMS_RQST      0x24U
/* J1939TP CMDT TX States */
#define J1939TP_CMDT_TX_STATE_RTS_SEND                         0x30U
#define J1939TP_CMDT_TX_STATE_WAIT_CONFIRMATION_RTS            0x31U
#define J1939TP_CMDT_STATE_CTS0                                0x32U
#define J1939TP_CMDT_STATE_CTS                                 0x33U
#define J1939TP_CMDT_TX_STATE_DATA_TRANSMISSION                0x34U
#define J1939TP_CMDT_TX_STATE_WAIT_CONFIRMATION_DATA           0x35U
#define J1939TP_CMDT_TX_STATE_WAIT_ENDOFMSGACK                 0x36U
#define J1939TP_CMDT_TX_STATE_ABORT                            0x37U
#define J1939TP_CMDT_TX_STATE_WAIT_CONFIRMATION_ABORT          0x38U
#define J1939TP_CMDT_TX_STATE_EOMS_TRANSMISSION                0x4FU
#define J1939TP_CMDT_TX_STATE_WAIT_CONFIRMATION_EOMS           0x50U
/* J1939TP CMDT RX States */
#define J1939TP_CMDT_RX_STATE_RTS_RECEIVED                     0x40U
#define J1939TP_CMDT_RX_STATE_WAIT_DATA                        0x41U
#define J1939TP_CMDT_RX_STATE_CTS                              0x42U
#define J1939TP_CMDT_RX_STATE_CTS0                             0x43U
#define J1939TP_CMDT_RX_STATE_WAIT_CONFIRMATION_CTS            0x44U
#define J1939TP_CMDT_RX_STATE_WAIT_CONFIRMATION_CTS0           0x45U
#define J1939TP_CMDT_RX_STATE_DATA_COMPLETE                    0x46U
#define J1939TP_CMDT_RX_STATE_WAIT_CONFIRMATION_DATA_COMPLETE  0x47U
#define J1939TP_CMDT_RX_STATE_ABORT                            0x48U
#define J1939TP_CMDT_RX_STATE_WAIT_CONFIRMATION_ABORT          0x49U
/* J1939TP PGNs */
#define J1939TP_DEFAULT_PRIORITY                               0x07U
#define J1939TP_TP_CM_PGN                                      0xECU
#define J1939TP_TP_DT_PGN                                      0xEBU
#define J1939TP_CANFD_TP_CM_PGN                                0x4DU
#define J1939TP_CANFD_TP_DT_PGN                                0x4EU
/*=====================Structure TypeDefs=======================================*/


typedef enum {
J1939TP_PROTOCOL_BAM,
J1939TP_PROTOCOL_CMDT
}J1939Tp_ProtocolType;

/* This type represents frame possible states. */
typedef enum {
J1939TP_FRAME_SENT,                       /* Frame is sent on bus (0) */
J1939TP_FRAME_PENDING,                    /* Frame is still pending to be send but to N-PDU is not available (1) */
J1939TP_FRAME_REJECTED                    /* Frame has not been accepted by the lower layer. */
}J1939TP_FrameStateType;

typedef P2FUNC(void, AUTOMATIC, J1939Tp_GetVersionInfoType_FctPtrType)(Std_VersionInfoType * VersionInfo);

typedef P2FUNC(Std_ReturnType, AUTOMATIC, J1939Tp_CancelTransmit_FctPtrType)(PduIdType TxSduId);

typedef P2FUNC(Std_ReturnType, AUTOMATIC, J1939Tp_CancelReceive_FctPtrType)(PduIdType RxSduId);

/*=========================Structure Definitions================================*/

typedef struct
{
    uint32  metaDatacanId;
    uint32  pgn;
    uint8   sa;
    uint8   da;
    uint8   MessageType;
    uint8   MetaDataLen;
    uint8   ReceivedLength;
    uint8   ch_idx;
    uint8   pg_idx;
    uint8   nsdu_idx;
    uint8   session_num;
    uint8   AssuranceDataType;
    boolean PduIdDirectPg;
    boolean PduId_CM_BAM;
}J1939Tp_SduInfoType;

typedef struct
{
    uint8 J1939TpSrcAdd;                   /* Source Address of the node of ongoing reception */
    uint8 J1939TpDestAdd;                  /* Dest Address of the node of ongoing reception */
    boolean J1939TpChannelBusy;            /* Channel State */
    boolean J1939TpTxCmNPduAvailable;      /* If False, means that CM N-PDU has ongoing transmission not confirmed from lower layer. True otherwise. */
    boolean J1939TpTxDtNPduAvailable;      /* If False, means that DT (Data) N-PDU has ongoing transmission not confirmed from lower layer. True otherwise. */
    boolean J1939TpTxFcNPduAvailable;      /* If False, means that FC N-PDU has ongoing transmission not confirmed from lower layer. True otherwise. */
}J1939Tp_ChannelInfoType;

typedef struct
{
    uint32 pgn;                                     /* Storing the pgn for using in the conn_abort and EndOfMsgAck frame */
    boolean AbortFlag;                              /* If True, This flag indicates an abort frame is available to be sent. False otherwise */
    boolean txconfirmation;                         /* This flag is used in the J1939Tp_TxConfirmation function TRUE: got confirmation else FALSE */
    uint8 AbortReason;                              /* Rx Tx - Abort Reason */
    uint8 sa;                                       /* source address that is requested to transmit for the NSDU  */
    uint8 da;                                       /* destination address that is requested to transmit for the NSDU */
    uint8 session_num;                              /* session number */
}J1939Tp_ChannelAbortType;

typedef struct
{
    PduLengthType SduLength;                         /* Length of the received NPdu/NSdu */
    uint32 pgn;                                      /* Storing the pgn for using in the conn_abort and EndOfMsgAck frame */
    uint32 msglength;                                /* Rx Tx - length of the message */
    uint32 RxNoPacketsInRTS;                         /* Tx Rx - No of packets in the RTS frame */
    uint32 sn;                                       /* Rx Tx - current sequence number */
    uint32 data_cnt;                                 /* Current position within the buffer during a segmented data transfer */
    uint32 RxNoPacketReceived;                       /* No of packets received in the CMDT reception */
    uint32 SN_Confirmed_in_CTS;                      /* Confirmed Sequence Number SN in the last received CTS */
    uint16 T1TimeCounter;                            /* Rx -it counts the tick each time by calling the MainFunction, initially 0 when timer start */
    uint16 T2TimeCounter;                            /* Rx -it counts the tick each time by calling the MainFunction, initially 0 when timer start */
    uint16 T3TimeCounter;                            /* Tx -it counts the tick each time by calling the MainFunction, initially 0 when timer start */
    uint16 T4TimeCounter;                            /* Tx -it counts the tick each time by calling the MainFunction, initially 0 when timer start */
    uint16 T5TimeCounter;                            /* Tx -it counts the tick each time by calling the MainFunction, initially 0 when timer start */
    uint16 ThTimeCounter;                            /* Rx -it counts the tick each time by calling the MainFunction, initially 0 when timer start */
    uint16 TrTimeCounter;                            /* Tx -it counts the tick each time by calling the MainFunction, initially 0 when timer start */
    uint16 TxConfirmationTimeOutCounter;             /* Rx Tx - TxConfirmation Timeout */
    uint8 state;                                     /* Rx Tx -current state of the state machine */
    uint8 error_code;                                /* Rx Tx - error information */
    uint8 cts_packets;                               /* No of packets got in CTS frame */
    uint8 cnt_packets;                               /* Counter for sending DATA frame for each CTS */
    uint8 NrOfRxPacketsInCts;                        /* No of packets calculation for each CTS frame */
    uint8 TbamminTimeElapsed;                        /* Tx - TbamminTimeElapsed flag to set TRUE or FALSE  based on counter will reach the tick */
    uint8 StartTbamminTime;                          /* Tx - StartTbamminTime flag to set TRUE or FALSE to start or stop the timer */
    uint8 TbamminTimeCounter;                        /* Tx -it counts the tick each time by calling the MainFunction, initially 0 when timer start */
    uint8 StartT3Time;                               /* Tx - StartT3Time flag to set TRUE or FALSE to start or stop the timer */
    uint8 T3TimeElapsed;                             /* Tx - T3TimeElapsed flag to set TRUE or FALSE  based on counter will reach the tick */
    uint8 StartThTime;                               /* Rx - StartThTime flag to set TRUE or FALSE to start or stop the timer */
    uint8 ThTimeElapsed;                             /* Rx - ThTimeElapsed flag to set TRUE or FALSE  based on counter will reach the tick */
    uint8 StartT4Time;                               /* Tx - StartT4Time flag to set TRUE or FALSE to start or stop the timer */
    uint8 T4TimeElapsed;                             /* Tx - T4TimeElapsed flag to set TRUE or FALSE  based on counter will reach the tick */
    uint8 StartT5Time;                               /* Tx - StartT5Time flag to set TRUE or FALSE to start or stop the timer */
    uint8 T5TimeElapsed;                             /* Tx - T5TimeElapsed flag to set TRUE or FALSE  based on counter will reach the tick */
    uint8 StartT1Time;                               /* Rx - StartT1Time flag to set TRUE or FALSE to start or stop the timer */
    uint8 T1TimeElapsed;                             /* Rx - T1TimeElapsed flag to set TRUE or FALSE  based on counter will reach the tick */
    uint8 StartT2Time;                               /* Rx - StartT2Time flag to set TRUE or FALSE to start or stop the timer */
    uint8 T2TimeElapsed;                             /* Rx - T2TimeElapsed flag to set TRUE or FALSE  based on counter will reach the tick */
    uint8 StartTrTime;                               /* Tx - StartTrTime flag to set TRUE or FALSE to start or stop the Tr timer */
    uint8 TrTimeElapsed;                             /* Tx - TrTimeElapsed flag to set TRUE or FALSE  based on counter will reach the tick */
    uint8 StartTxConfirmationTimeOut;                /* Tx - StartTrTime flag to set TRUE or FALSE to start or stop the TxConfirmation Timer */
    uint8 TxConfirmationTimeOutElapsed;              /* Tx - TxConfirmation TimeOut elasped flag to set TRUE or FALSE  based on counter will reach the tick */
    uint8 TrTimeout_SendAbort;                       /* Tx - TrTimeout_SendAbort flag to set TRUE or FALSE  based on wither to send Abort frame or not when timeout */
    uint8 J1939TpMetaDataInfo[4U];                   /* Rx Tx - Array to hold the MetaData information of any type of NPdu/Sdu */
    uint8 AbortReason;                               /* Rx Tx - Abort Reason */
    uint8 session_num;                               /* Session number for CanFD transfer session */
    Std_ReturnType txconfirmationResult;             /* This flag is used to store the result of J1939Tp_TxConfirmation, either E_OK or E_NOT_OK.*/
    uint8 sa;                                        /* source address that is requested to transmit for the NSDU  */
    uint8 da;                                        /* destination address that is requested to transmit for the NSDU  */
    uint8 u8MAx_Nr_Pkts_Per_CTS ;                    /* Maximum number of packets that can be sent in response to one CTS (TP.CM_RTS) */
    boolean retry_cts_flag;                          /* Indicates that CTS is received with retry */
    boolean RxStartOfReceptionFlag;                  /* Rx - TRUE when PduR_J1939TpStartOfReception called, and FALSE after sending first CTS */
    boolean txconfirmation;                          /* This flag is used in the txconfirmation function TRUE: got confirmation else FALSE */
    boolean IsMultipleFrameType;                     /* Multiple Frame(CMDT/BAM) message or single frame Direct message  */
}J1939Tp_NSduCtrlType;

typedef struct
{
    P2VAR(J1939Tp_NSduCtrlType,AUTOMATIC,J1939TP_APPL_DATA) NsduCtrlPrt ;
    uint8 NsduNextState;
}J1939Tp_NsduAbortCtrlType;

typedef struct
{
    P2VAR(J1939Tp_NSduCtrlType, AUTOMATIC, J1939TP_APPL_DATA) J1939TpTxNSduCtrl;    /* RAM structure for monitoring the NSU parameters */
    uint16 J1939TpTxNSduId;                          /* Own ID for PduR for transmit request and canceltransmit */
    uint16 J1939TpTxNSduIdPduR;                      /* PduR ID for calling PduRTxconfirmation and PduRcopytxdata */
    uint16 J1939TpTxNSduIdEcuC;                      /* EcuC ID for the referenced pdu */
    uint8 txnsdumetadatalength;                      /* MetaDataLength for the configured NSDU in the transmit side */
    uint8 AssuranceDataType;                         /* Type of the assurance data configured */
    uint8 AssuranceDataLength;                       /* Length of the assurance data configured */
}J1939Tp_TxNSduType;

typedef struct
{
    CONSTP2CONST(J1939Tp_TxNSduType, AUTOMATIC, J1939TP_APPL_CONST) J1939TpTxNSdu;
    uint32 J1939TpTxPgPGN;                         /* PGN of the referenced N-SDUs. */
    uint16 J1939TpTxDirectNPduTxConfIdEcuC;        /* EcuC Pdu ID for Transmit the Direct PG */
    uint16 J1939TpTxDirectNPduTxConfId;            /* Own ID for TxConfirmation from CanIf */
    uint16 J1939TpTxDirectNPduTxConfIdTxIf;        /* CanIf ID for Transmit the Direct PG */
    const uint8 J1939TpTxDirectNPduMetaDataLen;    /* MetaDataLength of DirectNpduRef Pdu configured in EcuC */
    const uint8 J1939TpNumberOfTxNSdu;             /* Number of configured transmit NSdus */
    boolean J1939TpTxPgDynLength;                  /* This flag is set to TRUE when the N-SDU refers to a PGN with variable length. */
}J1939Tp_TxPgType;

typedef struct
{
    CONSTP2CONST(J1939Tp_TxPgType, AUTOMATIC, J1939TP_APPL_CONST) J1939TpTxPg;
    P2VAR(J1939Tp_ChannelInfoType, AUTOMATIC, J1939TP_APPL_DATA) ChannelStatus;        /* Channel status */
    P2VAR(RetryInfoType, AUTOMATIC, J1939TP_APPL_DATA) J1939TpTxRetryInfo;             /* RetryInfoType pointer to hold info for retry parameter for CopyTxData feature */
    P2VAR(boolean, AUTOMATIC, J1939TP_APPL_DATA) J1939TpTxDirectNPduAvailable;         /* Flag that indicates if a direct PG pdu is available */
    J1939Tp_ProtocolType J1939TpTxProtocolType;      /* Protocol type used by this channel. This parameter is only required for channels with fixed destination address. */
    uint16 J1939TpTxCmNPduTxRTS;                     /* Own ID for TP.CM/BAM or RTS frame transmit Confirmation ID used by CanIf */
    uint16 J1939TpTxCmNPduTxRTSCanIf;                /* Lower layer ID-Tx NDU ID of CanIf for Transmit RTS or BAM */
    uint16 J1939TpTxDtNPduTxConfId;                  /* Own ID-For Dt Tx confirmation used by CanIf to J1939Tp */
    uint16 J1939TpTxDtNPduTxConfIdCanIf;             /* Lower layr ID for CanIf transmit for Dt Frame */
    uint16 J1939TpRxFcNPduIdCTS;                     /* Own ID- N-PDU identifier used by CanIf for transmit CTS. */
    const uint16 J1939TpRxFcNPduTxConfIdEcuC;        /* EcuC PduId of J1939TpRxFcNPdu */
    const uint16 J1939TpTxCmNPduTxConfIdEcuC;        /* EcuC PduId of J1939TpTxCmNPdu */
    const uint16 J1939TpTxDtNPduTxConfIdEcuC;        /* EcuC PduId of J1939TpTxDtNPdu */
    const uint8 J1939TpTxDa;                         /* Destination address (DA) of this channel. This parameter is only required for channels with fixed DA which use N-PDUs with MetaData containing the DA */
    const uint8 J1939TpTxMaxPacketsPerBlock;         /* Maximum number of TP.DT frames the transmitting J1939Tp module is ready to send before waiting for another TP.CM_CTS. This parameter is transmitted in the TP.CM_RTS frame, and is thus only relevant for transmission of messages via CMDT. When J1939TpTxDynamicBlockCalculation is enabled, this parameter specifies a maximum for the calculated value. */
    const uint8 J1939TpTxSa;                         /* Source address (SA) of this channel. This parameter is only required for channels with fixed SA which use N-PDUs with MetaData. */
    const uint8 J1939TpNumberOfTxPg;                 /* Number of configured Tx Pgs */
    const uint8 J1939TpRxFcNPduMetaData;             /* MetaDataLength of J1939TpRxFcNPdu */
    const uint8 J1939TpTxCmNPduMetaData;             /* MetaDataLength of J1939TpTxCmNPdu */
    const uint8 J1939TpTxDtNPduMetaData;             /* MetaDataLength of J1939TpTxDtNPdu */
    boolean J1939TpTxRetrySupport;                   /* Enable support for repetition of failed transmission using TP.CM_CTS with a packet number that has already been sent. Retransmission is handled via the retry feature of PduR_J1939TpCopyTxData. */
    boolean J1939TpTxDynamicBlockCalculation;        /* Enable dynamic calculation of "maximum number of packets that can be sent" value in TP.CM_RTS, based on the available amount of data in upper layers reported via PduR_J1939TpCopyTxData. */
    boolean J1939TpTxCancellationSupport;            /* Enable transmit cancellation using the API J1939Tp_CancelTransmit() for this channel */
    boolean J1939TpTxCanFDSupport;                   /* Enable CanFD message transmission for this channel */
}J1939Tp_TxChannelType;

typedef struct
{
    P2VAR(J1939Tp_NSduCtrlType, AUTOMATIC, J1939TP_APPL_DATA) J1939TpRxNSduCtrl;   /* RAM structure for monitoring the NSU parameters */
    uint16 J1939TpRxNSduId;                                                        /* Own ID for CancelReceive used by PduR */
    uint16 J1939TpRxNSduIdPduR;                                                    /* PduR ID for reception side(for all 3 functions) */
    uint16 J1939TpRxNSduIdEcuC;                                                    /* EcuC ID for the referenced pdu */
    const uint8 RxNsduMetaDataLen;                                                 /* MetaDataLength for the configured NSDU in the receiver side */
    uint8 AssuranceDataType;                                                       /* Type of the assurance data configured */
    uint8 AssuranceDataLength;                                                     /* Length of the assurance data configured */
}J1939Tp_RxNSduType;

typedef struct
{
    CONSTP2CONST(J1939Tp_RxNSduType, AUTOMATIC, J1939TP_APPL_CONST) J1939TpRxNSdu;   /* J1939TpRxNSdu container */
    uint32 J1939TpRxPgPGN;                           /* PGN of the referenced N-SDUs. */
    uint16 J1939TpTxDirectNPduRxConfIdEcuC;        /* EcuC Pdu ID for Receive the Direct PG */
    uint16 J1939TpRxDirectNPduId;                    /* Own ID for RxIndication for Direct Pdu */
    const uint8 J1939TpRxDirectNPduMetaDataLen;         /* MetaDataLength of DirectNpduRef Pdu configured in EcuC */
    const uint8 J1939TpNumberOfRxNSdu;               /* Number of configured receive NSdus */
    boolean J1939TpRxPgDynLength;                    /* This flag is set to TRUE when the N-SDU refers to a PGN with variable length. */
}J1939Tp_RxPgType;

typedef struct
{
    CONSTP2CONST(J1939Tp_RxPgType, AUTOMATIC, J1939TP_APPL_CONST) J1939TpRxPg;   /* J1939TpRxPg container */
    P2VAR(J1939Tp_ChannelInfoType, AUTOMATIC, J1939TP_APPL_DATA) ChannelStatus;     /* Channel status */
    P2VAR(J1939Tp_ChannelAbortType, AUTOMATIC, J1939TP_APPL_DATA) J1939TpRxChannelAbort; /* Abort data for messages not related to any N-SDU. In case of concurrent transmission this data is overwritten */
    J1939Tp_ProtocolType J1939TpRxProtocolType;                                 /* Protocol type used by this channel. This parameter is only required for channels with fixed destination address. */
    const uint16 J1939TpTxFcNPduRxConfIdEcuC;        /* EcuC PduId of J1939TpRxFcNPdu */
    const uint16 J1939TpRxCmNPduRxConfIdEcuC;        /* EcuC PduId of J1939TpTxCmNPdu */
    const uint16 J1939TpRxDtNPduRxConfIdEcuC;        /* EcuC PduId of J1939TpTxDtNPdu */
    uint16 J1939TpRxCmNPduId;                        /* TP Own ID-RX N-PDU ID for TP.CM and abort in CMDT: CanIf -> J1939Tp */
    uint16 J1939TpRxDtNPdu;                          /* TP Own ID-RX N-PDU ID for TP.DT: Canif -> J1939Tp */
    uint16 J1939TpTxCTSCanIf;                        /* Tx N-PDU ID of CanIf for transmitting CTS used by J1939Tp */
    uint16 J1939TpTxCTSCanIfConf;                    /* Tx N-PDU ID for TP own used by CanIf for giving confirmation of transmit CTS */
    uint8 J1939TpRxDynamicBufferRatio;               /* Percentage of available buffer that shall be used for retry.This parameter is only applicable when "J1939TpRxRetrySupport" and "J1939TpRxDynamicBlockCalculation" are enabled. */
    uint8 J1939TpRxDa;                               /* Destination address (DA) of this channel. This parameter is only required for channels with fixed DA which use N-PDUs with MetaData containing the DA */
    uint8 J1939TpRxPacketsPerBlock;                  /* Number of TP.DT frames the receiving J1939Tp module allows the sender to send before waiting for another TP.CM_CTS. */
    uint8 J1939TpRxSa;                               /* Source address (SA) of this channel. This parameter is only required for channels with fixed SA which use N-PDUs with MetaData. */
    const uint8 J1939TpNumberOfRxPg;                 /* Number of configured Rx Pgs */
    const uint8 J1939TpRxCmNPduMetaDataLen;          /* MetaDataLength of J1939TpRxCmNPdu */
    const uint8 J1939TpRxDtNPduMetaDataLen;          /* MetaDataLength of J1939TpRxDtNPdu */
    const uint8 J1939TpTxFcNPduMetaDataLen;          /* MetaDataLength of J1939TpTxFcNPdu */
    boolean J1939TpRxRetrySupport;                   /* Enable support for triggering repetition of failed transmission using TP.CM_CTS with a packet number that has already been sent. Retransmission is triggered when a sequence number is missing or a timeout occurs during reception. */
    boolean J1939TpRxDynamicBlockCalculation;        /* Enable dynamic calculation of "number of packets that can be sent" value in TP.CM_CTS, based on the size of buffers in upper layers reported via StartOfReception and PduR_J1939TpCopyRxData */
    boolean J1939TpRxCancellationSupport;            /* Enable receive cancellation using the API J1939Tp_CancelReceive() for this channel */
    boolean J1939TpRxCanFDSupport;                   /* Enable CanFD message reception for this channel */
}J1939Tp_RxChannelType;

typedef struct
{
    J1939Tp_CancelTransmit_FctPtrType J1939TpCancelTransmitFctPtr; /* Enable transmit and receive cancellation.  The APIs J1939Tp_CancelTransmit() and J1939Tp_CancelReceive() will only be available when this parameter is enabled. */
    J1939Tp_CancelReceive_FctPtrType J1939TpCancelReceiveFctPtrt; /* Enable transmit and receive cancellation.  The APIs J1939Tp_CancelTransmit() and J1939Tp_CancelReceive() will only be available when this parameter is enabled. */
    J1939Tp_GetVersionInfoType_FctPtrType J1939TpVersionInfoFctPtr; /* The function J1939Tp_GetVersionInfo is configurable (On/Off) by this configuration parameter. */
    uint16 T1;                                       /* =750ms/(main function period in ms) Timeout occurred on receiver side after reception of an intermediate TP.DT frame of a block.Means timeout between two data packets. */
    uint16 T2;                                       /* =1250ms/(main function period in ms) Timeout occurred on receiver side after transmission of a TP.CM/CTS frame. Means timeout between RTS/CTS and next data. */
    uint16 T3;                                       /* =1250ms/(main function period in ms) Timeout occurred on transmitter side after transmission of the last TP.DT frame of a block.Means timeout between data and next CTS */
    uint16 T4;                                       /* =1050ms/(main function period in ms) Timeout occurred on transmitter side after reception of a TP.CM/CTS(0) frame.Means timeout after CTS with 0 packets */
    uint16 T5;                                       /* =3000ms/(main function period in ms) Timeout occurred on transmitter side after transmission of FD.TP.CM_EOMS frame. Means timeout between EOMA after sending EOMS.*/
    uint16 Tr;                                       /* =200ms/(main function period in ms) Timeout occurred on transmitter or receiver side while trying to send the next TP.DT or TP.CM frame. */
    uint16 Tbammin;                                  /* =50ms/(main function period in ms) BAM minimal time between two messages. */
    uint16 Th;                                       /* =500ms/(main function period in ms) Timeout occurred on receiver side while trying to send the next TP.CM/CTS frame after a TP.CM/CTS(0) frame. */
    uint16 Tbammax;                                  /* =200ms/(main function period in ms) BAM maximal time between two messages. */
    uint16 TxConfirmationTimeOut;                    /* TxConfirmation timeout if configured */
    boolean J1939TpDevErrorDetect;                   /* Switches the Development Error Detection and Notification */
}J1939Tp_GeneralType;

/* !LINKSTO J1939Tp.EB.GeneralConfigType,1 */
typedef struct
{
    CONSTP2CONST(J1939Tp_TxChannelType, AUTOMATIC, J1939TP_APPL_CONST) J1939TpTxChannel;    /* J1939TpTxChannel Container */
    CONSTP2VAR(J1939Tp_RxChannelType, AUTOMATIC, J1939TP_APPL_DATA) J1939TpRxChannel;      /* J1939TpRxChannel Container */
    CONSTP2CONST(J1939Tp_GeneralType, AUTOMATIC, J1939TP_APPL_CONST) J1939TpGeneral;        /* J1939Tp General configurations */
    uint8 J1939TpNumberOfTxChannels;                 /* Number of configured J1939Tp Tx channels */
    uint8 J1939TpNumberOfRxChannels;                 /* Number of configured J1939Tp Rx channels */
}J1939Tp_GeneralConfigType;

/* \brief Type for the configuration data (place holder because of pre-compile
 *        time configuration support).
 */
typedef struct
{
  uint32 Dummy;   /**< Dummy variable to have valid C code */
} J1939Tp_ConfigType;

#endif
/*==================[end of file]============================================*/

