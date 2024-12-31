/* Os_tool_CORTEXM_armkeil.h - CORTEXM macros for the ARMKEIL C Compiler.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_tool_CORTEXM_armkeil.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_TOOL_CORTEXM_ARMKEIL_H
#define OS_TOOL_CORTEXM_ARMKEIL_H

/* ARMKEIL should be compatible with gnu inline assembly. */
#include "Os_tool_CORTEXM_gnu.h"

/* ARMKEIL-specific macros mainly dealing with its whimsical linker. */

/* Macro that evaluates to the symbol at the beginning of the (anonymous) initialized
 * data (execution address). It is used to initialize anonymous data in the board file.
 */
#define OS_TOOL_STARTDATA					(Image$$ ## data_ ## DATA ## $$Base)

/* Macro that evaluates to the symbol one byte beyond the (anonymous) initialized
 * data (execution address). It is used to initialize anonymous data in the board file.
 */
#define OS_TOOL_ENDDATA						(Image$$ ## data_ ## DATA ## $$ZI$$Limit)

/* Macro that evaluates to the symbol at the beginning of the (anonymous) initialized
 * data (load address). It is used to initialize anonymous data in the board file.
 */
#define OS_TOOL_INITDATA					(Load$$ ## data_ ## DATA ## $$Base)

/* Macro that evaluates to the symbol at the beginning of the (anonymous) uninitialized
 * data. It is used to clear the anonymous bss in the board file.
 */
#define OS_TOOL_STARTBSS					(Image$$ ## bss_ ## DATA ## $$Base)

/* Macro that evaluates to the symbol one byte beyond the (anonymous) uninitialized
 * data. It is used to clear the anonymous bss in the board file.
 */
#define OS_TOOL_ENDBSS						(Image$$ ## bss_ ## DATA ## $$ZI$$Limit)

/* Macro that evaluates to the symbol at the start of all text, rodata and data
 * sections (=ROM start). The region between OS_TOOL_ROM_START and OS_TOOL_ROM_END
 * is granted the rights r-xr-x.
 */
#define OS_TOOL_ROM_START					(Load$$__GLBL_ROM_START$$Base)

/* Macro that evaluates to the symbol at the end of all text, rodata and data
 * sections (=ROM end). The region between OS_TOOL_ROM_START and OS_TOOL_ROM_END
 * is granted the rights r-xr-x.
 */
#define OS_TOOL_ROM_END						(Load$$__GLBL_ROM_END$$Base)

/* Macro that evaluates to the symbol at the start of all data (=RAM start).
 * The region between OS_TOOL_RAM_START and OS_TOOL_RAM_END is granted
 * the rights s+rw, u+r as global data region.
 */
#define OS_TOOL_RAM_START					(Image$$__GLBL_RAM_START$$Base)

/* Macro that evaluates to the symbol one byte beyond the end of all data (=RAM end).
 * The region between OS_TOOL_RAM_START and OS_TOOL_RAM_END is granted
 * the rights s+rw, u+r as global data region.
 */
#define OS_TOOL_RAM_END						(Image$$__GLBL_RAM_END$$Base)

/* Macro that evaluates to the symbol at the start of the I/O region (=IO start).
 * The region between OS_TOOL_IO_START and OS_TOOL_IO_END is granted
 * the rights s+rw, u+rw for the kernel and all trusted entities as global I/O
 * region.
 */
#define OS_TOOL_IO_START					(Image$$__GLBL_IO_START$$Base)

/* Macro that evaluates to the symbol one byte beyond the end of the I/O region (=IO end).
 * The region between OS_TOOL_IO_START and OS_TOOL_IO_END is granted
 * the rights s+rw, u+rw for the kernel and all trusted entities as global I/O
 * region.
 */
#define OS_TOOL_IO_END						(Image$$__GLBL_IO_END$$Base)

/* OS_TOOL_MR_* macros are emitted by the generator to refer to private memory
 * sections of applications, tasks and isrs.
*/

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the Start-VMA of memory region <region>.
 */
#define OS_TOOL_MR_START(secname)			(Image$$ ## data_ ## secname ## $$Base)

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the virtual memory address one byte beyond memory region <region>.
 */
#define OS_TOOL_MR_END(secname)				(Image$$ ## bss_ ## secname ## $$ZI$$Limit)

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the LMA of the data portion of memory region <region>.
 */
#define OS_TOOL_MR_LMA_START(secname)		(Load$$ ## data_ ## secname ## $$Base)

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the LMA one byte beyond the initialized data portion of memory region
 * <region>.
 */
#define OS_TOOL_MR_LMA_END(secname) 		(Load$$ ## data_ ## secname ## $$ZI$$Limit)

#endif /* OS_TOOL_CORTEXM_ARMKEIL_H */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
