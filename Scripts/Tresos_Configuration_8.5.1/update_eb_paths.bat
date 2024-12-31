set PRJ_DIR=%~dp0
::set PRJ_DIR=c:\Temp\eCS_Platform_Git\Scripts\Tresos_Configuration_8.5.1\
python update_eb_paths.py -f="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1\Workspace\Application\.prefs\SplittableExp.mem"  -s="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1" -o="S:\Tools\Tresos_Configuration_8.5.1"
python update_eb_paths.py -f="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1\Workspace\Application\.prefs\SplittableExp.mem"  -s="%PRJ_DIR%\..\..\Components\Application" -o="S:\Components\Application"
python update_eb_paths.py -f="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1\Workspace\Application\.prefs\SplittableExp.mem"  -s="%PRJ_DIR%\..\..\..\Tools_Platform_Git\Tools\EB_BSW_8.5.1" -o="S:\Tools\EB_BSW_8.5.1"
python update_eb_paths.py -f="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1\Workspace\Application\.prefs\pref_imp_exp_System_Description.xdm"  -s="%PRJ_DIR%\..\..\Architectures\Application\Description" -o="S:\Architectures\Application\Description"

python update_eb_paths.py -f="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1\Workspace\Application\.prefs\pref_imp_exp_System_Description.xdm" -s="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1" -o="S:\Tools\Tresos_Configuration_8.5.1"
python update_eb_paths.py -f="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1\Workspace\Application\.prefs\pref_imp_exp_System_Description.xdm"  -s="%PRJ_DIR%\..\..\Components\Application" -o="S:\Components\Application"
python update_eb_paths.py -f="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1\Workspace\Application\.prefs\pref_imp_exp_System_Description.xdm"  -s="%PRJ_DIR%\..\..\..\Tools_Platform_Git\Tools\EB_BSW_8.5.1" -o="S:\Tools\EB_BSW_8.5.1"

python update_eb_paths.py -f="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1\Workspace\Application\.prefs\pref_general.xdm"  -s="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1" -o="S:\Tools\Tresos_Configuration_8.5.1"
python update_eb_paths.py -f="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1\Workspace\Application\.prefs\pref_general.xdm"  -s="%PRJ_DIR%\..\..\Components\Application" -o="S:\Components\Application"
python update_eb_paths.py -f="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1\Workspace\Application\.prefs\pref_general.xdm"  -s="%PRJ_DIR%\..\..\..\Tools_Platform_Git\Tools\EB_BSW_8.5.1" -o="S:\Tools\EB_BSW_8.5.1"

python update_eb_paths.py -f="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1\Workspace\Application\.prefs\Generate_All.mem"  -s="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1\Config\ManualAction.exe" -o="cscript &quot;S:\Tools\Build_env\Workspace\ManualAction.vbs"
python update_eb_paths.py -f="%PRJ_DIR%\..\..\Tools\Tresos_Configuration_8.5.1\Workspace\Application\.prefs\Generate_All.mem"  -s="%PRJ_DIR%\..\..\Tools\AutosarBuilder\Workspace\Remove_UUID_From_ECUExtract.bat" -o="S:\Tools\AutosarBuilder\Workspace\Remove_UUID_From_ECUExtract.bat"
