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

#define MEMMAP_ERROR_ADC

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Adc */

#if (defined ADC_START_SEC_CODE)
  #pragma default_function_attributes=@".mcal_text"
  #undef ADC_START_SEC_CODE
  #undef MEMMAP_ERROR_ADC
#elif (defined ADC_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef ADC_STOP_SEC_CODE
  #undef MEMMAP_ERROR_ADC

#elif (defined ADC_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_ADC
#elif (defined ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_ADC

#elif (defined ADC_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".mcal_const"
  #undef ADC_START_SEC_CONST_32
  #undef MEMMAP_ERROR_ADC
#elif (defined ADC_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef ADC_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_ADC

#elif (defined ADC_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const"
  #undef ADC_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_ADC
#elif (defined ADC_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef ADC_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_ADC

#elif (defined ADC_START_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_data_adc"
  #undef ADC_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_ADC
#elif (defined ADC_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_ADC

#elif (defined ADC_START_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=@".mcal_bss"
  #undef ADC_START_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_ADC
#elif (defined ADC_STOP_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=
  #undef ADC_STOP_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_ADC

#elif (defined ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_bss"
  #undef ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_ADC
#elif (defined ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_ADC

#endif

#if ((!defined MEMMAP_ERROR_ADC) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_ADC) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_ADC
  #error MEMMAP_ERROR_ADC the included memory section was not defined within the BSW-IMPLEMENTATION of Adc.
#endif
