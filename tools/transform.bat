@echo on
cd ..
set PROJECT_ROOT=%CD%
set PLATFORM=%1
set TRANS=%PROJECT_ROOT%\tools\transform.py
set TRANS_DIR=%PROJECT_ROOT%\platform\Air72x\core
call tools\launch.bat

:: 转换头文件
python38 %TRANS% transform -i "%TRANS_DIR%\core_api.h" -o "%TRANS_DIR%\trans_out\core_api.h" -oc "%TRANS_DIR%\trans_out\core_api.c"

:: 移动无函数定义的头文件，主要定义一些类型
:: python38 %TRANS% "move" -f "%CORE_INC%\cs_types.h" "%CORE_INC%\am_openat_drv.h" -d %USER_INC%

cd tools
