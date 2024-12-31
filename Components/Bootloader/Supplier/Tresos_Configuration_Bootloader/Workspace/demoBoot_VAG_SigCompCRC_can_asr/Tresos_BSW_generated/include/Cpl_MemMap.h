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

#define MEMMAP_ERROR_CPL

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Cpl */

#if (defined CPL_START_SEC_CODE)
  #undef CPL_START_SEC_CODE
  #undef MEMMAP_ERROR_CPL
#elif (defined CPL_STOP_SEC_CODE)
  #undef CPL_STOP_SEC_CODE
  #undef MEMMAP_ERROR_CPL

#elif (defined CPL_START_SEC_CONST_UNSPECIFIED)
  #undef CPL_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CPL
#elif (defined CPL_STOP_SEC_CONST_UNSPECIFIED)
  #undef CPL_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CPL

#endif

#if ((!defined MEMMAP_ERROR_CPL) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_CPL) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_CPL
  #error MEMMAP_ERROR_CPL the included memory section was not defined within the BSW-IMPLEMENTATION of Cpl.
#endif
