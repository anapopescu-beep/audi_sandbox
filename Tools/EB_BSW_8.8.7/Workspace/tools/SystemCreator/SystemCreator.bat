@echo off
echo.
SETLOCAL

IF [%1]==[] goto noArgumentserror
IF NOT DEFINED JAVA_CMD SET JAVA_CMD=java

IF EXIST "%CD%/tempworkspace" SET WORKSPACE_EXISTS=TRUE

SET ARTOP_CMD="%~dp0..\ArtopCmd\plugins"
call %JAVA_CMD% -jar "%ARTOP_CMD%\org.eclipse.equinox.launcher_1.5.700.v20200207-2156.jar" -data "%CD%/tempworkspace" -application com.elektrobit.asr.artop.command.core.artopcmd -Tool:SYSTEMCREATOR %*
if ERRORLEVEL 3 goto fatalError

IF NOT DEFINED WORKSPACE_EXISTS (
	IF NOT DEFINED DEBUG_MODE (
		RD /S /Q "%CD%/tempworkspace"
	) 
) 

if ERRORLEVEL 1 goto error

goto end

:error
echo [ERROR] SystemCreator returned errors!
goto end

:fatalError
echo [ERROR] SystemCreator returned fatal errors!
goto end

:noArgumentserror
echo [ERROR] No arguments in the SystemCreator!

:end
EXIT /B ERRORLEVEL
