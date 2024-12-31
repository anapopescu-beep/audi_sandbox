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
#include <Csm_SymDecryptCfg.h>

#include <Cry_CbcPkcs7Decrypt.h>

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
CONST(Csm_SymDecryptConfigType, CSM_CONST)
  Csm_SymDecryptConfigurations[1] =
{
  {
    &PROG_CsmEncryptDecryptNotification,
    &Cry_CbcPkcs7DecryptStart,
    &Cry_CbcPkcs7DecryptUpdate,
    &Cry_CbcPkcs7DecryptFinish,
    &Cry_CbcPkcs7DecryptMainFunction,
    &(CryCbcPkcs7DecryptConfig_0),
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

