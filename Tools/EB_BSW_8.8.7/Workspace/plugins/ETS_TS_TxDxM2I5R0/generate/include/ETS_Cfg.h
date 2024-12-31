#ifndef ETS_CFG_H
#define ETS_CFG_H

/**
 * \file
 *
 * \brief AUTOSAR ETS
 *
 * This file contains the implementation of the AUTOSAR
 * module ETS.
 *
 * \version 2.5.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[includes]====================================================================*/

#include <Rte_ETS.h>

/*==================[macros]======================================================================*/

#define ETS_MAINFUNCTION_CYCLE_MS [!"num:f(General/MainFunctionPeriod)"!]
[!IF "General/ETS_EnableDET = 'true'"!][!//
#define ETS_DEV_ERROR_DETECT      STD_ON
[!ELSE!][!//
#define ETS_DEV_ERROR_DETECT      STD_OFF
[!ENDIF!][!//

#define ETS_TICKS_PER_SECOND 50U

[!VAR "Num_Of_ETS_Events" = "0"!]

/* Echoes */

/** \brief Defines if reporting echoUint8 test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoUINT8 = 'true'"!][!//
#define ETS_Echo_UINT8      STD_ON
[!ELSE!][!//
#define ETS_Echo_UINT8      STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoInt8 test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoINT8 = 'true'"!][!//
#define ETS_Echo_INT8       STD_ON
[!ELSE!][!//
#define ETS_Echo_INT8       STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoCommonDatatypes test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoCommonDatatypes = 'true'"!][!//
#define ETS_Echo_CommonDatatypes       STD_ON
[!ELSE!][!//
#define ETS_Echo_CommonDatatypes       STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoUINT64 test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoUINT64 = 'true'"!][!//
#define ETS_Echo_UINT64                STD_ON
[!ELSE!][!//
#define ETS_Echo_UINT64                STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoENUM test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoENUM = 'true'"!][!//
#define ETS_Echo_ENUM                  STD_ON
[!ELSE!][!//
#define ETS_Echo_ENUM                  STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoUINT8Array test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoUINT8Array = 'true'"!][!//
#define ETS_Echo_UINT8Array            STD_ON
[!ELSE!][!//
#define ETS_Echo_UINT8Array            STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoStaticUINT8Array test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoStaticUINT8Array = 'true'"!][!//
#define ETS_Echo_StaticUINT8Array      STD_ON
[!ELSE!][!//
#define ETS_Echo_StaticUINT8Array      STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoBitfields test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoBitfields = 'true'"!][!//
#define ETS_Echo_Bitfields             STD_ON
[!ELSE!][!//
#define ETS_Echo_Bitfields             STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoTYPEDEF test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoTYPEDEF = 'true'"!][!//
#define ETS_Echo_TYPEDEF               STD_ON
[!ELSE!][!//
#define ETS_Echo_TYPEDEF               STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoUINT8Array16BitLength test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoUINT8Array16BitLength = 'true'"!][!//
#define ETS_Echo_UINT8Array16Bitlength STD_ON
[!ELSE!][!//
#define ETS_Echo_UINT8Array16Bitlength STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoInt64 test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoInt64 = 'true'"!][!//
#define ETS_Echo_INT64                 STD_ON
[!ELSE!][!//
#define ETS_Echo_INT64                 STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoFLOAT64 test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoFLOAT64 = 'true'"!][!//
#define ETS_Echo_FLOAT64               STD_ON
[!ELSE!][!//
#define ETS_Echo_FLOAT64               STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoUINT8E2E test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoUINT8E2E = 'true'"!][!//
#define ETS_Echo_UINT8E2E              STD_ON
[!ELSE!][!//
#define ETS_Echo_UINT8E2E              STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoUINT8RELIABLE test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoUINT8RELIABLE = 'true'"!][!//
#define ETS_Echo_UINT8RELIABLE         STD_ON
[!ELSE!][!//
#define ETS_Echo_UINT8RELIABLE         STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoSTRUCTSimple test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoSTRUCTSimple = 'true'"!][!//
#define ETS_Echo_STRUCTSimple          STD_ON
[!ELSE!][!//
#define ETS_Echo_STRUCTSimple          STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoUINT8Array8BitLength test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoUINT8Array8BitLength = 'true'"!][!//
#define ETS_Echo_UINT8Array8BitLength  STD_ON
[!ELSE!][!//
#define ETS_Echo_UINT8Array8BitLength  STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoUINT8ArrayMinSize test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoUINT8ArrayMinSize = 'true'"!][!//
#define ETS_Echo_UINT8ArrayMinSize     STD_ON
[!ELSE!][!//
#define ETS_Echo_UINT8ArrayMinSize     STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoUINT8Array2Dim test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoUINT8Array2Dim = 'true'"!][!//
#define ETS_Echo_UINT8Array2Dim        STD_ON
[!ELSE!][!//
#define ETS_Echo_UINT8Array2Dim        STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoUNION test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoUNION = 'true'"!][!//
#define ETS_Echo_UNION                 STD_ON
[!ELSE!][!//
#define ETS_Echo_UNION                 STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoUTF8FIXED test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoUTF8FIXED = 'true'"!][!//
#define ETS_Echo_UTF8FIXED             STD_ON
[!ELSE!][!//
#define ETS_Echo_UTF8FIXED             STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting echoUTF16FIXED test functionality is enabled */
[!IF "EnhancedTestabilityService/EchoingDataTypes/echoUTF16FIXED = 'true'"!][!//
#define ETS_Echo_UTF16FIXED            STD_ON
[!ELSE!][!//
#define ETS_Echo_UTF16FIXED            STD_OFF
[!ENDIF!][!//

/* Fields */

/** \brief Defines if reporting InterfaceVersion test functionality is enabled */
[!IF "EnhancedTestabilityService/EventsAndFields/InterfaceVersion = 'true'"!][!//
#define ETS_Fields_InterfaceVersion     STD_ON
[!ELSE!][!//
#define ETS_Fields_InterfaceVersion     STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting TestFieldUINT8 test functionality is enabled */
[!IF "EnhancedTestabilityService/EventsAndFields/TestFieldUINT8 = 'true'"!][!//
#define ETS_Fields_TestFieldUINT8                STD_ON
[!ELSE!][!//
#define ETS_Fields_TestFieldUINT8                STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting TestFieldUINT8Array test functionality is enabled */
[!IF "EnhancedTestabilityService/EventsAndFields/TestFieldUINT8Array = 'true'"!][!//
#define ETS_Fields_TestFieldUINT8Array             STD_ON
[!ELSE!][!//
#define ETS_Fields_TestFieldUINT8Array             STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting TestFieldUINT8Reliable test functionality is enabled */
[!IF "EnhancedTestabilityService/EventsAndFields/TestFieldUINT8Reliable = 'true'"!][!//
#define ETS_Fields_TestFieldUINT8Reliable               STD_ON
[!ELSE!][!//
#define ETS_Fields_TestFieldUINT8Reliable               STD_OFF
[!ENDIF!][!//


/* Services */
/** \brief Defines if reporting checkByteOrder test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingClientInteraction/checkByteOrder = 'true'"!][!//
#define ETS_Service_CheckByteOrder                        STD_ON
[!ELSE!][!//
#define ETS_Service_CheckByteOrder                        STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting clientServiceActivate test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingClientInteraction/clientServiceActivate = 'true'"!][!//
[!VAR "Num_Of_ETS_Events" = "num:i($Num_Of_ETS_Events) + 1"!]
#define ETS_Service_ClientServiceActivate                 STD_ON
[!ELSE!][!//
#define ETS_Service_ClientServiceActivate                 STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting clientServiceCallEchoUINT8Array test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingClientInteraction/clientServiceCallEchoUINT8Array = 'true'"!][!//
#define ETS_Service_ClientServiceCallEchoUINT8Array       STD_ON
[!ELSE!][!//
#define ETS_Service_ClientServiceCallEchoUINT8Array       STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting clientServiceDeactivate test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingClientInteraction/clientServiceDeactivate = 'true'"!][!//
[!VAR "Num_Of_ETS_Events" = "num:i($Num_Of_ETS_Events) + 1"!]
#define ETS_Service_ClientServiceDeactivate               STD_ON
[!ELSE!][!//
#define ETS_Service_ClientServiceDeactivate               STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting clientServiceGetLastValueOfEventTCP test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingClientInteraction/clientServiceGetLastValueOfEventTCP = 'true'"!][!//
#define ETS_Service_ClientServiceGetLastValueOfEventTCP   STD_ON
[!ELSE!][!//
#define ETS_Service_ClientServiceGetLastValueOfEventTCP   STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting clientServiceGetLastValueOfEventUDPMulticast test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingClientInteraction/clientServiceGetLastValueOfEventUDPMulticast = 'true'"!][!//
#define ETS_Service_ClientServiceGetLastValueOfEventUDPMulticast       STD_ON
[!ELSE!][!//
#define ETS_Service_ClientServiceGetLastValueOfEventUDPMulticast       STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting clientServiceGetLastValueOfEventUDPUnicast test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingClientInteraction/clientServiceGetLastValueOfEventUDPUnicast = 'true'"!][!//
#define ETS_Service_ClientServiceGetLastValueOfEventUDPUnicast         STD_ON
[!ELSE!][!//
#define ETS_Service_ClientServiceGetLastValueOfEventUDPUnicast         STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting clientServiceSubscribeEventgroup test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingClientInteraction/clientServiceSubscribeEventgroup = 'true'"!][!//
[!VAR "Num_Of_ETS_Events" = "num:i($Num_Of_ETS_Events) + 1"!]
#define ETS_Service_ClientServiceSubscribeEventgroup                   STD_ON
[!ELSE!][!//
#define ETS_Service_ClientServiceSubscribeEventgroup                   STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting resetInterface test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingClientInteraction/resetInterface = 'true'"!][!//
#define ETS_Service_ResetInterface                                     STD_ON
[!ELSE!][!//
#define ETS_Service_ResetInterface                                     STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting suspendInterface test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingClientInteraction/suspendInterface = 'true'"!][!//
#define ETS_Service_SuspendInterface                                   STD_ON
[!ELSE!][!//
#define ETS_Service_SuspendInterface                                   STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting triggerEventUINT8 test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingEvents/triggerEventUINT8 = 'true'"!][!//
[!VAR "Num_Of_ETS_Events" = "num:i($Num_Of_ETS_Events) + 1"!]
#define ETS_Service_TriggerEventUINT8                                  STD_ON
[!ELSE!][!//
#define ETS_Service_TriggerEventUINT8                                  STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting triggerEventUINT8Reliable test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingEvents/triggerEventUINT8Reliable = 'true'"!][!//
[!VAR "Num_Of_ETS_Events" = "num:i($Num_Of_ETS_Events) + 1"!]
#define ETS_Service_TriggerEventUINT8Reliable                          STD_ON
[!ELSE!][!//
#define ETS_Service_TriggerEventUINT8Reliable                          STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting triggerEventUINT8Array test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingEvents/triggerEventUINT8Array = 'true'"!][!//
[!VAR "Num_Of_ETS_Events" = "num:i($Num_Of_ETS_Events) + 1"!]
#define ETS_Service_TriggerEventUINT8Array                             STD_ON
[!ELSE!][!//
#define ETS_Service_TriggerEventUINT8Array                             STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting triggerEventUINT8E2E test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingEvents/triggerEventUINT8E2E = 'true'"!][!//
[!VAR "Num_Of_ETS_Events" = "num:i($Num_Of_ETS_Events) + 1"!]
#define ETS_Service_TriggerEventUINT8E2E                               STD_ON
[!ELSE!][!//
#define ETS_Service_TriggerEventUINT8E2E                               STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting triggerEventUINT8Multicast test functionality is enabled */
[!IF "EnhancedTestabilityService/TestingEvents/triggerEventUINT8Multicast = 'true'"!][!//
[!VAR "Num_Of_ETS_Events" = "num:i($Num_Of_ETS_Events) + 1"!]
#define ETS_Service_TriggerEventUINT8Multicast                         STD_ON
[!ELSE!][!//
#define ETS_Service_TriggerEventUINT8Multicast                         STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting TestEventUINT8 test functionality is enabled */
[!IF "EnhancedTestabilityService/EventsAndFields/TestEventUINT8 = 'true'"!][!//
#define ETS_Service_TestEventUINT8                       STD_ON
[!ELSE!][!//
#define ETS_Service_TestEventUINT8                       STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting TestEventUINT8Reliable test functionality is enabled */
[!IF "EnhancedTestabilityService/EventsAndFields/TestEventUINT8Reliable = 'true'"!][!//
#define ETS_Service_TestEventUINT8Reliable               STD_ON
[!ELSE!][!//
#define ETS_Service_TestEventUINT8Reliable               STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting TestEventUINT8Array test functionality is enabled */
[!IF "EnhancedTestabilityService/EventsAndFields/TestEventUINT8Array = 'true'"!][!//
#define ETS_Service_TestEventUINT8Array                  STD_ON
[!ELSE!][!//
#define ETS_Service_TestEventUINT8Array                  STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting TestEventUINT8E2E test functionality is enabled */
[!IF "EnhancedTestabilityService/EventsAndFields/TestEventUINT8E2E = 'true'"!][!//
#define ETS_Service_TestEventUINT8E2E                    STD_ON
[!ELSE!][!//
#define ETS_Service_TestEventUINT8E2E                    STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting TestEventUINT8Multicast test functionality is enabled */
[!IF "EnhancedTestabilityService/EventsAndFields/TestEventUINT8Multicast = 'true'"!][!//
#define ETS_Service_TestEventUINT8Multicast              STD_ON
[!ELSE!][!//
#define ETS_Service_TestEventUINT8Multicast              STD_OFF
[!ENDIF!][!//

/** \brief Defines if reporting ProjectSpecificTests test functionality is enabled */
[!IF "ProjectSpecificTests/ProjectSpecific_test/ActivateTest = 'true'"!][!//
#define ETS_ProjectSpecificTest STD_ON
[!ELSE!][!//
#define ETS_ProjectSpecificTest STD_OFF
[!ENDIF!][!//

/* Counted number of various ETS events */
#define NUM_OF_ETS_EVENTS            [!"num:i($Num_Of_ETS_Events)"!]U

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

#define ETS_START_SEC_CODE
#include <ETS_MemMap.h>



#define ETS_STOP_SEC_CODE
#include <ETS_MemMap.h>

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

#define ETS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <ETS_MemMap.h>



#define ETS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <ETS_MemMap.h>

/*================================================================================================*/

#endif /* #ifndef ETS_CFG_H */
