@echo off
:start
E.exe > input.txt
D.exe < input.txt > output.txt
right.exe < input.txt > output2.txt
fc output.txt output2.txt
if not errorlevel 1 goto start
set /p in=<input.txt
echo %in%
pause
goto start
