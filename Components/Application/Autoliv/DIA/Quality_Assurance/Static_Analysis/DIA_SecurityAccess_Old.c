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
/**
 *    $Revision: 1.2.2.17 $
 *    $ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/DIA/Quality_Assurance/Static_Analysis/project.pj $
 */
/******************************************************************************

details
   This file is intended to handle Security Access services.

 ******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "Rte_DIA.h"
#include "DIA.h"
#include "Dcm.h"
/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
/**
 * \brief
 *    Constant used for size of seed key
 */
#define KU8_DIA_SIZEOF_SEED_KEY                 ((uint8)8)
/**
 * \brief
 *    Constant used for convert seconds to milliseconds
 */
#define KU8_DIA_SECOND_TO_10MS                 	((uint8)100)
/**
 * \brief
 *    Constant used for enable DCM callback for getting number of failed attempts of a certain security level.
 */
#define KU8_DIA_ENABLE_DCM_SEC_GET_NUM_ATT      STD_OFF
/**
 * \brief
 *    Constant used for enable DCM callback for setting number of failed attempts of a certain security level.
 */
#define KU8_DIA_ENABLE_DCM_SEC_SET_NUM_ATT      STD_OFF
/******************************************************************************
MODULE TYPES
 ******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
 ******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
 ******************************************************************************/
#define DIA_START_SEC_VAR_NO_INIT_8
#include "DIA_MemMap.h"

/**
 * \brief
 *      This variable is an array of 8 bytes containing the last valid generated seed.
 * \range
 *    0..KU8_MAX
 */

LOCAL uint8 dia_au8ExpectedKey[KU8_DIA_SIZEOF_SEED_KEY];

#define DIA_STOP_SEC_VAR_NO_INIT_8
#include "DIA_MemMap.h"

#define DIA_START_SEC_VAR_INIT_8
#include "DIA_MemMap.h"

/**
 * \brief
 *      This variable represents the number of failed attempts of SecurityAccess sequences for ALV (Level 31) security level.
 * \initialization
 *      KU8_ZERO (0)
 * \range
 *    0..KU8_MAX
 */

LOCAL uint8 dia_u8NumAttAlvSecLevel = KU8_ZERO;

#define DIA_STOP_SEC_VAR_INIT_8
#include "DIA_MemMap.h"
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
#define DIA_START_SEC_CODE
#include "DIA_MemMap.h"

/**
 * \brief
 *       DIA Security Access diagnostic requests initialization function.
 *       This function is used to initialize the valid seed.
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \dynamicaspectcaller
 *       DIA_Init
 * \dynamicaspectdescription
 *       DIA component initialization function.
 * \ddesignrequirement
 *       DSG_DIA_SecurityAccess_Init
 * \archrequirement
 *       ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnStartComEffective
 **/
EXPORTED void DIA_SecurityAccess_Init(void)
{
   /* Index used to cycle through the seed bytes */
   uint8 u8Idx;

   /* Initialize the valid seed to 0; it won't be considered as valid before
      being written and this variable will always be written before read */
   for(u8Idx = KU8_ZERO; u8Idx < KU8_DIA_SIZEOF_SEED_KEY; u8Idx++)
   {
      dia_au8ExpectedKey[u8Idx] = KU8_ZERO;
   }

   dia_u8NumAttAlvSecLevel = KU8_ZERO;
}

/**
 * \brief
 *       Check that the key computed by the tester tool match the expected one,
 *       the key computed during last execution of DIA_runSecurityAccessGetSeed
 *       service.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: Key;
 *       Type: const uint8*;
 *       Description: The received key used to gain Security access;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType* (uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_SecurityAccess_DcmDspSecurityAlv_CompareKey
 * \dynamicaspectdescription
 *       Check that the key computed by the tester tool match the expected one.
 * \constrains
 *       Service result can be:
 *          o RTE_E_OK;
 *          o RTE_E_SecurityAccess_DcmDspSecurityAlv_DCM_E_COMPARE_KEY_FAILED;
 * \ddesignrequirement
 *		   DSG_DIA_runSecurityAccessCompareKey
 * \archrequirement
 *       ARCH_SW_DIA_pseSecurityAccess_CompareKey
 **/
EXPORTED Std_ReturnType DIA_runSecurityAccessCompareKey (const uint8* Key, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* ErrorCode)
{
   /* Index used to cycle through the seed bytes */
   uint8 u8Idx;
   /* Flag used to stop for loop*/
   boolean bCaughtInvalidKey = KB_FALSE;
   /* By default set the service result to TRUE */
   Std_ReturnType u8Result = RTE_E_OK;

   /* Compares the 8 byte of the received key with the generated seed */
   for (u8Idx = KU8_ZERO; ((u8Idx < KU8_DIA_SIZEOF_SEED_KEY) && (KB_FALSE == bCaughtInvalidKey)); u8Idx++)
   {
      if(dia_au8ExpectedKey[u8Idx] != *(Key + u8Idx))
      {
         /* The received key index is invalid;
          * Set the appropriate NRC and return NOK */
         *ErrorCode = DCM_E_INVALIDKEY;
         u8Result = RTE_E_SecurityAccess_DcmDspSecurityAlv_DCM_E_COMPARE_KEY_FAILED;
         /*Flag is set  true to force the foor loop to stop */
         bCaughtInvalidKey = KB_TRUE;
      }
   }

   return (u8Result);
}

/**
 * \brief
 *       Generate a seed which will be sent to the tester. Based on it,
 *       the tester will compute the security access key
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: Seed;
 *       Type: uint8*;
 *       Description: Will be generated and used to compute the security access key;
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType*(uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_SecurityAccess_DcmDspSecurityAlv_GetSeed
 * \dynamicaspectdescription
 *       Generate a seed which will be sent to the tester.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runSecurityAccessGetSeed
 * \archrequirement
 *       ARCH_SW_DIA_pseSecurityAccess_GetSeed
 **/
EXPORTED Std_ReturnType DIA_runSecurityAccessGetSeed (Dcm_OpStatusType OpStatus, uint8* Seed, Dcm_NegativeResponseCodeType* ErrorCode)
{
   /* Store the 32 bit random value from TIM */
   stAbsoluteSystemTimeType stSystemTime;
   uint32 u32SystemTime;

   /* Byte extraction of the key to return */
   uint8 u8KeyByte;
   /* Index used to cycle through the seed bytes */
   uint8 u8Idx;

   /* Get the random value used to generate the seed */
   Rte_Call_pclSystemTime_ReadAbsoluteSystemTime(&stSystemTime);
   u32SystemTime = (stSystemTime.u32SystemTimeInSec * KU8_DIA_SECOND_TO_10MS) + stSystemTime.u8SystemTimeOffset;

   /* Generate the seed */
   for (u8Idx = KU8_ZERO; u8Idx < KU8_DIA_SIZEOF_SEED_KEY; u8Idx++)
   {
      /* Compute one seed byte from the random value */
      u8KeyByte = (uint8)((u32SystemTime >> (KU8_THREE * u8Idx)) & KU32_MASK_BYTE_LOW);
      /* Fill the response buffer with the byte */
      *(Seed + u8Idx) = u8KeyByte;
      /* Compute the corresponding expected key */
      dia_au8ExpectedKey[u8Idx] = (u8KeyByte ^ KU8_MAX) + KU8_ONE;
   }
   return RTE_E_OK;
}
#if(KU8_DIA_ENABLE_DCM_SEC_GET_NUM_ATT == STD_ON)
/**
 * \brief
 *       Get number of failed attempts of a certain security level.
 * \inputparam
 *       Name: SecurityLevel;
 *       Type: Dcm_SecLevelType;
 *       Description: ;
 *       Range: ;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Number of fail attemps.
 * \dynamicaspectcaller
 *       Function called in Dcm_Dsp_SecurityAccess_SendKey_SSvcH.
 * \dynamicaspectdescription
 *       Get number of failed attempts of a certain security level.
 **/
EXPORTED uint8 Rte_DcmSecGetNumAtt(Dcm_SecLevelType SecurityLevel)
{
   /* The disable of external handling(DcmDspSecurityAttemptCounterEnabled) of the security attempt counter is not
    * possible currently and shall be handled here */
   return dia_u8NumAttAlvSecLevel;
}
#endif

#if(KU8_DIA_ENABLE_DCM_SEC_SET_NUM_ATT == STD_ON)
/**
 * \brief
 *       Set number of failed attempts of a certain security level.
 * \inputparam
 *       Name: SecurityLevel;
 *       Type: Dcm_SecLevelType;
 *       Description: ;
 *       Range: ;
 * \inputparam
 *       Name: NumAtt;
 *       Type: uint8;
 *       Description: DCM error code.;
 *       Range: ;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Process status.
 * \dynamicaspectcaller
 *       Dcm_Dsp_SecurityAccess_CompareKey_TreatAttemptCounters
 *       Dcm_Dsp_SecurityAccess_CompareKey_Operation;
 * \dynamicaspectdescription
 *       Set number of failed attempts of a certain security level.
 **/
EXPORTED void Rte_DcmSecSetNumAtt(Dcm_SecLevelType SecurityLevel, uint8 NumAtt)
{
   /* The disable of external handling(DcmDspSecurityAttemptCounterEnabled) of the security attempt counter is not
    * possible currently and shall be handled here */
   dia_u8NumAttAlvSecLevel = NumAtt;
}
#endif

#define DIA_STOP_SEC_CODE
#include "DIA_MemMap.h"

/*************************************************************************
 Evolution of the component

 created by : T. DEMIREL

 $Log: DIA_SecurityAccess_Old.c  $
 Revision 1.2.2.17 2023/07/18 14:00:45CEST David Puscasu (david.puscasu) 
 Run QAC After Update DIA Traceability
 Revision 1.1.6.16 2023/07/18 14:57:23EEST David Puscasu (david.puscasu) 
 Update DIA Traceability
 Revision 1.1.6.15 2023/07/11 16:59:56EEST Andreea Suiu (andreea.suiu) 
 update comments, update 0236 write
 Revision 1.1.6.14 2023/06/22 14:07:15EEST Andreea Suiu (andreea.suiu) 
 update src files (fix findings) after review
 Revision 1.1.6.13 2023/06/12 09:16:26EEST Mihai Motoc (mihai.motoc) 
 Doxygen comments updates
 Revision 1.1.6.12 2023/04/25 09:13:02EEST Andreea Suiu (andreea.suiu) 
 Fix DIA after review
 Revision 1.1.6.11 2023/04/18 18:08:08EEST Andreea Suiu (andreea.suiu) 
 Update DIA module according to the coding rules
 Revision 1.1.6.10 2023/03/20 15:15:27EET David Puscasu (david.puscasu) 
 Add Architecture requirements on local functions
 Revision 1.1.6.9 2023/02/28 18:06:44EET Septimiu Vintila (septimiu.vintila) 
 FuSa section reverted to normal one.
 Revision 1.1.6.8 2023/02/28 17:15:02EET Septimiu Vintila (septimiu.vintila) 
 Data sections changed to FuSa data sections.
 Revision 1.1.6.7 2023/02/28 16:35:52EET Septimiu Vintila (septimiu.vintila) 
 Code sections changed to FuSa code sections.
 Revision 1.1.6.6 2023/02/24 13:58:53EET Andreea Suiu (andreea.suiu) 
 Update DIA after QAC
 Revision 1.1.6.5 2023/01/20 15:24:05EET Denis Folea (denis.folea) 
 DIA fix after review
 Revision 1.1.6.4 2022/12/22 16:28:53EET Andrei Anca (andrei.anca) 
 Dia cleanup
 Revision 1.1.6.3 2022/11/25 12:47:56EET Dan Dustinta (dan.dustinta) 
 update DCM integration code
 Revision 1.1 2019/08/20 09:18:54CEST Audrey Vache (audrey.vache) 
 Initial revision

 *************************************************************************/

/******************************************************************************
End Of File
 *****************************************************************************/
