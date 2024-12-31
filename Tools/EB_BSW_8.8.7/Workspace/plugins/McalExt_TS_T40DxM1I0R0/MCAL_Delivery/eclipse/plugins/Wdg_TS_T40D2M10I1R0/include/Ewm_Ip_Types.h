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

#ifndef EWM_IP_TYPES_H
#define EWM_IP_TYPES_H

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

#include "StandardTypes.h"
#include "Ewm_Ip_Cfg_Defines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EWM_IP_TYPES_VENDOR_ID                    43
#define EWM_IP_TYPES_MODULE_ID                    102
#define EWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define EWM_IP_TYPES_AR_RELEASE_MINOR_VERSION     4
#define EWM_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define EWM_IP_TYPES_SW_MAJOR_VERSION             1
#define EWM_IP_TYPES_SW_MINOR_VERSION             0
#define EWM_IP_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Ewm_Ip_Cfg_Defines configuration header file are of the same vendor */
#if (EWM_IP_TYPES_VENDOR_ID != EWM_IP_CFG_DEFINES_VENDOR_ID)
#error "Ewm_Ip_Types.h and Ewm_Ip_Cfg_Defines.h have different vendor ids"
#endif

#if ((EWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != EWM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (EWM_IP_TYPES_AR_RELEASE_MINOR_VERSION    != EWM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (EWM_IP_TYPES_AR_RELEASE_REVISION_VERSION != EWM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Ewm_Ip_Types.h and Ewm_Ip_Cfg_Defines.h are different"
#endif

#if ((EWM_IP_TYPES_SW_MAJOR_VERSION != EWM_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (EWM_IP_TYPES_SW_MINOR_VERSION != EWM_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (EWM_IP_TYPES_SW_PATCH_VERSION != EWM_IP_CFG_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Ewm_Ip_Types.h and Ewm_Ip_Cfg_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((EWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
        (EWM_IP_TYPES_AR_RELEASE_MINOR_VERSION     != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ewm_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/** @brief       Enum defining the possible type values for EWM API
* @Implements    Ewm_Ip_StatusType_enumeration
*/
typedef enum
{
    EWM_IP_STATUS_SUCCESS   = 0x00,
    EWM_IP_STATUS_ERROR     = 0x01
} Ewm_Ip_StatusType;

/*!
 * @brief EWM input pin configuration
 * Configures if the input pin is enabled and when is asserted
 * Implements : Ewm_Ip_Assert_LogicType_Class
 */
typedef enum
{
    EWM_IN_ASSERT_DISABLED      = 0x00U,    /*!< Input pin disabled                    */
    EWM_IN_ASSERT_ON_LOGIC_ZERO = 0x01U,    /*!< Input pin asserts EWM when on logic 0 */
    EWM_IN_ASSERT_ON_LOGIC_ONE  = 0x02U     /*!< Input pin asserts EWM when on logic 1 */
} Ewm_Ip_Assert_LogicType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*!
 * @brief EWM callback type
 * Implements : Ewm_Ip_CallbackPtrType_Class
 */

typedef void (*Ewm_Ip_CallbackPtrType)(void);

/*!
 * @brief EWM configuration structure
 * This structure is used to configure the EWM prescaler, window, interrupt
 * and input pin.
 *
 * Implements : ewm_init_config_t_Class
 */
typedef struct
{
    Ewm_Ip_Assert_LogicType AssertLogic;      /*!< Assert logic for EWM input pin */
    boolean                 InterruptEnable; /*!< Enable EWM interrupt           */
    uint8                   Prescaler;      /*!< EWM clock prescaler            */
    uint8                   CompareLow;     /*!< Compare low value              */
    uint8                   CompareHigh;    /*!< Compare high value             */
    Ewm_Ip_CallbackPtrType  pfEwmCallback;    /*!< Interrupt callback             */
} Ewm_Ip_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EWM_IP_TYPES_H */
