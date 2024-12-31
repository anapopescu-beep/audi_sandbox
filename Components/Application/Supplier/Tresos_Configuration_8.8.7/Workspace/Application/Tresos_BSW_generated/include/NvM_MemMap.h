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

#define MEMMAP_ERROR_NVM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for NvM */

#if (defined NVM_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef NVM_START_SEC_CODE
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef NVM_STOP_SEC_CODE
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_CODE_MC_SHARED)
  #pragma default_function_attributes=@".text"
  #undef NVM_START_SEC_CODE_MC_SHARED
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_CODE_MC_SHARED)
  #pragma default_function_attributes=
  #undef NVM_STOP_SEC_CODE_MC_SHARED
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_CONFIG_DATA_16)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef NVM_START_SEC_CONFIG_DATA_16
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_CONFIG_DATA_16)
  #pragma default_variable_attributes=
  #undef NVM_STOP_SEC_CONFIG_DATA_16
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_CONFIG_DATA_8)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef NVM_START_SEC_CONFIG_DATA_8
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_CONFIG_DATA_8)
  #pragma default_variable_attributes=
  #undef NVM_STOP_SEC_CONFIG_DATA_8
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_CONFIG_DATA_MC_SHARED_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef NVM_START_SEC_CONFIG_DATA_MC_SHARED_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_CONFIG_DATA_MC_SHARED_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef NVM_STOP_SEC_CONFIG_DATA_MC_SHARED_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=@".mcal_const_cfg"
  #undef NVM_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_CLEARED_16)
  #undef NVM_START_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_CLEARED_16)
  #undef NVM_STOP_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_CLEARED_32)
  #undef NVM_START_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_CLEARED_32)
  #undef NVM_STOP_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_CLEARED_64)
  #undef NVM_START_SEC_VAR_CLEARED_64
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_CLEARED_64)
  #undef NVM_STOP_SEC_VAR_CLEARED_64
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_CLEARED_8)
  #undef NVM_START_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_CLEARED_8)
  #undef NVM_STOP_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_CLEARED_APPL_DATA_UNSPECIFIED)
  #undef NVM_START_SEC_VAR_CLEARED_APPL_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_CLEARED_APPL_DATA_UNSPECIFIED)
  #undef NVM_STOP_SEC_VAR_CLEARED_APPL_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_CLEARED_MC_SHARED_16)
  #undef NVM_START_SEC_VAR_CLEARED_MC_SHARED_16
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_CLEARED_MC_SHARED_16)
  #undef NVM_STOP_SEC_VAR_CLEARED_MC_SHARED_16
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_CLEARED_MC_SHARED_UNSPECIFIED)
  #undef NVM_START_SEC_VAR_CLEARED_MC_SHARED_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_CLEARED_MC_SHARED_UNSPECIFIED)
  #undef NVM_STOP_SEC_VAR_CLEARED_MC_SHARED_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_INIT_16)
  #undef NVM_START_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_INIT_16)
  #undef NVM_STOP_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_INIT_32)
  #undef NVM_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_INIT_32)
  #undef NVM_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_INIT_8)
  #undef NVM_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_INIT_8)
  #undef NVM_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_INIT_MC_SHARED_16)
  #undef NVM_START_SEC_VAR_INIT_MC_SHARED_16
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_INIT_MC_SHARED_16)
  #undef NVM_STOP_SEC_VAR_INIT_MC_SHARED_16
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef NVM_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef NVM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_POWER_ON_INIT_8)
  #undef NVM_START_SEC_VAR_POWER_ON_INIT_8
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_POWER_ON_INIT_8)
  #undef NVM_STOP_SEC_VAR_POWER_ON_INIT_8
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_POWER_ON_INIT_MC_SHARED_UNSPECIFIED)
  #undef NVM_START_SEC_VAR_POWER_ON_INIT_MC_SHARED_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_POWER_ON_INIT_MC_SHARED_UNSPECIFIED)
  #undef NVM_STOP_SEC_VAR_POWER_ON_INIT_MC_SHARED_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM

#elif (defined NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM
#elif (defined NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_NVM

#elif (defined NvM_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef NvM_START_SEC_CODE
  #undef MEMMAP_ERROR_NVM
#elif (defined NvM_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef NvM_STOP_SEC_CODE
  #undef MEMMAP_ERROR_NVM

#endif

#if ((!defined MEMMAP_ERROR_NVM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_NVM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_NVM
  #error MEMMAP_ERROR_NVM the included memory section was not defined within the BSW-IMPLEMENTATION or SWC-IMPLEMENTATION of NvM.
#endif
