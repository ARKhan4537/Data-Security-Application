@echo off
echo.
echo.
:sp
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
goto sp
exit
:detect
if not exist %Drive%\Enc goto alreadyDec
::Decryption Algorithm Connection with Call Func and then Controll Processing by .dat file no Extension Files
call algorithm_Name.bat/exe.
cls
exit
:alreadyDec
cls
echo  x=msgbox("Files are already Dcrypted and Unlocked",48,"Error..!") >Encmsg.vbs
start Encmsg.vbs
exit