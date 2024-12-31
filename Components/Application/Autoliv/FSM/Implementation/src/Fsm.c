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
$Revision: 1.50 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/FSM/Implementation/src/project.pj $
*/

/*!****************************************************************************

details
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
 *      Specify that the self-test for solenoid not blocked is not requested
 */
#define KU8_FSM_NO_SELF_TEST_REQ                ((uint8)  0)

/**
 *\brief
 *      Specify that the self-test for solenoid not blocked is requested
 */
#define KU8_FSM_SELF_TEST_REQ                   ((uint8)  1)

/**
 *\brief
 *      Specify that the self-test for solenoid not blocked is completed
 */
#define KU8_FSM_SELF_TEST_COMPLETED             ((uint8)  1)

/**
 *\brief
 *      Specify that the self-test for solenoid not blocked is not completed
 */
#define KU8_FSM_SELF_TEST_NOT_COMPLETED         ((uint8)  0xFF)

/**
 *\brief
 *      The value indicates the solenoid has no error confirmed
 */
#define KU8_FSM_NO_ERROR                        ((uint8)  0x00)

/**
 *\brief
 *      The value indicates the solenoid has qualified an error which
 *      disables the functionality of the solenoid while is present
 */
#define KU8_FSM_ABORTION_ERROR                  ((uint8)  0x01)

/**
 *\brief
 *      The value indicates the solenoid has qualified an error which
 *      inhibits the functionality of the solenoid but allow the profile to run
 *      in order to check again the error condition
 */
#define KU8_FSM_INHIBITION_ERROR                ((uint8)  0x02)

/**
 *\brief
 *      The value indicates the solenoid is disabled
 */
#define KU8_FSM_SOLENOID_DISABLE                ((uint8)  0x03)

/**
 *\brief
 *      Indicates the position of the option byte from the step description
 */
#define KU8_FSM_INDEX_OF_OPTION_BYTE            ((uint8) 6)

/**
 *\brief
 *      Indicate the byte index of the first step of a profile
 */
#define KU8_FSM_INDEX_OF_FIRST_STEP             ((uint8)  4)

/**
 *\brief
 *      Indicate the size in bytes of a seat belt profile
 */
#define KU8_FSM_PROFILE_SIZE                    ((uint8) 12)

/**
 *\brief
 *      Indicate the size in bytes of a step
 */
#define KU8_FSM_STEP_SIZE                       ((uint8)  7)

/**
 *\brief
 *      Indicate there is no used step for the profile
 */
#define KU8_FSM_NO_STEP                         ((uint8) 0xFF)

/**
 *\brief
 *      Sub-System state used in Backup profile management
 *      for locking state
 */
#define KU8_FSM_BACKUP_LOCK_SUBSTATE            ((uint8) KU8_LOCK_STATE)

/**
 *\brief
 *      Sub-System state used in Backup profile management for the backup state
 */
#define KU8_FSM_BACKUP_SUBSTATE                 ((uint8) KU8_BACKUP_STATE)

/**
 *\brief
 *      Sub-System state used in Backup profile management if solenoid unlock was confirmed
 */
#define KU8_FSM_BACKUP_CONFIRMED_SUBSTATE       ((uint8) 0x03)

/**
 *\brief
 *      Indicate the number of repeated backups that can
 *      be done before qualifying the error
 */
#define KU8_FSM_NB_OF_BACKUPS                   ((uint8) NVP_u8NbOfBackups)

/**
 *\brief
 *      Time value in milli-seconds representing the duration of executing Step 5
 *      which is the first step of any profile
 */
#define KU16_FSM_STEP_5_DURATION                   ((uint16) 50)

/**
 *\brief
 *      Time value in milli-seconds representing the duration of reaching
 *      the infinite step profile
 */
#define KU16_FSM_REACH_INFINITE_STEP_DURATION      ((uint16) 300)

/**
 *\brief
 *      Indicate the duration expressed in milliseconds(multiple of 1ms) used to
 *      execute the Lock profile before running the startup sequence
 */
#define KU16_FSM_STARTUP_LOCK_TIMEOUT_OFFSET    ((uint16) NVP_u16StartupLockTimeout)

/**
 *\brief
 *      Timeout offset expressed in milliseconds (multiple of 1ms) used to
 *      confirm the unlock action
 */
#define KU16_FSM_UNLOCK_CONFIRMATION_TIMEOUT_OFFSET                  ((uint16) NVP_u16UnlockConfirmationTimeout)

/**
 *\brief
 *      Timeout offset expressed in milliseconds (multiple of 1ms) applied
 *      on detecting unlocking action time
 */
#define KU16_FSM_UNLOCK_DETECTION_TIMEOUT_OFFSET                     ((uint16) NVP_u16UnlockDetectionTimeout)

/**
 *\brief
 *      Timing OFFSET (multiple of 1ms) used in
 *      repeating cyclic  backup profile
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
LOCAL uint8 fsm_ManageSolenoidErrors(const uint8 ku8SolenoidId);
LOCAL void fsm_ProcessingInputSignals(void);
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
 *       Used to store the Rte return status that signals that the corresponding
 *       sender receiver interface has been previously written before read.
 * \initialization
 *       FALSE (boolean 0).
 * \range
 *       KB_FALSE
 *       KB_TRUE;
 */
LOCAL boolean fsm_bRteIsu8EcsFlagUpdated = KB_FALSE;

/**
 * \brief
 *       Used to indicate if an Unlock request was read for the first time after
 *       a lock state.
 *
 * \initialization
 *       KB_FALSE ((boolean) 0x00).
 * \range
 *       ;
 */
LOCAL boolean fsm_bFirstUnlock = KB_FALSE;

/**
 * \brief
 *       Used to store each solenoid's state flag, which represents if the
 *       timeout interval for detecting unlock was reached.
 * \initialization
 *       KB_FALSE (boolean 0).
 * \range
 *       KB_FALSE
 *       KB_TRUE;
 */
LOCAL boolean fsm_abUnlockTimeout[KU8_MAX_SOLENOID_NB] =
{
   KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE
};

/**
 * \brief
 *       Used to indicate if a transition from a LOCK to UNLOCK request was made
 *       while inhibition errors are present.
 * \initialization
 *       KB_FALSE (boolean 0).
 * \range
 *       KB_FALSE
 *       KB_TRUE;
 */
LOCAL boolean fsm_abNewUnlockRequestUnderError[KU8_MAX_SOLENOID_NB] =
{
   KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE
};


#define FSM_STOP_SEC_VAR_INIT_BOOL_ASIL_A
#include "FSM_MemMap.h"

#define FSM_START_SEC_VAR_INIT_8_ASIL_A
#include "FSM_MemMap.h"

/**
 * \brief
 *       The variable is used to store the index of the last controlled solenoid
 *       in order to start the new cycle with the next one.
 *
 * \initialization
 *       KU8_SOLENOID_1 ((uint8) 0).
 * \range
 *       KU8_SOLENOID_1...KU8_SOLENOID_6;
 */
LOCAL uint8 fsm_u8SolenoidLastIndex = KU8_SOLENOID_1;

/**
 * \brief
 *       The variable is used to store the counter value used to determine how
 *       many cycles all solenoids will be controlled in the same function call.
 *
 * \initialization
 *       KU8_ZERO ((uint8) 0x00).
 * \range
 *       KU8_ZERO..KU8_MAX;
 */
LOCAL uint8 fsm_u8LockAllSolCnt = KU8_ZERO;

/**
 * \brief
 *       Used to store the command request for solenoids read from ECS component
 *       as output of the eCS Algorithm.
 * \initialization
 *       KU8_ECS_ALGO_LOCK (1U).
 * \range
 *       KU8_ECS_ALGO_LOCK
 *       KU8_ECS_ALGO_UNLOCK;
 */
LOCAL u8EcsTriggerType fsm_u8AlgoRequest = KU8_ECS_ALGO_LOCK;

/**
 * \brief
 *       Used to store the request state based on the values of input signals for
 *       solenoid control.
 * \initialization
 *       KU8_UNLOCK_STATE (0U).
 * \range
 *       KU8_LOCK_STATE
 *       KU8_UNLOCK_STATE;
 */
LOCAL u8EcsTriggerType fsm_u8ActiveSignalRequest = KU8_LOCK_STATE;

/**
* \brief
*       Used to store each solenoid's LOCK/UNLOCK request form different sources.
* \initialization
*       KU8_LOCK_STATE (0).
* \range
*       KU8_LOCK_STATE
*       KU8_UNLOCK_STATE
*       KU8_DISABLED_STATE;
*/
LOCAL uint8 fsm_au8Request[KU8_MAX_SOLENOID_NB] =
{
      KU8_LOCK_STATE, KU8_LOCK_STATE, KU8_LOCK_STATE,
      KU8_LOCK_STATE, KU8_LOCK_STATE, KU8_LOCK_STATE
};

/**
* \brief
*       Used to store each solenoid's LOCK/UNLOCK request form different sources
*       from the last iteration.
* \initialization
*       KU8_DISABLED_STATE (3).
* \range
*       KU8_LOCK_STATE
*       KU8_UNLOCK_STATE
*       KU8_DISABLED_STATE;
*/
LOCAL uint8 fsm_au8LastRequest[KU8_MAX_SOLENOID_NB] =
{
      KU8_DISABLED_STATE, KU8_DISABLED_STATE, KU8_DISABLED_STATE,
      KU8_DISABLED_STATE, KU8_DISABLED_STATE, KU8_DISABLED_STATE
};

/**
 * \brief
 *       Used to store each solenoid's unlock confirmation status.
 * \initialization
 *       KU8_FALSE (uint8 0x55).
 * \range
 *       KU8_FALSE
 *       KU8_TRUE;
 */
LOCAL uint8 fsm_au8SolenoidConfirmationModeStatus[KU8_MAX_SOLENOID_NB] =
{
   KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE
};

/**
 * \brief
 *       Used to store each solenoids startup state.
 * \initialization
 *       FSM_KU8_SELF_TEST_NOT_COMPLETED (uint8 0xFF).
 * \range
 *       FSM_KU8_SELF_TEST_NOT_COMPLETED
 *       FSM_KU8_SELF_TEST_COMPLETED;
 */
LOCAL uint8 fsm_au8StartupCompleted[KU8_MAX_SOLENOID_NB] =
{
   KU8_FSM_SELF_TEST_NOT_COMPLETED, KU8_FSM_SELF_TEST_NOT_COMPLETED, KU8_FSM_SELF_TEST_NOT_COMPLETED, 
   KU8_FSM_SELF_TEST_NOT_COMPLETED, KU8_FSM_SELF_TEST_NOT_COMPLETED, KU8_FSM_SELF_TEST_NOT_COMPLETED
};

/**
 * \brief
 *       The array is used to store the state machine of the backup profile
 *       logic execution of each solenoid.
 * \initialization
 *       FSM_KU8_BACKUP_LOCK_SUBSTATE (uint8 0x00).
 * \range
 *       FSM_KU8_BACKUP_LOCK_SUBSTATE
 *       FSM_KU8_BACKUP_SUBSTATE;
 */
LOCAL uint8 fsm_au8BackupStateSM[KU8_MAX_SOLENOID_NB] =
{
   KU8_FSM_BACKUP_LOCK_SUBSTATE, KU8_FSM_BACKUP_LOCK_SUBSTATE, KU8_FSM_BACKUP_LOCK_SUBSTATE,
   KU8_FSM_BACKUP_LOCK_SUBSTATE, KU8_FSM_BACKUP_LOCK_SUBSTATE, KU8_FSM_BACKUP_LOCK_SUBSTATE
};

/**
* \brief
*       Used to store each solenoid's number of backups in case unlock is
*       not detected.
* \initialization
*       KU8_ZERO (0).
* \range
*       0..255.
*/
LOCAL uint8 fsm_au8NbOfBackups[KU8_MAX_SOLENOID_NB] =
{
      KU8_ZERO, KU8_ZERO, KU8_ZERO,
      KU8_ZERO, KU8_ZERO, KU8_ZERO
};

/**
 * \brief
 *       The array is used to store the state machine of each solenoid.
 * \initialization
 *       KU8_PROFILE_NONE (255U).
 * \range
 *       KU8_PROFILE_UNLOCK
 *       KU8_PROFILE_BACKUP
 *       KU8_PROFILE_NONE;
 */
LOCAL uint8 fsm_au8FsmSelectedProfiles[KU8_MAX_SOLENOID_NB] =
{
   KU8_PROFILE_NONE, KU8_PROFILE_NONE, KU8_PROFILE_NONE,
   KU8_PROFILE_NONE, KU8_PROFILE_NONE, KU8_PROFILE_NONE
};

/**
 * \brief
 *       The array is used to store the Error type of each solenoid.
 * \initialization
 *       KU8_FSM_NO_ERROR (uint8 0x00).
 * \range
 *        KU8_FSM_NO_ERROR
 *        KU8_FSM_ABORTION_ERROR
 *        KU8_FSM_INHIBITION_ERROR
 *        KU8_FSM_SOLENOID_DISABLE;
 */
LOCAL uint8 fsm_au8SolenoidErrorState[KU8_MAX_SOLENOID_NB] =
{
      KU8_FSM_NO_ERROR, KU8_FSM_NO_ERROR, KU8_FSM_NO_ERROR,
      KU8_FSM_NO_ERROR, KU8_FSM_NO_ERROR, KU8_FSM_NO_ERROR
};

/**
 * \brief
 *       The array is used to store the Diagnostic request.
 * \initialization
 *       KU8_NO_DIAG_REQUEST (0U).
 * \range
 *        KU8_NO_DIAG_REQUEST
 *        KU8_UNLOCK_DIAG_REQUEST
 *        KU8_LOCK_DIAG_REQUEST
 *        KU8_DIAG_PROFILE_REQUEST_ON
 *        KU8_DIAG_PROFILE_REQUEST_OFF;
 */
LOCAL uint8 fsm_au8DiagReq[KU8_MAX_SOLENOID_NB] =
{
      KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST,
      KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST
};

/**
 * \brief
 *       The array is used to store the last diagnostic request.
 * \initialization
 *       KU8_NO_DIAG_REQUEST_COMPLEMENT (255U).
 * \range
 *       KU8_NO_DIAG_REQUEST
 *       KU8_UNLOCK_DIAG_REQUEST
 *       KU8_LOCK_DIAG_REQUEST
 *       KU8_DIAG_PROFILE_REQUEST_ON
 *       KU8_DIAG_PROFILE_REQUEST_OFF;
 */
LOCAL uint8 fsm_au8LastDiagRequest[KU8_MAX_SOLENOID_NB] =
{
      KU8_NO_DIAG_REQUEST_COMPLEMENT, KU8_NO_DIAG_REQUEST_COMPLEMENT, KU8_NO_DIAG_REQUEST_COMPLEMENT,
      KU8_NO_DIAG_REQUEST_COMPLEMENT, KU8_NO_DIAG_REQUEST_COMPLEMENT, KU8_NO_DIAG_REQUEST_COMPLEMENT
};

/**
 * \brief
 *       The array is used to store the complement value of diagnostic request.
 * \initialization
 *       KU8_NO_DIAG_REQUEST_COMPLEMENT (255U).
 * \range
 *       ~KU8_NO_DIAG_REQUEST
 *       ~KU8_UNLOCK_DIAG_REQUEST
 *       ~KU8_LOCK_DIAG_REQUEST
 *       ~KU8_DIAG_PROFILE_REQUEST_ON
 *       ~KU8_DIAG_PROFILE_REQUEST_OFF;
 */
LOCAL uint8 fsm_au8DiagReqComplement[KU8_MAX_SOLENOID_NB]=
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
 *       This variable is used to compute the timeout period in milli-seconds
 *       for solenoids when a specific Inhibition error is detected.
 * \initialization
 *       KU16_ZERO (uint16 0).
 * \range
 *       0..KU16_MAX
 */
LOCAL uint16 fsm_au16InhibitionTimeoutPeriod[KU8_MAX_SOLENOID_NB] =
{
   KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};

/**
 * \brief
 *       The array is used to store the counter value of solenoids before
 *       qualifying the unlock confirmation timeout flag. One unit expressed
 *       in milliseconds (multiple of 1ms).
 * \initialization
 *       KU16_ZERO (uint16 0).
 * \range
 *       0..KU16_MAX
 */
LOCAL uint16 fsm_au16UnlockConfirmTimeout[KU8_MAX_SOLENOID_NB] =
{
   KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};

/**
 * \brief
 *       The array is used to store the counter value of solenoids before
 *       qualifying the unlock confirmation timeout flag. One unit expressed
 *       in milliseconds (multiple of 1ms).
 * \initialization
 *       KU16_ZERO (uint16 0).
 * \range
 *       0..KU16_MAX
 */
LOCAL uint16 fsm_au16ErrorConfirmationTimeout[KU8_MAX_SOLENOID_NB] =
{
      KU16_ZERO, KU16_ZERO, KU16_ZERO,
      KU16_ZERO, KU16_ZERO, KU16_ZERO
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
 *       0..KU16_MAX
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
 * \initialization
 *       KU16_ZERO (uint16 0).
 * \range
 *       0..KU16_MAX
 */
LOCAL uint16 fsm_au16StartupLockTimeout[KU8_MAX_SOLENOID_NB] =
{
   KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};

/**
 * \brief
 *       This variable is used to compute unlock timeout period for solenoids.
 * \initialization
 *       KU16_ZERO (uint16 0).
 * \range
 *       0..KU16_MAX
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

/**
 * \brief
 *       Used to store on each bit the initialization state of the corresponding solenoid:
 *        o 0 - Not initialized;
 *        o 1 - Initialized;
 * \initialization
 *       KU8_ZERO (uint8 0x00).
 * \range
 *       0x00..0x3F
 */
EXPORTED uint8 FSM_u8SolenoidInitState = KU8_ZERO;

/**
 * \brief
 *       Used to store the state of each solenoid:
 *        o 0x00 - Lock state;
 *        o 0x01 - Unlock state;
 *        o 0x02 - Backup state;
 *        o 0x03 - Disable state;
 *        o 0x04 - Startup state;
 *        o 0x05 - Diagnostic state;
 * \initialization
 *       KU8_LOCK_STATE (uint8 0x00).
 * \range
 *       0x00..0x05
 */
EXPORTED uint8 FSM_au8SolenoidStates[KU8_MAX_SOLENOID_NB] =
{
   KU8_LOCK_STATE, KU8_LOCK_STATE, KU8_LOCK_STATE,
   KU8_LOCK_STATE, KU8_LOCK_STATE, KU8_LOCK_STATE
};

/**
 * \brief
 *       Used to store the information about the stuck situation of each solenoid:
 *        o 0x55 - (KU8_FALSE) Solenoid is NOT stuck;
 *        o 0xAA - (KU8_TRUE) Solenoid is stuck;
 * \initialization
 *       KU8_FALSE (uint8 0x55).
 * \range
 *       0x55..0xAA
 */
EXPORTED uint8 FSM_au8SolenoidIsStuck[KU8_MAX_SOLENOID_NB] =
{
   KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE
};

#define FSM_STOP_SEC_VAR_INIT_8_ASIL_A
#include "FSM_MemMap.h"
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
#define FSM_START_SEC_CONST_UNSPECIFIED_ASIL_A
#include "FSM_MemMap.h"
/**
 * \brief
 *       This array holds the Abortion error masks of each solenoid based on what
 *       flag to check.
 * \initialization
 *       {KU64_SOLENOID_X_ABORTION_ERROR | KU64_SOLENOID_X_CAN_INHIB_STATUS}
 *       where X - the solenoid number.
 * \range
 *       0..KU64_MAX
 */
LOCAL const uint64 fsm_kau64SolenoidErrorAbortionMask[KU8_MAX_SOLENOID_NB] =
{
   /* Solenoid 1 */ (KU64_SOLENOID_1_ABORTION_ERROR | KU64_ECU_CAN_INHIB_STATUS),
   /* Solenoid 2 */ (KU64_SOLENOID_2_ABORTION_ERROR | KU64_ECU_CAN_INHIB_STATUS),
   /* Solenoid 3 */ (KU64_SOLENOID_3_ABORTION_ERROR | KU64_ECU_CAN_INHIB_STATUS),
   /* Solenoid 4 */ (KU64_SOLENOID_4_ABORTION_ERROR | KU64_ECU_CAN_INHIB_STATUS),
   /* Solenoid 5 */ (KU64_SOLENOID_5_ABORTION_ERROR | KU64_ECU_CAN_INHIB_STATUS),
   /* Solenoid 6 */ (KU64_SOLENOID_6_ABORTION_ERROR | KU64_ECU_CAN_INHIB_STATUS)
};

/**
 * \brief
 *       This array holds the inhibit error mask of each solenoid based on what
 *       flag to check.
 * \initialization
 *       KU64_SOLENOID_X_INHIB_ERROR
 *       where X - the solenoid number.
 * \range
 *       0..KU64_MAX
 */
LOCAL const uint64 fsm_kau64SolenoidErrorInhibMask[KU8_MAX_SOLENOID_NB] =
{
   /* Solenoid 1 */ (KU64_SOLENOID_1_INHIB_ERROR),
   /* Solenoid 2 */ (KU64_SOLENOID_2_INHIB_ERROR),
   /* Solenoid 3 */ (KU64_SOLENOID_3_INHIB_ERROR),
   /* Solenoid 4 */ (KU64_SOLENOID_4_INHIB_ERROR),
   /* Solenoid 5 */ (KU64_SOLENOID_5_INHIB_ERROR),
   /* Solenoid 6 */ (KU64_SOLENOID_6_INHIB_ERROR)
};

/**
 * \brief
 *       This array holds the configuration mask of each solenoid based on what
 *       flag to check.
 * \initialization
 *       {KU64_SOLENOID_X_CONFIGURED}
 *       where X - the solenoid number.
 * \range
 *       0..KU64_MAX
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
 *       where X - the solenoid number.
 * \range
 *       0..KU64_MAX
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
 *       where X - the solenoid number.
 * \range
 *       0..KU64_MAX
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
/**
 * \brief
 *      This bit shall indicate the result of the most recently performed test.
 *      A logical ‘1’ shall indicate that the last test failed meaning that the
 *      failure is completely matured.
 *      Reset to logical '0' if the result of the most recently performed test
 *      returns a “pass” result meaning that all de-mature criteria have been fulfilled.
 *      Additional reset conditions may be defined by the vehicle manufacturer / implementation
 */
#define KU8_FSM_EVENT_FAILED(EventStatus) \
         ((KU8_ONE == ((EventStatus) & (DEM_UDS_STATUS_TF))) ? KB_TRUE : KB_FALSE)
/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
#define FSM_START_SEC_CODE_ASIL_A
#include "FSM_MemMap.h"
/**
* \brief
*        Used to read the signals from CAN , eCS and diagnostic in order to update the
*        local variables which are used in solenoids state management.
*        Also, based on the signals, the way controlling the solenoids is handled here:
*           - control solenoids with offset or all in one iteration.
* \inputparam
*        Name: None.
* \outputparam
*        None.
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        None.
* \dynamicaspectcaller
*        FSM_runMainFunction
* \dynamicaspectdescription
*        The local function is called by the function FSM_runMainFunction.
* \constrains
*        This function has no constraints.
* \ddesignrequirement
*        DSG_fsm_ProcessingInputSignals
* \archrequirement
*        ARCH_SW_FSM_prrEcsDiagRequest
*/
LOCAL void fsm_ProcessingInputSignals(void)
{
   boolean bActiveRequest = KB_FALSE;
   uint8 u8SolenoidIdx;

   fsm_bRteIsu8EcsFlagUpdated = Rte_IsUpdated_prrEcsAlgoFlag_u8EcsFlag();

   (void)Rte_Read_prrEcsDiagRequest_au8DiagReq(fsm_au8DiagReq);
   (void)Rte_Read_prrEcsDiagRequest_au8DiagReqComplement(fsm_au8DiagReqComplement);

   if(KB_TRUE == fsm_bRteIsu8EcsFlagUpdated)
   {
      (void)Rte_Read_prrEcsAlgoFlag_u8EcsFlag(&fsm_u8AlgoRequest);
   }
   else
   {
      fsm_u8AlgoRequest = KU8_ECS_ALGO_LOCK;
   }

   for(u8SolenoidIdx = KU8_ZERO; (u8SolenoidIdx < KU8_MAX_SOLENOID_NB) && (KB_FALSE == bActiveRequest); u8SolenoidIdx++)
   {
      if((KU8_ECS_ALGO_LOCK != fsm_u8AlgoRequest) ||
         ((KU8_NO_DIAG_REQUEST != fsm_au8DiagReq[u8SolenoidIdx]) && (KU8_LOCK_DIAG_REQUEST != fsm_au8DiagReq[u8SolenoidIdx])))
      {
         bActiveRequest = KB_TRUE;
         fsm_u8ActiveSignalRequest = KU8_UNLOCK_STATE;
      }
      else
      {
         fsm_u8ActiveSignalRequest = KU8_LOCK_STATE;
      }
   }
}

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
*        None.
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        Return the solenoid profile based on the diag request.
* \dynamicaspectcaller
*        FSM_runMainFunction
* \dynamicaspectdescription
*        The local function is called by the function FSM_runMainFunction.
* \constrains
*        This function has no constraints.
* \ddesignrequirement
*        DSG_fsm_GetDiagRequest
* \archrequirement
*        ARCH_SW_FSM_prrEcsDiagRequest
*/
LOCAL INLINE uint8 fsm_GetDiagRequest(const uint8 ku8SolenoidId)
{
   uint8 u8DiagSelectedProfile;

   u8DiagSelectedProfile = KU8_NO_DIAG_REQUEST;

   if(KU8_MAX == (fsm_au8DiagReq[ku8SolenoidId] ^ fsm_au8DiagReqComplement[ku8SolenoidId]))
   {
      u8DiagSelectedProfile = fsm_au8DiagReq[ku8SolenoidId];

      /* Check if the diag request was changed from Diag_Profile to mark the
       * moment when the solenoids init auto-tests were finished  */
      if((fsm_au8LastDiagRequest[ku8SolenoidId] != fsm_au8DiagReq[ku8SolenoidId]) &&
         (KU8_DIAG_PROFILE_REQUEST_ON == fsm_au8LastDiagRequest[ku8SolenoidId]))
      {
         U8_BIT_SET(FSM_u8SolenoidInitState, (uint8)(KU8_ONE << ku8SolenoidId));
      }

      fsm_au8LastDiagRequest[ku8SolenoidId] = fsm_au8DiagReq[ku8SolenoidId];

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
*       None.
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*      Returns the startup sequence request of the corresponding solenoid.
* \dynamicaspectcaller
*       FSM_runMainFunction
* \dynamicaspectdescription
*       API called by function FSM_runMainFunction.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_fsm_CheckStartupSelfTest
* \archrequirement
*       ARCH_SW_FSM_prrEcsAlgoFlag
*/
LOCAL INLINE uint8 fsm_CheckStartupSelfTest(const uint8 ku8SolenoidId)
{
   uint8 u8BuckleStatus;
   uint8 u8InitPhaseInProgress;
   register uint8 u8StartupSelfTestRequest;

   /* Check if the start-up sequence must be done taking buckle status into account */
   if (KU8_TRUE == NVP_u8SkipBuckelAtStartup)
   {
      u8StartupSelfTestRequest = KU8_FSM_NO_SELF_TEST_REQ;
   }
   else
   {

      FSM_runCheckModeStatus(fsm_kau64SolenoidBuckleStatusMask[ku8SolenoidId], &u8BuckleStatus);
      FSM_runCheckModeStatus(KU64_INIT_PHASE_IN_PROGRESS, &u8InitPhaseInProgress);
      /* Check if:
       * • The buckle is latched;
       * • The startup sequence never executed before;
       * • The init phase was finished
       * • There is no error*/
      if ((KU8_TRUE == u8BuckleStatus) &&
          (KU8_FSM_SELF_TEST_NOT_COMPLETED == fsm_au8StartupCompleted[ku8SolenoidId]) &&
          (KU8_FALSE == u8InitPhaseInProgress) &&
          (KU8_FSM_NO_ERROR == fsm_au8SolenoidErrorState[ku8SolenoidId]))
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
         if(KU8_FSM_INHIBITION_ERROR == fsm_au8SolenoidErrorState[ku8SolenoidId])
         {
            fsm_au8StartupCompleted[ku8SolenoidId] = KU8_FSM_SELF_TEST_COMPLETED;
         }
         u8StartupSelfTestRequest = KU8_FSM_NO_SELF_TEST_REQ;
      }
   }
   return u8StartupSelfTestRequest;
}

/**
* \brief
*       Based on the error source, the error type will be set and a timeout period
*       will be calculated in order to activate profiles for a short time to
*       pass the event status.
* \inputparam
*       Name: ku8SolenoidId;
*       Type: const uint8;
*       Description: The id of the solenoid;
*       Range: 0..5;
* \outputparam
*       None.
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       Return the type of error.
* \dynamicaspectcaller
*       FSM_runMainFunction;
* \dynamicaspectdescription
*       API called by function FSM_runMainFunction.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_fsm_ManageSolenoidErrors
* \archrequirement
*       ARCH_SW_FSM_pclDemServices
*       ARCH_SW_FSM_pclDemIfEventSerices
*/

LOCAL uint8 fsm_ManageSolenoidErrors(const uint8 ku8SolenoidId)
{
   uint8 u8ModeConfigStatusResult;
   uint8 u8ModeErrorAbortStatusResult;
   uint8 u8ModeInhibStatusResult;
   uint8 u8ErrorStatus = KU8_FSM_NO_ERROR;
   uint8 u8OCErrorStatus;
   uint8 u8ActuatorErrorStatus;
   uint8 u8STGndErrorStatus;
   uint8 u8SolenoidOVErrorStatus;
   uint16 u16EventCounterPassTrh = KU16_ZERO;
   uint16 u16MaxTimeoutPeriod = KU16_ZERO;

   FSM_runCheckModeStatus(fsm_kau64SolenoidConfigMask[ku8SolenoidId], &u8ModeConfigStatusResult);
   FSM_runCheckModeStatus(fsm_kau64SolenoidErrorAbortionMask[ku8SolenoidId], &u8ModeErrorAbortStatusResult);
   FSM_runCheckModeStatus(fsm_kau64SolenoidErrorInhibMask[ku8SolenoidId], &u8ModeInhibStatusResult);

   /* If the solenoid is not configured */
   if (KU8_FALSE == u8ModeConfigStatusResult)
   {
      u8ErrorStatus = KU8_FSM_SOLENOID_DISABLE;
   }
   else
   {
      if(KU8_TRUE == u8ModeErrorAbortStatusResult)
      {
         u8ErrorStatus = KU8_FSM_ABORTION_ERROR;
      }
      else if(KU8_TRUE == u8ModeInhibStatusResult)
      {
         u8ErrorStatus = KU8_FSM_INHIBITION_ERROR;

         (void)Rte_Call_pclDemServices_GetEventStatus(DemConf_DemEventParameter_EVENT_ACTUATOR_OPEN_CIRCUIT, &u8OCErrorStatus);
         (void)Rte_Call_pclDemServices_GetEventStatus(DemConf_DemEventParameter_EVENT_ACTUATOR_STATUS, &u8ActuatorErrorStatus);
         (void)Rte_Call_pclDemServices_GetEventStatus(DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_GND, &u8STGndErrorStatus);
         (void)Rte_Call_pclDemServices_GetEventStatus(DemConf_DemEventParameter_EVENT_SOLENOID_OVERVOLTAGE, &u8SolenoidOVErrorStatus);

         if(KB_TRUE == KU8_FSM_EVENT_FAILED(u8OCErrorStatus))
         {
            (void)Rte_Call_pclDemIfEventSerices_GetCounterPassedThreshold(DemConf_DemEventParameter_EVENT_ACTUATOR_OPEN_CIRCUIT, &u16EventCounterPassTrh);
            /* Denounce time * auto-test periodicity [ms] */
            fsm_au16InhibitionTimeoutPeriod[ku8SolenoidId] = u16EventCounterPassTrh * KU16_FIVE;

            if(fsm_au16InhibitionTimeoutPeriod[ku8SolenoidId] < u16MaxTimeoutPeriod)
            {
               fsm_au16InhibitionTimeoutPeriod[ku8SolenoidId] = u16MaxTimeoutPeriod;
            }
         }

         if(KB_TRUE == KU8_FSM_EVENT_FAILED(u8ActuatorErrorStatus))
         {
            (void)Rte_Call_pclDemIfEventSerices_GetCounterPassedThreshold(DemConf_DemEventParameter_EVENT_ACTUATOR_STATUS, &u16EventCounterPassTrh);
            /* (Profile duration + pause time between two consecutive backups) * Number of retries [ms] */
            fsm_au16InhibitionTimeoutPeriod[ku8SolenoidId] = u16EventCounterPassTrh * ((fsm_au16ProfileTimeoutPeriod[KU8_PROFILE_BACKUP] + KU16_FSM_REPEAT_PROFILE_TIMEOUT) * KU8_FSM_NB_OF_BACKUPS);

            if(fsm_au16InhibitionTimeoutPeriod[ku8SolenoidId] < u16MaxTimeoutPeriod)
            {
               fsm_au16InhibitionTimeoutPeriod[ku8SolenoidId] = u16MaxTimeoutPeriod;
            }
         }

         if(KB_TRUE == KU8_FSM_EVENT_FAILED(u8STGndErrorStatus))
         {
            (void)Rte_Call_pclDemIfEventSerices_GetCounterPassedThreshold(DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_GND, &u16EventCounterPassTrh);
            /* The auto-test will run after the first step (Step 5) of the profile is complete. An additional duration will be added */
            /* Denounce time * auto-test periodicity [ms] */
            fsm_au16InhibitionTimeoutPeriod[ku8SolenoidId] = (u16EventCounterPassTrh * KU16_TEN) + KU16_FSM_STEP_5_DURATION;

            if(fsm_au16InhibitionTimeoutPeriod[ku8SolenoidId] < u16MaxTimeoutPeriod)
            {
               fsm_au16InhibitionTimeoutPeriod[ku8SolenoidId] = u16MaxTimeoutPeriod;
            }

         }

         if(KB_TRUE == KU8_FSM_EVENT_FAILED(u8SolenoidOVErrorStatus))
         {
            (void)Rte_Call_pclDemIfEventSerices_GetCounterPassedThreshold(DemConf_DemEventParameter_EVENT_SOLENOID_OVERVOLTAGE, &u16EventCounterPassTrh);
            /* Denounce time * auto-test periodicity  [ms] */
            fsm_au16InhibitionTimeoutPeriod[ku8SolenoidId] = (u16EventCounterPassTrh * KU16_TEN) + KU16_FSM_REACH_INFINITE_STEP_DURATION;

            if(fsm_au16InhibitionTimeoutPeriod[ku8SolenoidId] < u16MaxTimeoutPeriod)
            {
               fsm_au16InhibitionTimeoutPeriod[ku8SolenoidId] = u16MaxTimeoutPeriod;
            }
         }
      }
      else
      {
         u8ErrorStatus = KU8_FSM_NO_ERROR;
         fsm_abNewUnlockRequestUnderError[ku8SolenoidId] = KB_FALSE;
         fsm_au16InhibitionTimeoutPeriod[ku8SolenoidId] = KU16_ZERO;
      }
   }
   return u8ErrorStatus;
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
*       None.
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
* \constrains
*       Called from FSM_runMainFunction at each 1ms.
* \ddesignrequirement
*       DSG_fsm_RunSolenoidStateManagement
* \archrequirement
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction
*       ARCH_SW_FSM_prrEcsAlgoFlag
*/
LOCAL INLINE void fsm_RunSolenoidStateManagement(const uint8 ku8SolenoidId)
{
   uint8 u8SolenoidStartUpSeqRequest = KU8_FSM_NO_SELF_TEST_REQ;
   uint8 u8DiagReq = KU8_NO_DIAG_REQUEST;

   FSM_runCheckModeStatus(fsm_kau64SolenoidUnlockConfirmedMask[ku8SolenoidId], &fsm_au8SolenoidConfirmationModeStatus[ku8SolenoidId]);

   fsm_au8SolenoidErrorState[ku8SolenoidId] = fsm_ManageSolenoidErrors(ku8SolenoidId);

   if((KU8_FSM_SOLENOID_DISABLE == fsm_au8SolenoidErrorState[ku8SolenoidId]) ||
      (KU8_FSM_ABORTION_ERROR == fsm_au8SolenoidErrorState[ku8SolenoidId]))
   {
      FSM_au8SolenoidStates[ku8SolenoidId] = KU8_DISABLED_STATE;
      fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
      fsm_au16RepeatProfileDelay[ku8SolenoidId] = KU16_ZERO;
      fsm_au16UnlockConfirmTimeout[ku8SolenoidId] = KU16_ZERO;
      fsm_au8NbOfBackups[ku8SolenoidId] = KU8_ZERO;

      fsm_au8Request[ku8SolenoidId] = KU8_DISABLED_STATE;
   }
   else
   {
      u8DiagReq = fsm_GetDiagRequest(ku8SolenoidId);

      if(KU8_DIAG_PROFILE_REQUEST_ON == u8DiagReq)
      {
         FSM_au8SolenoidStates[ku8SolenoidId] = KU8_DIAGNOSTIC_STATE;
      }
      else
      {
         u8SolenoidStartUpSeqRequest = fsm_CheckStartupSelfTest(ku8SolenoidId);
         /* Perform lock solenoid if:
                  • eCS_Algo set to lock
                  • The diagnostic request is lock or it doesn't exist
                  • No buckle was perform
          */
         if (((KU8_ECS_ALGO_LOCK == fsm_u8AlgoRequest) || (KU8_LOCK_DIAG_REQUEST == u8DiagReq)) &&
              (KU8_UNLOCK_DIAG_REQUEST != u8DiagReq) &&
              (KU8_FSM_NO_SELF_TEST_REQ == u8SolenoidStartUpSeqRequest)
            )
         {
            fsm_au8Request[ku8SolenoidId] = KU8_LOCK_STATE;
            FSM_au8SolenoidStates[ku8SolenoidId] = KU8_LOCK_STATE;
            fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
            fsm_au16RepeatProfileDelay[ku8SolenoidId] = KU16_ZERO;
            fsm_au16UnlockConfirmTimeout[ku8SolenoidId] = KU16_ZERO;
            fsm_au8NbOfBackups[ku8SolenoidId] = KU8_ZERO;
         }
         else
         {
            fsm_au8Request[ku8SolenoidId] = KU8_UNLOCK_STATE;
            if (KB_TRUE == KUB_eCS_BACK_UP_PROFILE_VARIANT)
            {
               /* Perform unlock solenoid if:
                • Received a diagnostic request;
                • The timeout for unlock detection was not reached;
                • No backup or self-test was required.
               */
               if ((KU8_UNLOCK_DIAG_REQUEST == u8DiagReq) &&
                   (KB_FALSE == fsm_abUnlockTimeout[ku8SolenoidId]) &&
                   (KU8_BACKUP_STATE != FSM_au8SolenoidStates[ku8SolenoidId]) &&
                   (KU8_FSM_NO_SELF_TEST_REQ == u8SolenoidStartUpSeqRequest)
                  )
               {
                  FSM_au8SolenoidStates[ku8SolenoidId] = KU8_UNLOCK_STATE;
                  fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
                  fsm_au16RepeatProfileDelay[ku8SolenoidId] = KU16_ZERO;
               }
               /* Perform unlock solenoid if:
                • Received a diagnostic request;
                • No backup or self-test was required.
               */
               else if ((KU8_FSM_SELF_TEST_REQ == u8SolenoidStartUpSeqRequest) &&
                        ((KU8_STARTUP_STATE != FSM_au8SolenoidStates[ku8SolenoidId]) && (KU8_BACKUP_STATE != FSM_au8SolenoidStates[ku8SolenoidId])))
               {
                  FSM_au8SolenoidStates[ku8SolenoidId] = KU8_STARTUP_STATE;
                  fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
                  fsm_au16RepeatProfileDelay[ku8SolenoidId] = KU16_ZERO;
                  fsm_au16StartupLockTimeout[ku8SolenoidId] = KU16_ZERO;
               }
               /* Perform backup state if:
                • The unlock detection is not confirmed and the timeout for detection expired;
                • The backup state already running.
               */
               else if ((KU8_FALSE == fsm_au8SolenoidConfirmationModeStatus[ku8SolenoidId]) &&
                        ((KB_TRUE == fsm_abUnlockTimeout[ku8SolenoidId]) || (KU8_BACKUP_STATE == FSM_au8SolenoidStates[ku8SolenoidId])))
               {
                  FSM_au8SolenoidStates[ku8SolenoidId] = KU8_BACKUP_STATE;
               }
               /* At the end of the unlock state, based on the request's source,
                        continue to maintain the current profile. or run other profile. */
               else
               {
                  if(KU8_FSM_SELF_TEST_REQ == u8SolenoidStartUpSeqRequest)
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
                     fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
                     fsm_au16RepeatProfileDelay[ku8SolenoidId] = KU16_ZERO;

                     if (KU8_TRUE == fsm_au8SolenoidConfirmationModeStatus[ku8SolenoidId])
                     {
                        FSM_au8SolenoidIsStuck[ku8SolenoidId] = KU8_FALSE;
                     }
                  }
               }
            }
            else
            {
               FSM_au8SolenoidStates[ku8SolenoidId] = KU8_UNLOCK_STATE;

               if (KU8_FSM_SELF_TEST_REQ == u8SolenoidStartUpSeqRequest)
               {
                  fsm_au8StartupCompleted[ku8SolenoidId] = KU8_FSM_SELF_TEST_COMPLETED;
               }
            }
         }
      }
   }

   if(KU8_FSM_INHIBITION_ERROR == fsm_au8SolenoidErrorState[ku8SolenoidId])
   {
      switch(fsm_au8Request[ku8SolenoidId])
      {
         case KU8_LOCK_STATE:
         {
            /* Reset transition status flag*/
            fsm_abNewUnlockRequestUnderError[ku8SolenoidId] = KB_FALSE;

            fsm_abUnlockTimeout[ku8SolenoidId] = KB_FALSE;
            FSM_au8SolenoidStates[ku8SolenoidId] = KU8_DISABLED_STATE;

            break;
         }

         case KU8_UNLOCK_STATE:
         {
            /* Transition from LOCK to UNLOCK */
            if(KU8_LOCK_STATE == fsm_au8LastRequest[ku8SolenoidId])
            {
               /* Confirm transition */
               fsm_abNewUnlockRequestUnderError[ku8SolenoidId] = KB_TRUE;
               /* Reset timer */
               fsm_au16ErrorConfirmationTimeout[ku8SolenoidId] = KU16_ZERO;
            }

            if(KB_TRUE == fsm_abNewUnlockRequestUnderError[ku8SolenoidId])
            {
               if((KU8_TRUE == FSM_au8SolenoidIsStuck[ku8SolenoidId]) &&
                  (KU8_ZERO == fsm_au16ErrorConfirmationTimeout[ku8SolenoidId]))
               {
                  FSM_au8SolenoidStates[ku8SolenoidId] = KU8_BACKUP_STATE;
                  fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
                  fsm_au16RepeatProfileDelay[ku8SolenoidId] = KU16_FSM_REPEAT_PROFILE_TIMEOUT;
               }
               else if(KU8_TRUE == FSM_au8SolenoidIsStuck[ku8SolenoidId])
               {
                  FSM_au8SolenoidStates[ku8SolenoidId] = KU8_BACKUP_STATE;
               }
               else
               {
                  /* Do nothing */
               }
            }
            else
            {
               FSM_au8SolenoidStates[ku8SolenoidId] = KU8_DISABLED_STATE;
            }

            break;
         }
         default:
            break;
      }
   }

   fsm_au8LastRequest[ku8SolenoidId] = fsm_au8Request[ku8SolenoidId];
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
*       None.
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
* \constrains
*       Called when the ECU detects the buckle action.
* \ddesignrequirement
*       DSG_fsm_RunStartupSequence
* \archrequirement
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction
*/
LOCAL INLINE void fsm_RunStartupSequence(const uint8 ku8SolenoidId)
{

   if (fsm_au16StartupLockTimeout[ku8SolenoidId] < KU16_FSM_STARTUP_LOCK_TIMEOUT_OFFSET)
   {
      fsm_au8FsmSelectedProfiles[ku8SolenoidId] = KU8_PROFILE_NONE;
      fsm_au16UnlockConfirmTimeout[ku8SolenoidId] = KU16_ZERO;
      fsm_abUnlockTimeout[ku8SolenoidId] = KB_FALSE;
      fsm_au16StartupLockTimeout[ku8SolenoidId] += KU16_CNT_INCR_STEP;
   }
   else if ((KU8_FALSE == fsm_au8SolenoidConfirmationModeStatus[ku8SolenoidId]) &&
            (KB_FALSE == fsm_abUnlockTimeout[ku8SolenoidId]))
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
*       None.
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
* \constrains
*       Called when the unlock action is not detected.
* \ddesignrequirement
*       DSG_fsm_RunBackupProfile
* \archrequirement
*       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction
*/
LOCAL INLINE void fsm_RunBackupProfile(const uint8 ku8SolenoidId)
{
   switch (fsm_au8BackupStateSM[ku8SolenoidId])
   {
      case KU8_FSM_BACKUP_LOCK_SUBSTATE:
      {
         if (KU8_FSM_NB_OF_BACKUPS > fsm_au8NbOfBackups[ku8SolenoidId])
         {
            if(fsm_au16RepeatProfileDelay[ku8SolenoidId] < KU16_FSM_REPEAT_PROFILE_TIMEOUT)
            {
               fsm_au8FsmSelectedProfiles[ku8SolenoidId] = KU8_PROFILE_NONE;
               fsm_abUnlockTimeout[ku8SolenoidId] = KB_FALSE;
               fsm_au16UnlockConfirmTimeout[ku8SolenoidId] = KU16_ZERO;
               fsm_au16RepeatProfileDelay[ku8SolenoidId] += KU16_CNT_INCR_STEP;
            }
            else
            {
               fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_SUBSTATE;
               fsm_au16RepeatProfileDelay[ku8SolenoidId] = KU16_ZERO;
            }
         }
         else
         {
            FSM_au8SolenoidIsStuck[ku8SolenoidId] = KU8_TRUE;
            fsm_au8FsmSelectedProfiles[ku8SolenoidId] = KU8_PROFILE_BACKUP;
            fsm_au8StartupCompleted[ku8SolenoidId] = KU8_FSM_SELF_TEST_COMPLETED;
         }
         break;
      }
      case KU8_FSM_BACKUP_SUBSTATE:
      {
         fsm_au8FsmSelectedProfiles[ku8SolenoidId] = KU8_PROFILE_BACKUP;

         if (KB_TRUE == fsm_abUnlockTimeout[ku8SolenoidId])
         {
            fsm_au8BackupStateSM[ku8SolenoidId] = KU8_FSM_BACKUP_LOCK_SUBSTATE;
            fsm_au8NbOfBackups[ku8SolenoidId]++;
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
         fsm_au8NbOfBackups[ku8SolenoidId] = KU8_ZERO;
         FSM_au8SolenoidIsStuck[ku8SolenoidId] = KU8_FALSE;
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
*       None.
* \outputparam
*       None.
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
* \constrains
*       Called during the initialization phase.
* \ddesignrequirement
*       DSG_FSM_Init
* \archrequirement
*       ARCH_SW_Fsm_ptrpFsmServicesBswMIf_FSM_Init
*/
EXPORTED void FSM_Init(void)
{
   uint8 u8Idx;
   uint8 u8Response;

   FSM_runCalculateProfileTimeout(&u8Response);

   for (u8Idx = KU8_ZERO; u8Idx < KU8_MAX_SOLENOID_NB; u8Idx++)
   {
      fsm_abUnlockTimeout[u8Idx] = KB_FALSE;
      FSM_au8SolenoidStates[u8Idx] = KU8_LOCK_STATE;
      fsm_au8SolenoidConfirmationModeStatus[u8Idx] = KU8_FALSE;
      FSM_au8SolenoidIsStuck[u8Idx] = KU8_FALSE;
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
*       None.
* \outputparam
*       None.
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
*       Called from OsTask_Alv_eCS_App at each 1ms.
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
*       ARCH_SW_FSM_psrSolenoidStuckStatus_FSM_runMainFunction
*/
EXPORTED void FSM_runMainFunction(void)
{
   register uint8 u8Index;
   uint8 u8IndexLimit;

   fsm_ProcessingInputSignals();

   if (KU8_LOCK_STATE != fsm_u8ActiveSignalRequest)
   {
      if(KB_TRUE == fsm_bFirstUnlock)
      {
         fsm_u8SolenoidLastIndex = KU8_SOLENOID_1;
         fsm_bFirstUnlock = KB_FALSE;
      }

      u8IndexLimit = fsm_u8SolenoidLastIndex + KU8_SOL_EXE_OFFSET;
      fsm_u8LockAllSolCnt = KU8_ZERO;
   }
   else
   {
      if(KU8_LOCK_ALL_SOLENOIDS_CYCLE_CNT > fsm_u8LockAllSolCnt)
      {
         fsm_u8SolenoidLastIndex = KU8_SOLENOID_1;
         u8IndexLimit = KU8_MAX_SOLENOID_NB;
         fsm_u8LockAllSolCnt += KU8_ONE;
      }
      else
      {
         u8IndexLimit = fsm_u8SolenoidLastIndex + KU8_SOL_EXE_OFFSET;
         fsm_u8LockAllSolCnt = KU8_LOCK_ALL_SOLENOIDS_CYCLE_CNT;
      }
      fsm_bFirstUnlock = KB_TRUE;
   }

   for (u8Index = fsm_u8SolenoidLastIndex; u8Index < u8IndexLimit; u8Index++)
   {
      fsm_RunSolenoidStateManagement(u8Index);

      switch (FSM_au8SolenoidStates[u8Index])
      {
         case KU8_LOCK_STATE:
         {
            fsm_au8FsmSelectedProfiles[u8Index] = KU8_PROFILE_NONE;
            fsm_abUnlockTimeout[u8Index] = KB_FALSE;
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
         if((fsm_au16UnlockConfirmTimeout[u8Index] < (fsm_au16ProfileTimeoutPeriod[fsm_au8FsmSelectedProfiles[u8Index]] + (KU16_CNT_INCR_STEP * KU16_TWO))) &&
               (KU8_FALSE == fsm_au8SolenoidConfirmationModeStatus[u8Index]))
         {
            fsm_au16UnlockConfirmTimeout[u8Index] += (KU16_CNT_INCR_STEP * KU16_TWO);
         }
         else if (fsm_au16UnlockConfirmTimeout[u8Index] >= fsm_au16ProfileTimeoutPeriod[fsm_au8FsmSelectedProfiles[u8Index]])
         {
            fsm_abUnlockTimeout[u8Index] = KB_TRUE;
         }
         else
         {
            /* Do nothing */
         }
      }

      if(KB_TRUE == fsm_abNewUnlockRequestUnderError[u8Index])
      {
         if(fsm_au16ErrorConfirmationTimeout[u8Index] < fsm_au16InhibitionTimeoutPeriod[u8Index])
         {
            fsm_au16ErrorConfirmationTimeout[u8Index] += KU16_CNT_INCR_STEP;
         }
         else
         {
            fsm_abNewUnlockRequestUnderError[u8Index] = KB_FALSE;
         }
      }
   }

   fsm_u8SolenoidLastIndex = (fsm_u8SolenoidLastIndex + KU8_SOL_EXE_OFFSET) % KU8_MAX_SOLENOID_NB;

   (void)Rte_Write_psrSolenoidProfile_au8SelectedProfile((const uint8 *)fsm_au8FsmSelectedProfiles);
   (void)Rte_Write_psrSolenoidState_au8SolenoidState((const uint8 *)FSM_au8SolenoidStates);
   (void)Rte_Write_psrSolenoidStuckStatus_au8SolenoidIsStuck((const uint8 *)FSM_au8SolenoidIsStuck);

   FSM_manageSolenoidCounters();
}

/**
* \brief
*       The function is used to return the value of the calculated unlocking
*       timeout period.
* \inputparam
*       None.
* \outputparam
*       Name: pu16UnlockDetectionTimeoutPeriod;
*       Type: uint16 *;
*       Description: Outputs the unlock detection timeout period;
*       Range: 0..KU16_MAX;
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
* \constrains
*       Write here if you have any constrains.
* \ddesignrequirement
*       DSG_FSM_getUnlockDetectionTimeoutPeriod
* \archrequirement
*       ARCH_SW_FSM_pseFsmServices_FSM_getUnlockDetectionTimeoutPeriod
*/
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
* \outputparam
*       Name: pu8Response;
*       Type: uint8 *;
*       Description: Outputs the status of profile timeout computation;
*       Range: 0x55..0xAA;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       FSM_Init;
*       DIA_runDidFDE3_EcsProfilesWrite;
*       DIA_runDidFDE4_EcsStepsWrite;
* \dynamicaspectdescription
*       API called by FSM_Init at the initialization phase or by
*       diagnostic request.
* \constrains
*       Called in the initialization phase or by diagnostic request.
* \ddesignrequirement
*       DSG_FSM_getProfileTimeout
* \archrequirement
*       ARCH_SW_FSM_pseFsmServices_FSM_runCalculateProfileTimeout
*/
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
