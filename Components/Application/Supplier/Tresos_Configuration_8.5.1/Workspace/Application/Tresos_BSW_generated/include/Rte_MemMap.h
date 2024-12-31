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

#define MEMMAP_ERROR_RTE

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Rte */

#if (defined RTE_START_SEC_APPL_CODE)
  #pragma default_function_attributes=@".text"
  #undef RTE_START_SEC_APPL_CODE
  #undef MEMMAP_ERROR_RTE
#elif (defined RTE_STOP_SEC_APPL_CODE)
  #pragma default_function_attributes=
  #undef RTE_STOP_SEC_APPL_CODE
  #undef MEMMAP_ERROR_RTE

#elif (defined RTE_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef RTE_START_SEC_CODE
  #undef MEMMAP_ERROR_RTE
#elif (defined RTE_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef RTE_STOP_SEC_CODE
  #undef MEMMAP_ERROR_RTE

#elif (defined RTE_START_SEC_CONST_16)
  #pragma default_variable_attributes=@".rodata"
  #undef RTE_START_SEC_CONST_16
  #undef MEMMAP_ERROR_RTE
#elif (defined RTE_STOP_SEC_CONST_16)
  #pragma default_variable_attributes=
  #undef RTE_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_RTE

#elif (defined RTE_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".rodata"
  #undef RTE_START_SEC_CONST_32
  #undef MEMMAP_ERROR_RTE
#elif (defined RTE_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef RTE_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_RTE

#elif (defined RTE_START_SEC_CONST_8)
  #pragma default_variable_attributes=@".rodata"
  #undef RTE_START_SEC_CONST_8
  #undef MEMMAP_ERROR_RTE
#elif (defined RTE_STOP_SEC_CONST_8)
  #pragma default_variable_attributes=
  #undef RTE_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_RTE

#elif (defined RTE_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef RTE_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_RTE
#elif (defined RTE_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef RTE_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_RTE

#elif (defined RTE_START_SEC_VAR_16)
  #pragma default_variable_attributes=@".bss"
  #undef RTE_START_SEC_VAR_16
  #undef MEMMAP_ERROR_RTE
#elif (defined RTE_STOP_SEC_VAR_16)
  #pragma default_variable_attributes=
  #undef RTE_STOP_SEC_VAR_16
  #undef MEMMAP_ERROR_RTE

#elif (defined RTE_START_SEC_VAR_32)
  #pragma default_variable_attributes=@".bss"
  #undef RTE_START_SEC_VAR_32
  #undef MEMMAP_ERROR_RTE
#elif (defined RTE_STOP_SEC_VAR_32)
  #pragma default_variable_attributes=
  #undef RTE_STOP_SEC_VAR_32
  #undef MEMMAP_ERROR_RTE

#elif (defined RTE_START_SEC_VAR_8)
  #pragma default_variable_attributes=@".data"
  #undef RTE_START_SEC_VAR_8
  #undef MEMMAP_ERROR_RTE
#elif (defined RTE_STOP_SEC_VAR_8)
  #pragma default_variable_attributes=
  #undef RTE_STOP_SEC_VAR_8
  #undef MEMMAP_ERROR_RTE

#elif (defined RTE_START_SEC_VAR_INIT_32)
  #pragma default_variable_attributes=@".bss"
  #undef RTE_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_RTE
#elif (defined RTE_STOP_SEC_VAR_INIT_32)
  #pragma default_variable_attributes=
  #undef RTE_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_RTE

#elif (defined RTE_START_SEC_VAR_UNSPECIFIED)
  #pragma default_variable_attributes=@".bss"
  #undef RTE_START_SEC_VAR_UNSPECIFIED
  #undef MEMMAP_ERROR_RTE
#elif (defined RTE_STOP_SEC_VAR_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef RTE_STOP_SEC_VAR_UNSPECIFIED
  #undef MEMMAP_ERROR_RTE

#endif

#if ((!defined MEMMAP_ERROR_RTE) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_RTE) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_RTE
  #error MEMMAP_ERROR_RTE the included memory section was not defined within the BSW-IMPLEMENTATION of Rte.
#endif
