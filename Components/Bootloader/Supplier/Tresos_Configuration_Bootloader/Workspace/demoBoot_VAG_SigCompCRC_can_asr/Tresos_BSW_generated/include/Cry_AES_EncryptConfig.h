/* --------{ EB Automotive C Source File }-------- */

/* !LINKSTO EB_CRY_0003,1 */

#ifndef CRY_AES_ENCRYPTCONFIG_H
#define CRY_AES_ENCRYPTCONFIG_H

/*==================[includes]====================================================================*/

#include <Std_Types.h>

#include <Cry_AES_CommonConfig.h>

/*==================[macros]======================================================================*/

#if (defined CRY_AES_ENCRYPT_ENABLED)
#error CRY_AES_ENCRYPT_ENABLED is already defined
#endif
/* !LINKSTO EB_CRY_0018,1 */
#define CRY_AES_ENCRYPT_ENABLED STD_OFF

#if (CRY_AES_ENCRYPT_ENABLED == STD_ON)
  
#if (defined PZ1A_CRY_OPTIM_AES_ENCRY_EANABLED)
#error PZ1A_CRY_OPTIM_AES_ENCRY_EANABLED is already defined
#endif

#define PZ1A_CRY_OPTIM_AES_ENCRY_EANABLED STD_OFF

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/



/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CRY_AES_ENCRYPT_ENABLED == STD_ON) */

#endif /* #ifndef CRY_AES_ENCRYPTCONFIG_H */
