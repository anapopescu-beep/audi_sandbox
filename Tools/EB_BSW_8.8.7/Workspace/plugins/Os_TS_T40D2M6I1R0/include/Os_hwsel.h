/* Os_hwsel.h
 *
 * This file provides characteristics of the current derivative's cpu.
 * It includes the target specific Os_*_cpu.h file.
 *
 * $Id: Os_hwsel.h 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_HWSEL_H
#define OS_HWSEL_H


/* Architecture specific defines */
#define OS_HWSEL_ATOMICS    <CORTEXM/Os_atomics_CORTEXM.h>
#define OS_HWSEL_API        <CORTEXM/Os_api_CORTEXM.h>
#define OS_HWSEL_CPU        <CORTEXM/Os_CORTEXM_cpu.h>
#define OS_HWSEL_DEFS       <CORTEXM/Os_defs_CORTEXM.h>
#define OS_HWSEL_KERNEL     <CORTEXM/Os_kernel_CORTEXM.h>
#define OS_HWSEL_MMU        <CORTEXM/Os_mmu_CORTEXM.h>
#define OS_HWSEL_PROTO      <CORTEXM/Os_proto_CORTEXM.h>
#define OS_HWSEL_TOOL       <CORTEXM/Os_tool_CORTEXM.h>
#define OS_HWSEL_TYPES      <CORTEXM/Os_types_CORTEXM.h>
#define OS_HWSEL_ERRORCODES <CORTEXM/Os_errorcodes_CORTEXM.h>

#endif
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
