@echo off
echo.
SETLOCAL

IF [%1]==[] goto noArgumentserror
IF NOT DEFINED JAVA_CMD SET JAVA_CMD=java

REM pushd %~dp0..\ArtopCmd
SET ARTOP_CMD="%~dp0..\ArtopCmd\plugins"
IF EXIST "%CD%/tempworkspace" SET WORKSPACE_EXISTS=TRUE

call %JAVA_CMD% -jar "%ARTOP_CMD%\org.eclipse.equinox.launcher_1.5.700.v20200207-2156.jar" -data "%CD%/tempworkspace" -application com.elektrobit.asr.artop.command.core.artopcmd -Tool:ECUEXTRACTUPDATER %*
IF ERRORLEVEL 3 goto fatalError

IF NOT DEFINED WORKSPACE_EXISTS (
	IF NOT DEFINED DEBUG_MODE (
		RD /S /Q "%CD%/tempworkspace"
	) 
) 

if ERRORLEVEL 1 goto error

goto end


:error
echo [ERROR] ECUExtractUpdate returned errors!
goto end

:fatalError
echo [ERROR] ECUExtractUpdate returned fatal errors!
goto end

:noArgumentserror
echo [ERROR] No arguments in the ECUExtractUpdate!

:end
EXIT /B ERRORLEVEL


