/* board.h - board specific configuration file.
 *
 * This file contains the board specific configuration.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: board.h 1.2.1.2 2022/09/01 06:53:03CEST Andrei Anca (andrei.anca) in_work  $
*/

#ifndef BOARD_H
#define BOARD_H

#ifndef BOARD_ASM
#include <ncs.h>
#include <Platforms_asm_CORTEXM.h>
#include "board_pub.h"
#ifdef PLATFORMS_STUBS_ENABLED
#include <BoardStub.h>
#endif
#endif

/* ********************************************
 * General configuration
 * ********************************************
*/
#define BOARD_TRUE                      1
#define BOARD_FALSE                     0

/*
 * Feature disabling macro
 */
#ifndef BOARD_INIT_SRAM
#define BOARD_INIT_SRAM   BOARD_TRUE
#endif

#ifndef BOARD_WDG_USED
#define BOARD_WDG_USED    BOARD_TRUE
#endif

#ifndef BOARD_LED_USED
#define BOARD_LED_USED    BOARD_TRUE
#endif

#ifndef BOARD_STARTUP_CLOCK_ENABLE
#define BOARD_STARTUP_CLOCK_ENABLE      BOARD_FALSE
#endif

#ifndef BOARD_INTERRUPT_ENABLE
#define BOARD_INTERRUPT_ENABLE          BOARD_TRUE
#endif

#if (PLATFORMS_TOOLCHAIN==PLATFORMS_gnu)

#define ASM_KEYWORD __asm__
#define BOARD_GEN_STACK(var, sec, size, granule)         \
  u32 var[size]                 \
  BOARD_SECTION_ATTRIB_POST(sec)  BOARD_ALIGNED_ATTRIB_POST(granule)

#elif (PLATFORMS_TOOLCHAIN==PLATFORMS_multi)

#define ASM_KEYWORD asm
#define BOARD_GEN_STACK(var, sec, size, granule)         \
  u32 BOARD_SECTION_ATTRIB_POST(sec) BOARD_ALIGNED_ATTRIB_POST(granule) var[size]
#elif (PLATFORMS_TOOLCHAIN==PLATFORMS_iar)

#define ASM_KEYWORD __asm

#endif
/*
 * Interrupt related macro
 */
#define BOARD_CORTEXM_IRQ_0_31          31U
#define BOARD_CORTEXM_IRQ_32_63         63U
#define BOARD_CORTEXM_IRQ_64_95         95U
#define BOARD_CORTEXM_IRQ_96_127        127U
#define BOARD_CORTEXM_IRQ_128_159       159U
#define BOARD_CORTEXM_NUM_SOURCES       (BOARD_CORTEXM_IRQ_128_159)

#define INTC_LPIT0                      48U
#define INTC_FLEXCAN_ESR_BOFF           78U
#define INTC_FLEXCAN_ESR_ERR            79U
#define INTC_FLEXCAN_BUF_00_15          81U
#define INTC_FLEXCAN_BUF_16_31          82U

#define INTC_PRIO_4                     4U
#define INTC_PRIO_A                     0xA0U

#define NVIC_ISER_BASE                  (0xE000E100)
#define NVIC_ISER(x)                    (*(volatile u32 *)(NVIC_ISER_BASE + (x*4)))

#define NVIC_ISPR_BASE                  (0xE000E200)
#define NVIC_ISPR(x)                    (*(volatile u32 *)(NVIC_ISPR_BASE + (x*4)))

#define NVIC_ICPR_BASE                  (0xE000E280)
#define NVIC_ICPR(x)                    (*(volatile u32 *)(NVIC_ICPR_BASE + (x*4)))

/* interrupt priority */
#define NVIC_IP_BASE                  (0xE000E400)
#define NVIC_IP(x)                    (*(volatile u8 *)(NVIC_IP_BASE + (x)))

#define BOARD_INTC_EN(x)   \
    do {   \
        u16 shift = x; \
        u8 reg; \
        for(reg=0U; shift >= 32U; reg++ ) {  \
            shift -= 32U; } \
        NVIC_ISER(reg) |= (1 << shift); \
    } while(0)

/*#define BOARD_INTC_PRIO(x, y)   \
    do {   \
        u16 shift = x; \
        u8 reg; \
        for(reg=0U; shift >= 4U; reg++ ) { \
             shift -= 4; } \

        NVIC_IPR(reg) = (y << shift); \
    } while(0)*/

#define BOARD_INTC_SET_PENDING(x)   \
    do {   \
        u16 shift = x; \
        u8 reg; \
        for(reg=0U; shift >= 32U; reg++ ) {  \
            shift -= 32U; } \
        NVIC_ISPR(reg) |= (1 << shift); \
    } while(0)

#define BOARD_INTC_CLEAR_PENDING(x)   \
    do {   \
        u16 shift = x; \
        u8 reg; \
        for(reg=0U; shift >= 32U; reg++ ) {  \
            shift -= 32U; } \
        NVIC_ICPR(reg) |= (1 << shift); \
    } while(0)


#ifdef BOARD_ISR_TEST
#define INTC_TESTISR                    INTC_LPIT0
#define INTC_TEST                       INTC_LPIT0

/* Stub for now shall be changed */
#define TRIGGER_INT()                   BOARD_INTC_SET_PENDING(INTC_TESTISR)

#ifndef BOARD_ASM
extern volatile u32 isrCounter;
#endif
#endif

#define EXIT_BOARD_INTERRUPT_HANDLER
/*
 *	Clock frequency and prescaler
 */
#define BOARD_BUS_CLK_FREQ	40000000
#define BOARD_CORTEXM_LPIT_PRESCALER	1

#define BOARD_SYSTEM_CLOCK_HZ           80000000UL
#define BOARD_SYSTEM_CLOCK_MHZ          80UL

/*1uS is the minimal timer available*/
#define BOARD_TIMER_MINIMAL             1L

#define BOARD_SYSTEM_CLOCK_DIVIDER      2U

/*
 * Stack length
 */
#define ISTACKLEN 0x200U

#ifndef BOARD_SECTION_ATTRIB_POST
#define BOARD_SECTION_ATTRIB_POST(sec)   __attribute__ ((section(#sec)))
#endif

#ifndef BOARD_ALIGNED_ATTRIB_POST
#define BOARD_ALIGNED_ATTRIB_POST(granule)   __attribute__ ((aligned (granule)))
#endif


#ifndef BOARD_ASM
#define BOARD_START_STACK_CODE
#include "MemMap.h"
extern u32 BoardStack[ISTACKLEN];
#define BOARD_STOP_STACK_CODE
#include "MemMap.h"
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
#define BOARD_SCG_CTRL_ADDR 				0x40064010u	/* SCG Control Registers Address				*/
#define BOARD_SCG_SOSC_ADDR				0x40064100u	/* System OSC Control Status Register Address	*/
#define BOARD_SCG_SPLL_ADDR				0x40064600u	/* System PLL Control Status Register Address	*/
#define BOARD_SCG_FIRC_ADDR				0x40064300u	/* FIRC Control Status Register Address			*/

/* SOSC Divide Register (SCG_SOSCDIV), dividers: 0..7 = {disable,1,2,4,8,16,32,64}				*/
#define BOARD_SCG_SOSC_DIV1				(1u << 0)	/* system clock source							*/
#define BOARD_SCG_SOSC_DIV2				(1u << 8)	/* asynchronous clock source					*/
#define BOARD_SCG_SOSC_DIV3				(0u << 16)	/* Reserved	(depending on HW version)			*/
#define BOARD_SCG_SOSCDIV					(BOARD_SCG_SOSC_DIV1 | BOARD_SCG_SOSC_DIV2 | BOARD_SCG_SOSC_DIV3)

/* SOSC Control Status Register (SCG_SOSCCSR) */
#define BOARD_SCG_SOSCCSR_SOSCEN			(1u	<< 0)	/* 1 = Enable System OSC						*/
#define BOARD_SCG_SOSCCSR_SOSCCM			(1u	<< 16)	/* System OSC Clock Monitor						*/
#define BOARD_SCG_SOSCCSR_SOSCCMRE		(1u	<< 17)	/* System OSC Clock Monitor Reset Enable		*/
#define BOARD_SCG_SOSCCSR_LK				(1u	<< 23)	/* Lock Register: 1 = cannot be written			*/
#define BOARD_SCG_SOSCCSR_SOSCVLD			(1u << 24)	/* SOSC clock enabled and valid					*/
#define BOARD_SCG_SOSCCSR_SOSCSEL			(1u	<< 25)	/* System OSC Selected: 1 = is system clock 	*/
#define BOARD_SCG_SOSCCSR_SOSCERR			(1u	<< 26)	/* System OSC Clock Error: 1 = error detected	*/
#define BOARD_SCG_SOSCCSR					(BOARD_SCG_SOSCCSR_SOSCEN)

/* SOSC Configuration Register (SCG_SOSCCFG) */
#define BOARD_SCG_SOSCCFG_RANGE			(3u << 4)	/* System OSC Range Select: 3 = 8Mhz to 32Mhz	*/
#define BOARD_SCG_SOSCCFG_HGO				(1u << 3)	/* High Gain Oscillator Select: 1 = high gain	*/
#define BOARD_SCG_SOSCCFG_EREFS			(1u << 2)	/* External Reference Select: 1 = int_OSC		*/
#define BOARD_SCG_SOSCCFG					(BOARD_SCG_SOSCCFG_RANGE | BOARD_SCG_SOSCCFG_HGO | BOARD_SCG_SOSCCFG_EREFS)

/* Run Clock Control Register (RCCR) fields: Normal Run */
#define BOARD_SCG_RCCR_NR_SCR				(6u << 24)	/* System Clock Source: System PLL				*/
#define BOARD_SCG_RCCR_NR_DIVCORE			(0u << 16)	/* Core Clock Divide Ratio: 2					*/
#define BOARD_SCG_RCCR_NR_DIVBUS			(1u << 4)	/* Bus Clock Divide Ratio: 2					*/
#define BOARD_SCG_RCCR_NR_DIVSLOW			(2u << 0)	/* Slow Clock Divide Ratio: 3					*/
#define BOARD_SCG_RCCR_NR					(BOARD_SCG_RCCR_NR_SCR		\
									| BOARD_SCG_RCCR_NR_DIVCORE	\
									| BOARD_SCG_RCCR_NR_DIVBUS	\
									| BOARD_SCG_RCCR_NR_DIVSLOW)

/* System PLL Configuration Register (SCG_SPLLCFG) */
#define BOARD_SCG_SPLLCFG_MULT			(4u << 16)	/* Multiplier:	20								*/
#define BOARD_SCG_SPLLCFG_PREDIV			(0u << 8)	/* Pre-divider:	1								*/
#define BOARD_SCG_SPLLCFG_SOURCE			(0u << 0)	/* Source: 0 = System OSC						*/
#define BOARD_SCG_SPLLCFG					(BOARD_SCG_SPLLCFG_MULT | BOARD_SCG_SPLLCFG_PREDIV | BOARD_SCG_SPLLCFG_SOURCE)

/* System PLL Divide Register (SCG_SPLLDIV), dividers: 0..7 = {disable,1,2,4,8,16,32,64}		*/
#define BOARD_SCG_SPLLDIV_SPLLDIV1		(0u << 0)	/* Clock divider 1				Disabled		*/
#define BOARD_SCG_SPLLDIV_SPLLDIV2		(2u << 8)	/* Clock divider 2				Divide by 2		*/
#define BOARD_SCG_SPLLDIV_SPLLDIV3		(0u << 16)	/* Clock divider 3 (reserved)	Disabled		*/
#define BOARD_SCG_SPLLDIV					(BOARD_SCG_SPLLDIV_SPLLDIV1	\
									| BOARD_SCG_SPLLDIV_SPLLDIV2	\
									| BOARD_SCG_SPLLDIV_SPLLDIV3)

/* System PLL Control Status Register (BOARD_SCG_SPLLCSR) */
#define BOARD_SCG_SPLLCSR_SPLLEN			(1u	<< 0)	/* 1 = Enable System PLL						*/
#define BOARD_SCG_SPLLCSR_SPLLCM			(1u	<< 16)	/* System PLL Clock Monitor						*/
#define BOARD_SCG_SPLLCSR_SPLLCMRE		(1u	<< 17)	/* System PLL Clock Monitor Reset Enable		*/
#define BOARD_SCG_SPLLCSR_LK				(1u	<< 23)	/* Lock Register: 1 = cannot be written			*/
#define BOARD_SCG_SPLLCSR_SPLLVLD			(1u << 24)	/* System PLL clock enabled and valid			*/
#define BOARD_SCG_SPLLCSR_SPLLSEL			(1u	<< 25)	/* System PLL Selected: 1 = is system clock 	*/
#define BOARD_SCG_SPLLCSR_SPLLERR			(1u	<< 26)	/* System PLL Clock Error: 1 = error detected	*/
#define BOARD_SCG_SPLLCSR					(BOARD_SCG_SPLLCSR_SPLLEN)

/* SCG CLKOUT Configuration Register (BOARD_SCG_CLKOUTCNFG) */
#define BOARD_SCG_CLKOUTCNFG				(6u << 24)	/* 6 = System PLL */

/*
 * PCC register definition
 */
#define BOARD_PCC_BASE                    0x40065000U

/* PCC_FLEXCAN0 */
#define BOARD_PCC_FLEXCAN0_ADDR           (BOARD_PCC_BASE + 0x90U)
#define BOARD_PCC_FLEXCAN0_PR             0x80000000U
#define BOARD_PCC_FLEXCAN0_CGC            0x40000000U
#define BOARD_PCC_FLEXCAN0                (*(volatile u32 *)BOARD_PCC_FLEXCAN0_ADDR)

/* PCC_FLEXCAN1 */
#define BOARD_PCC_FLEXCAN1_ADDR           (BOARD_PCC_BASE + 0x94U)
#define BOARD_PCC_FLEXCAN1_PR             0x80000000U
#define BOARD_PCC_FLEXCAN1_CGC            0x40000000U
#define BOARD_PCC_FLEXCAN1                (*(volatile u32 *)BOARD_PCC_FLEXCAN1_ADDR)

/* PCC_LPTMR */
#define BOARD_PCC_LPTMR0_ADDR             (BOARD_PCC_BASE + 0x100U)

#define BOARD_PCC_LPTMR0_PR               0x80000000U
#define BOARD_PCC_LPTMR0_CGC              0x40000000U
#define BOARD_PCC_LPTMR0_PCSC_MASK        0x07000000U
#define BOARD_PCC_LPTMR0_PCSC_SPLL        0x06000000U
#define BOARD_PCC_LPTMR0_FRAC             0x00000008U
#define BOARD_PCC_LPTMR0_PCD              0x00000007U
#define BOARD_PCC_LPTMR0                  (*(volatile u32 *)BOARD_PCC_LPTMR0_ADDR)

/*
 * LPTMR register definition
 */
#define BOARD_LPTMR_BASE          0x40040000U
#define BOARD_LPTMR_CSR_ADDR      BOARD_LPTMR_BASE
#define BOARD_LPTMR_PSR_ADDR      (BOARD_LPTMR_BASE + 4U)
#define BOARD_LPTMR_CMR_ADDR      (BOARD_LPTMR_BASE + 8U)
#define BOARD_LPTMR_CNR_ADDR      (BOARD_LPTMR_BASE + 12U)

/* CSR register */
#define BOARD_LPTMR_CSR_TEN       0x1U
#define BOARD_LPTMR_CSR_TMS       0x2U
#define BOARD_LPTMR_CSR_TFC       0x4U
#define BOARD_LPTMR_CSR_TPP       0x8U
#define BOARD_LPTMR_CSR_TPS       0x30U
#define BOARD_LPTMR_CSR_TIE       0x40U
#define BOARD_LPTMR_CSR_TCF       0x80U
#define BOARD_LPTMR_CSR_TDRE      0x100U
#define BOARD_LPTMR_CSR           (*(volatile u32 *)BOARD_LPTMR_CSR_ADDR)

/* PSR register */
#define BOARD_LPTMR_PSR_PCS       0x03U
#define BOARD_LPTMR_PSR_PBYP      0x04U
#define BOARD_LPTMR_PSR_PRESCALE  0x78U
#define BOARD_LPTMR_PSR           (*(volatile u32 *)BOARD_LPTMR_PSR_ADDR)

/* CMR register */
#define BOARD_LPTMR_CMR_COMPARE   0x0000FFFFU
#define BOARD_LPTMR_CMR           (*(volatile u32 *)BOARD_LPTMR_CMR_ADDR)

/* CNR register */
#define BOARD_LPTMR_CNR_COUNTER   0x0000FFFFU
#define BOARD_LPTMR_CNR           (*(volatile u32 *)BOARD_LPTMR_CNR_ADDR)

/*
 * LPIT register definition
 */
#define BOARD_LPIT_BASE           0x40037000U
#define BOARD_LPIT_MCR_ADDR       (BOARD_LPIT_BASE + 8U)
#define BOARD_LPIT_CVAL0_ADDR     (BOARD_LPIT_BASE + 0x24U)
#define BOARD_LPIT_TCTRL0_ADDR    (BOARD_LPIT_BASE + 0x28U)

#define BOARD_LPIT_MCR_MCEN       1U
#define BOARD_LPIT_MCR            (*(volatile u32 *)BOARD_LPIT_MCR_ADDR)

#define BOARD_LPIT_TCTRL0_TEN     1U
#define BOARD_LPIT_TCTRL0         (*(volatile u32 *)BOARD_LPIT_TCTRL0_ADDR)

#define BOARD_LPIT_CVAL0         (*(volatile u32 *)BOARD_LPIT_CVAL0_ADDR)
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


#define BOARD_NXPMPU_ADDR			0x4000D000u	/* MPU Base address								*/
#define BOARD_NXPMPU_ENABLE		1u			/* Enable MPU Module */


/* CONTROL bit FPCA floating point extension active in current
 * context. This means, the floating point context is automatically
 * saved on exceptoin entry.
*/
#define BOARD_CORTEXM_CONTROL_FPCA       0x00000004

/* FPCCR bit ASPEN: If 1, the CPU sets CONTROL.FPCA to 1 after
 * a FPU instruction was executed.
*/
#define BOARD_FPCCR_ASPEN    (1 << 31)
/* FPCCR bit LSPEN: If 1, the CPU enables lazy FPU context saving.
*/
#define BOARD_FPCCR_LSPEN    (1 << 30)

/*
 * Reset configuration
 */
/*
 * AIRCR Register mapping
 * Use to trigger a reset
 */
#define BOARD_AIRCR_BASEADDR            0xE000ED0CU

#define BOARD_AIRCR_VECTKEY             0x05FA0000U
#define BOARD_AIRCR_VECTKEY_MASK        0xFFFF0000U
#define BOARD_AIRCR_PRIGROUP_MASK       0x00000700U
#define BOARD_AIRCR_SYSRESETREQ_MASK    0x00000004U

#define BOARD_AIRCR                     (*(volatile u32 *)BOARD_AIRCR_BASEADDR)

/*
 * RCM_SRS Register mapping
 * Use to get reset type
 */
#define BOARD_RCM_BASEADDR                0x4007F000U
#define BOARD_RCM_SRS_OFFSET              8

#define BOARD_RCM_SRS_LVD                     0x00000002U
#define BOARD_RCM_SRS_LOC                     0x00000004U
#define BOARD_RCM_SRS_LOL                     0x00000008U
#define BOARD_RCM_SRS_WDOG                    0x00000020U
#define BOARD_RCM_SRS_PIN                     0x00000040U
#define BOARD_RCM_SRS_POR                     0x00000080U
#define BOARD_RCM_SRS_JTAG                    0x00000100U
#define BOARD_RCM_SRS_LOCKUP                  0x00000200U
#define BOARD_RCM_SRS_SW                      0x00000400U
#define BOARD_RCM_SRS_MDM_AP                  0x00000800U
#define BOARD_RCM_SRS_SACKERR                 0x00002000U
#define BOARD_RCM_SRS                         (*(volatile u32 *)(BOARD_RCM_BASEADDR + BOARD_RCM_SRS_OFFSET))

/*
 * SCR register
 */
#define BOARD_SCR_BASEADDR                    0xE000ED10U

#define BOARD_SCR_SLEEPDEEP_MASK32            0x00000004U
#define BOARD_SRS                         (*(volatile u32 *)BOARD_SCR_BASEADDR)

/*
 *	C only definitions
 */
#ifndef BOARD_ASM

extern u8 m_ubBoardIntLockNestingCounter;

/* LED functions */
#define LEDS_INIT()	do { BoardInitLeds(); } while (0)
#define LEDS_SET(a)	do { BoardProgramLeds(a); } while (0)

extern void main(void);

/* Called from demo.c */
extern void BoardInitLeds(void);				/* Initialize the LEDs							*/
extern void BoardProgramLeds(u32);		/* Write the lower 3 bits of status to LEDs		*/
extern void BoardStart(void);					/* Entry point after assembly startup			*/
extern u8 BoardSchedulingTimer (void);

/* Interrupt related functions */
extern void boardDisableInterrupts(void);
extern void boardEnableInterrupts(void);
extern void boardDisableInterruptsAsm(void);
extern void boardEnableInterruptsAsm(void);

extern void Board_CORTEXM_EnableVFPCoprocessor(void);

extern void *memcpy(void *, const void *, u32);
extern void *memset(void *s, int c, u32 n);
extern void *memcmp(void const * const a, void const * const b, const u32 len);

extern u8 BOARD_GET_ISR_SRC(void);

/* Watchdog registers */
struct board_wdt_s
{
	u32 cs;								/* 0x00 Watchdog Control & Status Register (CS)	*/
	u32 cnt;								/* 0x04 Watchdog Counter Register (CNT)			*/
	u32 toval;							/* 0x08 Watchdog Timeout Value Register (TOVAL) */
	u32 win;								/* 0x0C Watchdog Window Register (WIN)			*/
};

/* SCG Control register map */
struct board_scg_ctrl_s
{
	u32 csr;								/* offset + 0x00 Clock Status Register			*/
	u32 rccr;							/* offset + 0x04 RUN Clock Control Register		*/
	u32 vccr;							/* offset + 0x08 VLPR Clock Control Register	*/
	u32 hccr;							/* offset + 0x0C HSRUN Clock Control Register	*/
	u32 clkoutcnfg;						/* offset + 0x10 CLKOUT Configuration Register	*/
};

/* Clock control register map */
struct board_scg_clk_s
{
	u32 csr;								/* 0x00 Control Status Register					*/
	u32 div;								/* 0x04 Divide Register							*/
	u32 cfg;								/* 0x08 Configuration Register					*/
};

typedef struct board_nxpmpu_s board_nxpmpu_t;
struct board_nxpmpu_s							/* control and status registers of the NXP MPU	*/
{
	u32  cesr;						/* 0x00 -- Control/Error Status (CESR) 			*/
	u32  _pad[3];					/* 0x04	-- 3 words padding: 0x04, 0x08, 0x0C	*/
	u32  ear0;						/* 0x10	-- Error Address, slave port 0 (EAR0)	*/
	u32  edr0;						/* 0x14	-- Error Detail, slave port 0 (EDR0)	*/
	u32  ear1;						/* 0x18	-- Error Address, slave port 1 (EAR0)	*/
	u32  edr1;						/* 0x1C	-- Error Detail, slave port 1 (EDR0)	*/
	u32  ear2;						/* 0x20	-- Error Address, slave port 2 (EAR0)	*/
	u32  edr2;						/* 0x24	-- Error Detail, slave port 2 (EDR0)	*/
	u32  ear3;						/* 0x28	-- Error Address, slave port 3 (EAR0)	*/
	u32  edr3;						/* 0x2C	-- Error Detail, slave port 3 (EDR0)	*/
};

typedef struct board_nxpmpu_rgd_s board_nxpmpu_rgd_t;
struct board_nxpmpu_rgd_s						/* region descriptors of the NXP MPU			*/
{
	u32  w0_start;					/* 0xX0	--	32 byte alligned start address		*/
	u32  w1_end;						/* 0xX4	--	32 byte alligned end address		*/
	u32  w2_acr;						/* 0xX8	--	access control rights				*/
	u32  w3_pid;						/* 0xXC	--	pid, pid-mask, valid bit			*/
};

#endif /* ! BOARD_ASM */

#endif /* BOARD_H */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
