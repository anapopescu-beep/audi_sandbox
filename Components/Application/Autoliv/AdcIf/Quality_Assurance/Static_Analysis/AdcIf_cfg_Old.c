
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
$Revision: 1.4.2.7 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/AdcIf/Quality_Assurance/Static_Analysis/project.pj $
*/
/*!****************************************************************************

details
	Configuration and interfaces for the AdcIf component

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"
#include "AdcIf_cfg.h"
#include "AdcIf.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *      Macro used to set an invalid array length.
 *      This setting will trigger an error compilation.
 */
#define KS8_ADCIF_INVALID_ARRAY_LENGTH     ((sint8)-1)

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define AdcIf_START_SEC_VAR_NO_INIT_16_ASIL_A
#include "AdcIf_MemMap.h"

/**
 * \brief
 *      Array used to check if enum group 0 number of channels are the same as macro value. 
 *      This array must ONLY be defined, but NOT BE USED in source code. 
 *      This check has been made into an array because preprocessor does not take in account
 *      enum variables, so the #if..#error..#endif directive does not properly work.
 *      When compilation failed with length error, it needs to be checked that all channels 
 *      from Tresos configuration of ADC component are in same order that are defined in 
 *      AdcIf_Group0_Channels_Type enum. 
 *      Otherwise, enum must be modified according to Tresos configuration of ADC channels 
 *      arragement, both for Group 0 and Group 1.
 * \initialization 
 *      No intialization needed because this must NOT be used anywhere in source code.
 * \range
 *      0..unit16, and length of -1 to 1.
 */
LOCAL uint16 adcif_u16CheckGroup0ChannelsLength[(ADCIF_ENUM_GROUP0_NB_CHANNELS != ADC_CFGSET_GROUP_0_CHANNELS) ? KS8_ADCIF_INVALID_ARRAY_LENGTH : 1];

/**
 * \brief
 *      Array used to check if enum group 1 number of channels are the same as macro value. 
 *      This array must ONLY be defined, but NOT BE USED in source code. 
 *      This check has been made into an array because preprocessor does not take in account
 *      enum variables, so the #if..#error..#endif directive does not properly work.
 *      When compilation failed with length error, it needs to be checked that all channels 
 *      from Tresos configuration of ADC component are in same order that are defined in 
 *      AdcIf_Group1_Channels_Type enum. 
 *      Otherwise, enum must be modified according to Tresos configuration of ADC channels 
 *      arragement, both for Group 0 and Group 1.
 * \initialization 
 *      No intialization needed because this must NOT be used anywhere in source code.
 * \range
 *      0..unit16, and length of -1 to 1.
 */
LOCAL uint16 adcif_u16CheckGroup1ChannelsLength[(ADCIF_ENUM_GROUP1_NB_CHANNELS != ADC_CFGSET_GROUP_1_CHANNELS) ? KS8_ADCIF_INVALID_ARRAY_LENGTH : 1];

#define AdcIf_STOP_SEC_VAR_NO_INIT_16_ASIL_A
#include "AdcIf_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
/**
 * \brief
 *      Array used to copy ADC channels values from ADC Group 0.
 * \initialization
 *		KU16_ZERO
 * \range
 *      KU16_ZERO
 */
EXPORTED Adc_ValueGroupType ADCIF_au16Group0Results[ADC_CFGSET_GROUP_0_CHANNELS] = {
   KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO,
   KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};

/**
 * \brief
 *      Array used to copy ADC channels values from ADC Group 1.
 * \initialization
 *      KU16_ZERO
 * \range
 *      KU16_ZERO
 */
EXPORTED Adc_ValueGroupType ADCIF_au16Group1Results[ADC_CFGSET_GROUP_1_CHANNELS] = {
   KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO,
   KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO, KU16_ZERO
};
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
#define AdcIf_START_SEC_CODE_ASIL_A
#include "AdcIf_MemMap.h"

/**
 * \brief
 *       This function is used to read ADC lines from Group 0 of ADC channels.
 *       From this function, data will be send via ADCIF_u16Group0Results global array.
 * \dynamicaspectcaller
 *       AdcIf SW Component.
 * \dynamicaspectdescription
 *       Called in AdcIf_GPTOnTimer_Expiration ISR. 
 * \constrains
 *       ADC Pheripheral must be initialised.
 * \return
 *       This function has no return.
 * \ddesignrequirement
 *       DSG_ADCIF_EndOfConvGroup0
 * \archrequirement
 *       ARCH_SW_AdcIf_ptrpAsrGptServicesAdcIf
 *       ARCH_SW_AdcIf_ptrrAsrAdcServicesAdcIf_Adc_ReadGroup_AdcIf_GPTOnTimer_Expiration
 **/
EXPORTED void ADCIF_EndOfConvGroup0(void)
{
   Std_ReturnType u8ReturnGroup0 = E_NOT_OK;
   uint8 u8NoOfRetries = KU8_ZERO;

   do
   {
      u8ReturnGroup0 = Adc_ReadGroup(AdcGroup_0, ADCIF_au16Group0Results);
      u8NoOfRetries++;

   }while((E_NOT_OK == u8ReturnGroup0) && (u8NoOfRetries < KU8_SIXTY));

}

/**
 * \brief
 *       This function is used to read ADC lines from Group 1 of ADC channels.
 *       From this function, data will be send via ADCIF_u16Group1Results global array.
 * \dynamicaspectcaller
 *       AdcIf SW Component.
 * \dynamicaspectdescription
 *       Called in AdcIf_GPTOnTimer_Expiration ISR. 
 * \constrains
 *       ADC Pheripheral must be initialised.
 * \return
 *       This function has no return.
 * \ddesignrequirement
 *       DSG_ADCIF_EndOfConvGroup1
 * \archrequirement
 *       ARCH_SW_AdcIf_ptrpAsrGptServicesAdcIf
 *       ARCH_SW_AdcIf_ptrrAsrAdcServicesAdcIf_Adc_ReadGroup_AdcIf_GPTOnTimer_Expiration
 **/
EXPORTED void ADCIF_EndOfConvGroup1(void)
{
   Std_ReturnType u8ReturnGroup1 = E_NOT_OK;
   uint8 u8NoOfRetries = KU8_ZERO;

   do
   {
      u8ReturnGroup1 = Adc_ReadGroup(AdcGroup_1, ADCIF_au16Group1Results);
      u8NoOfRetries++;
   }while((E_NOT_OK == u8ReturnGroup1) && (u8NoOfRetries < KU8_SIXTY));
}

#define AdcIf_STOP_SEC_CODE_ASIL_A
#include "AdcIf_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
