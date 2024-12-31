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
#ifndef _MIC_PUBLIC_H_
#define _MIC_PUBLIC_H_ 1

#include "Std_Types.h"
#include "Fls_Api.h"
/*************************************************************************
DEFINITION OF CONSTANTS
*************************************************************************/

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
#define MIC_START_SEC_CODE_ASIL_A
#include "MIC_MemMap.h"

extern void MIC_Init                            (void);
extern void MIC_HardFaultException              (void);
extern void MIC_BusFaultException               (void);
extern void MIC_HardFaultHandlerHll(Fls_InstructionAddressType * const instr_pt2pt);

#define MIC_STOP_SEC_CODE_ASIL_A
#include "MIC_MemMap.h"
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
#endif /* _MIC_PUBLIC_H_ */

/*************************************************************************
Evolution of the component

Created by : C. Sauvage

$Log: MIC_Public.h  $
Revision 1.1.6.7 2023/03/17 13:05:43CET Razvan Badiu (razvan.badiu) 
fixes after review
Revision 1.1.6.6 2023/02/28 17:34:36EET Septimiu Vintila (septimiu.vintila) 
Memory sections changed to FuSa memory sections.
Revision 1.1.6.5 2022/11/22 15:27:39EET Andrei Anca (andrei.anca) 
Update after review
Revision 1.1 2014/09/30 11:14:31CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/_MIC/inc/project.pj


*****************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
