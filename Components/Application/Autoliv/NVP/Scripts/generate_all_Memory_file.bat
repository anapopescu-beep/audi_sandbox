@echo off

cd /D "%~dp0"

CALL generateCalibration.bat

CALL generateMainConfiguration.bat

CALL generateNvmDefault.bat