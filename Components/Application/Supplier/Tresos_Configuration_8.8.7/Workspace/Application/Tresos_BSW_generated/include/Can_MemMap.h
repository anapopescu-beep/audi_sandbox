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

#define MEMMAP_ERROR_CAN

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Can */

#if (defined CAN_START_SEC_CODE)
  #undef CAN_START_SEC_CODE
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_CODE)
  #undef CAN_STOP_SEC_CODE
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_CONFIG_DATA_32)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef CAN_START_SEC_CONFIG_DATA_32
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_CONFIG_DATA_32)
  #pragma default_variable_attributes=
  #undef CAN_STOP_SEC_CONFIG_DATA_32
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_CONFIG_DATA_8)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef CAN_START_SEC_CONFIG_DATA_8
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_CONFIG_DATA_8)
  #pragma default_variable_attributes=
  #undef CAN_STOP_SEC_CONFIG_DATA_8
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

#elif (defined CAN_START_SEC_VAR_CLEARED_16)
  #undef CAN_START_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_VAR_CLEARED_16)
  #undef CAN_STOP_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_VAR_CLEARED_16_NO_CACHEABLE)
  #undef CAN_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE)
  #undef CAN_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_VAR_CLEARED_32)
  #undef CAN_START_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_VAR_CLEARED_32)
  #undef CAN_STOP_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_VAR_CLEARED_32_NO_CACHEABLE)
  #undef CAN_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE)
  #undef CAN_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_VAR_CLEARED_8)
  #undef CAN_START_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_VAR_CLEARED_8)
  #undef CAN_STOP_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_VAR_CLEARED_8_NO_CACHEABLE)
  #undef CAN_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE)
  #undef CAN_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef CAN_START_SEC_VAR_CLEARED_BOOLEAN
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef CAN_STOP_SEC_VAR_CLEARED_BOOLEAN
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE)
  #undef CAN_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE)
  #undef CAN_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef CAN_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_CAN

#elif (defined CAN_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE)
  #undef CAN_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
  #undef MEMMAP_ERROR_CAN
#elif (defined CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE)
  #undef CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
  #undef MEMMAP_ERROR_CAN

#endif

#if ((!defined MEMMAP_ERROR_CAN) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_CAN) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_CAN
  #error MEMMAP_ERROR_CAN the included memory section was not defined within the BSW-IMPLEMENTATION of Can.
#endif
