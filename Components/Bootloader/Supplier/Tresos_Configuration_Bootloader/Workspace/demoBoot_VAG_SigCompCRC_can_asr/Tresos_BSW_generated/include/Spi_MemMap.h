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

#define MEMMAP_ERROR_SPI

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Spi */

#if (defined SPI_START_SEC_CODE)
  #undef SPI_START_SEC_CODE
  #undef MEMMAP_ERROR_SPI
#elif (defined SPI_STOP_SEC_CODE)
  #undef SPI_STOP_SEC_CODE
  #undef MEMMAP_ERROR_SPI

#elif (defined SPI_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_SPI
#elif (defined SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_SPI

#elif (defined SPI_START_SEC_CONST_32)
  #undef SPI_START_SEC_CONST_32
  #undef MEMMAP_ERROR_SPI
#elif (defined SPI_STOP_SEC_CONST_32)
  #undef SPI_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_SPI

#elif (defined SPI_START_SEC_VAR_INIT_32)
  #undef SPI_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_SPI
#elif (defined SPI_STOP_SEC_VAR_INIT_32)
  #undef SPI_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_SPI

#elif (defined SPI_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef SPI_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_SPI
#elif (defined SPI_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_SPI

#elif (defined SPI_START_SEC_VAR_NO_INIT_32)
  #undef SPI_START_SEC_VAR_NO_INIT_32
  #undef MEMMAP_ERROR_SPI
#elif (defined SPI_STOP_SEC_VAR_NO_INIT_32)
  #undef SPI_STOP_SEC_VAR_NO_INIT_32
  #undef MEMMAP_ERROR_SPI

#elif (defined SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_SPI
#elif (defined SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_SPI

#elif (defined SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE)
  #undef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
  #undef MEMMAP_ERROR_SPI
#elif (defined SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE)
  #undef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
  #undef MEMMAP_ERROR_SPI

#endif

#if ((!defined MEMMAP_ERROR_SPI) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_SPI) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_SPI
  #error MEMMAP_ERROR_SPI the included memory section was not defined within the BSW-IMPLEMENTATION of Spi.
#endif
