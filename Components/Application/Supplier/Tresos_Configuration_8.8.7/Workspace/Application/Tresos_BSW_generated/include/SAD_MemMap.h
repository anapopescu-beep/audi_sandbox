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

#define MEMMAP_ERROR_SAD

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for SAD */

#if (defined SAD_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef SAD_START_SEC_CODE
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef SAD_STOP_SEC_CODE
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_CODE_ASIL_A)
  #pragma default_function_attributes=@".text_asil_a"
  #undef SAD_START_SEC_CODE_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_CODE_ASIL_A)
  #pragma default_function_attributes=
  #undef SAD_STOP_SEC_CODE_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_CONST_16)
  #pragma default_variable_attributes=@".rodata"
  #undef SAD_START_SEC_CONST_16
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_CONST_16)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_CONST_16_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef SAD_START_SEC_CONST_16_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_CONST_16_ASIL_A)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_CONST_16_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".rodata"
  #undef SAD_START_SEC_CONST_32
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_CONST_32_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef SAD_START_SEC_CONST_32_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_CONST_32_ASIL_A)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_CONST_32_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_CONST_8)
  #pragma default_variable_attributes=@".rodata"
  #undef SAD_START_SEC_CONST_8
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_CONST_8)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_CONST_8_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef SAD_START_SEC_CONST_8_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_CONST_8_ASIL_A)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_CONST_8_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_CONST_BOOL)
  #pragma default_variable_attributes=@".rodata"
  #undef SAD_START_SEC_CONST_BOOL
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_CONST_BOOL)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_CONST_BOOL
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_CONST_BOOL_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef SAD_START_SEC_CONST_BOOL_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_CONST_BOOL_ASIL_A)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_CONST_BOOL_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef SAD_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_CONST_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef SAD_START_SEC_CONST_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_CONST_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_INIT_16)
  #undef SAD_START_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_INIT_16)
  #undef SAD_STOP_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_INIT_16_ASIL_A)
  #undef SAD_START_SEC_VAR_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_INIT_16_ASIL_A)
  #undef SAD_STOP_SEC_VAR_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_INIT_32)
  #undef SAD_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_INIT_32)
  #undef SAD_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_INIT_32_ASIL_A)
  #undef SAD_START_SEC_VAR_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_INIT_32_ASIL_A)
  #undef SAD_STOP_SEC_VAR_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_INIT_8)
  #undef SAD_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_INIT_8)
  #undef SAD_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_INIT_8_ASIL_A)
  #undef SAD_START_SEC_VAR_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_INIT_8_ASIL_A)
  #undef SAD_STOP_SEC_VAR_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_INIT_BOOL)
  #undef SAD_START_SEC_VAR_INIT_BOOL
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_INIT_BOOL)
  #undef SAD_STOP_SEC_VAR_INIT_BOOL
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_INIT_BOOL_ASIL_A)
  #undef SAD_START_SEC_VAR_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_INIT_BOOL_ASIL_A)
  #undef SAD_STOP_SEC_VAR_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef SAD_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef SAD_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_INIT_UNSPECIFIED_ASIL_A)
  #undef SAD_START_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_INIT_UNSPECIFIED_ASIL_A)
  #undef SAD_STOP_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=@".bss"
  #undef SAD_START_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_NO_INIT_16_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef SAD_START_SEC_VAR_NO_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_NO_INIT_16_ASIL_A)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_VAR_NO_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_NO_INIT_32)
  #pragma default_variable_attributes=@".bss"
  #undef SAD_START_SEC_VAR_NO_INIT_32
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_NO_INIT_32)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_VAR_NO_INIT_32
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_NO_INIT_32_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef SAD_START_SEC_VAR_NO_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_NO_INIT_32_ASIL_A)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_VAR_NO_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=@".bss"
  #undef SAD_START_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_NO_INIT_8_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef SAD_START_SEC_VAR_NO_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_NO_INIT_8_ASIL_A)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_VAR_NO_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_NO_INIT_BOOL)
  #pragma default_variable_attributes=@".bss"
  #undef SAD_START_SEC_VAR_NO_INIT_BOOL
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_NO_INIT_BOOL)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_VAR_NO_INIT_BOOL
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_NO_INIT_BOOL_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef SAD_START_SEC_VAR_NO_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_NO_INIT_BOOL_ASIL_A)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_VAR_NO_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".bss"
  #undef SAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef SAD_START_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_SAD

#elif (defined SAD_START_SEC_VAR_POWER_ON_CLEARED)
  #pragma default_variable_attributes=@".noinit"
  #undef SAD_START_SEC_VAR_POWER_ON_CLEARED
  #undef MEMMAP_ERROR_SAD
#elif (defined SAD_STOP_SEC_VAR_POWER_ON_CLEARED)
  #pragma default_variable_attributes=
  #undef SAD_STOP_SEC_VAR_POWER_ON_CLEARED
  #undef MEMMAP_ERROR_SAD

#endif

#ifdef MEMMAP_ERROR_SAD
  #undef MEMMAP_ERROR_SAD
  #error MEMMAP_ERROR_SAD the included memory section was not defined within the SWC-IMPLEMENTATION of SAD.
#endif
