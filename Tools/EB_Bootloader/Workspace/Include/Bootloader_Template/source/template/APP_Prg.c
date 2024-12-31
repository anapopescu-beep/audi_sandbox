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


/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */

#define UDS_DID_F187_VWSPAREPARTNUMBER_SIZE                                11u
#define UDS_DID_F189_VWSOFTWAREVERSIONNUMBER_SIZE                           4u
#define UDS_DID_F18C_ECUSERIALNUMBER_SIZE                                  20u
#define UDS_DID_F191_VWECUHARDWARENUMBER_SIZE                              11u
#define UDS_DID_F19E_ASAMODXFILEIDENTIFIER_SIZE                            25u
#define UDS_DID_F1A2_ASAMODXFILEVERSION_SIZE                                6u
#define UDS_DID_F1A3_VWECUHARDWAREVERSIONNUMBER_SIZE                        3u
#define UDS_DID_F190_VIN_SIZE                                              17u
#define UDS_DID_F17C_VWFAZITIDENTIFICATIONSTRING_SIZE                      23u
#define UDS_DID_F1D5_FDSPROJECTDATA_SIZE                                    7u
#define UDS_DID_F1DF_ECUPROGRAMMINGINFORMATION                              1u

#define APP_PROG_SESSION                                                    2U
#define APP_EXT_SESSION                                                     3U

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */

const uint8 DID_F187_VWSparePartNumber_Default[]                    = "TBD--------";
const uint8 DID_F189_VWSoftwareVersionNumber_Default[]              = "BOOT";
const uint8 DID_0405_StateOfFlashMemory_Default[]                   = "-";
const uint8 DID_0406_ProgrammingPreconditions_Default[]             = "-";
const uint8 DID_F18C_EcuSerialNumber_Default[]                      = "TBD-----------------";
const uint8 DID_F191_VWEcuHardwareNumber_Default[]                  = "TBD-------";
const uint8 DID_F19E_AsamOdxFileIdentifier_Default[]                = "TBD----------------------";
const uint8 DID_F1A2_AsamOdxFileVersion_Default[]                   = "------";
const uint8 DID_F1A3_VWEcuHardwareVersionNumber_Default[]           = "TBD";
const uint8 DID_F15A_VWCodingRepairShopCodeOrSerialNumber_Default[] = "---";
const uint8 DID_F190_Vin_Default[]                                  = "-----------------";
const uint8 DID_F17C_VWFazitIdentificationString_Default[]          = "-----------------------";
const uint8 DID_F1D5_FDSProjectData_Default[]                       = "-------";

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

}
/*--------------------------{end APP_Init}----------------------------------*/

/*--------------------------{APP_Manage}--------------------------------------*/
void APP_Manage (void)
{

}
/*--------------------------{end APP_Manage}----------------------------------*/

#ifdef BOARD_ISR_STMTIMER
/*--------------------------{APP_PlatformSTMTimSch}----------------------------------*/
void APP_PlatformSTMTimSch (void)
{
    /* Manage response for long request */
    UDS_ResponsePending_Manage();
}
/*--------------------------{end APP_PlatformSTMTimSch}----------------------------------*/
#endif
/*--------------------------{UDS_P2AboutToExpireInd}--------------------------------------*/
void UDS_P2AboutToExpireInd(void)
{

}
/*--------------------------{end UDS_P2AboutToExpireInd}----------------------------------*/

/*--------------------------{UDS_ReadDataByIdentifier}--------------------------------------*/
/* Deviation MISRA-1 */
tUdsStatus UDS_ReadDataByIdentifier(u16 *puwLen, u8 *aubUdsData)
{
    u8 eUdsStatus;
    u8 ubLoop;
    u8 numberOfBytes = 0U;
    u8 const * address = NULL;
    u16 uwDataIdentifier;

    uwDataIdentifier = (u16)((u16)((u16)aubUdsData[1] << 8U) & 0xFF00U);
    uwDataIdentifier |= (u16)((u16)aubUdsData[2] & 0x00FFU);

    /* Set positive response */
    eUdsStatus = UDS_ACK;

    switch(uwDataIdentifier)
    {
        case 0xF187:
            address = &DID_F187_VWSparePartNumber_Default[0];
            numberOfBytes = UDS_DID_F187_VWSPAREPARTNUMBER_SIZE;
            break;
        case 0xF189:
            address = &DID_F189_VWSoftwareVersionNumber_Default[0];
            numberOfBytes = UDS_DID_F189_VWSOFTWAREVERSIONNUMBER_SIZE;
            break;
        case 0xF18C:
            address = &DID_F18C_EcuSerialNumber_Default[0];
            numberOfBytes = UDS_DID_F18C_ECUSERIALNUMBER_SIZE;
            break;
        case 0xF191:
            address = &DID_F191_VWEcuHardwareNumber_Default[0];
            numberOfBytes = UDS_DID_F191_VWECUHARDWARENUMBER_SIZE;
            break;
        case 0xF19E:
            address = &DID_F19E_AsamOdxFileIdentifier_Default[0];
            numberOfBytes = UDS_DID_F19E_ASAMODXFILEIDENTIFIER_SIZE;
            break;
        case 0xF1A2:
            address = &DID_F1A2_AsamOdxFileVersion_Default[0];
            numberOfBytes = UDS_DID_F1A2_ASAMODXFILEVERSION_SIZE;
            break;
        case 0xF1A3:
            address = &DID_F1A3_VWEcuHardwareVersionNumber_Default[0];
            numberOfBytes = UDS_DID_F1A3_VWECUHARDWAREVERSIONNUMBER_SIZE;
            break;
        case 0xF190:
            address = &DID_F190_Vin_Default[0];
            numberOfBytes = UDS_DID_F190_VIN_SIZE;
            break;
        case 0xF17C:
            address = &DID_F17C_VWFazitIdentificationString_Default[0];
            numberOfBytes = UDS_DID_F17C_VWFAZITIDENTIFICATIONSTRING_SIZE;
            break;
        case 0xF1D5:
            address = &DID_F1D5_FDSProjectData_Default[0];
            numberOfBytes = UDS_DID_F1D5_FDSPROJECTDATA_SIZE;
            break;
        case 0xF1DF: /* ECU Programming Info */
            address = &stNVMBootloaderData.stNVMEcuData.ubECUProgInfo;
            numberOfBytes = UDS_DID_F1DF_ECUPROGRAMMINGINFORMATION;
            break;
        
        default:
          eUdsStatus = UDS_NRC_31;
          break;
    }

    if(eUdsStatus == UDS_ACK)
    {
        for(ubLoop = 0U; ubLoop < numberOfBytes; ubLoop++)
        {
            aubUdsData[3U + ubLoop] = address[ubLoop];
        }

        *puwLen = numberOfBytes + 3U;
    }

  return eUdsStatus;
}
/*--------------------------{end UDS_ReadDataByIdentifier}----------------------------------*/

/*--------------------------{APP_UdsSessionStatusInd}--------------------------------------*/
void APP_UdsSessionStatusInd (tUdsSessionType eUdsNewSessType,tUdsSessionType eUdsOldSessType,tUdsChangeReason eUdsChangingCause)
{

    OSC_PARAM_UNUSED(eUdsNewSessType);
    OSC_PARAM_UNUSED(eUdsOldSessType);
    OSC_PARAM_UNUSED(eUdsChangingCause);

}
/*--------------------------{end APP_UdsSessionStatusInd}----------------------------------*/


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


