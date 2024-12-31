/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef INTCTRL_IP_CFG_DEFINES_H_
#define INTCTRL_IP_CFG_DEFINES_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"
#ifdef SJA1110
#include "SJA1110.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_INTCTRL_IP_CFG_DEFINES_VENDOR_ID                          43
#define PLATFORM_INTCTRL_IP_CFG_DEFINES_SW_MAJOR_VERSION                   1
#define PLATFORM_INTCTRL_IP_CFG_DEFINES_SW_MINOR_VERSION                   0
#define PLATFORM_INTCTRL_IP_CFG_DEFINES_SW_PATCH_VERSION                   1
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* CPU to CPU interrupt (MSI) routing through MSCM */
[!NOCODE!][!// Include headers for System_Ip_DeviceRegister.h
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!// 
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName, 'S32G2')"!][!//  
        [!CODE!][!WS "0"!]    
        #include "S32G274A_NVIC.h"
        #include "S32G274A_MSCM.h"
        #include "S32G274A_SCB.h"
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32G3')"!][!//  
        [!CODE!][!WS "0"!]    
        #include "S32G399A_NVIC.h"
        #include "S32G399A_MSCM.h"
        #include "S32G399A_SCB.h"
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K3')"!][!//  
        [!CODE!][!WS "0"!]
#ifdef S32K344
        #include "S32K344_NVIC.h"
        #include "S32K344_MSCM.h"
        #include "S32K344_SCB.h"
#endif
#ifdef S32K342
        #include "S32K342_NVIC.h"
        #include "S32K342_MSCM.h"
        #include "S32K342_SCB.h"
#endif
#ifdef S32K324
        #include "S32K324_NVIC.h"
        #include "S32K324_MSCM.h"
        #include "S32K324_SCB.h"
#endif 
#ifdef S32K314
        #include "S32K314_NVIC.h"
        #include "S32K314_MSCM.h"
        #include "S32K314_SCB.h"
#endif
#ifdef S32K312
        #include "S32K312_NVIC.h"
        #include "S32K312_MSCM.h"
        #include "S32K312_SCB.h"
#endif    

       
        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'S32R45')"!][!//   
        [!CODE!][!WS "0"!]
        #include "S32R45_NVIC.h"
        #include "S32R45_MSCM.h"
        #include "S32R45_SCB.h"
        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'S32R41')"!][!//   
        [!CODE!][!WS "0"!]
        #include "[!"$DerivativeName"!].h"
        #include "S32R41_NVIC.h"
        #include "S32R41_MSCM.h"
        #include "S32R41_SCB.h"

        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'SAF85')"!][!//   
        [!CODE!][!WS "0"!]
        #include "SAF85XX.h"
        #include "SAF85XX_NVIC.h"
        #include "SAF85XX_MSCM.h"
        #include "SAF85XX_SCB.h"

#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)        
        typedef struct {
            __IO uint32_t IntStatusR;  /**< Interrupt Router CPn Interruptx Status Register, array offset: 0x200, index*0x20, index2*0x8 */
            __O  uint32_t IGR;  /**< Interrupt Router CPn Interruptx Generation Register, array offset: 0x204, index*0x20, index2*0x8 */
        } MSCM_IRCP_IR_Type;

        typedef struct {
            MSCM_IRCP_IR_Type IRCPnIRx[4][4];
        } MSCM_IRCPnIRx_Type;

        #define MSCM_IRCPnIRx ((volatile MSCM_IRCPnIRx_Type*)&IP_MSCM->IRCP0ISR0)
#endif
        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'S32K1')"!][!//
        [!CODE!][!WS "0"!]
        #include "[!"$DerivativeName"!].h"
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'sja1110')"!][!//
        [!CODE!][!WS "0"!]
        #include "[!"$DerivativeName"!].h"
        [!CR!][!ENDCODE!][!//       
    [!ELSEIF "contains($DerivativeName, 'S32E2')"!][!//
        [!CODE!][!WS "0"!]
        #include "[!"$DerivativeName"!].h"       
        #define IRQn_Type IRQn_Type    
        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'S32Z2')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32Z27.h"
        #define IRQn_Type IRQn_Type    
        [!CR!][!ENDCODE!][!//                
    [!ENDIF!][!// 
[!ENDIF!][!// 
[!ENDNOCODE!][!//


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Development error detection */
#define INT_CTRL_IP_DEV_ERROR_DETECT  ([!IF "GeneralConfiguration/PlatformDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


/* MSI target core count */
#define INTCTRL_IP_MSI_CORE_CNT                   ([!"ecu:get('Platform.msiCoresCnt')"!]U)

/* MSI vector min */
#define INTCTRL_IP_DIRECTED_CPU_INT_MIN           ([!"ecu:get('Platform.msiIrqMin')"!])

/* MSI vector max */
#define INTCTRL_IP_DIRECTED_CPU_INT_MAX           ([!"ecu:get('Platform.msiIrqMax')"!])

/* VTOR address configuration enable */
#define INTCTRL_IP_ENABLE_VTOR_CONFIG             ([!IF "GeneralConfiguration/PlatformEnableVtorConfiguration"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Core count */
#define INTCTRL_IP_CORE_MASK                      ([!"num:i(ecu:get('Platform.coreMask'))"!]U)

/* System interrupt routing through MSCM */
#define INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER  ([!IF "GeneralConfiguration/PlatformMscmConfigurable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* INCT CTRL IP standalone APIs */
#define INT_CTRL_IP_STANDALONE_APIS               ([!IF "GeneralConfiguration/PlatformIpAPIsAvailable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    /* First implemented interrupt vector */
    #define INT_CTRL_IP_IRQ_MIN                       ([!"ecu:list('Platform.irqsList')[position()=1]"!])
    [!VAR "maxIrq" = "ecu:get('Platform.irqCount')"!]
    /* Last implemented interrupt vector */
    #define INT_CTRL_IP_IRQ_MAX                       ([!"ecu:list('Platform.irqsList')[position()=$maxIrq]"!])  
    /* The interrupt counter value*/
    #define INT_CTRL_IP_IRQ_COUNT                     ([!"ecu:get('Platform.irqCount')"!]U)
    /* Arm Cortex M4 */
    #define INT_CTRL_IP_CORTEXM                      ([!"ecu:get('Platform.ArmCortexM')"!])
    #define INT_CTRL_IP_CORTEXR      STD_OFF
    #define INT_CTRL_IP_CORTEXA      STD_OFF   

 
/* Number of priority bits implemented */
#define INT_CTRL_IP_NVIC_PRIO_BITS                ([!"ecu:get('Platform.irqPrioBits')"!]U)

/*Interrupt Router Shared Peripheral Routing Control Register*/
#define INT_CTRL_IP_ROUTING_CONTROL_REGISTER      ([!"ecu:get('Platform.mscmIrqRouter')"!])

/* This instruction invalidates the entire instruction cache or caches */
#define INT_CTRL_IP_INVALIDATE_CACHE              ([!"ecu:get('Platform.InvalidateCache')"!])


/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the Int Ctrl PLATFORM driver code can be executed from both supervisor and user mode.
*/
[!IF "(GeneralConfiguration/PlatformEnableUserModeSupport)"!][!//
#define INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT   (STD_ON)
[!ELSE!]
#define INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT   (STD_OFF)
[!ENDIF!]

#endif /* INTCTRL_IP_CFG_DEFINES_H_ */

