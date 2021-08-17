@echo off
echo.
Title Program use History

findstr /v "#$Q3" %systemdrive%\FileSecurity\DriveMode\FilesActive
findstr /v "#$Q3" %systemdrive%\FileSecurity\USBMode\FilesActive

pause