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

#define MEMMAP_ERROR_CIL

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for CIL */

#if (defined CIL_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef CIL_START_SEC_CODE
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef CIL_STOP_SEC_CODE
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_CODE_ASIL_A)
  #pragma default_function_attributes=@".text_asil_a"
  #undef CIL_START_SEC_CODE_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_CODE_ASIL_A)
  #pragma default_function_attributes=
  #undef CIL_STOP_SEC_CODE_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_CONST_16)
  #pragma default_variable_attributes=@".rodata"
  #undef CIL_START_SEC_CONST_16
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_CONST_16)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_CONST_16_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef CIL_START_SEC_CONST_16_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_CONST_16_ASIL_A)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_CONST_16_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".rodata"
  #undef CIL_START_SEC_CONST_32
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_CONST_32_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef CIL_START_SEC_CONST_32_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_CONST_32_ASIL_A)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_CONST_32_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_CONST_8)
  #pragma default_variable_attributes=@".rodata"
  #undef CIL_START_SEC_CONST_8
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_CONST_8)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_CONST_8_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef CIL_START_SEC_CONST_8_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_CONST_8_ASIL_A)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_CONST_8_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_CONST_BOOL)
  #pragma default_variable_attributes=@".rodata"
  #undef CIL_START_SEC_CONST_BOOL
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_CONST_BOOL)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_CONST_BOOL
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_CONST_BOOL_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef CIL_START_SEC_CONST_BOOL_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_CONST_BOOL_ASIL_A)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_CONST_BOOL_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef CIL_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_CONST_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef CIL_START_SEC_CONST_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_CONST_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_INIT_16)
  #undef CIL_START_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_INIT_16)
  #undef CIL_STOP_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_INIT_16_ASIL_A)
  #undef CIL_START_SEC_VAR_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_INIT_16_ASIL_A)
  #undef CIL_STOP_SEC_VAR_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_INIT_32)
  #undef CIL_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_INIT_32)
  #undef CIL_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_INIT_32_ASIL_A)
  #undef CIL_START_SEC_VAR_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_INIT_32_ASIL_A)
  #undef CIL_STOP_SEC_VAR_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_INIT_8)
  #undef CIL_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_INIT_8)
  #undef CIL_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_INIT_8_ASIL_A)
  #undef CIL_START_SEC_VAR_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_INIT_8_ASIL_A)
  #undef CIL_STOP_SEC_VAR_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_INIT_BOOL)
  #undef CIL_START_SEC_VAR_INIT_BOOL
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_INIT_BOOL)
  #undef CIL_STOP_SEC_VAR_INIT_BOOL
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_INIT_BOOL_ASIL_A)
  #undef CIL_START_SEC_VAR_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_INIT_BOOL_ASIL_A)
  #undef CIL_STOP_SEC_VAR_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef CIL_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef CIL_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_INIT_UNSPECIFIED_ASIL_A)
  #undef CIL_START_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_INIT_UNSPECIFIED_ASIL_A)
  #undef CIL_STOP_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=@".bss"
  #undef CIL_START_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_NO_INIT_16_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef CIL_START_SEC_VAR_NO_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_NO_INIT_16_ASIL_A)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_VAR_NO_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_NO_INIT_32)
  #pragma default_variable_attributes=@".bss"
  #undef CIL_START_SEC_VAR_NO_INIT_32
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_NO_INIT_32)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_VAR_NO_INIT_32
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_NO_INIT_32_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef CIL_START_SEC_VAR_NO_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_NO_INIT_32_ASIL_A)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_VAR_NO_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=@".bss"
  #undef CIL_START_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_NO_INIT_8_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef CIL_START_SEC_VAR_NO_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_NO_INIT_8_ASIL_A)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_VAR_NO_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_NO_INIT_BOOL)
  #pragma default_variable_attributes=@".bss"
  #undef CIL_START_SEC_VAR_NO_INIT_BOOL
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_NO_INIT_BOOL)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_VAR_NO_INIT_BOOL
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_NO_INIT_BOOL_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef CIL_START_SEC_VAR_NO_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_NO_INIT_BOOL_ASIL_A)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_VAR_NO_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".bss"
  #undef CIL_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef CIL_START_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_CIL

#elif (defined CIL_START_SEC_VAR_POWER_ON_CLEARED)
  #pragma default_variable_attributes=@".noinit"
  #undef CIL_START_SEC_VAR_POWER_ON_CLEARED
  #undef MEMMAP_ERROR_CIL
#elif (defined CIL_STOP_SEC_VAR_POWER_ON_CLEARED)
  #pragma default_variable_attributes=
  #undef CIL_STOP_SEC_VAR_POWER_ON_CLEARED
  #undef MEMMAP_ERROR_CIL

#endif

#ifdef MEMMAP_ERROR_CIL
  #undef MEMMAP_ERROR_CIL
  #error MEMMAP_ERROR_CIL the included memory section was not defined within the SWC-IMPLEMENTATION of CIL.
#endif
