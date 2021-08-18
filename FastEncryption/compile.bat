call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x86
del FastEncryption.exe
cl /EHsc /Ox /c main.cpp
link /LTCG main.obj cryptlib.lib /out:FastEncryption.exe
del main.obj
timeout /t 60 /nobreak