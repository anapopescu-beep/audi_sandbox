@echo off
rem *****************************************************************************
rem * CYGWIN_DIR has to be set to Make_support root directory or to a cygwin dist
rem * There MUSTN'T be any blanks between the '=' sign and the path string
rem * Example: 
rem *     set CYGWIN_DIR=..\..\Make_support
rem *****************************************************************************

set "CYGWIN_DIR=%~dp0\Make_support"
set "BUILD_PATH=%~dp0\Makefile"

rem *****************************************************************************
rem * COMPILER_DIR has to be set to compiler root directory
rem * There MUSTN'T be any blanks between the '=' sign and the path string
rem * Example: 
rem *     set COMPILER_DIR=C:\COSMIC\CXS12Z
rem *****************************************************************************

set COMPILER_DIR=c:\Program Files (x86)\IAR Systems\Embedded Workbench 8.3\arm\bin\

rem *****************************************************************************
rem * THREAD has to be set in order to enable or disable parralel execution
rem * of receipes. Leave blank for maximum amount of available threads(fastest).
rem *****************************************************************************
set THREAD=

set SRECORD_BASE=srecord-1.63-win32
set ECLIPSE_BASE=eclipse-embedcpp-2022-03
set CYCLONE_BASE=cyclone_universal
set HEXVIEW_BASE=HexView-1.12.02
set PYTHON_BASE=python-3.11.1
set VERA_BASE=vera++
set ZIP_INSTALLER_BASE=zip_installer-1.0.1-py3-none-any
set BUILD_ENV_BASE=build_assist-2.0.0-py3-none-any
set CONFIG_MANAGEMENT_BASE=configuration_manangement_assist-1.0.0-py3-none-any

set "SW_DEV_TOOLS_DIR=c:\Prog"

set "SRECORD_DIR=%~dp0\..\..\..\srecord\Installation"
set "ECLIPSE_DIR=%~dp0\..\..\..\Eclipse\Installation"
set "ECLIPSE_CONFIG_DIR=%~dp0\..\..\..\Eclipse\Config"
set "CYCLONE_DIR=%~dp0\..\..\..\Cyclone_Universal\Installation"
set "HEXVIEW_DIR=%~dp0\..\..\..\HexView\Installation"
set "PYTHON_DIR=%~dp0\..\..\..\Python\Installation"
set "VERA_DIR=%~dp0\..\..\..\vera++\Installation"
set "ZIP_INSTALLER_DIR=%~dp0\..\..\..\ZipInstaller\Installation"
set "BUILD_ENV_DIR=%~dp0\..\..\..\Build_Env\Installation"

set "SRECORD_ZIP=%SRECORD_DIR%\%SRECORD_BASE%.zip"
set "ECLIPSE_ZIP=%ECLIPSE_DIR%\%ECLIPSE_BASE%.zip"
set "CYCLONE_ZIP=%CYCLONE_DIR%\%CYCLONE_BASE%.zip"
set "HEXVIEW_ZIP=%HEXVIEW_DIR%\%HEXVIEW_BASE%.zip"
set "PYTHON_ZIP=%PYTHON_DIR%\%PYTHON_BASE%.zip"
set "VERA_ZIP=%VERA_DIR%\%VERA_BASE%.zip"
set "ZIP_INSTALLER_WHL=%ZIP_INSTALLER_DIR%\%ZIP_INSTALLER_BASE%.whl"
set "BUILD_ENV_WHL=%BUILD_ENV_DIR%\%BUILD_ENV_BASE%.whl"
set "CONFIG_MANAGEMENT_WHL=%BUILD_ENV_DIR%\%CONFIG_MANAGEMENT_BASE%.whl"

set "SRECORD_INSTALLATION_DIR=%SW_DEV_TOOLS_DIR%\%SRECORD_BASE%"
set "ECLIPSE_INSTALLATION_DIR=%SW_DEV_TOOLS_DIR%\%ECLIPSE_BASE%"
set "CYCLONE_INSTALLATION_DIR=%SW_DEV_TOOLS_DIR%\%CYCLONE_BASE%"
set "HEXVIEW_INSTALLATION_DIR=%SW_DEV_TOOLS_DIR%\%HEXVIEW_BASE%"
set "PYTHON_INSTALLATION_DIR=%SW_DEV_TOOLS_DIR%\%PYTHON_BASE%"
set "PYTHON_SCRIPTS_DIR=%SW_DEV_TOOLS_DIR%\%PYTHON_BASE%\Scripts"
set "VERA_INSTALLATION_DIR=%SW_DEV_TOOLS_DIR%\%VERA_BASE%"

goto End

:End