/* board.c - board specific code.
 *
 * This file contains board-specific startup code.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: board.c 1.2.1.2 2022/09/01 06:52:41CEST Andrei Anca (andrei.anca) in_work  $
*/

#include <board.h>
#include <TSMem.h>     /* memory copy and set routines */

/* Static function declarations */
#if (BOARD_TRUE == BOARD_WDG_USED)
static void BoardDisableWatchdog(void);
#endif
static void BoardEnablePeripherals(void);
#if (BOARD_TRUE == BOARD_STARTUP_CLOCK_ENABLE)
static void BoardSetupClocks(void);
#endif
#if (BOARD_TRUE == BOARD_INIT_SRAM)
static void BoardInitMemorySections(void);
#endif
static void BoardDisableMPU(void);

u8 m_ubBoardIntLockNestingCounter = 0U;

/* Watchdog */
volatile static struct board_wdt_s * const board_wdt = (struct board_wdt_s *)BOARD_WDT_ADDR;

/* System Clock Generator (SCG) Control Registers Address */
volatile static struct board_scg_ctrl_s * const board_scg_ctrl = (struct board_scg_ctrl_s *)BOARD_SCG_CTRL_ADDR;

/* System Oscillator Control Status Register */
volatile static struct board_scg_clk_s * const board_scg_sosc = (struct board_scg_clk_s *)BOARD_SCG_SOSC_ADDR;

/* System PLL Control Status Register */
volatile static struct board_scg_clk_s * const board_scg_pll = (struct board_scg_clk_s *)BOARD_SCG_SPLL_ADDR;

/* Fast IRC Control Status Register */
volatile static struct board_scg_clk_s * const board_scg_firc = (struct board_scg_clk_s *)BOARD_SCG_FIRC_ADDR;

/* Pre-set meaningful colors for the LEDs */
static const u32 led_colors[] = {
        BOARD_LED_R,
        BOARD_LED_G,
        BOARD_LED_B,
        BOARD_LED_C,
        BOARD_LED_M,
        BOARD_LED_Y,
        BOARD_LED_W,
        BOARD_LED_K,
};

#if (PLATFORMS_TOOLCHAIN!=Platforms_iar)
/* CHECK: RULE 401 OFF (linker generated symbols) */
/* linker generated symbol: begin of data section (VMA) */
extern u32 PLATFORMS_TOOL_SECTION_VMA(DATA);
/* linker generated symbol: begin of data section (LMA) */
extern u32 PLATFORMS_TOOL_SECTION_LMA(DATA);
/* linker generated symbol: end of data section (VMA) */
extern u32 PLATFORMS_TOOL_SECTION_VMA_END(DATA);
/* linker generated symbol: begin of BSS section (VMA) */
extern u32 PLATFORMS_TOOL_SECTION_VMA(BSS);
/* linker generated symbol: end of BSS section (VMA) */
extern u32 PLATFORMS_TOOL_SECTION_VMA_END(BSS);
/* linker generated symbol: begin of NOINIT section (VMA) */
extern u32 PLATFORMS_TOOL_SECTION_VMA(NOINIT);
/* linker generated symbol: end of NOINIT section (VMA) */
extern u32 PLATFORMS_TOOL_SECTION_VMA_END(NOINIT);
/* linker generated symbol: begin of Flash_API_RAM_SECTION section (VMA) */
extern u32 PLATFORMS_TOOL_SECTION_FLASH_START(API_RAM);
/* linker generated symbol: end of Flash_API_RAM_SECTION section (VMA) */
extern u32 PLATFORMS_TOOL_SECTION_FLASH_END(API_RAM);
/* CHECK: RULE 401 ON */
#else
/* linker generated symbol: begin of anonymous DATA section (load address) */
extern uint32 PLATFORMS_TOOL_INITDATA;
/* linker generated symbol: begin of anonymous DATA section (execution address) */
extern uint32 PLATFORMS_TOOL_STARTDATA;
/* linker generated symbol: end of anonymous DATA section (execution address) */
extern uint32 PLATFORMS_TOOL_ENDDATA;
/* linker generated symbol: start of BSS section (VMA) */
extern uint32 PLATFORMS_TOOL_STARTBSS;
/* linker generated symbol: end of BSS section (VMA) */
extern uint32 PLATFORMS_TOOL_ENDBSS;
/* linker generated symbol: end of BSS section (VMA) */
extern uint32 PLATFORMS_TOOL_START_FLASH_API_RAM;
/* linker generated symbol: start of BSS section (VMA) */
extern uint32 PLATFORMS_TOOL_END_FLASH_API_RAM;
#endif

#if (BOARD_TRUE == BOARD_WDG_USED)
/* Disables the watchdog. */
void BoardDisableWatchdog(void)
{
    /* unlock the WDOG registres */
    board_wdt->cnt = BOARD_WDT_UNLOCK_SEQ;
    /* we have 8'd128 bus clocks to set win, toval and cs */
    board_wdt->toval = BOARD_WDT_TOVAL;
    /* disable WDOG, keep updates allowed, use default clock, set 32-bit command words */
    board_wdt->cs = (BOARD_WDT_CS_UPD | BOARD_WDT_CS_CLK | BOARD_WDT_CS_CMD32EN);
}
#endif
/* Enable the peripherals in PCC. */
void BoardEnablePeripherals(void)
{
    u32 * const pcc_ptd = (u32 *)BOARD_PCC_PTD_ADDR;
    u32 * const pcc_lpit = (u32 *)BOARD_PCC_LPIT_ADDR;
    *pcc_ptd    = 0xC0000000;   /* enable clock-gated portd for the LEDs */
    *pcc_lpit   = 0xC6000000;   /* enable clock-gated lpit, use SPLL_CLK */
}

#if (BOARD_TRUE == BOARD_STARTUP_CLOCK_ENABLE)
void BoardSetupClocks(void)
{
    /* Setup clocks and power up PLL
    * Default configuration after reset is FIRC 48 MHz. This means that:
    * Fast Internal Reference Clock is the active system clock.
    * 
    * FIRC can only provide frequencies in the range of 48-60 MHz,
    * we need to switch to System PLL clock to run in
    * "Normal" (80 MHz) or "High-Speed" (112 MHz) modes.
    * 
    * --------------------------------------------------------
    *               SLOW-RUN    NORMAL-RUN      HIGH-SPEED-RUN
    * CORE_CLK      48 MHz      80    MHz       112 MHz
    * SYS_CLK       48 MHz      80    MHz       112 MHz
    * BUS_CLK       48 MHz      40    MHz       56  MHz
    * FLASH_CLK     24 MHz      26,67 MHz       28  MHz
    * --------------------------------------------------------
    *
    * Selecting a different clock source when in RUN requires clock source
    * to be enabled first and be valid before system clocks switch to that
    * clock source. If system clock divide ratios also change when selecting
    * a different clock mode when in RUN, new system clock divide ratios
    * will not take affect until new clock source is valid.
    */

    /* configure SOSC */
    board_scg_sosc->csr &= ~BOARD_SCG_SOSCCSR_SOSCEN; /* SOSC has to be disabled first */
    board_scg_sosc->cfg = BOARD_SCG_SOSCCFG;
    board_scg_sosc->div = BOARD_SCG_SOSCDIV;
    board_scg_sosc->csr = BOARD_SCG_SOSCCSR;
    while ((board_scg_sosc->csr & BOARD_SCG_SOSCCSR_SOSCVLD) == 0)
    {
        /* wait for SOSC clock to become ready. */
    }

    /* configure SPLL: div2 goes to LPIT */
    board_scg_pll->cfg = BOARD_SCG_SPLLCFG;
    board_scg_pll->div = BOARD_SCG_SPLLDIV;
    board_scg_pll->csr = BOARD_SCG_SPLLCSR;
    while ((board_scg_pll->csr & BOARD_SCG_SPLLCSR_SPLLVLD) == 0)
    {
        /* wait for SPLL clock to become ready. */
    }

    /* set up SCG to use SPLL */
    board_scg_ctrl->rccr = BOARD_SCG_RCCR_NR;
    
    /* set CLKOUT to SPLL */
    board_scg_ctrl->clkoutcnfg = BOARD_SCG_CLKOUTCNFG;
    
    /* disable the FIRC clock */
    board_scg_firc->csr = 0x0u;

    /* Enable both can controler clock */
    BOARD_PCC_FLEXCAN0 = BOARD_PCC_FLEXCAN0_CGC;
    BOARD_PCC_FLEXCAN1 = BOARD_PCC_FLEXCAN1_CGC;

    /* Enable timer clock */
    /* Select SPLL clock source */
    BOARD_PCC_LPTMR0 = (u32)(BOARD_PCC_LPTMR0_PCSC_SPLL & BOARD_PCC_LPTMR0_PCSC_MASK);
    BOARD_PCC_LPTMR0 |= (u32)(BOARD_PCC_LPTMR0_CGC);
}
#endif

u8 BoardInitializationTimers(u16 uwTimer)
{
    u8 RetVal = 0u;

#if(BOARD_STARTUP_CLOCK_ENABLE == BOARD_TRUE)
    u32 ulTimerValue = 0u;

    /* check Timer validity and Board frequency available */
    if ((uwTimer >= BOARD_TIMER_MINIMAL) && (BOARD_SYSTEM_CLOCK_MHZ > 0))
    {
        /* Turn on Periodic Interrupt Timer */
        /* FRZ = 1 : Timer freezed in debug mode */
        BOARD_LPTMR_CSR = 0x00U;

        /* Timer for scheduling: */
        /* F40 is the input CLK for the PIT
         * F40 is MAx 40Mhz
         */
        /* Input clock is x MHz = y ns
         * Use Timer with uwTimer in __nS__ period (parameter is passed on __µS__)
         * x MHz => Load value must be uwTimer/y ns cycles
         */
        /* multiply before divide to avoid timer to be round down/up*/
        ulTimerValue = (u32)(uwTimer * 4);

        /* Set Compare value to calculated timeout */
        BOARD_LPTMR_CMR = ulTimerValue;

        /* Disable prescaler */
        BOARD_LPTMR_PSR = (0x4 & BOARD_LPTMR_PSR_PBYP);

        BOARD_LPTMR_CSR = (BOARD_LPTMR_CSR_TEN);

        /* activate LPTI timer only for random value generation */
        /* Activate LPIT cell */
        BOARD_LPIT_MCR = BOARD_LPIT_MCR_MCEN;

        /* Activate Timer 0 */
        BOARD_LPIT_TCTRL0 = BOARD_LPIT_TCTRL0_TEN;

        /* Timer configured OK*/
        RetVal = 1u;
    }
    else
    {
        RetVal = 0u;
    }
#else
    /* This is done here in order to prevent infinite loops when calling the function
     * Please refer to OSCPLATFORMS-334
     */
    RetVal = 1u;
#endif
    return RetVal;
}

u8 BoardSchedulingTimer (void)
{
    u8 ubFlag = BOARD_FALSE;

    /* Timer is scheduled at 1ms */
    if (BOARD_LPTMR_CSR_TCF == ((u8)(BOARD_LPTMR_CSR & BOARD_LPTMR_CSR_TCF)))
    {
        /* reset timer */
        BOARD_LPTMR_CSR |= (BOARD_LPTMR_CSR_TCF);

        /* Set return flag to TRUE */
        ubFlag = BOARD_TRUE;
    }

    return ubFlag;
}

#if (BOARD_TRUE == BOARD_INIT_SRAM)
/* Initialize memory sections (data, bss). */
#if (PLATFORMS_TOOLCHAIN!=Platforms_iar)
void BoardInitMemorySections(void)
{
    register u32 *ram;
    register u32 *flash;
    register Platforms_ResetType Reset;


    for (ram = &PLATFORMS_TOOL_SECTION_VMA(DATA), flash = &PLATFORMS_TOOL_SECTION_LMA(DATA);
         ram < &PLATFORMS_TOOL_SECTION_VMA_END(DATA);
         ram++, flash++)
    {
        *ram = *flash;
    }
    for (ram = &PLATFORMS_TOOL_SECTION_VMA(BSS);
         ram < &PLATFORMS_TOOL_SECTION_VMA_END(BSS);
         ram++)
    {
        *ram = 0;
    }
    for (ram = &PLATFORMS_TOOL_SECTION_FLASH_START(API_RAM);
         ram < &PLATFORMS_TOOL_SECTION_FLASH_END(API_RAM);
         ram++)
    {
        *ram = 0;
    }

    /* Get reset reason */
    Reset = BoardIsSwReset();

    /* If reset was not a software reset init the No Init ram */
    if(Reset != PLATFORMS_SW_RESET)
    {
        for (ram = &PLATFORMS_TOOL_SECTION_VMA(NOINIT);
              ram < &PLATFORMS_TOOL_SECTION_VMA_END(NOINIT);
              ram++)
        {
            *ram = 0;
        }
    }
}
#else
void BoardInitMemorySections(void)
{
    register u32 *ram;
    register u32 *flash;


    for (ram = &PLATFORMS_TOOL_STARTDATA, flash = &PLATFORMS_TOOL_INITDATA;
         ram < &PLATFORMS_TOOL_ENDDATA;
         ram++, flash++)
    {
        *ram = *flash;
    }
    for (ram = &PLATFORMS_TOOL_STARTBSS;
         ram < &PLATFORMS_TOOL_ENDBSS;
         ram++)
    {
        *ram = 0;
    }
    for (ram = &PLATFORMS_TOOL_START_FLASH_API_RAM;
         ram < &PLATFORMS_TOOL_END_FLASH_API_RAM;
         ram++)
    {
        *ram = 0;
    }
}
#endif
#endif

/* MPU should be disabled at startup    */
void BoardDisableMPU(void)
{
    board_nxpmpu_t* const board_mpu = (board_nxpmpu_t*)BOARD_NXPMPU_ADDR;
    board_mpu->cesr &= ~(BOARD_NXPMPU_ENABLE);
}

#if (BOARD_TRUE == BOARD_LED_USED)
/* Initialize the LEDs */
void BoardInitLeds(void)
{
    /*  Set operation mode of pins: 0,15,16 on Port-D to control RGB-leds by
     *  setting multiplexer switch to 0x100u */
    u32 * const ptd_mxctl = (u32 *)BOARD_PORTD_MX_CTL_BASEADDR;
    ptd_mxctl[0]    = 0x100u;   /*  Enable Blue LED:    ptd0    */
    ptd_mxctl[15]   = 0x100u;   /*  Enable Red LED:     ptd15   */
    ptd_mxctl[16]   = 0x100u;   /*  Enable Green LED:   ptd16   */
}
#endif
#if (BOARD_TRUE == BOARD_LED_USED)
/* Make LEDs represent the lower three bits of status. */
void BoardProgramLeds(u32 status)
{
    u32 * const board_leds = (u32 *)BOARD_GPIO_REG_LEDS_ADDR;
    u32 index = (status & 0x7u);
    if (led_colors[index] != *board_leds)
    {
        *board_leds = led_colors[index];
    }
}
#endif
/*
 * BoardStart() - called from assembler
*/
void BoardStart(void)
{
    /* Note: You may only use the stack and rely on initialized data,
     * after BoardInitMemorySections() was executed.
    */
#if (BOARD_TRUE == BOARD_WDG_USED)
    BoardDisableWatchdog();
#endif
#if (BOARD_TRUE == BOARD_INIT_SRAM)
    BoardInitMemorySections();
#endif

    /* From here on you can rely on data and stack. */

    BoardDisableInterrupts();

    BoardEnablePeripherals();
#if (BOARD_TRUE == BOARD_STARTUP_CLOCK_ENABLE)
    BoardSetupClocks();
#endif

    /*BoardInitializationTimers(1000);*/

    Board_CORTEXM_EnableVFPCoprocessor();

    BoardDisableMPU();

#if (BOARD_TRUE == BOARD_INTERRUPT_ENABLE)
    BoardInitInterrupts();

    BoardEnableInterrupts();
#endif
    /* When all that is done, we can start the OS */
    main();

    /* NOT REACHED */
}

#if (PLATFORMS_TOOLCHAIN == PLATFORMS_gnu)
/* To avoid drawing in the C-library, we need to provide a memcpy
 * function for gcc-generated code.
 * Probably, you may want to use a proper C-library instead.
*/


#define unlikely(expr) __builtin_expect(!!(expr), 0)

void *memcpy(void *dest, const void *src, u32 n)
{
    u32 i;
    void * tmp = dest;

    /* check assumptions */
    if (unlikely(   (((u32) dest & 3) != 0)
                 || (((u32) src & 3) != 0)
                 || (((u32) n & 3) != 0)
       )        )
    {
        /* We need to use the slow version... */
        const u8 * source8 = (const u8 *) src;
        u8 * d8 = (u8 *) dest;

        for (i = 0; i < n; i++)
        {
            *d8++ = *source8++;
        }
    }
    else
    {
        /* Use unrolled 32-bit accesses */
        const u32 * source32 = (const u32 *) src;
        u32 * d32 = (u32 *) dest;

        n /= 4u;
        switch (n & 3)
        {
            case 3:
                *d32++ = *source32++;
            case 2:
                *d32++ = *source32++;
            case 1:
                *d32++ = *source32++;
            default:
                break;
        }
        n /= 4u;

        for (i = 0; i < n; i++)
        {
            *d32++ = *source32++;
            *d32++ = *source32++;
            *d32++ = *source32++;
            *d32++ = *source32++;
        }
    }

    return tmp;

}

void *memset(void *s, int c, u32 n)
{
    TS_MemSet(s,c,n);
    return 0;
}

void *memcmp
(
    void const * const a,
    void const * const b,
    const u32 len
)
{
    TS_MemCmp(a,b,len);
    return 0;
}

#endif

#ifndef PLATFORMS_STUBS_ENABLED
uint32 BoardGetRandom(void)
{
    uint32 ulBoardRandom;

    /* Get 32bit running counter */
    ulBoardRandom = BOARD_LPIT_CVAL0;

    /* Bit inverted */
    ulBoardRandom = ~(ulBoardRandom);

    /* Manipulate the Random value so it is not that easy to find !*/
    ulBoardRandom =
            (uint32) ((uint32) ulBoardRandom + (uint32) (ulBoardRandom << 16U)
                    + (uint32) (ulBoardRandom <<12U));

    return ulBoardRandom;
}
#endif

/*----------------------------------{BoardInitInterrupts}---------------------------------*/
void BoardInitInterrupts(void)
{
  /* set priorities of all interrupts
   * TODO : it looks like some PSR cannot be written which cause CPU exception while
   * doing global initializing. project must ensure to configure interruptions correctly
   * Some PSR are reserved, it is therefore not possible to initialize all Interrupt "easily"
   * Project shall ensure ISRs priorities are set correctly
   */
#ifdef BOARD_ISR_TEST

    /* Enable the tests interrupt */
    BOARD_INTC_EN(INTC_TEST);
#endif

#ifdef BOARD_ISR_CAN0
    BOARD_INTC_EN(INTC_FLEXCAN_ESR_BOFF);
    BOARD_INTC_EN(INTC_FLEXCAN_ESR_ERR);
    BOARD_INTC_EN(INTC_FLEXCAN_BUF_00_15);
    BOARD_INTC_EN(INTC_FLEXCAN_BUF_16_31);
#endif
}
/*----------------------------------{end of BoardInitInterrupts}---------------------------------*/


#ifndef PLATFORMS_STUBS_ENABLED
void BoardDisableInterrupts (void)
{
    if (m_ubBoardIntLockNestingCounter < 255U)
    {
        if (m_ubBoardIntLockNestingCounter == 0U)
        {
            boardDisableInterruptsAsm();
        }
        /* Manage nesting
         * !LINKSTO OsekCore.Platforms.Board.102, 1
         */
        m_ubBoardIntLockNestingCounter++;
    }
}
#endif

#ifndef PLATFORMS_STUBS_ENABLED
void BoardEnableInterrupts (void)
{
    if (m_ubBoardIntLockNestingCounter > 0U)
    {
        /* Manage nesting
         * !LINKSTO OsekCore.Platforms.Board.102, 1
         */
        m_ubBoardIntLockNestingCounter--;

        if (m_ubBoardIntLockNestingCounter == 0U)
        {
            boardEnableInterruptsAsm();
        }
    }
}
#endif

#ifndef PLATFORMS_STUBS_ENABLED
void BoardPerformSwReset(void)
{
    u32 ulPriGroup;
    
    ulPriGroup = (u32)(BOARD_AIRCR & BOARD_AIRCR_PRIGROUP_MASK);

    ASM_KEYWORD(" dsb");               /* All memory accesses have to be completed before reset */
    BOARD_AIRCR = (u32)((u32)(BOARD_AIRCR_VECTKEY & BOARD_AIRCR_VECTKEY_MASK) | ulPriGroup | BOARD_AIRCR_SYSRESETREQ_MASK);
    ASM_KEYWORD(" dsb");               /* All memory accesses have to be completed before reset */

    /* Infinite loop is intended since ECU shall reset,
     * in worst case, if WDG is on, it shall reset the ECU
     */
    /* Wait for Reset*/
    for (;;)
    {

    }
}
#endif

#ifndef PLATFORMS_STUBS_ENABLED
Platforms_ResetType BoardIsSwReset(void)
{    
    Platforms_ResetType BoardResetReturn;

    volatile uint32 BoardResetRegister = BOARD_RCM_SRS;

    if (BoardResetRegister == BOARD_RCM_SRS_POR)
    {
        BoardResetReturn = PLATFORMS_POWER_ON_RESET;
    } 
    else if (BoardResetRegister == BOARD_RCM_SRS_SW)
    {
        BoardResetReturn = PLATFORMS_SW_RESET;
    } 
    else if (BoardResetRegister == BOARD_RCM_SRS_WDOG)
    {
        BoardResetReturn = PLATFORMS_WATCHDOG_RESET;
    } 
    else 
    {
        BoardResetReturn = PLATFORMS_RESET_UNDEFINED;
    }

    return BoardResetReturn;
}
#endif

#ifndef PLATFORMS_STUBS_ENABLED
void BoardSetSleepState(void)
{

    /* request into sleep mode: wait for interrupt */
    BOARD_SRS = BOARD_SCR_SLEEPDEEP_MASK32;

    /* infinite loop to wait Sleep / Standby*/
    for(;;)
    {

    }
    
}
#endif

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
