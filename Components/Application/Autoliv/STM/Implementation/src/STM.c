/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version: 
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
******************************************************************************/
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.4.6 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/STM/Implementation/src/project.pj $
*/
/*!****************************************************************************

Overview of the component :
   The aim of the STM component is to handle the System Time Management of microcontroller.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"
#include "Rte_STM.h"
#include "STM_cfg.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define STM_START_SEC_VAR_INIT_32
#include "STM_MemMap.h"

/**
 * \brief
 *       Relative System time.
 * \initialization 
 *       ZERO.
 * \range
 *       NA.
 */
LOCAL uint32 stm_u32RelativeSystemTime = KU32_ZERO;

#define STM_STOP_SEC_VAR_INIT_32
#include "STM_MemMap.h"

#define STM_START_SEC_VAR_INIT_UNSPECIFIED
#include "STM_MemMap.h"

/**
 * \brief
 *       A structure with absolute system time.
 * \initialization 
 *       ZERO.
 * \range
 *       NA.
 */
LOCAL stAbsoluteSystemTimeType stm_stAbsoluteSystemTimeStruct = {KU32_ZERO, KU8_ZERO};

#define STM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "STM_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
#define STM_START_SEC_CODE
#include "STM_MemMap.h"

/**
* \brief
*     Function used to increase system time every secound.
* \return
*     This function has no return.
* \dynamicaspectcaller
*     Rte Os.
* \dynamicaspectdescription
*     Function called in OsTask_Alv_Com Rte Task via direct call.
* \ddesignrequirement
*     DSG_STM_runIncreaseSystemTime
* \archrequirement
*     ARCH_SW_STM_ptrpAsrOsServices
**/
EXPORTED void STM_runIncreaseSystemTime(void)
{

   /* If less than 1s separate two call of this function, the OffsetTime is updated*/
   if (KU8_MAX_ECU_TIME_OFFSET > stm_stAbsoluteSystemTimeStruct.u8SystemTimeOffset)
   {
      stm_stAbsoluteSystemTimeStruct.u8SystemTimeOffset++;
   }
   /* If the OffsetTime represent 1s and if the RelativeTime counter value is less
    * than the Max possible value)
    * => The Relativ and absolute time counters are updated */
   else if (KU32_MAX_ABSOLUTE_ECU_TIME > stm_stAbsoluteSystemTimeStruct.u32SystemTimeInSec)
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

#if ( KU8_STM_ENABLE_READ_ABS_SYS_TIME_API == STD_ON )
/**
* \brief
*     Function used to read Absolute System Time.
* \outputparam
*     Name: pstAbsoluteSystemTime;
*     Type: stAbsoluteSystemTimeType * (struct[uint32, uint8]);
*     Description: Pointer to struct where Absolute System time are writen;
*     Range: NA.;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     DIA module.
* \dynamicaspectdescription
*     Called in DIA_runDid4024_SWSystemTimeRead and DIA_runSecurityAccessGetSeed through Rte_Call_pclSystemTime_ReadAbsoluteSystemTime interface.
* \ddesignrequirement
*     DSG_STM_runReadAbsoluteSystemTime
* \archrequirement
*     ARCH_SW_STM_pseSystemTime_ReadAbsoluteSystemTime
**/
EXPORTED void STM_runReadAbsoluteSystemTime(stAbsoluteSystemTimeType * pstAbsoluteSystemTime)
{
   pstAbsoluteSystemTime->u32SystemTimeInSec = stm_stAbsoluteSystemTimeStruct.u32SystemTimeInSec;
   pstAbsoluteSystemTime->u8SystemTimeOffset = stm_stAbsoluteSystemTimeStruct.u8SystemTimeOffset;
}
#endif

#if (KU8_STM_ENABLE_READ_REL_SYS_TIME_API == STD_ON)
/**
* \brief
*     Function used to read Relative System Time.
* \outputparam
*     Name: pu32RelativeSystemTime;
*     Type: u32RelativeSystemTimeType *;
*     Description: Pointer to struct where Relative System time are writen;
*     Range: NA.;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     This function is not called.
* \dynamicaspectdescription
*     NA.
**/
EXPORTED void STM_runReadRelativeSystemTime(u32RelativeSystemTimeType * pu32RelativeSystemTime)
{
   *pu32RelativeSystemTime = stm_u32RelativeSystemTime;
}
#endif

#if (KU8_STM_ENABLE_WRITE_REL_SYS_TIME_API == STD_ON)
/**
* \brief
*     Function used to write Absolute System Time.
* \inputparam
*     Name: stAbsoluteSystemTime;
*     Type: const stAbsoluteSystemTimeType * (struct[uint32, uint8]);
*     Description: pointer to struct from which Absolute System time are read;
*     Range: NA.;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     This function is not called.
* \dynamicaspectdescription
*     NA.
**/
EXPORTED void STM_runWriteAbsoluteSystemTime(const stAbsoluteSystemTimeType * stAbsoluteSystemTime)
{
   stm_stAbsoluteSystemTimeStruct.u32SystemTimeInSec = stAbsoluteSystemTime->u32SystemTimeInSec;
   stm_stAbsoluteSystemTimeStruct.u8SystemTimeOffset = stAbsoluteSystemTime->u8SystemTimeOffset;
}
#endif

#if (KU8_STM_ENABLE_WRITE_ABS_SYS_TIME_API == STD_ON)
/**
* \brief
*     Function used to write Relative System Time.
* \inputparam
*     Name: u32RelativeSystemTime;
*     Type: u32RelativeSystemTimeType;
*     Description: variable from which Relative System time are read;
*     Range: NA.;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     This function is not called.
* \dynamicaspectdescription
*     NA.
**/
EXPORTED void STM_runWriteRelativeSystemTime(u32RelativeSystemTimeType u32RelativeSystemTime)
{
   stm_u32RelativeSystemTime = u32RelativeSystemTime;
}
#endif

#define STM_STOP_SEC_CODE
#include "STM_MemMap.h"

/******************************************************************************
End Of File
******************************************************************************/
