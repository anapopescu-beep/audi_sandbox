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

#ifndef CAL_COMPRESS_CFG_H
#define CAL_COMPRESS_CFG_H

/*================================================================================================*/

/* !LINKSTO EB_CAL_0801_010, 1
 */

/*==================[includes]====================================================================*/

#include <Cal_Types.h>

/*==================[macros]======================================================================*/

/* !LINKSTO EB_CAL_0806_000, 1
 */
/** \brief  Macro indicates whether the compression service is configured.
 **/
#define  CAL_COMPRESS_ENABLED       STD_OFF



#if (CAL_COMPRESS_ENABLED == STD_ON)

/* !LINKSTO EB_CAL_0806_001, 1
 */
/** \brief  Macro defining the number of existing configurations for the compression service.
 **/
#define  CAL_COMPRESS_CONFIG_COUNT  0U

/* !LINKSTO EB_CAL_0806_002, 1
 */
/** \brief  The size of the context buffer required for the compression.
 **/
#define  CAL_COMPRESS_CTX_BUF_SIZE  CAL_LEN_IN_ALIGN_TYPE(100U)

/* !LINKSTO EB_CAL_0806_003, 1
 */
/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CAL_COMPRESS_ENABLED == STD_ON) */

#endif /* #ifndef CAL_COMPRESS_CFG_H */

/*==================[end of file]=================================================================*/

