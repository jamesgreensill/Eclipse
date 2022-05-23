@echo off

setlocal EnableDelayedExpansion
(set \n=^
%=This is Mandatory Space=%
)
set /p projectname="Project Name: "

mkdir "./%projectname%

echo include "%projectname%" >> .\Projects.lua

echo CreateProject( >> ./"%projectname%"/premake5.lua
echo "%projectname%", >> ./"%projectname%"/premake5.lua
echo -- Dependencies >> ./"%projectname%"/premake5.lua
echo { >> ./"%projectname%"/premake5.lua
echo }, >> ./"%projectname%"/premake5.lua
echo "%%{wks.location}../Projects/%projectname%" >> ./"%projectname%"/premake5.lua
echo ) >> ./"%projectname%"/premake5.lua

xcopy /s/e ".\.project_resources"  ".\"%projectname%"\"

cd .\..\.tools\.project_builders\
start vs19_win.bat