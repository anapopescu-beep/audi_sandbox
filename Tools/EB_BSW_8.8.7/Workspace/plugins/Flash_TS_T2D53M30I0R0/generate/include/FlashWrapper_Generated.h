#ifndef FLASHWRAPPERGENERATED_H
#define FLASHWRAPPERGENERATED_H
/*===============================================================================*/
/*                                                                               */
/*                               FLASH layers                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                              FLASH  configuration                             */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file FlashWrapper_Generated.h        */
/*%%  |                             |  %%  \brief FLASH layer implementation     */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 30.0.2                 */
/*%%  |   &       &    &            |  %%  Variant: Autosar                  */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
[!AUTOSPACING!]
/*List the needed include files*/
[!VAR "LOOP_1"="1"!]
[!VAR "NB_OF_INCLUDE"="num:dectoint(count(Include/Include/*))"!]
[!FOR "LOOP_1" = "1" TO "$NB_OF_INCLUDE"!]
  [!VAR "CURRENT_INCLUDE"="Include/Include/*[number($LOOP_1)]"!]
#include [!"$CURRENT_INCLUDE"!]
[!ENDFOR!]

/*Retrieve the Low Layer parameters names*/
/******/
/*Init*/
/******/
/*Configurations*/
#define FLW_INIT_ROUTINE_NAME                                                        [!"Init/LowerLayer/LowerLayer_Init_RoutineName"!]
#define FLW_INIT_ROUTINE_TYPEDEF                                                     FLW_TYPEDEF_CB([!"Init/LowerLayer/LowerLayer_Init_RoutineName"!])
#define FLW_INIT_ROUTINE_RETURN                                                      [!"Init/LowerLayer/LowerLayer_Init_RoutineTypeReturn"!]
[!IF "not(node:empty(Init/LowerLayer/LowerLayer_Init_RoutineTypeArg1))"!]
#define FLW_INIT_ROUTINE_TYPE_ARG1                                                   [!"Init/LowerLayer/LowerLayer_Init_RoutineTypeArg1"!]
[!ENDIF!]
[!IF "not(node:empty(Init/LowerLayer/LowerLayer_Init_RoutineTypeArg2))"!]
#define FLW_INIT_ROUTINE_TYPE_ARG2                                                   [!"Init/LowerLayer/LowerLayer_Init_RoutineTypeArg2"!]
[!ENDIF!]
[!IF "not(node:empty(Init/LowerLayer/LowerLayer_Init_RoutineTypeArg3))"!]
#define FLW_INIT_ROUTINE_TYPE_ARG3                                                   [!"Init/LowerLayer/LowerLayer_Init_RoutineTypeArg3"!]
[!ENDIF!]
[!IF "not(node:empty(Init/LowerLayer/LowerLayer_Init_RoutineTypeArg4))"!]
#define FLW_INIT_ROUTINE_TYPE_ARG4                                                   [!"Init/LowerLayer/LowerLayer_Init_RoutineTypeArg4"!]
[!ENDIF!]
[!IF "not(node:empty(Init/LowerLayer/LowerLayer_Init_RoutineTypeArg5))"!]
#define FLW_INIT_ROUTINE_TYPE_ARG5                                                   [!"Init/LowerLayer/LowerLayer_Init_RoutineTypeArg5"!]
[!ENDIF!]
#define FLW_INIT_ROUTINE_SIGNATURE                                                   (FLW_INIT_ROUTINE_TYPE_ARG1 ARG1)
#define FLW_INIT_ROUTINE_SIGNATURE_CASTED(ARG1)                                      (FLW_INIT_ROUTINE_TYPE_ARG1) ARG1
[!IF "not(Init/LowerLayer/LowerLayer_Init_RoutineTypeReturn = 'void')"!]
/*Return existing*/
#define FLW_INIT_ROUTINE_IS_RETURN_EXIST
[!ENDIF!]
/*Arguments wrapping*/
#define FLW_INIT_ROUTINE_CB_IN_ROM(ARG1)                                             FLWCbInROM_T.InitRoutine(FLW_INIT_ROUTINE_SIGNATURE_CASTED(ARG1))
[!IF "Init/Configurations/CopyROMToRAM = 'true'"!]
/*Copy low layer flash API from ROM to RAM*/
#define FLW_INIT_IS_COPY_ROM_TO_RAM
[!ENDIF!]

/*******/                                                                            
/*Erase*/                                                                            
/*******/
/*Configurations*/
#define FLW_ERASE_ROUTINE_NAME                                                       [!"Erase/LowerLayer/LowerLayer_Erase_RoutineName"!]
#define FLW_ERASE_ROUTINE_TYPEDEF                                                    FLW_TYPEDEF_CB([!"Erase/LowerLayer/LowerLayer_Erase_RoutineName"!])
#define FLW_ERASE_ROUTINE_RETURN                                                     [!"Erase/LowerLayer/LowerLayer_Erase_RoutineTypeReturn"!]
[!IF "not(node:empty(Erase/LowerLayer/LowerLayer_Erase_RoutineTypeArg1))"!]
#define FLW_ERASE_ROUTINE_TYPE_ARG1                                                  [!"Erase/LowerLayer/LowerLayer_Erase_RoutineTypeArg1"!]
[!ENDIF!]                                                                                                          
[!IF "not(node:empty(Erase/LowerLayer/LowerLayer_Erase_RoutineTypeArg2))"!]                                         
#define FLW_ERASE_ROUTINE_TYPE_ARG2                                                  [!"Erase/LowerLayer/LowerLayer_Erase_RoutineTypeArg2"!]
[!ENDIF!]                                                                                                          
[!IF "not(node:empty(Erase/LowerLayer/LowerLayer_Erase_RoutineTypeArg3))"!]                                         
#define FLW_ERASE_ROUTINE_TYPE_ARG3                                                  [!"Erase/LowerLayer/LowerLayer_Erase_RoutineTypeArg3"!]
[!ENDIF!]                                                                                                          
[!IF "not(node:empty(Erase/LowerLayer/LowerLayer_Erase_RoutineTypeArg4))"!]                                         
#define FLW_ERASE_ROUTINE_TYPE_ARG4                                                  [!"Erase/LowerLayer/LowerLayer_Erase_RoutineTypeArg4"!]
[!ENDIF!]                                                                                                          
[!IF "not(node:empty(Erase/LowerLayer/LowerLayer_Erase_RoutineTypeArg5))"!]                                         
#define FLW_ERASE_ROUTINE_TYPE_ARG5                                                  [!"Erase/LowerLayer/LowerLayer_Erase_RoutineTypeArg5"!]
[!ENDIF!]
#define FLW_ERASE_ROUTINE_SIGNATURE                                                  (FLW_ERASE_ROUTINE_TYPE_ARG1 ARG1, FLW_ERASE_ROUTINE_TYPE_ARG2 ARG2)
#define FLW_ERASE_ROUTINE_SIGNATURE_CASTED(ARG1,ARG2)                                (FLW_ERASE_ROUTINE_TYPE_ARG1) ARG1, (FLW_ERASE_ROUTINE_TYPE_ARG2) ARG2
[!IF "Erase/Configurations/EraseCriticalSectionMngt = 'true'"!]
/*Critical section management*/
#define FLW_ERASE_IS_CRITICAL_SECTION_MNGT
[!ENDIF!]
[!IF "not(Erase/LowerLayer/LowerLayer_Erase_RoutineTypeReturn = 'void')"!]
/*Return existence*/
#define FLW_ERASE_ROUTINE_IS_RETURN_EXIST
[!ENDIF!]
/*Arguments wrapping*/
#define FLW_ERASE_ROUTINE_CB_IN_ROM(ARG1,ARG2)                                       FLWCbInROM_T.EraseRoutine(FLW_ERASE_ROUTINE_SIGNATURE_CASTED([!"text:toupper(substring(Erase/ArgsWrapper/UpperLayer_Erase_RoutineTypeArg1,string-length('LowerLayer_Erase_RoutineType') + 1, 4))"!],\
                                                                                                                                                  [!"text:toupper(substring(Erase/ArgsWrapper/UpperLayer_Erase_RoutineTypeArg2,string-length('LowerLayer_Erase_RoutineType') + 1, 4))"!]))
[!IF "General/CustomWrapperUsing = 'true'"!]
#define FLW_ERASE_ROUTINE_CB_IN_RAM(ARG1,ARG2)                                       FLWCbInRAM_T.EraseRoutine(FLW_ERASE_ROUTINE_SIGNATURE_CASTED([!"text:toupper(substring(Erase/ArgsWrapper/UpperLayer_Erase_RoutineTypeArg1,string-length('LowerLayer_Erase_RoutineType') + 1, 4))"!],\
                                                                                                                                                  [!"text:toupper(substring(Erase/ArgsWrapper/UpperLayer_Erase_RoutineTypeArg2,string-length('LowerLayer_Erase_RoutineType') + 1, 4))"!]))
[!ENDIF!]

/*******/
/*Write*/
/*******/
/*Configurations*/
#define FLW_WRITE_ROUTINE_NAME                                                       [!"Write/LowerLayer/LowerLayer_Write_RoutineName"!]
#define FLW_WRITE_ROUTINE_TYPEDEF                                                    FLW_TYPEDEF_CB([!"Write/LowerLayer/LowerLayer_Write_RoutineName"!])
#define FLW_WRITE_ROUTINE_RETURN                                                     [!"Write/LowerLayer/LowerLayer_Write_RoutineTypeReturn"!]
[!IF "not(node:empty(Write/LowerLayer/LowerLayer_Write_RoutineTypeArg1))"!]
#define FLW_WRITE_ROUTINE_TYPE_ARG1                                                  [!"Write/LowerLayer/LowerLayer_Write_RoutineTypeArg1"!]
[!ENDIF!]                                                                                                          
[!IF "not(node:empty(Write/LowerLayer/LowerLayer_Write_RoutineTypeArg2))"!]                                         
#define FLW_WRITE_ROUTINE_TYPE_ARG2                                                  [!"Write/LowerLayer/LowerLayer_Write_RoutineTypeArg2"!]
[!ENDIF!]                                                                                                          
[!IF "not(node:empty(Write/LowerLayer/LowerLayer_Write_RoutineTypeArg3))"!]                                         
#define FLW_WRITE_ROUTINE_TYPE_ARG3                                                  [!"Write/LowerLayer/LowerLayer_Write_RoutineTypeArg3"!]
[!ENDIF!]                                                                                                          
[!IF "not(node:empty(Write/LowerLayer/LowerLayer_Write_RoutineTypeArg4))"!]                                         
#define FLW_WRITE_ROUTINE_TYPE_ARG4                                                  [!"Write/LowerLayer/LowerLayer_Write_RoutineTypeArg4"!]
[!ENDIF!]                                                                                                          
[!IF "not(node:empty(Write/LowerLayer/LowerLayer_Write_RoutineTypeArg5))"!]
#define FLW_WRITE_ROUTINE_TYPE_ARG5                                                  [!"Write/LowerLayer/LowerLayer_Write_RoutineTypeArg5"!]
[!ENDIF!]
#define FLW_WRITE_ROUTINE_SIGNATURE                                                  (FLW_WRITE_ROUTINE_TYPE_ARG1 ARG1, FLW_WRITE_ROUTINE_TYPE_ARG2 ARG2, FLW_WRITE_ROUTINE_TYPE_ARG3 ARG3)
#define FLW_WRITE_ROUTINE_SIGNATURE_CASTED(ARG1,ARG2,ARG3)                           (FLW_WRITE_ROUTINE_TYPE_ARG1) ARG1, (FLW_WRITE_ROUTINE_TYPE_ARG2) ARG2, (FLW_WRITE_ROUTINE_TYPE_ARG3) ARG3
[!IF "Write/Configurations/WriteCriticalSectionMngt = 'true'"!]
/*Critical section management*/
#define FLW_WRITE_IS_CRITICAL_SECTION_MNGT
[!ENDIF!]
[!IF "not(Write/LowerLayer/LowerLayer_Write_RoutineTypeReturn = 'void')"!]
/*Return existence*/
#define FLW_WRITE_ROUTINE_IS_RETURN_EXIST
[!ENDIF!]
/*Arguments wrapping*/
#define FLW_WRITE_ROUTINE_CB_IN_ROM(ARG1,ARG2,ARG3)                                  FLWCbInROM_T.WriteRoutine(FLW_WRITE_ROUTINE_SIGNATURE_CASTED([!"text:toupper(substring(Write/ArgsWrapper/UpperLayer_Write_RoutineTypeArg1,string-length('LowerLayer_Write_RoutineType') + 1, 4))"!],\
                                                                                                                                                  [!"text:toupper(substring(Write/ArgsWrapper/UpperLayer_Write_RoutineTypeArg2,string-length('LowerLayer_Write_RoutineType') + 1, 4))"!],\
                                                                                                                                                  [!"text:toupper(substring(Write/ArgsWrapper/UpperLayer_Write_RoutineTypeArg3,string-length('LowerLayer_Write_RoutineType') + 1, 4))"!]))
[!IF "General/CustomWrapperUsing = 'true'"!]
#define FLW_WRITE_ROUTINE_CB_IN_RAM(ARG1,ARG2,ARG3)                                  FLWCbInRAM_T.WriteRoutine(FLW_WRITE_ROUTINE_SIGNATURE_CASTED([!"text:toupper(substring(Write/ArgsWrapper/UpperLayer_Write_RoutineTypeArg1,string-length('LowerLayer_Write_RoutineType') + 1, 4))"!],\
                                                                                                                                                  [!"text:toupper(substring(Write/ArgsWrapper/UpperLayer_Write_RoutineTypeArg2,string-length('LowerLayer_Write_RoutineType') + 1, 4))"!],\
                                                                                                                                                  [!"text:toupper(substring(Write/ArgsWrapper/UpperLayer_Write_RoutineTypeArg3,string-length('LowerLayer_Write_RoutineType') + 1, 4))"!]))
[!ENDIF!]																																				  

/******/
/*Read*/
/******/
/*Configurations*/
#define FLW_READ_ROUTINE_NAME                                                        [!"Read/LowerLayer/LowerLayer_Read_RoutineName"!]
#define FLW_READ_ROUTINE_TYPEDEF                                                     FLW_TYPEDEF_CB([!"Read/LowerLayer/LowerLayer_Read_RoutineName"!])
#define FLW_READ_ROUTINE_RETURN                                                      [!"Read/LowerLayer/LowerLayer_Read_RoutineTypeReturn"!]
[!IF "not(node:empty(Read/LowerLayer/LowerLayer_Read_RoutineTypeArg1))"!]
#define FLW_READ_ROUTINE_TYPE_ARG1                                                   [!"Read/LowerLayer/LowerLayer_Read_RoutineTypeArg1"!]
[!ENDIF!]                                                                                                          
[!IF "not(node:empty(Read/LowerLayer/LowerLayer_Read_RoutineTypeArg2))"!]                                              
#define FLW_READ_ROUTINE_TYPE_ARG2                                                   [!"Read/LowerLayer/LowerLayer_Read_RoutineTypeArg2"!]
[!ENDIF!]                                                                                                           
[!IF "not(node:empty(Read/LowerLayer/LowerLayer_Read_RoutineTypeArg3))"!]                                               
#define FLW_READ_ROUTINE_TYPE_ARG3                                                   [!"Read/LowerLayer/LowerLayer_Read_RoutineTypeArg3"!]
[!ENDIF!]                                                                                                           
[!IF "not(node:empty(Read/LowerLayer/LowerLayer_Read_RoutineTypeArg4))"!]                                               
#define FLW_READ_ROUTINE_TYPE_ARG4                                                   [!"Read/LowerLayer/LowerLayer_Read_RoutineTypeArg4"!]
[!ENDIF!]                                                                                                      
[!IF "not(node:empty(Read/LowerLayer/LowerLayer_Read_RoutineTypeArg5))"!]                                          
#define FLW_READ_ROUTINE_TYPE_ARG5                                                   [!"Read/LowerLayer/LowerLayer_Read_RoutineTypeArg5"!]
[!ENDIF!]
#define FLW_READ_ROUTINE_SIGNATURE                                                   (FLW_READ_ROUTINE_TYPE_ARG1 ARG1, FLW_READ_ROUTINE_TYPE_ARG2 ARG2, FLW_READ_ROUTINE_TYPE_ARG3 ARG3)
#define FLW_READ_ROUTINE_SIGNATURE_CASTED(ARG1,ARG2,ARG3)                            (FLW_READ_ROUTINE_TYPE_ARG1) ARG1, (FLW_READ_ROUTINE_TYPE_ARG2) ARG2, (FLW_READ_ROUTINE_TYPE_ARG3) ARG3
[!IF "not(Read/LowerLayer/LowerLayer_Read_RoutineTypeReturn = 'void')"!]
/*Return existence*/
#define FLW_READ_ROUTINE_IS_RETURN_EXIST
[!ENDIF!]
/*Arguments wrapping*/
#define FLW_READ_ROUTINE_CB_IN_ROM(ARG1,ARG2,ARG3)                                   FLWCbInROM_T.ReadRoutine(FLW_READ_ROUTINE_SIGNATURE_CASTED([!"text:toupper(substring(Read/ArgsWrapper/UpperLayer_Read_RoutineTypeArg1,string-length('LowerLayer_Read_RoutineType') + 1, 4))"!],\
                                                                                                                                                [!"text:toupper(substring(Read/ArgsWrapper/UpperLayer_Read_RoutineTypeArg2,string-length('LowerLayer_Read_RoutineType') + 1, 4))"!],\
                                                                                                                                                [!"text:toupper(substring(Read/ArgsWrapper/UpperLayer_Read_RoutineTypeArg3,string-length('LowerLayer_Read_RoutineType') + 1, 4))"!]))
[!IF "General/CustomWrapperUsing = 'true'"!]
/*Build the arguments which will feed the "FLW_READ_ROUTINE_NAME" API*/
#define FLW_READ_ROUTINE_ADDRESS_ARG        [!"text:toupper(substring(Read/ArgsWrapper/UpperLayer_Read_RoutineTypeArg1,string-length('LowerLayer_Read_RoutineType') + 1, 4))"!]
#define FLW_READ_ROUTINE_LENGHT_ARG         [!"text:toupper(substring(Read/ArgsWrapper/UpperLayer_Read_RoutineTypeArg2,string-length('LowerLayer_Read_RoutineType') + 1, 4))"!]
#define FLW_READ_ROUTINE_POINTER_DATA_ARG   [!"text:toupper(substring(Read/ArgsWrapper/UpperLayer_Read_RoutineTypeArg3,string-length('LowerLayer_Read_RoutineType') + 1, 4))"!]
[!ENDIF!]

/******/
/*Main*/
/******/
/*Configurations*/
#define FLW_MAIN_ROUTINE_NAME                                                        [!"Main/LowerLayer/LowerLayer_Main_RoutineName"!]
#define FLW_MAIN_ROUTINE_TYPEDEF                                                     FLW_TYPEDEF_CB([!"Main/LowerLayer/LowerLayer_Main_RoutineName"!])
#define FLW_MAIN_ROUTINE_RETURN                                                      [!"Main/LowerLayer/LowerLayer_Main_RoutineTypeReturn"!]
[!IF "not(node:empty(Main/LowerLayer/LowerLayer_Main_RoutineTypeArg1))"!]
#define FLW_MAIN_ROUTINE_TYPE_ARG1                                                   [!"Main/LowerLayer/LowerLayer_Main_RoutineTypeArg1"!]
[!ENDIF!]                                                                                                          
[!IF "not(node:empty(Main/LowerLayer/LowerLayer_Main_RoutineTypeArg2))"!]                                              
#define FLW_MAIN_ROUTINE_TYPE_ARG2                                                   [!"Main/LowerLayer/LowerLayer_Main_RoutineTypeArg2"!]
[!ENDIF!]                                                                                                           
[!IF "not(node:empty(Main/LowerLayer/LowerLayer_Main_RoutineTypeArg3))"!]                                               
#define FLW_MAIN_ROUTINE_TYPE_ARG3                                                   [!"Main/LowerLayer/LowerLayer_Main_RoutineTypeArg3"!]
[!ENDIF!]                                                                                                           
[!IF "not(node:empty(Main/LowerLayer/LowerLayer_Main_RoutineTypeArg4))"!]                                               
#define FLW_MAIN_ROUTINE_TYPE_ARG4                                                   [!"Main/LowerLayer/LowerLayer_Main_RoutineTypeArg4"!]
[!ENDIF!]                                                                                                      
[!IF "not(node:empty(Main/LowerLayer/LowerLayer_Main_RoutineTypeArg5))"!]                                          
#define FLW_MAIN_ROUTINE_TYPE_ARG5                                                   [!"Main/LowerLayer/LowerLayer_Main_RoutineTypeArg5"!]
[!ENDIF!]
#define FLW_MAIN_ROUTINE_SIGNATURE                                                   (void)      
#define FLW_MAIN_ROUTINE_SIGNATURE_CASTED()
[!IF "not(Main/LowerLayer/LowerLayer_Main_RoutineTypeReturn = 'void')"!]
/*Return existence*/
#define FLW_MAIN_ROUTINE_IS_RETURN_EXIST
[!ENDIF!]
/*Arguments wrapping*/
#define FLW_MAIN_ROUTINE_CB_IN_ROM()                                                      FLWCbInROM_T.MainRoutine(FLW_MAIN_ROUTINE_SIGNATURE_CASTED())

/***********/
/*JobStatus*/
/***********/
/*Configurations*/
#define FLW_JOBSTATUS_ROUTINE_NAME                                                        [!"JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineName"!]
#define FLW_JOBSTATUS_ROUTINE_TYPEDEF                                                     FLW_TYPEDEF_CB([!"JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineName"!])
#define FLW_JOBSTATUS_ROUTINE_RETURN                                                      [!"JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineTypeReturn"!]
[!IF "not(node:empty(JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineTypeArg1))"!]
#define FLW_JOBSTATUS_ROUTINE_TYPE_ARG1                                                   [!"JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineTypeArg1"!]
[!ENDIF!]                                                                                                          
[!IF "not(node:empty(JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineTypeArg2))"!]                                              
#define FLW_JOBSTATUS_ROUTINE_TYPE_ARG2                                                   [!"JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineTypeArg2"!]
[!ENDIF!]                                                                                                           
[!IF "not(node:empty(JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineTypeArg3))"!]                                               
#define FLW_JOBSTATUS_ROUTINE_TYPE_ARG3                                                   [!"JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineTypeArg3"!]
[!ENDIF!]                                                                                                           
[!IF "not(node:empty(JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineTypeArg4))"!]                                               
#define FLW_JOBSTATUS_ROUTINE_TYPE_ARG4                                                   [!"JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineTypeArg4"!]
[!ENDIF!]                                                                                                      
[!IF "not(node:empty(JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineTypeArg5))"!]                                          
#define FLW_JOBSTATUS_ROUTINE_TYPE_ARG5                                                   [!"JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineTypeArg5"!]
[!ENDIF!]
#define FLW_JOBSTATUS_ROUTINE_SIGNATURE                                                   (void)
#define FLW_JOBSTATUS_ROUTINE_SIGNATURE_CASTED()
[!IF "not(JobStatus/LowerLayer/LowerLayer_JobStatus_RoutineTypeReturn = 'void')"!]
/*Return existence*/
#define FLW_JOBSTATUS_ROUTINE_IS_RETURN_EXIST
[!ENDIF!]
/*Arguments wrapping*/
#define FLW_JOBSTATUS_ROUTINE_CB_IN_ROM()                                                 FLWCbInROM_T.JobStatusRoutine(FLW_JOBSTATUS_ROUTINE_SIGNATURE_CASTED())

[!IF "General/CustomWrapperUsing = 'true'"!]
/******************************/
/*Specific Wrapping operations*/
/******************************/
/*The configuration request to used custom wrapping*/
#define FLW_CUSTOM_WRAPPER_USED

#define FLW_WRAPPER_INIT_ROUTINE_NAME                                                 [!"Init/CustomWrapperInit/FLW_CustomWrapperInit_RoutineName"!]
#define FLW_WRAPPER_ERASE_ROUTINE_NAME                                                [!"Erase/CustomWrapperErase/FLW_CustomWrapperErase_RoutineName"!]
#define FLW_WRAPPER_WRITE_ROUTINE_NAME                                                [!"Write/CustomWrapperWrite/FLW_CustomWrapperWrite_RoutineName"!]

/*Macro which enable to set the function name to call for the wrapper init*/
#define FLW_WRAPPER_INIT(ARG1)                                                        FLW_WRAPPER_INIT_ROUTINE_NAME(ARG1)
[!ELSE!]
/*******/
/*Dummy*/
/*******/
/*Dummy macro to allow the compilation*/
#define FLW_WRAPPER_INIT(ARG1)
[!ENDIF!]
#endif
