@echo off

setlocal EnableDelayedExpansion
(set \n=^
%=This is Mandatory Space=%
)
set /p demoname="Demo Name: "

mkdir "./%demoname%

echo include "%demoname%" >> .\Demos.lua

echo CreateDemo( >> ./"%demoname%"/premake5.lua
echo "%demoname%", >> ./"%demoname%"/premake5.lua
echo -- Dependencies >> ./"%demoname%"/premake5.lua
echo { >> ./"%demoname%"/premake5.lua
echo }, >> ./"%demoname%"/premake5.lua
echo "%%{wks.location}../Demos/%demoname%" >> ./"%demoname%"/premake5.lua
echo ) >> ./"%demoname%"/premake5.lua

xcopy /s/e ".\.project_resources"  ".\"%demoname%"\"

cd .\..\.tools\.project_builders\
start vs19_win.bat