/* Os_asm_CORTEXM_arm5.h
 *
 * This file is the toolchain-dependent include file for the ARM Compiler 5
 * assembler.
 *
 * This file defines the macros used in assembler files in a way such that the
 * assembler files will compile with the ARM Assembler.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_asm_CORTEXM_arm5.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM_CORTEXM_ARM5_H
#define OS_ASM_CORTEXM_ARM5_H

/* We claim to preserve 8-byte alignment of the stacks to avoid warnings/errors
 * from the linker. This may not be true for all cases (e.g. directly called ISRs),
 * but does no harm, since 8-byte alignment is only required for floating point
 * and SIMD 64-bit data types. These are not used in the kernel and only
 * supported for tasks, but not ISRs. Task stacks (given a correct linker-script)
 * have an 8-byte aligned stack pointer.
*/
#ifdef OS_ASM
	PRESERVE8	{TRUE}
#endif

/*
 * Assembler directive to define an external symbol.
 */
#define OS_global	EXPORT

/*
 * Assembler directive to reference an external symbol.
 */
#define OS_extern	EXTERN

/*
 * Assembler directive to define a machine word (32 bit).
 */
#define OS_word		DCDU

/*
 * Assembler directive to align the following data or code to the given amount of
 * bytes (b) or power of 2 (p2).
 */
#define OS_align(b, p2)	ALIGN	b

/*
 * Create a label with name name. Allowed characters for name are [a-zA-Z0-9_]. It
 * must not start with a number. Labels created in this manner are guaranteed to
 * result in a symbol with name name, which may be exported by OS_global.
 */
#define OS_ASM_LABEL(name)	name

/*
 * Assembler directive to start a text section (OS-code).
 * This could be already defined by the user's memmap,
 * so we only define it if it isn't already defined.
 */
#ifndef OS_ASM_SECTION_TEXT
#define OS_ASM_SECTION_TEXT		AREA	|OS_CAT(.,os_text)|, CODE, READONLY
#endif

/*
 * Assembler directive to select the ARM instruction set.
 */
#define OS_ASM_CODE_ARM		ARM

/*
 * Assembler directive to select the THUMB instruction set.
 */
#define OS_ASM_CODE_THUMB	THUMB

/*
 * Assembler directive to declare that the next label refers to a function
 * definition. The next label must be named <name>.
 * name: symbol name of the function.
 */
#define OS_ASM_FUNC(name)		/* nothing */

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
#define OS_PAR(param, number)	OS_CAT($p, param)

/*
 * OS_MACRO_PREPARE_START
 *
 * This macro prepares the start of an assembly macro definition. It must be
 * followed in the next line by one of the OS_MACRO_START macros.
 */
#define OS_MACRO_PREPARE_START()	OS_BLANK MACRO

/*
 * OS_MACRO_START
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has no parameters.
*/
#define OS_MACRO_START(name)	OS_BLANK name

/*
 * OS_MACRO_START_P1
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has one parameter p1.
*/
#define OS_MACRO_START_P1(name, p1)	OS_BLANK name	OS_CAT($p, p1)

/*
 * OS_MACRO_START_P2
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has two parameters p1 and p2.
*/
#define OS_MACRO_START_P2(name, p1, p2)	OS_BLANK name	OS_CAT($p, p1), OS_CAT($p, p2)

/*
 * OS_MACRO_START_P3
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has three parameters p1, p2 and p3.
*/
#define OS_MACRO_START_P3(name, p1, p2, p3)	OS_BLANK name		\
												OS_CAT($p, p1),	\
												OS_CAT($p, p2),	\
												OS_CAT($p, p3)

/*
 * OS_MACRO_START_P4
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has four parameters p1, p2, p3 and p4.
*/
#define OS_MACRO_START_P4(name, p1, p2, p3, p4)	OS_BLANK name	\
												OS_CAT($p, p1),	\
												OS_CAT($p, p2),	\
												OS_CAT($p, p3),	\
												OS_CAT($p, p4)

/*
 * OS_MACRO_START_P5
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has five parameters p1, p2, p3, p4 and p5.
*/
#define OS_MACRO_START_P5(name, p1, p2, p3, p4, p5)		OS_BLANK name	\
														OS_CAT($p, p1),	\
														OS_CAT($p, p2),	\
														OS_CAT($p, p3),	\
														OS_CAT($p, p4),	\
														OS_CAT($p, p5)

/*
 * OS_MACRO_START_P6
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has six parameters p1, p2, p3, p4, p5 and p6.
*/
#define OS_MACRO_START_P6(name, p1, p2, p3, p4, p5, p6)	OS_BLANK name	\
														OS_CAT($p, p1),	\
														OS_CAT($p, p2),	\
														OS_CAT($p, p3),	\
														OS_CAT($p, p4),	\
														OS_CAT($p, p5),	\
														OS_CAT($p, p6)


/*
 * OS_MACRO_END
 *
 * This macro ends an assembly macro definition.
*/
#define OS_MACRO_END()	OS_BLANK			MEND

/* ExceptionTable section.
 *
 * The section containing the exception vector table.
*/
#ifndef OS_ASM_SECTION_EXCTAB
#define OS_ASM_SECTION_EXCTAB	AREA	|ExceptionTable|, CODE, READONLY
#endif

/* InterruptTable section.
 *
 * The section containing the interrupt vector table (e.g. for Cortex-M ARM cores).
*/
#ifndef OS_ASM_SECTION_INTTAB
#define OS_ASM_SECTION_INTTAB	AREA	|InterruptTable|, CODE, READONLY
#endif


/*
 * OS_ASM_SRC_END
 *
 * This macro marks the end of an assembly source file.
*/
#define OS_ASM_SRC_END	END

/* Bitwise OR. ARM RealView uses a different notation.
*/
#define OS_ASM_OR	:OR:

#endif /* OS_ASM_CORTEXM_ARM5_H */
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
