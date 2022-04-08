@echo off

:: Load variables into program.

set /P initialDirectory=Source Directory: 

echo Loading variables into program from "config.cfg"

echo. 

for /F "usebackq eol=# tokens=* delims=" %%i in ("config.cfg") do (
echo %%i loaded.
call set %%i 
)
echo.
prompt cloc 

cloc %initialDirectory% --exclude-dir=%ignoredDirectories% --by-file

if not defined fileExtension goto :clocWithoutEx ELSE goto :clocWithEx

:clocWithoutEx
if not defined fileExtension cloc "%initialDirectory%" --exclude-dir="%ignoredDirectories%" --by-file > report.txt

:clocWithEx
if defined fileExtension cloc "%initialDirectory%" --exclude-dir="%ignoredDirectories%" --by-file --%fileExtension% > report.%fileExtension%

if defined exitWhenFinished pause
