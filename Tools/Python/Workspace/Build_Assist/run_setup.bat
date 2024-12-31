@echo off
rem ***********************************************************************
rem 			Batch file to execute setup build assist wheel.
rem ***********************************************************************

python setup.py sdist bdist_wheel

if exist %~dp0\build rmdir /s /q %~dp0\build
if exist %~dp0\src\build_assist.egg-info rmdir /s /q %~dp0\src\build_assist.egg-info