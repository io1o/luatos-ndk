@echo off



@REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
@REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
@REM wo quan ni du yi bian xia mian de ti shi!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
@REM Note: do not write any Chinese in the bat file. As long as you write Chinese, there will be problems in some special cases!!!!!!!
@REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
@REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
@REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


@REM Gets the path to the current file
set PROJECT_ROOT=%~dp0
@REM Example Switch the working path to the current path
cd %PROJECT_ROOT%

if "%1" == "" (
    goto NDK_USER
) else (
    goto LUATIDE_USER
)

:NDK_USER
    @REM If there is no incoming path to the NDK, go three levels up
    @REM The following lines are to get the upper level path of the current path
    cd ..
    @REM Save default NDK path
    set NDK_PATH=%CD%
    cd %PROJECT_ROOT%
    goto START

:LUATIDE_USER
    @REM If there is an incoming value, use the incoming value
    @REM This is mainly for the IDE. In the IDE, the compilation environment will be placed in appdata, and this path needs to be passed in from the outside
    set NDK_PATH=%1
    goto START

:START

echo NDK_PATH=%NDK_PATH%
@echo on

set PROJECT_OUT=%PROJECT_ROOT%\build

set NDK_ROOT=%NDK_PATH%
set TRANS=%NDK_ROOT%\tools\transform.py
set USER_INC=%PROJECT_ROOT%\include
set USER_SRC=%PROJECT_ROOT%\src
set MAKE_DIR=%NDK_ROOT%\platform\Air72x\toolchain\GnuWin32\bin
call %NDK_ROOT%\tools\launch.bat


set DFLAG= -DLUA_CORE -DLUA_USE_MTK_NUCLEUS -DLUAT_FLOATPOINT_SUPPORT

goto RDA8910
:: call tools/launch.bat project debug
:RDA8910
set CORE_INC="%NDK_ROOT%\platform\Air72x\core"
set CORE_TRAN_MAIN="%NDK_ROOT%\platform\Air72x\core\trans_api"
@REM if not exist %USER_INC% mkdir %USER_INC%
:: Conversion header file
@REM This line cannot be opened directly, nor can it be opened
:: python38 %TRANS% transform -i "%NDK_ROOT%\platform\8910\core\core_api.h" -o "%NDK_ROOT%\user\include\core_api.h" -oc "%NDK_ROOT%\user\src\core_api.c"

@REM python38 %TRANS% "move" -f "%CORE_INC%\cs_types.h" "%CORE_INC%\am_openat_drv.h" "%CORE_TRAN_MAIN%\core_api.h" "%CORE_INC%\am_openat_common.h" "%CORE_INC%\am_openat_system.h" "%CORE_INC%\lua_type.h" "%CORE_INC%\std_type.h" "%CORE_INC%\luaconf.h" -d %USER_INC%

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
%MAKE_DIR%\gnumake LR=%CMAKE_LINKER% CC=%CMAKE_C_COMPILER% CCOPTION=%CCOPTION% NDK_PATH=%NDK_PATH%
copy %PROJECT_ROOT%\out\lib\user.lib %PROJECT_ROOT%\out\user_tmp.lib
%CMAKE_OBJDUMP_COMPILER% -S %PROJECT_ROOT%\out\user_tmp.lib > %PROJECT_OUT%\user.map
%CMAKE_READELF_COMPILER% -s %PROJECT_ROOT%\out\user_tmp.lib >> %PROJECT_OUT%\user.map
%CMAKE_OBJCOPY_COMPILER% -R .debug* %PROJECT_ROOT%\out\user_tmp.lib %PROJECT_OUT%\user.lib
rmdir /S/Q %PROJECT_ROOT%\out\

@REM When IDE is used, it will call compilation before debugging every time, so it cannot be cleaned
@REM %MAKE_DIR%\gnumake clean

:: Delete the converted header file
@REM if "%PLATFROM%"=="RDA8910" (
@REM 	python38 %TRANS% clear -f %USER_INC%\core_api.h %USER_SRC%\core_api.c %USER_INC%\cs_types.h %USER_INC%\am_openat_drv.h %USER_INC%\am_openat_common.h %USER_INC%\am_openat_system.h %USER_INC%\lua_type.h %USER_INC%\std_type.h %USER_INC%\luaconf.h
@REM )

cd ..
:: rd /s /Q "out/project_debug"
