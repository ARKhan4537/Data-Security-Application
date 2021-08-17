@echo off
echo.
setlocal enableDelayedExpansion
md %systemdrive%\script
echo 1 >%systemdrive%\script\counter.txt
cls
for /f "Delims=" %%a in (Pathe8) do (
set st=%%a
)

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
exit