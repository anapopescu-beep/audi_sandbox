/* CORTEXM-cat2exit.asm
 *
 * Contains funtionality to return from a category 1 interrupt
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-cat1exit.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <CORTEXM/Os_asm_CORTEXM.h>
#include <CORTEXM/Os_CORTEXM_cpu.h>
#include <Os_kernel.h>

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB

	OS_global OS_CORTEXM_IntCat1Exit
	OS_extern OS_CORTEXM_IntReturnFromInterrupt
	OS_extern OS_kernel_ptr

	OS_align(4, 2)

	/* Data label: cover the following OS_ASM_LABEL declaration */
	OS_ASM_DATALABEL

	/* Address of the kernel pointer */
OS_ASM_LABEL(OS_kernelDataAddr)
	OS_word OS_kernel_ptr

/* OS_CORTEXM_IntCat1Exit(os_uint8_t inKernel)
 *
 * set OS_inKernel to old value and return from interrupt.
 */
	OS_ASM_FUNC(OS_CORTEXM_IntCat1Exit)
OS_ASM_LABEL(OS_CORTEXM_IntCat1Exit)
	/* OS_inKernel = inKernel */
	OS_GET_KERNEL_PTR	OS_kernelDataAddr, r1, r4

	strb	r0, [r1, #OS_T_INKERNEL]
	/* just return from interrupt */
	bl		OS_CORTEXM_IntReturnFromInterrupt

	OS_ASM_END_FUNC(OS_CORTEXM_IntCat1Exit)

	OS_ASM_SRC_END

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
