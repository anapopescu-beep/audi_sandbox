
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
$Revision: 1.1.1.7 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/PwmIf/Quality_Assurance/Static_Analysis/project.pj $
*/
/*!****************************************************************************
details
   This file defines the information (interfaces, definitions and data) provided
by the module PwmIf, part of the component PwmIf.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"
#include "Rte_PwmIf.h"
#include "PwmIf.h"
#include "Pwm.h"
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
#define PwmIf_START_SEC_CONST_8_ASIL_A
#include "PwmIf_MemMap.h"
/**
 * \brief
 *      This constant is used to retain configuration of PWM channels.
 */
LOCAL const uint8 kau8PwmMapping[PWMIF_CH_MAX]=
{
      PwmConf_PwmChannelConfigSet_Pwm_CH_SOLENOID_1,
      PwmConf_PwmChannelConfigSet_Pwm_CH_SOLENOID_2,
      PwmConf_PwmChannelConfigSet_Pwm_CH_SOLENOID_3,
      PwmConf_PwmChannelConfigSet_Pwm_CH_SOLENOID_4,
      PwmConf_PwmChannelConfigSet_Pwm_CH_SOLENOID_5,
      PwmConf_PwmChannelConfigSet_Pwm_CH_SOLENOID_6,
};
#define PwmIf_STOP_SEC_CONST_8_ASIL_A
#include "PwmIf_MemMap.h"
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

#define PwmIf_START_SEC_CODE_ASIL_A
#include "PwmIf_MemMap.h"

/**
* \brief
*       Function used to call Pwm pheripheral in order to update duty cycle on a specific channel.
* \inputparam
*       Name: u8TargetChannel;
*       Type: u8PwmChannelType;
*       Description: The ID of PWM Channel to be configured.;
*       Range:
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1 		
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_2
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_3
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1;
* \inputparam
*       Name: u16DutyCycle;
*       Type: u16PwmDutyCycleType;
*       Description: The Level of PWM Channel to be setted;
*       Range: 0..unit16;
* \pre
*       PWM Pheripheral must be initialised.
* \return
*       This function must not have any return.
* \dynamicaspectcaller
*       IoHwAb, SAD SW Components.
* \dynamicaspectdescription
*       Called to configure a specific PWM channel.
* \ddesignrequirement
*		  DSG_PwmIf_SetDutyCycle
* \archrequirement
*       ARCH_SW_PwmIf_psePwmServices_PwmIf_SetDutyCycle
*       ARCH_SW_DioIf_PwmIf_ptrrAsrPwmServicesPwmIf_Pwm_SetDutyCycle_PwmIf_SetDutyCycle
*/
EXPORTED void PwmIf_SetDutyCycle(u8PwmChannelType u8TargetChannel, u16PwmDutyCycleType u16DutyCycle)
{
   if ( u8TargetChannel < PWMIF_CH_MAX )
   {
      /* Call Pwm_SetDutyCycle API without any rework of parameters (processing is performed by Pwm MCAL module */
      Pwm_SetDutyCycle(kau8PwmMapping[u8TargetChannel], u16DutyCycle);
   }
}

#define PwmIf_STOP_SEC_CODE_ASIL_A
#include "PwmIf_MemMap.h"

#define PwmIf_START_SEC_CODE
#include "PwmIf_MemMap.h"

/**
* \brief
*       Function used to enable PWM signal on a specific channel.
* \inputparam
*       Name: cu8TargetChannel;
*       Type: u8PwmChannelType;
*       Description: The ID of PWM Channel to be configured;
*       Range:
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1 		
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_2
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_3
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1
*       	PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1;
* \pre
*       PWM Pheripheral must be initialised.
* \return
*       This function must not have any return.
* \dynamicaspectcaller
*       IoHwAb, SAD SW Components.
* \dynamicaspectdescription
*       Called to enable a specific PWM channel.
* \ddesignrequirement
*		DSG_PwmIf_EnablePWM
* \archrequirement
*       ARCH_SW_PwmIf_psePwmServices_PwmIf_EnablePWM
*/

EXPORTED void PwmIf_EnablePWM(u8PwmChannelType u8TargetChannel)
{
   if ( u8TargetChannel < PWMIF_CH_MAX )
   {
      /* Test the target channel where the order shall be applied */
      switch (u8TargetChannel)
      {
         default:
            /* This is an expected value of cu8TargetChannel argument. */
            /* The safest choice is to ignore this command */
         break;
      }
   }
}

/**
* \brief
*       Function used to disable PWM signal on a specific channel.
* \inputparam
*       Name: cu8TargetChannel;
*       Type: u8PwmChannelType;
*       Description: The ID of PWM Channel to be configured;
*       Range:
*       	  PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1 		
*       	  PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_2
*       	  PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_3
*       	  PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1
*       	  PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1
*       	  PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1
*       	  PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1
*       	  PwmConf_PwmChannelConfigSet_Pwm_CH_LDO_1;
* \pre
*       PWM Pheripheral must be initialised.
* \return
*       This function must not have any return.
* \dynamicaspectcaller
*       IoHwAb, SAD SW Components.
* \dynamicaspectdescription
*       Called to disable a specific PWM channel.
* \ddesignrequirement
*		DSG_PwmIf_DisablePWM
* \archrequirement
*       ARCH_SW_PwmIf_psePwmServices_PwmIf_DisablePWM
*/

EXPORTED void PwmIf_DisablePWM(u8PwmChannelType cu8TargetChannel)
{
   if ( cu8TargetChannel < PWMIF_CH_MAX )
   {
      /* Test the target channel where the order shall be applied */
      switch (cu8TargetChannel)
      {
         default:
            /* This is an expected value of cu8TargetChannel argument. */
            /* The safest choice is to ignore this command */
         break;
      }
   }
}

#define PwmIf_STOP_SEC_CODE
#include "PwmIf_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/
