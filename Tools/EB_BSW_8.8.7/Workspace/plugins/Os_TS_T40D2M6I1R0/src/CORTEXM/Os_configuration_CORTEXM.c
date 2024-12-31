/* Os_configuration_CORTEXM.c
 *
 * This file provides architecture-specific kernel configuration data
 * for CORTEXM.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_configuration_CORTEXM.c 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#include <Os_configuration.h>
#include <Os_kernel.h>
#include <Os_tool.h>
#include <Os_configuration_decls.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

/* CHECK: NOPARSE */
/* Idle stack - Stack for the Idle loop. Need room for at least one
 * exception stack frame.
*/
OS_GEN_STACK(OS_idleStack, .bss.os_idlestack, OS_IDLESTACK_SIZE, 8);
/* CHECK: PARSE */

#include <memmap/Os_mm_const_begin.h>

/*!
 * OS_intDisableLevel
 *
 * The interrupt level for disabling OS (category 2) interrupts
*/
const os_intstatus_t OS_intDisableLevel = OS_CAT2LOCK;

/*!
 * OS_kernDisableLevel
 *
 * The interrupt level for disabling OS (category 2) interrupts AND
 * - currently calculated during initialization of the interrupt controller
 */
const os_intstatus_t OS_kernDisableLevel = OS_KERNLOCK;

/*!
 * OS_intDisableLevelAll
 *
 * The interrupt level for disabling all (category 1 and 2) interrupts
*/
const os_intstatus_t OS_intDisableLevelAll = OS_CAT1LOCK;

#if (OS_N_CORES_MAX > 1)
/*!
 * OS_kernOnlyXcoreLevel
 *
 * The interrupt level for disabling all interrupts except the inter-core notification
*/
const os_intstatus_t OS_kernOnlyXcoreLevel = OS_XCOREUNLOCK;
#endif /* OS_N_CORES_MAX > 1 */

/*!
 * OS_intDisableLevelMax
 *
 * The interrupt disable level to disable ALL possible interrupts. This includes
 * CAT2, CAT1 and OS interrupts, i.e. the maximum of all lock levels.
*/
#if (OS_KERNLOCK < OS_CAT1LOCK)
const os_intstatus_t OS_intDisableLevelMax = OS_KERNLOCK;
#else
const os_intstatus_t OS_intDisableLevelMax = OS_CAT1LOCK;
#endif

/* stack size for application error, startup and shutdown hooks */
const os_size_t OS_eHookStackLen = OS_EHOOKSTACKLEN;
const os_size_t OS_sHookStackLen = OS_SHOOKSTACKLEN;

#if ( (OS_N_CORES_MAX > 1) && (OS_HAS_SEMA4 == 1) )
const os_uint8_t OS_SEMA42_DomainIdMap[OS_N_CORES_MAX] = { OS_SEMA42_DOMAIN_ID_MAP };
#endif

#include <memmap/Os_mm_const_end.h>

/* Constants needed for the syscall kernel/memory protection
 *
 * OS_textBase, OS_ramBase, OS_constBase, OS_textLimit, OS_ramLimit, OS_constLimit
 *
 * These constants are used by the memory-protection subsystem.
 *
 * OS_textBase defines the start address of the ROM region that is executable by all non-trusted tasks.
 * OS_ramBase defines the start address of the RAM region that is readable by all non-trusted tasks.
 * OS_constBase defines the start address of the ROM region that is readable by all non-trusted tasks.
 *
 * These base "variables" aren't really variables at all. They are linker-defined symbols that
 * tell us where memory regions are. We simply take their addresses and put them into registers.
 *
 * CHECK: SAVE
 * CHECK: RULE 401 OFF (see above)
*/

#if (OS_HASMEMPROT == 1) && (OS_KERNEL_TYPE==OS_SYSTEM_CALL)
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_ROM_START;
extern os_uint8_t OS_TOOL_ROM_END;
extern os_uint8_t OS_TOOL_RAM_START;
extern os_uint8_t OS_TOOL_RAM_END;
#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM) || (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
extern os_uint8_t OS_TOOL_IO_START;
extern os_uint8_t OS_TOOL_IO_END;
#endif
#endif

#include <memmap/Os_mm_const_begin.h>
#ifndef EB_STATIC_CHECK
const void * const OS_romBase		= (void *)&OS_TOOL_ROM_START;
const void * const OS_romLimit		= (void *)&OS_TOOL_ROM_END;

const void * const OS_ramBase		= (void *)&OS_TOOL_RAM_START;
const void * const OS_ramLimit		= (void *)&OS_TOOL_RAM_END;

#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM) || (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
const void * const OS_ioBase		= (void *)&OS_TOOL_IO_START;
const void * const OS_ioLimit		= (void *)&OS_TOOL_IO_END;
#endif
#else
const void * const OS_romBase		= (void *)0;
const void * const OS_romLimit		= (void *)0;

const void * const OS_ramBase		= (void *)0;
const void * const OS_ramLimit		= (void *)0;

#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM) || (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
const void * const OS_ioBase		= (void *)0;
const void * const OS_ioLimit		= (void *)0;
#endif
#endif

#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM)
const os_uint8_t OS_romMpuSize		= OS_CORTEXM_MPU_GLOBAL_ROM_SIZE;
const os_uint8_t OS_ramMpuSize		= OS_CORTEXM_MPU_GLOBAL_RAM_SIZE;
const os_uint8_t OS_ioMpuSize		= OS_CORTEXM_MPU_GLOBAL_IO_SIZE;
const os_uint8_t OS_eHookMpuSize	= OS_CORTEXM_MPU_EHOOK_SIZE;
const os_uint8_t OS_sHookMpuSize	= OS_CORTEXM_MPU_SHOOK_SIZE;
const os_uint8_t OS_kernStackMpuSize[OS_N_CORES_MAX] = {
#if ((OS_PROPERTIES_CORE0 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
	OS_CORTEXM_MPU_SIZE_KERNSTACK0,
#else
	0u,
#endif
#if (OS_N_CORES_MAX > 1)
#if ((OS_PROPERTIES_CORE1 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
	OS_CORTEXM_MPU_SIZE_KERNSTACK1,
#else
	0u,
#endif
#endif
#if (OS_N_CORES_MAX > 2)
#if ((OS_PROPERTIES_CORE2 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
	OS_CORTEXM_MPU_SIZE_KERNSTACK2,
#else
	0u,
#endif
#endif
#if (OS_N_CORES_MAX > 3)
#if ((OS_PROPERTIES_CORE3 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
	OS_CORTEXM_MPU_SIZE_KERNSTACK3,
#else
	0u,
#endif
#endif
} ;
#endif

#include <memmap/Os_mm_const_end.h>

#endif

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_Os_configuration_CORTEXM_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* CHECK: RESTORE
*/

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
