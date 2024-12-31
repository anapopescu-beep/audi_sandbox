@echo off

set HEXVIEW_INSTALLATION_DIR="c:\Prog\HexView-1.12.02"
set CALIBRRATION_FILE=%1
set APP_FILE=%2
set BOOTLOADER_UPDATER_FILE=%3
set OUTPUT_PATH=%4
set OEM_APPL_VERSION=%5
set OEM_CALIB_VERSION=%6
set OEM_BOOTLOADER_VERSION=%7
set OEM_BOOTLOADER_UPDATER_VERSION=%8
set OEM_CONTAINER_VERSION=%9
set OEM_VARIANT=audi_ecs
REM echo "CALIBRRATION_FILE:%CALIBRRATION_FILE%"
REM echo "APP_FILE:%APP_FILE%"
REM echo "OUTPUT_PATH:%OUTPUT_PATH%"
REM echo "OEM_VARIANT:%OEM_VARIANT%"

set CALIBRATION_FILE_NAME=%~n1
set APP_FILE_NAME=%~n2
set BOOTLOADER_UPDATER_FILE_NAME=%~n3

rem echo "CALIBRATION_FILE_NAME:%CALIBRATION_FILE_NAME%"
rem echo "APP_FILE_NAME:%APP_FILE_NAME%"

if [%1] == [] set CALIBRRATION_FILE=%~dp0\..\..\..\..\Release\CanFlash\Calibration.s19
if [%2] == [] set APP_FILE=%~dp0\..\..\..\..\Release\CanFlash\Application.s19
if [%3] == [] set BOOTLOADER_UPDATER_FILE_NAME=%~dp0\..\..\..\..\Release\CanFlash\Bootloader_updater.s19
if [%4] == [] set OUTPUT_PATH=%~dp0\..\..\..\..\Release\CanFlash
if [%5] == [] set OEM_APPL_VERSION=0001
if [%6] == [] set OEM_CALIB_VERSION=0001
if [%7] == [] set OEM_BOOTLOADER_UPDATER_VERSION=9999
if [%8] == [] set OEM_BOOTLOADER_VERSION=9998
if [%9] == [] set OEM_CONTAINER_VERSION=001

if [%1] == [] set CALIBRATION_FILE_NAME=Calibration
if [%2] == [] set APP_FILE_NAME=Application
if [%3] == [] set BOOTLOADER_UPDATER_FILE_NAME=Bootloader_updater

rem echo "CALIBRRATION_FILE:%CALIBRRATION_FILE%"
rem echo "APP_FILE:%APP_FILE%"
rem echo "OUTPUT_PATH:%OUTPUT_PATH%"
rem echo "OEM_VARIANT:%OEM_VARIANT%"
rem echo "CALIBRATION_FILE_NAME:%CALIBRATION_FILE_NAME%"
rem echo "APP_FILE_NAME:%APP_FILE_NAME%"
rem echo "OEM_APPL_VERSION=%OEM_APPL_VERSION%"
rem echo "OEM_CALIB_VERSION=%OEM_CALIB_VERSION%"
rem echo "OEM_CONTAINER_VERSION=%OEM_CONTAINER_VERSION%"
set "OUTPUT_PATH_UNIX=%OUTPUT_PATH:\=/%"

set "TOOLS_DIR=%~dp0\..\..\..\..\Tools"
set "RELEASE_DIR=%~dp0\..\..\..\..\Release"

if exist "%TOOLS_DIR%\Odx\Installation\config_FDSProject_dev" (
   
   echo Running post processing on CanFlash files

   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\sleep 5
   
   %HEXVIEW_INSTALLATION_DIR%\hexview.exe /s %APP_FILE%  /XN -o %OUTPUT_PATH%\%APP_FILE_NAME%.bin 
   %HEXVIEW_INSTALLATION_DIR%\hexview.exe /s %CALIBRRATION_FILE% /XN -o %OUTPUT_PATH%\%CALIBRATION_FILE_NAME%.bin
   %HEXVIEW_INSTALLATION_DIR%\hexview.exe /s %BOOTLOADER_UPDATER_FILE% /XN -o %OUTPUT_PATH%\%BOOTLOADER_UPDATER_FILE_NAME%.bin
   
   echo Generating ODX files that contain all logical blocks

   %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\ODXCreate.exe -as -s %OEM_APPL_VERSION% -cv %OEM_CONTAINER_VERSION% -sbv 0001;%OEM_APPL_VERSION% -sbv 0002;%OEM_CALIB_VERSION% %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\%OEM_VARIANT%_app.ocnf
   %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\ODXCreate.exe -as -s %OEM_APPL_VERSION% -cv %OEM_CONTAINER_VERSION% -sbv 0001;%OEM_APPL_VERSION% -sbv 0002;%OEM_CALIB_VERSION% %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\%OEM_VARIANT%_app_Enc.ocnf
   %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\ODXCreate.exe -as -s %OEM_APPL_VERSION% -cv %OEM_CONTAINER_VERSION% -sbv 0001;%OEM_APPL_VERSION% -sbv 0002;%OEM_CALIB_VERSION% %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\%OEM_VARIANT%_app_Comp.ocnf
   %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\ODXCreate.exe -as -s %OEM_APPL_VERSION% -cv %OEM_CONTAINER_VERSION% -sbv 0001;%OEM_APPL_VERSION% -sbv 0002;%OEM_CALIB_VERSION% %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\%OEM_VARIANT%_app_Comp_Enc.ocnf

   %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\ODXCreate.exe -as -s %OEM_BOOTLOADER_UPDATER_VERSION% -cv %OEM_CONTAINER_VERSION% -sbv 0001;%OEM_BOOTLOADER_VERSION% %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\%OEM_VARIANT%_fbl_u.ocnf
   %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\ODXCreate.exe -as -s %OEM_BOOTLOADER_UPDATER_VERSION% -cv %OEM_CONTAINER_VERSION% -sbv 0001;%OEM_BOOTLOADER_VERSION% %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\%OEM_VARIANT%_fbl_u_Enc.ocnf
   %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\ODXCreate.exe -as -s %OEM_BOOTLOADER_UPDATER_VERSION% -cv %OEM_CONTAINER_VERSION% -sbv 0001;%OEM_BOOTLOADER_VERSION% %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\%OEM_VARIANT%_fbl_u_Comp.ocnf
   %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\ODXCreate.exe -as -s %OEM_BOOTLOADER_UPDATER_VERSION% -cv %OEM_CONTAINER_VERSION% -sbv 0001;%OEM_BOOTLOADER_VERSION% %TOOLS_DIR%\Odx\Installation\ODXCreate_V263\%OEM_VARIANT%_fbl_u_Comp_Enc.ocnf
   
   echo Extracting .bin files from ODX

   for /F "tokens=*" %%f in ('dir /B /S "%OUTPUT_PATH%\app\default\*.odx"') do (
   %TOOLS_DIR%\Odx\Installation\OdxExtractor\extractASCIIfromOdx.exe "%%~ff" "app" "calib"
   )

   for /F "tokens=*" %%f in ('dir /B /S "%OUTPUT_PATH%\app\compressed\*.odx"') do (
   %TOOLS_DIR%\Odx\Installation\OdxExtractor\extractASCIIfromOdx.exe "%%~ff" "app" "calib"
   )

   %TOOLS_DIR%\Odx\Installation\eb_ecl_V3\eb_ecl_V3.exe --infile "%OUTPUT_PATH%\app\compressed\app.bin" --command=d --outfile "%OUTPUT_PATH%\app\compressed\app_decompressed.bin" > nul 2>&1

   %TOOLS_DIR%\Odx\Installation\eb_ecl_V3\eb_ecl_V3.exe --infile "%OUTPUT_PATH%\app\compressed\calib.bin" --command=d --outfile "%OUTPUT_PATH%\app\compressed\calib_decompressed.bin" > nul 2>&1
    
   for /F "tokens=*" %%f in ('dir /B /S "%OUTPUT_PATH%\app\encrypted\*.odx"') do (
   %TOOLS_DIR%\Odx\Installation\OdxExtractor\extractASCIIfromOdx.exe "%%~ff" "app" "calib"
   )

   %TOOLS_DIR%\Odx\Installation\eb_ecl_V3\eb_ecl_V3.exe --command=decrypt -infile "%OUTPUT_PATH%\app\encrypted\app.bin" -iv "FDBB56043462b8db2aff3f310fa67902" -key "c9165310abcd778b8192108f232e0201"  -outfile "%OUTPUT_PATH%\app\encrypted\app_decrypted.bin" > nul 2>&1

   %TOOLS_DIR%\Odx\Installation\eb_ecl_V3\eb_ecl_V3.exe --command=decrypt -infile "%OUTPUT_PATH%\app\encrypted\calib.bin" -iv "FDBB56043462b8db2aff3f310fa67902" -key "c9165310abcd778b8192108f232e0201"  -outfile "%OUTPUT_PATH%\app\encrypted\calib_decrypted.bin" > nul 2>&1

   for /F "tokens=*" %%f in ('dir /B /S "%OUTPUT_PATH%\app\compressed_encrypted\*.odx"') do (
   %TOOLS_DIR%\Odx\Installation\OdxExtractor\extractASCIIfromOdx.exe "%%~ff" "app" "calib"
   )

   %TOOLS_DIR%\Odx\Installation\eb_ecl_V3\eb_ecl_V3.exe --command=decrypt -infile "%OUTPUT_PATH%\app\compressed_encrypted\app.bin" -iv "FDBB56043462b8db2aff3f310fa67902" -key "c9165310abcd778b8192108f232e0201"  -outfile "%OUTPUT_PATH%\app\compressed_encrypted\app_decrypted.bin" > nul 2>&1

   %TOOLS_DIR%\Odx\Installation\eb_ecl_V3\eb_ecl_V3.exe --command=decrypt -infile "%OUTPUT_PATH%\app\compressed_encrypted\calib.bin" -iv "FDBB56043462b8db2aff3f310fa67902" -key "c9165310abcd778b8192108f232e0201"  -outfile "%OUTPUT_PATH%\app\compressed_encrypted\calib_decrypted.bin" > nul 2>&1

   %TOOLS_DIR%\Odx\Installation\eb_ecl_V3\eb_ecl_V3.exe --infile "%OUTPUT_PATH%\app\compressed_encrypted\app_decrypted.bin" --command=d --outfile "%OUTPUT_PATH%\app\compressed_encrypted\app_decompressed.bin" > nul 2>&1

   %TOOLS_DIR%\Odx\Installation\eb_ecl_V3\eb_ecl_V3.exe --infile "%OUTPUT_PATH%\app\compressed_encrypted\calib_decrypted.bin" --command=d --outfile "%OUTPUT_PATH%\app\compressed_encrypted\calib_decompressed.bin" > nul 2>&1
    
   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\sleep 10
   
   echo Extracting .bin files from fbl_u ODX

   for /F "tokens=*" %%f in ('dir /B /S "%OUTPUT_PATH%\fbl_u\default\*.odx"') do (
   %TOOLS_DIR%\Odx\Installation\OdxExtractor\extractASCIIfromOdx.exe "%%~ff" "fbl_u"
   )

   for /F "tokens=*" %%f in ('dir /B /S "%OUTPUT_PATH%\fbl_u\compressed\*.odx"') do (
   %TOOLS_DIR%\Odx\Installation\OdxExtractor\extractASCIIfromOdx.exe "%%~ff" "fbl_u"
   )

   %TOOLS_DIR%\Odx\Installation\eb_ecl_V3\eb_ecl_V3.exe --infile "%OUTPUT_PATH%\fbl_u\compressed\fbl_u.bin" --command=d --outfile "%OUTPUT_PATH%\fbl_u\compressed\fbl_u_decompressed.bin" > nul 2>&1
    
   for /F "tokens=*" %%f in ('dir /B /S "%OUTPUT_PATH%\fbl_u\encrypted\*.odx"') do (
   %TOOLS_DIR%\Odx\Installation\OdxExtractor\extractASCIIfromOdx.exe "%%~ff" "fbl_u"
   )

   %TOOLS_DIR%\Odx\Installation\eb_ecl_V3\eb_ecl_V3.exe --command=decrypt -infile "%OUTPUT_PATH%\fbl_u\encrypted\fbl_u.bin" -iv "FDBB56043462b8db2aff3f310fa67902" -key "c9165310abcd778b8192108f232e0201"  -outfile "%OUTPUT_PATH%\fbl_u\encrypted\fbl_u_decrypted.bin" > nul 2>&1

   for /F "tokens=*" %%f in ('dir /B /S "%OUTPUT_PATH%\fbl_u\compressed_encrypted\*.odx"') do (
   %TOOLS_DIR%\Odx\Installation\OdxExtractor\extractASCIIfromOdx.exe "%%~ff" "fbl_u"
   )

   %TOOLS_DIR%\Odx\Installation\eb_ecl_V3\eb_ecl_V3.exe --command=decrypt -infile "%OUTPUT_PATH%\fbl_u\compressed_encrypted\fbl_u.bin" -iv "FDBB56043462b8db2aff3f310fa67902" -key "c9165310abcd778b8192108f232e0201"  -outfile "%OUTPUT_PATH%\fbl_u\compressed_encrypted\fbl_u_decrypted.bin" > nul 2>&1

   %TOOLS_DIR%\Odx\Installation\eb_ecl_V3\eb_ecl_V3.exe --infile "%OUTPUT_PATH%\fbl_u\compressed_encrypted\fbl_u_decrypted.bin" --command=d --outfile "%OUTPUT_PATH%\fbl_u\compressed_encrypted\fbl_u_decompressed.bin" > nul 2>&1
    
   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\sleep 10
   
   
   echo Checking plausability of bin files
   
   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\cmp %OUTPUT_PATH_UNIX%/%APP_FILE_NAME%.bin %OUTPUT_PATH_UNIX%/app/compressed_encrypted/app_decompressed.bin
   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\cmp %OUTPUT_PATH_UNIX%/%APP_FILE_NAME%.bin %OUTPUT_PATH_UNIX%/app/compressed/app_decompressed.bin
   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\cmp %OUTPUT_PATH_UNIX%/%APP_FILE_NAME%.bin %OUTPUT_PATH_UNIX%/app/encrypted/app_decrypted.bin
   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\cmp %OUTPUT_PATH_UNIX%/%APP_FILE_NAME%.bin %OUTPUT_PATH_UNIX%/app/default/app.bin

   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\cmp %OUTPUT_PATH_UNIX%/%CALIBRATION_FILE_NAME%.bin %OUTPUT_PATH_UNIX%/app/compressed_encrypted/calib_decompressed.bin
   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\cmp %OUTPUT_PATH_UNIX%/%CALIBRATION_FILE_NAME%.bin %OUTPUT_PATH_UNIX%/app/compressed/calib_decompressed.bin
   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\cmp %OUTPUT_PATH_UNIX%/%CALIBRATION_FILE_NAME%.bin %OUTPUT_PATH_UNIX%/app/encrypted/calib_decrypted.bin
   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\cmp %OUTPUT_PATH_UNIX%/%CALIBRATION_FILE_NAME%.bin %OUTPUT_PATH_UNIX%/app/default/calib.bin

   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\cmp %OUTPUT_PATH_UNIX%/%BOOTLOADER_UPDATER_FILE_NAME%.bin %OUTPUT_PATH_UNIX%/fbl_u/compressed_encrypted/fbl_u_decompressed.bin
   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\cmp %OUTPUT_PATH_UNIX%/%BOOTLOADER_UPDATER_FILE_NAME%.bin %OUTPUT_PATH_UNIX%/fbl_u/compressed/fbl_u_decompressed.bin
   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\cmp %OUTPUT_PATH_UNIX%/%BOOTLOADER_UPDATER_FILE_NAME%.bin %OUTPUT_PATH_UNIX%/fbl_u/encrypted/fbl_u_decrypted.bin
   %TOOLS_DIR%\Build_Env\Workspace\Build\Make_support\bin\cmp %OUTPUT_PATH_UNIX%/%BOOTLOADER_UPDATER_FILE_NAME%.bin %OUTPUT_PATH_UNIX%/fbl_u/default/fbl_u.bin

   goto End
   
) else (
   echo "config_FDSProject_dev is missing. Cannot generate ODX files"
   goto End
)


:End
