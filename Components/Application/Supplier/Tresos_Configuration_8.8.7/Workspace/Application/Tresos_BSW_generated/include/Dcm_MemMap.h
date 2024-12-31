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

#define MEMMAP_ERROR_DCM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Dcm */

#if (defined DCM_START_SEC_CALIB_8)
  #undef DCM_START_SEC_CALIB_8
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_CALIB_8)
  #undef DCM_STOP_SEC_CALIB_8
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_CALLOUT_CODE)
  #pragma default_function_attributes=@".text"
  #undef DCM_START_SEC_CALLOUT_CODE
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_CALLOUT_CODE)
  #pragma default_function_attributes=
  #undef DCM_STOP_SEC_CALLOUT_CODE
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef DCM_START_SEC_CODE
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef DCM_STOP_SEC_CODE
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_CONST_16)
  #pragma default_variable_attributes=@".rodata"
  #undef DCM_START_SEC_CONST_16
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_CONST_16)
  #pragma default_variable_attributes=
  #undef DCM_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".rodata"
  #undef DCM_START_SEC_CONST_32
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef DCM_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_CONST_8)
  #pragma default_variable_attributes=@".rodata"
  #undef DCM_START_SEC_CONST_8
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_CONST_8)
  #pragma default_variable_attributes=
  #undef DCM_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef DCM_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef DCM_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_VAR_CLEARED_16)
  #undef DCM_START_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_VAR_CLEARED_16)
  #undef DCM_STOP_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_VAR_CLEARED_32)
  #undef DCM_START_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_VAR_CLEARED_32)
  #undef DCM_STOP_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_VAR_CLEARED_8)
  #undef DCM_START_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_VAR_CLEARED_8)
  #undef DCM_STOP_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_VAR_INIT_16)
  #undef DCM_START_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_VAR_INIT_16)
  #undef DCM_STOP_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_VAR_INIT_32)
  #undef DCM_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_VAR_INIT_32)
  #undef DCM_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_VAR_INIT_8)
  #undef DCM_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_VAR_INIT_8)
  #undef DCM_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef DCM_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_DCM

#elif (defined DCM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef DCM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_DCM
#elif (defined DCM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef DCM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_DCM

#elif (defined Dcm_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef Dcm_START_SEC_CODE
  #undef MEMMAP_ERROR_DCM
#elif (defined Dcm_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef Dcm_STOP_SEC_CODE
  #undef MEMMAP_ERROR_DCM

#endif

#if ((!defined MEMMAP_ERROR_DCM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_DCM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_DCM
  #error MEMMAP_ERROR_DCM the included memory section was not defined within the BSW-IMPLEMENTATION or SWC-IMPLEMENTATION of Dcm.
#endif
