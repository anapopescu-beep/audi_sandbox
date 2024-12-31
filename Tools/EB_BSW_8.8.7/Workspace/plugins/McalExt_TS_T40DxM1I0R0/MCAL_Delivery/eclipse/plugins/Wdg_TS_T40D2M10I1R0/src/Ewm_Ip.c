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

#include "Ewm_Ip.h"
#include "Devassert.h"
#include "OsIf.h"
#include "Mcal.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EWM_IP_VENDOR_ID_C                      43
#define EWM_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define EWM_IP_AR_RELEASE_MINOR_VERSION_C       4
#define EWM_IP_AR_RELEASE_REVISION_VERSION_C    0
#define EWM_IP_SW_MAJOR_VERSION_C               1
#define EWM_IP_SW_MINOR_VERSION_C               0
#define EWM_IP_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Ewm_Ip header file are of the same vendor */
#if (EWM_IP_VENDOR_ID_C != EWM_IP_VENDOR_ID)
#error "Ewm_Ip.c and Ewm_Ip.h have different vendor ids"
#endif

/* Check if current file and Ewm_Ip header file are of the same Autosar version */
#if ((EWM_IP_AR_RELEASE_MAJOR_VERSION_C     != EWM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (EWM_IP_AR_RELEASE_MINOR_VERSION_C     != EWM_IP_AR_RELEASE_MINOR_VERSION) || \
     (EWM_IP_AR_RELEASE_REVISION_VERSION_C  != EWM_IP_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Ewm_Ip.c and Ewm_Ip.h are different"
#endif

/* Check if current file and Ewm_Ip header file are of the same software version */
#if ((EWM_IP_SW_MAJOR_VERSION_C != EWM_IP_SW_MAJOR_VERSION) || \
     (EWM_IP_SW_MINOR_VERSION_C != EWM_IP_SW_MINOR_VERSION) || \
     (EWM_IP_SW_PATCH_VERSION_C != EWM_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Ewm_Ip.c and Ewm_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Devassert header file are of the same Autosar version */
    #if ((EWM_IP_AR_RELEASE_MAJOR_VERSION_C    != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
        (EWM_IP_AR_RELEASE_MINOR_VERSION_C     != DEVASSERT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ewm_Ip.c and Devassert.h are different"
    #endif
        /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((EWM_IP_AR_RELEASE_MAJOR_VERSION_C    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (EWM_IP_AR_RELEASE_MINOR_VERSION_C     != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ewm_Ip.c and Mcal.h are different"
    #endif

    /* Check if current file and Osif header file are of the same Autosar version */
    #if ((EWM_IP_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (EWM_IP_AR_RELEASE_MINOR_VERSION_C     != OSIF_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ewm_Ip.c and Osif.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#if (EWM_IP_ENABLE == STD_ON)

#define WDG_START_SEC_CONST_UNSPECIFIED

#include "Wdg_MemMap.h"

/*! @brief Table of base addresses for EWM instances. */
static EWM_Type * const Ewm_Ip_sBase[] = IP_EWM_BASE_PTRS;

#define WDG_STOP_SEC_CONST_UNSPECIFIED

#include "Wdg_MemMap.h"

#define WDG_START_SEC_VAR_CLEARED_UNSPECIFIED

#include "Wdg_MemMap.h"

static Ewm_Ip_CallbackPtrType Ewm_Ip_apCallbackPtr[EWM_INSTANCE_COUNT];

#define WDG_STOP_SEC_VAR_CLEARED_UNSPECIFIED

#include "Wdg_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

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
 * @brief Refresh EWM
 *
 * This method needs to be called within the window period
 * specified by the Compare Low and Compare High registers
 *
 * @param[in] Base EWM base pointer
 */
static inline void Ewm_Ip_Refresh(EWM_Type * const Base)
{
    OsIf_SuspendAllInterrupts();

    /* Write first byte of the service key */
    Base->SERV = EWM_IP_FEATURE_KEY_FIRST_BYTE_U8;
    /* Write second byte of the service key */
    Base->SERV = EWM_IP_FEATURE_KEY_SECOND_BYTE_U8;

    OsIf_ResumeAllInterrupts();
}

/*!
 * @brief Get the EWM enable bit.
 *
 * @param[in] Base EWM base pointer
 * @return The state of the device enable bit:
 *      -   FALSE - EWM disabled
 *      -   TRUE  - EWM enabled
 */
static inline boolean Ewm_Ip_IsEnabled(const EWM_Type * const Base)
{
    return ((Base->CTRL & EWM_CTRL_EWMEN_MASK) >> EWM_CTRL_EWMEN_SHIFT) != 0U;
}

/*!
 * @brief Get the EWM interrupt enable bit.
 *
 * @param[in] Base EWM base pointer
 * @return The state of the interrupt enable bit:
 *      -   FALSE - EWM interrupt disabled
 *      -   TRUE  - EWM interrupt enabled
 */
static inline boolean Ewm_Ip_IsIntEnabled(const EWM_Type * const Base)
{
    return ((Base->CTRL & EWM_CTRL_INTEN_MASK) >> EWM_CTRL_INTEN_SHIFT) != 0U;
}

/*!
 * @brief Clear the EWM interrupt enable bit.
 *
 * @param[in] Base EWM base pointer
 */
static inline void Ewm_Ip_ClearIntenBit(EWM_Type * const Base)
{
    Base->CTRL &= ~(uint8)EWM_CTRL_INTEN_MASK;
}

/*!
 * @brief Set the Control Value.
 *
 * This register can be only written once after a CPU reset.
 *
 * @param[in] Base  EWM base pointer
 * @param[in] value Value to write into Control register
 */
static inline void Ewm_Ip_SetControl(EWM_Type * const Base, uint8_t value)
{
    Base->CTRL = value;
}

/*!
 * @brief Set the Compare Low Value.
 *
 * This register can be only written once after a CPU reset.
 * The user must make sure that the Compare High is greater than Compare Low value
 *
 * @param[in] Base  EWM base pointer
 * @param[in] value Value to write into Compare Low register
 */
static inline void Ewm_Ip_SetCompareLow(EWM_Type * const Base, uint8_t value)
{
    Base->CMPL = value;
}

/*!
 * @brief Set the Compare High Value.
 *
 * This register can be only written once after a CPU reset.
 * The user must make sure that the Compare High is greater than Compare Low value
 * Note: The maximum Compare High value is 0xFE
 *
 * @param[in] Base  EWM base pointer
 * @param[in] value Value to write into Compare High register
 */
static inline void Ewm_Ip_SetCompareHigh(EWM_Type * const Base, uint8_t value)
{
    Base->CMPH = value;
}

/*!
 * @brief Set the Clock Prescaler Value.
 *
 * This register can be only written once after a CPU reset and
 * it must be written before enabling the EWM
 *
 * @param[in] Base  EWM base pointer
 * @param[in] value Prescaler Value
 */
static inline void Ewm_Ip_SetPrescaler(EWM_Type * const Base, uint8_t value)
{
    Base->CLKPRESCALER = value;
}

/*==================================================================================================
*                                 GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/

void Ewm_Ip_IrqHandler(uint8 Instance);

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Ewm_Ip_Init
 * Description   : This function initializes the EWM instance to a specified
 * state
 *
 * @implements     Ewm_Ip_Init_Activity
 *END**************************************************************************/
Ewm_Ip_StatusType Ewm_Ip_Init(const uint8 Instance, const Ewm_Ip_ConfigType * const ConfigPtr)
{
#if (EWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < EWM_INSTANCE_COUNT);
    DevAssert(ConfigPtr != NULL_PTR);
#endif

    /* Return status variable */
    Ewm_Ip_StatusType StatusCode = EWM_IP_STATUS_SUCCESS;
    /* Flag to store if the module is enabled */
    boolean IsModuleEnabled;
    uint8_t TempValue = 0U;
    /* Base pointer */
    EWM_Type * Base = Ewm_Ip_sBase[Instance];

    /* Get the enablement status of the module */
    IsModuleEnabled = Ewm_Ip_IsEnabled(Base);
    /* Check if the EWM instance is already enabled or if the windows values are not correct */
    if ((TRUE == IsModuleEnabled) || (ConfigPtr->CompareHigh <= ConfigPtr->CompareLow) ||
        (ConfigPtr->CompareHigh > EWM_IP_FEATURE_CMPH_MAX_VALUE_U8))
    {
        /* If conditions are met change the status code to error */
        StatusCode = EWM_IP_STATUS_ERROR;
    }
    else
    {
        /* Set clock prescaler */
        Ewm_Ip_SetPrescaler(Base, ConfigPtr->Prescaler);
        /* Set compare high and low values */
        Ewm_Ip_SetCompareHigh(Base, ConfigPtr->CompareHigh);
        Ewm_Ip_SetCompareLow(Base, ConfigPtr->CompareLow);

        /* Configure the Control register and enable the instance.
         * Set the values that are not affected by the input pin
         */
        TempValue = (uint8_t)((uint8_t)EWM_CTRL_EWMEN(1U) | EWM_CTRL_INTEN(ConfigPtr->InterruptEnable ? 1U : 0U));

        /* Depending how the input pin is configured set the values into the
         * temporary variable
         */
        switch (ConfigPtr->AssertLogic)
        {
            case EWM_IN_ASSERT_ON_LOGIC_ZERO:
                TempValue |= EWM_CTRL_INEN_MASK;    /* Input pin enabled, Input asserted on logic 0 */
                break;
            case EWM_IN_ASSERT_ON_LOGIC_ONE:
                TempValue |= (uint8_t)(EWM_CTRL_INEN_MASK | EWM_CTRL_ASSIN_MASK);    /* Input pin enabled, Input asserted on logic 1 */
                break;
            case EWM_IN_ASSERT_DISABLED:
            default:
                /* Input pin disabled */
                break;
        }

        if (TRUE == ConfigPtr->InterruptEnable)
        {
            Ewm_Ip_apCallbackPtr[Instance] = ConfigPtr->pfEwmCallback;
        }
        else
        {
            Ewm_Ip_apCallbackPtr[Instance] = NULL_PTR;
        }

        /* Write the configuration into the Control register */
        Ewm_Ip_SetControl(Base, TempValue);
    }

    /* Return the status code */
    return StatusCode;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Ewm_Ip_Service
 * Description   : This function services the EWM instance counter
 *
 * @implements     Ewm_Ip_Service_Activity
 *END**************************************************************************/
void Ewm_Ip_Service(const uint8 Instance)
{
#if (EWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < EWM_INSTANCE_COUNT);
#endif

    /* Base pointer */
    EWM_Type * Base = Ewm_Ip_sBase[Instance];

    Ewm_Ip_Refresh(Base);
}

/**
* @Description    This function handles the EWM interrupt request.
*
* @implements     EWM_Ip_IrqHandler_Activity
*/
void Ewm_Ip_IrqHandler(uint8 Instance)
{
#if (EWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < EWM_INSTANCE_COUNT);
#endif
    
    /* Base pointer */
    EWM_Type * Base = Ewm_Ip_sBase[Instance];

    if (Ewm_Ip_IsIntEnabled(Base))
    {
        /* Clear the interrupt enable bit */
        Ewm_Ip_ClearIntenBit(Base);
        
        if (Ewm_Ip_apCallbackPtr[Instance] != ((void *)0))
        {
            Ewm_Ip_apCallbackPtr[Instance]();
        }
    }
}

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
