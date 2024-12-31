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
#include "S32K148_LMEM.h"
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
#define PHYSICAL_START_ADDR          0x1000U
#define FLS_BUF_SIZE                 1000U

/*
   FlsSectorType | FlsSectorList     | Fls Sector Size | Fls Number  | Fls Logical    |   Fls Physical     |
                 |                   |                 | Of Sector   | Start Address  |   Start Address    |
   ------------- | ----------------- | --------------: | ----------: | -------------: | -----------------: |
   Internal      | FlsSector_0       | 4096 (0x1000)   |     1       |     0 (0x0000) | 1560576 (0x17D000) |
   Internal      | FlsSector_1       | 4096 (0x1000)   |     1       |  4096 (0x1000) | 1564672 (0x17E000) |
   Internal      | FlsSector_2       | 4096 (0x1000)   |     1       |  8192 (0x2000) | 1568768 (0x17F000) |
   External      | FlsSector_3       | 4096 (0x1000)   |     1       | 12288 (0x2000) |    4096 (0x1000)   |
   External      | FlsSector_4       | 4096 (0x1000)   |     1       | 16384 (0x4000) |    8192 (0x2000)   |
   External      | FlsSector_5       | 4096 (0x1000)   |     1       | 20480 (0x5000) |   12288 (0x3000)   |
*/
#define NUMBER_OF_INTERNAL_SECTOR    3U
#define INTERNAL_SECTOR_SIZE         0x1000U
#define NUMBER_OF_EXTERNAL_SECTOR    3U
#define EXTERNAL_SECTOR_SIZE         0x1000U

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
uint8 RxBuffer_IP[FLS_BUF_SIZE];    /* Storage Rx buffers by IP command */
uint8 RxBuffer_AHB[FLS_BUF_SIZE];   /* Storage Rx buffers by ABH command */

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Fls_ExampleAssert(boolean Condition);
static void Fls_InitBuffers(void);
static boolean Fls_VerifyInternalData(void);
static boolean Fls_VerifyExternalData(void);

static void Fls_ClockSetup(void);
static void Fls_PinSetup(void);
static void Fls_CacheSetup(void);

static void Fls_Test_InternalSector(void);
static void Fls_Test_ExternalSector(void);

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
        RxBuffer_IP[Index] = 0U;
    }
}

static boolean Fls_VerifyInternalData(void)
{
    uint32 Index;

    for (Index = 0U; Index < FLS_BUF_SIZE; Index++)
    {
        if (RxBuffer_IP[Index] != TxBuffer[Index])
        {
            return FALSE;
        }
    }
    return TRUE;
}

static boolean Fls_VerifyExternalData(void)
{
    uint32 Index;

    for (Index = 0U; Index < FLS_BUF_SIZE; Index++)
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

static void Fls_CacheSetup(void)
{
    /* Disable cache on R2 bank: as S32K148 FlexNVMs region is not cacheable */
    IP_LMEM->PCCRMR &= ~LMEM_PCCRMR_R2_MASK;
}

static void Fls_Test_InternalSector(void)
{
    Fls_AddressType u32TargetAddress = LOGICAL_START_ADDR;

    /* Initialize Tx and Rx Buffer */
    Fls_InitBuffers();

    /* Write to internal FLS */
    Fls_Write(u32TargetAddress, TxBuffer, FLS_BUF_SIZE);
    /* Perform the job */
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check job result */
    Fls_ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Read data from internal sector */
    Fls_Read(u32TargetAddress, RxBuffer_IP, FLS_BUF_SIZE);
    /* Perform the job */
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check job result */
    Fls_ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Compare data in internal sector to TxBuffer buffer */
    Fls_Compare(u32TargetAddress, TxBuffer, FLS_BUF_SIZE);
    /* Perform the job */
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check job result */
    Fls_ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Compare data between Tx and Rx buffer */
    Fls_ExampleAssert(TRUE == Fls_VerifyInternalData());
}

static void Fls_Test_ExternalSector(void)
{
    Fls_AddressType u32TargetAddress = LOGICAL_START_ADDR + NUMBER_OF_INTERNAL_SECTOR * INTERNAL_SECTOR_SIZE;

    /* Initialize Tx and Rx Buffer */
    Fls_InitBuffers();

    /* Write data to external sector */
    Fls_Write(u32TargetAddress, TxBuffer, FLS_BUF_SIZE);
    /* Perform the job */
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check job result */
    Fls_ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Read data from external sector */
    Fls_Read(u32TargetAddress, RxBuffer_IP, FLS_BUF_SIZE);
    /* Perform the job */
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check job result */
    Fls_ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Compare data in external sector to TxBuffer buffer*/
    Fls_Compare(u32TargetAddress, TxBuffer, FLS_BUF_SIZE);
    /* Perform the job */
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check job result */
    Fls_ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Read data from external sector via AHB command */

    /* Table of AHB addresses for QuadSPI instances */
    const uint32 Qspi_Ip_AhbAddress[QuadSPI_INSTANCE_COUNT] = QuadSPI_AHB_PTRS;
    /* Get AHB address of QSPI_0 */
    uint8* pAHBExAddr = (uint8*)(Qspi_Ip_AhbAddress[0U] + PHYSICAL_START_ADDR);

    for (uint32 Index = 0U; Index < FLS_BUF_SIZE; Index++)
    {
        RxBuffer_AHB[Index] = pAHBExAddr[Index];
    }

    /* Compare data between Tx and Rx buffer */
    Fls_ExampleAssert(TRUE == Fls_VerifyExternalData());
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
    /* Initialize Qspi's clock */
    Fls_ClockSetup();

    /* Initialize Qspi's pins */
    Fls_PinSetup();

    /* Initialize cache */
    Fls_CacheSetup();

    /* Initialize Fls driver */
    Fls_Init(NULL_PTR);
    /* Check Fls driver status */
    Fls_ExampleAssert(MEMIF_IDLE == Fls_GetStatus());

    /* Erase all configured sectors */
    Fls_Erase(LOGICAL_START_ADDR, NUMBER_OF_INTERNAL_SECTOR * INTERNAL_SECTOR_SIZE + NUMBER_OF_EXTERNAL_SECTOR * EXTERNAL_SECTOR_SIZE);
    /* Perform the job */
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check job result */
    Fls_ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Run test with Internal Sector */
    Fls_Test_InternalSector();

    /* Run test with External Sector */
    Fls_Test_ExternalSector();

    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
