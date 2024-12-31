/*********************************************************************************/
/*                                                                               */
/*                                  CAN Stack                                    */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                                APP                                            */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file APP_Prg.c                       */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 3.6.255 OSC_BOOT                */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*********************************************************************************/
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*********************************************************************************/

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 16.7 (advisory)
 *   A pointer parameter in a function prototype should be declared as pointer to const
 *   if the pointer is not used to modify the addressed object.
 *
 *   Reason:
 *   The MISRA rule is not violated. This pointer will be used once the function is completed by customer.
 */


/******************************** FILE INCLUSION *********************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Header Files: EB                                                            */
#include "EB_Prj.h"
#include "board.h"
/*                                                                               */
/*********************************************************************************/

/****************************** PUBLIC DEFINITIONS *******************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */

/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */

/*-------------------------------------------------------------------------------*/
/* - Public Callback Prototypes                                                  */

/*                                                                               */
/*********************************************************************************/

/***************************** PRIVATE DEFINITIONS *******************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Private Constants                                                           */

/*-------------------------------------------------------------------------------*/
/* - Private Types                                                               */

/*-------------------------------------------------------------------------------*/
/* - Private Variables                                                           */
#define PROG_REPROG_FLAG_START_SEC_VAR_NO_INIT_8
#include <MemMap.h>
/* RAM structure of NVM mirror */
tNoIntShareVar stNoIntShareVar;
#define PROG_REPROG_FLAG_STOP_SEC_VAR_NO_INIT_8
#include <MemMap.h>

#define PROG_START_SEC_VAR_RAM_NO_INIT
#include <MemMap.h>
/* RAM structure of NVM mirror */
tNVMBootloaderData stNVMBootloaderData;
#define PROG_STOP_SEC_VAR_RAM_NO_INIT
#include <MemMap.h>

#define NUMBER_OF_BYTES 1U

/* Integration to test the response after the reset */
NCS_PRI_VAR u8 m_ubProgFirstCall;
NCS_PRI_VAR u8 m_aubUdsData[7];

/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */

/*                                                                               */
/*********************************************************************************/

/******************************** IMPLEMENTATION *********************************/
/*                                                                               */

/*-------------------------------------------------------------------------------*/
/* - Public Functions                                                            */

/*-------------------------------------------------------------------------------*/
/* - Public Functions                                                            */

/*--------------------------{APP_InterruptEnable}--------------------------------------*/
void APP_InterruptEnable (u8 ebStatus)
{


    /* Implement here a treatment for a critical section exit. */
    /* Interrupts must be resumed. */
    BoardEnableInterrupts();
    OSC_PARAM_UNUSED(ebStatus);
}
/*--------------------------{end APP_InterruptEnable}----------------------------------*/

/*--------------------------{APP_InterruptDisable}--------------------------------------*/
u8 APP_InterruptDisable (void)
{

    /* Implement here a treatment for a critical section entry. */
    /* Interrupts must be suspended. */
    BoardDisableInterrupts();
    return (0U);
}
/*--------------------------{end APP_InterruptDisable}----------------------------------*/


/*--------------------------{APP_Init}--------------------------------------*/
void APP_Init (void)
{
    u16 i;
    u16 j;
    m_ubProgFirstCall = TRUE;
  
    if (stNVMBootloaderData.ulInitPattern != NVM_INIT_PATTERN)
    {
        for (i = 0; i < PROG_BLOCK_NBR; i++)
        {
            /* Init counter to 0 */
            stNVMBootloaderData.stNVMBlockData[i].uwProgCounter = 0x0000U;
            /* Init block status info to block invalid */
            stNVMBootloaderData.stNVMBlockData[i].ubStatusInformation = PROG_INFO_REPROG_STATE_CHECK_NOK;
            for (j = 0; j < PROG_FINGERPRINT_LENGTH; j++)
            {
                stNVMBootloaderData.stNVMBlockData[i].aubFingerPrintInfo[j] = 0xFFU;
            }
        }

        /* Init As retry count to 0 */
        stNVMBootloaderData.stNVMEcuData.ubAsRetryCnt = 0U;

        for (j = 0; j < SA_RANDOM_NUMBER_LENGTH; j++)
        {
            stNVMBootloaderData.stNVMEcuData.aubRandom[j] = 0x00U;
        }

        stNVMBootloaderData.ulInitPattern = NVM_INIT_PATTERN;
    }
}
/*--------------------------{end APP_Init}----------------------------------*/





/*--------------------------{APP_Manage}--------------------------------------*/
void APP_Manage (void)
{

}
/*--------------------------{end APP_Manage}----------------------------------*/


/*--------------------------{CAN_BusOffInd}--------------------------------------*/
void CAN_BusOffInd (void)
{
}
/*--------------------------{end CAN_BusOffInd}----------------------------------*/


/*--------------------------{UDS_P2AboutToExpireInd}--------------------------------------*/
void UDS_P2AboutToExpireInd(void)
{

}
/*--------------------------{end UDS_P2AboutToExpireInd}----------------------------------*/

/*--------------------------{APP_ProgSession}--------------------------------------*/
/* Deviation MISRA-1 */
tUdsStatus APP_ProgSession(u16 *puwLen, u8 *aubUdsData)
{
    OSC_PARAM_UNUSED(aubUdsData);

    BlPduR_StoreConnectionInfo();

    stNoIntShareVar.ulProgSig = 0x55AA55AAU;

    stNoIntShareVar.ubResetCause = PROG_RESET_CAUSE_DSC02;
    /* Check SuppressPositiveResponseBit */
    if (0x80U == (aubUdsData[1] & 0x80U))
    {
        /* store the reset request */
      stNoIntShareVar.ubResponseRequired = PROG_FALSE;
    }
    else
    {
      stNoIntShareVar.ubResponseRequired = PROG_TRUE;
      /* Reset the board without response */
    }

    BoardPerformReset(PLATFORMS_SW_RESET);

    /* Dummy check to avoid warning */
    if(stNoIntShareVar.ulProgSig == 0x55AA55AAU)
    {
        *puwLen = 2U;
    }

    /* No return since reset is triggered */
    return UDS_ACK;
}
/*--------------------------{end APP_ProgSession}----------------------------------*/

/*--------------------------{APP_CommunicationControl}--------------------------------------*/
/* Deviation MISRA-1 */
 tUdsStatus APP_CommunicationControl(u16 *puwLen, u8 *aubUdsData)
 {
    *puwLen = 2U;
     OSC_PARAM_UNUSED(aubUdsData);

     return UDS_ACK;
 }
/*--------------------------{end APP_CommunicationControl}----------------------------------*/

/*--------------------------{APP_ControlDTCSetting}--------------------------------------*/
/* Deviation MISRA-1 */
tUdsStatus APP_ControlDTCSetting(u16 *puwLen, u8 *aubUdsData)
{
    *puwLen = 2U;
    OSC_PARAM_UNUSED(aubUdsData);

    return UDS_ACK;
}
/*--------------------------{end APP_ControlDTCSetting}----------------------------------*/

/*--------------------------{APP_EcuReset}--------------------------------------*/
tUdsStatus APP_EcuReset(u16 *puwLen, u8 *aubUdsData)
{
    OSC_PARAM_UNUSED(puwLen);

    BlPduR_StoreConnectionInfo();

    stNoIntShareVar.ubResetCause = PROG_RESET_CAUSE_ER;
    /* Check SuppressPositiveResponseBit */
    if (0x80U == (aubUdsData[1] & 0x80U))
    {
        /* store the reset request */
        stNoIntShareVar.ubResponseRequired = PROG_FALSE;
    }
    else
    {
      stNoIntShareVar.ubResponseRequired = PROG_TRUE;
      /* Reset the board without response */
    }

    /* Reset the board */
    BoardPerformReset(PLATFORMS_SW_RESET);

    return UDS_ACK;
}
/*--------------------------{end APP_EcuReset}----------------------------------*/


/*--------------------------{UDS_ReadDataByIdentifier}--------------------------------------*/
/* Deviation MISRA-1 */
tUdsStatus UDS_ReadDataByIdentifier(u16 *puwLen, u8 *aubUdsData)
{
  u8 eUdsStatus;
  u8 ubLoop;
  u8 Data[NUMBER_OF_BYTES] = {0xEBU};
  u8 const * address = NULL;
  u16 uwDataIdentifier;

  uwDataIdentifier = (u16)((u16)((u16)aubUdsData[1] << 8U) & 0xFF00U);
  uwDataIdentifier |= (u16)((u16)aubUdsData[2] & 0x00FFU);

  /* Set positive response */
  eUdsStatus = UDS_ACK;

  switch(uwDataIdentifier)
  {
      case 0xF1AA:
          address = &Data[0];
          eUdsStatus = UDS_ACK;
          break;
      default:
          eUdsStatus = UDS_NRC_31;
          break;
  }

  if(eUdsStatus == UDS_ACK)
  {
      for(ubLoop = 0U; ubLoop < NUMBER_OF_BYTES; ubLoop++)
      {
          aubUdsData[3U + ubLoop] = address[ubLoop];
      }

      *puwLen = NUMBER_OF_BYTES + 3U;
  }

  return eUdsStatus;
}
/*--------------------------{end UDS_ReadDataByIdentifier}----------------------------------*/


/*--------------------------{APP_ReqCheckProgPreCondition}--------------------------------------*/
tUdsStatus APP_ReqCheckProgPreCondition(u16 *puwLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    OSC_PARAM_UNUSED(aubUdsData);
    eStatus = UDS_ACK;
    *puwLen = 4U;
    return (eStatus);
}
/*--------------------------{end APP_ReqCheckProgPreCondition}----------------------------------*/

/*--------------------------{APP_ClearProgCounter}--------------------------------------*/
tUdsStatus APP_ClearProgCounter(u16 *puwLen, u8 *aubUdsData)
{
    u8 ubBlockIndex;

    OSC_PARAM_UNUSED(puwLen);
    OSC_PARAM_UNUSED(aubUdsData);

    for(ubBlockIndex = 0; ubBlockIndex < PROG_BLOCK_NBR; ubBlockIndex++)
    {
        stNVMBootloaderData.stNVMBlockData[ubBlockIndex].uwProgCounter = (u16) 0U;
    }

    return UDS_ACK;
}
/*--------------------------{end APP_ClearProgCounter}----------------------------------*/



/*--------------------------{APP_UdsSessionStatusInd}--------------------------------------*/
void APP_UdsSessionStatusInd (tUdsSessionType eUdsNewSessType,tUdsSessionType eUdsOldSessType,tUdsChangeReason eUdsChangingCause)
{
    OSC_PARAM_UNUSED(eUdsOldSessType);
    OSC_PARAM_UNUSED(eUdsChangingCause);
    OSC_PARAM_UNUSED(eUdsNewSessType);
}
/*--------------------------{end APP_UdsSessionStatusInd}----------------------------------*/

/*--------------------------{NCS_SdfVariableCoherencyError}--------------------------------------*/
void NCS_SdfVariableCoherencyError(u16 uwParam)
{
    OSC_PARAM_UNUSED(uwParam);
}
/*--------------------------{end NCS_SdfVariableCoherencyError}----------------------------------*/

/*--------------------------{NCS_SdfVariableRangeError}--------------------------------------*/
void NCS_SdfVariableRangeError(u16 uwParam)
{
    OSC_PARAM_UNUSED(uwParam);
}
/*--------------------------{end NCS_SdfVariableRangeError}----------------------------------*/


/*--------------------------{APP_TpTxConf}--------------------------------------*/
void APP_TpTxConf (tTpMsgIdx uMsgIdx, u8 ebStatus)
{
    OSC_PARAM_UNUSED(uMsgIdx);
    OSC_PARAM_UNUSED(ebStatus);
}
/*--------------------------{end APP_TpTxConf}----------------------------------*/

/*--------------------------{APP_TpRxInd}--------------------------------------*/
void APP_TpRxInd (tTpMsgIdx uMsgIdx, u8 ebStatus)
{
    OSC_PARAM_UNUSED(uMsgIdx);
    OSC_PARAM_UNUSED(ebStatus);

}
/*--------------------------{end APP_TpRxInd}----------------------------------*/


/*--------------------------{APP_Reset_Cause}--------------------------------------*/
void APP_Reset_Cause (void)
{

  if (PROG_TRUE == stNoIntShareVar.ubResponseRequired)
  {
      /*Response needed, check the reset cause*/
      switch(stNoIntShareVar.ubResetCause)
      {
          case PROG_RESET_CAUSE_ER:
              {
                  /*Send Positive Response to ER*/
                  PROG_SimulateER();
                  break;
              }
          case PROG_RESET_CAUSE_DSC01:
              {
                  /*Send Positive Response to DSC01*/
                  PROG_SimulateCloseProgSession();
                  break;
              }
          case PROG_RESET_CAUSE_S3_TIMEOUT:
          default:
              {
                  /*do nothing*/
                  break;
              }
      }
  }
  else
  {
      /*Do nothing, no response needed*/
  }
}
/*--------------------------{end APP_Reset_Cause}----------------------------------*/

/*---------------------------{PROG_SimulateCloseProgSession}----------------------*/
void PROG_SimulateCloseProgSession(void)
{
    u16 uwLen;

    if (TRUE == m_ubProgFirstCall)
    {
        BlPduR_RetrieveConnectionInfo();

        /* Prepare the sending of response to DSC01 */
        uwLen = 6U;

        m_aubUdsData[0U]=(u8)(UDS_SRV_DSC + UDS_ACK);
        m_aubUdsData[1U]=(u8)(UDS_SESSION_DEFAULT);
        m_aubUdsData[2U]=(u8)((PROG_P2_DEFAULT_SESSION_VAL)>>8U);
        m_aubUdsData[3U]=(u8) (PROG_P2_DEFAULT_SESSION_VAL);
        m_aubUdsData[4U]=(u8)((PROG_P2STAR_DEFAULT_SESSION_VAL/10U)>>8U);
        m_aubUdsData[5U]=(u8)((PROG_P2STAR_DEFAULT_SESSION_VAL/10U));

        /* Send Message */
        EB_Send_TPFrame(uwLen, m_aubUdsData);
    }
}
/*--------------------------{end PROG_SimulateCloseProgSession}-------------------*/

/*----------------------------------{PROG_SimulateER}-----------------------------*/
void PROG_SimulateER(void)
{
    u16 uwLen;

    if (TRUE == m_ubProgFirstCall)
    {
        BlPduR_RetrieveConnectionInfo();

        /* Prepare the sending of response to ER */
        uwLen = PROG_ECU_RESET_RESPONSE_SIZE;

        /* Reset type: HW */
        m_aubUdsData[0U]=(u8)(UDS_SRV_ER + UDS_ACK);
        m_aubUdsData[1U]=(u8)(UDS_SESSION_DEFAULT);

        /* Send Message */
        EB_Send_TPFrame(uwLen, m_aubUdsData);
    }
}
/*--------------------------------{end PROG_SimulateER}---------------------------*/

