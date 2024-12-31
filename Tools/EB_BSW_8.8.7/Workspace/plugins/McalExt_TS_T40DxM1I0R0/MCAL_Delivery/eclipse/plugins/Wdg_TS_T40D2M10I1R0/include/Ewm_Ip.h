/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Wdog,Ewm
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

#ifndef EWM_IP_H
#define EWM_IP_H

/**
*   @file
*
*   @addtogroup Ewm_Ip
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Ewm_Ip_Types.h"
#include "Ewm_Ip_DeviceRegisters.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EWM_IP_VENDOR_ID                    43
#define EWM_IP_MODULE_ID                    102
#define EWM_IP_AR_RELEASE_MAJOR_VERSION     4
#define EWM_IP_AR_RELEASE_MINOR_VERSION     4
#define EWM_IP_AR_RELEASE_REVISION_VERSION  0
#define EWM_IP_SW_MAJOR_VERSION             1
#define EWM_IP_SW_MINOR_VERSION             0
#define EWM_IP_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Ewm_Ip_Types header file are of the same vendor */
#if (EWM_IP_VENDOR_ID != EWM_IP_TYPES_VENDOR_ID)
#error "Ewm_Ip.h and Ewm_Ip_Types.h have different vendor ids"
#endif

#if ((EWM_IP_AR_RELEASE_MAJOR_VERSION    != EWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EWM_IP_AR_RELEASE_MINOR_VERSION    != EWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EWM_IP_AR_RELEASE_REVISION_VERSION != EWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Ewm_Ip.h and Ewm_Ip_Types.h are different"
#endif

#if ((EWM_IP_SW_MAJOR_VERSION != EWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (EWM_IP_SW_MINOR_VERSION != EWM_IP_TYPES_SW_MINOR_VERSION) || \
     (EWM_IP_SW_PATCH_VERSION != EWM_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Ewm_Ip.h and Ewm_Ip_Types.h are different"
#endif

/* Check if current file and Ewm_Ip_DeviceRegisters header file are of the same vendor */
#if (EWM_IP_VENDOR_ID != EWM_IP_DEVICE_REGISTERS_VENDOR_ID)
#error "Ewm_Ip.h and Ewm_Ip_DeviceRegisters.h have different vendor ids"
#endif

#if ((EWM_IP_AR_RELEASE_MAJOR_VERSION    != EWM_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (EWM_IP_AR_RELEASE_MINOR_VERSION    != EWM_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (EWM_IP_AR_RELEASE_REVISION_VERSION != EWM_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Ewm_Ip.h and Ewm_Ip_DeviceRegisters.h are different"
#endif

#if ((EWM_IP_SW_MAJOR_VERSION != EWM_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (EWM_IP_SW_MINOR_VERSION != EWM_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (EWM_IP_SW_PATCH_VERSION != EWM_IP_DEVICE_REGISTERS_SW_PATCH_VERSION))
#error "Software Version Numbers of Ewm_Ip.h and Ewm_Ip_DeviceRegisters.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#if (EWM_IP_ENABLE == STD_ON)

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_START_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_START_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"

/*!
 * @brief Init EWM. This method initializes EWM instance to the configuration
 * from the passed structure. The user must make sure that the clock is
 * enabled. This is the only method needed to be called to start the module.
 *
 *  Example configuration structure:
 *  @code
 *      Ewm_Ip_ConfigType ewmUserCfg = {
 *          .AssertLogic        = EWM_IN_ASSERT_ON_LOGIC_ZERO,
 *          .InterruptEnable    = true,
 *          .Prescaler          = 128,
 *          .CompareLow         = 0,
 *          .CompareHigh        = 254
 *      };
 *  @endcode
 *      This configuration will enable the peripheral, with input pin configured
 *      to assert on logic low, interrupt enabled, prescaler 128 and maximum
 *      refresh window.
 *
 *      The EWM can be initialized only once per CPU reset as the registers
 *      are write once.
 *
 * @param[in] u8Instance EWM instance number
 * @param[in] config  Pointer to the module configuration structure.
 *
 * @return Ewm_Ip_StatusType Will return the status of the operation:
 *          - STATUS_SUCCESS            if the operation is successful
 *          - STATUS_ERROR              if the windows values are not
 *                                        correct or if the instance is
 *                                        already enabled
 *
 */
Ewm_Ip_StatusType Ewm_Ip_Init(const uint8 Instance, const Ewm_Ip_ConfigType * const ConfigPtr);

/*!
 * @brief Refresh EWM. This method needs to be called within the window period
 * specified by the Compare Low and Compare High registers.
 *
 * @param[in] u8Instance EWM instance number
 *
 * @return None
 *
 */
void Ewm_Ip_Service(const uint8 Instance);

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_STOP_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_STOP_SEC_RAMCODE
    #endif
#endif


#include "Wdg_MemMap.h"

#endif /* (EWM_IP_ENABLE == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EWM_IP_H */
