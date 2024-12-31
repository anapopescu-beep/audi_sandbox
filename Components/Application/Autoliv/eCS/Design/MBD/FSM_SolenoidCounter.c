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
   The purpose of this module is to handle the number of profiles (Lock,
   Unlock, Unlock confirmation).

 ******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "FSM.h"
#include "Rte_FSM.h"
#include "Nvp_Cfg.h"
#include "NvmIf.h"

/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
#define KU8_FSM_SOLENOID_NB_OF_LOCKS                  ((uint8) 0)
#define KU8_FSM_SOLENOID_NB_OF_UNLOCKS                ((uint8) 1)
#define KU8_FSM_SOLENOID_NB_OF_UNLOCKS_CONFIRMATIONS  ((uint8) 2)

/**
 *\brief
 *      Ticks to wait until copy data from counters in NVM
 *      1000 ticks means 1 second because FSM_manageSolenoidCounters() is 
 *      called cyclic every 1ms and 1 second = 1000ms = 1000 ticks
 */
#define KU16_FSM_TICKS_TO_STORE_IN_NVM              ((uint16)1000)

/******************************************************************************
MODULE TYPES
 ******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
 ******************************************************************************/
LOCAL uint8 fsm_getCounterIndex(const uint8 ku8solenoidNumber, uint8 u8SolenoidModePosition);

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
 ******************************************************************************/
#define FSM_STOP_SEC_VAR_INIT_8_ASIL_A
#include "FSM_MemMap.h"
/**
 * \brief
 *       The array is used to return the last solenoid state (lock or unlock)
 *       per every solenoid.
 * \initialization
 *       KU8_LOCK_STATE (uint8 0x00)
 * \range
 *       KU8_LOCK_STATE, KU8_UNLOCK_STATE, KU8_BACKUP_STATE, KU8_DISABLED_STATE
 */
LOCAL uint8 fsm_au8LastSolenoidState[KU8_MAX_SOLENOID_NB] =
{
      KU8_LOCK_STATE, KU8_LOCK_STATE, KU8_LOCK_STATE,
      KU8_LOCK_STATE, KU8_LOCK_STATE, KU8_LOCK_STATE
};

/**
 * \brief
 *       The array is used to return the last solenoid state confirmation per
 *       every solenoid.
 * \initialization
 *       KU8_FALSE (uint8 0x55)
 * \range
 *       KU8_FALSE, KU8_TRUE
 */
LOCAL uint8 fsm_au8LastSolenoidStateConfirmationStatus[KU8_MAX_SOLENOID_NB] = {
      KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE
};

#define FSM_STOP_SEC_VAR_INIT_8_ASIL_A
#include "FSM_MemMap.h"

#define FSM_START_SEC_VAR_INIT_16_ASIL_A
#include "FSM_MemMap.h"
/**
 * \brief
 *       The counter is used to number uS until copy data is in FSM.
 * \initialization
 *       KU16_ZERO (uint16 0x00)
 * \range
 *       0...65535
 */
LOCAL uint16 fsm_u16TimeCounter = KU16_ZERO; 

#define FSM_STOP_SEC_VAR_INIT_16_ASIL_A
#include "FSM_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
 ******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
 ******************************************************************************/
#define FSM_START_SEC_CONST_UNSPECIFIED_ASIL_A
#include "FSM_MemMap.h"
/**
 * \brief
 *       The counter is used to number uS until copy data is in FSM.
 * \initialization
 *       KU64_SOLENOID_X_UNLOCK_CONFIRMED
 *       where X - the solenoid number
 *
 */
LOCAL const uint64 fsm_kau64SolenoidConfirmationStatusMASK[KU8_MAX_SOLENOID_NB] =
{
      /* Solenoid 1 */ (KU64_SOLENOID_1_UNLOCK_CONFIRMED ),
      /* Solenoid 2 */ (KU64_SOLENOID_2_UNLOCK_CONFIRMED ),
      /* Solenoid 3 */ (KU64_SOLENOID_3_UNLOCK_CONFIRMED ),
      /* Solenoid 4 */ (KU64_SOLENOID_4_UNLOCK_CONFIRMED ),
      /* Solenoid 5 */ (KU64_SOLENOID_5_UNLOCK_CONFIRMED ),
      /* Solenoid 6 */ (KU64_SOLENOID_6_UNLOCK_CONFIRMED )
};

#define FSM_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
#include "FSM_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
 ******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
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
 *       The function is used to return the NVM array index based on the solenoid
 *       number and data to be stored.
 * \inputparam
 *       Name: ku8solenoidNumber;
 *       Type: const uint8;
 *       Description: Solenoid ID;
 *       Range: 0..6;
 * \inputparam
 *       Name: u8SolenoidModePosition;
 *       Type: uint8;
 *       Description: Solenoid mode to be stored in the array;
 *       Range: 0..2;
 * \return
 *       Index of the array where to write data.
 * \dynamicaspectcaller
 *       FSM_manageSolenoidCounters
 * \dynamicaspectdescription
 *       API called by function FSM_manageSolenoidCounters.
 * \constraints
 *       None.
 * \ddesignrequirement
 *       DSG_fsm_getCounterIndex
 * \archrequirement
 *       ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction
 **/
LOCAL INLINE uint8 fsm_getCounterIndex(const uint8 ku8solenoidNumber, uint8 u8SolenoidModePosition)
{
   register uint8 u8CounterIndex = KU8_ZERO;

   switch (u8SolenoidModePosition)
   {
   /* Set case for first solenoid index - NO OF LOCKS */
   case KU8_FSM_SOLENOID_NB_OF_LOCKS:
      u8CounterIndex = ( ku8solenoidNumber * KU8_THREE ) + KU8_ZERO;
      break;

      /* Set case for second solenoid index - NO OF UNLOCKS */
   case KU8_FSM_SOLENOID_NB_OF_UNLOCKS:
      u8CounterIndex = ( ku8solenoidNumber * KU8_THREE ) + KU8_ONE;
      break;

      /* Set case for second solenoid index - NO OF CONFIRMATION STATUS */
   case KU8_FSM_SOLENOID_NB_OF_UNLOCKS_CONFIRMATIONS:
      u8CounterIndex = ( ku8solenoidNumber * KU8_THREE ) + KU8_TWO;
      break;

   default:
      u8CounterIndex = KU8_ZERO;
      break;
   }

   return u8CounterIndex;
}

/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/
/**
 * \brief
 *        The function used to count in NVM variable number of locks,
 *        unlock and unlocks confirmation per every solenoid.
 * \inputparam
 *        None
 * \outputparam
 *        None
 * \exception
 *        This function has no exceptions.
 * \pre
 *        This function has no preconditions.
 * \post
 *        This function has no postconditions.
 * \return
 *        This function has no return.
 * \dynamicaspectcaller
 *        FSM_runMainFunction
 * \dynamicaspectdescription
 *        API called by function FSM_runMainFunction.
 * \constraints
 *        API must be called cyclic.
 * \ddesignrequirement
 *        DSG_FSM_manageSolenoidCounters
 * \archrequirement
 *        ARCH_SW_FSM_ptrpAsrOsServices_FSM_runMainFunction
 **/
EXPORTED void FSM_manageSolenoidCounters(void)
{
   register uint8 u8SolenoidIndex = KU8_ZERO;
   register uint8 u8SolenoidNVPArrayIndex = KU8_ZERO;
   uint8 u8SolenoidConfirmationStatus = KU8_FALSE;


   /* Check what solenoid is used */
   for (u8SolenoidIndex = KU8_ZERO; u8SolenoidIndex < KU8_MAX_SOLENOID_NB; u8SolenoidIndex++)
   {
      /* Check if a solenoid has been disabled or not */
      if(FSM_au8SolenoidStates[u8SolenoidIndex] != KU8_DISABLED_STATE)
      {
         /* Check if a solenoid has been locked or unlocked */
         if (FSM_au8SolenoidStates[u8SolenoidIndex] != fsm_au8LastSolenoidState[u8SolenoidIndex])
         {
            if((KU8_LOCK_STATE == FSM_au8SolenoidStates[u8SolenoidIndex]) || (KU8_UNLOCK_STATE == FSM_au8SolenoidStates[u8SolenoidIndex]))
            {
               if (KU8_LOCK_STATE == FSM_au8SolenoidStates[u8SolenoidIndex])
               {
                  /* WRITE NO. OF LOCKS ON 1/3 POSITION */
                  u8SolenoidNVPArrayIndex = fsm_getCounterIndex(u8SolenoidIndex, KU8_FSM_SOLENOID_NB_OF_LOCKS);
               }
               else if(KU8_UNLOCK_STATE == FSM_au8SolenoidStates[u8SolenoidIndex])
               {
                  /* WRITE NO. OF UNLOCKS ON 2/3 POSITION */
                  u8SolenoidNVPArrayIndex = fsm_getCounterIndex(u8SolenoidIndex, KU8_FSM_SOLENOID_NB_OF_UNLOCKS);
               }
               else
               {
                  /* nothing */
               }
               /* Check data overflow */
               if (KU32_MAX > NVP_au32ExecutedSolenoidCounters[u8SolenoidNVPArrayIndex])
               {
                  /* Increase counter value */
                  NVP_au32ExecutedSolenoidCounters[u8SolenoidNVPArrayIndex]++;
               }
            }
            else
            {
               /* nothing */
            }
         }
      }
      else
      {
         /* nothing */
      }

      /* Get solenoid confirmation status */
      FSM_runCheckModeStatus(fsm_kau64SolenoidConfirmationStatusMASK[u8SolenoidIndex], &u8SolenoidConfirmationStatus);

      /* Check if a solenoid has been changed confirmation status */
      if ((u8SolenoidConfirmationStatus != fsm_au8LastSolenoidStateConfirmationStatus[u8SolenoidIndex]) &&
            ( KU8_TRUE == u8SolenoidConfirmationStatus))
      {

         /* WRITE NO. OF UNLOCKS CONFIRMATION ON 3/3 POSITION */
         u8SolenoidNVPArrayIndex = fsm_getCounterIndex(u8SolenoidIndex, KU8_FSM_SOLENOID_NB_OF_UNLOCKS_CONFIRMATIONS);

         /* Check data overflow */
         if (KU32_MAX > NVP_au32ExecutedSolenoidCounters[u8SolenoidNVPArrayIndex])
         {
            /* Increase counter value */
            NVP_au32ExecutedSolenoidCounters[u8SolenoidNVPArrayIndex]++;
         }
      }

      /* Retain last value of solenoid state*/
      fsm_au8LastSolenoidState[u8SolenoidIndex] = FSM_au8SolenoidStates[u8SolenoidIndex];
      fsm_au8LastSolenoidStateConfirmationStatus[u8SolenoidIndex] = u8SolenoidConfirmationStatus;
   }

   if (KU16_FSM_TICKS_TO_STORE_IN_NVM == fsm_u16TimeCounter)
   {
      /* Write ExecutionCounters Block in EEPROM */
      NvmIf_WriteNvmBlock((NvM_ASR42_BlockIdType)NvM_EOL_COUNTERS, (NvM_SrcPtrType *)&NVP_au32ExecutedSolenoidCounters);

      /* Time achieved, reset counter */
      fsm_u16TimeCounter = KU16_ZERO;
   }
   else
   {
      /* Increment counter in order to count until desired time */
      fsm_u16TimeCounter++;
   }
}

#define FSM_STOP_SEC_CODE_ASIL_A
#include "FSM_MemMap.h"

/******************************************************************************
End Of File
 *****************************************************************************/
