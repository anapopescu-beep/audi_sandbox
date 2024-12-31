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
/* This file generated from the configuration of J1939Nm module . */

[!CODE!]
[!INCLUDE "J1939Nm_Vars.m"!][!//
#ifndef J1939NM_CFG_H
#define J1939NM_CFG_H
[!//
/*==================[includes]===============================================*/

/* !LINKSTO SWS_J1939Nm_00001.1,1*/
#include <J1939Nm_Types.h>
#include <J1939Nm_Externals.h>
/*==================[macros]=================================================*/

#if (defined J1939NM_NUMBER_OF_CHANNELS)
#error J1939NM_NUMBER_OF_CHANNELS already defined
#endif
/** \brief Switch, indicating Total Number of Channels */
#define J1939NM_NUMBER_OF_CHANNELS      [!"$J1939NmMaxChannel"!]U

#if (defined J1939NM_NUMBER_OF_COMM_CHANNELS)
#error J1939NM_NUMBER_OF_COMM_CHANNELS already defined
#endif
/** \brief Switch, indicating Total Number of J1939Nm Channels mapped to ComM Channels */
#define J1939NM_NUMBER_OF_COMM_CHANNELS       [!"num:integer($J1939NmChannelMapToComMChannel)"!]U

#if (defined J1939NM_DEV_ERROR_DETECT)
#error J1939NM_DEV_ERROR_DETECT already defined
#endif
/** \brief Switch, indicating whether the Development Error Detect is Enabled or Not */
#define J1939NM_DEV_ERROR_DETECT          [!//
STD_[!IF "text:tolower(J1939NmGeneral/J1939NmDevErrorDetect) = 'true'"!]ON[!ELSE!]OFF[!ENDIF!]

#if (defined J1939NM_VERSION_INFO_API)
#error J1939NM_VERSION_INFO_API already defined
#endif
/** \brief Switch, indicating whether API version information is
 ** activated or deactivated  for J1939Nm */
#define J1939NM_VERSION_INFO_API          [!//
STD_[!IF "text:tolower(J1939NmGeneral/J1939NmVersionInfoApi) = 'true'"!]ON[!ELSE!]OFF[!ENDIF!]

#if (defined J1939NM_NUMBER_OF_NODECHANNELS)
#error J1939NM_NUMBER_OF_NODECHANNELS already defined
#endif
/** \brief Switch, indicating the total number of Nodes configured for different
 ** channels(NodeChannels) */
#define J1939NM_NUMBER_OF_NODECHANNELS    [!"num:integer($J1939NmMaxNodeChannels)"!]U

/*------------------[symbolic name values]----------------------------------*/
[!VAR "ConfigIndex" = "'0'"!]
[!SELECT "(node:order(J1939NmConfigSet/*))"!][!//

  [!LOOP "node:order(J1939NmNode/*)"!]
    [!VAR "SymbolName" = "@name"!]

#if (defined J1939NmConf_J1939NmNode_[!"$SymbolName"!])
#error J1939NmConf_J1939NmNode_[!"$SymbolName"!] already defined
#endif
/** \brief Symbolic name value of the Node Id.*/
#define J1939NmConf_J1939NmNode_[!"$SymbolName"!]        [!"J1939NmNodeId"!]U
  [!ENDLOOP!]

  [!LOOP "node:order(J1939NmChannel/*)"!]
    [!VAR "SymbolName_Tx" = "node:ref(J1939NmTxPdu/J1939NmTxPduRef)/@name"!]
    [!VAR "SymbolName_Rx" = "node:ref(J1939NmRxPdu/J1939NmRxPduRef)/@name"!]

#if (defined J1939NmConf_J1939NmNode_[!"$SymbolName_Tx"!])
#error J1939NmConf_J1939NmTxPdu_[!"$SymbolName_Tx"!] already defined
#endif
/** \brief Symbolic name value of the Handle ID for Tx
 ** This Handle ID must be used by the underlying communication layer after the J1939Nm requested a
 ** transmission.
 **/
#define J1939NmConf_J1939NmTxPdu_[!"$SymbolName_Tx"!]     [!"J1939NmTxPdu/J1939NmTxPduId"!]U

#if (defined J1939NmConf_J1939NmRxPdu_[!"$SymbolName_Rx"!])
#error J1939NmConf_J1939NmRxPdu_[!"$SymbolName_Rx"!] already defined
#endif
/** \brief Symbolic name value of the Handle ID for reception.*/
#define J1939NmConf_J1939NmRxPdu_[!"$SymbolName_Rx"!]     [!"J1939NmRxPdu/J1939NmRxPduId"!]U
  [!ENDLOOP!]

[!VAR "ConfigIndex" = "num:i($ConfigIndex + 1)"!]
[!ENDSELECT!][!//

#if (defined J1939NM_USER_CALLOUT)
#error J1939NM_USER_CALLOUT already defined
#endif
/** \brief Switch, indicating whether User call-out is
 ** activated or deactivated  for J1939Nm */
#define J1939NM_USER_CALLOUT          [!//
STD_[!IF "node:exists(J1939NmGeneral/J1939NmUserCallout)"!]ON[!ELSE!]OFF[!ENDIF!]

#if (defined J1939NM_DELAY_TICK_PERIOD)
#error J1939NM_DELAY_TICK_PERIOD already defined
#endif
/** \brief Switch, indicating the delay time in milliseconds */
#define J1939NM_DELAY_TICK_PERIOD         [!"num:integer($J1939NmBusOffDelayTickPeriod)"!]U

#if (defined J1939NM_MAIN_FUNC_PERIOD)
#error J1939NM_MAIN_FUNC_PERIOD already defined
#endif
/** \brief Switch, indicating the Main function period in milliseconds */
#define J1939NM_MAIN_FUNC_PERIOD         [!"num:integer($J1939NmMainFunctionPeriod)"!]U

#if (defined J1939NM_CLAIMING_PERIOD)
#error J1939NM_CLAIMING_PERIOD already defined
#endif
/** \brief Switch, indicating the Claiming of NodeChannel to 250 milliseconds */
#define J1939NM_CLAIMING_PERIOD         250U


#if (defined J1939NM_DEM_ENABLED)
#error J1939NM_DEM_ENABLED already defined
#endif
/** \brief Switch, indicating whether DEM handling is enabled or not */
#define J1939NM_DEM_ENABLED          [!//
STD_[!IF "$J1939NmDemEventRefCount != 0"!]ON[!ELSE!]OFF[!ENDIF!]

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

#define J1939NM_START_SEC_CONST_8
#include <J1939Nm_MemMap.h>

extern CONST(uint8, J1939NM_CONST) J1939Nm_ComMChannelIDs[J1939NM_NUMBER_OF_COMM_CHANNELS];
extern CONST(uint8, J1939NM_CONST) J1939Nm_J1939TxPduIDs[J1939NM_NUMBER_OF_CHANNELS];
extern CONST(uint8, J1939NM_CONST) J1939Nm_J1939RxPduIDs[J1939NM_NUMBER_OF_CHANNELS];

#define J1939NM_STOP_SEC_CONST_8
#include <J1939Nm_MemMap.h>

#define J1939NM_START_SEC_CONST_UNSPECIFIED
#include <J1939Nm_MemMap.h>

extern CONST(J1939Nm_DescriptorType, J1939NM_CONST) J1939Nm_DescriptorConfiguration;
[!IF "node:exists(J1939NmGeneral/J1939NmUserCallout)"!]
/* Pointer to J1939Nm Callout function */
extern CONST(J1939Nm_CalloutFunctionPointerType, J1939NM_CONST) J1939NmCalloutFunctionPtr;
[!ENDIF!]

#define J1939NM_STOP_SEC_CONST_UNSPECIFIED
#include <J1939Nm_MemMap.h>

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef J1939NM_CFG_H */
/*==================[end of file]============================================*/
[!ENDCODE!]
