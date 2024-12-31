@echo off

mkdir %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\ECUIntegration\Services\Dcm

COPY %~dp0\..\..\..\Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application\Tresos_BSW_generated\swcd\\Dcm_swc_internal.arxml  %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\ECUIntegration\Services\Dcm\Dcm_swc_internal.arxml

mkdir %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\ECUIntegration\Services\Dem

COPY %~dp0\..\..\..\Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application\Tresos_BSW_generated\swcd\\Dem_swc_internal.arxml  %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\ECUIntegration\Services\Dem\Dem_swc_internal.arxml

mkdir %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\ECUIntegration\Services\NvM

COPY %~dp0\..\..\..\Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application\Tresos_BSW_generated\swcd\\NvM_swc_internal.arxml  %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\ECUIntegration\Services\NvM\NvM_swc_internal.arxml

mkdir %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\DataDictionary\Autosar\Services\DEM

COPY %~dp0\..\..\..\Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application\Tresos_BSW_generated\swcd\\Dem_swc_interface.arxml %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\DataDictionary\Autosar\Services\DEM\Dem_swc_interface.arxml

mkdir %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\DataDictionary\Autosar\Services\DCM

COPY %~dp0\..\..\..\Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application\Tresos_BSW_generated\swcd\\Dcm_swc_interface.arxml %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\DataDictionary\Autosar\Services\DCM\Dcm_swc_interface.arxml

mkdir %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\DataDictionary\Autosar\Services\NVM

COPY %~dp0\..\..\..\Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application\Tresos_BSW_generated\swcd\\NvM_swc_interface.arxml %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\DataDictionary\Autosar\Services\NVM\NvM_swc_interface.arxml

mkdir %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\DataDictionary\Platform\Standard

COPY %~dp0\..\..\..\Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application\Tresos_BSW_generated\swcd\\Base_Bswmd.arxml  %~dp0\..\..\..\Components\Application\Autoliv\RTE\Config\ARXML\Description\DataDictionary\Platform\Standard\Base_ASR40_Bswmd.arxml