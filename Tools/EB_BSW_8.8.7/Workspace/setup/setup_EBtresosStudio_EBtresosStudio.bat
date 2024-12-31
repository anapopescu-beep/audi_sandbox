@ECHO OFF
if exist configuration\org.eclipse.osgi rmdir /Q/S configuration\org.eclipse.osgi
if exist configuration\org.eclipse.core.runtime rmdir /Q/S configuration\org.eclipse.core.runtime
if exist configuration\org.eclipse.update rmdir /Q/S configuration\org.eclipse.update

rem re-create this file empty unless it already exists (see also https://issue.ebgroup.elektrobit.com/browse/BITE-2026 / TRESOSWP-3682)
if not exist jre_x86_64\linux\lib\security\trusted.libraries copy /b NUL jre_x86_64\linux\lib\security\trusted.libraries
if not exist jre_x86_64\win32\lib\security\trusted.libraries copy /b NUL jre_x86_64\win32\lib\security\trusted.libraries
