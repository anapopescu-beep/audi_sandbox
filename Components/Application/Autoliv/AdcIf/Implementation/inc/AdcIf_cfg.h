#ifndef ADCIF_CFG_H_
#define ADCIF_CFG_H_ 1

/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------------------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
H-File Template Version: 
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
*******************************************************************************

Overview of the interfaces:
   This file defines the information (interfaces, definitions and data) provided
	by the module AdcIf, part of the component AdcIf.

******************************************************************************/
/*
$Revision: 1.6.1.4.1.2.1.4 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/AdcIf/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Adc.h"
#include "Adc_Types.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/

/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
/* ------------------------------------------------------------------------------*/
/* ! CHANGE ENUM POSITION ONLY ACCORDING TO TRESOS CONFIGURATION OF ADC GROUPS ! */
/* ------------------------------------------------------------------------------*/
/*! 
 *  \brief
 *        This enum contains all ADC channels indexes used from MCU's group 0.
 *  \remark
 *        No unit has been defined for this enumeration.
 */
typedef enum AdcIf_Group0_Channels_Type
{
   ADCIF_ENUM_GROUP0_ADC_MAG_V_5 = 0x00u,
   ADCIF_ENUM_GROUP0_ADC_MAG_V_6,
   ADCIF_ENUM_GROUP0_ADC_WAKE_1,
   ADCIF_ENUM_GROUP0_ADC_WAKE_2,
   ADCIF_ENUM_GROUP0_ADC_REF_HIGH,
   ADCIF_ENUM_GROUP0_ADC_REF_LOW,
   ADCIF_ENUM_GROUP0_ADC_ECU_TEMP_MCU_VREF,
   ADCIF_ENUM_GROUP0_ADC_ECU_TEMP_MCU,
   ADCIF_ENUM_GROUP0_ADC_MAG_V_5_1,
   ADCIF_ENUM_GROUP0_ADC_MAG_V_6_1,
   ADCIF_ENUM_GROUP0_ADC_MAG_V_5_2,
   ADCIF_ENUM_GROUP0_ADC_MAG_V_6_2,

   ADCIF_ENUM_GROUP0_NB_CHANNELS
}AdcIf_Group0_Channels_Type;

/* ------------------------------------------------------------------------------*/
/* ! CHANGE ENUM POSITION ONLY ACCORDING TO TRESOS CONFIGURATION OF ADC GROUPS ! */
/* ------------------------------------------------------------------------------*/
/*!
 *  \brief
 *        This enum contains all ADC channels indexes used from MCU's group 1.
 *  \remark
 *        No unit has been defined for this enumeration. 
 */
typedef enum AdcIf_Group1_Channels_Type
{
   ADCIF_ENUM_GROUP1_ADC_MAG_V_1,
   ADCIF_ENUM_GROUP1_ADC_MAG_V_2,
   ADCIF_ENUM_GROUP1_ADC_MAG_V_3,
   ADCIF_ENUM_GROUP1_ADC_MAG_V_4,
   ADCIF_ENUM_GROUP1_ADC_V_KL30,
   ADCIF_ENUM_GROUP1_ADC_ECU_TEMP_PTC,
   ADCIF_ENUM_GROUP1_ADC_BOOST_DIAG,
   ADCIF_ENUM_GROUP1_ADC_MAG_V_1_1,
   ADCIF_ENUM_GROUP1_ADC_MAG_V_2_1,
   ADCIF_ENUM_GROUP1_ADC_MAG_V_3_1,
   ADCIF_ENUM_GROUP1_ADC_MAG_V_4_1,
   ADCIF_ENUM_GROUP1_ADC_MAG_V_1_2,
   ADCIF_ENUM_GROUP1_ADC_MAG_V_2_2,
   ADCIF_ENUM_GROUP1_ADC_MAG_V_3_2,
   ADCIF_ENUM_GROUP1_ADC_MAG_V_4_2,
   ADCIF_ENUM_GROUP1_NB_CHANNELS
}AdcIf_Group1_Channels_Type;

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/
#define AdcIf_START_SEC_VAR_INIT_16_ASIL_A
#include "AdcIf_MemMap.h"

/* Array used to copy ADC channels values from ADC Group 0. */
extern Adc_ValueGroupType ADCIF_au16Group0Results[ADC_CFGSET_TDK_4G_GROUP_0_CHANNELS];

/* Array used to copy ADC channels values from ADC Group 1. */
extern Adc_ValueGroupType ADCIF_au16Group1Results[ADC_CFGSET_TDK_4G_GROUP_1_CHANNELS];

#define AdcIf_STOP_SEC_VAR_INIT_16_ASIL_A
#include "AdcIf_MemMap.h"
/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
/* Function used to copy ADC channels values from ADC Group 0. */
extern void ADCIF_EndOfConvGroup0(void);

/* Function used to copy ADC channels values from ADC Group 1. */
extern void ADCIF_EndOfConvGroup1(void);

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/
#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/
#endif /* ADCIF_CFG_H_ */
