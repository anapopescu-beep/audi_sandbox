
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
$Revision: 1.5 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/EIM/Implementation/src/project.pj $
*/

/*****************************************************************************

@details
   This module can inject different types of DEM errors.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_EIM.h"
#include "EIM.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 * This module is used to configure EIM warm reset
 *
 */
#define KU8_EIM_WARM_RESET_AEC_CFG        	((uint8)0x03)

#if (EIM_CONFIGURED == CAL_KU8_ERROR_INJECTION_MANAGER_ACTIVE)

/**
 * \brief
 *    This macro is used to define EIM profile none
 */
#define KU8_EIM_PROFILE_NONE				((uint8)0xFF)
/**
 * \brief
 *    This macro is used to define EIM shift on 8 bits
 */
#define KU8_EIM_SHIFT_8_BITS				((uint8)0x08)
/**
 * \brief
 *    This macro is used to define EIM shift on 16 bits
 */
#define KU8_EIM_SHIFT_16_BITS				((uint8)0x10)
/**
 * \brief
 *    This macro is used to define EIM qualification time maximum number of bits
 */
#define KU16_EIM_QUALIFICATION_TIME_MAX_BITS	((uint16)0xFFFF)
/**
 * \brief
 *    This macro is used to define EIM AEC maximum number of bits
 */
#define KU32_EIM_AEC_MAX_BITS				((uint32)0x3F)
/**
 * \brief
 *    This macro is used to define EIM AEC status maximum number of bits
 */
#define KU32_EIM_AEC_STATUS_MAX_BITS		((uint32)0x0F)
/**
 * \brief
 *    This macro is used to define EIM qualification maximum number of bits
 */
#define KU32_EIM_QUALIFICATION_MAX_BITS		((uint32)0xF0)
/**
 * \brief
 *    This macro is used to define EIM AEC status qualified
 */
#define KU32_EIM_AEC_STATUS_QUALIFIED		((uint32)0x0A)
/**
 * \brief
 *    This macro is used to define EIM AEC status disqualified
 */
#define KU32_EIM_AEC_STATUS_DISQUALIFIED	((uint32)0x00)
/**
 * \brief
 *    This macro is used to define EIM qualification type instant
 */
#define KU32_EIM_QUALIF_TYPE_INSTANT		((uint32)0x10)
/**
 * \brief
 *    This macro is used to define EIM qualification type after x time
 */
#define KU32_EIM_QUALIF_TYPE_AFTER_X_TIME	((uint32)0x20)
/**
 * \brief
 *    This macro is used to define EIM qualification type after x time after started cycle
 */
#define KU32_EIM_QUALIF_AFTER_STARTED_CYCLE_AND_AFTER_X_TIME      ((uint32)0x30)
/**
 * \brief
 *    This macro is used to define EIM initialization status
 */
#define KU32_EIM_INIT_STATUS         		(KU32_MAX)

#endif
/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL void eim_Init(void);
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#if (EIM_CONFIGURED == CAL_KU8_ERROR_INJECTION_MANAGER_ACTIVE)
#define EIM_START_SEC_VAR_NO_INIT_32
#include "EIM_MemMap.h"
/**
 * \brief
 *    	This variable is used to Change Event status.
 * \initialization
 * 		0x05.
 * \range
 *		0..KU32_MAX.
 */
LOCAL volatile uint32 EIM_u32ChangeEventStatus[KU8_EIM_MAXIMUM_NUMBER_OF_ERRORS];
/**
 * \brief
 *    This variable is used to configure XOR EIM change event status.
 * \initialization
 * 		False.
 * \range
 *		0..KU32_MAX.
 */
LOCAL volatile uint32 EIM_u32ChangeEventStatusXOR[KU8_EIM_MAXIMUM_NUMBER_OF_ERRORS];
#define EIM_STOP_SEC_VAR_NO_INIT_32
#include "EIM_MemMap.h"

#define EIM_START_SEC_VAR_INIT_16
#include "EIM_MemMap.h"
/**
 * \brief
 *    	This variable is used configure EIM time counter.
 * \initialization
 * 		KU8_ZERO.
 * \range
 *		0..KU32_MAX.
 */
LOCAL uint16 eim_u16TimeCounter[KU8_EIM_MAXIMUM_NUMBER_OF_ERRORS] = {KU16_ZERO,KU16_ZERO,KU16_ZERO,KU16_ZERO,KU16_ZERO};
/**
 * \brief
 *    	This variable is used to configure EIM counter after cycle
 * \initialization
 * 		KU8_ZERO
 * \range
*		0..KU32_MAX.
 */
LOCAL uint16 eim_u16CounterAfterCycle[KU8_EIM_MAXIMUM_NUMBER_OF_ERRORS] = {KU16_ZERO,KU16_ZERO,KU16_ZERO,KU16_ZERO,KU16_ZERO};
#define EIM_STOP_SEC_VAR_INIT_16
#include "EIM_MemMap.h"

#define EIM_START_SEC_VAR_INIT_8
#include "EIM_MemMap.h"
/**
 * \brief
 *    This variable is used to configure EIM AEC event ID.
 * \initialization
 * 		0xFF.
 * \range
 * 		1..20.
 */
LOCAL uint8 eim_u8AecEventId = KU8_EIM_PROFILE_NONE;
#define EIM_STOP_SEC_VAR_INIT_8
#include "EIM_MemMap.h"

#define EIM_START_SEC_VAR_INIT_BOOL
#include "EIM_MemMap.h"
/**
 * \brief
 *    	This variable is used to configure EIM Run initialization condition.
 * \initialization
 * 		KB_FALSE.
 * \range
 * 		0..1.
 */
LOCAL boolean eim_bRunInitCondition = KB_FALSE;
#define EIM_STOP_SEC_VAR_INIT_BOOL
#include "EIM_MemMap.h"

#endif
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/
/**
 * \brief
 *    This function-like macros is used to define EIM mask selection of AEC event
 */
#define KU8_EIM_MASK_SELECTED_AEC(AEC_NUMBER)       ((uint8)((AEC_NUMBER) & KU32_EIM_AEC_MAX_BITS))
/**
 * \brief
 *    This function-like macros is used to define EIM mask selection of AEC event
 */
#define KU32_EIM_MASK_AEC_STATUS(AEC_STATUS)         ((uint32)(((AEC_STATUS) >> KU8_EIM_SHIFT_8_BITS) & KU32_EIM_AEC_STATUS_MAX_BITS))
/**
 * \brief
 *    This function-like macros is used to define EIM mask of AEC status
 */
#define KU8_EIM_MASK_QUALIFICATION_TYPE(TYPE)       ((uint8)(((TYPE) >> KU8_EIM_SHIFT_8_BITS) & KU32_EIM_QUALIFICATION_MAX_BITS))
/**
 * \brief
 *    This function-like macros is used to define EIM mask qualification time
 */
#define KU16_EIM_MASK_QUALIFICATION_TIME(TIME)       ((uint16)(((TIME) >> KU8_EIM_SHIFT_16_BITS) & KU16_EIM_QUALIFICATION_TIME_MAX_BITS))
/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
#if (EIM_CONFIGURED == CAL_KU8_ERROR_INJECTION_MANAGER_ACTIVE)
/**
* \brief
*     Function used to initialize the error event status for the EIM module
* \dynamicaspectcaller
*     BswMIf_runMainFunction
* \dynamicaspectdescription
*     Called only at startup
* \constrains
*     No constraints
* \ddesignrequirement
*     DSG_EIM_Init
* \archrequirement
*	  ARCH_SW_EIM_pseInjectError
**/
LOCAL void eim_Init(void)
{
   uint8 u8Idx;
   /* Check if initialization is not running*/
   if(KB_FALSE == eim_bRunInitCondition)
   {
      for(u8Idx = KU8_ZERO; u8Idx < KU8_EIM_MAXIMUM_NUMBER_OF_ERRORS; u8Idx++)
      { /* Initialize Eim_ChangeEventStatus array with default value */
         EIM_u32ChangeEventStatus[u8Idx] = KU32_EIM_INIT_STATUS;
         EIM_u32ChangeEventStatusXOR[u8Idx] = KU32_ZERO;
      }
      /*Set the initialization flag to true*/
      eim_bRunInitCondition = KB_TRUE;
   }
}
#endif
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
#define EIM_START_SEC_CODE
#include "EIM_MemMap.h"

#if (EIM_CONFIGURED == CAL_KU8_ERROR_INJECTION_MANAGER_ACTIVE)
/**
* \brief
*     Function used to handle error event status for the EIM module
* \dynamicaspectcaller
*     ATM_runMainFunction
* \dynamicaspectdescription
*     Called cyclic at every 10ms by ATM_runMainFunction method.
* \constrains
*     EIM must be activated
* \ddesignrequirement
*     DSG_EIM_ManageAecStatus
* \archrequirement
*    ARCH_SW_EIM_pseInjectError
*    ARCH_SW_EIM_prrFSMSolenoidProfile
**/
EXPORTED void EIM_ManageAecStatus(void)
{
   uint8 u8Idx;
   uint8 u8QualificationType = KU8_EIM_PROFILE_NONE;
   uint8 au8SelectedProfile[KU8_SIX];
   /* Initialize Eim_ChangeEventStatus array with default value */
   eim_Init();

   (void)Rte_Read_prrFSMSolenoidProfile_au8SelectedProfile(au8SelectedProfile);

   for(u8Idx = KU8_ZERO; u8Idx < KU8_EIM_MAXIMUM_NUMBER_OF_ERRORS; u8Idx++)
   {
      if((KU32_EIM_INIT_STATUS != EIM_u32ChangeEventStatus[u8Idx]) && (KU32_MAX == (EIM_u32ChangeEventStatus[u8Idx] ^ EIM_u32ChangeEventStatusXOR[u8Idx])))
      {
         /*Extract the AEC event ID from the current element in EIM_u32ChangeEventStatus array*/
         eim_u8AecEventId = KU8_EIM_MASK_SELECTED_AEC(EIM_u32ChangeEventStatus[u8Idx]);
         /*Checking if the AEC status is qualified*/
         if(KU32_EIM_AEC_STATUS_QUALIFIED == KU32_EIM_MASK_AEC_STATUS(EIM_u32ChangeEventStatus[u8Idx]))
         {
               u8QualificationType = KU8_EIM_MASK_QUALIFICATION_TYPE(EIM_u32ChangeEventStatus[u8Idx]);
               /*Switch based on the qualification type of the event*/
               switch(u8QualificationType)
               {
               /*If the qualification type is instant*/
               case KU32_EIM_QUALIF_TYPE_INSTANT:
                  /*If warm reset*/
                  if(KU8_EIM_WARM_RESET_AEC_CFG == eim_u8AecEventId)
                  {
                     /*Infinite loop*/
                	  while(1)
                	  {
                		  ;
                	  }
                  }
                  else
                  {
                     /*Set the event status to failed*/
                    (void) Dem_SetEventStatus(eim_u8AecEventId, DEM_EVENT_STATUS_FAILED);
                  }
                  break;
               /*If the qualification type is after x time*/
               case KU32_EIM_QUALIF_TYPE_AFTER_X_TIME:
                  /*Increment time counter*/
                  eim_u16TimeCounter[u8Idx]++;
                  if(KU16_EIM_MASK_QUALIFICATION_TIME(EIM_u32ChangeEventStatus[u8Idx]) == eim_u16TimeCounter[u8Idx])
                  {
                     /*If warm reset*/
                     if(KU8_EIM_WARM_RESET_AEC_CFG == eim_u8AecEventId)
                     {
                        /*Infinite loop*/
                    	 while(1)
                    	 {
                    		 ;
                    	 }
                     }
                     else
                     {
                        /*Set the event status to failed*/
                    	 (void) Dem_SetEventStatus(eim_u8AecEventId, DEM_EVENT_STATUS_FAILED);
                     }
                     /*Reset the time counter of the event*/
                     eim_u16TimeCounter[u8Idx] = KU16_EIM_MASK_QUALIFICATION_TIME(EIM_u32ChangeEventStatus[u8Idx]) - KU16_ONE;
                  }
                  break;
               /*If the qualification type is after x time after started cycle*/
               case KU32_EIM_QUALIF_AFTER_STARTED_CYCLE_AND_AFTER_X_TIME:
                  if((KU8_EIM_PROFILE_NONE != au8SelectedProfile[KU8_ZERO]) 	  ||
                		  (KU8_EIM_PROFILE_NONE != au8SelectedProfile[KU8_ONE])   ||
						  (KU8_EIM_PROFILE_NONE != au8SelectedProfile[KU8_TWO])   ||
						  (KU8_EIM_PROFILE_NONE != au8SelectedProfile[KU8_THREE]) ||
						  (KU8_EIM_PROFILE_NONE != au8SelectedProfile[KU8_FOUR])  ||
						  (KU8_EIM_PROFILE_NONE != au8SelectedProfile[KU8_FIVE]))
                  {
                     /*Increment time counter*/
                     eim_u16CounterAfterCycle[u8Idx]++;
                     if(KU16_EIM_MASK_QUALIFICATION_TIME(EIM_u32ChangeEventStatus[u8Idx]) == eim_u16CounterAfterCycle[u8Idx])
                     {  /*If warm reset*/
                        if(KU8_EIM_WARM_RESET_AEC_CFG == eim_u8AecEventId)
                        {
                           /*Infinite loop*/
                           while(1)
                           {
                        	   ;
                           }
                        }
                        else
                        {
                           /*Set the event status to failed*/
                        	 (void) Dem_SetEventStatus(eim_u8AecEventId, DEM_EVENT_STATUS_FAILED);
                        }
                        /*Reset the time counter of the event*/
                        eim_u16CounterAfterCycle[u8Idx] = KU16_EIM_MASK_QUALIFICATION_TIME(EIM_u32ChangeEventStatus[u8Idx]) - KU16_ONE;
                     }
                  }
                  break;

               default:
                  break;
               }
         }
         /*If the status is disqualified, set Dem event status to PASSED*/
         else if(KU32_EIM_MASK_AEC_STATUS(EIM_u32ChangeEventStatus[u8Idx]) == KU32_EIM_AEC_STATUS_DISQUALIFIED)
         {
        	 /* Set event to status passed */
        	 (void) Dem_SetEventStatus(eim_u8AecEventId, DEM_EVENT_STATUS_PASSED);

        	 /* Reset timer if event is disqualified*/
        	 eim_u16TimeCounter[u8Idx] = KU16_ZERO;
         }
         else
         {
            /* do nothing */
         }
      }
   }
}
#endif

#define EIM_STOP_SEC_CODE
#include "EIM_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
