/*********************************************************************************/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                           BlPduR configuration                                */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file BlPduR_Cfg.c                       */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 0.9.0 BL-3.X                */
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
/******************************** FILE INCLUSION *********************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Header Files: BlPduR                                                           */
#include "BlPduR_Prj.h"

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
/* - Private Functions                                                           */

/*-------------------------------------------------------------------------------*/
/* - Public Callbacks                                                            */

/*                                                                               */
/*********************************************************************************/

tRxPdu stRxPdu[BLPDUR_MAX_RX_PDU_NUM+BLPDUR_SHARED_RX_PDU_NUM] =
{
    {
        0U,                  /* ConnectionNum  */
        BLPDUR_FUNCTIONAL,    /* AddressingType */
        0U,                 /* RxPduId */
        BLPDUR_EXTENDED_CAN_ID /* RxPduType */
    },
    {
        0U,                  /* ConnectionNum  */
        BLPDUR_PHYSICAL,    /* AddressingType */
        1U,                 /* RxPduId */
        BLPDUR_EXTENDED_CAN_ID /* RxPduType */
    },
};

tPduConnection stPduConnection[BLPDUR_MAX_PDU_CONNECTION] =
{
    {
        BLPDUR_Sdu_Tx_Boot,   /* TxPdu  */
        0U                     /* TestAddress */
    },
};

uint8 BlPduRRxPhysBuffer[BLPDUR_RX_PHY_BUFFER_NUM][BLPDUR_RX_PHYS_BUFFERSIZE];
tBufferInfoType stRxPhysBufferInfo[BLPDUR_RX_PHY_BUFFER_NUM] =
{
    {
        0U,                 /* filledLen          */
        0U,                 /* dataMark           */
        0U,                 /* confirmedDataMark  */
        BLPDUR_BUFF_IDLE,   /* state              */
        0U                  /* originatingRxPduId */
    },
    {
        0U,                 /* filledLen          */
        0U,                 /* dataMark           */
        0U,                 /* confirmedDataMark  */
        BLPDUR_BUFF_IDLE,   /* state              */
        0U                  /* originatingRxPduId */
    },
    {
        0U,                 /* filledLen          */
        0U,                 /* dataMark           */
        0U,                 /* confirmedDataMark  */
        BLPDUR_BUFF_IDLE,   /* state              */
        0U                  /* originatingRxPduId */
    },
    {
        0U,                 /* filledLen          */
        0U,                 /* dataMark           */
        0U,                 /* confirmedDataMark  */
        BLPDUR_BUFF_IDLE,   /* state              */
        0U                  /* originatingRxPduId */
    },
};

tBufferConfigType stRxPhysBufferConfig[BLPDUR_RX_PHY_BUFFER_NUM] =
{
    {
        &BlPduRRxPhysBuffer[0][0U],  /* ptrBuffer   */
        &stRxPhysBufferInfo[0],      /* bufferInfo  */
        BLPDUR_RX_PHYS_BUFFERSIZE,   /* Buffer size */
    },
    {
        &BlPduRRxPhysBuffer[1][0U],  /* ptrBuffer   */
        &stRxPhysBufferInfo[1],      /* bufferInfo  */
        BLPDUR_RX_PHYS_BUFFERSIZE,   /* Buffer size */
    },
    {
        &BlPduRRxPhysBuffer[2][0U],  /* ptrBuffer   */
        &stRxPhysBufferInfo[2],      /* bufferInfo  */
        BLPDUR_RX_PHYS_BUFFERSIZE,   /* Buffer size */
    },
    {
        &BlPduRRxPhysBuffer[3][0U],  /* ptrBuffer   */
        &stRxPhysBufferInfo[3],      /* bufferInfo  */
        BLPDUR_RX_PHYS_BUFFERSIZE,   /* Buffer size */
    },
};


