/**
 * \file
 *
 * \brief AUTOSAR FrIf
 *
 * This file contains the implementation of the AUTOSAR
 * module FrIf.
 *
 * \version 5.3.29
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
[!CODE!]
[!AUTOSPACING!]
#ifndef FRIF_LCFG_H
#define FRIF_LCFG_H

/*
 * Include Section
 */
#include <FrIf_Api.h>      /* FrIf public API */

/*
 * Global function declarations
 */
/* start code section declaration */
#define FRIF_START_SEC_CODE
#include <FrIf_MemMap.h>

[!SELECT "FrIfGeneral"!]
[!FOR "i" = "1" TO "FrIfNumClstSupported"!]
extern FUNC(void,FRIF_CODE) FrIf_MainFunction_[!"num:i($i - 1)"!](void);
extern FUNC(void,FRIF_CODE) FrIf_JobListExec_[!"num:i($i - 1)"!](void);
[!ENDFOR!]
[!ENDSELECT!]

/* stop code section declaration */
#define FRIF_STOP_SEC_CODE
#include <FrIf_MemMap.h>

#endif /* FRIF_LCFG_H */
/*==================[end of file]============================================*/
[!ENDCODE!][!//

