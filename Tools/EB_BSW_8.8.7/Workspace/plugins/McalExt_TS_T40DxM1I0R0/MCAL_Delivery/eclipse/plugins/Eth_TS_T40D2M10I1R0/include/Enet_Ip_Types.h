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

#ifndef ENET_IP_TYPES_H
#define ENET_IP_TYPES_H

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
#include "Mcal.h"
#include "Enet_Ip_CfgDefines.h"
#include "Enet_Ip_Features.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ENET_IP_TYPES_VENDOR_ID                      43
#define ENET_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define ENET_IP_TYPES_AR_RELEASE_MINOR_VERSION       4
#define ENET_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define ENET_IP_TYPES_SW_MAJOR_VERSION               1
#define ENET_IP_TYPES_SW_MINOR_VERSION               0
#define ENET_IP_TYPES_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Enet_Ip_Features.h */
#if (ENET_IP_TYPES_VENDOR_ID != ENET_IP_FEATURES_VENDOR_ID)
    #error "Enet_Ip_Types.h and Enet_Ip_Features.h have different vendor ids"
#endif
#if (( ENET_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != ENET_IP_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     ( ENET_IP_TYPES_AR_RELEASE_MINOR_VERSION    != ENET_IP_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     ( ENET_IP_TYPES_AR_RELEASE_REVISION_VERSION != ENET_IP_FEATURES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip_Types.h and Enet_Ip_Features.h are different"
#endif
#if (( ENET_IP_TYPES_SW_MAJOR_VERSION != ENET_IP_FEATURES_SW_MAJOR_VERSION) || \
     ( ENET_IP_TYPES_SW_MINOR_VERSION != ENET_IP_FEATURES_SW_MINOR_VERSION) || \
     ( ENET_IP_TYPES_SW_PATCH_VERSION != ENET_IP_FEATURES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Enet_Ip_Types.h and Enet_Ip_Features.h are different"
#endif

/* Checks against Enet_Ip_CfgDefines.h */
#if (ENET_IP_TYPES_VENDOR_ID != ENET_IP_CFGDEFINES_VENDOR_ID)
    #error "Enet_Ip_Types.h and Enet_Ip_CfgDefines.h have different vendor ids"
#endif
#if (( ENET_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != ENET_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     ( ENET_IP_TYPES_AR_RELEASE_MINOR_VERSION    != ENET_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     ( ENET_IP_TYPES_AR_RELEASE_REVISION_VERSION != ENET_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip_Types.h and Enet_Ip_CfgDefines.h are different"
#endif
#if (( ENET_IP_TYPES_SW_MAJOR_VERSION != ENET_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     ( ENET_IP_TYPES_SW_MINOR_VERSION != ENET_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     ( ENET_IP_TYPES_SW_PATCH_VERSION != ENET_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Enet_Ip_Types.h and Enet_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((ENET_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ENET_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Enet_Ip_Types.h and Mcal.h are different"
    #endif
#endif
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Return values
 * @implements Enet_Ip_StatusType_structure
 */
typedef enum
{
    /* Generic error codes */
    ENET_STATUS_SUCCESS                    = 0x000U,   /*!< Generic operation success status */
    ENET_STATUS_ERROR                      = 0x001U,   /*!< Generic operation failure status */
    ENET_STATUS_BUSY                       = 0x002U,   /*!< Generic operation busy status */
    ENET_STATUS_TIMEOUT                    = 0x003U,   /*!< Generic operation timeout status */
    ENET_STATUS_UNSUPPORTED                = 0x004U,   /*!< Generic operation unsupported status */

    /* ENET specific error codes */
    ENET_STATUS_RX_QUEUE_EMPTY             = 0xA01U,   /*!< There is no available frame in the receive queue */
    ENET_STATUS_TX_QUEUE_FULL              = 0xA02U,   /*!< There is no available space for the frame in the transmit queue */
    ENET_STATUS_BUFF_NOT_FOUND             = 0xA03U,   /*!< The specified buffer was not found in the queue */
    ENET_STATUS_TX_BUFF_BUSY               = 0xA04U,   /*!< All internal TX buffers are currently in use */
    ENET_STATUS_TX_BUFF_OVERFLOW           = 0xA05U    /*!< The requested TX buffer length cannot*/

} Enet_Ip_StatusType;

/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief Common interrupt sources
 * @implements Enet_Ip_InterruptType_structure
 */
typedef enum
{
    ENET_BABR_INTERRUPT             = ENET_EIR_BABR_MASK,
    ENET_BABT_INTERRUPT             = ENET_EIR_BABT_MASK,
    ENET_GRACE_STOP_INTERRUPT       = ENET_EIR_GRA_MASK,
    ENET_TX_FRAME_INTERRUPT         = ENET_EIR_TXF_MASK,
    ENET_TX_BUFFER_INTERRUPT        = ENET_EIR_TXB_MASK,
    ENET_RX_FRAME_INTERRUPT         = ENET_EIR_RXF_MASK,
    ENET_RX_BUFFER_INTERRUPT        = ENET_EIR_RXB_MASK,
    ENET_MII_INTERRUPT              = ENET_EIR_MII_MASK,
    ENET_EBERR_INTERRUPT            = ENET_EIR_EBERR_MASK,
    ENET_LATE_COLLISION_INTERRUPT   = ENET_EIR_LC_MASK,
    ENET_RETRY_LIMIT_INTERRUPT      = ENET_EIR_RL_MASK,
    ENET_UNDERRUN_INTERRUPT         = ENET_EIR_UN_MASK,
    ENET_PAYLOAD_RX_INTERRUPT       = ENET_EIR_PLR_MASK,
    ENET_WAKEUP_INTERRUPT           = ENET_EIR_WAKEUP_MASK,
    ENET_TS_AVAIL_INTERRUPT         = ENET_EIR_TS_AVAIL_MASK,
    ENET_TS_TIMER_INTERRUPT         = ENET_EIR_TS_TIMER_MASK,
} Enet_Ip_InterruptType;
/** @endcond */

/*!
 * @brief Event specifier for the callback function
 * @implements  Enet_Ip_EventType_structure
 */
typedef enum
{
    ENET_ERR_EVENT,        
    ENET_WAKE_UP_EVENT
} Enet_Ip_EventType;

/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief Special receive control configurations.
 * @implements  Enet_Ip_RxSpecialConfigType_structure
 */
typedef enum
{
    ENET_RX_CONFIG_ENABLE_PAYLOAD_LEN_CHECK  = ENET_RCR_NLC_MASK,
    ENET_RX_CONFIG_STRIP_CRC_FIELD           = ENET_RCR_CRCFWD_MASK,
    ENET_RX_CONFIG_FORWARD_PAUSE_FRAMES      = ENET_RCR_PAUFWD_MASK,
    ENET_RX_CONFIG_REMOVE_PADDING            = ENET_RCR_PADEN_MASK,
    ENET_RX_CONFIG_ENABLE_FLOW_CONTROL       = ENET_RCR_FCE_MASK,
    ENET_RX_CONFIG_REJECT_BROADCAST_FRAMES   = ENET_RCR_BC_REJ_MASK,
    ENET_RX_CONFIG_ENABLE_PROMISCUOUS_MODE   = ENET_RCR_PROM_MASK,
    ENET_RX_CONFIG_ENABLE_MII_LOOPBACK       = ENET_RCR_LOOP_MASK
} Enet_Ip_RxSpecialConfigType;
/** @endcond */

/*!
 * @brief Special transmit control configurations
 * @implements  Enet_Ip_TxSpecialConfigType_structure
 */
typedef enum
{
    ENET_TX_CONFIG_DISABLE_CRC_APPEND           = ENET_TCR_CRCFWD_MASK,
    ENET_TX_CONFIG_ENABLE_MAC_ADDR_INSERTION    = ENET_TCR_ADDINS_MASK
} Enet_Ip_TxSpecialConfigType;

/*!
 * @brief Transmit accelerator configurations
 * @implements  Enet_Ip_TxAcceleratorType_structure
 */
typedef enum
{
    ENET_TX_ACCEL_ENABLE_SHIFT16        = ENET_TACC_SHIFT16_MASK,
    ENET_TX_ACCEL_INSERT_IP_CHECKSUM    = ENET_TACC_IPCHK_MASK,
    ENET_TX_ACCEL_INSERT_PROTO_CHECKSUM = ENET_TACC_PROCHK_MASK
} Enet_Ip_TxAcceleratorType;

/*!
 * @brief Receive accelerator configurations
 * @implements  Enet_Ip_RxAcceleratorType_structure
 */
typedef enum
{
    ENET_RX_ACCEL_REMOVE_PAD         = ENET_RACC_PADREM_MASK,
    ENET_RX_ACCEL_ENABLE_IP_CHECK    = ENET_RACC_IPDIS_MASK,
    ENET_RX_ACCEL_ENABLE_PROTO_CHECK = ENET_RACC_PRODIS_MASK,
    ENET_RX_ACCEL_ENABLE_MAC_CHECK   = ENET_RACC_LINEDIS_MASK,
    ENET_RX_ACCEL_ENABLE_SHIFT16     = ENET_RACC_SHIFT16_MASK
} Enet_Ip_RxAcceleratorType;

/*!
 * @brief Callback function invoked when a general event is encountered
 */
typedef void (*Enet_Ip_CallbackType)(uint8 Instance, Enet_Ip_EventType Event);

/*!
 * @brief Callback function invoked when a channel event is encountered
 */
typedef void (*Enet_Ip_ChCallbackType)(uint8 Instance, uint8 Ring);

/*!
 * @brief Callback function invoked when a timer event is encountered. The channels parameter
 * represents a mask of the channels on which an event occurred.
 *
 * Implements : Enet_Ip_TimerCallbackType_class
 */
typedef void (*Enet_Ip_TimerCallbackType)(uint8 Instance);

/** @endcond */

/*!
 * @brief Statistics counters enumeration
 * @implements  Enet_Ip_CounterType_structure
 */
typedef enum
{
    ENET_CTR_RMON_T_DROP = 0U,
    ENET_CTR_RMON_T_PACKETS,
    ENET_CTR_RMON_T_BC_PKT,
    ENET_CTR_RMON_T_MC_PKT,
    ENET_CTR_RMON_T_CRC_ALIGN,
    ENET_CTR_RMON_T_UNDERSIZE,
    ENET_CTR_RMON_T_OVERSIZE,
    ENET_CTR_RMON_T_FRAG,
    ENET_CTR_RMON_T_JAB,
    ENET_CTR_RMON_T_COL,
    ENET_CTR_RMON_T_P64,
    ENET_CTR_RMON_T_P65TO127,
    ENET_CTR_RMON_T_P128TO255,
    ENET_CTR_RMON_T_P256TO511,
    ENET_CTR_RMON_T_P512TO1023,
    ENET_CTR_RMON_T_P1024TO2047,
    ENET_CTR_RMON_T_P_GTE2048,
    ENET_CTR_RMON_T_OCTETS,
    ENET_CTR_IEEE_T_DROP,
    ENET_CTR_IEEE_T_FRAME_OK,
    ENET_CTR_IEEE_T_1COL,
    ENET_CTR_IEEE_T_MCOL,
    ENET_CTR_IEEE_T_DEF,
    ENET_CTR_IEEE_T_LCOL,
    ENET_CTR_IEEE_T_EXCOL,
    ENET_CTR_IEEE_T_MACERR,
    ENET_CTR_IEEE_T_CSERR,
    ENET_CTR_IEEE_T_SQE,
    ENET_CTR_IEEE_T_FDXFC,
    ENET_CTR_IEEE_T_OCTETS_OK = 29U,
    ENET_CTR_RMON_R_PACKETS = 33U,
    ENET_CTR_RMON_R_BC_PKT,
    ENET_CTR_RMON_R_MC_PKT,
    ENET_CTR_RMON_R_CRC_ALIGN,
    ENET_CTR_RMON_R_UNDERSIZE,
    ENET_CTR_RMON_R_OVERSIZE,
    ENET_CTR_RMON_R_FRAG,
    ENET_CTR_RMON_R_JAB,
    ENET_CTR_RMON_R_RESVD_0,
    ENET_CTR_RMON_R_P64,
    ENET_CTR_RMON_R_P65TO127,
    ENET_CTR_RMON_R_P128TO255,
    ENET_CTR_RMON_R_P256TO511,
    ENET_CTR_RMON_R_P512TO1023,
    ENET_CTR_RMON_R_P1024TO2047,
    ENET_CTR_RMON_R_P_GTE2048,
    ENET_CTR_RMON_R_OCTETS,
    ENET_CTR_IEEE_R_DROP,
    ENET_CTR_IEEE_R_FRAME_OK,
    ENET_CTR_IEEE_R_CRC,
    ENET_CTR_IEEE_R_ALIGN,
    ENET_CTR_IEEE_R_MACERR,
    ENET_CTR_IEEE_R_FDXFC,
    ENET_CTR_IEEE_R_OCTETS_OK, 
    ENET_CTR_NUMBER_OF_COUNTERS
} Enet_Ip_CounterType;

/*!
 * @brief Media Independent Interface speed selection
 * @implements  Enet_Ip_MiiSpeedType_structure
 */
typedef enum
{
    ENET_MII_SPEED_10M = 0U,  /*!< Speed 10 Mbps. */
    ENET_MII_SPEED_100M       /*!< Speed 100 Mbps. */
} Enet_Ip_MiiSpeedType;

/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief Media Independent Interface mode selection
 * @implements  Enet_Ip_MiiModeType_structure
 */
typedef enum
{
    ENET_MII_MODE = 0U,      /*!< MII mode for data interface. */
    ENET_RMII_MODE = 1U     /*!< RMII mode for data interface. */
} Enet_Ip_MiiModeType;

/*!
 * @brief Media Independent Interface full-/half-duplex selection
 * @implements  Enet_Ip_DuplexType_structure
 */
typedef enum
{
    ENET_MII_HALF_DUPLEX = 0U, /*!< Half-duplex mode. */
    ENET_MII_FULL_DUPLEX       /*!< Full-duplex mode. */
} Enet_Ip_DuplexType;
/** @endcond */

/*!
 * @brief Controller power state indication
 * @implements  Enet_Ip_PowerStateType_structure
 */
typedef enum
{
    ENET_PSTATE_INACTIVE = 0U,  /*!<  Controller is powered on and Transmitter/Receiver are disabled */
    ENET_PSTATE_ACTIVE   = 1U,  /*!<  Controller is powered on and Transmitter/Receiver are enabled */
    ENET_PSTATE_SLEEP    = 2U,  /*!<  Controller is sleeping (WoL or LPI) and waiting for wake-up packet */
    ENET_PSTATE_RESET    = 3U   /*!<  Controller is resetting its internal logic and registers */
} Enet_Ip_PowerStateType;

/*!
 * @brief Send/Receive buffer information for the user
 * @implements  Enet_Ip_BufferType_structure
 */
typedef struct
{
    uint8 *Data;
    uint16 Length;
} Enet_Ip_BufferType;

/*!
 * @brief Send/Receive internal buffer descriptor
 * @implements  Enet_Ip_BufferDescriptorType_structure
 */
typedef struct
{
    uint16 Length;        /*!< Buffer descriptor data length. */
    uint16 Control;       /*!< Buffer descriptor control and status. */
    uint8 *Buffer;        /*!< Data buffer pointer. */
    uint32 Enh1;          /*!< First word of the extended part of the buffer descriptor. */
    uint32 Enh2;          /*!< Second word of the extended part of the buffer descriptor. */
    uint32 Enh3;          /*!< Third word of the extended part of the buffer descriptor. */
    uint32 TimeStamp;     /*!< TimeStamp of the frame. */
    uint32 Reserved1;     /*!< Reserved. */
    uint32 Reserved2;     /*!< Reserved. */
} Enet_Ip_BufferDescriptorType;

/*!
 * @brief Specialization of ring configuration for Tx Rings
 * @implements  Enet_Ip_BufferConfigType_structure
 */
typedef struct Enet_Ip_BufferConfigType
{
    Enet_Ip_BufferDescriptorType *RingDesc; /*!< Buffer descriptor ring start address. */
    Enet_Ip_ChCallbackType Callback;        /*!< Callback function for current channel. */
    uint8 *Buffer;                          /*!< Buffer data pool start address */
    uint32 Interrupts;                      /*!< Channel interrupt sources. A logical OR of "Enet_Ip_InterruptType". */
    uint16 BufferLen;                       /*!< Length of each individual buffer in a pool */
    uint16 RingSize;                        /*!< Buffer descriptors number. */
} Enet_Ip_BufferConfigType;

/*!
 * @brief Defines the ENET module configuration structure
 * @implements  Enet_Ip_ConfigType_structure
 */
typedef struct Enet_Ip_ConfigType
{
    uint8 RxRingCount;                          /*!< The number of Receive rings to be used by the driver. */
    uint8 TxRingCount;                          /*!< The number of Transmit rings to be used by the driver. */
    Enet_Ip_TimerCallbackType TimerCallback;    /*!< Callback to be invoked when a timer event occurs. */
    uint32 Interrupts;                          /*!< MAC interrupt source. A logical OR of "Enet_Ip_InterruptType". */
    Enet_Ip_CallbackType Callback;              /*!< Callback function */
    uint16 MaxFameLen;                          /*!< Maximum frame length. */
    Enet_Ip_MiiModeType MiiMode;                /*!< MII mode. */
    Enet_Ip_MiiSpeedType MiiSpeed;              /*!< MII Speed. */
    Enet_Ip_DuplexType MiiDuplex;               /*!< MII duplex. */
    uint32 RxConfig;                            /*!< MAC receive special configuration. A logical OR of "Enet_Ip_RxSpecialConfigType". */
    uint32 TxConfig;                            /*!< MAC transmit special configuration. A logical OR of "Enet_Ip_TxSpecialConfigType". */
    uint8 RxAccelerConfig;                      /*!< Receive accelerator, A logical OR of "Enet_Ip_RxAcceleratorType". */
    uint8 TxAccelerConfig;                      /*!< Transmit accelerator, A logical OR of "Enet_Ip_TxAcceleratorType". */
    boolean EnableCtrl;                         /*!< Configures whether the controller is enabled at initialization. */
} Enet_Ip_ConfigType;

/*!
 * @brief Internal driver state structure
 * @implements  Enet_Ip_StateType_structure
 */
typedef struct Enet_Ip_StateType
{
    Enet_Ip_CallbackType Callback;                                              /*!< Callback function for general interrupts. */
    Enet_Ip_ChCallbackType RxChCallback[FEATURE_ENET_NUM_RINGS];                /*!< Callback function for receive channels. */
    Enet_Ip_ChCallbackType TxChCallback[FEATURE_ENET_NUM_RINGS];                /*!< Callback function for transmit channels. */
    Enet_Ip_TimerCallbackType TimerCallback;                                    /*!< Timer callback function. */
    Enet_Ip_BufferDescriptorType *RxBdBase[FEATURE_ENET_NUM_RINGS];             /*!< Receive buffer descriptor base address pointer array. */
    Enet_Ip_BufferDescriptorType *RxCurrentDesc[FEATURE_ENET_NUM_RINGS];        /*!< The current available receive buffer descriptor pointer array. */
    Enet_Ip_BufferDescriptorType *RxBdAlloc[FEATURE_ENET_NUM_RINGS];            /*!< Pointer array used for enqueuing Rx buffers provided using ENET_DRV_ProvideRxBuff. */
    Enet_Ip_BufferDescriptorType *TxBdBase[FEATURE_ENET_NUM_RINGS];             /*!< Transmit buffer descriptor base address pointer array. */
    Enet_Ip_BufferDescriptorType *TxCurrentDesc[FEATURE_ENET_NUM_RINGS];        /*!< The current available provided buffer descriptor pointer array. */
    Enet_Ip_BufferDescriptorType *TxTransmitDesc[FEATURE_ENET_NUM_RINGS];       /*!< The current available transmit buffer descriptor pointer array. */
    uint8 *TxDataBuffer[FEATURE_ENET_NUM_RINGS];                                /*!< Transmit data buffer base address pointer array. */
    uint8 *RxDataBuffer[FEATURE_ENET_NUM_RINGS];                                /*!< Receive data buffer base address pointer array. */
    uint16 RxBuffNums[FEATURE_ENET_NUM_RINGS];                                  /*!< Number of Rx buffers in ring */
    uint16 TxBuffNums[FEATURE_ENET_NUM_RINGS];                                  /*!< Number of Tx buffers in ring */
    uint16 RxBuffLen[FEATURE_ENET_NUM_RINGS];                                   /*!< Rx Length of buffer */
    uint16 TxBuffLen[FEATURE_ENET_NUM_RINGS];                                   /*!< Tx Length of buffer */
    uint8 RxRingCount;                                                          /*!< The number of rings used by the driver. */
    uint8 TxRingCount;                                                          /*!< The number of rings used by the driver. */
} Enet_Ip_StateType;

/*!
 * @brief System time correction offset.
 * @implements Enet_Ip_SysTimeCorrOffsetType_structure
 */
typedef enum
{
    ENET_SYS_TIME_CORR_POSITIVE = 0U,  /*!< Correction value is added to the system time. */
    ENET_SYS_TIME_CORR_NEGATIVE = 1U,  /*!< Correction value is subtracted from the system time. */
} Enet_Ip_SysTimeCorrOffsetType;

/*!
 * @brief Defines the TimeStamp
 * @implements Enet_Ip_TimeStampType_structure
 */
typedef struct
{
    uint32 nanoseconds;  /*!< Nanoseconds part of the time. */
    uint32 seconds;      /*!< The 32 least significant bits of the 48 bits seconds part of the time. */
    uint16 secondsHi;    /*!< The 16 most significant bits of the 48 bit seconds part of the time. */
} Enet_Ip_TimeStampType;

/*!
 * @brief Enhanced information related to a receive buffer descriptor
 * @implements  Enet_Ip_RxInfoType_structure
 */
typedef struct {
    uint32 ErrMask;                     /*!< Mask of ENET_RX_ENH_ERR_*, representing the errors that occurred. */
    uint16 Checksum;                    /*!< One's complement sum of the payload section of the IP frame. */
    uint8 VlanPrio;                     /*!< Frame priority level. Valid values are from 0 (best effort) to 7 (highest). */
    uint8 HeaderLen;                    /*!< Number of 32-bit words found within the IP and its following protocol headers. */
    uint16 PktLen;                      /*!< Byte length of the received packet that was transferred to system memory (including CRC). */
    uint8 Proto;                        /*!< The 8-bit protocol field found within the IP header of the frame. */
    boolean Unicast;                    /*!< Indicates that the frame is an unicast frame. */
    boolean Ipv6;                       /*!< Indicates that the frame is an IPv6 frame. */
    boolean Ipv4Frag;                   /*!< Indicates that the frame is an IPv4 fragment frame. */
    Enet_Ip_TimeStampType TimeStamp;    /*!< TimeStamp of the received frame. */
} Enet_Ip_RxInfoType;

/*!
 * @brief Enhanced information related to a transmit buffer descriptor
 * @implements  Enet_Ip_TxInfoType_structure
 */
typedef struct {
    uint32 ErrMask;                     /*!< Mask of ENET_TX_ENH_ERR_*, representing the errors that occurred. */
    Enet_Ip_TimeStampType TimeStamp;    /*!< TimeStamp of the transmitted frame. */
} Enet_Ip_TxInfoType;

/*!
 * @brief Configuration of the adjustable timer.
 * @implements  Enet_Ip_TimerConfigType_structure
 */
typedef struct {
    uint32 TimerPeriod;                         /*!< When the timer reaches this value, the period event occurs and the timer restarts. */
    uint8  TimerInc;                            /*!< The timer increments by this amount each clock cycle. */
    uint32 CorrectionPeriod;                    /*!< Defines after how many timer clock cycles the correction counter should be reset and
                                                        triggers a correction increment on the timer.*/
    uint8  CorrectionInc;                       /*!< This value is added every time the correction timer expires. */
} Enet_Ip_TimerConfigType;

/*!
 * @brief Timer channels configuration modes.
 * @implements  Enet_Ip_TimerChannelModeType_structure
 */
typedef enum {
#if FEATURE_ENET_HAS_INPUT_CAPTURE
    ENET_TIMER_IC_RISING_EDGE = 1U,               /*!< Timer Channel is configured for Input Capture on rising edge. */
    ENET_TIMER_IC_FALLING_EDGE = 2U,              /*!< Timer Channel is configured for Input Capture on falling edge. */
    ENET_TIMER_IC_BOTH_EDGES = 3U,                /*!< Timer Channel is configured for Input Capture on both edges. */
#endif
    ENET_TIMER_OC_SOFTWARE = 4U                  /*!< Timer Channel is configured for Output Compare - software only. */
#if FEATURE_ENET_HAS_INPUT_CAPTURE
    ,ENET_TIMER_OC_TOGGLE_ON_COMP = 5U,            /*!< Timer Channel is configured for Output Compare - toggle output on compare. */
    ENET_TIMER_OC_CLEAR_ON_COMP = 6U,             /*!< Timer Channel is configured for Output Compare - clear output on compare. */
    ENET_TIMER_OC_SET_ON_COMP = 7U,               /*!< Timer Channel is configured for Output Compare - set output on compare. */
    ENET_TIMER_OC_CLEAR_ON_COMP_SET_ON_OVF = 10U, /*!< Timer Channel is configured for Output Compare - clear output on compare,
                                                       set output on overflow. */
    ENET_TIMER_OC_SET_ON_COMP_CLEAR_ON_OVF = 11U, /*!< Timer Channel is configured for Output Compare - set output on compare,
                                                       clear output on overflow. */
    ENET_TIMER_OC_PULSE_LOW_ON_COMP = 14U,        /*!< Timer Channel is configured for Output Compare - pulse output low on compare. */
    ENET_TIMER_OC_PULSE_HIGH_ON_COMP = 15U        /*!< Timer Channel is configured for Output Compare - pulse output high on compare. */
#endif
} Enet_Ip_TimerChannelModeType;

/*!
 * @brief Configuration structure of the timer channels.
 * @implements  Enet_Ip_TimerChannelConfigType_structure
 */
typedef struct {
    Enet_Ip_TimerChannelModeType Mode; /*!< The mode in which the timer channel shall be configured. */
    boolean IrqEnable;                 /*!< Enable timer interrupt for this channel. Note:  When enabling a channel interrupt,
                                         the timer interrupt must also be enabled. */
    boolean DmaEnable;                 /*!< Enable DMA request for this channel. */
} Enet_Ip_TimerChannelConfigType;


/*!
 * @brief Checksum insertion control
 * @implements  Enet_Ip_ChecksumInsControlType_structure
 */
typedef enum
{
    ENET_CHECKSUM_INSERTION_DISABLE          = 0U,      /*!< Checksum insertion is disabled. */
    ENET_CHECKSUM_INSERTION_IP               = 1U,      /*!< IP header checksum calculation and insertion are enabled. */
    ENET_CHECKSUM_INSERTION_PROTO            = 2U,      /*!< Insert protocol specific checksum. */
    ENET_CHECKSUM_INSERTION_IP_PROTO         = 3U       /*!< Both Ip header and protocol are enabled */
} Enet_Ip_ChecksumInsControlType;

/*!
 * @brief Management Frame operation type
 */
typedef enum
{
    ENET_MMFR_OP_ADDR = 0U,
    ENET_MMFR_OP_WRITE,
    ENET_MMFR_OP_READ,
    ENET_MMFR_OP_READ_45
} Enet_Ip_MmfrOpType;

/*!
 * @brief Transmit options for a particular frame.
 * @implements  Enet_Ip_TxOptionsType_structure
 */
typedef struct {
    boolean NoCRC;                                      /*!< Do not append CRC. It will be provided by the application. */
    boolean NoInt;                                      /*!< Do not generate a transmit interrupt. */
    Enet_Ip_ChecksumInsControlType ChecksumIns;         /*!< Controls the IP checksum insertion for Tx packet. */
} Enet_Ip_TxOptionsType;

/*!
 * @brief Available FIFO threshold levels.
 * @implements  Enet_Ip_FifoThresholdType_structure
 */
typedef enum {
    ENET_RX_SECTION_FULL = 0U, /*!< Value, in 64-bit words, of the receive FIFO section full threshold. When the FIFO
                                    level reaches the value in this field, data is available in the Receive FIFO. */
    ENET_RX_SECTION_EMPTY,     /*!< Value, in 64-bit words, of the receive FIFO section empty threshold. When the FIFO
                                    has reached this level, a pause frame will be issued. */
    ENET_RX_ALMOST_EMPTY,      /*!< Value, in 64-bit words, of the receive FIFO almost empty threshold. When the FIFO
                                    level reaches this level and the end-of-frame has not been received for the frame
                                    yet, the core receive read control stops FIFO read. A minimum value of 4 should be
                                    set. */
    ENET_RX_ALMOST_FULL,       /*!< Value, in 64-bit words, of the receive FIFO almost full threshold. When the FIFO level
                                    comes close to the maximum, so that there is no more space for at least RX_ALMOST_FULL
                                    number of words, the MAC stops writing data in the FIFO and truncates the received frame
                                    to avoid FIFO overflow. A minimum value of 4 should be set. */
    ENET_TX_SECTION_EMPTY,     /*!< Value, in 64-bit words, of the transmit FIFO section empty threshold. When the FIFO level
                                    reaches this value, a MAC status signal indicates that the transmit FIFO is getting full.
                                    This gives the ENET module an indication to slow or stop its write transaction to avoid a
                                    buffer overflow. */
    ENET_TX_ALMOST_EMPTY,      /*!< Value, in 64-bit words, of the transmit FIFO almost empty threshold. When the FIFO level
                                    reaches this level and no end-of-frame is available for the frame, the MAC transmit logic,
                                    to avoid FIFO underflow, stops reading the FIFO and transmits a frame with an MII error
                                    indication. */
    ENET_TX_ALMOST_FULL        /*!< Value, in 64-bit words, of the transmit FIFO almost full threshold. A minimum value of six
                                    is required. When the FIFO level comes close to the maximum, so that there is no more space
                                    for at least TX_ALMOST_FULL number of words, the FIFO write control logic, to avoid FIFO overflow,
                                    truncates the current frame and sets the error status. As a result, the frame will be transmitted
                                    with an GMII/MII error indication. */
} Enet_Ip_FifoThresholdType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ENET_IP_TYPES_H */
