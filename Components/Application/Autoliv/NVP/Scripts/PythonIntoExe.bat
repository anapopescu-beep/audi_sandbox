REM use "python -m pip install PyInstaller" in command window before launch this script

REM List of generated file :
REM generate_CalibrationFlashS00.exe
REM generate_NvmDefaultValueS00.exe
REM generate_FEE_D_FlashS00.exe
REM generate_NVPAliash.exe
REM generate_NVPGeneratedCalibrationc.exe
REM generate_NVPGeneratedCalibrationh.exe
REM generate_NVPGenerateNvmDefaultc.exe
REM generate_NVPGenerateNvmDefaulth.exe
REM generate_NVPMemoryMappingh.exe

REM Generate generate_CalibrationFlashS00.exe file
if exist generate_CalibrationFlashS00.exe (del generate_CalibrationFlashS00.exe)
C:\Prog\Python352\Scripts\pyinstaller.exe -F generate_CalibrationFlashS00.py
copy dist\generate_CalibrationFlashS00.exe .\generate_CalibrationFlashS00.exe
del generate_CalibrationFlashS00.spec

REM Generate generate_NvmDefaultValueS00.exe file
if exist generate_NvmDefaultValueS00.exe (del generate_NvmDefaultValueS00.exe)
C:\Prog\Python352\Scripts\pyinstaller.exe -F generate_NvmDefaultValueS00.py
copy dist\generate_NvmDefaultValueS00.exe .\generate_NvmDefaultValueS00.exe
del generate_NvmDefaultValueS00.spec

REM Generate generate_FEE_D_FlashS00.exe file
if exist generate_FEE_D_FlashS00.exe (del generate_FEE_D_FlashS00.exe)
C:\Prog\Python352\Scripts\pyinstaller.exe -F generate_FEE_D_FlashS00.py
copy dist\generate_FEE_D_FlashS00.exe .\generate_FEE_D_FlashS00.exe
del generate_FEE_D_FlashS00.spec

REM Generate generate_NVPAliash.exe file
if exist generate_NVPAliash.exe (del generate_NVPAliash.exe)
C:\Prog\Python352\Scripts\pyinstaller.exe -F generate_NVPAliash.py
copy dist\generate_NVPAliash.exe .\generate_NVPAliash.exe
del generate_NVPAliash.spec

REM Generate generate_NVPGeneratedCalibrationc.exe file
if exist generate_NVPGeneratedCalibrationc.exe (del generate_NVPGeneratedCalibrationc.exe)
C:\Prog\Python352\Scripts\pyinstaller.exe -F generate_NVPGeneratedCalibrationc.py
copy dist\generate_NVPGeneratedCalibrationc.exe .\generate_NVPGeneratedCalibrationc.exe
del generate_NVPGeneratedCalibrationc.spec

REM Generate generate_NVPGeneratedCalibrationh.exe file
if exist generate_NVPGeneratedCalibrationh.exe (del generate_NVPGeneratedCalibrationh.exe)
C:\Prog\Python352\Scripts\pyinstaller.exe -F generate_NVPGeneratedCalibrationh.py
copy dist\generate_NVPGeneratedCalibrationh.exe .\generate_NVPGeneratedCalibrationh.exe
del generate_NVPGeneratedCalibrationh.spec

REM Generate generate_NVPGenerateNvmDefaultc.exe file
if exist generate_NVPGenerateNvmDefaultc.exe (del generate_NVPGenerateNvmDefaultc.exe)
C:\Prog\Python352\Scripts\pyinstaller.exe -F generate_NVPGenerateNvmDefaultc.py
copy dist\generate_NVPGenerateNvmDefaultc.exe .\generate_NVPGenerateNvmDefaultc.exe
del generate_NVPGenerateNvmDefaultc.spec

REM Generate generate_NVPGenerateNvmDefaulth.exe file
if exist generate_NVPGenerateNvmDefaulth.exe (del generate_NVPGenerateNvmDefaulth.exe)
C:\Prog\Python352\Scripts\pyinstaller.exe -F generate_NVPGenerateNvmDefaulth.py
copy dist\generate_NVPGenerateNvmDefaulth.exe .\generate_NVPGenerateNvmDefaulth.exe
del generate_NVPGenerateNvmDefaulth.spec

REM Generate generate_NVPMemoryMappingh.exe file
if exist generate_NVPMemoryMappingh.exe (del generate_NVPMemoryMappingh.exe)
C:\Prog\Python352\Scripts\pyinstaller.exe -F generate_NVPMemoryMappingh.py
copy dist\generate_NVPMemoryMappingh.exe .\generate_NVPMemoryMappingh.exe
del generate_NVPMemoryMappingh.spec

rmdir /S /Q build 
rmdir /S /Q dist
