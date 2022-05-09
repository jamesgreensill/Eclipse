@echo off

set /P rootDir=Root Folder Name: 
mkdir "../%rootDir%"
echo Folder %rootDir% Created.
echo Generating Folders in "config.cfg"

echo. 

for /F "usebackq eol=# tokens=* delims=" %%i in ("config.cfg") do (
echo Folder %%i Created.
mkdir "../%rootDir%/%%i"
)
echo.
pause
