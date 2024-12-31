/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IPV_FTFC
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

#ifndef EEP_IPW_H
#define EEP_IPW_H

/**
*  @file Eep_IPW.h
*
*  @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eep_InternalTypes.h"
#include "Ftfc_Eep_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_IPW_VENDOR_ID_H                    43
#define EEP_IPW_AR_RELEASE_MAJOR_VERSION_H     4
#define EEP_IPW_AR_RELEASE_MINOR_VERSION_H     4
#define EEP_IPW_AR_RELEASE_REVISION_VERSION_H  0
#define EEP_IPW_SW_MAJOR_VERSION_H             1
#define EEP_IPW_SW_MINOR_VERSION_H             0
#define EEP_IPW_SW_PATCH_VERSION_H             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Version checks for Eep_InternalTypes.h */
#if (EEP_IPW_VENDOR_ID_H != EEP_INTERNALTYPES_VENDOR_ID)
    #error "Eep_IPW.h and Eep_InternalTypes.h have different vendor ids"
#endif
#if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_H    != EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_IPW_AR_RELEASE_MINOR_VERSION_H    != EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION) || \
     (EEP_IPW_AR_RELEASE_REVISION_VERSION_H != EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep_IPW.h and Eep_InternalTypes.h are different"
#endif
#if ((EEP_IPW_SW_MAJOR_VERSION_H != EEP_INTERNALTYPES_SW_MAJOR_VERSION) || \
     (EEP_IPW_SW_MINOR_VERSION_H != EEP_INTERNALTYPES_SW_MINOR_VERSION) || \
     (EEP_IPW_SW_PATCH_VERSION_H != EEP_INTERNALTYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_IPW.h and Eep_InternalTypes.h are different"
#endif

/* Version checks for Ftfc_Eep_Ip.h */
#if (EEP_IPW_VENDOR_ID_H != FTFC_EEP_IP_VENDOR_ID_H)
    #error "Eep_IPW.h and Ftfc_Eep_Ip.h have different vendor IDs!"
#endif
#if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_H    != FTFC_EEP_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (EEP_IPW_AR_RELEASE_MINOR_VERSION_H    != FTFC_EEP_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (EEP_IPW_AR_RELEASE_REVISION_VERSION_H != FTFC_EEP_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "Eep_IPW.h and Ftfc_Eep_Ip.h are for different AUTOSAR versions!"
#endif
#if ((EEP_IPW_SW_MAJOR_VERSION_H != FTFC_EEP_IP_SW_MAJOR_VERSION_H) || \
     (EEP_IPW_SW_MINOR_VERSION_H != FTFC_EEP_IP_SW_MINOR_VERSION_H) || \
     (EEP_IPW_SW_PATCH_VERSION_H != FTFC_EEP_IP_SW_PATCH_VERSION_H) \
    )
    #error "Eep_IPW.h and Ftfc_Eep_Ip.h have different SW versions!"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define EEP_START_SEC_CODE
#include "Eep_MemMap.h"

Eep_ReturnType Eep_Ipw_Init (Eep_ConfigType const * pxEepConfig);

Std_ReturnType Eep_Ipw_CheckReadParams (Eep_AddressType SrcAddress,
                                        uint8 const * pu8DestAddress,
                                        Eep_LengthType Length
                                       );
Eep_ReturnType Eep_Ipw_Read (Eep_AddressType SrcAddress,
                             uint8 * pu8DestAddress,
                             Eep_LengthType Length
                            );

#if (EEP_COMPARE_API == STD_ON)
Std_ReturnType Eep_Ipw_CheckCompareParams (Eep_AddressType SrcAddress,
                                           uint8 const * pu8DestAddress,
                                           Eep_LengthType Length
                                          );
Eep_ReturnType Eep_Ipw_CompareSync (Eep_AddressType SrcAddress,
                                    uint8 const * pu8DestAddress,
                                    Eep_LengthType Length
                                   );
#endif

Std_ReturnType Eep_Ipw_CheckEraseParams (Eep_AddressType Address,
                                         Eep_LengthType Length
                                        );
Eep_ReturnType Eep_Ipw_Erase (Eep_AddressType Address,
                              Eep_LengthType Length
                             );

Std_ReturnType Eep_Ipw_CheckWriteParams (Eep_AddressType DestAddress,
                                         uint8 const * pu8SrcAddress,
                                         Eep_LengthType Length
                                        );
Eep_ReturnType Eep_Ipw_Write (Eep_AddressType DestAddress,
                              uint8 const * pu8SrcAddress,
                              Eep_LengthType Length
                             );

#if (EEP_QUICK_WRITES_API == STD_ON)
Std_ReturnType Eep_Ipw_CheckQuickWriteParams (Eep_AddressType DestAddress,
                                              uint8 const * pu8SrcAddress,
                                              Eep_LengthType Length,
                                              Eep_LengthType QuickWritesLength
                                             );
Eep_ReturnType Eep_Ipw_QuickWrite (Eep_AddressType DestAddress,
                                   uint8 const * pu8SrcAddress,
                                   Eep_LengthType Length
                                  );
#endif

#if (EEP_CANCEL_API == STD_ON)
Eep_ReturnType Eep_Ipw_Cancel (void);
#endif

#define EEP_STOP_SEC_CODE
#include "Eep_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* EEP_IPW_H */
