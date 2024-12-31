/*********************************************************************************/
/*                                                                               */
/*                                BOOT Layers                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                                 PROG_VAG configuration                        */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_VAG_Cbk.h                  */
/*%%  |                             |  %%  \brief PROG layer include plugin file */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 0.13.0 BL3              */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*********************************************************************************/
/* Copyright 2021 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*********************************************************************************/

[!AUTOSPACING!]


#ifndef PROGVAG_CBK_H
#define PROGVAG_CBK_H

[!IF "(as:modconf('Prog')/VAG/Downgrade_Protection = 'true')"!]
/*---------------------------{PROG_CustomGetRfsVMinimum}----------------------------*/
extern tProgStatus PROG_CustomGetRfsVMinimum(u8 ubLogicalBlock, u8* pubRfsVMinimum);

/*---------------------------{PROG_CustomGetRfsVCurrent}----------------------------*/
extern tProgStatus PROG_CustomGetRfsVCurrent(u8 ubLogicalBlock, u8* pubRfsVCurrent);

/*---------------------------{PROG_CustomGetRfsVLB}----------------------------*/
extern tProgStatus PROG_CustomGetRfsVLB(u8 ubLogicalBlock, u8* pubRfsVLB);

/*---------------------------{PROG_CustomStoreRfsVCurrent}----------------------------*/
extern tProgStatus PROG_CustomStoreRfsVCurrent(u8 ubLogicalBlock, const u8* pubRfsVCurrent);
[!ENDIF!]
#endif     /* PROGVAG_CBK_H */
