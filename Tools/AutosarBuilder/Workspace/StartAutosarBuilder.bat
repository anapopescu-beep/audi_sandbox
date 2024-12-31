@echo off
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: 
:: AUTOLIV ELECTRONIC document.
:: 
:: :::::::::::::::::::::::::::::::::::
:: DUPLICATION or DISCLOSURE PROHIBITED without prior written consent
:: 
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: 
:: Use this file to start Autosar Builder.
:: 
:: Current revision: $Revision: 1.1.6.3 $
:: Checked in: 		$Date: 2023/03/30 12:35:48CEST $
:: 
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::if exist %HOMEPATH%\Environment.bat (call "%HOMEPATH%\Environment.bat")

REM If S: drive does not exist abort procedure
REM IF NOT EXIST S: (goto :ERR_SDRIVE)

REM Set location of batch file (to allow script to work when batch file is called from outside its folder)
REM S:
cd %~dp0

call "Environment.bat"

call "ServicesComponents.bat"

if exist "%~dp0\..\..\..\Scripts\AutosarBuilder\arxml_description_cleaner\Executables" (
"%~dp0\..\..\..\Scripts\AutosarBuilder\arxml_description_cleaner\Executables\arxml_description_cleaner.exe" "-f=%~dp0\..\..\..\Scripts\AutosarBuilder\arxml_description_cleaner\Executables\arxml_description_cleaner.yaml"
)

if "%ABLIC%" NEQ "" set LM_LICENSE_FILE=%ABLIC%

:: Local workspace
set LOCAL-WS=_EWS-AB

if not exist "%ABEXE%" goto ERR
if not exist "%ABWSREF%" goto ERR

if not exist "%LOCAL-WS%" (echo Copying reference Workspace... & xcopy "%ABWSREF%" "%LOCAL-WS%" /S /E /I /H /Q)

:SKIPCOPY
if exist "flex*.log" del /S /Q /F "flex*.log"
start "Autosar Builder" "%ABEXE%" -clean -data "%LOCAL-WS%" -alvImport "ABProjects"
goto EXIT

:ERR
echo Environmental variable ABEXE=[%ABEXE%] pointing to installation of Autosar Builder is not set or incorrect!
pause

:EXIT
echo All done.

:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: Evolution of the component
:: 
:: Created by : E. Kagan
:: 
:: $Log: StartAutosarBuilder.bat  $
:: Revision 1.1.6.3 2023/03/30 12:35:48CEST Dan Dustinta (dan.dustinta) 
:: update .bat
:: Revision 1.1.6.2 2022/10/17 12:56:03EEST Andrei Anca (andrei.anca) 
:: Initial revision
:: Member added to project e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Tools/AutosarBuilder/Workspace/project.pj
:: Revision 1.1 2021/08/26 09:18:06EEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
:: Initial revision
:: Member added to project e:/MKSProjects/SBE/Innovation/ECS/Phase_01/Tools/AutosarBuilder/Workspace/project.pj
:: Revision 1.1 2019/08/22 10:22:48CEST Gaetan Lievre (gaetan.lievre) 
:: Initial revision
:: Member added to project e:/MKSProjects/AEM/Frame_Platforms/S32K144/Phase_01/View_Development/Tools/AutosarBuilder/Workspace/project.pj
:: Revision 1.1 2019/06/25 16:21:01CEST Nicolas Bianchi (nicolas.bianchi) 
:: Initial revision
:: Member added to project e:/MKSProjects/DEV_KIT/S32K/Phase_01/Tools/AutosarBuilder/Workspace/project.pj
:: Revision 1.1.1.3 2017/02/15 17:47:48CET michael.pastor 
:: Check In modified already present files
:: Revision 1.1 2016/12/14 08:47:30CET Maxime Bourdon (maxime.bourdon) 
:: Initial revision
:: Member added to project e:/MKSProjects/err_generic/Exploration/Extended/PP4G_R31E/Tools/AutosarBuilder/Workspace/project.pj
:: Revision 1.1 2016/12/14 08:47:30CET Maxime Bourdon (maxime.bourdon) 
:: Initial revision
:: Member added to project e:/MKSProjects/err_generic/Exploration/PP4G_Extended/Tools/AutosarBuilder/Workspace/project.pj
:: Revision 1.2 2016/11/03 14:58:17CET Audrey Vache (audrey.vache) 
:: Update script to allow launching tool from ooutside the sandbox
:: Revision 1.1 2016/10/05 10:54:44CEST Michael Pastor (michael.pastor) 
:: Initial revision
:: Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Tools/AutosarBuilder/Workspace/project.pj
:: Revision 1.2 2016/10/04 08:54:27CEST Audrey Vache (audrey.vache) 
:: Check S drive before opening AB
:: Revision 1.1 2016/09/30 14:23:56CEST Michael Pastor (michael.pastor) 
:: Initial revision
:: Member added to project e:/MKSProjects/err_generic/Exploration/Automation/PropagationProject_R3.0M/PP4G/Platform_Mainstream_Phase_01/Core/Tools/AutosarBuilder/Workspace/Workspace.pj
:: Revision 1.2 2016/08/04 14:15:34CEST Maxime Bourdon (maxime.bourdon) 
:: Create SCM connexion for MMG, CIL connexion with Algo flags for Measurement frames block 24, rename SBC MUX autotest and remove it for the moment
:: Revision 1.1 2015/09/17 14:57:01CEST Maxime Bourdon (mbourdon) 
:: Initial revision
:: Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/SystemAuthoring/project.pj
:: Revision 1.3 2015/08/10 07:43:19EDT Eugene Kagan (ekagan) 
:: Added local licence set up
:: Revision 1.2 2015/06/30 11:59:00EDT Eugene Kagan (ekagan) 
:: Adding environment set up call
:: Revision 1.1 2014/10/01 09:12:22EDT Eugene Kagan (ekagan) 
:: Initial revision
:: Member added to project e:/FoundationLibrary/UtilityLibrary/ToolLibrary/MBCGUtilities/Test/TestModel/SystemAuthoring/project.pj
:: 
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


