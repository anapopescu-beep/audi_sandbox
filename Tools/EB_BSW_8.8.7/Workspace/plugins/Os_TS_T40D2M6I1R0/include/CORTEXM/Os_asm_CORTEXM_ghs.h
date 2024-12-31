/* Os_asm_CORTEXM_ghs.h
 *
 * This file is the toolchain-dependent include file for the Greenhills Multi
 * Assembler for CORTEXM.
 *
 * This file defines the macros used in assembler files in a way such that the
 * assembler files will compile with the Greenhlls Multi Assembler.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_asm_CORTEXM_ghs.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM_CORTEXM_GHS_H
#define OS_ASM_CORTEXM_GHS_H

/*
 * Assembler directive to define an external symbol.
 */
#define OS_global	.global

/*
 * Assembler directive to reference an external symbol.
 */
#define OS_extern	.import

/*
 * Assembler directive to define a machine word (32 bit).
 */
#define OS_word		.word

/*
 * Assembler directive to align the following data or code to the given amount of
 * bytes (b) or power of 2 (p2).
 */
#define OS_align(b, p2)	.align b

/*
 * Assembler directive to start a text section (OS-code).
 */
#define OS_ASM_SECTION_TEXT		.section ".os_text", "ax"

/*
 * Assembler directive to select the THUMB instruction set.
 */
#define OS_ASM_CODE_THUMB	.thumb2

/*
 * Assembler directive to declare that the next label refers to a function
 * definition. The next label must be named <name>.
 * name: symbol name of the function.
 */
#define OS_ASM_FUNC(name)		.type name, $function

/*
 * OS_PAR
 *
 * Expands the parameter to the proper parameter format in the macro body.
 * The expansion depends on the toolchain used.
 * The parameters param and number are different representations of assembly macro
 * parameters for different toolchains (either by-name or by-position).
 * - param         is the unmodified parameter name (e.g. Diab, GHS, GNU)
 * - number        is the parameter number like 3 for the 3rd parameter (e.g. CodeWarrior)
*/
#define OS_PAR(param, number)	param

/*
 * OS_MACRO_START_P1
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has one parameter p1.
*/
#define OS_MACRO_START_P1(name, p1)				.macro name p1

/*
 * OS_MACRO_START_P2
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has two parameters p1 and p2.
*/
#define OS_MACRO_START_P2(name, p1, p2)			.macro name p1 p2

/*
 * OS_MACRO_START_P3
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has three parameters p1, p2 and p3.
*/
#define OS_MACRO_START_P3(name, p1, p2, p3)		.macro	name p1 p2 p3

/*
 * OS_MACRO_START_P4
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has four parameters p1, p2, p3 and p4.
*/
#define OS_MACRO_START_P4(name, p1, p2, p3, p4)	.macro	name p1 p2 p3 p4

/*
 * OS_MACRO_START_P5
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has five parameters p1, p2, p3, p4 and p5.
*/
#define OS_MACRO_START_P5(name, p1, p2, p3, p4, p5)	.macro	name p1 p2 p3 p4 p5

/*
 * OS_MACRO_START_P6
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has six parameters p1, p2, p3, p4, p5 and p6.
*/
#define OS_MACRO_START_P6(name, p1, p2, p3, p4, p5, p6)	.macro	name p1 p2 p3 p4 p5 p6

/* ExceptionTable section.
 *
 * The section containing the exception vector table.
*/
#define OS_ASM_SECTION_EXCTAB(_coreno)	.section ExceptionTable_C ## _coreno, "ax"

/* InterruptTable section.
 *
 * The section containing the interrupt vector table (e.g. for Cortex-M CORTEXM cores).
*/
#define OS_ASM_SECTION_INTTAB(_coreno)	.section InterruptTable_C ## _coreno, "ax"

#ifdef OS_ASM
/* Define official CORTEXM mnemonics which are missing in the Greenhills assembler */
.macro	neg rDest rSrc
	rsb		rDest,rSrc,#0
	.endm
#endif /* OS_ASM */

#endif /* OS_ASM_CORTEXM_GHS_H */
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
