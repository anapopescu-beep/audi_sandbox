/* This file is generated automatically. DO NOT EDIT!!
 *
 * EB tresos AutoCore OS 6.1.144 CORTEXM/S32K14X
 * (Build 20230308)
 *
 * (c) 1998-2023 Elektrobit Automotive GmbH
 * Am Wolfsmantel 46
 * 91058 Erlangen
 * GERMANY
 *
 */

#include <Os_config.h>
#include <Os_kernel.h>
#include <Os_tool.h>

#if OS_GENERATION_ID_OS_H!=0x1905575eUL
#error "Build-Ids of src\Os_gen.c and include\Os_user.h did not match! Hint: A wrong include\Os_user.h was most probably included."
#endif
#if OS_GENERATION_ID_OS_CONF_H!=0x1905575eUL
#error "Build-Ids of src\Os_gen.c and include\Os_config.h did not match! Hint: A wrong include\Os_config.h was most probably included."
#endif
#if OS_GENERATION_ID_OS_KCONF_H!=0x1905575eUL
#error "Build-Ids of src\Os_gen.c and include\Os_kconfig.h did not match! Hint: A wrong include\Os_kconfig.h was most probably included."
#endif

const os_uint32_t OS_os_GenBuildId = 0x1905575eUL;

/*===================================================================
 * Counters
 *==================================================================*/

void OS_CounterIsr_OsCounter_HARDWARE(void)
{
  OS_HwCounterUpdate(&OS_counterTableBase[OsCounter_HARDWARE]);
}

/*===================================================================
 * Stacks
 *==================================================================*/
/* Task stacks */
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot0, .bss.core0.os_taskstack0_slot0, 168, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot1, .bss.core0.os_taskstack0_slot1, 168, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot2, .bss.core0.os_taskstack0_slot2, 232, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot3, .bss.core0.os_taskstack0_slot3, 168, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot4, .bss.core0.os_taskstack0_slot4, 232, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot5, .bss.core0.os_taskstack0_slot5, 168, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot6, .bss.core0.os_taskstack0_slot6, 72, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot7, .bss.core0.os_taskstack0_slot7, 168, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot8, .bss.core0.os_taskstack0_slot8, 168, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot9, .bss.core0.os_taskstack0_slot9, 296, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot10, .bss.core0.os_taskstack0_slot10, 296, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot11, .bss.core0.os_taskstack0_slot11, 104, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot12, .bss.core0.os_taskstack0_slot12, 104, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot13, .bss.core0.os_taskstack0_slot13, 168, 32);
#endif

/* Interrupt stacks */
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_kernStack0, .bss.core0.os_kernstack0, 1360, 32);
#endif
