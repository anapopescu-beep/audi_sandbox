/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \version 5.0.15
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* MISRA-C:2004 Deviation List
  *
  * MISRA-1) Deviated Rule: 12.4 (required)
  *     The right-hand operand of a logical '&&' or '||' operator
  *     shall not contain side effects.
  *
  *     Reason:
  *     Logical operators '&&' and '||' are used here purposefully. The sub-expression shall not be
  *      evaluated if the first expression of a '&&' operation is FALSE. Similarly the
  *      sub-expression shall not be evaluated if the first expression of a '||' operation is TRUE.
  *      There is no side effects.
  *
  * MISRA-2) Deviated Rule: 11.4 (advisory)
  *     A cast should not be performed between a pointer to object type and a
  *     different pointer to object type.
  *
  *     Reason:
  *     A cast to unsigned is necessary here to copy data bit by bit and
  *     there is no alignment issues.
  *
  * MISRA-3) Deviated Rule: 11.1 (required)
  *     Conversions shall not be performed between a pointer to a function and
  *     any type other than an integral type.
  *
  *     Reason:
  *     In order to save memory, the function pointers necessary for DID operations are generated
  *     as an array of unions (union type which contains all such possible function pointers),
  *     instead of an array of structures containing all possible pointer types.
  *     The array containing the function pointers is initialized using brace-enclosed initializer
  *     list and C90 standard allows only the initialization of the first union member.
  *     The solution is to use a "generic function pointer" and use that type to define the array,
  *     and use explicit casts for each initialized member.
  *     Casting one function pointer type to the general type at initialization and then back again
  *     to the original type is guaranteed to preserve the correct data.
  *
  */

 /* MISRA-C:2012 Deviation List
  *
  *  MISRAC2012-1) Deviated Rule: 11.1 (required)
  *     "Conversions shall not be performed between a pointer to a function and any other type."
  *
  *     Reason:
  *     In order to save memory, the function pointers necessary for DID operations are generated
  *     as an array of unions (union type which contains all such possible function pointers),
  *     instead of an array of structures containing all possible pointer types.
  *     The array containing the function pointers is initialized using brace-enclosed initializer
  *     list and C90 standard allows only the initialization of the first union member.
  *     The solution is to use a "generic function pointer" and use that type to define the array,
  *     and use explicit casts for each initialized member.
  *     Casting one function pointer type to the general type at initialization and then back again
  *     to the original type is guaranteed to preserve the correct data.
  *
  *  MISRAC2012-2) Deviated Rule: 13.5 (required)
  *     "The right hand operand of a logical && or || operator shall not contain persistent
  *     side effects."
  *
  *     Reason:
  *     Logical operators '&&' and '||' are used here purposefully. The sub-expression shall not be
  *     evaluated if the first expression of a '&&' operation is FALSE. Similarly the
  *     sub-expression shall not be evaluated if the first expression of a '||' operation is TRUE.
  *     There is no side effects.
  *
  *  MISRAC2012-3) Deviated Rule: 11.3 (required)
  *     "A cast should not be performed between a pointer to object type and a different pointer to
  *     object type."
  *
  *     Reason:
  *     A cast to UINT8 is necessary here to copy data bit by bit and to be flexible for all
  *     the types, being no alignment issues.
  *     There is no side effects.
  *
  *  MISRAC2012-4) Deviated Rule: 8.9 (advisory)
  *     "An object should be defined at block scope if its identifier only
  *     appears in a single function."
  *
  *     Reason:
  *     The object is defined in this way because the values that are stored
  *     in them are required for the next call of this function and should be
  *     hold in the data segment memory.
  */

/*==================[inclusions]=================================================================*/
#include <ComStack_Types.h>                                            /* AUTOSAR standard types */
#include <Dcm_Cfg.h>                                           /* Generated configuration header */
#include <Dcm_API_Cfg.h>                                  /*  Configurable function declarations */
#include <Dcm_Hsm.h>                                                        /* Dcm State Machine */
#include <Dcm_Int.h>                                       /* Module internal header static part */
#include <Dcm_DspExternal.h>                          /* Callbacks provided by Central Diag SwC  */
#include <Dcm_Dsl_Supervisor.h>                                       /* Module internal header static part */

/* OBD Service 0x01 and 0x02*/
#if(DCM_DSP_USE_SERVICE_0X01 == STD_ON) || \
(DCM_DSP_USE_SERVICE_0X02 == STD_ON) || \
(DCM_DSP_USE_SERVICE_0X22 == STD_ON) || \
(DCM_NUM_PID_CFG > 0U)
#include <Dcm_Dsp_PidServices.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X06 == STD_ON)
#include <Dcm_Dsp_SvcH_RequestOnboardMonitoringTestResults.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X08 == STD_ON)
#include <Dcm_Dsp_SvcH_RequestControlOfOnBoardSysTstComp.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X09 == STD_ON)
/* OBD Service 0x09 */
#include <Dcm_Dsp_SvcH_RequestVehicleInformation.h>
#endif

#if ( (DCM_DSP_USE_SERVICE_0X19 == STD_ON) || (DCM_DSP_USE_SERVICE_0XAF == STD_ON) )
#include <Dcm_Dsp_SvcH_ReadDTCInformation.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X22 == STD_ON)
#include <Dcm_Dsp_SvcH_ReadDataByIdentifier.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X23 == STD_ON)
#include <Dcm_Dsp_SvcH_ReadMemoryByAddress.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X24 == STD_ON)
#include <Dcm_Dsp_SvcH_ReadScalingDataByIdentifier.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X2E == STD_ON)
#include <Dcm_Dsp_SvcH_WriteDataByIdentifier.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X34 == STD_ON)
#include <Dcm_Dsp_SvcH_RequestDownload.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X35 == STD_ON)
#include <Dcm_Dsp_SvcH_RequestUpload.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X36 == STD_ON)
#include <Dcm_Dsp_SvcH_TransferData.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X37 == STD_ON)
#include <Dcm_Dsp_SvcH_RequestTransferExit.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X3D == STD_ON)
#include <Dcm_Dsp_SvcH_WriteMemoryByAddress.h>
#endif

#if (DCM_DSP_USE_DIDSERVICES == STD_ON)
/* Include DidServices SW unit header for IO control */
#include <Dcm_Dsp_DidServices.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X85 == STD_ON)
#include <Dcm_Dsp_SvcH_ControlDTCSetting.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X86 == STD_ON)
#include <Dcm_Dsp_SvcH_ResponseOnEvent.h>
#endif

#if (DCM_DSP_USE_ROESERVICES == STD_ON)
#include <Dcm_Dsl_RoeServices.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X2C == STD_ON)
#include <Dcm_Dsp_SvcH_DynamicallyDefineDataIdentifier.h>
#endif

#if(DCM_DSP_USE_SERVICE_0X28 == STD_ON)
#include <Dcm_Dsp_SvcH_CommunicationControl.h>
#endif

#if(DCM_DSP_USE_SERVICE_0X29 == STD_ON)
#include <Dcm_Dsp_SvcH_Authentication.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X87 == STD_ON)
#include <Dcm_Dsp_SvcH_LinkControl.h>
#endif

#if(DCM_DSP_USE_SERVICE_0X27 == STD_ON)
#include <Dcm_Dsp_SvcH_SecurityAccess.h>
#endif

#if(DCM_DSP_USE_MEMORYSERVICES == STD_ON)
#include <Dcm_Dsp_MemoryServices.h>
#endif

#if(DCM_DSP_USE_SERVICE_0X3E == STD_ON)
#include <Dcm_Dsp_SvcH_TesterPresent.h>
#endif

#if(DCM_DSP_USE_SERVICE_0X2F == STD_ON)
#include <Dcm_Dsp_SvcH_InputOutputControlByIdentifier.h>
#endif

#if(DCM_DSP_USE_SERVICE_0X31 == STD_ON)
#include <Dcm_Dsp_SvcH_RoutineControl.h>
#endif


#if ((DCM_DSP_USE_DIDSERVICES == STD_ON) && (DCM_DSP_USE_SENDERRECEIVER_INTERFACES == STD_ON))
#include <Dcm_Dsp_EndiannessInterpretation.h>
#endif

#include <SchM_Dcm.h>

/*==================[macros]=====================================================================*/

/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/

/*==================[internal function declarations]=============================================*/
#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>
/*==================[internal constants]=========================================================*/

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/* Array of session types for all Subservices */
STATIC CONST(Dcm_SesCtrlType,DCM_CONST) Dcm_SubSidTabSesLevels[34] =
{
  0x01U, /* DCM_DEFAULT_SESSION of SID10_DiagnosticSessionControl referred by its subservice Subf_01_DefaultSession */
  0x03U, /* DCM_EXTENDED_SESSION of SID10_DiagnosticSessionControl referred by its subservice Subf_01_DefaultSession */
  0x02U, /* DCM_PROGRAMMING_SESSION of SID10_DiagnosticSessionControl referred by its subservice Subf_01_DefaultSession */
  0x7eU, /* DCM_SUPPLIER_SESSION of SID10_DiagnosticSessionControl referred by its subservice Subf_01_DefaultSession */
  0x03U, /* DCM_EXTENDED_SESSION of SID10_DiagnosticSessionControl referred by its subservice Subf_02_ProgrammingSession */
  0x02U, /* DCM_PROGRAMMING_SESSION of SID10_DiagnosticSessionControl referred by its subservice Subf_02_ProgrammingSession */
  0x01U, /* DCM_DEFAULT_SESSION of SID10_DiagnosticSessionControl referred by its subservice Subf_03_ExtendedSession */
  0x03U, /* DCM_EXTENDED_SESSION of SID10_DiagnosticSessionControl referred by its subservice Subf_03_ExtendedSession */
  0x7eU, /* DCM_SUPPLIER_SESSION of SID10_DiagnosticSessionControl referred by its subservice Subf_03_ExtendedSession */
  0x01U, /* DCM_DEFAULT_SESSION of SID10_DiagnosticSessionControl referred by its subservice Subf_7E_SupplierSession */
  0x03U, /* DCM_EXTENDED_SESSION of SID10_DiagnosticSessionControl referred by its subservice Subf_7E_SupplierSession */
  0x7eU, /* DCM_SUPPLIER_SESSION of SID10_DiagnosticSessionControl referred by its subservice Subf_7E_SupplierSession */
  0x01U, /* DCM_DEFAULT_SESSION of SID11_ECUReset referred by its subservice Subf01_HardReset */
  0x03U, /* DCM_EXTENDED_SESSION of SID11_ECUReset referred by its subservice Subf01_HardReset */
  0x7eU, /* DCM_SUPPLIER_SESSION of SID11_ECUReset referred by its subservice Subf01_HardReset */
  0x01U, /* DCM_DEFAULT_SESSION of SID11_ECUReset referred by its subservice Subf03_SoftReset */
  0x03U, /* DCM_EXTENDED_SESSION of SID11_ECUReset referred by its subservice Subf03_SoftReset */
  0x7eU, /* DCM_SUPPLIER_SESSION of SID11_ECUReset referred by its subservice Subf03_SoftReset */
  0x7eU, /* DCM_SUPPLIER_SESSION of SID27_SecurityAccess referred by its subservice Subf61_SecurityAccess_GetSeed */
  0x02U, /* DCM_PROGRAMMING_SESSION of SID27_SecurityAccess referred by its subservice Subf61_SecurityAccess_GetSeed */
  0x7eU, /* DCM_SUPPLIER_SESSION of SID27_SecurityAccess referred by its subservice Subf62_SecurityAccess_CompareKey */
  0x02U, /* DCM_PROGRAMMING_SESSION of SID27_SecurityAccess referred by its subservice Subf62_SecurityAccess_CompareKey */
  0x02U, /* DCM_PROGRAMMING_SESSION of SID28_CommunicationControl referred by its subservice Subf00_EnableTxEnableRx */
  0x03U, /* DCM_EXTENDED_SESSION of SID28_CommunicationControl referred by its subservice Subf00_EnableTxEnableRx */
  0x7eU, /* DCM_SUPPLIER_SESSION of SID28_CommunicationControl referred by its subservice Subf00_EnableTxEnableRx */
  0x02U, /* DCM_PROGRAMMING_SESSION of SID28_CommunicationControl referred by its subservice Subf01_DisableTxEnableRx */
  0x03U, /* DCM_EXTENDED_SESSION of SID28_CommunicationControl referred by its subservice Subf01_DisableTxEnableRx */
  0x7eU, /* DCM_SUPPLIER_SESSION of SID28_CommunicationControl referred by its subservice Subf01_DisableTxEnableRx */
  0x02U, /* DCM_PROGRAMMING_SESSION of SID85_ControlDTCSetting referred by its subservice Subf00_EnableUpdateDTC */
  0x03U, /* DCM_EXTENDED_SESSION of SID85_ControlDTCSetting referred by its subservice Subf00_EnableUpdateDTC */
  0x7eU, /* DCM_SUPPLIER_SESSION of SID85_ControlDTCSetting referred by its subservice Subf00_EnableUpdateDTC */
  0x02U, /* DCM_PROGRAMMING_SESSION of SID85_ControlDTCSetting referred by its subservice Subf01_DisableUpdateDTC */
  0x03U, /* DCM_EXTENDED_SESSION of SID85_ControlDTCSetting referred by its subservice Subf01_DisableUpdateDTC */
  0x7eU, /* DCM_SUPPLIER_SESSION of SID85_ControlDTCSetting referred by its subservice Subf01_DisableUpdateDTC */
};

/* Array of session types for all services */
STATIC CONST(Dcm_SesCtrlType,DCM_CONST) Dcm_SidTabSesLevels[29] =
{
  0x01U, /* DCM_DEFAULT_SESSION referred to by SID11_ECUReset */
  0x03U, /* DCM_EXTENDED_SESSION referred to by SID11_ECUReset */
  0x7eU, /* DCM_SUPPLIER_SESSION referred to by SID11_ECUReset */
  0x01U, /* DCM_DEFAULT_SESSION referred to by SID14_ClearDiagnosticInformation */
  0x03U, /* DCM_EXTENDED_SESSION referred to by SID14_ClearDiagnosticInformation */
  0x7eU, /* DCM_SUPPLIER_SESSION referred to by SID14_ClearDiagnosticInformation */
  0x7eU, /* DCM_SUPPLIER_SESSION referred to by SID22_ReadDataByIdentifier */
  0x03U, /* DCM_EXTENDED_SESSION referred to by SID22_ReadDataByIdentifier */
  0x01U, /* DCM_DEFAULT_SESSION referred to by SID22_ReadDataByIdentifier */
  0x7eU, /* DCM_SUPPLIER_SESSION referred to by SID23_ReadMemoryByAddress */
  0x02U, /* DCM_PROGRAMMING_SESSION referred to by SID27_SecurityAccess */
  0x7eU, /* DCM_SUPPLIER_SESSION referred to by SID27_SecurityAccess */
  0x02U, /* DCM_PROGRAMMING_SESSION referred to by SID28_CommunicationControl */
  0x03U, /* DCM_EXTENDED_SESSION referred to by SID28_CommunicationControl */
  0x7eU, /* DCM_SUPPLIER_SESSION referred to by SID28_CommunicationControl */
  0x02U, /* DCM_PROGRAMMING_SESSION referred to by SID2E_WriteDataByIdentifier */
  0x7eU, /* DCM_SUPPLIER_SESSION referred to by SID2E_WriteDataByIdentifier */
  0x03U, /* DCM_EXTENDED_SESSION referred to by SID2E_WriteDataByIdentifier */
  0x7eU, /* DCM_SUPPLIER_SESSION referred to by SID31_RoutineControl */
  0x02U, /* DCM_PROGRAMMING_SESSION referred to by SID31_RoutineControl */
  0x03U, /* DCM_EXTENDED_SESSION referred to by SID31_RoutineControl */
  0x7eU, /* DCM_SUPPLIER_SESSION referred to by SID3D_WriteMemoryByAddress */
  0x01U, /* DCM_DEFAULT_SESSION referred to by SID3E_TesterPresent */
  0x02U, /* DCM_PROGRAMMING_SESSION referred to by SID3E_TesterPresent */
  0x03U, /* DCM_EXTENDED_SESSION referred to by SID3E_TesterPresent */
  0x7eU, /* DCM_SUPPLIER_SESSION referred to by SID3E_TesterPresent */
  0x02U, /* DCM_PROGRAMMING_SESSION referred to by SID85_ControlDTCSetting */
  0x03U, /* DCM_EXTENDED_SESSION referred to by SID85_ControlDTCSetting */
  0x7eU, /* DCM_SUPPLIER_SESSION referred to by SID85_ControlDTCSetting */
};

/* Array of security types for all services */
STATIC CONST(Dcm_SecLevelType, DCM_CONST) Dcm_SidTabSecLevels[2] =
{
  0x31U, /* DcmDspSecurityAlv referred to by SID23_ReadMemoryByAddress */
  0x31U, /* DcmDspSecurityAlv referred to by SID3D_WriteMemoryByAddress */
};

#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/* Array of Subservices for Service 'SID10_DiagnosticSessionControl' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig16[6] =
{
  {
    &( Dcm_SubSidTabSesLevels[0]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_DiagnosticSessionControlCommon_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x01U, /* SubServiceId */
    4U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    &( Dcm_SubSidTabSesLevels[4]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_DiagnosticSessionControlCommon_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x02U, /* SubServiceId */
    2U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    &( Dcm_SubSidTabSesLevels[6]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_DiagnosticSessionControlCommon_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x03U, /* SubServiceId */
    3U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_DiagnosticSessionControlCommon_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x60U, /* SubServiceId */
    0U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_DiagnosticSessionControlCommon_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x61U, /* SubServiceId */
    0U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    &( Dcm_SubSidTabSesLevels[9]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_DiagnosticSessionControlCommon_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x7eU, /* SubServiceId */
    3U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
};

/* Array of Subservices for Service 'SID11_ECUReset' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig17[2] =
{
  {
    &( Dcm_SubSidTabSesLevels[12]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_HardReset_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x01U, /* SubServiceId */
    3U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    &( Dcm_SubSidTabSesLevels[15]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_SoftReset_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x03U, /* SubServiceId */
    3U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
};

/* Array of Subservices for Service 'SID27_SecurityAccess' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig39[2] =
{
  {
    &( Dcm_SubSidTabSesLevels[18]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    NULL_PTR, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x61U, /* SubServiceId */
    2U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    &( Dcm_SubSidTabSesLevels[20]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    NULL_PTR, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x62U, /* SubServiceId */
    2U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
};

/* Array of Subservices for Service 'SID28_CommunicationControl' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig40[2] =
{
  {
    &( Dcm_SubSidTabSesLevels[22]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_CommunicationControl_EnableRxAndTx_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x00U, /* SubServiceId */
    3U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    &( Dcm_SubSidTabSesLevels[25]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_CommunicationControl_EnableRxAndDisableTx_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x01U, /* SubServiceId */
    3U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
};

/* Array of Subservices for Service 'SID31_RoutineControl' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig49[3] =
{
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_RoutineControl_StartRoutine_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x01U, /* SubServiceId */
    0x00U, /* Number of sub service session levels */
    0x00U, /* Number of sub service security levels */
  },

  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_RoutineControl_StopRoutine_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x02U, /* SubServiceId */
    0x00U, /* Number of sub service session levels */
    0x00U, /* Number of sub service security levels */
  },

  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_RoutineControl_RequestResults_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x03U, /* SubServiceId */
    0x00U, /* Number of sub service session levels */
    0x00U, /* Number of sub service security levels */
  }
};
/* Array of Subservices for Service 'SID3E_TesterPresent' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig62[1] =
{
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_TesterPresent_ZeroSubFunction_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x00U, /* SubServiceId */
    0U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
};

/* Array of Subservices for Service 'SID85_ControlDTCSetting' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig133[2] =
{
  {
    &( Dcm_SubSidTabSesLevels[28]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_ControlDTCSetting_On_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x01U, /* SubServiceId */
    3U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    &( Dcm_SubSidTabSesLevels[31]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_ControlDTCSetting_Off_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x02U, /* SubServiceId */
    3U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
};

/* Array of services for Service table 'DcmDsdServiceTable_0' (id 0) */
STATIC CONST(Dcm_SidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0[12] =
{
  {
    NULL_PTR,
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig16), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_DspInternal_DiagnosticSessionControl_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x10U, /* ServiceId */
    0U, /* Number of sessions */
    0U, /* Number of security levels */
    6U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[0]), /* Pointer to sessions */
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig17), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_DspInternal_ECUReset_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x11U, /* ServiceId */
    3U, /* Number of sessions */
    0U, /* Number of security levels */
    2U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[3]), /* Pointer to sessions */
    NULL_PTR,
    NULL_PTR, /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_DspInternal_ClearDiagnosticInformation_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x14U, /* ServiceId */
    3U, /* Number of sessions */
    0U, /* Number of security levels */
    0U, /* Number of subservices */
    FALSE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[6]), /* Pointer to sessions */
    NULL_PTR,
    NULL_PTR, /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_ReadDataByIdentifier_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x22U, /* ServiceId */
    3U, /* Number of sessions */
    0U, /* Number of security levels */
    0U, /* Number of subservices */
    FALSE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[9]), /* Pointer to sessions */
    &( Dcm_SidTabSecLevels[0]),/* Pointer to security levels */
    NULL_PTR, /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_ReadMemoryByAddress_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x23U, /* ServiceId */
    1U, /* Number of sessions */
    1U, /* Number of security levels */
    0U, /* Number of subservices */
    FALSE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[10]), /* Pointer to sessions */
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig39), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_SecurityAccess_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x27U, /* ServiceId */
    2U, /* Number of sessions */
    0U, /* Number of security levels */
    2U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[12]), /* Pointer to sessions */
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig40), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_CommunicationControl_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x28U, /* ServiceId */
    3U, /* Number of sessions */
    0U, /* Number of security levels */
    2U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[15]), /* Pointer to sessions */
    NULL_PTR,
    NULL_PTR, /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_WriteDataByIdentifier_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x2eU, /* ServiceId */
    3U, /* Number of sessions */
    0U, /* Number of security levels */
    0U, /* Number of subservices */
    FALSE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[18]), /* Pointer to sessions */
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig49), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_RoutineControl_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x31U, /* ServiceId */
    3U, /* Number of sessions */
    0U, /* Number of security levels */
    3U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[21]), /* Pointer to sessions */
    &( Dcm_SidTabSecLevels[1]),/* Pointer to security levels */
    NULL_PTR, /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_WriteMemoryByAddress_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x3dU, /* ServiceId */
    1U, /* Number of sessions */
    1U, /* Number of security levels */
    0U, /* Number of subservices */
    FALSE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[22]), /* Pointer to sessions */
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig62), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_TesterPresent_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x3eU, /* ServiceId */
    4U, /* Number of sessions */
    0U, /* Number of security levels */
    1U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[26]), /* Pointer to sessions */
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig133), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_ControlDTCSetting_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x85U, /* ServiceId */
    3U, /* Number of sessions */
    0U, /* Number of security levels */
    2U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
};

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

STATIC CONST(Dcm_SecLevelType,DCM_CONST) Dcm_ReadMemSecLevels[4] =
{
  0x31U,
  0x31U,
  0x31U,
  0x31U,
};

STATIC CONST(Dcm_SecLevelType,DCM_CONST) Dcm_WriteMemSecLevels[2] =
{
  0x31U,
  0x31U,
};
#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#if (DCM_DSP_USE_DIDSERVICES == STD_ON)
/* Array of signals configured Did services */
/* !LINKSTO Dcm.Dsn.DidSignals.ConfigurationData.DidSignals,1 */
CONST(Dcm_DidSignalType,DCM_CONST) Dcm_DidSignals[DCM_DID_SIGNALS_COUNT] =
{
  { 0U, 41U }, /* signal 0 of Did DID_0236_ProgrammingDataElockEcuDid */
  { 0U, 42U }, /* signal 0 of Did DID_023E_WSCForProgrammingElockEcuDid */
  { 0U, 29U }, /* signal 0 of Did DID_0407_VWLogicalSoftwareBlockCounterOfProgrammingAttemptsDid */
  { 0U, 30U }, /* signal 0 of Did DID_040F_VWLogicalSoftwareBlockLockValueDid */
  { 0U, 31U }, /* signal 0 of Did DID_0410_BootloaderTPBlocksizeDid */
  { 0U, 32U }, /* signal 0 of Did DID_0448_ProgrammingPreconditionsDid */
  { 0U, 0U }, /* signal 0 of Did DID_4024_SWSystemTimeDid */
  { 0U, 40U }, /* signal 0 of Did DID_F15B_FingerprintAndProgrammingDateOfLogicalSoftwareBlocksDid */
  { 0U, 9U }, /* signal 0 of Did DID_F186_ActiveDiagnosticSessionDid */
  { 0U, 24U }, /* signal 0 of Did DID_F187_VWSparePartNumberDid */
  { 0U, 25U }, /* signal 0 of Did DID_F189_VWApplicationSoftwareVersionNumberDid */
  { 0U, 38U }, /* signal 0 of Did DID_F18C_ECUSerialNumberDid */
  { 0U, 26U }, /* signal 0 of Did DID_F191_VWECUHardwareNumberDid */
  { 0U, 27U }, /* signal 0 of Did DID_F197_VWSystemNameOrEngineTypeDid */
  { 0U, 34U }, /* signal 0 of Did DID_F19E_ASAMODXFileIdentifierDid */
  { 0U, 35U }, /* signal 0 of Did DID_F1A2_ASAMODXFileVersionDid */
  { 0U, 37U }, /* signal 0 of Did DID_F1A3_VWECUHardwareVersionNumberDid */
  { 0U, 39U }, /* signal 0 of Did DID_F1AB_VWLogicalSoftwareBlockVersionDid */
  { 0U, 28U }, /* signal 0 of Did DID_F1B4_TechnicalSpecificationsVersionDid */
  { 0U, 36U }, /* signal 0 of Did DID_F1D5_FDSProjectDataDid */
  { 0U, 33U }, /* signal 0 of Did DID_F1DF_ECUProgrammingInformationDid */
  { 0U, 1U }, /* signal 0 of Did DID_FD00_HWVersionDid */
  { 0U, 2U }, /* signal 0 of Did DID_FD01_SWVersionDid */
  { 0U, 3U }, /* signal 0 of Did DID_FD03_AEETraceabilityNumberDid */
  { 0U, 4U }, /* signal 0 of Did DID_FD08_ResetCauseDid */
  { 0U, 5U }, /* signal 0 of Did DID_FD09_LastWarmResetParamDid */
  { 0U, 12U }, /* signal 0 of Did DID_FD0F_BatteryMeasureDid */
  { 0U, 13U }, /* signal 0 of Did DID_FD10_ECUTemperature */
  { 0U, 6U }, /* signal 0 of Did DID_FD62_EccOccurenceNbDid */
  { 0U, 10U }, /* signal 0 of Did DID_FD8B_ECUManufacturingDateDid */
  { 0U, 11U }, /* signal 0 of Did DID_FD8C_AssemblySerialNumberDid */
  { 0U, 14U }, /* signal 0 of Did DID_FDE0_EcsVariantDid */
  { 0U, 15U }, /* signal 0 of Did DID_FDE1_EcsParametersDid */
  { 0U, 16U }, /* signal 0 of Did DID_FDE2_AccOffsetDid */
  { 0U, 17U }, /* signal 0 of Did DID_FDE3_EcsProfilesDid */
  { 0U, 18U }, /* signal 0 of Did DID_FDE4_EcsStepsDid */
  { 0U, 19U }, /* signal 0 of Did DID_FDE5_EcsAccLowPassDid */
  { 0U, 20U }, /* signal 0 of Did DID_FDE7_AlgoOutputDelayDid */
  { 0U, 21U }, /* signal 0 of Did DID_FDE9_SensitivityLutDid */
  { 0U, 22U }, /* signal 0 of Did DID_FDEA_SensitivityOptDid */
  { 0U, 23U }, /* signal 0 of Did DID_FDFF_MeasurementFrameConfDataRamDid */
  { 0U, 8U }, /* signal 0 of Did DID_FE00_AllEventStatusesReadDid */
  { 0U, 7U }, /* signal 0 of Did DID_FEFF_MeasurementFramesConfDid */
};
#endif /* #if (DCM_DSP_USE_DIDSERVICES == STD_ON) */

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/** \brief Array that holds the configured security levels for read access of the didinfo
entries */
STATIC CONST(Dcm_SecLevelType, DCM_CONST) Dcm_ReadDidSecTypes[] =
{
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
};

/** \brief Array that holds the configured sessions for read access of the didinfo entries */
STATIC CONST(Dcm_SesCtrlType, DCM_CONST) Dcm_ReadDidSesTypes[] =
{
  0x03U,0x01U,0x7eU,
  0x03U,0x01U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x7eU,
  0x01U,0x03U,0x7eU,
  0x7eU,0x01U,0x03U,
  0x03U,0x01U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x01U,0x03U,0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
};

/** \brief Array that holds the configured security levels for write access of the didinfo
entries */
STATIC CONST(Dcm_SecLevelType, DCM_CONST) Dcm_WriteDidSecTypes[] =
{
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
};

/** \brief Array that holds the configured sessions for write access of the didinfo entries */
STATIC CONST(Dcm_SesCtrlType, DCM_CONST) Dcm_WriteDidSesTypes[] =
{
  0x03U,
  0x03U,
  0x03U,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
  0x7eU,
};


#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidReadAccessInfo,1 */
/** \brief Array that holds the configured read access information of the didinfo entries */
CONST(Dcm_DidReadAccessInfoType, DCM_CONST) Dcm_DidReadAccessInfo[] =
{
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[0]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[3]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[6]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[9]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[12]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[15]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[0]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[18]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[19]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[22]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[25]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[28]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[31]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[34]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[37]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[40]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[43]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[46]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[49]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[52]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[55]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[58]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      3, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[1]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[61]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[2]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[62]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[3]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[63]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[4]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[64]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[5]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[65]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[6]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[66]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[7]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[67]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[8]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[68]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[9]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[69]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[10]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[70]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[11]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[71]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[12]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[72]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[13]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[73]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[14]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[74]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[15]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[75]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[16]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[76]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[17]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[77]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[18]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[78]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[19]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[79]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[20]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[80]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[21]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[81]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_ReadDidSecTypes[22]), /* SecLevels */
      &(Dcm_ReadDidSesTypes[82]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
};

/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidWriteAccessInfo,1 */
/** \brief Array that holds the configured write access information of the didinfo entries */
CONST(Dcm_DidWriteAccessInfoType, DCM_CONST) Dcm_DidWriteAccessInfo[] =
{
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_WriteDidSesTypes[0]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_WriteDidSesTypes[1]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_WriteDidSesTypes[2]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[0]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[3]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[1]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[4]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[2]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[5]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[3]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[6]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[4]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[7]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[5]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[8]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[6]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[9]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[7]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[10]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[8]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[11]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[9]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[12]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[10]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[13]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[11]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[14]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[12]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[15]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[13]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[16]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[14]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[17]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[15]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[18]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[16]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[19]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[17]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[20]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[18]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[21]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[19]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[22]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[20]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[23]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[21]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[24]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[22]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[25]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
};

/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidIoctlAccessInfo,1 */
/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidReadScalingAccessInfo,1 */
/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidInfo,1 */
/** \brief Array that holds the configured didinfo entries that are enabled */
CONST(Dcm_DidInfoType, DCM_CONST) Dcm_DidInfo[] =
{
  {
    0, /* ReadAccessInfoIdx */
    0, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    1, /* ReadAccessInfoIdx */
    1, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    2, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    3, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    4, /* ReadAccessInfoIdx */
    2, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    5, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    6, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    7, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    8, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    9, /* ReadAccessInfoIdx */
    3, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    10, /* ReadAccessInfoIdx */
    4, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    11, /* ReadAccessInfoIdx */
    5, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    12, /* ReadAccessInfoIdx */
    6, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    13, /* ReadAccessInfoIdx */
    7, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    14, /* ReadAccessInfoIdx */
    8, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    15, /* ReadAccessInfoIdx */
    9, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    16, /* ReadAccessInfoIdx */
    10, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    17, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    18, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    19, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    20, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    21, /* ReadAccessInfoIdx */
    11, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    22, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    23, /* ReadAccessInfoIdx */
    12, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    24, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    25, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    26, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    27, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    28, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    29, /* ReadAccessInfoIdx */
    13, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    30, /* ReadAccessInfoIdx */
    14, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    31, /* ReadAccessInfoIdx */
    15, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    32, /* ReadAccessInfoIdx */
    16, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    33, /* ReadAccessInfoIdx */
    17, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    34, /* ReadAccessInfoIdx */
    18, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    35, /* ReadAccessInfoIdx */
    19, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    36, /* ReadAccessInfoIdx */
    20, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    37, /* ReadAccessInfoIdx */
    21, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    38, /* ReadAccessInfoIdx */
    22, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    39, /* ReadAccessInfoIdx */
    23, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    40, /* ReadAccessInfoIdx */
    24, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    41, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    42, /* ReadAccessInfoIdx */
    25, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
};

/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidRangeConfig,1 */

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#if ((DCM_DSP_USE_DIDSERVICES == STD_ON) && (DCM_DID_REF_COUNT > 0))
#define DCM_START_SEC_CONST_16
#include <Dcm_MemMap.h>

/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidRefers,1 */
/* Array for Dids which is referred from other Dids. */
CONST(uint16,DCM_CONST) Dcm_DidRefers[DCM_DID_REF_COUNT] =
{
};

#define DCM_STOP_SEC_CONST_16
#include <Dcm_MemMap.h>
#endif /* #if ((DCM_DSP_USE_DIDSERVICES == STD_ON) && (DCM_DID_REF_COUNT > 0)) */
/*==================[internal data]==============================================================*/

/*==================[external constants]=========================================================*/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidConfig,1 */
CONST(Dcm_DidConfigType, DCM_CONST) Dcm_DidConfig[] =
{
  {
    0x236U, /* Did */
    1U, /* NumSignals */
    0U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    0U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 41 */
  {
    0x23eU, /* Did */
    1U, /* NumSignals */
    1U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    1U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 42 */
  {
    0x407U, /* Did */
    1U, /* NumSignals */
    2U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    2U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 29 */
  {
    0x40fU, /* Did */
    1U, /* NumSignals */
    3U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    3U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 30 */
  {
    0x410U, /* Did */
    1U, /* NumSignals */
    4U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    4U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 31 */
  {
    0x448U, /* Did */
    1U, /* NumSignals */
    5U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    5U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 32 */
  {
    0x4024U, /* Did */
    1U, /* NumSignals */
    6U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    6U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 0 */
  {
    0xf15bU, /* Did */
    1U, /* NumSignals */
    7U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    7U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 39 */
  {
    0xf186U, /* Did */
    1U, /* NumSignals */
    8U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    8U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 9 */
  {
    0xf187U, /* Did */
    1U, /* NumSignals */
    9U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    9U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 24 */
  {
    0xf189U, /* Did */
    1U, /* NumSignals */
    10U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    10U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 25 */
  {
    0xf18cU, /* Did */
    1U, /* NumSignals */
    11U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    11U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 37 */
  {
    0xf191U, /* Did */
    1U, /* NumSignals */
    12U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    12U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 26 */
  {
    0xf197U, /* Did */
    1U, /* NumSignals */
    13U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    13U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 27 */
  {
    0xf19eU, /* Did */
    1U, /* NumSignals */
    14U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    14U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 34 */
  {
    0xf1a2U, /* Did */
    1U, /* NumSignals */
    15U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    15U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 40 */
  {
    0xf1a3U, /* Did */
    1U, /* NumSignals */
    16U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    16U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 36 */
  {
    0xf1abU, /* Did */
    1U, /* NumSignals */
    17U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    17U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 38 */
  {
    0xf1b4U, /* Did */
    1U, /* NumSignals */
    18U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    18U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 28 */
  {
    0xf1d5U, /* Did */
    1U, /* NumSignals */
    19U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    19U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 35 */
  {
    0xf1dfU, /* Did */
    1U, /* NumSignals */
    20U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    20U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 33 */
  {
    0xfd00U, /* Did */
    1U, /* NumSignals */
    21U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    21U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 1 */
  {
    0xfd01U, /* Did */
    1U, /* NumSignals */
    22U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    22U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 2 */
  {
    0xfd03U, /* Did */
    1U, /* NumSignals */
    23U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    23U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 3 */
  {
    0xfd08U, /* Did */
    1U, /* NumSignals */
    24U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    24U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 4 */
  {
    0xfd09U, /* Did */
    1U, /* NumSignals */
    25U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    25U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 5 */
  {
    0xfd0fU, /* Did */
    1U, /* NumSignals */
    26U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    26U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 12 */
  {
    0xfd10U, /* Did */
    1U, /* NumSignals */
    27U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    27U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 13 */
  {
    0xfd62U, /* Did */
    1U, /* NumSignals */
    28U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    28U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 6 */
  {
    0xfd8bU, /* Did */
    1U, /* NumSignals */
    29U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    29U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 10 */
  {
    0xfd8cU, /* Did */
    1U, /* NumSignals */
    30U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    30U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 11 */
  {
    0xfde0U, /* Did */
    1U, /* NumSignals */
    31U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    31U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 14 */
  {
    0xfde1U, /* Did */
    1U, /* NumSignals */
    32U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    32U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 15 */
  {
    0xfde2U, /* Did */
    1U, /* NumSignals */
    33U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    33U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 16 */
  {
    0xfde3U, /* Did */
    1U, /* NumSignals */
    34U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    34U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 17 */
  {
    0xfde4U, /* Did */
    1U, /* NumSignals */
    35U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    35U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 18 */
  {
    0xfde5U, /* Did */
    1U, /* NumSignals */
    36U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    36U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 19 */
  {
    0xfde7U, /* Did */
    1U, /* NumSignals */
    37U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    37U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 20 */
  {
    0xfde9U, /* Did */
    1U, /* NumSignals */
    38U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    38U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 21 */
  {
    0xfdeaU, /* Did */
    1U, /* NumSignals */
    39U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    39U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 22 */
  {
    0xfdffU, /* Did */
    1U, /* NumSignals */
    40U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    40U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 23 */
  {
    0xfe00U, /* Did */
    1U, /* NumSignals */
    41U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    41U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 8 */
  {
    0xfeffU, /* Did */
    1U, /* NumSignals */
    42U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    42U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 7 */
};

/* Constant holding the pointer to the configured mode rule to be used when re-enabling DTC */
CONST(Dcm_ModeRuleFunctionType, DCM_CONST) Dcm_DspModeRuleDTCFunction =
  NULL_PTR;

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/** \brief Configuration structure */
CONST(Dcm_ConfigType, DCM_CONST) DcmConfigSet = { 0U };


/* Array of configuration information of all Supported AddressAndLengthFormatIdentifiers */
CONST(uint8, DCM_CONST) Dcm_SupportedAddAndLenFormatIds[DCM_NUM_ADDR_LENGTH_FORMAT_IDENTIFIER] =
{
  0x24U,
};


#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/* Array of configuration information for diagnostic sessions */
STATIC CONST(Dcm_SesTabEntryConfigType, DCM_CONST) Dcm_SesTabEntryConfig0[6] =
{
  {
    1000U,/*P2StarMaxTime*/
    10U, /*P2MaxTime*/
    DCM_NO_BOOT,/*specifies whether this session allows
    to jump to Bootloader */
    1U,/* Session type */
    RTE_MODE_DcmDiagnosticSessionControl_DCM_DEFAULT_SESSION /* Session type generate by Rte */
  },
  {
    1000U,/*P2StarMaxTime*/
    10U, /*P2MaxTime*/
    DCM_OEM_BOOT,/*specifies whether this session allows
    to jump to Bootloader */
    2U,/* Session type */
    RTE_MODE_DcmDiagnosticSessionControl_DCM_PROGRAMMING_SESSION /* Session type generate by Rte */
  },
  {
    1000U,/*P2StarMaxTime*/
    10U, /*P2MaxTime*/
    DCM_NO_BOOT,/*specifies whether this session allows
    to jump to Bootloader */
    3U,/* Session type */
    RTE_MODE_DcmDiagnosticSessionControl_DCM_EXTENDED_SESSION /* Session type generate by Rte */
  },
  {
    1000U,/*P2StarMaxTime*/
    10U, /*P2MaxTime*/
    DCM_NO_BOOT,/*specifies whether this session allows
    to jump to Bootloader */
    126U,/* Session type */
    RTE_MODE_DcmDiagnosticSessionControl_DCM_SUPPLIER_SESSION /* Session type generate by Rte */
  },
  {
    1000U,/*P2StarMaxTime*/
    20U, /*P2MaxTime*/
    DCM_NO_BOOT,/*specifies whether this session allows
    to jump to Bootloader */
    96U,/* Session type */
    RTE_MODE_DcmDiagnosticSessionControl_DCM_ELE_MANUFACTURING_SESSION /* Session type generate by Rte */
  },
  {
    1000U,/*P2StarMaxTime*/
    20U, /*P2MaxTime*/
    DCM_NO_BOOT,/*specifies whether this session allows
    to jump to Bootloader */
    97U,/* Session type */
    RTE_MODE_DcmDiagnosticSessionControl_DCM_SYSTEM_MANUFACTURING_SESSION /* Session type generate by Rte */
  },
};

/* Holds configuration information for diagnostic sessions */
CONST(Dcm_SesTabConfigType, DCM_CONST) Dcm_SesTabConfig[DCM_NUM_PROTOCOL] =
{
  {
    Dcm_SesTabEntryConfig0, /* Pointer to session configurations */
    6U, /* Number of configured sessions */
    0U /* Index of default session */
  },
  {
    Dcm_SesTabEntryConfig0, /* Pointer to session configurations */
    6U, /* Number of configured sessions */
    0U /* Index of default session */
  },
};

/* Initialize global array holding the configuration for the service Id table */
CONST(Dcm_SidTabConfigType, DCM_CONST) Dcm_SidTabConfig[1] =
{
  {
    Dcm_SidTabEntryConfig0, /* Pointer to array of service table entries */
    12U /* Number of service entries within this table */
  },
};

CONST(Dcm_CallbackRequestServicesType, DCM_CONST) Dcm_CallbackRequests[DCM_CALLBACK_REQUEST_SIZE] =
{
  {
    &Rte_Call_Dcm_CallBackDCMRequestServices_CBReqServInd_1_StartProtocol, /* StartProtocol */
    &Rte_Call_Dcm_CallBackDCMRequestServices_CBReqServInd_1_StopProtocol, /* StopProtocol */
  },
};


/** \brief Provides the range of memory address allowed for reading */
STATIC CONST(Dcm_MemoryRangeInfoType,DCM_CONST) Dcm_ReadMemoryRangeInfoTable0[9] =
{
  {
    0xee000000U,
    0xee900008U,
    NULL_PTR,
    NULL_PTR,
    0U,
  },
  {
    0x7f000U,
    0x7ffffU,
    NULL_PTR,
    &(Dcm_ReadMemSecLevels[0]),
    1U,
  },
  {
    0x7e000U,
    0x7efffU,
    NULL_PTR,
    &(Dcm_ReadMemSecLevels[1]),
    1U,
  },
  {
    0x20000U,
    0x7dfffU,
    NULL_PTR,
    &(Dcm_ReadMemSecLevels[2]),
    1U,
  },
  {
    0x14000000U,
    0x14000dffU,
    NULL_PTR,
    &(Dcm_ReadMemSecLevels[3]),
    1U,
  },
  {
    0x1fff8000U,
    0x1fffffffU,
    NULL_PTR,
    NULL_PTR,
    0U,
  },
  {
    0x20000000U,
    0x20003dffU,
    NULL_PTR,
    NULL_PTR,
    0U,
  },
  {
    0x20006f00U,
    0x20006fffU,
    NULL_PTR,
    NULL_PTR,
    0U,
  },
  {
    0x10000000U,
    0x1000ffffU,
    NULL_PTR,
    NULL_PTR,
    0U,
  },

};


/** \brief Provides the range of memory address allowed for writing */
STATIC CONST(Dcm_MemoryRangeInfoType,DCM_CONST) Dcm_WriteMemoryRangeInfoTable0[4] =
{
  {
    0xee000000U,
    0xee900008U,
    NULL_PTR,
    /* Configurations for Write Memory access*/
    &(Dcm_WriteMemSecLevels[0]),
    1U,
  },
  {
    0x14000000U,
    0x14000dffU,
    NULL_PTR,
    /* Configurations for Write Memory access*/
    NULL_PTR,
    0,
  },
  {
    0x1fff8000U,
    0x1fffffffU,
    NULL_PTR,
    /* Configurations for Write Memory access*/
    &(Dcm_WriteMemSecLevels[1]),
    1U,
  },
  {
    0x20006f00U,
    0x20006fffU,
    NULL_PTR,
    /* Configurations for Write Memory access*/
    NULL_PTR,
    0,
  },

};

/** \brief Provides the configuration of memory access requested through diagnostic services: WriteMemoryByAddress and readMemoryByAddress*/
CONST(Dcm_MemoryIdInfoType, DCM_CONST) Dcm_MemoryIdInfoAndIdValueTable[DCM_NUM_MEMORY_IDINFO] =
{
  {
    /* Pointer to Write memory range info configurations */
    Dcm_WriteMemoryRangeInfoTable0,
    /* Pointer to Read memory range info configurations */
    Dcm_ReadMemoryRangeInfoTable0,
    /* Number of ranges of memory addresses available for writing */
    4U,
    /* Number of range of memory addresses available for reading */
    9U,
    /* MemoryID Value */
    0U
  },
};

#if ((DCM_DID_DATA_TABLE_SIZE > 0U) && (DCM_DID_SIGNALS_COUNT > 0))
/* !LINKSTO Dcm.Dsn.DidSignals.ConfigurationData.DidDataTable,1 */
CONST(Dcm_VariableFunctionPointerRecordType, DCM_CONST) Dcm_DidDataTable[DCM_DID_DATA_TABLE_SIZE] =
{
  /* Deviation MISRAC2012-1 <START> */ /* Deviation MISRA-3  <START> */
  
  /* Available function pointers for DID_4024_SWSystemTimeData */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_4024_SWSystemTimeData_ReadData},

  /* Available function pointers for DID_FD00_HWVersionData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD00_HWVersionData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD00_HWVersionData_WriteData},

  /* Available function pointers for DID_FD01_SWVersionData */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD01_SWVersionData_ReadData},

  /* Available function pointers for DID_FD03_AEETraceabilityNumberData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD03_AEETraceabilityNumberData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD03_AEETraceabilityNumberData_WriteData},

  /* Available function pointers for DID_FD08_ResetCauseData */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD08_ResetCauseData_ReadData},

  /* Available function pointers for DID_FD09_LastWarmResetParamData */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD09_LastWarmResetParamData_ReadData},

  /* Available function pointers for DID_FD62_EccOccurenceNbData */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD62_EccOccurenceNbData_ReadData},

  /* Available function pointers for DID_FEFF_MeasurementFramesConfData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FEFF_MeasurementFramesConfData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FEFF_MeasurementFramesConfData_WriteData},

  /* Available function pointers for DID_FE00_AllEventStatusesRead */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FE00_AllEventStatusesRead_ReadData},

  /* Available function pointers for DID_F186_ActiveDiagnosticSessionData */
  /* ReadData sync function */
  {(Dcm_GeneralDidOperationFuncType)&Dcm_Internalf186Readout},

  /* Available function pointers for DID_FD8B_ECUManufacturingDateData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD8B_ECUManufacturingDateData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD8B_ECUManufacturingDateData_WriteData},

  /* Available function pointers for DID_FD8C_AssemblySerialNumber */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD8C_AssemblySerialNumber_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD8C_AssemblySerialNumber_WriteData},

  /* Available function pointers for DID_FD0F_BatteryMeasureData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD0F_BatteryMeasureData_ReadData},

  /* Available function pointers for DID_FD10_ECUTemperatureData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FD10_ECUTemperatureData_ReadData},

  /* Available function pointers for DID_FDE0_EcsVariantData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE0_EcsVariantData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE0_EcsVariantData_WriteData},

  /* Available function pointers for DID_FDE1_EcsParametersData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE1_EcsParametersData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE1_EcsParametersData_WriteData},

  /* Available function pointers for DID_FDE2_AccOffsetData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE2_AccOffsetData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE2_AccOffsetData_WriteData},

  /* Available function pointers for DID_FDE3_EcsProfilesData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE3_EcsProfilesData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE3_EcsProfilesData_WriteData},

  /* Available function pointers for DID_FDE4_EcsStepsData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE4_EcsStepsData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE4_EcsStepsData_WriteData},

  /* Available function pointers for DID_FDE5_EcsAccLowPassData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE5_EcsAccLowPassData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE5_EcsAccLowPassData_WriteData},

  /* Available function pointers for DID_FDE7_AlgoOutputDelayData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE7_AlgoOutputDelayData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE7_AlgoOutputDelayData_WriteData},

  /* Available function pointers for DID_FDE9_SensitivityLutData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE9_SensitivityLutData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDE9_SensitivityLutData_WriteData},

  /* Available function pointers for DID_FDEA_SensitivityOptData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDEA_SensitivityOptData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDEA_SensitivityOptData_WriteData},

  /* Available function pointers for DID_FDFF_MeasurementFrameConfDataRam */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDFF_MeasurementFrameConfDataRam_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_FDFF_MeasurementFrameConfDataRam_WriteData},

  /* Available function pointers for DID_F187_VWSparePartNumberData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F187_VWSparePartNumberData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F187_VWSparePartNumberData_WriteData},

  /* Available function pointers for DID_F189_VWApplicationSoftwareVersionNumberData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F189_VWApplicationSoftwareVersionNumberData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F189_VWApplicationSoftwareVersionNumberData_WriteData},

  /* Available function pointers for DID_F191_VWECUHardwareNumberData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F191_VWECUHardwareNumberData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F191_VWECUHardwareNumberData_WriteData},

  /* Available function pointers for DID_F197_VWSystemNameOrEngineTypeData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F197_VWSystemNameOrEngineTypeData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F197_VWSystemNameOrEngineTypeData_WriteData},

  /* Available function pointers for DID_F1B4_TechnicalSpecificationsVersionData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F1B4_TechnicalSpecificationsVersionData_ReadData},

  /* Available function pointers for DID_0407_VWLogicalSoftwareBlockCounterOfProgrammingAttemptsData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_0407_VWLogicalSoftwareBlockCounterOfProgrammingAttemptsData_ReadData},

  /* Available function pointers for DID_040F_VWLogicalSoftwareBlockLockValueData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_040F_VWLogicalSoftwareBlockLockValueData_ReadData},

  /* Available function pointers for DID_0410_BootloaderTPBlocksizeData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_0410_BootloaderTPBlocksizeData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_0410_BootloaderTPBlocksizeData_WriteData},

  /* Available function pointers for DID_0448_ProgrammingPreconditionsData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_0448_ProgrammingPreconditionsData_ReadData},

  /* Available function pointers for DID_F1DF_ECUProgrammingInformationData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F1DF_ECUProgrammingInformationData_ReadData},

  /* Available function pointers for DID_F19E_ASAMODXFileIdentifierData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F19E_ASAMODXFileIdentifierData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F19E_ASAMODXFileIdentifierData_WriteData},

  /* Available function pointers for DID_F1A2_ASAMODXFileVersionData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F1A2_ASAMODXFileVersionData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F1A2_ASAMODXFileVersionData_WriteData},

  /* Available function pointers for DID_F1D5_FDSProjectData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F1D5_FDSProjectData_ReadData},

  /* Available function pointers for DID_F1A3_VWECUHardwareVersionNumberData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F1A3_VWECUHardwareVersionNumberData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F1A3_VWECUHardwareVersionNumberData_WriteData},

  /* Available function pointers for DID_F18C_ECUSerialNumberData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F18C_ECUSerialNumberData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F18C_ECUSerialNumberData_WriteData},

  /* Available function pointers for DID_F1AB_VWLogicalSoftwareBlockVersionData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F1AB_VWLogicalSoftwareBlockVersionData_ReadData},

  /* Available function pointers for DID_F15B_FingerprintAndProgrammingDateOfLogicalSoftwareBlocksData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_F15B_FingerprintAndProgrammingDateOfLogicalSoftwareBlocksData_ReadData},

  /* Available function pointers for DID_0236_ProgrammingDataElockEcuData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_0236_ProgrammingDataElockEcuData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_0236_ProgrammingDataElockEcuData_WriteData},

  /* Available function pointers for DID_023E_WSCForProgrammingElockEcuData */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_023E_WSCForProgrammingElockEcuData_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DID_023E_WSCForProgrammingElockEcuData_WriteData},

  /* Deviation MISRA-3  <STOP> */ /* Deviation MISRAC2012-1 <STOP> */
};
#endif

/* !LINKSTO Dcm.Dsn.DidSignals.ConfigurationData.DidDataIndexingArray,1 */
CONST(Dcm_DidDataIndexingArrayEntryType, DCM_CONST) Dcm_DidDataIndexingArray[DCM_NUM_DID_DATA] =
{
    {
    /* Index in Dcm_DidDataTable */
    0U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    1U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    3U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    4U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    6U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    7U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    8U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    9U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    11U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    12U,
    /* Data descriptor */
    0x1bdU,
  },
  {
    /* Index in Dcm_DidDataTable */
    13U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    15U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    17U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    18U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    19U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    21U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    23U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    25U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    27U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    29U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    31U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    33U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    35U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    37U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    39U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    41U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    43U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    45U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    47U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    48U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    49U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    50U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    52U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    53U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    54U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    56U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    58U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    59U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    61U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    63U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    64U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    65U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    67U,
    /* Data descriptor */
    0x9b9U,
  },
};


/* !LINKSTO Dcm.Dsn.DidSignals.ConfigurationData.DidScalingDataSignalsIndexingArray,1 */
#if (DCM_DSP_USE_SERVICE_0X24 == STD_ON)
#if (DCM_NUM_READSCALING_DID_DATA > 0)
CONST(Dcm_DidScalingDataSignalsIndexingArrayEntryType, DCM_CONST) Dcm_DidScalingDataSignalsIndexingArray[DCM_NUM_READSCALING_DID_DATA] =
{
};
#endif /* #if (DCM_NUM_READSCALING_DID_DATA > 0) */
#endif /* #if (DCM_DSP_USE_SERVICE_0X24 == STD_ON) */
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_16
#include <Dcm_MemMap.h>
/* !LINKSTO Dcm.Dsn.DidSignals.ConfigurationData.DidDataSizeArray,1 */
CONST(uint16, DCM_CONST) Dcm_DidDataSizeArray[DCM_NUM_DID_DATA] =
{
  40,
  80,
  96,
  96,
  32,
  64,
  128,
  40,
  552,
  8,
  24,
  160,
  16,
  16,
  32,
  392,
  48,
  384,
  448,
  24,
  16,
  160,
  8,
  600,
  88,
  32,
  88,
  104,
  208,
  48,
  48,
  8,
  40,
  8,
  192,
  48,
  56,
  24,
  160,
  96,
  240,
  472,
  48,
};

#define DCM_STOP_SEC_CONST_16
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/** \brief RTE function pointer table for Supplier Notification */
CONST(Dcm_RteRequestNotificationType, DCM_CONST)
  Dcm_RteSupplierNotificationTable[DCM_RTE_TABLE_REQUEST_SUPPLIER_SIZE] =
{
{      &Rte_Call_ServiceRequestSupplierNotification_DcmDslServiceRequestSupplierNotification_Indication,
    &Rte_Call_ServiceRequestSupplierNotification_DcmDslServiceRequestSupplierNotification_Confirmation
  },
};


#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>


#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>


#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>


#define DCM_START_SEC_CALIB_8
#include <Dcm_MemMap.h>

#if (DCM_DSP_SUBSERVICE_USED_BUF_SIZE > 0)
/* Initialize global array holding the configuration for the subservice usage */

CONST(uint8, DCM_CONST) Dcm_DsdSubServiceUsed[DCM_DSP_SRV_TABLES_USED_BUF_SIZE][DCM_DSP_NUMBER_OF_SERVICE_USED][DCM_DSP_SUBSERVICE_USED_BUF_SIZE] =
{
  {
    /* SID10_DiagnosticSessionControl subservice used */
    {
      63U,
    },
    /* SID11_ECUReset subservice used */
    {
      3U,
    },
    /* SID14_ClearDiagnosticInformation subservice used */
    {
      0U,
    },
    /* SID22_ReadDataByIdentifier subservice used */
    {
      0U,
    },
    /* SID23_ReadMemoryByAddress subservice used */
    {
      0U,
    },
    /* SID27_SecurityAccess subservice used */
    {
      3U,
    },
    /* SID28_CommunicationControl subservice used */
    {
      3U,
    },
    /* SID2E_WriteDataByIdentifier subservice used */
    {
      0U,
    },
    /* SID31_RoutineControl subservice used */
    {
      0U,
    },
    /* SID3D_WriteMemoryByAddress subservice used */
    {
      0U,
    },
    /* SID3E_TesterPresent subservice used */
    {
      2U,
    },
    /* SID85_ControlDTCSetting subservice used */
    {
      3U,
    },
  },
};
#endif

/* Initialize global array holding the configuration for the service usage */

CONST(uint8, DCM_CONST) Dcm_DsdServiceUsed[DCM_DSP_SRV_TABLES_USED_BUF_SIZE][DCM_DSP_SERVICE_USED_BUF_SIZE] =
{
  {
    255U,
    15U,
  },
};

#if (DCM_DSP_USE_DIDSERVICES == STD_ON)
#if (DCM_DSP_DIDSERVICES_NUM_DIDS > 0)
CONST(Dcm_DspDidUsedType,DCM_CONST) Dcm_DspDidUsed[DCM_DSP_DID_USED_BUF_SIZE] =
{
  255U,
  255U,
  255U,
  255U,
  255U,
  7U,
};
#endif /* #if (DCM_DSP_DIDSERVICES_NUM_DIDS > 0) */
#endif /* #if (DCM_DSP_USE_DIDSERVICES == STD_ON) */




#define DCM_STOP_SEC_CALIB_8
#include <Dcm_MemMap.h>

/*==================[external data]==============================================================*/

/*==================[external function definitions]==============================================*/
#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>

/*------------ Definition of user function for the service 0xF186 --------------*/
/* !LINKSTO Dcm.EB.ActiveDiagnosticSessionDataIdentifier,1 */
FUNC(Std_ReturnType, DCM_APPL_CODE) Dcm_Internalf186Readout(
P2VAR(uint8, AUTOMATIC, DCM_VAR) Data)
{
Std_ReturnType retVal = E_NOT_OK;

retVal = Dcm_GetSesCtrlTypeExt(Data);

return retVal;
}

#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>
/*==================[internal function definitions]==============================================*/
#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

/*==================[end of file]================================================================*/
