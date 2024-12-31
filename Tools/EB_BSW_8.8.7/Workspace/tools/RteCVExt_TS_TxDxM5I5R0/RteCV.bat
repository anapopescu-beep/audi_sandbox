@ECHO OFF

REM --- Batch file to execute the RteCV ---
REM Usage: RteCV <parameters for the RteCV>

REM ----- RTECV_BASE: RteCV installation directory -----
SET RTECV_BASE=%~dp0
REM ----- RTECV_JAR: RteCV jar file (with path)
SET RTECV_JAR=%RTECV_BASE%RteCV.jar
REM ----- TRESOS_BASE: tresos Studio installation directory -----
SET TRESOS_BASE=%RTECV_BASE%..\..

REM ----- JAVA: java command for executing the RteCV -----
SET JAVACMD=java.exe
SET JAVA_HOME=%TRESOS_BASE%\jre_x86_64\win32
SET JAVA=%JAVA_HOME%\bin\%JAVACMD%

REM ----- Command line parameters -----
SET VMARGS=-Xmx8g -Xms1g -Xss32m

REM ----- Run java -----
IF NOT EXIST %JAVA% GOTO NOJAVA
SET CMD="%JAVA%" %VMARGS% -jar %RTECV_JAR% %*
%CMD%

EXIT /B %ERRORLEVEL%



REM ----------------------------------------

:NOJAVA
ECHO ERROR: java not found: %JAVA%
EXIT /B 255
GOTO END
