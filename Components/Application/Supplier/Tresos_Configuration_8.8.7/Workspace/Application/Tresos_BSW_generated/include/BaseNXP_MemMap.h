/**
 * \file
 *
 * \brief AUTOSAR MemMap
 *
 * This file contains the implementation of the AUTOSAR
 * module MemMap.
 *
 * \version 1.3.13
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

#define MEMMAP_ERROR_BASENXP

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for BaseNXP */

#if (defined BASENXP_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef BASENXP_START_SEC_CODE
  #undef MEMMAP_ERROR_BASENXP
#elif (defined BASENXP_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef BASENXP_STOP_SEC_CODE
  #undef MEMMAP_ERROR_BASENXP

#elif (defined BASENXP_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef BASENXP_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_BASENXP
#elif (defined BASENXP_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef BASENXP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_BASENXP

#elif (defined BASENXP_START_SEC_VAR_CLEARED_32)
  #undef BASENXP_START_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_BASENXP
#elif (defined BASENXP_STOP_SEC_VAR_CLEARED_32)
  #undef BASENXP_STOP_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_BASENXP

#elif (defined BASENXP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef BASENXP_START_SEC_VAR_CLEARED_BOOLEAN
  #undef MEMMAP_ERROR_BASENXP
#elif (defined BASENXP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef BASENXP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #undef MEMMAP_ERROR_BASENXP

#elif (defined BASENXP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef BASENXP_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_BASENXP
#elif (defined BASENXP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef BASENXP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_BASENXP

#elif (defined MCU_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef MCU_START_SEC_CODE
  #undef MEMMAP_ERROR_BASENXP
#elif (defined MCU_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef MCU_STOP_SEC_CODE
  #undef MEMMAP_ERROR_BASENXP

#elif (defined MCU_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_BASENXP
#elif (defined MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_BASENXP

#endif

#if ((!defined MEMMAP_ERROR_BASENXP) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_BASENXP) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_BASENXP
  #error MEMMAP_ERROR_BASENXP the included memory section was not defined within the BSW-IMPLEMENTATION of BaseNXP.
#endif
