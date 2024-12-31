/* CORTEXM-exceptiontable.s
 *
 * Contains the exception table for CORTEXM.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: exceptiontable.s 1.2 2023/02/08 11:48:29CET Andreea Suiu (andreea.suiu) in_work  $
*/

#ifndef BOARD_ASM
#define BOARD_ASM
#endif

#include <Platforms_asm_CORTEXM.h>
#include <board.h>

    Platforms_global CORTEXMExceptionTable

    Platforms_extern boardResetStart
    Platforms_extern BoardStack
    Platforms_extern boardInvalidException

    PLATFORMS_ASM_SECTION_EXCTAB
    PLATFORMS_ASM_CODE_THUMB

    PLATFORMS_ASM_DATALABEL

PLATFORMS_ASM_LABEL(CORTEXMExceptionTable)
    Platforms_word  (BoardStack + ISTACKLEN)    /* reset value of main stack pointer (0x00) */
    Platforms_word  boardResetStart                 /* reset vector (0x04) */
    Platforms_word  boardInvalidException           /* non maskable interrupt vector (0x08) */
    Platforms_word  boardInvalidException           /* hard fault vector (0x0c) */
    Platforms_word  boardInvalidException           /* memory management vector (0x10) */
    Platforms_word  boardInvalidException           /* bus fault vector (0x14) */
    Platforms_word  boardInvalidException           /* usage fault vector (0x18) */
    Platforms_word  boardInvalidException           /* reserved (0x1c) */
    Platforms_word  boardInvalidException           /* reserved (0x20) */
    Platforms_word  boardInvalidException           /* reserved (0x24) */
    Platforms_word  boardInvalidException           /* reserved (0x28) */
    Platforms_word  boardInvalidException                   /* supervisor call vector (0x2c) */
    Platforms_word  boardInvalidException           /* debug monitor vector (0x30) */
    Platforms_word  boardInvalidException           /* reserved (0x34) */
    Platforms_word  boardInvalidException           /* pending supervisor vector (0x38) */
    Platforms_word  boardInvalidException           /* system tick vector (0x3c) */



    PLATFORMS_ASM_SRC_END

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
