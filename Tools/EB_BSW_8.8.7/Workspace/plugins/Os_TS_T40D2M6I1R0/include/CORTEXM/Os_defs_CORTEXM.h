/* Os_defs_CORTEXM.h - CORTEXM definitions for derivative selection etc.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_defs_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_DEFS_CORTEXM_H
#define OS_DEFS_CORTEXM_H

/* CPUs. OS_CPU must be one of these.
 *
 * CAVEAT:
 * The existence of a CORTEXM derivative in this list does not imply a
 * commitment or intention to support the derivative.
 *
 * Tip: using a value of 0 is not recommended because "undefined" also means
 * zero in the preprocessor.
 * Some values were assigned in the past for obsolete ARM derivatives.
 * These numbers mentioned below are deprecated and not recommended to be used in future.
 * 0x001, 0x005, 0x006, 0x007, 0x008, 0x00E, 0x015, 0x01A, 0x01F
*/
#define OS_S32K14X			0x002
#define OS_MV88Q5050		0x00C	/* same as platforms */
#define OS_BCM89107			0x00E
#define OS_CYT4BF			0x01B	/* same as platforms */
#define OS_IMX8QMM4			0x01E	/* same as platforms */
#define OS_CYT2B95			0x020	/* same as platforms */
#define OS_S32G27X			0x021	/* same as platforms */
#define OS_MV88Q5072		0x022	/* same as platforms */
#define OS_MV88Q6113		0x023	/* same as platforms */
#define OS_IMX8DXLM4		0x024	/* same as platforms */
#define OS_S32K34X			0x025	/* same as platforms */
#define OS_CYT3DL			0x026	/* same as platforms */
#define OS_SAME5X			0x029	/* same as platforms */
#define OS_IMX8QXPM4		0x02A	/* same as platforms */
#define OS_RTL90XXA			0x02E	/* same as platforms */
#define OS_S32G399			0x035	/* same as platforms */
#define OS_S32K31X			0x036	/* same as platforms */
#define OS_S32Z27XM33		0x038	/* same as platforms */
#define OS_S32R45X			0x039	/* same as platforms */
#define OS_CYT2B75			0x03A	/* same as platforms */
#define OS_CYT4BB			0x03B	/* same as platforms */
#define OS_SAF85XXM7		0x034	/* same as platforms */
#define OS_SR6P6M4			0x03C	/* same as platforms */
/* Timer units, that can be present on a board.
 * OS_CORTEXM_TIMER must be a combination of these. Hence each definition must
 * specify a distinct bit.
 *
 * CAVEAT:
 * The existence of a timer unit in this list does not imply a
 * commitment or intention to support the timer unit.
*/
#define OS_CORTEXM_TIMER_FS_STM			0x00080		/* STM (Freescale) */
#define OS_CORTEXM_TIMER_N				0x00100		/* TimerN down-counter (MV88Q5050|MV88Q5072) */
#define OS_CORTEXM_TIMER_FS_LPIT		0x00200		/* Low-power Periodic Interrupt Timer (Freescale S32K14X) */
#define OS_CORTEXM_TIMER_BCM_DTM		0x00400		/* Broadcom Dual-Timer Module (BCM89107) */
#define OS_CORTEXM_TIMER_BCM_CCT		0x00800		/* Broadcom Capture Compare Timer (BCM89107) */
#define OS_CORTEXM_TIMER_CY_PWM			0x02000		/* Cypress traveo II Timer/Counter PWM */
#define OS_CORTEXM_TIMER_NXP_TPM		0x04000		/* Low Power Timer/Pulse Width Modulation Module (TPM) on IMX8QMM4. */
#define OS_CORTEXM_TIMER_FS_FTM			0x08000		/* FlexTimer Module (Freescale S32K14X) */
#define OS_CORTEXM_TIMER_SAME5X_TC		0x10000		/* TC Timer Counter for SAME5X derivatives */
#define OS_CORTEXM_TIMER_DWTIMER		0x20000		/* Synopsys DesignWare timer module */
#define OS_CORTEXM_TIMER_NXP_PIT		0x40000		/* Periodic Interrupt Timer (NXP S32K31X) */
#define OS_CORTEXM_TIMER_ARC			0x80000		/* Auto Reload or Compare Module */

/* The inKernel flag is set during IRQ entry.
 * This is necessary for the IUNIT, and doesn't hurt for other interrupt
 * controllers. If an interrupt occurs in the timeframe between the vector
 * entry and setting the locking mask, IUNIT will deliver this interrupt so
 * that the vector is taken right after enabling interrupts again.
 * As a consequence, OS_GetKernelData()->inKernel must be set prior to enabling
 * interrupts to avoid a nested interrupt handler to dispatch tasks.
 */
#define OS_USE_IRQ_ATOMIC_INKERNEL 1

/* Core architecture variant.
 *
 * CAVEAT:
 * The existence of an architecture variant in this list does not imply a
 * commitment or intention to support this variant.
 */
#define OS_CORTEXM_ARMV7			0x01
#define OS_CORTEXM_ARMV8			0x02

/* FPU that can be supported by the core.
 *
 * CAVEAT:
 * The existence of a FPU in this list does not imply a
 * commitment or intention to support the FPU.
 */
#define OS_CORTEXM_FPU_NONE			0x001		/* no FPU */
#define OS_CORTEXM_FPU_ARMV7		0x002		/* VFPv5 and VFPv4 with 16 DP / 32 SP registers */

/*	MPU:
 *	Usually CortexM has the ARM Core MPU, or no MPU at all.
 *	But some hardware manufacturers install their own MPU modules (NXP).
 *	CAVEAT:
 *	The existence of an MPU in this list does not imply a
 *	commitment or intention to support the MPU.
 *	NOTICE: the macro 'OS_USE_MPU' defines whether there is an MPU or not.
 */
 #define OS_CORTEXM_MPU_ARM		0x1u
 #define OS_CORTEXM_MPU_NXP		0x2u
#define OS_CORTEXM_MPU_ARMV8	0x3u

/* MSCM:
 * For NXP multi-core devices only:
 * Variant of the Miscellaneous System Control Module (mainly used for interrupt
 * routing).
 */
#define OS_CORTEXM_MSCM_3C		0x01		/* three-core variant */
#define OS_CORTEXM_MSCM_4C		0x02		/* four-core variant */

/* INT MUX:
 * Type of interrupt multiplexer.
 */
#define OS_CORTEXM_INT_MUX_NONE		0x00
#define OS_CORTEXM_INT_MUX_CPUSS	0x01	/* Cypress CPU Subsystem */

#endif /* ! OS_DEFS_CORTEXM_H */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
