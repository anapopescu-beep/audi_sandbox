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
#include "SchM_Fls.h"
#include "Fls.h"

#include "check_example.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define LOGICAL_START_ADDR           0U
#define FLS_BUF_SIZE                 1000U

#define NUMBER_OF_INTERNAL_SECTOR    2U
#define INTERNAL_SECTOR_SIZE         0x800U

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/* Data buffers to test */
uint8 TxBuffer[FLS_BUF_SIZE];
uint8 RxBuffer[FLS_BUF_SIZE];

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Fls_ExampleAssert(boolean Condition);
static void Fls_InitBuffers(void);
static boolean Fls_VerifyBuffers(void);

static void Fls_Test_InternalSector(void);

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
    for (Index = 0U; Index < FLS_BUF_SIZE; Index++)
    {
        TxBuffer[Index] = (uint8)Index;
        RxBuffer[Index] = 0U;
    }
}

static boolean Fls_VerifyBuffers(void)
{
    uint32 Index;

    for (Index = 0U; Index < FLS_BUF_SIZE; Index++)
    {
        if (RxBuffer[Index] != TxBuffer[Index])
        {
            return FALSE;
        }
    }
    return TRUE;
}

static void Fls_Test_InternalSector(void)
{
    /* Initialize Tx and Rx Buffer */
    Fls_InitBuffers();

    /* Write to internal FLS */
    Fls_Write(LOGICAL_START_ADDR, TxBuffer, FLS_BUF_SIZE);
    /* Perform the job  */
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check job result */
    Fls_ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Read data from internal sector */
    Fls_Read(LOGICAL_START_ADDR, RxBuffer, FLS_BUF_SIZE);
    /* Perform the job  */
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check job result */
    Fls_ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Compare data in internal sector to TxBuffer buffer */
    Fls_Compare(LOGICAL_START_ADDR, TxBuffer, FLS_BUF_SIZE);
    /* Perform the job  */
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check job result */
    Fls_ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Compare data between Tx and Rx buffer */
    Fls_ExampleAssert(TRUE == Fls_VerifyBuffers());
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Main function of the example
* @details      Initializes the used drivers and uses the Fls driver to erase, write and read the memory
*/
int main(void)
{
    /* Initialize clock */
    sys_init();

    /* Initialize Fls driver */
    Fls_Init(NULL_PTR);
    /* Check Fls driver status */
    Fls_ExampleAssert(MEMIF_IDLE == Fls_GetStatus());

    /* Erase all configured sectors  */
    Fls_Erase(LOGICAL_START_ADDR, NUMBER_OF_INTERNAL_SECTOR * INTERNAL_SECTOR_SIZE);
    /* Perform the job  */
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check job result */
    Fls_ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Run test with Internal Sector */
    Fls_Test_InternalSector();

    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
