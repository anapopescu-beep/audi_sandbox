/**
 * \file
 *
 * \brief AUTOSAR MemMap
 *
 * This file contains the implementation of the AUTOSAR
 * module MemMap.
 *
 * \version 1.3.8
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

#define MEMMAP_ERROR_CRY

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Cry */

#if (defined CRY_START_SEC_CODE)
  #undef CRY_START_SEC_CODE
  #undef MEMMAP_ERROR_CRY
#elif (defined CRY_STOP_SEC_CODE)
  #undef CRY_STOP_SEC_CODE
  #undef MEMMAP_ERROR_CRY

#elif (defined CRY_START_SEC_CONST_16)
  #undef CRY_START_SEC_CONST_16
  #undef MEMMAP_ERROR_CRY
#elif (defined CRY_STOP_SEC_CONST_16)
  #undef CRY_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_CRY

#elif (defined CRY_START_SEC_CONST_32)
  #undef CRY_START_SEC_CONST_32
  #undef MEMMAP_ERROR_CRY
#elif (defined CRY_STOP_SEC_CONST_32)
  #undef CRY_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_CRY

#elif (defined CRY_START_SEC_CONST_8)
  #undef CRY_START_SEC_CONST_8
  #undef MEMMAP_ERROR_CRY
#elif (defined CRY_STOP_SEC_CONST_8)
  #undef CRY_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_CRY

#elif (defined CRY_START_SEC_CONST_UNSPECIFIED)
  #undef CRY_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CRY
#elif (defined CRY_STOP_SEC_CONST_UNSPECIFIED)
  #undef CRY_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CRY

#elif (defined CRY_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef CRY_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CRY
#elif (defined CRY_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CRY

#elif (defined CRY_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef CRY_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CRY
#elif (defined CRY_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef CRY_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CRY

#endif

#if ((!defined MEMMAP_ERROR_CRY) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_CRY) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_CRY
  #error MEMMAP_ERROR_CRY the included memory section was not defined within the BSW-IMPLEMENTATION of Cry.
#endif
