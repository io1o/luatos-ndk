@echo on

set PROJECT_OUT=%CD%\out
set PLATFROM=%1
set PROJECT_ROOT=%CD%
set TRANS=%PROJECT_ROOT%\tools\transform.py
set USER_INC=%PROJECT_ROOT%\user\include
set USER_SRC=%PROJECT_ROOT%\user\src

call tools\launch.bat

if "%PLATFROM%"=="FLOAT" (
    set DFLAG= -DLUA_CORE -DLUA_USE_MTK_NUCLEUS -DLUAT_FLOATPOINT_SUPPORT
) else (
    set DFLAG=-DLUA_CORE -DLUA_USE_MTK_NUCLEUS 
)
goto RDA8910
:: call tools/launch.bat project debug
:RDA8910
set CORE_INC="%PROJECT_ROOT%\platform\Air72x\core"
set CORE_TRAN_MAIN="%PROJECT_ROOT%\platform\Air72x\core\trans_api"
if not exist %USER_INC% mkdir %USER_INC%
:: 转换头文件
:: python38 %TRANS% transform -i "%PROJECT_ROOT%\platform\8910\core\core_api.h" -o "%PROJECT_ROOT%\user\include\core_api.h" -oc "%PROJECT_ROOT%\user\src\core_api.c"
python38 %TRANS% "move" -f "%CORE_INC%\cs_types.h" "%CORE_INC%\am_openat_drv.h" "%CORE_TRAN_MAIN%\core_api.h" "%CORE_INC%\am_openat_common.h" "%CORE_INC%\am_openat_system.h" "%CORE_INC%\lua_type.h" "%CORE_INC%\std_type.h" "%CORE_INC%\luaconf.h" -d %USER_INC%
python38 %TRANS% "move" -f "%CORE_TRAN_MAIN%\core_api.c" -d %USER_SRC%

set CMAKE_LINKER=%PROJECT_ROOT%/platform/Air72x/compiler/win32/gcc-arm-none-eabi/bin/arm-none-eabi-ld.exe
set CMAKE_C_COMPILER=%PROJECT_ROOT%/platform/Air72x/compiler/win32/gcc-arm-none-eabi/bin/arm-none-eabi-gcc.exe
set CMAKE_OBJDUMP_COMPILER=%PROJECT_ROOT%/platform/Air72x/compiler/win32/gcc-arm-none-eabi/bin/arm-none-eabi-objdump.exe
set CMAKE_OBJCOPY_COMPILER=%PROJECT_ROOT%/platform/Air72x/compiler/win32/gcc-arm-none-eabi/bin/arm-none-eabi-objcopy.exe
set CCOPTION="-mcpu=cortex-a5 -mtune=generic-armv7-a -mfpu=neon-vfpv4  -mthumb -mfloat-abi=hard -mno-unaligned-access  -g -Os -Wall -std=c11 -c" 
goto BUILD

:ASR1603
set CMAKE_LINKER="C:/Program Files/DS-5/sw/ARMCompiler5.05/bin/armlink.exe"
set CMAKE_C_COMPILER="C:/Program Files/DS-5/sw/ARMCompiler5.05/bin/armcc.exe"
set CCOPTION="-c --c99 --cpu Cortex-R4 --no_unaligned_access -g -O2 --apcs /inter --diag_suppress 2084,1,2,177,550,6319 --gnu --thumb --loose_implicit_cast %PLATFROM%"
goto BUILD

:BUILD
if not exist %PROJECT_OUT% mkdir %PROJECT_OUT%
cd user
gnumake LR=%CMAKE_LINKER% CC=%CMAKE_C_COMPILER% CCOPTION=%CCOPTION%
copy %PROJECT_ROOT%\user\out\lib\user.lib %PROJECT_ROOT%\out\user_tmp.lib
%CMAKE_OBJDUMP_COMPILER% -S %PROJECT_ROOT%\out\user_tmp.lib > %PROJECT_ROOT%\out\user.map
%CMAKE_OBJCOPY_COMPILER% -R .debug* %PROJECT_ROOT%\out\user_tmp.lib %PROJECT_ROOT%\out\user.lib
del %PROJECT_ROOT%\out\user_tmp.lib
gnumake clean

:: 删除转换后的头文件
if "%PLATFROM%"=="RDA8910" (
	python38 %TRANS% clear -f %USER_INC%\core_api.h %USER_SRC%\core_api.c %USER_INC%\cs_types.h %USER_INC%\am_openat_drv.h %USER_INC%\am_openat_common.h %USER_INC%\am_openat_system.h %USER_INC%\lua_type.h %USER_INC%\std_type.h %USER_INC%\luaconf.h
)

cd ..
:: rd /s /Q "out/project_debug"
