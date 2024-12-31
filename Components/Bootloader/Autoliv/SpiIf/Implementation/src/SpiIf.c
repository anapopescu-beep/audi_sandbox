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
$Revision: 1.13.2.12 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/SpiIf/Implementation/src/project.pj $
*/
/*!****************************************************************************

@details
   SPI Interface betwwen SBC, ACC and SPI component, module is in charge of:
   - write a SPI command
   - sync transmit sequence
   - read Internal Buffer from a Spi channel

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "SpiIf.h"
#include "Nvp_Generated_Nvmdefault.h"
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
#define SpiIf_START_SEC_CODE
#include "SpiIf_MemMap.h"

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
* \brief
*     Function used to send SPI commands.
* \inputparam
*     Name: kstSpiChannelSequence;
*     Type: SpiIf_stSpiChannelSequenceType const (struct[uint8, uint8]);
*     Description: A struct that contain the sequence and the channel where we want to send the command;
*     Range: NA.;
* \inputparam
*     Name: kpu8SpiCommand;
*     Type: Spi_DataBufferType const * (uint8);
*     Description: A pointer to the Spi command. Spi command length depends on the channel we have selected.;
*     Range: NA.;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     SBC and ACC module.
* \dynamicaspectdescription
*     Called in acc_SendCommandToReadOrWriteRegister and sbc_ClearStateAndReport functions via direct call.
* \ddesignrequirement
*     DSG_SpiIf_writeSpiData
* \archrequirement
*     ARCH_SW_SpiIf_ptrpSpiIfServicesACC_writeSpiData
*     ARCH_SW_SpiIf_ptrpSpiIfServicesSBC_writeSpiData 
*     ARCH_SW_SpiIf_ptrrAsrSpiServices_Spi_WriteIB_SpiIf_writeSpiData
*     ARCH_SW_SpiIf_ptrrAsrSpiServices_Spi_SyncTransmit_SpiIf_writeSpiData
**/
EXPORTED void SpiIf_writeSpiData
   (
      SpiIf_stSpiChannelSequenceType const kstSpiChannelSequence,
      Spi_DataBufferType const * kpu8SpiCommand
   )
{
   (void)Spi_WriteIB(kstSpiChannelSequence.kstSpiChannel, kpu8SpiCommand);
   (void)Spi_SyncTransmit(kstSpiChannelSequence.kstSpiSequence);
}

/**
* \brief
*     Function used to transmit a Spi Sequence.
* \inputparam
*     Name: kstSpiSequence;
*     Type: Spi_SequenceType const (uint8);
*     Description: The Sequence to transmit on SPI;
*     Range: NA.;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     ACC and SBC modules.
* \dynamicaspectdescription
*     Called in ACC_runMainFunction, SBC_Init, SBC_runMainFunction, SBC_Shutdown, SBC_sleepTriggerWatchdog, 
*     SBC_SetToNormal, SBC_SetToLowPower, SBC_Reset and SBC_ForceExternalWatchdogReset functions via direct call.
* \ddesignrequirement
*     DSG_SpiIf_spiSyncTransmitSequence
* \archrequirement
*     ARCH_SW_SpiIf_ptrpSpiIfServicesACC_spiSyncTransmitSequence
*     ARCH_SW_SpiIf_ptrpSpiIfServicesSBC_spiSyncTransmitSequence
*     ARCH_SW_SpiIf_ptrrAsrSpiServices_Spi_SyncTransmit_SpiIf_spiSyncTransmitSequence
**/
EXPORTED void SpiIf_spiSyncTransmitSequence(Spi_SequenceType const kstSpiSequence)
{
   (void)Spi_SyncTransmit(kstSpiSequence);
}

/**
* \brief
*     Function used to read Spi response from Internal Buffer of a Spi channel.
* \inputparam
*     Name: kstSpiChannel;
*     Type: Spi_ChannelType const (uint8);
*     Description: The Spi channel from witch read response;
*     Range: NA.;
* \outputparam
*     Name: pu8SpiResponse;
*     Type: Spi_DataBufferType * (uint8);
*     Description: Pointer to the Spi response;
*     Range: NA.;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     ACC and SBC module.
* \dynamicaspectdescription
*     Called in acc_GetRegDataResponseFromSpiIB, ACC_runMainFunction, sbc_ClearStateAndReport, 
*     SBC_Init and SBC_runMainFunction function via direct call.
* \ddesignrequirement
*     DSG_SpiIf_spiReadIBFromChannel
* \archrequirement
*     ARCH_SW_SpiIf_ptrpSpiIfServicesACC_spiReadIBFromChannel
*     ARCH_SW_SpiIf_ptrpSpiIfServicesSBC_spiReadIBFromChannel
*     ARCH_SW_SpiIf_ptrrAsrSpiServices_spiReadIBFromChannel
**/
EXPORTED void SpiIf_spiReadIBFromChannel(Spi_ChannelType const ku8SpiChannel, Spi_DataBufferType * pu8SpiResponse)
{
   (void)Spi_ReadIB(ku8SpiChannel, pu8SpiResponse);
}

#define SpiIf_STOP_SEC_CODE
#include "SpiIf_MemMap.h"
/******************************************************************************
End Of File
******************************************************************************/
