


/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
 *
 * \version 1.4.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
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

#include <CanIf_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME CanIf_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE CanIf_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
CanIf_ConstConfigLayoutType CanIf_ConfigLayout = {
    { /* RootCfg */
        UINT32_C( 2147485970 ), /* PlatformSignature */
        UINT32_C( 3337953732 ), /* LcfgSignature */
        UINT32_C( 3164262722 ), /* CfgSignature */
        UINT32_C( 3410752704 ), /* PublicInfoSignature */
        TS_MAKEREF2CFG( txLPduConfig[0] ), /* txLPduConfigPtr */
        TS_MAKEREF2CFG( rxLPduConfig[0] ), /* rxLPduConfigPtr */
        TS_MAKEREF2CFG( sortedRxLPduConfig[0] ), /* sortedRxLPduConfigPtr */
        TS_MAKEREF2CFG( canDriverConfig[0] ), /* driverConfigPtr */
        UINT16_C( 12 ), /* nrOfStaticTxLPdus */
        UINT16_C( 12 ), /* nrOfTxLPdus */
        UINT16_C( 6 ) /* nrOfRxLPdus */
    },
    { /* txLPduConfig */
        { /* txLPduConfig[0] */
            UINT32_C( 3623764486 ), /* canId */
            UINT16_C( 1 ), /* hth */
            UINT16_C( 0 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        },
        { /* txLPduConfig[1] */
            UINT32_C( 3623764486 ), /* canId */
            UINT16_C( 1 ), /* hth */
            UINT16_C( 6 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        },
        { /* txLPduConfig[2] */
            UINT32_C( 3640541702 ), /* canId */
            UINT16_C( 2 ), /* hth */
            UINT16_C( 1 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        },
        { /* txLPduConfig[3] */
            UINT32_C( 3640541702 ), /* canId */
            UINT16_C( 2 ), /* hth */
            UINT16_C( 7 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        },
        { /* txLPduConfig[4] */
            UINT32_C( 3623768582 ), /* canId */
            UINT16_C( 1 ), /* hth */
            UINT16_C( 2 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        },
        { /* txLPduConfig[5] */
            UINT32_C( 3623768582 ), /* canId */
            UINT16_C( 1 ), /* hth */
            UINT16_C( 8 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        },
        { /* txLPduConfig[6] */
            UINT32_C( 3640545798 ), /* canId */
            UINT16_C( 2 ), /* hth */
            UINT16_C( 3 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        },
        { /* txLPduConfig[7] */
            UINT32_C( 3640545798 ), /* canId */
            UINT16_C( 2 ), /* hth */
            UINT16_C( 9 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        },
        { /* txLPduConfig[8] */
            UINT32_C( 3623772678 ), /* canId */
            UINT16_C( 1 ), /* hth */
            UINT16_C( 4 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        },
        { /* txLPduConfig[9] */
            UINT32_C( 3623772678 ), /* canId */
            UINT16_C( 1 ), /* hth */
            UINT16_C( 10 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        },
        { /* txLPduConfig[10] */
            UINT32_C( 3640549894 ), /* canId */
            UINT16_C( 2 ), /* hth */
            UINT16_C( 5 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        },
        { /* txLPduConfig[11] */
            UINT32_C( 3640549894 ), /* canId */
            UINT16_C( 2 ), /* hth */
            UINT16_C( 11 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        }
    },
    { /* rxLPduConfig */
        { /* rxLPduConfig[0] */
            UINT16_C( 0 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[1] */
            UINT16_C( 1 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[2] */
            UINT16_C( 2 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[3] */
            UINT16_C( 3 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[4] */
            UINT16_C( 4 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[5] */
            UINT16_C( 5 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
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
            UINT16_C( 6 ), /* firstIndex */
            UINT8_C( 0 ) /* intCtrlIdx */
        }
    },
    { /* driverHrhConfig */
        { /* driverHrhConfig[0] */
            UINT16_C( 0 ), /* firstIndex */
            UINT16_C( 5 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        }
    },
    { /* hohIdToCanIfIdx */
        UINT16_C( 0 ), /* hohIdToCanIfIdx[0] */
        UINT16_C( 0 ), /* hohIdToCanIfIdx[1] */
        UINT16_C( 1 ) /* hohIdToCanIfIdx[2] */
    },
    { /* canControllerConfig */
        { /* canControllerConfig[0] */
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
            UINT32_C( 3623633414 ), /* canId */
            UINT16_C( 0 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[1] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3623637510 ), /* canId */
            UINT16_C( 2 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[2] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3623641606 ), /* canId */
            UINT16_C( 4 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[3] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3640410630 ), /* canId */
            UINT16_C( 1 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[4] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3640414726 ), /* canId */
            UINT16_C( 3 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[5] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 3640418822 ), /* canId */
            UINT16_C( 5 ) /* rxLPduIndex */
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

