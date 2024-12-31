/* --------{ EB Automotive C Source File }-------- */

/* !LINKSTO EB_CRY_0003,1 */

#ifndef CRY_CBCPKCS7DECRYPTCONFIG_H
#define CRY_CBCPKCS7DECRYPTCONFIG_H

/*==================[includes]====================================================================*/

#include <Std_Types.h>

#include <Csm.h>

/*==================[macros]======================================================================*/

#if (defined CRY_CBC_PKCS7_DEC_ENABLED)
#error CRY_CBC_PKCS7_DEC_ENABLED is already defined
#endif
/* !LINKSTO EB_CRY_0018,1 */
#define CRY_CBC_PKCS7_DEC_ENABLED STD_ON

#if (CRY_CBC_PKCS7_DEC_ENABLED == STD_ON)

/*==================[type definitions]============================================================*/

/* !LINKSTO EB_CRY_0017,1 */
/** \brief  Configuration type for representing a configured AES algorithm.
 **/
typedef struct
{
  Csm_ConfigIdType symBlockDecryptCfgId;
}
Cry_CbcPkcs7DecryptConfigType;

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/


#define CRY_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/* !LINKSTO EB_CRY_0023,1 */

extern CONST(Cry_CbcPkcs7DecryptConfigType, CRY_CONST) CryCbcPkcs7DecryptConfig_0;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>


/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CRY_CBC_PKCS7_DEC_ENABLED == STD_ON) */

#endif /* #ifndef CRY_CBC_PKCS7_DECCONFIG_H */
