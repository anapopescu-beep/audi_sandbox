/**
*   @file    Fls_PBcfg.c
*   @implements Fls_PBcfg.c_Artifact
*   @version 1.0.2
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of all post-build configuration structures.
*
*   @addtogroup FLS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : IPV_FTFE
*   Dependencies         : 
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.2
*   Build Version        : S32K14xS32K14X_MCAL_1_0_2_RTM_ASR_REL_4_2_REV_0002_20190426
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2019 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section fls_TDK_4G_pbcfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before 
* '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping.
* 
* @section fls_TDK_4G_pbcfg_c_REF_2
* Violates MISRA 2004 Required Rule 11.1, Conversions involing function pointers must be to/from integral types.
* This violation is due to FLS213.
* 
* @section fls_TDK_4G_pbcfg_c_REF_3
* Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed between a pointer to object type
* and a different pointer to object type.
* This violation is due to FLS213.
* 
* @section fls_TDK_4G_pbcfg_c_REF_4
* Violates MISRA 2004 Required Rule 8.8, Object/function previously declared.
* The rule 8.8 requires that 'An external object or function shall be declared in one and only one file'.
* This requirement is fulfilled since the function is declared as external in and only in one configuration 
* C file (Fls_Cfg.c or Fls_TDK_4G_PBcfg.c). There is no need to put the declaration into Fls_Cfg.h and made it 
* accessible for all modules which includes Fls.h/Fls_Cfg.h.
* 
* @section fls_TDK_4G_pbcfg_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, Could be made static.  
* Making FlsConfigSet_0 static would make it unaccessible to the application.
*
* @section fls_TDK_4G_pbcfg_c_REF_6
* Violates MISRA 2004 Required Rule 20.2, Re-use of C90 identifier pattern.
* This is just a matter of a symbol specified in the configuration.
* 
* @section fls_TDK_4G_pbcfg_c_REF_7
* Violates MISRA 2004 Required Rule 8.8,
* An external object or function shall be declared in one and only one file.
* Possible MISRA error if the same callback function or variable name is used in multiple configuration variants. 
* Callback function/variable name is set by the driver user so this cannot be fixed by updating the driver code.
*
* @section fls_TDK_4G_pbcfg_c_REF_8
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* This violation is due to FLS213.
* 
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section [global]
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*  
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Reg_eSys_QSPI.h"
#include "Reg_eSys_FLASHC.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_CFG_C                      43
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define FLS_AR_RELEASE_MINOR_VERSION_CFG_C       2
#define FLS_AR_RELEASE_REVISION_VERSION_CFG_C    2
#define FLS_SW_MAJOR_VERSION_CFG_C               1
#define FLS_SW_MINOR_VERSION_CFG_C               0
#define FLS_SW_PATCH_VERSION_CFG_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != FLS_VENDOR_ID)
    #error "Fls_TDK_4G_PBcfg.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_TDK_4G_PBcfg.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG_C != FLS_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_TDK_4G_PBcfg.c and Fls.h are different"
#endif

/* Check if current file and Reg_eSys_QSPI header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != ESYS_QSPI_VENDOR_ID)
    #error "Fls_TDK_4G_PBcfg.c and Reg_eSys_QSPI.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_QSPI header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != ESYS_QSPI_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != ESYS_QSPI_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != ESYS_QSPI_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_TDK_4G_PBcfg.c and Reg_eSys_QSPI.h are different"
#endif
/* Check if current file and Reg_eSys_QSPI header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != ESYS_QSPI_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG_C != ESYS_QSPI_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG_C != ESYS_QSPI_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_TDK_4G_PBcfg.c and Reg_eSys_QSPI.h are different"
#endif

/* Check if current file and Reg_eSys_FLASHC header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != ESYS_FLASHC_VENDOR_ID)
    #error "Fls_TDK_4G_PBcfg.c and Reg_eSys_FLASHC.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_FLASHC header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != ESYS_FLASHC_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != ESYS_FLASHC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_TDK_4G_PBcfg.c and Reg_eSys_FLASHC.h are different"
#endif
/* Check if current file and Reg_eSys_FLASHC header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG_C != ESYS_FLASHC_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG_C != ESYS_FLASHC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_TDK_4G_PBcfg.c and Reg_eSys_FLASHC.h are different"
#endif


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_TDK_4G_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"        
/* Declaration of Fls notification function (Fee_JobEndNotification())*/
/* @violates @ref fls_TDK_4G_pbcfg_c_REF_4 Object/function previously declared */
extern FUNC( void, FLS_CODE ) Fee_JobEndNotification( void );
/* Declaration of Fls notification function (Fee_JobErrorNotification())*/
/* @violates @ref fls_TDK_4G_pbcfg_c_REF_4 Object/function previously declared */
extern FUNC( void, FLS_CODE ) Fee_JobErrorNotification( void );
#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_TDK_4G_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE_AC
/* 
* @violates @ref fls_TDK_4G_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#ifdef _LINARO_C_S32K14x_ 
#if (FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON)
#if (FLS_TIMEOUT_HANDLING == STD_ON)
/* @violates @ref fls_TDK_4G_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC, P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAbort ) __attribute__ ((section (".acfls_code_rom")));
#else
/* @violates @ref fls_TDK_4G_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) ) __attribute__ ((section (".acfls_code_rom")));
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
#else   /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_OFF */
#if (FLS_TIMEOUT_HANDLING == STD_ON)
/* @violates @ref fls_TDK_4G_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC ) __attribute__ ((section (".acfls_code_rom")));
#else
/* @violates @ref fls_TDK_4G_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) ) __attribute__ ((section (".acfls_code_rom")));
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
#endif  /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON */
#else
#if (FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON)
#if (FLS_TIMEOUT_HANDLING == STD_ON)
/* @violates @ref fls_TDK_4G_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode(CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC, P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAbort );
#else
/* @violates @ref fls_TDK_4G_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) );
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
#else   /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_OFF */
#if (FLS_TIMEOUT_HANDLING == STD_ON)
/* @violates @ref fls_TDK_4G_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode(CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC );
#else
/* @violates @ref fls_TDK_4G_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) );
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
#endif  /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON */
#endif /* #ifdef _LINARO_C_S32K14x_ */

#define FLS_STOP_SEC_CODE_AC
/* 
* @violates @ref fls_TDK_4G_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


                                                                                                                                                                                
            
                



#define FLS_START_SEC_CONFIG_DATA_8
/* 
* @violates @ref fls_TDK_4G_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/* aFlsSectorFlags[] (FlsConfigSet) */
static CONST(uint8, FLS_CONST) FlsConfigSet_TDK_4G_aFlsSectorFlags[32] =
{
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_0) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_1) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_2) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_3) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_4) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_5) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_6) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_7) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_8) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_9) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_10) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_11) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_12) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_13) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_14) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_15) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_16) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_17) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_18) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_19) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_20) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_21) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_22) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_23) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_24) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_25) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_26) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_27) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_28) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_29) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_30) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH /* (FlsSector_31) */
};
/* aFlsSectorUnlock[] (FlsConfigSet) */
static CONST(uint8, FLS_CONST) FlsConfigSet_TDK_4G_aFlsSectorUnlock[32] =
{
    1U, /* (FlsSector_0) */
    1U, /* (FlsSector_1) */
    1U, /* (FlsSector_2) */
    1U, /* (FlsSector_3) */
    1U, /* (FlsSector_4) */
    1U, /* (FlsSector_5) */
    1U, /* (FlsSector_6) */
    1U, /* (FlsSector_7) */
    1U, /* (FlsSector_8) */
    1U, /* (FlsSector_9) */
    1U, /* (FlsSector_10) */
    1U, /* (FlsSector_11) */
    1U, /* (FlsSector_12) */
    1U, /* (FlsSector_13) */
    1U, /* (FlsSector_14) */
    1U, /* (FlsSector_15) */
    1U, /* (FlsSector_16) */
    1U, /* (FlsSector_17) */
    1U, /* (FlsSector_18) */
    1U, /* (FlsSector_19) */
    1U, /* (FlsSector_20) */
    1U, /* (FlsSector_21) */
    1U, /* (FlsSector_22) */
    1U, /* (FlsSector_23) */
    1U, /* (FlsSector_24) */
    1U, /* (FlsSector_25) */
    1U, /* (FlsSector_26) */
    1U, /* (FlsSector_27) */
    1U, /* (FlsSector_28) */
    1U, /* (FlsSector_29) */
    1U, /* (FlsSector_30) */
    1U /* (FlsSector_31) */
};
#define FLS_STOP_SEC_CONFIG_DATA_8
/* 
* @violates @ref fls_TDK_4G_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
/* 
* @violates @ref fls_TDK_4G_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/* aFlsSectorEndAddr[] (FlsConfigSet) */
static CONST(Fls_AddressType, FLS_CONST) FlsConfigSet_TDK_4G_aFlsSectorEndAddr[32] =
{
    (Fls_AddressType)2047U, /* FlsSectorEndAddr (FlsSector_0)*/
    (Fls_AddressType)4095U, /* FlsSectorEndAddr (FlsSector_1)*/
    (Fls_AddressType)6143U, /* FlsSectorEndAddr (FlsSector_2)*/
    (Fls_AddressType)8191U, /* FlsSectorEndAddr (FlsSector_3)*/
    (Fls_AddressType)10239U, /* FlsSectorEndAddr (FlsSector_4)*/
    (Fls_AddressType)12287U, /* FlsSectorEndAddr (FlsSector_5)*/
    (Fls_AddressType)14335U, /* FlsSectorEndAddr (FlsSector_6)*/
    (Fls_AddressType)16383U, /* FlsSectorEndAddr (FlsSector_7)*/
    (Fls_AddressType)18431U, /* FlsSectorEndAddr (FlsSector_8)*/
    (Fls_AddressType)20479U, /* FlsSectorEndAddr (FlsSector_9)*/
    (Fls_AddressType)22527U, /* FlsSectorEndAddr (FlsSector_10)*/
    (Fls_AddressType)24575U, /* FlsSectorEndAddr (FlsSector_11)*/
    (Fls_AddressType)26623U, /* FlsSectorEndAddr (FlsSector_12)*/
    (Fls_AddressType)28671U, /* FlsSectorEndAddr (FlsSector_13)*/
    (Fls_AddressType)30719U, /* FlsSectorEndAddr (FlsSector_14)*/
    (Fls_AddressType)32767U, /* FlsSectorEndAddr (FlsSector_15)*/
    (Fls_AddressType)34815U, /* FlsSectorEndAddr (FlsSector_16)*/
    (Fls_AddressType)36863U, /* FlsSectorEndAddr (FlsSector_17)*/
    (Fls_AddressType)38911U, /* FlsSectorEndAddr (FlsSector_18)*/
    (Fls_AddressType)40959U, /* FlsSectorEndAddr (FlsSector_19)*/
    (Fls_AddressType)43007U, /* FlsSectorEndAddr (FlsSector_20)*/
    (Fls_AddressType)45055U, /* FlsSectorEndAddr (FlsSector_21)*/
    (Fls_AddressType)47103U, /* FlsSectorEndAddr (FlsSector_22)*/
    (Fls_AddressType)49151U, /* FlsSectorEndAddr (FlsSector_23)*/
    (Fls_AddressType)51199U, /* FlsSectorEndAddr (FlsSector_24)*/
    (Fls_AddressType)53247U, /* FlsSectorEndAddr (FlsSector_25)*/
    (Fls_AddressType)55295U, /* FlsSectorEndAddr (FlsSector_26)*/
    (Fls_AddressType)57343U, /* FlsSectorEndAddr (FlsSector_27)*/
    (Fls_AddressType)59391U, /* FlsSectorEndAddr (FlsSector_28)*/
    (Fls_AddressType)61439U, /* FlsSectorEndAddr (FlsSector_29)*/
    (Fls_AddressType)63487U, /* FlsSectorEndAddr (FlsSector_30)*/
    (Fls_AddressType)65535U /* FlsSectorEndAddr (FlsSector_31)*/
};

/* paSectorProgSize[] (FlsConfigSet) */
static CONST(Fls_LengthType, FLS_CONST) FlsConfigSet_TDK_4G_aFlsProgSize[32] =
{
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_0) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_1) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_2) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_3) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_4) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_5) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_6) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_7) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_8) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_9) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_10) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_11) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_12) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_13) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_14) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_15) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_16) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_17) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_18) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_19) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_20) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_21) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_22) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_23) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_24) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_25) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_26) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_27) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_28) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_29) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_30) */
    (Fls_LengthType)FLS_WRITE_DOUBLE_WORD /* FlsProgrammingSize (FlsSector_31) */
};


/* paSectorPageSize[] (FlsConfigSet) */
static CONST(Fls_LengthType, FLS_CONST) FlsConfigSet_TDK_4G_aFlsSectorPageSize[32] =
{
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_0) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_1) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_2) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_3) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_4) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_5) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_6) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_7) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_8) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_9) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_10) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_11) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_12) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_13) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_14) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_15) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_16) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_17) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_18) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_19) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_20) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_21) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_22) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_23) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_24) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_25) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_26) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_27) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_28) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_29) */
    (Fls_LengthType)8U, /* FlsPageSize (FlsSector_30) */
    (Fls_LengthType)8U /* FlsPageSize (FlsSector_31) */
};



static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_0_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x000000UL),    /* sectorStartAddressPtr */
    0U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_1_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x000800UL),    /* sectorStartAddressPtr */
    1U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_2_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x001000UL),    /* sectorStartAddressPtr */
    2U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_3_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x001800UL),    /* sectorStartAddressPtr */
    3U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_4_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x002000UL),    /* sectorStartAddressPtr */
    4U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_5_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x002800UL),    /* sectorStartAddressPtr */
    5U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_6_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x003000UL),    /* sectorStartAddressPtr */
    6U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_7_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x003800UL),    /* sectorStartAddressPtr */
    7U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_8_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x004000UL),    /* sectorStartAddressPtr */
    8U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_9_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x004800UL),    /* sectorStartAddressPtr */
    9U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_10_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x005000UL),    /* sectorStartAddressPtr */
    10U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_11_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x005800UL),    /* sectorStartAddressPtr */
    11U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_12_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x006000UL),    /* sectorStartAddressPtr */
    12U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_13_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x006800UL),    /* sectorStartAddressPtr */
    13U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_14_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x007000UL),    /* sectorStartAddressPtr */
    14U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_15_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x007800UL),    /* sectorStartAddressPtr */
    15U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_16_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x008000UL),    /* sectorStartAddressPtr */
    16U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_17_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x008800UL),    /* sectorStartAddressPtr */
    17U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_18_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x009000UL),    /* sectorStartAddressPtr */
    18U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_19_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x009800UL),    /* sectorStartAddressPtr */
    19U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_20_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x00a000UL),    /* sectorStartAddressPtr */
    20U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_21_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x00a800UL),    /* sectorStartAddressPtr */
    21U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_22_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x00b000UL),    /* sectorStartAddressPtr */
    22U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_23_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x00b800UL),    /* sectorStartAddressPtr */
    23U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_24_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x00c000UL),    /* sectorStartAddressPtr */
    24U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_25_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x00c800UL),    /* sectorStartAddressPtr */
    25U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_26_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x00d000UL),    /* sectorStartAddressPtr */
    26U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_27_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x00d800UL),    /* sectorStartAddressPtr */
    27U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_28_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x00e000UL),    /* sectorStartAddressPtr */
    28U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_29_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x00e800UL),    /* sectorStartAddressPtr */
    29U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_30_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x00f000UL),    /* sectorStartAddressPtr */
    30U  /* Sector location to calculate cfgCRC */              
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) FlsSector_31_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)(D_FLASH_BASE_ADDR + 0x00f800UL),    /* sectorStartAddressPtr */
    31U  /* Sector location to calculate cfgCRC */              
};

/*  FLASH physical sectorization description */
static CONSTP2CONST(Fls_Flash_InternalSectorInfoType, FLS_VAR, FLS_APPL_CONST) FlsConfigSet_TDK_4G_aSectorList[32] =
{
    /* FLS_DATA_ARRAY_0_BLOCK_1_S000 */
    &FlsSector_0_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S001 */
    &FlsSector_1_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S002 */
    &FlsSector_2_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S003 */
    &FlsSector_3_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S004 */
    &FlsSector_4_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S005 */
    &FlsSector_5_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S006 */
    &FlsSector_6_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S007 */
    &FlsSector_7_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S008 */
    &FlsSector_8_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S009 */
    &FlsSector_9_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S010 */
    &FlsSector_10_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S011 */
    &FlsSector_11_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S012 */
    &FlsSector_12_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S013 */
    &FlsSector_13_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S014 */
    &FlsSector_14_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S015 */
    &FlsSector_15_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S016 */
    &FlsSector_16_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S017 */
    &FlsSector_17_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S018 */
    &FlsSector_18_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S019 */
    &FlsSector_19_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S020 */
    &FlsSector_20_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S021 */
    &FlsSector_21_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S022 */
    &FlsSector_22_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S023 */
    &FlsSector_23_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S024 */
    &FlsSector_24_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S025 */
    &FlsSector_25_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S026 */
    &FlsSector_26_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S027 */
    &FlsSector_27_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S028 */
    &FlsSector_28_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S029 */
    &FlsSector_29_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S030 */
    &FlsSector_30_FlsConfigSet_TDK_4G_sInternalSectorInfo
    ,    /* FLS_DATA_ARRAY_0_BLOCK_1_S031 */
    &FlsSector_31_FlsConfigSet_TDK_4G_sInternalSectorInfo
};


/* External QSPI flash parameters. */

/* paHwCh[] (FlsConfigSet) */
static CONST(Fls_HwChType, FLS_CONST) FlsConfigSet_TDK_4G_paHwCh[32] =
{
    FLS_CH_INTERN, /* (FlsSector_0) */
    FLS_CH_INTERN, /* (FlsSector_1) */
    FLS_CH_INTERN, /* (FlsSector_2) */
    FLS_CH_INTERN, /* (FlsSector_3) */
    FLS_CH_INTERN, /* (FlsSector_4) */
    FLS_CH_INTERN, /* (FlsSector_5) */
    FLS_CH_INTERN, /* (FlsSector_6) */
    FLS_CH_INTERN, /* (FlsSector_7) */
    FLS_CH_INTERN, /* (FlsSector_8) */
    FLS_CH_INTERN, /* (FlsSector_9) */
    FLS_CH_INTERN, /* (FlsSector_10) */
    FLS_CH_INTERN, /* (FlsSector_11) */
    FLS_CH_INTERN, /* (FlsSector_12) */
    FLS_CH_INTERN, /* (FlsSector_13) */
    FLS_CH_INTERN, /* (FlsSector_14) */
    FLS_CH_INTERN, /* (FlsSector_15) */
    FLS_CH_INTERN, /* (FlsSector_16) */
    FLS_CH_INTERN, /* (FlsSector_17) */
    FLS_CH_INTERN, /* (FlsSector_18) */
    FLS_CH_INTERN, /* (FlsSector_19) */
    FLS_CH_INTERN, /* (FlsSector_20) */
    FLS_CH_INTERN, /* (FlsSector_21) */
    FLS_CH_INTERN, /* (FlsSector_22) */
    FLS_CH_INTERN, /* (FlsSector_23) */
    FLS_CH_INTERN, /* (FlsSector_24) */
    FLS_CH_INTERN, /* (FlsSector_25) */
    FLS_CH_INTERN, /* (FlsSector_26) */
    FLS_CH_INTERN, /* (FlsSector_27) */
    FLS_CH_INTERN, /* (FlsSector_28) */
    FLS_CH_INTERN, /* (FlsSector_29) */
    FLS_CH_INTERN, /* (FlsSector_30) */
    FLS_CH_INTERN /* (FlsSector_31) */
};

/* paSectorHwAddress[] (FlsConfigSet) */
static CONST(Fls_AddressType, FLS_CONST) FlsConfigSet_TDK_4G_paSectorHwAddress[32] =
{
    (Fls_AddressType)0U, /* (FlsSector_0) */
    (Fls_AddressType)0U, /* (FlsSector_1) */
    (Fls_AddressType)0U, /* (FlsSector_2) */
    (Fls_AddressType)0U, /* (FlsSector_3) */
    (Fls_AddressType)0U, /* (FlsSector_4) */
    (Fls_AddressType)0U, /* (FlsSector_5) */
    (Fls_AddressType)0U, /* (FlsSector_6) */
    (Fls_AddressType)0U, /* (FlsSector_7) */
    (Fls_AddressType)0U, /* (FlsSector_8) */
    (Fls_AddressType)0U, /* (FlsSector_9) */
    (Fls_AddressType)0U, /* (FlsSector_10) */
    (Fls_AddressType)0U, /* (FlsSector_11) */
    (Fls_AddressType)0U, /* (FlsSector_12) */
    (Fls_AddressType)0U, /* (FlsSector_13) */
    (Fls_AddressType)0U, /* (FlsSector_14) */
    (Fls_AddressType)0U, /* (FlsSector_15) */
    (Fls_AddressType)0U, /* (FlsSector_16) */
    (Fls_AddressType)0U, /* (FlsSector_17) */
    (Fls_AddressType)0U, /* (FlsSector_18) */
    (Fls_AddressType)0U, /* (FlsSector_19) */
    (Fls_AddressType)0U, /* (FlsSector_20) */
    (Fls_AddressType)0U, /* (FlsSector_21) */
    (Fls_AddressType)0U, /* (FlsSector_22) */
    (Fls_AddressType)0U, /* (FlsSector_23) */
    (Fls_AddressType)0U, /* (FlsSector_24) */
    (Fls_AddressType)0U, /* (FlsSector_25) */
    (Fls_AddressType)0U, /* (FlsSector_26) */
    (Fls_AddressType)0U, /* (FlsSector_27) */
    (Fls_AddressType)0U, /* (FlsSector_28) */
    (Fls_AddressType)0U, /* (FlsSector_29) */
    (Fls_AddressType)0U, /* (FlsSector_30) */
    (Fls_AddressType)0U /* (FlsSector_31) */
};




/**
* @brief        Structure used to set function pointers notification, working mode
*/
/* Fls module initialization data (FlsConfigSet)*/
/* @violates @ref fls_TDK_4G_pbcfg_c_REF_5 Could be made static */

CONST(Fls_ConfigType, FLS_CONST) FlsConfigSet_TDK_4G=
{
    /* @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types */
    /* @violates @ref fls_TDK_4G_pbcfg_c_REF_3 Cast from pointer to pointer */
    /* @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.*/
    (Fls_AcErasePtrType)&Fls_Flash_AccessCode, /* FlsAcErase */
    /* @violates @ref fls_TDK_4G_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types */
    /* @violates @ref fls_TDK_4G_pbcfg_c_REF_3 Cast from pointer to pointer */
    /* @violates @ref fls_TDK_4G_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.*/
    (Fls_AcWritePtrType)&Fls_Flash_AccessCode, /* FlsAcWrite */
    NULL_PTR, /* FlsACCallback */  
    &Fee_JobEndNotification, /* FlsJobEndNotification */
    &Fee_JobErrorNotification, /* FlsJobErrorNotification */  
    NULL_PTR, /* FlsStartFlashAccessNotif */
    NULL_PTR, /* FlsFinishedFlashAccessNotif */
    MEMIF_MODE_SLOW, /* FlsDefaultMode */
    1048576U, /* FlsMaxReadFastMode */
    1024U, /* FlsMaxReadNormalMode */
    256U, /* FlsMaxWriteFastMode */
    8U, /* FlsMaxWriteNormalMode */
    32U, /* FlsSectorCount */
    &FlsConfigSet_TDK_4G_aFlsSectorEndAddr,                /* (*paSectorEndAddr)[]  */
    &FlsConfigSet_TDK_4G_aSectorList,                      /* (*pSectorList)[] */
    &FlsConfigSet_TDK_4G_aFlsSectorFlags,                  /* (*paSectorFlags)[] */
    &FlsConfigSet_TDK_4G_aFlsProgSize,                     /* (*paSectorProgSize)[] */
    &FlsConfigSet_TDK_4G_aFlsSectorPageSize,               /* (*paSectorPageSize)[] */    
    &FlsConfigSet_TDK_4G_aFlsSectorUnlock,                 /* (*paSectorUnlock)[] */
    &FlsConfigSet_TDK_4G_paHwCh,                           /* (*paHwCh)[] */
    &FlsConfigSet_TDK_4G_paSectorHwAddress,                /* (*paSectorHwAddress)[] */
    NULL_PTR, /* pFlsQspiCfgConfig */
    16261U /* configCrc */
};
#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* 
* @violates @ref fls_TDK_4G_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/
