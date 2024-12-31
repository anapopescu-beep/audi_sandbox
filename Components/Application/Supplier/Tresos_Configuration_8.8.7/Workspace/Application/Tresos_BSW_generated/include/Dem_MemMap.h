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

#define MEMMAP_ERROR_DEM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Dem */

#if (defined DEM_START_SEC_CALIB_16)
  #undef DEM_START_SEC_CALIB_16
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_CALIB_16)
  #undef DEM_STOP_SEC_CALIB_16
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_CALIB_32)
  #undef DEM_START_SEC_CALIB_32
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_CALIB_32)
  #undef DEM_STOP_SEC_CALIB_32
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_CALIB_8)
  #undef DEM_START_SEC_CALIB_8
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_CALIB_8)
  #undef DEM_STOP_SEC_CALIB_8
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_CALIB_UNSPECIFIED)
  #undef DEM_START_SEC_CALIB_UNSPECIFIED
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_CALIB_UNSPECIFIED)
  #undef DEM_STOP_SEC_CALIB_UNSPECIFIED
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef DEM_START_SEC_CODE
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef DEM_STOP_SEC_CODE
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_CONST_16)
  #pragma default_variable_attributes=@".rodata"
  #undef DEM_START_SEC_CONST_16
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_CONST_16)
  #pragma default_variable_attributes=
  #undef DEM_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".rodata"
  #undef DEM_START_SEC_CONST_32
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef DEM_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_CONST_8)
  #pragma default_variable_attributes=@".rodata"
  #undef DEM_START_SEC_CONST_8
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_CONST_8)
  #pragma default_variable_attributes=
  #undef DEM_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=@".rodata"
  #undef DEM_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_CONST_UNSPECIFIED)
  #pragma default_variable_attributes=
  #undef DEM_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_VAR_CLEARED_16)
  #undef DEM_START_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_VAR_CLEARED_16)
  #undef DEM_STOP_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_VAR_CLEARED_32)
  #undef DEM_START_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_VAR_CLEARED_32)
  #undef DEM_STOP_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_VAR_CLEARED_8)
  #undef DEM_START_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_VAR_CLEARED_8)
  #undef DEM_STOP_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef DEM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_VAR_INIT_16)
  #undef DEM_START_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_VAR_INIT_16)
  #undef DEM_STOP_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_VAR_INIT_32)
  #undef DEM_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_VAR_INIT_32)
  #undef DEM_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_VAR_INIT_8)
  #undef DEM_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_VAR_INIT_8)
  #undef DEM_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef DEM_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef DEM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_VAR_SAVED_ZONE_16)
  #undef DEM_START_SEC_VAR_SAVED_ZONE_16
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_VAR_SAVED_ZONE_16)
  #undef DEM_STOP_SEC_VAR_SAVED_ZONE_16
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_VAR_SAVED_ZONE_8)
  #undef DEM_START_SEC_VAR_SAVED_ZONE_8
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_VAR_SAVED_ZONE_8)
  #undef DEM_STOP_SEC_VAR_SAVED_ZONE_8
  #undef MEMMAP_ERROR_DEM

#elif (defined DEM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef DEM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #undef MEMMAP_ERROR_DEM
#elif (defined DEM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef DEM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #undef MEMMAP_ERROR_DEM

#elif (defined Dem_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef Dem_START_SEC_CODE
  #undef MEMMAP_ERROR_DEM
#elif (defined Dem_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef Dem_STOP_SEC_CODE
  #undef MEMMAP_ERROR_DEM

#endif

#if ((!defined MEMMAP_ERROR_DEM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_DEM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_DEM
  #error MEMMAP_ERROR_DEM the included memory section was not defined within the BSW-IMPLEMENTATION or SWC-IMPLEMENTATION of Dem.
#endif
