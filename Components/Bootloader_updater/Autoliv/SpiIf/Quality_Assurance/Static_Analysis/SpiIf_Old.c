/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version:
******************************************************************************/
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.10.1.2 $
*/
/*!****************************************************************************

@details
   SPI Interface betwwen SBC and SPI components, module is in charge of:
   - initialise the SBC components
   - refresh the watchdog and diagnose the HW components
   - de-initialise the HW component

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "SpiIf.h"
#include "Rte_SpiIf.h"
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
#define SpiIf_START_SEC_VAR_INIT_16
#include "SpiIf_MemMap.h"

#define SpiIf_STOP_SEC_VAR_INIT_16
#include "SpiIf_MemMap.h"

#define SpiIf_START_SEC_VAR_INIT_8
#include "SpiIf_MemMap.h"

#define SpiIf_STOP_SEC_VAR_INIT_8
#include "SpiIf_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
#define SpiIf_START_SEC_CONST_16
#include "SpiIf_MemMap.h"

#define SpiIf_STOP_SEC_CONST_16
#include "SpiIf_MemMap.h"

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
* \param[in]
*     SpiIf_stSpiChannelSequenceType kstSpiChannelSequence a struct with SPI Channel and Sequence;
*     Spi_DataBufferType kpu8SpiCommand data to send on SPI;
*     boolean bWaitIdleStatusFlag a flag to activate or dezactivate Wait IDLE Status of SPI Module;
* \return
*     void
* \remark
*     None
* \dynamiaspectcaller
*     SBC Module
**/
EXPORTED void SpiIf_writeSpiData
   (
      SpiIf_stSpiChannelSequenceType const kstSpiChannelSequence,
      Spi_DataBufferType const * kpu8SpiCommand,
      boolean const kbWaitIdleStatusFlag
   )
{
   (void)Spi_WriteIB(kstSpiChannelSequence.kstSpiChannel, kpu8SpiCommand);
   (void)Spi_AsyncTransmit(kstSpiChannelSequence.kstSpiSequence);

   if (SPIIF_WAIT_IDLE_STATUS_ON == kbWaitIdleStatusFlag)
   {
      SpiIf_waitSpiIdleStatus();
   }
}

/**
* \brief
*     Function used to send SPI commands and read answer.
* \param[in]
*     SpiIf_stSpiChannelSequenceType kstSpiChannelSequence a struct with SPI Channel and Sequence;
*     Spi_DataBufferType kpu8SpiCommand data to send on SPI;
* \param[out]
*     Spi_DataBufferType pu8SpiResponse data received from SPI;
* \return
*     void
* \remark
*     None
* \dynamiaspectcaller
*     SBC Module
**/
EXPORTED void SpiIf_writeSpiDataAndReadAnswer
   (
      SpiIf_stSpiChannelSequenceType const kstSpiChannelSequence,
      Spi_DataBufferType const * kpu8SpiCommand,
      Spi_DataBufferType * pu8SpiResponse
   )
{
   (void)Spi_WriteIB(kstSpiChannelSequence.kstSpiChannel, kpu8SpiCommand);
   (void)Spi_AsyncTransmit(kstSpiChannelSequence.kstSpiSequence);

   SpiIf_waitSpiIdleStatus();
   
   (void)Spi_ReadIB(kstSpiChannelSequence.kstSpiChannel, pu8SpiResponse);
}

/**
* \brief
*     Function used to set Spi in Async Mode.
* \param[in]
*     Spi_AsyncModeType kstAsyncMode the Async Mode to set for SPI module;
* \param[out]
*     None
* \return
*     void
* \remark
*     None
* \dynamiaspectcaller
*     SBC Module
**/
EXPORTED void SpiIf_setSpiAsyncMode(Spi_AsyncModeType const kstAsyncMode)
{
   (void)Spi_SetAsyncMode(kstAsyncMode);
}

/**
* \brief
*     Function used to transmit just a Spi Sequence.
* \param[in]
*     Spi_SequenceType kstSpiSequence the Sequence to transmit on SPI;
* \param[out]
*     None
* \return
*     void
* \remark
*     None
* \dynamiaspectcaller
*     SBC Module
**/
EXPORTED void SpiIf_spiAsyncTransmitSequence(Spi_SequenceType const kstSpiSequence)
{
   (void)Spi_AsyncTransmit(kstSpiSequence);
   SpiIf_waitSpiIdleStatus();
}

/**
* \brief
*     Function used to wait for the SPI module to enter in IDLE state.
* \param[in]
*     None
* \param[out]
*     None
* \return
*     void
* \remark
*     None
* \dynamiaspectcaller
*     SpiIf Module
**/
EXPORTED void SpiIf_waitSpiIdleStatus(void)
{
   Spi_StatusType spiif_stSpiStatus;

   spiif_stSpiStatus = Spi_GetStatus();
   while (spiif_stSpiStatus != SPI_IDLE)
   {
      Spi_MainFunction_Handling();
      spiif_stSpiStatus = Spi_GetStatus();
   }
}

#define SpiIf_STOP_SEC_CODE
#include "SpiIf_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
