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

#ifndef CRY_CRC_CONFIG_H
#define CRY_CRC_CONFIG_H

/*==================[includes]====================================================================*/

#include <Std_Types.h>

/*==================[macros]======================================================================*/

#if (defined CRY_CRC_ENABLED)
#error CRY_CRC_ENABLED is already defined
#endif
#define CRY_CRC_ENABLED FALSE

#if (CRY_CRC_ENABLED == TRUE)

#if (defined CRY_CRC_BUFLEN)
#error CRY_CRC_BUFLEN is already defined
#endif

#define  CRY_CRC_BUFLEN  0U     /* == sizeof(CRY_CRC_BUFTYP) */

/*==================[type definitions]============================================================*/

/*---[enum]---------------------------------------------------------------------------------------*/

/** \brief  Type of the configured order of CRC polynom.
 **/
typedef enum
{
  CRY_CRC_8  = 1,
  CRY_CRC_16 = 2,
  CRY_CRC_32 = 4
}
Cry_CRC_Type;

/*---[struct]-------------------------------------------------------------------------------------*/

/** \brief  Configuration type for representing a configured CRC.
 **/
typedef struct
{
  Cry_CRC_Type typeCrc;
  uint32       polyCrc;
  uint32       mbpcCrc;
  uint32       iputXor;
  uint32       oputXor;
  boolean      iputReflect;
  boolean      oputReflect;
}
Cry_CRC_ConfigType;

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/


/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CRY_CRC_ENABLED == TRUE) */

#endif /* #ifndef CRY_CRC_CONFIG_H */
