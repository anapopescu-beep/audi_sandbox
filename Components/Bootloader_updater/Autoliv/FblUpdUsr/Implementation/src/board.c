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
$Revision: 1.4 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader_updater/Autoliv/FblUpdUsr/Implementation/src/project.pj $
 */
/*!****************************************************************************
@details
   This file contains board-specific startup code.

 ******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "board.h"
#include "common.h"
/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
#define FBLUSR_KU32_VAL_4        ((uint32) 0x4)

#define FBLUSR_KU32_MAX_VAL      (0xFFFFFFFFu)

#define FBLUSR_KU32_VAL_16       (16U)

#define FBLUSR_KU32_VAL_12       (12U)

#define FBLUSR_KU32_BYTE         ((uint32) 0xFF)
/******************************************************************************
MODULE TYPES
 ******************************************************************************/
/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
 ******************************************************************************/
#if (BOARD_TRUE == BOARD_INIT_SRAM)
LOCAL void BoardInitMemorySections(void);
#endif
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
 ******************************************************************************/
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
 ******************************************************************************/
/**
 *\brief
 *       The counter for enabling/disabling interrupts.
 *
 */
uint8 FblUsr_u8BoardIntLockNestingCounter = KU8_ZERO;

#if (PLATFORMS_TOOLCHAIN==Platforms_iar)
/* linker generated symbol: begin of anonymous DATA section (load address) */
extern uint32 PLATFORMS_TOOL_INITDATA;
/* linker generated symbol: begin of anonymous DATA section (execution address) */
extern uint32 PLATFORMS_TOOL_STARTDATA;
/* linker generated symbol: end of anonymous DATA section (execution address) */
extern uint32 PLATFORMS_TOOL_ENDDATA;
/* linker generated symbol: begin of anonymous DATA section (load address) */
extern uint32 PLATFORMS_TOOL_INITDATARW;
/* linker generated symbol: begin of anonymous DATA section (execution address) */
extern uint32 PLATFORMS_TOOL_STARTDATARW;
/* linker generated symbol: end of anonymous DATA section (execution address) */
extern uint32 PLATFORMS_TOOL_ENDDATARW;
/* linker generated symbol: start of BSS section (VMA) */
extern uint32 PLATFORMS_TOOL_STARTBSS;
/* linker generated symbol: end of BSS section (VMA) */
extern uint32 PLATFORMS_TOOL_ENDBSS;
/* linker generated symbol: start of BSS section (VMA) */
extern uint32 PLATFORMS_TOOL_STARTNOINIT;
#endif

#ifdef QAC
uint32 *u32PlatformsAddressBaseInit = (uint32 *)0x62060uL;
uint32 *u32PlatformsAddressBase = (uint32 *)0x1fff91c0uL;
uint32 *u32PlatformsAddressBaseLimit = (uint32 *)0x1fff925cuL;
uint32 *u32PlatformsAddressExtraBaseInit = (uint32 *)0x40000uL;
uint32 *u32PlatformsAddressExtraBase = (uint32 *)0x1fff8000uL;
uint32 *u32PlatformsAddressExtraBaseLimit = (uint32 *)0x1fff8130uL;
uint32 *u32PlatformsAddressBSSBase = (uint32 *)0x1fff8700uL;
uint32 *u32PlatformsAddressBSSLimit = (uint32 *)0x1fff91b4uL;
uint32 *u32PlatformsAddressNoInitBase = (uint32 *) 0x20006f00uL;
#endif
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
 *       This function is used to set to configure and start the timers.
 * \inputparam
 *       Name: u16Timer;
 *       Type: const u16 ;
 *       Description: u16Timer timer value;
 * \pre
 *       None.
 * \return
 *       u8RetVal.
 * \retval BOARD_TRUE - Timer configuration successful
 * \retval BOARD_FALSE - Timer configuration failed
 * \dynamicaspectcaller
 *       Startup module.
 * \dynamicaspectdescription
 *       Called by main function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *		DSG_FblUpdUsr_BoardInitializationTimers
 * \archrequirement
 *       None.
 **/
EXPORTED uint8 BoardInitializationTimers(const uint16 u16Timer)
{
	uint8 u8RetVal = BOARD_FALSE;

	uint32 u32TimerValue = KU32_ZERO;

	/* check Timer validity and Board frequency available */
	if ((BOARD_TIMER_MINIMAL <= u16Timer) && (KU32_ZERO < BOARD_SYSTEM_CLOCK_MHZ))
	{
		/* Turn on Periodic Interrupt Timer */
		/* FRZ = 1 : Timer freezed in debug mode */
		BOARD_LPTMR_CSR = KU32_ZERO; /* 0x00U */

		/* Timer for scheduling: */
		/* F40 is the input CLK for the PIT */
		/* F40 is MAx 40Mhz */
		/* Input clock is x MHz = y ns
		 * Use Timer with uwTimer in __nS__ period (parameter is passed on __�S__)
		 * x MHz => Load value must be uwTimer/y ns cycles
		 */
		/* multiply before divide to avoid timer to be round down/up*/
		u32TimerValue = ((uint32)(u16Timer) * FBLUSR_KU32_VAL_4);

		/* Set Compare value to calculated timeout */
		BOARD_LPTMR_CMR = u32TimerValue;

		/* Disable prescaler */
		BOARD_LPTMR_PSR = (FBLUSR_KU32_VAL_4 & BOARD_LPTMR_PSR_PBYP);

		BOARD_LPTMR_CSR = (BOARD_LPTMR_CSR_TEN);

		/* activate LPTI timer only for random value generation */
		/* Activate LPIT cell */
		BOARD_LPIT_MCR = BOARD_LPIT_MCR_MCEN;

		/* Activate Timer 0 */
		BOARD_LPIT_TCTRL0 = BOARD_LPIT_TCTRL0_TEN;

		/* Timer configured OK*/
		u8RetVal = BOARD_TRUE;
	}
	else
	{
		u8RetVal = BOARD_FALSE;
	}
	return u8RetVal;
}

/**
 * \brief
 *       Scheduling Timer used to have a time reference (ex: flag is set every u8Timer, parameter passed to BoardInitialisationTimers(u8Timer))
 * \pre
 *       None.
 * \return
 *       u8Flag = flag for scheduling timer.
 * \dynamicaspectcaller
 *       Startup module.
 * \dynamicaspectdescription
 *       Called by main function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *		DSG_FblUpdUsr_BoardSchedulingTimer
 * \archrequirement
 *       None.
 **/
EXPORTED uint8 BoardSchedulingTimer (void)
{
	uint8 u8Flag = BOARD_FALSE;

	/* Timer is scheduled at 1ms */
	if (BOARD_LPTMR_CSR_TCF == ((uint8)(BOARD_LPTMR_CSR & BOARD_LPTMR_CSR_TCF)))
	{
		/* reset timer */
		BOARD_LPTMR_CSR |= (BOARD_LPTMR_CSR_TCF);

		/* Set return flag to TRUE */
		u8Flag = BOARD_TRUE;
	}

	return u8Flag;
}

#if (BOARD_TRUE == BOARD_INIT_SRAM)
/* Initialize memory sections (data, bss). */
#if (PLATFORMS_TOOLCHAIN==Platforms_iar)
/**
 * \brief
 *      Initialize memory sections.
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       FblUsr module.
 * \dynamicaspectdescription
 *       Called in BoardStart function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *		DSG_FblUpdUsr_BoardInitMemorySections
 * \archrequirement
 *       None.
 **/
LOCAL void BoardInitMemorySections(void)
{
	register uint32 *ram;
	register uint32 *flash;

	for (ram = &PLATFORMS_TOOL_STARTDATA, flash = &PLATFORMS_TOOL_INITDATA;
			ram < &PLATFORMS_TOOL_ENDDATA;
			ram++, flash++)
	{
		*ram = *flash;
	}

	for (ram = &PLATFORMS_TOOL_STARTDATARW, flash = &PLATFORMS_TOOL_INITDATARW;
			ram < &PLATFORMS_TOOL_ENDDATARW;
			ram++, flash++)
	{
		*ram = *flash;
	}

	for (ram = &PLATFORMS_TOOL_STARTBSS;
			ram < &PLATFORMS_TOOL_ENDBSS;
			ram++)
	{
		*ram = KU32_ZERO;
	}
}

/**
 * \brief
 *      Initialize RAM if reset was not a SW reset initialization
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       FblUsr module.
 * \dynamicaspectdescription
 *		   Called in BoardStart function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *		DSG_FblUpdUsr_InitNoInitRam
 * \archrequirement
 *       None.
 **/
LOCAL void InitNoInitRam(void)
{
	uint32 *ram;
	Platforms_ResetType Reset;

	/* Get reset reason */
	Reset = BoardIsSwReset();

	/* If reset was not a software reset init the No Init ram */
	if(PLATFORMS_POWER_ON_RESET == Reset)
	{
		for (ram = &PLATFORMS_TOOL_STARTNOINIT;
				ram < ((uint32*)((uint32)(&PLATFORMS_TOOL_STARTNOINIT) + FBLUSR_KU32_BYTE));
				ram++)
		{
			*ram = KU32_ZERO;
		}
	}
}
#endif
#endif

/**
 * \brief
 *      Realize board initial startup conditions for correct main execution.
 *      Function used to start the bootloader updater activity.
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
 *		DSG_FblUpdUsr_BoardStart
 * \archrequirement
 *       None.
 **/
EXPORTED void BoardStart(void)
{
	/* Note: You may only use the stack and rely on initialized data,
	 * after BoardInitMemorySections() was executed.
	 */
#if (BOARD_TRUE == BOARD_INIT_SRAM)
	BoardInitMemorySections();
	InitNoInitRam();
#endif

	/* From here on you can rely on data and stack. */

	BoardDisableInterrupts();

#if (BOARD_TRUE == BOARD_INTERRUPT_ENABLE)
	BoardInitInterrupts();

	BoardEnableInterrupts();
#endif
	/* When all that is done, we can start the OS */
	main();
}

/**
 * \brief
 *      This function is used to initialize the interrupt controller
 *   and sets a default priority in all interrupt vectors,
 *   integrator shall ensure that each integrated software using interrupts
 *   shall verify the interrupt settings or set them to a correct value
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       FblUsr module.
 * \dynamicaspectdescription
 *      Called in BoardStart function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *		DSG_FblUpdUsr_BoardInitInterrupts
 * \archrequirement
 *       None.
 **/
EXPORTED void BoardInitInterrupts(void)
{
	/* set priorities of all interrupts
	 * TODO : it looks like some PSR cannot be written which cause CPU exception while
	 * doing global initializing. project must ensure to configure interruptions correctly
	 * Some PSR are reserved, it is therefore not possible to initialize all Interrupt "easily"
	 * Project shall ensure ISRs priorities are set correctly
	 */
#ifdef BOARD_ISR_CAN0
	BOARD_INTC_EN(INTC_FLEXCAN_ESR_BOFF);
	BOARD_INTC_EN(INTC_FLEXCAN_ESR_ERR);
	BOARD_INTC_EN(INTC_FLEXCAN_BUF_00_15);
	BOARD_INTC_EN(INTC_FLEXCAN_BUF_16_31);
#endif
}

/**
 * \brief
 *      This function is used to manage interruptions disabling by
 *  taking into consideration the interrupt nesting
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       SchM module.
 * \dynamicaspectdescription
 *       Called when is necessary to disable interrupts.
 * \constrains
 *       None.
 * \ddesignrequirement
 *		DSG_FblUpdUsr_BoardDisableInterrupts
 * \archrequirement
 *      ARCH_SW_FblUpdUsr_BoardDisableInterrupts
 **/
EXPORTED void BoardDisableInterrupts (void)
{
	if (KU8_MAX > FblUsr_u8BoardIntLockNestingCounter)
	{
		if (KU8_ZERO == FblUsr_u8BoardIntLockNestingCounter)
		{
			boardDisableInterruptsAsm();
		}
		FblUsr_u8BoardIntLockNestingCounter++;
	}
}

/**
 * \brief
 *      This function is used to manage interruptions enabling by
 *  taking into consideration the interrupt nesting
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       SchM module.
 * \dynamicaspectdescription
 *       Called when is necessary to enable interrupts.
 * \constrains
 *       None.
 * \ddesignrequirement
 *		DSG_FblUpdUsr_BoardEnableInterrupts
 * \archrequirement
 *      ARCH_SW_FblUpdUsr_BoardEnableInterrupts
 **/
EXPORTED void BoardEnableInterrupts (void)
{
	if (KU8_ZERO < FblUsr_u8BoardIntLockNestingCounter)
	{
		FblUsr_u8BoardIntLockNestingCounter--;

		if (KU8_ZERO == FblUsr_u8BoardIntLockNestingCounter)
		{
			boardEnableInterruptsAsm();
		}
	}
}

/**
 * \brief
 *      This function is used to get the reset reason.
 * \pre
 *       None.
 * \return
 *       BoardResetReturn = reset type
 * \retval PLATFORMS_SW_RESET: software reset
 * \retval PLATFORMS_POWER_ON_RESET: power on reset
 * \retval PLATFORMS_WATCHDOG_RESET: watchdog reset
 * \dynamicaspectcaller
 *       FblUsr module.
 * \dynamicaspectdescription
 *       Called in InitNoInitRam function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *		DSG_FblUpdUsr_BoardIsSwReset
 * \archrequirement
 *      ARCH_SW_FblUpdUsr_BoardIsSwReset
 **/
EXPORTED Platforms_ResetType BoardIsSwReset(void)
{    
	Platforms_ResetType BoardResetReturn;

	uint32 BoardResetRegister = BOARD_RCM_SRS;

	if (KU8_ZERO != (BoardResetRegister & BOARD_RCM_SRS_POR))
	{
		BoardResetReturn = PLATFORMS_POWER_ON_RESET;
	}
	else if (KU8_ZERO != (BoardResetRegister & BOARD_RCM_SRS_LVD))
	{
		BoardResetReturn = PLATFORMS_POWER_ON_RESET;
	}
	else if (KU8_ZERO != (BoardResetRegister & BOARD_RCM_SRS_SW))
	{
		BoardResetReturn = PLATFORMS_SW_RESET;
	}
	else if (KU8_ZERO != (BoardResetRegister & BOARD_RCM_SRS_WDOG))
	{
		BoardResetReturn = PLATFORMS_WATCHDOG_RESET;
	}
	else if (KU8_ZERO != (BoardResetRegister & BOARD_RCM_SRS_PIN))
	{
		BoardResetReturn = PLATFORMS_SW_RESET;
	}
	else
	{
		BoardResetReturn = PLATFORMS_RESET_UNDEFINED;
	}

	return BoardResetReturn;
}


/******************************************************************************
End Of File
 *****************************************************************************/
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
 */
