/* Os_asm_CORTEXM_ticgt.h
 *
 * This file is the toolchain-dependent include file for the TICGT assembler
 * for CORTEXM.
 *
 * This file defines the macros used in assembler files in a way such that the
 * assembler files will compile with the TICGT assembler.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_asm_CORTEXM_ticgt.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_ASM_CORTEXM_TICGT_H
#define OS_ASM_CORTEXM_TICGT_H

/*
 * Assembler directive to define an external symbol.
 */
#define OS_global	OS_INNER_CAT(., def)

/*
 * Assembler directive to reference an external symbol.
 */
#define OS_extern	OS_INNER_CAT(., ref)

/*
 * Assembler directive to define a machine word (32 bit).
 */
#define OS_word		OS_INNER_CAT(., word)

/*
 * Assembler directive to align the following data or code to the given amount of
 * bytes (b) or power of 2 (p2).
 */
#define OS_align(b, p2)	OS_INNER_CAT(., align)	b

/*
 * Assembler directive to start a text section (OS-code).
 * This could be already defined by the user's memmap,
 * so we only define it if it isn't already defined.
 */
#ifndef OS_ASM_SECTION_TEXT
#define OS_ASM_SECTION_TEXT		OS_INNER_CAT(., text)
#endif

/*
 * Assembler directive to select the THUMB instruction set.
 */
#define OS_ASM_CODE_THUMB	OS_INNER_CAT(., thumb)

/*
 * Assembler directive to declare that the next label refers to a function
 * definition. The next label must be named <name>.
 * name: symbol name of the function.
 */
#define OS_ASM_FUNC(name)			/* nothing */

/*
 * Assembler directive to mark the end of a function.
 * name: symbol name of function.
 */
#define OS_ASM_END_FUNC(name)		/* nothing */

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
 * OS_MACRO_START
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has no parameters.
*/
#define OS_MACRO_START(name)	name	OS_INNER_CAT(., macro)

/*
 * OS_MACRO_START_P1
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has one parameter p1.
*/
#define OS_MACRO_START_P1(name, p1)	name	OS_INNER_CAT(., macro)	p1

/*
 * OS_MACRO_START_P2
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has two parameters p1 and p2.
*/
#define OS_MACRO_START_P2(name, p1, p2)	name	OS_INNER_CAT(., macro)	p1, p2

/*
 * OS_MACRO_START_P3
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has three parameters p1, p2 and p3.
*/
#define OS_MACRO_START_P3(name, p1, p2, p3)	name	OS_INNER_CAT(., macro)	p1, p2, p3

/*
 * OS_MACRO_START_P4
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has four parameters p1, p2, p3 and p4.
*/
#define OS_MACRO_START_P4(name, p1, p2, p3, p4)	name	OS_INNER_CAT(., macro)	p1, p2, p3, p4

/*
 * OS_MACRO_START_P5
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has five parameters p1, p2, p3, p4 and p5
*/
#define OS_MACRO_START_P5(name, p1, p2, p3, p4, p5)			\
	name	OS_INNER_CAT(., macro)	p1, p2, p3, p4, p5


/*
 * OS_MACRO_END
 *
 * This macro ends an assembly macro definition.
*/
#define OS_MACRO_END()			OS_BLANK	OS_INNER_CAT(., endm)

/* ExceptionTable section.
 *
 * The section containing the exception vector table
 * This could be already defined by the user's memmap, so we only define it if it
 * isn't already defined.
*/
#ifndef OS_ASM_SECTION_EXCTAB
#define OS_ASM_SECTION_EXCTAB	OS_INNER_CAT(.,sect)	"ExceptionTable"
#endif

/* InterruptTable section.
 *
 * The section containing the interrupt vector table (e.g. for Cortex-M CORTEXM cores)
*/
#ifndef OS_ASM_SECTION_INTTAB
#define OS_ASM_SECTION_INTTAB	OS_INNER_CAT(.,sect)	"InterruptTable"
#endif

#endif /* ! OS_ASM_CORTEXM_TICGT_H */
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
