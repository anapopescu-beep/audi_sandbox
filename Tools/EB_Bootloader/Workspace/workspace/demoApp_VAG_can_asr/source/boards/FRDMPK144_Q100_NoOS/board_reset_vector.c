/* board_reset_vector.c
 *
 *	This file contains the reset vector for S32K14X:
 *	reset vector is two 32-bit words, linked to a hardware-specific location,
 *	that tell the hardware:
 *		1) Reset value of main stack pointer
 *		2) Address of the boardResetStart function
 *
 *	Usually this is not needed, because by default the reset vector is part of the interrupt table
 *	(See CORTEXM-exceptiontable.s). However, because of the S32K14X memory layout the interrupt
 *	table is relocated and the reset vector must be provided separately.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: board_reset_vector.c 1.2.1.2 2022/09/01 06:53:03CEST Andrei Anca (andrei.anca) in_work  $
*/


#include "board.h"

/* the function to be executed on reset or power-on	*/
extern void boardResetStart(void);

#define BOARD_START_STACK_CODE
#include "MemMap.h"
u32 BoardStack[ISTACKLEN];
#define BOARD_STOP_STACK_CODE
#include "MemMap.h"

/* Const array of two 32-bit words */
const u32 reset_vector[2] = {
	(u32)BoardStack + ISTACKLEN, /* stack pointer as in CORTEXM-exceptiontable.s */
	(u32)&boardResetStart
};
