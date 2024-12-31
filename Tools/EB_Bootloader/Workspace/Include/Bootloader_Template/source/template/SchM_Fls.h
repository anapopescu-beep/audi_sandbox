#ifndef SCHM_FLS_H
#define SCHM_FLS_H
/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* ==================[Includes]=============================================== */
//#include <SchM_FlsType.h>

/* ==================[Declaration of functions with external linkage]========= */
extern FUNC(void, RTE_CODE) SchM_Enter_Fls_Exclusive_Area_00 (void);
extern FUNC(void, RTE_CODE) SchM_Exit_Fls_Exclusive_Area_00 (void);
extern FUNC(void, RTE_CODE) SchM_Enter_Fls_Exclusive_Area_01 (void);
extern FUNC(void, RTE_CODE) SchM_Exit_Fls_Exclusive_Area_01 (void);
extern FUNC(void, RTE_CODE) SchM_Enter_Fls_Exclusive_Area_02 (void);
extern FUNC(void, RTE_CODE) SchM_Exit_Fls_Exclusive_Area_02 (void);
extern FUNC(void, RTE_CODE) SchM_Enter_Fls_Exclusive_Area_03 (void);
extern FUNC(void, RTE_CODE) SchM_Exit_Fls_Exclusive_Area_03 (void);
extern FUNC(void, RTE_CODE) SchM_Enter_Fls_Exclusive_Area_04 (void);
extern FUNC(void, RTE_CODE) SchM_Exit_Fls_Exclusive_Area_04 (void);
extern FUNC(void, RTE_CODE) SchM_Enter_Fls_Exclusive_Area_06 (void);
extern FUNC(void, RTE_CODE) SchM_Exit_Fls_Exclusive_Area_06 (void);
#define FLS_START_SEC_CODE
#include <Fls_MemMap.h>

extern FUNC(void, FLS_CODE) Fls_MainFunction (void);

#define FLS_STOP_SEC_CODE
#include <Fls_MemMap.h>

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
