#if (!defined BL_NVM_H)
#define BL_NVM_H

/*================== [includes] =============================================*/

#include <Base_Modules.h> 
#include <Port.h>
#include "APP_Boot.h"
#if (NVM_PRESENT == STD_ON)
#include "Fls.h"
#include "Fee.h"
#include "NvM_Cfg.h"
#include "MemIf_Types.h"
#include "NvM.h"
#include "ncs.h"
#include "BlPduR_Prj.h"

/*================== [macros] ===============================================*/

extern void BL_Nvm_Init(void);
extern void BL_InitNvMStruct(void);
extern void BL_Nvm_ReadSync( uint8* pubNVMDataStored, uint8 ubNVMBlockID);
extern void BL_Nvm_WriteSync( uint8* pubNVMDataStored, uint8 ubNVMBlockID);
extern void BL_Nvm_WaitEndjob
(
        uint16 blockid
);
extern void BL_Nvm_WaitReadjobEnd
(
        uint16 blockid
);
extern FUNC(void, EBTEST_CODE) Test_WaitNvMReady
(
  VAR(NvM_BlockIdType, EBTEST_VAR) blockNumber
);
extern FUNC(void, EBTEST_CODE) Test_WaitAllNvMJobsReady
(
  void
);

extern FUNC(void, EBTEST_CODE) Test_WaitAllNvMJobsReady_MainFunctionsIncluded
(
  void
);

FUNC(void, EBTEST_CODE) Test_NvTask
(
  void
);
extern void BL_memset(uint8 *dest, uint8 pattern, uint32 n);


#endif  /* #if (NVM_PRESENT == STD_ON) */
#endif  /* #if (!defined BL_NVM_H) */
