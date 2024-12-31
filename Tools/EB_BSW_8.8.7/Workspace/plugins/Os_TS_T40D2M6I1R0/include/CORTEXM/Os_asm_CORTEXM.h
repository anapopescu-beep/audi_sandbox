/* Os_asm_CORTEXM.h
 *
 * This file includes the appropriate Os_asm_CORTEXM_xxx.h include file
 * depending on the chosen toolchain.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_asm_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_ASM_CORTEXM_H
#define OS_ASM_CORTEXM_H

#include <Os_asm_common.h>
#include <CORTEXM/Os_CORTEXM_cpu.h>
#include <CORTEXM/Os_CORTEXM_core.h>

/* Include the appropriate abstraction file for the toolchain
*/
#if (OS_TOOL==OS_ticgt)
#include <CORTEXM/Os_asm_CORTEXM_ticgt.h>
#elif (OS_TOOL==OS_gnu)
#include <CORTEXM/Os_asm_CORTEXM_gnu.h>
#elif (OS_TOOL==OS_ghs)
#include <CORTEXM/Os_asm_CORTEXM_ghs.h>
#elif (OS_TOOL==OS_iar)
#include <CORTEXM/Os_asm_CORTEXM_iar.h>
#elif (OS_TOOL==OS_arm5)
#include <CORTEXM/Os_asm_CORTEXM_arm5.h>
#elif (OS_TOOL==OS_armkeil)
#include <CORTEXM/Os_asm_CORTEXM_armkeil.h>
#elif (OS_TOOL==OS_diab)
#include <CORTEXM/Os_asm_CORTEXM_diab.h>
#else
#error "Unknown or unsupported toolchain. Check your Makefiles!"
#endif

/*
 * OS_CAT
 *
 * Concatenates the two specified parameters x and y by use of another C macro.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_CAT
#define OS_CAT(x,y)				OS_INNER_CAT(x,y)
#endif

/*
 * OS_INNER_CAT
 *
 * Concatenates the two specified parameters x and y with ##.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_INNER_CAT
#define OS_INNER_CAT(x,y)		x##y
#endif

/*
 * OS_EMPTY
 *
 * Just an empty macro definition. This macro may be used to encapsulate a space character.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_EMPTY
#define OS_EMPTY
#endif

/*
 * OS_BLANK
 *
 * Encapsulate a space character to avoid the preprocessor to remove it.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_BLANK
#define OS_BLANK	OS_EMPTY OS_EMPTY
#endif


/*
 * OS_ASM_DATALABEL
 *
 * Some assemblers (e.g., IAR) require strict usage of DATA directive before data label.
 *
 * IAR Note 1: "Labels placed in Thumb code, i.e. that appear after a CODE16 directive, always have
 * bit 0 set (i.e. an odd label) in IASMARM. ARMASM, on the other hand, does not set bit 0
 * on symbols in expressions that are solved at assembly time."
 *
 * IAR Note 2: "Always use the DATA directive when defining data in a
 * Thumb code section with DC8, DC16, or DC32, otherwise
 * labels on the data will have bit 0 set."
 *
 * Keep default value of 'OS_ASM_DATALABEL' empty by default
*/
#ifndef OS_ASM_DATALABEL
#define OS_ASM_DATALABEL	/* Nothing */
#endif

 
/*
 * OS_ASM_SRC_END
 *
 * This macro marks the end of an assembly source file.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 *        The default implementation is empty, because only a few assemblers need it.
*/
#ifndef OS_ASM_SRC_END
#define OS_ASM_SRC_END
#endif

/* Assembler directive to set the file name
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef OS_file
#define OS_file(name)	.file   #name
#endif

/*
 * Assembler directive to define an external symbol.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef OS_global
#define OS_global	.globl
#endif

/*
 * Assembler directive to reference an external symbol.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef OS_extern
#define OS_extern	.extern
#endif

/*
 * Assembler directive to define a machine word (32 bit).
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef OS_word
#define OS_word		.long
#endif

/*
 * Assembler directive to define a machine half-word (16 bit).
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef OS_short
#define OS_short	.short
#endif

/*
 * Assembler directive to align the following data or code to the given amount of
 * bytes (b) or power of 2 (p2).
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef OS_align
#define OS_align(b, p2)	.p2align p2
#endif

/*
 * Create a label with name name. Allowed characters for name are [a-zA-Z0-9_]. It
 * must not start with a number. Labels created in this manner are guaranteed to
 * result in a symbol with name name, which may be exported by OS_global.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef OS_ASM_LABEL
#define OS_ASM_LABEL(name)	name:
#endif

/*
 * Assembler directive to start a text section (OS-code).
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef OS_ASM_SECTION_TEXT
#define OS_ASM_SECTION_TEXT		.section ".os_text", "ax", %progbits
#endif

/*
 * Assembler directive to select the THUMB instruction set.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef OS_ASM_CODE_THUMB
#define OS_ASM_CODE_THUMB	.thumb; .syntax unified
#endif

/*
 * Assembler directive to declare that the next label refers to a function
 * definition. The next label must be named <name>.
 * name: symbol name of the function.
 * Note: This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef OS_ASM_FUNC
#define OS_ASM_FUNC(name)		.type name, "function"
#endif

/*
 * Assembler directive to mark the end of a function.
 * name: symbol name of function.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef OS_ASM_END_FUNC
#define OS_ASM_END_FUNC(name)		.size name, . - name
#endif

/*
 * OS_PAR
 *
 * Expands the parameter to the proper parameter format in the macro body.
 * The expansion depends on the toolchain used.
 * The parameters param and number are different representations of assembly macro
 * parameters for different toolchains (either by-name or by-position).
 * - param         is the unmodified parameter name (e.g. Diab, GHS, GNU)
 * - number        is the parameter number like 3 for the 3rd parameter (e.g. CodeWarrior)
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_PAR
#define OS_PAR(param, number)	OS_INNER_CAT(\P, param)
#endif

/*
 * OS_MACRO_PREPARE_START
 *
 * This macro prepares the start of an assembly macro definition. It must be
 * followed in the next line by one of the OS_MACRO_START macros.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef OS_MACRO_PREPARE_START
#define OS_MACRO_PREPARE_START()	/* nothing */
#endif

/*
 * OS_MACRO_START
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has no parameters.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_MACRO_START
#define OS_MACRO_START(name)	.macro	name
#endif

/*
 * OS_MACRO_START_P1
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has one parameter p1.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_MACRO_START_P1
#define OS_MACRO_START_P1(name, p1)		\
	.macro name							\
		OS_INNER_CAT(P, p1)
#endif

/*
 * OS_MACRO_START_P2
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has two parameters p1 and p2.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_MACRO_START_P2
#define OS_MACRO_START_P2(name, p1, p2)	\
	.macro name							\
		OS_INNER_CAT(P, p1),			\
		OS_INNER_CAT(P, p2)
#endif

/*
 * OS_MACRO_START_P3
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has three parameters p1, p2 and p3.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_MACRO_START_P3
#define OS_MACRO_START_P3(name, p1, p2, p3)	\
	.macro	name							\
		OS_INNER_CAT(P, p1),				\
		OS_INNER_CAT(P, p2),				\
		OS_INNER_CAT(P, p3)
#endif

/*
 * OS_MACRO_START_P4
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has four parameters p1, p2, p3 and p4.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_MACRO_START_P4
#define OS_MACRO_START_P4(name, p1, p2, p3, p4)	\
	.macro	name								\
		OS_INNER_CAT(P, p1),					\
		OS_INNER_CAT(P, p2),					\
		OS_INNER_CAT(P, p3),					\
		OS_INNER_CAT(P, p4)
#endif

/*
 * OS_MACRO_START_P5
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has five parameters p1, p2, p3, p4 and p5.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_MACRO_START_P5
#define OS_MACRO_START_P5(name, p1, p2, p3, p4, p5)	\
	.macro	name									\
		OS_INNER_CAT(P, p1),						\
		OS_INNER_CAT(P, p2),						\
		OS_INNER_CAT(P, p3),						\
		OS_INNER_CAT(P, p4),						\
		OS_INNER_CAT(P, p5)
#endif

/*
 * OS_MACRO_START_P6
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has six parameters p1, p2, p3, p4, p5 and p6.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_MACRO_START_P6
#define OS_MACRO_START_P6(name, p1, p2, p3, p4, p5, p6)	\
	.macro	name									\
		OS_INNER_CAT(P, p1),						\
		OS_INNER_CAT(P, p2),						\
		OS_INNER_CAT(P, p3),						\
		OS_INNER_CAT(P, p4),						\
		OS_INNER_CAT(P, p5),						\
		OS_INNER_CAT(P, p6)
#endif

/*
 * OS_MACRO_END
 *
 * This macro ends an assembly macro definition.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_MACRO_END
#define OS_MACRO_END()	OS_BLANK			.endm
#endif

/* ExceptionTable section.
 *
 * The section containing the exception vector table.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_ASM_SECTION_EXCTAB
#define OS_ASM_SECTION_EXCTAB(_coreno)	.section ExceptionTable_C ## _coreno, "ax", %progbits
#endif

/* InterruptTable section.
 *
 * The section containing the interrupt vector table.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_ASM_SECTION_INTTAB
#define OS_ASM_SECTION_INTTAB(_coreno)	.section InterruptTable_C ## _coreno, "ax", %progbits
#endif

/* Name of the xPSR register for mrs instructions.
 *
 * This macros defines the name of the xPSR register for mrs instructions.
 * UAL defines it to xPSR.
 *
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_ASM_XPSR
#define OS_ASM_XPSR	xpsr
#endif

/* CHECK: NOPARSE (Assembler macros) */

#if (OS_N_CORES_MAX > 1)
#if defined(OS_MSCM_CPXNUM_ADDR_HI) && defined(OS_MSCM_CPXNUM_ADDR_LO) && defined(OS_MSCM_CPXNUM_CM_START)
/* Get core Id using the NXP MSCM module.
 * destReg: will contain the core Id, after handling the Cortex-M CPN start.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P1(OS_ASM_GET_COREID, destReg)
	movw	OS_PAR(destReg, 1), #OS_MSCM_CPXNUM_ADDR_LO
	movt	OS_PAR(destReg, 1), #OS_MSCM_CPXNUM_ADDR_HI
	ldr		OS_PAR(destReg, 1), [OS_PAR(destReg, 1)]
	sub		OS_PAR(destReg, 1), OS_PAR(destReg, 1), #OS_MSCM_CPXNUM_CM_START
OS_MACRO_END()
#elif (OS_CORTEXM_INT_MUX == OS_CORTEXM_INT_MUX_CPUSS)
/* Get core Id by deriving it from our current bus master Id*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P1(OS_ASM_GET_COREID, destReg)
	movw	OS_PAR(destReg, 1), #OS_CORTEXM_CPUSS_BASE_LO
	movt	OS_PAR(destReg, 1), #OS_CORTEXM_CPUSS_BASE_HI
	ldr		OS_PAR(destReg, 1), [OS_PAR(destReg, 1)]
	lsr		OS_PAR(destReg, 1), OS_PAR(destReg, 1), #OS_CY_CPUSS_IDENTITY_MS_Shift
	rsb		OS_PAR(destReg, 1), OS_PAR(destReg, 1), #OS_CORTEXM_BUSMASTER_START
OS_MACRO_END()
#else
#error "Necessary feature to get core Ids is not available. Add appropriate implementation."
#endif
#endif /* (OS_N_CORES_MAX == 1) */

/* Get kernel pointer address for current core.
 * litBase: literal with address of OS_kernel_ptr
 * destReg: will contain the kernel pointer address after the macro is called.
 * sReg: Scratch Register
*/

OS_MACRO_PREPARE_START()
OS_MACRO_START_P3(OS_GET_KERNEL_PTR, litBase, destReg, sReg)
#if (OS_N_CORES_MAX <= 1)
	ldr		OS_PAR(destReg, 2),	OS_PAR(litBase, 1)
	ldr		OS_PAR(destReg, 2), [OS_PAR(destReg, 2)]
#else
	OS_ASM_GET_COREID	OS_PAR(sReg, 3)
	lsl 	OS_PAR(sReg, 3), OS_PAR(sReg, 3), #2
	ldr		OS_PAR(destReg, 2),	OS_PAR(litBase, 1)
	ldr		OS_PAR(destReg, 2), [OS_PAR(destReg, 2), OS_PAR(sReg, 3)]
#endif
OS_MACRO_END()

/* Create the literal with the SHCSR address for the macro OS_ACTIVATE_SVC.
 *
 * Use in the data section of an assembly file that uses OS_ACTIVATE_SVC.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START(OS_GENLIT_ACTIVATE_SVC)
	/* Data label: cover the following OS_ASM_LABEL declarations */
	OS_ASM_DATALABEL
OS_ASM_LABEL(OS_SHCSR_Addr)
	OS_word	OS_CORTEXM_SHCSR
OS_MACRO_END()

/* Activate the SVC-active flag in SHSCR.
 * reg1: scratch register used within the macro body.
 * reg2: scratch register used within the macro body.
 *
 * Precondition:
 * The macro OS_GENLIT_ACTIVATE_SVC has been used to generate
 * the literal with the address of the SHCSR.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P2(OS_ACTIVATE_SVC, reg1, reg2)
	ldr		OS_PAR(reg1, 1), OS_SHCSR_Addr
	ldr		OS_PAR(reg2, 2), [OS_PAR(reg1, 1)]
	orr		OS_PAR(reg2, 2), OS_PAR(reg2, 2), #OS_CORTEXM_SHCSR_SVCALLACT
	str		OS_PAR(reg2, 2), [OS_PAR(reg1, 1)]
	dsb
	isb
OS_MACRO_END()

/* Set the current interrupt lock level to level and
 * return the old level.
 *
 * level: register that contains the new level to set
 * oldLevel: register, into which the previous level is written to.
 *
 * constraints: level and oldLevel may not be the same register.
  *             interrupts are disabled by flag.
*/
OS_MACRO_PREPARE_START()
OS_MACRO_START_P2(OS_SETLEVEL, level, oldLevel)
	lsl		OS_PAR(level, 1), OS_PAR(level, 1), #OS_CORTEXM_INT_PRIO_SHIFT
	mrs		OS_PAR(oldLevel, 2), basepri
	lsr		OS_PAR(oldLevel, 2), OS_PAR(oldLevel, 2), #OS_CORTEXM_INT_PRIO_SHIFT
	msr		basepri, OS_PAR(level, 1)
OS_MACRO_END()

/* CHECK: PARSE */

#endif /* ! OS_ASM_CORTEXM_H */
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
