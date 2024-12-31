/**
 * \file
 *
 * \brief AUTOSAR Cpl
 *
 * This file contains the implementation of the AUTOSAR
 * module Cpl.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CPL_ARLEDECOMPRESS_CFG_H
#define CPL_ARLEDECOMPRESS_CFG_H

/* !LINKSTO EB_CPL_0801_078, 1
 */

/*==================[misra deviations]============================================================*/

/*==================[includes]====================================================================*/

/* !LINKSTO EB_CPL_0801_079, 1
 */
#include <Std_Types.h>
#include <Cpl_Version.h>
#include <Cpl_Common.h>

/*==================[macros]======================================================================*/

/* !LINKSTO EB_CPL_0806_516, 1
 */
/** \brief  This macro encodes whether the ARLEDecompress primitive is configured.
 **/
#define  CPL_ARLEDECOMPRESS_ENABLED          STD_OFF

/*==================[type definitions]============================================================*/

/* !LINKSTO EB_CPL_ARLE_CFG_TYPE, 1 */
/** \brief  Type for representing a ARLEDecompress configuration.
 **/
typedef struct
{
  uint8 dummyParameter;
}
Cpl_ARLEDecompressConfigType;

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/
/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #ifndef CPL_ARLEDECOMPRESS_CFG_H */

/*==================[end of file]=================================================================*/
