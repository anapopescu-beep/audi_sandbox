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
$Revision: 1.39 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/FSM/Implementation/src/project.pj $
*/

/*!****************************************************************************

details
   The purpose of this module is to handle the internal and external condition of
   solenoid inhibition.

******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "FSM.h"
#include "Rte_FSM.h"
#include "Nvp_Cfg.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *      Used to disable modes
 */
#define KU8_FSM_MODE_STATUS_OFF                       (KU8_FALSE)

/**
 * \brief
 *      Used to enable modes
 */
#define KU8_FSM_MODE_STATUS_ON                        (KU8_TRUE)

/**
 * \brief
 *      Used to determine the number of Dem events that are present in au8SporadicHwErrorDemEventCfg
 */
#define KU8_FSM_SPORADIC_HW_ERROR_DEM_EVENT_NB        (KU8_SIX)

/**
 * \brief
 *      Used to determine the number of Dem events that are present in au8PermanentHwErrorDemEventCfg
 */
#define KU8_FSM_PERMANENT_HW_ERROR_DEM_EVENT_NB       (KU8_TWELVE)

/**
 * \brief
 *      Used to determine the number of Dem events that are present in auSolenoidDisableDemEventCfg
 */
#define KU8_FSM_SOLENOID_ABORTION_DEM_EVENT_NB        (KU8_EIGHTEEN)

/**
 * \brief
 *      Used to determine the number of Dem events that are present in fsm_kau8SolenoidInhibionEvtList
 */
#define KU8_FSM_SOLENOID_INHIBITION_DEM_EVENT_NB      ((uint8) 0x04)

/**
 * \brief
 *      Used to determine if all the modules passed the initialization phase
 */
#define KU8_FSM_INIT_WAIT_READY                       ((uint8) 25)

/**
 * \brief
 *      Used to indicate the number of functions from the schedule list
 */
#define KU8_FSM_SCHADULE_NB_OF_FCNS                   ((uint8) 0x09)

/**
 * \brief
 *       Main timing (1ms) scheduler manager parameters macros,
 *       to be used in sorting function calls
 */
#define  KST_FSM_PERIODIC_1_MS                        (uint16) 1, (uint8) 0

/**
 * \brief
 *       Decade value used to offset function call execution with 0 cycle
 */
#define  KU8_FSM_IN_DECADE_0                          ((uint8) 0)

/**
 * \brief
 *       Decade value used to offset function call execution with 1 cycle
 */
#define  KU8_FSM_IN_DECADE_1                          ((uint8) 1)

/**
 * \brief
 *       Decade value used to offset function call execution with 2 cycle
 */
#define  KU8_FSM_IN_DECADE_2                          ((uint8) 2)

/**
 * \brief
 *       Decade value used to offset function call execution with 3 cycle
 */
#define  KU8_FSM_IN_DECADE_3                          ((uint8) 3)

/**
 * \brief
 *      Mask for mode status initialized status flag
 */
#define KU8_FSM_MASK_NVM_BLOCK_RESTORED               ((uint8) 0x02)

/**
 * \brief
 *      Used to detect no modes enabled
 */
#define KU64_FSM_MASK_NO_MODE                         ((uint64) 0x00)

/**
 * \brief
 *      Used to as initial value
 */
#define KU64_FSM_MASK_INITIAL_VALUE                   (KU64_CRITICAL_AUTOTESTS_IN_PROGRESS | KU64_NVM_BLOCK_RESTORE_IN_PROGRESS | KU64_INIT_PHASE_IN_PROGRESS | KU64_ECU_BATTERY_UNSTABLE)

/******************************************************************************
MODULE TYPES
******************************************************************************/

/**
 * \brief
 *       Data structure used to configure control the periodicity of function
 *       calls.
 */
typedef struct fsm_SchedulerFunction_Type {
   const uint16 ku16Period;               // Rate at which the task should tick
   const uint8 ku8Offset;                 // Offset added to the period
   void (*pfFunctionCallback)(void);      // Function to call for task's tick
} fsm_SchadulerFunction_Type;

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/
/**
 * \brief
 *       Mask used to enable modes
 */
#define KU64_FSM_SET_MODE_MASK_ON(mask) \
   U64_BIT_SET   (fsm_u64ModesStatus, (mask)); \
   U64_BIT_CLEAR (fsm_u64ModesStatusComplement, (mask))

/**
 * \brief
 *      Mask used to disable modes
 */
#define KU64_FSM_SET_MODE_MASK_OFF(mask) \
   U64_BIT_CLEAR (fsm_u64ModesStatus, (mask)); \
   U64_BIT_SET   (fsm_u64ModesStatusComplement, (mask))

/**
 * \brief
 *       Main timing (2ms) scheduler manager parameters macros,
 *       to be used in sorting function calls order
 */
#define  KST_FSM_PERIODIC_2_MS(decade)          (uint16) 2, (decade)

/**
 * \brief
 *       Main timing (5ms) scheduler manager parameters macros,
 *       to be used in sorting function calls order
 */
#define  KST_FSM_PERIODIC_5_MS(decade)          (uint16) 5, (decade)

/**
 * \brief
 *       Main timing (10ms) scheduler manager parameters macros,
 *       to be used in sorting function calls order
 */
#define  KST_FSM_PERIODIC_10_MS(decade)         (uint16) 10, (decade)

/**
 * \brief
 *       Main timing (100ms) scheduler manager parameters macros,
 *       to be used in sorting function calls order
 */
#define  KST_FSM_PERIODIC_100_MS(decade)        (uint16) 100, (decade)

/**
 * \brief
 *       Main timing (1s) scheduler manager parameters macros,
 *       to be used in sorting function calls order
 */
#define  KST_FSM_PERIODIC_1_S(decade)           (uint16) 1000, (decade)
/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL_INLINE void fsm_UpdateModeStatus_SolenoidAbortionErrorPresentConditions(void);
LOCAL_INLINE void fsm_UpdateModeStatus_SolenoidInhibitionErrorPresentConditions(void);
LOCAL_INLINE void fsm_UpdateModeStatus_SolenoidEnabledConditions(void);
LOCAL_INLINE void fsm_UpdateModeStatus_SolenoidUnlockConfirmation(void);
LOCAL_INLINE void fsm_UpdateModeStatus_NvmBlockRestore(void);
LOCAL_INLINE void fsm_UpdateModeStatus_Init(void);
LOCAL_INLINE void fsm_UpdateModeStatus_EcuBatteryUnstableInhibition(void);
LOCAL_INLINE void fsm_UpdateModeStatus_SporadicHwError(void);
LOCAL_INLINE void fsm_UpdateModeStatus_PermanentHwError(void);
LOCAL_INLINE void fsm_UpdateModeStatus_CanInhibit(void);
LOCAL_INLINE void fsm_UpdateModeStatus_BuckleStatus(void);
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

#define FSM_START_SEC_VAR_INIT_8_ASIL_A
#include "FSM_MemMap.h"

/**
 * \brief
 *      To detect if the modes have been initialized.
 * \initialization
 *      KU8_FALSE (uint8 0x55).
 * \range
 *      KU8_FALSE or KU8_TRUE.
 */
LOCAL uint8 fsm_u8ModesHasBeenInitialized = KU8_FALSE;

/**
 * \brief
 *      To detect if the modes have been initialized.
 * \initialization
 *      KU8_FALSE (uint8 0x55).
 * \range
 *      KU8_FALSE or KU8_TRUE.
 */
LOCAL uint8 fsm_u8InitializationFinished = KU8_FALSE;

/**
 * \brief
 *      To count the number of samples of measurements under the UV threshold.
 * \initialization
 *      KU8_ZERO
 * \range
 *      0..255
 */
LOCAL uint8 fsm_u8BatteryUnstableCnt = KU8_ZERO;

#define FSM_STOP_SEC_VAR_INIT_8_ASIL_A
#include "FSM_MemMap.h"

#define FSM_START_SEC_VAR_INIT_16_ASIL_A
#include "FSM_MemMap.h"

/**
 * \brief
 *       Variable use to store the counter value of callback number of function
 *       FSM_runUpdateModeStatus.
 * \initialization
 *       KU16_ZERO (uint16 0).
 * \range
 *       0..KU16_MAX.
 */
LOCAL uint16 fsm_u16CurrentDecade = KU16_ZERO;

#define FSM_STOP_SEC_VAR_INIT_16_ASIL_A
#include "FSM_MemMap.h"

#define FSM_START_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
#include "FSM_MemMap.h"

/**
 * \brief
 *      Used to store FSM modes status.
 * \initialization
 *      KU64_ZERO (uint64 0x0000000000000000).
 * \range
 *      0..KU64_MAX
 */
LOCAL uint64 fsm_u64ModesStatus = KU64_ZERO;

/**
 * \brief
 *      Used to store FSM modes status complement.
 * \initialization
 *      Complement of KU64_ZERO (uint64 0xFFFFFFFFFFFFFFFF).
 * \range
 *      0..KU64_MAX
 */
LOCAL uint64 fsm_u64ModesStatusComplement = U64_COMPLEMENT(KU64_ZERO);

#define FSM_STOP_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
#include "FSM_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
#define FSM_START_SEC_CONST_8_ASIL_A
#include "FSM_MemMap.h"

/**
 * \brief
 *       Configuration array that holds what Dem events will set the sporadic HW error mask.
 * \initialization
 *       DemConf_DemEventParameter_EVENT_CANSM_E_BUS_OFF          ( 1)
 *       DemConf_DemEventParameter_EVENT_ECU_OVER_TEMPERATURE     ( 9)
 *       DemConf_DemEventParameter_EVENT_POWER_SUPPLY_OV          (12)
 *       DemConf_DemEventParameter_EVENT_POWER_SUPPLY_UV          (13)
 *       DemConf_DemEventParameter_EVENT_SPI_E_HW_ERROR           (20);
 */
LOCAL const uint8 fsm_kau8SporadicHwErrorDemEventCfg[KU8_FSM_SPORADIC_HW_ERROR_DEM_EVENT_NB] =
{
   DemConf_DemEventParameter_EVENT_CANSM_E_BUS_OFF,
   DemConf_DemEventParameter_EVENT_ECU_OVER_TEMPERATURE,
   DemConf_DemEventParameter_EVENT_POWER_SUPPLY_OV,
   DemConf_DemEventParameter_EVENT_POWER_SUPPLY_UV,
   DemConf_DemEventParameter_EVENT_SPI_E_HW_ERROR,
   DemConf_DemEventParameter_EVENT_NVM_NOT_PRG
};

/**
 * \brief
 *       Configuration array that holds what Dem events will set the permanent HW error mask.
 * \initialization
 *       DemConf_DemEventParameter_EVENT_ADC_OUT_OF_ORDER         ( 2)
 *       DemConf_DemEventParameter_EVENT_WARM_RESET               ( 3)
 *       DemConf_DemEventParameter_EVENT_PFLASH_MEM_CORRUPT       ( 4)
 *       DemConf_DemEventParameter_EVENT_EXT_WDG_OUT_OF_ORDER     ( 5)
 *       DemConf_DemEventParameter_EVENT_RAM_MEM_CORRUPT          ( 7)
 *       DemConf_DemEventParameter_EVENT_ADC_CALIB                ( 8)
 *       DemConf_DemEventParameter_EVENT_DFLASH_MEM_CORRUPT       (10)
 *       DemConf_DemEventParameter_EVENT_SBC_STATUS_FAILURE       (11)
 *       DemConf_DemEventParameter_EVENT_MCU_SELFTEST             (15)
 *       DemConf_DemEventParameter_EVENT_ACC_STATUS_FAILURE       (19);
 */
LOCAL const uint8 fsm_kau8PermanentHwErrorDemEventCfg[KU8_FSM_PERMANENT_HW_ERROR_DEM_EVENT_NB] =
{
   DemConf_DemEventParameter_EVENT_ADC_OUT_OF_ORDER,
   DemConf_DemEventParameter_EVENT_WARM_RESET,
   DemConf_DemEventParameter_EVENT_PFLASH_MEM_CORRUPT,
   DemConf_DemEventParameter_EVENT_EXT_WDG_OUT_OF_ORDER,
   DemConf_DemEventParameter_EVENT_RAM_MEM_CORRUPT,
   DemConf_DemEventParameter_EVENT_ADC_CALIB,
   DemConf_DemEventParameter_EVENT_DFLASH_MEM_CORRUPT,
   DemConf_DemEventParameter_EVENT_SBC_STATUS_FAILURE,
   DemConf_DemEventParameter_EVENT_MCU_SELFTEST,
   DemConf_DemEventParameter_EVENT_ACC_STATUS_FAILURE,
   DemConf_DemEventParameter_EVENT_POWER_STAGE_FAILIURE,
   DemConf_DemEventParameter_EVENT_MCU_CRC_REGISTERS
};

/**
 * \brief
 *       Configuration array that holds what Dem events will set the solenoid disable error mask.
 * \initialization
 *       DemConf_DemEventParameter_EVENT_CANSM_E_BUS_OFF          ( 1)
 *       DemConf_DemEventParameter_EVENT_ADC_OUT_OF_ORDER         ( 2)
 *       DemConf_DemEventParameter_EVENT_WARM_RESET               ( 3)
 *       DemConf_DemEventParameter_EVENT_PFLASH_MEM_CORRUPT       ( 4)
 *       DemConf_DemEventParameter_EVENT_EXT_WDG_OUT_OF_ORDER     ( 5)
 *       DemConf_DemEventParameter_EVENT_RAM_MEM_CORRUPT          ( 7)
 *       DemConf_DemEventParameter_EVENT_ADC_CALIB                ( 8)
 *       DemConf_DemEventParameter_EVENT_ECU_OVER_TEMPERATURE     ( 9)
 *       DemConf_DemEventParameter_EVENT_DFLASH_MEM_CORRUPT       (10)
 *       DemConf_DemEventParameter_EVENT_SBC_STATUS_FAILURE       (11)
 *       DemConf_DemEventParameter_EVENT_MCU_SELFTEST             (15)
 *       DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_VBAT   (18)
 *       DemConf_DemEventParameter_EVENT_ACC_STATUS_FAILURE       (19)
 *       DemConf_DemEventParameter_EVENT_POWER_SUPPLY_OV          (12)
 *       DemConf_DemEventParameter_EVENT_POWER_SUPPLY_UV          (13)
 *       DemConf_DemEventParameter_EVENT_SPI_E_HW_ERROR           (20);
 */
LOCAL const uint8 fsm_kau8SolenoidAbortionEvtList[KU8_FSM_SOLENOID_ABORTION_DEM_EVENT_NB] =
{
   DemConf_DemEventParameter_EVENT_CANSM_E_BUS_OFF,
   DemConf_DemEventParameter_EVENT_ADC_OUT_OF_ORDER,
   DemConf_DemEventParameter_EVENT_WARM_RESET,
   DemConf_DemEventParameter_EVENT_PFLASH_MEM_CORRUPT,
   DemConf_DemEventParameter_EVENT_EXT_WDG_OUT_OF_ORDER,
   DemConf_DemEventParameter_EVENT_RAM_MEM_CORRUPT,
   DemConf_DemEventParameter_EVENT_ADC_CALIB,
   DemConf_DemEventParameter_EVENT_ECU_OVER_TEMPERATURE,
   DemConf_DemEventParameter_EVENT_DFLASH_MEM_CORRUPT,
   DemConf_DemEventParameter_EVENT_SBC_STATUS_FAILURE,
   DemConf_DemEventParameter_EVENT_MCU_SELFTEST,
   DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_VBAT,
   DemConf_DemEventParameter_EVENT_ACC_STATUS_FAILURE,
   DemConf_DemEventParameter_EVENT_POWER_SUPPLY_OV,
   DemConf_DemEventParameter_EVENT_POWER_SUPPLY_UV,
   DemConf_DemEventParameter_EVENT_SPI_E_HW_ERROR,
   DemConf_DemEventParameter_EVENT_NVM_NOT_PRG,
   DemConf_DemEventParameter_EVENT_MCU_CRC_REGISTERS
};

/**
 * \brief
       Configuration array that holds what Dem events will Abort the solenoids
       functionality until the error disappears and set the solenoid error
       present mask.
 * \initialization
 *     DemConf_DemEventParameter_EVENT_ACTUATOR_STATUS          (14)
 *     DemConf_DemEventParameter_EVENT_ACTUATOR_OPEN_CIRCUIT    (16)
 *     DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_GND    (17)
 *     DemConf_DemEventParameter_EVENT_SOLENOID_OVERVOLTAGE     (21);
 */
LOCAL const uint8 fsm_kau8SolenoidInhibionEvtList[KU8_FSM_SOLENOID_INHIBITION_DEM_EVENT_NB] =
{
      DemConf_DemEventParameter_EVENT_ACTUATOR_STATUS,
      DemConf_DemEventParameter_EVENT_ACTUATOR_OPEN_CIRCUIT,
      DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_GND,
      DemConf_DemEventParameter_EVENT_SOLENOID_OVERVOLTAGE
};
#define FSM_STOP_SEC_CONST_8_ASIL_A
#include "FSM_MemMap.h"

#define FSM_START_SEC_CONST_UNSPECIFIED_ASIL_A
#include "FSM_MemMap.h"

/**
 * \brief
 *       Configuration array that holds bit masks for all solenoids .
 * \initialization
 *       KU64_SOLENOID_X_CONFIGURED
 *       where X - the solenoid number.
 */
LOCAL const uint64 fsm_kau64SolenoidConfiguredBitMask[KU8_MAX_SOLENOID_NB] =
{
      KU64_SOLENOID_1_CONFIGURED, KU64_SOLENOID_2_CONFIGURED, KU64_SOLENOID_3_CONFIGURED,
      KU64_SOLENOID_4_CONFIGURED, KU64_SOLENOID_5_CONFIGURED, KU64_SOLENOID_6_CONFIGURED
};

/**
 * \brief
 *    Array of structures which defines the scheduler properties.
 *    The period parameters represents the number of ticks before execute
 *    the function: 1 tick = 1 call of FSM_runUpdateModeStatus (1ms).
 */
LOCAL const fsm_SchadulerFunction_Type fsm_kastScheduler[KU8_FSM_SCHADULE_NB_OF_FCNS] =
{  /*    Periodicity     |       Offset        |            Function call                                         */
   {KST_FSM_PERIODIC_10_MS(KU8_FSM_IN_DECADE_0),   &fsm_UpdateModeStatus_Init                                     },
   {KST_FSM_PERIODIC_10_MS(KU8_FSM_IN_DECADE_1),   &fsm_UpdateModeStatus_SporadicHwError                          },
   {KST_FSM_PERIODIC_10_MS(KU8_FSM_IN_DECADE_2),   &fsm_UpdateModeStatus_PermanentHwError                         },
   {KST_FSM_PERIODIC_2_MS(KU8_FSM_IN_DECADE_0),    &fsm_UpdateModeStatus_SolenoidUnlockConfirmation               },
   {KST_FSM_PERIODIC_10_MS(KU8_FSM_IN_DECADE_3),   &fsm_UpdateModeStatus_CanInhibit                               },
   {KST_FSM_PERIODIC_1_MS,                         &fsm_UpdateModeStatus_SolenoidAbortionErrorPresentConditions   },
   {KST_FSM_PERIODIC_1_MS,                         &fsm_UpdateModeStatus_SolenoidInhibitionErrorPresentConditions },
   {KST_FSM_PERIODIC_10_MS(KU8_FSM_IN_DECADE_3),   &fsm_UpdateModeStatus_BuckleStatus                             },
   {KST_FSM_PERIODIC_1_MS,                         &fsm_UpdateModeStatus_EcuBatteryUnstableInhibition             },
};

#define FSM_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
#include "FSM_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
#define FSM_START_SEC_CODE_ASIL_A
#include "FSM_MemMap.h"

/**
* \brief
*        The function is used to update Solenoid Abortion error bits from
*        the mode status variable based on an event list.
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        FSM_runUpdateModeStatus
* \dynamicaspectdescription
*        The function is used to update mode statuses.
* \ddesignrequirement
*        DSG_fsm_UpdateModeStatus_SolenoidAbortionErrorPresentConditions
* \archrequirement
*        ARCH_SW_FSM_ptrpAsrOsServices_FSM_runUpdateModeStatus
*        ARCH_SW_FSM_pclDemServices
*/
LOCAL_INLINE void fsm_UpdateModeStatus_SolenoidAbortionErrorPresentConditions(void)
{
   Dem_EventStatusExtendedType u8EventStatus = KU8_ZERO;
   register Dem_EventStatusExtendedType u8MergedErrorEventStatus = KU8_ZERO;
   register uint8 u8Idx;

   /* Read and merge all Abortion events statuses */
   for (u8Idx = KU8_ZERO; u8Idx < KU8_FSM_SOLENOID_ABORTION_DEM_EVENT_NB; u8Idx++)
   {
      (void)Rte_Call_pclDemServices_GetEventStatus(fsm_kau8SolenoidAbortionEvtList[u8Idx], &u8EventStatus);
      u8MergedErrorEventStatus |= u8EventStatus;
   }

   /* If an hardware error is detected, disable all solenoids */
   if (DEM_UDS_STATUS_TF == (u8MergedErrorEventStatus & DEM_UDS_STATUS_TF))
   {
      /* Set the Error Present */
      if(KB_TRUE == KB_eCS_SOLENOID_1_ENABLED_VARIANT)
      {
         KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_1_ABORTION_ERROR);
      }
      if(KB_TRUE == KB_eCS_SOLENOID_2_ENABLED_VARIANT)
      {
         KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_2_ABORTION_ERROR);
      }
      if(KB_TRUE == KB_eCS_SOLENOID_3_ENABLED_VARIANT)
      {
         KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_3_ABORTION_ERROR);
      }
      if(KB_TRUE == KB_eCS_SOLENOID_4_ENABLED_VARIANT)
      {
         KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_4_ABORTION_ERROR);
      }
      if(KB_TRUE == KB_eCS_SOLENOID_5_ENABLED_VARIANT)
      {
         KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_5_ABORTION_ERROR);
      }
      if(KB_TRUE == KB_eCS_SOLENOID_6_ENABLED_VARIANT)
      {
         KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_6_ABORTION_ERROR);
      }
   }
   else
   {
      /* Mode is cleared */
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_1_ABORTION_ERROR);
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_2_ABORTION_ERROR);
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_3_ABORTION_ERROR);
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_4_ABORTION_ERROR);
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_5_ABORTION_ERROR);
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_6_ABORTION_ERROR);
   }
}

/**
* \brief
*        The function is used to update Solenoid Inhibition error bits from
*        the mode status variable based on an event list.
* \exception
*        This function has no exceptions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        FSM_runUpdateModeStatus
* \dynamicaspectdescription
*        Called based on a schedule list from FSM_runUpdateModeStatus.
* \constrains
*        Called every 1 ms.
* \ddesignrequirement
*        DSG_fsm_UpdateModeStatus_SolenoidInhibitionErrorPresentConditions
* \archrequirement
*        ARCH_SW_FSM_ptrpAsrOsServices_FSM_runUpdateModeStatus
*        ARCH_SW_FSM_pclDemServices
*        ARCH_SW_FSM_prrSolenoidOpenCircuitStatus
*        ARCH_SW_FSM_prrSolenoidShortToGndStatus
*        ARCH_SW_FSM_prrSolenoidOverVoltageStatus
*/
LOCAL_INLINE void fsm_UpdateModeStatus_SolenoidInhibitionErrorPresentConditions(void)
{
   uint8 au8SolenoidErrorPresentOpenCircuit[KU8_MAX_SOLENOID_NB];
   uint8 au8SolenoidErrorPresentShortToGND[KU8_MAX_SOLENOID_NB];
   uint8 au8SolenoidErrorPresentOverVoltage[KU8_MAX_SOLENOID_NB];
   Dem_EventStatusExtendedType u8EventStatus = KU8_ZERO;
   register Dem_EventStatusExtendedType u8MergedInhibitionEventStatus = KU8_ZERO;
   register uint8 u8Idx;


   /* Read and merge all Inhibition events statuses */
   for (u8Idx = KU8_ZERO; u8Idx < KU8_FSM_SOLENOID_INHIBITION_DEM_EVENT_NB; u8Idx++)
   {
      (void)Rte_Call_pclDemServices_GetEventStatus(fsm_kau8SolenoidInhibionEvtList[u8Idx], &u8EventStatus);
      u8MergedInhibitionEventStatus |= u8EventStatus;
   }

   /* If a solenoid specific hardware error is detected, disable all solenoids */
   if (DEM_UDS_STATUS_TF == (u8MergedInhibitionEventStatus & DEM_UDS_STATUS_TF))
   {
      (void)Rte_Read_prrSolenoidOpenCircuitStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentOpenCircuit);
      (void)Rte_Read_prrSolenoidShortToGndStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToGND);
      (void)Rte_Read_prrSolenoidOverVoltageStatus_au8SolenoidOvervoltageStatus(au8SolenoidErrorPresentOverVoltage);
      /* Mode is set */
      if(KB_TRUE == KB_eCS_SOLENOID_1_ENABLED_VARIANT)
      {
         if((KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOpenCircuit[KU8_SOLENOID_1]) ||
            (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToGND[KU8_SOLENOID_1]) ||
            (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOverVoltage[KU8_SOLENOID_1]) ||
            (KU8_TRUE == FSM_au8SolenoidIsStuck[KU8_SOLENOID_1]))
         {
            KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_1_INHIB_ERROR);
         }
         else
         {
            KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_1_INHIB_ERROR);
         }
      }
      if(KB_TRUE == KB_eCS_SOLENOID_2_ENABLED_VARIANT)
      {
         if((KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOpenCircuit[KU8_SOLENOID_2]) ||
            (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToGND[KU8_SOLENOID_2]) ||
            (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOverVoltage[KU8_SOLENOID_2]) ||
            (KU8_TRUE == FSM_au8SolenoidIsStuck[KU8_SOLENOID_2]))
         {
            KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_2_INHIB_ERROR);
         }
         else
         {
            KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_2_INHIB_ERROR);
         }
      }
      if(KB_TRUE == KB_eCS_SOLENOID_3_ENABLED_VARIANT)
      {
         if((KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOpenCircuit[KU8_SOLENOID_3]) ||
            (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToGND[KU8_SOLENOID_3]) ||
            (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOverVoltage[KU8_SOLENOID_3]) ||
            (KU8_TRUE == FSM_au8SolenoidIsStuck[KU8_SOLENOID_3]))
         {
            KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_3_INHIB_ERROR);
         }
         else
         {
            KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_3_INHIB_ERROR);
         }
      }
      if(KB_TRUE == KB_eCS_SOLENOID_4_ENABLED_VARIANT)
      {
         if((KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOpenCircuit[KU8_SOLENOID_4]) ||
            (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToGND[KU8_SOLENOID_4]) ||
            (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOverVoltage[KU8_SOLENOID_4]) ||
            (KU8_TRUE == FSM_au8SolenoidIsStuck[KU8_SOLENOID_4]))
         {
            KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_4_INHIB_ERROR);
         }
         else
         {
            KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_4_INHIB_ERROR);
         }
      }
      if(KB_TRUE == KB_eCS_SOLENOID_5_ENABLED_VARIANT)
      {
         if((KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOpenCircuit[KU8_SOLENOID_5]) ||
            (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToGND[KU8_SOLENOID_5]) ||
            (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOverVoltage[KU8_SOLENOID_5]) ||
            (KU8_TRUE == FSM_au8SolenoidIsStuck[KU8_SOLENOID_5]))
         {
            KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_5_INHIB_ERROR);
         }
         else
         {
            KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_5_INHIB_ERROR);
         }
      }
      if(KB_TRUE == KB_eCS_SOLENOID_6_ENABLED_VARIANT)
      {
         if((KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOpenCircuit[KU8_SOLENOID_6]) ||
            (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToGND[KU8_SOLENOID_6]) ||
            (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOverVoltage[KU8_SOLENOID_6]) ||
            (KU8_TRUE == FSM_au8SolenoidIsStuck[KU8_SOLENOID_6]))
         {
            KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_6_INHIB_ERROR);
         }
         else
         {
            KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_6_INHIB_ERROR);
         }
      }
   }
   else
   {
      /* Mode is cleared */
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_1_INHIB_ERROR);
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_2_INHIB_ERROR);
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_3_INHIB_ERROR);
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_4_INHIB_ERROR);
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_5_INHIB_ERROR);
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_6_INHIB_ERROR);
   }
}

/**
* \brief
*        The function is used to set/clear mode mask bits for all solenoids
*        based on the NVP variant configuration (not used/used).
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        FSM_runUpdateModeStatus
* \dynamicaspectdescription
*        The function is used to update mode statuses.
* \ddesignrequirement
*        DSG_fsm_UpdateModeStatus_SolenoidEnabledConditions
* \archrequirement
*        ARCH_SW_Fsm_ptrpFsmServicesBswMIf_FSM_ModesInit
*        ARCH_SW_FSM_pseModeManagement_SolenoidDisabled
*/
LOCAL void fsm_UpdateModeStatus_SolenoidEnabledConditions(void)
{
   boolean abSolenoidEnableVariant[KU8_MAX_SOLENOID_NB];
   uint8 u8SolenoidIdx = KU8_ZERO;

   abSolenoidEnableVariant[KU8_SOLENOID_1] = KB_eCS_SOLENOID_1_ENABLED_VARIANT;
   abSolenoidEnableVariant[KU8_SOLENOID_2] = KB_eCS_SOLENOID_2_ENABLED_VARIANT;
   abSolenoidEnableVariant[KU8_SOLENOID_3] = KB_eCS_SOLENOID_3_ENABLED_VARIANT;
   abSolenoidEnableVariant[KU8_SOLENOID_4] = KB_eCS_SOLENOID_4_ENABLED_VARIANT;
   abSolenoidEnableVariant[KU8_SOLENOID_5] = KB_eCS_SOLENOID_5_ENABLED_VARIANT;
   abSolenoidEnableVariant[KU8_SOLENOID_6] = KB_eCS_SOLENOID_6_ENABLED_VARIANT;

   for(u8SolenoidIdx = KU8_ZERO; u8SolenoidIdx < KU8_MAX_SOLENOID_NB; u8SolenoidIdx++)
   {
      /* Check if solenoid is enabled in NVP Variant */
      if(KB_TRUE == abSolenoidEnableVariant[u8SolenoidIdx])
      {
         KU64_FSM_SET_MODE_MASK_ON(fsm_kau64SolenoidConfiguredBitMask[u8SolenoidIdx]);
      }
      else
      {
         KU64_FSM_SET_MODE_MASK_OFF(fsm_kau64SolenoidConfiguredBitMask[u8SolenoidIdx]);
      }
   }
}

/**
* \brief
*        The function is used to disable all solenoids if any hardware error
*        is detected and to provide confirmation for each disabled solenoid.
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        FSM_runUpdateModeStatus
* \dynamicaspectdescription
*        The function is used to update mode statuses.
* \ddesignrequirement
*        DSG_fsm_UpdateModeStatus_SolenoidUnlockConfirmation
* \archrequirement
*        ARCH_SW_FSM_ptrpAsrOsServices_FSM_runUpdateModeStatus
*        ARCH_SW_FSM_prrSolenoidConfirmation
*        ARCH_SW_FSM_pseModeManagement_SolenoidUnlockConfirmation
*/
LOCAL_INLINE void fsm_UpdateModeStatus_SolenoidUnlockConfirmation(void)
{
   uint8 au8SolenoidUnlockConfirmation[KU8_MAX_SOLENOID_NB];

   (void)Rte_Read_FSM_prrSolenoidConfirmation_au8SolenoidStatus(au8SolenoidUnlockConfirmation);


   /* If an hardware error is detected, disable all solenoids */
   if ((KU8_SOLENOID_UNLOCK_CONFIRMED == au8SolenoidUnlockConfirmation[KU8_SOLENOID_1]) && (TRUE == KB_eCS_SOLENOID_1_ENABLED_VARIANT))
   {
      /* Mode is set */
      KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_1_UNLOCK_CONFIRMED);
   }
   else
   {
      /* Mode is cleared */
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_1_UNLOCK_CONFIRMED);
   }

   if ((KU8_SOLENOID_UNLOCK_CONFIRMED == au8SolenoidUnlockConfirmation[KU8_SOLENOID_2]) && (TRUE == KB_eCS_SOLENOID_2_ENABLED_VARIANT))
   {
      /* Mode is set */
      KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_2_UNLOCK_CONFIRMED);
   }
   else
   {
      /* Mode is cleared */
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_2_UNLOCK_CONFIRMED);
   }

   if ((KU8_SOLENOID_UNLOCK_CONFIRMED == au8SolenoidUnlockConfirmation[KU8_SOLENOID_3]) && (TRUE == KB_eCS_SOLENOID_3_ENABLED_VARIANT))
   {
      /* Mode is set */
      KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_3_UNLOCK_CONFIRMED);
   }
   else
   {
      /* Mode is cleared */
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_3_UNLOCK_CONFIRMED);
   }

   if ((KU8_SOLENOID_UNLOCK_CONFIRMED == au8SolenoidUnlockConfirmation[KU8_SOLENOID_4]) && (TRUE == KB_eCS_SOLENOID_4_ENABLED_VARIANT))
   {
      /* Mode is set */
      KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_4_UNLOCK_CONFIRMED);
   }
   else
   {
      /* Mode is cleared */
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_4_UNLOCK_CONFIRMED);
   }

   if ((KU8_SOLENOID_UNLOCK_CONFIRMED == au8SolenoidUnlockConfirmation[KU8_SOLENOID_5]) && (TRUE == KB_eCS_SOLENOID_5_ENABLED_VARIANT))
   {
      /* Mode is set */
      KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_5_UNLOCK_CONFIRMED);
   }
   else
   {
      /* Mode is cleared */
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_5_UNLOCK_CONFIRMED);
   }

   if ((KU8_SOLENOID_UNLOCK_CONFIRMED == au8SolenoidUnlockConfirmation[KU8_SOLENOID_6]) && (TRUE == KB_eCS_SOLENOID_6_ENABLED_VARIANT))
   {
      /* Mode is set */
      KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_6_UNLOCK_CONFIRMED);
   }
   else
   {
      /* Mode is cleared */
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_6_UNLOCK_CONFIRMED);
   }
}

/**
* \brief
*        The function used to restore NVM Blocks.
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        FSM_runUpdateModeStatus
* \dynamicaspectdescription
*        The function is used to update mode statuses.
* \constraints
*        None
* \ddesignrequirement
*        DSG_fsm_UpdateModeStatus_NvmBlockRestore
* \archrequirement
*        ARCH_SW_FSM_ptrpAsrOsServices_FSM_runUpdateModeStatus
*        ARCH_SW_FSM_prrBswMIfServices
*        ARCH_SW_FSM_pseModeManagement_NvmBlockRestore
*/
LOCAL_INLINE void fsm_UpdateModeStatus_NvmBlockRestore(void)
{
   uint8 u8NvmBlockRestoreStatus = KU8_FALSE;

   (void)Rte_Read_prrBswMIfServices_u8BlockRestoreStatus(&u8NvmBlockRestoreStatus);

   /* If block restore is finished */
   if (KU8_TRUE == u8NvmBlockRestoreStatus)
   {
      /* Mode is cleared */
      KU64_FSM_SET_MODE_MASK_OFF(KU64_NVM_BLOCK_RESTORE_IN_PROGRESS);
      U8_BIT_SET(fsm_u8InitializationFinished, KU8_FSM_MASK_NVM_BLOCK_RESTORED);
   }
   else
   {
      /* Mode is set */
      KU64_FSM_SET_MODE_MASK_ON(KU64_NVM_BLOCK_RESTORE_IN_PROGRESS);
   }
}

/**
* \brief
*        The function is used to determine if a sporadic hardware error
*        is present.
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        FSM_runUpdateModeStatus
* \dynamicaspectdescription
*        The function is used to update mode statuses.
* \ddesignrequirement
*        DSG_fsm_UpdateModeStatus_SporadicHwError
* \archrequirement
*        ARCH_SW_FSM_ptrpAsrOsServices_FSM_runUpdateModeStatus
*        ARCH_SW_FSM_pclDemServices
*        ARCH_SW_FSM_pseModeManagement_EcuSporadicError
*/
LOCAL_INLINE void fsm_UpdateModeStatus_SporadicHwError(void)
{
   Dem_EventStatusExtendedType u8EventStatus = KU8_ZERO;
   register Dem_EventStatusExtendedType u8MergedEventStatus = KU8_ZERO;
   register uint8 u8Idx;

   for (u8Idx = KU8_ZERO; u8Idx < KU8_FSM_SPORADIC_HW_ERROR_DEM_EVENT_NB; u8Idx++)
   {
      (void)Rte_Call_pclDemServices_GetEventStatus(fsm_kau8SporadicHwErrorDemEventCfg[u8Idx], &u8EventStatus);
      u8MergedEventStatus |= u8EventStatus;
   }

   /* If block restore is finished */
   if (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8MergedEventStatus))
   {
      /* Mode is set */
      KU64_FSM_SET_MODE_MASK_ON(KU64_ECU_SPORADIC_ERROR);
   }
   else
   {
      /* Mode is cleared */
      KU64_FSM_SET_MODE_MASK_OFF(KU64_ECU_SPORADIC_ERROR);
   }
}

/**
* \brief
*        The function is used to determine if a permanent hardware
*        error is present.
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        FSM_runUpdateModeStatus
* \dynamicaspectdescription
*        The function is used to update mode statuses.
* \ddesignrequirement
*        DSG_fsm_UpdateModeStatus_PermanentHwError
* \archrequirement
*        ARCH_SW_FSM_ptrpAsrOsServices_FSM_runUpdateModeStatus
*        ARCH_SW_FSM_pclDemServices
*        ARCH_SW_FSM_pseModeManagement_EcuPermanentHwError
*/
LOCAL_INLINE void fsm_UpdateModeStatus_PermanentHwError(void)
{
   Dem_EventStatusExtendedType u8EventStatus = KU8_ZERO;
   register Dem_EventStatusExtendedType u8MergedEventStatus = KU8_ZERO;
   register uint8 u8Idx;

   for (u8Idx = KU8_ZERO; u8Idx < KU8_FSM_PERMANENT_HW_ERROR_DEM_EVENT_NB; u8Idx++)
   {
      (void)Rte_Call_pclDemServices_GetEventStatus(fsm_kau8PermanentHwErrorDemEventCfg[u8Idx], &u8EventStatus);
      u8MergedEventStatus |= u8EventStatus;
   }

   /* If block restore is finished */
   if (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8MergedEventStatus))
   {
      /* Mode is set */
      KU64_FSM_SET_MODE_MASK_ON(KU64_ECU_PERMANENT_HW_ERROR);
   }
}

/**
* \brief
*        The function is used to determine if a Crash is reported
*        via CAN message.
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        FSM_runUpdateModeStatus
* \dynamicaspectdescription
*        The function is used to update mode statuses.
* \ddesignrequirement
*        DSG_fsm_UpdateModeStatus_CanInhibit
* \archrequirement
*        ARCH_SW_FSM_ptrpAsrOsServices_FSM_runUpdateModeStatus
*        ARCH_SW_FSM_prrCrashStatus
*        ARCH_SW_FSM_pseModeManagement_CanInhibStatus
*/
LOCAL_INLINE void fsm_UpdateModeStatus_CanInhibit(void)
{
   uint8 u8CrashStatusOnCan;

   (void)Rte_Read_prrCrashStatus_u8IsCrashActive(&u8CrashStatusOnCan);

   /* Kept as a switch for future function functionality reasons */
   switch(u8CrashStatusOnCan)
   {
      case CM_AB_Crash_Int_Cx0_kein_Crash:
         /* No crash, clear mask */
         KU64_FSM_SET_MODE_MASK_OFF(KU64_ECU_CAN_INHIB_STATUS);
      break;

      case CM_AB_Crash_Int_Cx1_Crash_Intensitaet_1:
      case CM_AB_Crash_Int_Cx2_Crash_Intensitaet_2_nur_Stellgliedtest_MLB_B8:
      case CM_AB_Crash_Int_Cx3_Crash_Intensitaet_2_nur_D4_C7_Colorado_NF_PAG_Crash_im_MLB_B8:
      case CM_AB_Crash_Int_Cx4_Crash_Intensitaet_3_alt_VW_AUDI_Stellgliedtest_MLB_B8:
      case CM_AB_Crash_Int_Cx5_Crash_Intensitaet_3_alt_PAG:
      case CM_AB_Crash_Int_Cx7_Crash_Intensitaet_3:
      default: /* Error on CAN message read, safer to treat it as a crash */
         KU64_FSM_SET_MODE_MASK_ON(KU64_ECU_CAN_INHIB_STATUS);
      break;
   }
}

/**
* \brief
*        The function is used to determine if a buckle is latched.
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        FSM_runUpdateModeStatus
* \dynamicaspectdescription
*        The function is used to update mode statuses.
* \ddesignrequirement
*        DSG_fsm_UpdateModeStatus_BuckleStatus
* \archrequirement
*        ARCH_SW_FSM_ptrpAsrOsServices_FSM_runUpdateModeStatus
*        ARCH_SW_Fsm_prrCILData_FSM_runUpdateModeStatus
*        ARCH_SW_FSM_pseModeManagement_BuckleStatus
*/
LOCAL_INLINE void fsm_UpdateModeStatus_BuckleStatus(void)
{
   uint8 au8MergedBuckleStatus[KU8_MAX_SOLENOID_NB];

   (void)Rte_Read_FSM_prrCILData_au8MergedBuckleStatus(au8MergedBuckleStatus);

   if(KU8_BUCKLE_LATCHED == au8MergedBuckleStatus[KU8_SOLENOID_1])
   {
      KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_1_BUCKLE_LATCHED);
   }
   else
   {
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_1_BUCKLE_LATCHED);
   }

   if(KU8_BUCKLE_LATCHED == au8MergedBuckleStatus[KU8_SOLENOID_2])
   {
      KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_2_BUCKLE_LATCHED);
   }
   else
   {
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_2_BUCKLE_LATCHED);
   }

   if(KU8_BUCKLE_LATCHED == au8MergedBuckleStatus[KU8_SOLENOID_3])
   {
      KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_3_BUCKLE_LATCHED);
   }
   else
   {
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_3_BUCKLE_LATCHED);
   }

   if(KU8_BUCKLE_LATCHED == au8MergedBuckleStatus[KU8_SOLENOID_4])
   {
      KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_4_BUCKLE_LATCHED);
   }
   else
   {
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_4_BUCKLE_LATCHED);
   }

   if(KU8_BUCKLE_LATCHED == au8MergedBuckleStatus[KU8_SOLENOID_5])
   {
      KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_5_BUCKLE_LATCHED);
   }
   else
   {
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_5_BUCKLE_LATCHED);
   }

   if(KU8_BUCKLE_LATCHED == au8MergedBuckleStatus[KU8_SOLENOID_6])
   {
      KU64_FSM_SET_MODE_MASK_ON(KU64_SOLENOID_6_BUCKLE_LATCHED);
   }
   else
   {
      KU64_FSM_SET_MODE_MASK_OFF(KU64_SOLENOID_6_BUCKLE_LATCHED);
   }
}

/**
* \brief
*        The function is used to initialize mode statuses.
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        FSM_runUpdateModeStatus
* \dynamicaspectdescription
*        The function is used to update mode statuses.
* \ddesignrequirement
*        DSG_fsm_UpdateModeStatus_Init
* \archrequirement
*        ARCH_SW_FSM_ptrpAsrOsServices_FSM_runUpdateModeStatus
*        ARCH_SW_FSM_pclAutotestServices
*        ARCH_SW_FSM_prrACCServices
*/
LOCAL_INLINE void fsm_UpdateModeStatus_Init(void)
{
   uint8 u8SolenoidEnableVariant;
   uint8 u8SolenoidIdx;
   uint8 u8CriticalAutoTestsFinishedFlag = KU8_FALSE;
   uint8 u8AccInitStatus = KU8_ZERO;
   uint8 u8SolenoidUsedBitMask = KU8_ZERO;

   (void)Rte_Call_pclAutotestServices_GetCriticalAutoTestsReachedFlag(&u8CriticalAutoTestsFinishedFlag);

   for(u8SolenoidIdx = KU8_ZERO; u8SolenoidIdx < KU8_MAX_SOLENOID_NB; u8SolenoidIdx++)
   {
      FSM_runCheckModeStatus(fsm_kau64SolenoidConfiguredBitMask[u8SolenoidIdx], &u8SolenoidEnableVariant);

      if(KU8_TRUE == u8SolenoidEnableVariant)
      {
         u8SolenoidUsedBitMask |=  (uint8)(KU8_ONE << u8SolenoidIdx);
      }
   }

   if(KU8_TRUE == u8CriticalAutoTestsFinishedFlag)
   {
      /* Mode is cleared: Critical auto-tests were finished */
      KU64_FSM_SET_MODE_MASK_OFF(KU64_CRITICAL_AUTOTESTS_IN_PROGRESS);

      (void)Rte_Read_prrACCServices_u8AccInitStateMachine(&u8AccInitStatus);

      /* If initialization phase is finished:
          * • Auto-test startup list finished to be performed;
          * • Accelerometer was initialized
          * • Solenoid auto-tests were finished
          */
      if((u8AccInitStatus > KU8_FSM_INIT_WAIT_READY) &&
            (u8SolenoidUsedBitMask == FSM_u8SolenoidInitState))
      {
         /* Mode is cleared: initialization was finished */
         KU64_FSM_SET_MODE_MASK_OFF(KU64_INIT_PHASE_IN_PROGRESS);
      }
      else
      {
         /* Mode is set: initialization not finished */
         KU64_FSM_SET_MODE_MASK_ON(KU64_INIT_PHASE_IN_PROGRESS);
      }
   }
   else
   {
      /* Mode is set: Critical auto-tests are running */
      KU64_FSM_SET_MODE_MASK_ON(KU64_CRITICAL_AUTOTESTS_IN_PROGRESS);

      /* Mode is set: initialization not finished */
      KU64_FSM_SET_MODE_MASK_ON(KU64_INIT_PHASE_IN_PROGRESS);
   }
}

/**
* \brief
*        The function is used to inhibit BOOST/ON_OFF_PWR until KL30>9V.
* \dynamicaspectcaller
*        FSM_runUpdateModeStatus
* \dynamicaspectdescription
*        The function is used to update mode statuses.
* \ddesignrequirement
*        DSG_fsm_UpdateModeStatus_EcuBatteryUnstableInhibition
* \archrequirement
*        ARCH_SW_FSM_pclConvAdcService
*/
LOCAL_INLINE void fsm_UpdateModeStatus_EcuBatteryUnstableInhibition(void)
{
   u16AdcValueLsbType u16VBatt = KU16_ZERO;
   Dem_EventStatusExtendedType u8EventStatus = KU8_ZERO;

   /* check if the undervoltage Dem event is set */
   (void)Rte_Call_pclDemServices_GetEventStatus(DemConf_DemEventParameter_EVENT_POWER_SUPPLY_UV, &u8EventStatus);

   if(KU8_ZERO == ((u8EventStatus) & (DEM_UDS_STATUS_TNCTOC)))
   {
      /* test passed or failed */
      if (DEM_UDS_STATUS_TF == (u8EventStatus & DEM_UDS_STATUS_TF))
      {
         KU64_FSM_SET_MODE_MASK_ON(KU64_ECU_BATTERY_UNSTABLE);
      }
      else
      {
         KU64_FSM_SET_MODE_MASK_OFF(KU64_ECU_BATTERY_UNSTABLE);
      }
   }
   else
   {
      /* check if KL30 is under threshold */
      Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_V_BATT, &u16VBatt);

      if((NVP_u16BatteryUnstableDisqualificationThrs <= u16VBatt) && (NVP_u8BatteryUnstableDisqualificationCnt > fsm_u8BatteryUnstableCnt))
      {
         fsm_u8BatteryUnstableCnt++;

         if(NVP_u8BatteryUnstableDisqualificationCnt == fsm_u8BatteryUnstableCnt)
         {
            KU64_FSM_SET_MODE_MASK_OFF(KU64_ECU_BATTERY_UNSTABLE);
         }
      }
   }
}
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/**
* \brief
*        The function is used to initialize contexts for modes.
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        BswM_OnStartComEffective
* \dynamicaspectdescription
*        This service is a callout used to start RTE and to initialize
*        all functions that need RTE features.
* \ddesignrequirement
*        DSG_FSM_ModesInit
* \archrequirement
*        ARCH_SW_Fsm_ptrpFsmServicesBswMIf_FSM_ModesInit
*/
EXPORTED void FSM_ModesInit(void)
{
   fsm_u8InitializationFinished = KU8_ZERO;

   fsm_u8ModesHasBeenInitialized = KU8_TRUE;

   /* The contexts are first set to NOK to ensure context and
      complement will be equal to each other at the end of this
      function*/
   fsm_u64ModesStatus = KU64_FSM_MASK_INITIAL_VALUE;

   /* The complement has to be initialized so that fsm_u32_ModesStatus
         Bitwise XOR fsm_u64ModesStatusComplement is equal to 0x0000000000000000 */
   fsm_u64ModesStatusComplement = U64_COMPLEMENT(fsm_u64ModesStatus);

   /* Check and set all enabled solenoids */
   fsm_UpdateModeStatus_SolenoidEnabledConditions();
}

/**
* \brief
*        The function is used to update mode statuses.
* \exception
*        This function has no exceptions.
* \pre
*        fsm_b8modesHAsBeenInitialized variable has to be TRUE.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        OsTask_Alv_eCS_App
* \dynamicaspectdescription
*        OsTask_Alv_eCS_App
* \constrains
*        Called every 1 ms.
* \ddesignrequirement
*        DSG_FSM_runUpdateModeStatus
* \archrequirement
*        ARCH_SW_FSM_ptrpAsrOsServices_FSM_runUpdateModeStatus
*        ARCH_SW_FSM_pseModeManagement_NvmBlockRestore
*        ARCH_SW_FSM_pseModeManagement_SolenoidDisabled
*        ARCH_SW_FSM_pseModeManagement_CanInhibStatus
*        ARCH_SW_FSM_pseModeManagement_SolenoidUnlockConfirmation
*        ARCH_SW_FSM_pseModeManagement_EcuPermanentHwError
*        ARCH_SW_FSM_pseModeManagement_EcuSporadicError
*        ARCH_SW_FSM_pseModeManagement_BuckleStatus
*/
EXPORTED void FSM_runUpdateModeStatus(void)
{
   uint8 u8Index = KU8_ZERO;

   /* Check MMG component is initialized */
   if (KU8_TRUE == fsm_u8ModesHasBeenInitialized)
   {
      if(KU8_FSM_MASK_NVM_BLOCK_RESTORED != (fsm_u8InitializationFinished & KU8_FSM_MASK_NVM_BLOCK_RESTORED))
      {
         fsm_UpdateModeStatus_NvmBlockRestore();
      }

      for(u8Index = KU8_ZERO; u8Index < KU8_FSM_SCHADULE_NB_OF_FCNS; u8Index++)
      {
         if((uint16)(fsm_kastScheduler[u8Index].ku8Offset) == (fsm_u16CurrentDecade % fsm_kastScheduler[u8Index].ku16Period))
         {
            fsm_kastScheduler[u8Index].pfFunctionCallback();
         }
      }

      /* Consider next decade number */
      fsm_u16CurrentDecade = (fsm_u16CurrentDecade + KU16_ONE) % KU8_TEN;
   }
}

/**
* \brief
*       The function is used to check mode statuses.
* \inputparam
*       Name: u64ModesToCheck;
*       Type: uint64;
*       Description: Mask value which corresponds to flag which will be checked;
*       Range: 0..KU64_MAX;
* \outputparam
*       Name: pu8ModeStatus;
*       Type: uint8 *;
*       Description: return the result based on flag status checked with variable
*       u32ModesToCheck;
*       Range: 
*           KU8_ZERO
*           FSM_KU8_MODE_STATUS_OFF
*           FSM_KU8_MODE_STATUS_ON;
* \exception
*        This function has no exceptions.
* \pre
*        fsm_b8ModesHasBeenInitialized variable has to be TRUE.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        FSM_manageSolenoidCounters;
*        fsm_CheckStartupSelfTest;
*        fsm_RunSolenoidStateManagement;
*        cil_ManagePeriodicData_TimeSlot02;
*        cil_ManagePeriodicData_TimeSlot03;
*        cil_ManagePeriodicData_TimeSlot04;
*        atm_executeAutoTest;
*        CIL_runAppliToCAN;
*        eCS_runMainFunctionIf;
*        SAD_checkActuatorState;
*        SAD_CheckSolenoidOpenCircuitAutotest;
*        SAD_CheckSolenoidShortToGNDAutotest;
*        SAD_CheckSolenoidShortToVBATAutotest;
*        sad_ControlStepExecution;
*        SAD_Init;
*        SAD_runMainFunction;
* \dynamicaspectdescription
*        API called from multiple modules in order to check different flags statuses.
* \constrains
*        None.
* \ddesignrequirement
*        DSG_FSM_runCheckModeStatus
* \archrequirement
*        ARCH_SW_FSM_pseModeManagement_CriticalAutotests
*/
EXPORTED void FSM_runCheckModeStatus(uint64 u64ModesToCheck, uint8 *pu8ModeStatus)
{
   /* Check if the modes are initialized */
   if (KU8_TRUE == fsm_u8ModesHasBeenInitialized)
   {
      /* Check there is no RAM corruption using bitwise XOR */
      if (KU64_MAX != (fsm_u64ModesStatus ^ fsm_u64ModesStatusComplement))
      {
         /* The RAM is corrupted */
         /* A RAM default error could be notified to DEM here */
         /* Wait for next call to MMG_Mainfunction to have a coherence between RC and its XOR value */
         /* In the meantime, do a reset */
         fsm_u64ModesStatus = KU64_FSM_MASK_INITIAL_VALUE;
         fsm_u64ModesStatusComplement = U64_COMPLEMENT(fsm_u64ModesStatus);

         /* Returned status is null */
         (*pu8ModeStatus) = KU8_ZERO;
      }
      else
      {
         /* Check a system context is asked */
         /* Check at least one mode is ON (a mode is ON when the situation is detected) */
         if ((KU64_FSM_MASK_NO_MODE != u64ModesToCheck) &&
             (KU64_ZERO != (fsm_u64ModesStatus & u64ModesToCheck)))
         {
            /* then return KU8_TRUE */
            (*pu8ModeStatus) = KU8_FSM_MODE_STATUS_ON;
         }
         else
         {
            /* else return KU8_FALSE */
            (*pu8ModeStatus) = KU8_FSM_MODE_STATUS_OFF;
         }
      }
   }
   else
   {
      /* Modes are not yet initialized */
      /* Returned status is null */
      (*pu8ModeStatus) = KU8_ZERO;
   }
}

#define FSM_STOP_SEC_CODE_ASIL_A
#include "FSM_MemMap.h"
