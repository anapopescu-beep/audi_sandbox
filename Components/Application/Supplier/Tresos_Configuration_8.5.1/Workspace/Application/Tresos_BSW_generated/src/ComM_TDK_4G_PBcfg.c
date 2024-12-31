
/**
 * \file
 *
 * \brief AUTOSAR ComM
 *
 * This file contains the implementation of the AUTOSAR
 * module ComM.
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

#include <ComM_TDK_4G_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME ComM_TDK_4G_Configuration
#define TS_PB_CFG_LAYOUT_TYPE ComM_TDK_4G_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define COMM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <ComM_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
ComM_TDK_4G_ConstConfigLayoutType ComM_TDK_4G_Configuration = {
    { /* RootCfg */
        UINT32_C( 2147485970 ), /* PlatformSignature */
        UINT32_C( 3958107115 ), /* LcfgSignature */
        UINT32_C( 286360164 ), /* CfgSignature */
        UINT32_C( 1761362124 ), /* PublicInfoSignature */
        TS_MAKEREF2CFG( aUsersOfAllChannel[0] ), /* pUsersOfAllChannel */
        { /* NumUsersOfAllChannel */
            UINT16_C( 0 ), /* NumUsersOfAllChannel[0] */
            UINT16_C( 1 ) /* NumUsersOfAllChannel[1] */
        },
        TS_MAKEREF2CFG( aChannelsOfAllUser[0] ), /* pChannelsOfAllUser */
        { /* NumChannelsOfAllUser */
            UINT16_C( 0 ), /* NumChannelsOfAllUser[0] */
            UINT16_C( 1 ) /* NumChannelsOfAllUser[1] */
        },
        { /* DirectNumChannelsOfAllUser */
            UINT16_C( 0 ), /* DirectNumChannelsOfAllUser[0] */
            UINT16_C( 1 ) /* DirectNumChannelsOfAllUser[1] */
        }
    },
    { /* aUsersOfAllChannel */
        UINT8_C( 0 ) /* aUsersOfAllChannel[0] */
    },
    { /* aChannelsOfAllUser */
        UINT8_C( 0 ) /* aChannelsOfAllUser[0] */
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define COMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <ComM_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

