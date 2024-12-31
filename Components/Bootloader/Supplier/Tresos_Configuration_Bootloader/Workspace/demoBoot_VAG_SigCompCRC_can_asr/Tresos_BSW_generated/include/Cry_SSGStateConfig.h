/* --------{ EB Automotive C Source File }-------- */

/* !LINKSTO EB_CRY_0003,1 */

#ifndef CRY_SSGSTATECONFIG_H
#define CRY_SSGSTATECONFIG_H

/*==[Includes]================================================================*/

#include <Std_Types.h>

#include <Csm_Types.h>
#include <Csm.h>

#include <Cry_Common.h>

/*==[Macros]==================================================================*/

#if (defined CRY_SSGSTATE_ENABLED)
#error CRY_SSGSTATE_ENABLED is already defined
#endif
#define CRY_SSGSTATE_ENABLED STD_OFF

#if (CRY_SSGSTATE_ENABLED == STD_ON)

/*==[Types]===================================================================*/


typedef uint8 Cry_SSGStateType[1];

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>

/* !LINKSTO EB_CRY_0023,1 */


#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>

/*==[Declaration of functions with external linkage]==========================*/

#endif /* #if (CRY_SSG_ENABLED == STD_ON) */

#endif
