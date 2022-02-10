@echo off
@REM set PROJECT_ROOT=%CD%
@REM echo asfasfafa
call :add_path %~dp0\python38

exit /B 0

:add_path
(echo ";%PATH%;" | find /C /I ";%1;" > nul) || set "PATH=%1;%PATH%"
goto :eof
