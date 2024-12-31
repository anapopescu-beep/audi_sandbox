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
/* This file contains the generated J1939Rm module configuration. */

/*
 *  MISRA-C:2012 Deviations:
 *
 *  MISRAC2012-1) Deviated Rule: 9.3 (Required)
 *    Arrays shall not be partially initialized.
 *
 *    Reason:
 *    - The J1939Rm_GlobalConfig.J1939Rm50MsSupervision is initialized in J1939Rm_Init.
 *
 *  MISRAC2012-2) Deviated Rule 11.1 (Required)
 *    Conversions shall not be performed between a pointer to a function and any other type.
 *
 *    Reason:
 *    - Casting must be done to avoid the warning because the Rte_user has a different return type for all its callback functions.
 */
 
[!CODE!]
[!AUTOSPACING!]
[!INCLUDE "include/J1939Rm_Vars.m"!]
[!VAR "ConfigIndex" = "'0'"!]
[!SELECT "(J1939RmConfigSet/*)"!][!//
/*==================[inclusions]============================================*/
#include <J1939Rm.h>

[!IF "$Cdd_count > 0"!]
[!LOOP "(node:order(J1939RmNode/*))"!]
  [!LOOP "(node:order(J1939RmUser/*))"!]
    [!IF "(J1939RmUserType = 'J1939RM_USER_CDD')"!]
#include <[!"J1939RmUserCddName"!].h> /* CDD Inclusion */
    [!ENDIF!]
  [!ENDLOOP!]
[!ENDLOOP!]
[!ENDIF!]


[!AUTOSPACING!][!//
/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/


#define J1939RM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <J1939Rm_MemMap.h>

/*Runtime memory allocation area for J1939RM*/
J1939Rm_Channel_Ram_Struct J1939Rm_Cfg[!"$ConfigIndex"!]_ChannelBss[J1939RM_CFG[!"$ConfigIndex"!]_CHANNELBSS_SIZE];
J1939Rm_AckmTxQueueType_Struct J1939Rm_Cfg[!"$ConfigIndex"!]_AckmTxQueueTypeBss[J1939RM_CFG[!"$ConfigIndex"!]_ACKMTXQUEUETYPEBSS_SIZE];
J1939Rm_AckmTxQueueData_Struct J1939Rm_Cfg[!"$ConfigIndex"!]_AckmTxQueueDataBss[J1939RM_CFG[!"$ConfigIndex"!]_ACKMTXQUEUEDATABSS_SIZE];
J1939Rm_RqstTxQueueType_Struct J1939Rm_Cfg[!"$ConfigIndex"!]_RqstTxQueueTypeBss[J1939RM_CFG[!"$ConfigIndex"!]_RQSTTXQUEUETYPEBSS_SIZE];
J1939Rm_RqstTxQueueData_Struct J1939Rm_Cfg[!"$ConfigIndex"!]_RqstTxQueueDataBss[J1939RM_CFG[!"$ConfigIndex"!]_RQSTTXQUEUEDATABSS_SIZE];
J1939Rm_RqstTSQueueType_Struct J1939Rm_Cfg[!"$ConfigIndex"!]_RqstTsQueueTypeBss[J1939RM_CFG[!"$ConfigIndex"!]_RQSTTSQUEUETYPEBSS_SIZE];
J1939Rm_RqstTSQueueData_Struct J1939Rm_Cfg[!"$ConfigIndex"!]_RqstTsQueueDataBss[J1939RM_CFG[!"$ConfigIndex"!]_RQSTTSQUEUEDATABSS_SIZE];
J1939Rm_ComIpduRqstQueueType_Struct J1939Rm_Cfg[!"$ConfigIndex"!]_ComIpduRqstQueueTypeBss[J1939RM_CFG[!"$ConfigIndex"!]_COMIPDURQSTQUEUETYPEBSS_SIZE];
[!IF "$Com_count > 0"!]
J1939Rm_ComIpduRqstQueueData_Struct J1939Rm_Cfg[!"$ConfigIndex"!]_ComIpduRqstQueueDataBss[J1939RM_CFG[!"$ConfigIndex"!]_COMIPDURQSTQUEUEDATABSS_SIZE];
[!ENDIF!]

#define J1939RM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <J1939Rm_MemMap.h>

/* Public Constant Definitions*/

#define J1939RM_START_SEC_CONST_UNSPECIFIED
#include <J1939Rm_MemMap.h>

/*J1939Rm Channel Configuration*/
/*****************************CONFIGURATION [!"$ConfigIndex"!]*********************************************************/
static CONST(J1939Rm_Channel_Const_Struct, J1939RM_CONST) J1939Rm_Cfg[!"$ConfigIndex"!]_Channel[[!"$TotalNumberOfJ1939RmChannels"!]] =
{
[!VAR "ChannelIndex" = "'0'"!]
[!VAR "J1939RmAckmRxPduRefVerify" = "0"!]
[!LOOP "(node:order(J1939RmChannel/*))"!]
/*****************************CHANNEL [!"$ChannelIndex"!]*********************************************************/
  {
    /* J1939RmAckmRxPdu */
    [!IF "node:exists(J1939RmAckmRxPdu)"!]
      /* Make sure that MetaData of type CAN_ID_32 is configured for AckmRxPdu*/
      [!IF "(not(node:empty(node:ref(J1939RmAckmRxPdu/J1939RmAckmRxPduRef)/MetaDataTypeRef)))"!]
        [!IF "node:refvalid(node:ref(J1939RmAckmRxPdu/J1939RmAckmRxPduRef)/MetaDataTypeRef)"!]
          [!IF "(not(node:exists(node:ref(node:ref(J1939RmAckmRxPdu/J1939RmAckmRxPduRef)/MetaDataTypeRef)/MetaDataItem/*[MetaDataItemType = 'CAN_ID_32'])))"!]
            [!ERROR!]MetaDataItem should be configured as CAN_ID_32 for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmAckmRxPdu/J1939RmAckmRxPduRef))"!]" of J1939RmAckmRxPdu "[!"as:name(J1939RmAckmRxPdu)"!]".[!ENDERROR!]
          [!ENDIF!]
        [!ELSE!]
          [!ERROR!]No proper MetaDataTypeRef "[!"node:ref(J1939RmAckmRxPdu/J1939RmAckmRxPduRef)/MetaDataTypeRef"!]" exist for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmAckmRxPdu/J1939RmAckmRxPduRef))"!]" of J1939RmAckmRxPdu "[!"as:name(J1939RmAckmRxPdu)"!]".[!ENDERROR!]
        [!ENDIF!]
      [!ELSE!]
        [!ERROR!]MetaDataTypeRef should be configured for EcuC Pdu  of J1939RmAckmRxPdu "[!"as:name(J1939RmAckmRxPdu)"!]".[!ENDERROR!]
      [!ENDIF!]

      [!IF "node:exists(node:ref(J1939RmAckmRxPdu/J1939RmAckmRxPduRef)/PduId)"!]
            [!"node:ref(J1939RmAckmRxPdu/J1939RmAckmRxPduRef)/PduId"!],     /*J1939RmAckmRx_Ecuc_PduId*/
      [!ELSE!]
             [!ERROR!]PduId is not configured for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmAckmRxPdu/J1939RmAckmRxPduRef))"!]" of J1939RmAckmRxPdu "[!"as:name(.)"!]".[!ENDERROR!]
      [!ENDIF!] 

      [!VAR "J1939RmAckmRxPduRefVerify" = "name(as:ref(J1939RmAckmRxPdu/J1939RmAckmRxPduRef))"!]
      [!VAR "RefFound" = "'false'"!]
      [!LOOP "(node:order(as:modconf('PduR')[1]/PduRRoutingTables/*/PduRRoutingTable/*/PduRRoutingPath/*))"!]
        [!IF "$RefFound = 'true'"!]
          [!BREAK!]
        [!ELSE!]
          [!LOOP "(node:order(PduRDestPdu/*))"!]
            [!IF "$J1939RmAckmRxPduRefVerify = name(as:ref(PduRDestPduRef))"!] 
              [!VAR "RefFound" = "'true'"!]
              [!BREAK!]
            [!ENDIF!]
          [!ENDLOOP!]
        [!ENDIF!]
      [!ENDLOOP!]
      [!IF "$RefFound = 'false'"!]
        [!ERROR!]The J1939RmAckmRxPdu([!"as:name(J1939RmAckmRxPdu)"!]) reference [!"$J1939RmAckmRxPduRefVerify"!] is not matching with any PduRDestPduRef in the PduR module configuration.[!ENDERROR!]
      [!ENDIF!]
      /*J1939RmAckmRxPduId*/
      J1939RmConf_J1939RmAckmRxPdu_[!"as:name(J1939RmAckmRxPdu)"!],  /*uint16, The I-PDU identifier (Handle Id of J1939RmAckmRxPdu) used for RxIndication from PduR.*/

    [!ELSE!]
    /*J1939RmAckmRxPduId*/
    J1939RM_INVALID_PDU,                     /*uint16, The I-PDU identifier used for RxIndication from PduR*/
    J1939RM_INVALID_PDU,                     /*J1939RmAckmRx_Ecuc_PduId*/
    [!ENDIF!]
    


    /* J1939RmAckmTxPdu */
    [!IF "node:exists(J1939RmAckmTxPdu)"!]

      [!IF "node:exists(node:ref(J1939RmAckmTxPdu/J1939RmAckmTxPduRef)/PduId)"!]
        [!"node:ref(J1939RmAckmTxPdu/J1939RmAckmTxPduRef)/PduId"!],     /*J1939RmAckmTx_Ecuc_PduId*/
      [!ELSE!]
        [!ERROR!] PduId is not configured for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmAckmTxPdu/J1939RmAckmTxPduRef))"!]" of J1939RmAckmTxPdu "[!"as:name(.)"!]".[!ENDERROR!]
      [!ENDIF!] 
    

      [!VAR "J1939RmAckmTxPduRefVerify" = "name(as:ref(J1939RmAckmTxPdu/J1939RmAckmTxPduRef))"!]
      [!VAR "RefFound" = "'false'"!]
      /*J1939RmAckmTxPduId*/
      J1939RmConf_J1939RmAckmTxPdu_[!"as:name(J1939RmAckmTxPdu)"!],  /*uint16, The I-PDU identifier (Handle Id of J1939RmAckmTxPdu) used for TxConfirmation from PduR.*/

      /*J1939RmAckmTxPduRef*/
      [!LOOP "(node:order(../../../../../../../PduR/ELEMENTS/PduR/PduRRoutingTables/*))"!]
        [!IF "$RefFound = 'true'"!]
          [!BREAK!]
        [!ELSE!]
          [!LOOP "(node:order(PduRRoutingTable/*))"!]
            [!IF "$RefFound = 'true'"!]
              [!BREAK!]
            [!ELSE!]
              [!LOOP "(node:order(PduRRoutingPath/*))"!]
                [!IF "$J1939RmAckmTxPduRefVerify = name(as:ref(PduRSrcPdu/PduRSrcPduRef))"!]
                  [!"PduRSrcPdu/PduRSourcePduHandleId"!]U, /*uint16, The I-PDU identifier (Handle Id of PduRSrcPdu) used for TxConfirmation to upper layer. */
                  [!VAR "RefFound" = "'true'"!]
                  [!BREAK!]
                [!ENDIF!]
              [!ENDLOOP!]
            [!ENDIF!]
          [!ENDLOOP!]
        [!ENDIF!]
      [!ENDLOOP!]
      [!IF "$RefFound = 'false'"!]
        [!ERROR!]The J1939RmAckmTxPdu([!"as:name(J1939RmAckmTxPdu)"!]) reference [!"$J1939RmAckmTxPduRefVerify"!] is not matching with the PduR module configuration.[!ENDERROR!]
      [!ENDIF!]
    [!ELSE!]
    
      /*J1939RmAckmTx_Ecuc_PduId*/
      J1939RM_INVALID_PDU,
      /*J1939RmAckmTxPduId*/
      J1939RM_INVALID_PDU,  /*uint16, The I-PDU identifier used for TxConfirmation from PduR.*/

      /*J1939RmAckmTxPduRef*/
      J1939RM_INVALID_PDU,  /*uint16, The I-PDU identifier used for TxConfirmation to upper layer.*/
    [!ENDIF!]

    /* J1939RmRqstRxPdu */
    [!IF "node:exists(J1939RmRqstRxPdu)"!]
    
      /* Make sure that MetaData of type CAN_ID_32 is configured for RqstRxPdu*/
      [!IF "(not(node:empty(node:ref(J1939RmRqstRxPdu/J1939RmRqstRxPduRef)/MetaDataTypeRef)))"!]
        [!IF "node:refvalid(node:ref(J1939RmRqstRxPdu/J1939RmRqstRxPduRef)/MetaDataTypeRef)"!]
          [!IF "(not(node:exists(node:ref(node:ref(J1939RmRqstRxPdu/J1939RmRqstRxPduRef)/MetaDataTypeRef)/MetaDataItem/*[MetaDataItemType = 'CAN_ID_32'])))"!]
            [!ERROR!]MetaDataItem should be configured as CAN_ID_32 for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmRqstRxPdu/J1939RmRqstRxPduRef))"!]" of J1939RmRqstRxPdu "[!"as:name(J1939RmRqstRxPdu)"!]".[!ENDERROR!]
          [!ENDIF!]
        [!ELSE!]
          [!ERROR!]No proper MetaDataTypeRef "[!"node:ref(J1939RmRqstRxPdu/J1939RmRqstRxPduRef)/MetaDataTypeRef"!]" exist for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmRqstRxPdu/J1939RmRqstRxPduRef))"!]" of J1939RmRqstRxPdu "[!"as:name(J1939RmRqstRxPdu)"!]".[!ENDERROR!]
        [!ENDIF!]
      [!ELSE!]
        [!ERROR!]MetaDataTypeRef should be configured for EcuC Pdu  of J1939RmRqstRxPdu "[!"as:name(J1939RmRqstRxPdu)"!]".[!ENDERROR!]
      [!ENDIF!]

      [!IF "node:exists(node:ref(J1939RmRqstRxPdu/J1939RmRqstRxPduRef)/PduId)"!]
        [!"node:ref(J1939RmRqstRxPdu/J1939RmRqstRxPduRef)/PduId"!],     /*J1939RmRqstRx_Ecuc_PduId*/
      [!ELSE!]
        [!ERROR!] PduId is not configured for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmRqstRxPdu/J1939RmRqstRxPduRef))"!]" of J1939RmRqstRxPdu "[!"as:name(.)"!]".[!ENDERROR!]
      [!ENDIF!] 

      [!VAR "J1939RmRqstRxPduRefVerify" = "name(as:ref(J1939RmRqstRxPdu/J1939RmRqstRxPduRef))"!]
      [!VAR "RefFound" = "'false'"!]
      /*J1939RmRqstRxPduId*/
      [!LOOP "(node:order(as:modconf('PduR')[1]/PduRRoutingTables/*/PduRRoutingTable/*/PduRRoutingPath/*))"!]
        [!IF "$RefFound = 'true'"!]
          [!BREAK!]
        [!ELSE!]
          [!LOOP "(node:order(PduRDestPdu/*))"!]
            [!IF "$J1939RmRqstRxPduRefVerify = name(as:ref(PduRDestPduRef))"!] 
              [!VAR "RefFound" = "'true'"!]
              [!BREAK!]
            [!ENDIF!]
          [!ENDLOOP!]
        [!ENDIF!]
      [!ENDLOOP!]
      [!IF "$RefFound = 'false'"!]
        [!ERROR!]The J1939RmRqstRxPdu([!"as:name(J1939RmRqstRxPdu)"!]) reference [!"$J1939RmRqstRxPduRefVerify"!] is not matching with any PduRDestPduRef in the PduR module configuration.[!ENDERROR!]
      [!ENDIF!]
      J1939RmConf_J1939RmRqstRxPdu_[!"as:name(J1939RmRqstRxPdu)"!],  /*uint16, The I-PDU identifier (Handle Id of J1939RmRqstRxPdu) used for RxIndication from PduR.*/

    [!ELSE!]
    /*J1939RmRqstRxPduId*/
    J1939RM_INVALID_PDU,  /* J1939RmRqstRx_Ecuc_PduId */
    J1939RM_INVALID_PDU,  /* uint16, The I-PDU identifier used for RxIndication to upper layer.*/
    [!ENDIF!]


    /* J1939RmRqstTxPdu */
    [!IF "node:exists(J1939RmRqstTxPdu)"!]

      [!IF "node:exists(node:ref(J1939RmRqstTxPdu/J1939RmRqstTxPduRef)/PduId)"!]
        [!"node:ref(J1939RmRqstTxPdu/J1939RmRqstTxPduRef)/PduId"!],     /*J1939RmRqstTx_Ecuc_PduId*/
      [!ELSE!]
        [!ERROR!] PduId is not configured for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmRqstTxPdu/J1939RmRqstTxPduRef))"!]" of J1939RmRqstTxPdu "[!"as:name(.)"!]".[!ENDERROR!]
      [!ENDIF!] 

      [!VAR "J1939RmRqstTxPduRefVerify" = "name(as:ref(J1939RmRqstTxPdu/J1939RmRqstTxPduRef))"!]
      [!VAR "RefFound" = "'false'"!]
      /*J1939RmRqstTxPduId*/
      J1939RmConf_J1939RmRqstTxPdu_[!"as:name(J1939RmRqstTxPdu)"!],  /*uint16, The I-PDU identifier (Handle Id of J1939RmRqstTxPdu) used for TxConfirmation from PduR.*/

    /*J1939RmRqstTxPduRef*/
      [!LOOP "(node:order(../../../../../../../PduR/ELEMENTS/PduR/PduRRoutingTables/*))"!]
        [!IF "$RefFound = 'true'"!]
          [!BREAK!]
        [!ELSE!]
          [!LOOP "(node:order(PduRRoutingTable/*))"!]
            [!IF "$RefFound = 'true'"!]
              [!BREAK!]
            [!ELSE!]
              [!LOOP "(node:order(PduRRoutingPath/*))"!]
                [!IF "$J1939RmRqstTxPduRefVerify = name(as:ref(PduRSrcPdu/PduRSrcPduRef))"!]
                  [!"PduRSrcPdu/PduRSourcePduHandleId"!]U, /*uint16, The I-PDU identifier (Handle Id of PduRSrcPdu) used for TxConfirmation to upper layer. */
                  [!VAR "RefFound" = "'true'"!]
                  [!BREAK!]
                [!ENDIF!]
              [!ENDLOOP!]
            [!ENDIF!]
          [!ENDLOOP!]
        [!ENDIF!]
      [!ENDLOOP!]
      [!IF "$RefFound = 'false'"!]
        [!ERROR!]The J1939RmRqstTxPdu([!"as:name(J1939RmRqstTxPdu)"!]) reference [!"$J1939RmRqstTxPduRefVerify"!] is not matching with the PduR module configuration.[!ENDERROR!]
      [!ENDIF!]
    [!ELSE!]
      /*J1939RmRqstTxPduId*/
      J1939RM_INVALID_PDU,  /*uint16, The I-PDU identifier used for TxConfirmation from PduR.*/
      J1939RM_INVALID_PDU,  /*J1939RmRqstTx_Ecuc_PduId*/
      /*J1939RmRqstTxPduRef*/
      J1939RM_INVALID_PDU,  /*uint16, The I-PDU identifier used for TxConfirmation to upper layer.*/
    [!ENDIF!]

    /*J1939RmAckQueueSize*/
    /* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00018.J1939RmAckQueueSize,1 */
    [!"num:i(J1939RmAckQueueSize)"!]U,  /*uint8, Number of transmitted acknowledgements that can be stored.*/

    /*J1939RmRequestQueueSize*/
    /* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00021.J1939RmRequestQueueSize,1 */
    [!"num:i(J1939RmRequestQueueSize)"!]U,  /*uint8, Number of transmitted requests that can be stored.*/

    /*J1939RmRequestTimeoutMonitors*/
    [!"num:i(J1939RmRequestTimeoutMonitors)"!]U,  /*uint8, Number of transmitted requests that can be monitored for timeout.*/

    /*J1939RmChannelId*/
    J1939RM_J1939RMCHANNEL_CFG[!"$ConfigIndex"!]_[!"text:toupper(@name)"!],

    /*J1939RmAckmTxPdu MetaData Length*/

    [!IF "(node:exists(J1939RmAckmTxPdu))"!]
      [!IF "(not(node:empty(node:ref(J1939RmAckmTxPdu/J1939RmAckmTxPduRef)/MetaDataTypeRef)))"!]
        [!IF "node:refvalid(node:ref(J1939RmAckmTxPdu/J1939RmAckmTxPduRef)/MetaDataTypeRef)"!]
          [!IF "node:exists(node:ref(node:ref(J1939RmAckmTxPdu/J1939RmAckmTxPduRef)/MetaDataTypeRef)/MetaDataItem/*[MetaDataItemType = 'CAN_ID_32'])"!]
            4U, /* Pdu MetaDataLength */
          [!ELSE!]
            [!ERROR!]MetaDataItem should be configured as CAN_ID_32 for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmAckmTxPdu/J1939RmAckmTxPduRef))"!]" of J1939RmAckmTxPdu "[!"as:name(J1939RmAckmTxPdu)"!]".[!ENDERROR!]
          [!ENDIF!]
        [!ELSE!]
          /* !LINKSTO J1939Rm.EB.MetaData_J1939RmAckmTxPdu,1 */
          [!ERROR!]No proper MetaDataTypeRef "[!"node:ref(J1939RmAckmTxPdu/J1939RmAckmTxPduRef)/MetaDataTypeRef"!]" exist for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmAckmTxPdu/J1939RmAckmTxPduRef))"!]" of J1939RmAckmTxPdu "[!"as:name(J1939RmAckmTxPdu)"!]".[!ENDERROR!]
        [!ENDIF!]
      [!ELSE!]
        [!ERROR!]MetaDataTypeRef should be configured for EcuC Pdu  of J1939RmAckmTxPdu "[!"as:name(J1939RmAckmTxPdu)"!]".[!ENDERROR!]
      [!ENDIF!]
    [!ELSE!]
      0U, /*J1939RmAckmTxPdu is not configured*/
    [!ENDIF!]


    /*J1939RmRqstTxPdu MetaData Length*/
    [!IF "(node:exists(J1939RmRqstTxPdu))"!]
      [!IF "(not(node:empty(node:ref(J1939RmRqstTxPdu/J1939RmRqstTxPduRef)/MetaDataTypeRef)))"!]
        [!IF "node:refvalid(node:ref(J1939RmRqstTxPdu/J1939RmRqstTxPduRef)/MetaDataTypeRef)"!]
          [!IF "node:exists(node:ref(node:ref(J1939RmRqstTxPdu/J1939RmRqstTxPduRef)/MetaDataTypeRef)/MetaDataItem/*[MetaDataItemType = 'CAN_ID_32'])"!]
            4U /* Pdu MetaDataLength */
          [!ELSE!]
            [!ERROR!]MetaDataItem should be configured as CAN_ID_32 for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmRqstTxPdu/J1939RmRqstTxPduRef))"!]" of J1939RmRqstTxPdu "[!"as:name(J1939RmRqstTxPdu)"!]".[!ENDERROR!]
          [!ENDIF!]
        [!ELSE!]
          /* !LINKSTO J1939Rm.EB.MetaData_J1939RmRqstTxPdu,1 */
          [!ERROR!]No proper MetaDataTypeRef "[!"node:ref(J1939RmRqstTxPdu/J1939RmRqstTxPduRef)/MetaDataTypeRef"!]" exist for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmRqstTxPdu/J1939RmRqstTxPduRef))"!]" of J1939RmRqstTxPdu "[!"as:name(J1939RmRqstTxPdu)"!]".[!ENDERROR!]
        [!ENDIF!]
      [!ELSE!]
        [!ERROR!]MetaDataTypeRef should be configured for EcuC Pdu  of J1939RmRqstTxPdu "[!"as:name(J1939RmRqstTxPdu)"!]".[!ENDERROR!]
      [!ENDIF!]
    [!ELSE!]
      0U  /*J1939RmRqstTxPdu is not configured*/
    [!ENDIF!]

  },/* Deviation MISRAC2012-1 <1> */
[!VAR "ChannelIndex" = "num:i($ChannelIndex + 1)"!]
[!ENDLOOP!]
};

#define J1939RM_STOP_SEC_CONST_UNSPECIFIED
#include <J1939Rm_MemMap.h>

#define J1939RM_START_SEC_CONST_16
#include <J1939Rm_MemMap.h>

/* J1939Rm Node Configuration */
/* J1939Rm NodeUsers Configuration */
[!VAR "NodeIndex" = "'0'"!]
[!LOOP "(node:order(J1939RmNode/*))"!]
/*****************************CONFIGURATION [!"$ConfigIndex"!] NODE [!"$NodeIndex"!]*********************************************/
static CONST(uint16, J1939RM_CONST) J1939Rm_Cfg[!"$ConfigIndex"!]_Rmnode[!"$NodeIndex"!]_Rmusers[[!"num:i(count(node:order(J1939RmUser/*)))"!]] =
{
  [!LOOP "(node:order(J1939RmUser/*))"!]
  J1939RM_J1939RMUSER_CFG[!"$ConfigIndex"!]_[!"text:toupper(@name)"!],
  [!ENDLOOP!]
};
[!VAR "NodeIndex" = "num:i($NodeIndex + 1)"!]
[!ENDLOOP!]

#define J1939RM_STOP_SEC_CONST_16
#include <J1939Rm_MemMap.h>

#define J1939RM_START_SEC_CONST_8
#include <J1939Rm_MemMap.h>

/* J1939Rm NodeChannels Configuration */
[!VAR "NodeIndex" = "'0'"!]
[!LOOP "(node:order(J1939RmNode/*))"!]
/*****************************CONFIGURATION [!"$ConfigIndex"!] NODE [!"$NodeIndex"!]*********************************************/
static CONST(uint8, J1939RM_CONST) J1939Rm_Cfg[!"$ConfigIndex"!]_Rmnode[!"$NodeIndex"!]_Channels[[!"num:i(count(node:order(J1939RmNodeChannelRef/*)))"!]] =
{
  [!LOOP "(node:order(J1939RmNodeChannelRef/*))"!]
  J1939RM_J1939RMCHANNEL_CFG[!"$ConfigIndex"!]_[!"text:toupper(name(as:ref(.)))"!],
  [!ENDLOOP!]
};
[!VAR "NodeIndex" = "num:i($NodeIndex + 1)"!]
[!ENDLOOP!]

#define J1939RM_STOP_SEC_CONST_8
#include <J1939Rm_MemMap.h>

#define J1939RM_START_SEC_CONST_UNSPECIFIED
#include <J1939Rm_MemMap.h>

/* J1939Rm Node Configuration */
/*****************************CONFIGURATION [!"$ConfigIndex"!]*********************************************************/
static CONST(J1939Rm_Node_Const_Struct, J1939RM_CONST) J1939Rm_Cfg[!"$ConfigIndex"!]_Rmnode[[!"num:i(count(node:order(J1939RmNode/*)))"!]] =
{
  [!VAR "NodeIndex" = "'0'"!]
  [!LOOP "(node:order(J1939RmNode/*))"!]
  /*****************************NODE [!"$NodeIndex"!]*********************************************************/
  {
    /*J1939RmNodeUserRefPtr*/
    &J1939Rm_Cfg[!"$ConfigIndex"!]_Rmnode[!"$NodeIndex"!]_Rmusers[0],

    /*J1939RmNodeChannelRefPtr*/
    &J1939Rm_Cfg[!"$ConfigIndex"!]_Rmnode[!"$NodeIndex"!]_Channels[0],

    /*J1939RmNodeUserNr*/
    (uint8)[!"num:i(count(node:order(J1939RmUser/*)))"!]U, /* uint8, Number of Users present in J1939RmNode[!"$NodeIndex"!] configuration[!"$ConfigIndex"!] */

    /*J1939RmNodeChannelNr*/
    [!"num:i(count(node:order(J1939RmNodeChannelRef/*)))"!]U,  /*uint8, Number of Channels referred in J1939RmNode[!"$NodeIndex"!] configuration[!"$ConfigIndex"!] */

    /*J1939RmNodeId*/
    J1939RM_J1939RMNODE_CFG[!"$ConfigIndex"!]_[!"text:toupper(@name)"!],  /* J1939RM Node id */
    
    /*J1939RmNodeAddress*/
    J1939RM_J1939RMNODE_CFG[!"$ConfigIndex"!]_[!"text:toupper(@name)"!]_NODEADDRESS   /* J1939RM Node Address */
  },
  [!VAR "NodeIndex" = "num:i($NodeIndex + 1)"!]
  [!ENDLOOP!]
};

/* J1939Rm User Configuration */
/* COM Request Transmit I-PDU Configuration */
[!VAR "NodeIndex" = "'0'"!]
[!LOOP "(node:order(J1939RmNode/*))"!]
  [!VAR "UserIndex" = "'0'"!]
  [!LOOP "(node:order(J1939RmUser/*))"!]
    [!IF "J1939RmUserType = 'J1939RM_USER_COM'"!]
/*****************************CONFIGURATION [!"$ConfigIndex"!], NODE [!"$NodeIndex"!]*********************************************************/
static CONST(J1939Rm_ComIPdu_Const_Struct, J1939RM_CONST) J1939Rm_Cfg[!"$ConfigIndex"!]_Rmnode[!"$NodeIndex"!]_Rmuser[!"$UserIndex"!]_ComTxPdu[[!"num:i(count(node:order(J1939RmComIPdu/*)))"!]] =
{
    [!VAR "UserName" = "as:name(.)"!]
      [!LOOP "(node:order(J1939RmComIPdu/*))"!]
  {
    /*J1939RmComIPduPGN*/
    [!"node:value(J1939RmComIPduPGN)"!]U,/*uint32, PGN of the COM I-PDU.*/

    /*J1939RmUpperComIPduId*/
    J1939RmConf_J1939RmUpperComIPdu_[!"as:name(J1939RmUpperComIPdu)"!],  /*uint16, The I-PDU identifier (Handle Id of J1939RmUpperComIPdu) used for Tx from COM to J1939Rm.*/

    
    [!VAR "J1939Rm_ComIpduType" = "node:value(ComIPduType)"!]
    
    /*J1939RmUpperComIPduRef*/
      [!VAR "J1939RmUpperComIPduRefVerify" = "name(as:ref(J1939RmUpperComIPdu/J1939RmUpperComIPduRef))"!]
      [!VAR "RefFound" = "'false'"!]
      [!VAR "skip_J1939Tp" = "'TRUE'"!]
        [!IF "$Com_count > 0"!]
          [!LOOP "(node:order(../../../../../../../../../../../Com/ELEMENTS/Com/ComConfig/*))"!]
            [!IF "$RefFound = 'true'"!]
              [!BREAK!]
            [!ELSE!]
              [!LOOP "(node:order(ComIPdu/*))"!]
                [!IF "$J1939RmUpperComIPduRefVerify = name(as:ref(ComPduIdRef))"!]
    [!"ComIPduHandleId"!]U, /*uint16, The I-PDU identifier (Handle Id of ComIPdu) used for TxConfirmation to COM from J1939Rm. */
                  [!VAR "RefFound" = "'true'"!]
                  [!VAR "IpduType" = "node:value(ComIPduType)"!]
                    [!IF "$IpduType = 'NORMAL'"!]
                        [!VAR "skip_J1939Tp" = "'TRUE'"!]       /* True: If this is NORMAL Pdu that can be sent unfragmented, False: It this is large PDU that shall be sent via TP*/
    [!"$skip_J1939Tp"!], 
                    [!ELSE!]
                        [!VAR "skip_J1939Tp" = "'FALSE'"!]      /* True: If this is NORMAL Pdu that can be sent unfragmented, False: It this is large PDU that shall be sent via TP*/
    [!"$skip_J1939Tp"!],
                    [!ENDIF!]
                  [!BREAK!]
                [!ENDIF!]
              [!ENDLOOP!]
            [!ENDIF!]
          [!ENDLOOP!]
        [!ENDIF!]
        [!IF "$RefFound = 'false'"!]
        [!ERROR!]UpperComIpdu of [!"$UserName"!] is not configured in Com module [!ENDERROR!]
    J1939RM_INVALID_PDU,
        [!ENDIF!]
        
        [!IF "($J1939Rm_ComIpduType = 'ComIPdu_IF') and ($skip_J1939Tp = 'FALSE')"!]
            [!ERROR!]wrong ComIPduType for user [!"$UserName"!] [!ENDERROR!]
        [!ELSEIF "( $J1939Rm_ComIpduType = 'ComIPdu_TP') and ($skip_J1939Tp = 'TRUE')"!]
            [!ERROR!]wrong ComIPduType for user [!"$UserName"!] [!ENDERROR!]
        [!ENDIF!]

    /*J1939RmUpperComIPduRef-PduR*/
      [!VAR "J1939RmUpperPduRRefVerify" = "name(as:ref(J1939RmUpperComIPdu/J1939RmUpperComIPduRef))"!]
      [!VAR "RefFound" = "'false'"!]
      [!LOOP "(node:order(../../../../../../../../../../../PduR/ELEMENTS/PduR/PduRRoutingTables/*))"!]
        [!IF "$RefFound = 'true'"!]
          [!BREAK!]
        [!ELSE!]
          [!LOOP "(node:order(PduRRoutingTable/*))"!]
            [!IF "$RefFound = 'true'"!]
              [!BREAK!]
            [!ELSE!]
              [!LOOP "(node:order(PduRRoutingPath/*))"!]
                [!IF "$RefFound = 'true'"!]
                  [!BREAK!]
                [!ELSE!]
                  [!LOOP "(node:order(PduRDestPdu/*))"!]
                    [!IF "$J1939RmUpperPduRRefVerify = name(as:ref(PduRDestPduRef))"!]
                      [!IF "node:exists(PduRDestPduHandleId)"!]
    [!"PduRDestPduHandleId"!]U,  /*uint16, The I-PDU identifier (Handle Id of PduRDestPdu) used for TxConfirmation to COM from J1939Rm. */
                        [!VAR "RefFound" = "'true'"!]
                        [!BREAK!]
                      [!ELSE!]
                        [!ERROR!]The PduRDestPduHandleId shall be configured for the Pdu [!"$J1939RmUpperPduRRefVerify"!].[!ENDERROR!]
                      [!ENDIF!]
                    [!ENDIF!]
                  [!ENDLOOP!]
                [!ENDIF!]
              [!ENDLOOP!]
            [!ENDIF!]
          [!ENDLOOP!]
        [!ENDIF!]
      [!ENDLOOP!]
      [!IF "$RefFound = 'false'"!]
    J1939RM_INVALID_PDU,
      [!ENDIF!]

    /*J1939RmLowerComIPduId*/
    J1939RmConf_J1939RmLowerComIPdu_[!"as:name(J1939RmLowerComIPdu)"!],  /*uint16, The I-PDU identifier used for Tx  from J1939Rm to PduR.*/

      [!IF "node:exists(node:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef)/PduId)"!]
            [!"node:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef)/PduId"!],       /*J1939RmLowerComIPdu_Ecuc_PduId*/
      [!ELSE!].
              /* !LINKSTO J1939Rm.EB.J1939RmLowerComIPduRefPduId,1 */
             [!ERROR!]PduId is not configured for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef))"!]" of J1939RmLowerComIPdu "[!"as:name(.)"!]".[!ENDERROR!]
      [!ENDIF!] 

    /*J1939RmLowerComIPduRef*/
      [!VAR "J1939RmLowerPduRRefVerify" = "name(as:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef))"!]
      [!VAR "RefFound" = "'false'"!]
      
      [!LOOP "(as:modconf('PduR')[1]/PduRRoutingTables/*)"!]
        [!IF "$RefFound = 'true'"!]
          [!BREAK!]
        [!ELSE!]
          [!LOOP "(node:order(PduRRoutingTable/*))"!]
            [!IF "$RefFound = 'true'"!]
              [!BREAK!]
            [!ELSE!]
              [!LOOP "(node:order(PduRRoutingPath/*))"!]
                [!IF "$J1939RmLowerPduRRefVerify = name(as:ref(PduRSrcPdu/PduRSrcPduRef))"!]
    [!"PduRSrcPdu/PduRSourcePduHandleId"!]U,  /*uint16, The I-PDU identifier (Handle Id of PduRSrcPdu) used for TxConfirmation to J1939Rm from PduR. */
                  [!VAR "RefFound" = "'true'"!]
                  [!BREAK!]
                [!ENDIF!]
              [!ENDLOOP!]
            [!ENDIF!]
          [!ENDLOOP!]
        [!ENDIF!]
      [!ENDLOOP!]
      [!IF "$RefFound = 'false'"!]
        [!ERROR!]The J1939RmLowerComIPdu ([!"as:name(J1939RmLowerComIPdu)"!]) reference [!"$J1939RmLowerPduRRefVerify"!] which is not configured in the PduR module configuration.[!ENDERROR!]
      [!ENDIF!]

    /*J1939RmComIPduDA*/
    [!"J1939RmComIPduDA"!]U,/*uint8, Destination address of the COM I-PDU.*/

    /*J1939RmComIPduSA*/
    [!"J1939RmComIPduSA"!]U,/*uint8, Source address of the COM I-PDU.*/

    /*J1939RmLowerComIPdu MetaData Length*/

    [!IF "not(node:empty(node:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef)/MetaDataTypeRef))"!]
      [!VAR "MetaDataItemLength"= "'0'"!]
      [!IF "node:refvalid(node:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef)/MetaDataTypeRef)"!]
        [!IF " (node:exists(node:ref(node:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef)/MetaDataTypeRef)/MetaDataItem/*[MetaDataItemType = 'PRIORITY_8']) ) and ($skip_J1939Tp = 'FALSE')"!]
          [!IF "node:exists(node:ref(node:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef)/MetaDataTypeRef)/MetaDataItem/*[MetaDataItemType = 'TARGET_ADDRESS_16'])"!]
            [!IF "node:exists(node:ref(node:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef)/MetaDataTypeRef)/MetaDataItem/*[MetaDataItemType = 'SOURCE_ADDRESS_16'])"!]
              [!VAR "MetaDataItemLength"= "'4'"!]
            [!ELSE!]
              [!ERROR!]MetaDataItem "SOURCE_ADDRESS_16" is not configured for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef))"!]" of J1939RmLowerComIPdu "[!"as:name(J1939RmLowerComIPdu)"!]".[!ENDERROR!]
            [!ENDIF!]
          [!ELSE!]
            [!ERROR!]MetaDataItem "TARGET_ADDRESS_16" is not configured for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef))"!]" of J1939RmLowerComIPdu "[!"as:name(J1939RmLowerComIPdu)"!]".[!ENDERROR!]
          [!ENDIF!]
        [!ELSEIF "(node:exists(node:ref(node:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef)/MetaDataTypeRef)/MetaDataItem/*[MetaDataItemType = 'TARGET_ADDRESS_16']) ) and ($skip_J1939Tp = 'FALSE')"!]
          [!IF "node:exists(node:ref(node:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef)/MetaDataTypeRef)/MetaDataItem/*[MetaDataItemType = 'SOURCE_ADDRESS_16'])"!]
            [!VAR "MetaDataItemLength"= "'2'"!]
          [!ELSE!]
            [!ERROR!]MetaDataItem "SOURCE_ADDRESS_16" is not configured for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef))"!]" of J1939RmLowerComIPdu "[!"as:name(J1939RmLowerComIPdu)"!]".[!ENDERROR!]
          [!ENDIF!]
        [!ELSEIF "(node:exists(node:ref(node:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef)/MetaDataTypeRef)/MetaDataItem/*[MetaDataItemType = 'CAN_ID_32'])) and ($skip_J1939Tp = 'TRUE')"!]
            [!VAR "MetaDataItemLength"= "'4'"!]
        [!ELSE!]
          /* !LINKSTO J1939Rm.EB.MetaData_J1939RmLowerComIPdu,1 */
          [!ERROR!]MetaDataItem is not configured correctly for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef))"!]" of J1939RmLowerComIPdu "[!"as:name(J1939RmLowerComIPdu)"!]".[!ENDERROR!]
        [!ENDIF!]
      [!ELSE!]
        [!ERROR!]No proper MetaDataTypeRef "[!"node:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef)/MetaDataTypeRef"!]" exist for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef))"!]" of J1939RmLowerComIPdu "[!"as:name(J1939RmLowerComIPdu)"!]".[!ENDERROR!]
      [!ENDIF!]
    [!"$MetaDataItemLength"!]U /* Pdu MetaDataLength */
    [!ELSE!]
       [!ERROR!]MetaDataItem is not configured for the reference EcuC Pdu "[!"node:name(as:ref(J1939RmLowerComIPdu/J1939RmLowerComIPduRef))"!]" of J1939RmLowerComIPdu "[!"as:name(J1939RmLowerComIPdu)"!]".[!ENDERROR!]
    [!ENDIF!]

  },
      [!ENDLOOP!]
};
    [!ENDIF!]
  [!VAR "UserIndex" = "num:i($UserIndex + 1)"!]
  [!ENDLOOP!]
[!VAR "NodeIndex" = "num:i($NodeIndex + 1)"!]
[!ENDLOOP!]

#define J1939RM_STOP_SEC_CONST_UNSPECIFIED
#include <J1939Rm_MemMap.h>

#define J1939RM_START_SEC_CONST_32
#include <J1939Rm_MemMap.h>

/* PGN Configuration */
[!VAR "NodeIndex" = "'0'"!]
[!LOOP "(node:order(J1939RmNode/*))"!]
  [!VAR "UserIndex" = "'0'"!]
  [!LOOP "(node:order(J1939RmUser/*))"!]
    [!IF "((J1939RmUserType = 'J1939RM_USER_CDD') or (J1939RmUserType = 'J1939RM_USER_RTE'))"!]
        [!IF "num:i(count(node:order(J1939RmUserAckPGN/*))) > 0"!]
/* J1939RmUserAckPGNs */
static CONST(uint32, J1939RM_CONST) J1939Rm_Cfg[!"$ConfigIndex"!]_Rmnode[!"$NodeIndex"!]_Rmuser[!"$UserIndex"!]_UserAckPGNs[[!"num:i(count(node:order(J1939RmUserAckPGN/*)))"!]] =
{
      [!LOOP "(node:order(J1939RmUserAckPGN/*))"!]
  [!"node:value(.)"!]U,
      [!ENDLOOP!]
};
        [!ENDIF!]
    [!ENDIF!]
  [!VAR "UserIndex" = "num:i($UserIndex + 1)"!]
  [!ENDLOOP!]
[!VAR "NodeIndex" = "num:i($NodeIndex + 1)"!]
[!ENDLOOP!]

[!VAR "NodeIndex" = "'0'"!]
[!LOOP "(node:order(J1939RmNode/*))"!]
  [!VAR "UserIndex" = "'0'"!]
  [!LOOP "node:order(J1939RmUser/*)"!]
    [!IF "((J1939RmUserType) = 'J1939RM_USER_J1939NM')"!]
       /* J1939RmUserPGNs */
       /*J1939RmUserPGN is predefined to AC (0x0EE00) for J1939RmUserType J1939RM_USER_J1939NM*/
      static CONST(uint32, J1939RM_CONST) J1939Rm_Cfg[!"$ConfigIndex"!]_Rmnode[!"$NodeIndex"!]_Rmuser[!"$UserIndex"!]_UserPGNs[1] =
       {
       60928U
       };
    [!ELSEIF "count(J1939RmUserPGN/*) > 0"!]
    /* J1939RmUserPGNs */
    /*Array of the configured PGNs for user [!"$UserIndex"!] */
static CONST(uint32, J1939RM_CONST) J1939Rm_Cfg[!"$ConfigIndex"!]_Rmnode[!"$NodeIndex"!]_Rmuser[!"$UserIndex"!]_UserPGNs[[!"num:i(count(node:order(J1939RmUserPGN/*)))"!]] =
    {
    [!LOOP "(node:order(J1939RmUserPGN/*))"!]

    [!"node:value(.)"!]U,

    [!ENDLOOP!]
    };
    [!ENDIF!]
  [!VAR "UserIndex" = "num:i($UserIndex + 1)"!]
  [!ENDLOOP!]
[!VAR "NodeIndex" = "num:i($NodeIndex + 1)"!]
[!ENDLOOP!]

#define J1939RM_STOP_SEC_CONST_32
#include <J1939Rm_MemMap.h>

#define J1939RM_START_SEC_CONST_UNSPECIFIED
#include <J1939Rm_MemMap.h>

/* J1939Rm User Configuration */
/*****************************CONFIGURATION [!"$ConfigIndex"!]*********************************************/
static CONST(J1939Rm_User_Const_Struct, J1939RM_CONST) J1939Rm_Cfg[!"$ConfigIndex"!]_Rmuser[[!"num:i($TotalNumberOfJ1939RmUser)"!]] =
{
[!VAR "NodeIndex" = "'0'"!]
[!LOOP "(node:order(J1939RmNode/*))"!]
  [!VAR "UserIndex" = "'0'"!]
  [!LOOP "(node:order(J1939RmUser/*))"!]
  {
    
    
        [!VAR "userName" = "@name"!]
        [!VAR "userName_occurance" = "'0'"!]
      [!LOOP "(as:modconf('J1939Rm')[1]/J1939RmConfigSet/*)"!]

          [!LOOP "(node:order(J1939RmNode/*))"!]
              [!LOOP "(node:order(J1939RmUser/*))"!]
              [!VAR "CurrentUserName" = "@name"!]
                [!IF "$userName = $CurrentUserName"!]
                    [!VAR "userName_occurance" = "num:i($userName_occurance + 1)"!]
                [!ENDIF!]
              [!ENDLOOP!]
          [!ENDLOOP!]
      [!ENDLOOP!]
      [!IF "$userName_occurance > 1"!]
      [!ERROR!]The username should not be repeated[!ENDERROR!]
      [!ENDIF!]
    
    
                                        
 
    /*J1939RmComIPduStructConstPtr*/
    [!IF "(J1939RmUserType = 'J1939RM_USER_COM')"!]
    &J1939Rm_Cfg[!"$ConfigIndex"!]_Rmnode[!"$NodeIndex"!]_Rmuser[!"$UserIndex"!]_ComTxPdu[0], /*This configuration of an I-PDU is only relevant to J1939RmUserType J1939RM_USER_COM.*/
    
    [!ELSE!]
    NULL_PTR, /*This configuration of an I-PDU is only relevant to J1939RmUserType J1939RM_USER_COM.*/
    [!ENDIF!]

    /* J1939RmUserAckIndicationFctPtr */
    /* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00086,1 */
    [!IF "(//J1939RmSupportAckIndication = 'true') and (J1939RmUserAckIndication = 'true') and (J1939RmUserType = 'J1939RM_USER_CDD')"!]
    /* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00027,1 */
    &[!"J1939RmUserCddName"!]_AckIndication,
    [!ELSEIF "(//J1939RmSupportAckIndication = 'true') and (J1939RmUserAckIndication = 'true') and (J1939RmUserType = 'J1939RM_USER_RTE')"!]
    /* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00028,1 */
    /* Deviation MISRAC2012-2 <1> */
    (void (*)(uint8 node, NetworkHandleType channel, uint32 ackPgn, J1939Rm_AckCode ackCode, uint8 ackAddress, uint8 sourceAddress, uint8 priority))Rte_Call_J1939Rm_AckIndication_[!"@name"!]_AckIndication,
    [!ELSE!]
    NULL_PTR, /*_AckIndication*/
    [!ENDIF!]


    /* J1939RmUserRequestIndicationFctPtr */
    /* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00085,1 */
    [!IF "(J1939RmUserRequestIndication = 'true') and (as:modconf('J1939Rm')[1]/J1939RmGeneral/J1939RmSupportRequestIndication = 'true')"!]
      [!IF "J1939RmUserType = 'J1939RM_USER_J1939DCM'"!]
       /* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00002.J1939Dcm,1 */
       /* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00045.J1939Dcm_RequestIndication,1 */
    &J1939Dcm_RequestIndication,
      [!ENDIF!]
      [!IF "J1939RmUserType = 'J1939RM_USER_J1939NM'"!]
      /* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00045.J1939Nm_RequestIndication,1 */
      /* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00002.J1939Nm,1 */
    &J1939Nm_RequestIndication,
      [!ENDIF!]
      [!IF "J1939RmUserType = 'J1939RM_USER_CDD'"!]
      /* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00002.CDD,1 */
    &[!"J1939RmUserCddName"!]_RequestIndication,
      [!ENDIF!]
      [!IF "J1939RmUserType = 'J1939RM_USER_RTE'"!]  
      /* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00003,1 */
      /* Deviation MISRAC2012-2 <1> */
    (void (*)(uint8 node, NetworkHandleType channel, uint32 requestedPgn, uint8 sourceAddress, uint8 destAddress, uint8 priority))Rte_Call_J1939Rm_RequestIndication_[!"@name"!]_RequestIndication,
      [!ENDIF!]
    [!ELSE!]
    NULL_PTR, /*_RequestIndication*/
    [!ENDIF!]

    /* J1939RmUserRequestTimeoutIndicationFctPtr */
    /* !LINKSTO J1939Rm.ASR413.SWS_J1939Rm_00087,1 */
    [!IF "(//J1939RmSupportTimeoutSupervision = 'true') and (J1939RmUserTimeoutSupervision = 'true') and (J1939RmUserType = 'J1939RM_USER_CDD')"!]
    &[!"J1939RmUserCddName"!]_RequestTimeoutIndication,
    [!ELSEIF "(//J1939RmSupportTimeoutSupervision = 'true') and (J1939RmUserTimeoutSupervision = 'true') and (J1939RmUserType = 'J1939RM_USER_RTE')"!]
    /* Deviation MISRAC2012-2 <1> */
    (void (*)(uint8 node, NetworkHandleType channel, uint32 requestedPgn, uint8 destAddress))Rte_Call_J1939Rm_RequestTimeoutIndication_[!"@name"!]_RequestTimeoutIndication,
    [!ELSE!]
    NULL_PTR, /*_RequestTimeoutIndication*/
    [!ENDIF!]

    /* J1939RmUserSendAckSupport */
    [!IF "(//J1939RmSupportAckTransmission = 'true') and (J1939RmUserSendAck = 'true')"!]
      [!IF "((J1939RmUserType = 'J1939RM_USER_CDD') or (J1939RmUserType = 'J1939RM_USER_RTE') or (J1939RmUserType = 'J1939RM_USER_J1939DCM'))"!]
    TRUE,
      [!ELSE!]
    FALSE,
      [!ENDIF!]
    [!ELSE!]
    FALSE,
    [!ENDIF!]

    /* J1939RmUserSendRequestSupport */
    [!IF "(//J1939RmSupportRequestTransmission = 'true') and (J1939RmUserSendRequest = 'true')"!]
      [!IF "((J1939RmUserType = 'J1939RM_USER_CDD') or (J1939RmUserType = 'J1939RM_USER_RTE'))"!]
    TRUE,
      [!ELSE!]
    FALSE,
      [!ENDIF!]
    [!ELSE!]
    FALSE,
    [!ENDIF!]

    /* J1939RmCancelRequestTimeoutFctPtr */
    [!IF "(//J1939RmSupportTimeoutSupervision = 'true') and (J1939RmUserTimeoutSupervision = 'true')"!]
      [!IF "((J1939RmUserType = 'J1939RM_USER_CDD') or (J1939RmUserType = 'J1939RM_USER_RTE'))"!]
    &J1939Rm_CancelRequestTimeout,
      [!ELSE!]
    NULL_PTR,
      [!ENDIF!]
    [!ELSE!]
    NULL_PTR,
    [!ENDIF!]

    /* J1939RmUserPGNPtr */
    [!IF "count(J1939RmUserPGN/*) > 0"!]
    &J1939Rm_Cfg[!"$ConfigIndex"!]_Rmnode[!"$NodeIndex"!]_Rmuser[!"$UserIndex"!]_UserPGNs[0],
    [!ELSE!]
    NULL_PTR,
    [!ENDIF!]

    /* J1939RmUserAckPGNPtr */
    [!IF "((J1939RmUserType = 'J1939RM_USER_COM') or (J1939RmUserType = 'J1939RM_USER_J1939DCM') or (J1939RmUserType = 'J1939RM_USER_J1939NM') or (num:i(count(node:order(J1939RmUserAckPGN/*))) <= 0))"!]
    NULL_PTR,
    [!ELSE!]
    &J1939Rm_Cfg[!"$ConfigIndex"!]_Rmnode[!"$NodeIndex"!]_Rmuser[!"$UserIndex"!]_UserAckPGNs[0],
    [!ENDIF!]

    /* J1939RmUserPGNNr */
    [!IF "(J1939RmUserType = 'J1939RM_USER_COM')"!]
    0U, /*Zero for J1939RM_USER_COM J1939RmUserType configured*/
    [!ELSE!]
    [!"num:i(count(node:order(J1939RmUserPGN/*)))"!]U, /*Number of PGNs supported to be requested from this User.*/
    [!ENDIF!]

    /* J1939RmUserAckPGNNr */
    [!IF "J1939RmUserType = 'J1939RM_USER_COM'"!]
    0U, /*Zero for J1939RM_USER_COM J1939RmUserType configured*/
    [!ELSE!]
    [!"num:i(count(node:order(J1939RmUserAckPGN/*)))"!]U, /*Number of Ack PGNs supported to be acknowledged from this User.*/
    [!ENDIF!]

    /*J1939RmComIPduNr*/
    [!IF "J1939RmUserType = 'J1939RM_USER_COM'"!]
    [!"num:i(count(node:order(J1939RmComIPdu/*)))"!]U, /*uint16, Number of ComIpdus present in J1939RmUser[!"$UserIndex"!] J1939RmNode[!"$NodeIndex"!] configuration[!"$ConfigIndex"!]*/
    [!ELSE!]
    0U, /* ComIpdus is not required when COM is not the user*/
    [!ENDIF!]

    /*J1939RmUserComIPduRequestQueueSize*/
    [!IF "J1939RmUserType = 'J1939RM_USER_COM'"!]
    [!"node:value(J1939RmUserComIPduRequestQueueSize)"!]U, /* Number of received requests that can be stored for COM I-PDUs of this user.*/
    [!ELSE!]
    0U, /*0 - J1939RmUserComIPduRequestQueueSize needs to be configured only for user type J1939RM_USER_COM.*/
    [!ENDIF!]

    /* J1939RmUserType */
    [!"J1939RmUserType"!],

    /* J1939RmUserId */
    J1939RM_J1939RMUSER_CFG[!"$ConfigIndex"!]_[!"text:toupper(node:name(.))"!] /*Id used by a module using J1939Rm, only required for transmission of requests.*/
  },
  [!VAR "UserIndex" = "num:i($UserIndex + 1)"!]
  [!ENDLOOP!]
[!VAR "NodeIndex" = "num:i($NodeIndex + 1)"!]
[!ENDLOOP!]
};

#define J1939RM_STOP_SEC_CONST_UNSPECIFIED
#include <J1939Rm_MemMap.h>

[!VAR "ConfigIndex" = "num:i($ConfigIndex + 1)"!]
[!ENDSELECT!][!//

#define J1939RM_START_SEC_CONST_UNSPECIFIED
#include <J1939Rm_MemMap.h>

/* J1939Rm Configuration */
/* !LINKSTO J1939Rm.dsn.PrecompileTimeConfig,1 */
CONST(J1939Rm_RealStructType, J1939RM_CONST) J1939Rm_Cfg_J1939RmConfig[J1939RM_NUM_CFG] =
{
[!VAR "ConfigIndex" = "'0'"!]
[!LOOP "(J1939RmConfigSet/*)"!]
/*****************************CONFIGURATION [!"$ConfigIndex"!]*********************************************************/
  {
    /*J1939RmChannelConstStructPtr*/
    &J1939Rm_Cfg[!"$ConfigIndex"!]_Channel[0],

    /*J1939RmNodeConstStructPtr*/
    &J1939Rm_Cfg[!"$ConfigIndex"!]_Rmnode[0],

    /*J1939RmUserConstStructPtr*/
    &J1939Rm_Cfg[!"$ConfigIndex"!]_Rmuser[0],

    &J1939Rm_Cfg[!"$ConfigIndex"!]_ChannelBss[0],

    &J1939Rm_Cfg[!"$ConfigIndex"!]_AckmTxQueueTypeBss[0],

    &J1939Rm_Cfg[!"$ConfigIndex"!]_RqstTxQueueTypeBss[0],

    &J1939Rm_Cfg[!"$ConfigIndex"!]_RqstTsQueueTypeBss[0],

    &J1939Rm_Cfg[!"$ConfigIndex"!]_AckmTxQueueDataBss[0],

    &J1939Rm_Cfg[!"$ConfigIndex"!]_RqstTxQueueDataBss[0],

    &J1939Rm_Cfg[!"$ConfigIndex"!]_RqstTsQueueDataBss[0],

    &J1939Rm_Cfg[!"$ConfigIndex"!]_ComIpduRqstQueueTypeBss[0],

    [!IF "$Com_count > 0"!]
    /* Memory allocation area info - J1939Rm_ComIpduRqstQueueData_Struct_tag structure */
    &J1939Rm_Cfg[!"$ConfigIndex"!]_ComIpduRqstQueueDataBss[0],
    [!ELSE!]
    /* Runtime Memory allocation area info - Icsp_J1939Rm_ComIpduRqstQueueData_Struct_tag structure */
    NULL_PTR, /*&Icsp_J1939Rm_Cnf_Cfg[!"$ConfigIndex"!]_ComIpduRqstQueueDataBss[0],*/
    [!ENDIF!]

    /*J1939RmTxConfirmationTimeout*/
    [!"$J1939RmTxConfirmationTimeoutValue"!]U,  /* uint16,  Number of J1939Rm MainFunction calls to wait for a Tx confirmation. */

    /*J1939RmTimeoutSupervision*/
    [!"$J1939RmTimeoutSupervisionValue"!]U,  /* uint16,  Number of J1939Rm MainFunction calls to wait for a J1939RmUserTimeoutSupervision to reach 1.25s. */

    /*J1939RmUserNr*/
    [!"num:i($TotalNumberOfJ1939RmUser)"!]U, /*uint16, Number of Users*/

    /*J1939RmNodeNr*/
    [!"$TotalNumberOfJ1939RmNodes"!]U, /*uint8, Number of Nodes*/

    /*J1939RmChannelNr*/
    [!"$TotalNumberOfJ1939RmChannels"!]U, /*uint8, Number of Channels*/
  },
  /* Deviation MISRAC2012-1 <1> */
[!VAR "ConfigIndex" = "num:i($ConfigIndex + 1)"!]
[!ENDLOOP!]
};

#define J1939RM_STOP_SEC_CONST_UNSPECIFIED
#include <J1939Rm_MemMap.h>
/*======================[end of file]============================================*/

[!ENDCODE!]
