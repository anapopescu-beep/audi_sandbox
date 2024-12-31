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

#define MEMMAP_ERROR_FEE

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Fee */

#if (defined FEE_START_SEC_CODE)
  #undef FEE_START_SEC_CODE
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_CODE)
  #undef FEE_STOP_SEC_CODE
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_CONST_UNSPECIFIED)
  #undef FEE_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_CONST_UNSPECIFIED)
  #undef FEE_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_VAR_INIT_16)
  #undef FEE_START_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_VAR_INIT_16)
  #undef FEE_STOP_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_VAR_INIT_32)
  #undef FEE_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_VAR_INIT_32)
  #undef FEE_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_VAR_INIT_8)
  #undef FEE_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_VAR_INIT_8)
  #undef FEE_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef FEE_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_FEE

#elif (defined FEE_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef FEE_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_FEE
#elif (defined FEE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef FEE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_FEE

#endif

#if ((!defined MEMMAP_ERROR_FEE) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_FEE) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_FEE
  #error MEMMAP_ERROR_FEE the included memory section was not defined within the BSW-IMPLEMENTATION of Fee.
#endif
