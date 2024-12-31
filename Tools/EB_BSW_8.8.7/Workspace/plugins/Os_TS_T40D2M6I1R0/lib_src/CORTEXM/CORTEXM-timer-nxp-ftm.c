/* CORTEXM-timer-nxp-ftm.c - CORTEXM timer driver for NXP FTM module (e.g. S32K14x)
 *
 * The timer hardware is described in the header file Os_CORTEXM_timer_nxp_ftm.h
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-timer-nxp-ftm.c 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#include <Os_kernel.h>

#include <CORTEXM/Os_CORTEXM_timer_nxp_ftm.h>
#include <Os_tool.h>

/* In this driver, the timer descriptor is configured externally because
 * it is known that some customers use special derivatives that have more FTM
 * instances than the standard devices.
 *
 * These functions are only referenced in this file but are not declared static
 * to ensure that they appear in the ELF symbol table.
*/
void OS_TimerFtmInit(const os_hwt_t *);
os_timervalue_t OS_TimerFtmRead(const os_hwt_t *);
os_boolean_t OS_TimerFtmStart(const os_hwt_t *, os_timervalue_t, os_tick_t);
void OS_TimerFtmStop(const os_hwt_t *);

/* Driver table
 *
 * This table tells the kernel what the driver functions are.
*/
#include <memmap/Os_mm_const_begin.h>
const os_hwtdrv_t OS_timerFtmDriver =
{
	&OS_TimerFtmInit,
	&OS_TimerFtmRead,
	&OS_TimerFtmStart,
	&OS_TimerFtmStop
};
#include <memmap/Os_mm_const_end.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_TimerFtmInit()
 *
 * Initialises the Frc specified in the HW timer descriptor.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_TimerFtmInit(const os_hwt_t *td)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	const os_ftmdescriptor_t *fd = &OS_ftmDescriptor[td->major];

	/* Disable the write protection
	*/
	fd->ftm->ftm_mode |= OS_FTM_WPDIS;

	/* Set the counter to be free-running as described in section 47.5.3.3:
	 *	FTMEN = 1
	 *	MOD = 0xFFFF
	 *	CNTIN = 0
	 *	QUADEN = 0
	*/
	fd->ftm->ftm_mode = OS_FTM_FTMEN;	/* Clears other bits. */
	fd->ftm->ftm_qdctrl = 0x00;			/* Clears other bits as well as QUADEN */
	fd->ftm->ftm_cntin = 0u;
	fd->ftm->ftm_mod = 0xffff;

	/* Configure the channel mode to Output Compare.
	 *  - MSB:MSA = 01 ---> Output Compare mode 
	 *	- ELS = 0 ---> No Output  
	*/
	fd->ftm->ftm_ch[td->minor * 2].ftm_csc = OS_FTM_MS_OUTPUT_COMPARE;
	
	/* Configure the clock source and the prescaler as selected in the config file.
	 *	- FLTPS = 0 --> filter prescaler divide-by-1 (not used)
	 *	- PWMENn = 0 (n = 0..7) --> PWM output disabled
	 *	- TOIE = 0 --> Timer overflow interrupt is disabled
	 *	- RIE = 0 --> Timer reload interrupt disabled
	 *	- CPWMS = 0 --> Up-counting mode
	 *	- TOF and RF are read-only bits that are cleared by writing 0
	*/
	fd->ftm->ftm_sc = fd->clockSource | fd->prescaler;
}

/*!
 * OS_TimerFtmRead()
 *
 * Reads the timer and returns the result.
 *
 * !LINKSTO Kernel.Autosar.Counter.Types.HARDWARE.Value, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_timervalue_t OS_TimerFtmRead(const os_hwt_t *td)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	const os_ftmdescriptor_t *fd = &OS_ftmDescriptor[td->major];

	return (fd->ftm->ftm_cnt & OS_FTM_COUNT);	/* Paranoia - ensure upper halfword is clear */
}

/*!
 * OS_TimerFtmStart()
 *
 * Initialises and starts the comparator channel as specified in the HW timer descriptor.
 *
 * The absolute value given by (old + delta) is stored into the comparator. If the
 * value is already in the past, the timer interrupt is triggered. The "in the past"
 * computation uses the given old value as a limit for times that are less than the
 * new timer position but must be considered to be in the future.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_boolean_t OS_TimerFtmStart(const os_hwt_t *td, os_timervalue_t old, os_tick_t delta)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	const os_ftmdescriptor_t *fd = &OS_ftmDescriptor[td->major];
	os_ftmch_t *ch = &fd->ftm->ftm_ch[td->minor * 2];
	os_timervalue_t new;

	/* Clear any pending interrupt.
	*/
	ch->ftm_csc &= ~OS_FTM_CHF;

	/* Set the compare register to the absolute value specified.
	 * Wraparound is handled by ANDing with the mask. The upper bits of the
	 * register *should* be fixed at 0, but it is better not to assume anything.
	*/
	ch->ftm_cv = (old + delta) & OS_FTM_COUNT;

	/* Enable the comparator.
	*/
	ch->ftm_csc |= OS_FTM_CHIE;

	/* Look at the counter value.
	 * If it lies between old and old+delta we've got a future time.
	 * If not, go round again.
	*/
	new = fd->ftm->ftm_cnt & OS_FTM_COUNT;

	/* Overflows here don't matter - all we're interested in are the relative distances.
	 * (Might be otherwise if the timers are not the full word-width)
	*/
	return ( delta <= ((new - old) & OS_FTM_COUNT) );
}

/*!
 * OS_TimerFtmStop()
 *
 * Disables the comparator as specified in the HW timer descriptor.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_TimerFtmStop(const os_hwt_t *td)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	const os_ftmdescriptor_t *fd = &OS_ftmDescriptor[td->major];
	os_ftmch_t *ch = &fd->ftm->ftm_ch[td->minor * 2];

	/* Disable the comparator interrupt and clear any pending interrupt.
	*/
	ch->ftm_csc &= ~(OS_FTM_CHIE | OS_FTM_CHF);
}

#include <memmap/Os_mm_code_end.h>

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
