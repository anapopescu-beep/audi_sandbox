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

#define MEMMAP_ERROR_PORT

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Port */

#if (defined PORT_START_SEC_CODE)
  #pragma default_function_attributes=@".mcal_text"
  #undef PORT_START_SEC_CODE
  #undef MEMMAP_ERROR_PORT
#elif (defined PORT_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef PORT_STOP_SEC_CODE
  #undef MEMMAP_ERROR_PORT

#elif (defined PORT_START_SEC_CONFIG_DATA_16)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef PORT_START_SEC_CONFIG_DATA_16
  #undef MEMMAP_ERROR_PORT
#elif (defined PORT_STOP_SEC_CONFIG_DATA_16)
  #pragma default_variable_attributes=
  #undef PORT_STOP_SEC_CONFIG_DATA_16
  #undef MEMMAP_ERROR_PORT

#elif (defined PORT_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_PORT
#elif (defined PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_PORT

#elif (defined PORT_START_SEC_CONST_16)
  #pragma default_variable_attributes=@".rodata"
  #undef PORT_START_SEC_CONST_16
  #undef MEMMAP_ERROR_PORT
#elif (defined PORT_STOP_SEC_CONST_16)
  #pragma default_variable_attributes=
  #undef PORT_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_PORT

#elif (defined PORT_START_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_data"
  #undef PORT_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_PORT
#elif (defined PORT_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef PORT_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_PORT

#elif (defined PORT_START_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=@".mcal_bss"
  #undef PORT_START_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_PORT
#elif (defined PORT_STOP_SEC_VAR_NO_INIT_16)
  #pragma default_variable_attributes=
  #undef PORT_STOP_SEC_VAR_NO_INIT_16
  #undef MEMMAP_ERROR_PORT

#endif

#if ((!defined MEMMAP_ERROR_PORT) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_PORT) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_PORT
  #error MEMMAP_ERROR_PORT the included memory section was not defined within the BSW-IMPLEMENTATION of Port.
#endif
