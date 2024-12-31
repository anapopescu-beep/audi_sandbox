/* --------{ EB Automotive C Source File }-------- */



#ifndef CRY_SHA_COMMONCONFIG_H
#define CRY_SHA_COMMONCONFIG_H

/*==[Includes]================================================================*/

#include <Std_Types.h>

/*==[Macros]==================================================================*/


#if (defined CRY_SHA_BLOCK_LEN_WORDS)
#error CRY_SHA_BLOCK_LEN_WORDS is already defined
#endif
/** \brief Number of blocks used in message schedule */
#define CRY_SHA_BLOCK_LEN_WORDS               64U

#if (defined CRY_SHA_STATE_WORDS)
#error CRY_SHA_STATE_WORDS is already defined
#endif
/** \brief   Number of states.
 **/
#define CRY_SHA_STATE_WORDS                   8U

#if (defined CRY_SHAONEANDTWO_INTERRUPTABLE)
#error CRY_SHAONEANDTWO_INTERRUPTABLE is already defined
#endif
/** \brief Value indicating that the SHA-1/SHA-2 "INTERRUPTABLE" implementation shall be used */
#define CRY_SHAONEANDTWO_INTERRUPTABLE        0U

#if (defined CRY_SHAONEANDTWO_FAST)
#error CRY_SHAONEANDTWO_FAST is already defined
#endif
/** \brief Value indicating that the SHA-1/SHA-2 "FAST" implementation shall be used */
#define CRY_SHAONEANDTWO_FAST                 1U

#if (defined CRY_SHAONEANDTWO_VARIANT)
#error CRY_SHAONEANDTWO_VARIANT is already defined
#endif
/* !LINKSTO CS_SECURE_CRY_0192,1 */
/** \brief Switch for selecting between SHA-1/SHA-2 hashing "INTERRUPTABLE" or "FAST"
 **        implementation variant
 **/
#define CRY_SHAONEANDTWO_VARIANT              CRY_SHAONEANDTWO_INTERRUPTABLE

/*==[Types]===================================================================*/


/** \brief Type of functions to initialize the states
 **
 **/
typedef P2FUNC(void, CRY_CODE, Cry_SHAInitFctType)
(
   void
);

/** \brief Type of compress functions
 **
 ** \var uint8::Data
 **  \brief Input data to be compressed
 **
 **/
typedef P2FUNC(boolean, CRY_CODE, Cry_SHACompressFctType)
(
   P2CONST(uint8, AUTOMATIC, CRY_APPL_DATA) Data
);



/* !LINKSTO EB_CRY_0017,1 */
/** \brief Configuration type for SHA
 **
 ** \var Cry_SHAConfigType::AlgorithmIdLength
 **  \brief The length of the algorithm identifier for the configured algorithm.
 **
 ** \var Cry_SHAConfigType::HashLength
 **  \brief The length of the hash digest.
 **
 ** \var Cry_SHAConfigType::AlgorithmId
 **  \brief The algorithm identifier for the configured algorithm.
 **
 ** \var Cry_SHAConfigType::IterationsPerMain
 **  \brief Indicates the number iteration performed per main function call during the compression phase.
 **
 ** \var Cry_SHAConfigType::SupportRestart
 **  \brief Indicates whether restarting of the algorithm feature is enabled or not.
 **
 **/
typedef struct
{
   uint32                             AlgorithmIdLength;
   uint32                             HashLength;
   P2CONST(uint8, TYPEDEF, CRY_CONST) AlgorithmId;
   uint16                             IterationsPerMain;
   boolean                            SupportRestart;
}
Cry_SHAConfigType;
/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

#endif
