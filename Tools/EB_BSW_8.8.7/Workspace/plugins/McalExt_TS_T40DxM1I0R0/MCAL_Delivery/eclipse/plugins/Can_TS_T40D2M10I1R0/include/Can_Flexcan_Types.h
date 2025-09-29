/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
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
/*==================================================================================================
==================================================================================================*/

#ifndef CAN_FLEXCAN_TYPES_H
#define CAN_FLEXCAN_TYPES_H

/**
*   @file    Can_Flexcan_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Main header file - can include different IPV models.
*
*   @addtogroup CAN_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
*
* @section Can_Flexcan_Types_h_REF_1
* Violates MISRA 2012 Advisory Rule 2.5, A project should not contain unused macro declarations.
* Declaration is reserved for future feature.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_GeneralTypes.h"
#include "Can_Ipw_Types.h"
#include "Can_Cfg.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
*
*/
#define CAN_FLEXCAN_TYPES_VENDOR_ID_H                    43
/* @violates @ref Can_Flexcan_Types_h_REF_1 MISRA 2012 Advisory Rule 2.5 */
#define CAN_FLEXCAN_TYPES_MODULE_ID_H                    80
#define CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H     4
#define CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H     4
#define CAN_FLEXCAN_TYPES_AR_RELEASE_REVISION_VERSION_H  0
#define CAN_FLEXCAN_TYPES_SW_MAJOR_VERSION_H             1
#define CAN_FLEXCAN_TYPES_SW_MINOR_VERSION_H             0
#define CAN_FLEXCAN_TYPES_SW_PATCH_VERSION_H             1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can_Cfg.h are of the same vendor */
#if (CAN_FLEXCAN_TYPES_VENDOR_ID_H != CAN_VENDOR_ID_CFG_H)
    #error "Can_Flexcan_Types.h and Can_Cfg.h have different vendor ids"
#endif
/* Check if current file and Can_Cfg.h are of the same Autosar version */
#if ((CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H    != CAN_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H    != CAN_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (CAN_FLEXCAN_TYPES_AR_RELEASE_REVISION_VERSION_H != CAN_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Can_Flexcan_Types.h and Can_Cfg.h are different"
#endif
/* Check if current file and Can_Cfg.h are of the same Software version */
#if ((CAN_FLEXCAN_TYPES_SW_MAJOR_VERSION_H != CAN_SW_MAJOR_VERSION_CFG_H) || \
     (CAN_FLEXCAN_TYPES_SW_MINOR_VERSION_H != CAN_SW_MINOR_VERSION_CFG_H) || \
     (CAN_FLEXCAN_TYPES_SW_PATCH_VERSION_H != CAN_SW_PATCH_VERSION_CFG_H) \
    )
    #error "Software Version Numbers of Can_Flexcan_Types.h and Can_Cfg.h are different"
#endif

/* Check if current file and Can_Ipw_Types.h are of the same vendor */
#if (CAN_FLEXCAN_TYPES_VENDOR_ID_H != CAN_IPW_TYPES_VENDOR_ID_H)
    #error "Can_Flexcan_Types.h and Can_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and Can_Ipw_Types.h are of the same Autosar version */
#if ((CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H    != CAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H    != CAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_FLEXCAN_TYPES_AR_RELEASE_REVISION_VERSION_H != CAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Flexcan_Types.h and Can_Ipw_Types.h are different"
#endif
/* Check if current file and Can_Ipw_Types.h are of the same Software version */
#if ((CAN_FLEXCAN_TYPES_SW_MAJOR_VERSION_H != CAN_IPW_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_FLEXCAN_TYPES_SW_MINOR_VERSION_H != CAN_IPW_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_FLEXCAN_TYPES_SW_PATCH_VERSION_H != CAN_IPW_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Flexcan_Types.h and Can_Ipw_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of Can_Flexcan_Types.h and Mcal.h are different"
    #endif
    #if ((CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H != CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H != CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of Can_Flexcan_Types.h and Can_GeneralTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    /*
    *                 Development errors.
    *                 (CAN104) The Can module shall be able to detect the following errors and exceptions depending on its configuration (development/production).
    *                 (CAN026) Development Errors shall indicate errors that are caused by erroneous usage of the Can module API. This covers API
    *                 parameter checks and call sequence errors.
    *                 (CAN080) Development error values are of type uint8.
    */

    /*! @brief Development Error ID for "API Service called with wrong parameter" */
    #define CAN_E_PARAM_POINTER         ((uint8)0x01U)
    /*! @brief Development Error ID for "API Service called with wrong parameter" */
    #define CAN_E_PARAM_HANDLE          ((uint8)0x02U)
    /*! @brief Development Error ID for "API Service called with wrong parameter" */
    #define CAN_E_PARAM_DATA_LENGTH     ((uint8)0x03U)
    /*! @brief Development Error ID for "API Service called with wrong parameter" */
    #define CAN_E_PARAM_CONTROLLER      ((uint8)0x04U)
    /*! @brief Development Error ID for "API Service used without initialization" */
    #define CAN_E_UNINIT                ((uint8)0x05U)
    /*! @brief Development Error ID for "Invalid transition for the current mode" */
    #define CAN_E_TRANSITION            ((uint8)0x06U)
    #if (CAN_SET_BAUDRATE_API == STD_ON)
        /*! @brief Development Error ID for "Parameter Baudrate has an invalid value" */
        #define CAN_E_PARAM_BAUDRATE        ((uint8)0x07U)
    #endif
    /* @violates @ref Can_Flexcan_Types_h_REF_1 MISRA 2012 Advisory Rule 2.5 */
    #define CAN_E_ICOM_CONFIG_INVALID   ((uint8)0x08U)
    /*! @brief Development Error ID for "Invalid configuration set selection" */
    #define CAN_E_INIT_FAILED           ((uint8)0x09U)
    #if (CAN_MULTICORE_ENABLED == STD_ON)
    /*! @brief Development Error ID for "Requested resource is not available on the current core" */
    #define CAN_E_PARAM_CONFIG          ((uint8)0x0AU)
    #endif /* (CAN_MULTICORE_ENABLED == STD_ON) */
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
/*! @brief Runtime Error ID for "Received CAN message is lost" */
#define CAN_E_DATALOST              ((uint8)0x01U)

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    /*
    *           Service ID (APIs) for Det reporting
    *           Service ID (APIs) for Det reporting
    *
    */
    /*! @brief Service ID of Can_Init */
    #define CAN_SID_INIT                                ((uint8)0x00U)
    /* @violates @ref Can_Flexcan_Types_h_REF_1 MISRA 2012 Advisory Rule 2.5 */
    /*! @brief Service ID of Can_MainFunction_Write */
    #define CAN_SID_MAIN_FUNCTION_WRITE                 ((uint8)0x01U)
    /*! @brief Service ID of Can_SetControllerMode */
    #define CAN_SID_SET_CONTROLLER_MODE                 ((uint8)0x03U)
    /*! @brief Service ID of Can_DisableControllerInterrupts */
    #define CAN_SID_DISABLE_CONTROLLER_INTERRUPTS       ((uint8)0x04U)
    /*! @brief Service ID of Can_EnableControllerInterrupts */
    #define CAN_SID_ENABLE_CONTROLLER_INTERRUPTS        ((uint8)0x05U)
    /*! @brief Service ID of Can_Write */
    #define CAN_SID_WRITE                               ((uint8)0x06U)
    #if (CAN_VERSION_INFO_API == STD_ON)
        /*! @brief Service ID of Can_GetVersionInfo */
        #define CAN_SID_GET_VERSION_INFO                    ((uint8)0x07U)
    #endif
    /* @violates @ref Can_Flexcan_Types_h_REF_1 MISRA 2012 Advisory Rule 2.5 */
    /*! @brief Service ID of Can_MainFunction_BusOff */
    #define CAN_SID_MAIN_FUNCTION_BUS_OFF               ((uint8)0x09U)
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
        #define CAN_SID_MAIN_FUNCTION_WAKEUP                ((uint8)0x0AU)
    #endif
    #if (CAN_CHECK_WAKEUP_API == STD_ON)
        #define CAN_SID_CHECK_WAKEUP                        ((uint8)0x0BU)
    #endif
    /* @violates @ref Can_Flexcan_Types_h_REF_1 MISRA 2012 Advisory Rule 2.5 */
    /*! @brief Service ID of Can_MainFunction_Mode */
    #define CAN_SID_MAIN_FUNCTION_MODE                  ((uint8)0x0CU)
    #if (CAN_SET_BAUDRATE_API == STD_ON)
        /*! @brief Service ID of Can_SetBaudrate */
        #define CAN_SID_SET_BAUDRATE                        ((uint8)0x0FU)
    #endif
    /*! @brief Service ID of Can_DeInit */
    #define CAN_SID_DEINIT                              ((uint8)0x10U)
    /*! @brief Service ID of Can_GetControllerErrorState */
    #define CAN_SID_GET_CONTROLLER_ERROR_STATE          ((uint8)0x11U)
    /*! @brief Service ID of Can_GetControllerMode */
    #define CAN_SID_GET_CONTROLLER_MODE                 ((uint8)0x12U)
    #if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
        #define CAN_SID_SET_ICOM_CONFIG                     ((uint8)0x21U)
    #endif
    /*! @brief Service ID of Can_GetControllerRxErrorCounter */
    #define CAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER     ((uint8)0x30U)
    /*! @brief Service ID of Can_GetControllerTxErrorCounter */
    #define CAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER     ((uint8)0x31U)
    #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        /*! @brief Service ID of Can_SetClockMode */
        #define CAN_SID_SETCLOCKMODE                        ((uint8)0x13U)
    #endif
    #if (CAN_ABORT_MB_API == STD_ON)
        /*! @brief Service ID of Can_AbortMb */
        #define CAN_SID_ABORT_MB                            ((uint8)0x14U)
    #endif
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
/*! @brief Service ID of Can_MainFunction_Read */
#define CAN_SID_MAIN_FUNCTION_READ                  ((uint8)0x08U)
#if (CAN_LISTEN_ONLY_MODE == STD_ON)
#define CAN_SID_LISTEN_ONLY_MODE                        ((uint8)0x32U)
#endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */

#define CAN_FD_FRAME_U32        ((uint32)0x40000000U)
#define CAN_EXTENDED_ID_U32     ((uint32)0x80000000U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if (CAN_DUAL_CLOCK_MODE == STD_ON)
    /**
    * @brief          Can_ClockModeType
    * @details        CAN source clock selection used in Can_SetClockMode Non-Autosar API.
    *
    */
    typedef enum
    {
        CAN_CLOCKMODE_NORMAL = 0U, /**< @brief Standard configuration (Default) */
        CAN_CLOCKMODE_ALTERNATE    /**< @brief Second configuration (Alternate) */
    }Can_ClockModeType;
#endif

/** @brief Can Hardware Object Handle*/
typedef enum
{
    CAN_RECEIVE = 0,    /**< @brief Specifies the HardwareObject is used as Receive */
    CAN_TRANSMIT        /**< @brief Specifies the HardwareObject is used as Transmit */
}Can_HwObjectHandleType;

/** @brief Can Id Message */
typedef enum
{
    CAN_STANDARD = 0,   /**< @brief All the CANIDs are of type standard only (11bit). */
    CAN_EXTENDED,       /**< @brief All the CANIDs are of type extended only (29 bit) */
    CAN_MIXED           /**< @brief All the CANIDs are of type extended only (29 bit) */
}Can_IdMessageType;

/** @brief Message Buffer Type: TX, RX, RX FIFO */
typedef enum
{
    CAN_RX_NORMAL = 0,            /**< @brief Specifies the HardwareObject is used as Normal Receive Object */
    CAN_RX_LEGACY_FIFO,           /**< @brief Specifies the HardwareObject is used as Legacy FIFO Receive Object */
    CAN_RX_ENHANCED_FIFO,         /**< @brief Specifies the HardwareObject is used as Enhanced FIFO Receive Object */
    CAN_TX_NORMAL                 /**< @brief Specifies the HardwareObject is used as Normal Transmit Object */
}Can_MbType;

/** @brief Legacy FIFO ID Acceptance Mode */
typedef enum
{
    CAN_LEGACY_FIFO_FORMAT_A = 0U,  /**< @brief One full ID (standard and extended) per ID filter table element. */
    CAN_LEGACY_FIFO_FORMAT_B = 1U,  /**< @brief Two full standard IDs or two partial 14-bit (standard and extended) IDs per ID filter table element. */
    CAN_LEGACY_FIFO_FORMAT_C = 2U   /**< @brief Four partial 8-bit standard IDs per ID filter table element. */
}Can_LegacyFIFOAcceptanceModeType;

#if (CAN_TIMESTAMP_ENABLE == STD_ON)
    typedef void (*Can_TxTimestampPCallBackType)(Can_HwHandleType Hoh, uint32 CanTxPduId, uint32 u32TimestampVal);
    typedef void (*Can_RxTimestampPCallBackType)(Can_HwHandleType Hoh, uint32 u32TimestampVal);
#endif

#if (CAN_LISTEN_ONLY_MODE == STD_ON)
/** @brief Listen Only Type */
typedef enum
{
    NORMAL_MODE          = 0U,     /**< @brief Nomal mode. */
    LISTEN_ONLY_MODE     = 1U      /**< @brief Enable Listen Only mode. */
}Can_ListenOnlyType;
#endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef void (*Can_NotifyType)(void);

/** @brief Can Hardware Filter */
typedef struct
{
    const uint32 Can_u32HwFilterCode;   /**< @brief Specifies (together with the filter mask) the identifiers range that passes the hardware filter. */
    const uint32 Can_u32HwFilterMask;   /**< @brief Describes a mask for hardware-based filtering of CAN identifiers. */
}Can_HwFilterType;

/** @brief Can Hardware Object */
typedef struct
{
    /** @brief Can Hardware Object ID */
    const Can_HwHandleType Can_HwObjectID;
    /** @brief Specifies Hardware Object is used as Tansmit or as Receive Object */
    const Can_HwObjectHandleType Can_HohType;
    /** @brief Specifies the type of Message ID: STANDARD, EXTENDED, MIXED */
    const Can_IdMessageType Can_IdMessage;
    /** @brief Specifies the processing of HOH is Polling or Interrupt */
    const boolean Can_bHwObjectUsesPolling;
    /** @brief Specifies the Hw object is enable/disable Trigger Transmit */
    const boolean Can_bTriggerTransmit;
    /** @brief Number of Hardware Objects used to implement one HOH */
    const uint8 Can_u8ObjectCount;
    /** @brief Can MainFunction RW period reference */
    const uint8 Can_MainFuncPeriodIndex;
    /** @brief Specifies the Max data length of Hw Object */
    const uint8 Can_u8PayloadLength;
    /** @brief Specifies the value which is used to pad unspecified data */
    const uint8 Can_u8PaddingValue;
    /** @brief The number of Can Hw Filter Config */
    const uint8 Can_u8HwFilterCount;
    /** @brief Pointer to Hw Filter Config */
    const Can_HwFilterType * Can_pHwFilterConfig;
    /** @brief Specifies the Message Buffer is TX, RX or RX FIFO */
    const Can_MbType Can_eReceiveType;
    /** @brief Buffer Index in Message buffer ram */
    const uint8 Can_u8HwBufferIndex;
    /** @brief Pointer to Hw Buffer Address */
    const uint32 * Can_pHwBufferAddr;
     /** @brief The parameter is used to detect the MB which is use to get Timestamp or not */
#if (CAN_TIMESTAMP_ENABLE == STD_ON)
    const boolean CanTimestampEnable;
#endif
}Can_HwObjectConfigType;

/** @brief Can Bit Rate */
typedef struct
{
    /** @brief Propagation Segment */
    const uint8 Can_u8PropSeg;
    /** @brief Phase Segment 1 */
    const uint8 Can_u8PhaseSeg1;
    /** @brief Phase Segment 2 */
    const uint8 Can_u8PhaseSeg2;
    /** @brief Prescaler Devider */
    const uint16 Can_u16Prescaler;
#if (CAN_DUAL_CLOCK_MODE == STD_ON)
    /** @brief Alternative Baudrate Prescaller */
    const uint16 Can_u16PrescalerAlternate;
#endif
    /** @brief Synchronization Jump Width*/
    const uint8 Can_u8ResyncJumpWidth;
}Can_TimeSegmentType;

/** @brief Can Baudrate */
typedef struct
{
    /** @brief enhance CBT support */
    const boolean Can_bEnhanceCBTEnable;
    /** @brief Tx Bit Rate Switch */
    const boolean Can_bBitRateSwitch;
    /** @brief Can FD support */
    const boolean Can_bFDFrame;
    /** @brief Nominal Bit Rate */
    const Can_TimeSegmentType Can_NominalBitRate;
    /** @brief Data Bit Rate (using when support FD and Bit Rate Swith is set) */
    const Can_TimeSegmentType Can_DataBitRate;
    /** @brief Specifies the Transmission Arbitration start delay */
    const uint8 Can_u8TxArbitrationStartDelay;
    /** @brief Transmiter Delay Compensation Enable */
    const boolean Can_bTrcvDelayEnable;
    /** @brief Specifies the Transmiter Delay Compensation Offset */
    const uint8 Can_u8TrcvDelayCompOffset;
}Can_BaudrateConfigType;

/** @brief Can Controller */
typedef struct
{
    /** @brief Abstracted CanIf Controller ID */
    const uint8 Can_u8AbstControllerID;
    /** @brief Controller ID */
    const uint8 Can_u8ControllerID;
    /** @brief Controller Offset */
    const uint8 Can_u8ControllerOffset;
    /** @brief Controller Base Address */
    const uint32 Can_u32BaseAddress;
    /** @brief Define Controller is used in Config */
    const boolean Can_bActivation;
    /** @brief Bus Off uses Polling */
    const boolean Can_bBusOffUsesPolling;
    /** @brief Specifies the Global mask of Legacy FIFO */
    const uint32 Can_u32LegacyGlobalMask;
    /** @brief ID Acceptance Mode */
    const Can_LegacyFIFOAcceptanceModeType Can_eLegacyAcceptanceMode;
    /** @brief Legacy FIFO Warning Notification */
    const Can_NotifyType Can_pLegacyFiFoWarnNotif;
    /** @brief Legacy FIFO Overflow Notification */
    const Can_NotifyType Can_pLegacyFiFoOvfNotif;
    /** @brief Enhance FIFO Overflow Notification */
    const Can_NotifyType Can_pEnhanceFiFoOvfNotif;
#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
    /** @brief Enhance FIFO Dma Error Notification */
    const Can_NotifyType Can_pDmaErrorNotif;
    /** @brief Pointer to DMA destination address */
    Flexcan_Ip_MsgBuffType * pDmaDstAddr;
#endif
    /** @brief Error Interrupt enable */
    const boolean bErrEn;
    /** @brief Error Notification */
    const Can_NotifyType Can_pErrNotif;
    /** @brief Error FD Notification */
    const Can_NotifyType Can_pFDErrNotif;
    /** @brief Default Baudrate ID */
    const uint16 Can_u16DefaultBaudrateID;
     /** @brief Number of Baurate Configured */
    const uint16 Can_u16BaudrateConfigCount;
    /** @brief Pointer to Baudrate Config */
    const Can_BaudrateConfigType * Can_pBaudrateConfig;
    /** @brief Pointer to Controller config */
    const Can_Ipw_HwChannelConfigType * HwChannelIpConfig;
    /** @brief The number of Hw Objects referred to Controller */
    const uint8 Can_u8HwObjectRefCount;
    /** @brief Pointer point to Pointer to Hw Object that refer to Controller */
    const Can_HwObjectConfigType * const * Can_ppHwObject;
#if (CAN_TIMESTAMP_ENABLE == STD_ON)
    /** @brief Pointer to TX Timestamp notification function. */
    const Can_TxTimestampPCallBackType CanTxTimestampNotification;
    /** @brief Pointer to RX Timestamp notification function. */
    const Can_RxTimestampPCallBackType CanRxTimestampNotification;
#endif
}Can_ControllerConfigType;

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
typedef struct
{
    const uint8 u8CanIcomConfigId;
    const boolean bCanIcomWakeOnBusOff;
    const uint8 u8NumberCanIcomRxMessage;
    const Can_Ipw_IcomRxMessageConfigsType * pCanIcomRxMessageConfigs;
} Can_IcomConfigsType;
#endif /* (CAN_PUBLIC_ICOM_SUPPORT == STD_ON) */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CAN_FLEXCAN_TYPES_H */
