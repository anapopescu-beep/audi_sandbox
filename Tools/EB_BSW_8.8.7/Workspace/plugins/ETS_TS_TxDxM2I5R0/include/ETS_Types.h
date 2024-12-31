#ifndef ETS_TYPES_H
#define ETS_TYPES_H
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

#include <Std_Types.h>
#include <ETS_Macros.h>

/*==================[macros]======================================================================*/

/** \brief Event status for ETS_Events */
/**< Event is currently not active. */
#define ETS_EVENT_STATUS_DISABLED 0U
/** \brief Event status for ETS_Events */
/**< Event is currently active. */
#define ETS_EVENT_STATUS_RUNNING  1U

/*==================[type definitions]============================================================*/

/** \brief Type to store timer values. */
typedef uint16 ETS_TimeType;

/** \brief Type to store event status values. */
typedef uint8 ETS_EventStatusType;

/** \brief Struct to hold timer values for events. */
typedef struct {
  ETS_TimeType start;    /**< Keeps the time till start event. */
  ETS_TimeType duration; /**< Keeps the time the event will be active. */
  ETS_TimeType cycle;    /**< Keeps the time till next cyclic call in event. */
} ETS_TriggerEventTimerType;

/** \brief Struct for Events. */
typedef struct {
  ETS_TriggerEventTimerType timer; /**< Event timer. */
  ETS_EventStatusType status; /**< Current status of the event. */
  ETS_TimeType cycleValue; /**< Keeps the time for cyclic events. Value is reloaded from here. */
  P2FUNC(void, AUTOMATIC, startEvent) (void); /**< Function pointer to the start event. */
  P2FUNC(void, AUTOMATIC, cyclicEvent) (void); /**< Function pointer to the cyclic event. */
  P2FUNC(void, AUTOMATIC, stopEvent) (void); /**< Function pointer to the stop event. */
} ETS_TriggeredEventType;

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*==================[external function declarations]==============================================*/

#endif /* ETS_TYPES_H */
/*--- End of file ------------------------------------------------------------*/

