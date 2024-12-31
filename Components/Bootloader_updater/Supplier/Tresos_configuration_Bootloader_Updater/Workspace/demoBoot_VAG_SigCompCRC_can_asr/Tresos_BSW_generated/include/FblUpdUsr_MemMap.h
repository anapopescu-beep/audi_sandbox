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

#define MEMMAP_ERROR_FBLUPDUSR

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for FblUpdUsr */

#if (defined BOOTLOADER_START_SEC_CONST_EXPORT)
  #pragma default_variable_attributes=@".fls_driver"
  #undef BOOTLOADER_START_SEC_CONST_EXPORT
  #undef MEMMAP_ERROR_FBLUPDUSR
#elif (defined BOOTLOADER_STOP_SEC_CONST_EXPORT)
  #pragma default_variable_attributes=
  #undef BOOTLOADER_STOP_SEC_CONST_EXPORT
  #undef MEMMAP_ERROR_FBLUPDUSR
#elif (defined BOOTLOADER_START_SEC_CONST)
  #pragma default_variable_attributes=@".fls_driver"
  #undef BOOTLOADER_START_SEC_CONST
  #undef MEMMAP_ERROR_FBLUPDUSR
#elif (defined BOOTLOADER_STOP_SEC_CONST)
  #pragma default_variable_attributes=
  #undef BOOTLOADER_STOP_SEC_CONST
  #undef MEMMAP_ERROR_FBLUPDUSR

#endif

#if ((!defined MEMMAP_ERROR_FBLUPDUSR) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_FBLUPDUSR) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_FBLUPDUSR
  #error MEMMAP_ERROR_FBLUPDUSR the included memory section was not defined within the BSW-IMPLEMENTATION of Port.
#endif