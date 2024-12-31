/**   
*   @file    Spi_PBcfg.c
*   @implements Spi_PBcfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup SPI_DRIVER_CONFIGURATION Spi Driver Configuration
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LPSPI
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
*
*   (c) Copyright 2020-2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif



/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Spi.h"
#include "Spi_Ipw_TDK_4G_PBcfg.h"

#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_TDK_4G_MODULE_ID_PBCFG_C                        83
#define SPI_TDK_4G_VENDOR_ID_PBCFG_C                        43
#define SPI_TDK_4G_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
#define SPI_TDK_4G_AR_RELEASE_MINOR_VERSION_PBCFG_C         4
#define SPI_TDK_4G_AR_RELEASE_REVISION_VERSION_PBCFG_C      0
#define SPI_TDK_4G_SW_MAJOR_VERSION_PBCFG_C                 1
#define SPI_TDK_4G_SW_MINOR_VERSION_PBCFG_C                 0
#define SPI_TDK_4G_SW_PATCH_VERSION_PBCFG_C                 1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and SPI header file are of the same vendor */
#if (SPI_TDK_4G_VENDOR_ID_PBCFG_C != SPI_VENDOR_ID)
    #error "Spi_PBCfg.c and Spi.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_TDK_4G_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_TDK_4G_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_TDK_4G_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_TDK_4G_SW_MAJOR_VERSION_PBCFG_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_TDK_4G_SW_MINOR_VERSION_PBCFG_C != SPI_SW_MINOR_VERSION) || \
     (SPI_TDK_4G_SW_PATCH_VERSION_PBCFG_C != SPI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif

/* Check if current file and SPI header file are of the same vendor */
#if (SPI_TDK_4G_VENDOR_ID_PBCFG_C != SPI_IPW_VENDOR_ID_TDK_4G_PBCFG_H)
    #error "Spi_PBCfg.c and Spi_Ipw_PBCfg.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_TDK_4G_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_IPW_AR_RELEASE_MAJOR_VERSION_TDK_4G_PBCFG_H) || \
     (SPI_TDK_4G_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_IPW_AR_RELEASE_MINOR_VERSION_TDK_4G_PBCFG_H) || \
     (SPI_TDK_4G_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_IPW_AR_RELEASE_REVISION_VERSION_TDK_4G_PBCFG_H ))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Spi_Ipw_PBCfg.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_TDK_4G_SW_MAJOR_VERSION_PBCFG_C != SPI_IPW_SW_MAJOR_VERSION_TDK_4G_PBCFG_H) || \
     (SPI_TDK_4G_SW_MINOR_VERSION_PBCFG_C != SPI_IPW_SW_MINOR_VERSION_TDK_4G_PBCFG_H) || \
     (SPI_TDK_4G_SW_PATCH_VERSION_PBCFG_C != SPI_IPW_SW_PATCH_VERSION_TDK_4G_PBCFG_H))
    #error "Software Version Numbers of Spi_PBCfg.c and Spi_Ipw_PBCfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/* Check if current file and Dem.h file are of the same Autosar version */
#if ((SPI_TDK_4G_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_TDK_4G_AR_RELEASE_MINOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Dem.h are different"
#endif
#endif
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
#include "Spi_MemMap.h"

/* List Of Notification Functions */
/* Job start Notifications */

/* Job End Notifications */

/* Sequence End Notifications */


#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)))
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) ||
        (SPI_LEVEL_DELIVERED == SPI_LEVEL2))) */
#include "Spi_MemMap.h"

/* Buffers Descriptors for EB Channels and Allocate Buffers for IB Channels */
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_WDG_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_WDG_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_WDG_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_WDG_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_HW_CTRL_2_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_HW_CTRL_2_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_HW_CTRL_2_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_HW_CTRL_2_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_HW_CTRL_1_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_HW_CTRL_1_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_HW_CTRL_1_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_HW_CTRL_1_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_HW_CTRL_0_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_HW_CTRL_0_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_HW_CTRL_0_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_HW_CTRL_0_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_BUS_CTRL_0_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_BUS_CTRL_0_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_BUS_CTRL_0_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_BUS_CTRL_0_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_WK_CTRL_0_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_WK_CTRL_0_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_WK_CTRL_0_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_WK_CTRL_0_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_WK_CTRL_1_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_WK_CTRL_1_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_WK_CTRL_1_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_WK_CTRL_1_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_TIMER_CTRL_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_TIMER_CTRL_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_TIMER_CTRL_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_TIMER_CTRL_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_PWM_CTRL_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_PWM_CTRL_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_PWM_CTRL_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_PWM_CTRL_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_SBC_NORMAL_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_SBC_NORMAL_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_SBC_NORMAL_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_SBC_NORMAL_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_GPIO_CTRL_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_GPIO_CTRL_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_INIT_GPIO_CTRL_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_INIT_GPIO_CTRL_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_SD_WK_STAT_0_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_SD_WK_STAT_0_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_SD_WK_STAT_0_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_SD_WK_STAT_0_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_SD_WK_STAT_1_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_SD_WK_STAT_1_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_SD_WK_STAT_1_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_SD_WK_STAT_1_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_SD_BUS_CTRL_0_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_SD_BUS_CTRL_0_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_SD_BUS_CTRL_0_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_SD_BUS_CTRL_0_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_SD_M_S_CTRL_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_SD_M_S_CTRL_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_SD_M_S_CTRL_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_SD_M_S_CTRL_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_STN_M_S_CTRL_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_STN_M_S_CTRL_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_STN_M_S_CTRL_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_STN_M_S_CTRL_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_STN_BUS_CTRL_0_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_STN_BUS_CTRL_0_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_STN_BUS_CTRL_0_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_STN_BUS_CTRL_0_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_STLP_BUS_CTRL_0_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_STLP_BUS_CTRL_0_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_STLP_BUS_CTRL_0_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_STLP_BUS_CTRL_0_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_STLP_HW_CTRL_2_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_STLP_HW_CTRL_2_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_STLP_HW_CTRL_2_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_STLP_HW_CTRL_2_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_STLP_M_S_CTRL_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_STLP_M_S_CTRL_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_STLP_M_S_CTRL_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_STLP_M_S_CTRL_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_RST_M_S_CTRL_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_RST_M_S_CTRL_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_RST_M_S_CTRL_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_RST_M_S_CTRL_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_CLEAR_STATE_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_CLEAR_STATE_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_CLEAR_STATE_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_CLEAR_STATE_Ch[2], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_READ_AX_Ch[4], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_READ_AX_Ch[4], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_READ_AX_Ch[4], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_READ_AX_Ch[4], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_READ_AY_Ch[4], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_READ_AY_Ch[4], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_READ_AY_Ch[4], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_READ_AY_Ch[4], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_READ_AZ_Ch[4], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_READ_AZ_Ch[4], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_READ_AZ_Ch[4], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_READ_AZ_Ch[4], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_INIT_Ch[4], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_INIT_Ch[4], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_INIT_Ch[4], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_INIT_Ch[4], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_READ_TEMPERATURE_Ch[4], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_READ_TEMPERATURE_Ch[4], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_READ_TEMPERATURE_Ch[4], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_READ_TEMPERATURE_Ch[4], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Dummy_Ch[4], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Dummy_Ch[4], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Dummy_Ch[4], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Dummy_Ch[4], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Unlock_1_Ch[4], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Unlock_1_Ch[4], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Unlock_1_Ch[4], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Unlock_1_Ch[4], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Unlock_2_Ch[4], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Unlock_2_Ch[4], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Unlock_2_Ch[4], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Unlock_2_Ch[4], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Unlock_3_Ch[4], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Unlock_3_Ch[4], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Unlock_3_Ch[4], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Unlock_3_Ch[4], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Unlock_4_Ch[4], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Unlock_4_Ch[4], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Unlock_4_Ch[4], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Unlock_4_Ch[4], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Unlock_5_Ch[4], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Unlock_5_Ch[4], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Unlock_5_Ch[4], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Unlock_5_Ch[4], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Unlock_6_Ch[4], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Unlock_6_Ch[4], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Acc_Unlock_6_Ch[4], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Acc_Unlock_6_Ch[4], 4)
#endif
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_Wdg_Autotest_Ch[2], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_Wdg_Autotest_Ch[2], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_TDK_4G_Sbc_Wdg_Autotest_Ch[2], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_TDK_4G_Sbc_Wdg_Autotest_Ch[2], 4)
#endif


#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)))
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) ||
        (SPI_LEVEL_DELIVERED == SPI_LEVEL2))) */
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

/* Buffers Descriptors for IB Channels */
    /*  Buffers Descriptors for IB Channels (if any) */
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_WDG_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_WDG_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_WDG_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_INIT_HW_CTRL_2_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_INIT_HW_CTRL_2_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_INIT_HW_CTRL_2_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_INIT_HW_CTRL_1_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_INIT_HW_CTRL_1_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_INIT_HW_CTRL_1_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_INIT_HW_CTRL_0_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_INIT_HW_CTRL_0_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_INIT_HW_CTRL_0_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_INIT_BUS_CTRL_0_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_INIT_BUS_CTRL_0_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_INIT_BUS_CTRL_0_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_INIT_WK_CTRL_0_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_INIT_WK_CTRL_0_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_INIT_WK_CTRL_0_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_INIT_WK_CTRL_1_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_INIT_WK_CTRL_1_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_INIT_WK_CTRL_1_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_INIT_TIMER_CTRL_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_INIT_TIMER_CTRL_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_INIT_TIMER_CTRL_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_INIT_PWM_CTRL_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_INIT_PWM_CTRL_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_INIT_PWM_CTRL_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_INIT_SBC_NORMAL_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_INIT_SBC_NORMAL_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_INIT_SBC_NORMAL_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_INIT_GPIO_CTRL_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_INIT_GPIO_CTRL_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_INIT_GPIO_CTRL_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_SD_WK_STAT_0_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_SD_WK_STAT_0_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_SD_WK_STAT_0_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_SD_WK_STAT_1_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_SD_WK_STAT_1_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_SD_WK_STAT_1_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_SD_BUS_CTRL_0_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_SD_BUS_CTRL_0_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_SD_BUS_CTRL_0_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_SD_M_S_CTRL_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_SD_M_S_CTRL_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_SD_M_S_CTRL_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_STN_M_S_CTRL_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_STN_M_S_CTRL_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_STN_M_S_CTRL_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_STN_BUS_CTRL_0_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_STN_BUS_CTRL_0_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_STN_BUS_CTRL_0_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_STLP_BUS_CTRL_0_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_STLP_BUS_CTRL_0_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_STLP_BUS_CTRL_0_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_STLP_HW_CTRL_2_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_STLP_HW_CTRL_2_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_STLP_HW_CTRL_2_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_STLP_M_S_CTRL_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_STLP_M_S_CTRL_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_STLP_M_S_CTRL_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_RST_M_S_CTRL_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_RST_M_S_CTRL_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_RST_M_S_CTRL_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_CLEAR_STATE_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_CLEAR_STATE_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_CLEAR_STATE_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Acc_READ_AX_Ch =
{
    Spi_BufferTX_TDK_4G_Acc_READ_AX_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Acc_READ_AX_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Acc_READ_AY_Ch =
{
    Spi_BufferTX_TDK_4G_Acc_READ_AY_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Acc_READ_AY_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Acc_READ_AZ_Ch =
{
    Spi_BufferTX_TDK_4G_Acc_READ_AZ_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Acc_READ_AZ_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Acc_INIT_Ch =
{
    Spi_BufferTX_TDK_4G_Acc_INIT_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Acc_INIT_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Acc_READ_TEMPERATURE_Ch =
{
    Spi_BufferTX_TDK_4G_Acc_READ_TEMPERATURE_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Acc_READ_TEMPERATURE_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Acc_Dummy_Ch =
{
    Spi_BufferTX_TDK_4G_Acc_Dummy_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Acc_Dummy_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Acc_Unlock_1_Ch =
{
    Spi_BufferTX_TDK_4G_Acc_Unlock_1_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Acc_Unlock_1_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Acc_Unlock_2_Ch =
{
    Spi_BufferTX_TDK_4G_Acc_Unlock_2_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Acc_Unlock_2_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Acc_Unlock_3_Ch =
{
    Spi_BufferTX_TDK_4G_Acc_Unlock_3_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Acc_Unlock_3_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Acc_Unlock_4_Ch =
{
    Spi_BufferTX_TDK_4G_Acc_Unlock_4_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Acc_Unlock_4_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Acc_Unlock_5_Ch =
{
    Spi_BufferTX_TDK_4G_Acc_Unlock_5_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Acc_Unlock_5_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Acc_Unlock_6_Ch =
{
    Spi_BufferTX_TDK_4G_Acc_Unlock_6_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Acc_Unlock_6_Ch   /* pBufferRX */
};
static Spi_BufferDescriptorType Spi_Buffer_TDK_4G_Sbc_Wdg_Autotest_Ch =
{
    Spi_BufferTX_TDK_4G_Sbc_Wdg_Autotest_Ch,  /* pBufferTX */
    Spi_BufferRX_TDK_4G_Sbc_Wdg_Autotest_Ch   /* pBufferRX */
};



#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/* Channel Configuration */
/* Channel Configuration of Sbc_WDG_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_WDG_Ch_TDK_4G =
{
        /* Sbc_WDG_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)38275U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_WDG_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[0U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_INIT_HW_CTRL_2_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_INIT_HW_CTRL_2_Ch_TDK_4G =
{
        /* Sbc_INIT_HW_CTRL_2_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)143U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_INIT_HW_CTRL_2_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[1U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_INIT_HW_CTRL_1_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_INIT_HW_CTRL_1_Ch_TDK_4G =
{
        /* Sbc_INIT_HW_CTRL_1_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)142U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_INIT_HW_CTRL_1_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[2U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_INIT_HW_CTRL_0_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_INIT_HW_CTRL_0_Ch_TDK_4G =
{
        /* Sbc_INIT_HW_CTRL_0_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)130U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_INIT_HW_CTRL_0_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[3U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_INIT_BUS_CTRL_0_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_INIT_BUS_CTRL_0_Ch_TDK_4G =
{
        /* Sbc_INIT_BUS_CTRL_0_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)900U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_INIT_BUS_CTRL_0_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[4U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_INIT_WK_CTRL_0_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_INIT_WK_CTRL_0_Ch_TDK_4G =
{
        /* Sbc_INIT_WK_CTRL_0_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)134U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_INIT_WK_CTRL_0_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[5U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_INIT_WK_CTRL_1_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_INIT_WK_CTRL_1_Ch_TDK_4G =
{
        /* Sbc_INIT_WK_CTRL_1_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)135U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_INIT_WK_CTRL_1_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[6U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_INIT_TIMER_CTRL_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_INIT_TIMER_CTRL_Ch_TDK_4G =
{
        /* Sbc_INIT_TIMER_CTRL_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)140U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_INIT_TIMER_CTRL_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[7U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_INIT_PWM_CTRL_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_INIT_PWM_CTRL_Ch_TDK_4G =
{
        /* Sbc_INIT_PWM_CTRL_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)152U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_INIT_PWM_CTRL_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[8U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_INIT_SBC_NORMAL_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_INIT_SBC_NORMAL_Ch_TDK_4G =
{
        /* Sbc_INIT_SBC_NORMAL_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)2177U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_INIT_SBC_NORMAL_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[9U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_INIT_GPIO_CTRL_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_INIT_GPIO_CTRL_Ch_TDK_4G =
{
        /* Sbc_INIT_GPIO_CTRL_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)1175U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_INIT_GPIO_CTRL_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[10U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_SD_WK_STAT_0_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_SD_WK_STAT_0_Ch_TDK_4G =
{
        /* Sbc_SD_WK_STAT_0_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)198U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_SD_WK_STAT_0_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[11U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_SD_WK_STAT_1_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_SD_WK_STAT_1_Ch_TDK_4G =
{
        /* Sbc_SD_WK_STAT_1_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)199U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_SD_WK_STAT_1_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[12U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_SD_BUS_CTRL_0_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_SD_BUS_CTRL_0_Ch_TDK_4G =
{
        /* Sbc_SD_BUS_CTRL_0_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)388U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_SD_BUS_CTRL_0_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[13U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_SD_M_S_CTRL_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_SD_M_S_CTRL_Ch_TDK_4G =
{
        /* Sbc_SD_M_S_CTRL_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)16769U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_SD_M_S_CTRL_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[14U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_STN_M_S_CTRL_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_STN_M_S_CTRL_Ch_TDK_4G =
{
        /* Sbc_STN_M_S_CTRL_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)2177U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_STN_M_S_CTRL_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[15U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_STN_BUS_CTRL_0_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_STN_BUS_CTRL_0_Ch_TDK_4G =
{
        /* Sbc_STN_BUS_CTRL_0_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)900U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_STN_BUS_CTRL_0_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[16U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_STLP_BUS_CTRL_0_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_STLP_BUS_CTRL_0_Ch_TDK_4G =
{
        /* Sbc_STLP_BUS_CTRL_0_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)388U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_STLP_BUS_CTRL_0_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[17U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_STLP_HW_CTRL_2_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_STLP_HW_CTRL_2_Ch_TDK_4G =
{
        /* Sbc_STLP_HW_CTRL_2_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)20623U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_STLP_HW_CTRL_2_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[18U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_STLP_M_S_CTRL_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_STLP_M_S_CTRL_Ch_TDK_4G =
{
        /* Sbc_STLP_M_S_CTRL_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)33153U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_STLP_M_S_CTRL_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[19U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_RST_M_S_CTRL_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_RST_M_S_CTRL_Ch_TDK_4G =
{
        /* Sbc_RST_M_S_CTRL_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)1U, /* In the case SpiDefaultData is disabled. Set this value is 1U */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_RST_M_S_CTRL_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[20U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_CLEAR_STATE_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_CLEAR_STATE_Ch_TDK_4G =
{
        /* Sbc_CLEAR_STATE_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)38275U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_CLEAR_STATE_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[21U] /* pChannelState pointer */
};
/* Channel Configuration of Acc_READ_AX_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Acc_READ_AX_Ch_TDK_4G =
{
        /* Acc_READ_AX_Ch*/
        IB, /* BufferType IB or EB */
        32U, /* Frame size */
                (boolean)FALSE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)268435525U, /* u32DefaultTransmitValue (configured) */
        4U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Acc_READ_AX_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[22U] /* pChannelState pointer */
};
/* Channel Configuration of Acc_READ_AY_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Acc_READ_AY_Ch_TDK_4G =
{
        /* Acc_READ_AY_Ch*/
        IB, /* BufferType IB or EB */
        32U, /* Frame size */
                (boolean)FALSE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)335544424U, /* u32DefaultTransmitValue (configured) */
        4U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Acc_READ_AY_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[23U] /* pChannelState pointer */
};
/* Channel Configuration of Acc_READ_AZ_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Acc_READ_AZ_Ch_TDK_4G =
{
        /* Acc_READ_AZ_Ch*/
        IB, /* BufferType IB or EB */
        32U, /* Frame size */
                (boolean)FALSE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)402653215U, /* u32DefaultTransmitValue (configured) */
        4U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Acc_READ_AZ_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[24U] /* pChannelState pointer */
};
/* Channel Configuration of Acc_INIT_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Acc_INIT_Ch_TDK_4G =
{
        /* Acc_INIT_Ch*/
        IB, /* BufferType IB or EB */
        32U, /* Frame size */
                (boolean)FALSE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)12517376U, /* u32DefaultTransmitValue (configured) */
        4U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Acc_INIT_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[25U] /* pChannelState pointer */
};
/* Channel Configuration of Acc_READ_TEMPERATURE_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Acc_READ_TEMPERATURE_Ch_TDK_4G =
{
        /* Acc_READ_TEMPERATURE_Ch*/
        IB, /* BufferType IB or EB */
        32U, /* Frame size */
                (boolean)FALSE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)12517376U, /* u32DefaultTransmitValue (configured) */
        4U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Acc_READ_TEMPERATURE_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[26U] /* pChannelState pointer */
};
/* Channel Configuration of Acc_Dummy_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Acc_Dummy_Ch_TDK_4G =
{
        /* Acc_Dummy_Ch*/
        IB, /* BufferType IB or EB */
        32U, /* Frame size */
                (boolean)FALSE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)738197747U, /* u32DefaultTransmitValue (configured) */
        4U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Acc_Dummy_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[27U] /* pChannelState pointer */
};
/* Channel Configuration of Acc_Unlock_1_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Acc_Unlock_1_Ch_TDK_4G =
{
        /* Acc_Unlock_1_Ch*/
        IB, /* BufferType IB or EB */
        32U, /* Frame size */
                (boolean)FALSE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)3825205896U, /* u32DefaultTransmitValue (configured) */
        4U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Acc_Unlock_1_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[28U] /* pChannelState pointer */
};
/* Channel Configuration of Acc_Unlock_2_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Acc_Unlock_2_Ch_TDK_4G =
{
        /* Acc_Unlock_2_Ch*/
        IB, /* BufferType IB or EB */
        32U, /* Frame size */
                (boolean)FALSE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)3825205643U, /* u32DefaultTransmitValue (configured) */
        4U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Acc_Unlock_2_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[29U] /* pChannelState pointer */
};
/* Channel Configuration of Acc_Unlock_3_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Acc_Unlock_3_Ch_TDK_4G =
{
        /* Acc_Unlock_3_Ch*/
        IB, /* BufferType IB or EB */
        32U, /* Frame size */
                (boolean)FALSE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)3825206414U, /* u32DefaultTransmitValue (configured) */
        4U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Acc_Unlock_3_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[30U] /* pChannelState pointer */
};
/* Channel Configuration of Acc_Unlock_4_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Acc_Unlock_4_Ch_TDK_4G =
{
        /* Acc_Unlock_4_Ch*/
        IB, /* BufferType IB or EB */
        32U, /* Frame size */
                (boolean)FALSE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)3825402029U, /* u32DefaultTransmitValue (configured) */
        4U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Acc_Unlock_4_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[31U] /* pChannelState pointer */
};
/* Channel Configuration of Acc_Unlock_5_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Acc_Unlock_5_Ch_TDK_4G =
{
        /* Acc_Unlock_5_Ch*/
        IB, /* BufferType IB or EB */
        32U, /* Frame size */
                (boolean)FALSE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)3825303575U, /* u32DefaultTransmitValue (configured) */
        4U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Acc_Unlock_5_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[32U] /* pChannelState pointer */
};
/* Channel Configuration of Acc_Unlock_6_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Acc_Unlock_6_Ch_TDK_4G =
{
        /* Acc_Unlock_6_Ch*/
        IB, /* BufferType IB or EB */
        32U, /* Frame size */
                (boolean)FALSE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)3825369136U, /* u32DefaultTransmitValue (configured) */
        4U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Acc_Unlock_6_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[33U] /* pChannelState pointer */
};
/* Channel Configuration of Sbc_Wdg_Autotest_Ch*/
static const Spi_ChannelConfigType Spi_ChannelConfig_Sbc_Wdg_Autotest_Ch_TDK_4G =
{
        /* Sbc_Wdg_Autotest_Ch*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)36995U, /* u32DefaultTransmitValue (configured) */
        2U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_TDK_4G_Sbc_Wdg_Autotest_Ch, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[34U] /* pChannelState pointer */
};
/* Spi_apChannelConfigList_TDK_4G Channel Configuration of Spi*/
static const Spi_ChannelsCfgType Spi_aChannelConfigList_TDK_4G[35] =
{
    {
    /* Sbc_WDG_Ch */
    /* Sbc_WDG_Ch */
    &Spi_ChannelConfig_Sbc_WDG_Ch_TDK_4G
    },
    {
    /* Sbc_INIT_HW_CTRL_2_Ch */
    /* Sbc_INIT_HW_CTRL_2_Ch */
    &Spi_ChannelConfig_Sbc_INIT_HW_CTRL_2_Ch_TDK_4G
    },
    {
    /* Sbc_INIT_HW_CTRL_1_Ch */
    /* Sbc_INIT_HW_CTRL_1_Ch */
    &Spi_ChannelConfig_Sbc_INIT_HW_CTRL_1_Ch_TDK_4G
    },
    {
    /* Sbc_INIT_HW_CTRL_0_Ch */
    /* Sbc_INIT_HW_CTRL_0_Ch */
    &Spi_ChannelConfig_Sbc_INIT_HW_CTRL_0_Ch_TDK_4G
    },
    {
    /* Sbc_INIT_BUS_CTRL_0_Ch */
    /* Sbc_INIT_BUS_CTRL_0_Ch */
    &Spi_ChannelConfig_Sbc_INIT_BUS_CTRL_0_Ch_TDK_4G
    },
    {
    /* Sbc_INIT_WK_CTRL_0_Ch */
    /* Sbc_INIT_WK_CTRL_0_Ch */
    &Spi_ChannelConfig_Sbc_INIT_WK_CTRL_0_Ch_TDK_4G
    },
    {
    /* Sbc_INIT_WK_CTRL_1_Ch */
    /* Sbc_INIT_WK_CTRL_1_Ch */
    &Spi_ChannelConfig_Sbc_INIT_WK_CTRL_1_Ch_TDK_4G
    },
    {
    /* Sbc_INIT_TIMER_CTRL_Ch */
    /* Sbc_INIT_TIMER_CTRL_Ch */
    &Spi_ChannelConfig_Sbc_INIT_TIMER_CTRL_Ch_TDK_4G
    },
    {
    /* Sbc_INIT_PWM_CTRL_Ch */
    /* Sbc_INIT_PWM_CTRL_Ch */
    &Spi_ChannelConfig_Sbc_INIT_PWM_CTRL_Ch_TDK_4G
    },
    {
    /* Sbc_INIT_SBC_NORMAL_Ch */
    /* Sbc_INIT_SBC_NORMAL_Ch */
    &Spi_ChannelConfig_Sbc_INIT_SBC_NORMAL_Ch_TDK_4G
    },
    {
    /* Sbc_INIT_GPIO_CTRL_Ch */
    /* Sbc_INIT_GPIO_CTRL_Ch */
    &Spi_ChannelConfig_Sbc_INIT_GPIO_CTRL_Ch_TDK_4G
    },
    {
    /* Sbc_SD_WK_STAT_0_Ch */
    /* Sbc_SD_WK_STAT_0_Ch */
    &Spi_ChannelConfig_Sbc_SD_WK_STAT_0_Ch_TDK_4G
    },
    {
    /* Sbc_SD_WK_STAT_1_Ch */
    /* Sbc_SD_WK_STAT_1_Ch */
    &Spi_ChannelConfig_Sbc_SD_WK_STAT_1_Ch_TDK_4G
    },
    {
    /* Sbc_SD_BUS_CTRL_0_Ch */
    /* Sbc_SD_BUS_CTRL_0_Ch */
    &Spi_ChannelConfig_Sbc_SD_BUS_CTRL_0_Ch_TDK_4G
    },
    {
    /* Sbc_SD_M_S_CTRL_Ch */
    /* Sbc_SD_M_S_CTRL_Ch */
    &Spi_ChannelConfig_Sbc_SD_M_S_CTRL_Ch_TDK_4G
    },
    {
    /* Sbc_STN_M_S_CTRL_Ch */
    /* Sbc_STN_M_S_CTRL_Ch */
    &Spi_ChannelConfig_Sbc_STN_M_S_CTRL_Ch_TDK_4G
    },
    {
    /* Sbc_STN_BUS_CTRL_0_Ch */
    /* Sbc_STN_BUS_CTRL_0_Ch */
    &Spi_ChannelConfig_Sbc_STN_BUS_CTRL_0_Ch_TDK_4G
    },
    {
    /* Sbc_STLP_BUS_CTRL_0_Ch */
    /* Sbc_STLP_BUS_CTRL_0_Ch */
    &Spi_ChannelConfig_Sbc_STLP_BUS_CTRL_0_Ch_TDK_4G
    },
    {
    /* Sbc_STLP_HW_CTRL_2_Ch */
    /* Sbc_STLP_HW_CTRL_2_Ch */
    &Spi_ChannelConfig_Sbc_STLP_HW_CTRL_2_Ch_TDK_4G
    },
    {
    /* Sbc_STLP_M_S_CTRL_Ch */
    /* Sbc_STLP_M_S_CTRL_Ch */
    &Spi_ChannelConfig_Sbc_STLP_M_S_CTRL_Ch_TDK_4G
    },
    {
    /* Sbc_RST_M_S_CTRL_Ch */
    /* Sbc_RST_M_S_CTRL_Ch */
    &Spi_ChannelConfig_Sbc_RST_M_S_CTRL_Ch_TDK_4G
    },
    {
    /* Sbc_CLEAR_STATE_Ch */
    /* Sbc_CLEAR_STATE_Ch */
    &Spi_ChannelConfig_Sbc_CLEAR_STATE_Ch_TDK_4G
    },
    {
    /* Acc_READ_AX_Ch */
    /* Acc_READ_AX_Ch */
    &Spi_ChannelConfig_Acc_READ_AX_Ch_TDK_4G
    },
    {
    /* Acc_READ_AY_Ch */
    /* Acc_READ_AY_Ch */
    &Spi_ChannelConfig_Acc_READ_AY_Ch_TDK_4G
    },
    {
    /* Acc_READ_AZ_Ch */
    /* Acc_READ_AZ_Ch */
    &Spi_ChannelConfig_Acc_READ_AZ_Ch_TDK_4G
    },
    {
    /* Acc_INIT_Ch */
    /* Acc_INIT_Ch */
    &Spi_ChannelConfig_Acc_INIT_Ch_TDK_4G
    },
    {
    /* Acc_READ_TEMPERATURE_Ch */
    /* Acc_READ_TEMPERATURE_Ch */
    &Spi_ChannelConfig_Acc_READ_TEMPERATURE_Ch_TDK_4G
    },
    {
    /* Acc_Dummy_Ch */
    /* Acc_Dummy_Ch */
    &Spi_ChannelConfig_Acc_Dummy_Ch_TDK_4G
    },
    {
    /* Acc_Unlock_1_Ch */
    /* Acc_Unlock_1_Ch */
    &Spi_ChannelConfig_Acc_Unlock_1_Ch_TDK_4G
    },
    {
    /* Acc_Unlock_2_Ch */
    /* Acc_Unlock_2_Ch */
    &Spi_ChannelConfig_Acc_Unlock_2_Ch_TDK_4G
    },
    {
    /* Acc_Unlock_3_Ch */
    /* Acc_Unlock_3_Ch */
    &Spi_ChannelConfig_Acc_Unlock_3_Ch_TDK_4G
    },
    {
    /* Acc_Unlock_4_Ch */
    /* Acc_Unlock_4_Ch */
    &Spi_ChannelConfig_Acc_Unlock_4_Ch_TDK_4G
    },
    {
    /* Acc_Unlock_5_Ch */
    /* Acc_Unlock_5_Ch */
    &Spi_ChannelConfig_Acc_Unlock_5_Ch_TDK_4G
    },
    {
    /* Acc_Unlock_6_Ch */
    /* Acc_Unlock_6_Ch */
    &Spi_ChannelConfig_Acc_Unlock_6_Ch_TDK_4G
    },
    {
    /* Sbc_Wdg_Autotest_Ch */
    /* Sbc_Wdg_Autotest_Ch */
    &Spi_ChannelConfig_Sbc_Wdg_Autotest_Ch_TDK_4G
    }

};

/* Channel Assignment of Jobs */

/* Channel to Job Assignment */

static const Spi_ChannelType Spi_Sbc_WDG_Job_ChannelAssignment_TDK_4G[1] = {SpiConf_SpiChannel_Sbc_WDG_Ch};
static const Spi_ChannelType Spi_Sbc_INIT_Job_ChannelAssignment_TDK_4G[10] = {SpiConf_SpiChannel_Sbc_INIT_GPIO_CTRL_Ch, SpiConf_SpiChannel_Sbc_INIT_WK_CTRL_1_Ch, SpiConf_SpiChannel_Sbc_INIT_HW_CTRL_2_Ch, SpiConf_SpiChannel_Sbc_INIT_HW_CTRL_1_Ch, SpiConf_SpiChannel_Sbc_INIT_HW_CTRL_0_Ch, SpiConf_SpiChannel_Sbc_INIT_BUS_CTRL_0_Ch, SpiConf_SpiChannel_Sbc_INIT_WK_CTRL_0_Ch, SpiConf_SpiChannel_Sbc_INIT_TIMER_CTRL_Ch, SpiConf_SpiChannel_Sbc_INIT_PWM_CTRL_Ch, SpiConf_SpiChannel_Sbc_INIT_SBC_NORMAL_Ch};
static const Spi_ChannelType Spi_Sbc_SHUTDOWN_Job_ChannelAssignment_TDK_4G[4] = {SpiConf_SpiChannel_Sbc_SD_WK_STAT_0_Ch, SpiConf_SpiChannel_Sbc_SD_WK_STAT_1_Ch, SpiConf_SpiChannel_Sbc_SD_BUS_CTRL_0_Ch, SpiConf_SpiChannel_Sbc_SD_M_S_CTRL_Ch};
static const Spi_ChannelType Spi_Sbc_SET_NORMAL_Job_ChannelAssignment_TDK_4G[3] = {SpiConf_SpiChannel_Sbc_STN_M_S_CTRL_Ch, SpiConf_SpiChannel_Sbc_STN_M_S_CTRL_Ch, SpiConf_SpiChannel_Sbc_STN_BUS_CTRL_0_Ch};
static const Spi_ChannelType Spi_Sbc_SET_LOW_POWER_Job_ChannelAssignment_TDK_4G[3] = {SpiConf_SpiChannel_Sbc_STLP_BUS_CTRL_0_Ch, SpiConf_SpiChannel_Sbc_STLP_HW_CTRL_2_Ch, SpiConf_SpiChannel_Sbc_STLP_M_S_CTRL_Ch};
static const Spi_ChannelType Spi_Sbc_RESET_Job_ChannelAssignment_TDK_4G[1] = {SpiConf_SpiChannel_Sbc_RST_M_S_CTRL_Ch};
static const Spi_ChannelType Spi_Sbc_FORCE_WDG_RESET_Job_ChannelAssignment_TDK_4G[2] = {SpiConf_SpiChannel_Sbc_WDG_Ch, SpiConf_SpiChannel_Sbc_WDG_Ch};
static const Spi_ChannelType Spi_Sbc_CLEAR_STATE_Job_ChannelAssignment_TDK_4G[1] = {SpiConf_SpiChannel_Sbc_CLEAR_STATE_Ch};
static const Spi_ChannelType Spi_Acc_INIT_Job_ChannelAssignment_TDK_4G[1] = {SpiConf_SpiChannel_Acc_INIT_Ch};
static const Spi_ChannelType Spi_Acc_READ_TEMP_Job_ChannelAssignment_TDK_4G[1] = {SpiConf_SpiChannel_Acc_READ_TEMPERATURE_Ch};
static const Spi_ChannelType Spi_Acc_UNLOCK_Job_ChannelAssignment_TDK_4G[6] = {SpiConf_SpiChannel_Acc_Unlock_1_Ch, SpiConf_SpiChannel_Acc_Unlock_2_Ch, SpiConf_SpiChannel_Acc_Unlock_3_Ch, SpiConf_SpiChannel_Acc_Unlock_4_Ch, SpiConf_SpiChannel_Acc_Unlock_5_Ch, SpiConf_SpiChannel_Acc_Unlock_6_Ch};
static const Spi_ChannelType Spi_Acc_READ_Ax_Ay_Az_Job_ChannelAssignment_TDK_4G[4] = {SpiConf_SpiChannel_Acc_READ_AX_Ch, SpiConf_SpiChannel_Acc_READ_AY_Ch, SpiConf_SpiChannel_Acc_READ_AZ_Ch, SpiConf_SpiChannel_Acc_Dummy_Ch};
static const Spi_ChannelType Spi_Sbc_WDG_Autotest_Job_ChannelAssignment_TDK_4G[1] = {SpiConf_SpiChannel_Sbc_Wdg_Autotest_Ch};

/* Configuration of Jobs */

/* Job Configuration of Sbc_WDG_Job*/
static const Spi_JobConfigType Spi_JobConfig_Sbc_WDG_Job_TDK_4G =
{
        /* Sbc_WDG_Job */
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_Sbc_WDG_Job_ChannelAssignment_TDK_4G, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[0], /* JobState instance */
        CSIB0, /* HWUnit index */
        /* External Device Settings */
        SPI_Sbc_Device, /* External Device */
                &Spi_aExternalDeviceConfigList_TDK_4G[SPI_Sbc_Device] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Job Configuration of Sbc_INIT_Job*/
static const Spi_JobConfigType Spi_JobConfig_Sbc_INIT_Job_TDK_4G =
{
        /* Sbc_INIT_Job */
        (Spi_ChannelType)10U, /* NumChannels field */
        Spi_Sbc_INIT_Job_ChannelAssignment_TDK_4G, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[1], /* JobState instance */
        CSIB0, /* HWUnit index */
        /* External Device Settings */
        SPI_Sbc_Device, /* External Device */
                &Spi_aExternalDeviceConfigList_TDK_4G[SPI_Sbc_Device] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Job Configuration of Sbc_SHUTDOWN_Job*/
static const Spi_JobConfigType Spi_JobConfig_Sbc_SHUTDOWN_Job_TDK_4G =
{
        /* Sbc_SHUTDOWN_Job */
        (Spi_ChannelType)4U, /* NumChannels field */
        Spi_Sbc_SHUTDOWN_Job_ChannelAssignment_TDK_4G, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[2], /* JobState instance */
        CSIB0, /* HWUnit index */
        /* External Device Settings */
        SPI_Sbc_Device, /* External Device */
                &Spi_aExternalDeviceConfigList_TDK_4G[SPI_Sbc_Device] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Job Configuration of Sbc_SET_NORMAL_Job*/
static const Spi_JobConfigType Spi_JobConfig_Sbc_SET_NORMAL_Job_TDK_4G =
{
        /* Sbc_SET_NORMAL_Job */
        (Spi_ChannelType)3U, /* NumChannels field */
        Spi_Sbc_SET_NORMAL_Job_ChannelAssignment_TDK_4G, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[3], /* JobState instance */
        CSIB0, /* HWUnit index */
        /* External Device Settings */
        SPI_Sbc_Device, /* External Device */
                &Spi_aExternalDeviceConfigList_TDK_4G[SPI_Sbc_Device] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Job Configuration of Sbc_SET_LOW_POWER_Job*/
static const Spi_JobConfigType Spi_JobConfig_Sbc_SET_LOW_POWER_Job_TDK_4G =
{
        /* Sbc_SET_LOW_POWER_Job */
        (Spi_ChannelType)3U, /* NumChannels field */
        Spi_Sbc_SET_LOW_POWER_Job_ChannelAssignment_TDK_4G, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[4], /* JobState instance */
        CSIB0, /* HWUnit index */
        /* External Device Settings */
        SPI_Sbc_Device, /* External Device */
                &Spi_aExternalDeviceConfigList_TDK_4G[SPI_Sbc_Device] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Job Configuration of Sbc_RESET_Job*/
static const Spi_JobConfigType Spi_JobConfig_Sbc_RESET_Job_TDK_4G =
{
        /* Sbc_RESET_Job */
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_Sbc_RESET_Job_ChannelAssignment_TDK_4G, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[5], /* JobState instance */
        CSIB0, /* HWUnit index */
        /* External Device Settings */
        SPI_Sbc_Device, /* External Device */
                &Spi_aExternalDeviceConfigList_TDK_4G[SPI_Sbc_Device] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Job Configuration of Sbc_FORCE_WDG_RESET_Job*/
static const Spi_JobConfigType Spi_JobConfig_Sbc_FORCE_WDG_RESET_Job_TDK_4G =
{
        /* Sbc_FORCE_WDG_RESET_Job */
        (Spi_ChannelType)2U, /* NumChannels field */
        Spi_Sbc_FORCE_WDG_RESET_Job_ChannelAssignment_TDK_4G, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[6], /* JobState instance */
        CSIB0, /* HWUnit index */
        /* External Device Settings */
        SPI_Sbc_Device, /* External Device */
                &Spi_aExternalDeviceConfigList_TDK_4G[SPI_Sbc_Device] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Job Configuration of Sbc_CLEAR_STATE_Job*/
static const Spi_JobConfigType Spi_JobConfig_Sbc_CLEAR_STATE_Job_TDK_4G =
{
        /* Sbc_CLEAR_STATE_Job */
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_Sbc_CLEAR_STATE_Job_ChannelAssignment_TDK_4G, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[7], /* JobState instance */
        CSIB0, /* HWUnit index */
        /* External Device Settings */
        SPI_Sbc_Device, /* External Device */
                &Spi_aExternalDeviceConfigList_TDK_4G[SPI_Sbc_Device] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Job Configuration of Acc_INIT_Job*/
static const Spi_JobConfigType Spi_JobConfig_Acc_INIT_Job_TDK_4G =
{
        /* Acc_INIT_Job */
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_Acc_INIT_Job_ChannelAssignment_TDK_4G, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[8], /* JobState instance */
        CSIB1, /* HWUnit index */
        /* External Device Settings */
        SPI_Accelerometer_Device, /* External Device */
                &Spi_aExternalDeviceConfigList_TDK_4G[SPI_Accelerometer_Device] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Job Configuration of Acc_READ_TEMP_Job*/
static const Spi_JobConfigType Spi_JobConfig_Acc_READ_TEMP_Job_TDK_4G =
{
        /* Acc_READ_TEMP_Job */
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_Acc_READ_TEMP_Job_ChannelAssignment_TDK_4G, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[9], /* JobState instance */
        CSIB1, /* HWUnit index */
        /* External Device Settings */
        SPI_Accelerometer_Device, /* External Device */
                &Spi_aExternalDeviceConfigList_TDK_4G[SPI_Accelerometer_Device] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Job Configuration of Acc_UNLOCK_Job*/
static const Spi_JobConfigType Spi_JobConfig_Acc_UNLOCK_Job_TDK_4G =
{
        /* Acc_UNLOCK_Job */
        (Spi_ChannelType)6U, /* NumChannels field */
        Spi_Acc_UNLOCK_Job_ChannelAssignment_TDK_4G, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[10], /* JobState instance */
        CSIB1, /* HWUnit index */
        /* External Device Settings */
        SPI_Accelerometer_Device, /* External Device */
                &Spi_aExternalDeviceConfigList_TDK_4G[SPI_Accelerometer_Device] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Job Configuration of Acc_READ_Ax_Ay_Az_Job*/
static const Spi_JobConfigType Spi_JobConfig_Acc_READ_Ax_Ay_Az_Job_TDK_4G =
{
        /* Acc_READ_Ax_Ay_Az_Job */
        (Spi_ChannelType)4U, /* NumChannels field */
        Spi_Acc_READ_Ax_Ay_Az_Job_ChannelAssignment_TDK_4G, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[11], /* JobState instance */
        CSIB1, /* HWUnit index */
        /* External Device Settings */
        SPI_Accelerometer_Device, /* External Device */
                &Spi_aExternalDeviceConfigList_TDK_4G[SPI_Accelerometer_Device] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Job Configuration of Sbc_WDG_Autotest_Job*/
static const Spi_JobConfigType Spi_JobConfig_Sbc_WDG_Autotest_Job_TDK_4G =
{
        /* Sbc_WDG_Autotest_Job */
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_Sbc_WDG_Autotest_Job_ChannelAssignment_TDK_4G, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[12], /* JobState instance */
        CSIB0, /* HWUnit index */
        /* External Device Settings */
        SPI_Sbc_Device, /* External Device */
                &Spi_aExternalDeviceConfigList_TDK_4G[SPI_Sbc_Device] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Spi_apJobConfigList_TDK_4G Job Configuration of Spi*/
static const Spi_JobsCfgType Spi_aJobConfigList_TDK_4G[13] =
{
    {
    /* Sbc_WDG_Job */
    /* Sbc_WDG_Job */
    &Spi_JobConfig_Sbc_WDG_Job_TDK_4G
    },
    {
    /* Sbc_INIT_Job */
    /* Sbc_INIT_Job */
    &Spi_JobConfig_Sbc_INIT_Job_TDK_4G
    },
    {
    /* Sbc_SHUTDOWN_Job */
    /* Sbc_SHUTDOWN_Job */
    &Spi_JobConfig_Sbc_SHUTDOWN_Job_TDK_4G
    },
    {
    /* Sbc_SET_NORMAL_Job */
    /* Sbc_SET_NORMAL_Job */
    &Spi_JobConfig_Sbc_SET_NORMAL_Job_TDK_4G
    },
    {
    /* Sbc_SET_LOW_POWER_Job */
    /* Sbc_SET_LOW_POWER_Job */
    &Spi_JobConfig_Sbc_SET_LOW_POWER_Job_TDK_4G
    },
    {
    /* Sbc_RESET_Job */
    /* Sbc_RESET_Job */
    &Spi_JobConfig_Sbc_RESET_Job_TDK_4G
    },
    {
    /* Sbc_FORCE_WDG_RESET_Job */
    /* Sbc_FORCE_WDG_RESET_Job */
    &Spi_JobConfig_Sbc_FORCE_WDG_RESET_Job_TDK_4G
    },
    {
    /* Sbc_CLEAR_STATE_Job */
    /* Sbc_CLEAR_STATE_Job */
    &Spi_JobConfig_Sbc_CLEAR_STATE_Job_TDK_4G
    },
    {
    /* Acc_INIT_Job */
    /* Acc_INIT_Job */
    &Spi_JobConfig_Acc_INIT_Job_TDK_4G
    },
    {
    /* Acc_READ_TEMP_Job */
    /* Acc_READ_TEMP_Job */
    &Spi_JobConfig_Acc_READ_TEMP_Job_TDK_4G
    },
    {
    /* Acc_UNLOCK_Job */
    /* Acc_UNLOCK_Job */
    &Spi_JobConfig_Acc_UNLOCK_Job_TDK_4G
    },
    {
    /* Acc_READ_Ax_Ay_Az_Job */
    /* Acc_READ_Ax_Ay_Az_Job */
    &Spi_JobConfig_Acc_READ_Ax_Ay_Az_Job_TDK_4G
    },
    {
    /* Sbc_WDG_Autotest_Job */
    /* Sbc_WDG_Autotest_Job */
    &Spi_JobConfig_Sbc_WDG_Autotest_Job_TDK_4G
    }

};


/* Job Assignment of Sequences  */
/* Job to Sequence Assignment */

static const Spi_JobType Spi_Sbc_WDG_Seq_JobAssignment_TDK_4G[1] = {SpiConf_SpiJob_Sbc_WDG_Job};
static const Spi_JobType Spi_Sbc_INIT_Seq_JobAssignment_TDK_4G[1] = {SpiConf_SpiJob_Sbc_INIT_Job};
static const Spi_JobType Spi_Sbc_SHUTDOWN_Seq_JobAssignment_TDK_4G[1] = {SpiConf_SpiJob_Sbc_SHUTDOWN_Job};
static const Spi_JobType Spi_Sbc_SET_NORMAL_Seq_JobAssignment_TDK_4G[1] = {SpiConf_SpiJob_Sbc_SET_NORMAL_Job};
static const Spi_JobType Spi_Sbc_SET_LOW_POWER_Seq_JobAssignment_TDK_4G[1] = {SpiConf_SpiJob_Sbc_SET_LOW_POWER_Job};
static const Spi_JobType Spi_Sbc_RESET_Seq_JobAssignment_TDK_4G[1] = {SpiConf_SpiJob_Sbc_RESET_Job};
static const Spi_JobType Spi_Sbc_FORCE_WDG_RESET_Seq_JobAssignment_TDK_4G[1] = {SpiConf_SpiJob_Sbc_FORCE_WDG_RESET_Job};
static const Spi_JobType Spi_Sbc_CLEAR_STATE_Seq_JobAssignment_TDK_4G[1] = {SpiConf_SpiJob_Sbc_CLEAR_STATE_Job};
static const Spi_JobType Spi_Acc_INIT_Seq_JobAssignment_TDK_4G[1] = {SpiConf_SpiJob_Acc_INIT_Job};
static const Spi_JobType Spi_Acc_READ_TEMP_Seq_JobAssignment_TDK_4G[1] = {SpiConf_SpiJob_Acc_READ_TEMP_Job};
static const Spi_JobType Spi_Acc_UNLOCK_Seq_JobAssignment_TDK_4G[1] = {SpiConf_SpiJob_Acc_UNLOCK_Job};
static const Spi_JobType Spi_Acc_READ_Ax_Ay_Az_Seq_JobAssignment_TDK_4G[1] = {SpiConf_SpiJob_Acc_READ_Ax_Ay_Az_Job};
static const Spi_JobType Spi_Sbc_WDG_Autotest_Seq_JobAssignment_TDK_4G[1] = {SpiConf_SpiJob_Sbc_WDG_Autotest_Job};
/* Configuration of Sequences */

/* Sequence Configuration of Sbc_WDG_Seq_TDK_4G */
static const Spi_SequenceConfigType Spi_SequenceConfig_Sbc_WDG_Seq_TDK_4G =
{
        /* Sbc_WDG_Seq */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_Sbc_WDG_Seq_JobAssignment_TDK_4G, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
};
/* Sequence Configuration of Sbc_INIT_Seq_TDK_4G */
static const Spi_SequenceConfigType Spi_SequenceConfig_Sbc_INIT_Seq_TDK_4G =
{
        /* Sbc_INIT_Seq */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_Sbc_INIT_Seq_JobAssignment_TDK_4G, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
};
/* Sequence Configuration of Sbc_SHUTDOWN_Seq_TDK_4G */
static const Spi_SequenceConfigType Spi_SequenceConfig_Sbc_SHUTDOWN_Seq_TDK_4G =
{
        /* Sbc_SHUTDOWN_Seq */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_Sbc_SHUTDOWN_Seq_JobAssignment_TDK_4G, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
};
/* Sequence Configuration of Sbc_SET_NORMAL_Seq_TDK_4G */
static const Spi_SequenceConfigType Spi_SequenceConfig_Sbc_SET_NORMAL_Seq_TDK_4G =
{
        /* Sbc_SET_NORMAL_Seq */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_Sbc_SET_NORMAL_Seq_JobAssignment_TDK_4G, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
};
/* Sequence Configuration of Sbc_SET_LOW_POWER_Seq_TDK_4G */
static const Spi_SequenceConfigType Spi_SequenceConfig_Sbc_SET_LOW_POWER_Seq_TDK_4G =
{
        /* Sbc_SET_LOW_POWER_Seq */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_Sbc_SET_LOW_POWER_Seq_JobAssignment_TDK_4G, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
};
/* Sequence Configuration of Sbc_RESET_Seq_TDK_4G */
static const Spi_SequenceConfigType Spi_SequenceConfig_Sbc_RESET_Seq_TDK_4G =
{
        /* Sbc_RESET_Seq */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_Sbc_RESET_Seq_JobAssignment_TDK_4G, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
};
/* Sequence Configuration of Sbc_FORCE_WDG_RESET_Seq_TDK_4G */
static const Spi_SequenceConfigType Spi_SequenceConfig_Sbc_FORCE_WDG_RESET_Seq_TDK_4G =
{
        /* Sbc_FORCE_WDG_RESET_Seq */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_Sbc_FORCE_WDG_RESET_Seq_JobAssignment_TDK_4G, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
};
/* Sequence Configuration of Sbc_CLEAR_STATE_Seq_TDK_4G */
static const Spi_SequenceConfigType Spi_SequenceConfig_Sbc_CLEAR_STATE_Seq_TDK_4G =
{
        /* Sbc_CLEAR_STATE_Seq */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_Sbc_CLEAR_STATE_Seq_JobAssignment_TDK_4G, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
};
/* Sequence Configuration of Acc_INIT_Seq_TDK_4G */
static const Spi_SequenceConfigType Spi_SequenceConfig_Acc_INIT_Seq_TDK_4G =
{
        /* Acc_INIT_Seq */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_Acc_INIT_Seq_JobAssignment_TDK_4G, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
};
/* Sequence Configuration of Acc_READ_TEMP_Seq_TDK_4G */
static const Spi_SequenceConfigType Spi_SequenceConfig_Acc_READ_TEMP_Seq_TDK_4G =
{
        /* Acc_READ_TEMP_Seq */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_Acc_READ_TEMP_Seq_JobAssignment_TDK_4G, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
};
/* Sequence Configuration of Acc_UNLOCK_Seq_TDK_4G */
static const Spi_SequenceConfigType Spi_SequenceConfig_Acc_UNLOCK_Seq_TDK_4G =
{
        /* Acc_UNLOCK_Seq */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_Acc_UNLOCK_Seq_JobAssignment_TDK_4G, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
};
/* Sequence Configuration of Acc_READ_Ax_Ay_Az_Seq_TDK_4G */
static const Spi_SequenceConfigType Spi_SequenceConfig_Acc_READ_Ax_Ay_Az_Seq_TDK_4G =
{
        /* Acc_READ_Ax_Ay_Az_Seq */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_Acc_READ_Ax_Ay_Az_Seq_JobAssignment_TDK_4G, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
};
/* Sequence Configuration of Sbc_WDG_Autotest_Seq_TDK_4G */
static const Spi_SequenceConfigType Spi_SequenceConfig_Sbc_WDG_Autotest_Seq_TDK_4G =
{
        /* Sbc_WDG_Autotest_Seq */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_Sbc_WDG_Autotest_Seq_JobAssignment_TDK_4G, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
};
/* Spi_apSequenceConfigList_TDK_4G Sequence Configuration of Spi*/
static const Spi_SeqsConfigType Spi_aSequenceConfigList_TDK_4G[13] =
{
    {
    /* Sbc_WDG_Seq */
    /* Sbc_WDG_Seq */
    &Spi_SequenceConfig_Sbc_WDG_Seq_TDK_4G
    },
    {
    /* Sbc_INIT_Seq */
    /* Sbc_INIT_Seq */
    &Spi_SequenceConfig_Sbc_INIT_Seq_TDK_4G
    },
    {
    /* Sbc_SHUTDOWN_Seq */
    /* Sbc_SHUTDOWN_Seq */
    &Spi_SequenceConfig_Sbc_SHUTDOWN_Seq_TDK_4G
    },
    {
    /* Sbc_SET_NORMAL_Seq */
    /* Sbc_SET_NORMAL_Seq */
    &Spi_SequenceConfig_Sbc_SET_NORMAL_Seq_TDK_4G
    },
    {
    /* Sbc_SET_LOW_POWER_Seq */
    /* Sbc_SET_LOW_POWER_Seq */
    &Spi_SequenceConfig_Sbc_SET_LOW_POWER_Seq_TDK_4G
    },
    {
    /* Sbc_RESET_Seq */
    /* Sbc_RESET_Seq */
    &Spi_SequenceConfig_Sbc_RESET_Seq_TDK_4G
    },
    {
    /* Sbc_FORCE_WDG_RESET_Seq */
    /* Sbc_FORCE_WDG_RESET_Seq */
    &Spi_SequenceConfig_Sbc_FORCE_WDG_RESET_Seq_TDK_4G
    },
    {
    /* Sbc_CLEAR_STATE_Seq */
    /* Sbc_CLEAR_STATE_Seq */
    &Spi_SequenceConfig_Sbc_CLEAR_STATE_Seq_TDK_4G
    },
    {
    /* Acc_INIT_Seq */
    /* Acc_INIT_Seq */
    &Spi_SequenceConfig_Acc_INIT_Seq_TDK_4G
    },
    {
    /* Acc_READ_TEMP_Seq */
    /* Acc_READ_TEMP_Seq */
    &Spi_SequenceConfig_Acc_READ_TEMP_Seq_TDK_4G
    },
    {
    /* Acc_UNLOCK_Seq */
    /* Acc_UNLOCK_Seq */
    &Spi_SequenceConfig_Acc_UNLOCK_Seq_TDK_4G
    },
    {
    /* Acc_READ_Ax_Ay_Az_Seq */
    /* Acc_READ_Ax_Ay_Az_Seq */
    &Spi_SequenceConfig_Acc_READ_Ax_Ay_Az_Seq_TDK_4G
    },
    {
    /* Sbc_WDG_Autotest_Seq */
    /* Sbc_WDG_Autotest_Seq */
    &Spi_SequenceConfig_Sbc_WDG_Autotest_Seq_TDK_4G
    }
};

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/* Spi Configuration */


/** Compiler_Warning: In some cases, the partition configuration may not be used by the application. */
const Spi_ConfigType Spi_Config_TDK_4G=
{
    2U, /* u16MaxExternalDevice - number of external devices */
    34U, /* Spi_Max_Channel - number of channels */
    12U, /* Spi_Max_Job - number of jobs */
    12U, /* Spi_Max_Sequence - number of sequences */
    SPI_SPURIOUS_CORE_ID_U32, /* u32SpiCoreUse */
    Spi_aChannelConfigList_TDK_4G, /* pcChannelConfig */
    Spi_aJobConfigList_TDK_4G, /* pcJobConfig */
    Spi_aSequenceConfigList_TDK_4G, /* pcSequenceConfig */
    Spi_aExternalDeviceConfigList_TDK_4G, /* pcExternalDeviceConfig */
    Spi_aHwUnitConfigList_TDK_4G /* pcHWUnitConfig */
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                        ,{ (uint32)STD_ON, (uint32)DemConf_DemEventParameter_EVENT_SPI_E_HW_ERROR} /* SPI_E_HARDWARE_ERROR parameters*/                             
        
#endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */  
};






#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

