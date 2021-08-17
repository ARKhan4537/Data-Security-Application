@echo off
::taskkill /f /im LockDrive.exe
title Package Avr
:start
for /f "Delims=" %%a in (12345) do (
set qwe=%%a
)
del "%qwe%"
::ren %qwe% %qwe%.dat
::start LockDrive.exe 
goto start