
/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CANIF_TDK_4G_PBCFG_H
#define CANIF_TDK_4G_PBCFG_H



/*==================[inclusions]=============================================*/

#include <CanIf_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <CanIf_Types_Int.h>
#include <Platform_Types.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS CANIF_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined CanIf_Config_TDK_4G) /* To prevent double definition */
#error CanIf_Config_TDK_4G already defined
#endif /* (defined CanIf_Config_TDK_4G) */

#define CanIf_Config_TDK_4G (CanIf_TDK_4G_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* CanIf_TDK_4G_ConfigLayoutType */ {
    VAR( CanIf_ConfigType, TYPEDEF ) RootCfg;
    VAR( CanIf_TxLPduConfigType, TYPEDEF ) txLPduConfig[13];
    VAR( CanIf_RxLPduConfigType, TYPEDEF ) rxLPduConfig[8];
    VAR( CanIf_HthConfigType, TYPEDEF ) driverHthConfig[4];
    VAR( CanIf_HrhConfigType, TYPEDEF ) driverHrhConfig[3];
    VAR( uint16, TYPEDEF ) hohIdToCanIfIdx[7];
    VAR( CanIf_CanControllerConfigType, TYPEDEF ) canControllerConfig[1];
    VAR( CanIf_CanDriverConfigType, TYPEDEF ) canDriverConfig[1];
    VAR( CanIf_SortedRxLPduConfigType, TYPEDEF ) sortedRxLPduConfig[13];
} CanIf_TDK_4G_ConfigLayoutType;

typedef CONST( CanIf_TDK_4G_ConfigLayoutType, CANIF_APPL_CONST ) CanIf_TDK_4G_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

extern CanIf_TDK_4G_ConstConfigLayoutType CanIf_TDK_4G_ConfigLayout;

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* CANIF_TDK_4G_PBCFG_H */

/*==================[end of file]============================================*/

