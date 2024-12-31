#ifndef CPL_RLECOMPRESS_CFG_H
#define CPL_RLECOMPRESS_CFG_H

/*================================================================================================*/

/** \file        Cpl_RLECompress_Cfg.h
 **
 ** \brief       Cpl RLE compression interface.
 **
 ** \project     Crypto Primitive Library
 ** \author      Danny Block <Danny.Block@elektrobit.com>
 ** \author      EB Automotive GmbH, 91058 Erlangen, Germany
 **
 ** \controller  independent
 ** \compiler    independent
 ** \hardware    independent
 **
 ** Copyright 2012 by EB Automotive GmbH
 ** All rights exclusively reserved for EB Automotive GmbH,
 ** unless expressly agreed to otherwise
 **/

/* !LINKSTO EB_CPL_0801_060, 1
 */

/*==================[misra deviations]============================================================*/

/*==================[includes]====================================================================*/

/* !LINKSTO EB_CPL_0801_062, 1
 */
#include <Std_Types.h>
#include <Cpl_Version.h>
#include <Cpl_Common.h>

/*==================[macros]======================================================================*/

/* !LINKSTO EB_CPL_0806_020, 1
 */
/** \brief  This macro encodes whether the RLECompress primitive is configured.
 **/
#define  CPL_RLECOMPRESS_ENABLED          STD_OFF

/* !LINKSTO EB_CPL_0806_021, 1
 */
/** \brief  This macros encodes whether a specific RLE type is enabled.
 ** \addtogroup  RLE type enabled macros
 ** @{ */
#define  CPL_RLECOMPRESS_VARIANT_8BIT     STD_OFF
#define  CPL_RLECOMPRESS_VARIANT_CTRLBIT  STD_OFF
/** @} doxygen end group definition */

/*==================[type definitions]============================================================*/

/* !LINKSTO EB_CPL_0806_510, 1
 */
/** \brief  Type for representing a RLECompress configuration.
 **/
typedef struct
{
  Cpl_RleVariantType Variant;
}
Cpl_RLECompressConfigType;

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #ifndef CPL_RLECOMPRESS_CFG_H */

/*==================[end of file]=================================================================*/
