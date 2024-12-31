/*********************************************************************************//*!
*   \file           T1_MemMap.h
*
*   \brief          This header selects the T1-TARGET-SW sections for
*                   the IAR compiler.
*
*   \par Visibility
*                   External
*
*   \author         Generated file
*
*   \version 3.5.1.0 r65516
*
*   \copyright GLIWA embedded systems GmbH & Co. KG, Weilheim i.OB. All rights reserved
*************************************************************************************/

#if 0

#elif defined T1_START_SEC_CODE
#   undef T1_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_code"
#elif defined T1_STOP_SEC_CODE
#   undef T1_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE0_START_SEC_CODE
#   undef T1_CORE0_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore0"
#elif defined T1_CORE0_STOP_SEC_CODE
#   undef T1_CORE0_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE1_START_SEC_CODE
#   undef T1_CORE1_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore1"
#elif defined T1_CORE1_STOP_SEC_CODE
#   undef T1_CORE1_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE2_START_SEC_CODE
#   undef T1_CORE2_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore2"
#elif defined T1_CORE2_STOP_SEC_CODE
#   undef T1_CORE2_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE3_START_SEC_CODE
#   undef T1_CORE3_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore3"
#elif defined T1_CORE3_STOP_SEC_CODE
#   undef T1_CORE3_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE4_START_SEC_CODE
#   undef T1_CORE4_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore4"
#elif defined T1_CORE4_STOP_SEC_CODE
#   undef T1_CORE4_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE5_START_SEC_CODE
#   undef T1_CORE5_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore5"
#elif defined T1_CORE5_STOP_SEC_CODE
#   undef T1_CORE5_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE6_START_SEC_CODE
#   undef T1_CORE6_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore6"
#elif defined T1_CORE6_STOP_SEC_CODE
#   undef T1_CORE6_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE7_START_SEC_CODE
#   undef T1_CORE7_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore7"
#elif defined T1_CORE7_STOP_SEC_CODE
#   undef T1_CORE7_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE8_START_SEC_CODE
#   undef T1_CORE8_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore8"
#elif defined T1_CORE8_STOP_SEC_CODE
#   undef T1_CORE8_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE9_START_SEC_CODE
#   undef T1_CORE9_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore9"
#elif defined T1_CORE9_STOP_SEC_CODE
#   undef T1_CORE9_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE10_START_SEC_CODE
#   undef T1_CORE10_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore10"
#elif defined T1_CORE10_STOP_SEC_CODE
#   undef T1_CORE10_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE11_START_SEC_CODE
#   undef T1_CORE11_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore11"
#elif defined T1_CORE11_STOP_SEC_CODE
#   undef T1_CORE11_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE12_START_SEC_CODE
#   undef T1_CORE12_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore12"
#elif defined T1_CORE12_STOP_SEC_CODE
#   undef T1_CORE12_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE13_START_SEC_CODE
#   undef T1_CORE13_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore13"
#elif defined T1_CORE13_STOP_SEC_CODE
#   undef T1_CORE13_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_CORE14_START_SEC_CODE
#   undef T1_CORE14_START_SEC_CODE
#   pragma default_function_attributes = @ ".T1_codeCore14"
#elif defined T1_CORE14_STOP_SEC_CODE
#   undef T1_CORE14_STOP_SEC_CODE
#   pragma default_function_attributes =

#elif defined T1_START_SEC_CODE_FAST
#   undef T1_START_SEC_CODE_FAST
#   pragma default_function_attributes = @ ".T1_codeFast"
#elif defined T1_STOP_SEC_CODE_FAST
#   undef T1_STOP_SEC_CODE_FAST
#   pragma default_function_attributes =

#elif defined T1_START_SEC_CONST_8
#   undef T1_START_SEC_CONST_8
#   pragma default_variable_attributes = @ ".T1_const"
#elif defined T1_STOP_SEC_CONST_8
#   undef T1_STOP_SEC_CONST_8
#   pragma default_variable_attributes =

#elif defined T1_START_SEC_CONST_16
#   undef T1_START_SEC_CONST_16
#   pragma default_variable_attributes = @ ".T1_const"
#elif defined T1_STOP_SEC_CONST_16
#   undef T1_STOP_SEC_CONST_16
#   pragma default_variable_attributes =

#elif defined T1_START_SEC_CONST_32
#   undef T1_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_const"
#elif defined T1_STOP_SEC_CONST_32
#   undef T1_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE0_START_SEC_CONST_32
#   undef T1_CORE0_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore0"
#elif defined T1_CORE0_STOP_SEC_CONST_32
#   undef T1_CORE0_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE1_START_SEC_CONST_32
#   undef T1_CORE1_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore1"
#elif defined T1_CORE1_STOP_SEC_CONST_32
#   undef T1_CORE1_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE2_START_SEC_CONST_32
#   undef T1_CORE2_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore2"
#elif defined T1_CORE2_STOP_SEC_CONST_32
#   undef T1_CORE2_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE3_START_SEC_CONST_32
#   undef T1_CORE3_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore3"
#elif defined T1_CORE3_STOP_SEC_CONST_32
#   undef T1_CORE3_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE4_START_SEC_CONST_32
#   undef T1_CORE4_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore4"
#elif defined T1_CORE4_STOP_SEC_CONST_32
#   undef T1_CORE4_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE5_START_SEC_CONST_32
#   undef T1_CORE5_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore5"
#elif defined T1_CORE5_STOP_SEC_CONST_32
#   undef T1_CORE5_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE6_START_SEC_CONST_32
#   undef T1_CORE6_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore6"
#elif defined T1_CORE6_STOP_SEC_CONST_32
#   undef T1_CORE6_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE7_START_SEC_CONST_32
#   undef T1_CORE7_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore7"
#elif defined T1_CORE7_STOP_SEC_CONST_32
#   undef T1_CORE7_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE8_START_SEC_CONST_32
#   undef T1_CORE8_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore8"
#elif defined T1_CORE8_STOP_SEC_CONST_32
#   undef T1_CORE8_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE9_START_SEC_CONST_32
#   undef T1_CORE9_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore9"
#elif defined T1_CORE9_STOP_SEC_CONST_32
#   undef T1_CORE9_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE10_START_SEC_CONST_32
#   undef T1_CORE10_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore10"
#elif defined T1_CORE10_STOP_SEC_CONST_32
#   undef T1_CORE10_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE11_START_SEC_CONST_32
#   undef T1_CORE11_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore11"
#elif defined T1_CORE11_STOP_SEC_CONST_32
#   undef T1_CORE11_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE12_START_SEC_CONST_32
#   undef T1_CORE12_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore12"
#elif defined T1_CORE12_STOP_SEC_CONST_32
#   undef T1_CORE12_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE13_START_SEC_CONST_32
#   undef T1_CORE13_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore13"
#elif defined T1_CORE13_STOP_SEC_CONST_32
#   undef T1_CORE13_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CORE14_START_SEC_CONST_32
#   undef T1_CORE14_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constCore14"
#elif defined T1_CORE14_STOP_SEC_CONST_32
#   undef T1_CORE14_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_CLONE_START_SEC_CONST_32
#   undef T1_CLONE_START_SEC_CONST_32
#   pragma default_variable_attributes = @ ".T1_constClone"
#elif defined T1_CLONE_STOP_SEC_CONST_32
#   undef T1_CLONE_STOP_SEC_CONST_32
#   pragma default_variable_attributes =

#elif defined T1_START_SEC_VAR_CLEARED_32
#   undef T1_START_SEC_VAR_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_clear"
#elif defined T1_STOP_SEC_VAR_CLEARED_32
#   undef T1_STOP_SEC_VAR_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbss"
#elif defined T1_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE0_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE0_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore0"
#elif defined T1_CORE0_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE0_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore1"
#elif defined T1_CORE1_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE1_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE2_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE2_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore2"
#elif defined T1_CORE2_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE2_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE3_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE3_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore3"
#elif defined T1_CORE3_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE3_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE4_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE4_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore4"
#elif defined T1_CORE4_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE4_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE5_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE5_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore5"
#elif defined T1_CORE5_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE5_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE6_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE6_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore6"
#elif defined T1_CORE6_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE6_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE7_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE7_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore7"
#elif defined T1_CORE7_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE7_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE8_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE8_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore8"
#elif defined T1_CORE8_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE8_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE9_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE9_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore9"
#elif defined T1_CORE9_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE9_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE10_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE10_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore10"
#elif defined T1_CORE10_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE10_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE11_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE11_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore11"
#elif defined T1_CORE11_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE11_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE12_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE12_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore12"
#elif defined T1_CORE12_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE12_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE13_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE13_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore13"
#elif defined T1_CORE13_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE13_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE14_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE14_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCore14"
#elif defined T1_CORE14_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE14_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE_COMMS_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE_COMMS_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssCoreComms"
#elif defined T1_CORE_COMMS_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CORE_COMMS_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CLONE_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CLONE_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_sbssClone"
#elif defined T1_CLONE_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   undef T1_CLONE_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbss"
#elif defined T1_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE0_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE0_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore0"
#elif defined T1_CORE0_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE0_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore1"
#elif defined T1_CORE1_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE1_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE2_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE2_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore2"
#elif defined T1_CORE2_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE2_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE3_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE3_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore3"
#elif defined T1_CORE3_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE3_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE4_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE4_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore4"
#elif defined T1_CORE4_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE4_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE5_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE5_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore5"
#elif defined T1_CORE5_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE5_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE6_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE6_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore6"
#elif defined T1_CORE6_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE6_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE7_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE7_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore7"
#elif defined T1_CORE7_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE7_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE8_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE8_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore8"
#elif defined T1_CORE8_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE8_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE9_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE9_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore9"
#elif defined T1_CORE9_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE9_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE10_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE10_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore10"
#elif defined T1_CORE10_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE10_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE11_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE11_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore11"
#elif defined T1_CORE11_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE11_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE12_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE12_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore12"
#elif defined T1_CORE12_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE12_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE13_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE13_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore13"
#elif defined T1_CORE13_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE13_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE14_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE14_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCore14"
#elif defined T1_CORE14_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE14_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE_COMMS_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE_COMMS_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssCoreComms"
#elif defined T1_CORE_COMMS_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CORE_COMMS_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CLONE_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CLONE_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_sbssClone"
#elif defined T1_CLONE_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   undef T1_CLONE_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbss"
#elif defined T1_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE0_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE0_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore0"
#elif defined T1_CORE0_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE0_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore1"
#elif defined T1_CORE1_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE1_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE2_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE2_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore2"
#elif defined T1_CORE2_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE2_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE3_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE3_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore3"
#elif defined T1_CORE3_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE3_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE4_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE4_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore4"
#elif defined T1_CORE4_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE4_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE5_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE5_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore5"
#elif defined T1_CORE5_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE5_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE6_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE6_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore6"
#elif defined T1_CORE6_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE6_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE7_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE7_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore7"
#elif defined T1_CORE7_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE7_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE8_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE8_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore8"
#elif defined T1_CORE8_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE8_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE9_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE9_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore9"
#elif defined T1_CORE9_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE9_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE10_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE10_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore10"
#elif defined T1_CORE10_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE10_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE11_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE11_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore11"
#elif defined T1_CORE11_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE11_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE12_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE12_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore12"
#elif defined T1_CORE12_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE12_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE13_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE13_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore13"
#elif defined T1_CORE13_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE13_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE14_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE14_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCore14"
#elif defined T1_CORE14_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE14_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE_COMMS_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE_COMMS_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssCoreComms"
#elif defined T1_CORE_COMMS_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CORE_COMMS_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CLONE_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CLONE_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_sbssClone"
#elif defined T1_CLONE_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   undef T1_CLONE_STOP_SEC_VAR_NEAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bss"
#elif defined T1_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE0_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE0_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore0"
#elif defined T1_CORE0_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE0_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE1_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE1_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore1"
#elif defined T1_CORE1_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE1_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE2_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE2_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore2"
#elif defined T1_CORE2_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE2_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE3_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE3_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore3"
#elif defined T1_CORE3_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE3_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE4_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE4_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore4"
#elif defined T1_CORE4_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE4_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE5_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE5_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore5"
#elif defined T1_CORE5_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE5_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE6_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE6_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore6"
#elif defined T1_CORE6_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE6_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE7_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE7_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore7"
#elif defined T1_CORE7_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE7_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE8_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE8_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore8"
#elif defined T1_CORE8_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE8_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE9_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE9_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore9"
#elif defined T1_CORE9_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE9_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE10_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE10_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore10"
#elif defined T1_CORE10_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE10_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE11_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE11_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore11"
#elif defined T1_CORE11_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE11_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE12_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE12_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore12"
#elif defined T1_CORE12_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE12_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE13_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE13_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore13"
#elif defined T1_CORE13_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE13_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE14_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE14_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCore14"
#elif defined T1_CORE14_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE14_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CORE_COMMS_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE_COMMS_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssCoreComms"
#elif defined T1_CORE_COMMS_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CORE_COMMS_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_CLONE_START_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CLONE_START_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes = @ ".T1_bssClone"
#elif defined T1_CLONE_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   undef T1_CLONE_STOP_SEC_VAR_POWER_ON_CLEARED_8
#   pragma default_variable_attributes =

#elif defined T1_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bss"
#elif defined T1_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE0_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE0_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore0"
#elif defined T1_CORE0_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE0_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE1_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE1_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore1"
#elif defined T1_CORE1_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE1_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE2_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE2_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore2"
#elif defined T1_CORE2_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE2_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE3_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE3_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore3"
#elif defined T1_CORE3_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE3_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE4_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE4_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore4"
#elif defined T1_CORE4_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE4_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE5_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE5_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore5"
#elif defined T1_CORE5_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE5_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE6_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE6_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore6"
#elif defined T1_CORE6_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE6_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE7_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE7_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore7"
#elif defined T1_CORE7_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE7_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE8_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE8_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore8"
#elif defined T1_CORE8_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE8_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE9_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE9_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore9"
#elif defined T1_CORE9_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE9_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE10_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE10_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore10"
#elif defined T1_CORE10_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE10_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE11_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE11_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore11"
#elif defined T1_CORE11_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE11_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE12_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE12_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore12"
#elif defined T1_CORE12_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE12_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE13_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE13_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore13"
#elif defined T1_CORE13_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE13_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE14_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE14_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCore14"
#elif defined T1_CORE14_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE14_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CORE_COMMS_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE_COMMS_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssCoreComms"
#elif defined T1_CORE_COMMS_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CORE_COMMS_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_CLONE_START_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CLONE_START_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes = @ ".T1_bssClone"
#elif defined T1_CLONE_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   undef T1_CLONE_STOP_SEC_VAR_POWER_ON_CLEARED_16
#   pragma default_variable_attributes =

#elif defined T1_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bss"
#elif defined T1_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE0_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE0_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore0"
#elif defined T1_CORE0_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE0_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE1_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE1_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore1"
#elif defined T1_CORE1_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE1_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE2_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE2_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore2"
#elif defined T1_CORE2_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE2_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE3_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE3_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore3"
#elif defined T1_CORE3_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE3_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE4_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE4_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore4"
#elif defined T1_CORE4_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE4_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE5_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE5_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore5"
#elif defined T1_CORE5_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE5_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE6_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE6_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore6"
#elif defined T1_CORE6_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE6_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE7_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE7_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore7"
#elif defined T1_CORE7_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE7_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE8_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE8_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore8"
#elif defined T1_CORE8_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE8_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE9_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE9_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore9"
#elif defined T1_CORE9_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE9_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE10_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE10_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore10"
#elif defined T1_CORE10_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE10_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE11_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE11_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore11"
#elif defined T1_CORE11_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE11_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE12_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE12_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore12"
#elif defined T1_CORE12_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE12_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE13_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE13_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore13"
#elif defined T1_CORE13_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE13_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE14_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE14_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCore14"
#elif defined T1_CORE14_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE14_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CORE_COMMS_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE_COMMS_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCoreComms"
#elif defined T1_CORE_COMMS_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CORE_COMMS_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CLONE_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CLONE_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssClone"
#elif defined T1_CLONE_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CLONE_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssChecked"
#elif defined T1_CHECKED_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE0_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE0_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore0"
#elif defined T1_CHECKED_CORE0_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE0_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE1_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE1_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore1"
#elif defined T1_CHECKED_CORE1_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE1_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE2_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE2_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore2"
#elif defined T1_CHECKED_CORE2_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE2_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE3_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE3_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore3"
#elif defined T1_CHECKED_CORE3_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE3_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE4_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE4_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore4"
#elif defined T1_CHECKED_CORE4_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE4_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE5_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE5_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore5"
#elif defined T1_CHECKED_CORE5_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE5_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE6_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE6_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore6"
#elif defined T1_CHECKED_CORE6_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE6_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE7_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE7_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore7"
#elif defined T1_CHECKED_CORE7_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE7_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE8_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE8_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore8"
#elif defined T1_CHECKED_CORE8_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE8_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE9_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE9_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore9"
#elif defined T1_CHECKED_CORE9_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE9_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE10_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE10_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore10"
#elif defined T1_CHECKED_CORE10_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE10_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE11_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE11_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore11"
#elif defined T1_CHECKED_CORE11_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE11_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE12_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE12_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore12"
#elif defined T1_CHECKED_CORE12_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE12_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE13_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE13_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore13"
#elif defined T1_CHECKED_CORE13_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE13_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CORE14_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE14_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedCore14"
#elif defined T1_CHECKED_CORE14_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CORE14_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_CHECKED_CLONE_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CLONE_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_bssCheckedClone"
#elif defined T1_CHECKED_CLONE_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_CHECKED_CLONE_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBuffer"
#elif defined T1_TRACEBUFFER_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE0_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE0_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore0"
#elif defined T1_TRACEBUFFER_CORE0_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE0_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE1_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE1_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore1"
#elif defined T1_TRACEBUFFER_CORE1_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE1_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE2_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE2_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore2"
#elif defined T1_TRACEBUFFER_CORE2_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE2_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE3_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE3_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore3"
#elif defined T1_TRACEBUFFER_CORE3_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE3_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE4_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE4_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore4"
#elif defined T1_TRACEBUFFER_CORE4_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE4_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE5_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE5_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore5"
#elif defined T1_TRACEBUFFER_CORE5_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE5_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE6_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE6_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore6"
#elif defined T1_TRACEBUFFER_CORE6_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE6_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE7_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE7_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore7"
#elif defined T1_TRACEBUFFER_CORE7_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE7_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE8_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE8_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore8"
#elif defined T1_TRACEBUFFER_CORE8_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE8_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE9_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE9_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore9"
#elif defined T1_TRACEBUFFER_CORE9_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE9_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE10_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE10_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore10"
#elif defined T1_TRACEBUFFER_CORE10_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE10_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE11_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE11_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore11"
#elif defined T1_TRACEBUFFER_CORE11_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE11_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE12_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE12_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore12"
#elif defined T1_TRACEBUFFER_CORE12_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE12_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE13_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE13_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore13"
#elif defined T1_TRACEBUFFER_CORE13_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE13_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CORE14_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE14_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferCore14"
#elif defined T1_TRACEBUFFER_CORE14_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CORE14_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#elif defined T1_TRACEBUFFER_CLONE_START_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CLONE_START_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes = @ ".T1_traceBufferClone"
#elif defined T1_TRACEBUFFER_CLONE_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   undef T1_TRACEBUFFER_CLONE_STOP_SEC_VAR_POWER_ON_CLEARED_32
#   pragma default_variable_attributes =

#else
#   error "T1_MemMap.h: no valid section define used."
#endif

#if defined T1_DOXYGEN_ONLY
/*! \brief Code (in flash) shared by all cores */
#   define T1_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 0 */
#   define T1_CORE0_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 1 */
#   define T1_CORE1_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 2 */
#   define T1_CORE2_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 3 */
#   define T1_CORE3_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 4 */
#   define T1_CORE4_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 5 */
#   define T1_CORE5_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 6 */
#   define T1_CORE6_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 7 */
#   define T1_CORE7_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 8 */
#   define T1_CORE8_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 9 */
#   define T1_CORE9_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 10 */
#   define T1_CORE10_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 11 */
#   define T1_CORE11_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 12 */
#   define T1_CORE12_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 13 */
#   define T1_CORE13_START_SEC_CODE (1)
/*! \brief Code (in flash) for T1 logical core 14 */
#   define T1_CORE14_START_SEC_CODE (1)
/*! \brief Code relevant to T1-TARGET-SW overheads shared by all cores */
#   define T1_START_SEC_CODE_FAST (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 8-bit accesses shared by all cores */
#   define T1_START_SEC_CONST_8 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 16-bit accesses shared by all cores */
#   define T1_START_SEC_CONST_16 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses shared by all cores */
#   define T1_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 0 */
#   define T1_CORE0_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 1 */
#   define T1_CORE1_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 2 */
#   define T1_CORE2_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 3 */
#   define T1_CORE3_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 4 */
#   define T1_CORE4_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 5 */
#   define T1_CORE5_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 6 */
#   define T1_CORE6_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 7 */
#   define T1_CORE7_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 8 */
#   define T1_CORE8_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 9 */
#   define T1_CORE9_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 10 */
#   define T1_CORE10_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 11 */
#   define T1_CORE11_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 12 */
#   define T1_CORE12_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 13 */
#   define T1_CORE13_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses for T1 logical core 14 */
#   define T1_CORE14_START_SEC_CONST_32 (1)
/*! \brief Constant data (in flash or write-protected RAM) aligned for 32-bit accesses duplicated for each core */
#   define T1_CLONE_START_SEC_CONST_32 (1)
/*! \brief Shared zeroed RAM aligned for 32-bit accesses shared by all cores */
#   define T1_START_SEC_VAR_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses shared by all cores */
#   define T1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 0 */
#   define T1_CORE0_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 1 */
#   define T1_CORE1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 2 */
#   define T1_CORE2_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 3 */
#   define T1_CORE3_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 4 */
#   define T1_CORE4_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 5 */
#   define T1_CORE5_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 6 */
#   define T1_CORE6_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 7 */
#   define T1_CORE7_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 8 */
#   define T1_CORE8_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 9 */
#   define T1_CORE9_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 10 */
#   define T1_CORE10_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 11 */
#   define T1_CORE11_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 12 */
#   define T1_CORE12_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 13 */
#   define T1_CORE13_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 logical core 14 */
#   define T1_CORE14_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses for T1 communications core */
#   define T1_CORE_COMMS_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 8-bit accesses duplicated for each core */
#   define T1_CLONE_START_SEC_VAR_NEAR_POWER_ON_CLEARED_8 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses shared by all cores */
#   define T1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 0 */
#   define T1_CORE0_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 1 */
#   define T1_CORE1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 2 */
#   define T1_CORE2_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 3 */
#   define T1_CORE3_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 4 */
#   define T1_CORE4_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 5 */
#   define T1_CORE5_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 6 */
#   define T1_CORE6_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 7 */
#   define T1_CORE7_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 8 */
#   define T1_CORE8_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 9 */
#   define T1_CORE9_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 10 */
#   define T1_CORE10_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 11 */
#   define T1_CORE11_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 12 */
#   define T1_CORE12_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 13 */
#   define T1_CORE13_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 logical core 14 */
#   define T1_CORE14_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses for T1 communications core */
#   define T1_CORE_COMMS_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 16-bit accesses duplicated for each core */
#   define T1_CLONE_START_SEC_VAR_NEAR_POWER_ON_CLEARED_16 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses shared by all cores */
#   define T1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 0 */
#   define T1_CORE0_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 1 */
#   define T1_CORE1_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 2 */
#   define T1_CORE2_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 3 */
#   define T1_CORE3_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 4 */
#   define T1_CORE4_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 5 */
#   define T1_CORE5_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 6 */
#   define T1_CORE6_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 7 */
#   define T1_CORE7_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 8 */
#   define T1_CORE8_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 9 */
#   define T1_CORE9_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 10 */
#   define T1_CORE10_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 11 */
#   define T1_CORE11_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 12 */
#   define T1_CORE12_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 13 */
#   define T1_CORE13_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 logical core 14 */
#   define T1_CORE14_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses for T1 communications core */
#   define T1_CORE_COMMS_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Near uninitialized RAM aligned for 32-bit accesses duplicated for each core */
#   define T1_CLONE_START_SEC_VAR_NEAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses shared by all cores */
#   define T1_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 0 */
#   define T1_CORE0_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 1 */
#   define T1_CORE1_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 2 */
#   define T1_CORE2_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 3 */
#   define T1_CORE3_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 4 */
#   define T1_CORE4_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 5 */
#   define T1_CORE5_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 6 */
#   define T1_CORE6_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 7 */
#   define T1_CORE7_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 8 */
#   define T1_CORE8_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 9 */
#   define T1_CORE9_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 10 */
#   define T1_CORE10_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 11 */
#   define T1_CORE11_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 12 */
#   define T1_CORE12_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 13 */
#   define T1_CORE13_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 logical core 14 */
#   define T1_CORE14_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses for T1 communications core */
#   define T1_CORE_COMMS_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 8-bit accesses duplicated for each core */
#   define T1_CLONE_START_SEC_VAR_POWER_ON_CLEARED_8 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses shared by all cores */
#   define T1_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 0 */
#   define T1_CORE0_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 1 */
#   define T1_CORE1_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 2 */
#   define T1_CORE2_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 3 */
#   define T1_CORE3_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 4 */
#   define T1_CORE4_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 5 */
#   define T1_CORE5_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 6 */
#   define T1_CORE6_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 7 */
#   define T1_CORE7_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 8 */
#   define T1_CORE8_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 9 */
#   define T1_CORE9_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 10 */
#   define T1_CORE10_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 11 */
#   define T1_CORE11_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 12 */
#   define T1_CORE12_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 13 */
#   define T1_CORE13_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 logical core 14 */
#   define T1_CORE14_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses for T1 communications core */
#   define T1_CORE_COMMS_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 16-bit accesses duplicated for each core */
#   define T1_CLONE_START_SEC_VAR_POWER_ON_CLEARED_16 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses shared by all cores */
#   define T1_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 0 */
#   define T1_CORE0_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 1 */
#   define T1_CORE1_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 2 */
#   define T1_CORE2_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 3 */
#   define T1_CORE3_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 4 */
#   define T1_CORE4_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 5 */
#   define T1_CORE5_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 6 */
#   define T1_CORE6_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 7 */
#   define T1_CORE7_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 8 */
#   define T1_CORE8_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 9 */
#   define T1_CORE9_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 10 */
#   define T1_CORE10_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 11 */
#   define T1_CORE11_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 12 */
#   define T1_CORE12_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 13 */
#   define T1_CORE13_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 logical core 14 */
#   define T1_CORE14_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses for T1 communications core */
#   define T1_CORE_COMMS_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM aligned for 32-bit accesses duplicated for each core */
#   define T1_CLONE_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses shared by all cores */
#   define T1_CHECKED_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 0 */
#   define T1_CHECKED_CORE0_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 1 */
#   define T1_CHECKED_CORE1_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 2 */
#   define T1_CHECKED_CORE2_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 3 */
#   define T1_CHECKED_CORE3_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 4 */
#   define T1_CHECKED_CORE4_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 5 */
#   define T1_CHECKED_CORE5_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 6 */
#   define T1_CHECKED_CORE6_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 7 */
#   define T1_CHECKED_CORE7_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 8 */
#   define T1_CHECKED_CORE8_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 9 */
#   define T1_CHECKED_CORE9_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 10 */
#   define T1_CHECKED_CORE10_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 11 */
#   define T1_CHECKED_CORE11_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 12 */
#   define T1_CHECKED_CORE12_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 13 */
#   define T1_CHECKED_CORE13_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses for T1 logical core 14 */
#   define T1_CHECKED_CORE14_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Uninitialized RAM with protection against corruption aligned for 32-bit accesses duplicated for each core */
#   define T1_CHECKED_CLONE_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses shared by all cores */
#   define T1_TRACEBUFFER_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 0 */
#   define T1_TRACEBUFFER_CORE0_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 1 */
#   define T1_TRACEBUFFER_CORE1_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 2 */
#   define T1_TRACEBUFFER_CORE2_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 3 */
#   define T1_TRACEBUFFER_CORE3_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 4 */
#   define T1_TRACEBUFFER_CORE4_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 5 */
#   define T1_TRACEBUFFER_CORE5_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 6 */
#   define T1_TRACEBUFFER_CORE6_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 7 */
#   define T1_TRACEBUFFER_CORE7_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 8 */
#   define T1_TRACEBUFFER_CORE8_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 9 */
#   define T1_TRACEBUFFER_CORE9_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 10 */
#   define T1_TRACEBUFFER_CORE10_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 11 */
#   define T1_TRACEBUFFER_CORE11_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 12 */
#   define T1_TRACEBUFFER_CORE12_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 13 */
#   define T1_TRACEBUFFER_CORE13_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses for T1 logical core 14 */
#   define T1_TRACEBUFFER_CORE14_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
/*! \brief Trace buffer RAM aligned for 32-bit accesses duplicated for each core */
#   define T1_TRACEBUFFER_CLONE_START_SEC_VAR_POWER_ON_CLEARED_32 (1)
#endif /* defined T1_DOXYGEN_ONLY */
