@echo off
echo.
Title URL

break >url.txt
dir /s /b *.jpg >>url.txt
dir /s /b *.png >>url.txt
dir /s /b *.docx >>url.txt
dir /s /b *.jpeg >>url.txt
dir /s /b *.mp4 >>url.txt
dir /s /b *.zip >>url.txt
dir /s /b *.rar >>url.txt
dir /s /b *.png >>url.txt
dir /s /b *.bmp >>url.txt
dir /s /b *.mkv >>url.txt
dir /s /b *.docx >>url.txt
dir /s /b *.amv >>url.txt
dir /s /b *.mp3 >>url.txt
dir /s /b *.ppt >>url.txt
dir /s /b *.txt >>url.txt
dir /s /b *.xlsm >>url.txt
dir /s /b *.xls >>url.txt
dir /s /b *.xltm >>url.txt
dir /s /b *.wav >>url.txt
attrib +h +s url.txt
exit