@echo off 

rem Get current file path 
set "FILEPATH=%1"

rem set local variables 
setlocal EnableDelayedExpansion

rem Init local variables 
set "str="
set "string=%FILEPATH%"


rem Parse between strings 
set string=!string:Application\Autoliv\=^

!
set string=!string:\Implementation=^

!

rem Extract string in str variable
FOR /F skip^=1eol^= %%S in ("!string!") do if NOT DEFINED str set "str=%%S"

IF "%str%" == "" (
echo Current file does not belong to a SW component of Components folder! QAC script cannot run here.
) else (

echo Running QAC script on SW component: %str%
cd ..\\..\\Metrics\\Static_Analysis
run_qac.bat %str%
echo QAC script has been terminated successfully!
)


