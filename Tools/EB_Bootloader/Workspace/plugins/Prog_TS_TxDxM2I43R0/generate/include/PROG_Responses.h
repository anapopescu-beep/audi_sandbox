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
/*%%   _____________________________   %%  \file PROG_Responses.h                */
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
/* Copyright 2017 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/
[!NOCODE!]
[!/* Activate generation of the file*/!]
[!IF "not((node:exists(as:modconf('ProgOEMInd'))) or (node:exists(as:modconf('ProgVAG'))))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Responses.h:28:IF1 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!SKIPFILE!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Responses.h:30:DUMMYELSE2 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ENDNOCODE!]

#ifndef PROG_RESPONSES_H
#define PROG_RESPONSES_H

/*=============================== FILE INCLUSION ================================*/
/*                                                                               */

[!AUTOSPACING!]
/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */
[!IF "node:exists(as:modconf('ProgOEMInd'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Responses.h:42:IF3 osc_PROG main ', $project))"!][!ENDSELECT!]

extern void PROG_Custom_EraseRoutine_Succeed(u8 * Data, PduLengthType * DataLength);

extern void PROG_Custom_EraseRoutine_Failed(u8 * Data, PduLengthType * DataLength, tUdsStatus * eUdsStatus);


extern void PROG_Custom_CheckMemoryRoutine_Succeed(u8 * Data, PduLengthType  * DataLength);

extern void PROG_Custom_CheckMemoryRoutine_Failed(u8 * Data, PduLengthType  * DataLength, tUdsStatus * eUdsStatus);

[!IF "General/Check_Programming_PreConditions = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Responses.h:53:IF4 osc_PROG main ', $project))"!][!ENDSELECT!]
extern void PROG_Custom_PreCondCheckRoutine_Succeed(u8 * Data, PduLengthType  * DataLength);

extern void PROG_Custom_PreCondCheckRoutine_Failed(u8 * Data, PduLengthType  * DataLength, tUdsStatus * eUdsStatus);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Responses.h:57:DUMMYELSE5 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

extern void PROG_Custom_CheckProgDepRoutine_Succeed(u8 * Data, PduLengthType * DataLength);

extern void PROG_Custom_CheckProgDepRoutine_Failed(u8 * Data, PduLengthType * DataLength, tUdsStatus * eUdsStatus);

[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Responses.h:63:DUMMYELSE6 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgVAG'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Responses.h:65:IF7 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "General/Check_Programming_PreConditions = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Responses.h:66:IF8 osc_PROG main ', $project))"!][!ENDSELECT!]
extern void PROG_Custom_PreCondCheckRoutine_Succeed(u8 * Data, PduLengthType * DataLength);

extern void PROG_Custom_PreCondCheckRoutine_Failed(u8 * Data, PduLengthType * DataLength, tUdsStatus * eUdsStatus);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Responses.h:70:DUMMYELSE9 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Responses.h:71:DUMMYELSE10 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

#endif /* PROG_RESPONSES_H */
