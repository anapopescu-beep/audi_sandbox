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
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/FblUsr/Quality_Assurance/Static_Analysis/project.pj $
 */
/*!****************************************************************************

@details
   This file contains BlPduR callbacks.

 ******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "BlPduR_Prj.h"
#include "BL_Nvm.h"
#include "common.h"
/*********************************************************************************/
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
/******************************************************************************
MODULE FUNCTION-LIKE MACROS
 ******************************************************************************/
/******************************************************************************
DEFINITION OF LOCAL FUNCTION
 ******************************************************************************/
/**
 * \brief
 *      Request communication mode = up.
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       BlPduR_Cbk module.
 * \dynamicaspectdescription
 *       Called in BlPduR_Custom_Com_Init function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_FblUsr_BlPduR_Custom_RequestCommunicationUp
 * \archrequirement
 *       None.
 **/
LOCAL void BlPduR_Custom_RequestCommunicationUp(void)
{
	(void)CanSM_RequestComMode(KU8_ZERO, COMM_FULL_COMMUNICATION);
}

/**
 * \brief
 *      Request communication mode = down.
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       BlPduR_Cbk module.
 * \dynamicaspectdescription
 *       Called in BlPduR_Custom_Com_Init function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_FblUsr_BlPduR_Custom_RequestCommunicationDown
 * \archrequirement
 *       None.
 **/
LOCAL void BlPduR_Custom_RequestCommunicationDown(void)
{

	(void)CanSM_RequestComMode(KU8_ZERO, COMM_NO_COMMUNICATION);


}
/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/
/**
 * \brief
 *      This service is at system initialization by BlPduR module to retrieve Group Id use in the ECU.
 *      The Group ID shall be retrieve depending on the system architecture (e.g. from NVM, from a specific I/O,..).
 *      It shall then be returned.
 * \pre
 *       None.
 * \return
 *       u8Side = value of the Group ID that shall be used in by the bootloader to run.
 * \dynamicaspectcaller
 *       BlPduR_Prg module.
 * \dynamicaspectdescription
 *       Called in BlPduR_Init2 function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *      DSG_FblUsr_BlPduR_GetGroupIdVal
 * \archrequirement
 *       ARCH_SW_FblUsr_BlPduR_GetGroupIdVal
 **/
EXPORTED u8 BlPduR_GetGroupIdVal (void)
{
	uint8 u8Side;
	/* Here the group ID shall be retrieve and returned */
	u8Side = KU8_ZERO;

	return u8Side;//stNoIntShareVar.ubSide;
}

/**
 * \brief
 *      Get the Rx Pdu Identifier on which the response after reset shall be sent.
 * \outputparam
 *       Name: ubRxPduId;
 *       Type: uint8;
 *       Description: pubRxpduId Rx Pdu Identifier pointer;
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       BlPduR_Prg module.
 * \dynamicaspectdescription
 *       Called in BlPduR_RetrieveConnectionInfo function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_FblUsr_BlPduR_GetRxPduId
 * \archrequirement
 *      ARCH_SW_FblUsr_BlPduR_GetRxPduId
 **/
EXPORTED void BlPduR_GetRxPduId(u8* ubRxPduId)
{
	if (KU8_ONE == gFlag)
	{
		*ubRxPduId = stNoIntShareVar.ubRxPduId;
	}
	else
	{
		*ubRxPduId = KU8_ZERO;
	}
}

/**
 * \brief
 *      Store the Rx Pdu Identifier on which the request shall be responded after reset has been received.
 * \inputparam
 *       Name: ubRxPduId;
 *       Type: uint8;
 *       Description: pubRxpduId Rx Pdu Identifier;
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       BlPduR_Prg module.
 * \dynamicaspectdescription
 *       Called in BlPduR_StoreConnectionInfo function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_FblUsr_BlPduR_StoreRxPduId
 * \archrequirement
 *       ARCH_SW_FblUsr_BlPduR_StoreRxPduId
 **/
EXPORTED void BlPduR_StoreRxPduId(u8 ubRxPduId)
{
	stNoIntShareVar.ubRxPduId = ubRxPduId;
}

/**
 * \brief
 *      Initialization of modules of communication stack.
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       BlPduR_Prg module.
 * \dynamicaspectdescription
 *       Called in BlPduR_Init1 function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_FblUsr_BlPduR_Custom_Com_Init
 * \archrequirement
 *       ARCH_SW_FblUsr_BlPduR_Custom_Com_Init
 **/
EXPORTED void BlPduR_Custom_Com_Init(void)
{

#if (BLPDUR_USE_PDUR == STD_ON)
	/* If one of the ASR stack is configured initialize the PduR */
	PduR_Init(BASE_PDUR_CONFIG_PTR);
#endif
	/* Init */
	/* Start Can Controller */
	Can_Init(&CanConfigSet);

	CanIf_Init(BASE_CANIF_CONFIG_PTR);

	CanTp_Init(BASE_CANTP_CONFIG_PTR);

	CanSM_Init(BASE_CANSM_CONFIG_PTR);

	/* Request for FULL communication */
	BlPduR_Custom_RequestCommunicationUp();

}

/**
 * \brief
 *      Deactivate communication.
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       Prog_Cust_AppliCheck module.
 * \dynamicaspectdescription
 *       Called in PROG_SwitchApplicationMode function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_FblUsr_BlPduR_Custom_Com_Deactivate
 * \archrequirement
 *      ARCH_SW_FblUsr_BlPduR_Custom_Com_Deactivate
 **/
EXPORTED void BlPduR_Custom_Com_Deactivate(void)
{
	BlPduR_Custom_RequestCommunicationDown();
}
/******************************************************************************
End Of File
 *****************************************************************************/
