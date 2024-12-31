#if (!defined COMPILER_SPECIFIC_H)
#define COMPILER_SPECIFIC_H
/* --------{ EB Automotive C Source File }-------- */

/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/

/*------------------[compiler symbol]----------------------------------------*/

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 21.1 (required)
 * #define and #undef shall not be used on a reserved identifier or reserved
 * macro name.
 *
 * Reason:
 * Generally, all identifiers that begin with the underscore character are reserved.
 * The macro _VISUAL_C_WIN32X86_ is only used for Autosar 2.1 backward compatibility.
 */
/* COMPILER010 */
/* !LINKSTO CompilerAbstraction.ASR403.COMPILER010, 1 */
#if (defined _VISUAL_C_WIN32X86_)
#error _VISUAL_C_WIN32X86_ already defined
#endif

/** \brief compiler symbol for gcc compiler for Win32x86 */
/* Deviation MISRAC2012-1 */
#define _VISUAL_C_WIN32X86_ 1U

#endif /* if (!defined COMPILER_SPECIFIC_H) */
