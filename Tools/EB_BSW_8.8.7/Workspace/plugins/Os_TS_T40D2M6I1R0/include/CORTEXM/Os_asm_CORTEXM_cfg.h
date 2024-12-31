/* Os_asm_CORTEXM_cfg.h - configuration dependent assembly macros.
 *
 * This file contains assembly macros that are configuration dependent.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: Os_asm_CORTEXM_cfg.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM_CORTEXM_CFG_H
#define OS_ASM_CORTEXM_CFG_H

#include <Os_configuration.h>
#include <Os_kernel.h>

#if (OS_CORTEXM_INT_MUX == OS_CORTEXM_INT_MUX_CPUSS)
#include <CORTEXM/Os_CORTEXM_cy_cpuss.h>
#endif

/* Sanity checks for configuration macros. */

#ifndef OS_HASMEMPROT
#error "OS_HASMEMPROT undefined"
#endif

#ifndef OS_NAPPSNONPRIV
#error "OS_NAPPSNONPRIV undefined"
#endif

#ifndef OS_CONFIGMODE
#error "OS_CONFIGMODE undefined"
#endif

#ifndef OS_DBGPROT
#error "OS_DBGPROT undefined"
#endif

#ifndef OS_DBGPROT_OFF
#error "OS_DBGPROT_OFF undefined"
#endif

#ifndef OS_ASM_LABEL
#error "OS_ASM_LABEL undefined"
#endif

#ifndef OS_ASM_DATALABEL
#error "OS_ASM_DATALABEL undefined"
#endif

#if (OS_HASMEMPROT != 0)
#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM)
#ifndef OS_MPU_RAM_RNR
#error "OS_MPU_RAM_RNR undefined"
#endif
#ifndef OS_MPU_KERNSTACK_RNR
#error "OS_MPU_KERNSTACK_RNR undefined"
#endif
#ifndef OS_MPU_IO_PRIV_RNR
#error "OS_MPU_IO_PRIV_RNR undefined"
#endif
#endif /* (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM) */
#endif /* (OS_HASMEMPROT != 0) */

#if ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP))
/* Address of CPACR */
#define OS_CPACR_ADDR_LO	0xED88
#define OS_CPACR_ADDR_HI	0xE000
#endif

/* OS_ENABLE_FPU/OS_DISABLE_FPU - enables/disables the FPU
 *
 * Parameters:
 * - addrR	register used for CPACR address.
 * - tmpR	register used to store temporary value.
 * - storeR	register used to store old CPACR value.
 *			Could be same as tmpR, in this case, old value is not stored.
 *
 * Precondition: Os_config.h is included.
 *
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P3(OS_ENABLE_FPU, addrR, tmpR, storeR)
#if ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP))
	/* Enable VFP coprocessor in CPACR */
	movw	OS_PAR(addrR, 1), #(OS_CPACR_ADDR_LO)
	movt	OS_PAR(addrR, 1), #(OS_CPACR_ADDR_HI)
	ldr		OS_PAR(storeR, 3), [OS_PAR(addrR, 1)]
	orr		OS_PAR(tmpR, 2), OS_PAR(storeR, 3), #0x00f00000	/*  Mask cp10, cp11 to o11 */
	str		OS_PAR(tmpR, 2), [OS_PAR(addrR, 1)]
#endif
OS_MACRO_END()

OS_MACRO_PREPARE_START()
OS_MACRO_START_P3(OS_DISABLE_FPU, addrR, tmpR, storeR)
#if ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP))
	/* Disable VFP coprocessor in CPACR */
	movw	OS_PAR(addrR, 1), #(OS_CPACR_ADDR_LO)
	movt	OS_PAR(addrR, 1), #(OS_CPACR_ADDR_HI)
	ldr		OS_PAR(storeR, 3), [OS_PAR(addrR, 1)]
	movw	OS_PAR(tmpR, 2), #(0xffff)
	movt	OS_PAR(tmpR, 2), #(0xff0f)
	and		OS_PAR(tmpR, 2), OS_PAR(storeR, 3), OS_PAR(tmpR, 2)	/*  Mask cp10, cp11 to o00 */
	str		OS_PAR(tmpR, 2), [OS_PAR(addrR, 1)]
#endif
OS_MACRO_END()

#if (OS_HASMEMPROT != 0)
#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM)

/* Offsets of MPU registers. */
#define OS_MPU_RNR		8		/* region number register */
#define OS_MPU_RASR		16		/* region attribute and size register */

/* OS_GET_MPU_BASE_ADDR - get the MPU registers' base address
 *
 * This macro gets the MPU base address.
 *
 * Parameters:
 * - destR	MPU base address will be stored in this register.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P1(OS_GET_MPU_BASE_ADDR, destR)
	movw	OS_PAR(destR, 1), #0xED90
	movt	OS_PAR(destR, 1), #0xE000
OS_MACRO_END()

/* OS_ENTER_NON_TRUSTED_ARM - prepares the MPU to enter a non-trusted entity
 *
 * This macro
 * - disables the global I/O region IO_PRIV
 * - enables the kernel stack region KERNSTACK
 * - downgrades the global RAM region's access rights to r--r--
 * This is equal to entering non-trusted mode.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P2(OS_ENTER_NON_TRUSTED_ARM, reg1, reg2)
	OS_GET_MPU_BASE_ADDR OS_PAR(reg1, 1)
	mov		OS_PAR(reg2, 2), #OS_MPU_IO_PRIV_RNR
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RNR]
	ldr		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RASR]
	bic		OS_PAR(reg2, 2), #OS_CORTEXM_MPU_RASR_ENABLE
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RASR]
	mov		OS_PAR(reg2, 2), #OS_MPU_KERNSTACK_RNR
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RNR]
	ldr		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RASR]
	orr		OS_PAR(reg2, 2), #OS_CORTEXM_MPU_RASR_ENABLE
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RASR]
	mov		OS_PAR(reg2, 2), #OS_MPU_RAM_RNR
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RNR]
	ldr		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RASR]
	orr		OS_PAR(reg2, 2), #OS_CORTEXM_MPU_RASR_S_RO
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RASR]
OS_MACRO_END()

/* OS_LEAVE_NON_TRUSTED_ARM - prepares the MPU to enter the kernel
 *
 * This macro
 * - enables the global I/O region IO_PRIV and stores the old enable bit
 *   value in register "result"
 * - upgrades the global RAM region's access rights to rw-rw-
 * - disables the kernel stack region KERNSTACK.
 * This is equal to entering trusted mode.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P3(OS_LEAVE_NON_TRUSTED_ARM, reg1, reg2, result)
	OS_GET_MPU_BASE_ADDR OS_PAR(reg1, 1)
	mov		OS_PAR(reg2, 2), #OS_MPU_IO_PRIV_RNR
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RNR]
	ldr		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RASR]
	and		OS_PAR(result, 3), OS_PAR(reg2, 2), #1
	orr		OS_PAR(reg2, 2), #OS_CORTEXM_MPU_RASR_ENABLE
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RASR]
	mov		OS_PAR(reg2, 2), #OS_MPU_RAM_RNR
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RNR]
	ldr		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RASR]
	bic		OS_PAR(reg2, 2), #OS_CORTEXM_MPU_RASR_S_RO
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RASR]
	mov		OS_PAR(reg2, 2), #OS_MPU_KERNSTACK_RNR
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RNR]
	ldr		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RASR]
	bic		OS_PAR(reg2, 2), #OS_CORTEXM_MPU_RASR_ENABLE
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RASR]
OS_MACRO_END()

/* OS_RESTORE_NON_TRUSTED_ARM - conditionally prepares the MPU to enter a
 * non-trusted entity
 *
 * If the value in register "trusted" is 0, this macro
 * behaves exactly like OS_ENTER_NON_TRUSTED_ARM.
 * If the value in register "trusted" is 1, this macro
 * does nothing.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P3(OS_RESTORE_NON_TRUSTED_ARM, reg1, reg2, trusted)
	tst		OS_PAR(trusted, 3), #1
	bne		1f
	OS_ENTER_NON_TRUSTED_ARM OS_PAR(reg1, 1), OS_PAR(reg2, 2)
1:
OS_MACRO_END()

#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_NXP)

/* OS_GET_MPU_CESR_ADDR - get the MPU CESR address
 *
 * This macro gets the CESR register address.
 *
 * Parameters:
 * - destR	CESR address will be stored in this register.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P1(OS_GET_MPU_CESR_ADDR, destR)
	movw	OS_PAR(destR, 1), #0xD000
	movt	OS_PAR(destR, 1), #0x4000
OS_MACRO_END()

/* OS_ENABLE_MPU - enable MPU
 *
 * This macro unconditionally enables the MPU.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P2(OS_ENABLE_MPU, reg1, reg2)
	OS_GET_MPU_CESR_ADDR OS_PAR(reg1, 1)
	ldr		OS_PAR(reg2, 2), [OS_PAR(reg1, 1)]
	orr		OS_PAR(reg2, 2), #OS_NXPMPU_CESR_VLD
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1)]
OS_MACRO_END()

/* OS_DISABLE_MPU - disable MPU and store state
 *
 * Disables the MPU and stores the old enable bit
 * value in register "result".
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P3(OS_DISABLE_MPU, reg1, reg2, result)
	OS_GET_MPU_CESR_ADDR OS_PAR(reg1, 1)
	ldr		OS_PAR(reg2, 2), [OS_PAR(reg1, 1)]
	and		OS_PAR(result, 3), OS_PAR(reg2, 2), #OS_NXPMPU_CESR_VLD
	bic		OS_PAR(reg2, 2), #OS_NXPMPU_CESR_VLD
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1)]
OS_MACRO_END()

/* OS_RESTORE_MPU - restore MPU enabled state
 *
 * Restores the enable bit of the MPU to the value
 * in register "trusted".
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P3(OS_RESTORE_MPU, reg1, reg2, trusted)
	OS_GET_MPU_CESR_ADDR OS_PAR(reg1, 1)
	ldr		OS_PAR(reg2, 2), [OS_PAR(reg1, 1)]
	bic		OS_PAR(reg2, 2), #OS_NXPMPU_CESR_VLD
	orr		OS_PAR(reg2, 2), OS_PAR(trusted, 3)
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1)]
OS_MACRO_END()

#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)

/* Offsets of MPU registers. */
#define OS_MPU_RNR		8			/* region number register */
#define OS_MPU_RLAR		16			/* region limit address register */

/* OS_GET_MPU_BASE_ADDR - get the MPU registers' base address
 *
 * This macro gets the MPU base address.
 *
 * Parameters:
 * - destR	MPU base address will be stored in this register.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P1(OS_GET_MPU_BASE_ADDR, destR)
	movw	OS_PAR(destR, 1), #0xED90
	movt	OS_PAR(destR, 1), #0xE000
OS_MACRO_END()

/* OS_DISABLE_REGION - unconditionally disable region
 *
 * This macro disables the region denoted by the index in register "region".
 * "base" contains the MPU base address.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P2(OS_DISABLE_REGION, base, region)
	str		OS_PAR(region, 2), [OS_PAR(base, 1), #OS_MPU_RNR]
	ldr		OS_PAR(region, 2), [OS_PAR(base, 1), #OS_MPU_RLAR]
	bic		OS_PAR(region, 2), #OS_MPU_RLAR_EN
	str		OS_PAR(region, 2), [OS_PAR(base, 1), #OS_MPU_RLAR]
OS_MACRO_END()

/* OS_ENABLE_REGION - unconditionally enable region
 *
 * This macro enables the region denoted by the index in register "region".
 * "base" contains the MPU base address.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P2(OS_ENABLE_REGION, base, region)
	str		OS_PAR(region, 2), [OS_PAR(base, 1), #OS_MPU_RNR]
	ldr		OS_PAR(region, 2), [OS_PAR(base, 1), #OS_MPU_RLAR]
	orr		OS_PAR(region, 2), #OS_MPU_RLAR_EN
	str		OS_PAR(region, 2), [OS_PAR(base, 1), #OS_MPU_RLAR]
OS_MACRO_END()

/* OS_ENABLE_DYNREG - conditionally enable dynamic region
 *
 * This macro enables the dynamic region denoted by the index in register
 * "region" if the attribute index is unequal to zero, i.e., if it is used.
 * "base" contains the MPU base address.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P2(OS_ENABLE_DYNREG, base, region)
	str		OS_PAR(region, 2), [OS_PAR(base, 1), #OS_MPU_RNR]
	ldr		OS_PAR(region, 2), [OS_PAR(base, 1), #OS_MPU_RLAR]
	tst		OS_PAR(region, 2), #OS_MPU_RLAR_ATTR_MASK
	itt		NE
	orrne	OS_PAR(region, 2), #OS_MPU_RLAR_EN
	strne	OS_PAR(region, 2), [OS_PAR(base, 1), #OS_MPU_RLAR]
OS_MACRO_END()

/* OS_ENTER_NON_TRUSTED_ARMV8 - prepares the MPU to enter a non-trusted entity
 *
 * This macro
 * - disables the global I/O region
 * - disables the global RAM region
 * - enables the kernel stack region (first dynamic region)
 * - enables all further dynamic regions if they're actually used
 *   in the inverse order compared to OS_LEAVE_NON_TRUSTED_ARMV8
 *   (to enable the possibly present ISR/hook stack as early as
 *   possible).
 * This is equal to entering non-trusted mode.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P2(OS_ENTER_NON_TRUSTED_ARMV8, reg1, reg2)
	OS_GET_MPU_BASE_ADDR OS_PAR(reg1, 1)
	mov		OS_PAR(reg2, 2), #OS_MPU_IO_PRIV_RNR
	OS_DISABLE_REGION OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_RAM_RNR
	OS_DISABLE_REGION OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_KERNELSTACK_RNR
	OS_ENABLE_REGION OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+8
	OS_ENABLE_DYNREG OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+7
	OS_ENABLE_DYNREG OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+6
	OS_ENABLE_DYNREG OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+5
	OS_ENABLE_DYNREG OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+4
	OS_ENABLE_DYNREG OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+3
	OS_ENABLE_DYNREG OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+2
	OS_ENABLE_DYNREG OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+1
	OS_ENABLE_DYNREG OS_PAR(reg1, 1), OS_PAR(reg2, 2)
OS_MACRO_END()

/* OS_LEAVE_NON_TRUSTED_ARMV8 - prepares the MPU to enter the kernel
 *
 * This macro
 * - enables the global I/O region and stores the old enable bit
 *   value in register "result"
 * - disables all dynamic regions (incl. kernel stack region); disables
 *   the kernel stack region and the last dynamic region (which contains
 *   ISR/hook stack if present) as late as possible to reduce the corridor
 *   where nested NMIs/HardFaults may lead to lock-ups
 * - enables the global RAM region.
 * This is equal to entering trusted mode.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P3(OS_LEAVE_NON_TRUSTED_ARMV8, reg1, reg2, result)
	OS_GET_MPU_BASE_ADDR OS_PAR(reg1, 1)
	mov		OS_PAR(reg2, 2), #OS_MPU_IO_PRIV_RNR
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RNR]
	ldr		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RLAR]
	and		OS_PAR(result, 3), OS_PAR(reg2, 2), #OS_MPU_RLAR_EN
	orr		OS_PAR(reg2, 2), #OS_MPU_RLAR_EN
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1), #OS_MPU_RLAR]
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+1
	OS_DISABLE_REGION OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+2
	OS_DISABLE_REGION OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+3
	OS_DISABLE_REGION OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+4
	OS_DISABLE_REGION OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+5
	OS_DISABLE_REGION OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+6
	OS_DISABLE_REGION OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+7
	OS_DISABLE_REGION OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_FIRST_DYN_REGION+8
	OS_DISABLE_REGION OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_KERNELSTACK_RNR
	OS_DISABLE_REGION OS_PAR(reg1, 1), OS_PAR(reg2, 2)
	mov		OS_PAR(reg2, 2), #OS_MPU_RAM_RNR
	OS_ENABLE_REGION OS_PAR(reg1, 1), OS_PAR(reg2, 2)
OS_MACRO_END()

/* OS_RESTORE_NON_TRUSTED_ARMV8 - conditionally prepares the MPU to enter a
 * non-trusted entity
 *
 * If the value in register "trusted" is 0, this macro
 * behaves exactly like OS_ENTER_NON_TRUSTED_ARMV8.
 * If the value in register "trusted" is 1, this macro
 * does nothing.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P3(OS_RESTORE_NON_TRUSTED_ARMV8, reg1, reg2, trusted)
	tst		OS_PAR(trusted, 3), #1
	bne		1f
	OS_ENTER_NON_TRUSTED_ARMV8 OS_PAR(reg1, 1), OS_PAR(reg2, 2)
1:
OS_MACRO_END()

#else /* OS_CORTEXM_MPU_TYPE */
#error "MPU not supported, check OS_CORTEXM_MPU_TYPE"
#endif /* OS_CORTEXM_MPU_TYPE */
#endif /* (OS_HASMEMPROT != 0) */

/* OS_ENTER_NON_TRUSTED - enter non-trusted mode
 *
 * This macro delegates entering non-trusted mode to macros specific
 * to the MPU variant. They may use both parameter registers at
 * their own wishes to store intermediate values.
 *
 * Precondition: Os_config.h is included.
 *
 * ATTENTION: Do not use this macro in configuration-independent files,
 *            i.e. use this macro only for files in src/.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P2(OS_ENTER_NON_TRUSTED, reg1, reg2)
#if (OS_HASMEMPROT != 0) && (OS_NAPPSNONPRIV != 0) && ((OS_CONFIGMODE & OS_DBGPROT) != OS_DBGPROT_OFF)
#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM)
	OS_ENTER_NON_TRUSTED_ARM OS_PAR(reg1, 1), OS_PAR(reg2, 2)
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_NXP)
	OS_ENABLE_MPU OS_PAR(reg1, 1), OS_PAR(reg2, 2)
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
	OS_ENTER_NON_TRUSTED_ARMV8 OS_PAR(reg1, 1), OS_PAR(reg2, 2)
#endif
	dsb
	isb
#endif
OS_MACRO_END()

/* OS_LEAVE_NON_TRUSTED - leave non-trusted mode
 *
 * This macro delegates leaving non-trusted mode to macros specific
 * to the MPU variant. The first two register parameters may be used
 * by the implementing macros at will to store intermediate values,
 * the register "result" is used to store the old "in-non-trusted mode"
 * state in an appropriate form to restore the state with the macro
 * OS_RESTORE_NON_TRUSTED. The actual values which signify "trusted"
 * vs. "non-trusted" may depend on the MPU variant.
 *
 * Precondition: Os_config.h is included.
 *
 * ATTENTION: Do not use this macro in configuration-independent files,
 *            i.e. use this macro only for files in src/.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P3(OS_LEAVE_NON_TRUSTED, reg1, reg2, result)
#if (OS_HASMEMPROT != 0) && (OS_NAPPSNONPRIV != 0) && ((OS_CONFIGMODE & OS_DBGPROT) != OS_DBGPROT_OFF)
#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM)
	OS_LEAVE_NON_TRUSTED_ARM OS_PAR(reg1, 1), OS_PAR(reg2, 2), OS_PAR(result, 3)
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_NXP)
	OS_DISABLE_MPU OS_PAR(reg1, 1), OS_PAR(reg2, 2), OS_PAR(result, 3)
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
	OS_LEAVE_NON_TRUSTED_ARMV8 OS_PAR(reg1, 1), OS_PAR(reg2, 2), OS_PAR(result, 3)
#endif
	dsb
	isb
#endif
OS_MACRO_END()

/* OS_RESTORE_NON_TRUSTED - restore non-trusted mode
 *
 * This macro delegates re-entering non-trusted mode to macros specific
 * to the MPU variant. The first two register parameters may be used
 * by the implementing macros at will to store intermediate values,
 * the register "trusted" contains a value as returned by the macro
 * OS_LEAVE_NON_TRUSTED to restore the state as appropriate.
 *
 * Precondition: Os_config.h is included.
 *
 * ATTENTION: Do not use this macro in configuration-independent files,
 *            i.e. use this macro only for files in src/.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P3(OS_RESTORE_NON_TRUSTED, reg1, reg2, trusted)
#if (OS_HASMEMPROT != 0) && (OS_NAPPSNONPRIV != 0) && ((OS_CONFIGMODE & OS_DBGPROT) != OS_DBGPROT_OFF)
#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM)
	OS_RESTORE_NON_TRUSTED_ARM OS_PAR(reg1, 1), OS_PAR(reg2, 2), OS_PAR(trusted, 3)
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_NXP)
	OS_RESTORE_MPU OS_PAR(reg1, 1), OS_PAR(reg2, 2), OS_PAR(trusted, 3)
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
	OS_RESTORE_NON_TRUSTED_ARMV8 OS_PAR(reg1, 1), OS_PAR(reg2, 2), OS_PAR(trusted, 3)
#endif
	dsb
	isb
#endif
OS_MACRO_END()

/* DispatchInterruptEntry: Macro with common instructions for interrupt entry.
 * Will disable interrupts & MPU and save the remains of the hardware context.
 *
 * isrid: number of ISR.
 * entry: address of entry function
 * exit: address of exit function
 * level: selected locking level
 * corevar: Label with address of kernel core variables.
 *
 * Precondition: Os_config.h is included.
 *
 * ATTENTION: Do not use this macro in configuration-independent files,
 *            i.e. use this macro only for files in src/.
 */
OS_MACRO_PREPARE_START()
OS_MACRO_START(DispatchInterruptEntry)
	/* we are now in handler mode, interrupts still enabled */
	/* Disable interrupts */
	cpsid	i

	OS_LEAVE_NON_TRUSTED	r0, r1, r2
	OS_DISABLE_FPU			r0, r1, r3
	/* Save non-volatile registers */
	push	{r4-r11, lr}
	/* Save old MPU state and FPU state or gap for alignment (no FPU) */
	push	{r2, r3}
OS_MACRO_END()

/* DispatchInterruptMain: Macro to dispatch one interrupt.
 * isrid: number of ISR.
 * entry: address of entry function
 * exit: address of exit function
 * corevar: Label with address of kernel core variables.
 *
 * Precondition: Os_config.h is included.
 *
 * ATTENTION: Do not use this macro in configuration-independent files,
 *            i.e. use this macro only for files in src/.
 */
OS_MACRO_PREPARE_START()
OS_MACRO_START_P5(DispatchInterruptMain, isrid, entry, exit, level, corevar)
	/* OS_inKernel = 1; */
	OS_GET_KERNEL_PTR	OS_PAR(corevar, 5), r1, r0
	/* save old value of inKernel into r4 */
	ldrb	r4, [r1, #OS_T_INKERNEL]
	mov		r0, #1
	strb	r0, [r1, #OS_T_INKERNEL]
	mov		r2, #OS_PAR(level, 4)			/* set interrupt disabling level */
	OS_SETLEVEL		r2, r0
	push	{r0}							/* save previous lock level on stack */

	/* now it's safe to enable all interrupts */
	cpsie	i
	/* <entry>(<isrid>); call entry function with interrupt id */
	mov		r0, #OS_PAR(isrid, 1)
	bl		OS_PAR(entry, 2)

	mov		r0,r4
	/* <exit>(); call exit function. */
	bl		OS_PAR(exit, 3)
	/* NOT REACHED */
OS_MACRO_END()

/* DispatchInterrupt: Handle interrupt entry and dispatch interrupt.
 * isrid: number of ISR.
 * entry: address of entry function
 * exit: address of exit function
 * level: selected locking level
 * corevar: Label with address of kernel core variables.
 *
 * Precondition: Os_config.h is included.
 *
 * ATTENTION: Do not use this macro in configuration-independent files,
 *            i.e. use this macro only for files in src/.
 */
OS_MACRO_PREPARE_START()
OS_MACRO_START_P5(DispatchInterrupt, isrid, entry, exit, level, corevar)
	DispatchInterruptEntry
	DispatchInterruptMain	OS_PAR(isrid, 1), OS_PAR(entry, 2), OS_PAR(exit, 3), OS_PAR(level, 4), OS_PAR(corevar, 5)
OS_MACRO_END()

#if (OS_CORTEXM_INT_MUX == OS_CORTEXM_INT_MUX_CPUSS)
/* DemuxInterrupt: Macro to call the actual dispatch code of a multiplexed interrupt.
 *
 * The dispatch functions generated for multiplexed interrupts by the above macro will
 * be placed within the interrupt vector table after the actual CPU interrupts.
 * This shim retrieves the ID of the multiplexed interrupt and jumps to its actual dispatch code.
 * This macro only works with a CPUSS-based interrupt multiplexer from Cypress!
 *
 * isrid: number of ISR.
 * coreid: Id of the core executing this code
 * inttable: interrupt table of the core executing this code
 */
OS_MACRO_PREPARE_START()
OS_MACRO_START_P3(DemuxInterrupt, isrid, coreid, inttable)
	movw	r0, #(OS_CORTEXM_CPUSS_BASE_LO)
	movt	r0, #(OS_CORTEXM_CPUSS_BASE_HI)
	mov		r1, #OS_PAR(isrid, 1)

	/* calculate offset to our core's core control block */
	mov		r2, #OS_PAR(coreid, 2)
	lsl		r3, r2, #(OS_CY_CPUSS_CORECTL_Shift)
	add		r2, r3, #(OS_CY_CPUSS_INT_STATUS_OFF)
	lsl		r1, r1, #2		/* offset from start of interrupt status registers to register of this CPU interrupt */
	add		r2, r1, r2
	add		r2, r0, r2

	/* interrupt status register address get, read and process system interrupt Id */
	ldr		r2, [r2]
	mov		r0, #1
	lsls	r0, r0, #31		/* highest bit is valid bit */
	ands	r0, r2
	beq		DispatchUnknownInterrupt	/* valid bit not set, something went wrong */
	bfc		r2, #31, #1		/* strip valid bit to get interrupt Id */
	mov		r3, #(OS_CORTEXM_BANKED_SOURCES)
	add		r2, r2, r3		/* vector index = system Id + CPU IRQs */
	lsl		r2, r2, #2

	/* interrupt vector table offset get, now retrieve the address of the interrupt vector */
	ldr		r3, =OS_PAR(inttable, 3)
	bfc		r3, #0, #1		/* clear thumb bit in address */
	add		r3, r3, r2
	ldr		r3, [r3]

	/* jump into interrupt dispatch function */
	bx		r3

OS_MACRO_END()
#endif

#endif

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
