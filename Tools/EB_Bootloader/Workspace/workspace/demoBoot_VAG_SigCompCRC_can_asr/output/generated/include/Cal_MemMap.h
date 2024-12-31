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

#define MEMMAP_ERROR_CAL

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Cal */

#if (defined CAL_START_SEC_CODE)
  #undef CAL_START_SEC_CODE
  #undef MEMMAP_ERROR_CAL
#elif (defined CAL_STOP_SEC_CODE)
  #undef CAL_STOP_SEC_CODE
  #undef MEMMAP_ERROR_CAL

#elif (defined CAL_START_SEC_CONST_UNSPECIFIED)
  #undef CAL_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CAL
#elif (defined CAL_STOP_SEC_CONST_UNSPECIFIED)
  #undef CAL_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CAL

#endif

#if ((!defined MEMMAP_ERROR_CAL) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_CAL) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_CAL
  #error MEMMAP_ERROR_CAL the included memory section was not defined within the BSW-IMPLEMENTATION of Cal.
#endif
