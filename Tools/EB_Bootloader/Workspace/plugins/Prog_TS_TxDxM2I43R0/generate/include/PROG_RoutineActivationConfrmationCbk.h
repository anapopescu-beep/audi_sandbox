#ifndef PROG_ROUTINEACTIVATIONCONFIRMATIONCBK_H
#define PROG_ROUTINEACTIVATIONCONFIRMATIONCBK_H

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
/*%%   _____________________________   %%  \file PROG_RoutineActivationConfrmationCbk.h                      */
/*%%  |                             |  %%  \brief PROG layer source plugin file  */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.43.0 BL3 */
/*%%  |   &       &    &            |  %%                                        */
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
[!AUTOSPACING!]

[!IF "as:modconf('BlPduR')/General/Eth_Protocol_Supported = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_RoutineActivationConfrmationCbk.h:31:IF1 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "node:exists(as:modconf('DoIP'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_RoutineActivationConfrmationCbk.h:32:IF2 osc_PROG main ', $project))"!][!ENDSELECT!]
extern Std_ReturnType PROG_DoIpRoutineActivationRxConfirmationCbk(
    P2VAR(boolean, AUTOMATIC, DOIP_APPL_DATA) Authentified,
    P2CONST(uint8, AUTOMATIC, DOIP_APPL_DATA) AuthenticationReqData,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_DATA) AuthenticationResData);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_RoutineActivationConfrmationCbk.h:37:DUMMYELSE3 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_RoutineActivationConfrmationCbk.h:38:DUMMYELSE4 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

#endif      /* PROG_ROUTINEACTIVATIONCBK_H */
