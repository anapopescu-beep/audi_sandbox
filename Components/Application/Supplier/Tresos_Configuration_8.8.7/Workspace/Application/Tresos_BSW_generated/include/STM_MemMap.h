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

#define MEMMAP_ERROR_STM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for STM */

#if (defined STM_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef STM_START_SEC_CODE
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef STM_STOP_SEC_CODE
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_CODE_ASIL_A)
  #pragma default_function_attributes=@".text_asil_a"
  #undef STM_START_SEC_CODE_ASIL_A
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_CODE_ASIL_A)
  #pragma default_function_attributes=
  #undef STM_STOP_SEC_CODE_ASIL_A
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_CONST_16)
  #pragma default_variable_attributes=@".rodata"
  #undef STM_START_SEC_CONST_16
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_CONST_16)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_CONST_16_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef STM_START_SEC_CONST_16_ASIL_A
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_CONST_16_ASIL_A)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_CONST_16_ASIL_A
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".rodata"
  #undef STM_START_SEC_CONST_32
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_CONST_32_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef STM_START_SEC_CONST_32_ASIL_A
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_CONST_32_ASIL_A)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_CONST_32_ASIL_A
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_CONST_8)
  #pragma default_variable_attributes=@".rodata"
  #undef STM_START_SEC_CONST_8
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_CONST_8)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_CONST_8_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef STM_START_SEC_CONST_8_ASIL_A
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_CONST_8_ASIL_A)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_CONST_8_ASIL_A
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_CONST_BOOL)
  #pragma default_variable_attributes=@".rodata"
  #undef STM_START_SEC_CONST_BOOL
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_CONST_BOOL)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_CONST_BOOL
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_CONST_BOOL_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef STM_START_SEC_CONST_BOOL_ASIL_A
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_CONST_BOOL_ASIL_A)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_CONST_BOOL_ASIL_A
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef STM_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_CONST_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef STM_START_SEC_CONST_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_CONST_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_INIT_16)
  #undef STM_START_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_INIT_16)
  #undef STM_STOP_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_INIT_16_ASIL_A)
  #undef STM_START_SEC_VAR_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_INIT_16_ASIL_A)
  #undef STM_STOP_SEC_VAR_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_INIT_32)
  #undef STM_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_INIT_32)
  #undef STM_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_INIT_32_ASIL_A)
  #undef STM_START_SEC_VAR_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_INIT_32_ASIL_A)
  #undef STM_STOP_SEC_VAR_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_INIT_8)
  #undef STM_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_INIT_8)
  #undef STM_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_INIT_8_ASIL_A)
  #undef STM_START_SEC_VAR_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_INIT_8_ASIL_A)
  #undef STM_STOP_SEC_VAR_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_INIT_BOOL)
  #undef STM_START_SEC_VAR_INIT_BOOL
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_INIT_BOOL)
  #undef STM_STOP_SEC_VAR_INIT_BOOL
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_INIT_BOOL_ASIL_A)
  #undef STM_START_SEC_VAR_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_INIT_BOOL_ASIL_A)
  #undef STM_STOP_SEC_VAR_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef STM_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef STM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_INIT_UNSPECIFIED_ASIL_A)
  #undef STM_START_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_INIT_UNSPECIFIED_ASIL_A)
  #undef STM_STOP_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=@".bss"
  #undef STM_START_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_NO_INIT_32)
  #pragma default_variable_attributes=@".bss"
  #undef STM_START_SEC_VAR_NO_INIT_32
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_NO_INIT_32)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_VAR_NO_INIT_32
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=@".bss"
  #undef STM_START_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_NO_INIT_BOOL)
  #pragma default_variable_attributes=@".bss"
  #undef STM_START_SEC_VAR_NO_INIT_BOOL
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_NO_INIT_BOOL)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_VAR_NO_INIT_BOOL
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".bss"
  #undef STM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=@".bss"
  #undef STM_START_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_STM

#elif (defined STM_START_SEC_VAR_POWER_ON_CLEARED)
  #pragma default_variable_attributes=@".noinit"
  #undef STM_START_SEC_VAR_POWER_ON_CLEARED
  #undef MEMMAP_ERROR_STM
#elif (defined STM_STOP_SEC_VAR_POWER_ON_CLEARED)
  #pragma default_variable_attributes=
  #undef STM_STOP_SEC_VAR_POWER_ON_CLEARED
  #undef MEMMAP_ERROR_STM

#endif

#ifdef MEMMAP_ERROR_STM
  #undef MEMMAP_ERROR_STM
  #error MEMMAP_ERROR_STM the included memory section was not defined within the SWC-IMPLEMENTATION of STM.
#endif
