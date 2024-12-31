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

/* ==================[Includes]=============================================== */

#include <ETS_EventsHandler.h>
#include <ETS_Types.h>
#include <ETS_Cfg.h>
#include <Rte_ETS_Type.h>
#include <Rte_ETS.h>
#include <Std_Types.h>

/*===================[Declaration of internal functions]=======================*/

#define ETS_START_SEC_CODE
#include <ETS_MemMap.h>

#if ( NUM_OF_ETS_EVENTS > 0 )
STATIC FUNC(void, RTE_CODE) ETS_CallFctPtr(ETS_Event_Action fct);
STATIC FUNC(void, RTE_CODE) ETS_ReloadCycleTimer(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event);
STATIC FUNC(uint8, RTE_CODE) ETS_CheckTimerValue(P2VAR(ETS_TimeType, AUTOMATIC, RTE_APPL_DATA) timerValue);
STATIC FUNC(uint8, RTE_CODE) ETS_CheckStartTimer(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event);
STATIC FUNC(uint8, RTE_CODE) ETS_CheckDurationTimer(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event);
STATIC FUNC(uint8, RTE_CODE) ETS_CheckCycleTimer(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event);
#endif

/**
 * \brief Event EventUINT8 triggering.
 *
 * Checks non NULL pointer and after that call a void (void) function pointer.
 *
 * \param[in] fct Event action
 *
 * \return none
 *
 */
 #if ( NUM_OF_ETS_EVENTS > 0 )
STATIC FUNC(void, RTE_CODE) ETS_CallFctPtr(ETS_Event_Action fct)
{
  if(fct != NULL_PTR)
  {
    fct();
  }
}
#endif

/**
 * \brief Check timer value.
 *
 * Decrement Timer value.
 *
 * \param[out] timerValue ETS_TimeType type value
 *
 * \return function status (TRUE or FALSE).
 *
 */

/* !LINKSTO swdd.EB.ETS.TriggAndEvent.7, 1 */
#if ( NUM_OF_ETS_EVENTS > 0 )
STATIC FUNC(uint8, RTE_CODE) ETS_CheckTimerValue(P2VAR(ETS_TimeType, AUTOMATIC, RTE_APPL_DATA) timerValue)
{
  uint8 retVal = FALSE;
  if(*timerValue != 0U)
  {
    --(*timerValue);

    if((*timerValue) == 0U)
    {
      retVal = TRUE;
    }
  }
  return retVal;
}
#endif

/**
 * \brief Check start of timer for specific event.
 *
 * Returns Events timer value.
 *
 * \param[out] event ETS_TriggeredEventType timer start value
 *
 * \return function status (TRUE or FALSE).
 *
 */

#if ( NUM_OF_ETS_EVENTS > 0 )
STATIC FUNC(uint8, RTE_CODE) ETS_CheckStartTimer(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event)
{
  return ETS_CheckTimerValue(&(event->timer.start));
}
#endif

/**
 * \brief Check duration of timer for specific event.
 *
 * Returns Events timer value.
 *
 * \param[out] event ETS_TriggeredEventType duration start value
 *
 * \return function status (TRUE or FALSE).
 *
 */
#if ( NUM_OF_ETS_EVENTS > 0 )
STATIC FUNC(uint8, RTE_CODE) ETS_CheckDurationTimer(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event)
{
  return ETS_CheckTimerValue(&(event->timer.duration));
}
#endif

/**
 * \brief Check cycle of timer for specific event.
 *
 * Returns Events timer value.
 *
 * \param[out] event ETS_TriggeredEventType timer cycle value
 *
 * \return function status (TRUE or FALSE).
 *
 */
#if ( NUM_OF_ETS_EVENTS > 0 )
STATIC FUNC(uint8, RTE_CODE) ETS_CheckCycleTimer(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event)
{
  return ETS_CheckTimerValue(&(event->timer.cycle));
}
#endif

/**
 * \brief Specific events cycle timer reset.
 *
 * Sets new cycleValue Events stored timer value.
 *
 * \param[out] event ETS_TriggeredEventType timer cycleValue value
 *
 */

/* !LINKSTO swdd.EB.ETS.TriggAndEvent.12, 1 */
#if ( NUM_OF_ETS_EVENTS > 0 )
STATIC FUNC(void, RTE_CODE) ETS_ReloadCycleTimer(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event)
{
  event->timer.cycle = event->cycleValue;
}
#endif

/**
 * \brief Resets events timer values.
 *
 * Initialize Events stored timer values.
 *
 * \param[out] event ETS_TriggeredEventType timer values
 *
 */

/* !LINKSTO swdd.EB.ETS.Init.2, 1 */
#if ( NUM_OF_ETS_EVENTS > 0 )
FUNC(void, RTE_CODE) ETS_ResetTimer(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event)
{
  event->timer.start    = 0;
  event->timer.cycle    = 0;
  event->timer.duration = 0;
  event->cycleValue = 0;
  event->status = ETS_EVENT_STATUS_DISABLED;
}
#endif

/**
 * \brief Sets events timer values.
 *
 * Set new timer values for an event and reload cycle timer.
 *
 * \param[out] event ETS_TriggeredEventType timer values ETS_TimeType start, ETS_TimeType cycle, ETS_TimeType duration
 * \param[in] start Time in 1/10 s period until start.
 * \param[in]cycle Time in 1/10 s cycle tick during the run.
 * \param[in] duration Time in 1/10 s until stop, after starting.
 *
 */

/* !LINKSTO swdd.EB.ETS.TriggAndEvent.12, 1 */
/* !LINKSTO swdd.EB.ETS.TriggAndEvent.13, 1 */
#if ( ETS_Service_ClientServiceActivate == STD_ON )
/*  ( ETS_Service_ClientServiceDeactivate == TRUE )||
    ( ETS_Service_ClientServiceSubscribeEventgroup == TRUE )||
    ( ETS_Service_SuspendInterface == TRUE )||
    ( ETS_Service_TriggerEventUINT8 == TRUE )||
    ( ETS_Service_TriggerEventUINT8Reliable == TRUE )||
    ( ETS_Service_TriggerEventUINT8Array == TRUE )||
    ( ETS_Service_TriggerEventUINT8E2E == TRUE )||
    ( ETS_Service_TriggerEventUINT8Multicast == TRUE ))
*/      
FUNC(void, RTE_CODE) ETS_SetTimer(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event, ETS_TimeType start, ETS_TimeType cycle, ETS_TimeType duration)
{
  /* Start immediately in next cycle */
  if(start == 0U)
  {
    event->timer.start = 1U;
  }
  else
  {
    event->timer.start    = start    * ETS_TICKS_PER_SECOND;
  }
  event->timer.duration = duration * ETS_TICKS_PER_SECOND;
  event->cycleValue     = cycle    * ETS_TICKS_PER_SECOND;
  ETS_ReloadCycleTimer(event);
}
#endif

/**
 * \brief Checks timer event occurance and trigger function assigned to timer.
 *
 * Set new timer values for an event and reload cycle timer.
 *
 * \param[in] event ETS_TriggeredEventType which timer is assigned for.
 *
 */

/* !LINKSTO swdd.EB.ETS.TriggAndEvent.8, 1 */
/* !LINKSTO swdd.EB.ETS.TriggAndEvent.9, 1 */
/* !LINKSTO swdd.EB.ETS.TriggAndEvent.11, 1 */
/* !LINKSTO swdd.EB.ETS.TriggAndEvent.10, 1 */
#if ( NUM_OF_ETS_EVENTS > 0 )
FUNC(void, RTE_CODE) ETS_CheckEvent(P2VAR(ETS_TriggeredEventType, AUTOMATIC, RTE_APPL_DATA) event)
{

  if(ETS_CheckStartTimer(event) == TRUE)
  {
    event->status = ETS_EVENT_STATUS_RUNNING;
    ETS_CallFctPtr(event->startEvent);
  }
  else if(event->status == ETS_EVENT_STATUS_RUNNING)
  {
    if(ETS_CheckCycleTimer(event) == TRUE)
    {
      ETS_CallFctPtr(event->cyclicEvent);
      ETS_ReloadCycleTimer(event);
    }
    if(ETS_CheckDurationTimer(event) == TRUE)
    {
      event->status = ETS_EVENT_STATUS_DISABLED;
      ETS_CallFctPtr(event->stopEvent);
    }
  }
  else
  {
    /* MISRA */
  }
}
#endif

#define ETS_STOP_SEC_CODE
#include <ETS_MemMap.h>

/* ==================[end of file]============================================ */
