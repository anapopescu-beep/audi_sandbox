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
$Revision: 1.25 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/SAD/Quality_Assurance/Static_Analysis/project.pj $
*/

/*!****************************************************************************

details
   The SAD component is responsible for the control of the solenoid actuators
   and error detection

******************************************************************************/

/*!****************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "SAD.h"
#include "Rte_SAD.h"
#include "RteIf.h"
#include "Math.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 *\brief
 *      Indicate the status of the current step as invalid.
 */
#define KU8_SAD_INVALID_STEP                 ((uint8) 0)

/**
 *\brief
 *      Indicate the status of the current step as a new step.
 */
#define KU8_SAD_NEW_STEP                     ((uint8) 1)

/**
 *\brief
 *      Indicate the status of the current step as it is ongoing.
 */
#define KU8_SAD_ON_GOING_STEP                ((uint8) 2)

/**
 *\brief
 *      Indicates the position of the first step from the profile array
 */
#define KU8_SAD_INDEX_OF_FIRST_STEP          ((uint8) 4)


/**
 *\brief
 *      Indicates the position of the option byte from the step description.
 */
#define KU8_SAD_INDEX_OF_OPTION_BYTE         ((uint8) 6)

/**
 *\brief
 *      Indicates the maximum number of steps configured in NVP
 */
#define KU8_SAD_MAX_STEP                     ((uint8) 8)

/**
 *\brief
 *       Indicate the limit value of the profile number. If a profile is set to a
 *       higher value, the profile is invalid.
 */
#define KU8_SAD_NB_MAX_PROFILES_LIB          ((uint8) 4)

/**
 *\brief
 *      Indicates the maximum number of steps assigned to a profile
 */
#define KU8_SAD_NB_MAX_STEPS_LIB             ((uint8) 8)

/**
 *\brief
 *      Indicate the value of an invalid step
 */
#define KU8_SAD_NO_STEP_TYPE                 ((uint8) 7)

/**
 *\brief
 *      Indicate the number of bytes assigned to a profile.
 */
#define KU8_SAD_PROFILE_SIZE                 ((uint8) 12)

/**
 *\brief
 *      Indicates the type of control to be as PWM (the other type is current)
 */
#define KU8_SAD_PWM_ORDER_TYPE               ((uint8) 2)

/**
 *\brief
 *      Indicate the number of bytes from a step
 */
#define KU8_SAD_STEP_SIZE                    ((uint8) 7)

/**
 *\brief
 *      Indicates the maximum number of steps assigned to a profile.
 */
#define KU8_SAD_MAX_STEP_INDEX               ((uint8) 8)

/**
 *\brief
 *      Indicate the first profile from the NVP block
 */
#define KU8_SAD_UNLOCK_PROFILE               NVP_au8EcsProfile_0

/**
 *\brief
 *      Indicate the first step from the NVP block
 */
#define KU8_SAD_STEP_0                       NVP_au8Step_0

/**
 *\brief
 *      Indicates the NVP value for timeout value for detecting solenoid
 *      lock action
 */
#define KU16_SAD_LOCK_DETECTION_TIMEOUT      ((uint16) NVP_u16LockDetectionTimeout)

/**
 *\brief
 *      Indicate the value in LSB units for 100% PWM
 */
#define KU16_SAD_MAX_PWM_LSB                 ((uint16) 0x8000)

/**
 *\brief
 *      Indicate the value in LSB units for 99% PWM
 */
#define KU16_SAD_NINETY_NINE_PER_PWM         ((uint16) 32767)

/**
 *\brief
 *      The maximum value of PWM in percentage multiply by a gain factor of 1000
 */
#define KU32_SAD_MAX_PWM                     ((uint32) 100000)

/**
 *\brief
 *      Correction factor obtains from considering the effect of some hardware
 *      components in voltage readings.
 */
#define KU32_SAD_CORECTIVE_FACTOR            ((uint32) 3077)
/******************************************************************************
MODULE TYPES
******************************************************************************/
/**
 * \brief
 *       Data structure used to save the configuration of the current executed step
 */
typedef struct sad_stStepParam_tag {
   uint16 u16Duration;     /* Description: Step duration: 1 lsb = 1ms            */
   uint8 u8Order;          /* Description: Order type : PWM or current           */
   uint32 u32Consign;      /* Description: PWM Value                             */
   boolean b8IsRamp;       /* Description: Ramp option: 0 - OFF; 1 - ON          */
   boolean b8IsInfinite;   /* Description: Infinite step option: 0 - OFF; 1 - ON */
   boolean b8IsTrigOff;    /* Description: Trigger option: 0 - OFF; 1 - ON       */
} sad_stStepParam;

/**
 * \brief
 *       Data structure used to save the configuration of the NVP implemented steps
 */
typedef struct sad_stStepParamCollection_tag {
   sad_stStepParam astStepParam[KU8_EIGHT];
} sad_stStepParamCollection;
/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL void sad_ControlSolenoidsCircuitry(void);
LOCAL void sad_ControlStepExecution(const uint8 ku8SolenoidIdx);
LOCAL void sad_ManageStepEvents(const uint8 ku8SolenoidIdx);
LOCAL void sad_SelectStepId(const uint8 ku8SolenoidIdx);
LOCAL void sad_StepPreprocessing(const uint8 ku8SolenoidIdx);
LOCAL void sad_ExtractSteps(const uint8 ku8SolenoidIdx);
LOCAL void sad_runSolenoidControl(const uint8 ku8SolenoidIdx);
LOCAL void sad_TriggerDiagProfile(const uint8 ku8SolenoidIdx);

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define SAD_START_SEC_VAR_INIT_BOOL_ASIL_A
#include "SAD_MemMap.h"

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
LOCAL boolean sad_bFirstUnlock = KB_FALSE;

/**
 * \brief
 *       Used to store each solenoid's step status, which represents if
 *       the current step was completely executed or not.
 *
 * \initialization
 *       KB_FALSE (boolean 0)
 *
 * \range
 *       KB_FALSE
 *       KB_TRUE;
 */
LOCAL boolean sad_abIsStepFinished[KU8_MAX_SOLENOID_NB] =
{
      KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE
};

/**
 * \brief
 *       Used to store each solenoid's step status, which represents if
 *       the previous step was completely executed or not.
 *
 * \initialization
 *       KB_FALSE (boolean 0)
 *
 * \range
 *       KB_FALSE
 *       KB_TRUE;
 */
LOCAL boolean sad_abIsPrevStepFinished[KU8_MAX_SOLENOID_NB] =
{
      KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE
};

/**
 * \brief
 *       Used to store each solenoid duration status, which represents if
 *       the defined duration of the current step was reached.
 *
 * \initialization
 *       KB_FALSE (boolean 0)
 *
 * \range
 *       KB_FALSE
 *       KB_TRUE;
 */
LOCAL boolean sad_abIsTimerElapsed[KU8_MAX_SOLENOID_NB] =
{
      KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE
};

/**
 * \brief
 *       Store the status of the trigger-off option if is configured for
 *       the current step of each solenoid. If the option is set and
 *       the unlock confirmation is confirmed for the current solenoid,
 *       the flag is set.
 *
 * \initialization
 *       KB_FALSE (boolean 0)
 *
 * \range
 *       KB_FALSE
 *       KB_TRUE;
 */
LOCAL boolean sad_abIsTrigOff[KU8_MAX_SOLENOID_NB] =
{
      KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE, KB_FALSE
};

#define SAD_STOP_SEC_VAR_INIT_BOOL_ASIL_A
#include "SAD_MemMap.h"


#define SAD_START_SEC_VAR_INIT_8_ASIL_A
#include "SAD_MemMap.h"

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

LOCAL uint8 sad_u8SolenoidLastIndex = KU8_SOLENOID_1;

/**
 *\brief
 *     The variable used to store the Infinite step reached status check on the
 *     last step.
 *
 * \initialization
 *       KU8_ZERO (uint8 0x00)
 *
 * \range
 *       0..KU8_MAX.
 */
LOCAL uint8 sad_u8PrevSolenoidSolenoidInfiniteStepReached = KU8_ZERO;

/**
 *\brief
 *     The variable used to store the state of the ON_OFF_PWR switch.
 *
 * \initialization
 *       KU8_ZERO (uint8 0x00)
 *
 * \range
 *       0..KU8_MAX.
 */
LOCAL uint8 sad_u8PrevOnOffPwrSwitch = KU8_FALSE;

/**
 *\brief
 *       Variable used to store the bit mask which represents if a solenoid has
 *       an active profile request from FSM.
 *
 * \initialization
 *       KU8_ZERO ((uint8) 0x00)
 *
 * \range
 *       0..KU8_MAX;
 */
LOCAL uint8 sad_u8SolenoidActiveProfile = KU8_ZERO;

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
LOCAL uint8 sad_u8LockAllSolCnt = KU8_ZERO;

/**
 * \brief
 *       Store the counter value which represents the index of the currently
 *       executing step from a profile.
 *
 * \initialization
 *       KU8_ZERO (uint8 0x00)
 *
 * \range
 *       0..KU8_MAX.
 */
LOCAL uint8 sad_au8StepIdx[KU8_MAX_SOLENOID_NB] =
{
      KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO
};

/**
 * \brief
 *       Store the counter value which represents the index of the previously
 *       executed step from a profile.
 *
 * \initialization
 *       KU8_ZERO (uint8 0x00)
 *
 * \range
 *       0..KU8_MAX;
 */
LOCAL uint8 sad_au8PrevStepIdx[KU8_MAX_SOLENOID_NB] =
{
      KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO
};

/**
 *\brief
 *     The variable used to store the solenoid profile request which should be
 *     run.
 *
 * \initialization
 *       KU8_PROFILE_NONE (255U)
 *
 * \range
 *       KU8_PROFILE_UNLOCK
 *       KU8_PROFILE_BACKUP
 *       KU8_PROFILE_DIAGNOSTIC
 *       KU8_PROFILE_NONE;
 */
LOCAL uint8 sad_au8SelectedProfile[KU8_MAX_SOLENOID_NB] =
{
      KU8_PROFILE_NONE, KU8_PROFILE_NONE, KU8_PROFILE_NONE,
      KU8_PROFILE_NONE, KU8_PROFILE_NONE, KU8_PROFILE_NONE
};

/**
 *\brief
 *     The variable used to store the last solenoid profile request which was
 *     active.
 *
 * \initialization
 *       KU8_PROFILE_UNLOCK (0U)
 *
 * \range
 *       KU8_PROFILE_UNLOCK
 *       KU8_PROFILE_BACKUP
 *       KU8_PROFILE_DIAGNOSTIC
 *       KU8_PROFILE_NONE;
 */
LOCAL uint8 sad_au8PrevSelectedProfile[KU8_MAX_SOLENOID_NB] =
{
      KU8_PROFILE_UNLOCK, KU8_PROFILE_UNLOCK, KU8_PROFILE_UNLOCK,
      KU8_PROFILE_UNLOCK, KU8_PROFILE_UNLOCK, KU8_PROFILE_UNLOCK
};

/**
 *\brief
 *     The variable used to store the last solenoid profile request which was
 *     active but only if the PWM cut-off variant is active.
 *
 * \initialization
 *       KU8_PROFILE_NONE (255U)
 *
 * \range
 *       KU8_PROFILE_UNLOCK
 *       KU8_PROFILE_BACKUP
 *       KU8_PROFILE_DIAGNOSTIC
 *       KU8_PROFILE_NONE;
 */
LOCAL uint8 sad_au8PrevSelectedProfilePwmCutOff[KU8_MAX_SOLENOID_NB] =
{
      KU8_PROFILE_NONE, KU8_PROFILE_NONE, KU8_PROFILE_NONE,
      KU8_PROFILE_NONE, KU8_PROFILE_NONE, KU8_PROFILE_NONE
};

/**
 *\brief
 *     Variable stores the status of the Short to ground and Open circuit
 *     auto-tests. If both auto-tests were run at least once after powering on,
 *     the status should be changed to KU8_TRUE.
 *
 * \initialization
 *       KU8_FALSE (uint8 0x55)
 *
 * \range
 *       KU8_FALSE
 *       KU8_TRUE;
 */
LOCAL uint8 sad_au8SolenoidAutotestsFinished[KU8_MAX_SOLENOID_NB] =
{
      KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE
};

/**
 *\brief
 *       Variable stores the order type configured for each step.
 *
 * \initialization
 *       KU8_ZERO (uint8 0x00)
 *
 * \range
 *       KU8_ZERO
 *       KU8_SAD_NO_STEP_TYPE
 *       KU8_SAD_PWM_ORDER_TYPE;
 */
LOCAL uint8 sad_au8OrderOut[KU8_MAX_SOLENOID_NB] =
{
      KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO
};

/**
 *\brief
 *       Variable stores the status of the current executed step of each solenoid.
 *
 * \initialization
 *       KU8_ZERO (uint8 0x00)
 *
 * \range
 *       KU8_SAD_INVALID_STEP
 *       KU8_SAD_NEW_STEP
 *       KU8_SAD_ON_GOING_STEP;
 */
LOCAL uint8 sad_au8CurrentStepStatus[KU8_MAX_SOLENOID_NB] =
{
      KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO
};

/**
 *\brief
 *     This variable stores the step ID of each solenoid that was last
 *     time executed.
 *
 * \initialization
 *       KU8_ZERO (uint8 0x00)
 *
 * \range
 *       0..KU8_MAX.
 */
LOCAL uint8 sad_au8PrevStepToExecute[KU8_MAX_SOLENOID_NB] =
{
      KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO
};

#define SAD_STOP_SEC_VAR_INIT_8_ASIL_A
#include "SAD_MemMap.h"

#define SAD_START_SEC_VAR_INIT_16_ASIL_A
#include "SAD_MemMap.h"

/**
 *\brief
 *     Used to store the counter value of each solenoid which will represent
 *     the time passed before the detection of the lock action will reach
 *     the timeout value.
 *
 *     1 lsb = function call (currently called at each 1ms)
 *
 * \initialization
 *      KU16_ZERO (uint16 0)
 *
 * \range
 *       0..KU16_MAX.
 */
LOCAL uint16 sad_au16LockDetectionTimeout[KU8_MAX_SOLENOID_NB] =
{
      KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};

/**
 *\brief
 *     Used to store the counter value of each solenoid which will represent
 *     the time passed running the current step.
 *
 *     1 lsb = function call (currently called at each 1ms)
 *
 * \initialization
 *      KU16_ZERO (uint16 0)
 *
 * \range
 *       0..KU16_MAX.
 */
LOCAL uint16 sad_au16CurrentTime[KU8_MAX_SOLENOID_NB] =
{
      KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};

/**
 *\brief
 *     Used to store the counter value of the variable sad_au16CurrentTime
 *     at the end of a cycle.
 *
 *     1 lsb = function call (currently called at each 1ms)
 *
 * \initialization
 *      KU16_ZERO (uint16 0)
 *
 * \range
 *       0..KU16_MAX.
 */
LOCAL uint16 sad_au16PrevTime[KU8_MAX_SOLENOID_NB] =
{
      KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};

/**
 *\brief
 *     The variable used to store the PWM duty cycle was calculated.
 *
 * \initialization
 *      KU16_ZERO (uint16 0)
 *
 * \range
 *       0..KU16_MAX.
 */
LOCAL uint16 sad_au16Consign[KU8_MAX_SOLENOID_NB] =
{
      KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};

/**
 *\brief
 *     The variable used to store the last value of consign at the end of the cycle.
 *
 * \initialization
 *      KU16_ZERO (uint16 0)
 *
 * \range
 *       0..KU16_MAX.
 */
LOCAL uint16 sad_au16PrevConsign[KU8_MAX_SOLENOID_NB] =
{
      KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};

/**
 *\brief
 *     The variable used to store the PWM duty cycle.
 *
 * \initialization
 *      KU16_SAD_NINETY_NINE_PER_PWM (uint16 32767)
 *
 * \range
 *       0..KU16_MAX.
 */
LOCAL uint16 sad_au16DutyCycle[KU8_MAX_SOLENOID_NB] =
{
      KU16_SAD_NINETY_NINE_PER_PWM, KU16_SAD_NINETY_NINE_PER_PWM, KU16_SAD_NINETY_NINE_PER_PWM,
      KU16_SAD_NINETY_NINE_PER_PWM, KU16_SAD_NINETY_NINE_PER_PWM, KU16_SAD_NINETY_NINE_PER_PWM
};

/**
 *\brief
 *     The variable used to store the previous PWM duty cycle.
 *
 * \initialization
 *      KU16_ZERO (uint16 0)
 *
 * \range
 *       0..KU16_MAX.
 */
LOCAL uint16 sad_au16PrevDutyCycle[KU8_MAX_SOLENOID_NB] =
{
      KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};

/**
 *\brief
 *     The variable used to store the calculated slope value.
 *
 * \initialization
 *      KS16_ZERO (sint16 0)
 *
 * \range
 *       KS16_MIN..KS16_MAX.
 */
LOCAL sint16 sad_as16SlopeValue[KU8_MAX_SOLENOID_NB] =
{
      KS16_ZERO, KS16_ZERO, KS16_ZERO, KS16_ZERO, KS16_ZERO, KS16_ZERO
};

/**
 *\brief
 *     The variable used to store the previously calculated slope value.
 *
 * \initialization
 *      KS16_ZERO (sint16 0)
 *
 * \range
 *       KS16_MIN..KS16_MAX.
 */

LOCAL sint16 sad_as16PrevSlopeValue[KU8_MAX_SOLENOID_NB] =
{
      KS16_ZERO, KS16_ZERO, KS16_ZERO, KS16_ZERO, KS16_ZERO, KS16_ZERO
};

#define SAD_STOP_SEC_VAR_INIT_16_ASIL_A
#include "SAD_MemMap.h"

#define SAD_START_SEC_VAR_INIT_32_ASIL_A
#include "SAD_MemMap.h"

/**
 *\brief
 *     This variable stores the value in mA of the current executed step.
 *
 * \initialization
 *       KU32_ZERO (uint32 0x00)

 */
LOCAL uint32 sad_u32CurrentTargetInMilliA[KU8_MAX_SOLENOID_NB] = {
   KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO
};

#define SAD_STOP_SEC_VAR_INIT_32_ASIL_A
#include "SAD_MemMap.h"

#define SAD_START_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
#include "SAD_MemMap.h"

/**
 *\brief
 *     The variable used to store the current step characteristics from NVP.
 *
 * \initialization
 *      Duration  - KU16_ZERO (uint16 0)
 *      Order     - KU8_ZERO (uint8 0)
 *      Consign   - KU8_ZERO (uint8 0)
 *      Ramp      - KB_FALSE (boolean 0)
 *      Infinite  - KB_FALSE (boolean 0)
 *      TrigOff   - KB_FALSE (boolean 0)
 */
LOCAL sad_stStepParam sad_astStep[KU8_MAX_SOLENOID_NB] = {
   { KU16_ZERO, KU8_ZERO, KU8_ZERO, KB_FALSE, KB_FALSE, KB_FALSE },
   { KU16_ZERO, KU8_ZERO, KU8_ZERO, KB_FALSE, KB_FALSE, KB_FALSE },
   { KU16_ZERO, KU8_ZERO, KU8_ZERO, KB_FALSE, KB_FALSE, KB_FALSE },
   { KU16_ZERO, KU8_ZERO, KU8_ZERO, KB_FALSE, KB_FALSE, KB_FALSE },
   { KU16_ZERO, KU8_ZERO, KU8_ZERO, KB_FALSE, KB_FALSE, KB_FALSE },
   { KU16_ZERO, KU8_ZERO, KU8_ZERO, KB_FALSE, KB_FALSE, KB_FALSE }
};

#define SAD_STOP_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
#include "SAD_MemMap.h"

#define SAD_START_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A
#include "SAD_MemMap.h"

/**
 *\brief
 *     The variable used to store the step characteristics from NVP.
 */
LOCAL sad_stStepParamCollection sad_astStepCollection[KU8_MAX_SOLENOID_NB];

#define SAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A
#include "SAD_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

#define SAD_START_SEC_VAR_INIT_8_ASIL_A
#include "SAD_MemMap.h"

/**
 *\brief
 *     The variable used to store each bit is the state of the corresponding
 *     solenoid. The bit will be set when the current executed step has the
 *     infinite option active.
 *
 * \initialization
 *       KU8_ZERO (uint8 0x00)
 *
 * \range
 *       0..KU8_MAX.
 */
EXPORTED uint8 SAD_u8SolenoidInfiniteStepReached = KU8_ZERO;

/**
 *\brief
 *     Store a bit mask in which, each bit represents a solenoid. If the bit
 *     is SET the solenoid is used, else if the bit is CLEAR the solenoid is not
 *     used.
 *
 * \initialization
 *      KU8_ZERO (uint8 0x00)
 *
 * \range
 *       0..KU8_MAX.
 */
EXPORTED uint8 SAD_u8SolenoidUsedBitMask = KU8_ZERO;

/**
 *\brief
 *       This variable stores the step ID which will be executed for each solenoid.
 *
 * \initialization
 *       KU8_SAD_UNDEFINED_STEP (uint8 255)
 *
 * \range
 *       0...KU8_MAX.
 */
EXPORTED uint8 SAD_au8StepToExecute[KU8_MAX_SOLENOID_NB] =
{
      KU8_SAD_UNDEFINED_STEP, KU8_SAD_UNDEFINED_STEP, KU8_SAD_UNDEFINED_STEP,
      KU8_SAD_UNDEFINED_STEP, KU8_SAD_UNDEFINED_STEP, KU8_SAD_UNDEFINED_STEP
};

#define SAD_STOP_SEC_VAR_INIT_8_ASIL_A
#include "SAD_MemMap.h"
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
#define SAD_START_SEC_CONST_UNSPECIFIED_ASIL_A
#include "SAD_MemMap.h"

/**
 * \brief
 *       This array holds the configuration mask of each solenoid based on what
 *       flag to check.
 * \initialization
 *       {KU64_SOLENOID_X_CONFIGURED}
 *       where X - the solenoid number
 *
 * \range
 *       0..KU64_MAX;
 */
LOCAL const uint64 sad_kau64SolenoidConfigMask[KU8_MAX_SOLENOID_NB] =
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
 *       0..KU64_MAX.
 */
LOCAL const uint64 sad_kau64SolenoidUnlockConfirmedMask[KU8_MAX_SOLENOID_NB] =
{
   /* Solenoid 1 */ (KU64_SOLENOID_1_UNLOCK_CONFIRMED),
   /* Solenoid 2 */ (KU64_SOLENOID_2_UNLOCK_CONFIRMED),
   /* Solenoid 3 */ (KU64_SOLENOID_3_UNLOCK_CONFIRMED),
   /* Solenoid 4 */ (KU64_SOLENOID_4_UNLOCK_CONFIRMED),
   /* Solenoid 5 */ (KU64_SOLENOID_5_UNLOCK_CONFIRMED),
   /* Solenoid 6 */ (KU64_SOLENOID_6_UNLOCK_CONFIRMED)
};

#define SAD_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
#include "SAD_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/
/**
 * \brief
 *       Check if Auto-test was finished in the current cycle.
 *       A logical '1' shall indicate that the DTC test has not run to
 *       completion during the current operation cycle.
 *       If the test runs and passes or fails then the bit shall be set
 *       (and latched) to '0' until a new operation cycle is started.
 */
#define KU8_SAD_EVENT_COMPLETED(EventStatus) \
         (KU8_ZERO == ((EventStatus) & (DEM_UDS_STATUS_TNCTOC)))

/**
 * \brief
 *       Check if Auto-test was failed in the current cycle.
 *       A logical '1' shall indicate that the DTC test has failed
 *       during the current operation cycle.
 */
#define KU8_SAD_EVENT_FAILED(EventStatus) \
         (DEM_UDS_STATUS_TF == ((EventStatus) & (DEM_UDS_STATUS_TF)))

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
#define SAD_START_SEC_CODE_ASIL_A
#include "SAD_MemMap.h"

/**
* \brief
*        This function is used to manage the solenoid circuitry (boost control,
*        solenoid enabled and solenoids ON/OFF system);
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        None.
* \dynamicaspectcaller
*        SAD_runMainFunction
* \dynamicaspectdescription
*        The local function is called by the function SAD_runMainFunction.
* \constraints
*        None.
* \ddesignrequirement
*        DSG_sad_ControlSolenoidsCircuitry
* \archrequirement
*        ARCH_SW_SAD_pclModeManagement
*        ARCH_SW_SAD_pclDioIfServices;
**/
LOCAL void sad_ControlSolenoidsCircuitry(void)
{
   uint8 u8SolenoidProfileUnderExecution = KU8_FALSE;
   uint8 u8BatteryUnstableModeStatus;
   uint8 u8SolenoidIdx;
   uint8 au8SolenoidStates[KU8_MAX_SOLENOID_NB];
   uint8 u8SolenoidDisableMask = KU8_ZERO;

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_ECU_BATTERY_UNSTABLE, &u8BatteryUnstableModeStatus);
   (void)Rte_Read_SAD_prrSolenoidState_au8SolenoidState((uint8 *)au8SolenoidStates);

   for(u8SolenoidIdx = KU8_ZERO; u8SolenoidIdx < KU8_MAX_SOLENOID_NB; u8SolenoidIdx++)
   {
      if((KU8_DISABLED_STATE == au8SolenoidStates[u8SolenoidIdx]) && (KB_TRUE == KB_SAD_SOLENOID_CONFIGURED(u8SolenoidIdx)))
      {
         u8SolenoidDisableMask |=  (uint8)(KU8_ONE << u8SolenoidIdx);
      }
   }

   for(u8SolenoidIdx = KU8_ZERO; ((u8SolenoidIdx < KU8_MAX_SOLENOID_NB) && (KU8_FALSE == u8SolenoidProfileUnderExecution)); u8SolenoidIdx++)
   {
      /* check if at least one solenoid is executing a profile */
      if (KU8_PROFILE_NONE != sad_au8SelectedProfile[u8SolenoidIdx])
      {
         /* Turn on whole current source/boost circuit due to faulty OpAmp in HW4 ToDo: Remove */
         Rte_Call_pclDioIfServices_WriteChannel(DIOIF_CH_ON_OFF_POWER, STD_HIGH);

         /* set pin state for next power main function execution */
         sad_u8PrevOnOffPwrSwitch = KU8_FALSE;

         /* Check if all solenoids are in an infinite step */
         if((sad_u8PrevSolenoidSolenoidInfiniteStepReached | u8SolenoidDisableMask) == SAD_u8SolenoidUsedBitMask)
         {
            /* Turn off the booster */
            Rte_Call_pclDioIfServices_WriteChannel(DIOIF_CH_EN_BOOST, STD_LOW);
         }
         else
         {
            if(KU8_TRUE == u8BatteryUnstableModeStatus)
            {
               /* Turn off the booster */
               Rte_Call_pclDioIfServices_WriteChannel(DIOIF_CH_EN_BOOST, STD_LOW);
            }
            else
            {
               /* Turn on the booster */
               Rte_Call_pclDioIfServices_WriteChannel(DIOIF_CH_EN_BOOST, STD_HIGH);
            }
         }

         /* exit for loop */
         u8SolenoidProfileUnderExecution = KU8_TRUE;
      }
      else
      {
         /* check if profile is KU8_PROFILE_NONE for all solenoids */
         if(((u8SolenoidIdx == (KU8_MAX_SOLENOID_NB - KU8_ONE)) && (KB_TRUE == KUB_eCS_LOCK_CUTOFF_VARIANT)) ||
            ((u8SolenoidIdx == (KU8_MAX_SOLENOID_NB - KU8_ONE)) && (KB_TRUE == KUB_eCS_LOCK_99_PWM_VARIANT) && (sad_au16LockDetectionTimeout[u8SolenoidIdx] >= KU16_SAD_LOCK_DETECTION_TIMEOUT)))
         {
            if(KU8_TRUE == u8BatteryUnstableModeStatus)
            {
               /* Turn off the booster */
               Rte_Call_pclDioIfServices_WriteChannel(DIOIF_CH_EN_BOOST, STD_LOW);
            }
            else
            {
               /* Turn on the booster */
               Rte_Call_pclDioIfServices_WriteChannel(DIOIF_CH_EN_BOOST, STD_HIGH);
            }

            if(KU8_TRUE == sad_u8PrevOnOffPwrSwitch)
            {
               /* Turn off whole current source/boost circuit due to faulty OpAmp in HW4 ToDo: Remove */
               Rte_Call_pclDioIfServices_WriteChannel(DIOIF_CH_ON_OFF_POWER, STD_LOW);
            }

            /* set pin state for next main function execution */
            sad_u8PrevOnOffPwrSwitch = KU8_TRUE;

            /* Reset the solenoid infinite step execution flags */
            SAD_u8SolenoidInfiniteStepReached = KU8_ZERO;
            sad_u8PrevSolenoidSolenoidInfiniteStepReached = KU8_ZERO;
         }
      }
   }
}

/**
* \brief
*        This function is used to manage the solenoid profile execution by
*        extracting the profile and assigned steps from NVP variables and
*        supervising the execution of each step of the profile.
* \inputparam
*        Name: ku8SolenoidIdx;
*        Type: const uint8;
*        Description: The id of the solenoid;
*        Range: 0..5;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        None.
* \dynamicaspectcaller
*        SAD_runMainFunction
* \dynamicaspectdescription
*        The local function is called by the function SAD_runMainFunction.
* \constraints
*        The function is called only for enabled solenoids.
* \ddesignrequirement
*        DSG_sad_runSolenoidControl
* \archrequirement
*        ARCH_SW_SAD_ptrpAsrOsServices
*        ARCH_SW_SAD_pclDioIfServices
*        ARCH_SW_SAD_pclPwmServices
**/
LOCAL INLINE void sad_runSolenoidControl(const uint8 ku8SolenoidIdx)
{
   register uint8 u8IsPwmEnable = KU8_FALSE;
   uint32 u32FirstStepConsignValue;

   /* select the current step that has to be executed based on u8SolenoidIdx */
   sad_SelectStepId(ku8SolenoidIdx);

   /* extract option flags from step definition based on the selected step */
   sad_StepPreprocessing(ku8SolenoidIdx);

   /* execute the selected step based on the option flags*/
   sad_ControlStepExecution(ku8SolenoidIdx);

   u32FirstStepConsignValue = (uint32)(((uint32)(KU8_SAD_STEP_0[(KU8_SAD_UNLOCK_PROFILE[KU8_SAD_INDEX_OF_FIRST_STEP] * KU8_SAD_STEP_SIZE) + KU8_TWO]) << KU8_TWENTYFOUR) |
         ((uint32)(KU8_SAD_STEP_0[(KU8_SAD_UNLOCK_PROFILE[KU8_SAD_INDEX_OF_FIRST_STEP] * KU8_SAD_STEP_SIZE) + KU8_THREE]) << KU8_SIXTEEN) |
         ((uint32)(KU8_SAD_STEP_0[(KU8_SAD_UNLOCK_PROFILE[KU8_SAD_INDEX_OF_FIRST_STEP] * KU8_SAD_STEP_SIZE) + KU8_FOUR]) << KU8_EIGHT) |
         (uint32)(KU8_SAD_STEP_0[(KU8_SAD_UNLOCK_PROFILE[KU8_SAD_INDEX_OF_FIRST_STEP] * KU8_SAD_STEP_SIZE) + KU8_FIVE]));

   /* treat LOCK request */
   if (KU8_PROFILE_NONE == sad_au8SelectedProfile[ku8SolenoidIdx])
   {
      /* if the PWM cut-off variant is currently configured */
      if(KB_TRUE == KUB_eCS_LOCK_99_PWM_VARIANT)
      {
         /* check the last executed profile to see if you have a UNLOCK/BACKUP profile to LOCK transition */
         if(KU8_PROFILE_NONE != sad_au8PrevSelectedProfilePwmCutOff[ku8SolenoidIdx])
         {
            /* set the PWM to the highest possible value in order to set the lowest possible current */
            sad_au16DutyCycle[ku8SolenoidIdx] = KU16_SAD_NINETY_NINE_PER_PWM;

            /* Ensure enable pin is set to STD_LOW in order for the low current value to have an effect */
            Rte_Call_pclDioIfServices_WriteChannel((uint8)(DIOIF_CH_EN_CS_1 + ku8SolenoidIdx), STD_LOW);

            /* check if the configured timeout has expired before reseting the PWM value from 99% to the value configured in the first step (e.g. 70%) */
            if (KU16_SAD_LOCK_DETECTION_TIMEOUT > sad_au16LockDetectionTimeout[ku8SolenoidIdx])
            {
               sad_au16LockDetectionTimeout[ku8SolenoidIdx] += KU16_CNT_INCR_STEP;
            }
            else
            {
               /* reset the counter and previously executed profile */
               sad_au16LockDetectionTimeout[ku8SolenoidIdx] = KU16_ZERO;
               sad_au8PrevSelectedProfilePwmCutOff[ku8SolenoidIdx] = KU8_PROFILE_NONE;
            }
         }
         else
         {
            /* set the PWM value to the value configured in the first step (e.g. 70%) */
            sad_au16DutyCycle[ku8SolenoidIdx] = (uint16)(((u32FirstStepConsignValue/KU32_TEN) * (uint32)KU16_SAD_MAX_PWM_LSB) / KU32_SAD_MAX_PWM);

            /* set cut-off (enable pin to STD_LOW) if nothing was executed */
            Rte_Call_pclDioIfServices_WriteChannel((uint8)(DIOIF_CH_EN_CS_1 + ku8SolenoidIdx), STD_HIGH);
         }
      }
      else
      {
         /* set the PWM value to the value configured in the first step (e.g. 70%) */
         sad_au16DutyCycle[ku8SolenoidIdx] = (uint16)(((u32FirstStepConsignValue / KU32_TEN) * (uint32)KU16_SAD_MAX_PWM_LSB) / KU32_SAD_MAX_PWM);

         /* set cut-off */
         Rte_Call_pclDioIfServices_WriteChannel((uint8)(DIOIF_CH_EN_CS_1 + ku8SolenoidIdx), STD_HIGH);
      }
   }
   /* treat UNLOCK or BACKUP profile request */
   else
   {
      switch (sad_au8OrderOut[ku8SolenoidIdx])
      {
         /* if step is configured in PWM */
         case KU8_SAD_PWM_ORDER_TYPE:
         {
            u8IsPwmEnable = KU8_TRUE;

            if (KS16_ZERO != sad_as16PrevSlopeValue[ku8SolenoidIdx])
            {
               /* Treat case where PWM needs to increase or decrease in a ramp */
               sad_au16DutyCycle[ku8SolenoidIdx] = (uint16) (sad_au16PrevDutyCycle[ku8SolenoidIdx] + sad_as16PrevSlopeValue[ku8SolenoidIdx]);
            }
            else
            {
               if(KU16_ZERO == sad_au16PrevConsign[ku8SolenoidIdx])
               {
                  /* set the PWM value to the value configured in the first step (e.g. 70%) */
                  sad_au16DutyCycle[ku8SolenoidIdx] = (uint16)(((u32FirstStepConsignValue / KU32_TEN) * (uint32) KU16_SAD_MAX_PWM_LSB) / KU32_SAD_MAX_PWM);
               }
               else
               {
                  /* keep the last value */
                  sad_au16DutyCycle[ku8SolenoidIdx] = sad_au16PrevConsign[ku8SolenoidIdx];
               }
            }
            break;
         }
         default:
         {
            /* disable PWM output since step is not configured correctly */
            u8IsPwmEnable = KU8_FALSE;

            /* set PWM to 99% in order to have the lowest possible current */
            sad_au16DutyCycle[ku8SolenoidIdx] = KU16_SAD_NINETY_NINE_PER_PWM;
            break;
         }
      }

      /* if PWM is enabled then enable the solenoid output */
      if (KU8_TRUE == u8IsPwmEnable)
      {
         Rte_Call_pclDioIfServices_WriteChannel((uint8)(DIOIF_CH_EN_CS_1 + ku8SolenoidIdx), STD_LOW);
      }
      else
      {
         /* if PWM is disabled then disable the solenoid output */
         if(KB_TRUE == KUB_eCS_LOCK_CUTOFF_VARIANT)
         {
            /* set cut-off */
            Rte_Call_pclDioIfServices_WriteChannel((uint8)(DIOIF_CH_EN_CS_1 + ku8SolenoidIdx), STD_HIGH);
         }
         /* if the PWM cut-off variant is currently configured */
         else if(KB_TRUE == KUB_eCS_LOCK_99_PWM_VARIANT)
         {
            /* set cut-off with 99% PWM */
            sad_au16DutyCycle[ku8SolenoidIdx] = KU16_SAD_NINETY_NINE_PER_PWM;
         }
         else
         {
            /* do nothing */
         }
      }

      /* if the PWM cut-off variant is currently configured */
      if(KB_TRUE == KUB_eCS_LOCK_99_PWM_VARIANT)
      {
         /* save the last executed profile in order to know if you have to insert a delay before setting the cut-off pin */
         sad_au8PrevSelectedProfilePwmCutOff[ku8SolenoidIdx] = sad_au8SelectedProfile[ku8SolenoidIdx];
      }
   }
   Rte_Call_pclPwmServices_SetDutyCycle((uint8)(PWMIF_CH_SOLENOID_1 + ku8SolenoidIdx), sad_au16DutyCycle[ku8SolenoidIdx]);

   /* check if any step events have occurred */
   sad_ManageStepEvents(ku8SolenoidIdx);

   sad_au8PrevStepToExecute[ku8SolenoidIdx]     = SAD_au8StepToExecute[ku8SolenoidIdx];
   sad_au8PrevSelectedProfile[ku8SolenoidIdx]   = sad_au8SelectedProfile[ku8SolenoidIdx];
   sad_au16PrevConsign[ku8SolenoidIdx]          = sad_au16Consign[ku8SolenoidIdx];
   sad_as16PrevSlopeValue[ku8SolenoidIdx]       = sad_as16SlopeValue[ku8SolenoidIdx];
   sad_au16PrevDutyCycle[ku8SolenoidIdx]        = sad_au16DutyCycle[ku8SolenoidIdx];
   sad_abIsPrevStepFinished[ku8SolenoidIdx]     = sad_abIsStepFinished[ku8SolenoidIdx];
   sad_au16PrevTime[ku8SolenoidIdx]             = sad_au16CurrentTime[ku8SolenoidIdx];
   sad_au8PrevStepIdx[ku8SolenoidIdx]           = sad_au8StepIdx[ku8SolenoidIdx];
}

/**
* \brief
*        This function is used to manage the state of the current step.
*        Checks if the current step was finished or is still running.
* \inputparam
*        Name: ku8SolenoidIdx;
*        Type: const uint8;
*        Description: The id of the solenoid;
*        Range: 0..5;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        None.
* \dynamicaspectcaller
*        sad_runSolenoidControl
* \dynamicaspectdescription
*        The local function is called by the function sad_runSolenoidControl.
* \constraints
*        The function is called only for enabled solenoids.
* \ddesignrequirement
*        DSG_sad_ManageStepEvents
* \archrequirement
*        ARCH_SW_SAD_ptrpAsrOsServices
**/
LOCAL INLINE void sad_ManageStepEvents(const uint8 ku8SolenoidIdx)
{

   if ((KU8_SAD_NEW_STEP == sad_au8CurrentStepStatus[ku8SolenoidIdx]) || (KU8_SAD_ON_GOING_STEP == sad_au8CurrentStepStatus[ku8SolenoidIdx]))
   {
      if ((KB_TRUE == sad_abIsTimerElapsed[ku8SolenoidIdx]) || (KB_TRUE == sad_abIsTrigOff[ku8SolenoidIdx]))
      {
         sad_abIsStepFinished[ku8SolenoidIdx] = KB_TRUE;
      }
      else
      {
         sad_abIsStepFinished[ku8SolenoidIdx] = KB_FALSE;
      }
   }
   else
   {
      sad_abIsStepFinished[ku8SolenoidIdx] = KB_TRUE;
   }
}

/**
* \brief
*        This function is used to manage the selection of the step to be executed
*        based on the previous step status (if was finished or not) and the
*        profile.
* \inputparam
*        Name: ku8SolenoidIdx;
*        Type: const uint8;
*        Description: The id of the solenoid;
*        Range: 0..5;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        None.
* \dynamicaspectcaller
*        sad_runSolenoidControl
* \dynamicaspectdescription
*        The local function is called by the function sad_runSolenoidControl.
* \constraints
*        The function is called only for enabled solenoids.
* \ddesignrequirement
*        DSG_sad_SelectStepId
* \archrequirement
*        ARCH_SW_SAD_ptrpAsrOsServices
**/
LOCAL INLINE void sad_SelectStepId(const uint8 ku8SolenoidIdx)
{
   register uint8 u8UnfilteredStepId = KU8_MAX;
   register uint8 u8FilteredStepIdx;
   uint8 au8StepBytePosition[KU8_MAX_SOLENOID_NB] =
   {
         KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO
   };

   if (KU8_SAD_NB_MAX_PROFILES_LIB <= sad_au8SelectedProfile[ku8SolenoidIdx])
   {
      SAD_au8StepToExecute[ku8SolenoidIdx] = KU8_SAD_UNDEFINED_STEP;
   }
   else
   {
      if ((sad_au8SelectedProfile[ku8SolenoidIdx] != sad_au8PrevSelectedProfile[ku8SolenoidIdx]) ||
          (KU8_SAD_UNDEFINED_STEP == sad_au8PrevStepToExecute[ku8SolenoidIdx]))
      {
         u8UnfilteredStepId = KU8_ZERO;
      }
      else
      {
         if (KB_TRUE == sad_abIsPrevStepFinished[ku8SolenoidIdx])
         {
            u8UnfilteredStepId = sad_au8PrevStepIdx[ku8SolenoidIdx] + KU8_ONE;
         }
         else
         {
            u8UnfilteredStepId = sad_au8PrevStepIdx[ku8SolenoidIdx];
         }
      }

      u8FilteredStepIdx = u8UnfilteredStepId + (sad_au8SelectedProfile[ku8SolenoidIdx] * KU8_SAD_PROFILE_SIZE);

      if (KU8_SAD_MAX_STEP_INDEX <= u8UnfilteredStepId)
      {
         SAD_au8StepToExecute[ku8SolenoidIdx] = KU8_SAD_UNDEFINED_STEP;
      }
      else
      {
         au8StepBytePosition[ku8SolenoidIdx] = u8FilteredStepIdx + KU8_SAD_INDEX_OF_FIRST_STEP;

         if (KU8_SAD_NB_MAX_STEPS_LIB <= KU8_SAD_UNLOCK_PROFILE[au8StepBytePosition[ku8SolenoidIdx]])
         {
            SAD_au8StepToExecute[ku8SolenoidIdx] = KU8_SAD_UNDEFINED_STEP;
         }
         else
         {
            SAD_au8StepToExecute[ku8SolenoidIdx] = KU8_SAD_UNLOCK_PROFILE[au8StepBytePosition[ku8SolenoidIdx]];
         }
      }
   }

   if (KU8_SAD_UNDEFINED_STEP <= SAD_au8StepToExecute[ku8SolenoidIdx])
   {
      sad_au8StepIdx[ku8SolenoidIdx] = KU8_ZERO;
   }
   else
   {
      sad_au8StepIdx[ku8SolenoidIdx] = u8UnfilteredStepId;
   }
}

/**
* \brief
*        This function is used to manage the execution of each step based on
*        the option, duration, PWM and previous step executed.
* \inputparam
*        Name: ku8SolenoidIdx;
*        Type: const uint8;
*        Description: The id of the solenoid;
*        Range: 0..5;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        None.
* \dynamicaspectcaller
*        sad_runSolenoidControl
* \dynamicaspectdescription
*        The local function is called by the function sad_runSolenoidControl.
* \constraints
*        The function is called only for enabled solenoids.
* \ddesignrequirement
*        DSG_sad_ControlStepExecution
* \archrequirement
*        ARCH_SW_SAD_ptrpAsrOsServices
*        ARCH_SW_SAD_pclModeManagement
**/
LOCAL INLINE void sad_ControlStepExecution(const uint8 ku8SolenoidIdx)
{
   register boolean b8IsNewStepStarted;
   uint8 u8SolenoidConfirmationModeStatus;
   register uint16 u16TimerOrigin;
   register uint16 u16ScaledConsignValue;

   if(KU8_SAD_NEW_STEP == sad_au8CurrentStepStatus[ku8SolenoidIdx])
   {
      b8IsNewStepStarted = KB_TRUE;
   }
   else
   {
      b8IsNewStepStarted = KB_FALSE;
   }

   /* read solenoid confirmation mode mask in order to set the trig-off event */
      Rte_Call_pclModeManagement_CheckModeStatus(sad_kau64SolenoidUnlockConfirmedMask[ku8SolenoidIdx], &u8SolenoidConfirmationModeStatus);

   if((KB_TRUE == sad_astStep[ku8SolenoidIdx].b8IsTrigOff) && (KU8_TRUE == u8SolenoidConfirmationModeStatus))
   {
      sad_abIsTrigOff[ku8SolenoidIdx] =  KB_TRUE;
   }
   else
   {
      sad_abIsTrigOff[ku8SolenoidIdx] = KB_FALSE;
   }

   if (KB_TRUE == sad_astStep[ku8SolenoidIdx].b8IsInfinite)
   {
      sad_au16CurrentTime[ku8SolenoidIdx] = KU16_ZERO;

      if(sad_au8SelectedProfile[ku8SolenoidIdx] != KU8_PROFILE_NONE)
      {
         if(KU8_SAD_ON_GOING_STEP == sad_au8CurrentStepStatus[ku8SolenoidIdx])
         {
            /* if a step is under execution, that does have the infinite flag option, set the bit */
            SAD_u8SolenoidInfiniteStepReached |= (uint8)(KU8_ONE << ku8SolenoidIdx);
         }
         else
         {
            /* if step is invalid or new, reset the bit */
            SAD_u8SolenoidInfiniteStepReached &= (uint8)(~(uint8)(KU8_ONE << ku8SolenoidIdx));
         }
      }
   }
   else
   {
      if(sad_au8SelectedProfile[ku8SolenoidIdx] != KU8_PROFILE_NONE)
      {
         /* if a step is under execution, that does not have the infinite flag option, reset the bit */
         SAD_u8SolenoidInfiniteStepReached &= (uint8)(~(uint8)(KU8_ONE << ku8SolenoidIdx));
      }

      if ((KU8_SAD_ON_GOING_STEP == sad_au8CurrentStepStatus[ku8SolenoidIdx]) && (KB_FALSE == b8IsNewStepStarted))
      {
         u16TimerOrigin = sad_au16PrevTime[ku8SolenoidIdx];
      }
      else
      {
         u16TimerOrigin = KU16_ZERO;
      }

      sad_au16CurrentTime[ku8SolenoidIdx] = u16TimerOrigin + (KU16_CNT_INCR_STEP *KU16_TWO);

      if (KU16_ONE > sad_au16CurrentTime[ku8SolenoidIdx])
      {
         sad_au16CurrentTime[ku8SolenoidIdx] = KU16_MAX;
      }
   }

   if(sad_astStep[ku8SolenoidIdx].u16Duration <= sad_au16CurrentTime[ku8SolenoidIdx])
   {
      sad_abIsTimerElapsed[ku8SolenoidIdx] = KB_TRUE;
   }
   else
   {
      sad_abIsTimerElapsed[ku8SolenoidIdx] = KB_FALSE;
   }


   if (KB_TRUE == b8IsNewStepStarted)
   {
      if (KU8_SAD_PWM_ORDER_TYPE == sad_astStep[ku8SolenoidIdx].u8Order)
      {
         sad_au8OrderOut[ku8SolenoidIdx] = sad_astStep[ku8SolenoidIdx].u8Order;
      }
      else
      {
         sad_au8OrderOut[ku8SolenoidIdx] = KU8_SAD_NO_STEP_TYPE;
      }

      switch (sad_astStep[ku8SolenoidIdx].u8Order)
      {
         case KU8_SAD_PWM_ORDER_TYPE:
         {
            /* Convert PWM from 0-100% to 0x0000-0x8000  */
            u16ScaledConsignValue = (uint16)(((sad_astStep[ku8SolenoidIdx].u32Consign / KU32_TEN) * (uint32)KU16_SAD_MAX_PWM_LSB) / KU32_SAD_MAX_PWM);

            break;
         }
         default:
         {
            u16ScaledConsignValue = KU16_ZERO;
            break;
         }
      }

      if (KB_TRUE == sad_astStep[ku8SolenoidIdx].b8IsRamp)
      {
         sad_au16Consign[ku8SolenoidIdx] = sad_au16PrevDutyCycle[ku8SolenoidIdx];

         sad_as16SlopeValue[ku8SolenoidIdx] = (sint16)((sint32)((sint32)u16ScaledConsignValue - (sint32)sad_au16PrevDutyCycle[ku8SolenoidIdx]) /
                                                       ((sint32)(sad_astStep[ku8SolenoidIdx].u16Duration) / ((sint32)KU16_CNT_INCR_STEP * KS32_TWO)));
      }
      else
      {
         sad_au16Consign[ku8SolenoidIdx] = u16ScaledConsignValue;
         sad_as16SlopeValue[ku8SolenoidIdx] = KS16_ZERO;
      }
   }
   else
   {
      if (KU8_SAD_ON_GOING_STEP == sad_au8CurrentStepStatus[ku8SolenoidIdx])
      {
         sad_as16SlopeValue[ku8SolenoidIdx] = sad_as16PrevSlopeValue[ku8SolenoidIdx];
      }
      else
      {
         sad_au8OrderOut[ku8SolenoidIdx] = KU8_SAD_NO_STEP_TYPE;
         sad_au16Consign[ku8SolenoidIdx] = KU16_ZERO;
         sad_as16SlopeValue[ku8SolenoidIdx] = KS16_ZERO;
      }
   }
}

/**
* \brief
*        This function is used to extract the option bites from the selected
*        step.
* \inputparam
*        Name: ku8SolenoidIdx;
*        Type: const uint8;
*        Description: The id of the solenoid;
*        Range: 0..5;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        None.
* \dynamicaspectcaller
*        sad_runSolenoidControl
* \dynamicaspectdescription
*        The local function is called by the function sad_runSolenoidControl.
* \constraints
*        The function is called only for enabled solenoids.
* \ddesignrequirement
*        DSG_sad_StepPreprocessing
* \archrequirement
*        ARCH_SW_SAD_ptrpAsrOsServices
*        ARCH_SW_SAD_psrSolenoidElectricalCharacteristics
**/
LOCAL INLINE void sad_StepPreprocessing(const uint8 ku8SolenoidIdx)
{
   if (KU8_SAD_MAX_STEP <= SAD_au8StepToExecute[ku8SolenoidIdx])
   {
      sad_au8CurrentStepStatus[ku8SolenoidIdx] = KU8_SAD_INVALID_STEP;
   }
   else
   {
      if ((KU16_ZERO == sad_astStepCollection[ku8SolenoidIdx].astStepParam[SAD_au8StepToExecute[ku8SolenoidIdx]].u16Duration) ||
          (KU16_MAX == sad_astStepCollection[ku8SolenoidIdx].astStepParam[SAD_au8StepToExecute[ku8SolenoidIdx]].u16Duration) ||
          (KU8_SAD_PWM_ORDER_TYPE != sad_astStepCollection[ku8SolenoidIdx].astStepParam[SAD_au8StepToExecute[ku8SolenoidIdx]].u8Order))
      {
         sad_au8CurrentStepStatus[ku8SolenoidIdx] = KU8_SAD_INVALID_STEP;
      }
      else
      {
         if (SAD_au8StepToExecute[ku8SolenoidIdx] != sad_au8PrevStepToExecute[ku8SolenoidIdx])
         {
            sad_au8CurrentStepStatus[ku8SolenoidIdx] = KU8_SAD_NEW_STEP;
         }
         else
         {
            sad_au8CurrentStepStatus[ku8SolenoidIdx] = KU8_SAD_ON_GOING_STEP;
         }
      }

      if (KU8_SAD_NEW_STEP == sad_au8CurrentStepStatus[ku8SolenoidIdx])
      {
         sad_astStep[ku8SolenoidIdx].b8IsRamp  = sad_astStepCollection[ku8SolenoidIdx].astStepParam[SAD_au8StepToExecute[ku8SolenoidIdx]].b8IsRamp;
         sad_astStep[ku8SolenoidIdx].b8IsInfinite  = sad_astStepCollection[ku8SolenoidIdx].astStepParam[SAD_au8StepToExecute[ku8SolenoidIdx]].b8IsInfinite;
         sad_astStep[ku8SolenoidIdx].b8IsTrigOff = sad_astStepCollection[ku8SolenoidIdx].astStepParam[SAD_au8StepToExecute[ku8SolenoidIdx]].b8IsTrigOff;
         sad_astStep[ku8SolenoidIdx].u16Duration = sad_astStepCollection[ku8SolenoidIdx].astStepParam[SAD_au8StepToExecute[ku8SolenoidIdx]].u16Duration;
         sad_astStep[ku8SolenoidIdx].u32Consign = sad_astStepCollection[ku8SolenoidIdx].astStepParam[SAD_au8StepToExecute[ku8SolenoidIdx]].u32Consign;
         sad_astStep[ku8SolenoidIdx].u8Order = sad_astStepCollection[ku8SolenoidIdx].astStepParam[SAD_au8StepToExecute[ku8SolenoidIdx]].u8Order;

         /* Based on the Infinite step of the current profile, extract the PWM target (Consign) and
          * transform PWM to mA current target. */
         sad_u32CurrentTargetInMilliA[ku8SolenoidIdx] = sad_astStep[ku8SolenoidIdx].u32Consign / KU32_SAD_CORECTIVE_FACTOR;

         (void)Rte_Write_psrSolenoidElectricalCharacteristics_au32SolenoidmATarget((const uint32 *) sad_u32CurrentTargetInMilliA);
      }
   }
}

/**
* \brief
*        This function is used to extract the steps from the NVP variable at
*        the initialization step.
* \inputparam
*        Name: ku8SolenoidIdx;
*        Type: const uint8;
*        Description: The id of the solenoid;
*        Range: 0..5;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        None.
* \dynamicaspectcaller
*        SAD_Init
* \dynamicaspectdescription
*        The local function is called by the function SAD_Init.
* \constraints
*        The function is called only at the initialization step.
* \ddesignrequirement
*        DSG_sad_ExtractSteps
* \archrequirement
*        ARCH_SW_Sad_ptrpSadServicesBswMIf_SAD_Init
**/
LOCAL INLINE void sad_ExtractSteps(const uint8 ku8SolenoidIdx)
{
   register uint8 u8OptionByte;
   register uint8 u8Idx;

   for(u8Idx = KU8_ZERO; u8Idx < KU8_SAD_MAX_STEP; u8Idx++)
   {
      u8OptionByte = KU8_SAD_STEP_0[(u8Idx * KU8_SAD_STEP_SIZE) + KU8_SAD_INDEX_OF_OPTION_BYTE];

      sad_astStepCollection[ku8SolenoidIdx].astStepParam[u8Idx].u16Duration = (uint16)((uint16)(KU8_SAD_STEP_0[u8Idx * KU8_SAD_STEP_SIZE]) << KU8_EIGHT) +
                                                                              (uint16)(KU8_SAD_STEP_0[(u8Idx * KU8_SAD_STEP_SIZE) + KU8_ONE]);

      sad_astStepCollection[ku8SolenoidIdx].astStepParam[u8Idx].u32Consign =  (((uint32)(KU8_SAD_STEP_0[(u8Idx * KU8_SAD_STEP_SIZE) + KU8_TWO]) << KU8_TWENTYFOUR) |
                                                                               ((uint32)(KU8_SAD_STEP_0[(u8Idx * KU8_SAD_STEP_SIZE) + KU8_THREE]) << KU8_SIXTEEN) |
                                                                               ((uint32)(KU8_SAD_STEP_0[(u8Idx * KU8_SAD_STEP_SIZE) + KU8_FOUR]) << KU8_EIGHT) |
                                                                               (uint32)(KU8_SAD_STEP_0[(u8Idx * KU8_SAD_STEP_SIZE) + KU8_FIVE]));

      sad_astStepCollection[ku8SolenoidIdx].astStepParam[u8Idx].b8IsRamp  =      (u8OptionByte & KU8_MASK_BIT_7) >>  KU8_SEVEN;
      sad_astStepCollection[ku8SolenoidIdx].astStepParam[u8Idx].b8IsInfinite =   (u8OptionByte & KU8_MASK_BIT_6) >>  KU8_SIX;
      sad_astStepCollection[ku8SolenoidIdx].astStepParam[u8Idx].b8IsTrigOff =    (u8OptionByte & KU8_MASK_BIT_5) >>  KU8_FIVE;

      sad_astStepCollection[ku8SolenoidIdx].astStepParam[u8Idx].u8Order = (u8OptionByte & KU8_MASK_BIT_2) +
                                                                          (u8OptionByte & KU8_MASK_BIT_1) +
                                                                          (u8OptionByte & KU8_MASK_BIT_0);
   }
}

/**
* \brief
*        This function is used to request the diagnostic profile for each
*        solenoid based on specific auto-tests status.
* \inputparam
*        Name: ku8SolenoidIdx;
*        Type: const uint8;
*        Description: The id of the solenoid;
*        Range: 0..5;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        None.
* \dynamicaspectcaller
*        SAD_runMainFunction
* \dynamicaspectdescription
*        The local function is called by the function SAD_runMainFunction.
* \constraints
*        The function is called only for the enabled solenoids at each 1ms.
* \ddesignrequirement
*        DSG_sad_TriggerDiagProfile
* \archrequirement
*        ARCH_SW_SAD_ptrpAsrOsServices
*        ARCH_SW_SAD_pseDiagRequestServices
*        ARCH_SW_SAD_pclEvtActuatorOpenCircuit
*        ARCH_SW_SAD_pclEvtActuatorShortToGround
**/
LOCAL INLINE void sad_TriggerDiagProfile(const uint8 ku8SolenoidIdx)
{
   u8eCSDiagReqType au8DiagReq[KU8_MAX_SOLENOID_NB] =
   {
         KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST,
         KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST
   };

   u8eCSDiagReqType au8DiagReqComplement[KU8_MAX_SOLENOID_NB] =
   {
         KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST,
         KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST, KU8_NO_DIAG_REQUEST
   };

   uint8 u8OpenCircuitEvtStatus = KU8_ZERO;
   uint8 u8ShortToGndEvtStatus = KU8_ZERO;

   (void)Rte_Read_CIL_SAD_au8DiagReq_prrEcsDiagRequest(au8DiagReq);
   (void)Rte_Read_CIL_SAD_au8DiagReqComplement_prrEcsDiagRequest(au8DiagReqComplement);

   (void)Rte_Call_pclEvtActuatorOpenCircuit_GetEventStatus(&u8OpenCircuitEvtStatus);
   (void)Rte_Call_pclEvtActuatorShortToGround_GetEventStatus(&u8ShortToGndEvtStatus);

   /* Check if the Open Circuit and Short to GND auto-tests were performed
    * before for the specific solenoid with the Diagnostic profile */
   if(((KU8_SAD_EVENT_COMPLETED(u8OpenCircuitEvtStatus)) && (KU8_SAD_EVENT_COMPLETED(u8ShortToGndEvtStatus))) ||
          ((KU8_SAD_EVENT_FAILED(u8OpenCircuitEvtStatus)) && (KU8_SAD_EVENT_COMPLETED(u8OpenCircuitEvtStatus))) ||
          ((KU8_SAD_EVENT_FAILED(u8ShortToGndEvtStatus)) && (KU8_SAD_EVENT_COMPLETED(u8ShortToGndEvtStatus))))
   {
      if((KU8_MAX == (au8DiagReq[ku8SolenoidIdx] ^ au8DiagReqComplement[ku8SolenoidIdx])) &&
         (KU8_DIAG_PROFILE_REQUEST_ON == au8DiagReq[ku8SolenoidIdx]))
      {
         /* Clear the diagnostic request */
         au8DiagReq[ku8SolenoidIdx] = KU8_NO_DIAG_REQUEST;
         au8DiagReqComplement[ku8SolenoidIdx] = U8_COMPLEMENT((uint8)KU8_NO_DIAG_REQUEST);
      }

      sad_au8SolenoidAutotestsFinished[ku8SolenoidIdx] = KU8_TRUE;
   }
   else if (KU8_FALSE == sad_au8SolenoidAutotestsFinished[ku8SolenoidIdx])
   {
      /* Set the diagnostic request to diagnostic profile */
      au8DiagReq[ku8SolenoidIdx] = KU8_DIAG_PROFILE_REQUEST_ON;
      au8DiagReqComplement[ku8SolenoidIdx] = U8_COMPLEMENT((uint8)KU8_DIAG_PROFILE_REQUEST_ON);
   }
   else
   {
      /* do nothing */
   }
   /* Send diagnostic request request */
   (void)Rte_Write_pseDiagRequestServices_au8DiagReq(au8DiagReq);
   (void)Rte_Write_pseDiagRequestServices_au8DiagReqComplement(au8DiagReqComplement);
}

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/**
* \brief
*        This function is called at the initialization phase and it's used to
*        check what solenoid is enabled and to extract the description of the
*        steps from NVP variables.
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        None.
* \dynamicaspectcaller
*        BswM_OnStartComEffective.
* \dynamicaspectdescription
*        The local function is called by the function BswM_OnStartComEffective.
* \constraints
*        The function is called once at initialization.
* \ddesignrequirement
*        DSG_SAD_Init
* \archrequirement
*        ARCH_SW_Sad_ptrpSadServicesBswMIf_SAD_Init
*        ARCH_SW_SAD_pclModeManagement
**/
EXPORTED void SAD_Init(void)
{
   uint8 u8SolenoidEnableVariant;
   uint8 u8Idx;

   for(u8Idx = KU8_ZERO; u8Idx < KU8_MAX_SOLENOID_NB; u8Idx++)
   {
      Rte_Call_pclModeManagement_CheckModeStatus(sad_kau64SolenoidConfigMask[u8Idx], &u8SolenoidEnableVariant);
      if(KU8_TRUE == u8SolenoidEnableVariant)
      {
         SAD_u8SolenoidUsedBitMask |=  (uint8)(KU8_ONE << u8Idx);
      }
      sad_ExtractSteps(u8Idx);
   }
}

/**
* \brief
*        This function is responsible for managing the execution of the profiles
*        for each solenoid and boosts control.
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        None.
* \dynamicaspectcaller
*        BswM_OnStartComEffective
* \dynamicaspectdescription
*        The local function is called by the OsTask_Alv_eCS_App.
* \constraints
*        The function is called periodic at 1ms.
* \ddesignrequirement
*        DSG_SAD_runMainFunction
* \archrequirement
*        ARCH_SW_IoHwAb_pclModeManagement
*        ARCH_SW_SAD_ptrpAsrOsServices
*        ARCH_SW_SAD_prrSolenoidProfile
*        ARCH_SW_SAD_pclModeManagement
*        ARCH_SW_SAD_pseSolenoidPWM
*        ARCH_SW_SAD_pseSolenoidStep
**/
EXPORTED void SAD_runMainFunction(void)
{
   uint8 u8SolenoidIdx;
   uint8 u8InitModeStatus;
   uint8 u8IndexLimit;

   if(KB_TRUE == Rte_IsUpdated_prrSolenoidProfile_au8SelectedProfile())
   {
      /* get current profile command from FSM */
      (void)Rte_Read_prrSolenoidProfile_au8SelectedProfile((uint8 *)sad_au8SelectedProfile);

      for(u8SolenoidIdx = KU8_ZERO; u8SolenoidIdx < KU8_MAX_SOLENOID_NB; u8SolenoidIdx++)
      {
         if(KU8_PROFILE_NONE != sad_au8SelectedProfile[u8SolenoidIdx])
         {
            sad_u8SolenoidActiveProfile |= (uint8)(KU8_ONE << u8SolenoidIdx);
         }
         else
         {
            sad_u8SolenoidActiveProfile &= (uint8)(~(uint8)(KU8_ONE << u8SolenoidIdx));
         }
      }
   }
   else
   {
      for(u8SolenoidIdx = KU8_ZERO; u8SolenoidIdx < KU8_MAX_SOLENOID_NB; u8SolenoidIdx++)
      {
         sad_au8SelectedProfile[u8SolenoidIdx] = KU8_PROFILE_NONE;
         sad_u8SolenoidActiveProfile &= (uint8)(~(uint8)(KU8_ONE << u8SolenoidIdx));
      }
   }

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_CRITICAL_AUTOTESTS_IN_PROGRESS, &u8InitModeStatus);

   sad_ControlSolenoidsCircuitry();

   if (KU8_ZERO != sad_u8SolenoidActiveProfile)
   {
      if(KB_TRUE == sad_bFirstUnlock)
      {
         sad_u8SolenoidLastIndex = KU8_SOLENOID_1;
         sad_bFirstUnlock = KB_FALSE;
      }

      u8IndexLimit = sad_u8SolenoidLastIndex + KU8_SOL_EXE_OFFSET;
      sad_u8LockAllSolCnt = KU8_ZERO;
   }
   else
   {
      if(KU8_LOCK_ALL_SOLENOIDS_CYCLE_CNT > sad_u8LockAllSolCnt)
      {
         sad_u8SolenoidLastIndex = KU8_SOLENOID_1;
         u8IndexLimit = KU8_MAX_SOLENOID_NB;
         sad_u8LockAllSolCnt += KU8_ONE;
      }
      else
      {
         u8IndexLimit = sad_u8SolenoidLastIndex + KU8_SOL_EXE_OFFSET;
         sad_u8LockAllSolCnt = KU8_LOCK_ALL_SOLENOIDS_CYCLE_CNT;
      }

      sad_bFirstUnlock = KB_TRUE;
   }

   /* execute the profile independently for each solenoid */
   for(u8SolenoidIdx = sad_u8SolenoidLastIndex; u8SolenoidIdx < u8IndexLimit; u8SolenoidIdx++)
   {
      if(KB_TRUE == KB_SAD_SOLENOID_CONFIGURED(u8SolenoidIdx))
      {
         sad_runSolenoidControl(u8SolenoidIdx);

         /* Start solenoid diagnostic after the critical auto-tests were executed */
         if(KU8_FALSE == u8InitModeStatus)
         {
            sad_TriggerDiagProfile(u8SolenoidIdx);
         }
      }
   }

   sad_u8SolenoidLastIndex = (sad_u8SolenoidLastIndex + KU8_SOL_EXE_OFFSET) % KU8_MAX_SOLENOID_NB;

   /* Save the current Infinite step reached status for the next cycle */
   sad_u8PrevSolenoidSolenoidInfiniteStepReached = SAD_u8SolenoidInfiniteStepReached;

   /* report the current PWM to the rest of the Application */
   (void)Rte_Write_pseSolenoidPWM_au16Pwm((const uint16 *) sad_au16DutyCycle);

   /* report the current executed step to the rest of the Application */
   (void)Rte_Write_pseSolenoidStep_au8CurrentStep((const u8CurrentStepType *) SAD_au8StepToExecute);
}

#define SAD_STOP_SEC_CODE_ASIL_A
#include "SAD_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/
