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

#define MEMMAP_ERROR_NVP

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for NVP */

#if (defined NVP_START_SEC_NVP_CONST_8)
  #pragma default_variable_attributes=@".rodata"
  #undef NVP_START_SEC_NVP_CONST_8
  #undef MEMMAP_ERROR_NVP
#elif (defined NVP_STOP_SEC_NVP_CONST_8)
  #pragma default_variable_attributes=
  #undef NVP_STOP_SEC_NVP_CONST_8
  #undef MEMMAP_ERROR_NVP

#elif (defined NVP_START_SEC_NVP_CONST_CAL_VERS_U32)
  #pragma default_variable_attributes=@".rodata"
  #undef NVP_START_SEC_NVP_CONST_CAL_VERS_U32
  #undef MEMMAP_ERROR_NVP
#elif (defined NVP_STOP_SEC_NVP_CONST_CAL_VERS_U32)
  #pragma default_variable_attributes=
  #undef NVP_STOP_SEC_NVP_CONST_CAL_VERS_U32
  #undef MEMMAP_ERROR_NVP

#elif (defined NVP_START_SEC_NVP_CONST_NVM_VERS_U32)
  #pragma default_variable_attributes=@".rodata"
  #undef NVP_START_SEC_NVP_CONST_NVM_VERS_U32
  #undef MEMMAP_ERROR_NVP
#elif (defined NVP_STOP_SEC_NVP_CONST_NVM_VERS_U32)
  #pragma default_variable_attributes=
  #undef NVP_STOP_SEC_NVP_CONST_NVM_VERS_U32
  #undef MEMMAP_ERROR_NVP

#elif (defined NVP_START_SEC_NVP_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef NVP_START_SEC_NVP_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_NVP
#elif (defined NVP_STOP_SEC_NVP_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef NVP_STOP_SEC_NVP_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_NVP

#elif (defined NVP_START_SEC_NVP_VAR_8)
  #pragma default_variable_attributes=@".data"
  #undef NVP_START_SEC_NVP_VAR_8
  #undef MEMMAP_ERROR_NVP
#elif (defined NVP_STOP_SEC_NVP_VAR_8)
  #pragma default_variable_attributes=
  #undef NVP_STOP_SEC_NVP_VAR_8
  #undef MEMMAP_ERROR_NVP

#endif

#ifdef MEMMAP_ERROR_NVP
  #undef MEMMAP_ERROR_NVP
  #error MEMMAP_ERROR_NVP the included memory section was not defined within the SWC-IMPLEMENTATION of NVP.
#endif
