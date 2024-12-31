
/**
 * \file
 *
 * \brief AUTOSAR CanNm
 *
 * This file contains the implementation of the AUTOSAR
 * module CanNm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 1.3 (required)
 *    The macro `offsetof' shall not be used.
 *
 *    Reason:
 *    Relocatable postbuild macro requires the usage of `offsetof'.
 *
 * MISRAC2012-2) Deviated Rule: 11.4 (advisory)
 *    A cast should not be performed between a pointer type and an integral
 *    type.
 *
 *    Reason:
 *    Relocatable postbuild macro requires the cast between pointer and
 *    integral type.
 *
 * MISRAC2012-3) Deviated Rule: 11.9 (required)
 *    The macro NULL shall be the only permitted form of integer null pointer constant.
 *
 *    Reason:
 *    Macros are used in order to check the alignment for different data types.
 *
 */

/*==================[inclusions]=============================================*/

#include <CanNm_TDK_4G_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME CanNm_TDK_4G_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE CanNm_TDK_4G_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanNm_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
CanNm_TDK_4G_ConstConfigLayoutType CanNm_TDK_4G_ConfigLayout = {
    { /* RootCfg */
        UINT32_C( 2147485970 ), /* PlatformSignature */
        UINT32_C( 3958107115 ), /* LcfgSignature */
        UINT32_C( 1385074059 ), /* CfgSignature */
        UINT32_C( 1693094120 ), /* PublicInfoSignature */
        { /* CanNm_ChannelData */
            { /* CanNm_ChannelData[0] */
                UINT32_C( 7 ), /* UserDataLength */
                UINT16_C( 8 ), /* RxPduLength */
                UINT16_C( 0 ), /* UserTxConfPduId */
                UINT16_C( 0 ), /* UserRxPduId */
                UINT16_C( 4 ), /* TxPduId */
                UINT8_C( 17 ), /* CanNmNodeId */
                BOOLEAN_C( 1 ) /* UserRxPduEnabled */
            }
        },
        { /* BufferOffsets */
            UINT32_C( 0 ) /* BufferOffsets[0] */
        },
        UINT32_C( 8 ), /* TxBufferOffset */
        UINT32_C( 16 ) /* PbRequiredCfgRamSize */
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanNm_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

