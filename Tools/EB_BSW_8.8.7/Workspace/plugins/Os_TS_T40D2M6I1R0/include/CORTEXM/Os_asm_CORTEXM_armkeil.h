/* Os_asm_CORTEXM_armkeil.h
 *
 * This file is the toolchain-dependent include file for the ARM Compiler 6
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
 * $Id: Os_asm_CORTEXM_armkeil.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM_CORTEXM_ARMKEIL_H
#define OS_ASM_CORTEXM_ARMKEIL_H

/* set eabi attribute that we preserve 8 byte stack-pointer alignment. */
#define OS_ASM_CODE_THUMB	.thumb; .syntax unified; .eabi_attribute Tag_ABI_align_preserved, 1

#endif /* OS_ASM_CORTEXM_ARMKEIL_H */
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
