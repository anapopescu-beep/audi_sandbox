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

#define MEMMAP_ERROR_CSM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Csm */

#if (defined CSM_START_SEC_CODE)
  #undef CSM_START_SEC_CODE
  #undef MEMMAP_ERROR_CSM
#elif (defined CSM_STOP_SEC_CODE)
  #undef CSM_STOP_SEC_CODE
  #undef MEMMAP_ERROR_CSM

#elif (defined CSM_START_SEC_CONST_UNSPECIFIED)
  #undef CSM_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CSM
#elif (defined CSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef CSM_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_CSM

#elif (defined CSM_START_SEC_VAR_INIT_BOOLEAN)
  #undef CSM_START_SEC_VAR_INIT_BOOLEAN
  #undef MEMMAP_ERROR_CSM
#elif (defined CSM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef CSM_STOP_SEC_VAR_INIT_BOOLEAN
  #undef MEMMAP_ERROR_CSM

#elif (defined CSM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef CSM_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CSM
#elif (defined CSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CSM

#elif (defined CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CSM
#elif (defined CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CSM

#endif

#if ((!defined MEMMAP_ERROR_CSM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_CSM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_CSM
  #error MEMMAP_ERROR_CSM the included memory section was not defined within the BSW-IMPLEMENTATION of Csm.
#endif
