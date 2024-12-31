/**
 * \file
 *
 * \brief AUTOSAR Cal
 *
 * This file contains the implementation of the AUTOSAR
 * module Cal.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CAL_DECOMPRESS_CFG_H
#define CAL_DECOMPRESS_CFG_H

/*================================================================================================*/

/* !LINKSTO EB_CAL_0801_015, 1
 */

/*==================[includes]====================================================================*/

#include <Cal_Types.h>

/*==================[macros]======================================================================*/

/* !LINKSTO EB_CAL_0806_010, 1
 */
/** \brief  Macro indicates whether the decompression service is configured.
 **/
#define  CAL_DECOMPRESS_ENABLED       STD_ON



#if (CAL_DECOMPRESS_ENABLED == STD_ON)

/* !LINKSTO EB_CAL_0806_011, 1
 */
/** \brief  Macro defining the number of existing configurations for the decompression service.
 **/
#define  CAL_DECOMPRESS_CONFIG_COUNT  1U

/* !LINKSTO EB_CAL_0806_012, 1
 */
/** \brief  The size of the context buffer required for the decompression.
 **/
#define  CAL_DECOMPRESS_CTX_BUF_SIZE  CAL_LEN_IN_ALIGN_TYPE(20480U)

/* !LINKSTO EB_CAL_0806_013, 1
 */
/** \brief  Macro defining the index of configuration CalDecompressConfig_0 in Cal_CompressConfigurations
 **/
#define  CalDecompressConfig_0        (Cal_ConfigIdType)0U

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CAL_DECOMPRESS_ENABLED == STD_ON) */

#endif /* #ifndef CAL_DECOMPRESS_CFG_H */

/*==================[end of file]=================================================================*/

