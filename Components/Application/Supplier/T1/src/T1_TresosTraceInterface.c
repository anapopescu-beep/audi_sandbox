/*********************************************************************************//*!
 *  \file       T1_TresosTraceInterface.c
 *
 *  \brief      Tracing Interface for T1 <-> EB tresos AutoCore OS
 *
 *  $Author: Razvan Badiu (razvan.badiu) $
 *
 *  $Revision: 1.2 $
 *
 *  \copyright GLIWA embedded systems GmbH & Co. KG, Weilheim i.OB. All rights reserved
 ************************************************************************************/

/*----------------------------------------------------------------------------------*/
/*--- header includes --------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#include <Os.h>
#include <Os_config.h>

#include "T1_TresosTraceInterface.h"
#include "T1_AppInterface.h"

#ifdef T1_ENABLE

/*----------------------------------------------------------------------------------*/
/*--- local macros -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------*/
/*--- global variables -------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#   define T1_START_SEC_VAR_POWER_ON_CLEARED_8
#   include "T1_MemMap.h"
/*
 * Store the previous state of each task
 * Use OS macro OS_NTASKS as length to ensure that enough space is reserved.
 */
os_taskstate_t T1_oldTaskState[OS_NTASKS];
#   define T1_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   include "T1_MemMap.h"

#   if defined T1_USE_STOP_START
#       define T1_START_SEC_VAR_POWER_ON_CLEARED_32
#       include "T1_MemMap.h"
#       if T1_NOF_CORES > 1
T1_postponedEventInfo_t T1_postponedEventInfoPC_[T1_NOF_CORES];
#       else /* T1_NOF_CORES == 0 */
T1_postponedEventInfo_t T1_postponedEventInfo_;
#       endif /* T1_NOF_CORES > 1*/
#       define T1_STOP_SEC_VAR_POWER_ON_CLEARED_32
#       include "T1_MemMap.h"
#   endif /* defined T1_USE_STOP_START */

/*----------------------------------------------------------------------------------*/
/*--- definitions of global functions ----------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#   define T1_START_SEC_CODE
#   include "T1_MemMap.h"
void TraceInit( void )
{
    T1_uint16Least_t i;

    for( i = 0u; i < OS_NTASKS; ++i )
    {
        T1_oldTaskState[i] = OS_TS_SUSPENDED;
    }

#   if defined T1_USE_STOP_START
#       if T1_NOF_CORES > 1
    for( i = 0u; i < T1_NOF_CORES; ++i )
    {
        T1_postponedEventInfoPC_[i].event = T1_EMPTY;
        T1_postponedEventInfoPC_[i].info = 0u;
    }
#       else /* T1_NOF_CORES == 0 */
    T1_postponedEventInfo_.event = T1_EMPTY;
    T1_postponedEventInfo_.info = 0u;
#       endif /* T1_NOF_CORES > 1 */
#   endif /* defined T1_USE_STOP_START */
}

void TraceStateChangeTask( os_taskid_t const taskId,
                           os_taskstate_t const newState )
{
    switch( newState )
    {
        /*------------------------------------------------------------------*/
        case OS_TS_SUSPENDED: /* 0 */
        case OS_TS_QUARANTINED: /* 1 */
        {
            TraceStateChangeTask_OS_TS_SUSPENDED( taskId );
            break;
        }
        /*------------------------------------------------------------------*/
        case OS_TS_NEW: /* 2 */
        {
            TraceStateChangeTask_OS_TS_NEW( taskId );
            break;
        }
        /*------------------------------------------------------------------*/
        case OS_TS_READY_SYNC: /* 3 */
        case OS_TS_READY_ASYNC: /* 4 */
        {
            TraceStateChangeTask_OS_TS_READY_SYNC( taskId );
            break;
        }
        /*------------------------------------------------------------------*/
        case OS_TS_RUNNING: /* 5 */
        {
            TraceStateChangeTask_OS_TS_RUNNING( taskId );
            break;
        }
        /*------------------------------------------------------------------*/
        case OS_TS_WAITING: /* 6 */
        {
            TraceStateChangeTask_OS_TS_WAITING( taskId );
            break;
        }
        /*------------------------------------------------------------------*/
        /* Invalid state transitions */
        case T1_OS_TS_ECC_READY: /* 7 */
        case T1_OS_TS_PREEMPTED: /* 8 */
        default:
        {
            if( taskId < OS_NTASKS )
            {
                T1_oldTaskState[taskId] = newState;
            }
            break;
        }
    }
}
#   define T1_STOP_SEC_CODE
#   include "T1_MemMap.h"

#endif /* T1_ENABLE */
