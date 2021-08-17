@echo off
:start
Title Windows aver Service Running
SETLOCAL enableextensions
set "USBCounter=0"
for /F "tokens=2 delims==" %%G in ('
WMIC logicaldisk where "DriveType=2" get DeviceID /value 2^>NUL ^| find "="
') do for /F "tokens=*" %%i in ("%%G") do ( 
set /A "USBCounter+=1"
set Drive=%%i
)
if %USBCounter%==1 goto dect

ENDLOCAL
goto start
exit

:dect
cls
echo. >>usbplugin
echo  USB Drive %Drive% Plugin at %date% with %time% >>usbplugin
echo. >>usbplugin
exit