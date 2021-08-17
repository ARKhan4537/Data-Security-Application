@echo off
echo.
attrib -h -s *.fileexe
attrib -h -s *.filebat
ren *.fileexe *.exe
ren *.filebat *.bat
ren USB.fileexe USB.exe
attrib +h +s *.exe
attrib +h +s *.bat
attrib -h -s USB.exe
if Exist Enc goto UnLock
start inv.bat
start standaloneUSBLOCK.exe
exit
:UnLock
start standaloneUSBUNLOCK.exe
exit