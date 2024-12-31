#ifndef ETS_SERVICES_H
#define ETS_SERVICES_H
/**
 * \file
 *
 * \brief AUTOSAR ETS
 *
 * This file contains the implementation of the AUTOSAR
 * module ETS.
 *
 * \version 2.5.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[includes]====================================================================*/

#include <Std_Types.h>
#include <ETS_Macros.h>

/*==================[macros]======================================================================*/

/** \brief  Constant indicating that no error occured.
 **
 **/
#define ETS_OK             0U

/** \brief  Constant indicating that an error occured.
 **
 **/
#define ETS_NOK            1U

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

#define ETS_START_SEC_CODE
#include <ETS_MemMap.h>


#define ETS_STOP_SEC_CODE
#include <ETS_MemMap.h>

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #ifndef ETS_SERVICES_H */

/*==================[end of file]=================================================================*/

