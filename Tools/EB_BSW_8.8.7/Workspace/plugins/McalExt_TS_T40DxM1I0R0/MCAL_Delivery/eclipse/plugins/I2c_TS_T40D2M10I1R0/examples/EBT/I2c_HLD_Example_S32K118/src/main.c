/*
*   (c) Copyright 2021 NXP
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
#include "Mcu.h"
#include "Mcal.h"
#include "Platform.h"
#include "Port.h"
#include "CDD_I2c.h"
#include "CDD_Mcl.h"
#include "check_example.h"
#include "Flexio_I2c_Ip_CfgDefines.h"
#include "Platform_Cfg.h"
#include "Lpi2c_Ip_CfgDefines.h"
#include "Port_Ci_Port_Ip_Defines.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define TRANSFER_SIZE 8U

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
#define I2C_START_SEC_VAR_INIT_UNSPECIFIED
#include "I2c_MemMap.h"
I2c_DataType rxBufferSlave[TRANSFER_SIZE] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
I2c_DataType txBuffer[TRANSFER_SIZE] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7};
#define I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "I2c_MemMap.h"
I2c_RequestType pRequestSend = 
{
    /* Slave address */
    0x32,

    /*10 bit address*/
    FALSE,

    /*high speed */
    FALSE,

    /* expect Nack */
    FALSE,

    /*repeated start */
    FALSE,

    /*buffer size */
    8U,

    /*Data direction */
    I2C_SEND_DATA,

    /*Buffer*/
    txBuffer
};


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Interrupt handlers
*/
#if (I2C_FLEXIO_USED == STD_ON)
extern void MCL_FLEXIO_ISR(void);
#endif

extern void LPI2C0_Master_Slave_IRQHandler(void);

void Init_Pins(void)
{
    /* Configure both pins with MUX = 4, PE = 1, PS = 1*/
    /* Configure PTA0 as FLEXIO PD2 - SCL (ALT 4) - pullup resistor is enabled */
    IP_PORTA->PCR[0] = 0x400;
    /* Configure PTA1 as FLEXIO PD3 - SDA (ALT 4) - pullup resistor is enabled */
    IP_PORTA->PCR[1] = 0x400;

    /* Configure PTA0 and PTA1 as output pins */
    IP_PTA->PDDR |= 0x00000003;

    /* Configure both pins with MUX = 3, PE = 1, PS = 1*/
    /* Configure PTA2 as LPI2C0_SDA (ALT 3) - pullup resistor is enabled */
    IP_PORTA->PCR[2] = 0x303;
    /* Configure PTA3 as LPI2C0_SCL (ALT 3) - pullup resistor is enabled */
    IP_PORTA->PCR[3] = 0x303;

    /* Configure PTA2 and PTA3 as output pins */
    IP_PTA->PDDR |= 0x0000000C;

}

/**
* @brief        Slave callback for i2c
* @details      Prepare slave's buffer for transfer
*/
void I2c_Callback(uint8 u8Event, uint8 u8Channel)
{
    switch(u8Event)
    {
        case I2C_EVENT_RX_REQ_SLAVE:
            I2c_PrepareSlaveBuffer(u8Channel, TRANSFER_SIZE, rxBufferSlave);
            break;

        case I2C_EVENT_TX_REQ_SLAVE:
            I2c_PrepareSlaveBuffer(u8Channel, TRANSFER_SIZE, txBuffer);
            break;

        default:
            (void) u8Channel;
    }
}

/**
* @brief        Main function of the example
* @details      Initializez the LPI2C driver to asynchronous data.
*/
int main(void) 
{
    uint32 timeout = 0xFFFF;
    boolean checkOk = TRUE;
    uint8 i;
    I2c_StatusType status;

    /* Init system clock */
    Mcu_Init(&Mcu_Config_VS_0);

    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);

    Mcu_SetMode(McuModeSettingConf_0);

    /* Init Pins */
    Init_Pins();
    /* Install interrupt handlers */
    Platform_Init(NULL);
    Platform_InstallIrqHandler(LPI2C0_Master_Slave_IRQn, &LPI2C0_Master_Slave_IRQHandler, NULL_PTR);
    Platform_InstallIrqHandler(FLEXIO_IRQn, &MCL_FLEXIO_ISR, NULL_PTR);
    /* Init Mcl for FlexIO chanel */
    Mcl_Init(&Mcl_Config_VS_0);
    /* Init master and slave */
    I2c_Init(&I2c_Config_VS_0);
    /* Slave listening */
    I2c_StartListening(1U);
    /* Master send data */
    I2c_AsyncTransmit(0U, &pRequestSend);

    /* Wait until master is ready */
    while(((status = I2c_GetStatus(0U)) == I2C_CH_SEND) && (timeout > 0))
    {
        timeout--;
    }

    /* Wait until slave is ready */
    while(((status = I2c_GetStatus(1U)) == I2C_CH_RECEIVE) && (timeout > 0))
    {
        timeout--;
    }

    /* Verify data received */
    for (i = 0; i < TRANSFER_SIZE; i ++)
    {
        if( txBuffer[i] != rxBufferSlave[i])
        {
            checkOk = FALSE;
        }
    }

    Exit_Example(checkOk);

    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
