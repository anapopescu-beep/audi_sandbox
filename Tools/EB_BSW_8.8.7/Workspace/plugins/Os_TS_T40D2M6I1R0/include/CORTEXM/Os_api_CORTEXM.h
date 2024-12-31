/* Os_api_CORTEXM.h
 *
 * This file is the architecture-dependent public API prototype file for CORTEXM
 *
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_api_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
 */
#ifndef OS_API_CORTEXM_H
#define OS_API_CORTEXM_H

/* CORTEXM implementation supports atomic monitor operations using strex
 * (monitor is cleared on kernel entry).
 *
 * !LINKSTO Kernel.Feature.TransactionSupport, 1
 */
#define OS_HAS_TRANSACTION_SUPPORT	1

#ifndef OS_ASM

extern void boardInvalidInterrupt(void);
extern void boardInvalidException(void);
extern void boardNmiCallBack(void);

#ifndef OS_HAS_TB_INTERNAL
#error "OS_HAS_TB_INTERNAL undefined."
#endif

#if OS_HAS_TB_INTERNAL==1
/* system counter serves as internal timestamp timer. */
#ifndef OS_ASM
#define OS_TB_FUNC	OS_CORTEXM_GetTimeStamp
#endif
#endif

#endif /* OS_ASM */

#endif /* OS_API_CORTEXM_H */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
 */
