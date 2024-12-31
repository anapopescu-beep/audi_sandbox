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

#ifndef ENET_IP_H
#define ENET_IP_H

/**
*   @file
*
*   @addtogroup ENET_DRIVER ENET Driver
*   @{
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
#include "Enet_Ip_Types.h"
#include "Enet_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ENET_IP_VENDOR_ID                      43
#define ENET_IP_AR_RELEASE_MAJOR_VERSION       4
#define ENET_IP_AR_RELEASE_MINOR_VERSION       4
#define ENET_IP_AR_RELEASE_REVISION_VERSION    0
#define ENET_IP_SW_MAJOR_VERSION               1
#define ENET_IP_SW_MINOR_VERSION               0
#define ENET_IP_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Enet_Ip_Types.h */
#if (ENET_IP_VENDOR_ID != ENET_IP_TYPES_VENDOR_ID)
    #error "Enet_Ip.h and Enet_Ip_Types.h have different vendor ids"
#endif
#if (( ENET_IP_AR_RELEASE_MAJOR_VERSION    != ENET_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( ENET_IP_AR_RELEASE_MINOR_VERSION    != ENET_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( ENET_IP_AR_RELEASE_REVISION_VERSION != ENET_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip.h and Enet_Ip_Types.h are different"
#endif
#if (( ENET_IP_SW_MAJOR_VERSION != ENET_IP_TYPES_SW_MAJOR_VERSION) || \
     ( ENET_IP_SW_MINOR_VERSION != ENET_IP_TYPES_SW_MINOR_VERSION) || \
     ( ENET_IP_SW_PATCH_VERSION != ENET_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Enet_Ip.h and Enet_Ip_Types.h are different"
#endif

/* Checks against Enet_Ip_Cfg.h */
#if (ENET_IP_VENDOR_ID != ENET_IP_CFG_VENDOR_ID)
    #error "Enet_Ip.h and Enet_Ip_Cfg.h have different vendor ids"
#endif
#if (( ENET_IP_AR_RELEASE_MAJOR_VERSION    != ENET_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     ( ENET_IP_AR_RELEASE_MINOR_VERSION    != ENET_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     ( ENET_IP_AR_RELEASE_REVISION_VERSION != ENET_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip.h and Enet_Ip_Cfg.h are different"
#endif
#if (( ENET_IP_SW_MAJOR_VERSION != ENET_IP_CFG_SW_MAJOR_VERSION) || \
     ( ENET_IP_SW_MINOR_VERSION != ENET_IP_CFG_SW_MINOR_VERSION) || \
     ( ENET_IP_SW_PATCH_VERSION != ENET_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Enet_Ip.h and Enet_Ip_Cfg.h are different"
#endif


/*******************************************************************************
 * GLOBAL VARIABLE DECLARATIONS
 ******************************************************************************/
#define ETH_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_MemMap.h"

ENET_CONFIG_EXT

#define ETH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_MemMap.h"

/*******************************************************************************
 * API
 ******************************************************************************/
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

/*!
 * @name Initialization and De-initialization
 * @{
 */

/*!
 * @brief Initializes the ENET module
 *
 * This function initializes and enables the ENET module, configuring receive and transmit control
 * settings, the receive and transmit descriptors rings, and the MAC physical address.
 *
 * Note: All untagged packets will be received by ring 0 (zero). VLAN tagged
 * packets are routed depending on the VLAN Tag Priority field according to
 * the provided configuration.
 *
 * @param[in] Instance Instance number
 * @param[in] Config The module configuration structure
 *
 */
void Enet_Ip_Init(uint8 Instance,
                  const Enet_CtrlConfigType *Config);

/*!
 * @brief Gets the current power state of the ENET module
 *
 * @param[in] Instance Instance number
 * @return Enet_Ip_PowerStateType The power state of the controller
 */                  
Enet_Ip_PowerStateType Enet_Ip_GetPowerState(uint8 Instance);

/*!
 * @brief Deinitializes the ENET module
 *
 * This function disables the interrupts and then disables the ENET module.
 *
 * @param[in] Instance Instance number
 */
void Enet_Ip_Deinit(uint8 Instance);

/*!
 * @brief Enables all configured transmit and receive buffers and then enables the controller
 *
 * @param[in] Instance   Instance number
 */
void Enet_Ip_EnableController(uint8 Instance);

/*!
 * @brief Recover the hash table filtering caused by add add/remove open/close to hash table.
 *
 * @param[in] Instance   Instance number
 */
void Enet_Ip_RecoverFilter(uint8 Instance);

#if FEATURE_ENET_HAS_SLEEP_WAKEUP
/*!
 * @brief Set MAC in sleep Mode or Normal Mode.
 *
 * @param[in] Instance   Instance number
 * @param[in] Enable     TRUE: Sleep Mode, FALSE: Normal Mode.
 */
void Enet_Ip_SetSleepMode(uint8 Instance,
                           boolean Enable);
#endif

/*!
 * @brief Disables the controller and resets all the configured transmit and receive buffers
 *
 * Warning: This function ignores all pending transmission and reception requests
 *
 * @param[in] Instance   Instance number
 */
void Enet_Ip_DisableController(uint8 Instance);

/*!
 * @brief Sets the speed of the MII interface
 *
 * @param[in] Instance Instance number
 * @param[in] Speed MII speed
 */
void Enet_Ip_SetSpeed(uint8 Instance, Enet_Ip_MiiSpeedType Speed);

/*!
 * @brief Provides a transmit buffer to be used by the application for transmission.
 *
 * This function provides an internal buffer which can further be used by the application
 * to store the transmit data.
 * 
 * Note: The buffer will be marked as locked and won't be released until after a call to
 * Enet_Ip_GetTransmitStatus for the same buffer returns ENET_STATUS_SUCCESS.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to get a buffer at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in]     Instance Instance number
 * @param[in]     Ring   Ring number
 * @param[in,out] Buff   In:  Buffer containing the desired length
 *                       Out: Buffer containing the granted length or available length in case of overflow.
 * @param[out]    BuffId Index of the buffer (descriptor) within the ring.
 *                       If this information is not needed, this parameter should be NULL_PTR.
 * @retval ENET_STATUS_SUCCESS The buffer has been succesfully locked.
 * @retval ENET_STATUS_TX_BUFF_BUSY All buffers are currently in use.
 * @retval ENET_STATUS_TX_BUFF_OVERFLOW The requested buffer length cannot be granted.
 */
Enet_Ip_StatusType Enet_Ip_GetTxBuff(uint8 Instance,
                                     uint8 Ring,
                                     Enet_Ip_BufferType * Buff,
                                     uint16 * BuffId);

/*!
 * @brief Sends an Ethernet frame
 *
 * This function sends an Ethernet frame, contained in the buffer received as parameter.
 *
 * Note: Since the transmission of the frame is not complete when this function returns,
 * the application must not change/alter/re-use the provided buffer until after a call
 * to Enet_Ip_GetTransmitStatus for the same buffer returns ENET_STATUS_SUCCESS.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to send a frame at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in] Instance Instance number
 * @param[in] Ring The ring number
 * @param[in] Buff The buffer containing the frame
 * @param[in] Options Configuration options applicable to this buffer's transmission only.
 * Can be NULL_PTR, if no special option is required.
 * @retval ENET_STATUS_SUCCESS       The frame was successfully enqueued for transmission.
 * @retval ENET_STATUS_TX_QUEUE_FULL There is no available space for the frame in the queue.
 */
Enet_Ip_StatusType Enet_Ip_SendFrame(uint8 Instance,
                                     uint8 Ring,
                                     const Enet_Ip_BufferType * Buff,
                                     const Enet_Ip_TxOptionsType * Options);

/*!
 * @brief Reads a received Ethernet frame
 *
 * This function reads the first received Ethernet frame in the Rx queue. The buffer received
 * as parameter will be updated by the driver and the .data field will point to a memory area
 * containing the frame data.
 *
 * Note: Once the application finished processing the buffer, it could be reused by the
 * driver for further receptions by invoking Enet_Ip_ProvideRxBuff.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to read a frame at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in]  Instance Instance number
 * @param[in]  Ring The ring number
 * @param[out] Buff The buffer containing the frame
 * @param[out] Info Enhanced information related to the data contained by this receive buffer.
 * If this information is not needed, this parameter should be NULL_PTR.
 * @retval ENET_STATUS_SUCCESS        A frame was successfully read.
 * @retval ENET_STATUS_RX_QUEUE_EMPTY There is no available frame in the queue.
 */
Enet_Ip_StatusType Enet_Ip_ReadFrame(uint8 Instance,
                                     uint8 Ring,
                                     Enet_Ip_BufferType * Buff,
                                     Enet_Ip_RxInfoType * Info);

/*!
 * @brief Provides a receive buffer to be used by the driver for reception.
 *
 * This function provides a buffer which can further be used by the reception mechanism
 * in order to store the received data.
 *
 * Note: The application can either provide a buffer previously obtained in a Enet_Ip_ReadFrame
 * call (when it is no longer needed after being fully processed), or allocate a new buffer.
 * The former approach is recommended as it has a simpler usage model and re-uses the same initial
 * memory range for the entire driver lifetime operation. The later approach could provide more
 * flexibility, but since it involves constant memory free/alloc operations it is only recommended
 * with an efficient pool-based memory allocator.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to provide a buffer at the same time. This synchronization shall be implemented by the
 * application.
 *
 * Important: The application is responsible for providing one Rx buffer for every frame it
 * receives, otherwise the reception ring can fill-up, affecting further reception.
 *
 * Usage example:
 *
 * stat = Enet_Ip_ReadFrame(INST_ENET0, 0U, &rxBuff);
 *
 * if (stat == ENET_STATUS_SUCCESS)
 * {
 *     process_buffer(&rxBuff);
 *     Enet_Ip_ProvideRxBuff(INST_ENET0, 0U, &rxBuff);
 * }
 *
 * @param[in] Instance Instance number
 * @param[in] Ring The ring number
 * @param[in] Buff The buffer to be added to the reception ring
 */
void Enet_Ip_ProvideRxBuff(uint8 Instance,
                           uint8 Ring,
                           const Enet_Ip_BufferType * Buff);

/*!
 * @brief Checks if there are more frames available in the given queue
 *
 * This function takes a peek at the given Rx queue to check if there are more Ethernet
 * frames to be received. Its intended usage is to provide this information without
 * also extracting the frame as "Enet_Ip_ReadFrame".
 *
 * @param[in]  Instance Instance number
 * @param[in]  Ring The ring number
 * @retval TRUE  There is an available frame in the queue.
 * @retval FALSE There is no available frame in the queue.
 */
boolean Enet_Ip_IsFrameAvailable(uint8 Instance,
                                 uint8 Ring);

/*!
 * @brief Checks if the transmission of a buffer is complete.
 *
 * This function checks if the transmission of the given buffer is complete.
 *
 * Note: If the buffer is not found in the Tx ring, the function will return ENET_STATUS_BUFF_NOT_FOUND.
 *
 * @param[in]  Instance Instance number
 * @param[in]  Ring The ring number
 * @param[in]  Buff The transmit buffer for which the status shall be checked
 * @param[out] Info Extended information related to the buffer. If this information is not needed,
 * this parameter should be NULL_PTR.
 * @retval ENET_STATUS_BUSY            The frame is still enqueued for transmission.
 * @retval ENET_STATUS_BUFF_NOT_FOUND  The buffer was not found in the Tx queue.
 * @retval ENET_STATUS_SUCCESS         Otherwise.
 */
Enet_Ip_StatusType Enet_Ip_GetTransmitStatus(uint8 Instance,
                                             uint8 Ring,
                                             const Enet_Ip_BufferType * Buff,
                                             Enet_Ip_TxInfoType * Info);

/*!
 * @brief Gets statistics from the specified counter
 *
 * @param[in] Instance Instance number
 * @param[in] Counter The counter to be read
 * @return The value of the requested counter
 */
uint32 Enet_Ip_GetCounter(uint8 Instance,
                          Enet_Ip_CounterType Counter);
/*!
 * @brief Enables/Disables the MIB counters
 *
 * @param[in] Instance Instance number
 * @param[in] Enable The MIB logic is enabled(TRUE) else disabled(FALSE)
 * @return The Value of the requested counter
 */
void Enet_Ip_ConfigCounters(uint8 Instance,
                            boolean Enable);
/*!
 * @brief Enables the MDIO interface
 *
 * @param[in] Instance Instance number
 * @param[in] MiiPreambleDisabled Enables/disables prepending a preamble to the MII management frame.
 * @param[in] ModuleClk Clock frequency provide MDC.
 */
void Enet_Ip_EnableMDIO(uint8 Instance,
                        boolean MiiPreambleDisabled,
                        uint32 ModuleClk);

/*!
 * @brief Reads the selected register of the PHY
 *
 * @param[in]  Instance Instance number
 * @param[in]  PhyAddr PHY device address
 * @param[in]  PhyReg PHY register address
 * @param[out] Data Data read from the PHY
 * @param[in] TimeoutMs Timeout for the read operation (in milliseconds)
 * @retval ENET_STATUS_SUCCESS The operation completed successfully.
 * @retval ENET_STATUS_TIMEOUT The specified timeout expired before completing the operation.
 */
Enet_Ip_StatusType Enet_Ip_MDIORead(uint8 Instance,
                                    uint8 PhyAddr,
                                    uint8 PhyReg,
                                    uint16 *Data,
                                    uint32 TimeoutMs);

/*!
 * @brief Writes the selected register of the PHY
 *
 * @param[in] Instance Instance number
 * @param[in] PhyAddr PHY device address
 * @param[in] PhyReg PHY register address
 * @param[in] Data Data to be written in the specified register of the PHY
 * @param[in] TimeoutMs Timeout for the write operation (in milliseconds)
 * @retval ENET_STATUS_SUCCESS The operation completed successfully.
 * @retval ENET_STATUS_TIMEOUT The specified timeout expired before completing the operation.
 */
Enet_Ip_StatusType Enet_Ip_MDIOWrite(uint8 Instance,
                                     uint8 PhyAddr,
                                     uint8 PhyReg,
                                     uint16 Data,
                                     uint32 TimeoutMs);

/*!
 * @brief Reads a register of the specified MMD in a PHY device
 *
 * @param[in]  Instance Instance number
 * @param[in]  PhyAddr PHY device address
 * @param[in]  Mmd The MMD index of the target register
 * @param[in]  PhyReg PHY register address
 * @param[out] Data Data read from the PHY
 * @param[in] TimeoutMs Timeout for the read operation (in milliseconds)
 * @retval ENET_STATUS_SUCCESS The operation completed successfully.
 * @retval ENET_STATUS_TIMEOUT The specified timeout expired before completing the operation.
 */
Enet_Ip_StatusType Enet_Ip_MDIOReadMMD(uint8 Instance,
                                       uint8 PhyAddr,
                                       uint8 Mmd,
                                       uint16 PhyReg,
                                       uint16 *Data,
                                       uint32 TimeoutMs);

/*!
 * @brief Writes a register of the specified MMD in a PHY device
 *
 * @param[in] Instance Instance number
 * @param[in] PhyAddr PHY device address
 * @param[in] Mmd The MMD index of the target register
 * @param[in] PhyReg PHY register address
 * @param[in] Data Data to be written in the specified register of the PHY
 * @param[in] TimeoutMs Timeout for the write operation (in milliseconds)
 * @retval ENET_STATUS_SUCCESS The operation completed successfully.
 * @retval ENET_STATUS_TIMEOUT The specified timeout expired before completing the operation.
 */
Enet_Ip_StatusType Enet_Ip_MDIOWriteMMD(uint8 Instance,
                                        uint8 PhyAddr,
                                        uint8 Mmd,
                                        uint16 PhyReg,
                                        uint16 Data,
                                        uint32 TimeoutMs);

/*!
 * @brief Configures the physical address of the MAC
 *
 * @param[in] Instance Instance number
 * @param[in] MacAddr The MAC address to be configured
 */
void Enet_Ip_SetMacAddr(uint8 Instance,
                        const uint8 *MacAddr);

/*!
 * @brief Gets the physical address of the MAC
 *
 * @param[in]  Instance Instance number
 * @param[out] MacAddr The physical address of the MAC
 */
void Enet_Ip_GetMacAddr(uint8 Instance,
                        uint8 *MacAddr);

/*!
 * @brief Enables/Disables forwarding of the broadcast traffic.
 *
 * @param[in]  Instance Instance number
 * @param[in]  Enable   If true, the application will receive all the broadcast
 * traffic; if false, it stops forwarding this kind of traffic.
 */
void Enet_Ip_SetBroadcastForwardAll(uint8 Instance,
                                    boolean Enable);
/*!
 * @brief Enables/Disables forwarding of the multicast traffic,
 * irrespective of the destination MAC address.
 *
 * @param[in]  Instance Instance number
 * @param[in]  Enable   If true, the application will receive all the multicast
 * traffic; if false, it stops forwarding this kind of traffic.
 */
void Enet_Ip_SetMulticastForwardAll(uint8 Instance,
                                     boolean Enable);
                         
/*!
 * @brief Adds a hardware address to the hash filter. The destination address of
 * an incoming packet is passed through CRC logic and then compared to the
 * entries in the hash table.
 *
 * @param[in]  Instance Instance number
 * @param[in]  MacAddr  The physical address
 */
void Enet_Ip_AddDstAddrToHashFilter(uint8 Instance,
                                    const uint8 *MacAddr);

/*!
 * @brief Removes a hardware address from the hash filter. The destination
 * address of an incoming packet is passed through CRC logic and then compared
 * to the entries in the hash table.
 *
 * @param[in]  Instance Instance number
 * @param[in]  MacAddr  The physical address
 */
void Enet_Ip_RemoveDstAddrFromHashFilter(uint8 Instance,
                                         const uint8 *MacAddr);
/*!
 * @brief Set system time correction.
 *
 * @param[in]  Instance           Instance number
 * @param[in]  Offset             Chooses between negative and positive correction
 * @param[in]  TimeStamp          Offset between time stamp grandmaster and time stamp by local clock.
 */                                         
extern void Enet_Ip_SetSysTimeCorr(uint8 Instance,
                          Enet_Ip_SysTimeCorrOffsetType Offset,
                          Enet_Ip_TimeStampType DiffTimeStamp);
/*!
 * @brief Sets the timer correction period and correction increment value.
 *
 * @param[in]  Instance Instance number
 * @param[in]  CorrectValue   Correction timer added.
 * @param[in]  CorrectPeriod  Number of timer clock cycles
 */
void Enet_Ip_TimerSetCorrection(uint8 Instance,
                                 uint32 CorrectValue,
                                 uint32 CorrectPeriod);
/*!
 * @brief The timer stop at the current value.
 *
 * @param[in] Instance       Instance number
 */
void Enet_Ip_TimerStop(uint8 Instance);

/*!
 * @brief Configures and enables a specific timer channel.
 *
 * @param[in] Instance      Instance number
 * @param[in] Channel       Timer channel
 * @param[in] Config        the value(mode, interrupt, enable DMA or not) to set for timer channel.
 * @retval ENET_STATUS_SUCCESS The operation completed successfully.
 * @retval ENET_STATUS_TIMEOUT The specified timeout expired before completing the operation.
 */
Enet_Ip_StatusType Enet_Ip_TimerEnableChannel(uint8 Instance,
                                uint8 Channel,
                                const Enet_Ip_TimerChannelConfigType *Config);
                                
/*!
 * @brief Sets the compare value for a channel configured as output compare.
 *
 * @param[in] Instance      Instance number
 * @param[in] Channel       Timer channel
 * @param[in] Value        the value to compare.
 */                                
void Enet_Ip_TimerSetCompare(uint8 Instance,
                             uint8 Channel,
                             uint32 Value);
                             
#if FEATURE_ENET_HAS_INPUT_CAPTURE
/*!
 * @brief Gets the last value captured on a specific channel configured as
 *
 * @param[in] Instance      Instance number
 * @param[in] Channel       Timer channel
 * @param[in] Config        The value captured.
 */                             
void Enet_Ip_TimerGetCapture(uint8 Instance,
                              uint8 Channel,
                              uint32 *Capture);
#endif
                             
/*!
 * @brief The timer starts incrementing.
 *
 * @param[in] Instance       Instance number
 */
void Enet_Ip_TimerStart(uint8 Instance);

/*!
 * @brief Initializes the adjustable timer using the given configuration
 * and enables it.
 *
 * @param[in] Instance       Instance number
 * @param[in] TimerConfig    timer value need to initialize.
 */
void Enet_Ip_TimerInit(uint8 Instance,
                       const Enet_Ip_TimerConfigType *TimerConfig);
/*!
 * @brief Sets the value of the timer.
 *
 * @param[in] Instance       Instance number
 * @param[in] TimerConfig    timer value set.
 */
void Enet_Ip_TimerSet(uint8 Instance,
                      Enet_Ip_TimeStampType TimerValue);
/*!
 * @brief Gets the value of the timer.
 *
 * @param[in] Instance       Instance number
 * @param[in] TimerConfig    timer value gotten.
 */
void Enet_Ip_TimerGet(uint8 Instance,
                       Enet_Ip_TimeStampType *TimeStamp);
                      
/*!
 * @brief Enable store and forward .
 *
 * @param[in] Instance       Instance number
 */
void Enet_Ip_EnableTxStoreAndForward(uint8 Instance);

/*!
 * @brief Sets FIFO threshold levels.
 *
 * @param[in] Instance       Instance number
 * @param[in] ThresholdType  FIFO threshold types (defined in Enet_Ip_FifoThresholdType) need to update
 * @param[in] ThresholdValue  FIFO threshold value
 */
void Enet_Ip_SetFIFOThreshold(uint8 Instance,
                              Enet_Ip_FifoThresholdType ThresholdType,
                              uint8 ThresholdValue);
/*!
 * @brief Sets the transmit FIFO watermark.
 *
 * @param[in] Instance  Instance number
 * @param[in] Watermark  Number of bytes written to the transmit FIFO before transmission.
 */                              
void Enet_Ip_SetTxFIFOWatermark(uint8 Instance,
                                uint16 Watermark);  
                                
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ENET_IP_H */

