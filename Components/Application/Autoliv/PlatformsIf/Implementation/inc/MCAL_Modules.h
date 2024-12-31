/**
 * \file
 *
 * \brief AUTOSAR ApplTemplates
 *
 * This file contains the implementation of the AUTOSAR
 * module ApplTemplates.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/**
 * This file contains the implementation of the AUTOSAR
 * module ApplTemplates.
 */

#ifndef MCAL_MODULES_H
#define MCAL_MODULES_H


/*==================[includes]==============================================*/

/*==================[macros]================================================*/

/*
 * Here you can define platform-specific names for init functions 
 * and configuration pointer names when modules require other init function
 * names or configuration pointer names than defined in BswM_Modules.h
 * or Base_Modules.h.
 * Currently these defines are used in BswM_Usercallouts.c from application 
 * template.
 */

#define SPI_INIT_FUNC         Spi_Init
#define BASE_SPI_CONFIG_PTR   NULL_PTR

#define FLS_INIT_FUNC         Fls_Init
#define BASE_FLS_CONFIG_PTR   &FlsConfigSet

#define FEE_INIT_FUNC         Fee_Init
/* SWS_Fee_00189 - The  configuration  pointer  ConfigPtr  shall  always  
   have a NULL_PTR value. */
#define BASE_FEE_CONFIG_PTR   NULL_PTR

#define CAN_INIT_FUNC         Can_Init
#define BASE_CAN_CONFIG_PTR   &CanConfigSet

#define LIN_INIT_FUNC         Lin_Init
#define BASE_LIN_CONFIG_PTR   &LinGlobalConfig

#define BASE_MCU_CONFIG_PTR &McuModuleConfiguration
#define MCU_CLOCK_CFG_PARAM 0U

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef PLATFORMS_MODULES_H */

/*==================[end of file]===========================================*/
