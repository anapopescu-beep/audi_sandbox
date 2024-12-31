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

#define MEMMAP_ERROR_DCMIF

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for DcmIf */

#if (defined DcmIf_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef DcmIf_START_SEC_CODE
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef DcmIf_STOP_SEC_CODE
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_CODE_ASIL_A)
  #pragma default_function_attributes=@".text_asil_a"
  #undef DcmIf_START_SEC_CODE_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_CODE_ASIL_A)
  #pragma default_function_attributes=
  #undef DcmIf_STOP_SEC_CODE_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_CONST_16)
  #pragma default_variable_attributes=@".rodata"
  #undef DcmIf_START_SEC_CONST_16
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_CONST_16)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_CONST_16_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef DcmIf_START_SEC_CONST_16_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_CONST_16_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_CONST_16_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".rodata"
  #undef DcmIf_START_SEC_CONST_32
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_CONST_32_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef DcmIf_START_SEC_CONST_32_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_CONST_32_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_CONST_32_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_CONST_8)
  #pragma default_variable_attributes=@".rodata"
  #undef DcmIf_START_SEC_CONST_8
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_CONST_8)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_CONST_8_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef DcmIf_START_SEC_CONST_8_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_CONST_8_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_CONST_8_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_CONST_BOOL)
  #pragma default_variable_attributes=@".rodata"
  #undef DcmIf_START_SEC_CONST_BOOL
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_CONST_BOOL)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_CONST_BOOL
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_CONST_BOOL_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef DcmIf_START_SEC_CONST_BOOL_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_CONST_BOOL_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_CONST_BOOL_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef DcmIf_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_CONST_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=@".rodata_asil_a"
  #undef DcmIf_START_SEC_CONST_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_CONST_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_INIT_16)
  #pragma default_variable_attributes=@".data"
  #undef DcmIf_START_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_INIT_16)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_INIT_16_ASIL_A)
  #pragma default_variable_attributes=@".data_asil_a"
  #undef DcmIf_START_SEC_VAR_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_INIT_16_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_INIT_32)
  #pragma default_variable_attributes=@".data"
  #undef DcmIf_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_INIT_32)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_INIT_32_ASIL_A)
  #pragma default_variable_attributes=@".data_asil_a"
  #undef DcmIf_START_SEC_VAR_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_INIT_32_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_INIT_8)
  #pragma default_variable_attributes=@".data"
  #undef DcmIf_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_INIT_8)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_INIT_8_ASIL_A)
  #pragma default_variable_attributes=@".data_asil_a"
  #undef DcmIf_START_SEC_VAR_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_INIT_8_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_INIT_BOOL)
  #pragma default_variable_attributes=@".data"
  #undef DcmIf_START_SEC_VAR_INIT_BOOL
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_INIT_BOOL)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_INIT_BOOL
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_INIT_BOOL_ASIL_A)
  #pragma default_variable_attributes=@".data_asil_a"
  #undef DcmIf_START_SEC_VAR_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_INIT_BOOL_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".data"
  #undef DcmIf_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_INIT_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=@".data_asil_a"
  #undef DcmIf_START_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_INIT_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=@".bss"
  #undef DcmIf_START_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_NO_INIT_16_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef DcmIf_START_SEC_VAR_NO_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_NO_INIT_16_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_NO_INIT_16_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_NO_INIT_32)
  #pragma default_variable_attributes=@".bss"
  #undef DcmIf_START_SEC_VAR_NO_INIT_32
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_NO_INIT_32)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_NO_INIT_32
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_NO_INIT_32_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef DcmIf_START_SEC_VAR_NO_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_NO_INIT_32_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_NO_INIT_32_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=@".bss"
  #undef DcmIf_START_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_NO_INIT_8_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef DcmIf_START_SEC_VAR_NO_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_NO_INIT_8_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_NO_INIT_8_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_NO_INIT_BOOL)
  #pragma default_variable_attributes=@".bss"
  #undef DcmIf_START_SEC_VAR_NO_INIT_BOOL
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_NO_INIT_BOOL)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_NO_INIT_BOOL
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_NO_INIT_BOOL_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef DcmIf_START_SEC_VAR_NO_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_NO_INIT_BOOL_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_NO_INIT_BOOL_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".bss"
  #undef DcmIf_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=@".bss_asil_a"
  #undef DcmIf_START_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A
  #undef MEMMAP_ERROR_DCMIF

#elif (defined DcmIf_START_SEC_VAR_POWER_ON_CLEARED)
  #pragma default_variable_attributes=@".noinit"
  #undef DcmIf_START_SEC_VAR_POWER_ON_CLEARED
  #undef MEMMAP_ERROR_DCMIF
#elif (defined DcmIf_STOP_SEC_VAR_POWER_ON_CLEARED)
  #pragma default_variable_attributes=
  #undef DcmIf_STOP_SEC_VAR_POWER_ON_CLEARED
  #undef MEMMAP_ERROR_DCMIF

#endif

#ifdef MEMMAP_ERROR_DCMIF
  #undef MEMMAP_ERROR_DCMIF
  #error MEMMAP_ERROR_DCMIF the included memory section was not defined within the SWC-IMPLEMENTATION of DcmIf.
#endif
