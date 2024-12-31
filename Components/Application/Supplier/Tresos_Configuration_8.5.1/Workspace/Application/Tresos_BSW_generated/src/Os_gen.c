/* This file is generated automatically. DO NOT EDIT!!
 * 
 * EB tresos AutoCore OS 6.0.180 CORTEXM/S32K14X
 * (Build 20180906)
 * 
 * (c) 1998-2023 Elektrobit Automotive GmbH
 * Am Wolfsmantel 46
 * 91058 Erlangen
 * GERMANY
 * 
 * http://www.automotive.elektrobit.com
 * 
 */

#include <Os_config.h>
#include <Os_kernel.h>
#include <Os_tool.h>

#if OS_GENERATION_ID_OS_H!=0x21b85288UL
#error "Build-Ids of src\Os_gen.c and include\Os_user.h did not match! Hint: A wrong include\Os_user.h was most probably included."
#endif
#if OS_GENERATION_ID_OS_CONF_H!=0x21b85288UL
#error "Build-Ids of src\Os_gen.c and include\Os_config.h did not match! Hint: A wrong include\Os_config.h was most probably included."
#endif

const os_uint32_t OS_os_GenBuildId = 0x21b85288UL;

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

#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot0, .bss.core0.os_taskstack0_slot0, 152, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot1, .bss.core0.os_taskstack0_slot1, 152, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot2, .bss.core0.os_taskstack0_slot2, 216, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot3, .bss.core0.os_taskstack0_slot3, 152, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot4, .bss.core0.os_taskstack0_slot4, 216, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot5, .bss.core0.os_taskstack0_slot5, 152, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot6, .bss.core0.os_taskstack0_slot6, 56, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot7, .bss.core0.os_taskstack0_slot7, 152, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot8, .bss.core0.os_taskstack0_slot8, 152, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot9, .bss.core0.os_taskstack0_slot9, 280, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot10, .bss.core0.os_taskstack0_slot10, 280, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot11, .bss.core0.os_taskstack0_slot11, 88, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot12, .bss.core0.os_taskstack0_slot12, 152, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_taskStack0_slot13, .bss.core0.os_taskstack0_slot13, 152, 32);
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
OS_GEN_STACK(OS_kernStack0, .bss.core0.os_kernstack0, 1216, 32);
#endif

