/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               BM layer                                        */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file BM_Cbk.h                        */
/*%%  |                             |  %%  \brief BM layer include plugin file   */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 1.13.0 BL3                */
/*%%  |   &       &    &            |  %%  Variant: OsekCore                  */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/



#ifndef BM_CBK_H
#define BM_CBK_H
/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/* - Public Callback Prototypes                                                  */


/** \brief Callback that shall disable ECC if needed
 ** Callback is called: When Bootloader perform read access on Flash that can be
 **                     unprogrammed and can cause ECC error
 **
 ** Callback shall implement: If needed, disabling of ECC check
 **                           Hardware specific)
 **/
extern void BM_DisableECCCheck(void);

/** \brief Callback that shall enable ECC if needed
 ** Callback is called: After Bootloader has performed a read access on Flash
 **                    that can be unprogrammed and can cause ECC error
 **
 ** Callback shall implement: If needed, enabling of ECC check
 **                          (Hardware specific)
 **/
extern void BM_EnableECCCheck(void);




/** \brief Software RAM initialization
 **
 ** This function is called at the very beginning of the Boot manager.
 ** It allows the application to do the minimum software initialization
 ** before the Boot manager start to check the application validity.
 **
 **/
extern void BM_SoftwareInit(void);

/** \brief Hardware initialization
 **
 ** This function is called at the very beginning of the Boot manager.
 ** It allows the application to do the minimum hardware initialization
 ** before the Boot manager start to check the application validity.
 **
 **/
extern void BM_HardwareInit (void);

/** \brief Get the diagnostic tester source address
 **
 ** This function is called when programming is requested by
 ** application (eBootFromAppli = BM_TRUE) and BM_SOURCE_ADDRESS_CHECK is set.
 ** This is a callback that get the tester address
 **
 ** \param[in,out] ubTesterAddress pointer on tester address
 **
 **/
#if (BM_SOURCE_ADDRESS_CHECK == STD_ON)
extern void BM_GetTesterAddress (u8 *ubTesterAddress);
#endif









#if (BM_CSM_MAC_USED == STD_ON)
/** \brief Get the mac key used in Mac verification (should be the same key used in the generation)
 **
 ** This function is called at the beginning of the Mac verification to get the key yo be used in the process
 **
 **/
extern void BM_CustomGetMacKey(const u8** paubKeyData, u32* pulKeyLength);
#endif
/*                                                                               */
/*===============================================================================*/




#endif      /* BM_CBK_H */
