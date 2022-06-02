@echo off

setlocal EnableDelayedExpansion
(set \n=^
%=This is Mandatory Space=%
)
set /p classname="Class Name: "

echo #pragma once >> .\include\%classname%.h
echo class %classname% >> .\include\%classname%.h
echo {}; >> .\include\%classname%.h

echo #include "%classname%.h" > .\src\%classname%.cpp
start .\..\..\.tools\.project_builders\vs19_win.bat