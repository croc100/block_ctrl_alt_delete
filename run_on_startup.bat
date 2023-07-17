@echo off
REM set compiler path
set compiler=C:\MinGW\bin\g++.exe
REM Set C++ code files to compile
set source=block_ctrl_alt_delete.cpp
REM Set output file name
set output=block_ctrl_alt_delete.exe

REM Compile C++ code
%compiler% %source% -o %output%

REM Run the compiled program
start "" %output%
exit
