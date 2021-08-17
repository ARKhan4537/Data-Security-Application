@echo off
echo.
nircmdc.exe shortcut "%systemdrive%\FileSecurity\USBMode\UsbControl.exe" ~$"%systemdrive%\FileSecurity\"$ "usblockunlock"
nircmdc.exe shortcut "%systemdrive%\FileSecurity\USBMode\viewUSB.bat" ~$"%systemdrive%\FileSecurity\"$ "viewUSB"
nircmdc.exe shortcut "%systemdrive%\FileSecurity\DriveMode\DriveLockUnlock.exe" ~$"%systemdrive%\FileSecurity\"$ "drivelockunlock"
nircmdc.exe shortcut "%systemdrive%\FileSecurity\DriveMode\FI.vbs" ~$"%systemdrive%\FileSecurity\"$ "FI"
nircmdc.exe shortcut "%systemdrive%\FileSecurity\standaloneUSB\StandAloneUsb.bat" ~$"%systemdrive%\FileSecurity\"$ "standalone"
nircmdc.exe shortcut "%systemdrive%\FileSecurity\DriveMode\DisFI.vbs" ~$"%systemdrive%\FileSecurity\"$ "DisFi"
nircmdc.exe shortcut "%systemdrive%\FileSecurity\USBMode\Detect.vbs" ~$"folder.startup"$ "file"
echo.
exit