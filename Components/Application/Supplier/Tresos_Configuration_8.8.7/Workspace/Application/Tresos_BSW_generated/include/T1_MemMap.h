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

#define MEMMAP_ERROR_T1

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for T1 */

#ifdef MEMMAP_ERROR_T1
  #undef MEMMAP_ERROR_T1
  #error MEMMAP_ERROR_T1 the included memory section was not defined within the SWC-IMPLEMENTATION of T1.
#endif
