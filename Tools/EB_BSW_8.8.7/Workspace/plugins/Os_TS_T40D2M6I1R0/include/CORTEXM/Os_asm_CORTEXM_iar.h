/* Os_asm_CORTEXM_iar.h - Assembler abstraction for IAR.
 *
 * This file contains the assembler abastraction for IAR.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: Os_asm_CORTEXM_iar.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_ASM_CORTEXM_IAR_H
#define OS_ASM_CORTEXM_IAR_H

/*
 * OS_ASM_SRC_END
 *
 * This macro marks the end of an assembly source file.
*/
#define OS_ASM_SRC_END	OS_BLANK END

/*
 * Assembler directive to define an external symbol.
 */
#define OS_global	PUBLIC

/*
 * Assembler directive to reference an external symbol.
 */
#define OS_extern	EXTERN

/*
 * Assembler directive to define a machine word (32 bit).
 */
#define OS_word		DC32

/*
 * Assembler directive to print the source file-name.
 */
#define OS_file(name)	/* nothing */

/*
 * Assembler directive to align the following data or code to the given amount of
 * bytes (b) or power of 2 (p2).
 */
#define OS_align(b, p2)	ALIGNROM p2

/*
 * Create a label with name name. Allowed characters for name are [a-zA-Z0-9_]. It
 * must not start with a number. Labels created in this manner are guaranteed to
 * result in a symbol with name name, which may be exported by OS_global.
 */
#define OS_ASM_LABEL(name)	name

/*
 * Assembler directive to start a text section (OS-code).
 */
#define OS_ASM_SECTION_TEXT		SECTION .os_text :CODE

/*
 * Assembler directive to select the THUMB instruction set.
 *
 * Note: Since we explicitely specify literal pools, we define everything
 * outside of functions as data, only funcitons themselves as thumb(-code).
 * See OS_ASM_FUNC and OS_ASM_END_FUNC below.
 */
#define OS_ASM_CODE_THUMB	OS_BLANK DATA

/*
 * OS_ASM_DATALABEL
 *
 * IAR assembler requires strict usage of DATA directive before data label.
 *
 * Note 1: "Labels placed in Thumb code, i.e. that appear after a CODE16 directive, always have
 * bit 0 set (i.e. an odd label) in IASMARM. ARMASM, on the other hand, does not set bit 0
 * on symbols in expressions that are solved at assembly time."
 *
 * Note 2: "Always use the DATA directive when defining data in a
 * Thumb code section with DC8, DC16, or DC32, otherwise
 * labels on the data will have bit 0 set."
*/
#define OS_ASM_DATALABEL	OS_BLANK DATA

/*
 * Assembler directive to declare that the next label refers to a function
 * definition. The next label must be named <name>.
 * name: symbol name of the function.
 */
#define OS_ASM_FUNC(name)	OS_BLANK THUMB

/*
 * Assembler directive to mark the end of a function.
 * name: symbol name of function.
 */
#define OS_ASM_END_FUNC(name)	OS_BLANK DATA

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
 * OS_MACRO_PREPARE_START
 *
 * This macro prepares the start of an assembly macro definition. It must be
 * followed in the next line by one of the OS_MACRO_START macros.
 */
#define OS_MACRO_PREPARE_START()	/* nothing */

/*
 * OS_MACRO_START
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has no parameters.
*/
#define OS_MACRO_START(name)	name	MACRO

/*
 * OS_MACRO_START_P1
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has one parameter p1.
*/
#define OS_MACRO_START_P1(name, p1)		name	MACRO p1

/*
 * OS_MACRO_START_P2
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has two parameters p1 and p2.
*/
#define OS_MACRO_START_P2(name, p1, p2)	name	MACRO p1 p2

/*
 * OS_MACRO_START_P3
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has three parameters p1, p2 and p3.
*/
#define OS_MACRO_START_P3(name, p1, p2, p3)	name	MACRO p1 p2 p3

/*
 * OS_MACRO_START_P4
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has four parameters p1, p2, p3 and p4.
*/
#define OS_MACRO_START_P4(name, p1, p2, p3, p4)	name	MACRO p1 p2 p3 p4

/*
 * OS_MACRO_START_P5
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has five parameters p1, p2, p3, p4 and p5.
*/
#define OS_MACRO_START_P5(name, p1, p2, p3, p4, p5)	name	MACRO p1 p2 p3 p4 p5
/*
 * OS_MACRO_START_P6
 *
 * This macro starts an assembly macro definition with the macro-name name.
 * The defined assembly macro has six parameters p1, p2, p3, p4, p5 and p6.
*/
#define OS_MACRO_START_P6(name, p1, p2, p3, p4, p5, p6)	name	MACRO p1 p2 p3 p4 p5 p6

/*
 * OS_MACRO_END
 *
 * This macro ends an assembly macro definition.
*/
#define OS_MACRO_END()	OS_BLANK	ENDM

/* ExceptionTable section.
 *
 * The section containing the exception vector table.
*/
#define OS_ASM_SECTION_EXCTAB(_coreno) SECTION ExceptionTable_C ## _coreno :CODE

/* InterruptTable section.
 *
 * The section containing the interrupt vector table.
*/
#define OS_ASM_SECTION_INTTAB(_coreno) SECTION InterruptTable_C ## _coreno :CODE

/* Name of the xPSR register for mrs instructions.
 *
 * This macros defines the name of the xPSR register for mrs instructions.
 * UAL defines it to xPSR. IAR recognizes only PSR.
*/
#define OS_ASM_XPSR	PSR

#endif /* ! OS_ASM_CORTEXM_IAR_H */


/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
