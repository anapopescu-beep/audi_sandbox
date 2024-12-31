/* Os_asm_CORTEXM_diab.h
 *
 * This file is the toolchain-dependent include file for the DIAB assembler
 * for CORTEXM.
 *
 * This file defines the macros used in assembler files in a way such that the
 * assembler files will compile with the DIAB assembler.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 * CHECK: RULE 402 OFF (these are assembler directives, not C)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_asm_CORTEXM_diab.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM_CORTEXM_DIAB_H
#define OS_ASM_CORTEXM_DIAB_H

/* Various assembler directives
*/
#define OS_global			.global
#define OS_extern			.extern
#define OS_short			.short
#define OS_long				.long
#define OS_byte				.byte
#define OS_word				.word
#define OS_space(size)		.space	(size)

/*
 * Assembler directive to declare that the next label refers to a function
 * definition. The next label must be named <name>.
 * name: symbol name of the function.
 */
#ifndef OS_ASM_FUNC
#define OS_ASM_FUNC(name)		.type name, function
#endif

#ifndef OS_USE_DIAB_V7	

/* 
 * Workarround for DIAB 5, assembler is not generating ldr.w where needed.
 * Ensure that assembler always generate a 32-bit ldr.w instructon.
 */
#define ldr					ldr.w

#define OS_align(b,p2)		.alignn	b
/*
 * OS_PAR
 *
 * Expands the parameter to the propper parameter format in the macro body.
 * The expansion depends on the toolchain used.
 * The parameters param and number are different representations of assembly macro
 * parameters for different toolchains (either by-name or by-position).
 * - param         is the unmodified parameter name (e.g. Diab, GHS, GNU)
 * - number        is the parameter number like 3 for the 3rd parameter (e.g. CodeWarrior)
*/
#define OS_PAR(param, number)	param

/* The following are special versions of the assembler abstraction macros for this tool chain. */
/* Please see the common header for macro descriptions. */
#define OS_INNER_CAT(x,y)		x&&y
#define OS_MACRO_START(name)						name:	.macro
#define OS_MACRO_START_P1(name, p1)					name:	.macro	p1
#define OS_MACRO_START_P2(name, p1, p2)				name:	.macro	p1, p2
#define OS_MACRO_START_P3(name, p1, p2, p3)			name:	.macro	p1, p2, p3
#define OS_MACRO_START_P4(name, p1, p2, p3, p4)		name:	.macro	p1, p2, p3, p4
#define OS_MACRO_START_P5(name, p1, p2, p3, p4, p5)	name:	.macro	p1, p2, p3, p4, p5
#define OS_MACRO_START_P6(name, p1, p2, p3, p4, p5, p6)	name:	.macro	p1, p2, p3, p4, p5, p6


/* Data section
 *
 * This could be already defined by the user's memmap, so we only define it if it isn't already defined.
*/
#ifndef OS_ASM_SECTION_DATA
#define OS_ASM_SECTION_DATA		.data
#endif

/* BSS section
 *
 * This could be already defined by the user's memmap, so we only define it if it isn't already defined.
*/
#ifndef OS_ASM_SECTION_BSS
#define OS_ASM_SECTION_BSS		.bss
#endif

/* Text section
 *
 * This could be already defined by the user's memmap, so we only define it if it isn't already defined.
*/
#ifndef OS_ASM_SECTION_TEXT
#define OS_ASM_SECTION_TEXT		.section .os_text,4,c
#endif

/* Exctab section
 *
 * The section containing the exception vector table
 * This could be already defined by the user's memmap, so we only define it if it isn't already defined.
*/
#ifndef OS_ASM_SECTION_EXCTAB
#define OS_ASM_SECTION_EXCTAB(_coreno)	.section ExceptionTable_C ## _coreno, 4, c
#endif

/* InterruptTable section.
 *
 * The section containing the interrupt vector table.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef OS_ASM_SECTION_INTTAB
#define OS_ASM_SECTION_INTTAB(_coreno)	.section InterruptTable_C ## _coreno, 4, c
#endif

#endif /* OS_USE_DIAB_V7 */

#endif /* OS_ASM_CORTEXM_DIAB_H */
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
