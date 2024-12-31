set PRJ_DIR=%~dp0
set PRJ_DIR=C:\Temp\eCS_Platform_Git\Scripts\AutosarBuilder\
python update_ab_paths.py -f="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace\Remove_UUID_From_ECUExtract.bat" -o="%PRJ_DIR%\..\..\Tools\AutosarBuilder" -s="S:\Tools\AutosarBuilder"
python update_ab_paths.py -f="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace\Remove_UUID_Regex.ps1"  -o="%PRJ_DIR%\..\..\Architectures\Application" -s="S:\Architectures\Application"
python update_ab_paths.py -f="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace\ServicesComponents.bat"  -o="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1" -s="S:\Tools\Tresos_Configuration_8.5.1"
python update_ab_paths.py -f="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace\ServicesComponents.bat"  -o="%PRJ_DIR%\..\..\Components\Application\Autoliv\RTE" -s="S:\Components\Application\Autoliv\RTE"
python update_ab_paths.py -f="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace\ServicesComponents.bat"  -o="%PRJ_DIR%\..\..\Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application" -s="S:\Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application"
python update_ab_paths.py -f="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace\StartAutosarBuilder.bat"  -o="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace" -s="S:\Tools\AutosarBuilder\Workspace"

