/**
 * \file
 *
 * \brief AUTOSAR MemMap
 *
 * This file contains the implementation of the AUTOSAR
 * module MemMap.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

#define MEMMAP_ERROR_CAN

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Can */

#if (defined CAN_START_SEC_CODE)
  #pragma default_function_attributes=@".mcal_text"
  #undef CAN_START_SEC_CODE
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef CAN_STOP_SEC_CODE
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const"
  #undef CAN_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef CAN_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_data"
  #undef CAN_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_bss"
  #undef CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CAN

#endif

#if ((!defined MEMMAP_ERROR_CAN) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_CAN) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_CAN
  #error MEMMAP_ERROR_CAN the included memory section was not defined within the BSW-IMPLEMENTATION of Can.
#endif
