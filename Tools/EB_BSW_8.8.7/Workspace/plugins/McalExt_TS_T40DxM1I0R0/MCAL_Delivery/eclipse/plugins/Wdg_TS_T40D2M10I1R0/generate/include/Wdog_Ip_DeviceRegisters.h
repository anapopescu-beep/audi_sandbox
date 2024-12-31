/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Wdog,Ewm
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

#ifndef WDOG_IP_DEVICE_REGISTERS_H
#define WDOG_IP_DEVICE_REGISTERS_H

/**
*   @file
*
*   @addtogroup Wdog_Ip
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
[!NOCODE!][!// Include specific header file 
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!// 
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k142w')"!][!// 
[!CODE!][!WS "0"!]#include "S32K142W_WDOG.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k144w')"!][!// 
[!CODE!][!WS "0"!]#include "S32K144W_WDOG.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k116')"!][!// 
[!CODE!][!WS "0"!]#include "S32K116_WDOG.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k118')"!][!// 
[!CODE!][!WS "0"!]#include "S32K118_WDOG.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k142')"!][!// 
[!CODE!][!WS "0"!]#include "S32K142_WDOG.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k144')"!][!// 
[!CODE!][!WS "0"!]#include "S32K144_WDOG.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k146')"!][!// 
[!CODE!][!WS "0"!]#include "S32K146_WDOG.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k148')"!][!// 
[!CODE!][!WS "0"!]#include "S32K148_WDOG.h"[!CR!][!ENDCODE!][!// 
    [!ENDIF!][!// 
[!ENDIF!][!// 
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDOG_IP_DEVICE_REGISTERS_VENDOR_ID                    43
#define WDOG_IP_DEVICE_REGISTERS_MODULE_ID                    102
#define WDOG_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION     4
#define WDOG_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION     4
#define WDOG_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION  0
#define WDOG_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION             1
#define WDOG_IP_DEVICE_REGISTERS_SW_MINOR_VERSION             0
#define WDOG_IP_DEVICE_REGISTERS_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

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


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* WDOG_IP_DEVICE_REGISTERS_H */
