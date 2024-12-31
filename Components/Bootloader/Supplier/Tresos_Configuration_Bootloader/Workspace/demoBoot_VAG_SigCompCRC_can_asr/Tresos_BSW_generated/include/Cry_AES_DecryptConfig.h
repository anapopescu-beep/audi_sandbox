/* --------{ EB Automotive C Source File }-------- */

/* !LINKSTO EB_CRY_0003,1 */

#ifndef CRY_AES_DECRYPTCONFIG_H
#define CRY_AES_DECRYPTCONFIG_H

/*==================[includes]====================================================================*/

#include <Std_Types.h>

#include <Cry_AES_CommonConfig.h>

/*==================[macros]======================================================================*/

#if (defined CRY_AES_DECRYPT_ENABLED)
#error CRY_AES_DECRYPT_ENABLED is already defined
#endif
/* !LINKSTO EB_CRY_0018,1 */
#define CRY_AES_DECRYPT_ENABLED STD_ON

#if (CRY_AES_DECRYPT_ENABLED == STD_ON)
  
#if (defined PZ1A_CRY_OPTIM_AES_DECRY_EANABLED)
#error PZ1A_CRY_OPTIM_AES_DECRY_EANABLED is already defined
#endif

#define PZ1A_CRY_OPTIM_AES_DECRY_EANABLED STD_OFF

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/


#define CRY_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/* !LINKSTO EB_CRY_0023,1 */

extern CONST(Cry_AES_ConfigType, CRY_CONST) CryAESDecryptConfig_0;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>


/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CRY_AES_DECRYPT_ENABLED == STD_ON) */

#endif /* #ifndef CRY_AES_DECRYPTCONFIG_H */
