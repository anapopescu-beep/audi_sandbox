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
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 0.23.0 BL3                */
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
        BLPDUR_PHYSICAL,    /* AddressingType */
        0U,                 /* Active Group */
        0U,                 /* RxPduId */
        BLPDUR_EXTENDED_CAN_ID /* RxPduType */
    },
    {
        1U,                  /* ConnectionNum  */
        BLPDUR_PHYSICAL,    /* AddressingType */
        1U,                 /* Active Group */
        1U,                 /* RxPduId */
        BLPDUR_EXTENDED_CAN_ID /* RxPduType */
    },
    {
        2U,                  /* ConnectionNum  */
        BLPDUR_PHYSICAL,    /* AddressingType */
        0U,                 /* Active Group */
        2U,                 /* RxPduId */
        BLPDUR_EXTENDED_CAN_ID /* RxPduType */
    },
    {
        3U,                  /* ConnectionNum  */
        BLPDUR_PHYSICAL,    /* AddressingType */
        1U,                 /* Active Group */
        3U,                 /* RxPduId */
        BLPDUR_EXTENDED_CAN_ID /* RxPduType */
    },
    {
        4U,                  /* ConnectionNum  */
        BLPDUR_PHYSICAL,    /* AddressingType */
        0U,                 /* Active Group */
        4U,                 /* RxPduId */
        BLPDUR_EXTENDED_CAN_ID /* RxPduType */
    },
    {
        5U,                  /* ConnectionNum  */
        BLPDUR_PHYSICAL,    /* AddressingType */
        1U,                 /* Active Group */
        5U,                 /* RxPduId */
        BLPDUR_EXTENDED_CAN_ID /* RxPduType */
    },
};

tPduConnection stPduConnection[BLPDUR_MAX_PDU_CONNECTION] =
{
    {
        BLPDUR_Sdu_DIA_RGS_VL_Resp,   /* TxPdu  */
        0U                     /* TestAddress */
    },
    {
        BLPDUR_Sdu_DIA_RGS_VR_Resp,   /* TxPdu  */
        0U                     /* TestAddress */
    },
    {
        BLPDUR_Sdu_Diag_RGS_VL_Resp,   /* TxPdu  */
        1U                     /* TestAddress */
    },
    {
        BLPDUR_Sdu_Diag_RGS_VR_Resp,   /* TxPdu  */
        1U                     /* TestAddress */
    },
    {
        BLPDUR_Sdu_OBDC_SSN_RGS_VL_Resp,   /* TxPdu  */
        2U                     /* TestAddress */
    },
    {
        BLPDUR_Sdu_OBDC_SSN_RGS_VR_Resp,   /* TxPdu  */
        2U                     /* TestAddress */
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
    }
};

tBufferConfigType stRxPhysBufferConfig[BLPDUR_RX_PHY_BUFFER_NUM] =
{

    {
        &BlPduRRxPhysBuffer[0][0],  /* ptrBuffer   */
        &stRxPhysBufferInfo[0],      /* bufferInfo  */
        BLPDUR_RX_PHYS_BUFFERSIZE,   /* Buffer size */
    },
};

/* Tab for all CanId configured in a connection */
Can_IdType auCanId_0[BLPDUR_CONNECTION_NUM_ID_GR_0] =
{
    0x17fc4206U,
    0x17fc6206U,
    0x17fc5206U,
};
/* Tab for all CanId configured in a connection */
Can_IdType auCanId_1[BLPDUR_CONNECTION_NUM_ID_GR_1] =
{
    0x18fc4206U,
    0x18fc5206U,
    0x18fc6206U,
};

/* Tab that defines all the ID group */
const tMultipleIdConfig stMultipleIdConfig[BLPDUR_ID_GROUP_NUM] =
{
    {
        &auCanId_0[0],                   /* Pointer to the tab that list the Can ID of the group ID */
        BLPDUR_CONNECTION_NUM_ID_GR_0,   /* Number of can ID in the ID group */
    },
    {
        &auCanId_1[0],                   /* Pointer to the tab that list the Can ID of the group ID */
        BLPDUR_CONNECTION_NUM_ID_GR_1,   /* Number of can ID in the ID group */
    },
};
