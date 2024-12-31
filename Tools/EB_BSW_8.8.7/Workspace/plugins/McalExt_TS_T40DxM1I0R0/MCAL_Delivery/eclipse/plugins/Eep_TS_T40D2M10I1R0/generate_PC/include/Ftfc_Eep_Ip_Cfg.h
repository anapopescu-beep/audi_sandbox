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

#ifndef FTFC_EEP_IP_CFG_H
#define FTFC_EEP_IP_CFG_H

/**
*   @file Ftfc_Eep_Ip_Cfg.h
*
*   @addtogroup FTFC_EEP_IP
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

[!NOCODE!][!//
[!IF "ecu:get('Eep.HTChip')"!][!//
    [!VAR "HwUnit" = "'FTFM'"!][!//
[!ELSE!][!//
    [!VAR "HwUnit" = "'FTFC'"!][!//
[!ENDIF!][!//

[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//

    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k116')"!][!//
        [!CODE!][!WS "0"!]#include "S32K116_FTFC.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "S32K116_SIM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k118')"!][!//
        [!CODE!][!WS "0"!]#include "S32K118_FTFC.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "S32K118_SIM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k142w')"!][!//
        [!CODE!][!WS "0"!]#include "S32K142W_FTFM.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "S32K142W_SIM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k142')"!][!//
        [!CODE!][!WS "0"!]#include "S32K142_FTFC.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "S32K142_SIM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k144w')"!][!//
        [!CODE!][!WS "0"!]#include "S32K144W_FTFM.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "S32K144W_SIM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k144')"!][!//
        [!CODE!][!WS "0"!]#include "S32K144_FTFC.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "S32K144_SIM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k146')"!][!//
        [!CODE!][!WS "0"!]#include "S32K146_FTFC.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "S32K146_SIM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k148')"!][!//
        [!CODE!][!WS "0"!]#include "S32K148_FTFC.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "S32K148_SIM.h"[!CR!][!ENDCODE!][!//
    [!ELSE!][!//
        [!ERROR "The Resource plugin or ResourceSubderivative field is not available for header file inclusion."!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!ERROR "The Resource plugin or ResourceSubderivative field is not available for header file inclusion."!][!//
[!ENDIF!][!//

[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
[!CODE!]#include "Ftfc_Eep_Ip_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!][!//
[!ENDLOOP!][!//
[!ELSE!][!//
[!CODE!]#include "Ftfc_Eep_Ip_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDIF!][!//

[!CODE!]#include "Ftfc_Eep_Ip_Types.h"[!CR!][!ENDCODE!]

[!SELECT "./EepFtfcCfg/*[1]"!][!//
[!IF "EepFtfcIpDevErrorDetect"!][!CODE!]#include "Devassert.h"[!CR!][!ENDCODE!][!ENDIF!]
[!ENDSELECT!][!//

[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_EEP_IP_CFG_VENDOR_ID_H                    43
#define FTFC_EEP_IP_CFG_AR_RELEASE_MAJOR_VERSION_H     4
#define FTFC_EEP_IP_CFG_AR_RELEASE_MINOR_VERSION_H     4
#define FTFC_EEP_IP_CFG_AR_RELEASE_REVISION_VERSION_H  0
#define FTFC_EEP_IP_CFG_SW_MAJOR_VERSION_H             1
#define FTFC_EEP_IP_CFG_SW_MINOR_VERSION_H             0
#define FTFC_EEP_IP_CFG_SW_PATCH_VERSION_H             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
/* Version checks for Ftfc_Eep_Ip_VS_#_PBcfg.h */
#if (FTFC_EEP_IP_CFG_VENDOR_ID_H != FTFC_EEP_IP_[!"."!]_PBCFG_VENDOR_ID_H)
    #error "Ftfc_Eep_Ip.h and Ftfc_Eep_Ip_[!"."!]_PBcfg.h have different vendor IDs!"
#endif
#if ((FTFC_EEP_IP_CFG_AR_RELEASE_MAJOR_VERSION_H    != FTFC_EEP_IP_[!"."!]_PBCFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (FTFC_EEP_IP_CFG_AR_RELEASE_MINOR_VERSION_H    != FTFC_EEP_IP_[!"."!]_PBCFG_AR_RELEASE_MINOR_VERSION_H) || \
     (FTFC_EEP_IP_CFG_AR_RELEASE_REVISION_VERSION_H != FTFC_EEP_IP_[!"."!]_PBCFG_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "Ftfc_Eep_Ip.h and Ftfc_Eep_Ip_[!"."!]_PBcfg.h are for different AUTOSAR versions!"
#endif
#if ((FTFC_EEP_IP_CFG_SW_MAJOR_VERSION_H != FTFC_EEP_IP_[!"."!]_PBCFG_SW_MAJOR_VERSION_H) || \
     (FTFC_EEP_IP_CFG_SW_MINOR_VERSION_H != FTFC_EEP_IP_[!"."!]_PBCFG_SW_MINOR_VERSION_H) || \
     (FTFC_EEP_IP_CFG_SW_PATCH_VERSION_H != FTFC_EEP_IP_[!"."!]_PBCFG_SW_PATCH_VERSION_H)    \
    )
    #error "Ftfc_Eep_Ip.h and Ftfc_Eep_Ip_[!"."!]_PBcfg.h have different SW versions!"
#endif
[!ENDLOOP!][!//

[!ELSE!][!//
/* Version checks for Ftfc_Eep_Ip_PBcfg.h */
#if (FTFC_EEP_IP_CFG_VENDOR_ID_H != FTFC_EEP_IP_PBCFG_VENDOR_ID_H)
    #error "Ftfc_Eep_Ip.h and Ftfc_Eep_Ip_PBcfg.h have different vendor IDs!"
#endif
#if ((FTFC_EEP_IP_CFG_AR_RELEASE_MAJOR_VERSION_H    != FTFC_EEP_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (FTFC_EEP_IP_CFG_AR_RELEASE_MINOR_VERSION_H    != FTFC_EEP_IP_PBCFG_AR_RELEASE_MINOR_VERSION_H) || \
     (FTFC_EEP_IP_CFG_AR_RELEASE_REVISION_VERSION_H != FTFC_EEP_IP_PBCFG_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "Ftfc_Eep_Ip.h and Ftfc_Eep_Ip_PBcfg.h are for different AUTOSAR versions!"
#endif
#if ((FTFC_EEP_IP_CFG_SW_MAJOR_VERSION_H != FTFC_EEP_IP_PBCFG_SW_MAJOR_VERSION_H) || \
     (FTFC_EEP_IP_CFG_SW_MINOR_VERSION_H != FTFC_EEP_IP_PBCFG_SW_MINOR_VERSION_H) || \
     (FTFC_EEP_IP_CFG_SW_PATCH_VERSION_H != FTFC_EEP_IP_PBCFG_SW_PATCH_VERSION_H)    \
    )
    #error "Ftfc_Eep_Ip.h and Ftfc_Eep_Ip_PBcfg.h have different SW versions!"
#endif

[!ENDIF!][!//
/* Version checks for Ftfc_Eep_Ip_Types.h */
#if (FTFC_EEP_IP_CFG_VENDOR_ID_H != FTFC_EEP_IP_TYPES_VENDOR_ID_H)
    #error "Ftfc_Eep_Ip_Cfg.h and Ftfc_Eep_Ip_Types.h have different vendor IDs!"
#endif
#if ((FTFC_EEP_IP_CFG_AR_RELEASE_MAJOR_VERSION_H    != FTFC_EEP_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (FTFC_EEP_IP_CFG_AR_RELEASE_MINOR_VERSION_H    != FTFC_EEP_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (FTFC_EEP_IP_CFG_AR_RELEASE_REVISION_VERSION_H != FTFC_EEP_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "Ftfc_Eep_Ip_Cfg.h and Ftfc_Eep_Ip_Types.h are for different AUTOSAR versions!"
#endif
#if ((FTFC_EEP_IP_CFG_SW_MAJOR_VERSION_H != FTFC_EEP_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (FTFC_EEP_IP_CFG_SW_MINOR_VERSION_H != FTFC_EEP_IP_TYPES_SW_MINOR_VERSION_H) || \
     (FTFC_EEP_IP_CFG_SW_PATCH_VERSION_H != FTFC_EEP_IP_TYPES_SW_PATCH_VERSION_H)    \
    )
    #error "Ftfc_Eep_Ip_Cfg.h and Ftfc_Eep_Ip_Types.h have different SW versions!"
#endif

[!IF "./EepFtfcCfg/*[1]/EepFtfcIpDevErrorDetect"!][!//
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Version checks for Devassert.h */
    #if ((FTFC_EEP_IP_CFG_AR_RELEASE_MAJOR_VERSION_H != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (FTFC_EEP_IP_CFG_AR_RELEASE_MINOR_VERSION_H != DEVASSERT_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Ftfc_Eep_Ip_Cfg.h and Devassert.h are different"
    #endif
#endif
[!ENDIF!][!//

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

[!SELECT "./EepFtfcCfg/*[1]"!][!//

/** FlexRAM base address */
#define FTFC_EEP_IP_FLEXRAM_ADDRESS         [!"(num:inttohex(ecu:get('Eep.EepBaseAddressvalue')))"!]U

/** Total size of EEP */
#define FTFC_EEP_IP_EEP_SIZE                [!"node:value(./EepFtfcSize)"!]U

/** If this is a HT chip derivative the FTFM registers will be used - instead of FTFC. */
#define FTFC_EEP_IP_HIGH_TEMP_CHIP          [!IF "ecu:get('Eep.HTChip')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/** STD_ON: Access code loaded on job start / unloaded on job end or error */
#define FTFC_EEP_IP_LOAD_AC_INTO_RAM        [!IF "EepFtfcAcLoadToRam"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/** API for comparing a RAM region with the contents of an EEP region */
#define FTFC_EEP_IP_COMPARE_API             [!IF "EepFtfcEnableCompareApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/** Enable / disable the QuickWrites mode */
#define FTFC_EEP_IP_QUICK_WRITES_API        [!IF "EepFtfcEnableQuickWriteApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/** Check if source is aligned with half-word and word access. */
#define FTFC_EEP_IP_ALIGNED_RAM_ACCESS      [!IF "EepFtfcCheckAlignmentEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/** OsIf counter type used in timeout detection */
#define FTFC_EEP_IP_TIMEOUT_TYPE            [!"node:value(./EepTimeoutMethod)"!]
#define FTFC_EEP_IP_ABORT_TIMEOUT           [!"node:value(./EepFtfcAbortTimeout)"!]U
#define FTFC_EEP_IP_ASYNC_WRITE_TIMEOUT     [!"node:value(./EepFtfcAsyncWriteTimeout)"!]U
#define FTFC_EEP_IP_SYNC_WRITE_TIMEOUT      [!"node:value(./EepFtfcSyncWriteTimeout)"!]U

/** This macro can be used to deactivate the DEV_ASSERTs */
#define FTFC_EEP_IP_DEV_ERROR_DETECT        [!IF "EepFtfcIpDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/** Toggle the development errors detection. */
#define FTFC_DEV_ASSERT(X)                  [!IF "EepFtfcIpDevErrorDetect"!]DevAssert((X))[!ENDIF!][!CR!]
[!ENDSELECT!][!//

#define IP_EEPROM                           IP_[!"$HwUnit"!]                        /**< ptr to the IP_FTFM structure                                               */
#define FCNFG_EEERDY_MASK                   [!"$HwUnit"!]_FCNFG_EEERDY_MASK         /**< set when FlexRAM is ready for emulated EEPROM operations                   */
#define FSTAT_CCIF_MASK                     [!"$HwUnit"!]_FSTAT_CCIF_MASK           /**< zero while a FTFC command or an EEPROM operation is in progress            */
#define FSTAT_ACCERR_MASK                   [!"$HwUnit"!]_FSTAT_ACCERR_MASK         /**< flash access error flag                                                    */
#define FSTAT_FPVIOL_MASK                   [!"$HwUnit"!]_FSTAT_FPVIOL_MASK         /**< a write was attempted to a protected area                                  */
#define FSTAT_RDCOLERR_MASK                 [!"$HwUnit"!]_FSTAT_RDCOLERR_MASK       /**< collision over a FTFC resource that was being manipulated by a command     */
#define FSTAT_MGSTAT0_MASK                  [!"$HwUnit"!]_FSTAT_MGSTAT0_MASK        /**< set if an error is detected during execution of an FTFC command            */

#if (FTFC_EEP_IP_HIGH_TEMP_CHIP == STD_ON)
#define FSTAT_MGSTAT1_MASK                  FTFM_FSTAT_MGSTAT1_MASK        /**< uncorrectable ECC fault was detected during execution of a flash command   */
#define FSTAT_MGSTAT2_MASK                  FTFM_FSTAT_MGSTAT2_MASK        /**< uncorrectable ECC fault was detected during emulated EEPROM initialization */
#define FSTAT_MGSTAT3_MASK                  FTFM_FSTAT_MGSTAT3_MASK        /**< uncorrectable ECC fault was detected during the flash reset sequence       */
#endif
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
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

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTFC_EEP_IP_CFG_H */
