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

#define MEMMAP_ERROR_PWM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Pwm */

#if (defined PWM_START_SEC_CODE)
  #pragma default_function_attributes=@".mcal_text"
  #undef PWM_START_SEC_CODE
  #undef MEMMAP_ERROR_PWM
#elif (defined PWM_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef PWM_STOP_SEC_CODE
  #undef MEMMAP_ERROR_PWM

#elif (defined PWM_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_PWM
#elif (defined PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_PWM

#elif (defined PWM_START_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_data"
  #undef PWM_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_PWM
#elif (defined PWM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef PWM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_PWM

#elif (defined PWM_START_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=@".mcal_bss"
  #undef PWM_START_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_PWM
#elif (defined PWM_STOP_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=
  #undef PWM_STOP_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_PWM

#elif (defined PWM_START_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=@".mcal_bss"
  #undef PWM_START_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_PWM
#elif (defined PWM_STOP_SEC_VAR_NO_INIT_8)
  #pragma default_variable_attributes=
  #undef PWM_STOP_SEC_VAR_NO_INIT_8
  #undef MEMMAP_ERROR_PWM

#elif (defined PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_bss"
  #undef PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_PWM
#elif (defined PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_PWM

#endif

#if ((!defined MEMMAP_ERROR_PWM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_PWM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_PWM
  #error MEMMAP_ERROR_PWM the included memory section was not defined within the BSW-IMPLEMENTATION of Pwm.
#endif
