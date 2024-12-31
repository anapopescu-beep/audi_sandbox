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

#ifndef _T1_TRESOSTRACEINTERFACE_H
#define _T1_TRESOSTRACEINTERFACE_H

/*----------------------------------------------------------------------------------*/
/*--- header includes --------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#include <Os.h>
#include <Os_config.h>

#include "T1_AppInterface.h"

/*----------------------------------------------------------------------------------*/
/*--- global macros ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

/*!
 * \brief   Use T1_STOP_START event for gapless tracing
 * \details A background task with an endless loop is required as we defer T1_STOP to
 *          the resumption of the preempted task. Therefore without a background task
 *          there would at some point be no task to resume to.
 */
/* #define T1_USE_STOP_START       (1) */

/*!
 * \brief Directly map OS trace macros to inline functions where possible
 * \details If defined all occurrences of the OSs macro OS_TRACE_STATE_TASK that only
 *          have a literal value in their newValue argument are mapped to optimized
 *          inline functions. This gives the lowest overhead for tracing. The used
 *          technique might not work with all versions of the OS therefore undefine as
 *          needed.
 */
#define T1_MAP_LITERAL_NEW_VALUES_IN_TRACE_INTERFACE (1)

#if defined T1_USE_STOP_START
typedef struct
{
    T1_eventInfo_t info;
    T1_eventInfo_t event;
}
T1_postponedEventInfo_t;

/*!
 * \def T1_pPostponedEventInfoPC
 * \brief Macro to return pointer to the core specific T1_postponedEventInfo variable
 */
#   if T1_NOF_CORES > 1
#       define T1_pPostponedEventInfoPC( coreId_ ) ( &T1_postponedEventInfoPC_[(coreId_)] )
#   else   /* T1_NOF_CORES == 0 */
#       define T1_pPostponedEventInfoPC( coreId_ ) ( &T1_postponedEventInfo_ )
#   endif  /* T1_NOF_CORES > 1 */
#endif /* defined T1_USE_STOP_START */

/*!
 * \brief T1 specific task state, used to track the state transition of an ECC task
 *        from T1_RELEASE to T1_RESUME
 * \sa T1_OS_TS_PREEMPTED
 */
#define T1_OS_TS_ECC_READY      (OS_TS_NSTATES)

/*!
 * \brief T1 specific task state, used to trach the state transition of a BSS task
 *        from preempted to resume. T1 does not require tracing an event in this case.
 * \details This is used to distinguish between resuming ECC and BSS tasks.
 * \sa T1_OS_TS_ECC_READY
 */
#define T1_OS_TS_PREEMPTED      (OS_TS_NSTATES + 1)

/*!
 * Check if category 1 interrupts are used in the current OS config.
 * CAT1 interrupts stay enabled in the kernel, this means that it is required to
 * globally disable interrupts for T1_TraceEvent( ), assuming that CAT1 ISRs are
 * instrumented with T1_TraceEvent()
 */
#if OS_NCAT1_INTERRUPTS
/*!
 * \brief If defined T1 uses global interrupt locks in the OS trace interface
 * \details This is required to ensure that T1_TraceEvent() does not get preempted
 *          by T1_TraceEvent() from CAT1 ISRs.
 */
#   define T1_REQUIRE_INT_LOCK (1)
#endif /* OS_NCAT1_INTERRUPTS */

/*!
 * \def LOCAL_T1_TRACE_PC
 * \brief Macro to choose the correct type of T1_TraceEvent() depending on whether
 *        interrupts need to be locked the the OS trace interface or not
 */
#if defined T1_REQUIRE_INT_LOCK
#   define LOCAL_T1_TRACE_PC( specialization_, params_ ) \
        T1_Trace ## specialization_ ## PC params_
#else
#   define LOCAL_T1_TRACE_PC( specialization_, params_ ) \
        T1_Trace ## specialization_ ## NoSuspPC params_
#endif /* defined T1_REQUIRE_INT_LOCK */

#define T1_START_SEC_VAR_POWER_ON_CLEARED_8
#include "T1_MemMap.h"
/*!
 * \brief Store the previous state of each task
 * \details Use OS macro OS_NTASKS as length to ensure that enough space is reserved.
 */
extern os_taskstate_t T1_oldTaskState[OS_NTASKS];
#define T1_STOP_SEC_VAR_POWER_ON_CLEARED_8
#include "T1_MemMap.h"

#if defined T1_USE_STOP_START
#   define T1_START_SEC_VAR_POWER_ON_CLEARED_32
#   include "T1_MemMap.h"
#   if T1_NOF_CORES > 1
/*!
 * \brief Array used to keep track of task state changes that need to be delayed
 *        in order to avoid gaps in the trace.
 * \sa T1_USE_STOP_START
 */
extern T1_postponedEventInfo_t T1_postponedEventInfoPC_[T1_NOF_CORES];
#   else /* T1_NOF_CORES == 0 */
/*!
 * \brief Variable used to keep track of task state changes that need to be delayed
 *        in order to avoid gaps in the trace.
 * \sa T1_USE_STOP_START
 */
extern T1_postponedEventInfo_t T1_postponedEventInfo_;
#   endif /* T1_NOF_CORES > 1*/
#   define T1_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   include "T1_MemMap.h"
#endif /* defined T1_USE_STOP_START */

/*----------------------------------------------------------------------------------*/
/*--- declarations for static functions --------------------------------------------*/
/*----------------------------------------------------------------------------------*/

static inline void  TraceStateChangeTask_OS_TS_SUSPENDED( os_taskid_t const taskId );
static inline void  TraceStateChangeTask_OS_TS_QUARANTINED( os_taskid_t const taskId );
static inline void  TraceStateChangeTask_OS_TS_NEW( os_taskid_t const taskId );
static inline void  TraceStateChangeTask_OS_TS_READY_SYNC( os_taskid_t const taskId );
static inline void  TraceStateChangeTask_OS_TS_READY_ASYNC( os_taskid_t const taskId );
static inline void  TraceStateChangeTask_OS_TS_RUNNING( os_taskid_t const taskId );
static inline void  TraceStateChangeTask_OS_TS_WAITING( os_taskid_t const taskId );

/*----------------------------------------------------------------------------------*/
/*--- forward declarations for global functions ------------------------------------*/
/*----------------------------------------------------------------------------------*/

/*!
 * \brief Perform required initializations for the OS trace interface
 * \details This should only be called from the OSs startup core. This could be added
 *          to T1_AppInit( )
 *
 * \code{.c}
 * void T1_CODE T1_AppInit( void )
 * {
 * #if defined T1_ENABLE
 *     T1_uint8Least_t const coreId = T1_GetCoreIdOffset( );
 *     T1_errorCount[coreId] = 0;
 *
 *     if( OS_CORE_ID_MASTER == coreId )
 *     {
 *         TraceInit( );
 *     }
 *
 *     ...
 * }
 * \endcode
 */
void  TraceInit( void );

/*!
 * \brief Main function used to instrument the OS. Forms the OS trace interface to T1.
 */
void  TraceStateChangeTask( os_taskid_t    const taskId,
                                             os_taskstate_t const newState );

/*----------------------------------------------------------------------------------*/
/*--- definitions for static functions ---------------------------------------------*/
/*----------------------------------------------------------------------------------*/

static inline void  TraceStateChangeTask_OS_TS_SUSPENDED( os_taskid_t const taskId )
{
    /* **Any State** -> OS_TS_SUSPENDED or OS_TS_QUARANTINED
     *
     * Task has been terminated or killed
     */

    /* OS_NULLTASK is the "taskId" for call-outs */
    /* OS_NULLTASK > OS_NTASKS */
    if( ( OS_NULLTASK != taskId ) && (taskId < OS_NTASKS) && T1_TRACE_TASK( taskId ) )
    {
#if T1_NOF_CORES > 1
        T1_uint8Least_t const coreId = T1_GetCoreIdOffset( );
#endif /* defined T1_NOF_CORES */

#if defined T1_USE_STOP_START
        T1_postponedEventInfo_t * const pPostponedEventInfo = T1_pPostponedEventInfoPC( coreId );
        pPostponedEventInfo->event = T1_STOP;
        pPostponedEventInfo->info = taskId;
#else
        LOCAL_T1_TRACE_PC( Stop, ( coreId, taskId ) );
#endif /* defined T1_USE_STOP_START */

        T1_oldTaskState[taskId] = OS_TS_SUSPENDED;
    }
}

static inline void  TraceStateChangeTask_OS_TS_QUARANTINED( os_taskid_t const taskId )
{
    TraceStateChangeTask_OS_TS_SUSPENDED( taskId );

    /*
     * Do not save old state OS_TS_QUARANTINED as we do not distinguish between
     * OS_TS_QUARANTINED and OS_TS_SUSPENDED
     */
}

static inline void  TraceStateChangeTask_OS_TS_NEW( os_taskid_t const taskId )
{
    /* **Any State** -> OS_TS_NEW
     *
     * Task has been activated
     */

    /* OS_NULLTASK is the "taskId" for call-outs */
    /* OS_NULLTASK > OS_NTASKS */
    if( ( OS_NULLTASK != taskId ) && (taskId < OS_NTASKS) && T1_TRACE_TASK( taskId ) )
    {
#if T1_NOF_CORES > 1
        T1_uint8Least_t const coreId = T1_GetCoreIdOffset( );
#endif /* defined T1_NOF_CORES */

        os_taskstate_t const oldState = T1_oldTaskState[taskId]; /* Range of index (taskId) is checked before */

        LOCAL_T1_TRACE_PC( Activation, ( coreId, taskId ) );
        if( OS_TS_RUNNING == oldState ) /* In case RUNNING -> NEW we have a multi activation */
        {
#if defined T1_USE_STOP_START
            T1_postponedEventInfo_t * const pPostponedEventInfo = T1_pPostponedEventInfoPC( coreId );
            pPostponedEventInfo->event = T1_STOP;
            pPostponedEventInfo->info = taskId;
#else
            LOCAL_T1_TRACE_PC( Stop, ( coreId, taskId ) );
#endif /* defined T1_USE_STOP_START */
        }

        T1_oldTaskState[taskId] = OS_TS_NEW;
    }
}

static inline void  TraceStateChangeTask_OS_TS_READY_SYNC( os_taskid_t const taskId )
{
    /* OS_NULLTASK is the "taskId" for call-outs */
    /* OS_NULLTASK > OS_NTASKS */
    if( ( OS_NULLTASK != taskId ) && (taskId < OS_NTASKS) && T1_TRACE_TASK( taskId ) )
    {
#if T1_NOF_CORES > 1
        T1_uint8Least_t const coreId = T1_GetCoreIdOffset( );
#endif /* defined T1_NOF_CORES */

        os_taskstate_t const oldState = T1_oldTaskState[taskId]; /* Range of index (taskId) is checked before */

        switch( oldState )
        {
            case OS_TS_WAITING:
            {
                /* OS_TS_WAITING -> OS_TS_READY_SYNC or OS_TS_READY_ASYNC
                 *
                 * An event an ECC task was waiting for has been set
                 */
#if defined T1_WAIT_RESUME
                LOCAL_T1_TRACE_PC( Release, ( coreId, taskId ) );
#else
                LOCAL_T1_TRACE_PC( Activation, ( coreId, taskId ) );
#endif /* defined T1_WAIT_RESUME */
                T1_oldTaskState[taskId] =  T1_OS_TS_ECC_READY;
                break;
            }
            case OS_TS_RUNNING:
            {
                /* OS_TS_RUNNING -> OS_TS_READY_SYNC or OS_TS_READY_ASYNC
                 *
                 * Task has been preempted
                 */
                T1_oldTaskState[taskId] = T1_OS_TS_PREEMPTED; /* Inhibit T1_START on resume */
                break;
            }
            default:
                ;
        }
    }
}

static inline void  TraceStateChangeTask_OS_TS_READY_ASYNC( os_taskid_t const taskId )
{
    TraceStateChangeTask_OS_TS_READY_SYNC( taskId );
}

static inline void  TraceStateChangeTask_OS_TS_RUNNING( os_taskid_t const taskId )
{
    /* OS_NULLTASK is the "taskId" for call-outs */
    /* OS_NULLTASK > OS_NTASKS */
    if( ( OS_NULLTASK != taskId ) && (taskId < OS_NTASKS) && T1_TRACE_TASK( taskId ) )
    {
#if T1_NOF_CORES > 1
        T1_uint8Least_t const coreId = T1_GetCoreIdOffset( );
#endif /* defined T1_NOF_CORES */

        os_taskstate_t const oldState = T1_oldTaskState[taskId]; /* Range of index (taskId) is checked before */

#if defined T1_USE_STOP_START
        T1_postponedEventInfo_t * const pPostponedEventInfo = T1_pPostponedEventInfoPC( coreId );
#endif /* defined T1_USE_STOP_START */

        switch( oldState )
        {
            case OS_TS_SUSPENDED: /* 0 */
            case OS_TS_QUARANTINED: /* 1 */
            case OS_TS_NEW: /* 2 */
            /* States
             * OS_TS_READY_SYNC (3),
             * and OS_TS_READY_ASYNC (4)
             * will not appear as these where replaced with
             * states T1_OS_TS_ECC_READY or T1_OS_TS_PREEMPTED before
             */
            {
                /* OS_TS_NEW, OS_TS_SUSPENDED or OS_TS_QUARANTINED -> OS_TS_RUNNING
                 *
                 * Start of a new task instance
                 * OS_TS_SUSPENDED or OS_TS_QUARANTINED will probably never
                 * occur as task have to transition through OS_TS_NEW state.
                 */
#if defined T1_USE_STOP_START
                if( T1_EMPTY == pPostponedEventInfo->event )
#endif /* defined T1_USE_STOP_START */
                {
                    LOCAL_T1_TRACE_PC( Start, ( coreId, taskId ) );
                }
#if defined T1_USE_STOP_START
                else if( T1_STOP == pPostponedEventInfo->event )
                {
                    LOCAL_T1_TRACE_PC( StopStart, ( coreId, pPostponedEventInfo->info, taskId ) );
                    pPostponedEventInfo->event = T1_EMPTY;
                }
#   if defined T1_WAIT_RESUME
                else if( T1_WAIT == pPostponedEventInfo->event )
                {
#       if T1_REQUIRE_INT_LOCK
                    T1_SuspendAllInterruptsPC( coreId );
#       endif /* T1_REQUIRE_INT_LOCK */
                    {
                        T1_tickUint_t const traceTime = T1_GET_TRACE_TIME_PC( coreId );
                        T1_TraceEventNoSuspTimePC( coreId, traceTime, T1_WAIT,  pPostponedEventInfo->info ); /* couldn't find T1_TraceWait()/T1_TraceStart() for Time-variant API */
                        T1_TraceEventNoSuspTimePC( coreId, traceTime, T1_START, taskId ); /* maybe they are not necessary in this context because preemption counter shouldn't be changed */
                    }
#       if T1_REQUIRE_INT_LOCK
                    T1_ResumeAllInterruptsPC( coreId );
#       endif /* T1_REQUIRE_INT_LOCK */

                    pPostponedEventInfo->event = T1_EMPTY;
                }
#   endif /* defined T1_WAIT_RESUME */
#endif /* defined T1_USE_STOP_START */
                break;
            }
            case T1_OS_TS_ECC_READY: /* 7 */
            {
               /* T1_OS_TS_ECC_READY -> OS_TS_RUNNING
                *
                * Resumption of waiting ECC task
                */
#if defined T1_USE_STOP_START
                if( T1_EMPTY == pPostponedEventInfo->event )
#endif /* defined T1_USE_STOP_START */
                {
#if defined T1_WAIT_RESUME
                    LOCAL_T1_TRACE_PC( Resume, ( coreId, taskId ) );
#else
                    LOCAL_T1_TRACE_PC( Start, ( coreId, taskId ) );
#endif /* defined T1_WAIT_RESUME */
                }
#if defined T1_USE_STOP_START
                else if( T1_STOP == pPostponedEventInfo->event )
                {
#   if defined T1_WAIT_RESUME
#       if T1_REQUIRE_INT_LOCK
                    T1_SuspendAllInterruptsPC( coreId );
#       endif /* T1_REQUIRE_INT_LOCK */
                    {
                        T1_tickUint_t const traceTime = T1_GET_TRACE_TIME_PC( coreId );
                        T1_TraceEventNoSuspTimePC( coreId, traceTime, T1_STOP,    pPostponedEventInfo->info ); /* couldn't find T1_TraceStop()/T1_TraceResume() for Time-variant API */
                        T1_TraceEventNoSuspTimePC( coreId, traceTime, T1_RESUME,  taskId ); /* maybe they are not necessary in this context because preemption counter shouldn't be changed */
                    }
#       if T1_REQUIRE_INT_LOCK
                    T1_ResumeAllInterruptsPC( coreId );
#       endif /* T1_REQUIRE_INT_LOCK */
#   else
                    LOCAL_T1_TRACE_PC( StopStart, ( coreId, pPostponedEventInfo->info, taskId ) );
#   endif /* defined T1_WAIT_RESUME */
                    pPostponedEventInfo->event = T1_EMPTY;
                }
#   if defined T1_WAIT_RESUME
                else if( T1_WAIT == pPostponedEventInfo->event )
                {
#       if T1_REQUIRE_INT_LOCK
                    T1_SuspendAllInterruptsPC( coreId );
#       endif /* T1_REQUIRE_INT_LOCK */
                    {
                        T1_tickUint_t const traceTime = T1_GET_TRACE_TIME_PC( coreId );
                        T1_TraceEventNoSuspTimePC( coreId, traceTime, T1_WAIT,   pPostponedEventInfo->info );
                        T1_TraceEventNoSuspTimePC( coreId, traceTime, T1_RESUME, taskId ); /* maybe they are not necessary in this context because preemption counter shouldn't be changed */
                    }
#       if T1_REQUIRE_INT_LOCK
                    T1_ResumeAllInterruptsPC( coreId );
#       endif /* T1_REQUIRE_INT_LOCK */
                    pPostponedEventInfo->event = T1_EMPTY;
                }
#   endif /* defined T1_WAIT_RESUME */
#endif /* defined T1_USE_STOP_START */
                break;
            }
            case T1_OS_TS_PREEMPTED: /* 8 */
            {
                /* T1_OS_TS_PREEMPTED -> OS_TS_RUNNING
                 *
                 * Only used for T1_USE_STOP_START
                 */
#if defined T1_USE_STOP_START
                if( T1_STOP == pPostponedEventInfo->event )
                {
                    LOCAL_T1_TRACE_PC( Stop, ( coreId, pPostponedEventInfo->info ) );
                }
#   if defined T1_WAIT_RESUME
                else if( T1_WAIT == pPostponedEventInfo->event )
                {
                    LOCAL_T1_TRACE_PC( Wait, ( coreId, pPostponedEventInfo->info ) );
                }
#   endif /*  defined T1_WAIT_RESUME */
                pPostponedEventInfo->event = T1_EMPTY;
#endif /* defined T1_USE_STOP_START */
                break;
            }
            /* Invalid state transitions */
            case OS_TS_READY_SYNC: /* 3 */
            case OS_TS_READY_ASYNC: /* 4 */
            case OS_TS_RUNNING: /* 5 */
            case OS_TS_WAITING: /* 6 */
            default:
                break;
        }

        T1_oldTaskState[taskId] = OS_TS_RUNNING;
    }
}

static inline void  TraceStateChangeTask_OS_TS_WAITING( os_taskid_t const taskId )
{
    /* **Any State** -> OS_TS_WAITING
     *
     * Task called WaitEvent() with no event already set, enters
     * waiting state
     */

    /* OS_NULLTASK is the "taskId" for call-outs */
    /* OS_NULLTASK > OS_NTASKS */
    if( ( OS_NULLTASK != taskId ) && (taskId < OS_NTASKS) && T1_TRACE_TASK( taskId ) )
    {
#if T1_NOF_CORES > 1
        T1_uint8Least_t const coreId = T1_GetCoreIdOffset( );
#endif /* defined T1_NOF_CORES */

#if defined T1_USE_STOP_START
        T1_postponedEventInfo_t * const pPostponedEventInfo = T1_pPostponedEventInfoPC( coreId );
#endif /* defined T1_USE_STOP_START */

#if defined T1_WAIT_RESUME
#   if defined T1_USE_STOP_START
        pPostponedEventInfo->event = T1_WAIT;
        pPostponedEventInfo->info = taskId;
#   else
        LOCAL_T1_TRACE_PC( Wait, ( coreId, taskId ) );
#   endif /* defined T1_USE_STOP_START */
#else
#   if defined T1_USE_STOP_START
        pPostponedEventInfo->event = T1_STOP;
        pPostponedEventInfo->info = taskId;
#   else
        LOCAL_T1_TRACE_PC( Stop, ( coreId, taskId ) );
#   endif /* defined T1_USE_STOP_START */
#endif /* defined T1_WAIT_RESUME */

        T1_oldTaskState[taskId] = OS_TS_WAITING;
    }
}

#endif /* _T1_TRESOSTRACEINTERFACE_H */

