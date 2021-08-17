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
if exist %Drive%\Enc goto alreadyEnc
::Encryption Algorithm Connection with Call Func and then Controll Processing by .dat file no Extension Files
call algorithm_Name.bat/exe

echo file>%Drive%\Enc
attrib +h +s %Drive%\Enc
echo  x=msgbox("Files Encrypted and Lock Successfully",64,"Success") >Encmsg.vbs
start Encmsg.vbs
cls
exit
:alreadyEnc
echo  x=msgbox("USB Files are already Encrypted ",48,"Erorr..!") >Encmsg.vbs
start Encmsg.vbs
exit