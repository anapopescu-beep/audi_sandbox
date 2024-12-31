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

#define MEMMAP_ERROR_COM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Com */

#if (defined COM_START_SEC_CALLOUT_CODE)
  #pragma default_function_attributes=@".text"
  #undef COM_START_SEC_CALLOUT_CODE
  #undef MEMMAP_ERROR_COM
#elif (defined COM_STOP_SEC_CALLOUT_CODE)
  #pragma default_function_attributes=
  #undef COM_STOP_SEC_CALLOUT_CODE
  #undef MEMMAP_ERROR_COM

#elif (defined COM_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef COM_START_SEC_CODE
  #undef MEMMAP_ERROR_COM
#elif (defined COM_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef COM_STOP_SEC_CODE
  #undef MEMMAP_ERROR_COM

#elif (defined COM_START_SEC_CODE_CC_BLOCK)
  #undef COM_START_SEC_CODE_CC_BLOCK
  #undef MEMMAP_ERROR_COM
#elif (defined COM_STOP_SEC_CODE_CC_BLOCK)
  #undef COM_STOP_SEC_CODE_CC_BLOCK
  #undef MEMMAP_ERROR_COM

#elif (defined COM_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef COM_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_COM
#elif (defined COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_COM

#elif (defined COM_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".rodata"
  #undef COM_START_SEC_CONST_32
  #undef MEMMAP_ERROR_COM
#elif (defined COM_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef COM_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_COM

#elif (defined COM_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef COM_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_COM
#elif (defined COM_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef COM_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_COM

#elif (defined COM_START_SEC_VAR_CLEARED_16)
  #undef COM_START_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_COM
#elif (defined COM_STOP_SEC_VAR_CLEARED_16)
  #undef COM_STOP_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_COM

#elif (defined COM_START_SEC_VAR_CLEARED_32)
  #undef COM_START_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_COM
#elif (defined COM_STOP_SEC_VAR_CLEARED_32)
  #undef COM_STOP_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_COM

#elif (defined COM_START_SEC_VAR_CLEARED_8)
  #undef COM_START_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_COM
#elif (defined COM_STOP_SEC_VAR_CLEARED_8)
  #undef COM_STOP_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_COM

#elif (defined COM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef COM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_COM
#elif (defined COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_COM

#elif (defined COM_START_SEC_VAR_INIT_8)
  #undef COM_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_COM
#elif (defined COM_STOP_SEC_VAR_INIT_8)
  #undef COM_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_COM

#endif

#if ((!defined MEMMAP_ERROR_COM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_COM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_COM
  #error MEMMAP_ERROR_COM the included memory section was not defined within the BSW-IMPLEMENTATION of Com.
#endif
