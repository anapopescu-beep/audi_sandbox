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
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/APP/Quality_Assurance/Static_Analysis/project.pj $
 */
/*!****************************************************************************

@details
   API implementations of APP software component. 

 ******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "EB_Prj.h"
#include "board.h"
#include <S32K144.h>
#include <common.h>
/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
/**
 * \brief
 *       KU8_RECEIVED_DATA_LENGTH Value definition.
 *
 **/
#define KU8_RECEIVED_DATA_LENGTH     (12u)
/**
 * \brief
 *       KU8_FLASH_ADRESS_VALUE Value definition.
 *
 **/
#define KU8_FLASH_ADRESS_VALUE       (0x45u)
/**
 * \brief
 *       KU8_FLASH_ADRESS_POSITION Value definition.
 *
 **/
#define KU8_FLASH_ADRESS_POSITION    (3u)
/**
 * \brief
 *       KU16_DATA_STATUS_POSITION Value definition.
 *
 **/
#define KU16_DATA_STATUS_POSITION     ((uint16) 5)
/**
 * \brief
 *       KU8_DATA_ARRAY_START_INDEX Value definition.
 *
 **/
#define KU8_DATA_ARRAY_START_INDEX   (4u)
/**
 * \brief
 *       KU8_DATA_ARRAY_LENGTH Value definition.
 *
 **/
#define KU8_DATA_ARRAY_LENGTH        (12u)

#define KU8_VAL_80                   (0x80u)

#define KU8_VAL_30                   (0x30u)

#define KU8_VAL_10                   (0x10u)

#define KU8_VAL_20                   (0x20u)
/******************************************************************************
MODULE TYPES
 ******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
 ******************************************************************************/
__ramfunc LOCAL uint8 UnlockFlashRoutineRegOperations(u16 *u16DataLen, u8 *aubUdsData);

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

/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/
/**
 *\brief
 *      Interrupt enable function of APP SW Component. Interrupts must be resumed.
 *\inputparam
 *      Name: u8Status;
 *      Type: uint8;
 *      Description: parameter unused from Tresos-generated function;
 *\return
 *      None.
 *\dynamicaspectcaller
 *      Supplier Flash_TS_T40D2M7I0R0 module.
 *\dynamicaspectdescription
 *      Called in FLASH_LLD_EraseSector function.
 *\constrains
 *      None.
 *\ddesignrequirement
 *		DSG_APP_APP_InterruptEnable
 *\archrequirement
 *      ARCH_SW_APP_APP_InterruptEnable
 **/
EXPORTED void APP_InterruptEnable (uint8 u8Status)
{
	/* Implement here a treatment for a critical section exit. */
	BoardEnableInterrupts();
	OSC_PARAM_UNUSED(u8Status);
}

/**
 *\brief
 *      Interrupt disable function of APP SW Component. Interrupts must be suspended.
 *\return
 *      KU8_ZERO = always return 0 (Tresos generated function).
 *\dynamicaspectcaller
 *      Supplier Flash_TS_T40D2M7I0R0 module.
 *\dynamicaspectdescription
 *      Called in FLASH_LLD_EraseSector function.
 *\constrains
 *      None.
 *\ddesignrequirement
 *		DSG_APP_APP_InterruptDisable
 *\archrequirement
 *      ARCH_SW_APP_APP_InterruptDisable
 **/
EXPORTED uint8 APP_InterruptDisable (void)
{
	/* Implement here a treatment for a critical section entry. */
	BoardDisableInterrupts();
	return (KU8_ZERO);
}

/**
 * \brief
 *         Init function of APP SW Component.
 *         Here can be found all init API's of entire bootloader.
 *         This function initializes all layers of the complete STACK.
 *         EB_Init is called in this API.
 *         It shall be called only once at ECU startup.
 * \return
 *         None.
 *\dynamicaspectcaller
 *        BM_Prg module.
 *\dynamicaspectdescription
 *        Called in BM_BootStartUp function.
 *\constrains
 *        None.
 *\ddesignrequirement
 *		DSG_APP_APP_Init
 *\archrequirement
 *      ARCH_SW_APP_APP_Init
 **/
EXPORTED void APP_Init (void)
{
	BM_SoftwareInit();
}

//static uint8 app_ArrayCounter;
__ramfunc LOCAL uint8 UnlockFlashRoutineRegOperations(u16 *u16DataLen, u8 *aubUdsData)
{
	uint8 app_ArrayCounter = KU8_ZERO;
	uint8 u8RegVal = KU8_MAX;

	if((*u16DataLen) == KU8_DATA_ARRAY_LENGTH)
	{

		/* wait until the flash module is no longer busy */
		while(KU8_VAL_80 != (FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK))
		{
			; /*wait*/
		}

		/* check if there are any errors */
		//if(KU8_VAL_B0 == (FTFC->FSTAT & (FTFC_FSTAT_FPVIOL_MASK | FTFC_FSTAT_ACCERR_MASK)))
		if((KU8_VAL_30 == (FTFC->FSTAT & (FTFC_FSTAT_FPVIOL_MASK | FTFC_FSTAT_ACCERR_MASK))) ||
		   (KU8_VAL_10 == (FTFC->FSTAT & FTFC_FSTAT_FPVIOL_MASK)) ||
		   (KU8_VAL_20 == (FTFC->FSTAT & FTFC_FSTAT_ACCERR_MASK)))
		{
			FTFC->FSTAT = (FTFC_FSTAT_FPVIOL_MASK | FTFC_FSTAT_ACCERR_MASK);
		}

		/* write Flash address in memory controller register (Flash Common Command Object Registers) */
		FTFC->FCCOB[KU8_FLASH_ADRESS_POSITION] = KU8_FLASH_ADRESS_VALUE;


		/* write Flash data in memory controller register (Flash Common Command Object Registers) */

		for (app_ArrayCounter = KU8_DATA_ARRAY_START_INDEX; app_ArrayCounter < KU8_DATA_ARRAY_LENGTH; app_ArrayCounter++)
		{
			FTFC->FCCOB[app_ArrayCounter] = aubUdsData[app_ArrayCounter];
		}
		FTFC->FSTAT = FTFC_FSTAT_CCIF_MASK;

		while(KU8_VAL_80 != (FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK))
		{
			; /*wait*/
		}
		u8RegVal = FTFC->FSEC;
	}

	return u8RegVal;

};

/**
 *\brief
 *      Unlock Flash function of APP SW Component.
 *\inputparam
 *      Name: aubUdsData;
 *      Type: uint8;
 *      Description: pointer on request data;
 *      Name: pulLen;
 *      Type: PduLengthType;
 *      Description: pointer on data length;
 *\outputparam
 *      Name: pulLen;
 *      Type: PduLengthType;
 *      Description: pointer on data length;
 *      Name: aubUdsData;
 *      Type: uint8;
 *      Description: pointer on received data;
 *\return
 *      u8ret = Respond with acknowledge code or NRC code.
 *\dynamicaspectcaller
 *      Tresos_BSW_generated module.
 *\dynamicaspectdescription
 *      Tresos_BSW_generated - UDS_Cfg.
 *\constrains
 *      None.
 *\ddesignrequirement
 *		DSG_APP_APP_UnlockFlash
 *\archrequirement
 *      ARCH_SW_APP_APP_UnlockFlash
 **/
EXPORTED tUdsStatus APP_UnlockFlash(PduLengthType *pulLen, u8 *aubUdsData)
{
	//uint8 app_ArrayCounter = KU8_ZERO;

	tUdsStatus u8ret =  UDS_ACK;
	if(KU8_RECEIVED_DATA_LENGTH != (*pulLen))
	{
		u8ret = UDS_NRC_31;
	}
	else
	{
		BoardDisableInterrupts();

//		/* wait until the flash module is no longer busy */
//		while(KU8_VAL_80 != (FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK))
//		{
//			; /*wait*/
//		}
//
//		/* check if there are any errors */
//		if(KU8_VAL_B0 == (FTFC->FSTAT & (FTFC_FSTAT_FPVIOL_MASK | FTFC_FSTAT_ACCERR_MASK)))
//		{
//			FTFC->FSTAT = (FTFC_FSTAT_FPVIOL_MASK | FTFC_FSTAT_ACCERR_MASK);
//		}
//
//		/* write Flash address in memory controller register (Flash Common Command Object Registers) */
//		FTFC->FCCOB[KU8_FLASH_ADRESS_POSITION] = KU8_FLASH_ADRESS_VALUE;
//
//
//		/* write Flash data in memory controller register (Flash Common Command Object Registers) */
//
//		for (app_ArrayCounter = KU8_DATA_ARRAY_START_INDEX; app_ArrayCounter < KU8_DATA_ARRAY_LENGTH; app_ArrayCounter++)
//		{
//			FTFC->FCCOB[app_ArrayCounter] = aubUdsData[app_ArrayCounter];
//		}
//		FTFC->FSTAT = FTFC_FSTAT_CCIF_MASK;
//
//		while(KU8_VAL_80 != (FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK))
//		{
//			; /*wait*/
//		}


		//*pulLen = KU16_DATA_STATUS_POSITION;
		//aubUdsData[KU8_DATA_ARRAY_START_INDEX] =  FTFC->FSEC;
		//aubUdsData[KU8_DATA_ARRAY_START_INDEX] =  UnlockFlashRoutineRegOperations(&length, &data);
		aubUdsData[KU8_DATA_ARRAY_START_INDEX] =  UnlockFlashRoutineRegOperations(&pulLen[0], &aubUdsData[0]);

		*pulLen = KU16_DATA_STATUS_POSITION;

		BoardEnableInterrupts();
	} 

	return u8ret;
}

/**
 *\brief
 *      UDS Session status function of APP SW Component (Tresos generated function definition).
 *\inputparam
 *      Name: eUdsNewSessType;
 *      Type: tUdsSessionType;
 *      Description: new session;
 *      Name: eUdsOldSessType;
 *      Type: tUdsSessionType;
 *      Description: old session;
 *      Name: aubUdsData;
 *      Type: uint8;
 *      Description: pointer on received data;
 *      Name: eUdsChangingCause;
 *      Type: tUdsChangeReason;
 *      Description: the reason of the changing session;
 *\return
 *      None.
 *\dynamicaspectcaller
 *      BlPduR module.
 *\dynamicaspectdescription
 *      Called in UDS_SessionStatusInd function.
 *\constrains
 *      None.
 *\ddesignrequirement
 *		DSG_APP_APP_UdsSessionStatusInd
 *\archrequirement
 *      ARCH_SW_APP_APP_UdsSessionStatusInd
 **/
EXPORTED void APP_UdsSessionStatusInd (tUdsSessionType eUdsNewSessType,tUdsSessionType eUdsOldSessType,tUdsChangeReason eUdsChangingCause)
{
	OSC_PARAM_UNUSED(eUdsNewSessType);
	OSC_PARAM_UNUSED(eUdsOldSessType);
	OSC_PARAM_UNUSED(eUdsChangingCause);
}

/**
 *\brief
 *      Transmitter function of APP SW Component (Tresos generated function definition).
 *\inputparam
 *      Name: uMsgIdx;
 *      Type: tTpMsgIdx;
 *      Description: message ID;
 *      Name: ebStatus;
 *      Type: uint8;
 *      Description: status;
 *\return
 *      None.
 *\dynamicaspectcaller
 *      BlPduR module.
 *\dynamicaspectdescription
 *      Called in BlPduR_TxConf function.
 *      Callback is called: when a message reception is completed, successfully or not.
 *\constrains
 *      None.
 *\ddesignrequirement
 *		DSG_APP_APP_TpTxConf
 *\archrequirement
 *      ARCH_SW_APP_APP_TpTxConf
 **/
EXPORTED void APP_TpTxConf (tTpMsgIdx uMsgIdx, u8 ebStatus)
{
	OSC_PARAM_UNUSED(uMsgIdx);
	OSC_PARAM_UNUSED(ebStatus);
}

/**
 *\brief
 *      Receiver function of APP SW Component (Tresos generated function definition).
 *\inputparam
 *      Name: uMsgIdx;
 *      Type: tTpMsgIdx;
 *      Description: message ID;
 *      Name: ebStatus;
 *      Type: uint8;
 *      Description: status;
 *\return
 *      None.
 *\dynamicaspectcaller
 *      BlPduR module.
 *\dynamicaspectdescription
 *      Called in BlPduR_RxInd function.
 *      Callback is called: when a message reception is completed, successfully or not.
 *\constrains
 *      None.
 *\ddesignrequirement
 *		DSG_APP_APP_TpRxInd
 *\archrequirement
 *      ARCH_SW_APP_APP_TpRxInd
 **/
EXPORTED void APP_TpRxInd (tTpMsgIdx uMsgIdx, u8 ebStatus)
{
	OSC_PARAM_UNUSED(uMsgIdx);
	OSC_PARAM_UNUSED(ebStatus);
}

/**
 *\brief
 *      Variable range error check function of APP SW Component (Tresos generated function definition).
 *\inputparam
 *      Name: u16Param;
 *      Type: uint16;
 *      Description: parameter unused from Tresos-generated function;
 *\return
 *      None.
 *\dynamicaspectcaller
 *      Uds_TS_TxDxM3I17R0 module.
 *\dynamicaspectdescription
 *      Called in UDS_Prg.
 *\constrains
 *      None.
 *\ddesignrequirement
 *		DSG_APP_NCS_SdfVariableRangeError
 *\archrequirement
 *      ARCH_SW_APP_NCS_SdfVariableRangeError
 **/
EXPORTED void NCS_SdfVariableRangeError(uint16 u16Param)
{
	OSC_PARAM_UNUSED(u16Param);
}

/******************************************************************************
End Of File
 *****************************************************************************/
