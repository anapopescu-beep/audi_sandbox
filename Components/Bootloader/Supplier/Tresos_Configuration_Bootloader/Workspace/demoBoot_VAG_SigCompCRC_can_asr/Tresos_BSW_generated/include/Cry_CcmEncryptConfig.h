/* --------{ EB Automotive C Source File }-------- */

/* !LINKSTO EB_CRY_0003,1 */
#ifndef CRY_CCMENCRYPTCONFIG_H
#define CRY_CCMENCRYPTCONFIG_H

/*==================[includes]====================================================================*/

#include <Std_Types.h>

#include <Csm.h>
#include <Cry_CCM_CommonConfig.h>

/*==================[macros]======================================================================*/

#if (defined CRY_CCM_ENC_ENABLED)
#error CRY_CCM_ENC_ENABLED is already defined
#endif
/* !LINKSTO EB_CRY_0018,1 */
#define CRY_CCM_ENC_ENABLED STD_OFF

#if (CRY_CCM_ENC_ENABLED == STD_ON)

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/


/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CRY_CCM_ENC_ENABLED == STD_ON) */

#endif /* #ifndef CRY_CCM_ENCCONFIG_H */
