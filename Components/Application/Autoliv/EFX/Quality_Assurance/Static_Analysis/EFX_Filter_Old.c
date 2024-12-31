/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version:
Template version: AEM_PROCESS_1.22.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-04
******************************************************************************/
/*!****************************************************************************

@details
   File containing the EFX component definition.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "EFX_Filter.h"

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

/**
 * \brief
 *       This macro is used to check selected implementation. 
 */
#if (EFX_IMPLMEMENTATION == EFX_FUNCTION_IMPLEMENTATION)

/**
 * \brief
 *       This function is used to implement a first order Low Pass Filter. 
 * \param
 *       uint16 u16LastSample Value of last sample. This value will be updated
 *		 with u16CurrentSample value;
 * \param
 *       uint16 u16CurrentSample Value of the current sample;
 * \return
 *       uint16 Value of computed LPF value. 
 * \remark
 *       Formula : Y[n] = b * Y[n-1] + (1-b)X[n], with X = sample and Y = filtered value 
 *       b = k/(k+1) 
 *       After some simplification :
 *       Y[n] = (X[n] + k * Y[n-1]) / (k + 1) 
 * \dynamiaspectcaller
 *       AdcIf SW Component.
 * \dynamicaspectdescription
 *       Called for filtering solenoid current values.
 */
uint16 EFX_LPF_Filter_u16_u16(uint16 u16LastSample, uint16 u16CurrentSample)
{
   return       (uint16)                                                  \
                (                                                         \
                   (                                                      \
                      u16CurrentSample                                    \
                      +                                                   \
                      (                                                   \
                         KU16_EFX_LPF_K_COEFF * u16LastSample             \
                      )                                                   \
                   )                                                      \
                   /                                                      \
                   (                                                      \
                      KU16_EFX_LPF_K_COEFF + KU16_ONE                     \
                   )                                                      \
                );
}

#endif
/******************************************************************************
End Of File
*****************************************************************************/
