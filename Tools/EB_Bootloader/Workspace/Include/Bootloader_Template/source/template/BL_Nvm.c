/**
 * \file
 *
 * \brief AUTOSAR Demo
 *
 * This file contains the implementation of the AUTOSAR
 * module Demo.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2016 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/


#include "EB_Prj.h"
#include "APP_Boot.h"
#if (NVM_PRESENT == STD_ON)
#include "BL_Nvm.h"
#include "board.h"
#include <Base_Modules.h>   /* Module enable defines and standard config pointer names */
#include <Port.h>   /* Module enable defines and standard config pointer names */
#include "Fls.h"
#include "Fee.h"
#include "NvM_Cfg.h"
#include "MemIf_Types.h"
#include "NvM.h"
#include "Fls_Cfg.h"
#include <MemIf.h>

/******************************** DEFINES & VARIABLES ****************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/** \brief Blank check verification
 **
 ** This API Verify if the data retrieve from NVM are correctly initialized by checking a specific Init marker.
 **
 ** If this marker is not set, it initialized the whole NVM structure to the a default value
 **
 **/
VAR(NvM_BlockIdType, EBTEST_VAR) Test_BlockNumber=NVM_BLOCK_MULTI;
#define MEMIF_DEVICE_ID 0

static void BL_BlankNvMCheckAndFirstInit(void);

/** \brief NVM initialization
 **
 ** This API initialize all the NVM stack (Fls, Fee, NVM).
 **
 ** Then it retrieve the Bootloade NVM block from Memory and the correct data retrieved
 **
 **/
void BL_Nvm_Init(void)
{
	MemIf_StatusType status;
    /* Init of NVM stack */
    Fls_Init(&FlsConfigSet);
    Fee_Init(NULL_PTR);
    do
      {
         Fee_MainFunction();
         Fls_MainFunction();
         status = MemIf_GetStatus(0);
      } while ( (MEMIF_BUSY == status) || (MEMIF_BUSY_INTERNAL == status) );
    NvM_Init();
}

/** \brief Read data from NVM
 **
 ** This API call the NVM stack to retrive the booltoader NVM block data.
 **
 ** This API is blocker and wait until all the data has been read
 **
 **/
void BL_Nvm_ReadSync(uint8* pubNVMDataStored, uint8 ubNVMBlockID)
{
	uint8 Result ;
    /* RedNVM block */



	NvM_ReadBlock(ubNVMBlockID, pubNVMDataStored);
	/* wait until job is finished */
    BL_Nvm_WaitEndjob(ubNVMBlockID);
}

/** \brief Write data to NVM
 **
 ** This API call the NVM stack to store the booltoader NVM block data.
 **
 ** This API is blocker and wait until all the data has been written
 **
 **/
void BL_Nvm_WriteSync(uint8* pubNVMDataStored, uint8 ubNVMBlockID)
{
      /* Write Data into NVM */
      NvM_WriteBlock(ubNVMBlockID, pubNVMDataStored);

      BL_Nvm_WaitEndjob(ubNVMBlockID);
}

/** \brief Trigger NVM access and wait until operation is finished
 **
 ** This API trigger all the NVM stack Mainfunction until the current operation is fully finished.
 **
 ** \param[in] blockid Block ID of the NVM block the operation is done on.
 **
 **/
void BL_Nvm_WaitEndjob
(
        uint16 blockid
)
{
	uint8 retVal;
	MemIf_StatusType eStatus;

	eStatus= MEMIF_BUSY;

	NvM_MainFunction();
	NvM_GetErrorStatus(blockid, &retVal);

	while ( (retVal == NVM_REQ_PENDING)||
              (eStatus == MEMIF_BUSY))
	{
		Fls_MainFunction();
		Fee_MainFunction();
		NvM_MainFunction();
		eStatus = Fee_GetStatus();
		NvM_GetErrorStatus(blockid, &retVal);
	}
}



/** \brief Memory set
 **
 ** Set a given pattern to the a specified number of byte
 **
 ** \param[in] dest Destination pointer to set pattern on
 ** \param[in] pattern Value of the pattern
 ** \param[in] n Number of bytes to set
 **
 **/
void BL_memset(uint8 *dest, uint8 pattern, uint32 n)
{
    uint32 i=0;
    for (i=0; i<n; i++)
        dest[i] = pattern;
}


FUNC(void, EBTEST_CODE) Test_WaitNvMReady
(
  VAR(NvM_BlockIdType, EBTEST_VAR) blockNumber
)
{

  /* Schedule to TaskNv to process the job synchronous */
  Test_NvTask();
}

FUNC(void, EBTEST_CODE) Test_WaitAllNvMJobsReady
(
  void
)
{
   NvM_BlockIdType blockId;

   for ( blockId = (NvM_BlockIdType)NVM_BLOCK_MULTI;
         blockId < (NvM_BlockIdType)NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS;
         blockId++
       )
   {
      Test_WaitNvMReady( blockId );
   }
}

FUNC(void, EBTEST_CODE) Test_NvTask
(
  void
)
{
  /* return value of NvM functions */
  uint8 retVal;

  /*
   * wait for NVRAM Manager to finish job execution
   */
  NvM_GetErrorStatus(Test_BlockNumber, &retVal);

  while ( retVal == NVM_REQ_PENDING )
  {
    /*
     * wait for Nv stack to finish current job execution
     */
    while ( MemIf_GetStatus(MEMIF_DEVICE_ID) != MEMIF_IDLE )
    {
    }

    NvM_GetErrorStatus(Test_BlockNumber, &retVal);
  }
}

FUNC(void, BSWM_APPL_CODE) Eb_Intgr_BswM_DriverInitTwo(void)
{
MemIf_StatusType status;
  /* Adapt names of initialization functions or configuration structure
   * parameters in header file "Platforms_Modules.h" for architecture specific
   * modifications.
   * The following Module initialization sequence has been implemented on basis
   * of table 2 "Driver Initialization Details, Sample Configuration" you will
   * find in SWS "Specification of ECU State Manager with fixed state machine"
   * (document version  1.1.0, AUTOSAR 4.0.2). */


#ifdef BASE_FLS_ENABLED
   Fls_Init(&FlsConfigSet);
#endif
#ifdef BASE_FEE_ENABLED
   Fee_Init(NULL_PTR);
 do
   {
      Fee_MainFunction();
      Fls_MainFunction();
      status = MemIf_GetStatus(0);
   } while ( (MEMIF_BUSY == status) || (MEMIF_BUSY_INTERNAL == status) );
#endif
#ifdef BASE_NVM_ENABLED
   NvM_Init();
#endif

}

#endif
