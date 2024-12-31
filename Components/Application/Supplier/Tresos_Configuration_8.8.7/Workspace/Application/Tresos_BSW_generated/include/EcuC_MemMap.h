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

#define MEMMAP_ERROR_ECUC

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for EcuC */

#if (defined ECUC_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef ECUC_START_SEC_CODE
  #undef MEMMAP_ERROR_ECUC
#elif (defined ECUC_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef ECUC_STOP_SEC_CODE
  #undef MEMMAP_ERROR_ECUC

#elif (defined ECUC_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef ECUC_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUC
#elif (defined ECUC_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef ECUC_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUC

#elif (defined ECUC_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef ECUC_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUC
#elif (defined ECUC_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef ECUC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_ECUC

#endif

#if ((!defined MEMMAP_ERROR_ECUC) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_ECUC) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_ECUC
  #error MEMMAP_ERROR_ECUC the included memory section was not defined within the BSW-IMPLEMENTATION of EcuC.
#endif
