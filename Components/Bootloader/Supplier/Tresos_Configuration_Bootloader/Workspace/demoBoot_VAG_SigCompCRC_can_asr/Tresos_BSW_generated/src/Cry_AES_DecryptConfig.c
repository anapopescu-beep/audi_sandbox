/* --------{ EB Automotive C Source File }-------- */

/* !LINKSTO EB_CRY_0006,1 */

/*==================[includes]====================================================================*/

#include <Std_Types.h>
#include <Csm_Types.h>
#include <Csm.h>
#include <Cry_AES_DecryptConfig.h>

#if (CRY_AES_DECRYPT_ENABLED == STD_ON)

/*==================[macros]======================================================================*/

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[internal function declarations]==============================================*/

/*==================[external constants]==========================================================*/

#define CRY_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

CONST(Cry_AES_ConfigType, CRY_CONST) CryAESDecryptConfig_0 =
{
  CRY_AES_KEY_128
};

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[internal constants]==========================================================*/

/*==================[external data]===============================================================*/

/*==================[internal data]===============================================================*/

/*==================[external function definitions]===============================================*/

/*==================[internal function definitions]===============================================*/

#else /* #if (CRY_AES_DECRYPT_ENABLED == STD_ON) */

typedef uint8 Cry_AES_DecryptConfig_PrvtEmptyTranslationUnitType;

#endif /* #if (CRY_AES_DECRYPT_ENABLED == STD_ON) #else */

/*==================[end of file]=================================================================*/
