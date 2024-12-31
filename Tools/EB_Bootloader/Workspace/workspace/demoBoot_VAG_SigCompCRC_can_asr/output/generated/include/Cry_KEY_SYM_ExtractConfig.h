/**
 * \file
 *
 * \brief AUTOSAR Cry
 *
 * This file contains the implementation of the AUTOSAR
 * module Cry.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO EB_CRY_0003,1 */

#ifndef CRY_KEY_SYM_EXTRACTCONFIG_H
#define CRY_KEY_SYM_EXTRACTCONFIG_H

/*==================[includes]====================================================================*/

#include <Std_Types.h>

/*==================[macros]======================================================================*/

#if (defined CRY_KEY_SYM_EXTRACT_ENABLED)
#error CRY_KEY_SYM_EXTRACT_ENABLED is already defined
#endif
/* !LINKSTO EB_CRY_0018,1 */
#define CRY_KEY_SYM_EXTRACT_ENABLED STD_OFF

#if (CRY_KEY_SYM_EXTRACT_ENABLED == STD_ON)

#if (defined CRY_KEY_BUFLEN)
#error CRY_KEY_BUFLEN is already defined
#endif
#define  CRY_KEY_BUFLEN  0U

#if (defined CRY_SYMKEYEXTRACT_IMMEDIATE_RESTART_ENABLED)
#error CRY_SYMKEYEXTRACT_IMMEDIATE_RESTART_ENABLED is already defined
#endif
/** \brief Flag to indicate if the immediate restart of the service regardless of the configuration ID is enabled. */
#define CRY_SYMKEYEXTRACT_IMMEDIATE_RESTART_ENABLED STD_OFF

/*==================[type definitions]============================================================*/

/*---[enum]---------------------------------------------------------------------------------------*/

/** \brief  Type of the configured symmetrical key.
 **/
typedef enum
{
  CRY_KEY_SYM_128 = 16U,
  CRY_KEY_SYM_192 = 24U,
  CRY_KEY_SYM_256 = 32U
}
Cry_KEY_SYM_Type;

/*---[struct]-------------------------------------------------------------------------------------*/

/* !LINKSTO EB_CRY_0017,1 */
/** \brief  Configuration type for representing a configured symmetrical key extraction.
 **/
typedef struct
{
  Cry_KEY_SYM_Type typeKey;
}
Cry_KEY_SYM_ConfigType;

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CRY_KEY_SYM_EXTRACT_ENABLED == STD_ON) */

#endif /* #ifndef CRY_KEY_SYM_EXTRACTCONFIG_H */
