
/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \version 1.17.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* \addtogroup Mode Management Stack
  * @{ */

/* !LINKSTO BswM.Impl.SourceFile.BswM_Cfg_c,1 */

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 11.5 (advisory)
 * A conversion should not be performed from pointer to void into pointer to object.
 *
 * Reason:
 * It is ensured that the correct type is used when casting the void pointer.
 */

/*==================[inclusions]============================================*/
/* Internal headers */
#include <BswM.h>
#include <BswM_Int_Cfg.h>
#include <BswM_Int.h>
#include <TSMem.h>

#include <BswM_Lcfg.h>

#include <BswM_PBcfg.h>

#include <BswM_DefProg.h>

#include <BswM_Trace.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/
#define BSWM_START_SEC_CODE
#include <BswM_MemMap.h>

STATIC FUNC(void, BSWM_CODE) BswM_Core_Init(void);

STATIC FUNC(void, BSWM_CODE) BswM_Partition_Init
(
P2VAR(BswM_PartitionContextType, AUTOMATIC, BSWM_VAR) inst
);

STATIC FUNC(void, BSWM_CODE) BswM_RT_Init
(
P2VAR(BswM_PartitionContextType, AUTOMATIC, BSWM_VAR) inst
);

#define BSWM_STOP_SEC_CODE
#include <BswM_MemMap.h>

/*==================[external function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

#define BSWM_START_SEC_CONST_32
#include <BswM_MemMap.h>

CONST(uint32, BSWM_CONST) BswM_LcfgSignature = 3958107115U;

#define BSWM_STOP_SEC_CONST_32
#include <BswM_MemMap.h>

/*==================[internal data]=========================================*/

/*==================[external data]=========================================*/

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <BswM_MemMap.h>

P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_APPL_CONST) BswM_PostBuildConfig;

#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <BswM_MemMap.h>

/*==================[external function definitions]=========================*/

/* !LINKSTO BswM.Impl.MemoryMapping.SharedCode,1 */
#define BSWM_START_SEC_CODE
#include <BswM_MemMap.h>

FUNC(Std_ReturnType, BSWM_CODE) BswM_IsValidConfig
(
P2CONST(void, AUTOMATIC, BSWM_APPL_CONST) voidPtr
)
{
  /* Assume an invalid configuration */
  Std_ReturnType result = E_NOT_OK;
  /*
   * In the current implementation all BswM_ConfigType instances from
   * the BswM_RootConfig member of the BswM_ConfigLayoutType structure
   * share the same signatures therefore only the first one is checked.
   */
  P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_APPL_CONST) ConfigPtr = voidPtr;

  if (ConfigPtr != NULL_PTR)
  {
    /* Check if the configuration fits to the platform */
    if (TS_PlatformSigIsValid(ConfigPtr->PlatformSignature) == TRUE )
    {
      /* Validate the post build configuration against the compile time
       * configuration */
      if (BSWM_CFG_SIGNATURE == ConfigPtr->CfgSignature)
      {
        /* Validate the post build configuration against the link time
         * configuration */
        if (BswM_LcfgSignature == ConfigPtr->LcfgSignature)
        {
          /* Validate the post build configuration against the compile time
           * published information configuration */
          if (BSWM_PUBLIC_INFO_SIGNATURE == ConfigPtr->PublicInfoSignature)
          {
            /* Indicate that the configuration is valid */
            result = E_OK;
          }
        }
      }
    }
  }

  return result;
}

/* !LINKSTO BswM0118,1 */
FUNC(void, BSWM_CODE) BswM_Init
(
P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_APPL_CONST) ConfigPtr
)
{
#if ((BSWM_GET_INSTANCE_BSW_DISTRIBUTION == TRUE) || ((BSWM_IS_VARIANT_PRECOMPILE == FALSE) && (BSWM_DEV_ERROR_DETECT == STD_ON)))
  P2VAR(BswM_PartitionContextType, AUTOMATIC, BSWM_VAR) inst = BswM_GetInstance();
#endif
  DBG_BSWM_INIT_ENTRY(ConfigPtr);

  /*
   * The Os application from which EcuM calls BswM_Init must be mapped
   * to a BswM configuration.
   */
#if (BSWM_GET_INSTANCE_BSW_DISTRIBUTION == TRUE)
  if ( inst != NULL_PTR)
#endif
  {
    /* !LINKSTO BswM.IMPLEMENTATION_CONFIG_VARIANT,1 */
    TS_PARAM_UNUSED(ConfigPtr);
    BswM_PostBuildConfig = &BswM_ConfigLayout.BswM_RootConfig[0];
    BswM_Core_Init();
  }
#if ((BSWM_DEV_ERROR_DETECT == STD_ON) && (BSWM_GET_INSTANCE_BSW_DISTRIBUTION == TRUE))
  else
  {
    /* !LINKSTO BswM.Impl.RunTime.InvalidPartitionContext,3 */
    BSWM_DET_REPORT_ERROR(BSWM_GET_APPLICATION_ID(), BSWM_SID_INIT, BSWM_E_WRONG_CONTEXT);
  }
#endif
  DBG_BSWM_INIT_EXIT(ConfigPtr);
}

/* !LINKSTO BswM.Impl.Api.BswM_Core_Init,1 */
/* !LINKSTO BswM.Impl.Algorithm.Initialization,1 */
STATIC FUNC(void, BSWM_CODE) BswM_Core_Init(void)
{
  DBG_BSWM_CORE_INIT_ENTRY();
  BswM_Partition_Init(&BswM_Context);
  DBG_BSWM_CORE_INIT_EXIT();
}

/* !LINKSTO BswM.Impl.Api.BswM_GetInstance,1 */
FUNC_P2VAR(BswM_PartitionContextType, BSWM_VAR, BSWM_CODE) BswM_GetInstance(void)
{
  return &BswM_Context;
}

/*==================[internal function definitions]=========================*/

/* !LINKSTO BswM.Impl.Algorithm.Initialization,1 */
STATIC FUNC(void, BSWM_CODE) BswM_Partition_Init
(
P2VAR(BswM_PartitionContextType, AUTOMATIC, BSWM_VAR) inst
)
{
  DBG_BSWM_PARTITION_INIT_ENTRY(inst);

  inst->RunTimeContext.IsInitialized = FALSE;

  BswM_LT_Init();

  BswM_RT_Init(inst);

  inst->RunTimeContext.IsInitialized = TRUE;

  DBG_BSWM_PARTITION_INIT_EXIT(inst);
}

STATIC FUNC(void, BSWM_CODE) BswM_RT_Init
(
P2VAR(BswM_PartitionContextType, AUTOMATIC, BSWM_VAR) inst
)
{
  BswMIndexType i;
  DBG_BSWM_RT_INIT_ENTRY(inst);

  for (i = 0U; i < BSWM_GET_NUM_RULES(inst->ID); i++)
  {
    /* On startup, the rule initial state corresponds to the last expression
     * result. */
    inst->RunTimeContext.RuleResultTable[BSWM_GET_RULE_TABLE(inst->ID)[i].ID] = BSWM_GET_RULE_TABLE(inst->ID)[i].RuleInitState;
  }

  for(i = 0U; i < inst->LinkTimeContext->numBswMExpressions; i++)
  {
    BSWM_SET_LOG_EXPR_INIT_STATUS(i, BSWM_GET_EXPR_STATE(i));
  }

  inst->RunTimeContext.PduGroupSwitchTriggered = FALSE;
  inst->RunTimeContext.PduGroupSwitchReInitTriggered = FALSE;
  for (i = 0U; i < BSWM_IPDU_GROUP_VECTOR_SIZE; i++)
  {
    inst->RunTimeContext.IPduGroupReInitVector[i] = 0U;
    inst->RunTimeContext.IPduGroupVector[i] = 0U;
  }

  DBG_BSWM_RT_INIT_EXIT(inst);
}

FUNC(void, BSWM_CODE) BswM_ExecuteModeArbitration
(
P2VAR(BswM_PartitionContextType, AUTOMATIC, BSWM_VAR) inst,
P2VAR(void, AUTOMATIC, BSWM_VAR) port,
uint32 mode,
uint8 type
)
{
  BswMBasicPortType* base = NULL_PTR;
  boolean hasActivatedActionLists = FALSE;
  boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
  TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
  inst->SchMEnter();
  switch(type)
  {
    case BSWM_ARBITRATION_UINT8_CHANNEL_UINT8_MODE_PORT:
    {
      /* Deviation MISRAC2012-1 */
      BswMU8ChannelU8ModePortType* ref = (BswMU8ChannelU8ModePortType*) port;
      base = &(ref->base);
      ref->mode = (uint8) mode;
      break;
    }
    case BSWM_ARBITRATION_GENERIC_REQUEST_HANDLER_PORT:
    {
      /* Deviation MISRAC2012-1 */
      BswMGenericRequestPortType* ref = (BswMGenericRequestPortType*) port;
      base = &(ref->base);
      ref->mode = (uint16) mode;
      break;
    }
    case BSWM_ARBITRATION_UINT16_CHANNEL_UINT8_MODE_PORT:
    {
      /* Deviation MISRAC2012-1 */
      BswMU16ChannelU8ModePortType* ref = (BswMU16ChannelU8ModePortType*) port;
      base = &(ref->base);
      ref->mode = (uint8) mode;
      break;
    }
    case BSWM_ARBITRATION_RTE_PORT_UINT8:
    {
      /* Deviation MISRAC2012-1 */
      BswMUInt8RteModeRequestPortType* ref = (BswMUInt8RteModeRequestPortType*) port;
      base = &(ref->base);
      ref->mode = (uint8) mode;
      break;
    }
    default:
    BSWM_UNREACHABLE_CODE_ASSERT(inst->ID, BSWM_INTERNAL_API_ID);
    break;
  }
  if (BswM_PortUpdated(base, activatedActionLists, inst) == TRUE)
  {
    hasActivatedActionLists = TRUE;
  }
  inst->SchMExit();
  if (hasActivatedActionLists == TRUE)
  {
    BswM_ExecuteModeControl(activatedActionLists, inst);
  }
}

#define BSWM_STOP_SEC_CODE
#include <BswM_MemMap.h>
