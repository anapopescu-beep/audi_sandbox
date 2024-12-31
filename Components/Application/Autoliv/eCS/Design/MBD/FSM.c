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
$Revision: 1.1 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/eCS/Design/MBD/project.pj $
*/

/*!****************************************************************************

@details
   The purpose of this module is to handle the state of the solenoids based on
   signals, events and diagnostic requests.

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
 *\brief
 *      Specify that the self-test for solenoid not blocked is not requested.
 */
#define KU8_FSM_NO_SELF_TEST_REQ                ((uint8)  0)
/**
 *\brief
 *      Specify that the self-test for solenoid not blocked is requested.
 */
#define KU8_FSM_SELF_TEST_REQ                   ((uint8)  1)
/**
 *\brief
 *      Specify that the self-test for solenoid not blocked is completed.
 */
#define KU8_FSM_SELF_TEST_COMPLETED             ((uint8)  1)
/**
 *\brief
 *      Specify that the self-test for solenoid not blocked is not completed.
 */
#define KU8_FSM_SELF_TEST_NOT_COMPLETED         ((uint8)  0xFF)

/**
 *\brief
 *      Indicates the position of the option byte from the step description.
 */
#define KU8_FSM_INDEX_OF_OPTION_BYTE         ((uint8) 6)

/**
 *\brief
 *      Indicate the byte index of the first step of a profile.
 */
#define KU8_FSM_INDEX_OF_FIRST_STEP             ((uint8)  4)
/**
 *\brief
 *      Indicate the size in bytes of a seat belt profile.
 */
#define KU8_FSM_PROFILE_SIZE                    ((uint8) 12)
/**
 *\brief
 *      Indicate the size in bytes of a step.
 */
#define KU8_FSM_STEP_SIZE                       ((uint8)  7)

/**
 *\brief
 *      Indicate there is no used step for the profile.
 */
#define KU8_FSM_NO_STEP                         ((uint8) 0xFF)

/**
 *\brief
 *      Sub-System state used in Backup profile management
 *      for locking state.
 */
#define KU8_FSM_BACKUP_LOCK_SUBSTATE            ((uint8) KU8_LOCK_STATE)

/**
 *\brief
 *      Sub-System state used in Backup profile management for the backup state.
 */
#define KU8_FSM_BACKUP_SUBSTATE                 ((uint8) KU8_BACKUP_STATE)

/**
 *\brief
 *      Sub-System state used in Backup profile management if solenoid unlock was confirmed.
 */
#define KU8_FSM_BACKUP_CONFIRMED_SUBSTATE       ((uint8) 0x03)

/**
 *\brief
 *      Indicate the number of repeated backups that can
 *      be done before qualifying the error.
 */
#define KU8_FSM_NB_OF_BACKUPS                   ((uint8) NVP_u8NbOfBackups)

/**
 *\brief
 *      Indicate the duration expressed in milliseconds(multiple of 1ms) used to
 *      execute the Lock profile before running the startup sequence.
 */
#define KU16_FSM_STARTUP_LOCK_TIMEOUT_OFFSET    ((uint16) NVP_u16StartupLockTimeout)

/**
 *\brief
 *      Timeout offset expressed in milliseconds (multiple of 1ms) used to
 *      confirm the unlock action.
 */
#define KU16_FSM_UNLOCK_CONFIRMATION_TIMEOUT_OFFSET                  ((uint16) NVP_u16UnlockConfirmationTimeout)

/**
 *\brief
 *      Timeout offset expressed in milliseconds (multiple of 1ms) applied
 *      on detecting unlocking action time.
 */
#define KU16_FSM_UNLOCK_DETECTION_TIMEOUT_OFFSET                     ((uint16) NVP_u16UnlockDetectionTimeout)

/**
 *\brief
 *      Timing OFFSET (multiple of 1ms) used in
 *      repeating cyclic  backup profile. *
 */
#define KU16_FSM_REPEAT_PROFILE_TIMEOUT                              ((uint16) NVP_u16RepeatProfileTimeout)

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL uint8 fsm_GetDiagRequest(const uint8 ku8SolenoidId);
LOCAL uint8 fsm_CheckStartupSelfTest(const uint8 ku8SolenoidId);
LOCAL void fsm_RunSolenoidStateManagement(const uint8 ku8SolenoidId);
LOCAL void fsm_RunStartupSequence(const uint8 ku8SolenoidId);
LOCAL void fsm_RunBackupProfile(const uint8 ku8SolenoidId);
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define FSM_START_SEC_VAR_INIT_BOOL_ASIL_A
#include "FSM_MemMap.h"
/**
 * \brief
 *       Used to store each solenoid's state flag, which represents if the
 *       timeout interval for detecting unlock was reached.
 *
 * \initialization
 *       KB_FALSE (boolean 0).
 *
 * \range
 *       KB_FALSE, KB_TRUE.
 *
 */
LOCAL boolean fsm_ab8UnlockTimeout[KU8_MAX_SOLENOID_NB] =
{
   KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE
};

#define FSM_STOP_SEC_VAR_INIT_BOOL_ASIL_A
#include "FSM_MemMap.h"

#define FSM_START_SEC_VAR_INIT_8_ASIL_A
#include "FSM_MemMap.h"
 /**
 * \brief
 *       Used to store each solenoid's unlock confirmation status.
 *
 * \initialization
 *       KU8_FALSE (uint8 0x55).
 *
 * \range
 *       KU8_FALSE, KU8_TRUE
 */
LOCAL uint8 fsm_au8SolenoidConfirmationModeStatus[KU8_MAX_SOLENOID_NB] =
{
   KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE
};

/**
 * \brief
 *       Used to store each solenoid's startup state.
 *
 * \initialization
 *       FSM_KU8_SELF_TEST_NOT_COMPLETED (uint8 0xFF).
 *
 * \range
 *       FSM_KU8_SELF_TEST_NOT_COMPLETED, FSM_KU8_SELF_TEST_COMPLETED
 *
 */
LOCAL uint8 fsm_au8StartupCompleted[KU8_MAX_SOLENOID_NB] =
{
   KU8_FSM_SELF_TEST_NOT_COMPLETED, KU8_FSM_SELF_TEST_NOT_COMPLETED, KU8_FSM_SELF_TEST_NOT_COMPLETED, 
   KU8_FSM_SELF_TEST_NOT_COMPLETED, KU8_FSM_SELF_TEST_NOT_COMPLETED, KU8_FSM_SELF_TEST_NOT_COMPLETED
};

/**
 * \brief
 *       Used to store each solenoid's number of backups in case unlock is
 *       not detected.
 *
 * \initialization KU8_ZERO (uint8 0x00).
 *
 * \range
 *       0...3
 */
LOCAL uint8 fsm_au8BackupNbOfRetrys[KU8_MAX_SOLENOID_NB] =
{
   KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO
};

/**
 * \brief
 *       The array is used to store the state machine of the backup profile
 *       logic execution of each solenoid.
 *
 * \initialization
 *       FSM_KU8_BACKUP_LOCK_SUBSTATE (uint8 0x00).
 *
 * \range
 *    FSM_KU8_BACKUP_LOCK_SUBSTATE, FSM_KU8_BACKUP_SUBSTATE
 *
 */
LOCAL uint8 fsm_au8BackupStateSM[KU8_MAX_SOLENOID_NB] =
{
   KU8_FSM_BACKUP_LOCK_SUBSTATE, KU8_FSM_BACKUP_LOCK_SUBSTATE, KU8_FSM_BACKUP_LOCK_SUBSTATE,
   KU8_FSM_BACKUP_LOCK_SUBSTATE, KU8_FSM_BACKUP_LOCK_SUBSTATE, KU8_FSM_BACKUP_LOCK_SUBSTATE
};

/**
 * \brief
 *       The array is used to store the state machine of each solenoid.
 *
 * \initialization
 *       KU8_PROFILE_NONE (255U).
 *
 * \range
 *       KU8_PROFILE_UNLOCK, KU8_PROFILE_BACKUP, KU8_PROFILE_NONE
 *
 */
LOCAL uint8 fsm_au8FsmSelectedProfiles[KU8_MAX_SOLENOID_NB] =
{
   KU8_PROFILE_NONE, KU8_PROFILE_NONE, KU8_PROFILE_NONE,
   KU8_PROFILE_NONE, KU8_PROFILE_NONE, KU8_PROFILE_NONE
};

/**
 * \brief
 *       The array is used to store the last diagnostic request.
 *
 * \initialization
 *       KU8_NO_DIAG_REQUEST_COMPLEMENT (255U).
 *
 * \range
 *       KU8_NO_DIAG_REQUEST, KU8_UNLOCK_DIAG_REQUEST, KU8_LOCK_DIAG_REQUEST,
 *       KU8_DIAG_PROFILE_REQUEST_ON, KU8_DIAG_PROFILE_REQUEST_OFF
 *
 */
LOCAL uint8 fsm_au8LastDiagRequest[KU8_MAX_SOLENOID_NB] =
{
      KU8_NO_DIAG_REQUEST_COMPLEMENT, KU8_NO_DIAG_REQUEST_COMPLEMENT, KU8_NO_DIAG_REQUEST_COMPLEMENT,
      KU8_NO_DIAG_REQUEST_COMPLEMENT, KU8_NO_DIAG_REQUEST_COMPLEMENT, KU8_NO_DIAG_REQUEST_COMPLEMENT
};

#define FSM_STOP_SEC_VAR_INIT_8_ASIL_A
#include "FSM_MemMap.h"

#define FSM_START_SEC_VAR_INIT_16_ASIL_A
#include "FSM_MemMap.h"
/**
 * \brief
 *       The array is used to store the counter value of solenoids before
 *       qualifying the unlock confirmation timeout flag. One unit expressed
 *       in milliseconds (multiple of 1ms).
 *
 * \initialization
 *       KU16_ZERO (uint16 0).
 *
 * \range
 *       0...65535
 */
LOCAL uint16 fsm_au16UnlockConfirmTimeout[KU8_MAX_SOLENOID_NB] =
{
   KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};

/**
 * \brief
 *       The array is used to store the value of the counter which represents
 *       the time delay between two consecutive backup profiles of each solenoid.
 *       One unit expressed in milliseconds (multiple of 1ms).
 *
 * \initialization
 *       KU16_ZERO (uint16 0).
 *
 * \range
 *       0...65535
 */
LOCAL uint16 fsm_au16RepeatProfileDelay[KU8_MAX_SOLENOID_NB] =
{
   KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};

/**
 * \brief
 *       The array is used to store the value of the counter which represents
 *       the time value (multiple of 1ms) of the execution LOCK profile before
 *       starting the startup sequence.
 *
 * \initialization
 *       KU16_ZERO (uint16 0).
 *
 * \range
 *       0...65535
 */
LOCAL uint16 fsm_au16StartupLockTimeout[KU8_MAX_SOLENOID_NB] =
{
   KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};

/**
 * \brief
 *       This variable is used to compute unlock timeout period for solenoids.
  *
 * \initialization
 *       KU16_ZERO (uint16 0).
 *
 * \range
 *       0...65535
 */
LOCAL uint16 fsm_au16ProfileTimeoutPeriod[KU8_NB_OF_PROFILES] =
{
      KU16_ZERO, KU16_ZERO, KU16_ZERO
};
#define FSM_STOP_SEC_VAR_INIT_16_ASIL_A
#include "FSM_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
#define FSM_START_SEC_VAR_INIT_8_ASIL_A
#include "FSM_MemMap.h"

EXPORTED uint8 FSM_au8SolenoidStates[KU8_MAX_SOLENOID_NB] =
{
   KU8_LOCK_STATE, KU8_LOCK_STATE, KU8_LOCK_STATE, KU8_LOCK_STATE, KU8_LOCK_STATE, KU8_LOCK_STATE
};

EXPORTED uint8 FSM_u8SolenoidInitState = KU8_ZERO;

#define FSM_STOP_SEC_VAR_INIT_8_ASIL_A
#include "FSM_MemMap.h"
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
#define FSM_START_SEC_CONST_UNSPECIFIED_ASIL_A
#include "FSM_MemMap.h"
/**
 * \brief
 *       This array holds the inhibition mask of each solenoid based on what
 *       flag to check.
 * \initialization
 *       {KU64_KU64_SOLENOID_X_ERROR_DISABLED | KU64_SOLENOID_X_CAN_INHIB_STATUS}
 *       where X - the solenoid number
 *
 * \range
 *       0...18446744073709551615
 */
LOCAL const uint64 fsm_kau64SolenoidInhibMask[KU8_MAX_SOLENOID_NB] =
{
   /* Solenoid 1 */ (KU64_SOLENOID_1_ERROR_DISABLED | KU64_ECU_CAN_INHIB_STATUS),
   /* Solenoid 2 */ (KU64_SOLENOID_2_ERROR_DISABLED | KU64_ECU_CAN_INHIB_STATUS),
   /* Solenoid 3 */ (KU64_SOLENOID_3_ERROR_DISABLED | KU64_ECU_CAN_INHIB_STATUS),
   /* Solenoid 4 */ (KU64_SOLENOID_4_ERROR_DISABLED | KU64_ECU_CAN_INHIB_STATUS),
   /* Solenoid 5 */ (KU64_SOLENOID_5_ERROR_DISABLED | KU64_ECU_CAN_INHIB_STATUS),
   /* Solenoid 6 */ (KU64_SOLENOID_6_ERROR_DISABLED | KU64_ECU_CAN_INHIB_STATUS)
};

/**
 * \brief
 *       This array holds the configuration mask of each solenoid based on what
 *       flag to check.
 * \initialization
 *       {KU64_SOLENOID_X_CONFIGURED}
 *       where X - the solenoid number
 *
 * \range
 *       0...18446744073709551615
 */
LOCAL const uint64 fsm_kau64SolenoidConfigMask[KU8_MAX_SOLENOID_NB] =
{
   /* Solenoid 1 */ (KU64_SOLENOID_1_CONFIGURED),
   /* Solenoid 2 */ (KU64_SOLENOID_2_CONFIGURED),
   /* Solenoid 3 */ (KU64_SOLENOID_3_CONFIGURED),
   /* Solenoid 4 */ (KU64_SOLENOID_4_CONFIGURED),
   /* Solenoid 5 */ (KU64_SOLENOID_5_CONFIGURED),
   /* Solenoid 6 */ (KU64_SOLENOID_6_CONFIGURED)
};

/**
 * \brief
 *       This array holds the unlock confirmation mask of each solenoid based on what
 *       flag to check.
 * \initialization
 *       {KU64_SOLENOID_X_UNLOCK_CONFIRMED}
 *       where X - the solenoid number
 *
 * \range
 *       0...18446744073709551615
 */
LOCAL const uint64 fsm_kau64SolenoidUnlockConfirmedMask[KU8_MAX_SOLENOID_NB] =
{
   /* Solenoid 1 */ (KU64_SOLENOID_1_UNLOCK_CONFIRMED),
   /* Solenoid 2 */ (KU64_SOLENOID_2_UNLOCK_CONFIRMED),
   /* Solenoid 3 */ (KU64_SOLENOID_3_UNLOCK_CONFIRMED),
   /* Solenoid 4 */ (KU64_SOLENOID_4_UNLOCK_CONFIRMED),
   /* Solenoid 5 */ (KU64_SOLENOID_5_UNLOCK_CONFIRMED),
   /* Solenoid 6 */ (KU64_SOLENOID_6_UNLOCK_CONFIRMED)
};

/**
 * \brief
 *       This array holds the buckle latch confirmation mask of each solenoid based on what
 *       flag to check.
 * \initialization
 *       {KU64_SOLENOID_X_BUCKLE_LATCHED}
 *       where X - the solenoid number
 *
 * \range
 *       0...18446744073709551615
 */
LOCAL const uint64 fsm_kau64SolenoidBuckleStatusMask[KU8_MAX_SOLENOID_NB] =
{
   /* Solenoid 1 */ (KU64_SOLENOID_1_BUCKLE_LATCHED),
   /* Solenoid 2 */ (KU64_SOLENOID_2_BUCKLE_LATCHED),
   /* Solenoid 3 */ (KU64_SOLENOID_3_BUCKLE_LATCHED),
   /* Solenoid 4 */ (KU64_SOLENOID_4_BUCKLE_LATCHED),
   /* Solenoid 5 */ (KU64_SOLENOID_5_BUCKLE_LATCHED),
   /* Solenoid 6 */ (KU64_SOLENOID_6_BUCKLE_LATCHED)
};

#define FSM_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
#include "FSM_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
#define FSM_START_SEC_CODE_ASIL_A
#include "FSM_MemMap.h"
/**
* \brief
*        Used to check if a diagnostic request was made and what profile should
*        be activated.
* \inputparam
*        Name: ku8SolenoidId;
*        Type: const uint8;
*        Description: The id of the solenoid;
*        Range: 0..5;
* \outputparam
*        None;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        Name: u8DiagSelectedProfile;
*        Type: uint8;
*        Description: Return the solenoid profile based on the diag request;
*        Range: 0, 1, 2;
* \dynamicaspectcaller
*        FSM_runMainFunction
* \dynamicaspectdescription
*        The local function is called by the function FSM_runMainFunction.
* \constraints
*        This function has no constraints.
* \ddesignrequirement
*        DSG_fsm_GetDiagRequest
* \archrequirement
*        ARCH_SW_FSM_prrEcsDiagRequest
**/
LOCAL INLINE uint8 fsm_GetDiagRequest(const uint8 ku8SolenoidId)
{
   uint8 u8DiagSelectedProfile;
   uint8 au8DiagReq[KU8_MAX_SOLENOID_NB];
   uint8 au8DiagReqComplement[KU8_MAX_SOLENOID_NB];
   
   (void)Rte_Read_prrEcsDiagRequest_ab8DiagReq(au8DiagReq);
   (void)Rte_Read_prrEcsDiagRequest_ab8DiagReqComplement(au8DiagReqComplement);

   u8DiagSelectedProfile = KU8_NO_DIAG_REQUEST;

   if(KU8_MAX == (au8DiagReq[ku8SolenoidId] ^ au8DiagReqComplement[ku8SolenoidId]))
   {
      u8DiagSelectedProfile = au8DiagReq[ku8SolenoidId];

      /* Check if the diag request was changed from Diag_Profile to mark the
       * moment when the solenoids init auto-tests were finished  */
      if((fsm_au8LastDiagRequest[ku8SolenoidId] != au8DiagReq[ku8SolenoidId]) &&
         (KU8_DIAG_PROFILE_REQUEST_ON == fsm_au8LastDiagRequest[ku8SolenoidId]))
      {
         U8_BIT_SET(FSM_u8SolenoidInitState, (uint8)(KU8_ONE << ku8SolenoidId));
      }

      fsm_au8LastDiagRequest[ku8SolenoidId] = au8DiagReq[ku8SolenoidId];

   }

   return u8DiagSelectedProfile;
}

/**
* \brief
*       Based on the buckle status for each seatbelt, returns the startup
*       sequence request of the corresponding solenoid.
* \inputparam
*       Name: ku8SolenoidId;
*       Type: const uint8;
*       Description: The id of the solenoid;
*       Range: 0..5;
* \outputparam
*       None;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       Name: u8StartupSelfTestRequest;
*       Type: uint8;
*       Description: Return the solenoid profile based on the buckle status of the
*       seat belt;
*       Range: 0, 1;
* \dynamicaspectcaller
*       FSM_runMainFunction;
* \dynamicaspectdescription
*       API called by function FSM_runMainFunction.
* \constraints
*       None;
* \ddesignrequirement
*       DSG_fsm_CheckStartupSelfTest;
* \archrequirement
*       ARCH_SW_FSM_prrEcsAlgoFlag;
**/
LOCAL INLINE uint8 fsm_CheckStartupSelfTest(const uint8 ku8SolenoidId)
{
   uint8 u8BuckleStatus;
   uint8 u8InitPhaseInProgress;
   register uint8 u8StartupSelfTestRequest;

   u8StartupSelfTestRequest = KU8_FSM_NO_SELF_TEST_REQ;

   FSM_runCheckModeStatus(fsm_kau64SolenoidBuckleStatusMask[ku8SolenoidId], &u8BuckleStatus);
   FSM_runCheckModeStatus(KU64_INIT_PHASE_IN_PROGRESS, &u8InitPhaseInProgress);
   
   /* Check if:
    * • The buckle is latched;
    * • The startup sequence never executed before;
    * • The init phase was finished */
   if ((KU8_TRUE == u8BuckleStatus) &&
       (KU8_FSM_SELF_TEST_NOT_COMPLETED == fsm_au8StartupCompleted[ku8SolenoidId]) &&
       (KU8_FALSE == u8InitPhaseInProgress))
   {
      u8StartupSelfTestRequest = KU8_FSM_SELF_TEST_REQ;
   }
   else if (KU8_FALSE == u8BuckleStatus)
   {
      fsm_au8StartupCompleted[ku8SolenoidId] = KU8_FSM_SELF_TEST_NOT_COMPLETED;
      u8StartupSelfTestRequest = KU8_FSM_NO_SELF_TEST_REQ;
   }
   else
   {
      u8StartupSelfTestRequest = KU8_FSM_NO_SELF_TEST_REQ;
   }
   return u8StartupSelfTestRequest;
}

/**
* \brief
*       The function used to determine the next profile of the solenoid.
* \inputparam
*       Name: ku8SolenoidId;
*       Type: const uint8;
*       Description: The id of the solenoid;
*       Range: 0..5;
* \outputparam
*       None;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       FSM_runMainFunction
* \dynamicaspectdescription
*       The function is called by FSM_runMainFunction.
* \constraints
*       Called from FSM_runMainFunction at each 1ms.
* \ddesignrequirement
*       DSG_fsm_RunSolenoidStateManagement
* \archrequirement
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction
*       ARCH_SW_FSM_prrEcsAlgoFlag;
**/
LOCAL INLINE void fsm_RunSolenoidStateManagement(const uint8 ku8SolenoidId)
{
   b8EcsTriggerType b8EcsFlag;
   uint8 u8ModeInhibStatusResult;
   uint8 u8ModeConfigStatusResult;
   uint8 au8DiagReq[KU8_MAX_SOLENOID_NB] =
   {
      KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST,
      KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST
   };
   uint8 au8SolenoidStartUpSeqRequest[KU8_MAX_SOLENOID_NB] =
   {
      KU8_FSM_NO_SELF_TEST_REQ, KU8_FSM_NO_SELF_TEST_REQ, KU8_FSM_NO_SELF_TEST_REQ,
      KU8_FSM_NO_SELF_TEST_REQ, KU8_FSM_NO_SELF_TEST_REQ, KU8_FSM_NO_SELF_TEST_REQ
   };

   (void)Rte_Read_prrEcsAlgoFlag_b8EcsFlag(&b8EcsFlag);

   FSM_runCheckModeStatus(fsm_kau64SolenoidUnlockConfirmedMask[ku8SolenoidId], &fsm_au8SolenoidConfirmationModeStatus[ku8SolenoidId]);
   FSM_runCheckModeStatus(fsm_kau64SolenoidInhibMask[ku8SolenoidId], &u8ModeInhibStatusResult);
   FSM_runCheckModeStatus(fsm_kau64SolenoidConfigMask[ku8SolenoidId], &u8ModeConfigStatusResult);

   /* If an Inhibition condition is present or The solenoid is not configured */
   if ((KU8_TRUE == u8ModeInhibStatusResult) || (KU8_FALSE == u8ModeConfigStatusResult))
   {
      FSM_au8SolenoidStates[ku8SolenoidId] = KU8_DISABLED_STATE;
      fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
      fsm_au16RepeatProfileDelay[ku8SolenoidId] = KU16_ZERO;
      fsm_au16UnlockConfirmTimeout[ku8SolenoidId] = KU16_ZERO;
   }
   else
   {
      au8DiagReq[ku8SolenoidId] = fsm_GetDiagRequest(ku8SolenoidId);

      if(KU8_DIAG_PROFILE_REQUEST_ON == au8DiagReq[ku8SolenoidId])
      {
         FSM_au8SolenoidStates[ku8SolenoidId] = KU8_DIAGNOSTIC_STATE;
      }
      else
      {
         au8SolenoidStartUpSeqRequest[ku8SolenoidId] = fsm_CheckStartupSelfTest(ku8SolenoidId);
         /* Perform lock solenoid if:
                  • eCS_Algo set to lock
                  • The diagnostic request is lock or it doesn't exist
                  • No buckle was perform
          */
         if (((KB8_ECS_ALGO_LOCK == b8EcsFlag) || (KU8_LOCK_DIAG_REQUEST == au8DiagReq[ku8SolenoidId])) &&
              (KU8_UNLOCK_DIAG_REQUEST != au8DiagReq[ku8SolenoidId]) &&
              (KU8_FSM_NO_SELF_TEST_REQ == au8SolenoidStartUpSeqRequest[ku8SolenoidId])
            )
         {
            FSM_au8SolenoidStates[ku8SolenoidId] = KU8_LOCK_STATE;
            fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
            fsm_au16RepeatProfileDelay[ku8SolenoidId] = KU16_ZERO;
            fsm_au16UnlockConfirmTimeout[ku8SolenoidId] = KU16_ZERO;
         }
         else
         {
            if (KUB_eCS_BACK_UP_PROFILE_VARIANT)
            {
               /* Perform unlock solenoid if:
                • Received a diagnostic request;
                • The timeout for unlock detection was not reached;
                • No backup or self-test was required.
               */
               if ((KU8_UNLOCK_DIAG_REQUEST == au8DiagReq[ku8SolenoidId]) &&
                   (KB_FALSE == fsm_ab8UnlockTimeout[ku8SolenoidId]) &&
                   (KU8_BACKUP_STATE != FSM_au8SolenoidStates[ku8SolenoidId]) &&
                   (KU8_FSM_NO_SELF_TEST_REQ == au8SolenoidStartUpSeqRequest[ku8SolenoidId])
                  )
               {
                  FSM_au8SolenoidStates[ku8SolenoidId] = KU8_UNLOCK_STATE;
                  fsm_au8BackupNbOfRetrys[ku8SolenoidId] = KU8_ZERO;
                  fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
                  fsm_au16RepeatProfileDelay[ku8SolenoidId] = KU16_ZERO;
               }
               /* Perform unlock solenoid if:
                • Received a diagnostic request;
                • No backup or self-test was required.
               */
               else if ((KU8_FSM_SELF_TEST_REQ == au8SolenoidStartUpSeqRequest[ku8SolenoidId]) &&
                        ((KU8_STARTUP_STATE != FSM_au8SolenoidStates[ku8SolenoidId]) && (KU8_BACKUP_STATE != FSM_au8SolenoidStates[ku8SolenoidId])))
               {
                  FSM_au8SolenoidStates[ku8SolenoidId] = KU8_STARTUP_STATE;
                  fsm_au8BackupNbOfRetrys[ku8SolenoidId] = KU8_ZERO;
                  fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
                  fsm_au16RepeatProfileDelay[ku8SolenoidId] = KU16_ZERO;
                  fsm_au16StartupLockTimeout[ku8SolenoidId] = KU16_ZERO;
               }
               /* Perform backup state if:
                • The unlock detection is not confirmed and the timeout for detection expired;
                • The backup state already running.
               */
               else if ((KU8_FALSE == fsm_au8SolenoidConfirmationModeStatus[ku8SolenoidId]) &&
                     ((KB_TRUE == fsm_ab8UnlockTimeout[ku8SolenoidId]) || (KU8_BACKUP_STATE == FSM_au8SolenoidStates[ku8SolenoidId])))
               {
                  FSM_au8SolenoidStates[ku8SolenoidId] = KU8_BACKUP_STATE;
               }
               /* At the end of the unlock state, based on the request's source,
                        continue to maintain the current profile. or run other profile. */
               else
               {
                  if(KU8_FSM_SELF_TEST_REQ == au8SolenoidStartUpSeqRequest[ku8SolenoidId])
                  {
                     FSM_au8SolenoidStates[ku8SolenoidId] = KU8_STARTUP_STATE;
                  }
                  else if(KU8_BACKUP_STATE == FSM_au8SolenoidStates[ku8SolenoidId])
                  {
                     FSM_au8SolenoidStates[ku8SolenoidId] = KU8_BACKUP_STATE;
                  }
                  else
                  {
                     FSM_au8SolenoidStates[ku8SolenoidId] = KU8_UNLOCK_STATE;
                     fsm_au8BackupNbOfRetrys[ku8SolenoidId] = KU8_ZERO;
                     fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
                     fsm_au16RepeatProfileDelay[ku8SolenoidId] = KU16_ZERO;
                  }
               }
            }
            else
            {
               FSM_au8SolenoidStates[ku8SolenoidId] = KU8_UNLOCK_STATE;

               if (KU8_FSM_SELF_TEST_REQ == au8SolenoidStartUpSeqRequest[ku8SolenoidId])
               {
                  fsm_au8StartupCompleted[ku8SolenoidId] = KU8_FSM_SELF_TEST_COMPLETED;
               }
            }
         }
      }
   }
}


/**
* \brief
*       The function used to control the Startup logic of each solenoid.
* \inputparam
*       Name: ku8SolenoidId;
*       Type: const uint8;
*       Description: The id of the solenoid;
*       Range: 0..5;
* \outputparam
*       None;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       FSM_runMainFunction
* \dynamicaspectdescription
*       The function is called by FSM_runMainFunction.
* \constraints
*       Called when the ECU detects the buckle action.
* \ddesignrequirement
*       DSG_fsm_RunStartupSequence
* \archrequirement
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction;
**/
LOCAL INLINE void fsm_RunStartupSequence(const uint8 ku8SolenoidId)
{

   if (fsm_au16StartupLockTimeout[ku8SolenoidId] < KU16_FSM_STARTUP_LOCK_TIMEOUT_OFFSET)
   {
      fsm_au8FsmSelectedProfiles[ku8SolenoidId] = KU8_PROFILE_NONE;
      fsm_au16UnlockConfirmTimeout[ku8SolenoidId] = KU16_ZERO;
      fsm_ab8UnlockTimeout[ku8SolenoidId] = KB_FALSE;
      fsm_au16StartupLockTimeout[ku8SolenoidId] += KU16_TWO;
   }
   else if ((KU8_FALSE == fsm_au8SolenoidConfirmationModeStatus[ku8SolenoidId]) &&
            (KB_FALSE == fsm_ab8UnlockTimeout[ku8SolenoidId]))
   {
      fsm_au16StartupLockTimeout[ku8SolenoidId] = KU16_FSM_STARTUP_LOCK_TIMEOUT_OFFSET;
      fsm_au8FsmSelectedProfiles[ku8SolenoidId] = KU8_PROFILE_UNLOCK;
   }
   else
   {
      fsm_au8StartupCompleted[ku8SolenoidId] = KU8_FSM_SELF_TEST_COMPLETED;
   }
}

/**
* \brief
*       The function used to control the Backup logic of each solenoid.
* \inputparam
*       Name: ku8SolenoidId;
*       Type: const uint8;
*       Description: The id of the solenoid;
*       Range: 0..5;
* \outputparam
*       None;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       FSM_runMainFunction
* \dynamicaspectdescription
*       The function is called by FSM_runMainFunction.
* \constraints
*       Called when the unlock action is not detected.
* \ddesignrequirement
*       DSG_fsm_RunBackupProfile
* \archrequirement
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction;
**/
LOCAL INLINE void fsm_RunBackupProfile(const uint8 ku8SolenoidId)
{
   switch (fsm_au8BackupStateSM[ku8SolenoidId])
   {
      case KU8_FSM_BACKUP_LOCK_SUBSTATE:
      {
         if (fsm_au8BackupNbOfRetrys[ku8SolenoidId] < KU8_FSM_NB_OF_BACKUPS)
         {
            if(fsm_au16RepeatProfileDelay[ku8SolenoidId] < KU16_FSM_REPEAT_PROFILE_TIMEOUT)
            {
               fsm_au8FsmSelectedProfiles[ku8SolenoidId] = KU8_PROFILE_NONE;
               fsm_ab8UnlockTimeout[ku8SolenoidId] = KB_FALSE;
               fsm_au16UnlockConfirmTimeout[ku8SolenoidId] = KU16_ZERO;
               fsm_au16RepeatProfileDelay[ku8SolenoidId] += KU16_TWO;
            }
            else
            {
               fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_SUBSTATE;
               fsm_au16RepeatProfileDelay[ku8SolenoidId] = KU16_ZERO;
            }
         }
         else
         {
            fsm_au8FsmSelectedProfiles[ku8SolenoidId] = KU8_PROFILE_BACKUP;
            fsm_au8StartupCompleted[ku8SolenoidId] = KU8_FSM_SELF_TEST_COMPLETED;
         }
         break;
      }
      case KU8_FSM_BACKUP_SUBSTATE:
      {
         fsm_au8FsmSelectedProfiles[ku8SolenoidId] = KU8_PROFILE_BACKUP;

         if (KB_TRUE == fsm_ab8UnlockTimeout[ku8SolenoidId])
         {
            fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
            fsm_au8BackupNbOfRetrys[ku8SolenoidId]++;
         }
         else if(KU8_TRUE == fsm_au8SolenoidConfirmationModeStatus[ku8SolenoidId])
         {
            fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_CONFIRMED_SUBSTATE;
         }
         else
         {
            /* Do nothing */
         }
         break;
      }
      case KU8_FSM_BACKUP_CONFIRMED_SUBSTATE:
      {
         /* Keep the backup state active */
         fsm_au8FsmSelectedProfiles[ku8SolenoidId] = KU8_PROFILE_BACKUP;
         break;
      }
      default:
      {
         fsm_au8FsmSelectedProfiles[ku8SolenoidId] = KU8_PROFILE_NONE;
         break;
      }
   }
}

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/**
* \brief
*       The function is used to calculate the unlocking timeout period
*       and initialize variables.
* \inputparam
*       None;
* \outputparam
*       None;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       EcuM_DefaultInitListOne
* \dynamicaspectdescription
*       API called in EcuM_DefaultInitListOne at the initialization phase.
* \constraints
*       Called during the initialization phase.
* \ddesignrequirement
*       DSG_FSM_Init
* \archrequirement
*       ARCH_SW_Fsm_ptrpFsmServicesBswMIf_FSM_Init
**/
EXPORTED void FSM_Init(void)
{
   uint8 u8Idx;
   uint8 u8Response;

   FSM_runCalculateProfileTimeout(&u8Response);

   for (u8Idx = KU8_ZERO; u8Idx < KU8_MAX_SOLENOID_NB; u8Idx++)
   {
      fsm_ab8UnlockTimeout[u8Idx] = KB_FALSE;
      FSM_au8SolenoidStates[u8Idx] = KU8_LOCK_STATE;
      fsm_au8SolenoidConfirmationModeStatus[u8Idx] = KU8_FALSE;
      fsm_au8BackupNbOfRetrys[u8Idx] = KU8_ZERO;
      fsm_au8StartupCompleted[u8Idx] = KU8_FSM_SELF_TEST_NOT_COMPLETED;
      fsm_au8BackupStateSM[u8Idx] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
      fsm_au8FsmSelectedProfiles[u8Idx] = KU8_PROFILE_NONE;
      fsm_au16UnlockConfirmTimeout[u8Idx] = KU16_ZERO;
      fsm_au16RepeatProfileDelay[u8Idx] = KU16_ZERO;
      fsm_au16StartupLockTimeout[u8Idx] = KU16_ZERO;
   }
}

/**
* \brief
*       The function used to control the state machine of each used solenoid.
* \inputparam
*       None;
* \outputparam
*       None;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       OsTask_Alv_eCS_App
* \dynamicaspectdescription
*       API called in OsTask_Alv_eCS_App.
* \constraints
*       Called from OsTask_Alv_eCS_App at each 1ms
* \ddesignrequirement
*       DSG_FSM_runMainFunction
* \archrequirement
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction_Start
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction_DIagnostic
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction_Startup
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction_Lock
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction_Unlock
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction_Backup
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction_Disable
*       ARCH_SW_FSM_psrSolenoidProfile_FSM_runMainFunction
*       ARCH_SW_FSM_psrSolenoidState_FSM_runMainFunction
*       ARCH_SW_FSM_psrSolenoidNbOfBackups_FSM_runMainFunction
**/
EXPORTED void FSM_runMainFunction(void)
{

   register uint8 u8Index;

   for (u8Index = KU8_ZERO; u8Index < KU8_MAX_SOLENOID_NB; u8Index++)
   {
      fsm_RunSolenoidStateManagement(u8Index);

      switch (FSM_au8SolenoidStates[u8Index])
      {
         case KU8_LOCK_STATE:
         {
            fsm_au8FsmSelectedProfiles[u8Index] = KU8_PROFILE_NONE;
            fsm_ab8UnlockTimeout[u8Index] = KB_FALSE;
            fsm_au16UnlockConfirmTimeout[u8Index] = KU16_ZERO;
            break;
         }
         case KU8_UNLOCK_STATE:
         {
            fsm_au8FsmSelectedProfiles[u8Index] = KU8_PROFILE_UNLOCK;
            break;
         }
         case KU8_BACKUP_STATE:
         {
            fsm_RunBackupProfile(u8Index);
            break;
         }
         case KU8_STARTUP_STATE:
         {
            fsm_RunStartupSequence(u8Index);
            break;
         }
         case KU8_DIAGNOSTIC_STATE:
         {
            fsm_au8FsmSelectedProfiles[u8Index] = KU8_PROFILE_DIAGNOSTIC;
            break;
         }
         default:
         {
            fsm_au8FsmSelectedProfiles[u8Index] = KU8_PROFILE_NONE;
            break;
         }
      }

      if((KU8_PROFILE_NONE != fsm_au8FsmSelectedProfiles[u8Index]) &&
         (KU8_PROFILE_DIAGNOSTIC != fsm_au8FsmSelectedProfiles[u8Index]))
      {
         if((fsm_au16UnlockConfirmTimeout[u8Index] < fsm_au16ProfileTimeoutPeriod[fsm_au8FsmSelectedProfiles[u8Index]]) &&
               (KU8_FALSE == fsm_au8SolenoidConfirmationModeStatus[u8Index]))
         {
            fsm_au16UnlockConfirmTimeout[u8Index] += KU16_TWO;
         }
         else if (fsm_au16UnlockConfirmTimeout[u8Index] >= fsm_au16ProfileTimeoutPeriod[fsm_au8FsmSelectedProfiles[u8Index]])
         {
            fsm_ab8UnlockTimeout[u8Index] = KB_TRUE;
         }
         else
         {
            /* Do nothing */
         }
      }
   }

   (void)Rte_Write_psrSolenoidProfile_au8SelectedProfile((const uint8 *)fsm_au8FsmSelectedProfiles);
   (void)Rte_Write_psrSolenoidState_au8SolenoidState((const uint8 *)FSM_au8SolenoidStates);
   (void)Rte_Write_psrSolenoidNbOfBackups_au8SolenoidNbOfBackups((const uint8 *)fsm_au8BackupNbOfRetrys);
   
   FSM_manageSolenoidCounters();
}

/**
* \brief
*       The function is used to return the value of the calculated unlocking
*       timeout period.
* \inputparam
*       None
* \outputparam
*       Name: pu16UnlockDetectionTimeoutPeriod;
*       Type: uint16 *;
*       Description: Outputs the unlock detection timeout period;
*       Range: 0...65535;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       Called from IoHwAb_DetectVoltageFluctuation.
* \dynamicaspectdescription
*       API called by function IoHwAb_DetectVoltageFluctuation.
* \constraints
*       Write here if you have any constraints.
* \ddesignrequirement
*       DSG_FSM_getUnlockDetectionTimeoutPeriod
* \archrequirement
*       ARCH_SW_FSM_pseFsmServices_FSM_getUnlockDetectionTimeoutPeriod
**/
EXPORTED void FSM_getUnlockDetectionTimeoutPeriod(uint16 *pu16UnlockDetectionTimeoutPeriod )
{
    /* Check the variables before subtraction */
   if (KU16_FSM_UNLOCK_DETECTION_TIMEOUT_OFFSET < fsm_au16ProfileTimeoutPeriod[KU8_PROFILE_UNLOCK])
   {
      /* Subtract an offset from detection timeout to prevent the
      detection of voltage spikes after the voltage booster is turned off. */
      *pu16UnlockDetectionTimeoutPeriod = fsm_au16ProfileTimeoutPeriod[KU8_PROFILE_UNLOCK] - KU16_FSM_UNLOCK_DETECTION_TIMEOUT_OFFSET ;
   }
   else
   {
      *pu16UnlockDetectionTimeoutPeriod = fsm_au16ProfileTimeoutPeriod[KU8_PROFILE_UNLOCK];
   }
}

/**
* \brief
*       The function is used to calculate and return the unlocking timeout period.
* \inputparam
*       None;
* \outputparam
*       Name: pu8Response;
*       Type: uint8 *;
*       Description: Outputs the status of profile timeout computation;
*       Range: 0x55, 0xAA;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return;
* \dynamicaspectcaller
*       FSM_Init
*       DIA_runDidFDE3_EcsProfilesWrite
*       DIA_runDidFDE4_EcsStepsWrite
* \dynamicaspectdescription
*       API called by FSM_Init at the initialization phase or by
*       diagnostic request.
* \constraints
*       Called in the initialization phase or by diagnostic request.
* \ddesignrequirement
*       DSG_FSM_getProfileTimeout
* \archrequirement
*       ARCH_SW_FSM_pseFsmServices_FSM_runCalculateProfileTimeout
**/
EXPORTED void FSM_runCalculateProfileTimeout(uint8 * pu8Response)
{
   uint8 u8ProfileIdx;
   uint8 u8StepIdx;
   uint8 *pu8Step;
   uint8 *pu8Profile;
   uint8 u8InfiniteDuration;

   *pu8Response = KU8_FALSE;

   for (u8ProfileIdx = KU8_ZERO; u8ProfileIdx < KU8_NB_OF_PROFILES; u8ProfileIdx++)
   {
      fsm_au16ProfileTimeoutPeriod[u8ProfileIdx] = KU16_ZERO;
      pu8Profile = &(NVP_au8EcsProfile_0[KU8_ZERO]) + (KU8_FSM_PROFILE_SIZE * u8ProfileIdx);

      for (u8StepIdx = KU8_FSM_INDEX_OF_FIRST_STEP; u8StepIdx < KU8_FSM_PROFILE_SIZE; u8StepIdx++)
      {
         if(KU8_FSM_NO_STEP != (pu8Profile[u8StepIdx]))
         {
            pu8Step = &(NVP_au8Step_0[pu8Profile[u8StepIdx] * KU8_FSM_STEP_SIZE]);
            u8InfiniteDuration = (pu8Step[KU8_FSM_INDEX_OF_OPTION_BYTE] & KU8_SIXTYFOUR);

            /* If no infinite duration mode */
            if(KU8_ZERO == u8InfiniteDuration)
            {
               /* Add to timeout period the duration of the step */
               fsm_au16ProfileTimeoutPeriod[u8ProfileIdx] += (uint16)U16_SWAP_BYTE_ORDER(*(uint16*)pu8Step);
            }
         }
      }

      /* Check the variables before subtraction */
      if (KU16_FSM_UNLOCK_CONFIRMATION_TIMEOUT_OFFSET < fsm_au16ProfileTimeoutPeriod[u8ProfileIdx])
      {
         /* Subtract an offset from confirmation timeout to prevent the
           detection of voltage spikes after the voltage booster is turned off. */
         fsm_au16ProfileTimeoutPeriod[u8ProfileIdx] -= KU16_FSM_UNLOCK_CONFIRMATION_TIMEOUT_OFFSET;
      }
   }

   *pu8Response = KU8_TRUE;
}

#define FSM_STOP_SEC_CODE_ASIL_A
#include "FSM_MemMap.h"

/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
