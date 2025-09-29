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

#ifndef CAN_H
#define CAN_H

/**
*   @file    Can.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface.
*   @details API header for CAN driver.
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
* @section Can_h_REF_1
* Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents
* of a header file being included more than once.
* This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
*
* @section Can_h_REF_2
* Violates MISRA 2012 Advisory Rule 2.5, A project should not contain unused macro declarations.
* Declaration is reserved for future feature.
*
* @section Can_h_REF_3
* Violates MISRA 2012 Advisory Rule 4.9, A function should be used in preference to a function-like macro where they are interchangeable.
* Function like macro are used to reduce code complexity
*
* @section Can_h_REF_4
* Violates MISRA 2012 Advisory Rule 2.3, A project should not contain unused type declarations.
* The declarations are used depend on user configuration.
*
* @section Can_h_REF_5
* Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block scope if identifier only appears in a single function.
* These objects are used when Precompile is supported.
*
* @section Can_h_REF_6
* Violates MISRA 2012 Advisory Rule 20.1, #include directives should only be preceded by preprocessor
* directives or comments.
*/

/*
(CAN043) The file Can.h contains the declaration of the Can module API.
(CAN037) The file Can.h only contains 'extern' declarations of constants, global data, type definitions and services
            that are specified in the Can module SWS.
*/

/**
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
*
*/
#include "ComStackTypes.h"
#include "Soc_Ips.h"
#include "Can_Flexcan_Types.h"
#include "Can_Ipw_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
    Internal micro-dependent versioning. Check of AUTOSAR & Vendor specification version.
*/
/**
* @{
*
*/
#define CAN_VENDOR_ID                   43
/* @violates @ref Can_h_REF_2 MISRA 2012 Advisory Rule 2.5 */
#define CAN_MODULE_ID                   80
#define CAN_AR_RELEASE_MAJOR_VERSION    4
#define CAN_AR_RELEASE_MINOR_VERSION    4
#define CAN_AR_RELEASE_REVISION_VERSION 0
#define CAN_SW_MAJOR_VERSION            1
#define CAN_SW_MINOR_VERSION            0
#define CAN_SW_PATCH_VERSION            1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can_Ipw_Types header file are of the same vendor */
#if (CAN_VENDOR_ID != CAN_IPW_TYPES_VENDOR_ID_H)
    #error "Can.h and Can_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and Can_Ipw_Types header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != CAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION != CAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION != CAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can.h and Can_Ipw_Types.h are different"
#endif

/* Check if current file and Can_Ipw_Types header file are of the same software version */
#if ((CAN_SW_MAJOR_VERSION != CAN_IPW_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION != CAN_IPW_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION != CAN_IPW_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can.h and Can_Ipw_Types.h are different"
#endif

/* Check if current file and Can_Flexcan_Types header file are of the same vendor */
#if (CAN_VENDOR_ID != CAN_FLEXCAN_TYPES_VENDOR_ID_H)
    #error "Can.h and Can_Flexcan_Types.h have different vendor ids"
#endif
/* Check if current file and Can_Flexcan_Types header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION != CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION != CAN_FLEXCAN_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can.h and Can_Flexcan_Types.h are different"
#endif

/* Check if current file and Can_Ipw_Types header file are of the same software version */
#if ((CAN_SW_MAJOR_VERSION != CAN_FLEXCAN_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION != CAN_FLEXCAN_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION != CAN_FLEXCAN_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can.h and Can_Flexcan_Types.h are different"
#endif

/* Check if current file and CAN configuration header file are of the same software version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CAN_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of Can.h and Soc_Ips.h are different"
    #endif

    /* Check if current file and ComStackTypes header file are of the same Autosar version */
    #if ((CAN_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Can.h and ComStackTypes.h are different"
    #endif

#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    /**
    * @brief          Can_StatusType
    * @details        CAN Driver status used for checking and preventing double driver intialization.
    *                 CAN_UNINIT = The CAN controller is not initialized. The CAN Controller is not participating on the CAN bus.
    *                              All registers belonging to the CAN module are in reset state, CAN interrupts are disabled.
    *                 CAN_READY = Controller has initialized: static variables, including flags;
    *                             Common setting for the complete CAN HW unit; CAN controller specific settings for each CAN controller.
    *
    */
    typedef enum
    {
        CAN_UNINIT = 0U, /**< @brief Driver not initialized */
        CAN_READY       /**< @brief Driver ready */
    }Can_DriverStatusType;
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief Can Configuration */
typedef struct
{
    /** @brief Configuration Core ID */
    const uint32 Can_u32CoreID;
    /** @brief The first Hth after Hrh consecutive */
    const Can_HwHandleType Can_uHthFirstIndex;
    /** @brief Mapping Controller ID to Controller hardware offset */
    const uint8 * Can_pCtrlOffsetToCtrlIDMap;
    /** @brief Mapping Controller ID to Hardware Object ID */
    const uint8 * Can_pHwObjIDToCtrlIDMap;
    /** @brief Pointer to Can Hardware Object Config */
    const Can_HwObjectConfigType * Can_pHwObjectConfig;
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
    /** @brief The size of Can Pn Configs */
    const uint8 u8NumCanIcomConfigs;
    /** brief Pointer point to Can Pn Configs */
    const Can_IcomConfigsType * pCanIcomConfigs;
#endif /* (!!CAN##!!_##PUBLIC_ICOM_SUPPORT == STD_ON) */
    /** @brief Pointer to Can Controller Config */
    const Can_ControllerConfigType * const * Can_ppController;
}Can_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_h_REF_1 MISRA 2012 Required Directive 4.10 */
#include "Can_MemMap.h"

CAN_CONFIG_EXT

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_h_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_h_REF_6 MISRA 2012 Advisory Rule 20.1 */
#include "Can_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define CAN_START_SEC_CODE
/* @violates @ref Can_h_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_h_REF_6 MISRA 2012 Advisory Rule 20.1 */
#include "Can_MemMap.h"

#if (CAN_VERSION_INFO_API == STD_ON)
    /**
    * @brief          Returns the version information of this module. SID is 0x07
    * @details        This routine is called by:
    *                - CanIf or an upper layer according to Autosar requirements.
    *
    * @param[in]      versioninfo A pointer to location to store version info
    *                             Must be omitted if the function does not have parameters.
    *
    * @return         void
    *
    *
    * @pre            The CAN_VERSION_INFO_API define must be configured on.
    * @post           The version information is return if the parameter versionInfo is not a null pointer.
    *
    *
    */
    void Can_GetVersionInfo(Std_VersionInfoType * versioninfo);
#endif /* CAN_VERSION_INFO_API == STD_ON */

/**
* @brief          Initialize the CAN driver. SID is 0x00.
* @details        Initialize all the controllers.
*                 The CAN module shall be initialized by Can_Init(<&Can_Configuration>) service call during the start-up.
*                 This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Config Pointer to driver configuration.
*
* @return         void
*
*
* @pre            Can_Init shall be called at most once during runtime.
* @post           Can_Init shall initialize all the controllers and set the driver in READY state.
*
*/
void Can_Init(const Can_ConfigType * Config);

/**
* @brief          De-initialize the CAN driver. SID is 0x10.
* @details        De-initialize all the controllers.
*                 The CAN module shall be de-initialized by Can_DeInit() service call during the start-up.
*                 This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      None
*
* @return         void
*
*
* @pre            Before controller de-initalization, the driver must be initialized and the controllers must be not in Start state.
* @post           Can_DeInit shall de-initialize all the controllers and set the driver in UNINIT state.
*
*/
void Can_DeInit(void);

#if (CAN_SET_BAUDRATE_API == STD_ON)
    /**
    * @brief         This function set baudrate
    * @details       This routine is called by an upper layer.
    *
    * @param[in]     Controller controller ID
    * @param[in]     BaudRateConfigID baudrateID selection
    *
    * @return        Std_ReturnType  Result of the transition.
    * @retval        E_OK  Switch baudrate operation was ok.
    * @retval        E_NOT_OK  Switch baudrate operation was not ok.
    *
    * @pre           Driver must be initialized.
    */
    Std_ReturnType Can_SetBaudrate
    (
        uint8 Controller,
        uint16 BaudRateConfigID
    );
#endif /* CAN_SET_BAUDRATE_API == STD_ON */

/**
* @brief          Put the controller into a required state. SID is 0x03.
* @details        Switch the controller from one state to another.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller - Can controller for which the status shall be changed - based on configuration order list (CanControllerId).
* @param[in]      Transition - Possible transitions (CAN_CS_STOPPED , CAN_CS_STARTED , CAN_CS_SLEEP)
* @return         Std_ReturnType  Result of the transition.
* @retval         E_OK   request accepted.
* @retval         E_NOT_OK  request not accepted, a development error occurred.
*
*
* @pre            Before changing the controller state the driver must be initialized.
* @post           After the transition to the new state the interrupts required for that state must be enebaled.
*
*
*/
Std_ReturnType Can_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition);

#if (CAN_LISTEN_ONLY_MODE == STD_ON)
/**
* @brief          Enable or disable Listen Only Mode. SID is 0x32.
* @details        Enable or disable Listen Only Mode.
* @param[in]      Controller - Controller in which ListenOnlyMode will be enabled/disabled.
* @param[in]      State - Enable or Disable the feature (NORMAL_MODE , LISTEN_ONLY_MODE)
* @return         Std_ReturnType  Result of the transition.
* @retval         E_OK   request accepted.
* @retval         E_NOT_OK  request not accepted, a development error occurred.
*
* @pre
* @post
*
*
*/
Std_ReturnType Can_ListenOnlyMode(uint8 Controller, Can_ListenOnlyType State);
#endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */

/**
* @brief          Disable INTs. SID is 0x04.
* @details        Switch OFF the controller's interrupts.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller Can controller for which interrupts shall be disabled - based on configuration order list (CanControllerId).
*
* @return         void
*
*
* @pre            Driver must be initalzied before changing the interrupts state (en or dis).
* @post           Controller must not respond to any interrupt assertion.
*
*
*/
void Can_DisableControllerInterrupts(uint8 Controller);

/**
* @brief          Enable INTs. SID is 0x05.
* @details        Switch ON the controller's interrupts.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller Can controller for which interrupts shall be disabled - based on configuration order list (CanControllerId).
*
* @return         void
*
*
* @pre            Driver must be initalzied before changing the interrupts state (en or dis).
* @post           Controller must respond to interrupt assertion.
*
*/
void Can_EnableControllerInterrupts(uint8 Controller);

#if (CAN_CHECK_WAKEUP_API == STD_ON)
    Std_ReturnType Can_CheckWakeup(uint8 Controller);
#endif

/**
* @brief          Obtains the error state of the CAN controller.. SID is 0x11
* @details        This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      ControllerId: Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested for ErrorState.
*
* @param[out]     ErrorStatePtr: Pointer to a memory location, where the error state of the CAN controller will be stored.
*
* @return         Std_ReturnType  Result of the transition.
* @retval         E_OK : Error state request has been accepted.
* @retval         E_NOT_OK : Error state request has not been accepted.
*
* @pre
* @post
*
*
*/
Std_ReturnType Can_GetControllerErrorState
(
    uint8 ControllerId,
    Can_ErrorStateType * ErrorStatePtr
);

/**
* @brief          Reports about the current status of the requested CAN controller. SID is 0x12
* @details        This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller: CAN controller for which the status shall be requested.
*
* @param[out]     ControllerModePtr: Pointer to a memory location, where the current mode of the CAN controller will be stored.
*
* @return         Std_ReturnType  Result of the transition.
* @retval         E_OK : Controller mode request has been accepted.
* @retval         E_NOT_OK : Controller mode request has not been accepted.
*
* @pre
* @post
*
*
*/
Std_ReturnType Can_GetControllerMode
(
    uint8 Controller,
    Can_ControllerStateType * ControllerModePtr
);

/**
* @brief            Return the Rx error counter for a CAN controller
* @details          Return the Rx error counter for a CAN controller. This value might not be
*                   available for all CAN controller, in which case E_NOT_OK would be returned.
*                   Please note that the value of the counter might not be correct at the moment
*                   the API returns it, because the Rx counter is handled asynchronously in hardware.
*                   Applications should not trust this value for any assumption about the current bus state.
*
* @param[in]        ControllerId: CAN controller, whose current Rx error counter shall be acquired.
* @param[out]       RxErrorCounterPtr: Pointer to a memory location, where the current Rx error
*                       counter of the CAN controller will be stored.
*
* @return           Std_ReturnType  Result of the transition.
* @retval           E_OK:  Rx error counter available.
* @retval           E_NOT_OK: Wrong ControllerId, or Rx error counter not available.
*
* @pre
* @post
*
*/
Std_ReturnType Can_GetControllerRxErrorCounter
(
    uint8 ControllerId,
    uint8 * RxErrorCounterPtr
);

/**
* @brief            Return the Tx error counter for a CAN controller
* @details          Return the Tx error counter for a CAN controller. This value might not be
*                   available for all CAN controller, in which case E_NOT_OK would be returned.
*                   Please note that the value of the counter might not be correct at the moment
*                   the API returns it, because the Tx counter is handled asynchronously in hardware.
*                   Applications should not trust this value for any assumption about the current bus state.
*
* @param[in]        ControllerId: CAN controller, whose current Tx error counter shall be acquired.
* @param[out]       TxErrorCounterPtr: Pointer to a memory location, where the current Tx error
*                       counter of the CAN controller will be stored.
*
* @return           Std_ReturnType  Result of the transition.
* @retval           E_OK:  Tx error counter available.
* @retval           E_NOT_OK: Wrong ControllerId, or Tx error counter not available.
*
* @pre
* @post
*
*/
Std_ReturnType Can_GetControllerTxErrorCounter
(
    uint8 ControllerId,
    uint8 * TxErrorCounterPtr
);

/**
* @brief          Transmit information on CAN bus. SID is 0x06.
* @details        Can_Write checks if hardware transmit object that is identified by the HTH is free.
*                    Can_Write checks if another Can_Write is ongoing for the same HTH.
*                     a) hardware transmit object is free:
*                         The mutex for that HTH is set to 'signaled' the ID, DLC and SDU are put in a format appropriate for
*                           the hardware (if necessary) and copied in the appropriate hardware registers or buffers.
*                        All necessary control operations to initiate the transmit are done.
*                         The mutex for that HTH is released. The function returns with E_OK.
*                    b) hardware transmit object is busy with another transmit request.
*                         The function returns with CAN_BUSY.
*                     c) A preemptive call of Can_Write has been issued, that could not be handled reentrant (i.e. a call with the same HTH).
*                        The function returns with CAN_BUSY the function is non blocking
*                     d) The hardware transmit object is busy with another transmit request for an L-PDU that has lower priority than that for the current request
*                        The transmission of the previous L-PDU is cancelled (asynchronously).
*                        The function returns with CAN_BUSY.
*                   This routine is called by:
*                   - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Hth Information which HW-transmit handle shall be used for transmit.
*                 Implicitly this is also the information about the controller to use because the Hth numbers are unique inside one hardware unit.
* @param[in]      PduInfo Pointer to SDU user memory, DLC and Identifier.
* @return         Std_ReturnType   Result of the write operation.
* @retval         E_OK   Write command has been accepted.
* @retval         E_NOT_OK  Development error occured.
* @retval         CAN_BUSY   No of TX hardware buffer available or preemtive call of Can_Write() that can't be implemented reentrant.
*
*
* @pre            Driver must be initialized and MB must be configured for Tx.
* @post           The data can be transmitted or rejected because of another data with a higher priority.
*
*
*/
Std_ReturnType Can_Write
(
    Can_HwHandleType Hth,
    const Can_PduType * PduInfo
);

#if (CAN_ABORT_MB_API == STD_ON)
    /**
    * @brief          Process a message buffer abort
    * @details        This function write a abort code (b'1001) to MBCS[CODE] field of the MB.
    *                This routine is called by:
    *                - CanIf or an upper layer according to Autosar requirements.
    *
    * @param[in]      Hth - HW-transmit handler
    *
    *
    * @pre            Driver must be initialized and the current MB transmission should be ready for transmit.
    *
    *
    * @note           Not AUTOSAR required. This is user implementation.
    */
    void Can_AbortMb(Can_HwHandleType Hth);
#endif /* CAN_ABORT_MB_API == STD_ON */

#if (CAN_DUAL_CLOCK_MODE == STD_ON)
    /**
    * @brief          Function switch between two prescaler that was configured when Clock Source value to driver changed to another one.
    * @details        Function sets all controllers' prescaller based on input parameter.
    *
    * @param[in]      eClkMode - prescaler setting (NORMAL or ALTERNATE)
    *
    * @pre            Can_Init must be called before, all controllers must be in STOPPED.
    *
    */
    void Can_SetClockMode(Can_ClockModeType eClkMode);
#endif

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/**
* @brief          Set controller into Pretended Networking mode with the ConfigurationID valid.
* @details        This function is API which support the Pretended Networking featrue. After this function is called,
*                 it will configure for controller with information in the configurationIDs (corresponding with ID valid )

*
* @param[in]      Controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      ConfigurationId the ID of CanIcomConfig
*
* @return        Std_ReturnType
* @retval        E_OK       PNET is Enabled/disabled successfully.
* @retval        E_NOT_OK   PNET is not Enabled/disabled successfully.
*
* @pre            Driver must be initialized
*
* @note           In order to activate PNET (ConfigurationId != 0) the controller must be in START mode.
* @implements    Can_SetIcomConfiguration_Activity
*/
Std_ReturnType Can_SetIcomConfiguration(uint8 Controller, IcomConfigIdType ConfigurationId);
#endif /* (CAN_PUBLIC_ICOM_SUPPORT == STD_ON) */

#define CAN_STOP_SEC_CODE
/* @violates @ref Can_h_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_h_REF_6 MISRA 2012 Advisory Rule 20.1 */
#include "Can_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CAN_H */
