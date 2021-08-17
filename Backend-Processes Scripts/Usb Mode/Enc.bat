@echo off
echo.
echo.
for /f "Delims=" %%a in (Pathe6) do (
set qwe=%%a
)
if exist %qwe%\Enc goto alreadyEnc
::Encryption Algorithm Connection with Call Func and then Controll Processing by .dat file no Extension Files
call algorithm_Name.bat/exe
echo file>%qwe%\Enc
attrib +h +s %qwe%\Enc
echo  x=msgbox("Files Encrypted and Lock Successfully",64,"Success") >Encmsg.vbs
start Encmsg.vbs
break>Pathe6
cls
exit
:alreadyEnc
echo  x=msgbox("USB Files are already Encrypted ",48,"Erorr..!") >Encmsg.vbs
start Encmsg.vbs
exit