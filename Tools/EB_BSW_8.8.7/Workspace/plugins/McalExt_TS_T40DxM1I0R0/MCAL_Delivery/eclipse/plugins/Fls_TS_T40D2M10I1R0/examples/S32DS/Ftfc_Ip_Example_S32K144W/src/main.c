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
#include "sys_init.h"
#include "Ftfc_Fls_Ip.h"

#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Test the first sector of D_FLASH */
#define FTFC_SECTOR_ADDR             (FTFC_D_FLASH_BASE_ADDR + 0x000000UL)

/* Test data size = 128 bytes */
#define FTFC_BUF_SIZE                (FTFC_WRITE_DOUBLE_WORD * 16U)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
uint8 TxBuffer[FTFC_BUF_SIZE];
uint8 RxBuffer[FTFC_BUF_SIZE];

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Fls_ExampleAssert(boolean Condition);
static void Fls_InitBuffers(void);
static boolean Fls_VerifyBuffers(void);

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
    for (Index = 0U; Index < FTFC_BUF_SIZE; Index++)
    {
        TxBuffer[Index] = (uint8)Index;
        RxBuffer[Index] = 0U;
    }
}

static boolean Fls_VerifyBuffers(void)
{
    uint32 Index;

    for (Index = 0U; Index < FTFC_BUF_SIZE; Index++)
    {
        if (RxBuffer[Index] != TxBuffer[Index])
        {
            return FALSE;
        }
    }
    return TRUE;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Main function of the example
* @details      Initializes IP FTFC driver and erase, write, read internal flash memory
*/
int main(void)
{
    Ftfc_Fls_Ip_StatusType FtfcStatus;
    uint32 Index;

    /* Initialize clock */
    sys_init();

    /* Initialize FTFC driver */
    Ftfc_Fls_Ip_Init(&FtfcConfigSet_BOARD_InitPeripherals_InitCfg);

    /* Initialize buffers */
    Fls_InitBuffers();

    /* Erase sector */
    Ftfc_Fls_Ip_SectorErase(FTFC_SECTOR_ADDR);
    do
    {
        FtfcStatus = Ftfc_Fls_Ip_SectorEraseStatus();
    }
    while (STATUS_FTFC_FLS_IP_BUSY == FtfcStatus);
    Fls_ExampleAssert(STATUS_FTFC_FLS_IP_SUCCESS == FtfcStatus);

    /* Write data */
    for (Index = 0U; Index < FTFC_BUF_SIZE; Index += FTFC_WRITE_DOUBLE_WORD)
    {
        Ftfc_Fls_Ip_Write(FTFC_SECTOR_ADDR + Index, &TxBuffer[Index], FTFC_WRITE_DOUBLE_WORD);
        do
        {
            FtfcStatus = Ftfc_Fls_Ip_WriteStatus();
        }
        while (STATUS_FTFC_FLS_IP_BUSY == FtfcStatus);
        Fls_ExampleAssert(STATUS_FTFC_FLS_IP_SUCCESS == FtfcStatus);
    }

    /* Compare the written data */
    FtfcStatus = Ftfc_Fls_Ip_Compare(FTFC_SECTOR_ADDR, TxBuffer, FTFC_BUF_SIZE);
    Fls_ExampleAssert(STATUS_FTFC_FLS_IP_SUCCESS == FtfcStatus);

    /* Read data */
    FtfcStatus = Ftfc_Fls_Ip_Read(FTFC_SECTOR_ADDR, RxBuffer, FTFC_BUF_SIZE);
    Fls_ExampleAssert(STATUS_FTFC_FLS_IP_SUCCESS == FtfcStatus);

    /* Compare data between Tx and Rx buffer */
    Fls_ExampleAssert(TRUE == Fls_VerifyBuffers());

    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
