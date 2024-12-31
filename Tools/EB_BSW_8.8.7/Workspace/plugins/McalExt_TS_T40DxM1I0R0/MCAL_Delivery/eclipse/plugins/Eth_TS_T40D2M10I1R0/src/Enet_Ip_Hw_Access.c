/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ENET
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
*
*   (c) Copyright 2020-2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup ENET_DRIVER ENET Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Enet_Ip_Hw_Access.h"
#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ENET_IP_HW_ACCESS_VENDOR_ID_C                      43
#define ENET_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define ENET_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C       4
#define ENET_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define ENET_IP_HW_ACCESS_SW_MAJOR_VERSION_C               1
#define ENET_IP_HW_ACCESS_SW_MINOR_VERSION_C               0
#define ENET_IP_HW_ACCESS_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Enet_Ip_Hw_Access.h */
#if (ENET_IP_HW_ACCESS_VENDOR_ID_C != ENET_IP_HW_ACCESS_VENDOR_ID)
    #error "Enet_Ip_Hw_Access.c and Enet_Ip_Hw_Access.h have different vendor ids"
#endif
#if ((ENET_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != ENET_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (ENET_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C    != ENET_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (ENET_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C != ENET_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip_Hw_Access.c and Enet_Ip_Hw_Access.h are different"
#endif
#if ((ENET_IP_HW_ACCESS_SW_MAJOR_VERSION_C != ENET_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (ENET_IP_HW_ACCESS_SW_MINOR_VERSION_C != ENET_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (ENET_IP_HW_ACCESS_SW_PATCH_VERSION_C != ENET_IP_HW_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Enet_Ip_Hw_Access.c and Enet_Ip_Hw_Access.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against OsIf.h */
    #if (( ENET_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        ( ENET_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C     != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Enet_Ip_Hw_Access.c and OsIf.h are different"
    #endif
#endif
/*******************************************************************************
 * Definitions
 ******************************************************************************/
 
/*! @brief Masks for the bits in the CRC-32 value */
#define ENET_CRC32_BIT_1_MASK       0x80000000UL
#define ENET_CRC32_BITS_2_6_MASK    0x7C000000UL
#define ENET_CRC32_BITS_2_6_SHIFT   26UL

/*******************************************************************************
 * Variables
 ******************************************************************************/
#define ETH_START_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"

ENET_Type * const Enet_apxBases[FEATURE_ENET_NUM_INSTANCES] = IP_ENET_BASE_PTRS;

#define ETH_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"

#define ETH_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_MemMap.h"
/**
* @brief          Used for internal storage of local time
* @details        This variable is used to store the value for current time including 48 bits for second 
*                 and 32 bits for nanosecond part. 
*
* @note           This variable exists only if the time stamp is used.
*
*/
Enet_Ip_TimeStampType Enet_axLocalTime[FEATURE_ENET_NUM_INSTANCES] = {{0U,0U,0U}};

#define ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_MemMap.h"

/*******************************************************************************
 * Private Functions
 ******************************************************************************/
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_StartTimeout
 * Description   : Checks for timeout condition
 *
 *END**************************************************************************/
void ENET_StartTimeout(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs)
{
    *StartTimeOut    = OsIf_GetCounter(ENET_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, ENET_TIMEOUT_TYPE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_TimeoutExpired
 * Description   : Checks for timeout expiration condition
 *
 *END**************************************************************************/
boolean ENET_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks)
{
    *ElapsedTimeInOut += OsIf_GetElapsed(StartTimeInOut, ENET_TIMEOUT_TYPE);

    return ((*ElapsedTimeInOut >= TimeoutTicks)? TRUE : FALSE);
}
/*******************************************************************************
 * Code
 ******************************************************************************/
 
/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_SetSpeed
 * Description   : Sets the speed of the MII interface
 *
 *END**************************************************************************/
void ENET_SetSpeed(ENET_Type * Base,
                   Enet_Ip_MiiSpeedType Speed)
{
    if (Speed == ENET_MII_SPEED_10M)
    {
        Base->RCR |= ENET_RCR_RMII_10T_MASK;
    }
    else
    {
        Base->RCR &= ~ENET_RCR_RMII_10T_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_AddToHashTable
 * Description   : Adds an entry to the hash table filter
 *
 *END**************************************************************************/
void ENET_AddToHashTable(ENET_Type * Base,
                        uint32 Crc)
{
    if ((Crc & ENET_CRC32_BIT_1_MASK) != 0U)
    {
        Base->GAUR |= (1UL << ((Crc & ENET_CRC32_BITS_2_6_MASK) >> ENET_CRC32_BITS_2_6_SHIFT));
    }
    else
    {
        Base->GALR |= (1UL << ((Crc & ENET_CRC32_BITS_2_6_MASK) >> ENET_CRC32_BITS_2_6_SHIFT));
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_RemoveFromHashTable
 * Description   : Removes an entry from the hash table filter.
 *
 *END**************************************************************************/
void ENET_RemoveFromHashTable(ENET_Type * Base,
                              uint32 Crc)
{
    if ((Crc & ENET_CRC32_BIT_1_MASK) != 0U)
    {
        Base->GAUR &= ~(1UL << ((Crc & ENET_CRC32_BITS_2_6_MASK) >> ENET_CRC32_BITS_2_6_SHIFT));
    }
    else
    {
        Base->GALR &= ~(1UL << ((Crc & ENET_CRC32_BITS_2_6_MASK) >> ENET_CRC32_BITS_2_6_SHIFT));
    }
}

/*!
 * @brief Indicates that the driver produced empty transmit buffers with the ready bit set.
 *
 * @param[in] base The base address of the module
 * @param[in] ring The ring number
 */
void ENET_ActivateTransmit(ENET_Type *Base, 
                           uint8 Ring)
{
    if (0U == Ring)
    {
        Base->TDAR = ENET_TDAR_TDAR_MASK;
    }
}

/*!
 * @brief Indicates that the driver produced empty receive buffers with the ready bit set.
 *
 * @param[in] base The base address of the module
 * @param[in] ring The ring number
 */
void ENET_ActivateReceive(ENET_Type *Base, 
                          uint8 Ring)
{
    if (0U == Ring)
    {
        Base->RDAR = ENET_RDAR_RDAR_MASK;
    }
}

#if FEATURE_ENET_HAS_SLEEP_WAKEUP
/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_WakeupIRQHandler
 * Description   : Handler for ENET wakeup interrupts.
 * This handler invokes the installed callback, if available, and clears
 * the interrupt flags. Also, the ENET module is set to normal operation mode.
 *
 *END**************************************************************************/
void ENET_WakeupIRQHandler(uint8 Instance)
{
    ENET_Type *Base = Enet_apxBases[Instance];
    uint32 StatusFlags = Base->EIR;
    uint32 IrqEnFlags = Base->EIMR;
    
    /* Clear the interrupt event*/
    Base->EIR = ENET_EIR_WAKEUP_MASK;
    
    /* Check if driver is initialized*/
    if (Enet_apxState[Instance] != NULL_PTR)
    {
        /*Check if interrupt is spurious*/
        if (((IrqEnFlags & (uint32)ENET_EIMR_WAKEUP_MASK) != 0U) &&
            ((StatusFlags & (uint32)ENET_EIR_WAKEUP_MASK) != 0U))
        {
            /* Set to normal mode */
            Base->ECR &= ~((uint32)ENET_ECR_SLEEP_MASK | (uint32)ENET_ECR_MAGICEN_MASK);
            
            /* Callback function*/
            if (Enet_apxState[Instance]->Callback != NULL_PTR)
            {
                Enet_apxState[Instance]->Callback(Instance, ENET_WAKE_UP_EVENT);
            }
        }
    }
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_ErrorIRQHandler
 * Description   : Handler for ENET error interrupts.
 * This handler invokes the installed Callback, if available, and clears the
 * interrupt flags.
 *
 *END**************************************************************************/
void ENET_ErrIRQHandler(uint8 Instance)
{
    ENET_Type *Base = Enet_apxBases[Instance];
    uint32 IrqEnFlags = (uint32)ENET_EIMR_PLR_MASK | (uint32)ENET_EIR_BABT_MASK | (uint32)ENET_EIR_BABR_MASK |
                        (uint32)ENET_EIMR_UN_MASK | (uint32)ENET_EIMR_RL_MASK | (uint32)ENET_EIMR_LC_MASK |
                        (uint32)ENET_EIMR_EBERR_MASK;
    uint32 StatusFlags = (uint32)ENET_BABR_INTERRUPT | (uint32)ENET_BABT_INTERRUPT |(uint32)ENET_EBERR_INTERRUPT |
                        (uint32)ENET_LATE_COLLISION_INTERRUPT | (uint32)ENET_RETRY_LIMIT_INTERRUPT | (uint32)ENET_UNDERRUN_INTERRUPT |
                        (uint32)ENET_PAYLOAD_RX_INTERRUPT;
    uint32 RegisterValue = Base->EIR;
    
    /* Clear the interrupt event*/
    Base->EIR = StatusFlags;
    
    /* Check if driver is initialized*/
    if (Enet_apxState[Instance] != NULL_PTR)
    {
        /*Check if interrupt is spurious*/
        if (((Base->EIMR & IrqEnFlags) != 0U) &&
            ((RegisterValue & StatusFlags) != 0U))
        {  
            /* Callback function*/
            if (Enet_apxState[Instance]->Callback != NULL_PTR)
            {
                Enet_apxState[Instance]->Callback(Instance, ENET_ERR_EVENT);
            }
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_TxIRQHandler
 * Description   : Handler for ENET transmit interrupt.
 * This handler invokes the installed callback (if available) and clears the
 * interrupt flags.
 * implements    ENET_TxIRQHandler_Activity
 *
 *END**************************************************************************/
void ENET_TxIRQHandler(uint8 Instance,
                       uint8 Ring)
{
    ENET_Type *Base = Enet_apxBases[Instance];
    uint32 StatusFlags = Base->EIR;
    uint32 IrqEnFlags = Base->EIMR;
    
    /* Clear the interrupt event*/
    Base->EIR = (uint32)ENET_TX_FRAME_INTERRUPT | (uint32)ENET_TX_BUFFER_INTERRUPT;
    
    /* Check if driver is initialized*/
    if (Enet_apxState[Instance] != NULL_PTR)
    {
        /* Check interrupt is spurious*/
        if (((StatusFlags & ((uint32)ENET_TX_FRAME_INTERRUPT | (uint32)ENET_TX_BUFFER_INTERRUPT)) != 0U) &&
            ((IrqEnFlags & ((uint32)ENET_EIMR_TXB_MASK | (uint32)ENET_EIMR_TXF_MASK)) != 0U))
        {
            /* Callback function */
            if (Enet_apxState[Instance]->TxChCallback[Ring] != NULL_PTR)
            {
                Enet_apxState[Instance]->TxChCallback[Ring](Instance, Ring);
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_RxIRQHandler
 * Description   : Handler for ENET receive interrupt.
 * This handler invokes the installed callback (if available) and clears the
 * interrupt flags.
 *
 *END**************************************************************************/
void ENET_RxIRQHandler(uint8 Instance,
                       uint8 Ring)
{
    ENET_Type *Base = Enet_apxBases[Instance];
    uint32 StatusFlags = Base->EIR;
    uint32 IrqEnFlags = Base->EIMR;
    
    /* Clear the interrupt event*/
    Base->EIR = (uint32)ENET_RX_FRAME_INTERRUPT | (uint32)ENET_RX_BUFFER_INTERRUPT;
    
    /* Check if driver is initialized*/
    if (Enet_apxState[Instance] != NULL_PTR)
    {
        /* Check interrupt is spurious*/
        if (((StatusFlags & ((uint32)ENET_RX_FRAME_INTERRUPT | (uint32)ENET_RX_BUFFER_INTERRUPT)) != 0U) &&
            ((IrqEnFlags & ((uint32)ENET_EIR_RXB_MASK | (uint32)ENET_EIR_RXF_MASK)) != 0U))
        {
            /* Callback function */
            if (Enet_apxState[Instance]->RxChCallback[Ring] != NULL_PTR)
            {
                Enet_apxState[Instance]->RxChCallback[Ring](Instance, Ring);
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_TimeStampIRQHandler
 * Description   : Process timer-wrap event when using timestamps.
 * When using time-stamp, the timer only support for nano-second part of time,
 * driver need to process with second part of time. In this IRQ, the value in second will be updated.
 *
 *END**************************************************************************/
void ENET_TimeStampIRQHandler(uint8 Instance)
{
    ENET_Type *Base = Enet_apxBases[Instance];
    uint32 IrqEnFlags = Base->EIMR;
    uint32 StatusFlags = Base->EIR; 
    
    /* Clear the interrupt event*/
    Base->EIR = (uint32)ENET_EIR_TS_TIMER_MASK;
    /* Check if driver is initialized*/
    if (Enet_apxState[Instance] != NULL_PTR)
    {
        /* Check interrupt is spurious*/
        if (((StatusFlags & (uint32)ENET_EIR_TS_TIMER_MASK) != 0U) &&
            ((IrqEnFlags & (uint32)ENET_EIMR_TS_TIMER_MASK) != 0U))
        {
            if ((uint32)0xFFFFFFFFU == Enet_axLocalTime[Instance].seconds)
            {
                Enet_axLocalTime[Instance].secondsHi++;
                Enet_axLocalTime[Instance].seconds = 0U;
            }
            else
            {
                Enet_axLocalTime[Instance].seconds++;
            }
            /* Callback function */
            if (Enet_apxState[Instance]->TimerCallback != NULL_PTR)
            {
                Enet_apxState[Instance]->TimerCallback(Instance);
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_GetPowerState
 * Description   : Gets the current power state
 *
 *END**************************************************************************/
Enet_Ip_PowerStateType ENET_GetPowerState(const ENET_Type * Base)
{
    Enet_Ip_PowerStateType PowerState = ENET_PSTATE_RESET;

    /* The order is important to enforce RESET > SLEEP > ACTIVE > INACTIVE priority */
    if ((Base->ECR & ENET_ECR_RESET_MASK) != 0U)
    {
        PowerState = ENET_PSTATE_RESET;
    }
#if FEATURE_ENET_HAS_SLEEP_WAKEUP
    else if ((Base->ECR & ENET_ECR_SLEEP_MASK) != 0U)
    {
        PowerState = ENET_PSTATE_SLEEP;
    }
#endif
    else if ((Base->ECR & ENET_ECR_ETHEREN_MASK) != 0U)
    {
        PowerState = ENET_PSTATE_ACTIVE;
    }
    else if (((Base->ECR & ENET_ECR_ETHEREN_MASK) == 0U) || ((Base->ECR & ENET_ECR_DBGEN_MASK) == ENET_ECR_DBGEN_MASK))
    {
        PowerState = ENET_PSTATE_INACTIVE;
    }
    else 
    {
        /* Should not get here. */
    }

    return PowerState;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_WriteManagementFrame
 * Description   : Writes a MII management frame.
 *
 *END**************************************************************************/
Enet_Ip_StatusType ENET_WriteManagementFrame(ENET_Type * Base,
                                             const Enet_Ip_ManagementInfo *ManageInfo,
                                             uint32 TimeoutUs)
{
    Enet_Ip_StatusType status = ENET_STATUS_TIMEOUT;
    uint32 StartTime; 
    uint32 ElapsedTime; 
    uint32 TimeoutTicks;
    uint32 RegVal;
    
    /* Clear interrupt flag */
    Base->EIR |= ENET_EIR_MII_MASK;
    
    Base->MMFR = (ManageInfo->SupportedClause45 ? ENET_MMFR_ST(ENET_MMFR_START_INDICATION_45) : ENET_MMFR_ST(ENET_MMFR_START_INDICATION)) |
                              ENET_MMFR_OP(ManageInfo->OpFrameType) |
                              ENET_MMFR_PA(ManageInfo->PhysAddr) |
                              ENET_MMFR_RA(ManageInfo->SupportedClause45 ? (uint32)ManageInfo->MmdAddr : (uint32)ManageInfo->PhysReg) |
                              ENET_MMFR_TA(ENET_MMFR_TURN_AROUND) |
                              ENET_MMFR_DATA(ManageInfo->FrameData);
                              
    /* Wait for completion */
    ENET_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, TimeoutUs);
    
    do
    {
        RegVal = Base->EIR;
        if ((RegVal & ENET_EIR_MII_MASK) == ENET_EIR_MII_MASK)
        {
            status = ENET_STATUS_SUCCESS;
            break;
        }
    }
    while (!ENET_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));
    
    return status;
}


#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
