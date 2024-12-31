#ifndef SPIIF_H_
#define SPIIF_H_ 1

/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------------------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
H-File Template Version: 
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
*******************************************************************************

Overview of the interfaces:
   SPI Interface betwwen SBC, ACC and SPI component

******************************************************************************/
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.9.2.8 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/SpiIf/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Spi.h"
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/

/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
/*
 *  \brief
 *     This structure contains a pair of a Spi channel and a Spi structure.
 */
typedef struct
{
/**
 * \brief
 *     The Spi channel.
 */
   const Spi_ChannelType kstSpiChannel;
/**
 * \brief
 *     The Spi sequence.
 */
   const Spi_SequenceType kstSpiSequence;
} SpiIf_stSpiChannelSequenceType;

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
#define SpiIf_START_SEC_CODE
#include "SpiIf_MemMap.h"

extern void SpiIf_writeSpiData(SpiIf_stSpiChannelSequenceType const kstSpiChannelSequence, Spi_DataBufferType const * kpu8SpiCommand);
extern void SpiIf_spiSyncTransmitSequence(Spi_SequenceType const kstSpiSequence);
extern void SpiIf_spiReadIBFromChannel(Spi_ChannelType const ku8SpiChannel, Spi_DataBufferType * pu8SpiResponse);

#define SpiIf_STOP_SEC_CODE
#include "SpiIf_MemMap.h"

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/
#ifdef __cplusplus
           }
#endif
/******************************************************************************
End Of File
*****************************************************************************/
#endif /* SPIIF_H_ */