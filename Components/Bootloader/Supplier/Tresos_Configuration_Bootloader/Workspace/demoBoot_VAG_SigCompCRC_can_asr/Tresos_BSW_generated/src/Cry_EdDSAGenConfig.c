/* --------{ EB Automotive C Source File }-------- */

/*==[Includes]================================================================*/

#include <Std_Types.h>

#include <Csm_Hash.h>
#include <Csm_Types.h>
#include <Csm_SignatureGenerate.h>

#include <Cry_LN.h>
#include <Cry_EdDSA.h>
#include <Cry_EdDSAGenConfig.h>

#if (CRY_EDDSA_GEN_ENABLED == STD_ON)

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/

/*==[Declaration of functions with internal linkage]==========================*/

/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/

/*==[Constants with external linkage]=========================================*/

#define CRY_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>


#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/

/*==[Definition of functions with internal linkage]===========================*/

#else  /* #if (CRY_EDDSA_GEN_ENABLED == STD_ON) */

typedef uint8 Cry_EdDSAGenConfigDummyType_PrvtEmptyTranslationUnitType;
#endif /* #if (CRY_EDDSA_GEN_ENABLED == STD_ON) */
