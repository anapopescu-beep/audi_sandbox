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

#define MEMMAP_ERROR_BSWM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for BswM */

#if (defined BSWM_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef BSWM_START_SEC_CODE
  #undef MEMMAP_ERROR_BSWM
#elif (defined BSWM_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef BSWM_STOP_SEC_CODE
  #undef MEMMAP_ERROR_BSWM

#elif (defined BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_BSWM
#elif (defined BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_BSWM

#elif (defined BSWM_START_SEC_CONST_16)
  #pragma default_variable_attributes=@".rodata"
  #undef BSWM_START_SEC_CONST_16
  #undef MEMMAP_ERROR_BSWM
#elif (defined BSWM_STOP_SEC_CONST_16)
  #pragma default_variable_attributes=
  #undef BSWM_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_BSWM

#elif (defined BSWM_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".rodata"
  #undef BSWM_START_SEC_CONST_32
  #undef MEMMAP_ERROR_BSWM
#elif (defined BSWM_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef BSWM_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_BSWM

#elif (defined BSWM_START_SEC_CONST_8)
  #pragma default_variable_attributes=@".rodata"
  #undef BSWM_START_SEC_CONST_8
  #undef MEMMAP_ERROR_BSWM
#elif (defined BSWM_STOP_SEC_CONST_8)
  #pragma default_variable_attributes=
  #undef BSWM_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_BSWM

#elif (defined BSWM_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef BSWM_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_BSWM
#elif (defined BSWM_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef BSWM_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_BSWM

#elif (defined BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_BSWM
#elif (defined BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_BSWM

#elif (defined BSWM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef BSWM_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_BSWM
#elif (defined BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_BSWM

#endif

#if ((!defined MEMMAP_ERROR_BSWM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_BSWM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_BSWM
  #error MEMMAP_ERROR_BSWM the included memory section was not defined within the BSW-IMPLEMENTATION of BswM.
#endif
