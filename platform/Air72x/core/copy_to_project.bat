
echo off
set PROJECT_PATH=%1
xcopy /e/y/r  %~dp0\core_inc %PROJECT_PATH%\core_inc\
xcopy /y %~dp0\core_api.h %PROJECT_PATH%\core_inc\

set filename=%PROJECT_PATH%\core_inc\readme.txt
echo 1. This directory is automatically generated. Do not add any files >%filename%
echo 2. This directory has only one function: it can let you see the code >>%filename%
echo 3. Luatide projects can be compiled successfully without this directory >>%filename%
echo 4. This file is also automatically generated, and it is useless if you change it >>%filename%
