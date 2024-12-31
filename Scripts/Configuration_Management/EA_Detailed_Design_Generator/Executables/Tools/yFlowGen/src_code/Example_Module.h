/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the information (interfaces, definitions and data) provided
by the component FIRST_EXAMPLE_MODULE_H_, part of the package FIRST_EXAMPLE_MODULE.
These are globally visible.
This file is intended to be included in a package header file;
all components should include the package header file instead of this file.

Current revision: $Revision: 1.1 $
Checked in:       $Date: 2023/05/26 09:55:26CEST $

*************************************************************************/

#ifndef EXAMPLE_MODULE_H_
#define EXAMPLE_MODULE_H_

#include "Std_Types.h"

/*************************************************************************
Declaration of macros
*************************************************************************/

/*************************************************************************
EXPORTED variables declaration
*************************************************************************/
extern uint8 u8VariableExample;

/*************************************************************************
Declaration of constants
*************************************************************************/
/**
 * \brief
 *		Defined macro from H file
 */
#define DATATYPE_MACRO_DEFINED_FROM_H_FILE          ((uint8)  0x01)

/*************************************************************************
Declaration of functions
*************************************************************************/
LOCAL void Example_Module_another_service_c_template (uint8 another_variable_example);

/*************************************************************************
EXPORTED functions declaration
*************************************************************************/
extern void Example_Module_service_c_template (uint8 variable1, uint16 variable2, uint8 * ouput_param )


#endif /* FIRST_EXAMPLE_MODULE_H_ */

/*************************************************************************
