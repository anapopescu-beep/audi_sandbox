/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the information (interfaces, definitions and data) provided
by the component NVP_CFG_H, part of the package NVP.
These are globally visible.
This file is intended to be included in a package header file;
all components should include the package header file instead of this file.

Current revision: $Revision: 1.2.8.3 $
Checked in:       $Date: 2022/11/25 08:53:11CET $

*************************************************************************/
#ifndef NVP_CFG_H_
#define NVP_CFG_H_ 1

#include "Std_Types.h"
#include "Config.h"
#include "Common.h"
#include "Nvp_Generated_NvmDefault.h"
#include "Nvp_Generated_Calibration.h"
#include "NvM_Cfg.h"

/*************************************************************************
Other components external interface inclusion
*************************************************************************/

/*************************************************************************
Declaration of constants
*************************************************************************/

/* Mask used to determine which auto-test is enabled for a block */
#define NVP_KU8_NO_AUTO_TEST_MASK                                 ((uint8) 0x00)
#define NVP_KU8_E2P_NOT_PROGRAMMED_AT_MASK                        ((uint8) 0x02)

/*************************************************************************
Declaration of macros
*************************************************************************/

/*************************************************************************
Declaration of types
*************************************************************************/

typedef struct
{
   uint32 u32BlockRamStartAddress;
   uint16 u16BlockLength;
   uint8 u8AutotestFlag;
}tNvpBlockConfig;


/*************************************************************************
Declaration of variables
*************************************************************************/

/*************************************************************************
Declaration of constant data
*************************************************************************/
#define NVP_START_SEC_NVP_CONST_UNSPECIFIED
#include "NVP_MemMap.h"

extern const tNvpBlockConfig                   NVP_kastBlockConfig[NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS] ;
extern const tNvpBlockConfig                   NVP_kastCalibBlockConfig[CALIB_TOTAL_NUMBER_OF_NVRAM_BLOCKS] ;

#define NVP_STOP_SEC_NVP_CONST_UNSPECIFIED
#include "NVP_MemMap.h"


/*************************************************************************
Declaration of functions
*************************************************************************/


/*************************************************************************
Evolution of the component

Created by : C.Sauvage

$Log: Nvp_Cfg.h  $
Revision 1.2.8.3 2022/11/25 08:53:11CET David Puscasu (david.puscasu) 
Update NVP generated files
Revision 1.1.1.9 2020/04/30 08:51:57EEST Lian Sun (lian.sun) 
.
Revision 1.1.1.8 2018/06/18 19:58:07CST Arthur Mahe (arthur.mahe) 
Change table calib index name
Revision 1.1.1.7 2018/06/15 11:50:24CEST Arthur Mahe (arthur.mahe) 
Update RTE for block length and block status functions
Revision 1.1.1.6 2017/05/03 15:59:57CEST Charlene Dibourg (charlene.dibourg) 
Add blocks RAM Start Addresses in the structure
Revision 1.1.1.5 2017/04/07 08:42:49CEST Charlene Dibourg (charlene.dibourg) 
Remove checksums tables and update u8BLockLength into  u16BLockLength
Revision 1.1.1.4 2017/03/30 16:02:58CEST Andrei Mestereaga (andrei.mestereaga) 
- Nvp_Cfg.h header added to BFE componenet (adding include directive to BFE_Config.h file)
 - All used deifinitions moved from compiler.h (used by Target Link libraries) to Nvp_Cfg.h file and Pmp_public.h file
Revision 1.1.1.3 2017/03/27 16:20:09EEST Charlene Dibourg (charlene.dibourg) 
Remove unused parameters
Revision 1.1.1.2 2017/02/24 09:50:08CET Michael Pastor (michael.pastor) 
MAJ PP4G R3.1E from Explo since 15/02/2017
Revision 1.1.1.1 2017/02/15 17:19:53CET Michael Pastor (michael.pastor) 
Check In modified already present files
Revision 1.1 2016/10/05 18:27:15CEST Maxime Bourdon (maxime.bourdon) 
Initial revision

*************************************************************************/

/* end of file */

#endif /* NVP_CFG_H_ */
