set PRJ_DIR=%~dp0
::set PRJ_DIR=C:\Temp\eCS_Platform_Git\Scripts\AutosarBuilder\
python update_ab_paths.py -f="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace\Remove_UUID_From_ECUExtract.bat" -s="%PRJ_DIR%\..\..\Tools\AutosarBuilder" -o="S:\Tools\AutosarBuilder"
python update_ab_paths.py -f="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace\Remove_UUID_Regex.ps1"  -s="%PRJ_DIR%\..\..\Architectures\Application" -o="S:\Architectures\Application"
python update_ab_paths.py -f="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace\ServicesComponents.bat"  -s="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1" -o="S:\Tools\Tresos_Configuration_8.5.1"
python update_ab_paths.py -f="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace\ServicesComponents.bat"  -s="%PRJ_DIR%\..\..\Components\Application\Autoliv\RTE" -o="S:\Components\Application\Autoliv\RTE"
python update_ab_paths.py -f="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace\ServicesComponents.bat"  -s="%PRJ_DIR%\..\..\Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application" -o="S:\Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application"
python update_ab_paths.py -f="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace\StartAutosarBuilder.bat"  -s="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace" -o="S:\Tools\AutosarBuilder\Workspace"

