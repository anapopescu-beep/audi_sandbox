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

#define MEMMAP_ERROR_GPT

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Gpt */

#if (defined GPT_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef GPT_START_SEC_CODE
  #undef MEMMAP_ERROR_GPT
#elif (defined GPT_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef GPT_STOP_SEC_CODE
  #undef MEMMAP_ERROR_GPT

#elif (defined GPT_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_GPT
#elif (defined GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_GPT

#elif (defined GPT_START_SEC_VAR_INIT_32)
  #pragma default_variable_attributes=@".data"
  #undef GPT_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_GPT
#elif (defined GPT_STOP_SEC_VAR_INIT_32)
  #pragma default_variable_attributes=
  #undef GPT_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_GPT

#elif (defined GPT_START_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".data"
  #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_GPT
#elif (defined GPT_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_GPT

#elif (defined GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".data"
  #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_GPT
#elif (defined GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_GPT

#endif

#if ((!defined MEMMAP_ERROR_GPT) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_GPT) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_GPT
  #error MEMMAP_ERROR_GPT the included memory section was not defined within the BSW-IMPLEMENTATION of Gpt.
#endif
