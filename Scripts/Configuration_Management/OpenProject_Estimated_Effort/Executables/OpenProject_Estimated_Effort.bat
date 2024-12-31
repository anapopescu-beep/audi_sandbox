@ECHO OFF
FOR %%A IN ("%~dp0") DO SET parent_folder=%%~dpA


set input_path_excel="%parent_folder%\..\Inputs\E5957864 AUDI eCS ECU Feature Release Plan.xlsx"

set outpu_path_excel="%parent_folder%\..\Outputs\OpenProjectAPI.xlsm"


OpenProject_Estimated_Effort.exe -i=%input_path_excel% -o=%outpu_path_excel%