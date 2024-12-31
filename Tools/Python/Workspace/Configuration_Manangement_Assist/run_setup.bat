@echo off
rem ***********************************************************************
rem    Batch file to execute setup configuration management assist wheel.
rem ***********************************************************************

python setup.py sdist bdist_wheel

if exist %~dp0\build rmdir /s /q %~dp0\build
if exist %~dp0\src\configuration_manangement_assist.egg-info rmdir /s /q %~dp0\src\configuration_manangement_assist.egg-info