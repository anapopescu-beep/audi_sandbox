
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
$Revision: 1.58.1.50 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/BswMIf/Implementation/src/project.pj $
*/  
/*****************************************************************************

details
   Application level module of Basic Software Mode Manager (BswM) component.
   The BSW Mode Manager is the module that implements the part of the Vehicle Mode
   Management and Application Mode Management concept that resides in the BSW. 
   This module is used to define what actions are needed to be executed when a
   specific BswM rule is or isn't fullfiled.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "BswM_Callouts.h"
#include "Rte_BswMIf.h"
#include "BswM.h"
#include "EcuM.h"
#include "CanIf_TDK_4G_PBcfg.h"
#include "CanTp_TDK_4G_PBcfg.h"
#include "ComM_TDK_4G_PBcfg.h"
#include "CanTp.h"
#include "CanSM.h"
#include "PduR.h"
#include "ComM_EcuMBswM.h"
#include "ATM_public.h"
#include "MIC_Public.h"
#include "RCM.h"
#include "Fls.h"
#include "Adcif.h"
#include "SAD.h"
#include "Gpt.h"
#include "NvM.h"
#include "Fee.h"
#include "Dcm.h"
#include "LPM.h" 
#include "FSM.h"
#include "ACC.h"
#include "CIL.h"
#include "DIA.h"
#include "RteIf.h"
#include "McuIf.h"
#include "CanIf_Int.h"
#include "Nvp_Generated_NvmDefault.h"
#include "NvM_DataIntern.h"
#include "NvM_Queue.h"
#ifndef GLIWA_DISABLE
#include "T1_AppInterface.h"
#endif
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *    Macro used to define the CAN Controller ID
 */
#define KU8_BSWM_MQB_CAN_CONTROLLER ((uint8) 0x00)
/**
 * \brief
 *    Macro used to define Autoliv NvM Major revision ID
 */
#define KU8_BSWM_MAJOR_REVISION_IDX ((uint8) 0x01)
/**
 * \brief
 *    Macro used to define Autoliv NvM Minor revision ID
 */
#define KU8_BSWM_MINOR_REVISION_IDX ((uint8) 0x02)
/**
 * \brief
 *    Macro used to define Autoliv NvM Sub revision ID
 */
#define KU8_BSWM_SUB_REVISION_IDX   ((uint8) 0x03)
/**
 * \brief
 *    Flag associated with a valid detection of passenger occupancy
 */
#define KU8_BSWM_PASSENGER_OCCUPANCY_DETECTED_APP      ((uint8) 0x01)
/**
 * \brief
 *    Flag associated with a missing detection of passenger occupancy (external wakeup)
 */
#define KU8_BSWM_PASSENGER_OCCUPANCY_NOT_DETECTED_APP  ((uint8) 0x00)
/**
 * \brief
 *    This macro is used to set the end of conversion OS alarm period 
 *    associated with LPIT channel 2 timer.
 *    Based on Os ticks: 1 tick = 25ns and 10ms = 400000 ticks.
 */
#define KU32_BSWM_LPIT_CH2_RST_VALUE               ((uint32) 50000)
/**
 * \brief
 *    Flag associated with no of ticks of the schedulers
 *    Based on Os ticks: 1 tick = 25ns and 10ms = 400000 ticks.
 */
#define KU32_BSWM_SCHEDULER_NO_OF_TICKS            ((uint32) 50000)
/**
 * \brief
 *    Maximum time for POST RUN state to monitor:
 *    NVP_u32TPostRun - return maximum time to stay in POST RUN State in cycles
 *       o  10 ms       = 1 cycle (GPT Interrupt);
 *       o  1  seconds  = 1000 ms   =  100 cycles (GPT Interrupts);
 *       o  10 seconds  = 10000 ms  =  1000 cycles (GPT Interrupts);
 *       o  100 seconds = 100000 ms =  10000 cycles (GPT Interrupts);
 */
#define KU32_BSWM_TIMER_POST_RUN                   NVP_u32TPostRun
/**
 * \brief
 *    Maximum time for passenger occupancy monitoring:
 *    NVP_u32TPassengerWakeup - return maximum time to wait for Passenger Occupancy 
 *                               detection in cycles
 *       o  10 ms       = 1 cycle (GPT Interrupt);
 *       o  1  seconds  = 1000 ms   =  100 cycles (GPT Interrupts);
 *       o  10 seconds  = 10000 ms  =  1000 cycles (GPT Interrupts);
 *       o  100 seconds = 100000 ms =  10000 cycles (GPT Interrupts);
 */
#define KU32_BSWM_TIMER_PASSENGER_WAKEUP           NVP_u32TPassengerWakeup
/** 
 * \brief
 *    Maximum time to put ECU in RUN state when comes from LOW POWER state
 *    (passenger occupancy detected) but CAN Activity is not detected on bus
 *    and is represented by the difference between TPostRun and TPassengerWakeup timers.
 *    When this "timer" is active, current ECU state is AUTONOMOUS STATE.
 */
#define KU32_BSWM_TIMER_RUN_FROM_LOW_PWR           abs(KU32_BSWM_TIMER_PASSENGER_WAKEUP - KU32_BSWM_TIMER_POST_RUN)
/**
 * \brief
 *    Flag associated with NvM read action not performed
 */
#define KU8_BSWM_NVM_READ_ALL_NOT_PERFORMED        ((uint8) 0xD0)
/**
 * \brief
 *    Flag associated with NvM read action performed
 */
#define KU8_BSWM_NVM_READ_ALL_PERFORMED            ((uint8) 0xD1)
/**
 * \brief
 *    Flag associated with NvM read action to be performed
 */
#define KU8_BSWM_NVM_RESTORE_TO_BE_PERFORMED       ((uint8) 0xD2)
/**
 * \brief
 *    Flag associated with NvM restore action performed
 */
#define KU8_BSWM_NVM_RESTORE_PERFORMED             ((uint8) 0xD3)
/**
 * \brief
 *    Flag associated with DCM reset type: No reset
 */
#define KU8_BSWM_NO_RESET                          ((uint8) 0x00)
/**
 * \brief
 *    Flag associated with DCM reset type: Software reset
 */
#define KU8_BSWM_SW_RESET                          ((uint8) 0x01)
/**
 * \brief
 *    Flag associated with DCM reset type: Hardware reset
 */
#define KU8_BSWM_HW_RESET                          ((uint8) 0x02)
/**
 * \brief
 *    Flag associated with DCM reset type: Bootloader reset
 */
#define KU8_BSWM_FBL_RESET                         ((uint8) 0x03)
/**
 * \brief
 *    Flag associated with TX PDU status
 */
#define KU8_BSWM_TX_PDU_ENABLED                    ((uint8) 0x00)
/**
 * \brief
 *    Flag associated with TX PDU status
 */
#define KU8_BSWM_TX_PDU_DISABLED                   ((uint8) 0x01)
/**
 * \brief
 *    Flag associated with PROCESS_MODE command requested
 */
#define KU8_BSWM_PROCESS_MODE_REQUESTED            ((uint8) 0xAA)
/**
 * \brief
 *    Flag associated with PROCESS_MODE command not requested
 */
#define KU8_BSWM_PROCESS_MODE_NOT_REQUESTED        ((uint8) 0x55)

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL void bswm_CheckNvmIntegrity(void);
LOCAL void bswm_CheckProcessModeStatus(void);
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define BswMIf_START_SEC_VAR_INIT_8
#include "BswMIf_MemMap.h"
/**
 * \brief
 *    This variable is used to make a delay after initialization phase to
 *    be able to send the logger frame at startup
 * \initialization
 *    0x00
 * \range
 *    0x00-0x06;
 */
LOCAL uint8 bswmif_u8LoggerFrameTimeout = KU8_ZERO;
/**
 * \brief
 *    This variable is used to store the current state of the TX PDU.
 * \initialization 
 *    BSWM_KU8_TX_PDU_DISABLED	 - 0x00
 * \range
 *    BSWM_KU8_TX_PDU_DISABLED   - 0x00;
 *    BSWM_KU8_TX_PDU_ENABLED    - 0x01;
 */
LOCAL uint8 bswmif_u8CurrentTxPduState = KU8_ZERO;
/**
 * \brief
 *    This variable is used to store the current ECU State.
 * \initialization 
 *    BSWM_INIT_STATE_ACTIVE        - 40
 * \range
 *    BSWM_INIT_STATE_ACTIVE        - 40;
 *    BSWM_STARTUP_TWO_A            - 0;
 *    BSWM_STARTUP_TWO_B            - 1;
 *    BSWM_RUN_MODE_ACTIVE          - 8;
 *    BSWM_POST_RUN_MODE_ACTIVE     - 9;
 *    BSWM_RUN_MODE_NO_COM_ACTIVE   - 22;
 *    BSWM_LOW_PWR_MODE_ACTIVE      - 10;
 *    BSWM_SHUTDOWN_MODE_ACTIVE     - 11;
 *    BSWM_PROCESS_MODE_ACTIVE      - 26;
 *    BSWM_RUN_MODE_FROM_LOW_PWR    - 23;
 */
LOCAL uint8 bswmif_u8CurrentEcuState = KU8_BSWM_INIT_STATE_ACTIVE;
/**
 * \brief
 *    This variable is used to store the action which is needed to be 
 *    executed during the NVM Restore procedure.
 * \initialization 
 *    BSWM_KU8_NVM_READ_ALL_NOT_PERFORMED   - 0xD0
 * \range
 *    BSWM_KU8_NVM_READ_ALL_NOT_PERFORMED   - 0xD0;
 *    BSWM_KU8_NVM_READ_ALL_PERFORMED       - 0xD1;
 *    BSWM_KU8_NVM_RESTORE_TO_BE_PERFORMED  - 0xD2;
 *    BSWM_KU8_NVM_RESTORE_PERFORMED        - 0xD3;
 */
LOCAL uint8 bswmif_u8RestoreNvmBlockSM = KU8_BSWM_NVM_READ_ALL_NOT_PERFORMED;
/**
 * \brief
 *    This variable is used to store the current NvM Block Id which is
 *    needed during the NVM Restore procedure. He is initialized with 3
 *    to ignore first three blocks: 
 *       o NVM internal block;
 *       o NVM_BLOCK_DEM_DEFAULT;
 *       o NvM_NvMBlock_ConfigID;
 * \initialization 
 *    NvM_ECC_COUNTERS - 0x03 
 * \range
 *    0x03 - 0x1B but it depends on the number of blocks defined in NVP
 */
LOCAL uint8 bswmif_u8CurrentNvmBlockId = NvMConf_NvMBlockDescriptor_ECC_COUNTERS;
/**
 * \brief
 *    This variable is used to store the type of reset requested through
 *    diagnosis.
 * \initialization 
 *    BSWM_KU8_NO_RESET - 0x00 
 * \range
 *    BSWM_KU8_NO_RESET - 0x00;
 *    BSWM_KU8_SW_RESET - 0x01;
 *    BSWM_KU8_HW_RESET - 0x02;
 *    BSWM_KU8_FBL_RESET- 0x03;
 */
LOCAL uint8 bswmif_u8RequestedReset = KU8_BSWM_NO_RESET;
/**
 * \brief
 *    This variable is used to store the status of the read/write
 *    NVM process.
 * \initialization 
 *    KU8_FALSE - 0x55 
 * \range
 *    KU8_FALSE - 0x55;
 *    KU8_TRUE  - 0xAA;
 */
LOCAL uint8 bswmif_u8IsReadWriteAllProcessFinished = KU8_FALSE;
/**
 * \brief
 *    This variable is used to store the status of the read/write
 *    NVM notification
 * \initialization 
 *    KU8_FALSE - 0x55 
 * \range
 *    KU8_FALSE - 0x55;
 *    KU8_TRUE  - 0xAA;
 */
LOCAL uint8 bswmif_u8IsReadWriteAllEndNotificationSet = KU8_FALSE;
/**
 * \brief
 *    This variable is used to store the status of the passenger occupancy
 *    value provided by IoHwAb module
 *       
 * \initialization 
 *    KU8_BSWM_PASSENGER_OCCUPANCY_NOT_DETECTED_APP - 0x00 
 * \range
 *    KU8_BSWM_PASSENGER_OCCUPANCY_NOT_DETECTED_APP - 0x00
 *    BSWM_PASSANGER_OCCUPANCY_DETECTED     - 0x01
 */
LOCAL uint8 bswmif_u8PassengerOccupancyStatus = KU8_BSWM_PASSENGER_OCCUPANCY_NOT_DETECTED_APP;
/**
 * \brief
 *    This variable is used to save the current state of the LOW POWER -> RUN 
 *    transition state when CAN activity is detected on bus. This state is 
 *    necessary to avoid to execute the POST RUN sequence when BswM Rule is 
 *    validated before RX ACK validation.
 * \initialization 
 *    KU8_FALSE - 0x55 
 * \range
 *    KU8_FALSE - 0x55;
 *    KU8_TRUE  - 0xAA;
 */
LOCAL uint8 bswmif_u8RunToLowPowerTransitionValidated = KU8_FALSE;
/**
 * \brief
 *    This variable is used to save the current state Process Mode request
 * \initialization 
 *    KU8_FALSE - 0x55 
 * \range
 *    KU8_FALSE - 0x55;
 *    KU8_TRUE  - 0xAA;
 */
LOCAL uint8 bswmif_u8ProcessModeStarted = KU8_FALSE;
/**
 * \brief
 *    This variable is used to save the current state writeAll request
 *    when ECU is in AUTONOMOUS RUN State
 * \initialization 
 *    KU8_FALSE - 0x55 
 * \range
 *    KU8_FALSE - 0x55;
 *    KU8_TRUE  - 0xAA;
 */
LOCAL uint8 bswmif_u8WriteAllFromAutonomousRequested = KU8_FALSE;
/**
 * \brief
 *    This variable is used to avoid to execute Communication Services
 *    at initialization
 * \initialization
 *    KU8_FALSE - 0x55
 * \range
 *    KU8_FALSE - 0x55;
 *    KU8_TRUE  - 0xAA;
 */
LOCAL uint8 bswmif_u8AvoidToRunComAtInit = KU8_FALSE;

#define BswMIf_STOP_SEC_VAR_INIT_8
#include "BswMIf_MemMap.h"

#define BswMIf_START_SEC_VAR_INIT_16
#include "BswMIf_MemMap.h"
/**
 * \brief
 *    This variable is used to count how many times the GPT interrupt has been 
 *    performed to be able to execute specific actions depending of how many time
 *    was elapsed. According with the architecture this variable is represented by 
 *    the TPostRun timer.
 * \initialization 
 *    KU16_ZERO - 0x00 
 * \range
 *       0...6125 (1 unit = 10ms)
 */
LOCAL uint16 bswmif_u16TPostRunTimer = KU16_ZERO;
/**
 * \brief
 *    This variable is used to count how many times the GPT interrupt has been 
 *    performed to be able to execute specific actions depending of how many time
 *    was elapsed. According with the architecture this variable is represented by 
 *    the TPassengerWakeup timer.
 * \initialization 
 *       KU16_ZERO - 0x00 
 * \range
 *       0...6000 (1 unit = 10ms)
 */
LOCAL uint16 bswmif_u16TPassengerWakeupTimer = KU16_ZERO;
/**
 * \brief
 *    This variable is used to count how many times the GPT interrupt has been 
 *    performed to be able to execute specific actions depending of how many time
 *    was elapsed. According with the architecture this variable is represented by 
 *    the difference between TPassengerWakeup and TPostRun timers.
 * \initialization 
 *       KU16_ZERO - 0x00 
 * \range
 *       0...125
 */
LOCAL uint16 bswmif_u16TRunFromLowPowerTimer = KU16_ZERO;

#define BswMIf_STOP_SEC_VAR_INIT_16
#include "BswMIf_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
#define BswMIf_START_SEC_CONST_8
#include "BswMIf_MemMap.h"
/**
 * \brief
 *    This variable is used to define the NVM blocks that are skipped 
 *    during NVM restore procedure.
 *       
 * \initialization 
 *     ECC_COUNTERS,
 *     WARM_RESET_COUNTERS,
 *     HW_PART_NUMBER,
 *     AEE_TRACEABILITY_NUMBER,
 *     ECU_ASSEMBLY_SERIAL_NUMBER,
 *     ECS_ACC_OFFSETS,
 *     ECU_TEMP_CALIBRATION,
 *     ACC_AXIS_ANGLE_CALIBRATION,
 *     EOL_COUNTERS
 * \range
 *    There is no range because this variable is an array and his values
 *    are not modify during runtime
 */
LOCAL const uint8 bswmif_kau8NvmBlockToSkip[KU8_NINE] = {
		NvMConf_NvMBlockDescriptor_ECC_COUNTERS,
		NvMConf_NvMBlockDescriptor_WARM_RESET_COUNTERS,
		NvMConf_NvMBlockDescriptor_HW_PART_NUMBER,
		NvMConf_NvMBlockDescriptor_AEE_TRACEABILITY_NUMBER,
		NvMConf_NvMBlockDescriptor_ECU_ASSEMBLY_SERIAL_NUMBER,
		NvMConf_NvMBlockDescriptor_ECS_ACC_OFFSETS,
		NvMConf_NvMBlockDescriptor_ECU_TEMP_CALIBRATION,
		NvMConf_NvMBlockDescriptor_ACC_AXIS_ANGLE_CALIBRATION,
		NvMConf_NvMBlockDescriptor_EOL_COUNTERS
//    SPARE_PART_NUMBER,
//    HARDWARE_NUMBER,
//    SYSTEM_NAME_OR_ENGINE_TYPE,
//    BLOCK_FBL,
//    ODX_FILE_IDENTIFIER,
//    ODX_FILE_VERSION,
//    ECU_SERIAL_NUMBER,
//    LOGICAL_SW_BLOCK_VERSION,
//    HARDWARE_VERSION_NUMBER,
//    APP_SOFTWARE_VERSION_NUMBER

};

#define BswMIf_STOP_SEC_CONST_8
#include "BswMIf_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
#define BswMIf_START_SEC_CODE
#include "BswMIf_MemMap.h"
/**
* \brief
*     Function used to handle Process Mode ECU State.
* \dynamicaspectcaller
*     BswMIf_runMainFunction
* \dynamicaspectdescription
*     Called cyclic at every 10ms by BswMIf_runMainFunction method.
* \constrains
*     Current ECU state must be RUN_STATE
* \ddesignrequirement
*     DSG_bswm_CheckProcessModeStatus   
* \archrequirement
*     ARCH_SW_BswMIf_BswMIf_runMainFunction;
*     ARCH_SW_BswMIf_ptrpAsrOsServicesBswMIf_BswMIf_runMainFunction;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswMIf_runMainFunction;
**/
LOCAL void bswm_CheckProcessModeStatus(void)
{
   /* Start process mode if routine was called and last ECU state was RUN_STATE */
   if((BSWM_RUN_MODE_ACTIVE == bswmif_u8CurrentEcuState) && 
      (KU8_BSWM_PROCESS_MODE_REQUESTED == NVP_u8ProcessMode) && 
      (KU8_TRUE != bswmif_u8ProcessModeStarted))
   {
      /* Set BswM port to process mode to be able to trigger BswM Rule */
      BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_PROCESS_MODE_ACTIVE);

      /* Update Ecu current state */
      bswmif_u8CurrentEcuState = BSWM_PROCESS_MODE_ACTIVE;

      /* Set flag to avoid to enter cyclic in this condition */
      bswmif_u8ProcessModeStarted = KU8_TRUE;
   }
   /* Stop process mode if stop routine was called and last ECU state was PROCESS_MODE */
   else if ((KU8_BSWM_PROCESS_MODE_NOT_REQUESTED == NVP_u8ProcessMode) && (KU8_TRUE == bswmif_u8ProcessModeStarted))
   {
      /* Set BswM port to process mode to be able to trigger BswM Rule */
      BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_RUN_MODE_ACTIVE);

      /* Update Ecu current state */
      bswmif_u8CurrentEcuState = BSWM_RUN_MODE_ACTIVE;

      /* Reset flag to avoid to enter cyclic in this condition */
      bswmif_u8ProcessModeStarted = KU8_FALSE;
   }
   else
   {
      /* Do nothing */
   }
}
/**
* \brief
*     Function used to check the NvM Integrity.
* \dynamicaspectcaller
*     BswMIf_runMainFunction
* \dynamicaspectdescription
*     Called cyclic at every 10ms by BswMIf_runMainFunction method.
* \constrains
*     Current ECU state must be RUN_STATE
* \ddesignrequirement
*     DSG_bswm_CheckNvmIntegrity
* \archrequirement
*     ARCH_SW_BswMIf_BswMIf_runMainFunction;
*     ARCH_SW_BswMIf_ptrpAsrOsServicesBswMIf_BswMIf_runMainFunction;
*     ARCH_SW_BswMIf_pclNvmIfServices_GetNvmBlockStatus;
*     ARCH_SW_BswMIf_pclNvmIfServices_RestoreRAMBlockDefaults;
*     ARCH_SW_BswMIf_pclNvmIfServices_SetRamBlockStatus;
*     ARCH_SW_BswMIf_psrBswMIfServices;
**/
LOCAL void bswm_CheckNvmIntegrity(void)
{
   uint8 u8Idx = KU8_ZERO;
   uint8 u8BlockStatus = KU8_ZERO;
   boolean b8SkipBlock = KB_FALSE;

   switch(bswmif_u8RestoreNvmBlockSM)
   {
   case KU8_BSWM_NVM_READ_ALL_PERFORMED:
   {
      /* Get NvM Block Status */
      (void) Rte_Call_pclNvmIfServices_GetNvmBlockStatus(NvMConf_NvMBlockDescriptor_ALV_NVM_VERSION, &u8BlockStatus);

      if(NVM_REQ_RESTORED_FROM_ROM != u8BlockStatus)
      {
         /* Compare versions from NvM and ROM */
         if(NVP_au8AlvNvmVersion[KU8_BSWM_MAJOR_REVISION_IDX] != K_NVP_au8AlvNvmVersion[KU8_BSWM_MAJOR_REVISION_IDX])
         {
            bswmif_u8RestoreNvmBlockSM = KU8_BSWM_NVM_RESTORE_TO_BE_PERFORMED;
         }
         else if(NVP_au8AlvNvmVersion[KU8_BSWM_MINOR_REVISION_IDX] != K_NVP_au8AlvNvmVersion[KU8_BSWM_MINOR_REVISION_IDX])
         {
            bswmif_u8RestoreNvmBlockSM = KU8_BSWM_NVM_RESTORE_TO_BE_PERFORMED;
         }
         else if(NVP_au8AlvNvmVersion[KU8_BSWM_SUB_REVISION_IDX] != K_NVP_au8AlvNvmVersion[KU8_BSWM_SUB_REVISION_IDX])
         {
            bswmif_u8RestoreNvmBlockSM = KU8_BSWM_NVM_RESTORE_TO_BE_PERFORMED;
         }
         else
         {
            /* Restore is not necessary */
            bswmif_u8CurrentNvmBlockId = NvMConf_NvMBlockDescriptor_ECC_COUNTERS;
            bswmif_u8RestoreNvmBlockSM = KU8_BSWM_NVM_RESTORE_PERFORMED;
            Rte_Write_psrBswMIfServices_u8BlockRestoreStatus(KU8_TRUE);
         }
      }
      else
      {
         bswmif_u8RestoreNvmBlockSM = KU8_BSWM_NVM_RESTORE_TO_BE_PERFORMED;
      }

      break;
   }
   case KU8_BSWM_NVM_RESTORE_TO_BE_PERFORMED:
   {
      for(u8Idx = KU8_ZERO; ((u8Idx < sizeof(bswmif_kau8NvmBlockToSkip)) && (KB_TRUE != b8SkipBlock)); u8Idx++)
      {
         if(bswmif_kau8NvmBlockToSkip[u8Idx] == bswmif_u8CurrentNvmBlockId)
         {
            /* Skip block if it contains traceability data */
            b8SkipBlock = KB_TRUE;
         }
      }

      if(NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS > bswmif_u8CurrentNvmBlockId)
      {
         if(KB_FALSE == b8SkipBlock)
         {
            if(NVM_STD_QUEUE_NOT_FULL() || NVM_STD_QUEUE_EMPTY())
            {
               /* Restore from ROM and signal that block needs to be saved at shutdown */
               (void)Rte_Call_pclNvmIfServices_RestorePRAMBlockDefaults(bswmif_u8CurrentNvmBlockId);
               (void)Rte_Call_pclNvmIfServices_SetRamBlockStatus(bswmif_u8CurrentNvmBlockId, TRUE);
               bswmif_u8CurrentNvmBlockId++;
            }
         }
         else
         {
            bswmif_u8CurrentNvmBlockId++;
         }
      }
      else
      {
         /* Restore from ROM and signal that block needs to be saved at shutdown */
         (void)Rte_Call_pclNvmIfServices_RestorePRAMBlockDefaults(NvMConf_NvMBlockDescriptor_ALV_NVM_VERSION);
         (void)Rte_Call_pclNvmIfServices_SetRamBlockStatus(bswmif_u8CurrentNvmBlockId, TRUE);
         /* Reset state machine */
         bswmif_u8CurrentNvmBlockId = NvMConf_NvMBlockDescriptor_ECC_COUNTERS;
         bswmif_u8RestoreNvmBlockSM = KU8_BSWM_NVM_RESTORE_PERFORMED;
         Rte_Write_psrBswMIfServices_u8BlockRestoreStatus(KU8_TRUE);
      }

      break;
   }
   default:
   {
      break;
   }
   }
}
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/**
* \brief
*     Main function for BswM callouts.
* \dynamicaspectcaller
*     TASK(OsTask_Alv_Autotests)
* \dynamicaspectdescription
*     This function is called cyclic by OS at every 10 ms.
* \constrains
*     ECU must be in RUN_STATE
* \ddesignrequirement
*     DSG_BswMIf_runMainFunction
* \archrequirement
*     ARCH_SW_BswMIf_BswMIf_runMainFunction;
*     ARCH_SW_BswMIf_ptrpAsrOsServicesBswMIf_BswMIf_runMainFunction;
*     ARCH_SW_BswMIf_psrBswMIfServices;
*     ARCH_SW_BswMIf_pclNvmIfServices_GetNvmBlockStatus;
*     ARCH_SW_BswMIf_pclNvmIfServices_RestoreRAMBlockDefaults;
**/
EXPORTED void BswMIf_runMainFunction(void)
{
   /* Check NVM Integrity */
   bswm_CheckNvmIntegrity();

   /* Check Process Mode Status */
   bswm_CheckProcessModeStatus();

   if((BSWM_RUN_MODE_ACTIVE == bswmif_u8CurrentEcuState) && (KU8_FIVE == bswmif_u8LoggerFrameTimeout))
   {
	   /* Update ECU State */
	   Rte_Call_pclCILGetEcuState_updateCurrentEcuState(bswmif_u8CurrentEcuState);

	   /* Reset counter value */
	   bswmif_u8LoggerFrameTimeout = KU8_SIX;
   }
   else
   {
	   /* Condition used to avoid to increment counter to
	    * fulfill the if condition declared above */
	   if(KU8_SIX == bswmif_u8LoggerFrameTimeout)
	   {
		   bswmif_u8LoggerFrameTimeout = KU8_SIX;
	   }
	   else
	   {
		   bswmif_u8LoggerFrameTimeout++;
	   }
   }

}
/**
* \brief
*     This service is configured as a notification API from tresos-
      configured GPT timer. This service behaves like an interrupt 
      that is called by GPT timer every 10ms and is used to handle 
      the POST RUN and AUTONOMOUS RUN Ecu state.
* \dynamicaspectcaller
*     Tresos-configured GPT Timer.
* \dynamicaspectdescription
*     Called by GPT component configured in Tresos components 
*     at every 10 ms.
* \constrains
*     GPT timer must be started and to do that, a transition 
*     must be validated:
*        o RUN State -> POST RUN State (comm timeout)
*        o POST RUN State -> AUTONOMOUS RUN State (passenger detected)
*        o LOW POWER State -> AUTONOMOUS RUN State (passenger detected)
* \ddesignrequirement
*     DSG_BswM_Cyclic_10msTimer
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrGptServicesBswMIf_BswM_Cyclic_10msTimer;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_Cyclic_10msTimer;
*     ARCH_SW_BswMIf_ptrrGptServicesBswMIf_Gpt_StopTimer_BswM_Cyclic_10msTimer;
*     ARCH_SW_BswMIf_ptrrNvMServicesBswMIf_NvM_WriteAll_BswM_Cyclic_10msTimer;
*     ARCH_SW_BswMIf_pclCILGetEcuState_BswM_Cyclic_10msTimer;
**/
EXPORTED void BswM_Cyclic_10msTimer(void)
{
   /* Transition RUN -> POST RUN (communication timeout) for TPostRun seconds */
   if (BSWM_POST_RUN_MODE_ACTIVE == bswmif_u8CurrentEcuState)
   {
      /* Increment timer (10 ms passed) */
      bswmif_u16TPostRunTimer++;

      /* Verify if passenger occupancy was detected in max TPostRunTimer seconds
       * and if it is, go back to RUN state */
      if (KU32_BSWM_TIMER_POST_RUN >= bswmif_u16TPostRunTimer)
      {
         /* Verify if pasager occupancy is detected */
         if (KU8_BSWM_PASSENGER_OCCUPANCY_DETECTED_APP == bswmif_u8PassengerOccupancyStatus)
         {
            /* Set BswM port to notify that pasager occupancy was detected */
            BswM_RequestMode(KU8_BSWM_PASSANGER_OCCUPANCY_REQUEST_PORT, BSWM_PASSANGER_OCCUPANCY_DETECTED);

            /* Stop LPIT2 timer */
            Gpt_StopTimer(GptConf_GptChannelConfiguration_GPT_CYCLIC_TIMER);

            /* Reset timer counter value */
            bswmif_u16TPostRunTimer = KU16_ZERO;

            /* Reset passenger occupancy flag */
            bswmif_u8PassengerOccupancyStatus = KU8_BSWM_PASSENGER_OCCUPANCY_NOT_DETECTED_APP;
         }
      }
      /* Timeout, no Passenger occupancy OR CAN Activity detected */
      else
      {
         /* If Buckle and SBS sensors are not available, start the Shutdown procedure */
         if(KUB_eCS_SBS_SEAT_1_NOT_CONFIGURED_VARIANT && KUB_eCS_SBS_SEAT_2_NOT_CONFIGURED_VARIANT &&
            KUB_eCS_BKL_SEAT_1_NOT_CONFIGURED_VARIANT && KUB_eCS_BKL_SEAT_2_NOT_CONFIGURED_VARIANT)
         {
            /* Update BswM Ecu shutdown Port to be able to enter in SHUTDOWN state */
            BswM_RequestMode(KU8_BSWM_ECU_SHUTDOWN_REQUESTED_PORT, BSWM_ECU_SHUTDOWN_REQUESTED);

            /* Update Ecu current state */
            bswmif_u8CurrentEcuState = BSWM_SHUTDOWN_MODE_ACTIVE;
         }
         /* Buckle and SBS sensors are available, go to LOW POWER */
         else
         {
            Rte_Call_pclCILGetEcuState_updateCurrentEcuState(BSWM_LOW_PWR_MODE_ACTIVE);

            /* Update BswM EcuState Port to be able to enter in LOW POWER state */
            BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_LOW_PWR_MODE_REQUESTED);
         }
         /* Stop LPIT2 timer */
         Gpt_StopTimer(GptConf_GptChannelConfiguration_GPT_CYCLIC_TIMER);

         /* Reset timer counter value */
         bswmif_u16TPostRunTimer = KU16_ZERO;
      }
   }
   /* Autonomous RUN: Transition POST RUN -> RUN (Passenger detected) for TPassengerWakeup seconds */
   else if (BSWM_RUN_MODE_NO_COM_ACTIVE == bswmif_u8CurrentEcuState)
   {
      /* Increment timer => 10ms passed */
      bswmif_u16TPassengerWakeupTimer++;

      /* If passenger occupancy is detected on another seat or current passenger
         occupancy status is reset, reset the counter */
      if (KU8_BSWM_PASSENGER_OCCUPANCY_DETECTED_APP == bswmif_u8PassengerOccupancyStatus)
      {
         /* Reset Counter */
         bswmif_u16TPassengerWakeupTimer = KU16_ZERO;

         /* Reset external wakeup flag to be able to detect another occupancy detecton */
         bswmif_u8PassengerOccupancyStatus = KU8_BSWM_PASSENGER_OCCUPANCY_NOT_DETECTED_APP;
      }
      /* Verify if CAN Activity was detected in max TPassengerWakeupTimer seconds and if 
       * it is, go in RUN state */
      if (KU32_BSWM_TIMER_RUN_FROM_LOW_PWR >= bswmif_u16TPassengerWakeupTimer)
      {
         /* Check if CAN bus activity was detected this iteration */
         if (KU8_BSWM_TX_PDU_ENABLED == bswmif_u8CurrentTxPduState)
         {
            /* Reset timer value */
            bswmif_u16TPassengerWakeupTimer = KU16_ZERO;

            /* Stop LPIT2 timer */
            Gpt_StopTimer(GptConf_GptChannelConfiguration_GPT_CYCLIC_TIMER);

            /* Stop main scheduler due CPU Load to be able to call WriteAll service */
            //(void)StopScheduleTable(Rte_DefaultScheduleTable);

            /* Start default scheduler to manage OsTask_Bsw_ReadWrite_AllProcess task */
            //(void)StartScheduleTableRel(Rte_PostRunScheduleTable, KU32_BSWM_SCHEDULER_NO_OF_TICKS);

            /* Start Write All process */
            NvM_WriteAll();

            /* Request to start the process to fastened the ReadAll process */
            BswM_RequestMode(KU8_BSWM_REQUEST_PORT, BSWM_READ_WRITE_ALL_PROCESS);

            /* Activate the task and event dedicated to the OsTask_Bsw_ReadWrite_AllProcess */
            (void)ActivateTask(OsTask_Bsw_ReadWrite_AllProcess);
            (void)SetEvent(OsTask_Bsw_ReadWrite_AllProcess, OsEvent_ReadWriteAllProcess);

            /* Set flag to indicate that writeAll procedure was reqested */
            bswmif_u8WriteAllFromAutonomousRequested = KU8_TRUE;
         }
      }
      /* No CAN Activity detected, stop timer and go back to POST RUN State */
      else
      {
         /* Stop LPIT2 timer */
         Gpt_StopTimer(GptConf_GptChannelConfiguration_GPT_CYCLIC_TIMER);

         /* Set TX PDU request port to disable tx to trigger RUN->POST RUN rule */
         BswM_RequestMode(KU8_BSWM_TX_PDU_STATE_REQUESTED_PORT, BSWM_DISABLE_TX_PDU);

         /* Set BswM port to notify that pasager occupancy was not detected */
         BswM_RequestMode(KU8_BSWM_PASSANGER_OCCUPANCY_REQUEST_PORT, BSWM_PASSANGER_OCCUPANCY_NOT_DETECTED);

         /* Set ECU State BswM Port to RUN to be able to retrigger the RUN -> POST RUN rule */
         BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_RUN_MODE_ACTIVE);

         /* Reset timer value */
         bswmif_u16TPassengerWakeupTimer = KU16_ZERO;
      }
   }
   /* Autonomous RUN: Transition LOW POWER -> RUN (passenger detected) for TPassengerWakeup - TPostRun seconds */
   else if (BSWM_RUN_MODE_FROM_LOW_PWR == bswmif_u8CurrentEcuState)
   {
      /* Increment timer => 10ms passed */
      bswmif_u16TRunFromLowPowerTimer++;

      /* If passenger occupancy is detected on another seat or current passenger occupancy
         status is reset, reset the counter */
      if (KU8_BSWM_PASSENGER_OCCUPANCY_DETECTED_APP == bswmif_u8PassengerOccupancyStatus)
      {
         /* Reset Counter */
         bswmif_u16TRunFromLowPowerTimer = KU16_ZERO;

         /* Reset external wakeup flag to be able to detect another occupancy detecton */
         bswmif_u8PassengerOccupancyStatus = KU8_BSWM_PASSENGER_OCCUPANCY_NOT_DETECTED_APP;
      }

      /* Verify if CAN Activity was detected in max TPassengerWakeup - TPostRun seconds
       * and if it is, go in RUN state */
      if (KU32_BSWM_TIMER_RUN_FROM_LOW_PWR >= bswmif_u16TRunFromLowPowerTimer)
      {
         /* Check if CAN bus activity was detected this iteration */
         if (KU8_BSWM_TX_PDU_ENABLED == bswmif_u8CurrentTxPduState)
         {
            /* Reset timer value */
            bswmif_u16TRunFromLowPowerTimer = KU16_ZERO;

            /* Stop LPIT2 timer */
            Gpt_StopTimer(GptConf_GptChannelConfiguration_GPT_CYCLIC_TIMER);

            /* Stop main scheduler due CPU Load to be able to call WriteAll service */
            //(void)StopScheduleTable(Rte_DefaultScheduleTable);

            /* Start default scheduler to manage OsTask_Bsw_ReadWrite_AllProcess task */
            //(void)StartScheduleTableRel(Rte_PostRunScheduleTable, KU32_BSWM_SCHEDULER_NO_OF_TICKS);

            /* Start Write All process */
            NvM_WriteAll();

            /* Request to start the process to fastened the ReadAll process */
            BswM_RequestMode(KU8_BSWM_REQUEST_PORT, BSWM_READ_WRITE_ALL_PROCESS);

            /* Activate the task and event dedicated to the OsTask_Bsw_ReadWrite_AllProcess */
            (void)ActivateTask(OsTask_Bsw_ReadWrite_AllProcess);
            (void)SetEvent(OsTask_Bsw_ReadWrite_AllProcess, OsEvent_ReadWriteAllProcess);

            /* Set flag to indicate that writeAll procedure was reqested */
            bswmif_u8WriteAllFromAutonomousRequested = KU8_TRUE;
         }
      }
      /* No CAN Activity detected, stop timer and go back to POST RUN State */
      else
      {
         /* Stop LPIT2 timer */
         Gpt_StopTimer(GptConf_GptChannelConfiguration_GPT_CYCLIC_TIMER);

         /* Set TX PDU request port to disable tx to trigger RUN->POST RUN rule */
         BswM_RequestMode(KU8_BSWM_TX_PDU_STATE_REQUESTED_PORT, BSWM_DISABLE_TX_PDU);

         /* Set BswM port to notify that pasager occupancy was not detected */
         BswM_RequestMode(KU8_BSWM_PASSANGER_OCCUPANCY_REQUEST_PORT, BSWM_PASSANGER_OCCUPANCY_NOT_DETECTED);

         /* Set ECU State BswM Port to RUN to be able to retrigger the RUN -> POST RUN rule */
         BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_RUN_MODE_ACTIVE);

         /* Reset timer value */
         bswmif_u16TRunFromLowPowerTimer = KU16_ZERO;
      }
   }
   else
   {
      /* Do nothing */ 
   }
}
/**
* \brief
*     This service is a callout used to initialize Can/Com stack and modules 
*     which doesn't need RTE or dynamic EEPROM parameters. ReadAll process is
*     also started here.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_RequestPort == "BSWM_STARTUP_TWO_A" 
* \constrains
*     First part of ECU initialization must be done (EcuM_StartupOne, 
*     EcuM_StartupTwo) and default scheduler must be enabled.
* \ddesignrequirement
*     DSG_BswM_OnStartupTwoA
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServices_BswMIf_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrAdcIfServicesBswMIf_AdcIf_runInit_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrCanIfServicesBswMIf_CanIf_Init_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrCanServicesBswMIf_Can_SetControllerMode_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrCanServicesBswMIf_Can_EnableControllerInterrupts_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrCanSMServicesBswMIf_CanSM_Init_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrCanTpServicesBswMIf_CanTp_Init_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrComServicesBswMIf_Com_Init_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrNvMServicesBswMIf_NvM_Init_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrNvMServicesBswMIf_NvM_ReadAll_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_ActivateTask_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_SetEvent_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrPduRServicesBswMIf_PduR_Init_BswM_OnStartupTwoA;
*     ARCH_SW_BswMIf_ptrrMicServicesBswMIf_MIC_Init_BswM_OnStartupTwoA;
**/
EXPORTED void BswM_OnStartupTwoA(void)
{
   /* Initialize can stack */
   (void)Can_SetControllerMode(KU8_BSWM_MQB_CAN_CONTROLLER, CAN_CS_STARTED);
   Can_EnableControllerInterrupts(KU8_BSWM_MQB_CAN_CONTROLLER);
   CanIf_Init(&CanIf_Config_TDK_4G);
   CanSM_Init(&CanSM_Config_TDK_4G);
   CanTp_Init(&CanTp_Config_TDK_4G);
   PduR_Init(&PduRRoutingTables_TDK_4G);
   Com_Init(&ComConfig_TDK_4G);

   /* Run the MIC init and ECC reset detection */
   MIC_Init();

   /*Initialize NvM stack*/
   NvM_Init();

   /* Start Read All process */
   NvM_ReadAll();

   /* Call the AdcIf to start ADC conversions */
   AdcIf_runInit();

   /* Request to start the process to fastened the ReadAll process */
   BswM_RequestMode(KU8_BSWM_REQUEST_PORT, BSWM_READ_WRITE_ALL_PROCESS);

   /* Activate the task and event dedicated to the ReadAll process fastening */
   (void)ActivateTask(OsTask_Bsw_ReadWrite_AllProcess);
   (void)SetEvent(OsTask_Bsw_ReadWrite_AllProcess, OsEvent_ReadWriteAllProcess);

   /* Update Ecu current state */
   bswmif_u8CurrentEcuState = BSWM_STARTUP_TWO_A;
}
/**
* \brief
*     This service is a callout used to react when a NvM ReadAll/WriteAll 
*     job is end.
* \inputparam
*     Name: NvM_CurrentServiceId;
*     Type: uint8;
*     Description: Current service id requested;
*     Range: 0x0C and 0x0D;
*     Name: NvM_GlobalErrorStatus;
*     Type: uint8;
*     Description: Status of finished block operation;
*     Range: 0...8;
* \dynamicaspectcaller
*     Tresos-configured NvM multiblock request 
*     call-back Function.
* \dynamicaspectdescription
*     Called when a readAll or writeAll NvM request
*     is finished.
* \constrains
*     ReadWrite_AllProcess OS task should be activated
* \ddesignrequirement
*     DSG_BswM_CB_NfyNvMJobEnd
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrNvMServicesBswMIf_BswM_CB_NfyNvMJobEnd;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_CB_NfyNvMJobEnd;
*     ARCH_SW_BswMIf_ptrrCanIfServicesBswMIf_CanIf_CheckWakeup_BswM_CB_NfyNvMJobEnd;
*     ARCH_SW_BswMIf_ptrrGptServicesBswMIf_Gpt_StartTimer_BswM_CB_NfyNvMJobEnd;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_StopScheduleTable_BswM_CB_NfyNvMJobEnd;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_StartScheduleTableRel_BswM_CB_NfyNvMJobEnd;
**/
EXPORTED void BswM_CB_NfyNvMJobEnd(uint8 NvM_CurrentServiceId, uint8 NvM_GlobalErrorStatus)
{
   /* If Read All job is finished */
   if (NVM_READ_ALL_API_ID == NvM_CurrentServiceId)
   {
	  /* Start wake-up validation sequence */
	  CanIf_CanControllerFlags[0] |= 0x01U;

	  (void)EcuM_SetWakeupEvent(EcuM_ECUM_WKSOURCE_CAN);

      /* Request to continue the initialization phase */
      BswM_RequestMode(KU8_BSWM_REQUEST_PORT, BSWM_STARTUP_TWO_B);

      /* Notify that the read process has ended */
      bswmif_u8IsReadWriteAllEndNotificationSet = KU8_TRUE;
   }
   /* If Write All job is finished */
   else if (NVM_WRITE_ALL_API_ID == NvM_CurrentServiceId)
   {  
      /* If writeAll request was made by transition from AUTONOMOUS RUN
       to FULL RUN make unlock and go to FULL RUN */
      if(KU8_TRUE == bswmif_u8WriteAllFromAutonomousRequested)
      {
         /* Reset flag */
         bswmif_u8WriteAllFromAutonomousRequested = KU8_FALSE;

         /* Stop PostRun scheduler */
         //(void)StopScheduleTable(Rte_PostRunScheduleTable);

         /* Start main scheduler due CPU Load after WriteAll service was done */
         //(void)StartScheduleTableRel(Rte_DefaultScheduleTable, KU32_BSWM_SCHEDULER_NO_OF_TICKS);

         /* Reset passenger occupancy BswM port */
         BswM_RequestMode(KU8_BSWM_PASSANGER_OCCUPANCY_REQUEST_PORT, BSWM_PASSANGER_OCCUPANCY_NOT_DETECTED);

         /* Set ECU State BswM Port to RUN */
         BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_RUN_MODE_ACTIVE);

         /* Update ECU current state */
         bswmif_u8CurrentEcuState = BSWM_RUN_MODE_ACTIVE;

      }
      /* If writeAll request was made by transition in POST RUN start TPostRun timer */
      else if(KU8_BSWM_NO_RESET == bswmif_u8RequestedReset)
      {
         /* Stop default scheduler */
         //(void)StopScheduleTable(Rte_PostRunScheduleTable);

         /* Start main scheduler due CPU Load after WriteAll service was done */
         //(void)StartScheduleTableRel(Rte_DefaultScheduleTable, KU32_BSWM_SCHEDULER_NO_OF_TICKS);

         /* Start GPT timer on LPIT Channel 2 */
         Gpt_StartTimer(GptConf_GptChannelConfiguration_GPT_CYCLIC_TIMER, KU32_BSWM_LPIT_CH2_RST_VALUE);
      }
      /* SW/HW/FBL request, writeAll procedure finished, proceed with GO_OFF_ONE_A */
      else
      {
         /* Request to enter GO_OFF_ONE_A to perform de-initialization of modules */
         BswM_RequestMode(KU8_BSWM_REQUEST_PORT, BSWM_GO_OFF_ONE_A);
      }
      /* Notify that the write process has ended */
      bswmif_u8IsReadWriteAllEndNotificationSet = KU8_TRUE;
   }
   else
   {
      /* Do nothing */
   }
}
/**
* \brief
*     This service is a callout used to initialize modules which 
*     doesn't need RTE but need dynamic EEPROM parameters.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_RequestPort == "BSWM_STARTUP_TWO_B" 
* \constrains
*     ReadAll NvM procedure must be done in order to
*     BswM_CB_NfyNvMJobEnd callback to be called.
* \ddesignrequirement
*     DSG_BswM_OnStartupTwoB
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnStartupTwoB;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_OnStartupTwoB;
*     ARCH_SW_BswMIf_ptrrComMServicesBswMIf_ComM_Init_BswM_OnStartupTwoB;
*     ARCH_SW_BswMIf_ptrrDemServicesBswMIf_Dem_Init_BswM_OnStartupTwoB;
*     ARCH_SW_BswMIf_ptrrEcuMServicesBswMIf_EcuM_ValidateWakeupEvent_BswM_OnStartupTwoB;
*     ARCH_SW_BswMIf_ptrrFsmServicesBswMIf_FSM_Init_BswM_OnStartupTwoB;
*     ARCH_SW_BswMIf_ptrrGptServicesBswMIf_Gpt_EnableNotification_BswM_OnStartupTwoB;
*     ARCH_SW_BswMIf_pclCILGetEcuState_BswM_OnStartupTwoB;
**/
EXPORTED void BswM_OnStartupTwoB(void)
{
   /* Initializes the AUTOSAR Communication Manager and restarts the internal state machines. */
   ComM_Init(&ComMConfigSet_0_TDK_4G);

   /* Initialization of DEM module */
   Dem_Init();

   /* Initialization of FSM module */
   FSM_Init();

   /* Request to proceed with next step of initialization: state to wait for wake-up validation  */
   BswM_RequestMode(KU8_BSWM_REQUEST_PORT, BSWM_WAIT_WAKEUP_VALIDATION);

   /* Update Ecu current state */
   bswmif_u8CurrentEcuState = BSWM_STARTUP_TWO_B;

   /* Enable Notification function on GPT timer on LPIT Channel 2 */
   Gpt_EnableNotification(GptConf_GptChannelConfiguration_GPT_CYCLIC_TIMER);

   /* Start application Idle task (Gliwa) */
   (void)ActivateTask(OsTask_AppIdle);

   /* Update ECU State */
   Rte_Call_pclCILGetEcuState_updateCurrentEcuState(bswmif_u8CurrentEcuState);
}
/**
* \brief
*     This service is a callout used to authorize and start communication
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_RequestPort == "BSWM_WAIT_WAKEUP_VALIDATION";
*     BswM_EcuM_RequestPort == "ECUM_WKSTATUS_VALIDATED";
* \constrains
*     ReadAll NvM procedure must be done in order to
*     BswM_CB_NfyNvMJobEnd callback to be called and EcuM 
*     needs to validate the wakeup event.
* \ddesignrequirement
*     DSG_BswM_OnWakeupValidation
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnWakeupValidation;
*     ARCH_SW_BswMIf_ptrrComMServicesBswMIf_ComM_CommunicationAllowed_BswM_OnWakeupValidation;
*     ARCH_SW_BswMIf_ptrrComMServicesBswMIf_ComM_ASR40_RequestComMode_BswM_OnWakeupValidation;
**/
EXPORTED void BswM_OnWakeupValidation(void)
{
   /* Authorize the start of communication */
   ComM_CommunicationAllowed(ComMConf_ComMChannel_Airbag_SUBCANFD, TRUE);

   /* Switch COM to full communication mode */
   (void)ComM_ASR40_RequestComMode(0u, COMM_FULL_COMMUNICATION);
}

/**
* \brief
*     This service is a callout used to validate wakeup when process mode is
*     requested at power up OR if wakeup is not validated and ECU goes to SLEEP
*     State.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_RequestPort == "BSWM_WAIT_WAKEUP_VALIDATION";
*     BswM_EcuM_RequestPort == "ECUM_WKSTATUS_EXPIRED";
*     OR
*     BswM_RequestPort == "BSWM_GO_OFF_ONE_B";
* \constrains
*     ReadAll NvM procedure must be done in order to
*     BswM_CB_NfyNvMJobEnd callback to be called and EcuM 
*     needs to invalidate the wakeup event.
* \ddesignrequirement
*     DSG_BswM_OnWakeupExpired
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnWakeupExpired;
*     ARCH_SW_BswMIf_ptrrEcuMServicesBswMIf_EcuM_GoDown_BswM_OnWakeupExpired;
**/
EXPORTED void BswM_OnWakeupExpired(void)
{
   /* Check if process mode is active */
   if(KU8_BSWM_PROCESS_MODE_REQUESTED == NVP_u8ProcessMode)
   {
      /* If process mode is enabled AND a SW/HW/FBL reset is requested
         (BswM_RequestPort == "BSWM_GO_OFF_ONE_B" is validated), proceed with reset */
      if(KU8_BSWM_NO_RESET != bswmif_u8RequestedReset)
      {
         (void)EcuM_GoDown(0);
      }
      /* Wakeup validation expired (no active TX frames received) but Process mode
         is active, validate wakeup and jump to the run state */
      else
      {
         BswM_OnWakeupValidation();
      } 
   }
   /* Wakeup validation expired and process mode not requested (ECU is powered without
      receiving any valid frames)*/
   else
   {
      (void)EcuM_GoDown(0);
   } 
}

/**
* \brief
*     This service is a callout used to start RTE and to initialize  
*     all functions who need RTE features.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswmM_CanSM_RequestPort != "CANSM_BSWM_NO_COMMUNICATION;
*     BswM_RequestPort == "BSWM_WAIT_WAKEUP_VALIDATION";
* \constrains
*     Bus communication must be available (after authorisation in 
*     BswM_OnWakeupValidation step). 
* \ddesignrequirement
*     DSG_BswM_OnStartComEffective
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnStartComEffective;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_OnStartComEffective;
*     ARCH_SW_BswMIf_ptrrEcuMServicesBswMIf_EcuM_ClearWakeupEvent_BswM_OnStartComEffective;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_StopScheduleTable_BswM_OnStartComEffective;
*     ARCH_SW_BswMIf_ptrrRteServicesBswMIf_Rte_Start_BswM_OnStartComEffective;
*     ARCH_SW_BswMIf_ptrrAtmServicesBswMIf_ATM_Init_BswM_OnStartComEffective;
*     ARCH_SW_BswMIf_ptrrCilServicesBswMIf_CIL_runInit_BswM_OnStartComEffective;
*     ARCH_SW_BswMIf_ptrrDiaServicesBswMIf_DIA_Init_BswM_OnStartComEffective;
*     ARCH_SW_BswMIf_ptrrFsmServicesBswMIf_FSM_ModesInit_BswM_OnStartComEffective;
*     ARCH_SW_BswMIf_ptrrRcmServicesBswMIf_RCM_DetermineResetCause_BswM_OnStartComEffective;
*     ARCH_SW_BswMIf_ptrrSadServicesBswMIf_SAD_Init_BswM_OnStartComEffective;
*     ARCH_SW_BswMIf_pclDemSetOpCycle_BswM_OnStartComEffective;
*     ARCH_SW_BswMIf_ptrrDcmServicesBswMIf_Dcm_Init_BswM_OnStartComEffective;
**/
EXPORTED void BswM_OnStartComEffective(void)
{
   /* Acknowledge wake validation information */
   EcuM_ClearWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);

   /* Stop default schedule table */
   (void)StopScheduleTable(SchM_DefaultScheduleTable);

   /* Start main schedule table */
   (void)Rte_Start();
   
   /* Initialization of DCM module */
   Dcm_Init(&DcmConfigSet);

   /* Initialization of functions which need RTE features */
   ATM_Init();
   FSM_ModesInit();
   CIL_runInit();
   DIA_Init();
   SAD_Init();

   /* Second part of the Reset Cause Init */
   RCM_DetermineResetCause();

   /* Set operation cycle state for DEM */
   (void)Rte_Call_pclDemSetOpCycle_SetOperationCycleState(DEM_CYCLE_STATE_START);
   
   /* Request to enter the nominal mode of BswM */
   BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_WAKEUP_MODE_ACTIVE);

   /* Request to enter the nominal mode of BswM */
   BswM_RequestMode(KU8_BSWM_REQUEST_PORT, BSWM_WAKEUP_VALIDATED); 
}
/**
* \brief
*     This service is a callout called when a RUN from WAKE-UP 
*     transition is validated.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_EcuState_RequestPort == "BSWM_WAKEUP_MODE_ACTIVE"
* \constrains
*     BswM_OnStartComEffective callback must be called before
*     to be able to fullfil de BswM rule.
* \ddesignrequirement
*     DSG_BswM_OnRunFromWakeup
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnRunFromWakeup;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_OnRunFromWakeup;
*     ARCH_SW_BswMIf_ptrrMcuIfServicesBswMIf_McuIf_runInit;
*     ARCH_SW_BswMIf_pclCILGetEcuState_BswM_OnRunFromWakeup;
**/
EXPORTED void BswM_OnRunFromWakeup(void)
{
   /* Request to enter the nominal mode of BswM */
   BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_RUN_MODE_ACTIVE);

   /* Update Ecu current state */
   bswmif_u8CurrentEcuState = BSWM_RUN_MODE_ACTIVE;

   /* Call McuIf init to calculate init value of CRC on safety registers */
   McuIf_runInit();
}
/**
* \brief
*     This service is a callout called when a POST RUN from RUN 
*     transition is validated.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_TxPdu_RequestPort == "BSWM_DISABLE_TX_PDU";
*     BswM_EcuState_RequestPort == "BSWM_RUN_MODE_ACTIVE";
* \constrains
*     Ecu must be in RUN State and also a bus timeout is
*     necessary to be detected in NmIf module to be able to 
*     achieve this rule.
* \ddesignrequirement
*     DSG_BswM_OnPostRunFromRun
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnPostRunFromRun;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_StopScheduleTable_BswM_OnPostRunFromRun;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_StartScheduleTableRel_BswM_OnPostRunFromRun;
*     ARCH_SW_BswMIf_ptrrNvMServicesBswMIf_NvM_WriteAll_BswM_OnPostRunFromRun;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_OnPostRunFromRun;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_ActivateTask_BswM_OnPostRunFromRun;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_SetEvent_BswM_OnPostRunFromRun;
*     ARCH_SW_BswMIf_ptrrComMServicesBswMIf_ComM_ASR40_RequestComMode_BswM_OnPostRunFromRun;
*     ARCH_SW_BswMIf_pclCILGetEcuState_BswM_OnPostRunFromRun;
**/
EXPORTED void BswM_OnPostRunFromRun(void)
{
   /* This if is used to avoid the case when LOW POWER -> RUN 
   transition is validated by CAN activity on bus and this rule is 
   executed before to receive frame ack. */
   if (KU8_FALSE == bswmif_u8RunToLowPowerTransitionValidated)
   {
      /* Stop main scheduler due CPU Load to be able to call WriteAll service */
      //(void)StopScheduleTable(Rte_DefaultScheduleTable);

      /* Start default scheduler to manage OsTask_Bsw_ReadWrite_AllProcess task */
      //(void)StartScheduleTableRel(Rte_PostRunScheduleTable, KU32_BSWM_SCHEDULER_NO_OF_TICKS);

      /* Start Write All process */
      NvM_WriteAll();

      /* Request to start the process to fastened the ReadAll process */
      BswM_RequestMode(KU8_BSWM_REQUEST_PORT, BSWM_READ_WRITE_ALL_PROCESS);

      /* Activate the task and event dedicated to the OsTask_Bsw_ReadWrite_AllProcess */
      (void)ActivateTask(OsTask_Bsw_ReadWrite_AllProcess);
      (void)SetEvent(OsTask_Bsw_ReadWrite_AllProcess, OsEvent_ReadWriteAllProcess);

      /* Set ComM back to full communication to be able to detect a wake-up request */
      (void)ComM_ASR40_RequestComMode(0u, COMM_FULL_COMMUNICATION);
      
      /* Set ECU State port to POST RUN active */
      BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_POST_RUN_MODE_ACTIVE);

      /* Update ECU current state */
      bswmif_u8CurrentEcuState = BSWM_POST_RUN_MODE_ACTIVE;

      /* Update ECU State */
      Rte_Call_pclCILGetEcuState_updateCurrentEcuState(bswmif_u8CurrentEcuState);
   }
   /* Rule called before reception of RX ACK, do nothing and reset the flag */
   else
   {
      bswmif_u8RunToLowPowerTransitionValidated = KU8_FALSE;
   }
}
/**
* \brief
*     This service is a callout called when a RUN from POST RUN 
*     transition is validated.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_EcuState_RequestPort == "BSWM_POST_RUN_MODE_ACTIVE";
*     BswM_TxPdu_RequestPort == "BSWM_ENABLE_TX_PDU";
* \constrains
*     ECU must be in POST RUN State and a bus activity 
*     is necessary to be able to fulfill this rule
* \ddesignrequirement
*     DSG_BswM_OnRunFromPostRunBusAvailable
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnRunFromPostRunBusAvailable;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_OnRunFromPostRunBusAvailable;
*     ARCH_SW_BswMIf_ptrrGptServicesBswMIf_Gpt_StopTimer_BswM_OnRunFromPostRunBusAvailable;
*     ARCH_SW_BswMIf_pclCILGetEcuState_BswM_OnRunFromPostRunBusAvailable;
**/
EXPORTED void BswM_OnRunFromPostRunBusAvailable(void)
{
   /* Stop LPIT2 timer */
   Gpt_StopTimer(GptConf_GptChannelConfiguration_GPT_CYCLIC_TIMER);

   /* Request to proceed with RUN State because CAN Activity was detected */
   BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_RUN_MODE_ACTIVE);

   /* Update ECU current state */
   bswmif_u8CurrentEcuState = BSWM_RUN_MODE_ACTIVE;

   /* Update ECU State */
   Rte_Call_pclCILGetEcuState_updateCurrentEcuState(bswmif_u8CurrentEcuState);
}
/**
* \brief
*     This service is a callout called when a RUN from POST RUN  
*     transition is validated.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_EcuState_RequestPort == "BSWM_POST_RUN_MODE_ACTIVE";
*     BswM_ExternalWakeup_RequestPort == "BSWM_PASSANGER_OCCUPANCY_DETECTED";
* \constrains
*     Ecu must be in POST RUN State and passenger occupancy detection
*     is necessary to be able to fulfill this rule.
* \ddesignrequirement
*     DSG_BswM_OnRunFromPostRunPassengerDetected
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnRunFromPostRunPassengerDetected;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_OnRunFromPostRunPassengerDetected;
*     ARCH_SW_BswMIf_ptrrGptServicesBswMIf_Gpt_StartTimer_BswM_OnRunFromPostRunPassengerDetected;
*     ARCH_SW_BswMIf_pclCILGetEcuState_BswM_OnRunFromPostRunPassengerDetected;
**/
EXPORTED void BswM_OnRunFromPostRunPassengerDetected(void)
{
   /* Start GPT timer on LPIT Channel 2 */
   Gpt_StartTimer(GptConf_GptChannelConfiguration_GPT_CYCLIC_TIMER, KU32_BSWM_LPIT_CH2_RST_VALUE);

   /* Request to proceed with RUN no communication active mode */
   BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_RUN_MODE_NO_COM_ACTIVE);

   /* Set TX PDU request port to wait tx to not trigger another rule */
   BswM_RequestMode(KU8_BSWM_TX_PDU_STATE_REQUESTED_PORT, BSWM_WAIT_TX_PDU);

   /* Update ECU current state */
   bswmif_u8CurrentEcuState = BSWM_RUN_MODE_NO_COM_ACTIVE;

   /* Update ECU State */
   Rte_Call_pclCILGetEcuState_updateCurrentEcuState(bswmif_u8CurrentEcuState);

}

/**
* \brief
*     This service is a callout called when a LOW POWER from POST RUN 
*     transition is validated.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_EcuState_RequestPort == "BSWM_LOW_PWR_MODE_REQUESTED"
* \constrains
*     Ecu must be in POST RUN State and LOW POWER mode was requested
*     (no passenger occupancy or bus activity was detected during
*     TPostRun seconds)
* \ddesignrequirement
*     DSG_BswM_OnLowPwrFromPostRun
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnLowPwrFromPostRun;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_OnLowPwrFromPostRun;
*     ARCH_SW_BswMIf_ptrrLpmServicesBswMIf_LPM_sleepInit_BswM_OnLowPwrFromPostRun;
*     ARCH_SW_BswMIf_ptrrLpmServicesBswMIf_LPM_sleepMainLoop_BswM_OnLowPwrFromPostRun;
*     ARCH_SW_BswMIf_ptrrLpmServicesBswMIf_LPM_sleepRestore_BswM_OnLowPwrFromPostRun;
**/
EXPORTED void BswM_OnLowPwrFromPostRun(void)
{
   /* Request to proceed with Low Power mode*/
   BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_LOW_PWR_MODE_ACTIVE);

   /* Update ECU current state */
   bswmif_u8CurrentEcuState = BSWM_LOW_PWR_MODE_ACTIVE;

   /* Update ECU State */
   

   /* Initialize the Low Power Managment module */
   LPM_sleepInit();

   /* Enter in main loop and stay there until:
         - passenger occupancy detected
         - Bus activity detected
         - TLowPower timeout */
   LPM_sleepMainLoop();

   /* Restore previous state and set rules to go back in RUN STATE */
   LPM_sleepRestore();
}
/**
* \brief
*     This service is a callout called when a RUN from LOW POWER 
*     transition is validated.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_ExternalWakeup_RequestPort == "BSWM_PASSANGER_OCCUPANCY_DETECTED";
*     BswM_EcuState_RequestPort == "BSWM_LOW_PWR_MODE_ACTIVE";
*     BswM_WakeupType_RequestPort == "BSWM_ACTIVE_WAKEUP_REQ";
* \constrains
*     ECU must be in LOW POWER State AND passenger occupancy must be 
*     detected to enter in this state.
* \ddesignrequirement
*     DSG_BswM_OnRunFromLowPwrPassengerDetected
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnRunFromLowPwrPassengerDetected;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_OnRunFromLowPwrPassengerDetected;
*     ARCH_SW_BswMIf_ptrrGptServicesBswMIf_Gpt_StartTimer_BswM_OnRunFromLowPwrPassengerDetected;
*     ARCH_SW_BswMIf_pclCILGetEcuState_BswM_OnRunFromLowPwrPassengerDetected;
**/
EXPORTED void BswM_OnRunFromLowPwrPassengerDetected(void)
{
   /* Request to proceed with RUN Power mode */
   BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_RUN_MODE_FROM_LOW_PWR);

   /* Update Ecu current state */
   bswmif_u8CurrentEcuState = BSWM_RUN_MODE_FROM_LOW_PWR;

   /* Update ECU State */
   Rte_Call_pclCILGetEcuState_updateCurrentEcuState(BSWM_RUN_MODE_NO_COM_ACTIVE);

    /* Start GPT timer on LPIT Channel 2 */
   Gpt_StartTimer(GptConf_GptChannelConfiguration_GPT_CYCLIC_TIMER, KU32_BSWM_LPIT_CH2_RST_VALUE);
}
/**
* \brief
*     This service is a callout called when a RUN from LOW POWER 
*     transition is validated.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_EcuState_RequestPort == "BSWM_LOW_PWR_MODE_ACTIVE"
*     BswM_WakeupType_RequestPort == "BSWM_PASSIVE_WAKEUP_REQ"
* \constrains
*     Ecu must be in LOW POWER State AND bus activity must be 
*     detected to enter in this state.
* \ddesignrequirement
*     DSG_BswM_OnRunFromLowPwrBusAvailable
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnRunFromLowPwrBusAvailable
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_OnRunFromLowPwrBusAvailable
*     ARCH_SW_BswMIf_pclCILGetEcuState_BswM_OnRunFromLowPwrBusAvailable
**/
EXPORTED void BswM_OnRunFromLowPwrBusAvailable(void)
{
   /* Request to proceed with RUN Power mode */
   BswM_RequestMode(KU8_BSWM_ECU_STATE_REQUEST_PORT, BSWM_RUN_MODE_ACTIVE);

   /* Update Ecu current state */
   bswmif_u8CurrentEcuState = BSWM_RUN_MODE_ACTIVE;

   /* Update ECU State */
   Rte_Call_pclCILGetEcuState_updateCurrentEcuState(bswmif_u8CurrentEcuState);

   /* Set flag to avoid to enter in POST RUN state before to receive RX ACK */
   bswmif_u8RunToLowPowerTransitionValidated = KU8_TRUE;
}
/**
* \brief
*     This service is a callout called when RunToLowPowerTransition
*     status needs to be changed.
* \inputparam
*     Name: u8TransitionStatus;
*     Type: uint8;
*     Description: State of transition;
*     Range: 0x55..0xAA;
* \dynamicaspectcaller
*     NmIf_runMainFunction
* \dynamicaspectdescription
*     Called when Rx acknoledge is received by NmIf module
* \constrains
*     This function has no constrains
* \ddesignrequirement
*     DSG_BswM_SetEcuStateTransitionStatus
* \archrequirement
*     ARCH_SW_BswMIf_pseECUStateTransitions;
*     ARCH_SW_BswMIf_ptrpNmIfServicesBswMIf_BswM_SetEcuStateTransitionStatus;
**/
EXPORTED void BswM_SetEcuStateTransitionStatus(uint8 u8TransitionStatus)
{
   bswmif_u8RunToLowPowerTransitionValidated = u8TransitionStatus;
}

/**
* \brief
*     This service is a callout called when SHUTDOWN procedure is
*     requested.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_EcuShutdown_RequestPort == "BSWM_ECU_SHUTDOWN_REQUESTED";
*     OR
*     BswM_EcuState_RequestPort == "BSWM_LOW_PWR_MODE_ACTIVE",;
*     BswM_PassangerOccupancy_RequestPort == "BSWM_PASSANGER_OCCUPANCY_NOT_DETECTED",;
*     BswM_WakeupType_RequestPort == "BSWM_NO_WAKEUP_REQ";
* \constrains
*     Shutdown is called when:
*        o software reset is requested
*        o when buckle and SBS sensors are not present and TPostRun expires
*        o when ECU current state is LOW POWER and TLowPower expires  
* \ddesignrequirement
*     DSG_BswM_On_Prep_Shutdown
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_On_Prep_Shutdown;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_On_Prep_Shutdown;
*     ARCH_SW_BswMIf_ptrrDemServicesBswMIf_Dem_Shutdown_BswM_On_Prep_Shutdown;
*     ARCH_SW_BswMIf_ptrrEcuMServicesBswMIf_EcuM_ClearWakeupEvent_BswM_On_Prep_Shutdown;
*     ARCH_SW_BswMIf_ptrrNvMServicesBswMIf_NvM_WriteAll_BswM_On_Prep_Shutdown;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_ActivateTask_BswM_On_Prep_Shutdown;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_SetEvent_BswM_On_Prep_Shutdown;
*     ARCH_SW_BswMIf_ptrrRteServicesBswMIf_Rte_Stop_BswM_On_Prep_Shutdown;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_StartScheduleTableRel_BswM_On_Prep_Shutdown;
**/
EXPORTED void BswM_On_Prep_Shutdown(void)
{
   /* Shutdown Dem module */
   Dem_Shutdown();

   /* Clear wakeup events */
   EcuM_ClearWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);

   /* If SW/HW/FBL reset is requested start writeAll procedure. This condition is
      necessary because in this case POST RUN State is not reached and writeAll 
      procedure is not made. */
   if(KU8_BSWM_NO_RESET != bswmif_u8RequestedReset)
   {
      /* Stop all RTE processes */
      (void)Rte_Stop();

      /* Start default schedule table to be able to finish the shutdown procedure */
      (void)Rte_StartScheduleTable_SchM_DefaultScheduleTable();

      /* Start Write All process */
      NvM_WriteAll();

      /* Request to start the process to fastened the ReadAll process */
      BswM_RequestMode(KU8_BSWM_REQUEST_PORT, BSWM_READ_WRITE_ALL_PROCESS);

      /* Activate the task and event dedicated to thOsTask_Bsw_ReadWrite_AllProcess */
      (void)ActivateTask(OsTask_Bsw_ReadWrite_AllProcess);
      (void)SetEvent(OsTask_Bsw_ReadWrite_AllProcess, OsEvent_ReadWriteAllProcess);
   }
   /* POST RUN -> SHUTDOWN Transition validated
      LOW POWER -> SHUTDOWN (after 5min) validated
      writeAll request finished already, proceed with GO_OFF_ONE_A */
   else
   {
      /* Stop all RTE processes */
      (void)Rte_Stop();

      /* Start default schedule table to be able to finish the shutdown procedure */
      (void)Rte_StartScheduleTable_SchM_DefaultScheduleTable();

      /* Request to enter GO_OFF_ONE_A to perform de-initialization of modules */
      BswM_RequestMode(KU8_BSWM_REQUEST_PORT, BSWM_GO_OFF_ONE_A);
   }
}
/**
* \brief
*     This service is a callout called when SHUTDOWN procedure 
*     is started to Stop RTE and to de-initialize ComM module.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_RequestPort == "BSWM_GO_OFF_ONE_A"
* \constrains
*     BswM_On_Prep_Shutdown should be called before
* \ddesignrequirement
*     DSG_BswM_OnGoOffOneA
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnGoOffOneA;
*     ARCH_SW_BswMIf_ptrrAdcIfServicesBswMIf_AdcIf_runDeInit_BswM_OnGoOffOneA;
*     ARCH_SW_BswMIf_ptrrBswMServicesBswMIf_BswM_RequestMode_BswM_OnGoOffOneA;
*     ARCH_SW_BswMIf_ptrrComMServicesBswMIf_ComM_DeInit_BswM_OnGoOffOneA;
**/
EXPORTED void BswM_OnGoOffOneA(void)
{
   /* Stop ADC measurements */
   AdcIf_StopConversion();

   /* De-initialize communication */
   ComM_DeInit();

   /* Request to proceed with next step of shutdown procedure */
   BswM_RequestMode(KU8_BSWM_REQUEST_PORT, BSWM_GO_OFF_ONE_B);
}
/**
* \brief
*     This service is a callout called when a SW/HW/FBL Reset 
*     is requested.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_Dcm_RequestPort == ModeDeclaration::DcmEcuReset.EXECUTE 
* \constrains
*     A Software/Hardware Reset shall be requested
* \ddesignrequirement
*     DSG_BswM_ProceedReset
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_ProceedReset;
*     ARCH_SW_BswMIf_ptrrEcuMServicesBswMIf_EcuM_GoDown_BswM_ProceedReset;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_StopScheduleTable_BswM_ProceedReset;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_StartScheduleTable_BswM_ProceedReset;
**/
EXPORTED void BswM_ProceedReset(void)
{
   /* If a SW or FBL reset was requested -> start shutdown sequence to store parameters in NVM */
   if ((KU8_BSWM_SW_RESET == bswmif_u8RequestedReset)||
      (KU8_BSWM_FBL_RESET == bswmif_u8RequestedReset))
   {
      /* Start shutdown procedure */
      BswM_On_Prep_Shutdown();
   }
   /* If a HW or FBL reset was requested -> request to reset ECU */
   else if (KU8_BSWM_HW_RESET == bswmif_u8RequestedReset)
   {
      /* Stop Rte_DefaultScheduleTable */
      (void)StopScheduleTable(Rte_DefaultScheduleTable);
      /* Start SchM_DefaultScheduleTable to avoid OS error during SchM_DeInit function call */
      (void)Rte_StartScheduleTable_SchM_DefaultScheduleTable();
      (void)EcuM_GoDown(KU8_BSWM_MQB_CAN_CONTROLLER);
   }
   else
   {
      /* Do nothing */
   }
}
/**
* \brief
*     This service is a callout called at bus communication timeout.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_TxPdu_RequestPort == "BSWM_DISABLE_TX_PDU";
*     BswM_EcuState_RequestPort == "BSWM_RUN_MODE_ACTIVE";
* \constrains
*     Ecu must be in RUN State and also a bus timeout is
*     necessary to be detected in NmIf module to be able to 
*     achieve this rule.
* \ddesignrequirement
*     DSG_BswM_OnDisableTxPdu
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnDisableTxPdu;
*     ARCH_SW_BswMIf_ptrrComServicesBswMIf_Com_ClearIpduGroupVector_BswM_OnDisableTxPdu;
*     ARCH_SW_BswMIf_ptrrComServicesBswMIf_Com_SetIpduGroup_BswM_OnDisableTxPdu;
*     ARCH_SW_BswMIf_ptrrComServicesBswMIf_Com_IpduGroupControl_BswM_OnDisableTxPdu;
**/
EXPORTED void BswM_OnDisableTxPdu(void)
{
   Com_IpduGroupVector groupVector;
   
   /* Initialize the PDU group vector to 0 */
   Com_ClearIpduGroupVector(groupVector);

   /* Enable the RX and disable Tx ComIPDUs */
   Com_SetIpduGroup(groupVector, ComConf_ComIPduGroup_IPDUGroupIN_eCS, TRUE);
   Com_SetIpduGroup(groupVector, ComConf_ComIPduGroup_IPDUGroupOUT_eCS, FALSE);
   Com_SetIpduGroup(groupVector, ComConf_ComIPduGroup_IPDUGroupOUT_eCS_Comm, TRUE);

   /* Start both COM PDUs (enable Rx and disable Tx) */
   Com_IpduGroupControl(groupVector, FALSE);

   /* Set the current state of TX Pdu */
   bswmif_u8CurrentTxPduState = KU8_BSWM_TX_PDU_DISABLED;
}
/**
* \brief
*     This service is a callout called at bus communication reception after 
*     timeout.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_TxPdu_RequestPort == "BSWM_ENABLE_TX_PDU"
* \constrains
*     Ecu must detect bus reception to be able to achieve 
*     this rule.
* \ddesignrequirement
*     DSG_BswM_OnEnableTxPdu
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnEnableTxPdu;
*     ARCH_SW_BswMIf_ptrrComServicesBswMIf_Com_ClearIpduGroupVector_BswM_OnEnableTxPdu;
*     ARCH_SW_BswMIf_ptrrComServicesBswMIf_Com_SetIpduGroup_BswM_OnEnableTxPdu;
*     ARCH_SW_BswMIf_ptrrComServicesBswMIf_Com_IpduGroupControl_BswM_OnEnableTxPdu;
**/
EXPORTED void BswM_OnEnableTxPdu(void)
{
   /* Create the PDU group vector */
   Com_IpduGroupVector groupVector;
   
   if(KU8_TRUE == bswmif_u8AvoidToRunComAtInit)
   {
	   /* Initialize the PDU group vector to 0 */
	   Com_ClearIpduGroupVector(groupVector);

	   /* Enable the RX and Tx ComIPDUs */
	   Com_SetIpduGroup(groupVector, ComConf_ComIPduGroup_IPDUGroupOUT_eCS, TRUE);
	   Com_SetIpduGroup(groupVector, ComConf_ComIPduGroup_IPDUGroupIN_eCS, TRUE);
      Com_SetIpduGroup(groupVector, ComConf_ComIPduGroup_IPDUGroupOUT_eCS_Comm, TRUE);

	   /* Start both the COM RX PDUs and the TX PDUs */
	   Com_IpduGroupControl(groupVector, FALSE);

	   /* Set the current state of TX Pdu */
	   bswmif_u8CurrentTxPduState = KU8_BSWM_TX_PDU_ENABLED;
   }

   bswmif_u8AvoidToRunComAtInit = KU8_TRUE;

}
/**
* \brief
*     This service is a callout called when a HW Reset is requested
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_Dcm_RequestPort == ModeDeclaration::DcmEcuReset.HARD
* \constrains
*     Ecu must detect a HW reset to achieve this rule
* \ddesignrequirement
*     DSG_BswM_HWResetNotification
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_HWResetNotification;
*     ARCH_SW_BswMIf_pclNotifyResetCause_BswM_HWResetNotification;
**/
EXPORTED void BswM_HWResetNotification(void)
{
   /* Store the type of requested reset */
   bswmif_u8RequestedReset = KU8_BSWM_HW_RESET;

   /* Notify RCM module */
   Rte_Call_pclNotifyResetCause_NotifyResetCause(KU32_DIAG_HARD_RESET_NOTIFICATION);
}
/**
* \brief
*     This service is a callout called when a SW Reset is requested
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_Dcm_RequestPort == ModeDeclaration::DcmEcuReset.SOFT
* \constrains
*     Ecu must detect a SW reset to achieve this rule
* \ddesignrequirement
*     DSG_BswM_SWResetNotification
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_SWResetNotification;
*     ARCH_SW_BswMIf_pclNotifyResetCause_BswM_BswM_SWResetNotification;
**/
EXPORTED void BswM_SWResetNotification(void)
{
   /* Store the type of requested reset */
   bswmif_u8RequestedReset = KU8_BSWM_SW_RESET;

   /* Notify RCM module */
   Rte_Call_pclNotifyResetCause_NotifyResetCause(KU32_DIAG_SOFT_RESET_NOTIFICATION);
}
/**
* \brief
*     This service is a callout called when a Jump to FBL is requested
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_Dcm_RequestPort == ModeDeclaration::DcmEcuReset.JUMPTOBOOTLOADER 
* \constrains
*     Ecu must detect a jump to FBL request to achieve this rule
* \ddesignrequirement
*     DSG_BswM_JumpToFBLNotification
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_JumpToFBLNotification;
*     ARCH_SW_BswMIf_pclNotifyResetCause_BswM_JumpToFBLNotification;
**/
EXPORTED void BswM_JumpToFBLNotification(void)
{
   /* Store the type of requested reset */
   bswmif_u8RequestedReset = KU8_BSWM_FBL_RESET;

   /* Notify RCM module */
   Rte_Call_pclNotifyResetCause_NotifyResetCause(KU32_BTLD_RESET_NOTIFICATION);
}
/**
* \brief
*     This service is a callout called cyclic to check if
*     if any passenger occupancy or buckle status is changed.
* \dynamicaspectcaller
*     IoHwAb_runFilterMeasurements10ms
* \dynamicaspectdescription
*     Called when an external wakeup condition is validated.
* \constrains
*     Ecu must be in run mode.
* \ddesignrequirement
*     DSG_BswM_UpdatePassangerOccupancyStatus
* \archrequirement
*     ARCH_SW_BswMIf_psePassengerOccupancyState;
**/
EXPORTED void BswM_UpdatePassangerOccupancyStatus(void)
{
   /* Update external wakeup state just when current ecu state is not RUN */
   if(BSWM_RUN_MODE_ACTIVE != bswmif_u8CurrentEcuState)
   {
      bswmif_u8PassengerOccupancyStatus = KU8_BSWM_PASSENGER_OCCUPANCY_DETECTED_APP;
   }
}
/**
* \brief
*     This task is a cyclic task used in readAll/writeAll
*     process.
* \dynamicaspectcaller
*     Cyclic task called by OS.
* \dynamicaspectdescription
*     Called when read/write process task is activated.
* \constrains
*     ECU must previous call BswM_OnStartupTwoA or BswM_OnGoOffOneA
*     or BswM_OnPostRunFromRun rules.
* \ddesignrequirement
*     DSG_OsTask_Bsw_ReadWrite_AllProcess
* \archrequirement
*     ARCH_SW_BswMIf_OsTask_Bsw_ReadWrite_AllProcess;
*     ARCH_SW_BswMIf_ptrrFeeServicesBswMIf_Fee_MainFunction_OsTask_Bsw_ReadWrite_AllProcess;
*     ARCH_SW_BswMIf_ptrrFlsServicesBswMIf_Fls_MainFunction_OsTask_Bsw_ReadWrite_AllProcess;
*     ARCH_SW_BswMIf_ptrrNvMServicesBswMIf_NvM_MainFunction_OsTask_Bsw_ReadWrite_AllProcess;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_WaitEvent_OsTask_Bsw_ReadWrite_AllProcess;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_ClearEvent_OsTask_Bsw_ReadWrite_AllProcess;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_SuspendAllInterrupts_OsTask_Bsw_ReadWrite_AllProcess;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_ResumeAllInterrupts_OsTask_Bsw_ReadWrite_AllProcess;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_TerminateTask_OsTask_Bsw_ReadWrite_AllProcess;
*     ARCH_SW_BswMIf_ptrrOsServicesBswMIf_SetEvent_OsTask_Bsw_ReadWrite_AllProcess;
**/
TASK(OsTask_Bsw_ReadWrite_AllProcess)
{
   while (KU8_FALSE == bswmif_u8IsReadWriteAllProcessFinished)
   {
      (void)WaitEvent(OsEvent_ReadWriteAllProcess);
      (void)ClearEvent(OsEvent_ReadWriteAllProcess);

      SuspendAllInterrupts();
      NvM_MainFunction();
      Fee_MainFunction();
      Fls_MainFunction();

      if (KU8_FALSE == bswmif_u8IsReadWriteAllEndNotificationSet)
      {
         ResumeAllInterrupts();
         /* Request to continue fastening process */
         (void)SetEvent(OsTask_Bsw_ReadWrite_AllProcess, OsEvent_ReadWriteAllProcess);
      }
      else
      {
         ResumeAllInterrupts();
         bswmif_u8IsReadWriteAllProcessFinished = KU8_TRUE;
         bswmif_u8RestoreNvmBlockSM = KU8_BSWM_NVM_READ_ALL_PERFORMED;
      }
   }

   /* Reset the value of the synchronization variables for the next call (WriteAll) */
   bswmif_u8IsReadWriteAllProcessFinished = KU8_FALSE;
   bswmif_u8IsReadWriteAllEndNotificationSet = KU8_FALSE;

   /* All the block have been correctly managed, so terminate the task */
   (void)TerminateTask();
} 
/**
* \brief
*     This task is a cyclic task used in Gliwa measurement process.
* \dynamicaspectcaller
*     Cyclic task called by OS.
* \dynamicaspectdescription
*     Called when OsTask_AppIdle task is activated.
* \archrequirement
*     ARCH_SW_BswMIf_OsTask_AppIdle;
**/
#ifndef GLIWA_DISABLE
TASK(OsTask_AppIdle)
{
   while(1)
   {
      if(B_TRUE == NVP_Gliwa_Enable)
      {
         (void)T1_AppBackgroundHandler();
      }
   }
}
#endif
#define BswMIf_STOP_SEC_CODE
#include "BswMIf_MemMap.h"

#define BswMIf_START_SEC_CODE_ASIL_A
#include <BswMIf_MemMap.h>
/**
* \brief
*     This service is a callout called when one of the next transitions is validated:
*     - RUN from WAKE-UP 
*     - AUTONOMOUS RUN from LOW POWER
*     - RUN from LOW POWER
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_EcuState_RequestPort == "BSWM_WAKEUP_MODE_ACTIVE";
*     OR
*     BswM_ExternalWakeup_RequestPort == "BSWM_PASSANGER_OCCUPANCY_DETECTED";
*     BswM_EcuState_RequestPort == "BSWM_LOW_PWR_MODE_ACTIVE";
*     BswM_WakeupType_RequestPort == "BSWM_ACTIVE_WAKEUP_REQ";
*     OR
*     BswM_EcuState_RequestPort == "BSWM_LOW_PWR_MODE_ACTIVE";
*     BswM_WakeupType_RequestPort == "BSWM_PASSIVE_WAKEUP_REQ";
* \ddesignrequirement
*     DSG_BswM_OnRunFromSafeState
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnRunFromSafeState;
*     ARCH_SW_BswMIf_psrFsmSolenoidReqBswMIf_BswM_OnRunFromSafeState;
**/

EXPORTED void BswM_OnRunFromSafeState(void)
{
   uint8 u8counter = KU8_ZERO;
   u8eCSDiagReqType au8LastSolenoidRequest[KU8_MAX_SOLENOID_NB];
   u8eCSDiagReqType au8LastSolenoidRequestComplement[KU8_MAX_SOLENOID_NB];
   u8eCSDiagReqType au8SolenoidRequest[KU8_MAX_SOLENOID_NB];
   u8eCSDiagReqType au8SolenoidRequestComplement[KU8_MAX_SOLENOID_NB];

   (void)Rte_Read_CIL_SAD_au8DiagReq_prrEcsDiagRequest(au8LastSolenoidRequest);
   (void)Rte_Read_CIL_SAD_au8DiagReqComplement_prrEcsDiagRequest(au8LastSolenoidRequestComplement);

   /* Unlock all actuators */
   for (u8counter = KU8_ZERO; u8counter < KU8_MAX_SOLENOID_NB; u8counter++)
   {
      /* Check the integrity of the diag request data and if the request is not
       * a Diagnostic profile */
      if((KU8_MAX == (au8LastSolenoidRequest[u8counter] ^ au8LastSolenoidRequestComplement[u8counter])) &&
         (KU8_DIAG_PROFILE_REQUEST_ON != au8LastSolenoidRequest[u8counter]))
      {
         au8SolenoidRequest[u8counter] = KU8_NO_DIAG_REQUEST;
         au8SolenoidRequestComplement[u8counter] = ~((uint8)KU8_NO_DIAG_REQUEST);
      }
      else
      {
         /* Keep the last request */
         au8SolenoidRequest[u8counter] = au8LastSolenoidRequest[u8counter];
         au8SolenoidRequestComplement[u8counter] = au8LastSolenoidRequestComplement[u8counter];
      }
   }

   (void)Rte_Write_BswMIf_psrFsmSolenoidReqBswMIf_au8DiagReq(au8SolenoidRequest);
   (void)Rte_Write_BswMIf_psrFsmSolenoidReqBswMIf_au8DiagReqComplement(au8SolenoidRequestComplement);
}

/**
* \brief
*     This service is a callout called when a LOW POWER from POST RUN 
*     transition is validated and ECU manage his safe state.
* \dynamicaspectcaller
*     Tresos-configured BswM Rule.
* \dynamicaspectdescription
*     Called when next conditions are fullfiled:
*     BswM_EcuState_RequestPort == "BSWM_LOW_PWR_MODE_REQUESTED"
* \constrains
*     Ecu must be in POST RUN State and LOW POWER mode was requested
*     (no passenger occupancy or bus activity was detected during
*     TPostRun seconds)
* \ddesignrequirement
*     DSG_BswM_OnSafeStateFromPostRun
* \archrequirement
*     ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnSafeStateFromPostRun;
*     ARCH_SW_BswMIf_psrFsmSolenoidReqBswMIf_BswM_OnSafeStateFromPostRun
**/
EXPORTED void BswM_OnSafeStateFromPostRun(void)
{
   uint8 u8counter = KU8_ZERO;
   u8eCSDiagReqType au8SolenoidRequest[KU8_MAX_SOLENOID_NB];
   u8eCSDiagReqType au8SolenoidRequestComplement[KU8_MAX_SOLENOID_NB];

   /* Lock all actuators */
   for(u8counter = KU8_ZERO; u8counter < KU8_MAX_SOLENOID_NB; u8counter++)
   {
      au8SolenoidRequest[u8counter] = KU8_LOCK_DIAG_REQUEST;
      au8SolenoidRequestComplement[u8counter] = ~((uint8)KU8_LOCK_DIAG_REQUEST);
   }

   (void)Rte_Write_BswMIf_psrFsmSolenoidReqBswMIf_au8DiagReq(au8SolenoidRequest);
   (void)Rte_Write_BswMIf_psrFsmSolenoidReqBswMIf_au8DiagReqComplement(au8SolenoidRequestComplement);
}
#define BswMIf_STOP_SEC_CODE_ASIL_A
#include <BswMIf_MemMap.h>
/******************************************************************************
End Of File
*****************************************************************************/
