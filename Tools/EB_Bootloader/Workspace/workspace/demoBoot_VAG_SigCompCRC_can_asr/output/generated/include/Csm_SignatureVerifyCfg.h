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
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*================================================================================================*/

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 8.8 (required)
 *   "An external object or function shall be declared in one and only one file."
 *
 *   Reason:
 *   For each provided Csm service, the used callback functions are declared independent from the
 *   callbacks used for other services. The redundant redeclaration of callback functions are caused
 *   by certain test configurations, which use the same callback for
 *   different Csm services.
 */


#ifndef CSM_SIGNATUREVERIFYCFG_H
#define CSM_SIGNATUREVERIFYCFG_H

/*==================[includes]====================================================================*/

#include <Csm_Cfg.h>
#include <Csm_Types.h>

/*==================[macros]======================================================================*/

/* !LINKSTO CSM0015, 1
 */
#define  CSM_SIGNATUREVERIFY_ENABLED  STD_ON

/** \brief Macro indicating whether there is an Rte Interface for the SignatureVerify service.
 */
#define  CSM_SIGNATUREVERIFY_RTE_INTERFACE_ENABLED  STD_OFF

/** \brief Macro indicating whether the immediate restart feature is enabled for the SignatureVerify service.
 */
#define  CSM_SIGNATUREVERIFY_IMMEDIATE_RESTART_ENABLED  STD_OFF

/** \brief Macro indicating whether there is an Synchronous Interface for the SignatureVerify service.
 */
#define  CSM_SIGNATUREVERIFY_SYNCJOBPROCESSING_ENABLED  STD_OFF

/* !LINKSTO CSM0026, 1
 */
#define CsmSignatureVerifyConfig_0 (Csm_ConfigIdType)0U

/*==================[type definitions]============================================================*/

/* !LINKSTO EB_CSM0074_01, 1
 */
/** \struct  Csm_SignatureVerifyConfigType
 ** \brief   Structure which contains the configuration for a signature verification
 **          service
 **//**
 ** \var     Csm_SignatureVerifyConfigType::CallbackFct
 ** \brief   A pointer to the callback function which has to be called when
 **          the current start, update, or finish computation is completed.
 **//**
 ** \var     Csm_SignatureVerifyConfigType::PrimitiveStartFct
 ** \brief   A pointer to the start function of the primitive.
 **//**
 ** \var     Csm_SignatureVerifyConfigType::PrimitiveUpdateFct
 ** \brief   A pointer to the update function of the primitive.
 **//**
 ** \var     Csm_SignatureVerifyConfigType::PrimitiveFinishFct
 ** \brief   A pointer to the finish function of the primitive.
 **//**
 ** \var     Csm_SignatureVerifyConfigType::PrimitiveMainFct
 ** \brief   A pointer to the main function of the primitive.
 **//**
 ** \var     Csm_SignatureVerifyConfigType::PrimitiveConfigPtr
 ** \brief   A pointer to the configuration object of the primitive.
 **//**
 ** \var     Csm_SignatureVerifyConfigType::CsmSignatureVerifyEnableRestart
 ** \brief   A constant to the enable cancel configuration object of the primitive.
 **//**
 ** \var     Csm_SignatureVerifyConfigType::CsmSignatureVerifyUsePriorities
 ** \brief   A constant to the enable priority handling of the primitive.
 **/
typedef struct
{
  /* !LINKSTO CSM0032, 1
   */
  Csm_CallbackType CallbackFct;
  /* !LINKSTO CSM0701, 1
   */
  P2FUNC(Csm_ReturnType, CSM_APPL_CODE, PrimitiveStartFct)
  (
    P2CONST(void,                  AUTOMATIC, CSM_APPL_DATA) cfgPtr,
    P2CONST(Csm_AsymPublicKeyType, AUTOMATIC, CSM_APPL_DATA) keyPtr
  );

  /* !LINKSTO EB_CSM0702_01, 1
   */
  P2FUNC(Csm_ReturnType, CSM_APPL_CODE, PrimitiveUpdateFct)
  (
    P2CONST(uint8,  AUTOMATIC, CSM_APPL_DATA) dataPtr,
            uint32                            dataLength
  );

  /* !LINKSTO EB_CSM0703_01, 1
   */
  P2FUNC(Csm_ReturnType, CSM_APPL_CODE, PrimitiveFinishFct)
  (
    P2CONST(uint8,                AUTOMATIC, CSM_APPL_DATA) signaturePtr,
            uint32                                          signatureLength,
      P2VAR(Csm_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) resultPtr
  );

  /* !LINKSTO CSM0773, 1
  */
  P2FUNC(void, CSM_APPL_CODE, PrimitiveMainFct)
  (
    void
  );

  /* !LINKSTO CSM0732, 1
   */
  P2CONST(void, AUTOMATIC, CSM_APPL_CONST) PrimitiveConfigPtr;

  CONST(boolean, CSM_CONST) CsmSignatureVerifyEnableRestart;
  CONST(boolean, CSM_CONST) CsmSignatureVerifyUsePriorities;
}
Csm_SignatureVerifyConfigType;

/*==================[external function declarations]==============================================*/

#define CSM_START_SEC_CODE
#include <MemMap.h>


/* !LINKSTO CSM0037, 1
 */

/* Deviation MISRA-1 <START> */
extern FUNC(Std_ReturnType, CSM_APPL_CODE) PROG_CsmNotification
(
  Csm_ReturnType Result
);
/* Deviation MISRA-1 <STOP> */


#define CSM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[external constants]==========================================================*/

#define CSM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/* !LINKSTO CSM0025, 1
 */
extern CONST(Csm_SignatureVerifyConfigType, CSM_CONST)
  Csm_SignatureVerifyConfigurations[1];

#define CSM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #ifndef CSM_SIGNATUREVERIFYCFG_H */

