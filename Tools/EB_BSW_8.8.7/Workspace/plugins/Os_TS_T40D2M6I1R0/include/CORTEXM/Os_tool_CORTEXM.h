/* Os_tool_CORTEXM.h - CORTEXM definitions for different tool chains.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_tool_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_TOOL_CORTEXM_H
#define OS_TOOL_CORTEXM_H

#include <Os_defs.h>
#include <CORTEXM/Os_CORTEXM_cpu.h>

#ifndef EB_STATIC_CHECK

#if (OS_TOOL==OS_ticgt)
#include <CORTEXM/Os_tool_CORTEXM_ticgt.h>
#elif (OS_TOOL==OS_gnu)
#include <CORTEXM/Os_tool_CORTEXM_gnu.h>
#elif (OS_TOOL==OS_ghs)
#include <CORTEXM/Os_tool_CORTEXM_ghs.h>
#elif (OS_TOOL==OS_iar)
#include <CORTEXM/Os_tool_CORTEXM_iar.h>
#elif (OS_TOOL==OS_arm5)
#include <CORTEXM/Os_tool_CORTEXM_arm5.h>
#elif (OS_TOOL==OS_armkeil)
#include <CORTEXM/Os_tool_CORTEXM_armkeil.h>
#elif (OS_TOOL==OS_diab)
#include <CORTEXM/Os_tool_CORTEXM_diab.h>
#else
#error "Unknown or unsupported toolchain. Check your Makefiles!"
#endif

/* Macro that evaluates to the symbol at the beginning of the initialized data
 * section. It is used as the destination to initialize the data section in the
 * board file.
 *
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_TOOL_STARTDATA
#define OS_TOOL_STARTDATA		(__STARTDATA)
#endif

/* Macro that evaluates to the symbol one byte beyond of the initialized data
 * section. It is used to mark the end of data initialization in the board
 * file.
 *
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_TOOL_ENDDATA
#define OS_TOOL_ENDDATA			(__ENDDATA)
#endif

/* Macro that evaluates to the symbol at the beginning of the initialized data
 * section in ROM. It is used as the source for the initialization of the data
 * section in the board file.
 *
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_TOOL_INITDATA
#define OS_TOOL_INITDATA		(__INITDATA)
#endif

/* Macro that evaluates to the symbol at the beginning of the (anonymous)
 * uninitialized data section. It is used to clear the anonymous bss section in
 * the board file.
 *
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_TOOL_STARTBSS
#define OS_TOOL_STARTBSS		(__STARTBSS)
#endif

/* Macro that evaluates to the symbol one byte beyond the (anonymous)
 * uninitialized data section. It is used to clear the anonymous bss in the
 * board file.
 *
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_TOOL_ENDBSS
#define OS_TOOL_ENDBSS			(__ENDBSS)
#endif

/* Macro that evaluates to the symbol at the start of all text, rodata and data
 * sections (=ROM start). The region between OS_TOOL_ROM_START and OS_TOOL_ROM_END
 * is granted the rights r-xr-x.
 */
#ifndef OS_TOOL_ROM_START
#define OS_TOOL_ROM_START		(__GLBL_ROM_START)
#endif

/* Macro that evaluates to the symbol at the end of all text, rodata and data
 * sections (=ROM end). The region between OS_TOOL_ROM_START and OS_TOOL_ROM_END
 * is granted the rights r-xr-x.
 */
#ifndef OS_TOOL_ROM_END
#define OS_TOOL_ROM_END			(__GLBL_ROM_END)
#endif

/* Macro that evaluates to the symbol at the start of all data (=RAM start).
 * The region between OS_TOOL_RAM_START and OS_TOOL_RAM_END is granted
 * the rights s+rw, u+r as global data region.
 */
#ifndef OS_TOOL_RAM_START
#define OS_TOOL_RAM_START		(__GLBL_RAM_START)
#endif

/* Macro that evaluates to the symbol one byte beyond the end of all data (=RAM end).
 * The region between OS_TOOL_RAM_START and OS_TOOL_RAM_END is granted
 * the rights s+rw, u+r as global data region.
 */
#ifndef OS_TOOL_RAM_END
#define OS_TOOL_RAM_END			(__GLBL_RAM_END)
#endif

/* Macro that evaluates to the symbol at the start of the I/O region (=IO start).
 * The region between OS_TOOL_IO_START and OS_TOOL_IO_END is granted
 * the rights s+rw, u+rw for the kernel and all trusted entities as global I/O
 * region.
 */
#ifndef OS_TOOL_IO_START
#define OS_TOOL_IO_START		(__GLBL_IO_START)
#endif

/* Macro that evaluates to the symbol one byte beyond the end of the I/O region (=IO end).
 * The region between OS_TOOL_IO_START and OS_TOOL_IO_END is granted
 * the rights s+rw, u+rw for the kernel and all trusted entities as global I/O
 * region.
 */
#ifndef OS_TOOL_IO_END
#define OS_TOOL_IO_END			(__GLBL_IO_END)
#endif

#else
#define OS_DSB() /* nothing */
#endif /* EB_STATIC_CHECK */

/* Implemenation of OS_CORTEXM_GetSP() */
#ifndef OS_TOOL_GETSP_IMPLEMENTATION
#define OS_TOOL_GETSP_IMPLEMENTATION OS_TOOL_ASM_FUNC
#endif

/* Implemenation of OS_CORTEXM_SetSP() */
#ifndef OS_TOOL_SETSP_IMPLEMENTATION
#define OS_TOOL_SETSP_IMPLEMENTATION OS_TOOL_ASM_FUNC
#endif

/* Implementation of OS_CORTEXM_EnableIRQ() */
#ifndef OS_TOOL_ENABLE_IRQ_IMPLEMENTATION
#define OS_TOOL_ENABLE_IRQ_IMPLEMENTATION OS_TOOL_ASM_FUNC
#endif

/* Implementation fo OS_CORTEXM_DisableIRQ() */
#ifndef OS_TOOL_DISABLE_IRQ_IMPLEMENTATION
#define OS_TOOL_DISABLE_IRQ_IMPLEMENTATION OS_TOOL_ASM_FUNC
#endif

/* Implementation of OS_CORTEXM_EnableIRQGetState() */
#ifndef OS_TOOL_ENABLE_IRQ_GET_STATE_IMPLEMENTATION
#define OS_TOOL_ENABLE_IRQ_GET_STATE_IMPLEMENTATION OS_TOOL_ASM_FUNC
#endif

/* Implemenation of OS_CORTEXM_DisableIRQGetState() */
#ifndef OS_TOOL_DISABLE_IRQ_GET_STATE_IMPLEMENTATION
#define OS_TOOL_DISABLE_IRQ_GET_STATE_IMPLEMENTATION OS_TOOL_ASM_FUNC
#endif

/* Implementation of OS_CORTEXM_SetState() */
#ifndef OS_TOOL_SET_STATE_IMPLEMENTATION
#define OS_TOOL_SET_STATE_IMPLEMENTATION OS_TOOL_ASM_FUNC
#endif

/* Implemenation of OS_CORTEXM_GetIRQPrio() */
#ifndef OS_TOOL_GET_IRQ_PRIO_IMPLEMENTATION
#define OS_TOOL_GET_IRQ_PRIO_IMPLEMENTATION OS_TOOL_ASM_FUNC
#endif

/* Implemenation of OS_CORTEXM_SetIRQPrio() */
#ifndef OS_TOOL_SET_IRQ_PRIO_IMPLEMENTATION
#define OS_TOOL_SET_IRQ_PRIO_IMPLEMENTATION OS_TOOL_ASM_FUNC
#endif

/* Implemenation of OS_CORTEXM_GetCurIRQSource() */
#ifndef OS_TOOL_GET_CUR_IRQ_SOURCE_IMPLEMENTATION
#define OS_TOOL_GET_CUR_IRQ_SOURCE_IMPLEMENTATION OS_TOOL_ASM_FUNC
#endif

/* Implementation of OS_CORTEXM_GetKernelData() */
#ifndef OS_TOOL_GETKERNELDATA_IMPLEMENTATION
#define OS_TOOL_GETKERNELDATA_IMPLEMENTATION OS_TOOL_ASM_FUNC
#endif

/* Implementation of OS_CORTEXM_DSB_SY() */
#ifndef OS_TOOL_DSB_SY_IMPLEMENTATION
#define OS_TOOL_DSB_SY_IMPLEMENTATION OS_TOOL_ASM_FUNC
#endif

#endif
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
