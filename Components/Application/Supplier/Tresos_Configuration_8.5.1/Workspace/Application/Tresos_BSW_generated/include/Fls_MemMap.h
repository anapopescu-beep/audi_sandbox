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

#define MEMMAP_ERROR_FLS

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Fls */

#if (defined FLS_START_SEC_CODE)
  #pragma default_function_attributes=@".mcal_text"
  #undef FLS_START_SEC_CODE
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef FLS_STOP_SEC_CODE
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_CODE_AC)
  #pragma default_function_attributes=@".fls_ram_code_text"
  #undef FLS_START_SEC_CODE_AC
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_CODE_AC)
  #pragma default_function_attributes=
  #undef FLS_STOP_SEC_CODE_AC
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_CONFIG_DATA_8)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef FLS_START_SEC_CONFIG_DATA_8
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_CONFIG_DATA_8)
  #pragma default_variable_attributes=
  #undef FLS_STOP_SEC_CONFIG_DATA_8
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".mcal_const"
  #undef FLS_START_SEC_CONST_32
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef FLS_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const"
  #undef FLS_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef FLS_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_RAMCODE)
  #pragma default_function_attributes=@".fls_ram_code_text"
  #undef FLS_START_SEC_RAMCODE
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_RAMCODE)
  #pragma default_function_attributes=
  #undef FLS_STOP_SEC_RAMCODE
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_INIT_32)
  #pragma default_variable_attributes=@".mcal_data"
  #undef FLS_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_INIT_32)
  #pragma default_variable_attributes=
  #undef FLS_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_INIT_8)
  #pragma default_variable_attributes=@".mcal_data"
  #undef FLS_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_INIT_8)
  #pragma default_variable_attributes=
  #undef FLS_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_INIT_BOOLEAN)
  #pragma default_variable_attributes=@".mcal_data"
  #undef FLS_START_SEC_VAR_INIT_BOOLEAN
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_INIT_BOOLEAN)
  #pragma default_variable_attributes=
  #undef FLS_STOP_SEC_VAR_INIT_BOOLEAN
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_data"
  #undef FLS_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=@".data"
  #undef FLS_START_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=
  #undef FLS_STOP_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".data"
  #undef FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS

#endif

#if ((!defined MEMMAP_ERROR_FLS) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_FLS) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_FLS
  #error MEMMAP_ERROR_FLS the included memory section was not defined within the BSW-IMPLEMENTATION of Fls.
#endif
