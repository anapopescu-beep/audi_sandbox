#ifndef ETS_TRIGGERANDEVENTS_H
#define ETS_TRIGGERANDEVENTS_H
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
#include "ETS_Cfg.h"

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*==================[external function declarations]==============================================*/
#define ETS_START_SEC_CODE
#include <ETS_MemMap.h>

#if ( ETS_Service_TestEventUINT8 == TRUE )
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8(void);
#endif
#if ( ETS_Service_TestEventUINT8Reliable == TRUE )
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8Reliable(void);
#endif
#if ( ETS_Service_TestEventUINT8Array == TRUE )
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8Array(void);
#endif
#if ( ETS_Service_TestEventUINT8E2E == TRUE )
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8E2E(void);
#endif
#if ( ETS_Service_TestEventUINT8Multicast == TRUE )
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8Multicast(void);
#endif
#if ( ETS_Service_SuspendInterface == TRUE )
FUNC(void, RTE_CODE) ETS_Action_SuspendInterface(void);
FUNC(void, RTE_CODE) ETS_Action_ResumeInterface(void);
#endif
#if ( ETS_Service_ClientServiceActivate == TRUE )
FUNC(void, RTE_CODE) ETS_Action_ClientActivateInterface(void);
#endif
#if (ETS_Service_ClientServiceSubscribeEventgroup == STD_ON)
FUNC(void, RTE_CODE) ETS_Action_ClientSubscribeEventgroup(void);
FUNC(void, RTE_CODE) ETS_Action_ClientUnsubscribeEventgroup(void);
#endif
#if (ETS_Service_ClientServiceDeactivate == STD_ON)
FUNC(void, RTE_CODE) ETS_Action_ClientDeactivateInterface(void);
#endif

#define ETS_STOP_SEC_CODE
#include <ETS_MemMap.h>

#endif /* #ifndef ETS_TRIGGERANDEVENTS_H */
/*==================[end of file]=================================================================*/

