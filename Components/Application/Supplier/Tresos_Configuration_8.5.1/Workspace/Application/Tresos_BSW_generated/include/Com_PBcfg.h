
/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef COM_PBCFG_H
#define COM_PBCFG_H



/*==================[inclusions]=============================================*/

#include <Com_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <Com_Types.h>
#include <Platform_Types.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS COM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined ComConfig) /* To prevent double definition */
#error ComConfig already defined
#endif /* (defined ComConfig) */

#define ComConfig (Com_ConfigLayout.Com_RootConfig)



/*==================[type definitions]=======================================*/

typedef struct /* Com_ConfigLayoutType */ {
    VAR( Com_ConfigType, TYPEDEF ) Com_RootConfig;
    VAR( ComRxIPduType, TYPEDEF ) ComRxIPdu[4];
    VAR( ComTxIPduType, TYPEDEF ) ComTxIPdu[5];
    VAR( ComTxSignalGroupType, TYPEDEF ) ComTxSignalGroup[3];
    VAR( ComTxModeNTimesType, TYPEDEF ) ComTxModeNTimes[1];
    VAR( ComTxModePeriodicType, TYPEDEF ) ComTxModePeriodic[1];
    VAR( ComSignalGroupRefType, TYPEDEF ) ComRxIPduSignalGroupList[1];
    VAR( ComSignalGroupRefType, TYPEDEF ) ComTxIPduSignalGroupList[3];
    VAR( ComSignalRefType, TYPEDEF ) ComRxIPduSignalList[43];
    VAR( ComSignalRefType, TYPEDEF ) ComTxIPduSignalList[22];
    VAR( ComRxSignalGroupType, TYPEDEF ) ComRxSignalGroup[1];
    VAR( ComRxSignalType, TYPEDEF ) ComRxSignal[51];
    VAR( ComRxSignalExtType, TYPEDEF ) ComRxSignalExt[44];
    VAR( ComTxSignalType, TYPEDEF ) ComTxSignal[46];
    VAR( Com_CbkRxTOutIdxType, TYPEDEF ) ComRxTimeoutNotificationList[43];
    VAR( ComIPduRefType, TYPEDEF ) ComPeriodicQueueList[1];
    VAR( ComIPduRefType, TYPEDEF ) ComNTimesQueueList[4];
    VAR( ComIPduRefType, TYPEDEF ) ComRxTimeoutQueueList[3];
    VAR( ComIPduRefType, TYPEDEF ) ComCbkTxAckDeferredList[1];
    VAR( ComIPduGroupMaskType, TYPEDEF ) ComIPduGroupMask[12];
    VAR( ComFilter8BitMaskXMinMaxType, TYPEDEF ) ComFilter8BitMaskXMinMax[1];
    VAR( uint8, TYPEDEF ) ComIPduInit[96];
} Com_ConfigLayoutType;

typedef CONST( Com_ConfigLayoutType, TYPEDEF ) Com_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <Com_MemMap.h>

extern Com_ConstConfigLayoutType Com_ConfigLayout;

#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <Com_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* COM_PBCFG_H */

/*==================[end of file]============================================*/

