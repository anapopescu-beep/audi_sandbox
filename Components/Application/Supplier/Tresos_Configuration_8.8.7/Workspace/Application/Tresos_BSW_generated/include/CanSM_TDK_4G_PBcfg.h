


/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CANSM_TDK_4G_PBCFG_H
#define CANSM_TDK_4G_PBCFG_H



/*==================[inclusions]=============================================*/

#include <CanSM_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <CanSM_Types_Int.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_OFF
#define TS_PB_CFG_PTR_CLASS CANSM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined CanSM_Config_TDK_4G) /* To prevent double definition */
#error CanSM_Config_TDK_4G already defined
#endif /* (defined CanSM_Config_TDK_4G) */

#define CanSM_Config_TDK_4G (CanSM_TDK_4G_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* CanSM_TDK_4G_ConfigLayoutType */ {
    VAR( CanSM_ConfigType, TYPEDEF ) RootCfg;
    VAR( CanSMNetworkType, TYPEDEF ) CanSM_Net[1];
    VAR( CanSMControllerType, TYPEDEF ) CanSM_Ctrl[1];
} CanSM_TDK_4G_ConfigLayoutType;

typedef CONST( CanSM_TDK_4G_ConfigLayoutType, CANSM_APPL_CONST ) CanSM_TDK_4G_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanSM_MemMap.h>

extern CanSM_TDK_4G_ConstConfigLayoutType CanSM_TDK_4G_ConfigLayout;

#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanSM_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* CANSM_TDK_4G_PBCFG_H */

/*==================[end of file]============================================*/

