@echo off
:: \file
::
:: \brief AUTOSAR Resource
::
:: This file contains the implementation of the AUTOSAR
:: module Resource.
::
:: \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
::
:: Copyright 2005 - 2019 Elektrobit Automotive GmbH
:: All rights exclusively reserved for Elektrobit Automotive GmbH,
:: unless expressly agreed to otherwise.::
:: script to update MCAL module with EB content
:: or reset it to vendor content

if [%1]==[EB_update] goto usage
if [%1]==[origin] goto usage
echo Usage: %0 [OPTION]
echo(
echo   EB_update
echo		Update files of the plug-in with content of Elektrobit Automotive GmbH.
echo   origin
echo		Reset the files of the plug-in with vendor content.
echo(
goto copy_end

:usage
cd %~d0 >NUL
cd %~p0
:: if exist an *.origin_version delete the current file:
:: if exist an *.EB_update file delete the current file:
if exist .\anchors.xml (
echo 	remove %~d0%~p0anchors.xml
del .\anchors.xml )
if exist .\include\Compiler_CfgExtMCAL.h (
echo 	remove %~d0%~p0include\Compiler_CfgExtMCAL.h
del .\include\Compiler_CfgExtMCAL.h )
if exist .\META-INF\MANIFEST.MF (
echo 	remove %~d0%~p0META-INF\MANIFEST.MF
del .\META-INF\MANIFEST.MF )
if exist .\plugin.xml (
echo 	remove %~d0%~p0plugin.xml
del .\plugin.xml )
if exist .\resource\cangeneraltypesmapping.properties (
echo 	remove %~d0%~p0resource\cangeneraltypesmapping.properties
del .\resource\cangeneraltypesmapping.properties )
if exist .\resource\canwizard.properties (
echo 	remove %~d0%~p0resource\canwizard.properties
del .\resource\canwizard.properties )

:: perform origin
if [%1]==[EB_update] goto copy_EB
:: if exist an *.origin_version file make it to the current file:
if exist .\anchors.xml.origin_version (
echo 	use %~d0%~p0anchors.xml.origin_version 
copy .\anchors.xml.origin_version .\anchors.xml >NUL )
if exist .\META-INF\MANIFEST.MF.origin_version (
echo 	use %~d0%~p0META-INF\MANIFEST.MF.origin_version 
copy .\META-INF\MANIFEST.MF.origin_version .\META-INF\MANIFEST.MF >NUL )
if exist .\plugin.xml.origin_version (
echo 	use %~d0%~p0plugin.xml.origin_version 
copy .\plugin.xml.origin_version .\plugin.xml >NUL )
goto copy_end

:: perform EB update
:copy_EB
:: if exist an *.EB_update file make it to the current file:
if exist .\anchors.xml.EB_update (
echo 	use %~d0%~p0anchors.xml.EB_update
copy .\anchors.xml.EB_update .\anchors.xml >NUL )
if exist .\include\Compiler_CfgExtMCAL.h.EB_update (
echo 	use %~d0%~p0include\Compiler_CfgExtMCAL.h.EB_update
copy .\include\Compiler_CfgExtMCAL.h.EB_update .\include\Compiler_CfgExtMCAL.h >NUL )
if exist .\META-INF\MANIFEST.MF.EB_update (
echo 	use %~d0%~p0META-INF\MANIFEST.MF.EB_update
copy .\META-INF\MANIFEST.MF.EB_update .\META-INF\MANIFEST.MF >NUL )
if exist .\plugin.xml.EB_update (
echo 	use %~d0%~p0plugin.xml.EB_update
copy .\plugin.xml.EB_update .\plugin.xml >NUL )
if exist .\resource\cangeneraltypesmapping.properties.EB_update (
echo 	use %~d0%~p0resource\cangeneraltypesmapping.properties.EB_update
copy .\resource\cangeneraltypesmapping.properties.EB_update .\resource\cangeneraltypesmapping.properties >NUL )
if exist .\resource\canwizard.properties.EB_update (
echo 	use %~d0%~p0resource\canwizard.properties.EB_update
copy .\resource\canwizard.properties.EB_update .\resource\canwizard.properties >NUL )
:copy_end
