/**
 * \file
 *
 * \brief AUTOSAR MemAcc
 *
 * This file contains the implementation of the AUTOSAR
 * module MemAcc.
 *
 * \version 1.0.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/

#include <MemAcc_Trace.h>
#include <TSAutosar.h>               /* EB specific standard types          */
#include <TSMem.h>                   /* Autosar Base module header          */
#include <MemAcc_Queue.h>            /* Extern definitions of unit queue.   */
#include <MemAcc_Lcfg.h>
/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/


#define MEMACC_START_SEC_VAR_CLEARED_16
#include <MemAcc_MemMap.h>

VAR(uint16, MEMACC_VAR_CLEARED) QueueElementsNo;

#define MEMACC_STOP_SEC_VAR_CLEARED_16
#include <MemAcc_MemMap.h>

#define MEMACC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <MemAcc_MemMap.h>

VAR( MemAcc_QueueItemType, MEMACC_VAR_CLEARED ) MemAcc_AreaIdQueue[MEMACC_JOB_QUEUE_SIZE];

#define MEMACC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <MemAcc_MemMap.h>

/*==================[internal data]=========================================*/


/*==================[internal function declarations]========================*/

#define MEMACC_START_SEC_CODE
#include <MemAcc_MemMap.h>

/** \brief Returns insertion index in queue based on job priority
 **
 ** Insertion index is found using binary search in the sorted queue
 ** Index for insertion is after previous jobs having same priority
 **
 ** \Reentrancy{Non Reentrant}
 ** \Synchronicity{Synchronous} */
static FUNC(uint16, MEMACC_CODE) MemAcc_QueueInsertIndex(MemAcc_JobPriorityType JobPriority);

#define MEMACC_STOP_SEC_CODE
#include <MemAcc_MemMap.h>

/*==================internal functions definitions==========================*/

#define MEMACC_START_SEC_CODE
#include <MemAcc_MemMap.h>

/*==================[MemAcc_QueueInsertIndex]=========================*/
static FUNC(uint16, MEMACC_CODE) MemAcc_QueueInsertIndex(MemAcc_JobPriorityType JobPriority)
{
  uint16 Start = 0;
  uint16 End;
  uint16 Middle;

  End = QueueElementsNo;

  while (Start < End)
  {
    Middle = (Start + End)/2U;
    if (MemAcc_AddressAreas[MemAcc_AreaIdQueue[Middle].AddressAreaCfgIdx].JobPriority
        < JobPriority)
    {
      End = Middle;
    }
    else
    {
      Start = Middle + 1U;
    }
  }
  return Start;
}

#define MEMACC_STOP_SEC_CODE
#include <MemAcc_MemMap.h>


/*==================[external function definitions]=========================*/

#define MEMACC_START_SEC_CODE
#include <MemAcc_MemMap.h>


/*==================[MemAcc_Queue_Init]=========================*/
FUNC(void, MEMACC_CODE) MemAcc_Queue_Init(void)
{
  uint16 QueueIdx = 0;

  QueueElementsNo = 0;
  for(QueueIdx = 0; QueueIdx < MEMACC_JOB_QUEUE_SIZE;QueueIdx++)
  {
    MemAcc_AreaIdQueue[QueueIdx].AddressAreaCfgIdx = MEMACC_QUEUE_INVALID_AREA_INDEX;
  }
}


/*==================[MemAcc_InsertInQueue]=========================*/

FUNC(void, MEMACC_CODE) MemAcc_InsertInQueue(MemAcc_AddressAreaIdType AddressAreaCfgIdx)
{
  uint16 ElementsToMove;
  uint16 Index;

  /* !LINKSTO MemAcc.SWS_MemAcc_00014, 1 */
  Index = MemAcc_QueueInsertIndex(MemAcc_AddressAreas[AddressAreaCfgIdx].JobPriority);

  ElementsToMove = QueueElementsNo - Index;
  /*shift right all jobs with lower prio*/
  if(ElementsToMove > 0U)
  {
    /* TS_MemMove call causes bcgcc warning where it complains about */
    /* an ILLEGAL pointer in postdecrement (p--)*/
    /* but it has proven to work well in practice */
    TS_MemMove(&MemAcc_AreaIdQueue[Index + 1U], &MemAcc_AreaIdQueue[Index],
        sizeof(MemAcc_AreaIdQueue[0]) * ElementsToMove);
  }

  MemAcc_AreaIdQueue[Index].AddressAreaCfgIdx = AddressAreaCfgIdx;
  QueueElementsNo++;
}

/*==================[MemAcc_DequeueElement]=========================*/
FUNC(void, MEMACC_CODE) MemAcc_DequeueElement(MemAcc_AddressAreaIdType AddressAreaCfgIdx)
{
  uint16 ElementsToMove;
  uint16 Index;
  boolean ElementDequeued = FALSE;

  for(Index = 0; (Index < QueueElementsNo ) && (ElementDequeued == FALSE); Index++)
  {
    if(MemAcc_AreaIdQueue[Index].AddressAreaCfgIdx == AddressAreaCfgIdx)
    {
      /*shift left all other jobs*/
      ElementsToMove = QueueElementsNo - Index - 1U;
      if(ElementsToMove > 0U)
      {
        TS_MemMove(&MemAcc_AreaIdQueue[Index], &MemAcc_AreaIdQueue[Index + 1U],
            sizeof(MemAcc_AreaIdQueue[0]) * ElementsToMove);
      }
      QueueElementsNo--;
      MemAcc_AreaIdQueue[QueueElementsNo].AddressAreaCfgIdx = MEMACC_QUEUE_INVALID_AREA_INDEX;
      ElementDequeued = TRUE;
    }
  }
}

#define MEMACC_STOP_SEC_CODE
#include <MemAcc_MemMap.h>

/*==================[end of file]===========================================*/
