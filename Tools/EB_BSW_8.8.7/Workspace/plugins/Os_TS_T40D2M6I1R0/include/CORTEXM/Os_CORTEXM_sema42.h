/* Os_CORTEXM_sema42.h - Contains definitions for SEMA42 unit
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_CORTEXM_sema42.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_CORTEXM_SEMA42_H
#define OS_CORTEXM_SEMA42_H

#ifndef OS_SEMA42_BASE_ADR
#error "OS_SEMA42_BASE_ADR not defined."
#endif

#ifndef OS_NHARDWARELOCKS
#error "OS_NHARDWARELOCKS not defined."
#endif

#ifndef OS_SEMA42_PADDING0
#error "OS_SEMA42_PADDING0 not defined."
#endif

#ifndef OS_ASM
typedef struct os_sema42_s os_sema42_t;
struct os_sema42_s
{
	os_reg8_t gate[OS_NHARDWARELOCKS + 1];	/* Gate Register */
	os_reg16_t padding[OS_SEMA42_PADDING0];
	os_reg16_t rstgt_rw; 					/* Reset Gate Read/Write */
};

void OS_SEMA42_Acquire_ILevel(os_lockid_t lockId, os_intstatus_t oldIlevel);
void OS_SEMA42_Acquire_IState(os_lockid_t lockId, os_intstatus_t oldIState);

extern const os_uint8_t OS_SEMA42_DomainIdMap[OS_N_CORES_MAX];
#endif

#define OS_SEMA42			((os_sema42_t *)	OS_SEMA42_BASE_ADR)
#define OS_SEMA42_Drop(l)	(OS_SEMA42->gate[(l)] = 0)


#endif /* OS_CORTEXM_SEMA42_H */
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
