/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

COMPONENT STM

Current revision: $Revision: 1.2.1.2 $
Checked in:       $Date: 2022/10/05 10:39:45CEST $

**************************************************************************

Overview of the component :
Part of the package STM

------------------------------------------------------------------------

Design document:

*************************************************************************/

/*************************************************************************
Packages inclusion
*************************************************************************/
#include "common.h"
#include "Rte_STM.h"
/*************************************************************************
Intra-package inclusions
*************************************************************************/
#include "STM.h"
/*************************************************************************
Private inclusion
*************************************************************************/

/*************************************************************************
Declaration of constants
*************************************************************************/

/*************************************************************************
Declaration of macros
*************************************************************************/

/*************************************************************************
Declaration of types
*************************************************************************/

/*************************************************************************
LOCAL variables declaration
*************************************************************************/
#define STM_START_SEC_VAR_INIT_32
#include "STM_MemMap.h"

/**
 * \brief
 *       Relative System time.
 */
LOCAL uint32 stm_u32RelativeSystemTime = KU32_ZERO;

#define STM_STOP_SEC_VAR_INIT_32
#include "STM_MemMap.h"

#define STM_START_SEC_VAR_INIT_UNSPECIFIED
#include "STM_MemMap.h"

/**
 * \brief
 *       A structure with absolute system time.
 */
LOCAL stAbsoluteSystemTimeType stm_stAbsoluteSystemTimeStruct = { KU32_ZERO, KU8_ZERO};

#define STM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "STM_MemMap.h"

/*************************************************************************
EXPORTED functions declaration
*************************************************************************/
#define STM_START_SEC_CODE
#include "STM_MemMap.h"

/**
* \brief
*     Function used to increase system time every secound.
* \param
*     void
* \return
*     void
* \remark
*     None
**/
EXPORTED void STM_runIncreaseSystemTime(void)
{

   /* If less than 1s separate two call of this function, the OffsetTime is updated*/
   if ( KU8_MAX_ECU_TIME_OFFSET > stm_stAbsoluteSystemTimeStruct.u8SystemTimeOffset )
   {
      stm_stAbsoluteSystemTimeStruct.u8SystemTimeOffset++;
   }
   /* If the OffsetTime represent 1s and if the RelativeTime counter value is less
    * than the Max possible value)
    * => The Relativ and absolute time counters are updated */
   else if ( KU32_MAX_ABSOLUTE_ECU_TIME > stm_stAbsoluteSystemTimeStruct.u32SystemTimeInSec )
   {
      stm_stAbsoluteSystemTimeStruct.u32SystemTimeInSec++;
      stm_u32RelativeSystemTime++;

      /* Restart the offset timer */
      stm_stAbsoluteSystemTimeStruct.u8SystemTimeOffset = KU8_ZERO;
   }
   else
   {
      /* Do nothing */
      /* Counter have the max value */
   }
}

/**
* \brief
*     Function used to read Absolute System Time.
* \param
*     stAbsoluteSystemTimeType * pstAbsoluteSystemTime - pointer to struct
*     where Absolute System time are writen;
* \return
*     void
* \remark
*     None
**/
EXPORTED void STM_runReadAbsoluteSystemTime(stAbsoluteSystemTimeType * pstAbsoluteSystemTime)
{
   pstAbsoluteSystemTime->u32SystemTimeInSec = stm_stAbsoluteSystemTimeStruct.u32SystemTimeInSec;
   pstAbsoluteSystemTime->u8SystemTimeOffset = stm_stAbsoluteSystemTimeStruct.u8SystemTimeOffset;
}

/**
* \brief
*     Function used to read Relative System Time.
* \param
*     u32RelativeSystemTimeType * pu32RelativeSystemTime - pointer to struct
*     where Relative System time are writen;
* \return
*     void
* \remark
*     None
**/
EXPORTED void STM_runReadRelativeSystemTime(u32RelativeSystemTimeType * pu32RelativeSystemTime)
{
   *pu32RelativeSystemTime = stm_u32RelativeSystemTime;
}

/**
* \brief
*     Function used to write Absolute System Time.
* \param
*     const stAbsoluteSystemTimeType * stAbsoluteSystemTime - pointer to struct from
*     which Absolute System time are readed;
* \return
*     void
* \remark
*     None
**/
EXPORTED void STM_runWriteAbsoluteSystemTime(const stAbsoluteSystemTimeType * stAbsoluteSystemTime)
{
   stm_stAbsoluteSystemTimeStruct.u32SystemTimeInSec = stAbsoluteSystemTime->u32SystemTimeInSec;
   stm_stAbsoluteSystemTimeStruct.u8SystemTimeOffset = stAbsoluteSystemTime->u8SystemTimeOffset;
}

/**
* \brief
*     Function used to write Relative System Time.
* \param
*     u32RelativeSystemTimeType u32RelativeSystemTime - variable from
*     which Relative System time are readed;
* \return
*     void
* \remark
*     None
**/
EXPORTED void STM_runWriteRelativeSystemTime(u32RelativeSystemTimeType u32RelativeSystemTime)
{
   stm_u32RelativeSystemTime = u32RelativeSystemTime;
}

#define STM_STOP_SEC_CODE
#include "STM_MemMap.h"

/******************************************************************************
End Of File
******************************************************************************/