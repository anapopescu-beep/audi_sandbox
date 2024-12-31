@echo off

echo "***generateNvmDefault.bat***"
cd /D "%~dp0"

if exist ..\\..\\..\\..\\..\\Tools\\Build_Env\\Workspace\\Outputs\\nvp\\NvmDefaultValue.S00 (del ..\\..\\..\\..\\..\\Tools\\Build_Env\\Workspace\\Outputs\\nvp\\NvmDefaultValue.S00)
if exist ..\\..\\..\\..\\..\\Tools\\Build_Env\\Workspace\\Outputs\\nvp\\ErrorNvmDefaultValueS00.log (del ..\\..\\..\\..\\..\\Tools\\Build_Env\\Workspace\\Outputs\\nvp\\ErrorNvmDefaultValueS00.log)
if exist ..\\Implementation\\src\\Nvp_Generated_NvmDefault.c (del ..\\Implementation\\src\\Nvp_Generated_NvmDefault.c)
if exist ..\\Implementation\\src\\Nvp_Generated_NvmDefaultc.log (del ..\\Implementation\\src\\Nvp_Generated_NvmDefaultc.log)
if exist ..\\Implementation\\inc\\Nvp_Generated_NvmDefault.h (del ..\\Implementation\\inc\\Nvp_Generated_NvmDefault.h)
if exist ..\\Implementation\\inc\\Nvp_Generated_NvmDefaulth.log (del ..\\Implementation\\inc\\Nvp_Generated_NvmDefaulth.log)
if exist ..\\Implementation\\inc\\Nvp_alias.h (del ..\\Implementation\\inc\\Nvp_alias.h)
if exist ..\\Implementation\\inc\\Nvp_aliash.log (del ..\\Implementation\\inc\\Nvp_aliash.log)
python generate_NvmDefaultValueS00.py
python generate_FEE_D_FlashS00.py
python generate_NVPGenerateNvmDefaultc.py
python generate_NVPGenerateNvmDefaulth.py
python generate_NVPAliash.py