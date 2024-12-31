
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
$Revision: 1.9 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/NmIf/Implementation/src/project.pj $
*/
/*****************************************************************************

details
   Application level module which collects the bus communication status (timeout 
   or reception/ transmission) and coordinates the bus communication access 
   requests.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "NmIf.h"
#include "Rte_NmIf.h"
#include "BswM.h"
#include "BswM_Callouts.h"
#include "ComM.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *		Flag associated with ECS 01 Frame id timeout event
 */
#define KU8_NMIF_AIRBAG_ECS_01_FRAME_TIMEOUT     ((uint8) 0x01)

/**
 * \brief
 *		Flag associated with Airbag 01 Frame id timeout event
 */
#define KU8_NMIF_AIRBAG_01_FRAME_TIMEOUT         ((uint8) 0x02)

/**
 * \brief
 *		Flag associated with Airbag 02 Frame id timeout event
 */
#define KU8_NMIF_AIRBAG_02_FRAME_TIMEOUT         ((uint8) 0x04)

/**
 * \brief
 *		Flag associated with ECS 01 Frame id wakeup event
 */
#define KU8_NMIF_AIRBAG_ECS_01_FRAME_WAKEUP      ((uint8) 0x01)

/**
 * \brief
 *		Flag associated with Airbag 01 Frame id wakeup event
 */
#define KU8_NMIF_AIRBAG_01_FRAME_WAKEUP          ((uint8) 0x02)

/**
 * \brief
 *		Flag associated with Airbag 02 Frame id wakeup event
 */
#define KU8_NMIF_AIRBAG_02_FRAME_WAKEUP          ((uint8) 0x04)

/**
 * \brief
 *		Flag associated with a bus timeout and represent the 
 *    logic AND between ECS 01, Airbag 01 and Airbag 02 defines
 */
#define KU8_NMIF_BUS_TIMEOUT                     ((uint8) 0x07)

/**
 * \brief
 *		Flag associated with a bus wakeup
 */
#define KU8_NMIF_BUS_WAKEUP                      ((uint8) 0x00)

/**
 * \brief
 *		Flag associated NO_COMMUNICATION COMM command active
 */
#define KU8_NMIF_NO_COMM_ACTIVE                  ((uint8) 0x01)

/**
 * \brief
 *		Flag associated NO_COMMUNICATION COMM command not active
 */
#define KU8_NMIF_NO_COMM_NOT_ACTIVE              ((uint8) 0x02)

/**
 * \brief
 *		Flag associated FULL_COMMUNICATION COMM command active
 */
#define KU8_NMIF_FULL_COMM_ACTIVE            ((uint8) 0x01)

/**
 * \brief
 *		Flag associated FULL_COMMUNICATION COMM command not active
 */
#define KU8_NMIF_FULL_COMM_NOT_ACTIVE            ((uint8) 0x02)

/**
 * \brief
 *		Flag associated PROCESS_MODE command requested
 */
#define KU8_NMIF_PROCESS_MODE_REQUESTED          ((uint8) 0xAA)
/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define NmIf_START_SEC_VAR_INIT_8
#include "NmIf_MemMap.h"
/**
 * \brief
 *       This variable is used to store the timeout status of all frames.
 * \initialization 
 *       0x00.
 * \range
 *       0x01 - If ECS_01 frame timed out
 *       0x03 - If ECS_01 and Airbar_01 frames have timed out
 *       0x07 - If ECS_01 and Airbag_01 and Airbag_02 frames have timed out;
 */
LOCAL uint8 nmif_u8TimeoutFramesStatus = KU8_ZERO;

/**
 * \brief
 *       This variable is used to store the wakeup status of all frames.
 * \initialization 
 *       0x00.
 * \range
 *       0x01 - If the ECS_01 frame has woken up
 *       0x03 - If ECS_01 and Airbar_01 frames woke up
 *       0x07 - If ECS_01 and Airbag_01 and Airbag_02 frames woke up;
 */
LOCAL uint8 nmif_u8WakeupFramesStatus = KU8_ZERO;

/**
 * \brief
 *       This variable is used to store the no communication status.
 * \initialization 
 *       0x02.
 * \range
 *       0x02 - If no communication mode is not active
 *       0x01 - If no communication mode is active;
 */
LOCAL uint8 nmif_u8NoCommunicationStatus = KU8_NMIF_NO_COMM_NOT_ACTIVE;

/**
 * \brief
 *       This variable is used to store the full communication status.
 * \initialization 
 *       0x02.
 * \range
 *       0x02 - If full communication mode is not active
 *       0x01 - If full communication mode is active;
 */
LOCAL uint8 nmif_u8FullCommunicationStatus = KU8_NMIF_FULL_COMM_NOT_ACTIVE;

#define NmIf_STOP_SEC_VAR_INIT_8
#include "NmIf_MemMap.h"
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
#define NmIf_START_SEC_CODE
#include "NmIf_MemMap.h"
/**
* \brief
*     Network management interface main function.
* \dynamicaspectcaller
*     TASK(OsTask_Alv_Com).
* \dynamicaspectdescription
*     This function is called by OS cyclic at every 10 ms.
* \constrains
*     ECU must be in RUN_STATE.
* \ddesignrequirement
*     DSG_NmIf_runMainFunction
* \archrequirement
*     ARCH_SW_NmIf_pclECUStateTransitionsBswMIf
*     ARCH_SW_NmIf_ptrpAsrOsServicesNmIf_NmIf_runMainFunction
*     ARCH_SW_NmIf_ptrrAsrBswMServicesNmIf_NmIf_runMainFunction
*     ARCH_SW_NmIf_ptrrAsrComMServicesNmIf_NmIf_runMainFunction
*     ARCH_SW_NmIf_ptrrNmIfServicesBswMIf_NmIf_runMainFunction
*/
EXPORTED void NmIf_runMainFunction(void)
{

   /* Check if bus timeout is received AND transmission and reception of frames is still active */
   if((KU8_NMIF_BUS_TIMEOUT == nmif_u8TimeoutFramesStatus) && (KU8_NMIF_NO_COMM_NOT_ACTIVE == nmif_u8NoCommunicationStatus))
   {
      /* Check if in the previous check a wakeup was detected */
      if(KU8_NMIF_BUS_WAKEUP == nmif_u8WakeupFramesStatus)
      {
         /* Disable transmission and reception of frames */
         (void)ComM_ASR40_RequestComMode(0u, COMM_NO_COMMUNICATION);

         /* Set no communication status flag to active */
         nmif_u8NoCommunicationStatus = KU8_NMIF_NO_COMM_ACTIVE;

         /* Set full communication status flag to not active */
         nmif_u8FullCommunicationStatus = KU8_NMIF_FULL_COMM_NOT_ACTIVE;

         /* Set TX PDU request port to disable tx to be able to trigger BswM rule */
         BswM_RequestMode(KU8_BSWM_TX_PDU_STATE_REQUESTED_PORT, BSWM_DISABLE_TX_PDU);
      }
   }

   /* Check if wakeup is received on bus AND transmission and reception of frames is not active */
   if((KU8_NMIF_BUS_WAKEUP != nmif_u8WakeupFramesStatus) && (KU8_NMIF_FULL_COMM_NOT_ACTIVE == nmif_u8FullCommunicationStatus))
   {
      /* Reset RunToLowPowerTransitionStatus */
      Rte_Call_pclEcuStateTransitionBswMIf_BswM_SetEcuStateTransitionStatus(KU8_FALSE);

      /* Enable transmission and reception of frames */
      (void)ComM_ASR40_RequestComMode(0u, COMM_FULL_COMMUNICATION);

      /* Set full communication status flag to active */
      nmif_u8FullCommunicationStatus = KU8_NMIF_FULL_COMM_ACTIVE;

      /* Set no communication status flag to not active */
      nmif_u8NoCommunicationStatus = KU8_NMIF_NO_COMM_NOT_ACTIVE;

      /* Reset timeout frame status flag */
      nmif_u8TimeoutFramesStatus = KU8_ZERO;

      /* Set TX PDU request port to enable tx to be able to trigger BswM rule */
      BswM_RequestMode(KU8_BSWM_TX_PDU_STATE_REQUESTED_PORT, BSWM_ENABLE_TX_PDU);
   }
}

/**
* \brief
*     This service is a callout used to set the Airbag_eCS_01
*     frame timeout flag.
* \dynamicaspectcaller
*     Tresos-configured ComTimeoutNotification callback.
* \dynamicaspectdescription
*     This function is called every time any signal 
*     corresponding to Airbag_eCS_01 frame expires.
* \constrains
*     ECU must be initialized.
* \ddesignrequirement
*     DSG_NmIf_CbkRxTOut_Airbag_eCS_01
* \archrequirement
*     ARCH_SW_NmIf_ptrpAsrComServicesNmIf_NmIf_CbkRxTOut_Airbag_eCS_01
*/
EXPORTED void NmIf_CbkRxTOut_Airbag_eCS_01(void)
{
   /* If Process Mode is not active, set frame timeout 
   (this condition is used to avoid to stop RX frame if bus timeout 
   is received )*/
   if(KU8_NMIF_PROCESS_MODE_REQUESTED != NVP_u8ProcessMode)
   {
      /* Set Airbag_eCS_01 frame flag in TimeoutFramesStatus variable */
      nmif_u8TimeoutFramesStatus |= KU8_NMIF_AIRBAG_ECS_01_FRAME_TIMEOUT;

      /* Reset wakeup frame status flag because timeout received */
      nmif_u8WakeupFramesStatus = KU8_ZERO;
   } 
}

/**
* \brief
*     This service is a callout used to set the Airbag_01 
*     frame timeout flag.
* \dynamicaspectcaller
*     Tresos-configured ComTimeoutNotification callback.
* \dynamicaspectdescription
*     This function is called every time any signal 
*     corresponding to Airbag_01 frame expires.
* \constrains
*     ECU must be initialized.
* \ddesignrequirement
*     DSG_NmIf_CbkRxTOut_Airbag_01
* \archrequirement
*     ARCH_SW_NmIf_ptrpAsrComServicesNmIf_NmIf_CbkRxTOut_Airbag_01
*/
EXPORTED void NmIf_CbkRxTOut_Airbag_01(void)
{
   /* If Process Mode is not active, set frame timeout 
   (this condition is used to avoid to stop RX frame if bus timeout 
   is received )*/
   if(KU8_NMIF_PROCESS_MODE_REQUESTED != NVP_u8ProcessMode)
   {
      /* Set Airbag_01 frame flag in TimeoutFramesStatus variable */
      nmif_u8TimeoutFramesStatus |= KU8_NMIF_AIRBAG_01_FRAME_TIMEOUT;

      /* Reset wakeup frame status flag because timeout received */
      nmif_u8WakeupFramesStatus = KU8_ZERO;
   }
}

/**
* \brief
*     This service is a callout used to set the Airbag_02 
*     frame timeout flag.
* \dynamicaspectcaller
*     Tresos-configured ComTimeoutNotification callback.
* \dynamicaspectdescription
*     This function is called every time any signal 
*     corresponding to Airbag_02 frame expires.
* \constrains
*     ECU must be initialized.
* \ddesignrequirement
*     DSG_NmIf_CbkRxTOut_Airbag_02
* \archrequirement
*     ARCH_SW_NmIf_ptrpAsrComServicesNmIf_NmIf_CbkRxTOut_Airbag_02
*/
EXPORTED void NmIf_CbkRxTOut_Airbag_02(void)
{
   /* If Process Mode is not active, set frame timeout 
   (this condition is used to avoid to stop RX frame if bus timeout 
   is received )*/
   if(KU8_NMIF_PROCESS_MODE_REQUESTED != NVP_u8ProcessMode)
   {
      /* Set Airbag_02 frame flag in TimeoutFramesStatus variable */
      nmif_u8TimeoutFramesStatus |= KU8_NMIF_AIRBAG_02_FRAME_TIMEOUT;

      /* Reset wakeup frame status flag because timeout received */
      nmif_u8WakeupFramesStatus = KU8_ZERO;
   }
}

/**
* \brief
*     This service is a callout used to set the Airbag_eCS_01 
*     Rx acknowledge flag.
* \dynamicaspectcaller
*     Tresos-configured ComNotification callback.
* \dynamicaspectdescription
*     This function is called every time on every RX acknowledge 
*     signal that corresponds to the  Airbag_eCS_01 frame.
* \constrains
*     ECU must be initialized.
* \ddesignrequirement
*     DSG_NmIf_CbkRxAck_Airbag_eCS_01
* \archrequirement
*     ARCH_SW_NmIf_ptrpAsrComServicesNmIf_NmIf_CbkRxAck_Airbag_eCS_01
*/
EXPORTED void NmIf_CbkRxAck_Airbag_eCS_01(void)
{
   /* Set Airbag_eCS_01 frame flag in WakeupFramesStatus variable */
   nmif_u8WakeupFramesStatus |= KU8_NMIF_AIRBAG_ECS_01_FRAME_WAKEUP;

   nmif_u8TimeoutFramesStatus &= (uint8)(~KU8_NMIF_AIRBAG_ECS_01_FRAME_TIMEOUT);
}

/**
* \brief
*     This service is a callout used to set the Airbag_01 
*     Rx acknowledge flag.
* \dynamicaspectcaller
*     Tresos-configured ComNotification callback.
* \dynamicaspectdescription
*     This function is called every time on every RX acknowledge 
*     signal that corresponds to the Airbag_01 frame.
* \constrains
*     ECU must be initialized.
* \ddesignrequirement
*     DSG_NmIf_CbkRxAck_Airbag_01
* \archrequirement
*     ARCH_SW_NmIf_ptrpAsrComServicesNmIf_NmIf_CbkRxAck_Airbag_01
*/
EXPORTED void NmIf_CbkRxAck_Airbag_01(void)
{
   /* Set Airbag_01 frame flag in WakeupFramesStatus variable */
   nmif_u8WakeupFramesStatus |= KU8_NMIF_AIRBAG_01_FRAME_WAKEUP;

   nmif_u8TimeoutFramesStatus &= (uint8)(~KU8_NMIF_AIRBAG_01_FRAME_TIMEOUT);
}

/**
* \brief
*     This service is a callout used to set the Airbag_02 
*     Rx acknowledge flag.
* \dynamicaspectcaller
*     Tresos-configured ComNotification callback.
* \dynamicaspectdescription
*     This function is called every time on every RX acknowledge 
*     signal that corresponds to the Airbag_02 frame.
* \constrains
*     ECU must be initialized.
* \ddesignrequirement
*     DSG_NmIf_CbkRxAck_Airbag_02
* \archrequirement
*     ARCH_SW_NmIf_ptrpAsrComServicesNmIf_NmIf_CbkRxAck_Airbag_02
*/
EXPORTED void NmIf_CbkRxAck_Airbag_02(void)
{
   /* Set Airbag_02 frame flag in WakeupFramesStatus variable */
   nmif_u8WakeupFramesStatus |= KU8_NMIF_AIRBAG_02_FRAME_WAKEUP;
   
   nmif_u8TimeoutFramesStatus &= (uint8)(~KU8_NMIF_AIRBAG_02_FRAME_TIMEOUT);
}

#define NmIf_STOP_SEC_CODE
#include "NmIf_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
