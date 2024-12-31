/* --------{ EB Automotive C Source File }-------- */

#ifndef CRY_COMMONCONFIG_H
#define CRY_COMMONCONFIG_H

/*==================[includes]====================================================================*/

#include <Std_Types.h>

/*==================[macros]======================================================================*/



            




/* RSA key */

/* Max of RSA, EdDSA */

#if (defined CRY_RSAPUBKEY_NUM_LEN_WORDS)
#error CRY_RSAPUBKEY_NUM_LEN_WORDS is already defined
#endif
/** \brief The length, in words, which is needed for the long number representation of
 *         the longest possible stored public RSA key.
 *
 */
#define CRY_RSAPUBKEY_NUM_LEN_WORDS                           \
(                                                             \
  (Cry_LNWordType)                                            \
    (                                                         \
        Cry_LNNumberLen(384U) +  \
    (Cry_LNWordType)1UL                                       \
  )                                                           \
)

#if (defined CRY_MAX_KEY_NUM_LEN_WORDS)
#error CRY_MAX_KEY_NUM_LEN_WORDS is already defined
#endif
/** \brief The max length, in words, which is needed for the long number representation of
 *         the longest possible stored key.
 *
 */
#define CRY_MAX_KEY_NUM_LEN_WORDS                             \
(                                                             \
  (Cry_LNWordType)                                            \
    (                                                         \
        Cry_LNNumberLen(384U) +     \
    (Cry_LNWordType)1UL                                       \
  )                                                           \
)

#if (defined CRY_RSAPUBKEY_NUM_LEN_BYTES)
#error CRY_RSAPUBKEY_NUM_LEN_BYTES is already defined
#endif
/** \brief The length, in bytes, which is needed for the
 *         the longest possible stored public RSA key.
 */
#define CRY_RSAPUBKEY_NUM_LEN_BYTES 384U

#if (defined CRY_RSAPRIVKEY_NUM_LEN_WORDS)
#error CRY_RSAPRIVKEY_NUM_LEN_WORDS is already defined
#endif
/**
 * \brief The length, in words, which is needed for the long number representation of
 *         the longest possible stored private RSA key.
 *
 */
#define CRY_RSAPRIVKEY_NUM_LEN_WORDS                           \
(                                                              \
  (Cry_LNWordType)                                             \
    (                                                          \
        Cry_LNNumberLen(1U) +  \
    (Cry_LNWordType)1UL                                        \
  )                                                            \
)

#if (defined CRY_RSA_PRIV_KEY_TEMP_LEN_WORDS)
#error CRY_RSA_PRIV_KEY_TEMP_LEN_WORDS is already defined
#endif
/** \brief The length, in words, which is needed for the long number representation of
 *         the longest possible temporary private RSA key.
 */
#define CRY_RSA_PRIV_KEY_TEMP_LEN_WORDS                      \
(                                                            \
   (Cry_LNWordType)                                          \
   (                                                         \
      (CRY_RSAPRIVKEY_NUM_LEN_WORDS * (Cry_LNWordType)2UL) - \
      (Cry_LNWordType)1UL                                    \
   )                                                         \
)

#if (defined CRY_RSAPRIVKEY_NUM_LEN_BYTES)
#error CRY_RSAPRIVKEY_NUM_LEN_BYTES is already defined
#endif
/** \brief The length, in bytes, which is needed for the
 *         the longest possible stored private RSA key.
 */
#define CRY_RSAPRIVKEY_NUM_LEN_BYTES 1U



#if (defined CRY_LN_USE_BARRETT)
#error CRY_LN_USE_BARRETT is already defined
#endif
/** \brief The value of this macro indicates whether Barrett reduction is enabled
 *         in at least one CryRsaSsaV15Verify or CryRsaSsaPssVerify configuration.
 */
#define CRY_LN_USE_BARRETT STD_OFF

#if (defined CRY_RSA_PUB_KEY_TEMP_LEN_WORDS)
#error CRY_RSA_PUB_KEY_TEMP_LEN_WORDS is already defined
#endif
/** \brief The length, in words, which is needed for the long number representation of
 *         the longest possible temporary public RSA key.
 */
#define CRY_RSA_PUB_KEY_TEMP_LEN_WORDS                        \
(                                                             \
  (Cry_LNWordType)                                            \
    (                                                         \
        (CRY_RSAPUBKEY_NUM_LEN_WORDS * (Cry_LNWordType)2UL) - \
    (Cry_LNWordType)1UL                                       \
  )                                                           \
)


#if (defined CRY_LN_INTERRUPTABLE_ENABLED)
#error CRY_LN_INTERRUPTABLE_ENABLED is already defined
#endif
/** \brief Preprocessor switch to select between interruptable/non-interruptable
 **        long number library implementation variants
 **/
#define CRY_LN_INTERRUPTABLE_ENABLED                       STD_ON

#if (defined CRY_LN_PLATFORM_DOUBLE_WORD_SUPPORT)
#error CRY_LN_PLATFORM_DOUBLE_WORD_SUPPORT is already defined
#endif
/** \brief Preprocessor switch to enable/disable support for double word data type */
#define CRY_LN_PLATFORM_DOUBLE_WORD_SUPPORT                STD_OFF

#if (defined CRY_LN_MEMORY_OPTIMIZED)
#error CRY_LN_MEMORY_OPTIMIZED is already defined
#endif
/** \brief Value indicating that the long number library "memory optimized" implementation variant
 **        shall be used
 **/
#define CRY_LN_MEMORY_OPTIMIZED                            0U

#if (defined CRY_LN_SPEED_OPTIMIZED)
#error CRY_LN_SPEED_OPTIMIZED is already defined
#endif
/** \brief Value indicating that the long number library "speed optimized" implementation variant
 **        shall be used
 **/
#define CRY_LN_SPEED_OPTIMIZED                             1U

#if (defined CRY_LN_ALGORITHM_VARIANT)
#error CRY_LN_ALGORITHM_VARIANT is already defined
#endif
/** \brief Preprocessor switch to select between "memory optimized"/"speed optimized" number library
 **        implementation variants
 **/
#define CRY_LN_ALGORITHM_VARIANT                           CRY_LN_MEMORY_OPTIMIZED

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #ifndef CRY_COMMONCONFIG_H */
