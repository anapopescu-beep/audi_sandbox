/**
 * \file
 *
 * \brief AUTOSAR Csm
 *
 * This file contains the implementation of the AUTOSAR
 * module Csm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2019 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*================================================================================================*/

/*==================[includes]====================================================================*/

#include <Csm_Types.h>
#include <Csm_SymBlockDecryptCfg.h>

#include <Cry_AES_Decrypt.h>

/*==================[macros]======================================================================*/

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[internal function declarations]==============================================*/

/*==================[external constants]==========================================================*/

#define CSM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/* !LINKSTO CSM0025, 1
 */
/* !LINKSTO CSM0535, 1
 */
CONST(Csm_SymBlockDecryptConfigType, CSM_CONST)
  Csm_SymBlockDecryptConfigurations[1] =
{
  {
    &Cry_CbcPkcs7DecryptCallback,
    &Cry_AES_DecryptStart,
    &Cry_AES_DecryptUpdate,
    &Cry_AES_DecryptFinish,
    &Cry_AES_DecryptMainFunction,
    &(CryAESDecryptConfig_0),
    TRUE,
    TRUE
  },
};

#define CSM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[internal constants]==========================================================*/

/*==================[external data]===============================================================*/

/*==================[internal data]===============================================================*/

/*==================[external function definitions]===============================================*/

/*==================[internal function definitions]===============================================*/

/*==================[end of file]=================================================================*/

