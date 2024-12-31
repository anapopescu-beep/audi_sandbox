/* board.h - board specific configuration file.
 *
 * This file contains the board specific configuration.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: board.h 1.2.1.2 2022/09/01 06:52:41CEST Andrei Anca (andrei.anca) in_work  $
*/

#ifndef BOARD_H
#define BOARD_H 1

#include <board_version_check.h>
#include <Os_timeconversion.h>
#include <CORTEXM/Os_CORTEXM_timer_fs_lpit_config.h>


/*
 *	Clock frequency and prescaler
 */
#define BOARD_BUS_CLK_FREQ	40000000
#define BOARD_CORTEXM_LPIT_PRESCALER	1


/*
 *	Time conversion macros
 */
#if (BOARD_BUS_CLK_FREQ == 40000000) && (BOARD_CORTEXM_LPIT_PRESCALER == 1)
#define OS_BoardLPITNsToTicks(ns)		OS_NsToTicks_40000000(ns)
#define OS_BoardLPITTicksToNs(ticks)	OS_TicksToNs_40000000(ticks)
#else
#error "Please adjust conversion macros."
#endif


/*
 *	Peripheral Clock Controller
 */
#define BOARD_PCC_PTD_ADDR			0x40065130u
#define BOARD_PCC_LPIT_ADDR			0x400650DCu


/*
 *	Watchdog related definitions
 */
#define BOARD_WDT_ADDR				0x40052000u
#define BOARD_WDT_UNLOCK_SEQ		0xD928C520u
#define BOARD_WDT_TOVAL				0x00000400u
#define BOARD_WDT_CS_UPD			(1u << 5)	/* allow(1) updates flag						*/
#define BOARD_WDT_CS_EN				(1u << 7)	/* enable (1) / disable flag					*/
#define BOARD_WDT_CS_CLK			(1u << 8)	/* Watchdog Clock: LPO clock					*/
#define BOARD_WDT_CS_RCS			(1u << 10)	/* Reconfiguration flag, success=1				*/
#define BOARD_WDT_CS_ULK			(1u << 11)	/* unlocked(1)/locked flag						*/
#define BOARD_WDT_CS_PRES			(1u << 12)	/* Watchdog 256x prescaler: 1 = enable			*/
#define BOARD_WDT_CS_CMD32EN		(1u << 13)	/* Support 32-bit refresh/unlock command words	*/
#define BOARD_WDT_CS_FLG			(1u << 14)	/* Watchdog Interrupt Flag						*/
#define BOARD_WDT_CS_WIN			(1u << 15)	/* Watchdog Window								*/


/*
 *	System Clock Generator Module
 */
#define SCG_CTRL_ADDR 				0x40064010u	/* SCG Control Registers Address				*/
#define SCG_SOSC_ADDR				0x40064100u	/* System OSC Control Status Register Address	*/
#define SCG_SPLL_ADDR				0x40064600u	/* System PLL Control Status Register Address	*/
#define SCG_FIRC_ADDR				0x40064300u	/* FIRC Control Status Register Address			*/

/* SOSC Divide Register (SCG_SOSCDIV), dividers: 0..7 = {disable,1,2,4,8,16,32,64}				*/
#define SCG_SOSC_DIV1				(1u << 0)	/* system clock source							*/
#define SCG_SOSC_DIV2				(0u << 8)	/* asynchronous clock source					*/
#define SCG_SOSC_DIV3				(0u << 16)	/* Reserved	(depending on HW version)			*/
#define SCG_SOSCDIV					(SCG_SOSC_DIV1 | SCG_SOSC_DIV2 | SCG_SOSC_DIV3)

/* SOSC Control Status Register (SCG_SOSCCSR) */
#define SCG_SOSCCSR_SOSCEN			(1u	<< 0)	/* 1 = Enable System OSC						*/
#define SCG_SOSCCSR_SOSCCM			(1u	<< 16)	/* System OSC Clock Monitor						*/
#define SCG_SOSCCSR_SOSCCMRE		(1u	<< 17)	/* System OSC Clock Monitor Reset Enable		*/
#define SCG_SOSCCSR_LK				(1u	<< 23)	/* Lock Register: 1 = cannot be written			*/
#define SCG_SOSCCSR_SOSCVLD			(1u << 24)	/* SOSC clock enabled and valid					*/
#define SCG_SOSCCSR_SOSCSEL			(1u	<< 25)	/* System OSC Selected: 1 = is system clock 	*/
#define SCG_SOSCCSR_SOSCERR			(1u	<< 26)	/* System OSC Clock Error: 1 = error detected	*/
#define SCG_SOSCCSR					(SCG_SOSCCSR_SOSCEN)

/* SOSC Configuration Register (SCG_SOSCCFG) */
#define SCG_SOSCCFG_RANGE			(3u << 4)	/* System OSC Range Select: 3 = 8Mhz to 32Mhz	*/
#define SCG_SOSCCFG_HGO				(1u << 3)	/* High Gain Oscillator Select: 1 = high gain	*/
#define SCG_SOSCCFG_EREFS			(1u << 2)	/* External Reference Select: 1 = int_OSC		*/
#define SCG_SOSCCFG					(SCG_SOSCCFG_RANGE | SCG_SOSCCFG_HGO | SCG_SOSCCFG_EREFS)

/* Run Clock Control Register (RCCR) fields: Normal Run */
#define SCG_RCCR_NR_SCR				(6u << 24)	/* System Clock Source: System PLL				*/
#define SCG_RCCR_NR_DIVCORE			(1u << 16)	/* Core Clock Divide Ratio: 2					*/
#define SCG_RCCR_NR_DIVBUS			(1u << 4)	/* Bus Clock Divide Ratio: 2					*/
#define SCG_RCCR_NR_DIVSLOW			(2u << 0)	/* Slow Clock Divide Ratio: 3					*/
#define SCG_RCCR_NR					(SCG_RCCR_NR_SCR		\
									| SCG_RCCR_NR_DIVCORE	\
									| SCG_RCCR_NR_DIVBUS	\
									| SCG_RCCR_NR_DIVSLOW)

/* System PLL Configuration Register (SCG_SPLLCFG) */
#define SCG_SPLLCFG_MULT			(4u << 16)	/* Multiplier:	20								*/
#define SCG_SPLLCFG_PREDIV			(0u << 8)	/* Pre-divider:	1								*/
#define SCG_SPLLCFG_SOURCE			(0u << 0)	/* Source: 0 = System OSC						*/
#define SCG_SPLLCFG					(SCG_SPLLCFG_MULT | SCG_SPLLCFG_PREDIV | SCG_SPLLCFG_SOURCE)

/* System PLL Divide Register (SCG_SPLLDIV), dividers: 0..7 = {disable,1,2,4,8,16,32,64}		*/
#define SCG_SPLLDIV_SPLLDIV1		(0u << 0)	/* Clock divider 1				Disabled		*/
#define SCG_SPLLDIV_SPLLDIV2		(2u << 8)	/* Clock divider 2				Divide by 2		*/
#define SCG_SPLLDIV_SPLLDIV3		(0u << 16)	/* Clock divider 3 (reserved)	Disabled		*/
#define SCG_SPLLDIV					(SCG_SPLLDIV_SPLLDIV1	\
									| SCG_SPLLDIV_SPLLDIV2	\
									| SCG_SPLLDIV_SPLLDIV3)

/* System PLL Control Status Register (SCG_SPLLCSR) */
#define SCG_SPLLCSR_SPLLEN			(1u	<< 0)	/* 1 = Enable System PLL						*/
#define SCG_SPLLCSR_SPLLCM			(1u	<< 16)	/* System PLL Clock Monitor						*/
#define SCG_SPLLCSR_SPLLCMRE		(1u	<< 17)	/* System PLL Clock Monitor Reset Enable		*/
#define SCG_SPLLCSR_LK				(1u	<< 23)	/* Lock Register: 1 = cannot be written			*/
#define SCG_SPLLCSR_SPLLVLD			(1u << 24)	/* System PLL clock enabled and valid			*/
#define SCG_SPLLCSR_SPLLSEL			(1u	<< 25)	/* System PLL Selected: 1 = is system clock 	*/
#define SCG_SPLLCSR_SPLLERR			(1u	<< 26)	/* System PLL Clock Error: 1 = error detected	*/
#define SCG_SPLLCSR					(SCG_SPLLCSR_SPLLEN)

/* SCG CLKOUT Configuration Register (SCG_CLKOUTCNFG) */
#define SCG_CLKOUTCNFG				(6u << 24)	/* 6 = System PLL */


/*
 *	LEDs related definitions
 */
#define BOARD_PORTD_MX_CTL_BASEADDR	0x4004C000u	/* Port D multiplexing control (LED pins)		*/
#define BOARD_GPIO_REG_LEDS_ADDR	0x400FF0D4u /* Address of the GPIO register (control LEDs)	*/

/* LED color codes in GPIO-pin representation */
#define BOARD_LED_R					0x00008000u	/*	red		*/
#define BOARD_LED_G					0x00010000u	/*	green	*/
#define BOARD_LED_B					0x00000001u	/*	blue	*/
#define BOARD_LED_C					0x00010001u	/*	cyan	*/
#define BOARD_LED_M					0x00008001u	/*	magenta	*/
#define BOARD_LED_Y					0x00018000u	/*	yellow	*/
#define BOARD_LED_K					0x00000000u	/*	black	*/
#define BOARD_LED_W					0x00018001u	/*	white	*/
#define BOARD_LEDCLRS				8u;


/*
 *	C only definitions
 */
#ifndef OS_ASM

/* LED functions */
#define LEDS_INIT()	do { BoardInitLeds(); } while (0)
#define LEDS_SET(a)	do { BoardProgramLeds(a); } while (0)

/* Called from demo.c */
extern void BoardInitLeds(void);				/* Initialize the LEDs							*/
extern void BoardProgramLeds(os_uint32_t);		/* Write the lower 3 bits of status to LEDs		*/
extern void BoardStart(void);					/* Entry point after assembly startup			*/

/* Interrupt related functions */
extern void boardDisableInterrupts(void);
extern void boardEnableInterrupts(void);

/* main() */
extern os_int32_t main(void);

/* Watchdog registers */
struct board_wdt_s
{
	os_reg32_t cs;								/* 0x00 Watchdog Control & Status Register (CS)	*/
	os_reg32_t cnt;								/* 0x04 Watchdog Counter Register (CNT)			*/
	os_reg32_t toval;							/* 0x08 Watchdog Timeout Value Register (TOVAL) */
	os_reg32_t win;								/* 0x0C Watchdog Window Register (WIN)			*/
};

/* SCG Control register map */
struct board_scg_ctrl_s
{
	os_reg32_t csr;								/* offset + 0x00 Clock Status Register			*/
	os_reg32_t rccr;							/* offset + 0x04 RUN Clock Control Register		*/
	os_reg32_t vccr;							/* offset + 0x08 VLPR Clock Control Register	*/
	os_reg32_t hccr;							/* offset + 0x0C HSRUN Clock Control Register	*/
	os_reg32_t clkoutcnfg;						/* offset + 0x10 CLKOUT Configuration Register	*/
};

/* Clock controll register map */
struct board_scg_clk_s
{
	os_reg32_t csr;								/* 0x00 Control Status Register					*/
	os_reg32_t div;								/* 0x04 Divide Register							*/
	os_reg32_t cfg;								/* 0x08 Configuration Register					*/
};

#endif /* ! OS_ASM */

#endif /* BOARD_H */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
