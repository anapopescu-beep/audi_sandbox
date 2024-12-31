/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

COMPONENT First_Example_Module

Current revision: $Revision: 1.1 $
Checked in:       $Date: 2023/05/25 13:37:36CEST $

**************************************************************************

Overview of the component :
This component shall provide an example of how to insert comment block
in source code. 

------------------------------------------------------------------------

Design document:


*************************************************************************/

/*************************************************************************
Packages inclusion 
*************************************************************************/

/*************************************************************************
Intra-package inclusions 
*************************************************************************/

/*************************************************************************
Private inclusion 
*************************************************************************/

/*************************************************************************
Declaration of constants
*************************************************************************/

/*************************************************************************
Declaration of macros
*************************************************************************/
/**
 * \brief
 *		Defined macro from C file 
 */
 
#define DATATYPE_MACRO_DEFINED_FROM_C_FILE                  ((uint8)  0x10)

/**
 * \brief
 *		Defined macro from C file that will appear in GROUP. 
 */

#define DATATYPE_ANOTHER_MACRO_DEFINED_FROM_C_FILE          ((uint8)  0x01)
/*************************************************************************
Declaration of types
*************************************************************************/

/*************************************************************************
LOCAL variables declaration
*************************************************************************/
/**
 * \brief
 *      This variable is used to give an example descripton of a variable.
 * \initialization 
 *      Initialisation description or value.
 * \range
 *      0..255 or anything.
 */
uint8 u8VariableExample = ZERO;

/**
 * \brief
 *      This variable is used to give an example descripton of a variable.
 *		A local variable description example that will also appear in variable description.
 * \initialization 
 *      Initialisation description or value.
 * \range
 *      A range example.
 */
LOCAL uint8 u8AnotherVariableExample;


/**
 * \brief
 *      This variable is used to give an example descripton of a variable.
 *		A local variable description example that will also appear in variable description.
 * \initialization 
 *      Initialisation description or value.
 * \range
 *      A range example description or value.
 */
LOCAL uint8 u8AnotherVariableExample2;

/**
 * \brief
 *      This variable is used to give an example descripton of a variable.
 *		A local variable description example that will also appear in variable description.
 * \initialization 
 *      Initialisation description or value.
 * \range
 *      A range example description or value.
 */
LOCAL uint8 u8AnotherVariableExample3;
/*************************************************************************
LOCAL constant data declaration
**************************************************************************/

/*************************************************************************
EXPORTED variables declaration
 *************************************************************************/
 
/**************************************************************************
Local Functions
**************************************************************************/
/**
* \brief
*       An example of description for local function. Belongs to First_Example_Module.
*       Here is a list:
*           o element1;
*           o element2;
*           o element3;
* \inputparam
*       Name: variable1;
*       Type: uint8;
*       Description: This is a description for variable1;
*       Range: 0..255;
* \inputparam
*       Name: variable2;
*       Type: uint16;
*       Description: This is a description for variable 2;
*       Range: 0, 1, 2;
* \outputparam
*       Name: ouput_param;
*       Type: uint8 *;
*       Description: This is an ouput parameter.;
*       Range: OK, NOK, other_values;
* \exception
*       This function has the following exceptions
* \pre
*       This function has the following preconditions
* \post
*       This function has the following postconditions
* \return
*       This function has no return.
* \staticaspect
*       Write here the static aspect of the function.
* \dynamicaspectcaller
*       Write here who calls this function.
* \dynamicaspectdescription
*       Write here a description caller of this function.
* \constrains
*       Write here if you have any constraints.
* \ddesignrequirement
*       DSG_Example_Module_service_c_template
* \archrequirement
*       ARCH_TEST_REQ
**/
EXPORTED void Example_Module_service_c_template(uint8 variable1, uint16 variable2, uint8 *ouput_param)
{
   /* Function code here */

   /* Assign to parameter_1 upper defined value */
   Variable = value_from_defined_macro;

   /* Check values of parameter_1 */
   if (variable_condition)
   {
      /* Increment it */
      increment_variable;
   }
   else
   {
      /* Decrement it */
      decrement_variable;
   }
}

/**
 * \brief
 *       An example of description for local function. Belongs to First_Example_Module.
 * \inputparam
 *       Name: another_variable_example;
 *       Type: uint8;
 *       Description: This is a description for another_variable_example;
 *       Range: 0..255;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       another_variable_example Example of return variable description.
 * \dynamicaspectcaller
 *       Write here who calls this function.
 * \dynamicaspectdescription
 *       Write here a description caller of this function.
 * \staticaspect
 *       Write here the static aspect of the function.
 * \constrains
 *       Write here if you have any constraints.
 * \ddesignrequirement
 *		DSG_Example_Module_another_service_c_template
 * \archrequirement
 *       ARCH_TEST_REQ
 **/
LOCAL void Example_Module_another_service_c_template(uint8 another_variable_example)
{
   /* Function code here */

   /* Assign to parameter_1 upper defined value */
   another_variable_example = a_defined_macro_or_value;

   /* A IF-ELSE statement example */
   if (another_variable_example_condition)
   {
      /* Increment it */
      another_variable_example++;
   }
   else
   {
      /* Decrement it */
      another_variable_example--;
   }

   /* Assign value to another variable */
   variable_inside_function = value;

   /* a for iteration example */
   for (initializationStatement; testExpression; updateStatement)
   {

      /* statements inside the body of loop */
      variable_inside_function++;
   }

   /* A switch case example */
   switch (variable_inside_function)
   {
   case one_value:

      /* first case */
      do_something_1;

   case another_value:

      /* second case */
      do_something_2;

   default:

      /* default condition */
      do_something_3;
   }

   return another_variable_example
}

/**************************************************************************
End of file
**************************************************************************/
