/**
 * \file
 *
 * \brief AUTOSAR Cal
 *
 * This file contains the implementation of the AUTOSAR
 * module Cal.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CAL_TYPES_CFG_H
#define CAL_TYPES_CFG_H


/*==[Includes]================================================================*/

#include <Std_Types.h>


/*==[Macros]==================================================================*/

/** \brief The length, in elements of type ::Cal_AlignType, of an array which
 *         can hold as many bytes as given as input.
 */
#define CAL_LEN_IN_ALIGN_TYPE(ByteLength)      \
(                                              \
  (uint32)                                     \
  (                                            \
    (uint32)                                   \
    (                                          \
      (uint32)                                 \
      (                                        \
        (uint32)(ByteLength) - (uint32)1UL     \
      ) /                                      \
      (uint32)sizeof(Cal_AlignType)            \
    ) +                                        \
    (uint32)1UL                                \
  )                                            \
)


  






/** \brief CAL_SYM_KEY_MAX_SIZE*sizeof(Cal_AlignType) defines the maximal size in bytes of all
 *         configured symmetrical keys
 */
#define CAL_SYM_KEY_MAX_SIZE CAL_LEN_IN_ALIGN_TYPE(16UL)









/** \brief CAL_ASYM_PUB_KEY_MAX_SIZE*sizeof(Cal_AlignType) defines the maximal size in bytes of all
 *         configured asymmetrical public keys
 */
#define CAL_ASYM_PUB_KEY_MAX_SIZE CAL_LEN_IN_ALIGN_TYPE(1UL)






/** \brief CAL_KEY_EX_BASE_MAX_SIZE*sizeof(Cal_AlignType) defines the maximal size in bytes of all
 *         configured key exchange base types
 */
#define CAL_KEY_EX_BASE_MAX_SIZE CAL_LEN_IN_ALIGN_TYPE(1UL)






/** \brief CAL_KEY_EX_PRIV_MAX_SIZE*sizeof(Cal_AlignType) defines the maximal size in bytes of all
 *         configured key exchange private types
 */
#define CAL_KEY_EX_PRIV_MAX_SIZE CAL_LEN_IN_ALIGN_TYPE(1UL)



/*==[Types]===================================================================*/

/* !LINKSTO CAL0743, 1
 */
/** \brief An integer type with maximal alignment restrictions
 *
 * This is an integer type which has the maximal alignment restrictions. That
 * means that a pointer to a variable to this type can be cast to a pointer
 * to any other integer type without risking alignment problems.
 */
typedef uint32 Cal_AlignType;


/*==[Constants with external linkage]=========================================*/



/*==[Variables with external linkage]=========================================*/



/*==[Declaration of functions with external linkage]==========================*/

#endif /* #ifndef CAL_TYPES_CFG_H */

