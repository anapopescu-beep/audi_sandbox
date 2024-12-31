@echo off
pushd %~dp0

call :DeleteDirIfExist configuration\.settings
call :DeleteDirIfExist configuration\org.eclipse.core.runtime
call :DeleteDirIfExist configuration\org.eclipse.e4.ui.css.swt.theme
call :DeleteDirIfExist configuration\org.eclipse.equinox.app
call :DeleteDirIfExist configuration\org.eclipse.oomph.setup
call :DeleteDirIfExist configuration\org.eclipse.osgi
call :DeleteDirIfExist configuration\org.eclipse.ui.intro.universal
call :DeleteDirIfExist configuration\org.eclipse.update\history
call :DeleteDirIfExist p2\org.eclipse.equinox.p2.core
call :DeleteDirIfExist p2\org.eclipse.equinox.p2.repository
call :DeleteFileIfExist configuration\Workingsets.xml
call :DeleteFileIfExist p2\pools.info
call :DeleteFileIfExist p2\profiles.info
call :DeleteFileIfExist *.p2bu
popd
if NOT [%1]==[NOPAUSE] pause
goto :EOF


:DeleteDirIfExist
if exist %1 (
  echo deleting folder %1
  rd /Q /S %1
)
GOTO :EOF

:DeleteFileIfExist
if exist %1  (
  echo deleting file %1
  del /Q %1
  )
GOTO :EOF
