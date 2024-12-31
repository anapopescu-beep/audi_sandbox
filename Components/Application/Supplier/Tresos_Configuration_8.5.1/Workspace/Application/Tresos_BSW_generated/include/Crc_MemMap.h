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

#define MEMMAP_ERROR_CRC

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Crc */

#if (defined CRC_START_SEC_CODE)
  #pragma default_function_attributes=@".text"
  #undef CRC_START_SEC_CODE
  #undef MEMMAP_ERROR_CRC
#elif (defined CRC_STOP_SEC_CODE)
  #pragma default_function_attributes=
  #undef CRC_STOP_SEC_CODE
  #undef MEMMAP_ERROR_CRC

#elif (defined CRC_START_SEC_CONST_16)
  #pragma default_variable_attributes=@".rodata"
  #undef CRC_START_SEC_CONST_16
  #undef MEMMAP_ERROR_CRC
#elif (defined CRC_STOP_SEC_CONST_16)
  #pragma default_variable_attributes=
  #undef CRC_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_CRC

#elif (defined CRC_START_SEC_CONST_32)
  #pragma default_variable_attributes=@".rodata"
  #undef CRC_START_SEC_CONST_32
  #undef MEMMAP_ERROR_CRC
#elif (defined CRC_STOP_SEC_CONST_32)
  #pragma default_variable_attributes=
  #undef CRC_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_CRC

#elif (defined CRC_START_SEC_CONST_8)
  #pragma default_variable_attributes=@".rodata"
  #undef CRC_START_SEC_CONST_8
  #undef MEMMAP_ERROR_CRC
#elif (defined CRC_STOP_SEC_CONST_8)
  #pragma default_variable_attributes=
  #undef CRC_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_CRC

#endif

#if ((!defined MEMMAP_ERROR_CRC) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_CRC) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_CRC
  #error MEMMAP_ERROR_CRC the included memory section was not defined within the BSW-IMPLEMENTATION of Crc.
#endif
