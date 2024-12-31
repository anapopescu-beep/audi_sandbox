/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : IPV_FTFC
* Dependencies : 
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 1.0.1
* Build Version : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
*
* (c) Copyright 2020-2022 NXP Semiconductors
* All Rights Reserved.
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef EEP_TYPES_H
#define EEP_TYPES_H

/**
* @file
*
* @addtogroup EEP_DRIVER Eeprom Driver
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "MemIf_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_TYPES_VENDOR_ID                    43
#define EEP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define EEP_TYPES_AR_RELEASE_MINOR_VERSION     4
#define EEP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define EEP_TYPES_SW_MAJOR_VERSION             1
#define EEP_TYPES_SW_MINOR_VERSION             0
#define EEP_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h file are of the same version */
    #if ((EEP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Eep_Types.h and Std_Types.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and MemIf_Types.h file are of the same version */
    #if ((EEP_TYPES_AR_RELEASE_MAJOR_VERSION != MEMIF_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_TYPES_AR_RELEASE_MINOR_VERSION != MEMIF_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Eep_Types.h and MemIf_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief          Eep Address Type.
* @details        Address offset from the configured eeprom base address to access a certain eeprom
*                 memory area.
* @implements Eep_AddressType_typedef
*/
typedef uint32 Eep_AddressType;

/**
* @brief          Eep Length Type.
* @details        Number of bytes to read,write,erase,compare
* @implements Eep_LengthType_typedef
*/
typedef uint32 Eep_LengthType;

/**
* @brief          Eep Job End Notification Pointer Type
* @details        Pointer type of Eep_JobEndNotification function
*
*/
typedef void (*Eep_JobEndNotificationPtrType)(void);

/**
* @brief          Eep Job Error Notification Pointer Type
* @details        Pointer type of Eep_JobErrorNotification function
*
*/
typedef void (*Eep_JobErrorNotificationPtrType)(void);

/**
* @brief          Eep CRC Type.
* @details        CRC computed over config set.
*
*/
typedef uint16 Eep_CrcType;

#ifdef __cplusplus
}
#endif

#endif /* EEP_TYPES_H */

/** @}*/
