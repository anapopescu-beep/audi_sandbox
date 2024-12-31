/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FTFC_FLS_IP IPV_QSPI
*   Dependencies         : none
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

/**
*   @file Fls_TDK_4G_PBcfg.c
*
*   @addtogroup FLS
*   @{
*/

/* implements Fls_PBcfg.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Qspi_Ip_Features.h"
#include "Qspi_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_CFG_C                      43
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define FLS_AR_RELEASE_MINOR_VERSION_CFG_C       4
#define FLS_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define FLS_SW_MAJOR_VERSION_CFG_C               1
#define FLS_SW_MINOR_VERSION_CFG_C               0
#define FLS_SW_PATCH_VERSION_CFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != FLS_VENDOR_ID)
    #error "Fls_PBcfg.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG_C != FLS_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif

/* Check if current file and Qspi_Ip_Features header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != QSPI_IP_FEATURES_VENDOR_ID_CFG)
    #error "Fls_PBcfg.c and Qspi_Ip_Features.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != QSPI_IP_FEATURES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != QSPI_IP_FEATURES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != QSPI_IP_FEATURES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Qspi_Ip_Features.h are different"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != QSPI_IP_FEATURES_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION_CFG_C != QSPI_IP_FEATURES_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION_CFG_C != QSPI_IP_FEATURES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Qspi_Ip_Features.h are different"
#endif

/* Check if current file and Qspi_Ip_Cfg header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != QSPI_IP_VENDOR_ID_CFG)
    #error "Fls_PBcfg.c and Qspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Qspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != QSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION_CFG_C != QSPI_IP_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION_CFG_C != QSPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Qspi_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
/* Declaration of Fls notification function (Fee_JobEndNotification())*/
extern void Fee_JobEndNotification( void );

/* Declaration of Fls notification function (Fee_JobErrorNotification())*/
extern void Fee_JobErrorNotification( void );

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
#define FLS_START_SEC_CONFIG_DATA_8
#include "Fls_MemMap.h"

/* aFlsSectorFlags */
static const uint8 FlsConfigSet_TDK_4G_aFlsSectorFlags[32U] =
{
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_0 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_1 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_2 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_3 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_4 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_5 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_6 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_7 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_8 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_9 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_10 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_11 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_12 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_13 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_14 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_15 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_16 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_17 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_18 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_19 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_20 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_21 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_22 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_23 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_24 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_25 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_26 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_27 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_28 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_29 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_30 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH   /* FlsSector_31 */
};

#define FLS_STOP_SEC_CONFIG_DATA_8
#include "Fls_MemMap.h"



#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

/* aFlsSectorEndAddr */
static const Fls_AddressType FlsConfigSet_TDK_4G_aFlsSectorEndAddr[32U] =
{
    (Fls_AddressType)2047U,  /* FlsSector_0 */
    (Fls_AddressType)4095U,  /* FlsSector_1 */
    (Fls_AddressType)6143U,  /* FlsSector_2 */
    (Fls_AddressType)8191U,  /* FlsSector_3 */
    (Fls_AddressType)10239U,  /* FlsSector_4 */
    (Fls_AddressType)12287U,  /* FlsSector_5 */
    (Fls_AddressType)14335U,  /* FlsSector_6 */
    (Fls_AddressType)16383U,  /* FlsSector_7 */
    (Fls_AddressType)18431U,  /* FlsSector_8 */
    (Fls_AddressType)20479U,  /* FlsSector_9 */
    (Fls_AddressType)22527U,  /* FlsSector_10 */
    (Fls_AddressType)24575U,  /* FlsSector_11 */
    (Fls_AddressType)26623U,  /* FlsSector_12 */
    (Fls_AddressType)28671U,  /* FlsSector_13 */
    (Fls_AddressType)30719U,  /* FlsSector_14 */
    (Fls_AddressType)32767U,  /* FlsSector_15 */
    (Fls_AddressType)34815U,  /* FlsSector_16 */
    (Fls_AddressType)36863U,  /* FlsSector_17 */
    (Fls_AddressType)38911U,  /* FlsSector_18 */
    (Fls_AddressType)40959U,  /* FlsSector_19 */
    (Fls_AddressType)43007U,  /* FlsSector_20 */
    (Fls_AddressType)45055U,  /* FlsSector_21 */
    (Fls_AddressType)47103U,  /* FlsSector_22 */
    (Fls_AddressType)49151U,  /* FlsSector_23 */
    (Fls_AddressType)51199U,  /* FlsSector_24 */
    (Fls_AddressType)53247U,  /* FlsSector_25 */
    (Fls_AddressType)55295U,  /* FlsSector_26 */
    (Fls_AddressType)57343U,  /* FlsSector_27 */
    (Fls_AddressType)59391U,  /* FlsSector_28 */
    (Fls_AddressType)61439U,  /* FlsSector_29 */
    (Fls_AddressType)63487U,  /* FlsSector_30 */
    (Fls_AddressType)65535U   /* FlsSector_31 */
};

/* paSectorSize */
static const Fls_LengthType FlsConfigSet_TDK_4G_aFlsSectorSize[32U] =
{
    (Fls_LengthType)2048U,  /* FlsSector_0 */
    (Fls_LengthType)2048U,  /* FlsSector_1 */
    (Fls_LengthType)2048U,  /* FlsSector_2 */
    (Fls_LengthType)2048U,  /* FlsSector_3 */
    (Fls_LengthType)2048U,  /* FlsSector_4 */
    (Fls_LengthType)2048U,  /* FlsSector_5 */
    (Fls_LengthType)2048U,  /* FlsSector_6 */
    (Fls_LengthType)2048U,  /* FlsSector_7 */
    (Fls_LengthType)2048U,  /* FlsSector_8 */
    (Fls_LengthType)2048U,  /* FlsSector_9 */
    (Fls_LengthType)2048U,  /* FlsSector_10 */
    (Fls_LengthType)2048U,  /* FlsSector_11 */
    (Fls_LengthType)2048U,  /* FlsSector_12 */
    (Fls_LengthType)2048U,  /* FlsSector_13 */
    (Fls_LengthType)2048U,  /* FlsSector_14 */
    (Fls_LengthType)2048U,  /* FlsSector_15 */
    (Fls_LengthType)2048U,  /* FlsSector_16 */
    (Fls_LengthType)2048U,  /* FlsSector_17 */
    (Fls_LengthType)2048U,  /* FlsSector_18 */
    (Fls_LengthType)2048U,  /* FlsSector_19 */
    (Fls_LengthType)2048U,  /* FlsSector_20 */
    (Fls_LengthType)2048U,  /* FlsSector_21 */
    (Fls_LengthType)2048U,  /* FlsSector_22 */
    (Fls_LengthType)2048U,  /* FlsSector_23 */
    (Fls_LengthType)2048U,  /* FlsSector_24 */
    (Fls_LengthType)2048U,  /* FlsSector_25 */
    (Fls_LengthType)2048U,  /* FlsSector_26 */
    (Fls_LengthType)2048U,  /* FlsSector_27 */
    (Fls_LengthType)2048U,  /* FlsSector_28 */
    (Fls_LengthType)2048U,  /* FlsSector_29 */
    (Fls_LengthType)2048U,  /* FlsSector_30 */
    (Fls_LengthType)2048U   /* FlsSector_31 */
};

/* paSectorPageSize */
static const Fls_LengthType FlsConfigSet_TDK_4G_aFlsSectorPageSize[32U] =
{
    (Fls_LengthType)8U,  /* FlsSector_0 */
    (Fls_LengthType)8U,  /* FlsSector_1 */
    (Fls_LengthType)8U,  /* FlsSector_2 */
    (Fls_LengthType)8U,  /* FlsSector_3 */
    (Fls_LengthType)8U,  /* FlsSector_4 */
    (Fls_LengthType)8U,  /* FlsSector_5 */
    (Fls_LengthType)8U,  /* FlsSector_6 */
    (Fls_LengthType)8U,  /* FlsSector_7 */
    (Fls_LengthType)8U,  /* FlsSector_8 */
    (Fls_LengthType)8U,  /* FlsSector_9 */
    (Fls_LengthType)8U,  /* FlsSector_10 */
    (Fls_LengthType)8U,  /* FlsSector_11 */
    (Fls_LengthType)8U,  /* FlsSector_12 */
    (Fls_LengthType)8U,  /* FlsSector_13 */
    (Fls_LengthType)8U,  /* FlsSector_14 */
    (Fls_LengthType)8U,  /* FlsSector_15 */
    (Fls_LengthType)8U,  /* FlsSector_16 */
    (Fls_LengthType)8U,  /* FlsSector_17 */
    (Fls_LengthType)8U,  /* FlsSector_18 */
    (Fls_LengthType)8U,  /* FlsSector_19 */
    (Fls_LengthType)8U,  /* FlsSector_20 */
    (Fls_LengthType)8U,  /* FlsSector_21 */
    (Fls_LengthType)8U,  /* FlsSector_22 */
    (Fls_LengthType)8U,  /* FlsSector_23 */
    (Fls_LengthType)8U,  /* FlsSector_24 */
    (Fls_LengthType)8U,  /* FlsSector_25 */
    (Fls_LengthType)8U,  /* FlsSector_26 */
    (Fls_LengthType)8U,  /* FlsSector_27 */
    (Fls_LengthType)8U,  /* FlsSector_28 */
    (Fls_LengthType)8U,  /* FlsSector_29 */
    (Fls_LengthType)8U,  /* FlsSector_30 */
    (Fls_LengthType)8U   /* FlsSector_31 */
};

/* Info structure (reg prot, ecc trigger, etc) for each internal flash sector. */
static const Fls_Flash_InternalSectorInfoType FlsSector_0_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x000000UL),  /* pSectorStartAddressPtr */
    0U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_1_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x000800UL),  /* pSectorStartAddressPtr */
    1U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_2_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x001000UL),  /* pSectorStartAddressPtr */
    2U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_3_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x001800UL),  /* pSectorStartAddressPtr */
    3U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_4_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x002000UL),  /* pSectorStartAddressPtr */
    4U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_5_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x002800UL),  /* pSectorStartAddressPtr */
    5U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_6_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x003000UL),  /* pSectorStartAddressPtr */
    6U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_7_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x003800UL),  /* pSectorStartAddressPtr */
    7U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_8_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x004000UL),  /* pSectorStartAddressPtr */
    8U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_9_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x004800UL),  /* pSectorStartAddressPtr */
    9U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_10_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x005000UL),  /* pSectorStartAddressPtr */
    10U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_11_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x005800UL),  /* pSectorStartAddressPtr */
    11U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_12_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x006000UL),  /* pSectorStartAddressPtr */
    12U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_13_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x006800UL),  /* pSectorStartAddressPtr */
    13U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_14_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x007000UL),  /* pSectorStartAddressPtr */
    14U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_15_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x007800UL),  /* pSectorStartAddressPtr */
    15U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_16_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x008000UL),  /* pSectorStartAddressPtr */
    16U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_17_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x008800UL),  /* pSectorStartAddressPtr */
    17U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_18_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x009000UL),  /* pSectorStartAddressPtr */
    18U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_19_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x009800UL),  /* pSectorStartAddressPtr */
    19U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_20_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x00A000UL),  /* pSectorStartAddressPtr */
    20U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_21_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x00A800UL),  /* pSectorStartAddressPtr */
    21U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_22_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x00B000UL),  /* pSectorStartAddressPtr */
    22U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_23_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x00B800UL),  /* pSectorStartAddressPtr */
    23U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_24_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x00C000UL),  /* pSectorStartAddressPtr */
    24U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_25_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x00C800UL),  /* pSectorStartAddressPtr */
    25U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_26_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x00D000UL),  /* pSectorStartAddressPtr */
    26U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_27_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x00D800UL),  /* pSectorStartAddressPtr */
    27U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_28_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x00E000UL),  /* pSectorStartAddressPtr */
    28U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_29_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x00E800UL),  /* pSectorStartAddressPtr */
    29U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_30_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x00F000UL),  /* pSectorStartAddressPtr */
    30U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_31_FlsConfigSet_TDK_4G_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x00F800UL),  /* pSectorStartAddressPtr */
    31U  /* Sector location to calculate cfgCRC */
};


/* FLASH physical sectorization description */
static const Fls_Flash_InternalSectorInfoType * const FlsConfigSet_TDK_4G_aSectorList[32U] =
{
    &FlsSector_0_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S000 */
    &FlsSector_1_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S001 */
    &FlsSector_2_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S002 */
    &FlsSector_3_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S003 */
    &FlsSector_4_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S004 */
    &FlsSector_5_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S005 */
    &FlsSector_6_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S006 */
    &FlsSector_7_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S007 */
    &FlsSector_8_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S008 */
    &FlsSector_9_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S009 */
    &FlsSector_10_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S010 */
    &FlsSector_11_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S011 */
    &FlsSector_12_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S012 */
    &FlsSector_13_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S013 */
    &FlsSector_14_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S014 */
    &FlsSector_15_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S015 */
    &FlsSector_16_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S016 */
    &FlsSector_17_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S017 */
    &FlsSector_18_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S018 */
    &FlsSector_19_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S019 */
    &FlsSector_20_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S020 */
    &FlsSector_21_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S021 */
    &FlsSector_22_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S022 */
    &FlsSector_23_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S023 */
    &FlsSector_24_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S024 */
    &FlsSector_25_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S025 */
    &FlsSector_26_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S026 */
    &FlsSector_27_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S027 */
    &FlsSector_28_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S028 */
    &FlsSector_29_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S029 */
    &FlsSector_30_FlsConfigSet_TDK_4G_sInternalSectorInfo,  /* FLS_DATA_ARRAY_0_BLOCK_1_S030 */
    &FlsSector_31_FlsConfigSet_TDK_4G_sInternalSectorInfo   /* FLS_DATA_ARRAY_0_BLOCK_1_S031 */
};

/* paHwCh */
static const Fls_HwChType FlsConfigSet_TDK_4G_paHwCh[32U] =
{
    FLS_CH_INTERN,  /* FlsSector_0 */
    FLS_CH_INTERN,  /* FlsSector_1 */
    FLS_CH_INTERN,  /* FlsSector_2 */
    FLS_CH_INTERN,  /* FlsSector_3 */
    FLS_CH_INTERN,  /* FlsSector_4 */
    FLS_CH_INTERN,  /* FlsSector_5 */
    FLS_CH_INTERN,  /* FlsSector_6 */
    FLS_CH_INTERN,  /* FlsSector_7 */
    FLS_CH_INTERN,  /* FlsSector_8 */
    FLS_CH_INTERN,  /* FlsSector_9 */
    FLS_CH_INTERN,  /* FlsSector_10 */
    FLS_CH_INTERN,  /* FlsSector_11 */
    FLS_CH_INTERN,  /* FlsSector_12 */
    FLS_CH_INTERN,  /* FlsSector_13 */
    FLS_CH_INTERN,  /* FlsSector_14 */
    FLS_CH_INTERN,  /* FlsSector_15 */
    FLS_CH_INTERN,  /* FlsSector_16 */
    FLS_CH_INTERN,  /* FlsSector_17 */
    FLS_CH_INTERN,  /* FlsSector_18 */
    FLS_CH_INTERN,  /* FlsSector_19 */
    FLS_CH_INTERN,  /* FlsSector_20 */
    FLS_CH_INTERN,  /* FlsSector_21 */
    FLS_CH_INTERN,  /* FlsSector_22 */
    FLS_CH_INTERN,  /* FlsSector_23 */
    FLS_CH_INTERN,  /* FlsSector_24 */
    FLS_CH_INTERN,  /* FlsSector_25 */
    FLS_CH_INTERN,  /* FlsSector_26 */
    FLS_CH_INTERN,  /* FlsSector_27 */
    FLS_CH_INTERN,  /* FlsSector_28 */
    FLS_CH_INTERN,  /* FlsSector_29 */
    FLS_CH_INTERN,  /* FlsSector_30 */
    FLS_CH_INTERN   /* FlsSector_31 */
};

/* paSectorHwAddress */
static const Fls_AddressType FlsConfigSet_TDK_4G_paSectorHwAddress[32U] =
{
    (Fls_AddressType)0U,  /* FlsSector_0 */
    (Fls_AddressType)0U,  /* FlsSector_1 */
    (Fls_AddressType)0U,  /* FlsSector_2 */
    (Fls_AddressType)0U,  /* FlsSector_3 */
    (Fls_AddressType)0U,  /* FlsSector_4 */
    (Fls_AddressType)0U,  /* FlsSector_5 */
    (Fls_AddressType)0U,  /* FlsSector_6 */
    (Fls_AddressType)0U,  /* FlsSector_7 */
    (Fls_AddressType)0U,  /* FlsSector_8 */
    (Fls_AddressType)0U,  /* FlsSector_9 */
    (Fls_AddressType)0U,  /* FlsSector_10 */
    (Fls_AddressType)0U,  /* FlsSector_11 */
    (Fls_AddressType)0U,  /* FlsSector_12 */
    (Fls_AddressType)0U,  /* FlsSector_13 */
    (Fls_AddressType)0U,  /* FlsSector_14 */
    (Fls_AddressType)0U,  /* FlsSector_15 */
    (Fls_AddressType)0U,  /* FlsSector_16 */
    (Fls_AddressType)0U,  /* FlsSector_17 */
    (Fls_AddressType)0U,  /* FlsSector_18 */
    (Fls_AddressType)0U,  /* FlsSector_19 */
    (Fls_AddressType)0U,  /* FlsSector_20 */
    (Fls_AddressType)0U,  /* FlsSector_21 */
    (Fls_AddressType)0U,  /* FlsSector_22 */
    (Fls_AddressType)0U,  /* FlsSector_23 */
    (Fls_AddressType)0U,  /* FlsSector_24 */
    (Fls_AddressType)0U,  /* FlsSector_25 */
    (Fls_AddressType)0U,  /* FlsSector_26 */
    (Fls_AddressType)0U,  /* FlsSector_27 */
    (Fls_AddressType)0U,  /* FlsSector_28 */
    (Fls_AddressType)0U,  /* FlsSector_29 */
    (Fls_AddressType)0U,  /* FlsSector_30 */
    (Fls_AddressType)0U   /* FlsSector_31 */
};



/**
* @brief        Structure used to set function pointers notification, working mode
*/
/* Fls module initialization data (FlsConfigSet)*/
const Fls_ConfigType Fls_Config_TDK_4G =
{
    (Fls_AcErasePtrType)NULL_PTR,                                     /* FlsAcErase */
    (Fls_AcWritePtrType)NULL_PTR,                                     /* FlsAcWrite */
    NULL_PTR,                                                         /* FlsACCallback */
    &Fee_JobEndNotification,                                          /* FlsJobEndNotification */
    &Fee_JobErrorNotification,                                        /* FlsJobErrorNotification */
    NULL_PTR,                                                         /* FlsReadFunctionCallout */
    MEMIF_MODE_SLOW,                                                  /* FlsDefaultMode */
    1048576U,                                                         /* FlsMaxReadFastMode */
    1024U,                                                            /* FlsMaxReadNormalMode */
    256U,                                                             /* FlsMaxWriteFastMode */
    8U,                                                               /* FlsMaxWriteNormalMode */
    32U,                                                              /* FlsSectorCount */
    &FlsConfigSet_TDK_4G_aFlsSectorEndAddr,                           /* (*paSectorEndAddr)[] */
    &FlsConfigSet_TDK_4G_aFlsSectorSize,                              /* (*paSectorSize)[] */
    &FlsConfigSet_TDK_4G_aSectorList,                                 /* (*pSectorList)[] */
    &FlsConfigSet_TDK_4G_aFlsSectorFlags,                             /* (*paSectorFlags)[] */
    &FlsConfigSet_TDK_4G_aFlsSectorPageSize,                          /* (*paSectorPageSize)[] */
    &FlsConfigSet_TDK_4G_paHwCh,                                      /* (*paHwCh)[] */
    &FlsConfigSet_TDK_4G_paSectorHwAddress,                           /* (*paSectorHwAddress)[] */
    NULL_PTR,                                                         /* FlsQspiConfig */
    &FlsConfigSet_TDK_4G_InitCfg,                                     /* FlsInternalConfig */
    47452U                                                            /* configCrc */
};


#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/

