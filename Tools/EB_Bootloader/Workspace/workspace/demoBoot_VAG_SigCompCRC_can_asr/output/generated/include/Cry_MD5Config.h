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

#ifndef CRY_MD5CONFIG_H
#define CRY_MD5CONFIG_H


/*==[Includes]====================================================================================*/

#include <Std_Types.h>

/*==[Macros]======================================================================================*/

#if (defined CRY_MD5_ENABLED)
#error CRY_MD5_ENABLED is already defined
#endif
#define CRY_MD5_ENABLED STD_OFF

#if (CRY_MD5_ENABLED == STD_ON)

#if (defined CRY_MD5_IMMEDIATE_RESTART_ENABLED)
#error CRY_MD5_IMMEDIATE_RESTART_ENABLED is already defined
#endif
/** \brief Flag to indicate if the immediate restart of the service regardless of the configuration ID is enabled. */
#define CRY_MD5_IMMEDIATE_RESTART_ENABLED STD_OFF

/*==[Types]=======================================================================================*/

/** \brief MD5 Configuration type
 */
typedef uint16 Cry_MD5_ConfigType;

/*==[Constants with external linkage]=============================================================*/

#define CRY_START_SEC_CONST_16
#include <MemMap.h>


#define CRY_STOP_SEC_CONST_16
#include <MemMap.h>

/*==[Variables with external linkage]=============================================================*/

/*==[Declaration of functions with external linkage]==============================================*/

#endif /* #if (CRY_MD5_ENABLED == STD_ON) */

#endif /* CRY_MD5CONFIG_H */
