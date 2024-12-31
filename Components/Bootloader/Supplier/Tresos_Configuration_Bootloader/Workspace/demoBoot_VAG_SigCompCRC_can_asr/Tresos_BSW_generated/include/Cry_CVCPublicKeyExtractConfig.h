/* --------{ EB Automotive C Source File }-------- */

/* !LINKSTO EB_CRY_0003,1 */

#ifndef CRY_CVCPUBLICKEYEXTRACTCONFIG_H
#define CRY_CVCPUBLICKEYEXTRACTCONFIG_H

/*==================[includes]====================================================================*/

#include <Std_Types.h>

/*==================[macros]======================================================================*/

#if (defined CRY_CVCPUBLICKEYEXTRACT_ENABLED)
#error CRY_CVCPUBLICKEYEXTRACT_ENABLED is already defined
#endif
/* !LINKSTO EB_CRY_0018,1 */
/** \brief Indicates whether a CVCPublicKeyExtract configuration exists.
 */
#define CRY_CVCPUBLICKEYEXTRACT_ENABLED STD_OFF

#if (CRY_CVCPUBLICKEYEXTRACT_ENABLED == STD_ON)

#if (defined CRY_CVCPUBKEY_ROOTCERT_LEN_BYTES)
#error CRY_CVCPUBKEY_ROOTCERT_LEN_BYTES is already defined
#endif
#define CRY_CVCPUBKEY_ROOTCERT_LEN_BYTES   0U

#if (defined CRY_CVCPUBKEY_SIGCERT_LEN_BYTES)
#error CRY_CVCPUBKEY_SIGCERT_LEN_BYTES is already defined
#endif
#define CRY_CVCPUBKEY_SIGCERT_LEN_BYTES    0U

/*==================[type definitions]============================================================*/

/*---[struct]-------------------------------------------------------------------------------------*/

/* !LINKSTO EB_CRY_0017,1 */
/** \brief  Configuration type for a configured CVC Public key extraction configuration.
 **/
typedef struct
{
  Csm_ConfigIdType VerifySignatureCfg;
  boolean          EnableCertChain;
}
Cry_CVCPublicKeyExtractConfigType;

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/
/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CRY_CVCPUBLICKEYEXTRACT_ENABLED == STD_ON) */

#endif /* #ifndef CRY_CVCPUBLICKEYEXTRACTCONFIG_H */
