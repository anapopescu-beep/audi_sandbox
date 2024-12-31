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
$Revision: 1.4 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/SchM/Implementation/src/project.pj $
*/
/*!****************************************************************************

@details
   This file contains the implementation of the SchM exclusive areas.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include <board.h>
#include <SchM_Prog.h>
#include <SchM_Det.h>
#include <SchM_Can.h>
#include <SchM_CanIf.h>
#include <SchM_CanSm.h>
#include <SchM_CanTp.h>
#include <SchM_Csm.h>
#include <SchM_Fee.h>
#include <SchM_Fls.h>
#include <SchM_NvM.h>
#include <SchM_Port.h>
#include <SchM_Spi.h>
#include <common.h>
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
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
#define SCHM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/**
 * \brief
 *       This function is used to disable interrupts when an event occurs (Prog module).
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       ProgVAG_TS_TxDxM0I13R0 module.
 * \dynamicaspectdescription
 *       Called in PROG_HSM_FIND_EV_TO_DISPATCH function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *       DSG_SchM_SchM_Enter_PROG_SCHM_PROG_EXCLUSIVE_AREA_0
 * \archrequirement
 *       ARCH_SW_SchM_Enter_PROG_SCHM_PROG_EXCLUSIVE_AREA_0
 **/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_PROG_SCHM_PROG_EXCLUSIVE_AREA_0 (void)
{
  BoardDisableInterrupts();

}

/**
 * \brief
 *       This function is used to enable interrupts when an event ends (Prog module).
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       ProgVAG_TS_TxDxM0I13R0 module.
 * \dynamicaspectdescription
 *       Called in PROG_HSM_FIND_EV_TO_DISPATCH function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_SchM_SchM_Enter_PROG_SCHM_PROG_EXCLUSIVE_AREA_0
 * \archrequirement
 *        ARCH_SW_SchM_Enter_PROG_SCHM_PROG_EXCLUSIVE_AREA_0
 **/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_PROG_SCHM_PROG_EXCLUSIVE_AREA_0 (void)
{
  BoardEnableInterrupts();

}

/**
 * \brief
 *       This function is used to disable interrupts when an event occurs (Det module).
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       Det_TS_TxDxM6I5R0 module.
 * \dynamicaspectdescription
 *       Called in Det_Enter_SCHM_DET_EXCLUSIVE_AREA_0 function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *       DSG_SchM_SchM_Enter_Det_SCHM_DET_EXCLUSIVE_AREA_0
 * \archrequirement
 *       ARCH_SW_SchM_Enter_Det_SCHM_DET_EXCLUSIVE_AREA_0
 **/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_Det_SCHM_DET_EXCLUSIVE_AREA_0(void)
{
  BoardDisableInterrupts();
}

/**
 * \brief
 *       This function is used to enable interrupts when an event ends  (Det module).
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       Det_TS_TxDxM6I5R0 module.
 * \dynamicaspectdescription
 *       Called in Det_Enter_SCHM_DET_EXCLUSIVE_AREA_0 function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_SchM_SchM_Exit_Det_SCHM_DET_EXCLUSIVE_AREA_0
 * \archrequirement
 *       ARCH_SW_SchM_Exit_Det_SCHM_DET_EXCLUSIVE_AREA_0
 **/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_Det_SCHM_DET_EXCLUSIVE_AREA_0(void)
{
  BoardEnableInterrupts();
}

/**
 * \brief
 *       This function is used to disable interrupts when an event occurs (CanIf module).
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       CanIf_TS_TxDxM6I9R0 module.
 * \dynamicaspectdescription
 *       Called in CanIf_Transmit function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *       DSG_SchM_SchM_Enter_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0
 * \archrequirement
 *       ARCH_SW_SchM_Enter_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0
 **/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0 (void)
{
  BoardDisableInterrupts();

}

/**
 * \brief
 *       This function is used to enable interrupts when an event ends (CanIf module).
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *        CanIf_TS_TxDxM6I9R0 module.
 * \dynamicaspectdescription
 *       Called in CanIf_GetControllerMode function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_SchM_SchM_Exit_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0
 * \archrequirement
 *       ARCH_SW_SchM_Exit_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0
 **/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0 (void)
{
  BoardEnableInterrupts();

}

/**
 * \brief
 *       This function is used to disable interrupts when an event occurs (CanSm module).
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       CanSM_TS_TxDxM3I6R0 module.
 * \dynamicaspectdescription
 *       Called in CanSM_RequestComMode function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *      DSG_SchM_SchM_Enter_CanSM_SCHM_CANSM_EXCLUSIVE_AREA_0
 * \archrequirement
 *      ARCH_SW_SchM_Enter_CanSM_SCHM_CANSM_EXCLUSIVE_AREA_0
 **/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_CanSM_SCHM_CANSM_EXCLUSIVE_AREA_0 (void)
{
  BoardDisableInterrupts();

}

/**
 * \brief
 *       This function is used to enable interrupts when an event ends (CanSm module).
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       CanSM_TS_TxDxM3I6R0 module.
 * \dynamicaspectdescription
 *      Called in CanSM_RequestComMode function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_SchM_SchM_Exit_CanSM_SCHM_CANSM_EXCLUSIVE_AREA_0
 * \archrequirement
 *       ARCH_SW_SchM_Exit_CanSM_SCHM_CANSM_EXCLUSIVE_AREA_0
 **/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_CanSM_SCHM_CANSM_EXCLUSIVE_AREA_0 (void)
{
  BoardEnableInterrupts();

}

/**
 * \brief
 *       This function is used to disable interrupts when an event occurs (CanTp module).
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *      CanTp_TS_TxDxM6I8R0 module.
 * \dynamicaspectdescription
 *       Called CANTP_ENTER_CRITICAL_SECTION function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *       DSG_SchM_SchM_Enter_CanTp_SCHM_CANTP_EXCLUSIVE_AREA_0
 * \archrequirement
 *       ARCH_SW_SchM_Enter_CanTp_SCHM_CANTP_EXCLUSIVE_AREA_0
 **/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_CanTp_SCHM_CANTP_EXCLUSIVE_AREA_0 (void)
{
  BoardDisableInterrupts();

}

/**
 * \brief
 *       This function is used to enable interrupts when an event ends (CanTp module).
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       CanTp_TS_TxDxM6I8R0 module.
 * \dynamicaspectdescription
 *       Called CANTP_LEAVE_CRITICAL_SECTION function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_SchM_SchM_Exit_CanTp_SCHM_CANTP_EXCLUSIVE_AREA_0
 * \archrequirement
 *    ARCH_SW_SchM_Exit_CanTp_SCHM_CANTP_EXCLUSIVE_AREA_0
 **/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_CanTp_SCHM_CANTP_EXCLUSIVE_AREA_0 (void)
{
  BoardEnableInterrupts();

}

/**
 * \brief
 *       This function is used to disable interrupts when an event occurs (Csm module).
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       Csm_TS_TxDxM2I0R0 module.
 * \dynamicaspectdescription
 *       Called Csm_MainFunction function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_SchM_SchM_Enter_Csm_SCHM_CSM_EXCLUSIVE_AREA_0
 * \archrequirement
 *    ARCH_SW_SchM_Enter_Csm_SCHM_CSM_EXCLUSIVE_AREA_0
 **/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_Csm_SCHM_CSM_EXCLUSIVE_AREA_0 (void)
{
   BoardDisableInterrupts();
}

/**
 * \brief
 *       This function is used to disable interrupts when an event occurs (Csm module).
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       Csm_TS_TxDxM2I0R0 module.
 * \dynamicaspectdescription
 *       Called Csm_MainFunction function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_SchM_SchM_Exit_Csm_SCHM_CSM_EXCLUSIVE_AREA_0
 * \archrequirement
 *    ARCH_SW_SchM_Exit_Csm_SCHM_CSM_EXCLUSIVE_AREA_0
 **/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_Csm_SCHM_CSM_EXCLUSIVE_AREA_0 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (SchM_Port module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Port_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Port_Port_Ci_SetPinMode function.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00
* \archrequirement
*      ARCH_SW_SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00(void)
{
  BoardDisableInterrupts();

}

/**
* \brief
*       This function is used to enable interrupts when an event ends (SchM_Port module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Port_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Port_Port_Ci_SetPinMode function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00
* \archrequirement
*       ARCH_SW_SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00(void)
{
  BoardEnableInterrupts();

}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (SchM_Port module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Port_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Port_Port_Ci_RefreshPortDirection function.
* \constrains
*       None.
* \ddesignrequirement
*        DSG_SchM_SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01
* \archrequirement
*       ARCH_SW_SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01(void)
{
  BoardDisableInterrupts();

}

/**
* \brief
*       This function is used to enable interrupts when an event ends (SchM_Port module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Port_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Port_Port_Ci_RefreshPortDirection function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01
* \archrequirement
*       ARCH_SW_SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01(void)
{
  BoardEnableInterrupts();

}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (NvM module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       NvM_TS_TxDxM6I17R0 module.
* \dynamicaspectdescription
*       Called in many functions.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_NvM_SCHM_NVM_EXCLUSIVE_AREA_0
* \archrequirement
*       ARCH_SW_SchM_Enter_NvM_SCHM_NVM_EXCLUSIVE_AREA_0
**/
EXPORTED void SchM_Enter_NvM_SCHM_NVM_EXCLUSIVE_AREA_0(void)
{
  BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (NvM module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       NvM_TS_TxDxM6I17R0 module.
* \dynamicaspectdescription
*       Called in many functions.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_NvM_SCHM_NVM_EXCLUSIVE_AREA_0
* \archrequirement
*       ARCH_SW_SchM_Exit_NvM_SCHM_NVM_EXCLUSIVE_AREA_0
**/
EXPORTED void SchM_Exit_NvM_SCHM_NVM_EXCLUSIVE_AREA_0(void)
{
  BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Fls module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*      Fls_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fls_Write function.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_13
* \archrequirement
*       ARCH_SW_SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_13
**/
EXPORTED void SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_13 (void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Fls module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Fls_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fls_Write function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_13
* \archrequirement
*        ARCH_SW_SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_13
**/
EXPORTED void SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_13(void)
{
	BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Fls module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*      Fls_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fls_Write function.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_11
* \archrequirement
*       ARCH_SW_SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_11
**/
EXPORTED void SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_11 (void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Fls module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Fls_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fls_Write function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_11
* \archrequirement
*        ARCH_SW_SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_11
**/
EXPORTED void SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_11(void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Fls module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Fls_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fls_Read function.
* \constrains
*       None.
* \ddesignrequirement
*      DSG_SchM_SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_12
* \archrequirement
*       ARCH_SW_SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_12
**/
EXPORTED void SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_12(void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Fls module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Fls_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fls_Read function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_12
* \archrequirement
*       ARCH_SW_SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_12
**/
EXPORTED void SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_12 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Fls module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Fls_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fls_Erase function.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10
* \archrequirement
*       ARCH_SW_SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10
**/
EXPORTED void SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10(void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Fls module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*        Fls_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fls_Erase function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10
* \archrequirement
*       ARCH_SW_SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10
**/
EXPORTED void SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Fls module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Fls_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fls_Flash_SectorErase function.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00
* \archrequirement
*       ARCH_SW_SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00
**/
EXPORTED void SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00(void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Fls module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Fls_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fls_Flash_SectorErase function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00
* \archrequirement
*       ARCH_SW_SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00
**/
EXPORTED void SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Fee module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Fee_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fee_Read function.
* \constrains
*       None.
* \ddesignrequirement
*      DSG_SchM_SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_00
* \archrequirement
*      ARCH_SW_SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_00
**/
EXPORTED void SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_00(void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Fee module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Fee_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fee_Read function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_00
* \archrequirement
*      ARCH_SW_SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_00
**/
EXPORTED void SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_00 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_Write function.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_02
* \archrequirement
*       ARCH_SW_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_02
**/
EXPORTED void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_02 (void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_Write function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02
* \archrequirement
*       ARCH_SW_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02
**/
EXPORTED void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02(void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_SetControllerToStartMode function.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_13
* \archrequirement
*       ARCH_SW_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_13
**/
EXPORTED void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_13(void)
{
   BoardDisableInterrupts();
}
/**
* \brief
*       This function is used to enable interrupts when an event ends (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_SetControllerToStartMode function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_13
* \archrequirement
*       ARCH_SW_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_13
**/
EXPORTED void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_13 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*      Called in Can_FlexCan_EnableInterrupts function.
* \constrains
*       None.
* \ddesignrequirement
*      DSG_SchM_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_08
* \archrequirement
*      ARCH_SW_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_08
**/
EXPORTED void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_08(void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_EnableInterrupts function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_08
* \archrequirement
*       ARCH_SW_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_08
**/
EXPORTED void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_08 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_ResetController function.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05
* \archrequirement
*       ARCH_SW_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05
**/
EXPORTED void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05(void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_ResetController function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05
* \archrequirement
*       ARCH_SW_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05
**/
EXPORTED void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_ResetController function.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_04
* \archrequirement
*       ARCH_SW_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_04
**/
EXPORTED void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_04(void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*        Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_ResetController function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_04
* \archrequirement
*       ARCH_SW_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_04
**/
EXPORTED void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_04 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_SellectClockSource function.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_09
* \archrequirement
*       ARCH_SW_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_09
**/
EXPORTED void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_09(void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_SellectClockSource function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_09
* \archrequirement
*       ARCH_SW_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_09
**/
EXPORTED void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_09 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_GotoFreezeMode function.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_03
* \archrequirement
*       ARCH_SW_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_03
**/
EXPORTED void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_03(void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_GotoFreezeMode function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_03
* \archrequirement
*       ARCH_SW_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_03
**/
EXPORTED void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_03 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_SetControllerToStopMode function.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_06
* \archrequirement
*       ARCH_SW_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_06
**/
EXPORTED void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_06(void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_SetControllerToStopMode function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_06
* \archrequirement
*       ARCH_SW_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_06
**/
EXPORTED void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_06 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*      Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_DisableInterrupts function.
* \constrains
*       None.
* \ddesignrequirement
*      DSG_SchM_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_07
* \archrequirement
*       ARCH_SW_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_07
**/
EXPORTED void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_07(void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Can module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Can_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Can_FlexCan_DisableInterrupts function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_07
* \archrequirement
*       ARCH_SW_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_07
**/
EXPORTED void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_07 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to disable interrupts when an event occurs (Fee module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*      Fee_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fee_Write function.
* \constrains
*       None.
* \ddesignrequirement
*       DSG_SchM_SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_01
* \archrequirement
*       ARCH_SW_SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_01
**/
EXPORTED void SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_01(void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Fee module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Fee_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Fee_Write function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_01
* \archrequirement
*       ARCH_SW_SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_01
**/
EXPORTED void SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_01 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Spi module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Spi_SyncTransmit function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_01
* \archrequirement
*      ARCH_SW_SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_01
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_01 (void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Spi module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Spi_SyncTransmit function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01
* \archrequirement
*      ARCH_SW_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Spi module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Spi_SyncTransmit function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_02
* \archrequirement
*      ARCH_SW_SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_02
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_02 (void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Fee module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Spi_SyncTransmit function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02
* \archrequirement
*      ARCH_SW_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Spi module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Spi_ScheduleJob function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_03
* \archrequirement
*      ARCH_SW_SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_03
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_03 (void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Spi module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Spi_ScheduleJob function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_03
* \archrequirement
*      ARCH_SW_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_03
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_03 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Spi module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Spi_ScheduleNextJob function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_04
* \archrequirement
*      ARCH_SW_SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_04
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_04 (void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Spi module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*      Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Spi_ScheduleNextJob function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_04
* \archrequirement
*      ARCH_SW_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_04
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_04 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Spi module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Spi_LockJobs function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00
* \archrequirement
*     ARCH_SW_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_04
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_05 (void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Spi module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Spi_LockJobs function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_05
* \archrequirement
*      ARCH_SW_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_05
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_05 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Spi module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Spi_UnlockRemainingJobs function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_06
* \archrequirement
*      ARCH_SW_SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_06
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_06 (void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Spi module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*        Called in Spi_UnlockRemainingJobs function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_06
* \archrequirement
*     ARCH_SW_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_06
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_06 (void)
{
   BoardEnableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Spi module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Spi_JobTransferFinished function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_07
* \archrequirement
*      ARCH_SW_SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_07
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_07 (void)
{
   BoardDisableInterrupts();
}

/**
* \brief
*       This function is used to enable interrupts when an event ends (Spi module).
* \pre
*       None.
* \return
*       None.
* \dynamicaspectcaller
*       Spi_TS_T40D2M10I2R0 module.
* \dynamicaspectdescription
*       Called in Spi_JobTransferFinished function.
* \constrains
*       None.
* \ddesignrequirement
*    DSG_SchM_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_07
* \archrequirement
*      ARCH_SW_SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_07
**/
EXPORTED FUNC(void, SCHM_CODE) SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_07 (void)
{
   BoardEnableInterrupts();
}
#define SCHM_STOP_SEC_CODE
#include "MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/

