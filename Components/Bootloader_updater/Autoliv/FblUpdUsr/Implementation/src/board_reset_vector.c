/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version:
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
******************************************************************************/
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.2 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader_updater/Autoliv/FblUpdUsr/Implementation/src/project.pj $
*/
/*!****************************************************************************

@details
   This file contains the reset vector for S32K14X:
   reset vector is two 32-bit words, linked to a hardware-specific location,
   that tell the hardware:
     1) Reset value of main stack pointer
     2) Address of the boardResetStart function
   Usually this is not needed, because by default the reset vector is part of the interrupt table
   (See CORTEXM-exceptiontable.s). However, because of the S32K14X memory layout the interrupt
   table is relocated and the reset vector must be provided separately.
******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "board.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/******************************************************************************
MODULE TYPES
******************************************************************************/
/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/
/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/
/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
 * \brief
 *       The function to be executed on reset or power-on.
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       None.
 * \dynamicaspectdescription
 *       None.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_FblUpdUsr_boardResetStart
 * \archrequirement
 *       None.
 **/
extern void boardResetStart(void);

#define BOARD_START_STACK_CODE
#include "MemMap.h"
uint32 BoardStack[ISTACKLEN];
#define BOARD_STOP_STACK_CODE
#include "MemMap.h"

/* Const array of two 32-bit words */
const uint32 reset_vector[2] = {
	(uint32)BoardStack + ISTACKLEN, /* stack pointer as in CORTEXM-exceptiontable.s */
	(uint32)&boardResetStart
};

/******************************************************************************
End Of File
*****************************************************************************/
