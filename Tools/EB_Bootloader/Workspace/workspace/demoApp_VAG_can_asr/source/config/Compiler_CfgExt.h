/**
 * \file
 *
 * \brief AUTOSAR Demo_DAG
 *
 * This file contains the implementation of the AUTOSAR
 * module Demo_DAG.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined COMPILER_CFG_EXT_H)
#define COMPILER_CFG_EXT_H

/*==================[inclusions]=============================================*/

/*------------------[Compiler_Cfg extensions]--------------------------------*/
#if (defined CAN_CODE)
#error CAN_CODE already defined
#endif
#define CAN_CODE

#if (defined CAN_CONST)
#error CAN_CONST already defined
#endif
#define CAN_CONST

#if (defined CAN_VAR_NOINIT)
#error CAN_VAR_NOINIT already defined
#endif
#define CAN_VAR_NOINIT

#if (defined CAN_VAR)
#error CAN_VAR already defined
#endif
#define CAN_VAR

#endif /* if !defined( COMPILER_CFG_EXT_H ) */
/*==================[end of file]============================================*/
