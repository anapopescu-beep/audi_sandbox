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

/*==================[macros]=================================================*/

#if (defined MYDCM_BOOT_STATUS_STOP_SEC_Common)
  #undef MYDCM_BOOT_STATUS_STOP_SEC_Common
 // #pragma endsection
	#undef MEMMAP_ERROR
#elif (defined MYDCM_BOOT_STATUS_START_SEC_Common)
  #undef      MYDCM_BOOT_STATUS_START_SEC_Common
	#pragma location=".prog_sig" 
  #undef MEMMAP_ERROR
#endif
