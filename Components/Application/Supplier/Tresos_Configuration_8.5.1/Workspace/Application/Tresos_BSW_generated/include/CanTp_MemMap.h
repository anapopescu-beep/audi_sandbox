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

#define MEMMAP_ERROR_CANTP

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for CanTp */

#if (defined CANTP_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef CANTP_START_SEC_CODE
  #undef MEMMAP_ERROR_CANTP
#elif (defined CANTP_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef CANTP_STOP_SEC_CODE
  #undef MEMMAP_ERROR_CANTP

#elif (defined CANTP_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef CANTP_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_CANTP
#elif (defined CANTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef CANTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_CANTP

#elif (defined CANTP_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".rodata"
  #undef CANTP_START_SEC_CONST_32
  #undef MEMMAP_ERROR_CANTP
#elif (defined CANTP_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef CANTP_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_CANTP

#elif (defined CANTP_START_SEC_CONST_ENTRY_JUMP_TABLE)
  #pragma default_variable_attributes=@".rodata"
  #undef CANTP_START_SEC_CONST_ENTRY_JUMP_TABLE
  #undef MEMMAP_ERROR_CANTP
#elif (defined CANTP_STOP_SEC_CONST_ENTRY_JUMP_TABLE)
  #pragma default_variable_attributes=
  #undef CANTP_STOP_SEC_CONST_ENTRY_JUMP_TABLE
  #undef MEMMAP_ERROR_CANTP

#elif (defined CANTP_START_SEC_CONST_EXIT_JUMP_TABLE)
  #pragma default_variable_attributes=@".rodata"
  #undef CANTP_START_SEC_CONST_EXIT_JUMP_TABLE
  #undef MEMMAP_ERROR_CANTP
#elif (defined CANTP_STOP_SEC_CONST_EXIT_JUMP_TABLE)
  #pragma default_variable_attributes=
  #undef CANTP_STOP_SEC_CONST_EXIT_JUMP_TABLE
  #undef MEMMAP_ERROR_CANTP

#elif (defined CANTP_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef CANTP_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CANTP
#elif (defined CANTP_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef CANTP_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CANTP

#elif (defined CANTP_START_SEC_JUMP_TABLE_SHARED_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".data"
  #undef CANTP_START_SEC_JUMP_TABLE_SHARED_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CANTP
#elif (defined CANTP_STOP_SEC_JUMP_TABLE_SHARED_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef CANTP_STOP_SEC_JUMP_TABLE_SHARED_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CANTP

#elif (defined CANTP_START_SEC_VAR_CLEARED_16)
  #undef CANTP_START_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_CANTP
#elif (defined CANTP_STOP_SEC_VAR_CLEARED_16)
  #undef CANTP_STOP_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_CANTP

#elif (defined CANTP_START_SEC_VAR_CLEARED_8)
  #undef CANTP_START_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_CANTP
#elif (defined CANTP_STOP_SEC_VAR_CLEARED_8)
  #undef CANTP_STOP_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_CANTP

#elif (defined CANTP_START_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".data"
  #undef CANTP_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CANTP
#elif (defined CANTP_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef CANTP_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CANTP

#elif (defined CANTP_START_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=@".bss"
  #undef CANTP_START_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_CANTP
#elif (defined CANTP_STOP_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=
  #undef CANTP_STOP_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_CANTP

#elif (defined CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".bss"
  #undef CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CANTP
#elif (defined CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CANTP

#endif

#if ((!defined MEMMAP_ERROR_CANTP) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_CANTP) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_CANTP
  #error MEMMAP_ERROR_CANTP the included memory section was not defined within the BSW-IMPLEMENTATION of CanTp.
#endif
