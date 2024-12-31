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
#include "CDD_I2s.h"
#include "Mcu.h"
#include "Mcl.h"
#include "Port.h"
#include "Platform.h"
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
#define I2S_FLEXIO_SLAVE    (0U)
#define I2S_SAI_RECEIVER    (1U)
#define I2S_SAI_TRASMITTER  (2U)


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
uint8 SendData1[BUFF_SIZE*2];
uint8* SendData[1] = { SendData1 };
uint8 RecvBuff1[BUFF_SIZE*2];
uint8* RecvData[1] = { RecvBuff1 };

int main(void)
{
    volatile boolean bStatus = TRUE;
    Std_ReturnType Ret = 0U;
    volatile uint32 u32Timeout = 0U;
    I2s_RequestType * pRequest;
    I2s_StatusStructType transferStatus;
    I2s_RequestType I2s_MasterRequest;
    I2s_RequestType I2s_SlaveRequest;
    uint32 i;

    /* Create Master/Slave request */
    I2s_MasterRequest.bufferSize = BUFF_SIZE;
    I2s_MasterRequest.dataDirection = I2S_SEND_DATA;
    I2s_MasterRequest.wordMask = 0U;
    I2s_MasterRequest.pDataBuffer = (I2s_DataType (**))SendData;

    I2s_SlaveRequest.bufferSize = BUFF_SIZE;
    I2s_SlaveRequest.dataDirection = I2S_RECEIVE_DATA;
    I2s_SlaveRequest.wordMask = 0U;
    I2s_SlaveRequest.pDataBuffer = (I2s_DataType (**))RecvData;

    /* Init buffer data */
    for (i = 0; i < BUFF_SIZE; i++)
    {
        SendData1[i] = i + 1;
        RecvBuff1[i] = 0U;
    }

    /* Initialize Mcu Driver */
    Mcu_Init(&Mcu_Config_VS_0);
    Mcu_InitClock(McuClockSettingConfig_0);
    Mcu_DistributePllClock();
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize OsIf */
    OsIf_Init(NULL_PTR);

    /* Initialize Platform Driver */
    Platform_Init(NULL_PTR);
    Platform_SetIrq(SAI0_TX_SYNC_IRQn, TRUE);
    Platform_SetIrq(SAI0_RX_SYNC_IRQn, TRUE);
    Platform_SetIrq(FLEXIO_IRQn, TRUE);
    Platform_InstallIrqHandler(SAI0_TX_SYNC_IRQn, SAI0_IRQHandler, NULL_PTR);
    Platform_InstallIrqHandler(SAI0_RX_SYNC_IRQn, SAI0_IRQHandler, NULL_PTR);
    Platform_InstallIrqHandler(FLEXIO_IRQn, &MCL_FLEXIO_ISR, NULL_PTR);

    /* Initialize Port pin and Mcl */
    Port_Init(&Port_Config_VS_0);
    Mcl_Init(NULL_PTR);
    /* Init I2S over SAI as Master and FLEXIO_I2S as Slave */
    I2s_Init(&I2s_xConfig_VS_0);

    /* Part1: Sai Master sends data / Flexio_I2s Slave receives data */
    /* Start receiving data */
    pRequest = &I2s_SlaveRequest;
    Ret = I2s_AsyncTransmit(I2S_FLEXIO_SLAVE, pRequest);

    if (E_NOT_OK == Ret)
    {
        bStatus = FALSE;
    }
    else
    {
        /* Start sending data */
        pRequest = &I2s_MasterRequest;
        Ret = I2s_AsyncTransmit(I2S_SAI_TRASMITTER, pRequest);
    }

    if (E_NOT_OK == Ret)
    {
        bStatus = FALSE;
    }
    else
    {
        u32Timeout = TIME_OUT;
        /* Wait for Flexio_I2s receives all data */
        do
        {
            I2s_GetStatus(I2S_FLEXIO_SLAVE , &transferStatus);
            u32Timeout--;
            if (u32Timeout == 0U)
            {
                bStatus = FALSE;
                break;
            }
        } while (I2S_STATUS_BUSY == transferStatus.status);
        if ( (I2S_STATUS_COMPLETED != transferStatus.status) || (0U != transferStatus.byteRemainCount))
        {
            bStatus = FALSE;
        }
        I2s_GetStatus(I2S_SAI_TRASMITTER , &transferStatus);
        if ( (I2S_STATUS_COMPLETED != transferStatus.status) || (0U != transferStatus.byteRemainCount))
        {
            bStatus = FALSE;
        }

        /* Check the received data */
        for (i = 0U; i < BUFF_SIZE; i++)
        {
            if (RecvBuff1[i] != SendData1[i])
            {
                bStatus = FALSE;
                break;
            }
        }
    }

    /* Part2: Sai Master receives data / Flexio_I2s Slave sends data */
    /* Update Master/Slave request */
    I2s_MasterRequest.bufferSize = BUFF_SIZE;
    I2s_MasterRequest.dataDirection = I2S_RECEIVE_DATA;
    I2s_MasterRequest.wordMask = 0U;
    I2s_MasterRequest.pDataBuffer = (I2s_DataType (**))RecvData;

    I2s_SlaveRequest.bufferSize = BUFF_SIZE;
    I2s_SlaveRequest.dataDirection = I2S_SEND_DATA;
    I2s_SlaveRequest.wordMask = 0U;
    I2s_SlaveRequest.pDataBuffer = (I2s_DataType (**))SendData;

    /* Reset Recv buffer for next transfer */
    for (i = 0; i < BUFF_SIZE; i++)
    {
        RecvBuff1[i] = 0U;
    }

    /* Prepare to send data */
    pRequest = &I2s_SlaveRequest;
    Ret = I2s_AsyncTransmit(I2S_FLEXIO_SLAVE, pRequest);

    if (E_NOT_OK == Ret)
    {
        bStatus = FALSE;
    }
    else
    {
        /* Start receiving data */
        pRequest = &I2s_MasterRequest;
        Ret = I2s_AsyncTransmit(I2S_SAI_RECEIVER, pRequest);
    }

    if (E_NOT_OK == Ret)
    {
        bStatus = FALSE;
    }
    else
    {
        /* Wait for Sai receives all data */
        u32Timeout = TIME_OUT;
        do
        {
            I2s_GetStatus(I2S_SAI_RECEIVER, &transferStatus);
            u32Timeout--;
            if (u32Timeout == 0U)
            {
                break;
            }
        } while (I2S_STATUS_BUSY == transferStatus.status);
        if ( (I2S_STATUS_COMPLETED != transferStatus.status) || (0U != transferStatus.byteRemainCount))
        {
            bStatus = FALSE;
        }
        I2s_GetStatus(I2S_FLEXIO_SLAVE , &transferStatus);
        if ( (I2S_STATUS_COMPLETED != transferStatus.status) || (0U != transferStatus.byteRemainCount))
        {
            bStatus = FALSE;
        }

        /* Check the received data */
        for (i = 0U; i < BUFF_SIZE; i++)
        {
            if (RecvBuff1[i] != SendData1[i])
            {
                bStatus = FALSE;
                break;
            }
        }
    }

    I2s_DeInit();

    Exit_Example(bStatus);

    return 0;
}


#ifdef __cplusplus
}
#endif

/** @} */
