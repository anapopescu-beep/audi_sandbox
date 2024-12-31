
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
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.9 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/DioIf/Quality_Assurance/Static_Analysis/project.pj $
*/
/* PRQA S 0288 -- */
/*!****************************************************************************

Overview of the interfaces:
   This file defines the information (interfaces, definitions and data) provided
   by the module DioIf, part of the component DioIf.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"
#include "Config.h"
#include "Dio_cfg.h"
#include "Rte_DioIf.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/
#define DioIf_START_SEC_CONST_8_ASIL_A
#include "DioIf_MemMap.h"

/**
 * \brief
 *      This constant is used to retain all DIO mapping channels.
 */
EXPORTED const uint8 kau8DioMapping[DIOIF_CH_MAX]=
{
	(uint8)DioConf_DioChannel_Dio_EN_CS1,	 		/* DIOIF_CH_EN_CS_1		<> DioConf_DioChannel_Dio_EN_CS1 */
	(uint8)DioConf_DioChannel_Dio_EN_CS2,	 		/* DIOIF_CH_EN_CS_2		<> DioConf_DioChannel_Dio_EN_CS2 */
	(uint8)DioConf_DioChannel_Dio_EN_CS3,	 		/* DIOIF_CH_EN_CS_3		<> DioConf_DioChannel_Dio_EN_CS3 */
	(uint8)DioConf_DioChannel_Dio_EN_CS4,        	/* DIOIF_CH_EN_CS_4     <> DioConf_DioChannel_Dio_EN_CS4 */
	(uint8)DioConf_DioChannel_Dio_EN_CS5,
	(uint8)DioConf_DioChannel_Dio_EN_CS6,
	(uint8)DioConf_DioChannel_Dio_BOOST, 			/* DIOIF_CH_EN_BOOST     <> DioConf_DioChannel_Dio_BOOST */
	(uint8)DioConf_DioChannel_Dio_ON_OFF_Power,
	(uint8)DioConf_DioChannel_Dio_ALARMB,
	(uint8)DioConf_DioChannel_Dio_Wake_Cyclic_Power,
#if (1 == CAL_KU8_MOCK_UP_HW_CONFIGURATION)
	(uint8)DioConf_DioChannel_Dio_Wake_Sw1,
	(uint8)DioConf_DioChannel_Dio_Wake_Sw2,
#else
	(uint8)0,        /* Dummy entry should have no effect */
	(uint8)0,
#endif
};

#define DioIf_STOP_SEC_CONST_8_ASIL_A
#include "DioIf_MemMap.h"

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
