/* --------{ EB Automotive C Source File }-------- */

/* !LINKSTO EB_CRY_0003,1 */



#ifndef CRY_SHA1CONFIG_H
#define CRY_SHA1CONFIG_H

/*==[Includes]================================================================*/

#include <Std_Types.h>

#include <Csm_Types.h>
#include <Csm.h>
#include <Cry_SHA_CommonConfig.h>

/*==[Macros]==================================================================*/

/* !LINKSTO EB_CRY_0018,1 */
#if (defined CRY_SHA1_ENABLED)
#error CRY_SHA1_ENABLED is already defined
#endif
#define CRY_SHA1_ENABLED STD_OFF

/*==[Types]===================================================================*/

/*==[Constants with external linkage]=========================================*/


/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

#endif
