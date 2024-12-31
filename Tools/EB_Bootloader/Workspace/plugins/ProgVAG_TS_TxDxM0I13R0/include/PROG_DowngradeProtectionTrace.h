#ifndef PROG_DOWNGRADEPROTECTIONTRACE_H
#define PROG_DOWNGRADEPROTECTIONTRACE_H
/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               PROG_VAG layer                                  */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_DowngradeProtectionTrace.h */
/*%%  |                             |  %%  \brief PROG DGP trace debug mode      */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 0.13.0 BL3 */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/* Copyright 2021 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/

/*==================[inclusions]============================================*/

#include <Std_Types.h>

/* Check if BASE_DBG_ENABLE is defined and set to STD_ON.
 * If so, include Base_Dbg.h which includes a custom header file */
#if (defined BASE_DBG_ENABLE)
#if (BASE_DBG_ENABLE == STD_ON)

#include <Base_Dbg.h>

#endif
#endif

/*==================[macros]================================================*/

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_PROG_DOWNGRADEPROTECTION_CHECKFORERASEANDRD_IMPL40_ENTRY
/** \brief Entry point of function PROG_DowngradeProtection_CheckForEraseAndRD_Impl40()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_PROG_DOWNGRADEPROTECTION_CHECKFORERASEANDRD_IMPL40_ENTRY(ubBlockId)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */
/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_PROG_DOWNGRADEPROTECTION_CHECKFORERASEANDRD_IMPL40_EXIT
/** \brief Exit point of function PROG_DowngradeProtection_CheckForEraseAndRD_Impl40()
 **
 ** The first parameter of the macro is the return
 ** value of the function, followed by the arguments
 ** of the function.
 */
#define DBG_PROG_DOWNGRADEPROTECTION_CHECKFORERASEANDRD_IMPL40_EXIT(eProgStatus)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_PROG_DOWNGRADEPROTECTION_CHECKFORCHECKMEMORY_IMPL40_ENTRY
/** \brief Entry point of function PROG_DowngradeProtection_CheckForCheckMemory_Impl40()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_PROG_DOWNGRADEPROTECTION_CHECKFORCHECKMEMORY_IMPL40_ENTRY(ubBlockId,ubDgpStatus)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */
/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_PROG_DOWNGRADEPROTECTION_CHECKFORCHECKMEMORY_IMPL40_EXIT
/** \brief Exit point of function PROG_DowngradeProtection_CheckForCheckMemory_Impl40()
 **
 ** The first parameter of the macro is the return
 ** value of the function, followed by the arguments
 ** of the function.
 */
#define DBG_PROG_DOWNGRADEPROTECTION_CHECKFORCHECKMEMORY_IMPL40_EXIT(eProgStatus)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_PROG_DOWNGRADEPROTECTION_COMPARERFSFORCOHERENCYCHECK_IMPL40_ENTRY
/** \brief Entry point of function PROG_DowngradeProtection_CompareRfsForCoherencyCheck_Impl40()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_PROG_DOWNGRADEPROTECTION_COMPARERFSFORCOHERENCYCHECK_IMPL40_ENTRY(pubRoutineStatus)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */
/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_PROG_DOWNGRADEPROTECTION_COMPARERFSFORCOHERENCYCHECK_IMPL40_EXIT
/** \brief Exit point of function PROG_DowngradeProtection_CompareRfsForCoherencyCheck_Impl40()
 **
 ** The first parameter of the macro is the return
 ** value of the function, followed by the arguments
 ** of the function.
 */
#define DBG_PROG_DOWNGRADEPROTECTION_COMPARERFSFORCOHERENCYCHECK_IMPL40_EXIT(eProgStatus)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_PROG_DOWNGRADEPROTECTION_RESETPFTSTATUS_IMPL40_ENTRY
/** \brief Entry point of function PROG_DowngradeProtection_ResetPFTStatus_Impl40()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_PROG_DOWNGRADEPROTECTION_RESETPFTSTATUS_IMPL40_ENTRY()
#endif
/** \brief Exclude section from doxygen
 ** @endcond */
/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_PROG_DOWNGRADEPROTECTION_RESETPFTSTATUS_IMPL40_EXIT
/** \brief Exit point of function PROG_DowngradeProtection_ResetPFTStatus_Impl40()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_PROG_DOWNGRADEPROTECTION_RESETPFTSTATUS_IMPL40_EXIT()
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*                                                                               */
/*===============================================================================*/

#endif      /* PROG_DOWNGRADEPROTECTIONTRACE_H */
/*==================[end of file]===========================================*/

