@echo off
set "arg1=%1"
set "arg2=%2"

call env_cfg.bat

set ECLIPSE_EXE=%ECLIPSE_INSTALLATION_DIR%\eclipse.exe
set ECLIPSE_WORKSPACE=%~dp0\..\..\..\..\Tools\Eclipse\Workspace\eclipse_workspace

if "%arg1%"=="import_workspace" (
set ECLIPSE_PROJECT=%~dp0\..\..\..\..\Tools\Eclipse\Workspace\eclipse_project\%arg2%
)

if "%arg1%"=="import_workspace" (
	if not exist %ECLIPSE_WORKSPACE% mkdir %ECLIPSE_WORKSPACE%
	%ECLIPSE_EXE% -nosplash -application org.eclipse.cdt.managedbuilder.core.headlessbuild -import %ECLIPSE_PROJECT% -data %ECLIPSE_WORKSPACE% 
	goto End
)

if "%arg1%"=="post_import_workspace" (
xcopy /E /Y /Q %~dp0\..\..\..\..\Tools\Eclipse\Config\.settings\*.* %ECLIPSE_WORKSPACE%\.metadata\.plugins\org.eclipse.core.runtime\.settings\
xcopy /E /Y /Q %~dp0\..\..\..\..\Tools\Eclipse\Config\.launches\*.* %ECLIPSE_WORKSPACE%\.metadata\.plugins\org.eclipse.debug.core\.launches\
)
	
start %ECLIPSE_EXE% -refresh -data %ECLIPSE_WORKSPACE%
goto End

:End