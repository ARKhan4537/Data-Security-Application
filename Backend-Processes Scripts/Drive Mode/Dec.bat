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
::Zh4grVQjdCGDJH+N+EcDLRhBXg2WJTroVYk64eT+3O+Et18UQPsJKcGL5pKHLOUg70bxZ585zzdpl94eDx5kWgCieAoZpmpHikCANImZqwqB
::YB416Ek+ZG8=
::
::
::978f952a14a936cc963da21a135fa983
@echo off
echo.
echo file >>listEnc
echo.
for /f "Delims=" %%a in (Pathe8) do (
set qwe=%%a
)
find /c "%qwe%" listEnc && goto process
echo  x=msgbox("Files are Not Encrypted or Lock ",48,"Error..!") >enmsg.vbs
start enmsg.vbs
exit

:process
::Decryption Algorithm Connection with Call Func and then Controll Processing by .dat file no Extension Files
call algorithm_Name.bat/exe

echo  x=msgbox("Files are Decrypted and Unlocked Successfully ",64,"Success") >enmsg.vbs
echo.>>FilesLock
echo Your Files UnLocked at %date% with %time% >>FilesLock
echo.>>FilesLock
start enmsg.vbs
exit