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
    This file contains the implementation of the AUTOSAR module MemMap.

******************************************************************************/
/*
$Revision: 1.2 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/SchM/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
#define MEMMAP_ERROR_SCHM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for SchM */

#if (defined SCHM_START_SEC_VAR_UNSPECIFIED)
    #undef SCHM_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR_SCHM
#elif (defined SCHM_STOP_SEC_VAR_UNSPECIFIED)
    #undef SCHM_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR_SCHM

#elif (defined SCHM_START_SEC_CODE)
    #undef SCHM_START_SEC_CODE
    #undef MEMMAP_ERROR_SCHM
#elif (defined SCHM_STOP_SEC_CODE)
    #undef SCHM_STOP_SEC_CODE
    #undef MEMMAP_ERROR_SCHM

#endif

#if ((!defined MEMMAP_ERROR_SCHM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_SCHM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_SCHM
  #error MEMMAP_ERROR_SCHM the included memory section was not defined within the BSW-IMPLEMENTATION of SchM.
#endif
/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/
/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/
/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/
/******************************************************************************
End Of File
*****************************************************************************/
