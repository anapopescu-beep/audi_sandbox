/**
 * \file
 *
 * \brief AUTOSAR Demo_GM
 *
 * This file contains the implementation of the AUTOSAR
 * module Demo_GM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
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
#elif (defined BOARD_START_STACK_CODE)
  #undef BOARD_START_STACK_CODE
    #if (PLATFORMS_TOOLCHAIN == PLATFORMS_tasking)
      #pragma section farbss "stack"
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_gnu)
      __attribute__((section(".stack")))
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_multi)
      #pragma ghs section bss=".stack"
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_dcc)
      #pragma section DATA "" ".int_ram_stack"
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_iar)
        #pragma location=".stack"
    #endif
  #undef MEMMAP_ERROR

#elif (defined BOARD_STOP_STACK_CODE)
  #undef BOARD_STOP_STACK_CODE
    #if (PLATFORMS_TOOLCHAIN == PLATFORMS_tasking)
      #pragma section farbss restore
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_gnu)
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_multi)
      #pragma ghs section bss=default
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_dcc)
      #pragma section DATA
    #endif
  #undef MEMMAP_ERROR

#elif (defined BOARD_START_SEC_VAR_NO_INIT)
   #undef      BOARD_START_SEC_VAR_NO_INIT
    #if (PLATFORMS_TOOLCHAIN == PLATFORMS_tasking)
     #if (TS_ARCH_DERIVATE == TS_XC2268)
        #pragma section section_noinit
      #else
        #pragma section farbss "section_noinit"
      #endif
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_ccs)
     #pragma DATA_SECTION(ubRamNoInit,"section_noinit")
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_softune)
      #pragma segment DATA=section_noinit
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_ticgt)
     #pragma DATA_SECTION(ubRamNoInit,"section_noinit")
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_gnu)
      __attribute__((section(".section_noinit")))
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_multi)
      #if (defined BOARD_V850ESFX3)
        #pragma ghs section sbss=".section_noinit"
      #else
        #pragma ghs section bss=".section_noinit"
      #endif
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_csp)
      #if (defined BOARD_RL78F1X_GFEGSM)
        #pragma section bss .section_noinit
      #else
        #pragma section .section_noinit
      #endif
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_dcc)
      #pragma section DATA ".noinit" ".noinit" RW
      #pragma use_section DATA
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_iar)
      #pragma object_attribute=__no_init
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_mwerks)
      #if (TS_ARCH_FAMILY != TS_S12X)
        #pragma push
        #pragma section ".noinit" ".noinitbss"
        __declspec (section ".noinit")
      #else
        #pragma DATA_SEG __DPAGE_SEG .noinit
      #endif
    #endif
   #undef MEMMAP_ERROR
#elif (defined BOARD_STOP_SEC_VAR_NO_INIT)
   #undef      BOARD_STOP_SEC_VAR_NO_INIT
    #if (PLATFORMS_TOOLCHAIN == PLATFORMS_tasking)
      #if (TS_ARCH_FAMILY != TS_XC2000)
        #pragma section farbss restore
      #else
        #pragma endsection
      #endif
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_ccs)

    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_gnu)
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_multi)
		#if (defined BOARD_V850ESFX3)
		  #pragma ghs section sbss=default
		#else
          #pragma ghs section bss=default
		#endif
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_csp)
		#if (defined BOARD_RL78F1X_GFEGSM)
		  #pragma section
		#else
		  #pragma section default
		#endif
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_dcc)
      #pragma section DATA ".data"
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_softune)
      #pragma segment DATA=DATA
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_iar)
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_mwerks)
        #if (TS_ARCH_FAMILY != TS_S12X)
            #pragma pop
        #else
            #pragma DATA_SEG DEFAULT
        #endif
    #endif
   #undef MEMMAP_ERROR

#elif defined (PROG_REPROG_FLAG_START_SEC_VAR_NO_INIT_8)
   #undef      PROG_REPROG_FLAG_START_SEC_VAR_NO_INIT_8
     #if (PLATFORMS_TOOLCHAIN == PLATFORMS_tasking)
       #if (TS_ARCH_DERIVATE == TS_XC2268)
           #pragma section far=prog_sig
           #pragma protect
        #else
           #pragma section farbss "prog_sig"
           #pragma protect
        #endif
     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_gnu)
      __attribute__((section(".prog_sig")))
     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_multi)
        #if (defined BOARD_V850ESFX3)
          #pragma ghs section sbss=".prog_sig"
        #else
          #pragma ghs section bss=".prog_sig"
        #endif
     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_dcc)
       #pragma section DATA "" ".prog_sig"
     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_softune)
       #pragma segment DATA=prog_sig

     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_ccs)
       #pragma DATA_SECTION(m_ulProgSig,".prog_sig")
     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_ticgt)
       #pragma DATA_SECTION(m_ulProgSig,".prog_sig")
     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_ticgt)
      #pragma DATA_SECTION(m_ulProgSig,".prog_sig")
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_csp)
        #if (defined BOARD_RL78F1X_GFEGSM)
          #pragma section bss .prog_sig
        #else
          #pragma section .prog_sig
        #endif
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_mwerks)
      #if (TS_ARCH_FAMILY != TS_S12X)
            #pragma push
            #pragma section data_type ".prog_sig"
        #else
            #pragma DATA_SEG .prog_sig
        #endif
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_iar)
      #pragma location=".prog_sig"
     #endif
   #undef MEMMAP_ERROR
#elif defined (PROG_REPROG_FLAG_STOP_SEC_VAR_NO_INIT_8)
   #undef      PROG_REPROG_FLAG_STOP_SEC_VAR_NO_INIT_8
   #undef MEMMAP_ERROR
   #if (PLATFORMS_TOOLCHAIN == PLATFORMS_tasking)
     #if (TS_ARCH_DERIVATE == TS_XC2268)
         #pragma endprotect
         #pragma endsection
      #else
         #pragma section farbss restore
         #pragma endprotect
      #endif
   #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_gnu)
   #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_multi)
     #pragma ghs section
   #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_dcc)
     #pragma section DATA
   #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_softune)
      #pragma segment DATA=DATA
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_csp)
        #if (defined BOARD_RL78F1X_GFEGSM)
          #pragma section
        #else
          #pragma section default
        #endif
    #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_mwerks)
      #if (TS_ARCH_FAMILY != TS_S12X)
        #pragma pop
      #else
        #pragma DATA_SEG DEFAULT
       #endif
   #endif

#elif defined (PROG_START_SEC_VAR_RAM_NO_INIT)
   #undef      PROG_START_SEC_VAR_RAM_NO_INIT
     #if (PLATFORMS_TOOLCHAIN == PLATFORMS_tasking)
     #if (TS_ARCH_DERIVATE == TS_XC2268)
        #pragma section ram_no_init
       #else
        #pragma section farbss ".ram_no_init"
       #endif
     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_gnu)
      __attribute__((section(".ram_no_init")))
     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_multi)
       #pragma ghs section bss=".ram_no_init"
     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_dcc)
      #pragma section DATA "" ".ram_no_init"
     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_iar)
       #pragma location=".ram_no_init"
     #endif
   #undef MEMMAP_ERROR
#elif defined (PROG_STOP_SEC_VAR_RAM_NO_INIT)
   #undef      PROG_STOP_SEC_VAR_RAM_NO_INIT
     #if (PLATFORMS_TOOLCHAIN == PLATFORMS_tasking)
     #if (TS_ARCH_DERIVATE == TS_XC2268)
        #pragma endsection
       #else
        #pragma section farbss restore
       #endif

     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_gnu)
     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_multi)
       #pragma ghs section
     #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_dcc)
       #pragma section BSS "" ""
     #endif
   #undef MEMMAP_ERROR

      /*  Used for flash driver start */
      #elif (defined FLASH_FLS_START_SEC_CODE)
         #undef      FLASH_FLS_START_SEC_CODE
          #if (PLATFORMS_TOOLCHAIN == PLATFORMS_dcc)
           #pragma section CODE ".fls_driver"
          #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_multi)
           #pragma ghs section text = ".fls_driver"
          #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_gnu)
            __attribute__((section(".fls_driver")))
          #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_iar)
            #pragma location=".fls_driver"
          #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_softune)
            #pragma segment FAR_CODE=RAMCODE
            #pragma segment CODE=RAMCODE
          #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_mwerks)
            #if (TS_ARCH_FAMILY != TS_S12X)
                  #pragma push
                  #pragma section code_type ".fls_driver"
              #else
                  #pragma CODE_SEG fls_driver
              #endif
           #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_ccs)
            #ifdef FLASH_FLS_RAM_FUNC
              #pragma CODE_SECTION(FLASH_FLS_RAM_FUNC,"ramfuncs")
            #endif
            #ifdef FLASH_OPERATION_CBK
              #pragma CODE_SECTION(FLASH_OPERATION_CBK,"ramfuncs")
            #endif
          #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_ticgt)
           #ifdef FLASH_FLS_RAM_TMS320F28035_FUNC
             #pragma CODE_SECTION(FLASH_FLS_RAM_TMS320F28035_FUNC,"ramfuncs")
           #endif
           #ifdef FLASH_OPERATION_CBK
             #pragma CODE_SECTION(FLASH_OPERATION_CBK,"ramfuncs");
           #endif
          #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_tasking)
             #if (TS_ARCH_DERIVATE == TS_XC2268)
                 #pragma section code=DRV_FLS_WRITE_SEC
              #else

              #endif
          #endif
         #undef MEMMAP_ERROR
      #elif (defined FLASH_FLS_STOP_SEC_CODE)
         #undef      FLASH_FLS_STOP_SEC_CODE
          #if (PLATFORMS_TOOLCHAIN == PLATFORMS_dcc)
           #pragma section CODE
          #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_multi)
           #pragma ghs section text = default
          #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_gnu)
          #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_softune)
            #pragma segment FAR_CODE
            #pragma segment CODE
          #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_mwerks)
            #if (TS_ARCH_FAMILY != TS_S12X)
              #pragma pop
            #else
              #pragma CODE_SEG DEFAULT
             #endif
          #elif (PLATFORMS_TOOLCHAIN == PLATFORMS_tasking)
             #if (TS_ARCH_DERIVATE == TS_XC2268)
                #pragma endsection
              #else

              #endif
          #endif
         #undef MEMMAP_ERROR
#endif
