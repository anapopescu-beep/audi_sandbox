/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm
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
*     @file       Qdec.c
*
*     @addtogroup qdec Qdec Driver
*     @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
 *                                          INCLUDE FILES
 *  1) system and project includes
 *  2) needed interfaces from external units
 *  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcal.h"
#include "Qdec.h"
#include "Qdec_Ipw.h"
#include "Qdec_EnvCfg.h"

/*==================================================================================================
*                                  SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define QDEC_VENDOR_ID_C                     43
#define QDEC_AR_RELEASE_MAJOR_VERSION_C      4
#define QDEC_AR_RELEASE_MINOR_VERSION_C      4
#define QDEC_AR_RELEASE_REVISION_VERSION_C   0
#define QDEC_SW_MAJOR_VERSION_C              1
#define QDEC_SW_MINOR_VERSION_C              0
#define QDEC_SW_PATCH_VERSION_C              1

/*==================================================================================================
 *                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Mcal header file are of the same Autosar version */
    #if ((QDEC_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (QDEC_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Qdec.c and Mcal.h are different"
    #endif
#endif

/* Check if source file and Qdec header file are of the same vendor */
#if (QDEC_VENDOR_ID_C != QDEC_VENDOR_ID)
    #error "Qdec.c and Qdec.h have different vendor IDs"
#endif
/* Check if source file and Qdec header file are of the same AutoSar version */
#if ((QDEC_AR_RELEASE_MAJOR_VERSION_C != QDEC_AR_RELEASE_MAJOR_VERSION) || \
     (QDEC_AR_RELEASE_MINOR_VERSION_C != QDEC_AR_RELEASE_MINOR_VERSION) || \
     (QDEC_AR_RELEASE_REVISION_VERSION_C != QDEC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Qdec.c and Qdec.h are different"
#endif
/* Check if source file and Qdec header file are of the same Software version */
#if ((QDEC_SW_MAJOR_VERSION_C != QDEC_SW_MAJOR_VERSION) || \
     (QDEC_SW_MINOR_VERSION_C != QDEC_SW_MINOR_VERSION) || \
     (QDEC_SW_PATCH_VERSION_C != QDEC_SW_PATCH_VERSION))
#error "Software Version Numbers of Qdec.c and Qdec.h are different"
#endif

/* Check if source file and Qdec_Ipw header file are of the same vendor */
#if (QDEC_VENDOR_ID_C != QDEC_IPW_VENDOR_ID)
    #error "Qdec.c and Qdec_Ipw.h have different vendor IDs"
#endif
/* Check if source file and Qdec_Ipw header file are of the same AutoSar version */
#if ((QDEC_AR_RELEASE_MAJOR_VERSION_C != QDEC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (QDEC_AR_RELEASE_MINOR_VERSION_C != QDEC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (QDEC_AR_RELEASE_REVISION_VERSION_C != QDEC_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Qdec.c and Qdec_Ipw.h are different"
#endif
/* Check if source file and Qdec_Ipw header file are of the same Software version */
#if ((QDEC_SW_MAJOR_VERSION_C != QDEC_IPW_SW_MAJOR_VERSION) || \
     (QDEC_SW_MINOR_VERSION_C != QDEC_IPW_SW_MINOR_VERSION) || \
     (QDEC_SW_PATCH_VERSION_C != QDEC_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Qdec.c and Qdec_Ipw.h are different"
#endif

/* Check if source file and Qdec_EnvCfg header file are of the same vendor */
#if (QDEC_VENDOR_ID_C != QDEC_ENVCFG_VENDOR_ID)
    #error "Qdec.c and Qdec_EnvCfg.h have different vendor IDs"
#endif
/* Check if source file and Qdec_EnvCfg header file are of the same AutoSar version */
#if ((QDEC_AR_RELEASE_MAJOR_VERSION_C != QDEC_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (QDEC_AR_RELEASE_MINOR_VERSION_C != QDEC_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (QDEC_AR_RELEASE_REVISION_VERSION_C != QDEC_ENVCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Qdec.c and Qdec_EnvCfg.h are different"
#endif
/* Check if source file and Qdec_EnvCfg header file are of the same Software version */
#if ((QDEC_SW_MAJOR_VERSION_C != QDEC_ENVCFG_SW_MAJOR_VERSION) || \
     (QDEC_SW_MINOR_VERSION_C != QDEC_ENVCFG_SW_MINOR_VERSION) || \
     (QDEC_SW_PATCH_VERSION_C != QDEC_ENVCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Qdec.c and Qdec_EnvCfg.h are different"
#endif

/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#if ((QDEC_VALIDATE_GLOBAL_CALL == STD_ON) || (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON))

typedef enum
{
    QDEC_STATE_UNINIT = 0x00,
    QDEC_STATE_IDLE
} Qdec_eGlobalStateType;

#endif /* (QDEC_VALIDATE_GLOBAL_CALL == STD_ON) || (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON) */

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

#if (QDEC_MULTICORE_ENABLED == STD_ON)
    #define Qdec_GetCoreId()    ((uint32)OsIf_GetCoreID())
#else
    #define Qdec_GetCoreId()    ((uint32)0UL)
#endif

/*==================================================================================================
 *                                        LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                        LOCAL VARIABLES
==================================================================================================*/

#define QDEC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Qdec_MemMap.h"

#if ((QDEC_VALIDATE_GLOBAL_CALL == STD_ON) || (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON))
#if (QDEC_MULTICORE_ENABLED == STD_ON)
static Qdec_eGlobalStateType Qdec_GlobalState[QDEC_MAX_PARTITIONS] = {QDEC_STATE_UNINIT};
#else
static Qdec_eGlobalStateType Qdec_GlobalState[1] = {QDEC_STATE_UNINIT};
#endif
#endif /* ((QDEC_VALIDATE_GLOBAL_CALL == STD_ON) || (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)) */

static Qdec_CounterStateType Qdec_CurrentCounterState = QDEC_RESUME_COUNTER;

static Qdec_ModeType Qdec_CurrentMode = QDEC_MODE_NORMAL;

#define QDEC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Qdec_MemMap.h"

/*==================================================================================================
 *                                        GLOBAL CONSTANTS
==================================================================================================*/

#define QDEC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Qdec_MemMap.h"

#if (STD_ON == QDEC_PRECOMPILE_SUPPORT)
    #if (QDEC_MULTICORE_ENABLED == STD_ON)
        extern const Qdec_ConfigType * const Qdec_Config[QDEC_MAX_PARTITIONS];
    #else  /* (QDEC_MULTICORE_ENABLED == STD_ON) */
        extern const Qdec_ConfigType Qdec_Config;
    #endif /* (QDEC_MULTICORE_ENABLED == STD_ON) */
#endif /*STD_ON == QDEC_PRECOMPILE_SUPPORT*/

#define QDEC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Qdec_MemMap.h"

/*==================================================================================================
 *                                        GLOBAL VARIABLES
==================================================================================================*/

#define QDEC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Qdec_MemMap.h"

#if (QDEC_MULTICORE_ENABLED == STD_ON)
static const Qdec_ConfigType *Qdec_apxConfig[QDEC_MAX_PARTITIONS];
#else
static const Qdec_ConfigType *Qdec_apxConfig[1U];
#endif /* QDEC_MULTICORE_ENABLED == STD_ON */

#define QDEC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Qdec_MemMap.h"

/*==================================================================================================
 *                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define QDEC_START_SEC_CODE
#include "Qdec_MemMap.h"

#if (QDEC_VALIDATE_GLOBAL_CALL == STD_ON)
    
static inline Std_ReturnType Qdec_ValidateGlobalCall(uint8 u8ServiceId, uint32 CoreId);

static inline void Qdec_EndValidateGlobalCall(Std_ReturnType validation, uint8 u8ServiceId, uint32 CoreId);

#endif /* QDEC_VALIDATE_GLOBAL_CALL == STD_ON */

#if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)

static inline Std_ReturnType Qdec_ValidateCallAndInstance(uint8 Instance, uint8 u8ServiceId, uint32 CoreId);

#endif /* QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON */

#if (QDEC_VALIDATE_PARAMS == STD_ON)

static inline Std_ReturnType Qdec_ValidatePtrInit(uint32 CoreId, const Qdec_ConfigType * ConfigPtr);

static inline Std_ReturnType Qdec_ValidateMode(Qdec_ModeType mode);

#endif /* (QDEC_VALIDATE_PARAMS == STD_ON) */

/*==================================================================================================
 *                                        LOCAL FUNCTIONS
==================================================================================================*/

#if (QDEC_VALIDATE_GLOBAL_CALL == STD_ON)
/**
* @brief       This function validates the global call
* @details     This service is a non reentrant function used for validating the calls for functions
*              that uses all the instances - Qdec_Init, Qdec_DeInit.
*
* @param[in]   u8ServiceId      The service id of the caller function
* @param[in]   CoreId           The number of current core ID
*
* @return      The validity of the function call
* @retval      E_OK             The function call is valid
* @retval      E_NOT_OK         The function call is invalid
* @implements  Qdec_ValidateGlobalCall_Activity
*/
static inline Std_ReturnType Qdec_ValidateGlobalCall(uint8 u8ServiceId, uint32 CoreId)
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;

    if (QDEC_STATE_UNINIT == Qdec_GlobalState[CoreId])
    {
        if (QDEC_INIT_ID != u8ServiceId)
        {
            (void)Det_ReportError((uint16)QDEC_MODULE_ID, 0U, u8ServiceId, QDEC_E_UNINIT);
            valid = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        if (QDEC_INIT_ID == u8ServiceId)
        {
            (void)Det_ReportError((uint16)QDEC_MODULE_ID, 0U, u8ServiceId, QDEC_E_ALREADY_INITIALIZED);
            valid = (Std_ReturnType)E_NOT_OK;
        }
    }
    return valid;
}
#endif /* QDEC_VALIDATE_GLOBAL_CALL == STD_ON */
    
#if (QDEC_VALIDATE_GLOBAL_CALL == STD_ON)
/**
* @brief      This function ends the validation of the global call.
* @details    This service is a non reentrant function used for end the validation the calls for
*             functions that uses all the instances - Qdec_Init, Qdec_DeInit, Qdec_SetMode.
*
* @param[in]   u8ServiceId     The service id of the caller function
* @param[in]   validation      The function call was previously validated
* @param[in]   CoreId       The number of current core ID
*
* @return void
* @implements  Qdec_EndValidateGlobalCall_Activity
*/
static inline void Qdec_EndValidateGlobalCall(Std_ReturnType validation, uint8 u8ServiceId, uint32 CoreId)
{
    if ((Std_ReturnType)E_OK == validation)
    {
        if (QDEC_DEINIT_ID == u8ServiceId)
        {
            Qdec_GlobalState[CoreId] = QDEC_STATE_UNINIT;
        }
        else
        {
            Qdec_GlobalState[CoreId] = QDEC_STATE_IDLE;
        }
    }
}
#endif /* QDEC_VALIDATE_GLOBAL_CALL == STD_ON */

#if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)
/**
* @brief       This function validates the call for a specific instance
* @details     This service is a non reentrant function on instance used for validating the calls
*              for functions that use one instance
*
* @param[in]   Instance         Logical number of the QDEC instance
* @param[in]   ModeMask         The modes that are valid for the specific instance
* @param[in]   u8ServiceId      The service id of the caller function
* @param[in]   CoreId             The number of current core ID
* @return      The validity of the function call
* @retval      E_OK      The function call is valid
* @retval      E_NOT_OK The function call is invalid
* @implements  Qdec_ValidateCallAndInstance_Activity
*/
static inline Std_ReturnType Qdec_ValidateCallAndInstance(uint8 Instance, uint8 u8ServiceId, uint32 CoreId)
{
    Std_ReturnType valid = (Std_ReturnType)E_NOT_OK;

    if (QDEC_STATE_UNINIT == Qdec_GlobalState[CoreId])
    {
        (void)Det_ReportError((uint16)QDEC_MODULE_ID, 0U, u8ServiceId, QDEC_E_UNINIT);
    }
    else
    {
        if(QDEC_MAX_INSTANCE <= Instance)
        {
            (void)Det_ReportError((uint16)QDEC_MODULE_ID, 0U, u8ServiceId, QDEC_E_PARAM_INSTANCE);
        }
        else
        {
            valid = (Std_ReturnType)E_OK;
        }
    }

    return valid;
}
#endif

#if (QDEC_VALIDATE_PARAMS == STD_ON)

/**
* @brief       This function validate the initialization pointer.
*
* @param[in]   ConfigPtr   Pointer to a selected configuration structure.
*
* @return                  The validity of the function call
* @retval      E_OK        The function call is valid
* @retval      E_NOT_OK    The function call is invalid
* @implements  Qdec_ValidatePtrInit_Activity
*/
static inline Std_ReturnType Qdec_ValidatePtrInit(uint32 CoreId, const Qdec_ConfigType * ConfigPtr)
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;

#if (defined(QDEC_PRECOMPILE_SUPPORT) && (STD_ON == QDEC_PRECOMPILE_SUPPORT))
    if (NULL_PTR != ConfigPtr)
    {
#else
    if (NULL_PTR == ConfigPtr)
    {
#endif /*QDEC_PRECOMPILE_SUPPORT*/
        (void)Det_ReportError((uint16)QDEC_MODULE_ID, 0U, QDEC_INIT_ID, QDEC_E_INIT_FAILED);
        valid = (Std_ReturnType)E_NOT_OK;
    }
#if (STD_OFF == QDEC_PRECOMPILE_SUPPORT)
#if (QDEC_MULTICORE_ENABLED == STD_ON)
    else if (CoreId != ConfigPtr->CoreIndex)
    {
        (void)Det_ReportError((uint16) QDEC_MODULE_ID, 0U, QDEC_INIT_ID, QDEC_E_PARAM_CONFIG);
        valid = (Std_ReturnType)E_NOT_OK;  
    }
#endif /*QDEC_MULTICORE_ENABLED*/
    else
    {
        (void)CoreId;
        /* Do nothing */
    }
#else
    else
    {
#if (QDEC_MULTICORE_ENABLED == STD_ON)
        if (NULL_PTR == Qdec_Config[CoreId])
        {
            /* Avoid compiler warning */
            (void)CoreId;
            (void)Det_ReportError((uint16) QDEC_MODULE_ID, 0U, QDEC_INIT_ID, QDEC_E_INIT_FAILED);
            valid = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Do nothing */
        }
#endif /*QDEC_MULTICORE_ENABLED*/

        (void)CoreId;
        /* Do nothing */
    }    
#endif /*STD_OFF == QDEC_PRECOMPILE_SUPPORT*/
    return valid;
}

/**
 * @brief       This function validate the mode that will be set in the driver.
 *
 * @param[in]   mode        Specifies the operation mode
 *
 * @return                  The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 * @implements  Qdec_ValidateMode_Activity
 * */
static inline Std_ReturnType Qdec_ValidateMode(Qdec_ModeType mode)
{
    Std_ReturnType valid =  (Std_ReturnType)E_NOT_OK;

    if ((QDEC_MODE_SLEEP != mode) && (QDEC_MODE_NORMAL != mode))
    {
        (void)Det_ReportError((uint16)QDEC_MODULE_ID, 0U, QDEC_SETMODE_ID, QDEC_E_PARAM_MODE);
    }
    else
    {
        valid = (Std_ReturnType)E_OK;
    }
    return valid;
}

#endif /* (QDEC_VALIDATE_PARAMS == STD_ON)*/

/*==================================================================================================
 *                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @implements     Qdec_Init_Activity
*/
void Qdec_Init(const Qdec_ConfigType *Config)
{
    uint32 CoreId = (uint32)Qdec_GetCoreId();
#if (QDEC_VALIDATE_GLOBAL_CALL == STD_ON) || (QDEC_VALIDATE_PARAMS == STD_ON)
    Std_ReturnType valid;
#endif
#if (QDEC_VALIDATE_GLOBAL_CALL == STD_ON)
    valid = Qdec_ValidateGlobalCall(QDEC_INIT_ID, CoreId);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (QDEC_VALIDATE_GLOBAL_CALL == STD_ON */
#if (QDEC_VALIDATE_PARAMS == STD_ON)
        valid = Qdec_ValidatePtrInit(CoreId ,Config);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /* (QDEC_VALIDATE_PARAMS == STD_ON) */

#if (STD_ON == QDEC_PRECOMPILE_SUPPORT)
#if (QDEC_MULTICORE_ENABLED == STD_ON)
            Qdec_apxConfig[CoreId] = Qdec_Config[CoreId];
#else /* QDEC_MULTICORE_ENABLED == STD_OFF */
            Qdec_apxConfig[0] = &Qdec_Config;
#endif /* QDEC_MULTICORE_ENABLED */
            (void)Config;
#else
            Qdec_apxConfig[CoreId] = Config;
#endif /*STD_ON == QDEC_PRECOMPILE_SUPPORT*/

            Qdec_Ipw_Init((Qdec_apxConfig[CoreId]->Instances), (Qdec_apxConfig[CoreId]->Ipw_ConfigType));

#if (QDEC_VALIDATE_PARAMS == STD_ON)
        }
#endif
#if (STD_ON == QDEC_VALIDATE_GLOBAL_CALL)
    }
    Qdec_EndValidateGlobalCall(valid, QDEC_INIT_ID, CoreId);
#endif
}

#if (QDEC_DEINIT_API == STD_ON)
/**
* @implements     Qdec_DeInit_Activity
*/
void Qdec_DeInit(void)
{
    uint32 CoreId = (uint32)Qdec_GetCoreId();
#if (QDEC_VALIDATE_GLOBAL_CALL == STD_ON)
    Std_ReturnType valid = Qdec_ValidateGlobalCall(QDEC_DEINIT_ID, CoreId);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* QDEC_VALIDATE_GLOBAL_CALL == STD_ON */

        Qdec_Ipw_DeInit((Qdec_apxConfig[CoreId]->Instances), (Qdec_apxConfig[CoreId]->Ipw_ConfigType));
        Qdec_apxConfig[CoreId] = NULL_PTR;
#if (QDEC_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    Qdec_EndValidateGlobalCall(valid, QDEC_DEINIT_ID, CoreId);
#endif /* QDEC_VALIDATE_GLOBAL_CALL == STD_ON */
}
#endif /* QDEC_DEINIT_API == STD_ON */

/**
* @implements     Qdec_GetState_Activity
*/
Qdec_StateType Qdec_GetState(const uint8 module)
{
    Qdec_StateType InstanceState = {0x0U, FALSE, FALSE, FALSE, FALSE, FALSE};
    uint32 CoreId = (uint32)Qdec_GetCoreId();
    
#if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)
    if((Std_ReturnType)E_OK == Qdec_ValidateCallAndInstance(module, QDEC_GETSTATE_ID, CoreId))
    {
#endif /* QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON */
        Qdec_Ipw_State IpwState = Qdec_Ipw_GetState(module, Qdec_apxConfig[CoreId]->Ipw_ConfigType);
        InstanceState.mCounter          = IpwState.Counter;
        InstanceState.mTimerOverflow    = IpwState.TimerOverflow;
        InstanceState.mTimerOverflowDir = IpwState.TimerOverflowDir;
        InstanceState.mCountDir         = IpwState.CountDir;
#if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)
    }
#endif /* QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON */
    return InstanceState;
}

#if (QDEC_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief        Implementation specific function to change the peripheral clock frequency.
* @details      This function is useful to set the prescalers that divide the QDEC channels
*               clock frequency.
*
* @param[in]    selectPrescaler - selectPrescaler type
*
* @return       void
*
* @implements   Qdec_SetClockMode_Activity
*
*/
void Qdec_SetClockMode(Qdec_SelectPrescalerType selectPrescaler)
{
    uint32 coreId;
    uint8 index;

    /* Get core ID of current processor */
    coreId = (uint32)Qdec_GetCoreId();

#if (STD_ON == QDEC_VALIDATE_GLOBAL_CALL)
    Std_ReturnType valid = Qdec_ValidateGlobalCall(QDEC_SET_CLOCK_MODE_ID, coreId);
    if((Std_ReturnType)E_OK == valid)
    {
#endif
        for (index = 0; index < Qdec_apxConfig[coreId]->Instances; index++)
        {
            Qdec_Ipw_SetClockMode(Qdec_apxConfig[coreId]->Ipw_ConfigType, Qdec_apxConfig[coreId]->Ipw_ConfigType->Logic2HwMap[index].IpInstance, selectPrescaler);
        }
#if (STD_ON == QDEC_VALIDATE_GLOBAL_CALL)
    }
    Qdec_EndValidateGlobalCall(valid, QDEC_SET_CLOCK_MODE_ID, coreId);
#endif /* STD_ON == QDEC_VALIDATE_GLOBAL_CALL */
}
#endif /* QDEC_SET_CLOCK_MODE_API */

/**
* @implements     Qdec_CounterState_Activity
*/
void Qdec_CounterState(const uint8 module, Qdec_CounterStateType counterState)
{
    uint32 CoreId = (uint32)Qdec_GetCoreId();

#if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)
    if((Std_ReturnType)E_OK == Qdec_ValidateCallAndInstance(module, QDEC_COUNTERSTATE_ID, CoreId))
    {
#endif
        if (Qdec_CurrentCounterState != counterState)
        {
            Qdec_Ipw_CounterState(module, (Qdec_apxConfig[CoreId]->Ipw_ConfigType));
            /* Hold provided counterState */
            Qdec_CurrentCounterState = counterState;
        }   
#if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)
    }
#endif /* QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON */
}

/**
* @implements     Qdec_ResetState_Activity
*/
void Qdec_ResetState(const uint8 module)
{
    uint32 CoreId = (uint32)Qdec_GetCoreId();

#if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)
    if((Std_ReturnType)E_OK == Qdec_ValidateCallAndInstance(module, QDEC_RESETSTATE_ID, CoreId))
    {
#endif
        Qdec_Ipw_ResetState(module, (Qdec_apxConfig[CoreId]->Ipw_ConfigType));
    #if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)
    }
#endif /* QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON */
}

#if (QDEC_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief            This function disables QDEC overflow notification.
*
* @implements       Qdec_DisableOverFlowNotification_Activity
*/
void Qdec_DisableOverFlowNotification(const uint8 module)
{
    uint32 CoreId = (uint32)Qdec_GetCoreId();
#if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)
    if((Std_ReturnType)E_OK == Qdec_ValidateCallAndInstance(module, QDEC_DISABLEOVERFLOWNOTIFICATION_ID, CoreId))
    {
#endif
        Qdec_Ipw_DisableOverFlowNotification(module, (Qdec_apxConfig[CoreId]->Ipw_ConfigType));
#if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)
    }
#endif /* QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON */
}

/**
* @brief            This function enables QDEC overflow notification.
*
* @implements       Qdec_EnableOverFlowNotification_Activity
*/
void Qdec_EnableOverFlowNotification(const uint8 module)
{
    uint32 CoreId = (uint32)Qdec_GetCoreId();
#if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)
    if((Std_ReturnType)E_OK == Qdec_ValidateCallAndInstance(module, QDEC_ENABLEOVERFLOWNOTIFICATION_ID, CoreId))
    {
#endif
        Qdec_Ipw_EnableOverFlowNotification(module, (Qdec_apxConfig[CoreId]->Ipw_ConfigType));
#if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)
    }
#endif /* QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON */
}

#endif /* QDEC_NOTIFICATION_SUPPORTED == STD_ON */

/**
* @brief          This function sets the QDEC mode.
*
* @implements     Qdec_SetMode_Activity
*/
void Qdec_SetMode(const uint8 module, Qdec_ModeType mode)
{
    uint32 CoreId = (uint32)Qdec_GetCoreId();
#if (QDEC_VALIDATE_PARAMS == STD_ON)
    Std_ReturnType valid;
#endif

#if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)
    if((Std_ReturnType)E_OK == Qdec_ValidateCallAndInstance(module, QDEC_SETMODE_ID, CoreId))
    {
#endif /* QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON */

#if (QDEC_VALIDATE_PARAMS == STD_ON)
        valid = Qdec_ValidateMode(mode);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /* QDEC_VALIDATE_PARAMS == STD_ON */
            if  (Qdec_CurrentMode != mode)
            {
                Qdec_Ipw_SetMode(module, (Qdec_apxConfig[CoreId]->Ipw_ConfigType), mode);
    
                /* Update Qdec mode */
                Qdec_CurrentMode = mode;
            }
#if (QDEC_VALIDATE_PARAMS == STD_ON)
        }
#endif /* (QDEC_VALIDATE_PARAMS == STD_ON) */

#if (QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON)
    }
#endif /* QDEC_VALIDATE_CALL_AND_INSTANCE == STD_ON */
}

#if (QDEC_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief         Qdec_ReportEvents
*/
void Qdec_ReportEvents(uint8 HwInstance)
{
    Qdec_NotificationType lpfInsNotification;
    uint32 CoreId = (uint32)Qdec_GetCoreId();

    if (Qdec_apxConfig[CoreId] != NULL_PTR)
    {
        /* Check that there is a logic channel associated with the Hw one */
        lpfInsNotification = (*(Qdec_apxConfig[CoreId]->InstanceConfigType))[HwInstance].pfInsNotification;
        
        /* Check that a notification is defined for the associated logic channel.
         *  This is a double check not necessarily needed because if notification were
         *  enabled in IP layer for the channel that generated the interrupt causing this notify to
         *  be called, it means that this channel cannot have a null notification, otherwise notification
         *  could not have been enabled  */
        if ((NULL_PTR != lpfInsNotification))
        {
            lpfInsNotification();
        }
    }
}
#endif /* QDEC_NOTIFICATION_SUPPORTED == STD_ON */


#define QDEC_STOP_SEC_CODE
#include "Qdec_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
