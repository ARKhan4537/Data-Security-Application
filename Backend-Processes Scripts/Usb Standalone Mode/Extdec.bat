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
::Zh4grVQjdCGDJH+N+EcDLRhBXg2WJTroVYk64eT+3O+Et18UQPsJKcGL5pKHLOUg70bxZ585zzdpl94eDx5kbQaqYAs1pWFMs1G2Ffu5qxvlT0vH41M1ew==
::YB416Ek+ZG8=
::
::
::978f952a14a936cc963da21a135fa983
@echo off
echo.
setlocal enableDelayedExpansion
md %systemdrive%\script
echo 1 >%systemdrive%\script\counter.txt
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
cls
goto sp
exit
:detect
if not exist Enc goto term
dir /a:d /s /b>%systemdrive%\script\print.txt
echo %Drive%>>%systemdrive%\script\print.txt
cls
set /a co=0
:Loop
set /a co+=1
echo %co% >123
for /f "Delims=" %%a in (123) do (
set countfile=%%a
)
if %countfile%==10 goto term

set /a count=0
for /F "tokens=*" %%A in (%systemdrive%\script\print.txt) do (
set /a count+=1
set File[!count!]=%%A
)

set /a count=0
:repeat
find /c "!count!" %systemdrive%\script\counter.txt && goto process
set /a count+=1
goto repeat

:process
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filejpg" "*.jpg"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filejpeg" "*.jpg"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filemp4" "*.mp4"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filezip" "*.zip"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filerar" "*.rar"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filepng" "*.png"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filebmp" "*.bmp"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filemkv" "*.mkv"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filedocx" "*.docx"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.fileamv" "*.amv"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filemp3" "*.mp3"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.fileppt" "*.ppt"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filetxt" "*.txt"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filexlsm" "*.xlsm"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filexls" "*.xls"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filexltm" "*.xltm"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.filewav" "*.wav"
cls
set /a count+=1
echo !count! >%systemdrive%\script\counter.txt
goto Loop
:term
attrib -h -s %qwe%\Enc
del %qwe%\Enc
exit