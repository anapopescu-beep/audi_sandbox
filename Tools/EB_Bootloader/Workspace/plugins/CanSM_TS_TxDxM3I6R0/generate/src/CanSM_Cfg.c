/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \version 3.6.25
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2020 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
[!INCLUDE "../include/CanSM_Macros.m"!][!//
[!AUTOSPACING!]

/*==================[inclusions]============================================*/

#include <CanSM_Trace.h>
#include <ComStack_Types.h>         /* AUTOSAR communication stack types */

#include <CanSM_Int_Stc.h>          /* Module internal static header */
#include <CanSM_Cfg.h>              /* Module configuration */
[!IF "$multiCoreSupport = 'true'"!]
#include <SchM_CanSM.h>
[!ENDIF!]

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/

#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanSM_MemMap.h>

[!IF "$numNetworks > 1"!]

[!IF "$nwHandlesConsecutive = 'false'"!]

/** \brief Network handles
 *
 * Used to translate network handles to network indices
 */
STATIC CONST(NetworkHandleType, CANSM_CONST) CanSM_NetworkHandles[CANSM_NETWORKS_NUM] =
{
[!INDENT "2"!]
  [!LOOP "node:order(CanSMConfiguration/*[1]/CanSMManagerNetwork/*,'as:ref(CanSMComMNetworkHandleRef)/ComMChannelId')"!]
    [!"num:i(as:ref(CanSMComMNetworkHandleRef)/ComMChannelId)"!]U,
  [!ENDLOOP!]
[!ENDINDENT!]
};

[!ENDIF!]

CONST(CanSM_NetworkConfigType, CANSM_APPL_CONST) CanSM_NetworkConfig[CANSM_NETWORKS_NUM] =
{
[!INDENT "2"!]
  [!LOOP "node:order(CanSMConfiguration/*[1]/CanSMManagerNetwork/*,'as:ref(CanSMComMNetworkHandleRef)/ComMChannelId')"!]
  {
    [!INDENT "4"!]
      [!IF "$nwSpecificBorTimeL1 = 'true'"!]
      [!CALL "CalcToTicks", "time"="CanSMBorTimeL1", "maxTicks"="65535"!]U, /* Duration to stay
              in level 1 check before restart of communication */
      [!// maxTicks covers CanSM.Design.20092
      [!ENDIF!][!//
      [!IF "$nwSpecificBorTimeL2 = 'true'"!]
      [!CALL "CalcToTicks", "time"="CanSMBorTimeL2", "maxTicks"="65535"!]U, /* Duration to stay
              in level 2 check before restart of communication */
      [!// maxTicks covers CanSM.Design.20092
      [!ENDIF!][!//
      [!IF "$nwSpecificBorTimeTxEnsured = 'true'"!]
      [!CALL "CalcToTicks", "time"="CanSMBorTimeTxEnsured", "maxTicks"="65534"!]U, /* Duration until
              bus-off free communication is assumed */
      [!// maxTicks covers CanSM.Design.20092
      [!ENDIF!][!//
      [!IF "$useDEM = 'true'"!]
      [!IF "node:exists(CanSMDemEventParameterRefs/CANSM_E_BUS_OFF)"!]
      [!"node:value(as:ref(CanSMDemEventParameterRefs/CANSM_E_BUS_OFF)/DemEventId)"!]U, /* DEM Event CANSM_E_BUS_OFF */
      [!ELSE!]
      CANSM_INVALID_DEM_EVENTID, /* Disabled DEM Event CANSM_E_BUS_OFF */
      [!ENDIF!]
      [!ENDIF!]
      [!IF "$singleControllers = 'true'"!]
        [!"num:i(as:ref(CanSMController/*[1]/CanSMControllerId)/CanIfCtrlId)"!]U, /* CAN Controller Id */
      [!ENDIF!]
      [!IF "$useTransceiver = 'true'"!]
        [!IF "node:exists(CanSMTransceiverId)"!]
          [!"num:i(as:ref(CanSMTransceiverId)/CanIfTrcvId)"!]U, /* CAN Transceiver Id */
        [!ELSE!]
          CANSM_TRANSCEIVER_ID_NONE, /* No transceiver for this network */
        [!ENDIF!]
      [!ENDIF!]
      [!IF "$nwSpecificBorCounterL1ToL2 = 'true'"!]
        [!"CanSMBorCounterL1ToL2"!]U, /* bus-off recovery L1 to L2 Threshold */
      [!ENDIF!]
      [!IF "$nwSpecificBorTxConfirmationPolling = 'true'"!]
        [!//
      [!IF "CanSMBorTxConfirmationPolling = 'true'"!][!//
      TRUE, [!//
      [!ELSE!][!//
      FALSE, [!//
      [!ENDIF!][!//
      /* bus-off recovery Tx Confirmation Polling */
      [!ENDIF!]
      [!IF "$globalPnSupport = 'true'"!]
       [!//
      [!IF "CanSMActivatePN = 'true'"!][!//
      TRUE,[!//
      [!ELSE!][!//
      FALSE,[!ENDIF!] /* partial networking */[!//
      [!ENDIF!]
      [!IF "$multiCoreSupport = 'true'"!][!//
      &SchM_Call_CanSM_RequiredCSEntry_ComM_BusSM_ModeIndication_[!"as:ref(CanSMComMNetworkHandleRef)/ComMChannelId"!], /* SchM function pointer */[!//
      [!ENDIF!][!//
    [!ENDINDENT!]
  },
  [!ENDLOOP!]
[!ENDINDENT!]
};

[!ELSE!]
/* If there is only one network, CanSM_NetworkConfig has only the SchM function pointer */
[!IF "$multiCoreSupport = 'true'"!]
CONST(CanSM_NetworkConfigType, CANSM_APPL_CONST) CanSM_NetworkConfig[CANSM_NETWORKS_NUM] =
{
[!INDENT "2"!]
  [!LOOP "node:order(CanSMConfiguration/*[1]/CanSMManagerNetwork/*,'as:ref(CanSMComMNetworkHandleRef)/ComMChannelId')"!]
  {
    [!INDENT "4"!]
      &SchM_Call_CanSM_RequiredCSEntry_ComM_BusSM_ModeIndication_[!"as:ref(CanSMComMNetworkHandleRef)/ComMChannelId"!],
    [!ENDINDENT!]
  },
  [!ENDLOOP!]
[!ENDINDENT!]
};
[!ENDIF!]

[!ENDIF!]

#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanSM_MemMap.h>



#define CANSM_START_SEC_CONFIG_DATA_8
#include <CanSM_MemMap.h>

/** \brief Empty configuration structure to be passed to CanSM_Init() */
CONST(CanSM_ConfigType, CANSM_APPL_CONST) [!"as:modconf('CanSM')[1]/CanSMConfiguration/*[1]/@name"!] = 0U;

[!IF "$singleControllers != 'true'"!]
CONST(uint8, CANSM_APPL_CONST) CanSM_CanNetworkControllersStart[CANSM_NETWORKS_NUM] =
{
[!INDENT "2"!]
  [!VAR "idx"="0"!]
  [!LOOP "node:order(CanSMConfiguration/*[1]/CanSMManagerNetwork/*,'as:ref(CanSMComMNetworkHandleRef)/ComMChannelId')"!]
    [!"num:i($idx)"!]U,
    [!VAR "idx"="$idx + count(CanSMController/*)"!]
  [!ENDLOOP!]
[!ENDINDENT!]
};

CONST(uint8, CANSM_APPL_CONST) CanSM_CanNetworkControllersNum[CANSM_NETWORKS_NUM] =
{
[!INDENT "2"!]
  [!LOOP "node:order(CanSMConfiguration/*[1]/CanSMManagerNetwork/*,'as:ref(CanSMComMNetworkHandleRef)/ComMChannelId')"!]
    [!"num:i(count(CanSMController/*))"!]U,
  [!ENDLOOP!]
[!ENDINDENT!]
};

CONST(uint8, CANSM_APPL_CONST) CanSM_CanNetworkControllersList[CANSM_CONTROLLERS_NUM] =
{
[!INDENT "2"!]
  [!LOOP "node:order(CanSMConfiguration/*[1]/CanSMManagerNetwork/*,'as:ref(CanSMComMNetworkHandleRef)/ComMChannelId')"!]
    [!LOOP "CanSMController/*"!]
      [!"num:i(as:ref(CanSMControllerId)/CanIfCtrlId)"!]U,
    [!ENDLOOP!]
  [!ENDLOOP!]
[!ENDINDENT!]
};
[!ENDIF!]

CONST(uint8, CANSM_APPL_CONST) CanSM_ControllerNetworkLut[CANSM_CONTROLLERS_ID_NUM] =
{
[!INDENT "2"!]
  [!/* create lookup table */!][!//
  [!FOR "I"="0" TO "$ctrlMax"!]
    [!VAR "found"="0"!]
    [!SELECT "CanSMConfiguration/*[1]/CanSMManagerNetwork/*/CanSMController/*[as:ref(CanSMControllerId)/CanIfCtrlId = $I]"!]
      [!CALL "getNwIdxByNwRef", "nwRef"="as:path(../..)"!]U,
      [!VAR "found"="1"!]
    [!ENDSELECT!]
    [!IF "$found = 0"!]
      [!WARNING!]CAN Controller with Id [!"num:i($I)"!] is not part of any CAN network.[!ENDWARNING!]
      [!"$numNetworks"!]U,
    [!ENDIF!]
  [!ENDFOR!]
[!ENDINDENT!]
};

[!IF "$useTransceiver = 'true'"!]
CONST(uint8, CANSM_APPL_CONST) CanSM_TrcvNetworkLut[CANSM_TRANSCEIVERS_ID_NUM] =
{
[!INDENT "2"!]
  [!/* create lookup table */!][!//
  [!FOR "I"="0" TO "$trcvMax"!]
    [!VAR "found"="0"!]
    [!SELECT "CanSMConfiguration/*[1]/CanSMManagerNetwork/*[node:exists(CanSMTransceiverId) and as:ref(CanSMTransceiverId)/CanIfTrcvId = $I]"!]
      [!CALL "getNwIdxByNwRef", "nwRef"="as:path(.)"!]U,
      [!VAR "found"="1"!]
    [!ENDSELECT!]
    [!IF "$found = 0"!]
      CANSM_NETWORKS_NUM, /* no transceiver */
    [!ENDIF!]
  [!ENDFOR!]
[!ENDINDENT!]
};
[!ENDIF!]

#define CANSM_STOP_SEC_CONFIG_DATA_8
#include <CanSM_MemMap.h>

/*==================[external data]=========================================*/

#define CANSM_START_SEC_VAR_CLEARED_8
#include <CanSM_MemMap.h>

VAR(uint8, CANSM_VAR) CanSM_CtrlModeIndication[CANSM_CONTROLLERS_ID_NUM];

#define CANSM_STOP_SEC_VAR_CLEARED_8
#include <CanSM_MemMap.h>

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanSM_MemMap.h>

VAR(CanSM_NetworkInfoType, CANSM_VAR) CanSM_NetworkInfo[CANSM_NETWORKS_NUM];

#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanSM_MemMap.h>

/*==================[external function definitions]=========================*/

[!IF "($numNetworks > 1) and ($nwHandlesConsecutive = 'false')"!]

#define CANSM_START_SEC_CODE
#include <CanSM_MemMap.h>

FUNC(CanSM_NetworkIndexType, CANSM_CODE) CanSM_GetNetworkIndexFromHandle(
  NetworkHandleType nw
)
{
  CanSM_NetworkIndexType nwidx = 0U;

  for (nwidx = 0U; nwidx < CANSM_NETWORKS_NUM; nwidx++)
  {
    if (nw == CanSM_NetworkHandles[nwidx])
    {
      break;
    }
  }

  return nwidx;
}

FUNC(NetworkHandleType, CANSM_CODE) CanSM_GetNetworkHandleFromIndex(
  CanSM_NetworkIndexType nwidx
)
{
  NetworkHandleType ret;

  ret = CanSM_NetworkHandles[nwidx];
  return ret;
}

FUNC(boolean, CANSM_CODE) CanSM_NetworkHandleIsValid(
  NetworkHandleType nw
)
{
  CanSM_NetworkIndexType nwidx = 0U;
  boolean ret;

  for (nwidx = 0U; nwidx < CANSM_NETWORKS_NUM; nwidx++)
  {
    if (nw == CanSM_NetworkHandles[nwidx])
    {
      break;
    }
  }

  ret = (uint8) ((nwidx == CANSM_NETWORKS_NUM) ? FALSE : TRUE);

  return ret;
}

#define CANSM_STOP_SEC_CODE
#include <CanSM_MemMap.h>

[!ENDIF!]

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/

