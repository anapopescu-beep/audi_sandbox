/**
*   @file    Spi_PBcfg.c
*   @implements Spi_PBcfg.c_Artifact
*   @version 1.0.2
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPSPI,FLEXIO
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
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters.
*
* @section Spi_PBcfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_PBcfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_PBcfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Spi_PBcfg_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions 
* at file scope shall have internal linkage unless external linkage is required.
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Spi_PBcfg_c_REF_8
* Violates MISRA 2004 Required Rule 8.8,
* An external object or function shall be declared in one and only one file.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Spi.h"
#include "Reg_eSys_LPspi.h"
#include "Reg_eSys_FlexIOSPI.h"

#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPI_MODULE_ID_PBCFG_C                        83
#define SPI_VENDOR_ID_PBCFG_C                        43
#define SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
#define SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C         2
/*
* @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/

#define SPI_AR_RELEASE_REVISION_VERSION_PBCFG_C      2
#define SPI_SW_MAJOR_VERSION_PBCFG_C                 1
#define SPI_SW_MINOR_VERSION_PBCFG_C                 0
#define SPI_SW_PATCH_VERSION_PBCFG_C                 2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/* Check if current file and SPI header file are of the same vendor */
#if (SPI_VENDOR_ID_PBCFG_C != SPI_VENDOR_ID)
    #error "Spi_PBCfg.c and Spi.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_PBCFG_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_PBCFG_C != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_PBCFG_C != SPI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif

/* Check if current file and Reg_eSys_LPspi.h file are of the same vendor */
#if (SPI_VENDOR_ID_PBCFG_C != REG_ESYS_LPSPI_VENDOR_ID_REGFLEX)
    #error "Spi_PBCfg.c and Reg_eSys_LPspi.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_LPspi.h file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != REG_ESYS_LPSPI_AR_RELEASE_MAJOR_VERSION_REGFLEX) || \
     (SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C    != REG_ESYS_LPSPI_AR_RELEASE_MINOR_VERSION_REGFLEX) || \
     (SPI_AR_RELEASE_REVISION_VERSION_PBCFG_C != REG_ESYS_LPSPI_AR_RELEASE_REVISION_VERSION_REGFLEX))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Reg_eSys_LPspi.h are different"
#endif
/* Check if current file and Reg_eSys_LPspi.h file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_PBCFG_C != REG_ESYS_LPSPI_SW_MAJOR_VERSION_REGFLEX) || \
     (SPI_SW_MINOR_VERSION_PBCFG_C != REG_ESYS_LPSPI_SW_MINOR_VERSION_REGFLEX) || \
     (SPI_SW_PATCH_VERSION_PBCFG_C != REG_ESYS_LPSPI_SW_PATCH_VERSION_REGFLEX))
    #error "Software Version Numbers of Spi_PBCfg.c and Reg_eSys_LPspi.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Check if current file and Dem.h file are of the same Autosar version */
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MAJOR_VERSION) || \
        (SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Spi_PBCfg.c and Dem.h are different"
    #endif
    #endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
#endif  


/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"






#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
    /*
    * @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
    * signifiance and case sensitivity are supported for external identifiers.
    */    
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    /*
    * @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
    * signifiance and case sensitivity are supported for external identifiers.
    */
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */

/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"



/*  Buffers Descriptors for EB Channels (if any) */
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_WDG_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_WDG_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_INIT_HW_CTRL_2_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_INIT_HW_CTRL_2_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_INIT_HW_CTRL_1_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_INIT_HW_CTRL_1_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_INIT_HW_CTRL_0_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_INIT_HW_CTRL_0_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_INIT_BUS_CTRL_0_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_INIT_BUS_CTRL_0_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_INIT_WK_CTRL_0_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_INIT_WK_CTRL_0_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_INIT_WK_CTRL_1_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_INIT_WK_CTRL_1_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_INIT_TIMER_CTRL_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_INIT_TIMER_CTRL_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_INIT_PWM_CTRL_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_INIT_PWM_CTRL_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_INIT_SBC_NORMAL_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_INIT_SBC_NORMAL_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_INIT_GPIO_CTRL_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_INIT_GPIO_CTRL_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_SD_WK_STAT_0_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_SD_WK_STAT_0_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_SD_WK_STAT_1_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_SD_WK_STAT_1_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_SD_BUS_CTRL_0_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_SD_BUS_CTRL_0_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_SD_M_S_CTRL_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_SD_M_S_CTRL_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_RST_M_S_CTRL_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_RST_M_S_CTRL_Ch[2], 4)
/* Allocate Buffers for IB Channels (if any) */
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBSbc_CLEAR_STATE_Ch[2], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBSbc_CLEAR_STATE_Ch[2], 4)


#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))  
    /*
    * @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
    * signifiance and case sensitivity are supported for external identifiers.
    */    
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    /*
    * @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
    * signifiance and case sensitivity are supported for external identifiers.
    */
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */

/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"



/*  Buffers Descriptors for IB Channels (if any) */
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_WDG_Ch =
{
    BufferTX_PBSbc_WDG_Ch,
    BufferRX_PBSbc_WDG_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_INIT_HW_CTRL_2_Ch =
{
    BufferTX_PBSbc_INIT_HW_CTRL_2_Ch,
    BufferRX_PBSbc_INIT_HW_CTRL_2_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_INIT_HW_CTRL_1_Ch =
{
    BufferTX_PBSbc_INIT_HW_CTRL_1_Ch,
    BufferRX_PBSbc_INIT_HW_CTRL_1_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_INIT_HW_CTRL_0_Ch =
{
    BufferTX_PBSbc_INIT_HW_CTRL_0_Ch,
    BufferRX_PBSbc_INIT_HW_CTRL_0_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_INIT_BUS_CTRL_0_Ch =
{
    BufferTX_PBSbc_INIT_BUS_CTRL_0_Ch,
    BufferRX_PBSbc_INIT_BUS_CTRL_0_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_INIT_WK_CTRL_0_Ch =
{
    BufferTX_PBSbc_INIT_WK_CTRL_0_Ch,
    BufferRX_PBSbc_INIT_WK_CTRL_0_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_INIT_WK_CTRL_1_Ch =
{
    BufferTX_PBSbc_INIT_WK_CTRL_1_Ch,
    BufferRX_PBSbc_INIT_WK_CTRL_1_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_INIT_TIMER_CTRL_Ch =
{
    BufferTX_PBSbc_INIT_TIMER_CTRL_Ch,
    BufferRX_PBSbc_INIT_TIMER_CTRL_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_INIT_PWM_CTRL_Ch =
{
    BufferTX_PBSbc_INIT_PWM_CTRL_Ch,
    BufferRX_PBSbc_INIT_PWM_CTRL_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_INIT_SBC_NORMAL_Ch =
{
    BufferTX_PBSbc_INIT_SBC_NORMAL_Ch,
    BufferRX_PBSbc_INIT_SBC_NORMAL_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_INIT_GPIO_CTRL_Ch =
{
    BufferTX_PBSbc_INIT_GPIO_CTRL_Ch,
    BufferRX_PBSbc_INIT_GPIO_CTRL_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_SD_WK_STAT_0_Ch =
{
    BufferTX_PBSbc_SD_WK_STAT_0_Ch,
    BufferRX_PBSbc_SD_WK_STAT_0_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_SD_WK_STAT_1_Ch =
{
    BufferTX_PBSbc_SD_WK_STAT_1_Ch,
    BufferRX_PBSbc_SD_WK_STAT_1_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_SD_BUS_CTRL_0_Ch =
{
    BufferTX_PBSbc_SD_BUS_CTRL_0_Ch,
    BufferRX_PBSbc_SD_BUS_CTRL_0_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_SD_M_S_CTRL_Ch =
{
    BufferTX_PBSbc_SD_M_S_CTRL_Ch,
    BufferRX_PBSbc_SD_M_S_CTRL_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_RST_M_S_CTRL_Ch =
{
    BufferTX_PBSbc_RST_M_S_CTRL_Ch,
    BufferRX_PBSbc_RST_M_S_CTRL_Ch
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBSbc_CLEAR_STATE_Ch =
{
    BufferTX_PBSbc_CLEAR_STATE_Ch,
    BufferRX_PBSbc_CLEAR_STATE_Ch
};


    



    
    
        



    
        

                                    
/* LPspiDeviceAttributesConfig_PB0 Device Attribute Configuration of Spi*/
static VAR(Spi_Ipw_LPspiDeviceAttributesConfigType, SPI_VAR) LPspiDeviceAttributesConfig_PB0[1] =
{
                
        {
                                                                                /* Sbc_Device */
            
                
            (uint32)(LPSPI_TCR_CPOL_LOW_U32 | /* Clock Polarity (Idle State) */
                            LPSPI_TCR_CPHA_LEADING_U32 | /* Clock Phase */  
            LPSPI_TCR_PRESCALE_1_U32 /* Baudrate: Should=2000000.0, Is=2000000, Error=0.0% */
          |  LPSPI_TCR_BYSW_DIS_U32 
          | 
                                                (uint32)(LPSPI_TCR_PCS0_EN_U32 | /* Chip Select Pin Via Peripheral Engine*/
                                    LPSPI_TCR_CONT_DIS_U32)/* Disable continuous chip select */
                                                            
) & LPSPI_TCR_RESERVED_MASK_U32,
            ( ((uint32)(3) << 24u) | /* TimeClk2Cs: Should=1000ns, Is=1000, Error=0.0% */
            ((uint32)(3) << 16u) | /* TimeCs2Clk: Should=1000ns, Is=1000, Error=0.0% */
            ((uint32)(7) << 8u) | /* TimeCs2Cs: Should=2000ns, Is=2000, Error=0.0% */
            ((uint32)(0))
            ),

/* CFG1 register configuration */
        (uint32)0u  /* Chip select polarity */
     | LPSPI_CFGR1_PINCFG_SIN_INPUT_SOUT_OUTPUT_U32 | LPSPI_CFGR1_MATCFG_DIS_U32 | LPSPI_CFGR1_MASTER_EN_U32


        }
                

};

        
    


#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define   SPI_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include directives should only be preceded by other preprocessor
*        directives or comments
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent
*        the contents of a header file being included more than once.
*/
 #include "Spi_MemMap.h"


    

/* DeviceAttributesConfig_PB0 Device Attribute Configuration of Spi*/
static P2CONST(Spi_Ipw_LPspiDeviceAttributesConfigType, SPI_VAR, SPI_APPL_CONST) LPspiDeviceAttributesConfigArray_PB0[1] =
{
                &LPspiDeviceAttributesConfig_PB0[0]        
};

    

/* DeviceAttributesConfig_PB0 Device Attribute Configuration of Spi*/
static P2CONST(Spi_Ipw_FlexIODeviceAttributesConfigType, SPI_VAR, SPI_APPL_CONST) FlexIODeviceAttributesConfigArray_PB0[1] =
{
                NULL_PTR
};





/* DSpiDeviceAttributesConfig_PB0 Device Attribute Configuration of Spi*/
static VAR(Spi_Ipw_DeviceAttributesConfigType, SPI_VAR) SpiExternalDeviceAttrsPB0[1] =
{
        
        
        {
        &LPspiDeviceAttributesConfigArray_PB0[SPI_Sbc_Device],
        NULL_PTR
        }
};
 
 #define   SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
 /*
* @violates @ref Spi_PBcfg_c_REF_1 #include directives should only be preceded by other preprocessor
*        directives or comments
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent
*        the contents of a header file being included more than once.
*/
 #include "Spi_MemMap.h"
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"



/* SpiChannelConfig_PB0 Channel Configuration of Spi*/
static CONST(Spi_ChannelConfigType, SPI_CONST) SpiChannelConfig_PB0[17] =
{
    {
        /* Sbc_WDG_Ch*/
        IB,
        (uint32)6019U,

        2U,
        &Buffer_PBSbc_WDG_Ch,
        &Spi_aSpiChannelState[0]
    },

    {
        /* Sbc_INIT_HW_CTRL_2_Ch*/
        IB,
        (uint32)143U,

        2U,
        &Buffer_PBSbc_INIT_HW_CTRL_2_Ch,
        &Spi_aSpiChannelState[1]
    },

    {
        /* Sbc_INIT_HW_CTRL_1_Ch*/
        IB,
        (uint32)142U,

        2U,
        &Buffer_PBSbc_INIT_HW_CTRL_1_Ch,
        &Spi_aSpiChannelState[2]
    },

    {
        /* Sbc_INIT_HW_CTRL_0_Ch*/
        IB,
        (uint32)130U,

        2U,
        &Buffer_PBSbc_INIT_HW_CTRL_0_Ch,
        &Spi_aSpiChannelState[3]
    },

    {
        /* Sbc_INIT_BUS_CTRL_0_Ch*/
        IB,
        (uint32)900U,

        2U,
        &Buffer_PBSbc_INIT_BUS_CTRL_0_Ch,
        &Spi_aSpiChannelState[4]
    },

    {
        /* Sbc_INIT_WK_CTRL_0_Ch*/
        IB,
        (uint32)134U,

        2U,
        &Buffer_PBSbc_INIT_WK_CTRL_0_Ch,
        &Spi_aSpiChannelState[5]
    },

    {
        /* Sbc_INIT_WK_CTRL_1_Ch*/
        IB,
        (uint32)8327U,

        2U,
        &Buffer_PBSbc_INIT_WK_CTRL_1_Ch,
        &Spi_aSpiChannelState[6]
    },

    {
        /* Sbc_INIT_TIMER_CTRL_Ch*/
        IB,
        (uint32)140U,

        2U,
        &Buffer_PBSbc_INIT_TIMER_CTRL_Ch,
        &Spi_aSpiChannelState[7]
    },

    {
        /* Sbc_INIT_PWM_CTRL_Ch*/
        IB,
        (uint32)152U,

        2U,
        &Buffer_PBSbc_INIT_PWM_CTRL_Ch,
        &Spi_aSpiChannelState[8]
    },

    {
        /* Sbc_INIT_SBC_NORMAL_Ch*/
        IB,
        (uint32)2177U,

        2U,
        &Buffer_PBSbc_INIT_SBC_NORMAL_Ch,
        &Spi_aSpiChannelState[9]
    },

    {
        /* Sbc_INIT_GPIO_CTRL_Ch*/
        IB,
        (uint32)1175U,

        2U,
        &Buffer_PBSbc_INIT_GPIO_CTRL_Ch,
        &Spi_aSpiChannelState[10]
    },

    {
        /* Sbc_SD_WK_STAT_0_Ch*/
        IB,
        (uint32)198U,

        2U,
        &Buffer_PBSbc_SD_WK_STAT_0_Ch,
        &Spi_aSpiChannelState[11]
    },

    {
        /* Sbc_SD_WK_STAT_1_Ch*/
        IB,
        (uint32)199U,

        2U,
        &Buffer_PBSbc_SD_WK_STAT_1_Ch,
        &Spi_aSpiChannelState[12]
    },

    {
        /* Sbc_SD_BUS_CTRL_0_Ch*/
        IB,
        (uint32)388U,

        2U,
        &Buffer_PBSbc_SD_BUS_CTRL_0_Ch,
        &Spi_aSpiChannelState[13]
    },

    {
        /* Sbc_SD_M_S_CTRL_Ch*/
        IB,
        (uint32)16769U,

        2U,
        &Buffer_PBSbc_SD_M_S_CTRL_Ch,
        &Spi_aSpiChannelState[14]
    },

    {
        /* Sbc_RST_M_S_CTRL_Ch*/
        IB,
        (uint32)49537U,

        2U,
        &Buffer_PBSbc_RST_M_S_CTRL_Ch,
        &Spi_aSpiChannelState[15]
    },

    {
        /* Sbc_CLEAR_STATE_Ch*/
        IB,
        (uint32)38275U,

        2U,
        &Buffer_PBSbc_CLEAR_STATE_Ch,
        &Spi_aSpiChannelState[16]
    }


};



/* Channel to Job Assignment */

static CONST(Spi_ChannelType, SPI_CONST) Sbc_WDG_Job_ChannelAssignment_PB[1] = {SpiConf_SpiChannel_Sbc_WDG_Ch};
static CONST(Spi_ChannelType, SPI_CONST) Sbc_INIT_Job_ChannelAssignment_PB[10] = {SpiConf_SpiChannel_Sbc_INIT_GPIO_CTRL_Ch,SpiConf_SpiChannel_Sbc_INIT_WK_CTRL_1_Ch,SpiConf_SpiChannel_Sbc_INIT_HW_CTRL_2_Ch,SpiConf_SpiChannel_Sbc_INIT_HW_CTRL_1_Ch,SpiConf_SpiChannel_Sbc_INIT_HW_CTRL_0_Ch,SpiConf_SpiChannel_Sbc_INIT_BUS_CTRL_0_Ch,SpiConf_SpiChannel_Sbc_INIT_WK_CTRL_0_Ch,SpiConf_SpiChannel_Sbc_INIT_TIMER_CTRL_Ch,SpiConf_SpiChannel_Sbc_INIT_PWM_CTRL_Ch,SpiConf_SpiChannel_Sbc_INIT_SBC_NORMAL_Ch};
static CONST(Spi_ChannelType, SPI_CONST) Sbc_SHUTDOWN_Job_ChannelAssignment_PB[4] = {SpiConf_SpiChannel_Sbc_SD_WK_STAT_0_Ch,SpiConf_SpiChannel_Sbc_SD_WK_STAT_1_Ch,SpiConf_SpiChannel_Sbc_SD_BUS_CTRL_0_Ch,SpiConf_SpiChannel_Sbc_SD_M_S_CTRL_Ch};
static CONST(Spi_ChannelType, SPI_CONST) Sbc_RESET_Job_ChannelAssignment_PB[1] = {SpiConf_SpiChannel_Sbc_RST_M_S_CTRL_Ch};
static CONST(Spi_ChannelType, SPI_CONST) Sbc_CLEAR_STATE_Job_ChannelAssignment_PB[1] = {SpiConf_SpiChannel_Sbc_CLEAR_STATE_Ch};



/* SpiJobConfig_PB0 Job Configuration of Spi*/
static CONST(Spi_JobConfigType, SPI_CONST) SpiJobConfig_PB0[5] =
{
    {


        /* Sbc_WDG_Job */
        (Spi_ChannelType)1u,
        Sbc_WDG_Job_ChannelAssignment_PB, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        &Spi_aSpiJobState[0], /* JobState instance */
        CSIB0, /* HWUnit index */
        LPSPI_0_OFFSET, /* LPspi device HW unit offset */
        /* External Device Settings */
        
            SPI_Sbc_Device, /* External Device */
        &SpiExternalDeviceAttrsPB0[SPI_Sbc_Device]
        
        
    },

    {


        /* Sbc_INIT_Job */
        (Spi_ChannelType)10u,
        Sbc_INIT_Job_ChannelAssignment_PB, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        &Spi_aSpiJobState[1], /* JobState instance */
        CSIB0, /* HWUnit index */
        LPSPI_0_OFFSET, /* LPspi device HW unit offset */
        /* External Device Settings */
        
            SPI_Sbc_Device, /* External Device */
        &SpiExternalDeviceAttrsPB0[SPI_Sbc_Device]
        
        
    },

    {


        /* Sbc_SHUTDOWN_Job */
        (Spi_ChannelType)4u,
        Sbc_SHUTDOWN_Job_ChannelAssignment_PB, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        &Spi_aSpiJobState[2], /* JobState instance */
        CSIB0, /* HWUnit index */
        LPSPI_0_OFFSET, /* LPspi device HW unit offset */
        /* External Device Settings */
        
            SPI_Sbc_Device, /* External Device */
        &SpiExternalDeviceAttrsPB0[SPI_Sbc_Device]
        
        
    },

    {


        /* Sbc_RESET_Job */
        (Spi_ChannelType)1u,
        Sbc_RESET_Job_ChannelAssignment_PB, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        &Spi_aSpiJobState[3], /* JobState instance */
        CSIB0, /* HWUnit index */
        LPSPI_0_OFFSET, /* LPspi device HW unit offset */
        /* External Device Settings */
        
            SPI_Sbc_Device, /* External Device */
        &SpiExternalDeviceAttrsPB0[SPI_Sbc_Device]
        
        
    },

    {


        /* Sbc_CLEAR_STATE_Job */
        (Spi_ChannelType)1u,
        Sbc_CLEAR_STATE_Job_ChannelAssignment_PB, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        &Spi_aSpiJobState[4], /* JobState instance */
        CSIB0, /* HWUnit index */
        LPSPI_0_OFFSET, /* LPspi device HW unit offset */
        /* External Device Settings */
        
            SPI_Sbc_Device, /* External Device */
        &SpiExternalDeviceAttrsPB0[SPI_Sbc_Device]
        
        
    }


};



/* Job to Sequence Assignment */
static CONST(Spi_JobType, SPI_CONST) Sbc_WDG_Seq_JobAssignment_PB[1] = {SpiConf_SpiJob_Sbc_WDG_Job};
static CONST(Spi_JobType, SPI_CONST) Sbc_INIT_Seq_JobAssignment_PB[1] = {SpiConf_SpiJob_Sbc_INIT_Job};
static CONST(Spi_JobType, SPI_CONST) Sbc_SHUTDOWN_Seq_JobAssignment_PB[1] = {SpiConf_SpiJob_Sbc_SHUTDOWN_Job};
static CONST(Spi_JobType, SPI_CONST) Sbc_RESET_Seq_JobAssignment_PB[1] = {SpiConf_SpiJob_Sbc_RESET_Job};
static CONST(Spi_JobType, SPI_CONST) Sbc_CLEAR_STATE_Seq_JobAssignment_PB[1] = {SpiConf_SpiJob_Sbc_CLEAR_STATE_Job};



/* SpiSequenceConfig_PB0 Sequence Configuration of Spi*/
static CONST(Spi_SequenceConfigType, SPI_CONST) SpiSequenceConfig_PB0[5] =
{
    {  /* Sbc_WDG_Seq */
        LPSPI, /* HW type of sequences */ 
        (Spi_JobType)1u,
        Sbc_WDG_Seq_JobAssignment_PB, /* List of Jobs */
        NULL_PTR, /* End Notification */
                (uint8)FALSE /* Interruptible */
    },

    {  /* Sbc_INIT_Seq */
        LPSPI, /* HW type of sequences */ 
        (Spi_JobType)1u,
        Sbc_INIT_Seq_JobAssignment_PB, /* List of Jobs */
        NULL_PTR, /* End Notification */
                (uint8)FALSE /* Interruptible */
    },

    {  /* Sbc_SHUTDOWN_Seq */
        LPSPI, /* HW type of sequences */ 
        (Spi_JobType)1u,
        Sbc_SHUTDOWN_Seq_JobAssignment_PB, /* List of Jobs */
        NULL_PTR, /* End Notification */
                (uint8)FALSE /* Interruptible */
    },

    {  /* Sbc_RESET_Seq */
        LPSPI, /* HW type of sequences */ 
        (Spi_JobType)1u,
        Sbc_RESET_Seq_JobAssignment_PB, /* List of Jobs */
        NULL_PTR, /* End Notification */
                (uint8)FALSE /* Interruptible */
    },

    {  /* Sbc_CLEAR_STATE_Seq */
        LPSPI, /* HW type of sequences */ 
        (Spi_JobType)1u,
        Sbc_CLEAR_STATE_Seq_JobAssignment_PB, /* List of Jobs */
        NULL_PTR, /* End Notification */
                (uint8)FALSE /* Interruptible */
    }


};







    
    
        





    
/* LPspiChannelAttributesConfig_PB0 Channel Attribute Configuration of Spi*/
/*
* @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
static CONST(Spi_Ipw_LPspiChannelAttributesConfigType, SPI_CONST) LPspiChannelAttributesConfig_PB0[17] =
{
{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}
,

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_LSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(15.0))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16}



};














    
    
        



/* SpiAttributesConfig_PB0 Attribute Configuration of MODULE-CONFIGURATION */
static CONST(Spi_AttributesConfigType, SPI_CONST) SpiAttributesConfig_PB0 = {
    LPspiChannelAttributesConfig_PB0,
    NULL_PTR,
    LPspiDeviceAttributesConfigArray_PB0,
    FlexIODeviceAttributesConfigArray_PB0
};



/* Array of LPspi Unit configurations */
static CONST(Spi_HWUnitConfigType, SPI_CONST) HWUnitConfig_PB[SPI_MAX_HWUNIT] =
{




    { LPSPI_0_OFFSET,  LPSPI, (uint8)0u, SPI_MASTER , SPI_PHYUNIT_SYNC_U32, 0u, 0u, 0u, 0u }
};


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/




/* @violates @ref Spi_PBcfg_c_REF_4 MISRA 2004 Required Rule 8.10, external linkage ... */
/* MODULE-CONFIGURATION Configuration */
CONST(Spi_ConfigType, SPI_CONST) Spi_PBCfgVariantPredefined =
{
    1u,
    16u,
    4u,
    4u,
    SpiChannelConfig_PB0,
    SpiJobConfig_PB0,
    SpiSequenceConfig_PB0,
    &SpiAttributesConfig_PB0,
    HWUnitConfig_PB,
    /**
    * @brief   DEM error parameters
    */
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    { (uint32)STD_OFF, (uint32)0U}/* SPI_E_HARDWARE_ERROR parameters*/ 
#endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
};


/*
* @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

