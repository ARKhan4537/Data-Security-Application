@echo off
Setlocal enabledelayedexpansion
set "psCommand="(new-object -COM 'Shell.Application')^
.BrowseForFolder(0,'Please choose a folder.',0,0).self.path""
for /f "usebackq delims=" %%I in (`powershell %psCommand%`) do set "folder=%%I"
echo.
echo !folder! >Pathe8
echo  x=msgbox( "!folder!",64,"Selected Path")>123.vbs
taskkill /f /im UnlockDrive.exe
start UnlockDrive.exe
exit