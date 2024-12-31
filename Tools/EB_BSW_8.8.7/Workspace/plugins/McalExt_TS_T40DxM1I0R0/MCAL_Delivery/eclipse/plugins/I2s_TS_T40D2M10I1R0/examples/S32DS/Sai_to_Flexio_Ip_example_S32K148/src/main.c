/*
*   (c) Copyright 2022 NXP
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
#include "Clock_Ip.h"
#include "IntCtrl_Ip.h"
#include "Port_Ci_Port_Ip.h"
#include "Sai_Ip.h"
#include "Flexio_I2s_Ip.h"
#include "Flexio_Mcl_Ip.h"
#include "check_example.h"

/*==================================================================================================
*                                      EXTERN DECLARATIONS
==================================================================================================*/
extern ISR(SAI0_IRQHandler);
extern void MCL_FLEXIO_ISR(void);

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define TIME_OUT            (100000U)
#define BUFF_SIZE           (100U)
#define FLEXIO_INSTANCE     (0U)
#define FLEXIO_CHANNEL      (0U)
#define SAI_INSTANCE        (0U)

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
uint8 RecvData[BUFF_SIZE];
uint8 SendData[BUFF_SIZE];
uint8* SendBuff[1] = {SendData};


int main(void)
{
    uint32 i;
    uint32 bytesRemaining = 0U;
    volatile boolean bStatus = TRUE;
    Clock_Ip_StatusType clockStatus = CLOCK_IP_SUCCESS;

    /* Initialize the clock tree */
    clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
    while (clockStatus != CLOCK_IP_SUCCESS)
    {
        clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
    }

    /* Enable the SAI0 and FLEXIO interrupt vector */
    IntCtrl_Ip_EnableIrq(SAI0_TX_SYNC_IRQn);
    IntCtrl_Ip_EnableIrq(FLEXIO_IRQn);
    IntCtrl_Ip_InstallHandler(SAI0_TX_SYNC_IRQn, SAI0_IRQHandler, NULL_PTR);
    IntCtrl_Ip_InstallHandler(FLEXIO_IRQn, MCL_FLEXIO_ISR, NULL_PTR);

    /* Init buffer data */
    for (i = 0; i < BUFF_SIZE; i++)
    {
        SendData[i] = i + 1;
        RecvData[i] = 0U;
    }

    /* Initialize port */
    (void)Port_Ci_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize SAI module as master */
    Sai_Ip_TxInit(SAI_INSTANCE, &Sai_Ip_xInitConfig_0_VS_0);
    /* Initialize Flexio_I2s module as slave */
    Flexio_Mcl_Ip_InitDevice(&Flexio_Ip_xFlexioInit);
    Flexio_I2s_Ip_SlaveInit(FLEXIO_INSTANCE, FLEXIO_CHANNEL, &Flexio_I2s_Ip_xSlaveInitConfig_0_VS_0);

    /* Call receive data first because Flexio_i2s is slave */
    (void)Flexio_I2s_Ip_SlaveReceiveData(FLEXIO_INSTANCE, FLEXIO_CHANNEL, RecvData, BUFF_SIZE);

    /* Start sending data */
    Sai_Ip_Send(SAI_INSTANCE, (const uint8**)SendBuff, BUFF_SIZE);

    /* Wait for transfer complete */
    while (Sai_Ip_GetSendingStatus(SAI_INSTANCE, &bytesRemaining) != SAI_IP_STATUS_COMPLETED)
    {
    }
    if (bytesRemaining != 0U)
    {
        bStatus = FALSE;
    }

    while (Flexio_I2s_Ip_SlaveGetStatus(FLEXIO_INSTANCE, FLEXIO_CHANNEL, &bytesRemaining) != FLEXIO_I2S_IP_STATUS_SUCCESS)
    {
    }
    if (bytesRemaining != 0U)
    {
        bStatus = FALSE;
    }

    /* Check the received data */
    for (i = 0U; i < BUFF_SIZE; i++)
    {
        if (RecvData[i] != SendData[i])
        {
            bStatus = FALSE;
            break;
        }
    }

    /* De-initialize SAI module */
    Sai_Ip_TxDeInit(FLEXIO_INSTANCE);
    /* De-initial Flexio_I2s*/
    Flexio_I2s_Ip_SlaveDeinit(FLEXIO_INSTANCE, FLEXIO_CHANNEL);

    Exit_Example(bStatus);

    return 0;
}


#ifdef __cplusplus
}
#endif

/** @} */
