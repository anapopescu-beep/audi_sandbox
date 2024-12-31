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
#include "Port.h"
#include "Mcu.h"
#include "Eth.h"
#include "Platform.h"
#include "OsIf.h"
#include "CDD_Rm.h"

#include "check_example.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

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
* @brief        Transmit & receive in internal loopback mode
* @details      
*/
int main(void) 
{
    Eth_BufIdxType bufferIndex;
    uint8 *payloadBuffer;
    uint16 payloadLength;
    uint8 gmac_0_macAddr[6U] = {0};
    Eth_RxStatusType Status;
    boolean bPass = TRUE;
    
    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);
    
    Mcu_SetMode(McuModeSettingConf_0);
    
    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);
    
    Mcu_DistributePllClock();
    
    Rm_Init(NULL_PTR);
    
    /* Initialize all pins using the Port driver */
    Port_Init(NULL_PTR);

    OsIf_Init(NULL_PTR);

    Eth_Init(NULL_PTR);
    
    Eth_SetControllerMode(EthConf_EthCtrlConfig_EthCtrlConfig_0, ETH_MODE_ACTIVE);
    
    Eth_ProvideTxBuffer(EthConf_EthCtrlConfig_EthCtrlConfig_0, 0U, &bufferIndex, &payloadBuffer, &payloadLength);
    
    Eth_GetPhysAddr(EthConf_EthCtrlConfig_EthCtrlConfig_0, gmac_0_macAddr);
    
    Eth_Transmit(EthConf_EthCtrlConfig_EthCtrlConfig_0, bufferIndex, (Eth_FrameType)46U, TRUE, 46U, gmac_0_macAddr);
    
    Eth_TxConfirmation(EthConf_EthCtrlConfig_EthCtrlConfig_0);
    
    Eth_Receive(EthConf_EthCtrlConfig_EthCtrlConfig_0, 0U, &Status);
    
    if (ETH_RECEIVED != Status) 
    {
        bPass = FALSE;
    }
    
    Eth_SetControllerMode(EthConf_EthCtrlConfig_EthCtrlConfig_0, ETH_MODE_DOWN);
    
    Exit_Example(bPass);
    
    return 0;
}


#ifdef __cplusplus
}
#endif

/** @} */
