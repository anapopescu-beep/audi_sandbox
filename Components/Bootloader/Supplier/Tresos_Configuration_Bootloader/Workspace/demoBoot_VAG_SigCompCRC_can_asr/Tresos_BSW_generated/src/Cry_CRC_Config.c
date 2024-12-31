/* --------{ EB Automotive C Source File }-------- */

/*==================[includes]====================================================================*/




#include <Std_Types.h>

#include <Csm_Types.h>
#include <Csm.h>

#include <Cry_CRC_Config.h>

#if (CRY_CRC_ENABLED == TRUE)

/*==================[macros]======================================================================*/

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[internal function declarations]==============================================*/

/*==================[external constants]==========================================================*/


/*==================[internal constants]==========================================================*/

#define CRY_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

CONSTP2CONST(Cry_CRC_ConfigType, CRY_CONST, CRY_APPL_DATA) CryCrcConfigDummy = NULL_PTR;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[external data]===============================================================*/

/*==================[internal data]===============================================================*/

/*==================[external function definitions]===============================================*/

/*==================[internal function definitions]===============================================*/

#else /* #if (CRY_CRC_ENABLED == TRUE) */

/* dummy definition to prevent empty translation unit */
typedef void Cry_CRCConfig_PrvtEmptyTranslationUnitType;

#endif /* #if (CRY_CRC_ENABLED == TRUE) #else */

/*==================[end of file]=================================================================*/
