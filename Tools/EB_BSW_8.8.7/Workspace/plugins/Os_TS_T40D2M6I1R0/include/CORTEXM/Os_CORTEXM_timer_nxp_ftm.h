/* Os_CORTEXM_timer_nxp_ftm.h - Description of NXP FlexTimer (FTM) for CORTEXM
 *
 * This file will be included by every derivative that has a FTM.
 *
 * Configuration:
 *		OS_CORTEXM_FTMx_BASE	Base address of FlexTimer module x.
 *		OS_CORTEXM_N_FTM		Number of FTM instances
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_CORTEXM_timer_nxp_ftm.h 1.2 2023/08/01 10:18:37CEST Gabriel Brasoveanu (gabriel.brasoveanu) in_work  $
*/
#ifndef OS_CORTEXM_TIMER_NXP_FTM_H
#define OS_CORTEXM_TIMER_NXP_FTM_H

#include <Os_kernel.h>
#include <CORTEXM/Os_CORTEXM_cpu.h>
#include <CORTEXM/Os_CORTEXM_timer_nxp_ftm_config.h>
/*
 * Reference manual: S32K1xx-RM_Rev_12.1_022020.pdf
 *
 * Each instance of the FlexTimer contains:
 *	- a 16-bit counter that can be configured as a free-running counter
 *	- 8 compare register channels that can be used to trigger interrupts
 *	  The compare registers paired; each pair (0/1, 2/3, 4/5 and 6/7) share a common interrupt.
 *	  This driver doesn't support interrupt demultiplexing, so only the even-numbered channels are used.
 *
 * Each FTM instance can select one of the following clock sources:
 *	- fixed frequency (it isn't clear what this is)
 *	- FTM clock (i.e SYS_CLK, CPU frequency)
 *	- External (SPLLDIV1_CLK)
 * If "external" is selected, the clock must not be faster than a quarter of the FTM clock.
 *
 * Using the SYS_CLK seems to be the best default in order to avoid dependencies on other modules that use
 * SPLLDIV2. The default can be changed in board.h
 *
 * When using the CPU clock, the limited width of the timer becomes an obstacle. With a CPU clock
 * of 80 MHz, the wrap time of the counter is less than 820 us. At 100 MHz, less than 656 us.
 * The generic hardware counter mechanism attempts to avoid missing wrap-around events by inserting
 * extra interrupts; if the delta is greater that (typically) 75% of the range, is sets an intermediate
 * interrupt at 50% of the range. At a typical automotive tick interval there could be as many as 3 interrupts.
 * Therefore prescaling the clock is essential. A prescaler of 16 results in wrap times of about 13 and 10 ms
 * respectively so this should be the default, but should be configurable in board.h
 *
 * According to the reference manual, section 47.5.3.3, he counter is configured as a free-running counter when:
 *	1.  FTMEN = 0 and MOD = 0x0000 or 0xFFFF
 * or
 *	2. FTMEN = 1 and QUADEN = 0 and CPWMS = 0 and CNTIN = 0x0000 and MOD = 0xFFFF
 *
 * The second option appears to be work better because when FTMEN = 0, writes to the CnV register reset the
 * write coherency mechanism. See section 47.4.3.6.2.
 * 
 * In this driver:
 *	- The major number 0..7 specifies the FTM instance FTM0..FTM7.
 *	- The minor number 0..3 specifies the channel 0,2,4,6.
 * Odd-numbered channels are not used because they share an interrupt with the next-lower channel.
 * 
*/

/* Unless otherwise specified, assume the maximum number of FTM instances according to the ref. manual.
*/
#ifndef OS_MAX_FTM
#define OS_MAX_FTM	8
#endif

#ifndef OS_ASM

extern const os_hwtdrv_t OS_timerFtmDriver;

/* os_ftmchannel_t - a structure describing the counter registers of one FTM channel */
typedef struct os_ftmch_s os_ftmch_t;
struct os_ftmch_s
{
	os_reg32_t  ftm_csc;
	os_reg32_t  ftm_cv;
};

/* os_ftm_t - a structure describing the registers of one FTM module */
typedef struct os_ftm_s os_ftm_t;
struct os_ftm_s
{
	os_reg32_t  ftm_sc;			/* Status/control */
	os_reg32_t  ftm_cnt;		/* Counter */
	os_reg32_t  ftm_mod;		/* Modulo */
	os_ftmch_t	ftm_ch[8];		/* Counter channels */
	os_reg32_t	ftm_cntin;		/* Counter initial value */
	os_reg32_t	ftm_status;		/* Capture and compare status */
	os_reg32_t	ftm_mode;		/* Features mode selection */
	os_reg32_t	ftm_sync;		/* Synchronization */
	os_reg32_t	ftm_outinit;	/* Initial state for channels output */
	os_reg32_t	ftm_outmask;	/* Output mask */
	os_reg32_t	ftm_combine;	/* Function for linked channels */
	os_reg32_t	ftm_deadtime;	/* Deadtime configuration */
	os_reg32_t	ftm_exttrig;	/* FTM external trigger */
	os_reg32_t	ftm_pol;		/* Channels polarity */
	os_reg32_t	ftm_fms;		/* Fault mode status */
	os_reg32_t	ftm_filter;		/* Input capture filter control */
	os_reg32_t	ftm_fltctrl;	/* Fault control */
	os_reg32_t	ftm_qdctrl;		/* Quadrature decoder control and status */
	/* The rest of the registers are not modelled because they are not relevant for the OS driver */
};

/* ftm_sc
*/
#define OS_FTM_CLKS		0x00000018		/* Clock source: 00 = off; 01: FTM clock; 10: fixed freqi; 11: extern */
#define OS_FTM_CLKS_FTM	0x00000008		/* --- 01b : FTM input clock */
#define OS_FTM_CLKS_FIX	0x00000010		/* --- 10b : Fixed frequency clock */
#define OS_FTM_CLKS_EXT	0x00000018		/* --- 11b : External clock */
#define OS_FTM_PS		0x00000007		/* Prescaler : divide by 2**PS */
#define OS_FTM_PS_1		0x00000000		/* --- Divide by 1 */
#define OS_FTM_PS_2		0x00000001		/* --- Divide by 2 */
#define OS_FTM_PS_4		0x00000002		/* --- Divide by 4 */
#define OS_FTM_PS_8		0x00000003		/* --- Divide by 8 */
#define OS_FTM_PS_16	0x00000004		/* --- Divide by 16 */
#define OS_FTM_PS_32	0x00000005		/* --- Divide by 32 */
#define OS_FTM_PS_64	0x00000006		/* --- Divide by 64 */
#define OS_FTM_PS_128	0x00000007		/* --- Divide by 128 */
#define OS_FTM_TOIE		0x00000100		/* Timer Overflow Interrupt Enable */
#define OS_FTM_TOF		0x00000200		/* Timer Oveflow Flag */
#define OS_FTM_CPWMS	0x00000020		/* CPWMS = 1 Up-Down Counting mode */ 

/* ftm_cnt, ftm_mod, ftm_cntin, ftm_ch[n].ftm_cv
*/
#define OS_FTM_COUNT	0x0000ffff

/* ftm_ch[n].csc
*/
#define OS_FTM_CHOV					0x00000400		/* Channel output value */
#define OS_FTM_CHIS					0x00000200		/* Channel input value */
#define OS_FTM_TRIGMODE				0x00000100
#define OS_FTM_CHF					0x00000080		/* Channel flag */
#define OS_FTM_CHIE					0x00000040		/* Channel interrupt enable */
#define OS_FTM_MS					0x00000030		/* Mode select */
#define OS_FTM_ELS					0x0000000c		/* Edge/level select */
#define OS_FTM_ICRST				0x00000002		/* Input capture --> reset */
#define	OS_FTM_DMA					0x00000001		/* Enable DMA transfer */
#define OS_FTM_MS_OUTPUT_COMPARE	0x00000010		/* Channel Mode - Output Compare */

/* ftm_mode
*/
#define OS_FTM_FTMEN	0x00000001		/* When 0, TPM compatible (whatever that is) */
#define OS_FTM_WPDIS	0x00000004		/* Write Protection Disable */

/* FTM configuration (selected in board.h)
*/
typedef struct os_ftmdescriptor_s os_ftmdescriptor_t;
struct os_ftmdescriptor_s
{
	os_ftm_t *ftm;				/* The base address of the FTM */
	os_uint32_t clockSource;	/* One of OS_FTM_CLKS_FTM, OS_FTM_CLKS_FIX, OS_FTM_CLKS_FIX */
	os_uint32_t prescaler;		/* One of OS_FTM_PS_n */
};

extern const os_ftmdescriptor_t OS_ftmDescriptor[OS_MAX_FTM];

#endif

#endif /* OS_CORTEXM_TIMER_FTM_H */
/* Editor settings: DO NOT DELETE
 * vi: set ts=4:
*/
