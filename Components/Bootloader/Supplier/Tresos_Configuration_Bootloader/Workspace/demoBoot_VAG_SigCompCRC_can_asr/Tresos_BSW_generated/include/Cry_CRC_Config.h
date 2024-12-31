/* --------{ EB Automotive C Source File }-------- */

#ifndef CRY_CRC_CONFIG_H
#define CRY_CRC_CONFIG_H

/*==================[includes]====================================================================*/

#include <Std_Types.h>



/*==================[macros]======================================================================*/

#if (defined CRY_CRC_BUFTYP_SIZE)
#error CRY_CRC_BUFTYP_SIZE is already defined
#endif
#define  CRY_CRC_BUFTYP_SIZE  256U
#if (defined CRY_CRC_ENABLED)
#error CRY_CRC_ENABLED is already defined
#endif
#define CRY_CRC_ENABLED FALSE

/** \brief parameter configuration used to set the variant the way it's calculated LUT
 **/
#if (defined CRY_CRC_SPEED_OPTIMIZED)
#error CRY_CRC_SPEED_OPTIMIZED is already defined
#endif
#define CRY_CRC_SPEED_OPTIMIZED STD_OFF

#if (CRY_CRC_ENABLED == TRUE)

#if (defined CRY_CRC_BUFLEN)
#error CRY_CRC_BUFLEN is already defined
#endif

#define  CRY_CRC_BUFLEN  0U     /* == sizeof(CRY_CRC_BUFTYP) */

/*==================[type definitions]============================================================*/

/*---[enum]---------------------------------------------------------------------------------------*/

/** \brief  Type of the configured order of CRC polynom.
 **/
typedef enum
{
  CRY_CRC_8  = 1,
  CRY_CRC_16 = 2,
  CRY_CRC_32 = 4
}
Cry_CRC_Type;

/*---[struct]-------------------------------------------------------------------------------------*/

/** \brief  Configuration type for representing a configured CRC.
 **/
typedef struct
{
#if (CRY_CRC_SPEED_OPTIMIZED == STD_ON)
  uint32       nodeIndex;
#endif
  Cry_CRC_Type typeCrc;
  uint32       polyCrc;
  uint32       mbpcCrc;
  uint32       iputXor;
  uint32       oputXor;
  boolean      iputReflect;
  boolean      oputReflect;
}
Cry_CRC_ConfigType;

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/


/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CRY_CRC_ENABLED == TRUE) */

#endif /* #ifndef CRY_CRC_CONFIG_H */
