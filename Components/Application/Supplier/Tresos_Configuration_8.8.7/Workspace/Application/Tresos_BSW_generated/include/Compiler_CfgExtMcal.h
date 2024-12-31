#ifndef COMPILER_CFGEXTMCAL_H
#define COMPILER_CFGEXTMCAL_H
/**
 * \file
 *
 * \brief AUTOSAR Compiler
 *
 * This file contains the implementation of the AUTOSAR
 * module Compiler.
 *
 * \version 1.0.12
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2017 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* specific compiler symbol for MCAL 
 * currently supported: */

#if (defined _DIABDATA_C_CORTEXM_)
#if (defined _DIABDATA_C_S32K1XX_) /* to prevent double definition */
#error _DIABDATA_C_S32K1XX_ already defined
#endif /* if (defined _DIABDATA_C_S32K1XX_) */
/** \brief compiler symbol for Windriver Diab compiler for S32K1XX */
#define _DIABDATA_C_S32K1XX_ 1U
#endif

#if (defined _GREENHILLS_C_CORTEXM_)
#if (defined _GREENHILLS_C_S32K1XX_) /* to prevent double definition */
#error _GREENHILLS_C_S32K1XX_ already defined
#endif /* if (defined _GREENHILLS_C_S32K1XX_) */
/** \brief compiler symbol for Greenhills compiler for S32K1XX */
#define _GREENHILLS_C_S32K1XX_ 1U
#endif

#if (defined _HITECH_C_CORTEXM_)
#if (defined _HITECH_C_S32K1XX_) /* to prevent double definition */
#error _HITECH_C_S32K1XX_ already defined
#endif /* if (defined _HITECH_C_S32K1XX_) */
/** \brief compiler symbol for HighTech gnu compiler for S32K1XX */
#define _HITECH_C_S32K1XX_ 1U
#endif

#if (defined _COSMIC_C_CORTEXM_)
#if (defined _COSMIC_C_S32K1XX_) /* to prevent double definition */
#error _COSMIC_C_S32K1XX_ already defined
#endif /* if (defined _COSMIC_C_S32K1XX_) */
/** \brief compiler symbol for Cosmic compiler for S32K1XX */
#define _COSMIC_C_S32K1XX_ 1U
#endif

#if (defined _CODEWARRIOR_C_CORTEXM_)
#if (defined _CODEWARRIOR_C_S32K1XX_) /* to prevent double definition */
#error _CODEWARRIOR_C_S32K1XX_ already defined
#endif /* if (defined _CODEWARRIOR_C_S32K1XX_) */
/** \brief compiler symbol for CodeWarrior compiler for S32K1XX */
#define _CODEWARRIOR_C_S32K1XX_ 1U
#endif

#if (defined _LINARO_C_CORTEXM_)
#if (defined _LINARO_C_S32K1XX_) /* to prevent double definition */
#error _LINARO_C_S32K1XX_ already defined
#endif /* if (defined _LINARO_C_S32K1XX_) */
/** \brief compiler symbol for Linaro gnu compiler for S32K1XX */
#define _LINARO_C_S32K1XX_ 1U
#endif

#if (defined _IAR_C_CORTEXM_)
#if (defined _IAR_C_S32K1XX_) /* to prevent double definition */
#error _IAR_C_S32K1XX_ already defined
#endif /* if (defined _IAR_C_S32K1XX_) */
/** \brief compiler symbol for IAR compiler for S32K1XX */
#define _IAR_C_S32K1XX_ 1U
#endif

#if (defined _ARM_DS5_C_CORTEXM_)
#if (defined _ARM_DS5_C_S32K1XX_) /* to prevent double definition */
#error _ARM_DS5_C_S32K1XX_ already defined
#endif /* if (defined _ARM_DS5_C_S32K1XX_) */
/** \brief compiler symbol for ARM DS5 compiler for S32K1XX */
#define _ARM_DS5_C_S32K1XX_ 1U
#endif

/** \brief interrupt function */
#if (defined INTERRUPT_FUNC)
#error INTERRUPT_FUNC already defined
#endif

#ifdef _DIABDATA_C_S32K1XX_
#define INTERRUPT_FUNC __interrupt__
#endif /* #ifdef _DIABDATA_C_S32K1XX_ */

#ifdef _GREENHILLS_C_S32K1XX_
#define INTERRUPT_FUNC __interrupt
#endif /* #ifdef _GREENHILLS_C_S32K1XX_ */

#ifdef _HITECH_C_S32K1XX_
#define INTERRUPT_FUNC __attribute__((interrupt));
#endif /* #ifdef _HITECH_C_S32K1XX_ */

#ifdef _COSMIC_C_S32K1XX_
#define INTERRUPT_FUNC @interrupt
#endif /* #ifdef _COSMIC_C_S32K1XX_ */

#ifdef _CODEWARRIOR_C_S32K1XX_
#define INTERRUPT_FUNC __declspec(interrupt nowarn)
#endif /* #ifdef _CODEWARRIOR_C_S32K1XX_ */

#ifdef _LINARO_C_S32K1XX_
#define inline          __inline
#define INTERRUPT_FUNC  
#endif /* #ifdef _LINARO_C_S32K1XX_ */

#ifdef _IAR_C_S32K1XX_
#define INTERRUPT_FUNC
#endif /* #ifdef _IAR_C_S32K1XX_ */

#ifdef _ARM_DS5_C_S32K1XX_
#define INTERRUPT_FUNC
#endif /* #ifdef _ARM_DS5_C_S32K1XX_ */

#endif /* #ifndef COMPILER_CFGEXTMCAL_H */
/*==================[end of file]============================================*/
