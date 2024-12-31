/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \version 5.0.15
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef DCM_AUTHENTICATION_CFG_H
#define DCM_AUTHENTICATION_CFG_H

/* !LINKSTO Dcm.Dsn.File.Authentication.ConfigH,1 */

/*==================[includes]===================================================================*/

#include <Std_Types.h>
/*==================[macros]=====================================================================*/

/** @defgroup Macro_Dcm_AuthenticationConfigurationType Macros for 
 **           Dcm_AuthenticationConfigurationType
 ** \brief   These macros are used as values for Dcm_AuthenticationConfigurationType
 **  @{
 */
/** \brief Authentication not configured */
#if (defined DCM_AUTHENTICATION_CONFIGURATION_NONE)
  #error "DCM_AUTHENTICATION_CONFIGURATION_NONE is already defined"
#endif
#define DCM_AUTHENTICATION_CONFIGURATION_NONE 0x00U

/** \brief Authentication with PKI Certificate Exchange (APCE) */
#if (defined DCM_AUTHENTICATION_CONFIGURATION_APCE)
  #error "DCM_AUTHENTICATION_CONFIGURATION_APCE is already defined"
#endif
#define DCM_AUTHENTICATION_CONFIGURATION_APCE 0x02U

/** \brief Authentication with Challenge-Response (ACR) and Asymmetric Cryptography  */
#if (defined DCM_AUTHENTICATION_CONFIGURATION_ACRAC)
  #error "DCM_AUTHENTICATION_CONFIGURATION_ACRAC is already defined"
#endif
#define DCM_AUTHENTICATION_CONFIGURATION_ACRAC 0x03U

/** \brief Authentication with Challenge-Response (ACR) and Symmetric Cryptography  */
#if (defined DCM_AUTHENTICATION_CONFIGURATION_ACRSC)
  #error "DCM_AUTHENTICATION_CONFIGURATION_ACRSC is already defined"
#endif
#define DCM_AUTHENTICATION_CONFIGURATION_ACRSC 0x04U

/* @} */
/* End of macros definitions for Dcm_AuthenticationConfigurationType */ 

#if (defined DCM_AUTHENTICATION_CONFIGURATION) /* To prevent double declaration */
#error DCM_AUTHENTICATION_CONFIGURATION already defined
#endif /* if (defined DCM_AUTHENTICATION_CONFIGURATION) */
/** \brief Configured authentication type */
#define DCM_AUTHENTICATION_CONFIGURATION                   DCM_AUTHENTICATION_CONFIGURATION_NONE

#if (defined DCM_DSP_USE_SERVICE_0X29 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X29  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X29 ) */
/** \brief Defines whether UDS service 0x29 is configured */
#define DCM_DSP_USE_SERVICE_0X29           STD_OFF

#if (defined DCM_0X29_0X00_SSVC_ENABLED ) /* To prevent double declaration */
#error DCM_0X29_0X00_SSVC_ENABLED  already defined
#endif /* if (defined DCM_0X29_0X00_SSVC_ENABLED ) */

/** \brief Subservice 0x00 for 0x29 enabled or not */
#define DCM_0X29_0X00_SSVC_ENABLED           STD_OFF

#if (defined DCM_0X29_0X01_SSVC_ENABLED ) /* To prevent double declaration */
#error DCM_0X29_0X01_SSVC_ENABLED  already defined
#endif /* if (defined DCM_0X29_0X01_SSVC_ENABLED ) */

/** \brief Subservice 0x01 for 0x29 enabled or not */
#define DCM_0X29_0X01_SSVC_ENABLED           STD_OFF

#if (defined DCM_0X29_0X02_SSVC_ENABLED ) /* To prevent double declaration */
#error DCM_0X29_0X02_SSVC_ENABLED  already defined
#endif /* if (defined DCM_0X29_0X02_SSVC_ENABLED ) */

/** \brief Subservice 0x02 for 0x29 enabled or not */
#define DCM_0X29_0X02_SSVC_ENABLED           STD_OFF

#if (defined DCM_0X29_0X03_SSVC_ENABLED ) /* To prevent double declaration */
#error DCM_0X29_0X03_SSVC_ENABLED  already defined
#endif /* if (defined DCM_0X29_0X03_SSVC_ENABLED ) */

/** \brief Subservice 0x03 for 0x29 enabled or not */
#define DCM_0X29_0X03_SSVC_ENABLED           STD_OFF

#if (defined DCM_0X29_0X08_SSVC_ENABLED ) /* To prevent double declaration */
#error DCM_0X29_0X08_SSVC_ENABLED  already defined
#endif /* if (defined DCM_0X29_0X08_SSVC_ENABLED ) */

/** \brief Subservice 0x08 for 0x29 enabled or not */
#define DCM_0X29_0X08_SSVC_ENABLED           STD_OFF

/** \brief Defines whether authentication connection container contains at least one entry */
#define DCM_AUTHENTICATION_CONNECTION                      STD_OFF

/** \brief Defines whether Authentication default session timeout is used */
#define DCM_AUTHENTICATION_IDLECONNECTIONTIMER           STD_OFF

#endif /* ifndef DCM_AUTHENTICATION_CFG_H */
/*==================[end of file]================================================================*/
