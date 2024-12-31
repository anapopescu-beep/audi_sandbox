


/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 1.3 (required)
 *    There shall be no occurrence of undefined or critical unspecified behaviour.
 *
 *    Reason:
 *    The postbuild macro TS_MAKEREF2CFG requires the usage of the
 *    C standard macro 'offsetof'.
 *    According to the C90 standard, the usage of 'offsetof' produces
 *    an undefined behaviour when the member designator parameter
 *    is a bit-field or when it is an invalid right operator of the
 *    '.' operator for the type parameter.
 *    This is not the case here as the parameter of TS_MAKEREF2CFG
 *    is always a member of TS_PB_CFG_LAYOUT_TYPE and bitfields are
 *    never used when defining the postbuild structure members.
 *
 * MISRAC2012-2) Deviated Rule: 11.4 (advisory)
 *    A cast should not be performed between a pointer type and an integral
 *    type.
 *
 *    Reason:
 *    Relocatable postbuild macro requires the cast between pointer and
 *    integral type.
 *
 * MISRAC2012-3) Deviated Rule: 11.9 (required)
 *    The macro NULL shall be the only permitted form of integer null pointer constant.
 *
 *    Reason:
 *    Macros are used in order to check the alignment for different data types.
 *
 */

/*==================[inclusions]=============================================*/

#include <BswM_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME BswM_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE BswM_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <BswM_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
BswM_ConstConfigLayoutType BswM_ConfigLayout = {
    { /* BswM_RootConfig */
        { /* BswM_RootConfig[0] */
            TS_MAKEREF2CFG( RuleTable[0] ), /* RuleTable */
            TS_MAKEREF2CFG( RuleDependencyTable[0] ), /* RuleDependencyTable */
            TS_MAKEREF2CFG( RuleDependencyListRangeTable[0] ), /* RuleDependencyListRangeTable */
            TS_MAKEREF2CFG( ActionListTable[0] ), /* ActionListTable */
            TS_MAKEREF2CFG( ActionListItemTable[0] ), /* ActionListItemTable */
            TS_MAKEREF2CFG( PduGroupSwitchActionTable[0] ), /* PduGroupSwitchActionTable */
            TS_MAKEREF2CFG( UInt8InitialValuesTable[0] ), /* UInt8InitialValuesTable */
            TS_MAKENULLREF2CFG, /* UInt16InitialValuesTable */
            TS_MAKENULLREF2CFG, /* UInt32InitialValuesTable */
            UINT32_C( 2147485970 ), /* PlatformSignature */
            UINT32_C( 3958107115 ), /* LcfgSignature */
            UINT32_C( 408221305 ), /* CfgSignature */
            UINT32_C( 3642131911 ), /* PublicInfoSignature */
            UINT16_C( 23 ), /* NumRules */
            UINT16_C( 17 ), /* NumRulesDeferred */
            UINT16_C( 21 ) /* NumActionLists */
        }
    },
    { /* RuleTable */
        { /* RuleTable[0] -- BswM_EB_Rule_BswMRule_EnableTxPdu */
            UINT16_C( 20 ), /* ID */
            UINT16_C( 20 ), /* LogicalExprIndex */
            UINT16_C( 19 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[1] -- BswM_EB_Rule_BswMRule_EnterRunStateFromWakeupState */
            UINT16_C( 19 ), /* ID */
            UINT16_C( 12 ), /* LogicalExprIndex */
            UINT16_C( 12 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[2] -- BswM_EB_Rule_BswMRule_EnterRunStateFromLowPwrStateSecondCondition */
            UINT16_C( 18 ), /* ID */
            UINT16_C( 17 ), /* LogicalExprIndex */
            UINT16_C( 18 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[3] -- BswM_EB_Rule_BswMRule_EnterRunStateFromLowPwrStateFirstCondition */
            UINT16_C( 17 ), /* ID */
            UINT16_C( 16 ), /* LogicalExprIndex */
            UINT16_C( 17 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[4] -- BswM_EB_Rule_BswMRule_EnterShutdownStateFromLowPwrState */
            UINT16_C( 16 ), /* ID */
            UINT16_C( 19 ), /* LogicalExprIndex */
            UINT16_C( 6 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[5] -- BswM_EB_Rule_BswMRule_EnterLowPwrStateFromPostRunState */
            UINT16_C( 15 ), /* ID */
            UINT16_C( 18 ), /* LogicalExprIndex */
            UINT16_C( 16 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[6] -- BswM_EB_Rule_BswMRule_EnterRunStateFromPostRunStateSecondCondition */
            UINT16_C( 14 ), /* ID */
            UINT16_C( 14 ), /* LogicalExprIndex */
            UINT16_C( 15 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[7] -- BswM_EB_Rule_BswMRule_EnterRunStateFromPostRunStateFirstCondition */
            UINT16_C( 13 ), /* ID */
            UINT16_C( 13 ), /* LogicalExprIndex */
            UINT16_C( 14 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[8] -- BswM_EB_Rule_BswMRule_EnterPostRunStateFromRunState */
            UINT16_C( 12 ), /* ID */
            UINT16_C( 15 ), /* LogicalExprIndex */
            UINT16_C( 13 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[9] -- BswM_EB_Rule_BswMRule_StartComEffective */
            UINT16_C( 10 ), /* ID */
            UINT16_C( 10 ), /* LogicalExprIndex */
            UINT16_C( 10 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[10] -- BswM_EB_Rule_BswMRule_StartShutdownSequence */
            UINT16_C( 6 ), /* ID */
            UINT16_C( 6 ), /* LogicalExprIndex */
            UINT16_C( 6 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[11] -- BswM_EB_Rule_BswMRule_WakeUpExpired */
            UINT16_C( 5 ), /* ID */
            UINT16_C( 5 ), /* LogicalExprIndex */
            UINT16_C( 5 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[12] -- BswM_EB_Rule_BswMRule_WakeUpValidated */
            UINT16_C( 4 ), /* ID */
            UINT16_C( 4 ), /* LogicalExprIndex */
            UINT16_C( 4 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[13] -- BswM_EB_Rule_BswMRule_BswM_GoOffOneB */
            UINT16_C( 3 ), /* ID */
            UINT16_C( 3 ), /* LogicalExprIndex */
            UINT16_C( 3 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[14] -- BswM_EB_Rule_BswMRule_BswM_GoOffOneA */
            UINT16_C( 2 ), /* ID */
            UINT16_C( 2 ), /* LogicalExprIndex */
            UINT16_C( 2 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[15] -- BswM_EB_Rule_BswMRule_BswM_StartupTwoB */
            UINT16_C( 1 ), /* ID */
            UINT16_C( 1 ), /* LogicalExprIndex */
            UINT16_C( 1 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[16] -- BswM_EB_Rule_BswMRule_BswM_StartupTwoA */
            UINT16_C( 0 ), /* ID */
            UINT16_C( 0 ), /* LogicalExprIndex */
            UINT16_C( 0 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[17] -- BswM_EB_Rule_BswMRule_DisableTxPdu_DcmRequest */
            UINT16_C( 22 ), /* ID */
            UINT16_C( 22 ), /* LogicalExprIndex */
            UINT16_C( 20 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[18] -- BswM_EB_Rule_BswMRule_EnableTxPdu_DcmRequest */
            UINT16_C( 21 ), /* ID */
            UINT16_C( 21 ), /* LogicalExprIndex */
            UINT16_C( 19 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[19] -- BswM_EB_Rule_BswMRule_PrepareJumpToFBL */
            UINT16_C( 11 ), /* ID */
            UINT16_C( 11 ), /* LogicalExprIndex */
            UINT16_C( 11 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[20] -- BswM_EB_Rule_BswMRule_PrepareSWReset */
            UINT16_C( 9 ), /* ID */
            UINT16_C( 9 ), /* LogicalExprIndex */
            UINT16_C( 9 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[21] -- BswM_EB_Rule_BswMRule_ExecuteReset */
            UINT16_C( 8 ), /* ID */
            UINT16_C( 8 ), /* LogicalExprIndex */
            UINT16_C( 8 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        },
        { /* RuleTable[22] -- BswM_EB_Rule_BswMRule_PrepareHWReset */
            UINT16_C( 7 ), /* ID */
            UINT16_C( 7 ), /* LogicalExprIndex */
            UINT16_C( 7 ), /* TrueActionListIndex */
            UINT16_C( 65535 ), /* FalseActionListIndex */
            UINT8_C( 0 ) /* RuleInitState */
        }
    },
    { /* RuleDependencyTable */
        UINT16_C( 16 ), /* RuleDependencyTable[0] -- BswM_EB_Rule_BswMRule_BswM_StartupTwoA */
        UINT16_C( 15 ), /* RuleDependencyTable[1] -- BswM_EB_Rule_BswMRule_BswM_StartupTwoB */
        UINT16_C( 14 ), /* RuleDependencyTable[2] -- BswM_EB_Rule_BswMRule_BswM_GoOffOneA */
        UINT16_C( 13 ), /* RuleDependencyTable[3] -- BswM_EB_Rule_BswMRule_BswM_GoOffOneB */
        UINT16_C( 12 ), /* RuleDependencyTable[4] -- BswM_EB_Rule_BswMRule_WakeUpValidated */
        UINT16_C( 11 ), /* RuleDependencyTable[5] -- BswM_EB_Rule_BswMRule_WakeUpExpired */
        UINT16_C( 9 ), /* RuleDependencyTable[6] -- BswM_EB_Rule_BswMRule_StartComEffective */
        UINT16_C( 9 ), /* RuleDependencyTable[7] -- BswM_EB_Rule_BswMRule_StartComEffective */
        UINT16_C( 12 ), /* RuleDependencyTable[8] -- BswM_EB_Rule_BswMRule_WakeUpValidated */
        UINT16_C( 11 ), /* RuleDependencyTable[9] -- BswM_EB_Rule_BswMRule_WakeUpExpired */
        UINT16_C( 22 ), /* RuleDependencyTable[10] -- BswM_EB_Rule_BswMRule_PrepareHWReset */
        UINT16_C( 21 ), /* RuleDependencyTable[11] -- BswM_EB_Rule_BswMRule_ExecuteReset */
        UINT16_C( 20 ), /* RuleDependencyTable[12] -- BswM_EB_Rule_BswMRule_PrepareSWReset */
        UINT16_C( 19 ), /* RuleDependencyTable[13] -- BswM_EB_Rule_BswMRule_PrepareJumpToFBL */
        UINT16_C( 7 ), /* RuleDependencyTable[14] -- BswM_EB_Rule_BswMRule_EnterRunStateFromPostRunStateFirstCondition */
        UINT16_C( 4 ), /* RuleDependencyTable[15] -- BswM_EB_Rule_BswMRule_EnterShutdownStateFromLowPwrState */
        UINT16_C( 3 ), /* RuleDependencyTable[16] -- BswM_EB_Rule_BswMRule_EnterRunStateFromLowPwrStateFirstCondition */
        UINT16_C( 8 ), /* RuleDependencyTable[17] -- BswM_EB_Rule_BswMRule_EnterPostRunStateFromRunState */
        UINT16_C( 7 ), /* RuleDependencyTable[18] -- BswM_EB_Rule_BswMRule_EnterRunStateFromPostRunStateFirstCondition */
        UINT16_C( 6 ), /* RuleDependencyTable[19] -- BswM_EB_Rule_BswMRule_EnterRunStateFromPostRunStateSecondCondition */
        UINT16_C( 5 ), /* RuleDependencyTable[20] -- BswM_EB_Rule_BswMRule_EnterLowPwrStateFromPostRunState */
        UINT16_C( 4 ), /* RuleDependencyTable[21] -- BswM_EB_Rule_BswMRule_EnterShutdownStateFromLowPwrState */
        UINT16_C( 3 ), /* RuleDependencyTable[22] -- BswM_EB_Rule_BswMRule_EnterRunStateFromLowPwrStateFirstCondition */
        UINT16_C( 2 ), /* RuleDependencyTable[23] -- BswM_EB_Rule_BswMRule_EnterRunStateFromLowPwrStateSecondCondition */
        UINT16_C( 1 ), /* RuleDependencyTable[24] -- BswM_EB_Rule_BswMRule_EnterRunStateFromWakeupState */
        UINT16_C( 4 ), /* RuleDependencyTable[25] -- BswM_EB_Rule_BswMRule_EnterShutdownStateFromLowPwrState */
        UINT16_C( 3 ), /* RuleDependencyTable[26] -- BswM_EB_Rule_BswMRule_EnterRunStateFromLowPwrStateFirstCondition */
        UINT16_C( 2 ), /* RuleDependencyTable[27] -- BswM_EB_Rule_BswMRule_EnterRunStateFromLowPwrStateSecondCondition */
        UINT16_C( 8 ), /* RuleDependencyTable[28] -- BswM_EB_Rule_BswMRule_EnterPostRunStateFromRunState */
        UINT16_C( 6 ), /* RuleDependencyTable[29] -- BswM_EB_Rule_BswMRule_EnterRunStateFromPostRunStateSecondCondition */
        UINT16_C( 0 ), /* RuleDependencyTable[30] -- BswM_EB_Rule_BswMRule_EnableTxPdu */
        UINT16_C( 10 ), /* RuleDependencyTable[31] -- BswM_EB_Rule_BswMRule_StartShutdownSequence */
        UINT16_C( 18 ), /* RuleDependencyTable[32] -- BswM_EB_Rule_BswMRule_EnableTxPdu_DcmRequest */
        UINT16_C( 17 ) /* RuleDependencyTable[33] -- BswM_EB_Rule_BswMRule_DisableTxPdu_DcmRequest */
    },
    { /* RuleDependencyListRangeTable */
        { /* RuleDependencyListRangeTable[0] -- BswM_RequestPort */
            UINT16_C( 0 ), /* Head */
            UINT16_C( 7 ) /* Tail */
        },
        { /* RuleDependencyListRangeTable[1] -- BswmM_CanSM_RequestPort */
            UINT16_C( 7 ), /* Head */
            UINT16_C( 8 ) /* Tail */
        },
        { /* RuleDependencyListRangeTable[2] -- BswM_EcuM_RequestPort */
            UINT16_C( 8 ), /* Head */
            UINT16_C( 10 ) /* Tail */
        },
        { /* RuleDependencyListRangeTable[3] -- BswM_Dcm_RequestPort */
            UINT16_C( 10 ), /* Head */
            UINT16_C( 14 ) /* Tail */
        },
        { /* RuleDependencyListRangeTable[4] -- BswM_PassangerOccupancy_RequestPort */
            UINT16_C( 14 ), /* Head */
            UINT16_C( 17 ) /* Tail */
        },
        { /* RuleDependencyListRangeTable[5] -- BswM_EcuState_RequestPort */
            UINT16_C( 17 ), /* Head */
            UINT16_C( 25 ) /* Tail */
        },
        { /* RuleDependencyListRangeTable[6] -- BswM_WakeupType_RequestPort */
            UINT16_C( 25 ), /* Head */
            UINT16_C( 28 ) /* Tail */
        },
        { /* RuleDependencyListRangeTable[7] -- BswM_TxPdu_RequestPort */
            UINT16_C( 28 ), /* Head */
            UINT16_C( 31 ) /* Tail */
        },
        { /* RuleDependencyListRangeTable[8] -- BswM_EcuShutdown_RequestPort */
            UINT16_C( 31 ), /* Head */
            UINT16_C( 32 ) /* Tail */
        },
        { /* RuleDependencyListRangeTable[9] -- BswM_Dcm_ComM_RequestPort */
            UINT16_C( 32 ), /* Head */
            UINT16_C( 34 ) /* Tail */
        }
    },
    { /* ActionListTable */
        { /* ActionListTable[0] -- BswMActionList_BswMRule_BswM_StartupTwoA */
            { /* ActionListItemSegment */
                UINT16_C( 0 ), /* Head */
                UINT16_C( 1 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[1] -- BswMActionList_BswMRule_BswM_StartupTwoB */
            { /* ActionListItemSegment */
                UINT16_C( 1 ), /* Head */
                UINT16_C( 2 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[2] -- BswMActionList_BswMRule_BswM_GoOffOneA */
            { /* ActionListItemSegment */
                UINT16_C( 2 ), /* Head */
                UINT16_C( 3 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[3] -- BswMActionList_BswMRule_BswM_GoOffOneB */
            { /* ActionListItemSegment */
                UINT16_C( 3 ), /* Head */
                UINT16_C( 4 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[4] -- BswMActionList_BswMRule_WakeUpValidated */
            { /* ActionListItemSegment */
                UINT16_C( 4 ), /* Head */
                UINT16_C( 5 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[5] -- BswMActionList_BswMRule_WakeUpExpired */
            { /* ActionListItemSegment */
                UINT16_C( 5 ), /* Head */
                UINT16_C( 6 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[6] -- BswMActionList_BswMRule_StartShutdownSequence */
            { /* ActionListItemSegment */
                UINT16_C( 6 ), /* Head */
                UINT16_C( 8 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[7] -- BswMActionList_BswMRule_PrepareHWReset */
            { /* ActionListItemSegment */
                UINT16_C( 8 ), /* Head */
                UINT16_C( 10 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[8] -- BswMActionList_BswMRule_ExecuteReset */
            { /* ActionListItemSegment */
                UINT16_C( 10 ), /* Head */
                UINT16_C( 11 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[9] -- BswMActionList_BswMRule_PrepareSWReset */
            { /* ActionListItemSegment */
                UINT16_C( 11 ), /* Head */
                UINT16_C( 13 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[10] -- BswMActionList_BswMRule_StartComEffective */
            { /* ActionListItemSegment */
                UINT16_C( 13 ), /* Head */
                UINT16_C( 14 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[11] -- BswMActionList_BswMRule_PrepareJumpToFBL */
            { /* ActionListItemSegment */
                UINT16_C( 14 ), /* Head */
                UINT16_C( 16 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[12] -- BswMActionList_BswMRule_OnRunFromWakeup */
            { /* ActionListItemSegment */
                UINT16_C( 16 ), /* Head */
                UINT16_C( 19 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[13] -- BswMActionList_BswMRule_OnPostRunFromRun */
            { /* ActionListItemSegment */
                UINT16_C( 19 ), /* Head */
                UINT16_C( 21 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[14] -- BswMActionList_BswMRule_OnRunFromPostRunPassengerDetected */
            { /* ActionListItemSegment */
                UINT16_C( 21 ), /* Head */
                UINT16_C( 22 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[15] -- BswMActionList_BswMRule_OnRunFromPostRunBusWakeup */
            { /* ActionListItemSegment */
                UINT16_C( 22 ), /* Head */
                UINT16_C( 23 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[16] -- BswMActionList_BswMRule_OnLowPwrFromPostRun */
            { /* ActionListItemSegment */
                UINT16_C( 23 ), /* Head */
                UINT16_C( 25 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[17] -- BswMActionList_BswMRule_OnRunFromLowPwrPassengerDetected */
            { /* ActionListItemSegment */
                UINT16_C( 25 ), /* Head */
                UINT16_C( 28 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[18] -- BswMActionList_BswMRule_OnRunFromLowPwrBusWakeup */
            { /* ActionListItemSegment */
                UINT16_C( 28 ), /* Head */
                UINT16_C( 30 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[19] -- BswMActionList_BswMRule_EnableTxPdu */
            { /* ActionListItemSegment */
                UINT16_C( 30 ), /* Head */
                UINT16_C( 31 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        },
        { /* ActionListTable[20] -- BswMActionList_BswMRule_DisableTxPdu */
            { /* ActionListItemSegment */
                UINT16_C( 31 ), /* Head */
                UINT16_C( 32 ) /* Tail */
            },
            UINT8_C( 1 ) /* IsTriggered */
        }
    },
    { /* ActionListItemTable */
        { /* ActionListItemTable[0] */
            UINT16_C( 0 ), /* ArtifactIndex -- BswMAction_BswM_OnStartupTwoA */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[1] */
            UINT16_C( 1 ), /* ArtifactIndex -- BswMAction_BswM_OnStartupTwoB */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[2] */
            UINT16_C( 3 ), /* ArtifactIndex -- BswMAction_BswM_OnGoOffOneA */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[3] */
            UINT16_C( 4 ), /* ArtifactIndex -- BswMAction_OnWakeupExpired */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[4] */
            UINT16_C( 5 ), /* ArtifactIndex -- BswMAction_BswM_OnWakeupValidation */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[5] */
            UINT16_C( 4 ), /* ArtifactIndex -- BswMAction_OnWakeupExpired */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[6] */
            UINT16_C( 19 ), /* ArtifactIndex -- BswMAction_EcuM_SelectShutdownTarget_SLEEP */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[7] */
            UINT16_C( 6 ), /* ArtifactIndex -- BswMAction_BswM_On_Prep_Shutdown */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[8] */
            UINT16_C( 7 ), /* ArtifactIndex -- BswMAction_EcuM_SelectShutdownTarget_RESET */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[9] */
            UINT16_C( 11 ), /* ArtifactIndex -- BswMAction_BswM_HWResetNotification */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[10] */
            UINT16_C( 9 ), /* ArtifactIndex -- BswMAction_BswM_ProceedReset */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[11] */
            UINT16_C( 7 ), /* ArtifactIndex -- BswMAction_EcuM_SelectShutdownTarget_RESET */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[12] */
            UINT16_C( 10 ), /* ArtifactIndex -- BswMAction_BswM_SWResetNotification */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[13] */
            UINT16_C( 8 ), /* ArtifactIndex -- BswMAction_BswM_OnStartComEffective */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[14] */
            UINT16_C( 12 ), /* ArtifactIndex -- BswMAction_BswM_PrepareJumpToFBL */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[15] */
            UINT16_C( 7 ), /* ArtifactIndex -- BswMAction_EcuM_SelectShutdownTarget_RESET */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[16] */
            UINT16_C( 2 ), /* ArtifactIndex -- BswMAction_ComM_EnablePdus */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 1 ) /* ActionType */
        },
        { /* ActionListItemTable[17] */
            UINT16_C( 13 ), /* ArtifactIndex -- BswMAction_BswM_RunStateFromWakeup */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[18] */
            UINT16_C( 25 ), /* ArtifactIndex -- BswMAction_BswM_OnRunFromSafeState */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[19] */
            UINT16_C( 14 ), /* ArtifactIndex -- BswMAction_BswM_PostRunStateFromRun */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[20] */
            UINT16_C( 22 ), /* ArtifactIndex -- BswMAction_ComM_DisableTxPduConfirmation */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[21] */
            UINT16_C( 23 ), /* ArtifactIndex -- BswMAction_BswM_RunStateFromPostRunPassengerDetected */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[22] */
            UINT16_C( 15 ), /* ArtifactIndex -- BswMAction_BswM_RunStateFromPostRunBusAvailable */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[23] */
            UINT16_C( 24 ), /* ArtifactIndex -- BswMAction_BswM_OnSafeStateFromPostRun */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[24] */
            UINT16_C( 16 ), /* ArtifactIndex -- BswMAction_BswM_LowPwrStateFromPostRun */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[25] */
            UINT16_C( 17 ), /* ArtifactIndex -- BswMAction_BswM_RunStateFromLowPwr_ActiveWake */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[26] */
            UINT16_C( 20 ), /* ArtifactIndex -- BswMAction_ComM_FullCom */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[27] */
            UINT16_C( 25 ), /* ArtifactIndex -- BswMAction_BswM_OnRunFromSafeState */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[28] */
            UINT16_C( 18 ), /* ArtifactIndex -- BswMAction_BswM_RunStateFromLowPwr_PassiveWake */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[29] */
            UINT16_C( 25 ), /* ArtifactIndex -- BswMAction_BswM_OnRunFromSafeState */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[30] */
            UINT16_C( 21 ), /* ArtifactIndex -- BswMAction_ComM_EnableTxPduConfirmation */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[31] */
            UINT16_C( 22 ), /* ArtifactIndex -- BswMAction_ComM_DisableTxPduConfirmation */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT8_C( 0 ) /* ActionType */
        }
    },
    { /* PduGroupSwitchActionTable */
        { /* PduGroupSwitchActionTable[0] */
            { /* EnableMask */
                UINT8_C( 1 ), /* EnableMask[0] */
                UINT8_C( 0 ), /* EnableMask[1] */
                UINT8_C( 0 ), /* EnableMask[2] */
                UINT8_C( 64 ) /* EnableMask[3] */
            },
            { /* DisableMask */
                UINT8_C( 255 ), /* DisableMask[0] */
                UINT8_C( 255 ), /* DisableMask[1] */
                UINT8_C( 255 ), /* DisableMask[2] */
                UINT8_C( 255 ) /* DisableMask[3] */
            },
            UINT8_C( 0 ) /* RequestInit */
        }
    },
    { /* UInt8InitialValuesTable */
        UINT8_C( 5 ), /* UInt8InitialValuesTable[0] -- Initial value of Port BswM_Dcm_RequestPort */
        UINT8_C( 0 ) /* UInt8InitialValuesTable[1] -- Initial value of Port BswM_Dcm_ComM_RequestPort */
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <BswM_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

