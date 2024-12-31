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

#ifndef SYSTEM_IP_CFG_DEFINES_H_
#define SYSTEM_IP_CFG_DEFINES_H_
/**
*   @file
*
*   @addtogroup System_Ip
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"
#include "System_Ip_DeviceRegisters.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_SYSTEM_IP_CFG_DEFINES_TYPES_VENDOR_ID                    43
#define PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MAJOR_VERSION                   1
#define PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MINOR_VERSION                   0
#define PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_PATCH_VERSION                   1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and System_Ip_DeviceRegisters header file are of the same vendor */
#if (PLATFORM_SYSTEM_IP_CFG_DEFINES_TYPES_VENDOR_ID != PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_TYPES_VENDOR_ID)
    #error "System_Ip_Cfg.h and System_Ip_DeviceRegisters.h have different vendor ids"
#endif

/* Check if current file and System_Ip_DeviceRegisters header file are of the same Software version */
#if ((PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MAJOR_VERSION != PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MINOR_VERSION != PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_PATCH_VERSION != PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of System_Ip_Cfg.h and System_Ip_DeviceRegisters.h are different"
#endif



[!NOCODE!][!// Include headers for System_Ip_DeviceRegister.h
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!// 
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName, 'S32G2')"!][!//
        [!CODE!][!WS "0"!]    
        #include "S32G274A_MCM.h"
        
        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define TCM_WRITE_ABORT_IRQ_SUPPORTED

        #define MCM_HAS_WABS_SUPPORTED

        #define MCM_HAS_PLATFORM_REVISION

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32G3')"!][!//
        [!CODE!][!WS "0"!]    
        #include "S32G399A_MCM.h"
        
        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define TCM_WRITE_ABORT_IRQ_SUPPORTED

        #define MCM_HAS_WABS_SUPPORTED

        #define MCM_HAS_PLATFORM_REVISION

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K3')"!][!// 
        [!CODE!][!WS "0"!]
#ifdef S32K344
        #include "S32K344_MCM_CM7.h"
#endif
#ifdef S32K342
        #include "S32K342_MCM_CM7.h"
#endif      
#ifdef S32K324
        #include "S32K324_MCM_CM7.h"
#endif
#ifdef S32K314
        #include "S32K314_MCM_CM7.h"
#endif
#ifdef S32K312
        #include "S32K312_MCM_CM7.h"
#endif
        #define MCM_ISCR_FIDCE_SHIFT          MCM_CM7_ISCR_FIDCE_SHIFT
        #define MCM_ISCR_FIXCE_SHIFT          MCM_CM7_ISCR_FIXCE_SHIFT
        #define MCM_ISCR_FUFCE_SHIFT          MCM_CM7_ISCR_FUFCE_SHIFT
        #define MCM_ISCR_FOFCE_SHIFT          MCM_CM7_ISCR_FOFCE_SHIFT
        #define MCM_ISCR_FDZCE_SHIFT          MCM_CM7_ISCR_FDZCE_SHIFT
        #define MCM_ISCR_FIOCE_SHIFT          MCM_CM7_ISCR_FIOCE_SHIFT
        #define MCM_ISCR_WABE_SHIFT           MCM_CM7_ISCR_WABE_SHIFT 
        #define MCM_CPCR_CM7_AHBSPRI_MASK     MCM_CM7_CPCR_CM7_AHBSPRI_MASK
        #define MCM_ISCR_WABS_MASK            MCM_CM7_ISCR_WABS_MASK
        
        #define IP_MCM IP_MCM_0_CM7
        
        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define TCM_WRITE_ABORT_IRQ_SUPPORTED
        
        #define MCM_HAS_WABS_SUPPORTED
        
        #define MCM_HAS_PLATFORM_REVISION
        [!CR!][!ENDCODE!][!// 
     
    [!ELSEIF "contains($DerivativeName, 'S32R45')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32R45_MCM.h"

        
        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define TCM_WRITE_ABORT_IRQ_SUPPORTED

        #define MCM_HAS_WABS_SUPPORTED

        #define MCM_HAS_PLATFORM_REVISION
        [!CR!][!ENDCODE!][!// 
    
    [!ELSEIF "contains($DerivativeName, 'S32K1')"!][!//
        [!CODE!][!WS "0"!]
        
        #include "[!"$DerivativeName"!].h"
        
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32E')"!][!//
        [!CODE!][!WS "0"!]
        
        #include "S32E27_MCM.h"
        #define IP_MCM IP_CE_MCM
        [!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains($DerivativeName, 'S32Z')"!][!//
        [!CODE!][!WS "0"!]
        
        #include "S32Z27_MCM.h"
        #define IP_MCM IP_CE_MCM
        [!CR!][!ENDCODE!][!//        
    [!ENDIF!][!// 
[!ENDIF!][!// 
[!ENDNOCODE!][!//

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Arm Cortex M4 */
#define SYSTEM_IP_ARM_CORTEXM              ([!"ecu:get('Platform.ArmCortexM')"!])
#define SYSTEM_FPU_CFG                      ([!"ecu:get('Platform.fpu')"!])

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#if ((SYSTEM_IP_ARM_CORTEXM == STD_ON) && (SYSTEM_FPU_CFG == STD_ON))
/**
* @brief      Enumeration listing available core-related interrupt requests
*             defined per each platform.
* @implements System_Ip_IrqType_typedef
*/
typedef enum
{
#ifdef FPU_INPUT_DENORMAL_IRQ_SUPPORTED
    /** @brief FPU Input Denormal Interrupt */
    FPU_INPUT_DENORMAL_IRQ    = MCM_ISCR_FIDCE_SHIFT,
#endif    
#ifdef FPU_INEXACT_IRQ_SUPPORTED
    /** @brief FPU Inexact Interrupt */
    FPU_INEXACT_IRQ           = MCM_ISCR_FIXCE_SHIFT,
#endif
#ifdef FPU_UNDERFLOW_IRQ_SUPPORTED
    /** @brief FPU Underflow Interrupt */
    FPU_UNDERFLOW_IRQ         = MCM_ISCR_FUFCE_SHIFT,
#endif
#ifdef FPU_OVERFLOW_IRQ_SUPPORTED
    /** @brief FPU Overflow Interrupt */
    FPU_OVERFLOW_IRQ          = MCM_ISCR_FOFCE_SHIFT,
#endif
#ifdef FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
    /** @brief FPU Divide-by-Zero Interrupt */
    FPU_DIVIDE_BY_ZERO_IRQ    = MCM_ISCR_FDZCE_SHIFT,
#endif
#ifdef FPU_INVALID_OPERATION_IRQ_SUPPORTED
    /** @brief FPU Invalid Operation Interrupt */
    FPU_INVALID_OPERATION_IRQ = MCM_ISCR_FIOCE_SHIFT,
#endif
#ifdef TCM_WRITE_ABORT_IRQ_SUPPORTED
    /** @brief TCM Write Abort Interrupt */
    TCM_WRITE_ABORT_IRQ       = MCM_ISCR_WABE_SHIFT
#endif
}System_Ip_IrqType;
#endif /* SYSTEM_IP_ARM_CORTEXM == STD_ON */
#endif /* SYSTEM_IP_CFG_DEFINES_H_ */

/** @} */
