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

This file provides external services prototypes from MIC component

******************************************************************************/
/*
$Revision: 1.1.6.7 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/MIC/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#ifndef _MIC_PRIVATE_H_
#define _MIC_PRIVATE_H_ 1

#include "Std_Types.h"
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/

/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
/*! \union MIC_stSnapshotRegister MIC_Private.h
 *  \brief
 *     This structure contains the snapshot register - fault address .
 */
typedef struct
{
/**
 * \brief
 *     Data containing the value of MMCEC register.
 */
   uint32      u32FaultAddress;
/**
 * \brief
 *     Bit complement of the previous data element for integrity check
 */
   uint32      u32FaultAddress_XOR;
}MIC_stSnapshotRegister;

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/
/**
 * \brief
 *      Variable declaration for MIC component usage
 *      These data will be written under interrupt context and read at each
 *      SW application initialization at the end of the init function
 *      the content of the data will be cleared
 */
extern MIC_stSnapshotRegister MIC_stBusFaultRegister;

/**
 * \brief
 *      Variable declaration for FLS ECC Error detection
 */
extern boolean MIC_bECCErrFls;

/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _PFlash_Start;
/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _PFlash_End;
/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _EEP_Def_Start;
/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _EEP_Def_End;
/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _Calib_Start;
/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _Calib_End;
/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _Ram_Start;
/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _Ram_End;
/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _NoInitRam_Start;
/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _NoInitRam_End;
/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _FlexRam_Start;
/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _FlexRam_End;
/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _Stack_start;
/**
 * \brief
 *      Address automatically computed during link operation
 *      Symbol definition done in the linker file
 */
extern uint8 * _Stack_end;

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
extern void OS_ExceptionBusFaultHandler(void);
#endif /* _MIC_PRIVATE_H_ */
/*************************************************************************
Evolution of the component

Created by : C. Sauvage

$Log: MIC_Private.h  $
Revision 1.1.6.7 2023/03/17 13:05:43CET Razvan Badiu (razvan.badiu) 
fixes after review
Revision 1.1.6.6 2023/02/22 21:53:00EET Razvan Badiu (razvan.badiu) 
Mic interface
Revision 1.1.6.5 2022/11/22 15:27:39EET Andrei Anca (andrei.anca) 
Update after review
Revision 1.1 2014/10/01 14:36:54CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/_MIC/inc/project.pj

*****************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
