/************************************************************************************/
/*! \file           T1_targetSpecifics.h
 *
 *  \brief          T1-TARGET-SW header specific to ARM v7-M architecture
 *
 *  \par Visibility
 *                  External
 *
 *  \author GLIWA
 *
 *  \version 3.5.1.0 r67888
 *
 *  \copyright GLIWA embedded systems GmbH & Co. KG, Weilheim i.OB. All rights reserved
 ************************************************************************************/

#ifndef T1_TARGETSPECIFICS_H_
#define T1_TARGETSPECIFICS_H_ ( 1 )

/*----------------------------------------------------------------------------------*/
/*--- header includes --------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#if defined __ICCARM__      /* IAR */
#    include <intrinsics.h> /* Enable IAR intrisics */
#elif defined __ghs__
#    include <arm_ghs.h>       /* Enable Green Hills intrisics */
#elif !defined __ARMCC_VERSION /* not Keil, therefore GCC */
#    include "T1_gccSectionMacros.h"
#endif /* compiler */

/*----------------------------------------------------------------------------------*/
/*--- type definitions -------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

typedef unsigned long T1_icuRegister_t;

/*----------------------------------------------------------------------------------*/
/*--- macros and inline functions --------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#if defined T1_CHECKER_ARTEFACT
extern T1_icuRegister_t T1_primask;
#    define T1_GET_PRIMASK( )       ( T1_primask )
#    define T1_DISABLE_INTRRPTS_( ) ( (void)0 )
#    define T1_ENABLE_INTRRPTS_( )  ( (void)0 )
#    define T1_TARGET_DSYNC( )      ( (void)0 )
/* This is required before declaring T1_DebugMonitorHandler, below */
#    define T1_CODE_FAST( t_ )      t_
#elif defined __ARMCC_VERSION /* Keil */
#    define T1_GET_PRIMASK( )                                                        \
        ( {                                                                          \
            T1_icuRegister_t primask_;                                               \
            __asm( "MRS %0, PRIMASK" : "=r"( primask_ ) );                           \
            primask_;                                                                \
        } )
#    define T1_DISABLE_INTRRPTS_( ) __asm( " CPSID I" : )
#    define T1_ENABLE_INTRRPTS_( )  __asm( " CPSIE I" : )
#    define T1_TARGET_DSYNC( )      __asm( " DMB" : )
/* This is required before declaring T1_DebugMonitorHandler, below */
#    define T1_CODE_FAST( t_ )      t_
#elif defined __ICCARM__ /* IAR */
#    define T1_GET_PRIMASK( )       __get_PRIMASK( )
#    define T1_DISABLE_INTRRPTS_( ) __disable_interrupt( )
#    define T1_ENABLE_INTRRPTS_( )  __enable_interrupt( )
#    define T1_TARGET_DSYNC( )      __DMB( )
/* This is required before declaring T1_DebugMonitorHandler, below */
#    define T1_CODE_FAST( t_ )      t_
#elif defined __ghs__
#    define T1_GET_PRIMASK( )  ( (T1_icuRegister_t)__MRS( __PRIMASK ) )
#    define T1_TARGET_DSYNC( ) __DMB( )
#    if defined __GNUC__
#        define T1_DISABLE_INTRRPTS_( ) __asm volatile( " CPSID I" : )
#        define T1_ENABLE_INTRRPTS_( )  __asm volatile( " CPSIE I" : )
#    else /* ! defined __GNUC__ */
/* The Green Hills DI/EI intrinsics also affect FAULTMASK. */
#        define T1_DISABLE_INTRRPTS_( ) __MSR( __PRIMASK, 1uL )
#        define T1_ENABLE_INTRRPTS_( )  __MSR( __PRIMASK, 0uL )
#    endif /* defined __GNUC__ */
/* Align for FLASH lines. */
#    define T1_CODE_FAST( t_ ) __farcall t_ __attribute__( ( aligned( 16 ) ) )
#    define T1_FAR_CODE( t_ )  __farcall t_ __attribute__( ( aligned( 8 ) ) )
#    define T1_NEAR_CODE_FAST  __attribute__( ( aligned( 16 ) ) )
#    define T1_CODE            __attribute__( ( aligned( 8 ) ) )
#elif defined __GNUC__
#    define T1_GET_PRIMASK( )                                                        \
        ( {                                                                          \
            T1_icuRegister_t primask_;                                               \
            __asm volatile( "MRS %0, PRIMASK" : "=r"( primask_ ) );                  \
            primask_;                                                                \
        } )
#    define T1_DISABLE_INTRRPTS_( ) __asm volatile( " CPSID I" : )
#    define T1_ENABLE_INTRRPTS_( )  __asm volatile( " CPSIE I" : )
#    define T1_TARGET_DSYNC( )      __asm volatile( " DMB" : )
#    define T1_NEAR_CODE_FAST                                                        \
        __attribute__( ( section( ".T1_codeFast" ), aligned( 16 ) ) )
/* Redefine macro from T1_gccSectionMacros.h to align for FLASH lines. */
#    undef T1_CODE_FAST
#    define T1_CODE_FAST( t_ )                                                       \
        t_ __attribute__( ( section( ".T1_codeFast" ), aligned( 16 ), long_call ) )
/* Redefine macros from T1_gccSectionMacros.h to partially align for FLASH lines. */
#    undef T1_FAR_CODE
#    define T1_FAR_CODE( t_ )                                                        \
        t_ __attribute__( ( section( ".T1_code" ), aligned( 8 ), long_call ) )
#    undef T1_CODE
#    define T1_CODE __attribute__( ( section( ".T1_code" ), aligned( 8 ) ) )
#    define T1_INSERT32( dst_, ins_, offst_, len_ )                                  \
        ( {                                                                          \
            T1_uint32_t rslt = ( dst_ );                                             \
            __asm( "BFI %0, %2, %3, %4"                                              \
                   : "=r"( rslt )                                                    \
                   : "0"( rslt ), "r"( ins_ ), "i"( offst_ ), "i"( len_ ) );         \
            rslt;                                                                    \
        } )
#    define T1_ROTL32( x_, y_ )                                                      \
        ( {                                                                          \
            T1_uint32_t rslt;                                                        \
            __asm( "ROR %0, %1, %2"                                                  \
                   : "=r"( rslt )                                                    \
                   : "r"( x_ ), "i"( 32 - ( y_ ) ) );                                \
            rslt;                                                                    \
        } )
#    define T1_ALTERNATIVE_IS_FLEX_HANDLER ( 1 )
#else
/* Keil and IAR compilers do not support code alignment or far calls */
#endif /* compiler */

/* ARM Cortex-M uses PRIMASK */
#define T1_IRQ_MASK                  ( 0x1uL )

#define T1_INTERRUPTS_ENABLED( r_ )  ( 0uL == ( T1_IRQ_MASK & ( r_ ) ) )

#define T1_INTERRUPTS_ARE_ENABLED( ) T1_INTERRUPTS_ENABLED( T1_GET_PRIMASK( ) )

#define T1_DISABLE_INTERRUPTS( )                                                     \
    do                                                                               \
    {                                                                                \
        T1_DISABLE_INTRRPTS_( );                                                     \
        T1_TARGET_DSYNC( );                                                          \
    }                                                                                \
    while( 0 )

#define T1_ENABLE_INTERRUPTS( )                                                      \
    do                                                                               \
    {                                                                                \
        T1_TARGET_DSYNC( );                                                          \
        T1_ENABLE_INTRRPTS_( );                                                      \
    }                                                                                \
    while( 0 )

#define T1_INLINE static inline

#if defined __ghs__
#    define T1_NOINLINE __noinline
#elif !defined __ICCARM__ /* not IAR */
#    define T1_NOINLINE __attribute__( ( noinline ) )
#endif

#define T1_CPU32BIT        ( 1 )

#define T1_FLEX_SINGLESTEP ( 1 )

#define T1_ARM7M           ( 1 )

#if !defined __ICCARM__ /* not IAR */
#    define T1_UNUSED( varDecl_ ) varDecl_ __attribute__( ( unused ) )
#endif

#define T1_ALIGN_VAR( bytes_ ) __attribute__( ( aligned( bytes_ ) ) )

#if 1 < T1_NOF_CORES && !defined T1_GetCoreIdOffset
#    define T1_GetCoreIdOffset( ) ( TODO_GetCoreId( ) )
#endif /* 1 < T1_NOF_CORES && ! defined T1_GetCoreIdOffset */

#define T1_P_HFSR             ( (volatile T1_uint32_t *)0xE000ED2CuL )
#define T1_HFSR_DEBUGEVT_MASK ( 0x80000000uL )

/*----------------------------------------------------------------------------------*/
/*--- declarations of exception handlers -------------------------------------------*/
/*----------------------------------------------------------------------------------*/

/* This declaration is required to allow C code to configure exception vectoring. */
T1_CODE_FAST( void ) T1_DebugMonitorHandler( void );

#endif /* T1_TARGETSPECIFICS_H_ */
