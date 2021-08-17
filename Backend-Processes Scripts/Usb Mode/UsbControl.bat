@echo off
Title Detecting USB _Path..
:start
SETLOCAL enableextensions
set "USBCounter=0"
for /F "tokens=2 delims==" %%G in ('
WMIC logicaldisk where "DriveType=2" get DeviceID /value 2^>NUL ^| find "="
') do for /F "tokens=*" %%i in ("%%G") do ( 
set /A "USBCounter+=1"
set Drive=%%i
)
if %USBCounter%==1 goto detect
ENDLOCAL
echo  x=msgbox("Please Plugin USB Drive..!",48,"Error..!") >Plug.vbs
start Plug.vbs
exit
:detect
echo.
Title USB Drive Detect Successfully...
echo %Drive%>Pathe6
if Exist %Drive%\Enc goto usbunlock
start LockUSB.exe
exit
:usbunlock
cls
start UnlockUSB.exe 
exit