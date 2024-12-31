@rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem r
@rem
@rem File:          T1_BuildExe.bat
@rem
@rem Description:   Batch file to build exe
@rem
@rem $Author: Dan Dustinta (dan.dustinta) $
@rem
@rem $Revision: 1.3 $
@rem
@rem Copyright:     GLIWA embedded systems GmbH & Co. KG
@rem                Weilheim i.OB.
@rem                All rights reserved
@rem
@rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem r

@echo off
pushd %~dp0

set PM_PATH_T1_PERL=%~dp0
set PM_PATH_OS_PARSER=../T1_TresosAutoCoreOS
set PM_FILE_OS_PARSER=T1_TresosAutoCoreOS.pm
set PS_FILE_IN=%PM_PATH_T1_PERL%/T1_projGen.pl
set EXE_FILE_OUT=%PM_PATH_T1_PERL%/T1_projGen.exe

call pp.bat T1_projGen.pl -o %EXE_FILE_OUT% -I %PM_PATH_T1_PERL% -I %PM_PATH_OS_PARSER% --module=T1_config.pm --module=T1_annot.pm --module=%PM_FILE_OS_PARSER%

if errorlevel 1 (
    echo rem [T1_BuildExe.bat info: build failed. Check installation of Perl packages]
    exit /B 1
)

popd
exit /B 0
