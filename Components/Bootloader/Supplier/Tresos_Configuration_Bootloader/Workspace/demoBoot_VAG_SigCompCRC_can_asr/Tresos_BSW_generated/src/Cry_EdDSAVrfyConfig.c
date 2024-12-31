/* --------{ EB Automotive C Source File }-------- */

/*==[Includes]================================================================*/

#include <Std_Types.h>

#include <Csm_Hash.h>
#include <Csm_Types.h>
#include <Csm_SignatureVerify.h>

#include <Cry_LN.h>
#include <Cry_EdDSA.h>
#include <Cry_EdDSAVrfyConfig.h>

#if (CRY_EDDSA_VRFY_ENABLED == STD_ON)

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

#else /* #if (CRY_EDDSA_VRFY_ENABLED == STD_ON) */

/** Dummy definition preventing this file from being empty,
 *  if there is no EdDSA verify configuration.
 */
typedef void Cry_EdDSAVrfyConfig_PrvtEmptyTranslationUnitType;

#endif /* #if (CRY_EDDSA_VRFY_ENABLED == STD_ON) #else */
