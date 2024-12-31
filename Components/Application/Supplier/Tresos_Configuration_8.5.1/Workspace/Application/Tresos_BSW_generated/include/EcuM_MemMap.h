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

#define MEMMAP_ERROR_ECUM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for EcuM */

#if (defined ECUM_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef ECUM_START_SEC_CODE
  #undef MEMMAP_ERROR_ECUM
#elif (defined ECUM_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef ECUM_STOP_SEC_CODE
  #undef MEMMAP_ERROR_ECUM

#elif (defined ECUM_START_SEC_CONST_16)
  #pragma default_variable_attributes=@".rodata"
  #undef ECUM_START_SEC_CONST_16
  #undef MEMMAP_ERROR_ECUM
#elif (defined ECUM_STOP_SEC_CONST_16)
  #pragma default_variable_attributes=
  #undef ECUM_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_ECUM

#elif (defined ECUM_START_SEC_CONST_8)
  #pragma default_variable_attributes=@".rodata"
  #undef ECUM_START_SEC_CONST_8
  #undef MEMMAP_ERROR_ECUM
#elif (defined ECUM_STOP_SEC_CONST_8)
  #pragma default_variable_attributes=
  #undef ECUM_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_ECUM

#elif (defined ECUM_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef ECUM_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUM
#elif (defined ECUM_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef ECUM_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUM

#elif (defined ECUM_START_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".data"
  #undef ECUM_START_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUM
#elif (defined ECUM_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef ECUM_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUM

#elif (defined ECUM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef ECUM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUM
#elif (defined ECUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef ECUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUM

#elif (defined ECUM_START_SEC_VAR_INIT_8)
  #pragma default_variable_attributes=@".data"
  #undef ECUM_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_ECUM
#elif (defined ECUM_STOP_SEC_VAR_INIT_8)
  #pragma default_variable_attributes=
  #undef ECUM_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_ECUM

#elif (defined ECUM_START_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".data"
  #undef ECUM_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUM
#elif (defined ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUM

#elif (defined ECUM_START_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=@".bss"
  #undef ECUM_START_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_ECUM
#elif (defined ECUM_STOP_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=
  #undef ECUM_STOP_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_ECUM

#elif (defined ECUM_START_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=@".bss"
  #undef ECUM_START_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_ECUM
#elif (defined ECUM_STOP_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=
  #undef ECUM_STOP_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_ECUM

#elif (defined ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".bss"
  #undef ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUM
#elif (defined ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUM

#elif (defined ECUM_START_SEC_VAR_POWER_ON_INIT_8)
  #pragma default_variable_attributes=@".data"
  #undef ECUM_START_SEC_VAR_POWER_ON_INIT_8
  #undef MEMMAP_ERROR_ECUM
#elif (defined ECUM_STOP_SEC_VAR_POWER_ON_INIT_8)
  #pragma default_variable_attributes=
  #undef ECUM_STOP_SEC_VAR_POWER_ON_INIT_8
  #undef MEMMAP_ERROR_ECUM

#endif

#if ((!defined MEMMAP_ERROR_ECUM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_ECUM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_ECUM
  #error MEMMAP_ERROR_ECUM the included memory section was not defined within the BSW-IMPLEMENTATION of EcuM.
#endif
