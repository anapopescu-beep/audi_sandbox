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

/**
*   @file    Can_IPW.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Interrupt routines for Can driver.
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
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, External identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, Identifiers declared in the same scope and name space shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, Macro identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, Identifiers shall be distinct from macro names.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 14.4, the controlling expression of an if statement and the controlling expression of an iteration-statement shall have essentially Boolean type.
* SMCAL coding guideline, Rule 3.3:
* Multi-statement macros shall be wrapped in a do-while loop
* so the macro can appear safely inside if clauses or other places that expect a single statement or a statement block
*
* @section Can_Ipw_c_REF_1
* Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents
* of a header file being included more than once
* This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].)
*
* @section Can_Ipw_c_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #include directives should only be preceded by preprocessor
* directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR
*
* @section Can_Ipw_c_REF_3
*          Violates MISRA 2012 Advisory Rule 12.3, The comma operator shall not be used.
*          The comma is used  to abstract the trusted call function and to determine when the return into user mode is needed.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_Ipw_Types.h"
#include "Can_Flexcan_Types.h"
#include "Can_Ipw.h"
#include "CanIf_Can.h"
#include "CanIf.h"
#include "Det.h"
#include "Can_Externals.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Can_IPW.c
*/
#define CAN_IPW_VENDOR_ID_C                    43
#define CAN_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define CAN_IPW_AR_RELEASE_MINOR_VERSION_C     4
#define CAN_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define CAN_IPW_SW_MAJOR_VERSION_C             1
#define CAN_IPW_SW_MINOR_VERSION_C             0
#define CAN_IPW_SW_PATCH_VERSION_C             1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can_Ipw.h are of the same vendor */
#if (CAN_IPW_VENDOR_ID_C != CAN_IPW_VENDOR_ID_H)
#error "Can_IPW.c and Can_IPW.h have different vendor ids"
#endif
/* Check if current file and Can_Ipw.h are of the same Autosar version */
#if ((CAN_IPW_AR_RELEASE_MAJOR_VERSION_C    != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_IPW_AR_RELEASE_MINOR_VERSION_C    != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_IPW_AR_RELEASE_REVISION_VERSION_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H) \
    )
#error "AutoSar Version Numbers of Can_IPW.c and Can_IPW.h are different"
#endif
/* Check if current file and Can_Ipw.h are of the same software version */
#if ((CAN_IPW_SW_MAJOR_VERSION_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_IPW_SW_MINOR_VERSION_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_IPW_SW_PATCH_VERSION_C != CAN_IPW_SW_PATCH_VERSION_H) \
    )
#error "Software Version Numbers of Can_IPW.c and Can_IPW.h are different"
#endif

/* Check if current file and Can_Flexcan_Types.h are of the same vendor */
#if (CAN_IPW_VENDOR_ID_C != CAN_FLEXCAN_TYPES_VENDOR_ID_H)
#error "Can_IPW.c and Can_Flexcan_Types.h have different vendor ids"
#endif
/* Check if current file and Can_Flexcan_Types.h are of the same Autosar version */
#if ((CAN_IPW_AR_RELEASE_MAJOR_VERSION_C    != CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_IPW_AR_RELEASE_MINOR_VERSION_C    != CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_IPW_AR_RELEASE_REVISION_VERSION_C != CAN_FLEXCAN_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
#error "AutoSar Version Numbers of Can_IPW.c and Can_Flexcan_Types.h are different"
#endif
/* Check if current file and Can_Flexcan_Types.h are of the same software version */
#if ((CAN_IPW_SW_MAJOR_VERSION_C != CAN_FLEXCAN_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_IPW_SW_MINOR_VERSION_C != CAN_FLEXCAN_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_IPW_SW_PATCH_VERSION_C != CAN_FLEXCAN_TYPES_SW_PATCH_VERSION_H) \
    )
#error "Software Version Numbers of Can_IPW.c and Can_Flexcan_Types.h are different"
#endif

/* Check if current file and Can_Ipw_Types.h are of the same vendor */
#if (CAN_IPW_VENDOR_ID_C != CAN_IPW_TYPES_VENDOR_ID_H)
#error "Can_IPW.c and Can_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and Can_Ipw_Types.h are of the same Autosar version */
#if ((CAN_IPW_AR_RELEASE_MAJOR_VERSION_C    != CAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_IPW_AR_RELEASE_MINOR_VERSION_C    != CAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_IPW_AR_RELEASE_REVISION_VERSION_C != CAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
#error "AutoSar Version Numbers of Can_IPW.c and Can_Ipw_Types.h are different"
#endif
/* Check if current file and Can_Ipw_Types.h are of the same software version */
#if ((CAN_IPW_SW_MAJOR_VERSION_C != CAN_IPW_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_IPW_SW_MINOR_VERSION_C != CAN_IPW_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_IPW_SW_PATCH_VERSION_C != CAN_IPW_TYPES_SW_PATCH_VERSION_H) \
    )
#error "Software Version Numbers of Can_IPW.c and Can_Ipw_Types.h are different"
#endif

/* Check if current file and Can_Externals.h are of the same vendor */
#if (CAN_IPW_VENDOR_ID_C != CAN_EXTERNALS_VENDOR_ID_H)
#error "Can_IPW.c and Can_Externals.h have different vendor ids"
#endif
/* Check if current file and Can_Externals.h are of the same Autosar version */
#if ((CAN_IPW_AR_RELEASE_MAJOR_VERSION_C    != CAN_EXTERNALS_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_IPW_AR_RELEASE_MINOR_VERSION_C    != CAN_EXTERNALS_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_IPW_AR_RELEASE_REVISION_VERSION_C != CAN_EXTERNALS_AR_RELEASE_REVISION_VERSION_H) \
    )
#error "AutoSar Version Numbers of Can_IPW.c and Can_Externals.h are different"
#endif
/* Check if current file and Can_Externals.h are of the same software version */
#if ((CAN_IPW_SW_MAJOR_VERSION_C != CAN_EXTERNALS_SW_MAJOR_VERSION_H) || \
     (CAN_IPW_SW_MINOR_VERSION_C != CAN_EXTERNALS_SW_MINOR_VERSION_H) || \
     (CAN_IPW_SW_PATCH_VERSION_C != CAN_EXTERNALS_SW_PATCH_VERSION_H) \
    )
#error "Software Version Numbers of Can_IPW.c and Can_Externals.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and CanIf_Can.h header file are of the same version */
    #if ((CAN_IPW_AR_RELEASE_MAJOR_VERSION_C    !=  CANIF_CAN_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_IPW_AR_RELEASE_MINOR_VERSION_C     !=  CANIF_CAN_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Can_IPW.c and CanIf_Can.h are different"
    #endif
    /* Check if current file and CanIf header file are of the same version */
    #if ((CAN_IPW_AR_RELEASE_MAJOR_VERSION_C    !=  CANIF_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_IPW_AR_RELEASE_MINOR_VERSION_C     !=  CANIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Can_IPW.c and CanIf.h are different"
    #endif
    /* Check if current file and det.h header file are of the same version */
    #if ((CAN_IPW_AR_RELEASE_MAJOR_VERSION_C    !=  DET_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_IPW_AR_RELEASE_MINOR_VERSION_C     !=  DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Can_IPW.c and det.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define CAN_IPW_CS_IDE_MASK     ((uint32)0x00200000U)
#define CAN_IPW_CS_EDL_MASK     ((uint32)0x80000000U)
#define CAN_IPW_CS_CODE_MASK    ((uint32)0x0F000000U)
#define CAN_IPW_RX_FIFO_MASK_FILTER_FORMATA_EXT_SHIFT       (1U)
#define CAN_IPW_RX_FIFO_MASK_FILTER_FORMATA_STD_SHIFT       (19U)
#define CAN_IPW_RX_FIFO_MASK_FILTER_FORMATB_EXT_SHIFT1      (16U)
#define CAN_IPW_RX_FIFO_MASK_FILTER_FORMATB_EXT_SHIFT2      (0U)
#define CAN_IPW_RX_FIFO_MASK_FILTER_FORMATB_STD_SHIFT1      (19U)
#define CAN_IPW_RX_FIFO_MASK_FILTER_FORMATB_STD_SHIFT2      (3U)
#define CAN_IPW_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT     (15U)
#define CAN_IPW_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT1  (24U)
#define CAN_IPW_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT2  (16U)
#define CAN_IPW_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT3  (8U)
#define CAN_IPW_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT4  (0U)
#define CAN_IPW_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT     (3U)
#define CAN_IPW_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT     (21U)
#define CAN_IPW_RX_LEGACY_FIFO_MB_HANDLER                   (0U)
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/* CAN_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE */
#if (CAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* (CAN_NO_CACHE_NEEDED == STD_ON) */
#include "Can_MemMap.h"
/**
*   @brief      Initialize Controller
*/
#if CAN_CONTROLLER_CONFIG_COUNT == 1U
    static Flexcan_Ip_StateType Can_Ipw_xStatus0;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 1U */

#if CAN_CONTROLLER_CONFIG_COUNT == 2U
    static Flexcan_Ip_StateType Can_Ipw_xStatus0;
    static Flexcan_Ip_StateType Can_Ipw_xStatus1;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 2U */

#if CAN_CONTROLLER_CONFIG_COUNT == 3U
    static Flexcan_Ip_StateType Can_Ipw_xStatus0;
    static Flexcan_Ip_StateType Can_Ipw_xStatus1;
    static Flexcan_Ip_StateType Can_Ipw_xStatus2;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 3U */

#if CAN_CONTROLLER_CONFIG_COUNT == 4U
    static Flexcan_Ip_StateType Can_Ipw_xStatus0;
    static Flexcan_Ip_StateType Can_Ipw_xStatus1;
    static Flexcan_Ip_StateType Can_Ipw_xStatus2;
    static Flexcan_Ip_StateType Can_Ipw_xStatus3;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 4U */

#if CAN_CONTROLLER_CONFIG_COUNT == 5U
    static Flexcan_Ip_StateType Can_Ipw_xStatus0;
    static Flexcan_Ip_StateType Can_Ipw_xStatus1;
    static Flexcan_Ip_StateType Can_Ipw_xStatus2;
    static Flexcan_Ip_StateType Can_Ipw_xStatus3;
    static Flexcan_Ip_StateType Can_Ipw_xStatus4;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 5U */

#if CAN_CONTROLLER_CONFIG_COUNT == 6U
    static Flexcan_Ip_StateType Can_Ipw_xStatus0;
    static Flexcan_Ip_StateType Can_Ipw_xStatus1;
    static Flexcan_Ip_StateType Can_Ipw_xStatus2;
    static Flexcan_Ip_StateType Can_Ipw_xStatus3;
    static Flexcan_Ip_StateType Can_Ipw_xStatus4;
    static Flexcan_Ip_StateType Can_Ipw_xStatus5;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 6U */

#if CAN_CONTROLLER_CONFIG_COUNT == 7U
    static Flexcan_Ip_StateType Can_Ipw_xStatus0;
    static Flexcan_Ip_StateType Can_Ipw_xStatus1;
    static Flexcan_Ip_StateType Can_Ipw_xStatus2;
    static Flexcan_Ip_StateType Can_Ipw_xStatus3;
    static Flexcan_Ip_StateType Can_Ipw_xStatus4;
    static Flexcan_Ip_StateType Can_Ipw_xStatus5;
    static Flexcan_Ip_StateType Can_Ipw_xStatus6;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 7U */
#if CAN_CONTROLLER_CONFIG_COUNT == 8U
    static Flexcan_Ip_StateType Can_Ipw_xStatus0;
    static Flexcan_Ip_StateType Can_Ipw_xStatus1;
    static Flexcan_Ip_StateType Can_Ipw_xStatus2;
    static Flexcan_Ip_StateType Can_Ipw_xStatus3;
    static Flexcan_Ip_StateType Can_Ipw_xStatus4;
    static Flexcan_Ip_StateType Can_Ipw_xStatus5;
    static Flexcan_Ip_StateType Can_Ipw_xStatus6;
    static Flexcan_Ip_StateType Can_Ipw_xStatus7;
#endif

#if (CAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* (CAN_NO_CACHE_NEEDED == STD_ON) */
#include "Can_MemMap.h"
/* CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE */

#define CAN_START_SEC_CONST_UNSPECIFIED
#include "Can_MemMap.h"

#if CAN_CONTROLLER_CONFIG_COUNT == 1U
    static Flexcan_Ip_StateType * const Can_Ipw_apxStatus[CAN_CONTROLLER_CONFIG_COUNT] = {&Can_Ipw_xStatus0};
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 1U */

#if CAN_CONTROLLER_CONFIG_COUNT == 2U
    static Flexcan_Ip_StateType * const Can_Ipw_apxStatus[CAN_CONTROLLER_CONFIG_COUNT] = {&Can_Ipw_xStatus0, &Can_Ipw_xStatus1};
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 2U */

#if CAN_CONTROLLER_CONFIG_COUNT == 3U
    static Flexcan_Ip_StateType * const Can_Ipw_apxStatus[CAN_CONTROLLER_CONFIG_COUNT] = {&Can_Ipw_xStatus0, &Can_Ipw_xStatus1, &Can_Ipw_xStatus2};
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 3U */

#if CAN_CONTROLLER_CONFIG_COUNT == 4U
    static Flexcan_Ip_StateType * const Can_Ipw_apxStatus[CAN_CONTROLLER_CONFIG_COUNT] = {&Can_Ipw_xStatus0, &Can_Ipw_xStatus1, &Can_Ipw_xStatus2, &Can_Ipw_xStatus3};
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 4U */

#if CAN_CONTROLLER_CONFIG_COUNT == 5U
    static Flexcan_Ip_StateType * const Can_Ipw_apxStatus[CAN_CONTROLLER_CONFIG_COUNT] = {&Can_Ipw_xStatus0, &Can_Ipw_xStatus1, &Can_Ipw_xStatus2, &Can_Ipw_xStatus3, &Can_Ipw_xStatus4};
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 5U */

#if CAN_CONTROLLER_CONFIG_COUNT == 6U
    static Flexcan_Ip_StateType * const Can_Ipw_apxStatus[CAN_CONTROLLER_CONFIG_COUNT] = {&Can_Ipw_xStatus0, &Can_Ipw_xStatus1, &Can_Ipw_xStatus2, &Can_Ipw_xStatus3, &Can_Ipw_xStatus4, &Can_Ipw_xStatus5};
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 6U */

#if CAN_CONTROLLER_CONFIG_COUNT == 7U
    static Flexcan_Ip_StateType * const Can_Ipw_apxStatus[CAN_CONTROLLER_CONFIG_COUNT] = {&Can_Ipw_xStatus0, &Can_Ipw_xStatus1, &Can_Ipw_xStatus2, &Can_Ipw_xStatus3, &Can_Ipw_xStatus4, &Can_Ipw_xStatus5,
                                                                                          &Can_Ipw_xStatus6
                                                                                         };
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 7U */
#if CAN_CONTROLLER_CONFIG_COUNT == 8U
    static Flexcan_Ip_StateType * const Can_Ipw_apxStatus[CAN_CONTROLLER_CONFIG_COUNT] = {&Can_Ipw_xStatus0, &Can_Ipw_xStatus1, &Can_Ipw_xStatus2, &Can_Ipw_xStatus3, &Can_Ipw_xStatus4, &Can_Ipw_xStatus5,
                                                                                          &Can_Ipw_xStatus6, &Can_Ipw_xStatus7
                                                                                         };
#endif

#define CAN_STOP_SEC_CONST_UNSPECIFIED
#include "Can_MemMap.h"

/* CAN_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE */
#if (CAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* (CAN_NO_CACHE_NEEDED == STD_ON) */
#include "Can_MemMap.h"

#if ((CAN_TX_POLLING_SUPPORT == STD_ON) || (CAN_MB_INTERRUPT_SUPPORT == STD_ON))
    /**
    * @brief     Store the the swPduHandle that is given inside the parameter PduInfo
    */
    static PduIdType Can_Ipw_au16TxPduId[CAN_CONTROLLER_CONFIG_COUNT][CAN_HWMB_COUNT];
#endif

#if (CAN_DUAL_CLOCK_MODE == STD_ON)
    /**
    * @brief     Mode clock that controller
    */
    static Can_ClockModeType Can_Ipw_eClockMode[CAN_CONTROLLER_CONFIG_COUNT];
#endif

#if (CAN_LISTEN_ONLY_MODE == STD_ON)
    static Can_ListenOnlyType  Can_Ipw_eListenOnlyMode[CAN_CONTROLLER_CONFIG_COUNT];
#endif /* #if (CAN_LISTEN_ONLY_MODE == STD_ON) */

#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
    static Can_HwHandleType Can_Ipw_au16MbIdxToObjIDMap[CAN_CONTROLLER_CONFIG_COUNT][CAN_HWMB_COUNT];
#endif

#if (CAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* (CAN_NO_CACHE_NEEDED == STD_ON) */
#include "Can_MemMap.h"
/* CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE */

/* CAN_START_SEC_VAR_INIT_16_NO_CACHEABLE */
#if (CAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
#else
#define CAN_START_SEC_VAR_CLEARED_16
#endif /* (CAN_NO_CACHE_NEEDED == STD_ON) */
#include "Can_MemMap.h"

#if (CAN_SET_BAUDRATE_API == STD_ON)
static uint16 Can_au16ControllerBaudRateSel[CAN_CONTROLLER_CONFIG_COUNT];
#endif /* (CAN_SET_BAUDRATE_API == STD_ON) */

#if (CAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
#else
#define CAN_STOP_SEC_VAR_CLEARED_16
#endif /* (CAN_NO_CACHE_NEEDED == STD_ON) */
#include "Can_MemMap.h"
/* CAN_STOP_SEC_VAR_INIT_16_NO_CACHEABLE */


/* CAN_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE */
#if (CAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#else
#define CAN_START_SEC_VAR_CLEARED_BOOLEAN
#endif /* (CAN_NO_CACHE_NEEDED == STD_ON) */
#include "Can_MemMap.h"

static boolean Can_Ipw_abIsInterruptEnabled[CAN_CONTROLLER_CONFIG_COUNT];

#if (CAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#else
#define CAN_STOP_SEC_VAR_CLEARED_BOOLEAN
#endif /* (CAN_NO_CACHE_NEEDED == STD_ON) */
#include "Can_MemMap.h"
/* CAN_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE */


#define CAN_START_SEC_CODE
/* @violates @ref Can_Ipw_c_REF_1 MISRA 2012 Required Directive 4.10 */
#include "Can_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Can_Ipw_ParseData
(
    Can_HwType * CanIf_Mailbox,
    PduInfoType * CanIf_PduInfo,
    Flexcan_Ip_MsgBuffType * pReceivedDataBuffer,
    const Can_ControllerConfigType * Can_pControllerConfig,
    const Can_HwObjectConfigType * Can_pHwObjectConfig
);
static Std_ReturnType Can_Ipw_SetControlerErrorInit(const Can_ControllerConfigType * Can_pControllerConfig);
static void Can_Ipw_InitLegacyFifoFilter(const Can_ControllerConfigType * Can_pController, const Can_HwObjectConfigType * Can_pHwObject);

#if (CAN_RX_POLLING_SUPPORT == STD_ON)
static void Can_Ipw_ProcessLegacyFifoPolling
(
    Can_HwType * CanIf_Mailbox,
    PduInfoType * CanIf_PduInfo,
    Flexcan_Ip_MsgBuffType * pReceivedDataBuffer,
    const Can_ControllerConfigType * Can_pControllerConfig,
    const Can_HwObjectConfigType * Can_pHwObjectConfig
);

#if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
static void Can_Ipw_ProcessEnhancedFifoPolling
(
    Can_HwType * CanIf_Mailbox,
    PduInfoType * CanIf_PduInfo,
    Flexcan_Ip_MsgBuffType * pReceivedDataBuffer,
    const Can_ControllerConfigType * Can_pControllerConfig,
    const Can_HwObjectConfigType * Can_pHwObjectConfig
);
#endif /* (CAN_ENHANCED_FIFO_ENABLED == STD_ON) */
#endif /* (CAN_RX_POLLING_SUPPORT == STD_ON) */

/* re-Init baudrate (uses in Can_Ipw_SetControllerToStartMode only) */
static void Can_Ipw_InitBaudrate(const Can_ControllerConfigType * ControllerConfig);

/* Init all Rx objects */
static void Can_Ipw_InitRx(const Can_ControllerConfigType * Can_pController);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static void Can_Ipw_ParseData
(
    Can_HwType * CanIf_Mailbox,
    PduInfoType * CanIf_PduInfo,
    Flexcan_Ip_MsgBuffType * pReceivedDataBuffer,
    const Can_ControllerConfigType * Can_pControllerConfig,
    const Can_HwObjectConfigType * Can_pHwObjectConfig
)
{
    CanIf_Mailbox->CanId = pReceivedDataBuffer->msgId;
    /*
    * [SWS_Can_00423] ⌈ In case of an Extended CAN frame, the Can module shall
    * convert the ID to a standardized format since the Upper layer (CANIF) does not know
    * whether the received CAN frame is a Standard CAN frame or Extended CAN frame.
    * In case of an Extended CAN frame, MSB of a received CAN frame ID needs to be
    * made as ‘1’ to mark the received CAN frame as Extended.⌋
    */
    if (((pReceivedDataBuffer->cs) & CAN_IPW_CS_IDE_MASK) != 0U)
    {
        CanIf_Mailbox->CanId |= (uint32)0x80000000U;
    }

    if (CAN_RX_NORMAL == Can_pHwObjectConfig->Can_eReceiveType)
    {
        /* Check if Mb Overrun */
        if ((uint32)(0x06000000U) == (pReceivedDataBuffer->cs & CAN_IPW_CS_CODE_MASK))
        {
            (void)Det_ReportRuntimeError((uint16)CAN_IPW_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
        }
    }

    /* when legacy fifo enabled, FD must be disabled */
    if (CAN_RX_LEGACY_FIFO != Can_pHwObjectConfig->Can_eReceiveType)
    {
        /*
        * [SWS_Can_00501] ⌈ CanDrv shall indicate whether the received message is a
        * conventional CAN frame or a CAN FD frame as described in Can_IdType.⌋
        */
        if (((pReceivedDataBuffer->cs) & CAN_IPW_CS_EDL_MASK) != 0U)
        {
            CanIf_Mailbox->CanId |= (uint32)0x40000000U;
        }
    }

#if (CAN_LPDU_CALLOUT_SUPPORT == STD_ON)
    if (TRUE == CAN_LPDU_CALLOUT_FUNC_CALLED((uint8)Can_pHwObjectConfig->Can_HwObjectID, \
                                                      CanIf_Mailbox->CanId, \
                                                      pReceivedDataBuffer->dataLen, \
                                                      &pReceivedDataBuffer->data[0]) \
                                                     )
    {
#endif
        CanIf_Mailbox->Hoh = Can_pHwObjectConfig->Can_HwObjectID;
        CanIf_Mailbox->ControllerId = Can_pControllerConfig->Can_u8AbstControllerID;
        CanIf_PduInfo->SduLength = pReceivedDataBuffer->dataLen;
        CanIf_PduInfo->SduDataPtr = &pReceivedDataBuffer->data[0];
        CanIf_RxIndication(CanIf_Mailbox, CanIf_PduInfo);
#if (CAN_LPDU_CALLOUT_SUPPORT == STD_ON)
    }
#endif

#if (CAN_TIMESTAMP_ENABLE == STD_ON)
    if (TRUE == Can_pHwObjectConfig->CanTimestampEnable)
    {
        Can_pControllerConfig->CanRxTimestampNotification(Can_pHwObjectConfig->Can_HwObjectID, pReceivedDataBuffer->time_stamp);
    }
#endif
}

static void Can_Ipw_InitLegacyFifoFilter(const Can_ControllerConfigType * Can_pController, const Can_HwObjectConfigType * Can_pHwObject)
{
    uint8 u8FilterIdx=0U;
    uint8 u8HwFilterCount = 0U;
    uint32 u32HwFilterMask = (uint32)0x00000000U;
    /* The max FIFO id filter affected by Rx individual masks*/
    uint8 u8FiFoFilterIndvCount = 0U;
    Flexcan_Ip_RxFifoIdElementFormatType eElementFormat = FLEXCAN_RX_FIFO_ID_FORMAT_A;
    /* Need to alocate a filter array with elemnets no as defined in HwObject */
    Flexcan_Ip_IdTableType RxFifoFilters[128];

    if (((Can_pHwObject->Can_u8HwFilterCount / 4U) + 6U) <= 32U)
    {
        u8FiFoFilterIndvCount = (Can_pHwObject->Can_u8HwFilterCount / 4U) + 6U;
    }
    else
    {
        u8FiFoFilterIndvCount = 32U;
    }
    for (u8FilterIdx=0U; ((u8FilterIdx < u8FiFoFilterIndvCount) && (u8FilterIdx < Can_pHwObject->Can_u8HwFilterCount)); u8FilterIdx++)
    {
            if (CAN_LEGACY_FIFO_FORMAT_A == Can_pController->Can_eLegacyAcceptanceMode)
            {
                u8HwFilterCount =  Can_pHwObject->Can_u8HwFilterCount;
                u32HwFilterMask = (uint32)0xC0000000U;
                eElementFormat = FLEXCAN_RX_FIFO_ID_FORMAT_A;
                if (Can_pHwObject->Can_IdMessage != CAN_STANDARD)
                {
                    u32HwFilterMask |= Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterMask << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATA_EXT_SHIFT;
                }
                else
                {
                    u32HwFilterMask |= Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterMask << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATA_STD_SHIFT;
                }
            }
            else if (CAN_LEGACY_FIFO_FORMAT_B == Can_pController->Can_eLegacyAcceptanceMode)
            {
                u8HwFilterCount = Can_pHwObject->Can_u8HwFilterCount * 2U ;
                u32HwFilterMask = (uint32)0xC000C000U;
                eElementFormat = FLEXCAN_RX_FIFO_ID_FORMAT_B;
                if (Can_pHwObject->Can_IdMessage != CAN_STANDARD)
                {
                    u32HwFilterMask |= (Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx * 2U].Can_u32HwFilterMask >> CAN_IPW_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT) << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATB_EXT_SHIFT1;
                    u32HwFilterMask |= (Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 2U) + 1U].Can_u32HwFilterMask >> CAN_IPW_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT) << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATB_EXT_SHIFT2;
                }
                else
                {
                    u32HwFilterMask |= Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx * 2U].Can_u32HwFilterMask << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATB_STD_SHIFT1;
                    u32HwFilterMask |= Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 2U) + 1U].Can_u32HwFilterMask << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATB_STD_SHIFT2;
                }
            }
            else /*CAN_LEGACY_FIFO_FORMAT_C == Can_pController->Can_eLegacyAcceptanceMode */
            {
                u8HwFilterCount =  Can_pHwObject->Can_u8HwFilterCount * 4U ;
                u32HwFilterMask = (uint32)0x00000000U;
                eElementFormat = FLEXCAN_RX_FIFO_ID_FORMAT_C;
                if (Can_pHwObject->Can_IdMessage != CAN_STANDARD)
                {
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx * 4U].Can_u32HwFilterMask >> CAN_IPW_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT) << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT1;
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 4U) + 1U].Can_u32HwFilterMask >> CAN_IPW_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT) << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT2;
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 4U) + 2U].Can_u32HwFilterMask >> CAN_IPW_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT) << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT3;
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 4U) + 3U].Can_u32HwFilterMask >> CAN_IPW_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT) << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT4;
                }
                else
                {
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx * 4U].Can_u32HwFilterMask >> CAN_IPW_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT) << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT1;
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 4U) + 1U].Can_u32HwFilterMask >> CAN_IPW_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT) << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT2;
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 4U) + 2U].Can_u32HwFilterMask >> CAN_IPW_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT) << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT3;
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 4U) + 3U].Can_u32HwFilterMask >> CAN_IPW_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT) << CAN_IPW_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT4;
                }
            }
            /* Already in freeze mode */
            (void)FlexCAN_Ip_SetRxIndividualMask(Can_pController->Can_u8ControllerOffset, u8FilterIdx, u32HwFilterMask);
    }

    (void)FlexCAN_Ip_SetRxFifoGlobalMask(Can_pController->Can_u8ControllerOffset, Can_pController->Can_u32LegacyGlobalMask);

    for (u8FilterIdx=0U; u8FilterIdx < u8HwFilterCount; u8FilterIdx++)
    {
        RxFifoFilters[u8FilterIdx].id = Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterCode;
        if (Can_pHwObject->Can_IdMessage != CAN_STANDARD)
        {
            RxFifoFilters[u8FilterIdx].isExtendedFrame = TRUE;
        }
        else
        {
            RxFifoFilters[u8FilterIdx].isExtendedFrame = FALSE;
        }
        RxFifoFilters[u8FilterIdx].isRemoteFrame = FALSE;
    }

    (void)FlexCAN_Ip_ConfigRxFifo(Can_pController->Can_u8ControllerOffset, eElementFormat, &RxFifoFilters[0]);
}

#if (CAN_RX_POLLING_SUPPORT == STD_ON)
static void Can_Ipw_ProcessLegacyFifoPolling
(
    Can_HwType * CanIf_Mailbox,
    PduInfoType * CanIf_PduInfo,
    Flexcan_Ip_MsgBuffType * pReceivedDataBuffer,
    const Can_ControllerConfigType * Can_pControllerConfig,
    const Can_HwObjectConfigType * Can_pHwObjectConfig
)
{
    uint8 u8ObjIdx = 0U;
    boolean returnResult = TRUE;

    returnResult = FlexCAN_Ip_GetBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 5U);
    while ((u8ObjIdx < Can_pHwObjectConfig->Can_u8ObjectCount) && (TRUE == returnResult))
    {
        u8ObjIdx++;
        /* Check Legacy OverFlow */
        if (TRUE == FlexCAN_Ip_GetBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 7U))
        {
            (void)Det_ReportRuntimeError((uint16)CAN_IPW_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
            if (NULL_PTR != Can_pControllerConfig->Can_pLegacyFiFoOvfNotif)
            {
                Can_pControllerConfig->Can_pLegacyFiFoOvfNotif();
            }
            FlexCAN_Ip_ClearBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 7U);
        }

        /* Check Legacy FifoWarning */
        if (TRUE == FlexCAN_Ip_GetBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 6U))
        {
            if (NULL_PTR != Can_pControllerConfig->Can_pLegacyFiFoWarnNotif)
            {
                Can_pControllerConfig->Can_pLegacyFiFoWarnNotif();
            }
            FlexCAN_Ip_ClearBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 6U);
        }

        (void)FlexCAN_Ip_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, pReceivedDataBuffer);
        FlexCAN_Ip_MainFunctionRead(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex);

        if (FLEXCAN_STATUS_SUCCESS == FlexCAN_Ip_GetTransferStatus(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex))
        {
            Can_Ipw_ParseData(CanIf_Mailbox, \
                              CanIf_PduInfo, \
                              pReceivedDataBuffer, \
                              Can_pControllerConfig, \
                              Can_pHwObjectConfig \
                             );
        }
        returnResult = FlexCAN_Ip_GetBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 5U);
    }
}

#if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
static void Can_Ipw_ProcessEnhancedFifoPolling
(
    Can_HwType * CanIf_Mailbox,
    PduInfoType * CanIf_PduInfo,
    Flexcan_Ip_MsgBuffType * pReceivedDataBuffer,
    const Can_ControllerConfigType * Can_pControllerConfig,
    const Can_HwObjectConfigType * Can_pHwObjectConfig
)
{
    uint8 u8ObjIdx = 0U;

    while (u8ObjIdx < Can_pHwObjectConfig->Can_u8ObjectCount)
    {
        u8ObjIdx++;
        /* Check Enhanced OverFlow */
        if (TRUE == FlexCAN_Ip_GetBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 255U))
        {
            (void)Det_ReportRuntimeError((uint16)CAN_IPW_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
            if (NULL_PTR != Can_pControllerConfig->Can_pEnhanceFiFoOvfNotif)
            {
                Can_pControllerConfig->Can_pEnhanceFiFoOvfNotif();
            }
            FlexCAN_Ip_ClearBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 255U);
        }

        (void)FlexCAN_Ip_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, pReceivedDataBuffer);
        FlexCAN_Ip_MainFunctionRead(Can_pControllerConfig->Can_u8ControllerOffset, 255U);

        if (FLEXCAN_STATUS_SUCCESS == FlexCAN_Ip_GetTransferStatus(Can_pControllerConfig->Can_u8ControllerOffset, 255U))
        {
            Can_Ipw_ParseData(CanIf_Mailbox, \
                              CanIf_PduInfo, \
                              pReceivedDataBuffer, \
                              Can_pControllerConfig, \
                              Can_pHwObjectConfig \
                             );
        }
    }
}
#endif /* (CAN_ENHANCED_FIFO_ENABLED == STD_ON) */
#endif /* (CAN_RX_POLLING_SUPPORT == STD_ON) */

/* Init baudrate for controller */
static void Can_Ipw_InitBaudrate(const Can_ControllerConfigType * ControllerConfig)
{
    uint16 BaudRateConfigID = ControllerConfig->Can_u16DefaultBaudrateID;
#if ((CAN_DUAL_CLOCK_MODE == STD_ON) || (CAN_SET_BAUDRATE_API == STD_ON))
    Flexcan_Ip_TimeSegmentType FlexCANTimeSeg;
#endif /* ((CAN_DUAL_CLOCK_MODE == STD_ON) || (CAN_SET_BAUDRATE_API == STD_ON)) */

#if ((CAN_DUAL_CLOCK_MODE == STD_ON) || (CAN_SET_BAUDRATE_API == STD_ON))
        /* Re-Init baudrate */
    #if (CAN_SET_BAUDRATE_API == STD_ON)
        BaudRateConfigID = Can_au16ControllerBaudRateSel[ControllerConfig->Can_u8ControllerID];
    #endif

    #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        if (CAN_CLOCKMODE_NORMAL == Can_Ipw_eClockMode[ControllerConfig->Can_u8ControllerID])
        {
    #endif
            FlexCANTimeSeg.preDivider = ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u16Prescaler;
    #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        }
        else
        {
            FlexCANTimeSeg.preDivider = ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u16PrescalerAlternate;
        }
    #endif

        FlexCANTimeSeg.propSeg    = ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u8PropSeg;
        FlexCANTimeSeg.phaseSeg1  = ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u8PhaseSeg1;
        FlexCANTimeSeg.phaseSeg2  = ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u8PhaseSeg2;
        FlexCANTimeSeg.rJumpwidth = ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u8ResyncJumpWidth;

        (void)FlexCAN_Ip_SetBitrate(ControllerConfig->Can_u8ControllerOffset, &FlexCANTimeSeg, ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_bEnhanceCBTEnable);
#endif /* ((CAN_DUAL_CLOCK_MODE == STD_ON) || (CAN_SET_BAUDRATE_API == STD_ON)) */
        if (TRUE == ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_bFDFrame)
        {
    #if ((CAN_DUAL_CLOCK_MODE == STD_ON) || (CAN_SET_BAUDRATE_API == STD_ON))
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
            if (CAN_CLOCKMODE_NORMAL == Can_Ipw_eClockMode[ControllerConfig->Can_u8ControllerID])
            {
        #endif
                FlexCANTimeSeg.preDivider = ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u16Prescaler;
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
            }
            else
            {
                FlexCANTimeSeg.preDivider = ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u16PrescalerAlternate;
            }
        #endif
            FlexCANTimeSeg.propSeg    = ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u8PropSeg;
            FlexCANTimeSeg.phaseSeg1  = ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u8PhaseSeg1;
            FlexCANTimeSeg.phaseSeg2  = ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u8PhaseSeg2;
            FlexCANTimeSeg.rJumpwidth = ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u8ResyncJumpWidth;

            (void)FlexCAN_Ip_SetBitrateCbt(ControllerConfig->Can_u8ControllerOffset, &FlexCANTimeSeg, ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_bBitRateSwitch);
    #endif /* ((CAN_DUAL_CLOCK_MODE == STD_ON) || (CAN_SET_BAUDRATE_API == STD_ON)) */
            (void)FlexCAN_Ip_SetTDCOffset(ControllerConfig->Can_u8ControllerOffset, \
                                          ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_bTrcvDelayEnable, \
                                          ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_u8TrcvDelayCompOffset);
        }
        (void)FlexCAN_Ip_SetTxArbitrationStartDelay(ControllerConfig->Can_u8ControllerOffset, ControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_u8TxArbitrationStartDelay);
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
Std_ReturnType Can_Ipw_Init(const Can_ControllerConfigType * Can_pControllerConfig)
{
    Std_ReturnType eRetVal = (Std_ReturnType)FLEXCAN_STATUS_ERROR;
#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
    /* The Index of Hoh in a group that refer to a controller */
    uint8 u8HwObjRefIdx = 0U;
    uint8 u8ObjIdx = 0U;
    const Can_HwObjectConfigType * Can_pHwObject = NULL_PTR;
    uint8 u8HwBufferCount = 0U;
#endif

#if (CAN_SET_BAUDRATE_API == STD_ON)
    Can_au16ControllerBaudRateSel[Can_pControllerConfig->Can_u8ControllerID] = Can_pControllerConfig->Can_u16DefaultBaudrateID;
#endif

#if (CAN_DUAL_CLOCK_MODE == STD_ON)
    Can_Ipw_eClockMode[Can_pControllerConfig->Can_u8ControllerID] = CAN_CLOCKMODE_NORMAL;
#endif

#if (CAN_LISTEN_ONLY_MODE == STD_ON)
    Can_Ipw_eListenOnlyMode[Can_pControllerConfig->Can_u8ControllerID] = NORMAL_MODE;
#endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */

    /* @violates @ref Can_Ipw_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
    eRetVal = (Std_ReturnType)Call_Can_FlexCan_Init(Can_pControllerConfig->Can_u8ControllerOffset, Can_Ipw_apxStatus[Can_pControllerConfig->Can_u8ControllerID], Can_pControllerConfig->HwChannelIpConfig->pFlexcanIpHwConfig);
    
    /* by defaut, enable interrupt when setcontroller to start */
    Can_Ipw_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID] = TRUE;
    if ((Std_ReturnType)FLEXCAN_STATUS_SUCCESS == eRetVal)
    {
        /* disable all interrupts */
        (void)FlexCAN_Ip_DisableInterrupts(Can_pControllerConfig->Can_u8ControllerOffset);

        /* If the FlexCAN_Init retuns SUCCESS then the module is already in freezemode, and FlexCAN_Ip_SetTDCOffset and FlexCAN_Ip_SetTxArbitrationStartDelay will always retun success */
        if (Can_pControllerConfig->Can_pBaudrateConfig[Can_pControllerConfig->Can_u16DefaultBaudrateID].Can_bFDFrame)
        {
            (void)FlexCAN_Ip_SetTDCOffset(Can_pControllerConfig->Can_u8ControllerOffset, \
                                          Can_pControllerConfig->Can_pBaudrateConfig[Can_pControllerConfig->Can_u16DefaultBaudrateID].Can_bTrcvDelayEnable, \
                                          Can_pControllerConfig->Can_pBaudrateConfig[Can_pControllerConfig->Can_u16DefaultBaudrateID].Can_u8TrcvDelayCompOffset);
        }
        (void)FlexCAN_Ip_SetTxArbitrationStartDelay(Can_pControllerConfig->Can_u8ControllerOffset, \
                                                    Can_pControllerConfig->Can_pBaudrateConfig[Can_pControllerConfig->Can_u16DefaultBaudrateID].Can_u8TxArbitrationStartDelay);
        
        /* Init all Rx objects */
        Can_Ipw_InitRx(Can_pControllerConfig);
    }

#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
    for (u8HwBufferCount = 0U; u8HwBufferCount < CAN_HWMB_COUNT; u8HwBufferCount++)
    {
        Can_Ipw_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][u8HwBufferCount] = CAN_HWOBJ_UNMAPPED;
    }
    /* Map MB index to hardware object ID */
    for (u8HwObjRefIdx = 0U; u8HwObjRefIdx < Can_pControllerConfig->Can_u8HwObjectRefCount; u8HwObjRefIdx++)
    {
        Can_pHwObject = Can_pControllerConfig->Can_ppHwObject[u8HwObjRefIdx];
        switch (Can_pHwObject->Can_eReceiveType)
        {
            case CAN_TX_NORMAL:
            {
                for (u8ObjIdx = 0U; u8ObjIdx < Can_pHwObject->Can_u8ObjectCount; u8ObjIdx++)
                {
                    Can_Ipw_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][Can_pHwObject->Can_u8HwBufferIndex + u8ObjIdx] = Can_pHwObject->Can_HwObjectID;
                }
                break;
            }
            case CAN_RX_NORMAL:
            {
                Can_Ipw_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][Can_pHwObject->Can_u8HwBufferIndex] = Can_pHwObject->Can_HwObjectID;
                break;
            }
            case CAN_RX_LEGACY_FIFO:
            {
                Can_Ipw_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][Can_pHwObject->Can_u8HwBufferIndex] = Can_pHwObject->Can_HwObjectID;
                Can_Ipw_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][6U] = Can_pHwObject->Can_HwObjectID;
                Can_Ipw_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][7U] = Can_pHwObject->Can_HwObjectID;
                break;
            }
            default:
            {
                /* don't map for enhance fifo object because of out of message buffer memory */
                break;
            }
        }
    }
#endif /* MB_INTERRUPT_SUPPORT */
    eRetVal = (Std_ReturnType)FlexCAN_Ip_SetStopMode(Can_pControllerConfig->Can_u8ControllerOffset);

    return (Std_ReturnType)eRetVal;
}

/**
*   @brief      De-Initialize Controller
*/
void Can_Ipw_DeInit(const Can_ControllerConfigType * Can_pControllerConfig)
{
    /* @violates @ref Can_Ipw_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
    (void)FlexCAN_Ip_Deinit(Can_pControllerConfig->Can_u8ControllerOffset);
}

/**
*   @brief      Set Baud Rate of Controller
*/
#if (CAN_SET_BAUDRATE_API == STD_ON)
    Std_ReturnType Can_Ipw_SetBaudrate
    (
        const Can_ControllerConfigType * Can_pControllerConfig,
        uint16 BaudRateConfigID
    )
    {
        Flexcan_Ip_StatusType eRetVal = FLEXCAN_STATUS_ERROR;
        Flexcan_Ip_TimeSegmentType FlexCANTimeSeg;

        eRetVal = FlexCAN_Ip_EnterFreezeMode(Can_pControllerConfig->Can_u8ControllerOffset);
        if (FLEXCAN_STATUS_SUCCESS == eRetVal)
        {
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
            if (CAN_CLOCKMODE_NORMAL == Can_Ipw_eClockMode[Can_pControllerConfig->Can_u8ControllerID])
            {
        #endif
                FlexCANTimeSeg.preDivider = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u16Prescaler;
         #if (CAN_DUAL_CLOCK_MODE == STD_ON)
            }
            else
            {
                FlexCANTimeSeg.preDivider = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u16PrescalerAlternate;
            }
        #endif

            FlexCANTimeSeg.propSeg    = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u8PropSeg;
            FlexCANTimeSeg.phaseSeg1  = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u8PhaseSeg1;
            FlexCANTimeSeg.phaseSeg2  = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u8PhaseSeg2;
            FlexCANTimeSeg.rJumpwidth = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u8ResyncJumpWidth;

            (void)FlexCAN_Ip_SetBitrate(Can_pControllerConfig->Can_u8ControllerOffset, &FlexCANTimeSeg, Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_bEnhanceCBTEnable);

        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
            if (CAN_CLOCKMODE_NORMAL == Can_Ipw_eClockMode[Can_pControllerConfig->Can_u8ControllerID])
            {
        #endif
                FlexCANTimeSeg.preDivider = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u16Prescaler;
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
            }
            else
            {
                FlexCANTimeSeg.preDivider = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u16PrescalerAlternate;
            }
        #endif

            if (TRUE == Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_bFDFrame)
            {
                FlexCANTimeSeg.propSeg    = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u8PropSeg;
                FlexCANTimeSeg.phaseSeg1  = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u8PhaseSeg1;
                FlexCANTimeSeg.phaseSeg2  = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u8PhaseSeg2;
                FlexCANTimeSeg.rJumpwidth = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u8ResyncJumpWidth;

                (void)FlexCAN_Ip_SetBitrateCbt(Can_pControllerConfig->Can_u8ControllerOffset, &FlexCANTimeSeg, Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_bBitRateSwitch);

                (void)FlexCAN_Ip_SetTDCOffset(Can_pControllerConfig->Can_u8ControllerOffset, \
                                            Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_bTrcvDelayEnable, \
                                            Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_u8TrcvDelayCompOffset \
                                            );
            }

            (void)FlexCAN_Ip_SetTxArbitrationStartDelay(Can_pControllerConfig->Can_u8ControllerOffset, Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_u8TxArbitrationStartDelay);

            eRetVal = FlexCAN_Ip_SetStopMode(Can_pControllerConfig->Can_u8ControllerOffset);
            if (FLEXCAN_STATUS_SUCCESS == eRetVal)
            {
                Can_au16ControllerBaudRateSel[Can_pControllerConfig->Can_u8ControllerID] = BaudRateConfigID;
            }
        }
        return ((FLEXCAN_STATUS_SUCCESS == eRetVal) ? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK));
    }
#endif /* CAN_SET_BAUDRATE_API == STD_ON */

/**
*   @brief      Set Error Initialization and set Controller to start Mode.
*/
static Std_ReturnType Can_Ipw_SetControlerErrorInit(const Can_ControllerConfigType * Can_pControllerConfig)
{
    Flexcan_Ip_StatusType eRetVal = FLEXCAN_STATUS_SUCCESS;

    if (TRUE == Can_Ipw_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID])
        {
#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
            if (Can_pControllerConfig->bErrEn)
            {
                (void)FlexCAN_Ip_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_IP_INT_ERR, TRUE);
    #if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
                (void)FlexCAN_Ip_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_IP_INT_ERR_FAST, TRUE);
    #endif /* FLEXCAN_IP_FEATURE_HAS_FD */
            }
#endif /* ERROR_INTERRUPT_SUPPORT */
#if (CAN_BUSOFF_INTERRUPT_SUPPORT == STD_ON)
            if (FALSE == Can_pControllerConfig->Can_bBusOffUsesPolling)
            {
                (void)FlexCAN_Ip_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_IP_INT_BUSOFF, TRUE);
            }
#endif  /* BUSOFF_INTERRUPT_SUPPORT */
            (void)FlexCAN_Ip_EnableInterrupts(Can_pControllerConfig->Can_u8ControllerOffset);
        }
        eRetVal = FlexCAN_Ip_SetStartMode(Can_pControllerConfig->Can_u8ControllerOffset);

        return (Std_ReturnType)eRetVal;
}

/**
*   @brief      Set Controller to participate the CAN network
*/
Std_ReturnType Can_Ipw_SetControllerToStartMode(const Can_ControllerConfigType * Can_pControllerConfig)
{
#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
    uint8 u8HwObjRefIdx = 0U;
    const Can_HwObjectConfigType * Can_pHwObject = NULL_PTR;
#endif /* (CAN_MB_INTERRUPT_SUPPORT == STD_ON) */
    Flexcan_Ip_StatusType eRetVal;

    eRetVal = FlexCAN_Ip_Init(Can_pControllerConfig->Can_u8ControllerOffset, \
                                                    Can_Ipw_apxStatus[Can_pControllerConfig->Can_u8ControllerID], \
                                                    Can_pControllerConfig->HwChannelIpConfig->pFlexcanIpHwConfig);

    if (FLEXCAN_STATUS_SUCCESS == eRetVal)
    {
        /* disable all interrupts */
        (void)FlexCAN_Ip_DisableInterrupts(Can_pControllerConfig->Can_u8ControllerOffset);

        /* Re-Init baudrate */
        Can_Ipw_InitBaudrate(Can_pControllerConfig);

        /* Re-Init all Rx Objects */
        Can_Ipw_InitRx(Can_pControllerConfig);

    #if (CAN_LISTEN_ONLY_MODE == STD_ON)
        if (LISTEN_ONLY_MODE == Can_Ipw_eListenOnlyMode[Can_pControllerConfig->Can_u8ControllerID])
        {
            (void)FlexCAN_Ip_SetListenOnlyMode(Can_pControllerConfig->Can_u8ControllerOffset, TRUE);
        }
    #endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */

    #if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
        for (u8HwObjRefIdx = 0U; u8HwObjRefIdx < Can_pControllerConfig->Can_u8HwObjectRefCount; u8HwObjRefIdx++)
        {
            Can_pHwObject = (const Can_HwObjectConfigType *)Can_pControllerConfig->Can_ppHwObject[u8HwObjRefIdx];

            if (FALSE == Can_pHwObject->Can_bHwObjectUsesPolling)
            {
                switch (Can_pHwObject->Can_eReceiveType)
                {
                    case CAN_RX_NORMAL:
                    {
                        (void)FlexCAN_Ip_Receive(Can_pControllerConfig->Can_u8ControllerOffset, \
                                                 Can_pHwObject->Can_u8HwBufferIndex, \
                                                 NULL_PTR, \
                                                 Can_pHwObject->Can_bHwObjectUsesPolling \
                                                );
                        break;
                    }
                    case CAN_RX_ENHANCED_FIFO : /* FallThrough Allowed */
                    case CAN_RX_LEGACY_FIFO:
                    {
                    #if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
                        if (FLEXCAN_RXFIFO_USING_DMA == Can_pControllerConfig->HwChannelIpConfig->pFlexcanIpHwConfig->transfer_type)
                        {
                            (void)FlexCAN_Ip_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, Can_pControllerConfig->pDmaDstAddr);
                        }
                        else
                    #endif
                        {
                            (void)FlexCAN_Ip_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, NULL_PTR);
                        }
                        break;
                    }
                    default:
                    {
                        /* nothing to do(TX object) */
                        break;
                    }
                }
            }
        }
    #endif /* CAN_MB_INTERRUPT_SUPPORT == STD_ON */
        eRetVal = ((Std_ReturnType)E_OK == Can_Ipw_SetControlerErrorInit(Can_pControllerConfig)) ? (FLEXCAN_STATUS_SUCCESS) : (FLEXCAN_STATUS_ERROR);
    }
    return (Std_ReturnType)eRetVal;
}

#if (CAN_LISTEN_ONLY_MODE == STD_ON)
/**
*   @brief      Enable or disable Listen Only Mode
*/
Std_ReturnType Can_Ipw_ListenOnlyMode(const Can_ControllerConfigType * Can_pControllerConfig, const Can_ListenOnlyType State)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;

    switch (State)
    {
        case NORMAL_MODE:
        {
            eReturnValue = (Std_ReturnType)FlexCAN_Ip_SetListenOnlyMode(Can_pControllerConfig->Can_u8ControllerOffset, FALSE);
            break;
        }
        case LISTEN_ONLY_MODE:
        {
            eReturnValue = (Std_ReturnType)FlexCAN_Ip_SetListenOnlyMode(Can_pControllerConfig->Can_u8ControllerOffset, TRUE);
            break;
        }
        default:
        {
            /* nothing to do */
            break;
        }
    }

    if ((Std_ReturnType)E_OK == eReturnValue)
    {
        Can_Ipw_eListenOnlyMode[Can_pControllerConfig->Can_u8ControllerID] = State;
    }

    return eReturnValue;
}
#endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */

/**
*   @brief      Set Controller to stop participating the CAN network
*/
Std_ReturnType Can_Ipw_SetControllerToStopMode(const Can_ControllerConfigType * Can_pControllerConfig)
{
    /*
    * [SWS_Can_00197] ⌈ The function Can_SetControllerMode shall disable interrupts
    * that are not allowed in the new state. ⌋
    * [SWS_Can_00426] ⌈ Disabling of CAN interrupts shall not be executed, when CAN
    * interrupts have been disabled by function Can_DisableControllerInterrupts.⌋
    */
    Std_ReturnType eReturnValue;
    uint8 u8HwObjRefIdx = 0U;
    const Can_HwObjectConfigType * Can_pHwObject;
    uint8 u8Idx = 0U;

    if (FLEXCAN_STATUS_SUCCESS == FlexCAN_Ip_EnterFreezeMode(Can_pControllerConfig->Can_u8ControllerOffset))
    {
    #if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
        (void)FlexCAN_Ip_ConfigPN(Can_pControllerConfig->Can_u8ControllerOffset, FALSE, NULL_PTR);
    #endif

    if (TRUE == Can_Ipw_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID])
    {
        (void)FlexCAN_Ip_DisableInterrupts(Can_pControllerConfig->Can_u8ControllerOffset);
#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
        if (Can_pControllerConfig->bErrEn)
        {
            (void)FlexCAN_Ip_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_IP_INT_ERR, FALSE);
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
            (void)FlexCAN_Ip_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_IP_INT_ERR_FAST, FALSE);
#endif  /* FLEXCAN_IP_FEATURE_HAS_FD */
        }
#endif  /*  ERROR_INTERRUPT_SUPPORT */
#if (CAN_BUSOFF_INTERRUPT_SUPPORT == STD_ON)
        if (FALSE == Can_pControllerConfig->Can_bBusOffUsesPolling)
        {
            (void)FlexCAN_Ip_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_IP_INT_BUSOFF, FALSE);
        }
#endif /* BUSOFF_INTERRUPT_SUPPORT */
    }
    for (u8HwObjRefIdx = 0U; u8HwObjRefIdx < Can_pControllerConfig->Can_u8HwObjectRefCount; u8HwObjRefIdx++)
    {
        Can_pHwObject = (const Can_HwObjectConfigType *)Can_pControllerConfig->Can_ppHwObject[u8HwObjRefIdx];

        if (CAN_TX_NORMAL == Can_pHwObject->Can_eReceiveType)
        {
            u8Idx = 0U;
            do
            {
                (void)FlexCAN_Ip_AbortTransfer(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObject->Can_u8HwBufferIndex + u8Idx);
                u8Idx++;
            }while (u8Idx < Can_pHwObject->Can_u8ObjectCount);
        }
        else
        {
            (void)FlexCAN_Ip_AbortTransfer(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObject->Can_u8HwBufferIndex);
        }
    }
    eReturnValue = (Std_ReturnType)FlexCAN_Ip_SetStopMode(Can_pControllerConfig->Can_u8ControllerOffset);
    }
    else
    {
        eReturnValue = E_NOT_OK;
    }

    return eReturnValue;
}
/**
*   @brief      Disable Can Controller Interrupts
*/
void Can_Ipw_DisableControllerInterrupts(const Can_ControllerConfigType * Can_pControllerConfig)
{
    if (TRUE == Can_Ipw_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID])
    {
        /* @violates @ref Can_Ipw_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
        (void)FlexCAN_Ip_DisableInterrupts(Can_pControllerConfig->Can_u8ControllerOffset);
        Can_Ipw_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID] = FALSE;
#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
        if (Can_pControllerConfig->bErrEn)
        {
            (void)FlexCAN_Ip_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_IP_INT_ERR, FALSE);
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
            (void)FlexCAN_Ip_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_IP_INT_ERR_FAST, FALSE);
#endif  /* FLEXCAN_IP_FEATURE_HAS_FD */
        }
#endif  /*  ERROR_INTERRUPT_SUPPORT */
#if (CAN_BUSOFF_INTERRUPT_SUPPORT == STD_ON)
        if (FALSE == Can_pControllerConfig->Can_bBusOffUsesPolling)
        {
            (void)FlexCAN_Ip_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_IP_INT_BUSOFF, FALSE);
        }
#endif /* BUSOFF_INTERRUPT_SUPPORT */
    }
}

/**
*   @brief      Enable Can Controller Interrupts
*/
void Can_Ipw_EnableControllerInterrupts(const Can_ControllerConfigType * Can_pControllerConfig)
{
    /*
    * [SWS_Can_00208] ⌈ The function Can_EnableControllerInterrupts shall perform no
    * action when Can_DisableControllerInterrupts has not been called before.⌋
    */
    if (FALSE == Can_Ipw_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID])
    {
        /* @violates @ref Can_Ipw_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
        (void)FlexCAN_Ip_EnableInterrupts(Can_pControllerConfig->Can_u8ControllerOffset);
#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
        if (Can_pControllerConfig->bErrEn)
        {
            (void)FlexCAN_Ip_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_IP_INT_ERR, TRUE);
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
            (void)FlexCAN_Ip_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_IP_INT_ERR_FAST, TRUE);
#endif /* FLEXCAN_IP_FEATURE_HAS_FD */
        }
#endif /* ERROR_INTERRUPT_SUPPORT */
#if (CAN_BUSOFF_INTERRUPT_SUPPORT == STD_ON)
        if (FALSE == Can_pControllerConfig->Can_bBusOffUsesPolling)
        {
            (void)FlexCAN_Ip_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_IP_INT_BUSOFF, TRUE);
        }
#endif  /* BUSOFF_INTERRUPT_SUPPORT */
        /* update status */
        Can_Ipw_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID] = TRUE;
    }
}

/**
*   @brief      Get Controller Error State
*/
uint8 Can_Ipw_GetControllerErrorState(const Can_ControllerConfigType * Can_pControllerConfig)
{
    uint32 Error = 0U;

    Error = FlexCAN_Ip_GetErrorStatus(Can_pControllerConfig->Can_u8ControllerOffset);

    return (uint8)((Error & FLEXCAN_ESR1_FLTCONF_MASK)>>FLEXCAN_ESR1_FLTCONF_SHIFT);
}

/**
*   @brief      Get Controller Tx Error Counter
*/
uint8 Can_Ipw_GetControllerTxErrorCounter(const Can_ControllerConfigType * Can_pControllerConfig)
{
    return FlexCAN_Ip_GetControllerTxErrorCounter(Can_pControllerConfig->Can_u8ControllerOffset);
}

/**
*   @brief      Get Controller Rx Error Counter
*/
uint8 Can_Ipw_GetControllerRxErrorCounter(const Can_ControllerConfigType * Can_pControllerConfig)
{

    return FlexCAN_Ip_GetControllerRxErrorCounter(Can_pControllerConfig->Can_u8ControllerOffset);
}

/**
*   @brief      Write Pduinfo to Hw Buffer and request transmission
*/
Std_ReturnType Can_Ipw_Write
(
    const Can_ControllerConfigType * Can_pControllerConfig,
    const Can_HwObjectConfigType * Can_pHwObjectConfig,
    const Can_PduType * PduInfo
)
{
    Flexcan_Ip_StatusType eRetVal = FLEXCAN_STATUS_ERROR;
    Flexcan_Ip_DataInfoType DataInfo;
    uint8 u8ObjIdx = 0U;
#if (CAN_TRIGGER_TRANSMIT_USED == STD_ON)
    PduInfoType CanIf_PduInfo;
    uint8 Data[64U];
#endif

    DataInfo.msg_id_type = FLEXCAN_MSG_ID_STD;
    DataInfo.data_length = 0U;
    DataInfo.fd_padding = 0U;
    DataInfo.fd_enable = FALSE;
    DataInfo.enable_brs = FALSE;
    DataInfo.is_remote = FALSE;
    DataInfo.is_polling = FALSE;
    if (CAN_TX_NORMAL == Can_pHwObjectConfig->Can_eReceiveType)
    {
        DataInfo.msg_id_type = ((PduInfo->id & CAN_EXTENDED_ID_U32) != 0U) ? FLEXCAN_MSG_ID_EXT : FLEXCAN_MSG_ID_STD;
        DataInfo.data_length = PduInfo->length;
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
        DataInfo.fd_padding = Can_pHwObjectConfig->Can_u8PaddingValue;
        DataInfo.fd_enable = ((PduInfo->id & CAN_FD_FRAME_U32) != 0U) ? TRUE : FALSE;
    #if (CAN_SET_BAUDRATE_API == STD_ON)
            DataInfo.enable_brs = Can_pControllerConfig->Can_pBaudrateConfig[Can_au16ControllerBaudRateSel[Can_pControllerConfig->Can_u8ControllerID]].Can_bBitRateSwitch;
    #else
        DataInfo.enable_brs = Can_pControllerConfig->Can_pBaudrateConfig[Can_pControllerConfig->Can_u16DefaultBaudrateID].Can_bBitRateSwitch;
    #endif
#endif
        DataInfo.is_remote = FALSE;
        DataInfo.is_polling = Can_pHwObjectConfig->Can_bHwObjectUsesPolling;
        do
        {
            eRetVal = FlexCAN_Ip_GetTransferStatus(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx);
            if (FLEXCAN_STATUS_SUCCESS == eRetVal)
            {
                #if ((CAN_TX_POLLING_SUPPORT == STD_ON) || (FLEXCAN_IP_MB_INTERRUPT_SUPPORT == STD_ON))
                Can_Ipw_au16TxPduId[Can_pControllerConfig->Can_u8ControllerID][Can_pHwObjectConfig->Can_u8HwBufferIndex+u8ObjIdx] = PduInfo->swPduHandle;
                #endif
            #if (CAN_TRIGGER_TRANSMIT_USED == STD_ON)
                if ((TRUE == Can_pHwObjectConfig->Can_bTriggerTransmit) &&  (NULL_PTR == PduInfo->sdu))
                {
                    CanIf_PduInfo.SduDataPtr = Data;
                    CanIf_PduInfo.SduLength = (PduLengthType)Can_pHwObjectConfig->Can_u8PayloadLength;
                    if ((Std_ReturnType)E_OK == CanIf_TriggerTransmit(PduInfo->swPduHandle, &CanIf_PduInfo))
                    {
                        DataInfo.data_length = CanIf_PduInfo.SduLength;
                        eRetVal = FlexCAN_Ip_Send(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx, &DataInfo, PduInfo->id, Data);
                    }
                    else
                    {
                        eRetVal = FLEXCAN_STATUS_ERROR;
                    }
                }
                else
                {
            #endif
                    eRetVal = FlexCAN_Ip_Send(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx, &DataInfo, PduInfo->id, PduInfo->sdu);
            #if (CAN_TRIGGER_TRANSMIT_USED == STD_ON)
                }
            #endif
            }
            u8ObjIdx++;
        } while ((u8ObjIdx < Can_pHwObjectConfig->Can_u8ObjectCount) && (FLEXCAN_STATUS_BUSY == eRetVal));
    }

    if ((FLEXCAN_STATUS_SUCCESS != eRetVal) && (FLEXCAN_STATUS_BUSY != eRetVal))
    {
        eRetVal = FLEXCAN_STATUS_ERROR;
    }

    return ((FLEXCAN_STATUS_BUSY == eRetVal) ? ((Std_ReturnType)CAN_BUSY) : ((Std_ReturnType)eRetVal));
}

static void Can_Ipw_InitRx(const Can_ControllerConfigType * Can_pController)
{
    uint8 u8HwObjRefIdx = 0U;
    const Can_HwObjectConfigType * Can_pHwObject;
#if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
    uint8 u8FilterIdx = 0U;
    Flexcan_Ip_EnhancedIdTableType RxFifoFiltersEnhanced[128];
#endif
    Flexcan_Ip_DataInfoType DataInfo;

    /* This function just is called only if controller is in freeze mode */
    /* Always enable individual mask , Already in freeze mode */
    (void)FlexCAN_Ip_SetRxMaskType(Can_pController->Can_u8ControllerOffset, FLEXCAN_RX_MASK_INDIVIDUAL);

    for (u8HwObjRefIdx = 0U; u8HwObjRefIdx < Can_pController->Can_u8HwObjectRefCount; u8HwObjRefIdx++)
    {
        Can_pHwObject = (const Can_HwObjectConfigType *)Can_pController->Can_ppHwObject[u8HwObjRefIdx];

        if (CAN_RX_NORMAL == Can_pHwObject->Can_eReceiveType)
        {
            DataInfo.fd_enable = FALSE;
            DataInfo.data_length = 0U;
            if (Can_pHwObject->Can_IdMessage != CAN_STANDARD)
            {
                DataInfo.msg_id_type = FLEXCAN_MSG_ID_EXT;
            }
            else
            {
                DataInfo.msg_id_type = FLEXCAN_MSG_ID_STD;
            }
            (void)FlexCAN_Ip_ConfigRxMb(Can_pController->Can_u8ControllerOffset, Can_pHwObject->Can_u8HwBufferIndex, &DataInfo, Can_pHwObject->Can_pHwFilterConfig->Can_u32HwFilterCode);
            /* Already in freeze mode */
            (void)FlexCAN_Ip_SetRxIndividualMask(Can_pController->Can_u8ControllerOffset, Can_pHwObject->Can_u8HwBufferIndex, Can_pHwObject->Can_pHwFilterConfig->Can_u32HwFilterMask);
        }

        if (CAN_RX_LEGACY_FIFO == Can_pHwObject->Can_eReceiveType)
        {
            Can_Ipw_InitLegacyFifoFilter(Can_pController, Can_pHwObject);
        }
#if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
        if (CAN_RX_ENHANCED_FIFO == Can_pHwObject->Can_eReceiveType)
        {
            for (u8FilterIdx=0U; u8FilterIdx < Can_pHwObject->Can_u8HwFilterCount; u8FilterIdx++)
            {
                if (Can_pHwObject->Can_IdMessage != CAN_STANDARD)
                {
                    RxFifoFiltersEnhanced[u8FilterIdx].isExtendedFrame = TRUE;
                }
                else
                {
                    RxFifoFiltersEnhanced[u8FilterIdx].isExtendedFrame = FALSE;
                }
                /* The first 2 MSB bits are filter type encoding ! */
                if ((uint32)FLEXCAN_IP_ENHANCED_RX_FIFO_TWO_ID_FILTER == ((Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterCode & 0xC0000000U) >> 30U))
                {
                    RxFifoFiltersEnhanced[u8FilterIdx].filterType = FLEXCAN_IP_ENHANCED_RX_FIFO_TWO_ID_FILTER;
                }
                else if ((uint32)FLEXCAN_IP_ENHANCED_RX_FIFO_RANGE_ID_FILTER == ((Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterCode & 0xC0000000U) >> 30U))
                {
                    RxFifoFiltersEnhanced[u8FilterIdx].filterType = FLEXCAN_IP_ENHANCED_RX_FIFO_RANGE_ID_FILTER;
                }
                else
                {
                    RxFifoFiltersEnhanced[u8FilterIdx].filterType = FLEXCAN_IP_ENHANCED_RX_FIFO_ONE_ID_FILTER;
                }
                RxFifoFiltersEnhanced[u8FilterIdx].rtr1 = TRUE;
                RxFifoFiltersEnhanced[u8FilterIdx].rtr2 = FALSE;
                if (FLEXCAN_IP_ENHANCED_RX_FIFO_TWO_ID_FILTER == RxFifoFiltersEnhanced[u8FilterIdx].filterType)
                {
                    RxFifoFiltersEnhanced[u8FilterIdx].rtr1 = FALSE;
                }
                RxFifoFiltersEnhanced[u8FilterIdx].id1 = Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterMask;
                RxFifoFiltersEnhanced[u8FilterIdx].id2 = Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterCode & 0x3FFFFFFFU;
            }

            (void)FlexCAN_Ip_ConfigEnhancedRxFifo(Can_pController->Can_u8ControllerOffset, &RxFifoFiltersEnhanced[0]);
        }
#endif
    }
}


#if (CAN_ABORT_MB_API == STD_ON)
    /**
    *   @brief      Cancel of a pending CAN transmission
    */
    void Can_Ipw_AbortMb
    (
        const Can_ControllerConfigType * Can_pControllerConfig,
        const Can_HwObjectConfigType * Can_pHwObjectConfig
    )
    {
        uint8 u8Idx=0U;

        do
        {
            /* @violates @ref Can_Ipw_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
            (void)FlexCAN_Ip_AbortTransfer(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex + u8Idx);
            u8Idx++;
        }while (u8Idx < Can_pHwObjectConfig->Can_u8ObjectCount);
    }
#endif

#if (CAN_DUAL_CLOCK_MODE == STD_ON)
    /**
    *   @brief      Switch to another clock by changing controller's prescaler
    */
    void Can_Ipw_SetClockMode
    (
        const Can_ControllerConfigType * Can_pControllerConfig,
        uint16 Can_u16BaudrateID,
        Can_ClockModeType Can_eClkMode
    )
    {
        Flexcan_Ip_TimeSegmentType FlexCANtimeSeg;

        if (Can_Ipw_eClockMode[Can_pControllerConfig->Can_u8ControllerID] != Can_eClkMode)
        {
            Can_Ipw_eClockMode[Can_pControllerConfig->Can_u8ControllerID] = Can_eClkMode;

            if (CAN_CLOCKMODE_NORMAL == Can_Ipw_eClockMode[Can_pControllerConfig->Can_u8ControllerID])
            {
                FlexCANtimeSeg.preDivider = Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_NominalBitRate.Can_u16Prescaler;
            }
            else
            {
                FlexCANtimeSeg.preDivider = Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_NominalBitRate.Can_u16PrescalerAlternate;
            }

            FlexCANtimeSeg.propSeg    = Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_NominalBitRate.Can_u8PropSeg;
            FlexCANtimeSeg.phaseSeg1  = Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_NominalBitRate.Can_u8PhaseSeg1;
            FlexCANtimeSeg.phaseSeg2  = Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_NominalBitRate.Can_u8PhaseSeg2;
            FlexCANtimeSeg.rJumpwidth = Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_NominalBitRate.Can_u8ResyncJumpWidth;

            (void)FlexCAN_Ip_SetBitrate(Can_pControllerConfig->Can_u8ControllerOffset, &FlexCANtimeSeg, Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_bEnhanceCBTEnable);

            if (TRUE == Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_bFDFrame)
            {
                if (CAN_CLOCKMODE_NORMAL == Can_Ipw_eClockMode[Can_pControllerConfig->Can_u8ControllerID])
                {
                    FlexCANtimeSeg.preDivider = Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_DataBitRate.Can_u16Prescaler;
                }
                else
                {
                    FlexCANtimeSeg.preDivider = Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_DataBitRate.Can_u16PrescalerAlternate;
                }

                FlexCANtimeSeg.propSeg    = Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_DataBitRate.Can_u8PropSeg;
                FlexCANtimeSeg.phaseSeg1  = Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_DataBitRate.Can_u8PhaseSeg1;
                FlexCANtimeSeg.phaseSeg2  = Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_DataBitRate.Can_u8PhaseSeg2;
                FlexCANtimeSeg.rJumpwidth = Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_DataBitRate.Can_u8ResyncJumpWidth;

                (void)FlexCAN_Ip_SetBitrateCbt(Can_pControllerConfig->Can_u8ControllerOffset, &FlexCANtimeSeg, Can_pControllerConfig->Can_pBaudrateConfig[Can_u16BaudrateID].Can_bBitRateSwitch);
            }
        }
    }
#endif

#if (CAN_TX_POLLING_SUPPORT == STD_ON)
    /**
    *   @brief     Polling Tx Confirmation
    */
    void Can_Ipw_MainFunction_Write
    (
        const Can_ControllerConfigType * Can_pControllerConfig,
        const Can_HwObjectConfigType * Can_pHwObjectConfig
    )
    {
        uint8 u8ObjIdx = 0U;

        do
        {
            if (FLEXCAN_MB_TX_BUSY == ((Can_Ipw_apxStatus[Can_pControllerConfig->Can_u8ControllerID])->mbs[Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx].state))
            {
                /* @violates @ref Can_Ipw_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
                FlexCAN_Ip_MainFunctionWrite(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx);
                if (FLEXCAN_STATUS_SUCCESS == FlexCAN_Ip_GetTransferStatus(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx))
                {
                    CanIf_TxConfirmation(Can_Ipw_au16TxPduId[Can_pControllerConfig->Can_u8ControllerID][Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx]);
    #if (CAN_TIMESTAMP_ENABLE == STD_ON)
                    if (TRUE == Can_pHwObjectConfig->CanTimestampEnable)
                    {
                        uint32 timestamp = Can_Ipw_apxStatus[Can_pControllerConfig->Can_u8ControllerID]->mbs[Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx].time_stamp;

                        Can_pControllerConfig->CanTxTimestampNotification(Can_pHwObjectConfig->Can_HwObjectID,
                                                                            Can_Ipw_au16TxPduId[Can_pControllerConfig->Can_u8ControllerID][Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx],
                                                                            timestamp);
                    }
    #endif
                }
            }
            u8ObjIdx++;
        }while (u8ObjIdx < Can_pHwObjectConfig->Can_u8ObjectCount);
    }
#endif

#if (CAN_RX_POLLING_SUPPORT == STD_ON)
    /**
    *   @brief     Polling Rx Indication
    */
    void Can_Ipw_MainFunction_Read
    (
        const Can_ControllerConfigType * Can_pControllerConfig,
        const Can_HwObjectConfigType * Can_pHwObjectConfig
    )
    {
        /* @violates @ref Can_Ipw_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
        static Flexcan_Ip_MsgBuffType ReceivedDataBuffer;
        static Can_HwType CanIf_Mailbox;
        static PduInfoType CanIf_PduInfo;

        if (FALSE == FlexCAN_Ip_GetStopMode(Can_pControllerConfig->Can_u8ControllerOffset))
        {
        if (CAN_RX_NORMAL == Can_pHwObjectConfig->Can_eReceiveType)
        {
            (void)FlexCAN_Ip_Receive(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex, &ReceivedDataBuffer, Can_pHwObjectConfig->Can_bHwObjectUsesPolling);
            FlexCAN_Ip_MainFunctionRead(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex);

            if (FLEXCAN_STATUS_SUCCESS == FlexCAN_Ip_GetTransferStatus(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex))
            {
                Can_Ipw_ParseData(&CanIf_Mailbox, \
                                  &CanIf_PduInfo, \
                                  &ReceivedDataBuffer, \
                                  Can_pControllerConfig, \
                                  Can_pHwObjectConfig \
                                 );
            }
        }
        else if (CAN_RX_LEGACY_FIFO == Can_pHwObjectConfig->Can_eReceiveType)
        {
            Can_Ipw_ProcessLegacyFifoPolling(&CanIf_Mailbox, \
                                             &CanIf_PduInfo, \
                                             &ReceivedDataBuffer, \
                                             Can_pControllerConfig, \
                                             Can_pHwObjectConfig \
                                            );
        }
        #if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
        else if (CAN_RX_ENHANCED_FIFO == Can_pHwObjectConfig->Can_eReceiveType)
        {
            Can_Ipw_ProcessEnhancedFifoPolling(&CanIf_Mailbox, \
                                               &CanIf_PduInfo, \
                                               &ReceivedDataBuffer, \
                                               Can_pControllerConfig, \
                                               Can_pHwObjectConfig \
                                              );
        }
        #endif /*(CAN_ENHANCED_FIFO_ENABLED == STD_ON) */
        else
        {
            /* prevent misra */
        }
        }
    }
#endif

#if (CAN_BUSOFF_POLLING_SUPPORT == STD_ON)
    /**
    *   @brief     Polling Bus Off
    */
    void Can_Ipw_MainFunction_BusOff(const Can_ControllerConfigType * Can_pControllerConfig)
    {
        (void)FlexCAN_Ip_MainFunctionBusOff(Can_pControllerConfig->Can_u8ControllerOffset);
    }
#endif

/**
*   @brief     Polling Controller Mode Transitions
*/
void Can_Ipw_MainFunction_Mode
(
    const Can_ControllerConfigType * Can_pControllerConfig,
    Can_ControllerStateType * Can_pControllerState
)
{
    /* @violates @ref Can_Ipw_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
    if (CAN_CS_STARTED == *Can_pControllerState)
    {
        if (FALSE == FlexCAN_Ip_GetStartMode(Can_pControllerConfig->Can_u8ControllerOffset))
        {
            *Can_pControllerState = CAN_CS_STOPPED;
            CanIf_ControllerModeIndication(Can_pControllerConfig->Can_u8AbstControllerID, CAN_CS_STOPPED);
        }
    }
    else if (CAN_CS_STOPPED == *Can_pControllerState)
    {
        if (TRUE == FlexCAN_Ip_GetStartMode(Can_pControllerConfig->Can_u8ControllerOffset))
        {
            *Can_pControllerState = CAN_CS_STARTED;
            CanIf_ControllerModeIndication(Can_pControllerConfig->Can_u8AbstControllerID, CAN_CS_STARTED);
        }
    }
    else
    {
        /* nothing to do */
    }
}

#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
    /**
    *   @brief     Process Tx Interrupt
    */
    void Can_Ipw_ProcessTxMesgBuffer
    (
        const Can_ControllerConfigType * Can_pControllerConfig,
        const Can_HwObjectConfigType * Can_pHwObjectConfig,
        uint8 u8MbIdx
    )
    {
    #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        uint32 TimeStamp;
    #endif /* (CAN_TIMESTAMP_ENABLE == STD_ON) */
        Can_HwHandleType u8HwObjectID = 0U;

        u8HwObjectID = Can_Ipw_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][u8MbIdx];
        if ((CAN_HWOBJ_UNMAPPED != u8HwObjectID) && (FALSE == Can_pHwObjectConfig[u8HwObjectID].Can_bHwObjectUsesPolling))
        {
            if (CAN_TX_NORMAL == Can_pHwObjectConfig[u8HwObjectID].Can_eReceiveType)
            {
                CanIf_TxConfirmation(Can_Ipw_au16TxPduId[Can_pControllerConfig->Can_u8ControllerID][u8MbIdx]);
    #if (CAN_TIMESTAMP_ENABLE == STD_ON)
                if (TRUE == Can_pHwObjectConfig[u8HwObjectID].CanTimestampEnable)
                {
                    TimeStamp = Can_Ipw_apxStatus[Can_pControllerConfig->Can_u8ControllerID]->mbs[u8MbIdx].time_stamp;
                    Can_pControllerConfig->CanTxTimestampNotification(Can_pHwObjectConfig[u8HwObjectID].Can_HwObjectID,
                                                                      Can_Ipw_au16TxPduId[Can_pControllerConfig->Can_u8ControllerID][u8MbIdx],
                                                                      TimeStamp
                                                                     );
                }
    #endif /* (CAN_TIMESTAMP_ENABLE == STD_ON) */
            }
        }
    }

    /**
    *   @brief     Process Rx Interrupt
    */
    void Can_Ipw_ProcessRxMesgBuffer
    (
        const Can_ControllerConfigType * Can_pControllerConfig,
        const Can_HwObjectConfigType * Can_pHwObjectConfig,
        uint8 u8MbIdx
    )
    {
        Can_HwHandleType u8HwObjectID = 0U;
        static Can_HwType CanIf_Mailbox;
        static PduInfoType CanIf_PduInfo;
        const Can_HwObjectConfigType * Can_pHwObject = NULL_PTR;
        Flexcan_Ip_MsgBuffType * pReceivedDataBuffer = NULL_PTR;

        u8HwObjectID = Can_Ipw_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][u8MbIdx];
        if ((CAN_HWOBJ_UNMAPPED != u8HwObjectID) && (FALSE == Can_pHwObjectConfig[u8HwObjectID].Can_bHwObjectUsesPolling))
        {
            Can_pHwObject = &Can_pHwObjectConfig[u8HwObjectID];

            if (CAN_RX_NORMAL == Can_pHwObject->Can_eReceiveType)
            {
                pReceivedDataBuffer = (Can_Ipw_apxStatus[Can_pControllerConfig->Can_u8ControllerID])->mbs[Can_pHwObject->Can_u8HwBufferIndex].pMBmessage;
                Can_Ipw_ParseData(&CanIf_Mailbox, \
                                  &CanIf_PduInfo, \
                                  pReceivedDataBuffer, \
                                  Can_pControllerConfig, \
                                  Can_pHwObject \
                                 );
                /* ready to receive in next time */
                (void)FlexCAN_Ip_Receive(Can_pControllerConfig->Can_u8ControllerOffset, \
                                         Can_pHwObject->Can_u8HwBufferIndex, \
                                         NULL_PTR, \
                                         Can_pHwObject->Can_bHwObjectUsesPolling \
                                        );
            }
            else if (CAN_RX_LEGACY_FIFO == Can_pHwObject->Can_eReceiveType)
            {
                if ((uint8)7U == u8MbIdx)
                {
                    (void)Det_ReportRuntimeError((uint16)CAN_IPW_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);

                    if (NULL_PTR != Can_pControllerConfig->Can_pLegacyFiFoOvfNotif)
                    {
                        Can_pControllerConfig->Can_pLegacyFiFoOvfNotif();
                    }
                }
                else if ((uint8)6U == u8MbIdx)
                {
                    if (NULL_PTR != Can_pControllerConfig->Can_pLegacyFiFoWarnNotif)
                    {
                        Can_pControllerConfig->Can_pLegacyFiFoWarnNotif();
                    }
                }
                else
                {
                    pReceivedDataBuffer = (Can_Ipw_apxStatus[Can_pControllerConfig->Can_u8ControllerID])->mbs[Can_pHwObject->Can_u8HwBufferIndex].pMBmessage;
                    Can_Ipw_ParseData(&CanIf_Mailbox, \
                                      &CanIf_PduInfo, \
                                      pReceivedDataBuffer, \
                                      Can_pControllerConfig, \
                                      Can_pHwObject \
                                     );
                    /* ready to receive in next time */
                    (void)FlexCAN_Ip_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, NULL_PTR);
                }
            }
            else
            {
                /* prevent misra */
            }
        }
    }

#if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
/**
*   @brief     Process Rx Interrupt
*/
void Can_Ipw_ProcessRxLegacyDma
(
    const Can_ControllerConfigType * Can_pControllerConfig,
    const Can_HwObjectConfigType * Can_pHwObjectConfig,
    uint8 u8Event
)
{
    Can_HwHandleType u8HwObjectID = 0U;
    static Can_HwType CanIf_Mailbox;
    static PduInfoType CanIf_PduInfo;

    u8HwObjectID = Can_Ipw_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][CAN_IPW_RX_LEGACY_FIFO_MB_HANDLER];
    if ((CAN_HWOBJ_UNMAPPED != u8HwObjectID) && (FALSE == Can_pHwObjectConfig[u8HwObjectID].Can_bHwObjectUsesPolling))
    {
        if ((uint8)FLEXCAN_EVENT_DMA_COMPLETE == u8Event)
        {
                Can_Ipw_ParseData(&CanIf_Mailbox, \
                                  &CanIf_PduInfo, \
                                  &Can_pControllerConfig->pDmaDstAddr[0], \
                                  Can_pControllerConfig, \
                                  &Can_pHwObjectConfig[u8HwObjectID] \
                                 );
                /* ready to receive in next time */
                (void)FlexCAN_Ip_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, Can_pControllerConfig->pDmaDstAddr);
        }
        else if ((uint8)FLEXCAN_EVENT_DMA_ERROR == u8Event)
        {
            (void)Det_ReportRuntimeError((uint16)CAN_IPW_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);

            if (NULL_PTR != Can_pControllerConfig->Can_pDmaErrorNotif)
            {
                Can_pControllerConfig->Can_pDmaErrorNotif();
            }

            /* although DMA errors occurred, expect to ready to receive in next time */
            (void)FlexCAN_Ip_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, Can_pControllerConfig->pDmaDstAddr);
        }
        else
        {
            /* nothing to do */
        }
    }
}
#endif /* End of (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON) */

#if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
/**
*   @brief     Process Rx Enhance FIFO Interrupt
*/
    void Can_Ipw_ProcessRxEnhance
    (
        const Can_ControllerConfigType * Can_pControllerConfig,
        const Can_HwObjectConfigType * Can_pHwObjectConfig,
        uint8 u8Event
    )
    {
        static Can_HwType CanIf_Mailbox;
        static PduInfoType CanIf_PduInfo;
        Flexcan_Ip_MsgBuffType * pReceivedDataBuffer = NULL_PTR;
    #if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
        uint32 u32MbCnt = 0U;
    #endif /* (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON) */

        if ((uint8)FLEXCAN_EVENT_ENHANCED_RXFIFO_OVERFLOW == u8Event)
        {
            (void)Det_ReportRuntimeError((uint16)CAN_IPW_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
            if (NULL_PTR != Can_pControllerConfig->Can_pEnhanceFiFoOvfNotif)
            {
                Can_pControllerConfig->Can_pEnhanceFiFoOvfNotif();
            }
        }
        else if ((uint8)FLEXCAN_EVENT_ENHANCED_RXFIFO_COMPLETE == u8Event)
        {
            pReceivedDataBuffer = (Can_Ipw_apxStatus[Can_pControllerConfig->Can_u8ControllerID])->enhancedFifoOutput.pMBmessage;

            Can_Ipw_ParseData(&CanIf_Mailbox, \
                              &CanIf_PduInfo, \
                              pReceivedDataBuffer, \
                              Can_pControllerConfig, \
                              Can_pHwObjectConfig \
                             );
            /* ready to receive in next time */
            (void)FlexCAN_Ip_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, NULL_PTR);
        }
    #if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
        else if ((uint8)FLEXCAN_EVENT_DMA_COMPLETE == u8Event)
        {
            for (u32MbCnt = 0; u32MbCnt < Can_pControllerConfig->HwChannelIpConfig->pFlexcanIpHwConfig->num_enhanced_watermark; u32MbCnt++)
            {
                Can_Ipw_ParseData(&CanIf_Mailbox, \
                                  &CanIf_PduInfo, \
                                  &Can_pControllerConfig->pDmaDstAddr[u32MbCnt], \
                                  Can_pControllerConfig, \
                                  Can_pHwObjectConfig \
                                 );
            }
            /* ready to receive in next time */
            (void)FlexCAN_Ip_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, Can_pControllerConfig->pDmaDstAddr);
        }
        else if ((uint8)FLEXCAN_EVENT_DMA_ERROR == u8Event)
        {
            (void)Det_ReportRuntimeError((uint16)CAN_IPW_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);

            if (NULL_PTR != Can_pControllerConfig->Can_pDmaErrorNotif)
            {
                Can_pControllerConfig->Can_pDmaErrorNotif();
            }

            /* although DMA errors occurred, expect to ready to receive in next time */
            (void)FlexCAN_Ip_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, Can_pControllerConfig->pDmaDstAddr);
        }
    #endif /* (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON) */
        else
        {
            /* prevent misra */
        }
    }
#endif /* (CAN_ENHANCED_FIFO_ENABLED == STD_ON) */
#endif /* (CAN_MB_INTERRUPT_SUPPORT == STD_ON) */

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
Std_ReturnType Can_Ipw_DeactivateIcomConfiguration(const Can_ControllerConfigType * Can_pControllerConfig)
{
    boolean IsStart = TRUE;
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

    if ((uint8)0U == Can_pControllerConfig->Can_u8ControllerOffset)
    {
        
        if(TRUE == FlexCAN_Ip_GetStartMode(Can_pControllerConfig->Can_u8ControllerOffset))
        {
            IsStart = TRUE;
        }
        else
        {
            IsStart = FALSE;
        }
        if (FLEXCAN_STATUS_SUCCESS == FlexCAN_Ip_EnterFreezeMode(Can_pControllerConfig->Can_u8ControllerOffset))
        {
            /* Deactivate PN */
            (void)FlexCAN_Ip_ConfigPN(Can_pControllerConfig->Can_u8ControllerOffset, FALSE, NULL_PTR);
            if (TRUE == IsStart)
            {
                /* back to start mode */
                ReturnValue = (FLEXCAN_STATUS_SUCCESS == FlexCAN_Ip_ExitFreezeMode(Can_pControllerConfig->Can_u8ControllerOffset)) ? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK);
            }
            else
            {
                /* back to stop mode */
                ReturnValue = (FLEXCAN_STATUS_SUCCESS == FlexCAN_Ip_SetStopMode(Can_pControllerConfig->Can_u8ControllerOffset)) ? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK);
            }
        }
    }
    return ReturnValue;
}

Std_ReturnType Can_Ipw_SetIcomConfiguration(const Can_ControllerConfigType * Can_pControllerConfig, const Can_IcomConfigsType * pIcomConfig)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

    if ((uint8)0U == Can_pControllerConfig->Can_u8ControllerOffset)
    {
        if (FLEXCAN_STATUS_SUCCESS == FlexCAN_Ip_EnterFreezeMode(Can_pControllerConfig->Can_u8ControllerOffset))
        {
            /* Activate PN */
            (void)FlexCAN_Ip_ConfigPN(Can_pControllerConfig->Can_u8ControllerOffset, TRUE, pIcomConfig->pCanIcomRxMessageConfigs->pFlexcanIpPnConfig);
            ReturnValue = (FLEXCAN_STATUS_SUCCESS == FlexCAN_Ip_ExitFreezeMode(Can_pControllerConfig->Can_u8ControllerOffset)) ? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK);
        }
    }
    return ReturnValue;
}

void Can_Ipw_ProcessPN(const Can_ControllerConfigType * Can_pControllerConfig, const Can_IcomConfigsType * pIcomConfig)
{
    static Can_HwType CanIf_Mailbox;
    static PduInfoType CanIf_PduInfo;
    Flexcan_Ip_MsgBuffType ReceivedDataBuffer;
    uint8 u8WmbIndex = 0;
    uint8 u8NumOfWmb = 0U;

    u8NumOfWmb = ((pIcomConfig->pCanIcomRxMessageConfigs->pFlexcanIpPnConfig->u16NumMatches) < 4U) ? ((uint8)pIcomConfig->pCanIcomRxMessageConfigs->pFlexcanIpPnConfig->u16NumMatches) : ((uint8)4U);

    for (u8WmbIndex = 0U; u8WmbIndex < u8NumOfWmb; u8WmbIndex++)
    {
        FlexCAN_Ip_GetWMB(Can_pControllerConfig->Can_u8ControllerOffset, u8WmbIndex, &ReceivedDataBuffer);
        CanIf_Mailbox.CanId = ReceivedDataBuffer.msgId;
        /*
        * [SWS_Can_00423] ⌈ In case of an Extended CAN frame, the Can module shall
        * convert the ID to a standardized format since the Upper layer (CANIF) does not know
        * whether the received CAN frame is a Standard CAN frame or Extended CAN frame.
        * In case of an Extended CAN frame, MSB of a received CAN frame ID needs to be
        * made as ‘1’ to mark the received CAN frame as Extended.⌋
        */
        if (((ReceivedDataBuffer.cs) & CAN_IPW_CS_IDE_MASK) != 0U)
        {
            CanIf_Mailbox.CanId |= (uint32)0x80000000U;
        }

    #if (CAN_LPDU_CALLOUT_SUPPORT == STD_ON)
        if (TRUE == CAN_LPDU_CALLOUT_FUNC_CALLED((uint8)pIcomConfig->u8CanIcomConfigId, \
                                                          CanIf_Mailbox.CanId, \
                                                          ReceivedDataBuffer.dataLen, \
                                                          &ReceivedDataBuffer.data[0]) \
                                                         )
        {
    #endif
            CanIf_Mailbox.Hoh = (uint8)pIcomConfig->u8CanIcomConfigId;
            CanIf_Mailbox.ControllerId = Can_pControllerConfig->Can_u8AbstControllerID;
            CanIf_PduInfo.SduLength = ReceivedDataBuffer.dataLen;
            CanIf_PduInfo.SduDataPtr = &ReceivedDataBuffer.data[0];
            CanIf_RxIndication(&CanIf_Mailbox, &CanIf_PduInfo);
    #if (CAN_LPDU_CALLOUT_SUPPORT == STD_ON)
        }
    #endif
    }
}
#endif /* (CAN_PUBLIC_ICOM_SUPPORT == STD_ON) */

#define CAN_STOP_SEC_CODE
/* @violates @ref Can_Ipw_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_Ipw_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_MemMap.h"
#ifdef __cplusplus
}
#endif

/** @} */
