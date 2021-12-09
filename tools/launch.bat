@echo off
set PROJECT_ROOT=%CD%

call :add_path %PROJECT_ROOT%\tools\python38

exit /B 0

:add_path
(echo ";%PATH%;" | find /C /I ";%1;" > nul) || set "PATH=%1;%PATH%"
goto :eof
