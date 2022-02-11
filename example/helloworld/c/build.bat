@echo off

@REM 获取当前文件的路径
set PROJECT_ROOT=%~dp0
@REM 将工作路径切换到当前路径
cd %PROJECT_ROOT%
if "%1" == "" (
    @REM 如果没有传入NDK的路径，就往上三级目录
    @REM 下面几行是获取当前路径的上一级路径的
    cd..
    cd..
    cd..
    @REM 保存默认的NDK路径
    set NDK_PATH=%CD%
    cd %PROJECT_ROOT%
) else (
    @REM 如果有传入就使用传入值
    @REM 这里主要是给IDE使用，在IDE中编译环境会被放在APPDATA中，这个路径需要外界传进来
    set NDK_PATH=%1
)
echo %NDK_PATH%


@echo on

set PROJECT_OUT=%PROJECT_ROOT%\build

set NDK_ROOT=%NDK_PATH%
set TRANS=%NDK_ROOT%\tools\transform.py
set USER_INC=%PROJECT_ROOT%\include
set USER_SRC=%PROJECT_ROOT%\src
set MAKE_DIR=%NDK_ROOT%\platform\Air72x\toolchain\GnuWin32\bin
call %NDK_ROOT%\tools\launch.bat


set DFLAG=-DLUA_CORE -DLUA_USE_MTK_NUCLEUS 

goto RDA8910
:: call tools/launch.bat project debug
:RDA8910
set CORE_INC="%NDK_ROOT%\platform\Air72x\core"
set CORE_TRAN_MAIN="%NDK_ROOT%\platform\Air72x\core\trans_api"
if not exist %USER_INC% mkdir %USER_INC%
:: 转换头文件
:: python38 %TRANS% transform -i "%NDK_ROOT%\platform\8910\core\core_api.h" -o "%NDK_ROOT%\user\include\core_api.h" -oc "%NDK_ROOT%\user\src\core_api.c"
python38 %TRANS% "move" -f "%CORE_INC%\cs_types.h" "%CORE_INC%\am_openat_drv.h" "%CORE_TRAN_MAIN%\core_api.h" "%CORE_INC%\am_openat_common.h" "%CORE_INC%\am_openat_system.h" "%CORE_INC%\lua_type.h" "%CORE_INC%\std_type.h" "%CORE_INC%\luaconf.h" -d %USER_INC%
python38 %TRANS% "move" -f "%CORE_TRAN_MAIN%\core_api.c" -d %USER_SRC%

set CMAKE_LINKER=%NDK_ROOT%/platform/Air72x/toolchain/win32/gcc-arm-none-eabi/bin/arm-none-eabi-ld.exe
set CMAKE_C_COMPILER=%NDK_ROOT%/platform/Air72x/toolchain/win32/gcc-arm-none-eabi/bin/arm-none-eabi-gcc.exe
set CMAKE_OBJDUMP_COMPILER=%NDK_ROOT%/platform/Air72x/toolchain/win32/gcc-arm-none-eabi/bin/arm-none-eabi-objdump.exe
set CMAKE_READELF_COMPILER=%NDK_ROOT%/platform/Air72x/toolchain/win32/gcc-arm-none-eabi/bin/arm-none-eabi-readelf.exe
set CMAKE_OBJCOPY_COMPILER=%NDK_ROOT%/platform/Air72x/toolchain/win32/gcc-arm-none-eabi/bin/arm-none-eabi-objcopy.exe
set CCOPTION="-mcpu=cortex-a5 -mtune=generic-armv7-a -mfpu=neon-vfpv4  -mthumb -mfloat-abi=hard -mno-unaligned-access  -g -Os -Wall -std=c11 -c" 
goto BUILD

:ASR1603
set CMAKE_LINKER="C:/Program Files/DS-5/sw/ARMCompiler5.05/bin/armlink.exe"
set CMAKE_C_COMPILER="C:/Program Files/DS-5/sw/ARMCompiler5.05/bin/armcc.exe"
set CCOPTION="-c --c99 --cpu Cortex-R4 --no_unaligned_access -g -O2 --apcs /inter --diag_suppress 2084,1,2,177,550,6319 --gnu --thumb --loose_implicit_cast %PLATFROM%"
goto BUILD

:BUILD
if not exist %PROJECT_OUT% mkdir %PROJECT_OUT%
cd %PROJECT_ROOT%
%MAKE_DIR%\gnumake LR=%CMAKE_LINKER% CC=%CMAKE_C_COMPILER% CCOPTION=%CCOPTION%
copy %PROJECT_ROOT%\out\lib\user.lib %PROJECT_ROOT%\out\user_tmp.lib
%CMAKE_OBJDUMP_COMPILER% -S %PROJECT_ROOT%\out\user_tmp.lib > %PROJECT_OUT%\user.map
%CMAKE_READELF_COMPILER% -s %PROJECT_ROOT%\out\user_tmp.lib >> %PROJECT_OUT%\user.map
%CMAKE_OBJCOPY_COMPILER% -R .debug* %PROJECT_ROOT%\out\user_tmp.lib %PROJECT_OUT%\user.lib
del %NDK_ROOT%\out\user_tmp.lib
%MAKE_DIR%\gnumake clean

:: 删除转换后的头文件
if "%PLATFROM%"=="RDA8910" (
	python38 %TRANS% clear -f %USER_INC%\core_api.h %USER_SRC%\core_api.c %USER_INC%\cs_types.h %USER_INC%\am_openat_drv.h %USER_INC%\am_openat_common.h %USER_INC%\am_openat_system.h %USER_INC%\lua_type.h %USER_INC%\std_type.h %USER_INC%\luaconf.h
)

cd ..
:: rd /s /Q "out/project_debug"
