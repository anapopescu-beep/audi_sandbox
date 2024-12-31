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

#ifndef ENET_IP_HW_ACCESS_H
#define ENET_IP_HW_ACCESS_H

/**
*   @file
*   
*   @internal
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
#include "Enet_Ip_Types.h"
#include "Enet_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ENET_IP_HW_ACCESS_VENDOR_ID                    43
#define ENET_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION     4
#define ENET_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION     4
#define ENET_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION  0
#define ENET_IP_HW_ACCESS_SW_MAJOR_VERSION             1
#define ENET_IP_HW_ACCESS_SW_MINOR_VERSION             0
#define ENET_IP_HW_ACCESS_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Enet_Ip.h */
#if (ENET_IP_HW_ACCESS_VENDOR_ID != ENET_IP_VENDOR_ID)
    #error "Enet_Ip_Hw_Access.h and Enet_Ip.h have different vendor ids"
#endif
#if (( ENET_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION    != ENET_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( ENET_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION    != ENET_IP_AR_RELEASE_MINOR_VERSION) || \
     ( ENET_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != ENET_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip_Hw_Access.h and Enet_Ip.h are different"
#endif
#if (( ENET_IP_HW_ACCESS_SW_MAJOR_VERSION != ENET_IP_SW_MAJOR_VERSION) || \
     ( ENET_IP_HW_ACCESS_SW_MINOR_VERSION != ENET_IP_SW_MINOR_VERSION) || \
     ( ENET_IP_HW_ACCESS_SW_PATCH_VERSION != ENET_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Enet_Ip_Hw_Access.h and Enet_Ip.h are different"
#endif

/* Checks against Enet_Ip_Types.h */
#if (ENET_IP_HW_ACCESS_VENDOR_ID != ENET_IP_TYPES_VENDOR_ID)
    #error "Enet_Ip_Hw_Access.h and Enet_Ip_Types.h have different vendor ids"
#endif
#if (( ENET_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION    != ENET_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( ENET_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION    != ENET_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( ENET_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != ENET_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip_Hw_Access.h and Enet_Ip_Types.h are different"
#endif
#if (( ENET_IP_HW_ACCESS_SW_MAJOR_VERSION != ENET_IP_TYPES_SW_MAJOR_VERSION) || \
     ( ENET_IP_HW_ACCESS_SW_MINOR_VERSION != ENET_IP_TYPES_SW_MINOR_VERSION) || \
     ( ENET_IP_HW_ACCESS_SW_PATCH_VERSION != ENET_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Enet_Ip_Hw_Access.h and Enet_Ip_Types.h are different"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
 
#define ENET_MMFR_START_INDICATION     (1U)
#define ENET_MMFR_START_INDICATION_45  (0U)
#define ENET_MMFR_TURN_AROUND          (2U)

/*! @brief Control and status region bit masks of the receive buffer descriptor. */
#define ENET_BUFFDESCR_RX_EMPTY_MASK        0x8000U
#define ENET_BUFFDESCR_RX_CONSUMED_MASK     0x4000U
#define ENET_BUFFDESCR_RX_WRAP_MASK         0x2000U
#define ENET_BUFFDESCR_RX_CTRL_ERR_MASK     0x0037U

/*! @brief Control and status bit masks of the transmit buffer descriptor. */
#define ENET_BUFFDESCR_TX_READY_MASK        0x8000U
#define ENET_BUFFDESCR_TX_WRAP_MASK         0x2000U
#define ENET_BUFFDESCR_TX_LAST_MASK         0x0800U
#define ENET_BUFFDESCR_TX_TRANSMITCRC_MASK  0x0400U
#define ENET_BUFFDESCR_TX_LOCKED_MASK       0x4000U

#define ENET_RX_ENH_ERR_MASK    (0x86000000U)
#define ENET_TX_ENH_ERR_MASK    (0x00003F00U)

/*! @brief Control and status bit masks of the enhanced receive buffer descriptor. */
#define ENET_RX_ENH1_FRAG_MASK        0x00000001UL
#define ENET_RX_ENH1_IPV6_MASK        0x00000002UL
#define ENET_RX_ENH1_VPCP_MASK        0x0000E000UL
#define ENET_RX_ENH1_VPCP_SHIFT       13UL
#define ENET_RX_ENH1_INT_MASK         0x00800000UL
#define ENET_RX_ENH1_UNICAST_MASK     0x01000000UL
#define ENET_RX_ENH2_CSUM_MASK        0x0000FFFFUL
#define ENET_RX_ENH2_HLEN_SHIFT       27UL
#define ENET_RX_ENH2_HLEN_MASK        0xF8000000UL
#define ENET_RX_ENH2_PROTO_SHIFT      16UL
#define ENET_RX_ENH2_PROTO_MASK       0x00FF0000UL

/*! @brief Control and status bit masks of the enhanced transmit buffer descriptor. */
#define ENET_TX_ENH1_INT_MASK         0x40000000UL
#define ENET_TX_ENH1_TS_MASK          0x20000000UL

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 * @brief Management Frame information
 */
typedef struct 
{
    uint8 PhysAddr;
    uint16 PhysReg;
    uint16 MmdAddr;
    Enet_Ip_MmfrOpType OpFrameType;
    uint16 FrameData;
    boolean SupportedClause45;
} Enet_Ip_ManagementInfo;

/*******************************************************************************
 * Variables
 ******************************************************************************/
#define ETH_START_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"

extern ENET_Type * const Enet_apxBases[FEATURE_ENET_NUM_INSTANCES];

#define ETH_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"

#define ETH_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_MemMap.h"

extern Enet_Ip_StateType *Enet_apxState[FEATURE_ENET_NUM_INSTANCES];

#define ETH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_MemMap.h"

#define ETH_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_MemMap.h"

extern Enet_Ip_TimeStampType Enet_axLocalTime[FEATURE_ENET_NUM_INSTANCES];

#define ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_MemMap.h"

/*******************************************************************************
 * API
 ******************************************************************************/
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

/*!
 * @brief Sets the speed of the MII interface.
 *
 * @param[in] base  The base address of the module
 * @param[in] speed The MII speed
 */
extern void ENET_SetSpeed(ENET_Type * Base,
                   Enet_Ip_MiiSpeedType Speed);
/*!
 * @brief The transmit descriptor ring has been updated .
 *
 * The driver produced a new empty transmit buffer with bit empty set.
 *
 * @param[in] base  The base address of the module
 * @param[in] ring  ring number
 */                    
extern void ENET_ActivateTransmit(ENET_Type *Base, 
                                uint8 Ring);
/*!
 * @brief The receive descriptor ring has been updated .
 *
 * The driver produced a new empty receive buffer with bit empty set.
 *
 * @param[in] base  The base address of the module
 * @param[in] ring  ring number
 */                                
extern void ENET_ActivateReceive(ENET_Type *Base, 
                                 uint8 Ring);
                                 
#if FEATURE_ENET_HAS_SLEEP_WAKEUP                                
/*!
 * @brief Handler for ENET wakeup interrupts.
 *
 * This handler invokes the installed callback, if available, and clears the
 * interrupt flags.
 *
 * @param[in] instance Instance number
 * @param[in] ring  ring number
 */                                 
extern void ENET_WakeupIRQHandler(uint8 Instance);
#endif

/*!
 * @brief Handler for ENET error interrupts.
 *
 * This handler invokes the installed callback, if available, and clears the
 * interrupt flags.
 *
 * @param[in] Instance Instance number
 * @param[in] ring  ring number
 */
extern void ENET_ErrIRQHandler(uint8 Instance);
/*!
 * @brief Handler for ENET transmit interrupts.
 *
 * This handler invokes the installed callback, if available, and clears the
 * interrupt flags.
 *
 * @param[in] Instance Instance number
 * @param[in] ring  ring number
 */
extern void ENET_TxIRQHandler(uint8 Instance,
                            uint8 Ring); 
/*!
 * @brief Handler for ENET receive interrupts.
 *
 * This handler invokes the installed callback, if available, and clears the
 * interrupt flags.
 *
 * @param[in] Instance Instance number
 * @param[in] ring  ring number
 */                       
extern void ENET_RxIRQHandler(uint8 Instance,
                            uint8 Ring);
/*!
 * @brief Gets the power state
 *
 * @param[in] base   The base address of the module
 * @return  The power state of the controller
 */
extern Enet_Ip_PowerStateType ENET_GetPowerState(const ENET_Type * Base);
/*!
 * @brief Writes an MII management frame.
 *
 * @param[in] base The base address of the module
 * @param[in] ManageInfo contains some information:
 *  phyAddr The address of the PHY
 *  phyReg The address of the register to be accessed
 *  Mmd For clause 45, selects the device (MMD)
 *  OpType The operation type (read/write)
 *  Data Data to be written, ignored if the operation is a read one
 *  Clause45 True if the management frame is a clause 45 one, false for clause 22
 * @param[in] timeoutUs Timeout for the management operation (in microseconds)
 * @retval ENET_STATUS_SUCCESS The operation completed successfully.
 * @retval ENET_STATUS_TIMEOUT The specified timeout expired before completing the operation.
 */
extern Enet_Ip_StatusType ENET_WriteManagementFrame(ENET_Type * Base,
                                             const Enet_Ip_ManagementInfo *ManageInfo,
                                             uint32 TimeoutUs);
/*!
 * @brief Checks for timeout condition.
 *
 * @param[in,out] startTimeInOut    The starting time from which elapsed time is measured
 * @param[in,out] elapsedTimeInOut  The accumulated elapsed time from the starting time reference
 * @param[in]     timeoutTicks      The timeout limit (in ticks)
 */
extern boolean ENET_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks);
/*!
 * @brief Initializes a starting reference point for timeout
 *
 * @param[out] startTimeOut    The starting time from which elapsed time is measured
 * @param[out] elapsedTimeOut  The elapsed time to be passed to ENET_TimeoutExpired
 * @param[out] timeoutTicksOut The timeout value (in ticks) to be passed to ENET_TimeoutExpired
 * @param[in]  timeoutUs       The timeout value (in microseconds)
 */                            
extern void ENET_StartTimeout(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs);
/*!
 * @brief Handler for ENET timestamp interrupts.
 *
 * This handler invokes the installed callback, if available, and clears the
 * interrupt flags.
 *
 * @param[in] Instance Instance number
 */                        
extern void ENET_TimeStampIRQHandler(uint8 Instance);
/*!
 * @brief Reads the data field of a MII management frame.
 *
 * @param[in] base The base address of the module
 * @return The read data
 */
static inline uint16 ENET_ReadManagementFrameData(const ENET_Type * Base)
{
    return (uint16)(Base->MMFR & ENET_MMFR_DATA_MASK);
}

/*!
 *
 * Function Name : ENET_AddToHashTable
 * Description   : Adds an entry to the hash table filter.
 * This functions adds an entry to the hash table filter based on the CRC of a
 * hardware address.
 *
 */
void ENET_AddToHashTable(ENET_Type * Base,
                        uint32 Crc);

/*!
 *
 * Function Name : ENET_RemoveFromHashTable
 * Description   : Removes an entry from the hash table filter.
 * This functions removes an entry from the hash table filter based on the CRC
 * of a hardware address.
 *
 */
void ENET_RemoveFromHashTable(ENET_Type * Base,
                              uint32 Crc);

#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ENET_IP_HW_ACCESS_H */
