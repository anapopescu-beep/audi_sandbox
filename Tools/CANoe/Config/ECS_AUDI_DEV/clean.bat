@echo off
echo Cleaning junk files, please wait . . .
echo.

del /f /s /q %~dp0\*.ini
del /f /s /q %~dp0\*.stcfg
del /f /s /q %~dp0\*.pre
del /f /s /q %~dp0\*.cbk
del /f /s /q %~dp0\Nodes\*.cbf
del /f /s /q %~dp0\Nodes\*.html
del /f /s /q %~dp0\Nodes\*.xml
del /f /s /q %~dp0\TestEnvironment\*.cbf
del /f /s /q %~dp0\TestEnvironment\*.xml
del /f /s /q %~dp0\TestEnvironment\*.html
del /f /s /q %~dp0\TestEnvironment\*.sttse
del /f /s /q %~dp0\TestEnvironment\SwDevTests\*.cbf
del /f /s /q %~dp0\TestEnvironment\SwDevTests\*.xml
del /f /s /q %~dp0\TestEnvironment\SwDevTests\*.html
del /f /s /q %~dp0\TestEnvironment\SwDevTests\*.sttse
del /f /s /q %~dp0\TestEnvironment\PowerSupplyPanelControl\*.cbf
del /f /s /q %~dp0\TestEnvironment\PowerSupplyPanelControl\*.xml
del /f /s /q %~dp0\TestEnvironment\PowerSupplyPanelControl\*.html
del /f /s /q %~dp0\TestEnvironment\PowerSupplyPanelControl\*.sttse
del /f /s /q %~dp0\TestEnvironment\CommunicationControl\*.cbf
del /f /s /q %~dp0\TestEnvironment\CommunicationControl\*.xml
del /f /s /q %~dp0\TestEnvironment\CommunicationControl\*.html
del /f /s /q %~dp0\TestEnvironment\CommunicationControl\*.sttse
