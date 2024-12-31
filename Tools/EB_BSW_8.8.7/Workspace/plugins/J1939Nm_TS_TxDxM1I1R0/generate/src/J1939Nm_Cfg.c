/**
 * \file
 *
 * \brief AUTOSAR J1939Nm
 *
 * This file contains the implementation of the AUTOSAR
 * module J1939Nm.
 *
 * \version 1.1.7
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/* This file is generated from the configuration of J1939Nm module */

[!CODE!]
[!INCLUDE "include/J1939Nm_Vars.m"!][!//
[!AUTOSPACING!][!//
/*==================[inclusions]============================================*/

#include <J1939Nm_Cfg.h>
#include <NmStack_Types.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/
[!SELECT "(J1939NmConfigSet/*)"!][!//
#define J1939NM_START_SEC_VAR_INIT_8
#include <J1939Nm_MemMap.h>
[!LOOP "node:order(J1939NmChannel/*)"!]
[!VAR "ChannelName"= "@name"!]
[!VAR "NodeCounter"= "'0'"!]

  [!LOOP "node:order(../../J1939NmNode/*, 'J1939NmNodeId')"!]
    [!VAR "NodeId"= "J1939NmNodeId"!]
    [!LOOP "node:order(J1939NmNodeChannelRef/*)"!]
      [!IF "$ChannelName = name(as:ref(.))"!]
      [!VAR "NodeCounter"= "$NodeCounter + 1"!]
      [!ENDIF!]
    [!ENDLOOP!]
  [!ENDLOOP!]
[!WS "2"!]
[!ENDLOOP!]

#define J1939NM_STOP_SEC_VAR_INIT_8
#include <J1939Nm_MemMap.h>


[!IF "$J1939NmDemEventRefCount != 0"!]

#define J1939NM_START_SEC_CONST_UNSPECIFIED
#include <J1939Nm_MemMap.h>

[!LOOP "node:order(J1939NmChannel/*)"!]
[!VAR "DemChannelName"= "@name"!]
[!VAR "EventCounter"= "'0'"!]

[!LOOP "node:order(J1939NmNodeSpecificDemEventParameterRefs/*)"!]
  [!VAR "EventCounter"= "$EventCounter + 1"!]
[!ENDLOOP!]
[!IF "$EventCounter != '0'"!]
/* DemEvent Array for [!"$DemChannelName"!]*/
static CONST(J1939Nm_DemEventType, J1939NM_CONST) [!"(@name)"!]_DemEvent[[!"num:i($EventCounter)"!]] =
{
  [!LOOP "node:order(J1939NmNodeSpecificDemEventParameterRefs/*)"!]
  [!VAR "DemEventName"= "@name"!]
  /* [!"$DemEventName"!]*/
  {
    [!IF "node:exists(node:ref(J1939NM_E_ADDRESS_LOST)/DemEventId)"!]
    [!"node:ref(J1939NM_E_ADDRESS_LOST)/DemEventId"!]U,   /* Dem Event Id */
    [!ELSE!]
      [!ERROR!]DemEventId shall be configured for each Dem Event referenced in J1939NmNodeSpecificDemEventParameterRefs [!ENDERROR!]
    [!ENDIF!]
    [!IF "node:exists(node:ref(J1939NmNodeRef)/J1939NmNodeId)"!]
    [!"node:ref(J1939NmNodeRef)/J1939NmNodeId"!]U,    /* Node Id */
    [!ELSE!]
     [!ERROR!]J1939NmNodeId shall be configured for each J1939Nm Node referenced in J1939NmNodeSpecificDemEventParameterRefs [!ENDERROR!]
    [!ENDIF!]
  },
  [!ENDLOOP!]
};
[!ENDIF!]
[!ENDLOOP!]
#define J1939NM_STOP_SEC_CONST_UNSPECIFIED
#include <J1939Nm_MemMap.h>

[!ENDIF!]

#define J1939NM_START_SEC_VAR_INIT_UNSPECIFIED
#include <J1939Nm_MemMap.h>

static VAR(J1939Nm_ChannelConfigType, J1939NM_VAR) J1939Nm_CasChannelConfig[J1939NM_NUMBER_OF_CHANNELS] =
{
[!LOOP "node:order(J1939NmChannel/*)"!]
[!VAR "ChannelName"= "@name"!]
[!VAR "TxPduRef" =  "node:ref(J1939NmTxPdu/J1939NmTxPduRef)/@name"!]
[!VAR "RxPduRef" =  "node:ref(J1939NmRxPdu/J1939NmRxPduRef)/@name"!]
[!VAR "NodeCounter"= "'0'"!]
[!VAR "TxPduRefSet"= "'0'"!]
[!VAR "RxPduRefSet"= "'0'"!]
[!IF "$J1939NmDemEventRefCount != 0"!]
[!VAR "DemEventCounter"= "'0'"!]
[!ENDIF!]
 {
 /* [!"$ChannelName"!] */
  {
  /* The [!"$ChannelName"!] contains below NodeChannels */
  [!LOOP "node:order(../../J1939NmNode/*, 'J1939NmNodeId')"!]
  [!VAR "NodeId"= "J1939NmNodeId"!]
    [!LOOP "node:order(J1939NmNodeChannelRef/*)"!]
    [!IF "$ChannelName = name(as:ref(.))"!]
   {
    /* NodeChannel contains Channel ([!"$ChannelName"!]) and Node ([!"@name"!]) */
    NM_MODE_BUS_SLEEP,       /* Before initializing with SLEEP_MODE */
    NM_STATE_OFFLINE,        /* Before setting NETWORK_MODE */
    J1939NM_OFFLINE_CLAIMING,/* Before changing to any sub-state */
    [!"num:i($NodeId)"!]U     /* ID of the Node ([!"@name"!]) */
   },
    [!ENDIF!]
    [!ENDLOOP!]
  [!ENDLOOP!]
  },
  {
  [!LOOP "node:order(../../../../../../../CanIf/ELEMENTS/CanIf/CanIfInitCfg/*/CanIfTxPduCfg/*, 'CanIfTxPduId')"!]
    [!IF "name(as:ref(CanIfTxPduRef)) = $TxPduRef"!]
    [!"node:value(CanIfTxPduId)"!]U, /* CanIf TxPdu ID */
    [!VAR "TxPduRefSet"= "$TxPduRefSet + 1"!]
    [!BREAK!]
    [!ENDIF!]
  [!ENDLOOP!]
  [!IF "$TxPduRefSet = '0'"!]
    [!ERROR!]The [!"$TxPduRef"!] is not configured in the CanIf Tx configuration.[!ENDERROR!]
  [!ENDIF!]
    [!IF "node:refvalid(node:ref(J1939NmTxPdu/J1939NmTxPduRef)/MetaDataTypeRef)"!]
      [!IF "node:exists(node:ref(node:ref(J1939NmTxPdu/J1939NmTxPduRef)/MetaDataTypeRef)/MetaDataItem/*[MetaDataItemType = 'CAN_ID_32'])"!]
      [!ELSE!]
        [!ERROR!]MetaDataItem "CAN_ID_32" is not configured for the reference EcuC Pdu "[!"node:name(as:ref(J1939NmTxPdu/J1939NmTxPduRef))"!]" of J1939NmTxPdu "[!"as:name(J1939NmTxPdu)"!]". MetaDataItemLength shall be configured to 4 for a J1939Nm Tx Pdu.[!ENDERROR!]
      [!ENDIF!]
    [!ELSE!]
      [!ERROR!]No proper MetaDataTypeRef "[!"node:ref(J1939NmTxPdu/J1939NmTxPduRef)/MetaDataTypeRef"!]" exist for the reference EcuC Pdu "[!"node:name(as:ref(J1939NmTxPdu/J1939NmTxPduRef))"!]" of J1939NmTxPdu "[!"as:name(J1939NmTxPdu)"!]".[!ENDERROR!]
    [!ENDIF!]
  [!IF "node:exists(node:ref(J1939NmTxPdu/J1939NmTxPduRef)/PduId)"!]
    [!"node:ref(J1939NmTxPdu/J1939NmTxPduRef)/PduId"!]
  [!ELSE!]
    [!ERROR!]PduId shall be configured for each EcuC Pdu referenced in J1939NmTxPduRef [!ENDERROR!]
  [!ENDIF!] 
  },
  {
  [!LOOP "node:order(../../../../../../../CanIf/ELEMENTS/CanIf/CanIfInitCfg/*/CanIfRxPduCfg/*, 'CanIfRxPduId')"!]
    [!IF "name(as:ref(CanIfRxPduRef)) = $RxPduRef"!]
    [!"node:value(CanIfRxPduId)"!]U, /* CanIf RxPdu ID */
    [!VAR "RxPduRefSet"= "$RxPduRefSet + 1"!]
    [!BREAK!]
    [!ENDIF!]
  [!ENDLOOP!]
  [!IF "$RxPduRefSet = '0'"!]
    [!ERROR!]The [!"$RxPduRef"!] is not configured in the CanIf Rx configuration.[!ENDERROR!]
  [!ENDIF!]
  [!IF "not(node:empty(node:ref(J1939NmRxPdu/J1939NmRxPduRef)/MetaDataTypeRef))"!]

    [!IF "node:refvalid(node:ref(J1939NmRxPdu/J1939NmRxPduRef)/MetaDataTypeRef)"!]
      [!IF "node:exists(node:ref(node:ref(J1939NmRxPdu/J1939NmRxPduRef)/MetaDataTypeRef)/MetaDataItem/*[MetaDataItemType = 'CAN_ID_32'])"!]
      [!ELSE!]
          [!ERROR!]MetaDataItem "CAN_ID_32" is not configured for the reference EcuC Pdu "[!"node:name(as:ref(J1939NmRxPdu/J1939NmRxPduRef))"!]" of J1939NmRxPdu "[!"as:name(J1939NmRxPdu)"!]".[!ENDERROR!]
      [!ENDIF!]



    [!ELSE!]
      [!ERROR!]No proper MetaDataTypeRef "[!"node:ref(J1939NmRxPdu/J1939NmRxPduRef)/MetaDataTypeRef"!]" exist for the reference EcuC Pdu "[!"node:name(as:ref(J1939NmRxPdu/J1939NmRxPduRef))"!]" of J1939NmRxPdu "[!"as:name(J1939NmRxPdu)"!]".[!ENDERROR!]
    [!ENDIF!]

  [!ELSE!]
    [!ERROR!] MetaDataItem shall be configured for the reference EcuC Pdu "[!"node:name(as:ref(J1939NmRxPdu/J1939NmRxPduRef))"!]" of J1939NmRxPdu "[!"as:name(J1939NmRxPdu)"!]".[!ENDERROR!]
  [!ENDIF!]
  [!IF "node:exists(node:ref(J1939NmRxPdu/J1939NmRxPduRef)/PduId)"!]
    [!"node:ref(J1939NmRxPdu/J1939NmRxPduRef)/PduId"!]
  [!ELSE!]
    [!ERROR!]PduId shall be configured for each EcuC Pdu referenced in J1939NmRxPduRef [!ENDERROR!]
  [!ENDIF!]
  },

  [!LOOP "node:order(../../J1939NmNode/*, 'J1939NmNodeId')"!]
    [!VAR "NodeId"= "J1939NmNodeId"!]
    [!LOOP "node:order(J1939NmNodeChannelRef/*)"!]
      [!IF "$ChannelName = name(as:ref(.))"!]
      [!VAR "NodeCounter"= "$NodeCounter + 1"!]
      [!ENDIF!]
    [!ENDLOOP!]
  [!ENDLOOP!]
  [!"num:i($NodeCounter)"!]U, /* Number of Nodes in this Channel ([!"$ChannelName"!]) */
  [!WS "2"!][!IF "text:tolower(J1939NmChannelUsesAddressArbitration) = 'true'"!]TRUE,[!ELSE!]FALSE,[!ENDIF!]  /* Enable/Disable J1939NmChannelUsesAddressArbitration */
[!IF "$J1939NmDemEventRefCount != 0"!]
  /* Dem Event Configurartion */
  [!LOOP "node:order(J1939NmNodeSpecificDemEventParameterRefs/*)"!]
     [!VAR "DemEventCounter"= "$DemEventCounter + 1"!]
  [!ENDLOOP!]
  [!"num:i($DemEventCounter)"!]U, /* Number of Dem Events in this Channel ([!"$ChannelName"!]) */

  [!IF "($DemEventCounter != '0')"!]
  &[!"(@name)"!]_DemEvent[0],
  [!ELSE!]
  NULL_PTR, /*Dem Events are not configured for this Channel ([!"$ChannelName"!]) */
  [!ENDIF!]
[!ENDIF!]
 }, /* End of Channel ([!"$ChannelName"!]) */
[!ENDLOOP!]
};


#define J1939NM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <J1939Nm_MemMap.h>

#define J1939NM_START_SEC_VAR_INIT_8
#include <J1939Nm_MemMap.h>

static VAR(uint8, J1939NM_VAR) J1939Nm_TransmissionPending = {J1939NM_NO_TRANSMISSION_PENDING};

#define J1939NM_STOP_SEC_VAR_INIT_8
#include <J1939Nm_MemMap.h>

#define J1939NM_START_SEC_CONST_8
#include <J1939Nm_MemMap.h>

CONST(uint8, J1939NM_CONST) J1939Nm_ComMChannelIDs[J1939NM_NUMBER_OF_COMM_CHANNELS] =
{
[!LOOP "node:order(J1939NmChannel/*)"!]
[!VAR "ComMChannelIdValue" = "(as:ref(J1939NmComMNetworkHandleRef)/ComMChannelId)"!]
  [!"$ComMChannelIdValue"!]U, /* Reference to [!"@name"!] ID */
[!ENDLOOP!]
};

CONST(uint8, J1939NM_CONST) J1939Nm_J1939TxPduIDs[J1939NM_NUMBER_OF_CHANNELS] =
{
[!LOOP "node:order(J1939NmChannel/*)"!]
  J1939NmConf_J1939NmTxPdu_[!"node:ref(J1939NmTxPdu/J1939NmTxPduRef)/@name"!],
[!ENDLOOP!]
};

CONST(uint8, J1939NM_CONST) J1939Nm_J1939RxPduIDs[J1939NM_NUMBER_OF_CHANNELS] =
{
[!LOOP "node:order(J1939NmChannel/*)"!]
  J1939NmConf_J1939NmRxPdu_[!"node:ref(J1939NmRxPdu/J1939NmRxPduRef)/@name"!],
[!ENDLOOP!]
};

[!LOOP "node:order(J1939NmNode/*, 'J1939NmNodeId')"!]
[!VAR "NameArray_0" = "bit:and(J1939NmNodeNameIdentityNumber,$ValueFFtoInt)"!]
[!VAR "NameArray_1" = "bit:and(bit:shr(J1939NmNodeNameIdentityNumber, 8), $ValueFFtoInt)"!]
[!VAR "NameArray_2" = "bit:or((bit:and(bit:shl(J1939NmNodeNameManufacturerCode, 5), $ValueE0toInt)), (bit:and(bit:shr(J1939NmNodeNameIdentityNumber, 16), $Value1FtoInt)))"!]
[!VAR "NameArray_3" = "bit:shr(J1939NmNodeNameManufacturerCode, 3)"!]
[!VAR "NameArray_4" = "bit:or((bit:shl(J1939NmNodeNameFunctionInstance, 3)), (bit:and((J1939NmNodeNameECUInstance), (7))))"!]
[!VAR "NameArray_5" = "J1939NmNodeNameFunction"!]
[!VAR "NameArray_6" = "bit:shl(J1939NmNodeNameVehicleSystem, 1)"!]
[!IF "J1939NmNodeNameArbitraryAddressCapable = 'true'"!]
  [!VAR "NameArray_7" = "bit:or((bit:or((bit:and(bit:shl(J1939NmNodeNameIndustryGroup, 4), $Value70toInt)), (bit:and(J1939NmNodeNameVehicleSystemInstance, $Value0FtoInt)))), ($Value80toInt))"!]
[!ELSE!]
  [!VAR "NameArray_7" = "bit:and((bit:or((bit:and(bit:shl(J1939NmNodeNameIndustryGroup, 4), $Value70toInt)), (bit:and(J1939NmNodeNameVehicleSystemInstance, $Value0FtoInt)))), ($Value7FtoInt))"!]
[!ENDIF!]
/* NAME Array for each Node */
static CONST(uint8, J1939NM_CONST) [!"(@name)"!]_NAME[8] =
{
  [!"$NameArray_0"!]U, /* Identity number */
  [!"$NameArray_1"!]U, /* Identity number */
  [!"$NameArray_2"!]U, /* Manufacturer code and Identity number */
  [!"$NameArray_3"!]U, /* Manufacturer code */
  [!"$NameArray_4"!]U, /* Function instance and ECU instance */
  [!"$NameArray_5"!]U, /* Function */
  [!"$NameArray_6"!]U, /* Vehicle System and Reserved */
  [!"$NameArray_7"!]U, /* Arbitrary Address Capable, Industry Group and Vehicle System Instance */
};
[!ENDLOOP!]

#define J1939NM_STOP_SEC_CONST_8
#include <J1939Nm_MemMap.h>

#define J1939NM_START_SEC_VAR_INIT_UNSPECIFIED
#include <J1939Nm_MemMap.h>

static VAR(J1939Nm_NodeDescriptorType, J1939NM_VAR) J1939Nm_CasNodeDescriptor[J1939NM_NUMBER_OF_NODES] =
{
[!LOOP "node:order(J1939NmNode/*, 'J1939NmNodeId')"!]
[!VAR "NodePrefAddr" = "J1939NmNodePreferredAddress"!]
 {
  [!"J1939NmNodeId"!]U, /* ID */
  [!"@name"!]_NAME, /* NAME */
  [!"$NodePrefAddr"!]U, /* Source Address */
[!IF "(J1939NmNodeStartUpDelay = 'true')"!]
 [!IF "($NodePrefAddr <= 127 ) or (($NodePrefAddr >= 248) and ($NodePrefAddr >= 253))"!]
  (uint8) FALSE, /* StartUp delay */
 [!ELSE!]
  (uint8) TRUE, /* StartUp delay */
 [!ENDIF!]
[!ELSE!][!AUTOSPACING!]
  (uint8) FALSE, /* StartUp delay */
[!ENDIF!]
 },
[!ENDLOOP!]
};

#define J1939NM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <J1939Nm_MemMap.h>

[!ENDSELECT!][!//

#define J1939NM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <J1939Nm_MemMap.h>

/* Main configuration structure to access PS structures */
/* !LINKSTO J1939Nm.dsn.PrecompileTimeConfig,1 */
CONST(J1939Nm_DescriptorType, J1939NM_CONST) J1939Nm_DescriptorConfiguration =
{
  J1939Nm_CasChannelConfig,
  J1939Nm_CasNodeDescriptor,
  &J1939Nm_TransmissionPending
};

[!IF "node:exists(J1939NmGeneral/J1939NmUserCallout)"!]
/* Pointer to J1939Nm Callout function */
CONST(J1939Nm_CalloutFunctionPointerType, J1939NM_CONST) J1939NmCalloutFunctionPtr  = &[!"J1939NmGeneral/J1939NmUserCallout"!];
[!ENDIF!]

#define J1939NM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <J1939Nm_MemMap.h>

/*==================[end of file]============================================*/
[!ENDCODE!]
