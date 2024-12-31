#ifndef CPL_LZSSDECOMPRESS_CFG_H
#define CPL_LZSSDECOMPRESS_CFG_H

/*================================================================================================*/

/** \file        Cpl_LZSSDecompress_Cfg.h
 **
 ** \brief       Cpl LZSS decompression interface.
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

/* !LINKSTO EB_CPL_0801_050, 1
 */

/*==================[misra deviations]============================================================*/

/*==================[includes]====================================================================*/

/* !LINKSTO EB_CPL_0801_052, 1
 */
#include <Std_Types.h>
#include <Cpl_Version.h>

/*==================[macros]======================================================================*/

/* !LINKSTO EB_CPL_0806_010, 1
 */
/** \brief  Macro encodes whether the LZSSDecompress primitive is configured.
 **/
#define  CPL_LZSSDECOMPRESS_ENABLED          STD_ON

/** \brief  Macro encodes the maximum necessary look-back (LB) buffer size
 **/
#define  CPL_LZSSDECOMPRESS_BUF_LB_MAX_SIZE  1023U

/*==================[type definitions]============================================================*/

/* !LINKSTO EB_CPL_0806_505, 1
 */
/** \brief  Type for representing a LZSSDecompress configuration.
 **/
typedef struct
{
  uint16 shftLength;
  uint16 maskLength;
  uint16 maskOffset;
  uint16 sizeBufLookBack;
}
Cpl_LZSSDecompressConfigType;

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/

#define CPL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* !LINKSTO EB_CPL_0806_505, 1
 */
extern CONST(Cpl_LZSSDecompressConfigType, CPL_CONST) CplLzssDecompressConfig_0;

#define CPL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #ifndef CPL_LZSSDECOMPRESS_CFG_H */

/*==================[end of file]=================================================================*/
