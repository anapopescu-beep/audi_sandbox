
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

#ifndef CANNM_TDK_4G_PBCFG_H
#define CANNM_TDK_4G_PBCFG_H



/*==================[inclusions]=============================================*/

#include <CanNm_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <CanNm_Types.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS CANNM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined CanNmGlobalConfig_TDK_4G) /* To prevent double definition */
#error CanNmGlobalConfig_TDK_4G already defined
#endif /* (defined CanNmGlobalConfig_TDK_4G) */

#define CanNmGlobalConfig_TDK_4G (CanNm_TDK_4G_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* CanNm_TDK_4G_ConfigLayoutType */ {
    VAR( CanNm_ConfigType, TYPEDEF ) RootCfg;
} CanNm_TDK_4G_ConfigLayoutType;

typedef CONST( CanNm_TDK_4G_ConfigLayoutType, CANNM_APPL_CONST ) CanNm_TDK_4G_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanNm_MemMap.h>

extern CanNm_TDK_4G_ConstConfigLayoutType CanNm_TDK_4G_ConfigLayout;

#define CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanNm_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* CANNM_TDK_4G_PBCFG_H */

/*==================[end of file]============================================*/

