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
/**
 *    $Revision: 1.10.2.34 $
 *    $ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/DIA/Implementation/src/project.pj $
 */

/******************************************************************************

details
   This file is intended to handle control of routines.
 ******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "Rte_DIA.h"
#include "DIA.h"
#include "Dcm.h"
#include "Dem_IntEvtId.h"
/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
/**
 * \brief
 *    Constant used to check the Process Mode status.
 */
#define KU8_DIA_BIT_MASK_PROCESS_MODE                   ((uint8)KU32_MASK_BIT_1)
/**
 * \brief
 *    Last byte of Routine Control positive response.
 */
#define KU8_DIA_RINF_BYTE                                          ((uint8)0xFF)
/**
 * \brief
 *    Constant used to set the number of samples at which the accelerometer is calibrated.
 */
#define KS16_DIA_NB_SAMPLE                                        ((sint16)1000)
/**
 * \brief
 *    Constant used to set the Z-axis offset.
 */
#define KU16_DIA_ACC_OFFSET_AZ                                  ((uint16)0x1F40)
/**
 * \brief
 *    Constant used to change the sign of X and Y-axis values(Accelerometer axes).
 */
#define KS8_DIA_SIGN_CHANGE                                          ((sint8)-1)
/**
 * \brief
 *    Last byte of Routine Control positive response = correct results.
 */
#define KU8_DIA_RINF_LAST_BYTE                                     ((uint8)0x24)
/******************************************************************************
MODULE TYPES
 ******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
 ******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
 ******************************************************************************/
#define DIA_START_SEC_VAR_INIT_8
#include "DIA_MemMap.h"

/**
 * \brief
 *    Variable used to memorize if a function returned pending or not when it was previously called.
 * \initialization
 *    KU8_ZERO (0)
 * \range
 *    0..KU8_MAX
 */
LOCAL uint8 dia_u8FunctionPendingFlag = KU8_ZERO;

/**
 * \brief
 *    Local variable containing the state machine used to erase and check NVM data blocks.
 *    Initialized with the first data block.
 * \initialization
 *    KU8_ZERO (0)
 * \range
 *    0..KU8_MAX
 */
LOCAL uint8 dia_u8NVMDataBlockToIndex = KU8_ZERO;

#define DIA_STOP_SEC_VAR_INIT_8
#include "DIA_MemMap.h"

#define DIA_START_SEC_VAR_INIT_16
#include "DIA_MemMap.h"
/**
 * \brief
 *    Variable used as a counter for the sample value.
 * \initialization
 *    KU16_MIN (0)
 * \range
 *    0..KU16_MAX
 */
LOCAL uint16  dia_u16CurrentSample = KU16_MIN;

#define DIA_STOP_SEC_VAR_INIT_16
#include "DIA_MemMap.h"

#define DIA_START_SEC_VAR_INIT_32
#include "DIA_MemMap.h"
/**
 * \brief
 *    Variable used to calculate the sum of the angles to the x-axis.
 * \initialization
 *    KS32_ZERO (0)
 * \range
 *    0..KS32_MAX
 */
LOCAL sint32  dia_s32SumX = KS32_ZERO;

/**
 * \brief
 *    Variable used to calculate the sum of the angles to the y-axis.
 * \initialization
 *    KS32_ZERO (0)
 * \range
 *    0..KS32_MAX
 */
LOCAL sint32  dia_s32SumY = KS32_ZERO;
/**
 * \brief
 *    Variable used to calculate the sum of the angles to the z-axis.
 * \initialization
 *    KS32_ZERO (0)
 * \range
 *    0..KS32_MAX
 */
LOCAL sint32  dia_s32SumZ = KS32_ZERO;

#define DIA_STOP_SEC_VAR_INIT_32
#include "DIA_MemMap.h"


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

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
 ******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/
#define DIA_START_SEC_CODE
#include "DIA_MemMap.h"

/**
 * \brief
 *       Function used to unlock the ECU.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: Not used, generated automatically by Autosar;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Last byte in the response (RINF = 0xFF);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType*(uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Writing process status.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_RoutineServices_DcmDspRoutineCtrl_Lock_UnlockECU_Start
 * \dynamicaspectdescription
 *       Start the unlock ECU routine.
 * \constrains
 *       Writing process status can be:
 *          o DCM_E_NOT_OK;
 *          o DCM_E_OK;
 *          o DCM_E_NO_DATA;
 * \ddesignrequirement
 *		   DSG_DIA_runRidF781_EcuUnlockStart
 * \archrequirement
 *       ARCH_SW_DIA_pseRoutineControl_LockUnlockECU_Start
 **/
EXPORTED Std_ReturnType DIA_runRidF781_EcuUnlockStart(Dcm_OpStatusType OpStatus, uint8 * pu8Data, Dcm_NegativeResponseCodeType * ErrorCode)
{
   Std_ReturnType u8Result;
   u8Result = DCM_E_NOT_OK;

   /* First, let check if a writing process is on-going */
   if(KU8_ZERO != dia_u8NVMDataBlockToIndex)
   {
      /* Write process is on-going, check if it has ended already */
      u8Result = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_LOCK_UNLOCK_ECU, &NVP_u8ECUUnlock);

      if(NVM_REQ_OK == u8Result)
      {
         /* Writing is successfully done */
         u8Result = DCM_E_OK;
         *pu8Data = KU8_DIA_RINF_BYTE;

         /* Clear the Data block index for next calls */
         dia_u8NVMDataBlockToIndex = KU8_ZERO;
      }
      else if(NVM_REQ_NOT_OK == u8Result)
      {
         u8Result = DCM_E_NOT_OK;
         *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
         /* Writing process failed: retrieve the initial values in RAM */
         NVP_u8ECUUnlock = KU8_ECU_LOCK;
         NVP_u8ECUUnlock_XOR = KU8_ECU_UNLOCK;

         /* Retrieve initial status of ManageNVPBlockWriting */
         DIA_u8ManageNVPBlockWritingStatus = KU8_ZERO;
      }
      else
      {
         /* Write process is still going */
         u8Result = DCM_E_NO_DATA;
      }
   }
   else
   {
      NVP_u8ECUUnlock = KU8_ECU_UNLOCK;
      NVP_u8ECUUnlock_XOR = KU8_ECU_LOCK;

      /* ECU is locked. So unlock it: Send request to write data in EEPROM */
      u8Result = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_LOCK_UNLOCK_ECU, &NVP_u8ECUUnlock);

      if(NVM_REQ_PENDING == u8Result)
      {
         /* Pending, the write process if on-going */
         u8Result = DCM_E_NO_DATA;

         /* Increment the Data Block Index for the next call */
         dia_u8NVMDataBlockToIndex++;
      }
      else
      {
         /* Error while sending the request to write into E2PROM */
         u8Result = DCM_E_NOT_OK;
         *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
         /* Writing request failed: retrieve the initial values in RAM */
         NVP_u8ECUUnlock = KU8_ECU_LOCK;
         NVP_u8ECUUnlock_XOR = KU8_ECU_UNLOCK;
      }
   }
   return u8Result;
}

/**
 * \brief
 *       Function used to lock the ECU.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: Not used, generated automatically by Autosar;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Last byte in the response (RINF = 0xFF);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType*(uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Writing process status.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_RoutineServices_DcmDspRoutineCtrl_Lock_UnlockECU_Stop
 * \dynamicaspectdescription
 *       Stop the unlock ECU routine.
 * \constrains
 *       Writing process status can be:
 *          o DCM_E_NOT_OK;
 *          o DCM_E_OK;
 *          o DCM_E_NO_DATA;
 * \ddesignrequirement
 *		   DSG_DIA_runRidF781_EcuUnlockStop
 * \archrequirement
 *       ARCH_SW_DIA_pseRoutineControl_LockUnlockECU_Stop
 **/
EXPORTED Std_ReturnType DIA_runRidF781_EcuUnlockStop(Dcm_OpStatusType OpStatus, uint8 * pu8Data, Dcm_NegativeResponseCodeType * ErrorCode)
{
   Std_ReturnType u8Result;
   u8Result = DCM_E_NOT_OK;

   /* First, let check if a writing process is on-going */
   if (KU8_ZERO != dia_u8NVMDataBlockToIndex)
   {
      /* Write process is on-going, check if it has ended already */
      u8Result = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_LOCK_UNLOCK_ECU, &NVP_u8ECUUnlock);

      if(NVM_REQ_OK  == u8Result)
      {
         /* Writing is successfully done */
         u8Result = DCM_E_OK;
         *pu8Data = KU8_DIA_RINF_BYTE;

         /* Clear the Data block index for next calls */
         dia_u8NVMDataBlockToIndex = KU8_ZERO;
      }
      else if(NVM_REQ_NOT_OK  == u8Result)
      {
         u8Result = DCM_E_NOT_OK;
         *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
         /* Writing process failed: retrieve the initial values in RAM */
         NVP_u8ECUUnlock = KU8_ECU_UNLOCK;
         NVP_u8ECUUnlock_XOR = KU8_ECU_LOCK;
      }
      else
      {
         /* Write process is still going */
         u8Result = DCM_E_NO_DATA;
      }
   }
   else
   {
      NVP_u8ECUUnlock = KU8_ECU_LOCK;
      NVP_u8ECUUnlock_XOR = KU8_ECU_UNLOCK;

      /* ECU is locked. So unlock it: Send request to write data in EEPROM */
      u8Result = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_LOCK_UNLOCK_ECU, &NVP_u8ECUUnlock);

      if(NVM_REQ_PENDING == u8Result)
      {
         /* Pending, the write process if on-going */
         u8Result = DCM_E_NO_DATA;

         /* Increment the Data Block Index for the next call */
         dia_u8NVMDataBlockToIndex++;
      }
      else
      {
         u8Result = DCM_E_NOT_OK;
         *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
         /* Writing process failed: retrieve the initial values in RAM */
         NVP_u8ECUUnlock = KU8_ECU_LOCK;
         NVP_u8ECUUnlock_XOR = KU8_ECU_UNLOCK;

         /* Retrieve initial status of ManageNVPBlockWriting */
         DIA_u8ManageNVPBlockWritingStatus = KU8_ZERO;
      }
   }
   return u8Result;
}

/**
 * \brief
 *       Function used to read the ECU lock/unlock status.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: Not used, generated automatically by Autosar;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Last byte in the response (RINF = 0xFF);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: dataOut1;
 *       Type: uint16*;
 *       Description: Used to store of process mode status;
 *       Range: 0..KU16_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType*(uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Read process status.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_RoutineServices_DcmDspRoutineCtrl_Lock_UnlockECU_RequestResults.
 * \dynamicaspectdescription
 *       Request Lock/Unlock ECU status.
 * \constrains
 *       Read process status is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runRidF781_EcuUnlockRequestRes
 * \archrequirement
 *       ARCH_SW_DIA_pseRoutineControl_LockUnlockECU_RequestResult
 *       ARCH_SW_DIA_pseNvpBlockData_ECULockStatus
 **/
EXPORTED Std_ReturnType DIA_runRidF781_EcuUnlockRequestRes(Dcm_OpStatusType OpStatus, uint8 * pu8Data,uint16* dataOut1, Dcm_NegativeResponseCodeType * ErrorCode)
{
   /* Read ECU unlock status */
   *(pu8Data)  = KU8_DIA_RINF_BYTE;
   *(dataOut1) = ((uint16)(NVP_u8ECUUnlock) | (uint16)((uint16)NVP_u8ECUUnlock_XOR << KU8_EIGHT));

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Function used to start the Process Mode.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: Not used, generated automatically by Autosar;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: dataOut0;
 *       Type: uint8*;
 *       Description: Used to store last byte of routine control response (RINF = 0xFF);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType*(uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Process mode status.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_RoutineServices_DcmDspRoutineProcessMode_Start.
 * \dynamicaspectdescription
 *       Function used to start the Process Mode.
 * \constrains
 *       Process mode status can be:
 *          o DCM_E_OK;
 *          o DCM_E_NO_DATA;
 *          o DCM_E_NOT_OK;
 *          o E_NOT_OK;
 * \ddesignrequirement
 *		   DSG_DIA_runRidF793_ProcessModeStart
 * \archrequirement
 *       ARCH_SW_DIA_pseRoutineControl_ProcessMode_Start
 **/
EXPORTED Std_ReturnType DIA_runRidF793_ProcessModeStart (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;

   /* Check if ECU is locked */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   /* Check if Process Mode is activated or the writing process has already been started. */
   else if((KU8_NVP_PROCESS_MODE_ACTIVE != NVP_u8ProcessMode) || (KU8_ZERO != (dia_u8FunctionPendingFlag & KU8_DIA_BIT_MASK_PROCESS_MODE)))
   {
      /* Process Mode is disabled. So activate it */

      /* Write Data in RAM */
      NVP_u8ProcessMode = KU8_NVP_PROCESS_MODE_ACTIVE;

      /* Write Data in EEPROM */
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_PROCESS_MODE, &NVP_u8ProcessMode);

      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_NO_DATA;
         /* If the result is pending, set the corresponding flag to signal that the writing process is on-going */
         U8_BIT_SET(dia_u8FunctionPendingFlag, KU8_DIA_BIT_MASK_PROCESS_MODE);
      }
      else if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_OK;
         /* Send Routine info byte i.e last byte in diag positive response */
         *dataOut0 = KU8_DIA_RINF_BYTE;
         /* If the result is NOT pending, clear the corresponding flag to signal that the writing process was finished */
         U8_BIT_CLEAR(dia_u8FunctionPendingFlag, KU8_DIA_BIT_MASK_PROCESS_MODE);
      }
      else
      {
         u8Result = DCM_E_NOT_OK;
         /* Retrieve initial status of the Process Mode in RAM */
         NVP_u8ProcessMode = KU8_NVP_PROCESS_MODE_INACTIVE;
         *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
      }
   }

   else
   {
      /* Process Mode is already activated. Return OK by default */
      u8Result = DCM_E_OK;
      /* Send Routine info byte i.e last byte in diag positive response */
      *dataOut0 = KU8_DIA_RINF_BYTE;
   }

   return u8Result;
}

/**
 * \brief
 *       Function used to stop the Process Mode.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: Not used, generated automatically by Autosar;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: dataOut0;
 *       Type: uint8*;
 *       Description: Used to store last byte of routine control response (RINF = 0xFF);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType*(uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Process mode status.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_RoutineServices_DcmDspRoutineProcessMode_Stop.
 * \dynamicaspectdescription
 *       Function used to stop the Process Mode.
 * \constrains
 *       Process mode status can be:
 *          o DCM_E_OK;
 *          o DCM_E_NO_DATA;
 *          o DCM_E_NOT_OK;
 *          o E_NOT_OK;
 * \ddesignrequirement
 *		   DSG_DIA_runRidF793_ProcessModeStop
 * \archrequirement
 *       ARCH_SW_DIA_pseRoutineControl_ProcessMode_Stop
 **/
EXPORTED Std_ReturnType DIA_runRidF793_ProcessModeStop (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;

   uint8 u8ManageNVPBlockWritingResult;

   /* Check if ECU is locked */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   /* Check if Process Mode is deactivated or the writing process has already been started. */
   else if((KU8_NVP_PROCESS_MODE_INACTIVE != NVP_u8ProcessMode) || (KU8_ZERO != (dia_u8FunctionPendingFlag & KU8_DIA_BIT_MASK_PROCESS_MODE)))
   {
      /* Process Mode is activated. So disable it */

      /* Write Data in RAM */
      NVP_u8ProcessMode = KU8_NVP_PROCESS_MODE_INACTIVE;

      /* Write Data in EEPROM */
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_PROCESS_MODE, &NVP_u8ProcessMode);

      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_NO_DATA;
         /* If the result is pending, set the corresponding flag to signal that the writing process is on-going */
         U8_BIT_SET(dia_u8FunctionPendingFlag, KU8_DIA_BIT_MASK_PROCESS_MODE);
      }
      else if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_OK;
         /* Send Routine info byte i.e last byte in diag positive response */
         *dataOut0 = KU8_DIA_RINF_BYTE;
         /* If the result is NOT pending, clear the corresponding flag to signal that the writing process was finished */
         U8_BIT_CLEAR(dia_u8FunctionPendingFlag, KU8_DIA_BIT_MASK_PROCESS_MODE);
      }
      else
      {
         u8Result = DCM_E_NOT_OK;
         /* Retrieve initial status of the Process Mode in RAM */
         NVP_u8ProcessMode = KU8_NVP_PROCESS_MODE_ACTIVE;
         *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
      }
   }

   else
   {
      /* Process Mode is already activated. Return OK by default */
      u8Result = DCM_E_OK;
   }

   return u8Result;
}

/**
 * \brief
 *       Function used to read the Process Mode status.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: Not used, generated automatically by Autosar;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: dataOut0;
 *       Type: uint8*;
 *       Description: Used to store last byte of routine control response (RINF = 0xFF);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: dataOut1;
 *       Type: uint8*;
 *       Description: Used to store of process mode status;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType*(uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Process mode status.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_RoutineServices_DcmDspRoutineProcessMode_RequestResults.
 * \dynamicaspectdescription
 *       Function used to read the Process Mode status.
 * \constrains
 *       Process mode status can be DCM_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runRidF793_ProcessModeRequestRes
 * \archrequirement
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 *       ARCH_SW_DIA_pseNvpBlockData_ProcessModeRequestRes
 *       ARCH_SW_DIA_pseRoutineControl_ProcessMode_RequestRes
 **/
EXPORTED Std_ReturnType DIA_runRidF793_ProcessModeRequestRes (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dataOut1, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;

   /* Check if ECU is locked */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Send Routine info byte in positive response */
      *dataOut0 = KU8_DIA_RINF_BYTE;
      u8Result = DCM_E_OK;
      /* Read Process Mode Status */
      if(KU8_NVP_PROCESS_MODE_ACTIVE == NVP_u8ProcessMode)
      {
         /* Process mode is ACTIVE */
         *(dataOut1) = KU8_NVP_PROCESS_MODE_ACTIVE;
      }
      else
      {
         /* Process mode is INACTIVE */
         *(dataOut1) = KU8_NVP_PROCESS_MODE_INACTIVE;
      }
   }
   return u8Result;
}

/**
 * \brief
 *       Function used to start ACC Calibration.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: Not used, generated automatically by Autosar;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: dataOut0;
 *       Type: uint8*;
 *       Description: Used to store last byte of routine control response (RINF = 0xFF);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType*(uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Write process status.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_RoutineServices_DcmDspRoutineAccCalib_Start.
 * \dynamicaspectdescription
 *       Function used to start ACC Calibration.
 * \constrains
 *       Process status can be:
 *          o DCM_E_OK;
 *          o DCM_E_NO_DATA;
 *          o DCM_E_NOT_OK;
 * \ddesignrequirement
 *		   DSG_DIA_runRidF794_AccCalibStart
 * \archrequirement
 *       ARCH_SW_DIA_pseRoutineControl_AccCalib
 *       ARCH_SW_prr3DAcceleration
 **/
EXPORTED Std_ReturnType DIA_runRidF794_AccCalibStart (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   REC_3D_AccelerationType stRaw3AxisAccel;
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;

   /* Check if ECU is locked. */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Get Raw Acceleration in g from SPI communication */
      (void)Rte_Read_prr3DAcceleration_st3DAccel(&stRaw3AxisAccel);

      dia_s32SumX += KS8_DIA_SIGN_CHANGE * stRaw3AxisAccel.s16Ax;
      dia_s32SumY += KS8_DIA_SIGN_CHANGE * stRaw3AxisAccel.s16Ay;
      dia_s32SumZ += (KU16_DIA_ACC_OFFSET_AZ - stRaw3AxisAccel.s16Az);

      dia_u16CurrentSample++;
      /*Counter for the sample value was casted to sint16 because of QAC error */
      if(KS16_DIA_NB_SAMPLE > (sint16)dia_u16CurrentSample)
      {
         u8Result = DCM_E_NO_DATA;
      }
      else
      {
         /*Counter for the sample value was casted to sint16 because of QAC error */
         if(KS16_DIA_NB_SAMPLE == (sint16)dia_u16CurrentSample)
         {
            NVP_s16OffsetAx = (sint16)(dia_s32SumX/KS16_DIA_NB_SAMPLE);
            NVP_s16OffsetAy = (sint16)(dia_s32SumY/KS16_DIA_NB_SAMPLE);
            NVP_s16OffsetAz = (sint16)(dia_s32SumZ/KS16_DIA_NB_SAMPLE);
            dia_u16CurrentSample++;
         }
         /* Write Data in EEPROM */
         u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECS_ACC_OFFSETS, (uint8 const *)&NVP_s16OffsetAx);

         if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
         {
            u8Result = DCM_E_NO_DATA;
         }
         else if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
         {
            u8Result = DCM_E_OK;
            /* Send Routine info byte i.e last byte in diag positive response */
            *dataOut0 = KU8_DIA_RINF_BYTE;
            dia_u16CurrentSample = KU16_ZERO;
            dia_s32SumX = KS32_ZERO;
            dia_s32SumY = KS32_ZERO;
            dia_s32SumZ = KS32_ZERO;

         }
         else
         {
            u8Result = DCM_E_NOT_OK;
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            dia_u16CurrentSample = KU16_ZERO;
            dia_s32SumX = KS32_ZERO;
            dia_s32SumY = KS32_ZERO;
            dia_s32SumZ = KS32_ZERO;
         }
      }
   }
   return u8Result;
}

/**
 * \brief
 *       Function used to start ECU Temperature Calibration.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: Not used, generated automatically by Autosar;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: dataIn0;
 *       Type: sint8;
 *       Description: Represents the environmental temperature;
 *       Range: 0..KS8_MAX;
 * \outputparam
 *       Name: dataOut0;
 *       Type: uint8*;
 *       Description: Used to store last byte of routine control response (RINF = 0xFF);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType*(uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Process status.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_RoutineServices_DcmDspRoutineEcuTempCalibration_Start.
 * \dynamicaspectdescription
 *       Function used to start ECU Temperature Calibration.
 * \constrains
 *       Process status can be DCM_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runRidF796_EcuTempCalibration
 * \archrequirement
 *       ARCH_SW_DIA_pseRoutineControl_EcuTempCalibration
 *       ARCH_SW_DIA_pclPtcSensor
 *       ARCH_SW_DIA_pclAccSensor
 *       ARCH_SW_DIA_pclNvmIfServices_SetRamBlockStatus
 *       ARCH_SW_DIA_pclMcuCharacteristics
 **/
EXPORTED Std_ReturnType DIA_runRidF796_EcuTempCalibration (sint8 dataIn0, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result = DCM_E_OK;
   sint16 s16McuTemperature;
   sint16 s16PtcSensorTemperature;
   sint16 s16AccTemperature;
   sint16 s16EnvironmentalTemp;
   sint16 s16TrackingMcuTempOffset;
   sint16 s16TrackingAccTempOffset;
   sint16 s16TrackingPtcTempOffset;
   s16EnvironmentalTemp = ((sint16)dataIn0);

   /* Check if ECU is locked */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Send Routine info byte i.e last byte in diag positive response */
      *dataOut0 = KU8_DIA_RINF_BYTE;

      /*Read the Mcu temperature*/
      Rte_Call_pclMcuCharacteristics_GetTemperature(&s16McuTemperature);
      /*Read the Acc temperature*/
      Rte_Call_pclAccSensor_GetTemperature(&s16AccTemperature);
      /*Read the Ptc temperature*/
      Rte_Call_pclPtcSensor_GetTemperature(&s16PtcSensorTemperature);

      /* The local variable s16TrackingMcuTempOffset is used to calibrate the MCU temperature value. */
      s16TrackingMcuTempOffset = s16EnvironmentalTemp - s16McuTemperature;
      /* The local variable s16TrackingAccTempOffset is used to calibrate the Acc temperature value. */
      s16TrackingAccTempOffset = s16EnvironmentalTemp - s16AccTemperature;
      /* The local variable s16TrackingPtcTempOffset is used to calibrate the Ptc temperature value. */
      s16TrackingPtcTempOffset = s16EnvironmentalTemp - s16PtcSensorTemperature;

      /* If the MCU calibrated temperature value is in the range [-40, 80], NVP_s8McuTempOffset store that value.*/
      if(KS16_MAX_S8 > s16TrackingMcuTempOffset)
      {
         NVP_s8McuTempOffset = (sint8)s16TrackingMcuTempOffset;
      }
      else
      {
         /*Prevent NVP_s8McuTempOffset to overflow */
         NVP_s8McuTempOffset = KS8_ZERO;
      }

      /* If the Acc sensor calibrated temperature value is in the range [-40, 80], NVP_s8AccTempOffset store that value.*/
      if(KS16_MAX_S8 > s16TrackingAccTempOffset)
      {
         NVP_s8AccTempOffset = (sint8)s16TrackingAccTempOffset;
      }
      else
      {
         /*Prevent NVP_s8AccTempOffset to overflow */
         NVP_s8AccTempOffset = KS8_ZERO;
      }

      /* If the Ptc sensor calibrated temperature value is in the range [-40, 80], NVP_s8PtcTempOffset store that value.*/
      if(KS16_MAX_S8 > s16TrackingPtcTempOffset)
      {
         NVP_s8PtcTempOffset = (sint8)s16TrackingPtcTempOffset;
      }
      else
      {
         /*Prevent NVP_s8PtcTempOffset to overflow */
         NVP_s8PtcTempOffset = KS8_ZERO;
      }
      (void)Rte_Call_pclNvmIfServices_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_ECU_TEMP_CALIBRATION, TRUE);
   }
   return (u8Result);
}

/**
 * \brief
 *       Function used to start ACC Angle Offset Calibration.
 * \inputparam
 *       Name: u16XAngle;
 *       Type: uint16;
 *       Description: Used to calculate the angle on the x-axis ;
 *       Range: 0..KU16_MAX;
 * \inputparam
 *       Name: u16YAngle;
 *       Type: uint16;
 *       Description: Used to calculate the angle on the y-axis;
 *       Range: 0..KU16_MAX;
 * \inputparam
 *       Name: u16ZAngle;
 *       Type: uint16;
 *       Description: Used to calculate the angle on the z-axis;
 *       Range: 0..KU16_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: Not used, generated automatically by Autosar;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: dataOut0;
 *       Type: uint8*;
 *       Description: Used to store last byte of routine control response (RINF = 0xFF);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType*(uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Process status.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_RoutineServices_DcmDspRoutineAccAngleOffsetCalibration_Start
 * \dynamicaspectdescription
 *       Function used to start ACC Angle Offset Calibration.
 * \constrains
 *       Process status can be DCM_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runRidF797_AccAngleOffsetCalibrationStart
 * \archrequirement
 *       ARCH_SW_DIA_pseRoutineControl_AccAngleOffsetCalibration
 **/
EXPORTED Std_ReturnType DIA_runRidF797_AccAngleOffsetCalibrationStart (uint16 u16XAngle, uint16 u16YAngle, uint16 u16ZAngle, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;

   /* Check if ECU is locked */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Send Routine info byte i.e last byte in diag positive response */
      *dataOut0 = KU8_DIA_RINF_BYTE;
      NVP_u16XAxisAngleCalib = U16_SWAP_BYTE_ORDER(u16XAngle);
      NVP_u16YAxisAngleCalib = U16_SWAP_BYTE_ORDER(u16YAngle);
      NVP_u16ZAxisAngleCalib = U16_SWAP_BYTE_ORDER(u16ZAngle);

      /* Write Data in EEPROM */
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ACC_AXIS_ANGLE_CALIBRATION, (uint8 const *)&NVP_u16XAxisAngleCalib);

      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_NO_DATA;
      }
      else if( NVM_REQ_OK == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_OK;
      }
      else
      {
         u8Result = DCM_E_NOT_OK;
         *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
      }
   }
   return (u8Result);

}
/**
 * \brief
 *       Function used to read the status of programming preconditions.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: Not used, generated automatically by Autosar;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: dataOut0;
 *       Type: uint8*;
 *       Description: Used to store last byte of routine control response (RINF = 0xFF);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: currentDataLength;
 *       Type: uint16*;
 *       Description: Used to store the current data length;
 *       Range: 0..KU16_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType*(uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Process status.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_RoutineServices_DcmDspRoutineRoutineCheckProgrammingPreconditions_Start.
 * \dynamicaspectdescription
 *       Read the status of programming preconditions.
 * \constrains
 *       Process status can be DCM_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runRid0203_CheckProgrammingPreconditions
 * \archrequirement
 *       ARCH_SW_DIA_pseRoutineControl_CheckProgrammingPreconditions
 *       ARCH_SW_DIA_pclDemServices_GetEventStatus
 *       ARCH_SW_DIA_pclDemServices_GetEventFailed
 **/
EXPORTED Std_ReturnType DIA_runRid0203_CheckProgrammingPreconditions (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) currentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Dem_EventStatusExtendedType u8EventStatus = KU8_ZERO;

   uint8 u8DataIndex = KU8_ZERO;
   *currentDataLength = KU8_ONE;

   *dataOut0 = KU8_DIA_RINF_LAST_BYTE;

   (void) Rte_Call_pclDemServices_GetEventStatus(DemConf_DemEventParameter_EVENT_POWER_SUPPLY_OV, &u8EventStatus);

   if (DEM_UDS_STATUS_TF == (u8EventStatus & DEM_UDS_STATUS_TF))
   {
      (*currentDataLength)++;
      dataOut0[u8DataIndex] = KU8_DIA_OVERVOLTAGE;
      u8DataIndex++;
   }

   (void) Rte_Call_pclDemServices_GetEventStatus(DemConf_DemEventParameter_EVENT_POWER_SUPPLY_UV, &u8EventStatus);

   if (DEM_UDS_STATUS_TF == (u8EventStatus & DEM_UDS_STATUS_TF))
   {
      (*currentDataLength)++;
      dataOut0[u8DataIndex] = KU8_DIA_UNDERVOLTAGE;
      u8DataIndex++;
   }

   return ((Std_ReturnType)RTE_E_OK);
}

#define DIA_STOP_SEC_CODE
#include "DIA_MemMap.h"

#define DIA_START_SEC_CODE_ASIL_A
#include "DIA_MemMap.h"

/**
 * \brief
 *       Function used to lock the Solenoid.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: Not used, generated automatically by Autosar;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: dataOut0;
 *       Type: uint8*;
 *       Description: Used to store last byte of routine control response (RINF = 0xFF);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType*(uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Process status.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_RoutineServices_DcmDspRoutineLockSolenoid_Start
 * \dynamicaspectdescription
 *       Function used to lock the Solenoid.
 * \constrains
 *       Process status can be DCM_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runRidF795_LockSolenoidStart
 * \archrequirement
 *       ARCH_SW_DIA_pseRoutineControl_LockSolenoid_Start
 *       ARCH_SW_DIA_pseEcsDiagRequest
 **/
EXPORTED Std_ReturnType DIA_runRidF795_LockSolenoidStart (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result = DCM_E_OK;
   u8eCSDiagReqType au8SolenoidDiagRequest[sizeof(au8eCSDiagReqType)];
   u8eCSDiagReqType au8SolenoidDiagRequestComplement[sizeof(au8eCSDiagReqType)];
   uint8 u8Idx;

   /* Send Routine info byte i.e last byte in diag positive response */
   *dataOut0 = KU8_DIA_RINF_BYTE;

   for (u8Idx = KU8_ZERO; u8Idx < sizeof(au8eCSDiagReqType); u8Idx++)
   {
      au8SolenoidDiagRequest[u8Idx] = KU8_LOCK_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[u8Idx] = ~((uint8)KU8_LOCK_DIAG_REQUEST);
   }

   /* Send the diag request to eCS module */
   (void)Rte_Write_pseEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
   (void)Rte_Write_pseEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);

   return (u8Result);
}

/**
 * \brief
 *       Function used to unlock the Solenoid.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: Not used, generated automatically by Autosar;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: dataOut0;
 *       Type: uint8*;
 *       Description: Used to store last byte of routine control response (RINF = 0xFF);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType*(uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Process status.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_RoutineServices_DcmDspRoutineLockSolenoid_Stop
 * \dynamicaspectdescription
 *       Function used to unlock the Solenoid.
 * \constrains
 *       Process status can be DCM_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runRidF795_LockSolenoidStop
 * \archrequirement
 *       ARCH_SW_DIA_pseRoutineControl_LockSolenoid_Stop
 *       ARCH_SW_DIA_pseEcsDiagRequest
 **/
EXPORTED Std_ReturnType DIA_runRidF795_LockSolenoidStop (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dataOut0, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result  = DCM_E_OK;
   u8eCSDiagReqType au8SolenoidDiagRequest[sizeof(au8eCSDiagReqType)];
   u8eCSDiagReqType au8SolenoidDiagRequestComplement[sizeof(au8eCSDiagReqType)];
   uint8 u8Idx;

   /* Send Routine info byte i.e last byte in diag positive response */
   *dataOut0 = KU8_DIA_RINF_BYTE;

   for (u8Idx = KU8_ZERO; u8Idx < sizeof(au8eCSDiagReqType); u8Idx++)
   {
      au8SolenoidDiagRequest[u8Idx] = KU8_NO_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[u8Idx] = ~((uint8)KU8_NO_DIAG_REQUEST);
   }

   /* Clear diagnostic request */
   (void)Rte_Write_pseEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
   (void)Rte_Write_pseEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);

   return (u8Result);
}

#define DIA_STOP_SEC_CODE_ASIL_A
#include "DIA_MemMap.h"

/*************************************************************************
 Evolution of the component

 created by : T. DEMIREL

 $Log: DIA_RoutineControl.c  $
 Revision 1.10.2.34 2023/08/01 10:09:23CEST Gabriel Brasoveanu (gabriel.brasoveanu) 
 Update code after integration of new EB packages
 Revision 1.10.2.33 2023/07/20 09:44:10EEST David Puscasu (david.puscasu) 
 Update Traceability
 Revision 1.10.2.32 2023/07/14 15:18:55EEST Andreea Suiu (andreea.suiu) 
 add traceability
 Revision 1.10.2.31 2023/07/11 16:59:54EEST Andreea Suiu (andreea.suiu) 
 update comments, update 0236 write
 Revision 1.10.2.30 2023/06/28 15:17:40EEST Andreea Suiu (andreea.suiu) 
 update comments
 Revision 1.10.2.29 2023/06/22 14:07:12EEST Andreea Suiu (andreea.suiu) 
 update src files (fix findings) after review
 Revision 1.10.2.28 2023/06/20 13:08:18EEST Andreea Suiu (andreea.suiu) 
 bug fix for f793 subservice 03 (add condition if ecu is locked)
 Revision 1.10.2.27 2023/06/12 09:16:45EEST Mihai Motoc (mihai.motoc) 
 Doxygen comments updates
 Revision 1.10.2.26 2023/06/08 09:31:29EEST Mihai Motoc (mihai.motoc) 
 Doxygen comments updates
 Revision 1.10.2.25 2023/05/16 12:44:17EEST Dan Dustinta (dan.dustinta) 
 update b8 to u8
 Revision 1.10.2.24 2023/04/28 16:09:12EEST Andreea Suiu (andreea.suiu) 
 initialize variables on positive and negative response
 Revision 1.10.2.23 2023/04/28 14:59:12EEST Andreea Suiu (andreea.suiu) 
 update fd10 did
 Revision 1.10.2.22 2023/04/25 09:13:02EEST Andreea Suiu (andreea.suiu) 
 Fix DIA after review
 Revision 1.10.2.21 2023/04/18 18:22:00EEST Andreea Suiu (andreea.suiu) 
 Update DIA module according to the coding rules
 Revision 1.10.2.20 2023/04/18 18:08:06EEST Andreea Suiu (andreea.suiu) 
 Update DIA module according to the coding rules
 Revision 1.10.2.19 2023/04/18 16:39:04EEST Andreea Suiu (andreea.suiu) 
 Fix DIA module after review
 Revision 1.10.2.18 2023/04/06 13:26:31EEST Andreea Suiu (andreea.suiu) 
 Add ascii restrictions (first version)
 Revision 1.10.2.17 2023/03/30 07:33:39EEST Dan Dustinta (dan.dustinta) 
 fix variable declaration
 Revision 1.10.2.16 2023/03/24 14:08:41EET Andreea Suiu (andreea.suiu) 
 Add comment
 Revision 1.10.2.15 2023/03/15 10:15:20EET Andreea Suiu (andreea.suiu) 
 Add OEM diagnostics
 Revision 1.10.2.14 2023/02/28 18:07:47EET Septimiu Vintila (septimiu.vintila) 
 Only relevant routines kept in FuSa memory section.
 Revision 1.10.2.13 2023/02/28 17:15:02EET Septimiu Vintila (septimiu.vintila) 
 Data sections changed to FuSa data sections.
 Revision 1.10.2.12 2023/02/28 16:35:52EET Septimiu Vintila (septimiu.vintila) 
 Code sections changed to FuSa code sections.
 Revision 1.10.2.11 2023/02/24 13:58:53EET Andreea Suiu (andreea.suiu) 
 Update DIA after QAC
 Revision 1.10.2.10 2023/02/24 10:07:40EET Andreea Suiu (andreea.suiu) 
 Update DIA module (update comments)
 Revision 1.10.2.9 2023/02/24 08:56:19EET Andreea Suiu (andreea.suiu) 
 Update diagnostic services (add RoutineInfo for DIA_runRidF797_AccAngleOffsetCalibrationStart)
 Revision 1.10.2.8 2023/02/23 17:26:03EET Andreea Suiu (andreea.suiu) 
 Update Diagnostic
 Revision 1.10.2.7 2023/02/23 16:17:51EET Andreea Suiu (andreea.suiu) 
 Update diagnostic services (add NRCs)
 Revision 1.10.2.6 2023/01/23 16:10:26EET Denis Folea (denis.folea) 
 DIA fix after review
 Revision 1.10.2.5 2023/01/20 15:24:05EET Denis Folea (denis.folea) 
 DIA fix after review
 Revision 1.10.2.4 2022/12/22 16:28:53EET Andrei Anca (andrei.anca) 
 Dia cleanup
 Revision 1.10.2.3 2022/11/25 12:47:56EET Dan Dustinta (dan.dustinta) 
 update DCM integration code
 Revision 1.1 2021/08/26 09:16:55EEST Pierre-Olivier Pilot (pierre-olivier.pilot)
 Initial revision

 *************************************************************************/

/******************************************************************************
End Of File
 *****************************************************************************/
