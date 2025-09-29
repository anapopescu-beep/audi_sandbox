/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               PROG layer                                      */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_Driver.c                   */
/*%%  |                             |  %%  \brief Download driver flash routines */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.43.0 BL3 */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/* Copyright 2015 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/
/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 18.2 (required)
 * Subtraction between pointers shall only be applied to pointers that address elements of the same array.
 *
 *   Reason:
 * The pointers address to the same array in which contains the flash driver.
 *
 * MISRAC2012-2) Deviated Rule: 18.4 (advisory)
 * The +, -, += and -= operators should not be applied to an expression of pointer type.
 *
 *   Reason:
 * Pointer subtraction between two pointers is allowed, as long as they address to the same array.
 *
 */
/*=============================== FILE INCLUSION ================================*/
/*                                                                               */
#define COV_BASE 0u /* COV_START_(FILE) */
#ifndef /*Prog*/_cov_h_
  #define /*Prog*/_cov_h_
  /* #include <Prog_cov.h> */
  extern volatile unsigned char /*Prog_*/coveragedata[];
  #define ICOV(x) /*Prog_*/coveragedata[(COV_BASE+(x))>>3u]|=1u<<((COV_BASE+(x))&7u)
  #define BCOV(x) (ICOV(x),1)
#endif /*Prog_cov_h_*/

#include "EB_Prj.h"
#include "PROG_Priv.h"
#include <PROG_Trace.h>                        /* Dbg related macros for EB */
/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */
/*                                                                               */

/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */

/*-------------------------------------------------------------------------------*/
/* - Public Callback Prototypes                                                  */

/*                                                                               */
/*===============================================================================*/

/*============================ PRIVATE DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Private Constants                                                           */

/*-------------------------------------------------------------------------------*/
/* - Private Types                                                               */

/*-------------------------------------------------------------------------------*/
/* - Private Variables                                                           */
#if ((PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON) || (PROG_DECOMP_FLASH_ROUTINES == STD_ON))
NCS_PRI_VAR u8 m_ubFlashRoutinesPresent;
#endif
#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
NCS_PRI_VAR u8 m_ubFlashRoutinesCorrupted;
#endif /* PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON */

/*                                                                               */
/*===============================================================================*/

/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */


/*                                                                               */
/*===============================================================================*/

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */

/*                                                                               */
/*===============================================================================*/

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

/*-------------------------------------------------------------------------------*/
/* - Public Functions                                                            */

/*----------------------------{PROG_DrvDown_VerifyTransition}-----------------------*/
#if ((PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON) || (PROG_DECOMP_FLASH_ROUTINES == STD_ON))
tProgStatus PROG_DrvDown_VerifyTransition(void)
{
    tProgStatus eProgStatus;
#if PROG_DOWNLOAD_FLASH_ROUTINES_REJECT_AFTER_FAILURE == STD_ON
    tProgBoolean eProgCorrupted;
#endif
    tProgBoolean eProgPresent;

    ICOV(499);DBG_PROG_DRVDOWN_VERIFYTRANSITION_ENTRY();

    eProgStatus = PROG_E_OK;
#if PROG_DOWNLOAD_FLASH_ROUTINES_REJECT_AFTER_FAILURE == STD_ON
    eProgCorrupted = PROG_DrvDown_IsFlashRoutinesCorrupted();
    if ((PROG_TRUE == eProgCorrupted)?BCOV(500):!BCOV(501))
    {
        eProgStatus = PROG_E_NOT_OK;
    }
    if ((PROG_E_OK == eProgStatus)?BCOV(502):!BCOV(503))
#endif /*PROG_DOWNLOAD_FLASH_ROUTINES_REJECT_AFTER_FAILURE == STD_ON*/
    {
        eProgPresent = PROG_DrvDown_IsFlashRoutinesPresent();
        if ((PROG_TRUE == eProgPresent)?BCOV(504):!BCOV(505))
        {
            /* Nothing to do */
        }
        else
        {
            eProgStatus = PROG_E_NOT_OK;
        }
    }

    DBG_PROG_DRVDOWN_VERIFYTRANSITION_EXIT(eProgStatus);
    return eProgStatus;
}
#endif
/*--------------------{end PROG_DrvDown_VerifyTransition}-----------------------------*/

/*----------------------------{PROG_DrvDown_EraseFlashRoutines}-----------------------*/
#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
void PROG_DrvDown_EraseFlashRoutines(void)
{
    u8 ubLoopIndex;
    ICOV(506);DBG_PROG_DRVDOWN_ERASEFLASHROUTINES_ENTRY();

    (void) PROG_MemDataAccess(
                    PROG_MEM_TYPE_RAM,
                    PROG_MEM_OPERATION_TYPE_ERASE,
                    PROG_FLASH_ROUTINES_RAM_ADDR_START,
                    (u16) (PROG_FLASH_ROUTINES_RAM_ADDR_END - PROG_FLASH_ROUTINES_RAM_ADDR_START),
                    &ubLoopIndex);

    m_ubFlashRoutinesPresent = PROG_FALSE;

    DBG_PROG_DRVDOWN_ERASEFLASHROUTINES_EXIT();
}
#endif
/*--------------------{end PROG_DrvDown_EraseFlashRoutines}-----------------------------*/

/*-----------------------------{PROG_DrvDown_IsFlashRoutinesPresent}----------------------------------*/
#if ((PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON) || (PROG_DECOMP_FLASH_ROUTINES == STD_ON))
tProgBoolean PROG_DrvDown_IsFlashRoutinesPresent(void)
{
    ICOV(507);DBG_PROG_DRVDOWN_ISFLASHROUTINESPRESENT_ENTRY();

    DBG_PROG_DRVDOWN_ISFLASHROUTINESPRESENT_EXIT(m_ubFlashRoutinesPresent);

    return m_ubFlashRoutinesPresent;
}
#endif /* ((PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON) || (PROG_DECOMP_FLASH_ROUTINES == STD_ON)) */
/*--------------------{end PROG_DrvDown_IsFlashRoutinesPresent}-----------------------------*/


/*-----------------------------{PROG_DrvDown_SetFlashRoutinesPresence}----------------------------------*/
#if ((PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON) || (PROG_DECOMP_FLASH_ROUTINES == STD_ON))
void PROG_DrvDown_SetFlashRoutinesPresence(tProgBoolean eProgPresent)
{
    ICOV(508);DBG_PROG_DRVDOWN_SETFLASHROUTINESPRESENCE_ENTRY(eProgPresent);

    m_ubFlashRoutinesPresent = eProgPresent;

    DBG_PROG_DRVDOWN_SETFLASHROUTINESPRESENCE_EXIT();
}
#endif /* ((PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON) || (PROG_DECOMP_FLASH_ROUTINES == STD_ON)) */
/*--------------------{end PROG_DrvDown_SetFlashRoutinesPresence}-----------------------------*/


/*-----------------------------{PROG_DrvDown_IsFlashRoutinesCorrupted}----------------------------------*/
#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
tProgBoolean PROG_DrvDown_IsFlashRoutinesCorrupted(void)
{
    ICOV(509);DBG_PROG_DRVDOWN_ISFLASHROUTINESCORRUPTED_ENTRY();

    DBG_PROG_DRVDOWN_ISFLASHROUTINESCORRUPTED_EXIT(m_ubFlashRoutinesCorrupted);

    return m_ubFlashRoutinesCorrupted;
}
#endif /* PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON */
/*--------------------{end PROG_DrvDown_IsFlashRoutinesCorrupted}-----------------------------*/


/*-----------------------------{PROG_DrvDown_SetFlashRoutinesCorruption}----------------------------------*/
#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
void PROG_DrvDown_SetFlashRoutinesCorruption(tProgBoolean eProgCorruption)
{
    ICOV(510);DBG_PROG_DRVDOWN_SETFLASHROUTINESCORRUPTION_ENTRY(eProgCorruption);

    m_ubFlashRoutinesCorrupted = eProgCorruption;

    DBG_PROG_DRVDOWN_SETFLASHROUTINESCORRUPTION_EXIT();
}
#endif /* PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON */
/*--------------------{end PROG_DrvDown_SetFlashRoutinesCorruption}-----------------------------*/


#if PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON
/*-----------------------------{PROG_DrvDown_RD_Check}----------------------------------*/
#if ((PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON) || (PROG_DECOMP_FLASH_ROUTINES == STD_ON))
tProgStatus PROG_DrvDown_RD_Check(u8 ubLocalSegmentId)
{
    tProgStatus eProgStatus;
#if PROG_DOWNLOAD_FLASH_ROUTINES_REJECT_AFTER_FAILURE == STD_ON
    tProgBoolean eProgCorrupted;
#endif

#if PROG_DECOMP_FLASH_ROUTINES == STD_ON
    ICOV(511);OSC_PARAM_UNUSED(ubLocalSegmentId);
#endif


#if (PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON)
    ICOV(511);if ((stConfigSegment[ubLocalSegmentId].ePartitionType == PROG_FLASH_ROUTINES_PARTITION)?BCOV(512):!BCOV(513))
    {
#if PROG_DOWNLOAD_FLASH_ROUTINES_REJECT_AFTER_FAILURE == STD_ON
        eProgCorrupted = PROG_DrvDown_IsFlashRoutinesCorrupted();
        if ((PROG_FALSE == eProgCorrupted)?BCOV(514):!BCOV(515))
        {
            eProgStatus = PROG_E_OK;

#if(PROG_SEG_LIST_CKS == STD_ON)
            /* Init Segment list for CRC calculation */
            m_stSegList.ubSegNbr = 0;
#endif /*(PROG_SEG_LIST_CKS == STD_ON)*/
        }
        else
        {
            eProgStatus = PROG_E_NOT_OK;
        }
#else
        eProgStatus = PROG_E_OK;
#endif /*PROG_DOWNLOAD_FLASH_ROUTINES_REJECT_AFTER_FAILURE == STD_ON*/
    }
    else
    {
        eProgStatus = PROG_DrvDown_VerifyTransition();
    }
#else
    ICOV(511);eProgStatus = PROG_DrvDown_VerifyTransition();
#endif /*(PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON)*/

    ICOV(511);return eProgStatus;
}
#endif
/*-----------------------------{PROG_DrvDown_RD_Check}----------------------------------*/
#endif


/*----------------------------{PROG_Drv_DecompressFlashRoutines}-----------------------*/
#if (PROG_DECOMP_FLASH_ROUTINES == STD_ON)
tProgStatus PROG_Drv_DecompressFlashRoutines(void)
{
    tProgStatus eProgStatus;
    Cal_ReturnType eCplStatus;

    /* Size of input data to decompress */
    u32 ulInputLength;
    /* Size of the output data which remained to decompress */
    u32 ulOutputLength;
    /* Expected Size of the Compressed Flash Driver */
    u32 ulExpectedCompressedRoutinesSize;
    /* Expected Size of the RAM Allocated for Decompressed Flash Driver */
    u32 ulExpectedDecompressedRoutinesSize;

    u8* pubInputBuffer;
    u8* pubOutputBuffer;
    u8* pubSizeOfCompressedFlashROMArea;
    u8  ubShift;

    ICOV(516);DBG_PROG_DRV_DECOMPRESSFLASHROUTINES_ENTRY();

    eProgStatus = PROG_E_NOT_OK;

    /* Point to the ROM Start Address area of the Flash Driver Routines */
    pubInputBuffer  = PROG_FLASH_ROUTINES_ROM_ADDR_START;
    /* Point to the RAM Start Address area of the Flash Driver Routines */
    pubOutputBuffer = PROG_FLASH_ROUTINES_RAM_ADDR_START;

    /* Get the size of the decompressed Flash Driver Routines in ROM by the linker file */
    /* Deviation MISRAC2012-1, MISRAC2012-2 */
    ulExpectedDecompressedRoutinesSize = (PROG_FLASH_ROUTINES_ROM_ADDR_END) - (PROG_FLASH_ROUTINES_ROM_ADDR_START);
    /* Initialize the size of data which remain to decompress (Whole data as decompression has not been started) */
    /* Deviation MISRAC2012-1, MISRAC2012-2 */
    ulOutputLength = (PROG_FLASH_ROUTINES_RAM_ADDR_END) - (PROG_FLASH_ROUTINES_RAM_ADDR_START);

    /* Get size of compressed Flash routines in ROM (last 4 bytes stored at the end of the Flash routine area in ROM) */
    ubShift = 4U;
    ulExpectedCompressedRoutinesSize = 0x00000000U;

    for(pubSizeOfCompressedFlashROMArea = &pubInputBuffer[ulExpectedDecompressedRoutinesSize - ubShift];
        /* Deviation MISRAC2012-2 */
        (pubSizeOfCompressedFlashROMArea < (PROG_FLASH_ROUTINES_ROM_ADDR_END))?BCOV(517):!BCOV(518);
        pubSizeOfCompressedFlashROMArea++ )
    {
        /* Decrease shift index */
        ubShift--;

        ulExpectedCompressedRoutinesSize |= (u32)*pubSizeOfCompressedFlashROMArea << (8U * ubShift);
    }
    ulInputLength = ulExpectedCompressedRoutinesSize;

    /* Decompress the Flash Driver Routines */
    eCplStatus = Cal_DecompressStart(PROG_CALDECOMPRESS_CFGID, m_stProgCplContext);

    if ((CAL_E_OK == eCplStatus)?BCOV(519):!BCOV(520))
    {
        eCplStatus = Cal_DecompressUpdate(PROG_CALDECOMPRESS_CFGID, m_stProgCplContext, pubInputBuffer,
                &ulInputLength, pubOutputBuffer, &ulOutputLength);

        /* Test if the decompression returned OK and the whole compressed data have been processed */
        if (((CAL_E_OK == eCplStatus) && (ulExpectedCompressedRoutinesSize == ulInputLength))?BCOV(521):!BCOV(522))
        {
            /* Update output buffer */
            pubOutputBuffer = &pubOutputBuffer[ulOutputLength];
            /* Update length of Decompressed data which remain to write (expected 0 as whole compressed data have been processed) */
            ulOutputLength = ulExpectedDecompressedRoutinesSize - ulOutputLength;

            if ((0U == ulOutputLength)?BCOV(523):!BCOV(524))
            {
                eCplStatus = Cal_DecompressFinish(
                    PROG_CALDECOMPRESS_CFGID,
                    m_stProgCplContext,
                    pubOutputBuffer,
                    &ulOutputLength
                    );

                if ((CAL_E_OK == eCplStatus)?BCOV(525):!BCOV(526))
                {
                    /* No Decompression error */
                    eProgStatus = PROG_E_OK;
                }
            }
        }
    }

    DBG_PROG_DRV_DECOMPRESSFLASHROUTINES_EXIT(eProgStatus);
    return eProgStatus;
}
#endif
/*--------------------{end PROG_Drv_DecompressFlashRoutines}-----------------------------*/

/*----------------------------{PROG_Drv_ClearFlashRoutines}-----------------------*/
#if (PROG_DECOMP_FLASH_ROUTINES == STD_ON)
tProgStatus PROG_Drv_ClearFlashRoutines(void)
{
    tProgStatus eProgStatus;
    u8*         pubRAMStartFlashDriverArea;
    u32         ulLength;
    u32         ulIdx;


    ICOV(527);DBG_PROG_DRV_CLEARFLASHROUTINES_ENTRY();

    eProgStatus = PROG_E_OK;
    /* Deviation MISRAC2012-1, MISRAC2012-2 */
    ulLength    = (PROG_FLASH_ROUTINES_RAM_ADDR_END) - (PROG_FLASH_ROUTINES_RAM_ADDR_START);

    pubRAMStartFlashDriverArea = PROG_FLASH_ROUTINES_RAM_ADDR_START;
    /* Clear RAM Flash driver routines */
    for (ulIdx = 0; (ulIdx < ulLength)?BCOV(528):!BCOV(529); ulIdx++)
    {
        pubRAMStartFlashDriverArea[ulIdx] = 0U;
    }

    /* Mention the the Flash Driver Routines are not present in RAM */
    m_ubFlashRoutinesPresent = PROG_FALSE;

    DBG_PROG_DRV_CLEARFLASHROUTINES_EXIT(eProgStatus);
    return eProgStatus;
}
#endif
/*--------------------{end PROG_Drv_ClearFlashRoutines}-----------------------------*/
