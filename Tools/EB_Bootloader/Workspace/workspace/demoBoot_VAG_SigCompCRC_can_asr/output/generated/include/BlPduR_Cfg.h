/*********************************************************************************/
/*                                                                               */
/*                                  CAN Stack                                    */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                                BlPduR configuration                               */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file BlPduR_Cfg.h                        */
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
#ifndef BLPDUR_CFG_H
#define BLPDUR_CFG_H

#define BLPDUR_FALSE      0U
#define BLPDUR_TRUE       1U

/* BlPduR Manage period */
#define BLPDUR_MANAGE_PERIOD               1U

/* Define if the UDS module shall have a scheduling counter or not (only necessary if module have a different schedule than BlPduR) */

#define BLPDUR_USE_LIN_MANAGE_CNT         STD_OFF

/* Define if the UDS module shall have a scheduling counter or not (only necessary if module have a different schedule than BlPduR) */

#define BLPDUR_USE_LTP_MANAGE_CNT         STD_OFF

/* Define if the UDS module shall have a scheduling counter or not (only necessary if module have a different schedule than BlPduR) */

#define BLPDUR_USE_UDS_MANAGE_CNT         STD_OFF

/* Define if the Prog module shall have a scheduling counter or not (only necessary if module have a different schedule than BlPduR) */

#define BLPDUR_USE_PROG_MANAGE_CNT        STD_OFF

/* Define if the SA module shall have a scheduling counter or not (only necessary if module have a different schedule than BlPduR) */

#define BLPDUR_USE_SA_MANAGE_CNT          STD_OFF

/* Dynamic reconfiguration of TP parameters: BS and STmin */
#define BLPDUR_UPDATE_TP_PARAM_ENABLE                    STD_ON

/* Network use definition */
#define BLPDUR_NETWORK_CAN_SUPPORTED      STD_ON
#define BLPDUR_NETWORK_FLEXRAY_SUPPORTED  STD_OFF
#define BLPDUR_NETWORK_ETH_SUPPORTED      STD_OFF
#define BLPDUR_NETWORK_LIN_SUPPORTED      STD_OFF
#define BLPDUR_ASR_NETWORK_PRESENT        STD_ON

/**** LIN Stack ****/
/* Define if the Lin module is present in the project configuration */
#define BLPDUR_USE_LIN     STD_OFF
/* Define if the Ltp module is present in the project configuration */
#define BLPDUR_USE_LTP     STD_OFF

/**** Bootloader Stack ****/
/* Define if the Flash module is present in the project configuration */
#define BLPDUR_USE_FLASH   STD_ON
/* Define if the Prog module is present in the project configuration */
#define BLPDUR_USE_PROG    STD_ON
/* Define if the SA module is present in the project configuration */
#define BLPDUR_USE_SA      STD_ON
/* Define if the UDS module is present in the project configuration */
#define BLPDUR_USE_UDS     STD_ON

/**** ASR Stack ****/
/* Define if the PduR module is present in the project configuration */
#define BLPDUR_USE_PDUR    STD_ON

/**** Can Stack ****/
/* Define if the Can module is present in the project configuration */
#define BLPDUR_USE_CAN     STD_ON
/* Define if the CanIf module is present in the project configuration */
#define BLPDUR_USE_CANIF   STD_ON
/* Define if the CanTp module is present in the project configuration */
#define BLPDUR_USE_CANTP   STD_ON
/* Define if the CanSM module is present in the project configuration */
#define BLPDUR_USE_CANSM   STD_ON

/**** Fr Stack ****/
/* Define if the Fr module is present in the project configuration */
#define BLPDUR_USE_FR      STD_OFF
/* Define if the FrIf module is present in the project configuration */
#define BLPDUR_USE_FRIF    STD_OFF
/* Define if the FrTp module is present in the project configuration */
#define BLPDUR_USE_FRTP    STD_OFF
/* Define if the FrSM module is present in the project configuration */
#define BLPDUR_USE_FRSM    STD_OFF

/**** Eth Stack ****/
/* Define if the Eth module is present in the project configuration */
#define BLPDUR_USE_ETH     STD_OFF
/* Define if the EthIf module is present in the project configuration */
#define BLPDUR_USE_ETHIF   STD_OFF
/* Define if the EthSM module is present in the project configuration */
#define BLPDUR_USE_ETHSM   STD_OFF
/* Define if the TcpIp module is present in the project configuration */
#define BLPDUR_USE_TCPIP   STD_OFF
/* Define if the SoAd module is present in the project configuration */
#define BLPDUR_USE_SOAD    STD_OFF
/* Define if the DoIP module is present in the project configuration */
#define BLPDUR_USE_DOIP    STD_OFF
/* Define if the EthTrcv module is present in the project configuration */
#define BLPDUR_USE_ETHTRCV STD_OFF


#define BLPDUR_SOURCE_ADDRESS_CHECK_ENABLE          STD_OFF

#define BLPDUR_MULTIPLE_ID_CAN_NOTIFICATION         0U
#define BLPDUR_MULTIPLE_ID_EXTERNAL_NOTIFICATION    1U
#define BLPDUR_MULTIPLE_ID_OFF                      2U
#define BLPDUR_MULTIPLE_ID_NO_SEL                   0xFFU

#define BLPDUR_MULTIPLE_ID_TYPE          BLPDUR_MULTIPLE_ID_OFF
#define BLPDUR_MULTIPLE_ID_ENABLE        STD_OFF

/* Not yet supported */
#define BLPDUR_USE_STREAMING              STD_OFF

/* All tester address are allowed */
#define BLPDUR_ALL_TESTER_ADDRESS         0xFFU

#define BLPDUR_NO_ACTIVE_CONNECTION       0xFFU
#define BLPDUR_INVALID_PDU                0xFFU

/* Define the number of physical buffer configured (from 1 to 4) */
#define BLPDUR_MULTIPLE_BUFFERS_ENABLE    STD_ON
#define BLPDUR_RX_PHY_BUFFER_NUM          4U
/* total number of Rx Buffer (n for physical + 1 for functional) */
#define BLPDUR_RX_BUFFER                  (BLPDUR_RX_PHY_BUFFER_NUM + 1U)

/* Define Pdu for transmition */
#define  BLPDUR_Sdu_Tx_Boot PDURSA_Sdu_Tx_Boot


/* Functional buffer size */
#define BLPDUR_RX_FUNC_BUFFERSIZE         8U
/* Physical buffer size (same for all physical if multiple buffer enable) */
#define BLPDUR_RX_PHYS_BUFFERSIZE         4095U

/* Number of Rx PDU configured */
#define BLPDUR_MAX_RX_PDU_NUM             2U

/* Number of Shared PDU configured */
#define BLPDUR_SHARED_RX_PDU_NUM             0U

/* Number of connection configured */
#define BLPDUR_MAX_PDU_CONNECTION         1U

#define BLPDUR_OLD_BUFFER                 0x1U
#define BLPDUR_ALL_BUFFER                 0xFFU

/* Number of ID group configured */
#define BLPDUR_ID_GROUP_NUM               0U
/* ID of the default group */
#define BLPDUR_ID_GROUP_DEFAULT           0U



#define BLPDUR_BS_DEFAULT        0
#define BLPDUR_STMIN_DEFAULT    0

/* declaration of configuration */
extern tRxPdu stRxPdu[BLPDUR_MAX_RX_PDU_NUM+BLPDUR_SHARED_RX_PDU_NUM];
extern tPduConnection stPduConnection[BLPDUR_MAX_PDU_CONNECTION];
extern uint8 BlPduRRxPhysBuffer[BLPDUR_RX_PHY_BUFFER_NUM][BLPDUR_RX_PHYS_BUFFERSIZE];
extern tBufferInfoType stRxPhysBufferInfo[BLPDUR_RX_PHY_BUFFER_NUM];
extern tBufferConfigType stRxPhysBufferConfig[BLPDUR_RX_PHY_BUFFER_NUM];





#endif      /* BLPDUR_CFG_H */
