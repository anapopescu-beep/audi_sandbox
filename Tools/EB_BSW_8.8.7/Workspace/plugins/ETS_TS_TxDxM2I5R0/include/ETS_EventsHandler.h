#ifndef ETS_EVENTSHANDLER_H
#define ETS_EVENTSHANDLER_H
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

#include "Std_Types.h"
#include "ETS_Types.h"
#include "ETS_Macros.h"

/*==================[macros]======================================================================*/

/*==================[type definitions]============================================================*/

typedef P2FUNC(void, TYPEDEF, ETS_Event_Action)(void);

/*==================[external function declarations]==============================================*/

#define ETS_START_SEC_CODE
#include <ETS_MemMap.h>

FUNC(void, RTE_CODE) ETS_SetTimer(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event, ETS_TimeType start, ETS_TimeType cycle, ETS_TimeType duration);
FUNC(void, RTE_CODE) ETS_ResetTimer(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event);
FUNC(void, RTE_CODE) ETS_CheckEvent(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event);

#define ETS_STOP_SEC_CODE
#include <ETS_MemMap.h>

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* ETS_EVENTSHANDLER_H */

/*==================[end of file]=================================================================*/

