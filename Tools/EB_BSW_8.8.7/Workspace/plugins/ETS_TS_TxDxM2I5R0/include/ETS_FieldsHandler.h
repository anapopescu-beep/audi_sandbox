#ifndef ETS_FIELDSHANDLER_H
#define ETS_FIELDSHANDLER_H
/**
 * \file
 *
 * \brief AUTOSAR ETS
 *
 * This file contains the implementation of the AUTOSAR
 * module ETS.
 *
 * \version 2.5.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[includes]====================================================================*/

#include "ETS_Types.h"
#include "Rte_ETS_Type.h"
#include "Std_Types.h"
#include "ETS_Cfg.h"

/*==================[macros]======================================================================*/

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/
#define ETS_START_SEC_CODE
#include <ETS_MemMap.h>

#if ( ETS_Fields_InterfaceVersion == TRUE )
extern FUNC(void, RTE_CODE) ETS_GetField_InterfaceVersion(P2VAR(ETS_VersionType, AUTOMATIC, RTE_APPL_DATA) Getter);
extern FUNC(void, RTE_CODE) ETS_SetField_InterfaceVersion(void);
#endif
#if ( ETS_Fields_TestFieldUINT8 == TRUE )
extern FUNC(void, RTE_CODE) ETS_SetField_uint8(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Setter);
extern FUNC(void, RTE_CODE) ETS_GetField_uint8(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Getter);
#endif
#if ( ETS_Fields_TestFieldUINT8Reliable == TRUE )
extern FUNC(void, RTE_CODE) ETS_SetField_uint8Reliable(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Setter);
extern FUNC(void, RTE_CODE) ETS_GetField_uint8Reliable(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Getter);
#endif
#if ( ETS_Fields_TestFieldUINT8Array == TRUE )
extern FUNC(void, RTE_CODE) ETS_SetField_VarArray(P2VAR(ETS_Uint8Array, AUTOMATIC, RTE_APPL_DATA) Setter);
extern FUNC(void, RTE_CODE) ETS_GetField_VarArray(P2VAR(ETS_Uint8Array, AUTOMATIC, RTE_APPL_DATA) Getter);
#endif

#define ETS_STOP_SEC_CODE
#include <ETS_MemMap.h>

#endif /* ETS_FIELDSHANDLER_H */

/*==================[external constants]==========================================================*/

