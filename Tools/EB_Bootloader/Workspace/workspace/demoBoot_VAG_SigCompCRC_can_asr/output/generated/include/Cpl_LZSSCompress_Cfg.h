#ifndef CPL_LZSSCOMPRESS_CFG_H
#define CPL_LZSSCOMPRESS_CFG_H

/*================================================================================================*/

/** \file        Cpl_LZSSCompress_Cfg.h
 **
 ** \brief       Cpl LZSS compression interface.
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

/* !LINKSTO EB_CPL_0801_040, 1
 */

/*==================[misra deviations]============================================================*/

/*==================[includes]====================================================================*/

/* !LINKSTO EB_CPL_0801_042, 1
 */
#include <Std_Types.h>
#include <Cpl_Version.h>

/*==================[macros]======================================================================*/

/* !LINKSTO EB_CPL_0806_000, 1
 */
/** \brief  This macro encodes whether the LZSSCompress primitive is configured.
 **/
#define  CPL_LZSSCOMPRESS_ENABLED          STD_OFF

/** \brief  This macro encodes the maximum necessary look-back (LB) buffer size
 **/
#define  CPL_LZSSCOMPRESS_BUF_LB_MAX_SIZE  0U

/** \brief  This macro encodes the maximum necessary look-ahead (LA) buffer size
 **/
#define  CPL_LZSSCOMPRESS_BUF_LA_MAX_SIZE  0U

/*==================[type definitions]============================================================*/

/* !LINKSTO EB_CPL_0806_500, 1
 */
/** \brief  Type for representing a LZSSCompress configuration.
 **/
typedef struct
{
  uint16 shftLength;
  uint16 maskLength;
  uint16 maskOffset;
  uint32 sizeBufLookBack;
  uint32 sizeBufLookAhead;
  uint32 iterBeforeInterruption;
}
Cpl_LZSSCompressConfigType;

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #ifndef CPL_LZSSCOMPRESS_CFG_H */

/*==================[end of file]=================================================================*/
