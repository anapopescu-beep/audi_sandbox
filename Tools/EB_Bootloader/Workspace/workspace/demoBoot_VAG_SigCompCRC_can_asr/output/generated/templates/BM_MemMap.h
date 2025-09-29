/**
 * \file
 *
 * \brief AUTOSAR BM
 *
 * This file contains the implementation of the AUTOSAR
 * module BM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2019 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*
 *  MISRA deviation report:
 *  - This file violates MISRA-C:2004, Rule 19.6:
 *       "#undef shall not be used"
 *    Reason:
 *       The specification document explicitely describes this mechanism.
 *  - This file violates MISRA-C:2004, Rule 19.15:
 *       "Precautions shall be taken in order to prevent the contents
 *        of a header file being included twice."
 *    Reason:
 *       This file needs to be included more than once in a compilation unit
 */
/* CHECK: NOPARSE */

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 3.4 (required)
 *   "All uses of the #pragma directive shall be documented and explained."
 *
 *   Reason:
 *   lib.
 *
 */
/* Deviation MISRA-1 <START> */
#if 0 /* to be able to use #elif for every module */
/*------------------[Start of a module]--------------------------------------*/

/* Start of History Record */
#elif defined (BM_BOOT_CKS_START_SEC_VAR)
    #undef      BM_BOOT_CKS_START_SEC_VAR
    #if (PLATFORMS_TOOLCHAIN == PLATFORMS_tasking)
		#if (TS_ARCH_DERIVATE == TS_XC2268)
          #pragma  section far="Bootchecksum"
	      #pragma  romdata
	      #pragma  protect
        #else
          #pragma  section farrom "Bootchecksum"
          #pragma  protect
        #endif
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_gnu)
      __attribute__((section(".bootchecksum")))
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_multi)
        #pragma ghs section rodata = ".bootchecksum"
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_dcc)
    #endif
    #undef MEMMAP_ERROR
#elif defined (BM_BOOT_CKS_STOP_SEC_VAR)
    #undef      BM_BOOT_CKS_STOP_SEC_VAR
    #if (PLATFORMS_TOOLCHAIN == PLATFORMS_tasking)
		#if (TS_ARCH_DERIVATE == TS_XC2268)
		  #pragma endprotect
	      #pragma noromdata
          #pragma endsection
        #else
          #pragma section farrom restore
          #pragma endprotect
        #endif
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_gnu)
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_multi)
        #pragma ghs section rodata=default
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_dcc)
    #endif
    #undef MEMMAP_ERROR
  
#endif
