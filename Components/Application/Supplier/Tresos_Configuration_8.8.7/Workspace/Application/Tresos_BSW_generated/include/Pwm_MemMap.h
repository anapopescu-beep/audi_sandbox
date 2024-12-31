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

#define MEMMAP_ERROR_PWM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Pwm */

#if (defined PWM_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
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

#elif (defined PWM_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef PWM_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_PWM
#elif (defined PWM_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef PWM_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_PWM

#elif (defined PWM_START_SEC_VAR_CLEARED_16)
  #undef PWM_START_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_PWM
#elif (defined PWM_STOP_SEC_VAR_CLEARED_16)
  #undef PWM_STOP_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_PWM

#elif (defined PWM_START_SEC_VAR_CLEARED_32)
  #undef PWM_START_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_PWM
#elif (defined PWM_STOP_SEC_VAR_CLEARED_32)
  #undef PWM_STOP_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_PWM

#elif (defined PWM_START_SEC_VAR_CLEARED_8)
  #undef PWM_START_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_PWM
#elif (defined PWM_STOP_SEC_VAR_CLEARED_8)
  #undef PWM_STOP_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_PWM

#elif (defined PWM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_PWM
#elif (defined PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_PWM

#elif (defined PWM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef PWM_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_PWM
#elif (defined PWM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef PWM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_PWM

#endif

#if ((!defined MEMMAP_ERROR_PWM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_PWM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_PWM
  #error MEMMAP_ERROR_PWM the included memory section was not defined within the BSW-IMPLEMENTATION of Pwm.
#endif
