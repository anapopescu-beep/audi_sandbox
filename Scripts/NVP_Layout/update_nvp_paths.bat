set PRJ_DIR=%~dp0

::set PRJ_DIR=c:\Temp\eCS_Platform_Git\Scripts\Tresos_Configuration_8.5.1\
python update_nvp_paths.py -f="%PRJ_DIR%\..\..\Tools\NVP_Layout\Config\Config.xml"  -s="%PRJ_DIR%..\\..\\" -o="S:\\"
