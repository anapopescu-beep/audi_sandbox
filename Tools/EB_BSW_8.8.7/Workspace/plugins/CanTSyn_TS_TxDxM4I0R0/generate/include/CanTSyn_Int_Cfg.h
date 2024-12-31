/**
 * \file
 *
 * \brief AUTOSAR CanTSyn
 *
 * This file contains the implementation of the AUTOSAR
 * module CanTSyn.
 *
 * \version 4.0.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
[!CODE!]
[!AUTOSPACING!]

#ifndef CANTSYN_INT_CFG_H
#define CANTSYN_INT_CFG_H

/*==================[inclusions]============================================*/
[!INCLUDE "CanTSyn_PrecompileMacros.m"!][!//
#include <CanTSyn_Int_Stc.h>     /* multicore types */

/*==================[macros]================================================*/
[!IF "$isMulticoreEnabled = 'true'"!]

[!CALL "numberOfEcuCPartitionsUsedByCanTSyn"!]
#if (defined CANTSYN_NUMBER_OF_PARTITIONS)
#error CANTSYN_NUMBER_OF_PARTITIONS is already defined.
#endif
/** \brief Total number of partitions */
#define CANTSYN_NUMBER_OF_PARTITIONS  [!"num:i($numberOfEcuCPartitionsUsedByCanTSyn)"!]U

[!CALL "isOnlyTimeDomainMFAllocUsed"!]
#if (defined CANTSYN_ISONLY_TIMEDOMAINMFALLOC_USED)
#error CANTSYN_ISONLY_TIMEDOMAINMFALLOC_USED is already defined.
#endif
/** \brief Checks if only time domain MF allocation is used or not */
#define CANTSYN_ISONLY_TIMEDOMAINMFALLOC_USED  STD_[!IF "$isOnlyTimeDomainMFAllocUsed = 'true'"!]ON[!ELSE!]OFF[!ENDIF!]

[!ELSE!]

#if (defined CANTSYN_NUMBER_OF_PARTITIONS)
#error CANTSYN_NUMBER_OF_PARTITIONS is already defined.
#endif
/** \brief Dummy number of partitions */
#define CANTSYN_NUMBER_OF_PARTITIONS  255U

[!ENDIF!]
#if (defined CANTSYN_MAX_TRANSMIT_RETRIES)
#error CANTSYN_MAX_TRANSMIT_RETRIES is already defined.
#endif
/** \brief Transmit retries support */
#define CANTSYN_MAX_TRANSMIT_RETRIES  STD_[!IF "(node:exists(as:modconf('CanTSyn')[1]/CanTSynGeneral/CanTSynMaxNumberOfTransmitRetries)) and (node:value(as:modconf('CanTSyn')[1]/CanTSynGeneral/CanTSynMaxNumberOfTransmitRetries) > '0')"!]ON[!ELSE!]OFF[!ENDIF!]

[!IF "node:exists(as:modconf('CanTSyn')[1]/CanTSynGeneral/CanTSynMaxNumberOfTransmitRetries)"!]
#if (defined CANTSYN_MAX_NUMBER_OF_TRANSMIT_RETRIES)
#error CANTSYN_MAX_NUMBER_OF_TRANSMIT_RETRIES is already defined.
#endif
/** \brief Max number of transmit retries */
#define CANTSYN_MAX_NUMBER_OF_TRANSMIT_RETRIES  [!"num:i(node:value(as:modconf('CanTSyn')[1]/CanTSynGeneral/CanTSynMaxNumberOfTransmitRetries))"!]U
[!ENDIF!]

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

#define CANTSYN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanTSyn_MemMap.h>

[!IF "$isMulticoreEnabled = 'true'"!]
[!CALL "CreatePartitionRefList"!]
[!VAR "lastPartitionRef"!][!ENDVAR!][!//
[!VAR "countPartitionsRefsEntries" = "count(text:order(text:split($PartitionsRefList, ';')))"!][!//
[!FOR "PartitionsRefsEntriesIndex" = "1" TO "$countPartitionsRefsEntries"!][!//
  [!VAR "partRefName" = "text:order(text:split($PartitionsRefList, ';'))[position() = number($PartitionsRefsEntriesIndex)]"!][!//
  [!VAR "ecucPartitionRefName" = "text:split($partRefName, ':')[1]"!][!//
    [!IF "not($lastPartitionRef = $ecucPartitionRefName)"!][!//
    [!CALL "GetNumberOfConnectedTimeDomains", "ecuCPartitionName" = "$ecucPartitionRefName"!][!//
/** \brief Function pointer list of all time domains which are connected to [!"$ecucPartitionRefName"!] partition */
extern CONST(uint16, CANTSYN_APPL_CONST) CanTSyn_[!"$ecucPartitionRefName"!]_TimeDomainsList[[!"num:i($connectedTimeDomainCounter)"!]];
    [!ENDIF!][!//
    [!VAR "lastPartitionRef" = "$ecucPartitionRefName"!][!//
[!ENDFOR!][!//

[!IF "$isMulticoreEnabled = 'true'"!]
[!IF "$isOnlyTimeDomainMFAllocUsed = 'false'"!][!//
  [!VAR "partitionRefName" = "concat('EcucPartition_',num:i($numberOfEcuCPartitionsUsedByCanTSyn - 1))"!][!//
  [!CALL "GetNumberOfTimeDomainsNotConnectedToAnyPartition"!][!//
/** \brief Function pointer list of all time domains which are not connected to any partition */
extern CONST(uint16, CANTSYN_APPL_CONST) CanTSyn_[!"$partitionRefName"!]_TimeDomainsList[[!"num:i($notConnectedTimeDomainCounter)"!]];
[!ENDIF!][!//

[!CALL "numberOfEcuCPartitionsUsedByCanTSyn"!][!//
/** \brief Array of structures which contain information related to each partition which is connected to CanTSyn time domains */
extern CONST(CanTSyn_PartitionCfgType, CANTSYN_APPL_CONST) CanTSyn_PartitionTimeDomainsList[[!"num:i($numberOfEcuCPartitionsUsedByCanTSyn)"!]];
[!ENDIF!][!//
[!ENDIF!]

#define CANTSYN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanTSyn_MemMap.h>

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define CANTSYN_START_SEC_CODE
#include <CanTSyn_MemMap.h>

/** \brief CanTSyn Rx main function
 **
 ** Processes TimeSlavePdus decoupled from the reception events
 **
 ** This function has to be called periodically by the BSW scheduler.
 **
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, CANTSYN_CODE) CanTSyn_MainFunction_Rx(uint8 partitionIdx);


/** \brief CanTSyn Tx main function
 **
 ** Processes TimeMasterPdus decoupled from the transmit confirmation events
 **
 ** This function has to be called by the BSW scheduler.
 **
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, CANTSYN_CODE) CanTSyn_MainFunction_Tx(uint8 partitionIdx);

#define CANTSYN_STOP_SEC_CODE
#include <CanTSyn_MemMap.h>


[!IF "$isMulticoreEnabled = 'true'"!]
[!CALL "createSlaveTimeDomainMFAlloc"!]
[!LOOP "text:split($createSlaveTimeDomainMFAlloc,';')"!]
  [!VAR "qName" = "text:split(.,':')[1]"!]
  [!VAR "partitionName" = "text:split(.,':')[2]"!]
  [!VAR "qName" = "concat('CanTSyn_', $MulticoreVendorID, '_', $partitionName, $qName)"!]
  
#ifndef RTE_SCHM_SWCBSW_[!"text:toupper($qName)"!]
#define RTE_SCHM_SWCBSW_[!"text:toupper($qName)"!]

#define CANTSYN_[!"$MulticoreVendorID"!]_[!"$partitionName"!]_START_SEC_CODE
#include <CanTSyn_[!"$MulticoreVendorID"!]_[!"$partitionName"!]_MemMap.h>

/** \brief CanTSyn Rx main function
 **
 ** Processes decoupled RxPdus
 **
 ** This function has to be called by a task controlled by the
 ** BSW scheduler.
 **
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, CANTSYN_[!"$MulticoreVendorID"!]_[!"$partitionName"!]_CODE) [!"$qName"!](void);

#define CANTSYN_[!"$MulticoreVendorID"!]_[!"$partitionName"!]_STOP_SEC_CODE
#include <CanTSyn_[!"$MulticoreVendorID"!]_[!"$partitionName"!]_MemMap.h>

#endif /* RTE_SCHM_SWCBSW_[!"text:toupper($qName)"!] */
[!ENDLOOP!][!//Rx


[!CALL "createMasterTimeDomainMFAlloc"!]
[!LOOP "text:split($createMasterTimeDomainMFAlloc,';')"!]
  [!VAR "qName" = "text:split(.,':')[1]"!]
  [!VAR "partitionName" = "text:split(.,':')[2]"!]
  [!VAR "qName" = "concat('CanTSyn_', $MulticoreVendorID, '_', $partitionName, $qName)"!]

#ifndef RTE_SCHM_SWCBSW_[!"text:toupper($qName)"!]
#define RTE_SCHM_SWCBSW_[!"text:toupper($qName)"!]

#define CANTSYN_[!"$MulticoreVendorID"!]_[!"$partitionName"!]_START_SEC_CODE
#include <CanTSyn_[!"$MulticoreVendorID"!]_[!"$partitionName"!]_MemMap.h>

/** \brief CanTSyn Tx main function
 **
 ** Performs the processes of the activities that are not directly initiated by
 ** the calls from CAN driver.
 **
 ** This function has to be called by a task controlled by the
 ** BSW scheduler.
 **
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, CANTSYN_[!"$MulticoreVendorID"!]_[!"$partitionName"!]_CODE) [!"$qName"!](void);
#define CANTSYN_[!"$MulticoreVendorID"!]_[!"$partitionName"!]_STOP_SEC_CODE
#include <CanTSyn_[!"$MulticoreVendorID"!]_[!"$partitionName"!]_MemMap.h>

#endif /* RTE_SCHM_SWCBSW_[!"text:toupper($qName)"!] */
[!ENDLOOP!][!//Tx
[!ENDIF!]



/*==================[internal function definitions]=========================*/
#endif /* ifndef CANTSYN_INT_CFG_H */
/*==================[end of file]============================================*/
[!ENDCODE!][!//

