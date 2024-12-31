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


#ifndef _DBG_H
#define _DBG_H

#include "T1_TresosTraceInterface.h"
#include "OS_config.h"

#if defined T1_ENABLE
/*!
 * Map OS macro for tracing CAT2 ISR state changes to two macros that implement T1
 * trace interface using concatenation.
 *
 */
#   define OS_TRACE_STATE_ISR(IsrId, oldValue, newValue) \
        OS_TRACE_STATE_ISR_ ## oldValue ## _ ## newValue ( IsrId )

/*
 * Chose the matching T1_TraceEvent API depending on whether category 1 or Kernel
 * interrupts are active or not.
 */
#   if T1_REQUIRE_INT_LOCK
#       define OS_TRACE_STATE_ISR_OS_TRACE_ISR_SUSPENDED_OS_TRACE_ISR_RUNNING( IsrId ) \
            T1_TraceStartNoAct( (OS_NTASKS) + (IsrId) );
#       define OS_TRACE_STATE_ISR_OS_TRACE_ISR_RUNNING_OS_TRACE_ISR_SUSPENDED( IsrId ) \
            T1_TraceStop( (OS_NTASKS) + (IsrId) );
#   else
#       define OS_TRACE_STATE_ISR_OS_TRACE_ISR_SUSPENDED_OS_TRACE_ISR_RUNNING( IsrId ) \
            T1_TraceStartNoActNoSusp( (OS_NTASKS) + (IsrId) );
#       define OS_TRACE_STATE_ISR_OS_TRACE_ISR_RUNNING_OS_TRACE_ISR_SUSPENDED( IsrId ) \
            T1_TraceStopNoSusp( (OS_NTASKS) + (IsrId) );
#   endif /* T1_REQUIRE_INT_LOCK */

/*!
 * \def OS_TRACE_STATE_TASK
 * \brief Map OS macro for tracing task state changes to function that implements the
 *        logic to map the state changes to T1_TraceEvent API.
 *
 * \details Omit oldValue as TraceStateChangeTask( ) keeps track of it on its own.
 *
 */
#   if defined T1_MAP_LITERAL_NEW_VALUES_IN_TRACE_INTERFACE
#       define OS_TRACE_STATE_TASK(StateId, oldValue, newValue) \
            TraceStateChangeTask_ ## newValue( StateId )

#       define TraceStateChangeTask_newstate( StateId )         \
            TraceStateChangeTask( (StateId), (newstate) )

#       define TraceStateChangeTask_ts( StateId )               \
            TraceStateChangeTask( (StateId), (ts) )
#   else
#       define OS_TRACE_STATE_TASK(StateId, oldValue, newValue) \
            TraceStateChangeTask( (StateId), (newValue) )
#   endif /* defined T1_MAP_LITERAL_NEW_VALUES_IN_TRACE_INTERFACE */

/*!
 * Example Code to instrument OS services:
 *
#   define OS_TRACE_ACTIVATETASK_ENTRY( taskId_ ) T1_TraceEvent( T1_STOPWATCH_START, T1_SW_ActivateTask_CORE_ALL )
#   define OS_TRACE_ACTIVATETASK_EXIT( )          T1_TraceEvent( T1_STOPWATCH_STOP, T1_SW_ActivateTask_CORE_ALL )

#   define OS_TRACE_CALLTRUSTEDFUNCTION_ENTRY( tfIndex_ ) T1_TraceEvent( T1_STOPWATCH_START, T1_SW_CallTrustedFunction_CORE_ALL )
#   define OS_TRACE_CALLTRUSTEDFUNCTION_EXIT( )           T1_TraceEvent( T1_STOPWATCH_STOP, T1_SW_CallTrustedFunction_CORE_ALL )
 *
 */

#else /* !defined T1_ENABLE */
#   define OS_TRACE_STATE_ISR(IsrId, oldValue, newValue)    (void)0
#   define OS_TRACE_STATE_TASK(StateId, oldValue, newValue) (void)0
#endif /* defined T1_ENABLE */

#endif   /* #ifndef _DBG_H */
