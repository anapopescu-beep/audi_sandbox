/*
*   (c) Copyright 2020 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "S32K148_SIM.h"
#include "S32K148_PORT.h"
#include "sys_init.h"
#include "Qspi_Ip.h"
#include "Qspi_Ip_Cfg.h"

#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define QSPI_BUF_SIZE                 128U
#define QSPI_JOB_ADDRESS              4096U
#define QSPI_SECTOR_SIZE              4096U
#define QSPI_TIME_OUT                 32768U

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/* Data buffers to test */
uint8 TxBuffer[QSPI_BUF_SIZE];
uint8 RxBuffer_IP[QSPI_BUF_SIZE];    /* Storage Rx buffers by IP command */
uint8 RxBuffer_AHB[QSPI_BUF_SIZE];   /* Storage Rx buffers by ABH command */

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Fls_ExampleAssert(boolean Condition);
static void Fls_InitBuffers(void);
static boolean Fls_VerifyBuffers(void);

static void Fls_ClockSetup(void);
static void Fls_PinSetup(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/**
 * @brief Implement a simple assert macro
 *
 * @param Condition
 * @return void
 */
static void Fls_ExampleAssert(boolean Condition)
{
    if (!Condition)
    {
        for(;;)
        {
            /* Loop forever */
        }
    }
}

static void Fls_InitBuffers(void)
{
    uint32 Index;

    /* Initialize data to default value */
    for (Index = 0U; Index < QSPI_BUF_SIZE; Index++)
    {
        TxBuffer[Index] = (uint8)Index;
        RxBuffer_IP[Index] = 0U;
    }
}

static boolean Fls_VerifyBuffers(void)
{
    uint32 Index;

    for (Index = 0U; Index < QSPI_BUF_SIZE; Index++)
    {
        if ( (RxBuffer_IP[Index] != TxBuffer[Index]) || (RxBuffer_AHB[Index] != TxBuffer[Index]) )
        {
            return FALSE;
        }
    }
    return TRUE;
}

static void Fls_ClockSetup(void)
{
    /* Initialize clock */
    sys_init();

    /* Enable clock Gate for QSPI */
    IP_SIM->MISCTRL0 |= SIM_MISCTRL0_QSPI_CLK_SEL_MASK;
}

/**
 * @brief Initiate Pin for QSPI Flash A
 *
 */
static void Fls_PinSetup(void)
{
    /* Configure pins for: Clear PORT_PCR_MUX_SHIFT bits */
    IP_PORTC->PCR[3]  &= ~(PORT_PCR_MUX_MASK);      /* PTC3   QSPI_A_CS  */
    IP_PORTD->PCR[11] &= ~(PORT_PCR_MUX_MASK);      /* PTD11  QSPI_A_IO0 */
    IP_PORTD->PCR[7]  &= ~(PORT_PCR_MUX_MASK);      /* PTD7   QSPI_A_IO1 */
    IP_PORTD->PCR[12] &= ~(PORT_PCR_MUX_MASK);      /* PTD12  QSPI_A_IO2 */
    IP_PORTC->PCR[2]  &= ~(PORT_PCR_MUX_MASK);      /* PTC2   QSPI_A_IO3 */
    IP_PORTD->PCR[10] &= ~(PORT_PCR_MUX_MASK);      /* PTD10  QSPI_A_SCK */

    /* Configure pins for: QSPI pin mux, driver strength enable, pull up enabled. */
    IP_PORTC->PCR[3]  |= (0x06 << PORT_PCR_MUX_SHIFT) | PORT_PCR_DSE_MASK | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;      /* PTC3   QSPI_A_CS  */
    IP_PORTD->PCR[11] |= (0x07 << PORT_PCR_MUX_SHIFT) | PORT_PCR_DSE_MASK | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;      /* PTD11  QSPI_A_IO0 */
    IP_PORTD->PCR[7]  |= (0x07 << PORT_PCR_MUX_SHIFT) | PORT_PCR_DSE_MASK | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;      /* PTD7   QSPI_A_IO1 */
    IP_PORTD->PCR[12] |= (0x07 << PORT_PCR_MUX_SHIFT) | PORT_PCR_DSE_MASK | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;      /* PTD12  QSPI_A_IO2 */
    IP_PORTC->PCR[2]  |= (0x07 << PORT_PCR_MUX_SHIFT) | PORT_PCR_DSE_MASK | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;      /* PTC2   QSPI_A_IO3 */
    IP_PORTD->PCR[10] |= (0x07 << PORT_PCR_MUX_SHIFT) | PORT_PCR_DSE_MASK | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;      /* PTD10  QSPI_A_SCK */
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Main function of the example
* @details      Initialize Fls IP QSPI driver and
*               erase, write, read internal fls memory
*/
int main(void)
{
    uint32 TimeOut = QSPI_TIME_OUT;
    uint32 QspiInstance = QspiConfigSet_BOARD_InitPeripherals_paFlashConnectionCfg[0].qspiInstance;
    Qspi_Ip_StatusType QspiStatus;

    /* Initialize Qspi's clock */
    Fls_ClockSetup();

    /* Initialize Qspi's pins */
    Fls_PinSetup();

    /* Initialize Tx and Rx Buffer */
    Fls_InitBuffers();

    /* Initialize QSPI */
    QspiStatus = Qspi_Ip_ControllerInit(QspiInstance, &QspiConfigSet_BOARD_InitPeripherals_paQspiUnitCfg[0]);
    Fls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    QspiStatus = Qspi_Ip_Init(QspiInstance, &QspiConfigSet_BOARD_InitPeripherals_paFlashCfg[0], &QspiConfigSet_BOARD_InitPeripherals_paFlashConnectionCfg[0]);
    Fls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Erase an external sector which has address is 4096 */
    QspiStatus = Qspi_Ip_EraseBlock(QspiInstance, QSPI_JOB_ADDRESS, QSPI_SECTOR_SIZE);
    Fls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Check QspiStatus of external memory */
    while ((STATUS_QSPI_IP_BUSY == (QspiStatus = Qspi_Ip_GetMemoryStatus(QspiInstance))) && (TimeOut > 0))
    {
        TimeOut--;
    }
    Fls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Verify erase */
    QspiStatus = Qspi_Ip_EraseVerify(QspiInstance, QSPI_JOB_ADDRESS, QSPI_SECTOR_SIZE);
    Fls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Reset Timeout*/
    TimeOut = QSPI_TIME_OUT;

    /* Write to external flash*/
    QspiStatus = Qspi_Ip_Program(QspiInstance, QSPI_JOB_ADDRESS, TxBuffer, QSPI_BUF_SIZE);
    Fls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Check QspiStatus of external memory */
    while ((STATUS_QSPI_IP_BUSY == (QspiStatus = Qspi_Ip_GetMemoryStatus(QspiInstance))) && (TimeOut > 0))
    {
        TimeOut--;
    }
    Fls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);


    /* Read data from external flash */

    /* Enable AHB read */
    QspiStatus = Qspi_Ip_AhbReadEnable(QspiInstance);
    Fls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Enable enhance mode (optional) */
    QspiStatus = Qspi_Ip_Enter0XX(QspiInstance);
    Fls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Using IP command read into RxBuffer_IP buffer */
    QspiStatus = Qspi_Ip_Read(QspiInstance, QSPI_JOB_ADDRESS, RxBuffer_IP, QSPI_BUF_SIZE);
    Fls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Using AHB command read into RxBuffer_AHB buffer */

    /* Table of AHB addresses for QuadSPI instances. */
    const uint32 Qspi_Ip_AhbAddress[QuadSPI_INSTANCE_COUNT] = QuadSPI_AHB_PTRS;
    /* Get AHB address of QspiInstance */
    uint8* pAHBExAddr = (uint8*)(Qspi_Ip_AhbAddress[QspiInstance] + QSPI_JOB_ADDRESS);

    for (uint32 Index = 0U; Index < QSPI_BUF_SIZE; Index++)
    {
        RxBuffer_AHB[Index] = pAHBExAddr[Index];
    }

    /* Reset Timeout*/
    TimeOut = QSPI_TIME_OUT;
    /* Wait until AHB accesses finish to avoid conflict between AHB commands with subsequent IP commands */
    while ((STATUS_QSPI_IP_BUSY == (QspiStatus = Qspi_Ip_ControllerGetStatus(QspiInstance))) && (TimeOut > 0))
    {
        TimeOut--;
    }
    Fls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Disable enhance mode (optional) */
    QspiStatus = Qspi_Ip_Exit0XX(QspiInstance);
    Fls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Compare data between Tx and two Rx buffers (RxBuffer_IP and RxBuffer_AHB) */
    Fls_ExampleAssert(TRUE == Fls_VerifyBuffers());

    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
