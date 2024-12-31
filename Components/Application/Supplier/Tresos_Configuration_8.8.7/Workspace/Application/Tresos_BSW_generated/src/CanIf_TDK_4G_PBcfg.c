


/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 1.3 (required)
 *    There shall be no occurrence of undefined or critical unspecified behaviour.
 *
 *    Reason:
 *    The postbuild macro TS_MAKEREF2CFG requires the usage of the
 *    C standard macro 'offsetof'.
 *    According to the C90 standard, the usage of 'offsetof' produces
 *    an undefined behaviour when the member designator parameter
 *    is a bit-field or when it is an invalid right operator of the
 *    '.' operator for the type parameter.
 *    This is not the case here as the parameter of TS_MAKEREF2CFG
 *    is always a member of TS_PB_CFG_LAYOUT_TYPE and bitfields are
 *    never used when defining the postbuild structure members.
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

#include <CanIf_TDK_4G_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME CanIf_TDK_4G_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE CanIf_TDK_4G_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
CanIf_TDK_4G_ConstConfigLayoutType CanIf_TDK_4G_ConfigLayout = {
    { /* RootCfg */
        UINT32_C( 2147485970 ), /* PlatformSignature */
        UINT32_C( 3337953732 ), /* LcfgSignature */
        UINT32_C( 507235911 ), /* CfgSignature */
        UINT32_C( 3439620183 ), /* PublicInfoSignature */
        TS_MAKEREF2CFG( txLPduConfig[0] ), /* txLPduConfigPtr */
        TS_MAKEREF2CFG( rxLPduConfig[0] ), /* rxLPduConfigPtr */
        TS_MAKEREF2CFG( sortedRxLPduConfig[0] ), /* sortedRxLPduConfigPtr */
        TS_MAKEREF2CFG( canDriverConfig[0] ), /* driverConfigPtr */
        UINT16_C( 13 ), /* nrOfStaticTxLPdus */
        UINT16_C( 13 ), /* nrOfTxLPdus */
        UINT16_C( 8 ) /* nrOfRxLPdus */
    },
    { /* txLPduConfig */
        { /* txLPduConfig[0] */
            UINT32_C( 1073742080 ), /* canId */
            UINT8_C( 5 ), /* hth */
            UINT16_C( 0 ), /* sourcePduId_UL */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[1] */
            UINT32_C( 1073743813 ), /* canId */
            UINT8_C( 4 ), /* hth */
            UINT16_C( 4 ), /* sourcePduId_UL */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 8 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[2] */
            UINT32_C( 1073743812 ), /* canId */
            UINT8_C( 4 ), /* hth */
            UINT16_C( 1 ), /* sourcePduId_UL */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[3] */
            UINT32_C( 1073742024 ), /* canId */
            UINT8_C( 5 ), /* hth */
            UINT16_C( 3 ), /* sourcePduId_UL */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[4] */
            UINT32_C( 3405337872 ), /* canId */
            UINT8_C( 3 ), /* hth */
            UINT16_C( 2 ), /* sourcePduId_UL */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 8 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[5] */
            UINT32_C( 3623764486 ), /* canId */
            UINT8_C( 6 ), /* hth */
            UINT16_C( 4 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 8 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[6] */
            UINT32_C( 3695329798 ), /* canId */
            UINT8_C( 6 ), /* hth */
            UINT16_C( 5 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[7] */
            UINT32_C( 3695333894 ), /* canId */
            UINT8_C( 6 ), /* hth */
            UINT16_C( 6 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[8] */
            UINT32_C( 3695342086 ), /* canId */
            UINT8_C( 6 ), /* hth */
            UINT16_C( 7 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[9] */
            UINT32_C( 3623764486 ), /* canId */
            UINT8_C( 6 ), /* hth */
            UINT16_C( 0 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[10] */
            UINT32_C( 3695329798 ), /* canId */
            UINT8_C( 6 ), /* hth */
            UINT16_C( 1 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[11] */
            UINT32_C( 3695333894 ), /* canId */
            UINT8_C( 6 ), /* hth */
            UINT16_C( 2 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[12] */
            UINT32_C( 3695342086 ), /* canId */
            UINT8_C( 6 ), /* hth */
            UINT16_C( 3 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        }
    },
    { /* rxLPduConfig */
        { /* rxLPduConfig[0] */
            UINT16_C( 0 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[1] */
            UINT16_C( 1 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[2] */
            UINT16_C( 2 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[3] */
            UINT16_C( 0 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[4] */
            UINT16_C( 1 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[5] */
            UINT16_C( 2 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[6] */
            UINT16_C( 3 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[7] */
            UINT16_C( 3 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        }
    },
    { /* driverHthConfig */
        { /* driverHthConfig[0] */
            UINT16_C( 0 ), /* firstIndex */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHthConfig[1] */
            UINT16_C( 0 ), /* firstIndex */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHthConfig[2] */
            UINT16_C( 0 ), /* firstIndex */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHthConfig[3] */
            UINT16_C( 2 ), /* firstIndex */
            UINT8_C( 0 ) /* intCtrlIdx */
        }
    },
    { /* driverHrhConfig */
        { /* driverHrhConfig[0] */
            UINT16_C( 0 ), /* firstIndex */
            UINT16_C( 4 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[1] */
            UINT16_C( 5 ), /* firstIndex */
            UINT16_C( 7 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[2] */
            UINT16_C( 8 ), /* firstIndex */
            UINT16_C( 12 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        }
    },
    { /* hohIdToCanIfIdx */
        UINT16_C( 0 ), /* hohIdToCanIfIdx[0] */
        UINT16_C( 1 ), /* hohIdToCanIfIdx[1] */
        UINT16_C( 2 ), /* hohIdToCanIfIdx[2] */
        UINT16_C( 0 ), /* hohIdToCanIfIdx[3] */
        UINT16_C( 1 ), /* hohIdToCanIfIdx[4] */
        UINT16_C( 2 ), /* hohIdToCanIfIdx[5] */
        UINT16_C( 3 ) /* hohIdToCanIfIdx[6] */
    },
    { /* canControllerConfig */
        { /* canControllerConfig[0] */
            UINT32_C( 0 ), /* wakeupSourceIn */
            UINT32_C( 32 ), /* wakeupSourceOut */
            UINT8_C( 0 ) /* controllerId */
        }
    },
    { /* canDriverConfig */
        { /* canDriverConfig[0] */
            TS_MAKEREF2CFG( canControllerConfig[0] ), /* ctrlConfigPtr */
            TS_MAKEREF2CFG( hohIdToCanIfIdx[0] ), /* hohIdToCanIfIdxPtr */
            TS_MAKEREF2CFG( driverHthConfig[0] ), /* hthConfigPtr */
            TS_MAKEREF2CFG( driverHrhConfig[0] ), /* hrhConfigPtr */
            UINT8_C( 1 ) /* nrOfControllers */
        }
    },
    { /* sortedRxLPduConfig */
        { /* sortedRxLPduConfig[0] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3405337873 ), /* canId */
            UINT16_C( 2 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[1] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3623633414 ), /* canId */
            UINT16_C( 3 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[2] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3695198726 ), /* canId */
            UINT16_C( 4 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[3] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3695202822 ), /* canId */
            UINT16_C( 5 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[4] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3695211014 ), /* canId */
            UINT16_C( 7 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[5] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073741888 ), /* canId */
            UINT16_C( 0 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[6] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742124 ), /* canId */
            UINT16_C( 6 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[7] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073743136 ), /* canId */
            UINT16_C( 1 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[8] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3405337873 ), /* canId */
            UINT16_C( 2 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[9] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3623633414 ), /* canId */
            UINT16_C( 3 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[10] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3695198726 ), /* canId */
            UINT16_C( 4 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[11] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3695202822 ), /* canId */
            UINT16_C( 5 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[12] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3695211014 ), /* canId */
            UINT16_C( 7 ) /* rxLPduIndex */
        }
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

