[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('ADC_VERSIONCHECK_INC_M'))"!]
[!VAR "ADC_VERSIONCHECK_INC_M"="'true'"!]
[!NOCODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ADC
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
*   @file
*
*   @addtogroup adc_driver_config Adc Driver Configuration
*   @{
*/

[!VAR "ADC_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "ADC_AR_RELEASE_MINOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "ADC_AR_RELEASE_REVISION_VERSION_TEMPLATE"="0"!][!//
[!VAR "ADC_SW_MAJOR_VERSION_TEMPLATE"="1"!][!//
[!VAR "ADC_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "ADC_SW_PATCH_VERSION_TEMPLATE"="1"!][!//
[!ENDNOCODE!][!//
[!SELECT "CommonPublishedInformation"!][!//

[!IF "not(num:i(ArReleaseMajorVersion) = num:i($ADC_AR_RELEASE_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** AUTOSAR release major version number of the Basic Software Module Description file (Adc.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Adc_Cfg.h version [!"num:i($ADC_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseMinorVersion) = num:i($ADC_AR_RELEASE_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** AUTOSAR release minor version number of the Basic Software Module Description file (Adc.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (Adc_Cfg.h version [!"num:i($ADC_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseRevisionVersion) = num:i($ADC_AR_RELEASE_REVISION_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** AUTOSAR release revision version number of the Basic Software Module Description file (Adc.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (Adc_Cfg.h version [!"num:i($ADC_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!]

[!IF "not(num:i(SwMajorVersion) = num:i($ADC_SW_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** The software major number of the Basic Software Module Description file (Adc.epd version [!"SwMajorVersion"!]) and the Code template file (Adc_Cfg.h version [!"num:i($ADC_SW_MAJOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMinorVersion) = num:i($ADC_SW_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** The software minor number of the Basic Software Module Description file (Adc.epd version [!"SwMinorVersion"!]) and the Code template file (Adc_Cfg.h version [!"num:i($ADC_SW_MINOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwPatchVersion) = num:i($ADC_SW_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** The software patch number of the Basic Software Module Description file (Adc.epd version [!"SwPatchVersion"!]) and the Code template file (Adc_Cfg.h version [!"num:i($ADC_SW_PATCH_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!]

[!ENDSELECT!][!//
[!ENDIF!]

/** @} */