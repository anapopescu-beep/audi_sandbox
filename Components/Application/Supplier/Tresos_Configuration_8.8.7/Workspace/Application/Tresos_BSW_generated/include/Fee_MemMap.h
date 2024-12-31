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

#define MEMMAP_ERROR_FEE

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Fee */

#if (defined FEE_START_SEC_CODE)
  #undef FEE_START_SEC_CODE
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_CODE)
  #undef FEE_STOP_SEC_CODE
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef FEE_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".mcal_const"
  #undef FEE_START_SEC_CONST_32
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef FEE_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_VAR_CLEARED_16)
  #undef FEE_START_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_VAR_CLEARED_16)
  #undef FEE_STOP_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_VAR_CLEARED_32)
  #undef FEE_START_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_VAR_CLEARED_32)
  #undef FEE_STOP_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_VAR_CLEARED_8)
  #undef FEE_START_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_VAR_CLEARED_8)
  #undef FEE_STOP_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef FEE_START_SEC_VAR_CLEARED_BOOLEAN
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef FEE_STOP_SEC_VAR_CLEARED_BOOLEAN
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef FEE_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef FEE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef FEE_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_FEE

#endif

#if ((!defined MEMMAP_ERROR_FEE) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_FEE) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_FEE
  #error MEMMAP_ERROR_FEE the included memory section was not defined within the BSW-IMPLEMENTATION of Fee.
#endif
