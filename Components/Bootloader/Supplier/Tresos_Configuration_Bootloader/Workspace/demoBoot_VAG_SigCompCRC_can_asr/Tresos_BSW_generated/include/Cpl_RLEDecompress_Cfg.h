#ifndef CPL_RLEDECOMPRESS_CFG_H
#define CPL_RLEDECOMPRESS_CFG_H

/*================================================================================================*/

/** \file        Cpl_RLEDecompress_Cfg.h
 **
 ** \brief       Cpl RLE decompression interface.
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

/* !LINKSTO EB_CPL_0801_070, 1
 */

/*==================[misra deviations]============================================================*/

/*==================[includes]====================================================================*/

/* !LINKSTO EB_CPL_0801_072, 1
 */
#include <Std_Types.h>
#include <Cpl_Version.h>
#include <Cpl_Common.h>

/*==================[macros]======================================================================*/

/* !LINKSTO EB_CPL_0806_030, 1
 */
/** \brief  This macro encodes whether the RLEDecompress primitive is configured.
 **/
#define  CPL_RLEDECOMPRESS_ENABLED          STD_OFF

/* !LINKSTO EB_CPL_0806_031, 1
 */
/** \brief  This macros encodes whether a specific RLE type is enabled.
 ** \addtogroup  RLE type enabled macros
 ** @{ */
#define  CPL_RLEDECOMPRESS_VARIANT_8BIT     STD_OFF
#define  CPL_RLEDECOMPRESS_VARIANT_CTRLBIT  STD_OFF
/** @} doxygen end group definition */

/*==================[type definitions]============================================================*/

/* !LINKSTO EB_CPL_0806_515, 1
 */
/** \brief  Type for representing a RLEDecompress configuration.
 **/
typedef struct
{
  Cpl_RleVariantType Variant;
}
Cpl_RLEDecompressConfigType;

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #ifndef CPL_RLEDECOMPRESS_CFG_H */

/*==================[end of file]=================================================================*/
