/**
 * \file
 *
 * \brief AUTOSAR J1939Rm
 *
 * This file contains the implementation of the AUTOSAR
 * module J1939Rm.
 *
 * \version 1.1.9
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/* This file contains the generated J1939Rm Types. */

[!CODE!]
[!AUTOSPACING!]
[!INCLUDE "include/J1939Rm_Vars.m"!]

#ifndef J1939RM_TYPES_H
#define J1939RM_TYPES_H

/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00035,1 */
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00032,1 */
#include <ComStack_Types.h>

#include <EcuC.h>             /* Inclusion of Ecuc module */

[!IF "$Rte_count > 0"!]
#include <Rte_J1939Rm.h>
[!ENDIF!]

/* J1939Rm_AckCode type will be define in Rte_Type.h in case there is any user of type J1939RM_USER_RTE,
   and J1939RmUserAckIndication or J1939RmUserSendAck is enabled for this user.
   Otherwise the J1939Rm_Types.h has to define it. */
[!IF "not(($RTE_AckIndication > 0) or ($RTE_SendAck > 0))"!]
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00057,1 */
/* This type represents the available kinds of acknowledgments. */
typedef enum {
J1939RM_ACK_POSITIVE,                       /** Positive Acknowledgment (0) */
J1939RM_ACK_NEGATIVE,                       /** Negative Acknowledgment (1) */
J1939RM_ACK_ACCESS_DENIED,                  /** Access Denied (2) */
J1939RM_ACK_CANNOT_RESPOND                  /** Cannot Respond (3) */
} J1939Rm_AckCode;
[!ENDIF!]

/*Macro Definitions*/
#if (defined J1939RM_NO_TX)
#error J1939RM_NO_TX already defined
#endif
#define J1939RM_NO_TX                               ((uint8)0)           /**< No transmission. */

#if (defined J1939RM_RQST_TX_CONFIRMED)
#error J1939RM_RQST_TX_CONFIRMED already defined
#endif
#define J1939RM_RQST_TX_CONFIRMED                   ((uint8)1)           /**< Requested transmission Confirmed. */

#if (defined J1939RM_RQST_TX)
#error J1939RM_RQST_TX already defined
#endif
#define J1939RM_RQST_TX                             ((uint8)2)           /**< Requested transmission. */

#if (defined J1939RM_ACKM_TX_CONFIRMED)
#error J1939RM_ACKM_TX_CONFIRMED already defined
#endif
#define J1939RM_ACKM_TX_CONFIRMED                   ((uint8)4)           /**< Acknowledgement transmission Confirmed. */

#if (defined J1939RM_ACKM_TX)
#error J1939RM_ACKM_TX already defined
#endif
#define J1939RM_ACKM_TX                             ((uint8)8)           /**< Acknowledgement transmission. */

#if (defined J1939RM_COM_TX_CONFIRMED)
#error J1939RM_COM_TX_CONFIRMED already defined
#endif
#define J1939RM_COM_TX_CONFIRMED                    ((uint8)0x10)        /**< COM transmission Confirmed. */

#if (defined J1939RM_COM_TX)
#error J1939RM_COM_TX already defined
#endif
#define J1939RM_COM_TX                              ((uint8)0x20)        /**< COM transmission. */

#if (defined J1939RM_COM_RX)
#error J1939RM_COM_RX already defined
#endif
#define J1939RM_COM_RX                              ((uint8)0x40)        /**< COM request - triggered to COM. */

#if (defined J1939RM_TXPG_RQST)
#error J1939RM_TXPG_RQST already defined
#endif
#define J1939RM_TXPG_RQST                           ((uint8)0)           /**< Queue Type - RQST */

#if (defined J1939RM_TXPG_ACKM)
#error J1939RM_TXPG_ACKM already defined
#endif
#define J1939RM_TXPG_ACKM                           ((uint8)1)           /**< Queue Type - ACKM */

#if (defined J1939RM_TSV_RQST)
#error J1939RM_TSV_RQST already defined
#endif
#define J1939RM_TSV_RQST                            ((uint8)2)           /**< Queue Type - TSV - RQST with Timeout Supervision */

#if (defined J1939RM_COM_RQST)
#error J1939RM_COM_RQST already defined
#endif
#define J1939RM_COM_RQST                            ((uint8)3)           /**< Queue Type - COM */

#if (defined J1939RM_ADDR_CLAIM_PG_PGN)
#error J1939RM_ADDR_CLAIM_PG_PGN already defined
#endif
#define J1939RM_ADDR_CLAIM_PG_PGN                   ((uint32)60928)       /**< Address Claim PGN */

#if (defined J1939RM_BROADCAST_ADDR)
#error J1939RM_BROADCAST_ADDR already defined
#endif
#define J1939RM_BROADCAST_ADDR                      ((uint8)255)         /**< Broadcast Address */

#if (defined J1939RM_RQSTPG_LENGTH)
#error J1939RM_RQSTPG_LENGTH already defined
#endif
#define J1939RM_RQSTPG_LENGTH                       ((uint8)3)           /**< RQST PG Length */

#if (defined J1939RM_ACKMPG_LENGTH)
#error J1939RM_ACKMPG_LENGTH already defined
#endif
#define J1939RM_ACKMPG_LENGTH                       ((uint8)8)           /**< ACKM PG Length */

#if (defined J1939RM_INVALID_PDU_ID)
#error J1939RM_INVALID_PDU_ID already defined
#endif
#define J1939RM_INVALID_PDU_ID                      ((uint16)65535)       /**< Invalid PDU Identifier. */

#if (defined J1939RM_DEFAULT_PRIORITY)
#error J1939RM_DEFAULT_PRIORITY already defined
#endif
/*
 * development errors used by the J1939 Request Manager
*/
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00031.J1939RM_E_UNINIT,1 */
#define J1939RM_E_UNINIT                            (uint8)0x01
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00031.J1939RM_E_REINIT,1 */
#define J1939RM_E_REINIT                            (uint8)0x02
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00031.J1939RM_E_PARAM_POINTER,1 */
#define J1939RM_E_PARAM_POINTER                     (uint8)0x03
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00031.J1939RM_E_INVALID_PDU_SDU_ID,1 */
#define J1939RM_E_INVALID_PDU_SDU_ID                (uint8)0x04
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00031.J1939RM_E_INVALID_NETWORK_ID,1 */
#define J1939RM_E_INVALID_NETWORK_ID                (uint8)0x05
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00031.J1939RM_E_INVALID_STATE,1 */
#define J1939RM_E_INVALID_STATE                     (uint8)0x06
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00031.J1939RM_E_INVALID_USER,1 */
#define J1939RM_E_INVALID_USER                      (uint8)0x07
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00031.J1939RM_E_INVALID_PGN,1 */
#define J1939RM_E_INVALID_PGN                       (uint8)0x08
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00031.J1939RM_E_INVALID_PRIO,1 */
#define J1939RM_E_INVALID_PRIO                      (uint8)0x09
/* J1939Rm.ASR413.SWS_J1939Rm_00031.J1939RM_E_INVALID_ADDRESS,1 */
#define J1939RM_E_INVALID_ADDRESS                   (uint8)0x0a
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00031.J1939RM_E_INVALID_OPTION,1 */
#define J1939RM_E_INVALID_OPTION                    (uint8)0x0b
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00031.J1939RM_E_INVALID_ACK_CODE,1 */
#define J1939RM_E_INVALID_ACK_CODE                  (uint8)0x0c
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00031.J1939RM_E_INVALID_NODE,1 */
#define J1939RM_E_INVALID_NODE                      (uint8)0x0d
/*
 * vendor specific development errors used by the J1939 Request Manager
*/
#define J1939RM_E_TimeoutSupervision_1250MS         (uint8)0x0e
#define J1939RM_E_TimeoutSupervision_50MS           (uint8)0x0f
#define J1939RM_E_INVALID_SEND_REQUEST              (uint8)0x1E


#define J1939RM_DEFAULT_PRIORITY                    ((uint8)6)           /**< Default Priority for Request and Acknowledge messages as per J1939-21 spec. */
#define J1939RM_INSTANCE_ID                         (uint8)0x00u         /**< The Instance ID for the J1939RM usd for det error reporting */
#define J1939RM_RXINDICATION_SERVICEID              (uint8)0x42
#define J1939RM_MAINFUNCTION_SERVICEID              (uint8)0x04
#define J1939RM_TRANSMIT_SERVICEID                  (uint8)0x06
#define J1939RM_SEND_REQUEST_SERVICEID              (uint8)0x07          /**< The Instance ID for function sendrequest in the J1939RM usd for det error reporting */
#define J1939RM_SET_STATE_SERVICEID                 (uint8)0x05
#define J1939RM_INIT_SERVICEID                      (uint8)0x01
#define J1939RM_DEINIT_SERVICEID                    (uint8)0x02
#define J1939RM_SENDACK_SERVICEID                   (uint8)0x09
#define J1939RM_TXCONFIRMATION_SERVICEID            (uint8)0x40
#define J1939RM_COMRXIPDUCALLOUT_SERVICEID          (uint8)0x28
#define J1939RM_TPTXCONFIRMATION_SERVICEID          (uint8)0x37
#define J1939RM_COPYTXDATA_SERVICEID                (uint8)0x43
#define J1939RM_CANCELREQUESTTIMEOUT_SERVICEID      (uint8)0x08
#define J1939RM_GETVERSIONINFO_SERVICEID            (uint8)0x03




#if (defined J1939RM_E_INVALID_METADATA_HANDLE)
#error J1939RM_E_INVALID_METADATA_HANDLE already defined
#endif
/** \brief Error Code.
 **
 ** API was called with an invalid Metadata handle. */
#define J1939RM_E_INVALID_METADATA_HANDLE          0x10U


#if (defined J1939RM_DEV_ERROR_DETECT)
#error J1939RM_DEV_ERROR_DETECT already defined
#endif
/** \brief Switch, indicating whether J1939RmDevErrorDetect functionality is available */
#define J1939RM_DEV_ERROR_DETECT       [!//
[!IF "text:tolower(J1939RmGeneral/J1939RmDevErrorDetect) = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]



[!VAR "No_Of_Config" = "num:i(count(as:modconf('J1939Rm')[1]/J1939RmConfigSet/*))"!]
[!VAR "TotalNumberOfPGs" = "num:i(0)"!]

[!VAR "Channels" = "0"!]

[!FOR "i" = "1"
TO "$No_Of_Config" STEP "1"!]

[!VAR "Channels" = "num:i($Channels + count(as:modconf('J1939Rm')[1]/J1939RmConfigSet/*[num:i($i)]/J1939RmChannel/*))"!]

[!VAR "No_Of_nodes_per_ConfigSet" = "num:i(count(as:modconf('J1939Rm')[1]/J1939RmConfigSet/*[num:i($i)]/J1939RmNode/*))"!]
[!FOR "j" = "1"
TO "$No_Of_nodes_per_ConfigSet" STEP "1"!]

[!VAR "No_Of_users_per_node" = "num:i(count(as:modconf('J1939Rm')[1]/J1939RmConfigSet/*[num:i($i)]/J1939RmNode/*[num:i($j)]/J1939RmUser/*))"!]
[!FOR "k" = "1"
TO "$No_Of_users_per_node" STEP "1"!]

[!VAR "TotalNumberOfPGs" = "num:i($TotalNumberOfPGs + num:i(count(as:modconf('J1939Rm')[1]/J1939RmConfigSet/*[num:i($i)]/J1939RmNode/*[num:i($j)]/J1939RmUser/*[num:i($k)]/J1939RmUserPGN/*)))"!]

[!ENDFOR!]
[!ENDFOR!]
[!ENDFOR!]
#define J1939_NUMBER_OF_CONFIGURED_CHANNELS (uint8)[!"$Channels"!]
#define J1939_TOTAL_NUMBER_OF_PGS (uint8)[!"$TotalNumberOfPGs"!]
/*TypeDefs*/
/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00049,1 */
/** This type represents the communication state of the J1939 Request Manager. */
typedef enum {
J1939RM_STATE_ONLINE,                       /** Normal communication (0) */
J1939RM_STATE_OFFLINE                       /** Only Request for AC (1) */
} J1939Rm_StateType;




/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00064,1 */
/** Indicates reception of an Acknowledgement PG. */
typedef P2FUNC(void, AUTOMATIC, J1939Rm_AckIndication_FctPtrType)(uint8 node, NetworkHandleType channel, uint32 ackPgn, J1939Rm_AckCode ackCode, uint8 ackAddress, uint8 sourceAddress, uint8 priority);

/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00063,1 */
/** Indicates reception of a Request PG. */
typedef P2FUNC(void, AUTOMATIC, J1939Rm_RequestIndication_FctPtrType)(uint8 node, NetworkHandleType channel, uint32 requestedPgn, uint8 sourceAddress, uint8 destAddress, uint8 priority);

/* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00065,1 */
/** Indicates timeout of a request triggered with the same parameters. */
typedef P2FUNC(void, AUTOMATIC, J1939Rm_RequestTimeoutIndication_FctPtrType)(uint8 node, NetworkHandleType channel, uint32 requestedPgn, uint8 destAddress);

/** Type of module using J1939Rm. */
typedef enum {
J1939RM_USER_CDD,                           /** CDDs may use all APIs provided by J1939Rm. */
J1939RM_USER_COM,                      /** J1939Rm only supports requests for COM I-PDUs */
J1939RM_USER_J1939DCM,                 /** J1939Dcm uses only request indication and transmission of acknowledgement. */
J1939RM_USER_J1939NM,                  /** J1939Nm uses only request indication. */
J1939RM_USER_RTE                            /** Application SW-Cs may use all APIs provided by J1939Rm. */
} J1939Rm_UserType;

/** Cancels timeout monitoring of a Request. If the request is not active, or timeout monitoring was not requested, this call has no effect. */
typedef void (* J1939Rm_CancelRequestTimeout_FctPtrType)(uint8 userId, NetworkHandleType channel, uint32 requestedPgn, uint8 destAddress);

/** Constant Parameters for a CAN channel. */
typedef struct
{
EcuC_PduIdType J1939RmAckmRx_Ecuc_PduId;
uint16 J1939RmAckmRxPduId;                       /** The I-PDU identifier used for RxIndication from PduR. */
EcuC_PduIdType J1939RmAckmTx_Ecuc_PduId;
uint16 J1939RmAckmTxPduId;                       /** The I-PDU identifier used for TxConfirmation from PduR. */
uint16 J1939RmAckmTxPduRef;                      /** The I-PDU identifier used for TxConfirmation to upper layer. */
EcuC_PduIdType J1939RmRqstRx_Ecuc_PduId;
uint16 J1939RmRqstRxPduId;                       /** The I-PDU identifier used for RxIndication from PduR. */
EcuC_PduIdType J1939RmRqstTx_Ecuc_PduId;
uint16 J1939RmRqstTxPduId;                       /** The I-PDU identifier used for TxConfirmation from PduR. */
uint16 J1939RmRqstTxPduRef;                      /** The I-PDU identifier used for TxConfirmation to upper layer. */
uint8 J1939RmAckQueueSize;                       /** Number of transmitted acknowledgements that can be stored. */
uint8 J1939RmRequestQueueSize;                   /** Number of transmitted requests that can be stored. */
uint8 J1939RmRequestTimeoutMonitors;             /** Number of transmitted requests that can be monitored for timeout. */
uint8 J1939RmChannelId;                          /** Channel Identifier. */
uint8 J1939RmAckmTxPduMetaData;                  /** MetaDataLength of AckmTxPdu. */
uint8 J1939RmRqstTxPduMetaData;                  /** MetaDataLength of RqstTxPdu. */
}J1939Rm_Channel_Const_Struct;

/** Contains the parameters for the support of a logical J1939 node (identified by an ECU address). */
typedef struct
{
CONSTP2CONST(uint16, AUTOMATIC, J1939RM_APPL_CONST) J1939RmNodeUserRefPtr;            /** Reference to the Users of this node. */
CONSTP2CONST(uint8, AUTOMATIC, J1939RM_APPL_CONST) J1939RmNodeChannelRefPtr;          /** Reference to the channels this node has access to. */
uint16 J1939RmNodeUserNr;                        /** Number of Users present in J1939RmNode. */
uint8 J1939RmNodeChannelNr;                      /** Number of channels this node has access to. */
uint8 J1939RmNodeId;                             /** J1939Nm node Identifier. */
uint8 J1939RmNodeAddress;                        /** J1939Nm node Preferred Address. */
}J1939Rm_Node_Const_Struct;

/** Contains the configuration of an I-PDU that is to be transmitted on request by COM. This configuration container is only relevant for J1939RmUserType J1939RM_USER_COM. */
typedef struct
{
uint32 J1939RmComIPduPGN;                        /** PGN of the COM I-PDU. */
uint16 J1939RmUpperComIPduId;                    /** The I-PDU identifier used for communication with PduR. */
uint16 J1939RmUpperComIPduRef;                   /** The I-PDU identifier used for communication to COM from J1939Rm. */
boolean J1939Rm_IfTransmit;                       /** True: If this is NORMAL Pdu that can be sent unfragmented, False: It this is large PDU that shall be sent via TP*/
uint16 J1939RmUpperComIPduRef_PDUR;              /** The I-PDU identifier used for communication to COM from J1939Rm for confirmation. */
uint16 J1939RmLowerComIPduId;                    /** The I-PDU identifier used for communication with PduR. */
EcuC_PduIdType J1939RmLowerComIPdu_Ecuc_PduId;
uint16 J1939RmLowerComIPduRef;                   /** The I-PDU identifier used for communication to J1939Rm from PduR. */
uint8 J1939RmComIPduDA;                          /** Destination address of the COM I-PDU. */
uint8 J1939RmComIPduSA;                          /** Source address of the COM I-PDU. */
uint8 J1939RmLowerPduMetaData;                   /** MetaData Length of Lower COM I-PDU. */
}J1939Rm_ComIPdu_Const_Struct;

/** Contains the configuration of a module that uses the request and acknowledgement interfaces of J1939Rm. */
typedef struct
{
CONSTP2CONST(J1939Rm_ComIPdu_Const_Struct, AUTOMATIC, J1939RM_APPL_CONST) J1939RmComIPduConstStructPtr;        /** I-PDU configuration that is to be transmitted on request by COM. */
J1939Rm_AckIndication_FctPtrType J1939RmUserAckIndicationFctPtr;                        /** Function pointer for AckIndication. */
J1939Rm_RequestIndication_FctPtrType J1939RmUserRequestIndicationFctPtr;                /** Function pointer for RequestIndication. */
J1939Rm_RequestTimeoutIndication_FctPtrType J1939RmUserRequestTimeoutIndicationFctPtr;  /** Function pointer for RequestTimeoutIndication. */
boolean J1939RmUserSendAckSupport;                                                      /** SendAck API Support*/
boolean J1939RmUserSendRequestSupport;                                                  /** SendRequest API Support. */
J1939Rm_CancelRequestTimeout_FctPtrType J1939RmCancelRequestTimeoutFctPtr;              /** Function pointer for CancelRequestTimeout. */
CONSTP2CONST(uint32, AUTOMATIC, J1939RM_APPL_CONST) J1939RmUserPGNPtr;                  /** PGN supported to be requested. */
CONSTP2CONST(uint32, AUTOMATIC, J1939RM_APPL_CONST) J1939RmUserAckPGNPtr;               /** PGN supported to be acknowledged. */
uint32 J1939RmUserPGNNr;                                                                /** Number of PGNs supported to be requested by User. */
uint32 J1939RmUserAckPGNNr;                                                             /** Number of Ack PGNs supported to be acknowledged by User. */
uint16 J1939RmComIPduNr;                                                                /** Number of ComIpdus configured for UserType COM. */
uint8 J1939RmUserComIPduRequestQueueSize;                                               /** Number of received requests that can be stored for COM I-PDUs of this user. */
J1939Rm_UserType J1939RmUserType;                                                       /** Type of module using J1939Rm. */
uint8 J1939RmUserId;                                                                    /** User Identifier (Only required when the module uses transmission of requests). */
}J1939Rm_User_Const_Struct;


/** Store userId, ackPgn, type of acknowledgement, ackAddress and priority of the Acknowledgements in Transmission Acknowledgements Queue. */
typedef struct
{
uint32 J1939RmAckmPgn;                           /** PGN of the Acknowledged PG. */
uint16 J1939RmAckmUserId;                        /** Calling module user ID. */
uint8 J1939RmAckmCode;                           /** Type of acknowledgement. */
uint8 J1939RmAckmAddr;                           /** Address of the node that sent the request. */
uint8 J1939RmAckmPriority;                       /** Priority of the Acknowledgement PG. */
}J1939Rm_AckmTxQueueData_Struct;

/** Contains the parameters to manage Transmission Acknowledgements Queue. */
typedef struct
{
P2VAR(J1939Rm_AckmTxQueueData_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939RmAckmTxQueueDataPtr; /** Store userId, ackPgn, type of acknowledgement, ackAddress and priority of the Acknowledgements in Transmission Acknowledgements Queue. */
uint8 J1939RmAckmTxQueueFront;                   /** Index of first element (Dequeue Index). */
uint8 J1939RmAckmTxQueueRear;                    /** Index of last element (Enqueue Index). */
uint8 J1939RmAckmTxQueueCount;                   /** count=0 means empty queue, count=J1939RmAckQueueSize means full queue. */
}J1939Rm_AckmTxQueueType_Struct;

/** Store userId, requestedPgn, source address, destination address and priority of the requests in Transmission Requests Queue. */
typedef struct
{
uint32 J1939RmRqstPgn;                           /** PGN of the Requested PG. */
uint16 J1939RmRqstUserId;                        /** Calling module user ID. */
uint8 J1939RmRqstSA;                             /** Address of the Source node. */
uint8 J1939RmRqstDA;                             /** Address of the node that sent the request. */
uint8 J1939RmRqstPriority;                       /** Priority of the request. */
boolean J1939RmRqstcheckTimeout;                 /** TRUE: Timeout supervision will be performed. FALSE: No timeout supervision will be started. */
}J1939Rm_RqstTxQueueData_Struct;

/** Contains the parameters to manage Transmission Requests Queue. */
typedef struct
{
P2VAR(J1939Rm_RqstTxQueueData_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939RmRqstTxQueueDataPtr; /** Store userId, requestedPgn, source address, destination address and priority of the requests in Transmission Requests Queue. */
uint8 J1939RmRqstTxQueueFront;                   /** Index of first element (Dequeue Index). */
uint8 J1939RmRqstTxQueueRear;                    /** Index of last element (Enqueue Index). */
uint8 J1939RmRqstTxQueueCount;                   /** count=0 means empty queue, count=J1939RmRequestQueueSize means full queue. */
}J1939Rm_RqstTxQueueType_Struct;

/** Store userId, requestedPgn, source address and destination address of the requests in Timeout Supervision for Requests Queue. */
typedef struct
{
uint32 J1939RmRqstPgn;                           /** PGN of the Requested PG. */
uint16 J1939RmTimeoutSupervisionTimer;           /** Timer to track the time till the reception of an answer to a request after TxConfirmation. */
uint16 J1939RmRqstUserId;                        /** Calling module user ID. */
uint8 J1939RmRqstSA;                             /** Address of the Source node. */
uint8 J1939RmRqstDA;                             /** Address of the destination node or 0xFF for broadcast. */
boolean J1939RmTimeoutSupervisionEnable;         /** TRUE: Start timeout supervision for the request. FALSE: Disable timeout supervision for the request. */
}J1939Rm_RqstTSQueueData_Struct;

/** Contains the parameters to manage Timeout Supervision Queue. */
typedef struct
{
P2VAR(J1939Rm_RqstTSQueueData_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939RmRqstTSQueueDataStructPtr; /** Store userId, requestedPgn, source address and destination address of the requests in Timeout Supervision for Requests Queue. */
uint8 J1939RmRqstTSQueueFront;                   /** Index of first element (Dequeue Index). */
uint8 J1939RmRqstTSQueueRear;                    /** Index of last element (Enqueue Index). */
uint8 J1939RmRqstTSQueueCount;                   /** count=0 means empty queue, count=J1939RmRequestTimeoutMonitors means full queue. */
}J1939Rm_RqstTSQueueType_Struct;

/** RAM Parameters for a CAN channel. */
typedef struct
{
P2VAR(J1939Rm_AckmTxQueueType_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939RmAckmTxQueueTypeStructPtr;  /** Contains the parameters to manage Transmission Acknowledgements Queue. */
P2VAR(J1939Rm_RqstTxQueueType_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939RmRqstTxQueueTypeStructPtr;  /** Contains the parameters to manage Transmission Requests Queue. */
P2VAR(J1939Rm_RqstTSQueueType_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939RmRqstTSQueueTypeStructPtr;  /** Contains the parameters to manage Timeout Supervision Queue. */
uint16 J1939RmTxConfirmationTimer;                                            /** Time to wait for a confirmation after transmission of a request. The behavior when the time elapses depends on the transmitted request. */
uint8 J1939RmTxConfirmation;                                                  /** Status: bit3-AckmTx, bit2-AckmTxConfirmation, bit1-RqstTx, bit0-RqstTxConfirmation. */
J1939Rm_StateType J1939RmState;                                               /** State for a channel of a node. */
}J1939Rm_Channel_Ram_Struct;

/** Store source address and destination address of the COM requests in COMIPDUs Queue. */
typedef struct
{
uint32 J1939RmComIpduRqstPgn;                    /** PGN of the Requested PG. */
uint16 J1939RmComIpduRqstUserId;                 /** Calling module user ID. */
uint8 J1939RmComIpduRqstSA;                      /** Address of the Source node. */
uint8 J1939RmComIpduRqstDA;                      /** Address of the destination node or 0xFF for broadcast. */
uint8 J1939RmComIpduRqstChannelId;               /** Channel Id on which COM-RQST to be transmitted. */
}J1939Rm_ComIpduRqstQueueData_Struct;

/** Contains the parameters to manage COMIPDUs Queue. */
typedef struct
{
P2VAR(J1939Rm_ComIpduRqstQueueData_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939RmComIpduRqstQueueDataPtr;
uint8 J1939RmComIpduRqstQueueRear;               /** Index of last element (Enqueue Index). */
uint8 J1939RmComIpduRqstQueueCount;              /** count=0 means empty queue, count=J1939RmUserComIPduRequestQueueSize means full queue. */
}J1939Rm_ComIpduRqstQueueType_Struct;

/** This container is a MultipleConfigurationContainer, i.e. this container and its sub-containers exist once per configuration set. */
typedef struct
{
P2CONST(J1939Rm_Channel_Const_Struct, AUTOMATIC, J1939RM_APPL_CONST)J1939RmChannelConstStructPtr;                      /** Constant Parameters for a CAN channel. */
P2CONST(J1939Rm_Node_Const_Struct, AUTOMATIC, J1939RM_APPL_CONST) J1939RmNodeConstStructPtr;                           /** Parameters of a logical J1939 node (identified by an ECU address). */
P2CONST(J1939Rm_User_Const_Struct, AUTOMATIC, J1939RM_APPL_CONST) J1939RmUserConstStructPtr;                           /** J1939RM User constant Configuration. */
P2VAR(J1939Rm_Channel_Ram_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939Rm_GlobalChannel_Ram_StructPtr;
P2VAR(J1939Rm_AckmTxQueueType_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939Rm_GlobalAckmTxQueueType_StructPtr;            /**< Instance of Global J1939RM configuration structure */
P2VAR(J1939Rm_RqstTxQueueType_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939Rm_GlobalRqstTxQueueType_StructPtr;            /**< Instance of Global J1939RM configuration structure */
P2VAR(J1939Rm_RqstTSQueueType_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939Rm_GlobalRqstTSQueueType_StructPtr;            /**< Instance of Global J1939RM configuration structure */
P2VAR(J1939Rm_AckmTxQueueData_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939Rm_GlobalAckmTxQueueData_StructPtr;            /**< Instance of Global J1939RM configuration structure */
P2VAR(J1939Rm_RqstTxQueueData_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939Rm_GlobalRqstTxQueueData_StructPtr;            /**< Instance of Global J1939RM configuration structure */
P2VAR(J1939Rm_RqstTSQueueData_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939Rm_GlobalRqstTSQueueData_StructPtr;            /**< Instance of Global J1939RM configuration structure */
P2VAR(J1939Rm_ComIpduRqstQueueType_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939Rm_GlobalComIpduRqstQueueType_StructPtr;  /**< Instance of Global J1939RM configuration structure */
P2VAR(J1939Rm_ComIpduRqstQueueData_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939Rm_GlobalComIpduRqstQueueData_StructPtr;  /**< Instance of Global J1939RM configuration structure */
uint16 J1939RmTxConfirmationTimeout;                                                            /** Time to wait for a confirmation after transmission of a message. The behaviour when the time elapses depends on the transmitted message. */
uint16 J1939RmTimeoutSupervision;                                                               /** Timeout of 1.25s for the reception of answer to a request. */
uint16 J1939RmUserNr;                                                                           /** Number of Users present in configuration. */
uint8 J1939RmNodeNr;                                                                            /** Number of nodes present in configuration. */
uint8 J1939RmChannelNr;                                                                         /** Number of channels present in configuration. */
}J1939Rm_RealStructType;
#if(J1939RM_DEV_ERROR_DETECT == STD_ON)
typedef struct
{
   uint32 PGNumber;
   uint8 FiftyMsTimeoutTimer;
}J1939Rm_FiftyMsTimeoutSupervision_Data;
typedef struct
{
   J1939Rm_FiftyMsTimeoutSupervision_Data J1939Rm50MsSupervisionData[J1939_NUMBER_OF_CONFIGURED_CHANNELS][J1939_TOTAL_NUMBER_OF_PGS];
   uint16 Rear[J1939_NUMBER_OF_CONFIGURED_CHANNELS];
}J1939Rm_FiftyMsTimeoutSupervision_Struct;
#endif


/** Global J1939RM configuration structure */
typedef struct
{
P2CONST(J1939Rm_RealStructType, AUTOMATIC, J1939RM_APPL_CONST) J1939RmConfigPtr;
P2VAR(J1939Rm_Channel_Ram_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939RmChannelRamStructPtr;                    /** RAM Parameters for a CAN channel. */
P2VAR(J1939Rm_ComIpduRqstQueueType_Struct, AUTOMATIC, J1939RM_APPL_DATA) J1939RmComIpduRqstQueueTypeStructPtr; /** Contains the parameters to manage COMIPDUs Queue. */
#if(J1939RM_DEV_ERROR_DETECT == STD_ON)
J1939Rm_FiftyMsTimeoutSupervision_Struct J1939Rm50MsSupervision;
#endif
}J1939Rm_GlobalConfig_Struct;

/*==================[type definitions]=======================================*/

/** \brief Type for the configuration data (place holder because of pre-compile
 **        time configuration support).
 */
typedef struct
{
  uint32 Dummy;   /**< Dummy variable to have valid C code */
} J1939Rm_ConfigType;

#endif  /* J1939RM_TYPES_H */
/*==================[end of file]============================================*/
[!ENDCODE!]
