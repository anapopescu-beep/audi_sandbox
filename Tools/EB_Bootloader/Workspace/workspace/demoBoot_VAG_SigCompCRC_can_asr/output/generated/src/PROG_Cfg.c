/*********************************************************************************/
/*                                                                               */
/*                                  BOOT Layers                                  */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                                 PROG configuration                            */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_Cfg.c                      */
/*%%  |                             |  %%  \brief PROG layer source plugin file  */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.14.0 BL-3.X              */
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
#include "EB_Prj.h"






                                                                                                
/*----------------------------------------------------------------------------------*/


const tCfgMemorytType m_astCfgMemory[PROG_MEMORY_NB] =
{
    {
        PROG_MEM_TYPE_FLASH,
        PROG_MEMORY_SYNCHRONOUS,
        0x8U,
        0x0U,
        0xffU,
    },
};

const tCfgSegmentType stConfigSegment[PROG_SEGMENT_NB] =
{
    {
        0x20000U,                        /* Start Address */
        0x5ffffU,                        /* End Address */
        0x20000U,                        /* Erase Start Address */
        0x5ffffU,                        /* Erase End Address */
        0U,               /* Selected Memory Index */
        PROG_MEM_ACCESS_TYPE_READ_WRITE,   /* Memory Access Type */
        PROG_APPLICATION_PARTITION,        /* Partition Type */
        0U                                 /* Corresponding Block Index */
    },
    {
        0x60000U,                        /* Start Address */
        0x7ffffU,                        /* End Address */
        0x60000U,                        /* Erase Start Address */
        0x7ffffU,                        /* Erase End Address */
        0U,               /* Selected Memory Index */
        PROG_MEM_ACCESS_TYPE_READ_WRITE,   /* Memory Access Type */
        PROG_CALIBRATION_PARTITION,        /* Partition Type */
        1U                                 /* Corresponding Block Index */
    },
};

const tProg_Block    stCfgBlock[PROG_BLOCK_NB] =
{
    {
        0x1U,                       /* Block Identifier */
        PROG_SEG_APPLICATION_SEG0,  /* Name of the first segment*/
        0x1U,                       /* Number of segments contained in the block */
        0x0U,                       /* Maximum number of programming allowed */
    },
    {
        0x2U,                       /* Block Identifier */
        PROG_SEG_CALIBRATION_SEG0,  /* Name of the first segment*/
        0x1U,                       /* Number of segments contained in the block */
        0x0U,                       /* Maximum number of programming allowed */
    },
};







