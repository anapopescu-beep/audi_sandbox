/* --------{ EB Automotive C Source File }-------- */

/* !LINKSTO EB_CRY_0006,1 */

/*==[Includes]================================================================*/

#include <Std_Types.h>
#include <Csm_Types.h>
#include <Csm_Hash.h>
#include <Cry_LN.h>
#include <Cry_CommonConfig.h>
#include <Cry_RsaSsaV15VerifyConfig.h>

#if(CRY_RSASSAV15VERIFY_ENABLED == STD_ON)

#if (CRY_RSASSAV15VERIFY_USE_CBK == STD_ON)
#include <Cry_RsaSsaV15VerifyCbk.h>
#endif

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

#else /* #if(CRY_RSASSAV15VERIFY_ENABLED == STD_ON) */

typedef uint8 Cry_RsaSsaV15VerifyConfig_PrvtEmptyTranslationUnitType;

#endif /* #if(CRY_RSASSAV15VERIFY_ENABLED == STD_ON) else */
