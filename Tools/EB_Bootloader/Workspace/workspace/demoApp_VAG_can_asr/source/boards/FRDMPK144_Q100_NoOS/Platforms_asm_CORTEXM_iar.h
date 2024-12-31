/* Platforms_asm_PA_ghs.h
 *
 * This file is the toolchain-dependent include file for the ghs assembler for the Power Architecture.
 *
 * This file defines the macros used in assembler files in a way such that the assembler files
 * will compile with the ghs (Green Hills) assembler.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 * CHECK: RULE 402 OFF (these are assembler directives, not C)
 *
 * Copyright 1998-2014 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Platforms_asm_CORTEXM_iar.h 1.2.1.2 2022/09/01 06:53:03CEST Andrei Anca (andrei.anca) in_work  $
*/
#ifndef __PLATFORMS_ASM_CORTEXM_IAR_H
#define __PLATFORMS_ASM_CORTEXM_IAR_H

/* Filename for the assembler
*/
#define Platforms_file(name)   .file #name

/* Various assembler directives
*/
#define Platforms_global     PUBLIC
#define Platforms_extern     EXTERN
#define Platforms_align(b,p2)    ALIGNROM p2
#define Platforms_word       DC32

/*
 * C macros to create an assembler abstraction for assembly macro definition
 */

/*
 * Platforms_CAT_COND
 *
 * Concatenates the two specified parameters x and y by use of another C macro.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef PLATFORMS_CAT_COND
#define PLATFORMS_CAT_COND(x,y)    PLATFORMS_INNER_CAT_COND(x,y)
#define PLATFORMS_INNER_CAT_COND(x,y)  x##y
#endif

/* The following are special versions of
 the assembler abstraction macros for this tool chain. */
/* Please see the common header for macro descriptions. */
#define PLATFORMS_INNER_CAT(x,y)   x><y


/* Small data area offset
*/
#define Platforms_sda(x) x@sdarx(0)

/* High and low halfwords of 32-bit values
*/
#define Platforms_hi(x)  x@ha    /* For signed operations in combination with Platforms_lo() */
#define Platforms_uhi(x) x@h     /* For unsigned operations in combination with Platforms_lo() */
#define Platforms_lo(x)  x@l

/* Data section
 *
 * This could be already defined by the user's memmap, so we only define it if it isn't already defined.
*/
#ifndef PLATFORMS_ASM_SECTION_DATA
#define PLATFORMS_ASM_SECTION_DATA   .data
#endif

/* Text section
 *
 * This could be already defined by the user's memmap, so we only define it if it isn't already defined.
*/
#ifndef PLATFORMS_ASM_SECTION_TEXT
#define PLATFORMS_ASM_SECTION_TEXT   SECTION .startup :CODE
#endif

/* Intctab section
 *
 * The section containing the interrupt vector table
 * This could be already defined by the user's memmap, so we only define it if it isn't already defined.
*/
#ifndef PLATFORMS_ASM_SECTION_INTCTAB
#define PLATFORMS_ASM_SECTION_INTCTAB  SECTION .InterruptTable :CODE
#endif

/* Reset section
 *
 * The section containing the reset vector
 * This could be already defined by the user's memmap, so we only define it if it isn't already defined.
*/
#ifndef PLATFORMS_ASM_SECTION_RESET
#define PLATFORMS_ASM_SECTION_RESET  SECTION .reset :CODE
#endif

/* Exctab section
 *
 * The section containing the exception vector table
 * This could be already defined by the user's memmap, so we only define it if it isn't already defined.
*/
#ifndef PLATFORMS_ASM_SECTION_EXCTAB
#define PLATFORMS_ASM_SECTION_EXCTAB SECTION .ExceptionTable :CODE
#endif

/* InterruptTable section.
 *
 * The section containing the interrupt vector table.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
*/
#ifndef PLATFORMS_ASM_SECTION_INTTAB
#define PLATFORMS_ASM_SECTION_INTTAB SECTION .InterruptTable :CODE
#endif

/* Boot code section
 *
 * The section containing the boot code (code called after reset for CPU/MMU initialization).
 * This could be already defined by the user's memmap, so we only define it if it isn't already defined.
*/
#ifndef PLATFORMS_ASM_SECTION_BOOT_CODE
#define PLATFORMS_ASM_SECTION_BOOT_CODE  SECTION .boot_code :CODE
#endif

/* Reset code section
 *
 * The section containing the code executed at reset
 * This could be already defined by the user's memmap, so we only define it if it isn't already defined.
*/
#ifndef PLATFORMS_ASM_SECTION_RESET_CODE
#define PLATFORMS_ASM_SECTION_RESET_CODE SECTION .reset_code :CODE
#endif

/*
 * Create a label with name name. Allowed characters for name are [a-zA-Z0-9_]. It
 * must not start with a number. Labels created in this manner are guaranteed to
 * result in a symbol with name name, which may be exported by OS_global.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef PLATFORMS_ASM_LABEL
#define PLATFORMS_ASM_LABEL(name)	name
#endif

/*
 * Assembler directive to declare that the next label refers to a function
 * definition. The next label must be named <name>.
 * name: symbol name of the function.
 * Note: This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef PLATFORMS_ASM_FUNC
#define PLATFORMS_ASM_FUNC(name) THUMB
#endif

/*
 * Assembler directive to mark the end of a function.
 * name: symbol name of function.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef PLATFORMS_ASM_END_FUNC
#define PLATFORMS_ASM_END_FUNC(name) DATA
#endif


#ifndef PLATFORMS_ASM_DATALABEL
#define PLATFORMS_ASM_DATALABEL   DATA
#endif
/*
 * Assembler directive to select the THUMB instruction set.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 */
#ifndef PLATFORMS_ASM_CODE_THUMB
#define PLATFORMS_ASM_CODE_THUMB
#endif

#ifndef PLATFORMS_TOOL_INITDATA
#define PLATFORMS_TOOL_INITDATA (DATA_init$$Base)
#endif

#ifndef PLATFORMS_TOOL_STARTDATA
#define PLATFORMS_TOOL_STARTDATA (DATA$$Base)
#endif

#ifndef PLATFORMS_TOOL_ENDDATA
#define PLATFORMS_TOOL_ENDDATA (DATA$$Limit)
#endif

#ifndef PLATFORMS_TOOL_STARTBSS
#define PLATFORMS_TOOL_STARTBSS (BSS$$Base)
#endif

#ifndef PLATFORMS_TOOL_ENDBSS
#define PLATFORMS_TOOL_ENDBSS (BSS$$Limit)
#endif

#ifndef PLATFORMS_ASM_SRC_END
#define PLATFORMS_ASM_SRC_END END
#endif


#endif /* __PLATFORMS_ASM_CORTEXM_IAR_H*/
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
