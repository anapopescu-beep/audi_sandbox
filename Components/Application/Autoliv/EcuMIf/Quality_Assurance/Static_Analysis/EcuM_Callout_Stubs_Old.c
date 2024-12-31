
/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version: 
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
******************************************************************************/
/*
$Revision: 1.12.1.4 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/EcuMIf/Quality_Assurance/Static_Analysis/project.pj $
*/
/*****************************************************************************

details
  Application level module of ECU State Manager (BswM) component. The ECU State
  Manager is the module that initializes and de-initializes the OS, the SchM
  and the BswM as well as some basic software driver modules, configures the ECU
  for SLEEP and SHUTDOWN when requested and manages all wakeup events on the ECU.
  This module is used to define what actions are needed to be executed when a
  specific EcuM State is or isn't fullfiled.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"
#include "Mcu.h"
#include "SBC.h"
#include "CanIf.h"
#include "Can.h"
#include "Rte_EcuMIf.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *		Flag associated with none wakeup sources availability.
 */
#define ECUMIF_KU32_WKSOURCE_NONE_SOURCES ((uint32) 0x00000000)
/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
#define EcuMIf_START_SEC_VAR_INIT_8
#include "EcuMIf_MemMap.h"
/**
 * \brief
 *       This variable is used to store the scheduler state.
 * \initialization 
 *       None because is external variable.
 * \range
 *       SCHM_PARTITION_UNINITIALIZED 0xAU
 *       SCHM_PARTITION_ACTIVE 0xBU
 *       SCHM_PARTITION_STOPPED 0xCU
 *       SCHM_PARTITION_STARTING 0xDU;
 */
extern uint8 SchM_State;

#define EcuMIf_STOP_SEC_VAR_INIT_8
#include "EcuMIf_MemMap.h"
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
#define EcuMIf_START_SEC_CODE
#include "EcuMIf_MemMap.h"

#if (ECUM_INITLIST_ONE == STD_ON)
/**
* \brief
*     This service is a callout used to initialize 
*     configured drivers and is called from WAKEUP state.
* \outputparam
*     Name: ConfigPtr;
*     Type: EcuM_ConfigType * ;
*     Description: Type for EcuM configuration;
*     Range: NA.;
* \dynamicaspectcaller
*     EcuM_StartPreOS 
* \dynamicaspectdescription
*     Called at StartPreOs depends of tresos configuration.
* \ddesignrequirement
*     DSG_EcuM_AL_DriverInitOne
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_AL_DriverInitOne
*/
EXPORTED FUNC(void, ECUM_APPL_CODE) EcuM_AL_DriverInitOne
(
  P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_CONST) ConfigPtr
)
{
   /* Call Initialization List One. This initializes
    * all the configured modules in 'EcuMDriverInitListOne' */
   if (NULL_PTR != ConfigPtr->DriverInitOne)
   {
      ConfigPtr->DriverInitOne(ConfigPtr);
   }
}
#endif

/**
* \brief
*     This service is a callout used to initialize BSW modules. 
*     This initialization is made before the OS is started so 
*     these modules require no OS support. This is a callout from
*     WAKEUP state.
* \outputparam
*     Name: ConfigPtr;
*     Type: EcuM_ConfigType *;
*     Description: Type for EcuM configuration;
*     Range: NA.;
* \dynamicaspectcaller
*     EcuM_AL_DriverInitOne
* \dynamicaspectdescription
*     Called by EcuM_AL_DriverInitOne at start-up. 
* \ddesignrequirement
*     DSG_EcuM_DriverInitListOne
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_DriverInitListOne
*     ARCH_SW_EcuMIf_ptrrAsrAdcServicesEcuMIf_EcuM_DriverInitListOne
*     ARCH_SW_EcuMIf_ptrrAsrCanServicesEcuMIf_EcuM_DriverInitListOne
*     ARCH_SW_EcuMIf_ptrrAsrDemServicesEcuMIf_EcuM_DriverInitListOne
*     ARCH_SW_EcuMIf_ptrrAsrFeeServicesEcuMIf_EcuM_DriverInitListOne
*     ARCH_SW_EcuMIf_ptrrAsrFlsServicesEcuMIf_EcuM_DriverInitListOne
*     ARCH_SW_EcuMIf_ptrrAsrPwmServicesEcuMIf_EcuM_DriverInitListOne
*     ARCH_SW_EcuMIf_ptrpEcuMIfServicesAdcIf_EcuM_DriverInitListOne
*     ARCH_SW_EcuMIf_ptrpEcuMIfServicesDioIf_EcuM_DriverInitListOne
*     ARCH_SW_EcuMIf_ptrrSbcServicesEcuMIf_EcuM_DriverInitListOne
*     ARCH_SW_EcuMIf_ptrrSpiServicesEcuMIf_EcuM_DriverInitListOne
*     ARCH_SW_EcuMIf_ptrrAsrEcuMIfServicesEcuMIf_EcuM_DefaultInitListOne
*     ARCH_SW_EcuMIf_ptrrAsrMcuServicesEcuMIf_EcuM_DriverInitListOne
*/
EXPORTED FUNC(void, ECUM_APPL_CODE) EcuM_DriverInitListOne
(
  P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_CONST) ConfigPtr
)
{
  /* Macro used to avoid compiler warnings, remove if parameter is used */
  TS_PARAM_UNUSED(ConfigPtr);

  /* Call Default initialization list one */
  EcuM_DefaultInitListOne();

  /* Switch SchM state to partition uninitialized */
  SchM_State = SCHM_PARTITION_UNINITIALIZED; 
}

/**
* \brief
*     This service is a callout which should evaluate some condition, 
*     like port pin or NVRAM value, to determine which post-build 
*     configuration shall be used in the remainder of the startup process.
*     Not applicable because we use just one config type. 
* \return
*     EcuM_DeterminePbConfigurationRetType return type
*     is a EcuM_ConfigType struct type which retain 
*     the EcuM configuration.
* \dynamicaspectcaller
*     EcuM_Init
* \dynamicaspectdescription
*     Called by EcuM_Init at startup.
* \ddesignrequirement
*     DSG_EcuM_DeterminePbConfiguration
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_DeterminePbConfiguration
*/
EXPORTED FUNC(EcuM_DeterminePbConfigurationRetType, ECUM_APPL_CODE) EcuM_DeterminePbConfiguration(void)
{
  /* Create PbConfig variable and assign the only EcuM_Config which 
  is configured on this project */
  EcuM_DeterminePbConfigurationRetType PbConfig = &(EcuM_Config_0);
  
  /* Implement the routine to return EcuM configuration structure
   * which shall be activated on start up in this callout function.
   *
   * Integrator may select the post-build configuration after evaluating
   * some condition like status of a port pin or NVRAM value. */

  return PbConfig;
}

/**
* \brief
*     This service is a callout from the startup phase and shall 
*     set the interrupts on ECUs with programmable interrupts. 
*     This callout is invoked by EcuM before Mcu is started.
* \dynamicaspectcaller
*     EcuM_StartPreOS
* \dynamicaspectdescription
*     Called by EcuM_StartPreOS before Mcu is started.
* \ddesignrequirement
*     DSG_EcuM_AL_SetProgrammableInterrupts
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_AL_SetProgrammableInterrupts
*/
EXPORTED FUNC(void,ECUM_APPL_CODE) EcuM_AL_SetProgrammableInterrupts(void)
{
  /* Implement the routine to set interrupts on ECUs with programmable 
   * interrupts with in this callout function.
   *
   * On ECUs with programmable interrupt priorities, these priorities 
   * must be set before the OS is started. */
}

/**
* \brief
*     This service is a callout used to handle the production 
*     error ECUM_RAM_CHECK_FAILED when RAM Check fails on wakeup.
*     The ECU Manager module can invoke EcuM_ErrorHook in all phases.
* \inputparam
*     Name: reason;
*     Type: Std_ReturnType - uint8;
*     Description: Error hook reason;
*     Range: 0x02..ECUM_RAM_CHECK_FAILED;
* \dynamicaspectcaller
*     EcuM_HaltSequence
* \dynamicaspectdescription
*     Called by EcuM_HaltSequence when a RAM check fails
*     on wakeup.
* \ddesignrequirement
*     DSG_EcuM_ErrorHook
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_ErrorHook
*/
EXPORTED FUNC(void, ECUM_APPL_CODE) EcuM_ErrorHook(Std_ReturnType reason)
{
  /* Macro used to avoid compiler warnings remove if parameter is used */
  TS_PARAM_UNUSED(reason); 

  /* Integrator may define additional error codes to be passed as the 'reason'
   * parameter. This code shall not conflict with the development and production error
   * codes defined in SWS. Also it shall not conflict with standard error codes E_OK and
   * E_NOT_OK.
   *
   *  Implementation hint:
   * 
   *  if(reason == ECUM_RAM_CHECK_FAILED)
   *  {
   *    Mcu_PerformReset();
   *  }
   */
}

/**
* \brief
*     This service is a callout used for writing a RAM hash.
*     This callout is invoked by EcuM just before putting the 
*     ECU physically to sleep.
* \dynamicaspectcaller
*     EcuM_HaltSequence
* \dynamicaspectdescription
*     Called by EcuM_HaltSequence before halting the micro controller
*     to check the RAM integrity after the processor returns from halt.
* \ddesignrequirement
*     DSG_EcuM_GenerateRamHash
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_GenerateRamHash
*/
EXPORTED FUNC(void,ECUM_APPL_CODE) EcuM_GenerateRamHash(void)
{
  /* Ram memory may become corrupted when an ECU is held in sleep mode for a
   * long time. The RAM memories integrity should therefore be checked to prevent
   * unforeseen behavior. The system designer may choose an adequate checksum
   * algorithm to perform the check. */
}

/**
* \brief
*     This callout is intended to provide a RAM integrity test. The goal
*     of this test is to ensure that after a long SLEEP duration, RAM 
*     contents is still consistent. The check does not need to be exhaustive
*     since this would consume quite some processing time during wakeups.
* \return
*     Ram hash status.   
* \dynamicaspectcaller
*     EcuM_HaltSequence
* \dynamicaspectdescription
*     This callout is invoked by EcuM early in WAKEUP 1 state.
* \ddesignrequirement
*     DSG_EcuM_CheckRamHash
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_CheckRamHash
*/
EXPORTED FUNC(uint8, ECUM_APPL_CODE) EcuM_CheckRamHash(void)
{
  /* This variable is defined to avoid compiler errors */
  uint8 u8RamTest = KU8_ONE;

  /* Implement the routine to check RAM memories integrity with in 
   * this callout function. */


  return u8RamTest;
}

/**
* \brief
*     This service is a callout called when ECU state manager module
*     perform a power off or a reset depending on the selected shutdown target.
* \dynamicaspectcaller
*     EcuM_GoDownMaster
* \dynamicaspectdescription
*     Called by EcuM_GoDownMaster at shutdown/reset procedure.
* \ddesignrequirement
*     DSG_EcuM_OnGoOffOne
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_OnGoOffOne
*/
EXPORTED FUNC(void, ECUM_APPL_CODE) EcuM_OnGoOffOne(void)
{
  /* Ecu Manager module invokes this callout on entry actions of OffPreOS
   * sequence. */
}

/**
* \brief
*     This service is a callout called when ECU state manager module
*     perform a power off or a reset depending on the selected shutdown target
*     but after EcuM_OnGoOffOne method.
* \dynamicaspectcaller
*     ShutdownHook
* \dynamicaspectdescription
*     Called by ShutdownHook at shutdown/reset procedure.
* \ddesignrequirement
*     DSG_EcuM_OnGoOffTwo
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_OnGoOffTwo
*/
EXPORTED FUNC(void, ECUM_APPL_CODE) EcuM_OnGoOffTwo(void)
{
  /* Ecu Manager module invokes this callout on entry actions of OffPostOS
   * sequence. */
}

/**
* \brief
*     This service is a callout that turn off the power supply of the ECU
*     and this is the last activity in the OffPostOS Sequence. 
*     If the ECU cannot unpower itself, a reset may be an adequate reaction.
* \dynamicaspectcaller
*     EcuM_Shutdown
* \dynamicaspectdescription
*     Called by EcuM_Shutdown at shutdown/reset procedure.
* \ddesignrequirement
*     DSG_EcuM_AL_SwitchOff
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_AL_SwitchOff
*     ARCH_SW_EcuMIf_pclSbcServices_EcuM_AL_SwitchOff
*     ARCH_SW_EcuMIf_pclNotifyResetCause_EcuM_AL_SwitchOff
*/
EXPORTED FUNC(void, ECUM_APPL_CODE) EcuM_AL_SwitchOff(void)
{
  /* Notify RCM module */
  Rte_Call_pclNotifyResetCause_NotifyResetCause(KU32_WAKE_UP_EVENT_NOTIFICATION);

  /* Call SBC Shutdown to cut off the uC power supply */
  Rte_Call_pclSbcServices_SBC_Shutdown();
}

/**
* \brief
*     When the shutdown target is RESET, the ECU Manager module invokes
*     this callout. This callout shall take the code for resetting the ECU.
* \inputparam
*     Name: reset;
*     Type: EcuM_ResetType - uint8;
*     Description: Tells which type of reset to be done in Ecu;
*     Range: 
*        ECUM_RESET_MCU - Perform Microcontroller reset via Mcu_PerformReset
*        ECUM_RESET_WDG - Perform Watchdog reset via WdgM_PerformReset
*        ECUM_RESET_IO  - Perform Reset by toggeling an I/O line;
* \dynamicaspectcaller
*     EcuM_Shutdown
* \dynamicaspectdescription
*     Called by EcuM_Shutdown at shutdown/reset procedure.
* \ddesignrequirement
*     DSG_EcuM_AL_Reset
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_AL_Reset;
*     ARCH_SW_EcuMIf_ptrrAsrMcuServicesEcuMIf_Mcu_PerformReset_EcuM_AL_Reset;
*     ARCH_SW_EcuMIf_pclSbcServices_EcuM_AL_Reset
*/
EXPORTED FUNC(void, ECUM_APPL_CODE) EcuM_AL_Reset(EcuM_ResetType reset)
{
  if (ECUM_RESET_MCU == reset)
  {
    /* If Mcu reset is requested perform it */
    Mcu_PerformReset();
  }
  else if (ECUM_RESET_EXT_WDG == reset)
  {
    /* If External watchdog reset is requested perform it */
    Rte_Call_pclSbcServices_SBC_Reset();

    /* In case debugger is present do a SW reset to force reset */
    Mcu_PerformReset();
  }
  else
  {
    /* Else if another type of reset is requested perform external wdg */
    Rte_Call_pclSbcServices_SBC_Reset();

    /* In case debugger is present do a SW reset to force reset */
    Mcu_PerformReset();
  }
}

/**
* \brief
*     EcuM invokes this callout function in Poll sequence in a blocking loop at
*     maximum frequency until a pending wakeup event is reported if the MCU is not
*     halted (i.e. clock is reduced). 
* \dynamicaspectcaller
*     EcuM_GoPoll
* \dynamicaspectdescription
*     Called by periodically by EcuM_GoPoll.
* \ddesignrequirement
*     DSG_EcuM_SleepActivity
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_SleepActivity
*/
EXPORTED FUNC(void,ECUM_APPL_CODE) EcuM_SleepActivity(void)
{

}

/**
* \brief
*     Callout during sleep state. In this callout all the execution of interrupts 
*     leading to wakeup will be disabled. This will be called before setting up the 
*     ECU in to Halt mode. This prevents the ECU from neglecting the pending wakeup 
*     events, which occurred due to the execution of ISR before the call to Mcu_SetMode() 
*     This callout is invoked by EcuM periodically in SLEEP state, but only if the CPU is 
*     not suspended (i.e. clock is reduced). 
* \dynamicaspectcaller
*     EcuM_HaltSequence
* \dynamicaspectdescription
*     Called by periodically by EcuM_HaltSequence.
* \ddesignrequirement
*     DSG_EcuM_PreHalt
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_PreHalt
*/
EXPORTED FUNC(void, ECUM_APPL_CODE) EcuM_PreHalt(void)
{

}

/**
* \brief
*     Callout during sleep state. In this callout all the interrupts 
*     will be enabled which are disabled by the EcuM_PreHalt(). This will
*     be called after a wakeup event that will return the function Mcu_SetMode() 
*     This callout is invoked by EcuM periodically in SLEEP state, but only if 
*     the CPU is not suspended (i.e. clock is reduced).
* \dynamicaspectcaller
*     EcuM_HaltSequence
* \dynamicaspectdescription
*     Called by periodically by EcuM_HaltSequence.
* \ddesignrequirement
*     DSG_EcuM_PostHalt
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_PostHalt
*/
EXPORTED FUNC(void, ECUM_APPL_CODE) EcuM_PostHalt(void)
{

}

/**
* \brief
*     Callout which starts pending wakeup sources. In this method
*     are set up the conditions, so that a wakeup source can validate 
*     a wakeup event. This callout is invoked in wakeup state.
* \inputparam
*     Name: wakeupSource;
*     Type: EcuM_WakeupSourceType - uint32;
*     Description: Provides one bit for each wakeup source;
*     Range: 
*       ECUM_WKSOURCE_CAN - 32U
*       ECUM_WKSOURCE_EXTERNAL_WDG - 16U
*       EcuM_ECUM_WKSOURCE_INTERNAL_WDG - 8U
*       EcuM_ECUM_WKSOURCE_INTERNAL_RESET - 4U
*       EcuM_ECUM_WKSOURCE_RESET - 2U
*       EcuM_ECUM_WKSOURCE_POWER - 1U;
* \dynamicaspectcaller
*     EcuM_MainFunction
* \dynamicaspectdescription
*     Called by periodically by EcuM_MainFunction.
* \ddesignrequirement
*     DSG_EcuM_StartWakeupSources
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_StartWakeupSources
*     ARCH_SW_EcuMIf_ptrrAsrCanIfServicesEcuMIf_CanIf_SetControllerMode_EcuM_StartWakeupSources
*/
EXPORTED FUNC(void,ECUM_APPL_CODE) EcuM_StartWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
  /* If wakeupSource is assigned to CAN channel */
  if( ECUMIF_KU32_WKSOURCE_NONE_SOURCES != (wakeupSource & ECUM_WKSOURCE_CAN) )
  {
     (void)CanIf_SetControllerMode(CanConf_CanController_ctl_MQBw_Baseline_Airbag_SUBCANFD_KMatrix_V14_08_02E_20220819_MH_Alv, CANIF_CS_STOPPED);
     (void)CanIf_SetControllerMode(CanConf_CanController_ctl_MQBw_Baseline_Airbag_SUBCANFD_KMatrix_V14_08_02E_20220819_MH_Alv, CANIF_CS_STARTED);
  }
  else
  {
    /* Do nothing */
  }
}

/**
* \brief
*     Callout which stops pending and expired wakeup sources. In this 
*     method are stopped the wakeup sources, previously started in callout
*     function EcuM_StartWakeupSources(). This callout is invoked in wakeup
*     validation state after a failed validation of an wakeup event.
* \inputparam
*     Name: wakeupSource;
*     Type: EcuM_WakeupSourceType - uint32;
*     Description: Provides one bit for each wakeup source;
*     Range: 
*       ECUM_WKSOURCE_CAN - 32U
*       ECUM_WKSOURCE_EXTERNAL_WDG - 16U
*       EcuM_ECUM_WKSOURCE_INTERNAL_WDG - 8U
*       EcuM_ECUM_WKSOURCE_INTERNAL_RESET - 4U
*       EcuM_ECUM_WKSOURCE_RESET - 2U
*       EcuM_ECUM_WKSOURCE_POWER - 1U;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     EcuM_MainFunction
* \dynamicaspectdescription
*     Called by periodically by EcuM_MainFunction.
* \ddesignrequirement
*     DSG_EcuM_StopWakeupSources
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_StopWakeupSources
*     ARCH_SW_EcuMIf_ptrrAsrCanIfServicesEcuMIf_CanIf_SetControllerMode_EcuM_StopWakeupSources
*/
EXPORTED FUNC(void,ECUM_APPL_CODE) EcuM_StopWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
  /*
   *  Implementation hint:
   *  CanIf_SetControllerMode(CanConf_CanController_ctl_MQBw_Baseline_Airbag_SUBCANFD_KMatrix_V14_08_02E_20220819_MH_Alv, CANIF_CS_STOPPED);
   */
  if( ECUMIF_KU32_WKSOURCE_NONE_SOURCES != (wakeupSource & ECUM_WKSOURCE_CAN) )
  {
    (void)CanIf_SetControllerMode(CanConf_CanController_ctl_MQBw_Baseline_Airbag_SUBCANFD_KMatrix_V14_08_02E_20220819_MH_Alv, CANIF_CS_STOPPED);
  }
}

/**
* \brief
*     This service is a callout used to enable wakeup sources.
*     This callout is invoked before EcuM enter in Sleep.
* \inputparam
*     Name: wakeupSource;
*     Type: EcuM_WakeupSourceType - uint32;
*     Description: Provides one bit for each wakeup source;
*     Range: 
*       ECUM_WKSOURCE_CAN - 32U
*       ECUM_WKSOURCE_EXTERNAL_WDG - 16U
*       EcuM_ECUM_WKSOURCE_INTERNAL_WDG - 8U
*       EcuM_ECUM_WKSOURCE_INTERNAL_RESET - 4U
*       EcuM_ECUM_WKSOURCE_RESET - 2U
*       EcuM_ECUM_WKSOURCE_POWER - 1U;
* \dynamicaspectcaller
*     EcuM_GoSleep
* \dynamicaspectdescription
*     Called by EcuM_GoSleep at shutdown/reset procedure.
* \ddesignrequirement
*     DSG_EcuM_EnableWakeupSources
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_EnableWakeupSources
*/
EXPORTED FUNC(void,ECUM_APPL_CODE) EcuM_EnableWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
  /* Macro used to avoid compiler warnings remove if parameter is used */
  TS_PARAM_UNUSED(wakeupSource);

  /* Implement the routine to notify the wakeup sources defined in the wakeupSource
   * bitfield that SLEEP will be entered and enable the wakeup functionality accordingly
   * in this callout function.
   *
   *  Implementation hint:
   *
   *  Enable CAN Wakeup:
   * 
   *  if (wakeupSource is assigned to CAN channel)
   *  {
   *    CanIf_SetTrcvWakeupMode(TransceiverId, TrcvWakeupMode);
   *  }
   */
}

/**
* \brief
*     This service is a callout which disables pending wakeup sources. 
*     This callout is invoked after a wakeup event is detected.
* \inputparam
*     Name: wakeupSource;
*     Type: EcuM_WakeupSourceType - uint32;
*     Description: Provides one bit for each wakeup source;
*     Range: 
*       ECUM_WKSOURCE_CAN - 32U
*       ECUM_WKSOURCE_EXTERNAL_WDG - 16U
*       EcuM_ECUM_WKSOURCE_INTERNAL_WDG - 8U
*       EcuM_ECUM_WKSOURCE_INTERNAL_RESET - 4U
*       EcuM_ECUM_WKSOURCE_RESET - 2U
*       EcuM_ECUM_WKSOURCE_POWER - 1U;
* \dynamicaspectcaller
*     EcuM_WakeupRestart
* \dynamicaspectdescription
*     Called by EcuM_WakeupRestart at GoHalt or GoPoll procedure.
* \ddesignrequirement
*     DSG_EcuM_DisableWakeupSources
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_DisableWakeupSources
*/
EXPORTED FUNC(void,ECUM_APPL_CODE) EcuM_DisableWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
  TS_PARAM_UNUSED(wakeupSource); /* remove if parameter is used */

  /* Implement the routine to disable all wakeup sources in this callout function.
   *
   * The ECU Manager Module calls EcuM_DisableWakeupSources to set the wakeup
   * source(s) defined in the wakeupSource bitfield so that they are not able
   * to wake the ECU up and will be invoked in the WakeupRestart Sequence.
   *  
   */
}

/**
* \brief
*     Callout which checks pending wakeup sources. This callout is 
*     invoked in wakeup validation state and is checked all wakeup 
*     sources for validation of a pending wakeup event.
* \inputparam
*     Name: wakeupSource;
*     Type: EcuM_WakeupSourceType - uint32;
*     Description: Provides one bit for each wakeup source;
*     Range:
*        ECUM_WKSOURCE_CAN - 32U
*        ECUM_WKSOURCE_EXTERNAL_WDG - 16U
*        EcuM_ECUM_WKSOURCE_INTERNAL_WDG - 8U
*        EcuM_ECUM_WKSOURCE_INTERNAL_RESET - 4U
*        EcuM_ECUM_WKSOURCE_RESET - 2U
*        EcuM_ECUM_WKSOURCE_POWER - 1U;
* \dynamicaspectcaller
*     EcuM_MainFunction
* \dynamicaspectdescription
*     Called in EcuM_MainFunction.
* \ddesignrequirement
*     DSG_EcuM_CheckValidation
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_CheckValidation
*     ARCH_SW_EcuMIf_ptrrAsrCanIfServicesEcuMIf_CanIf_CheckValidation_EcuM_CheckValidation
*/
EXPORTED FUNC(void,ECUM_APPL_CODE) EcuM_CheckValidation (EcuM_WakeupSourceType wakeupSource)
{
  /* Implement the routine to validate a wakeup source with in this callout function.
   *
   * If a valid wakeup has been detected, it shall be reported to EcuM
   * via EcuM_ValidateWakeupEvent().
   * This callout will be invoked by EcuM in the Wakeup Validation Sequence.
   *
   * Implementation hint :
   *
   * if (wakeupSource is assigned to CAN channel)
   * {
   *   CanIf_CheckValidation(WakeupSource);
   * }
   *    
   */
  if(ECUMIF_KU32_WKSOURCE_NONE_SOURCES != (wakeupSource & ECUM_WKSOURCE_CAN))
  {
     (void)CanIf_CheckValidation(ECUM_WKSOURCE_CAN);
  }
}

/**
* \brief
*     Callout which checks wakeup sources. In this callout the 
*     wakeup sources are verified for detected wakeup events. 
*     These wakeup events are reported using EcuM_SetWakeupEvent(). 
*     This callout is invoked during sleep state or is invoked by an 
*     ISR resulting from an wakeup event, in case the CPU is powered 
*     of during sleep.
* \inputparam
*     Name: wakeupSource;
*     Type: EcuM_WakeupSourceType - uint32;
*     Description: Provides one bit for each wakeup source;
*     Range: 
*       ECUM_WKSOURCE_CAN - 32U
*       ECUM_WKSOURCE_EXTERNAL_WDG - 16U
*       EcuM_ECUM_WKSOURCE_INTERNAL_WDG - 8U
*       EcuM_ECUM_WKSOURCE_INTERNAL_RESET - 4U
*       EcuM_ECUM_WKSOURCE_RESET - 2U
*       EcuM_ECUM_WKSOURCE_POWER - 1U;
* \dynamicaspectcaller
*     EcuM_GoPoll
* \dynamicaspectdescription
*     Called in EcuM_GoPoll.
* \ddesignrequirement
*     DSG_EcuM_CheckWakeup
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrEcuMServicesEcuMIf_EcuM_CheckWakeup
*/
EXPORTED FUNC(void,ECUM_APPL_CODE) EcuM_CheckWakeup (EcuM_WakeupSourceType wakeupSource)
{
  /* Macro used to avoid compiler warnings remove if parameter is used */
  TS_PARAM_UNUSED(wakeupSource);
  
  /* Implement the routine to poll for a wakeup source in this callout function.
   *
   * It may also be called by the ISR of a wakeup source to set up the PLL and set
   * other wakeup sources that may be connected to the same interrupt.
   *
   * The Ecu Manager module invokes EcuM_CheckWakeup() periodically during the Poll
   * sequence(See section 7.5.3 Activities in the Poll Sequence) if the MCU is not halted
   * or when handling a wakeup interrupt.
   * If called from the Poll sequence, EcuM calls this callout functions in a blocking
   * loop at maximum frequency. The implementation must ensure by other means if callout
   * code shall be executed with a lower period. Choose any method to control the
   * execution period. eg. with the help of OS counters, OS alarms or GPT timers.
   *
   *  Implementation hint:
   *
   *  FUNC(void,ECUM_APPL_CODE) EcuM_CheckWakeup (EcuM_WakeupSourceType wakeupSource)
   *  {
   *    <Module>_CheckWakeup(wakeupSource);
   *  }
   */
}

/**
* \brief
*     This service shall evaluate the WakeupSource parameter to get the information,
*     which dedicate wakeup source needs to be checked, either a CAN transceiver or 
*     controller device. This routine is called by CanIf or an upper layer according 
*     to Autosar requirements.
* \inputparam
*     Name: controller;
*     Type: uint8;
*     Description: controller ID based on configuration order list (CanControllerId);
*     Range: 0..1;
* \return
*      o CAN_OK     (KU8_ZERO) - Success; 
*      o CAN_NOT_OK (KU8_ONE)  - Error occurred or wakeup event occurred during sleep 
*                                transition; 
*      o CAN_BUSY   (KU8_TWO)  - Transmit request could not be processed because no 
*                                transmit object was available;
* \dynamicaspectcaller
*     CanIf_CheckWakeup
* \dynamicaspectdescription
*     Called in CanIf_CheckWakeup to check for Can and CanTrcv wakeups;
* \ddesignrequirement
*     DSG_EcuM_Can_CheckWakeup
* \archrequirement
*     ARCH_SW_EcuMIf_ptrpAsrCanIfServicesEcuMIf_Can_CheckWakeup
*/
EXPORTED FUNC (uint8, CAN_CODE) Can_CheckWakeup( VAR(uint8, AUTOMATIC) controller)
{
   return 0u;
}
 

#define EcuMIf_STOP_SEC_CODE
#include "EcuMIf_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
