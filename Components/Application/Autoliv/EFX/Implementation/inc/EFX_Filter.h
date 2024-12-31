#ifndef EFX_FILTER_H_
#define EFX_FILTER_H_ 1

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
   by the module EFX, part of the component EFX.

******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.4 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/EFX/Implementation/inc/project.pj $
*/
/* PRQA S 0288 -- */
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_Types.h"
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *    This macro is used to define macro implementation functionality of this module. 
 */
#define KU32_EFX_MACRO_IMPLEMENTATION                  (0u)

/**
 * \brief
 *    This macro is used to define function implementation functionality of this module.
 */
#define KU32_EFX_FUNCTION_IMPLEMENTATION               (1u)

/**
 * \brief
 *       This macro is used to select between function or macro implementation.
 */
#define KU32_EFX_IMPLMEMENTATION                      (KU32_EFX_MACRO_IMPLEMENTATION)

/**
 * \brief
 *       This macro is used to define amplification factor value of LPF filter.
 */
#define KU16_EFX_LPF_K_COEFF                           ((uint16) 5u)
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

/**
 * \brief
 *       This macro is used to check selected implementation.
 */
#if (KU32_EFX_IMPLMEMENTATION == KU32_EFX_FUNCTION_IMPLEMENTATION)

extern uint16 EFX_LPF_Filter_u16_u16(uint16 u16LastSample, uint16 u16CurrentSample);
extern boolean Efx_HystCenterHalfDelta_u16_u16(uint16 X, uint16 center, uint16 halfDelta, boolean* State);

#else

/**
 * \brief
 *       This macro is used to implement a first order Low Pass Filter.
 */
#define EFX_LPF_Filter_u16_u16(LastSample, CurrentSample)       \
      (uint16)                                                  \
      (                                                         \
         (                                                      \
            (CurrentSample)                                     \
            +                                                   \
            (                                                   \
               (KU16_EFX_LPF_K_COEFF) * (LastSample)            \
            )                                                   \
         )                                                      \
         /                                                      \
         (                                                      \
            (KU16_EFX_LPF_K_COEFF) + (KU16_ONE)                 \
         )                                                      \
      )     

 /**
 * \brief
 *       This macro is used to implement a Center Half Delta Hysteresis 
 */                                                         
#define Efx_HystCenterHalfDelta_u16_u8(X, center, halfDelta, State) \
      ((X) > ((center) + (halfDelta)))?TRUE:(( (X) < ((center) - (halfDelta)))?FALSE:*(State)) 

#endif
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* EFX_FILTER_H_ */






























