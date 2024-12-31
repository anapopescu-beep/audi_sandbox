echo off
pushd %~dp0
set OUTFILE=Configuration/Config.ini
REM SET OUTFILE=Test.ini
REM Config.ini file Pre Content

echo #Product Runtime Configuration File>%OUTFILE%
echo eclipse.application=com.elektrobit.asr.artop.command.core.artopcmd>>%OUTFILE%
echo "osgi.bundles.defaultStartLevel=4">>%OUTFILE%
echo eclipse.product=com.elektrobit.asr.artop.command.core.artopcmd>>%OUTFILE%
echo osgi.splashPath=platform:/base/plugins/com.elektrobit.asr.artop.command.core>>%OUTFILE%
echo osgi.bundles=dummy,\>>%OUTFILE%


for %%F in (plugins/*.*) do (
for /f "tokens=1,2 delims=_" %%a in ("%%F") do (
 call :ProcessUnderscore %%a %%b
)
)
echo Registering the existing bundles.
REM Config.ini file Post content
REM ###########################################################
REM The following plugin list needs to be updated when there is a change in the Eclipse RCP product.
 echo   com.google.guava,\>>%OUTFILE%
 echo   com.google.inject,\>>%OUTFILE%
 echo   com.ibm.icu,\>>%OUTFILE%
 echo   javax.activation,\>>%OUTFILE%
 echo   javax.annotation,\>>%OUTFILE%
 echo   javax.inject,\>>%OUTFILE%
 echo   javax.servlet,\>>%OUTFILE%
 echo   javax.xml,\>>%OUTFILE%
 echo   org.apache.commons.cli,\>>%OUTFILE%
 echo   org.apache.commons.lang,\>>%OUTFILE%
 echo   org.apache.commons.logging,\>>%OUTFILE%
 echo   org.apache.felix.gogo.command,\>>%OUTFILE%
 echo   org.apache.felix.gogo.runtime,\>>%OUTFILE%
 echo   org.apache.xerces,\>>%OUTFILE%
 echo   org.apache.xml.resolver,\>>%OUTFILE%
 echo   org.apache.xml.serializer,\>>%OUTFILE%
 echo   org.artop.aal.autosar40.converters,\>>%OUTFILE%
 echo   org.artop.aal.autosar40.services.common,\>>%OUTFILE%
 echo   org.artop.aal.autosar40.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar40,\>>%OUTFILE%
 echo   org.artop.aal.autosar403.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar403.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar403,\>>%OUTFILE%
 echo   org.artop.aal.autosar411.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar411.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar411,\>>%OUTFILE%
 echo   org.artop.aal.autosar412.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar412.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar412,\>>%OUTFILE%
 echo   org.artop.aal.autosar421.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar421.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar421,\>>%OUTFILE%
 echo   org.artop.aal.autosar422.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar422.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar422,\>>%OUTFILE%
 echo   org.artop.aal.autosar430.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar430.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar430,\>>%OUTFILE%
 echo   org.artop.aal.autosar442.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar442.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar442,\>>%OUTFILE%
 echo   org.artop.aal.autosar443.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar443.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar443,\>>%OUTFILE%
 echo   org.artop.aal.autosar444.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar444.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar444,\>>%OUTFILE%
 echo   org.artop.aal.autosar445.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar445.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar445,\>>%OUTFILE%
 echo   org.artop.aal.autosar446.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar446.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar446,\>>%OUTFILE%
 echo   org.artop.aal.autosar447.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar447.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar447,\>>%OUTFILE%
 echo   org.artop.aal.autosar448.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar448.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar448,\>>%OUTFILE%
 echo   org.artop.aal.autosar449.edit,\>>%OUTFILE%
 echo   org.artop.aal.autosar449.services,\>>%OUTFILE%
 echo   org.artop.aal.autosar449,\>>%OUTFILE%
 echo   org.artop.aal.common,\>>%OUTFILE%
 echo   org.artop.aal.converters,\>>%OUTFILE%
 echo   org.artop.aal.extender,\>>%OUTFILE%
 echo   org.artop.aal.gautosar.edit,\>>%OUTFILE%
 echo   org.artop.aal.gautosar.services,\>>%OUTFILE%
 echo   org.artop.aal.gautosar,\>>%OUTFILE%
 echo   org.artop.aal.serialization,\>>%OUTFILE%
 echo   org.artop.aal.workspace,\>>%OUTFILE%
 echo   org.artop.eel.common,\>>%OUTFILE%
 echo   org.artop.eel.serialization,\>>%OUTFILE%
 echo   org.artop.sdk,\>>%OUTFILE%
 echo   org.eclipse.ant.core,\>>%OUTFILE%
 echo   org.eclipse.core.commands,\>>%OUTFILE%
 echo   org.eclipse.core.contenttype,\>>%OUTFILE%
 echo   org.eclipse.core.expressions,\>>%OUTFILE%
 echo   org.eclipse.core.filesystem.win32.x86_64,\>>%OUTFILE%
 echo   org.eclipse.core.filesystem,\>>%OUTFILE%
 echo   org.eclipse.core.jobs,\>>%OUTFILE%
 echo   org.eclipse.core.resources.win32.x86_64,\>>%OUTFILE%
 echo   org.eclipse.core.resources,\>>%OUTFILE%
 echo   org.eclipse.core.runtime@start,\>>%OUTFILE%
 echo   org.eclipse.core.variables,\>>%OUTFILE%
 echo   org.eclipse.emf.common,\>>%OUTFILE%
 echo   org.eclipse.emf.ecore.change,\>>%OUTFILE%
 echo   org.eclipse.emf.ecore.edit,\>>%OUTFILE%
 echo   org.eclipse.emf.ecore.xmi,\>>%OUTFILE%
 echo   org.eclipse.emf.ecore,\>>%OUTFILE%
 echo   org.eclipse.emf.edit,\>>%OUTFILE%
 echo   org.eclipse.emf.transaction,\>>%OUTFILE%
 echo   org.eclipse.emf.validation,\>>%OUTFILE%
 echo   org.eclipse.emf.workspace,\>>%OUTFILE%
 echo   org.eclipse.equinox.app,\>>%OUTFILE%
 echo   org.eclipse.equinox.common@2:start,\>>%OUTFILE%
 echo   org.eclipse.equinox.launcher.win32.win32.x86_64,\>>%OUTFILE%
 echo   org.eclipse.equinox.preferences,\>>%OUTFILE%
 echo   org.eclipse.equinox.region,\>>%OUTFILE%
 echo   org.eclipse.equinox.registry,\>>%OUTFILE%
 echo   org.eclipse.equinox.supplement,\>>%OUTFILE%
 echo   org.eclipse.equinox.transforms.hook,\>>%OUTFILE%
 echo   org.eclipse.equinox.weaving.hook,\>>%OUTFILE%
 echo   org.eclipse.osgi.compatibility.state,\>>%OUTFILE%
 echo   org.eclipse.osgi.services,\>>%OUTFILE%
 echo   org.eclipse.osgi.util,\>>%OUTFILE%
 echo   org.eclipse.sphinx.emf.workspace,\>>%OUTFILE%
 echo   org.eclipse.sphinx.emf,\>>%OUTFILE%
 echo   org.eclipse.sphinx.platform,\>>%OUTFILE%
 echo   org.eclipse.xtend.lib.macro,\>>%OUTFILE%
 echo   org.eclipse.xtend.lib,\>>%OUTFILE%
 echo   org.eclipse.xtext.xbase.lib,\>>%OUTFILE%
 echo   org.jdom>>%OUTFILE%
 echo.   >>%OUTFILE%
REM ###########################################################
popd
if [%1]==[NOPAUSE] ( echo. ) else ( pause )
goto :eof

:ProcessUnderscore
if [%2]==[] (
echo Registering %~n1
echo   %~n1,\>>%OUTFILE%
)

goto :eof

