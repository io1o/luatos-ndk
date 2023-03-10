# 一、简介

- **LuatOS NDK定义**

&emsp;&emsp;LuatOS NDK(Native Development Kit，以下简称为NDK)是一种本地化接口（芯片硬件提供的原始接口）开发工具集。可以简单的理解为 **使用C/C++开发的接口，可以在lua上直接调用。**  对于商用的LuatOS系统，Lua虚拟机部分是闭源的，用户无法直接集成C/C++代码。NDK正是针对这一场景提供的解决方案，开发简单，容易上手，无需过多关注本地化实现部分。

- **应用场景**

&emsp;&emsp;NDK主要针对LuatOS闭源版本（例如LuatOS-Air/LuatOS-HMI/LuatOS-iRTU等)的以下几种场景：
- lua语言运行效率达不到要求，需要用C/C++这类底层语言。
- 已有成熟的C/C++代码需要集成到LuatOS中。
- 希望关键代码能够受到保护，避免lua容易被反编译的风险。
- 向第三方提供闭源lib库。

&emsp;&emsp;当然开源版本的LuatOS理论上也可以使用，不过针对开源版本，更建议直接将库源码放到LuatOS源码中构建编译。

- **原理介绍**

&emsp;&emsp;用户使用NDK将C代码编译成lib库后，和lua脚本文件一起打包下载到硬件中。LuatOS系统将lib库动态加载到内存中运行，并将lib库中提供的API接口注册到系统中。这样lua脚本就可以通过dl模块进行加载，并使用这类接口。

![输入图片说明](doc/arch.png)

- **仓库地址**

&emsp;&emsp;[LuatOS-NDK(Native Development Kit) (gitee.com)](https://gitee.com/openLuat/luatos-ndk)

# 二、目录说明

![NDK](doc/file.png)

# 三、使用说明

### 3.1、使用NDK开发包开发

##### 1、编译core版本

&emsp;&emsp;通过 http://erp.openluat.com/firm_customized 服务器定制支持NDK功能的固件，版本号>=3209

##### 2、编译NDK版本

&emsp;&emsp;根据core版本是否支持float功能，选择对应的编译方式。编译结束会在build目录下生成user.lib

```
float版本编译: build_float.bat
非float版本编译: build.bat 
```

##### 3、下载固件

&emsp;&emsp;使用luatools将build\user.lib、user\src\demo\scripts\main.lua testJson.lua和LuatOS-Air_V3209_RDA8910_RND_0x150000_TMP.pac 一起下载到模块中

##### 4、运行结果

![image-20220113205307312](doc/image-20220113205307312.png) 

   

### 3.2、使用LuatIDE开发（推荐）

##### 1、编译core版本

&emsp;&emsp;通过 http://erp.openluat.com/firm_customized 服务器定制支持NDK功能的固件，版本号>=3209

##### 2、基于demo新建NDK工程

![LuatIDE新建NDK工程](doc/LuatIDE新建NDK工程.png)

##### 3、点击调试按钮

![LuatIDE运行NDK工程](doc/LuatIDE运行NDK工程.png)

##### 4、运行结果

![LuatIDE运行日志](doc/LuatIDE运行日志.png)

# 四、代码示例

**以RTT COREMARK为例 (RT-Thread上的 MCU/CPU 性能测试小工具)**

- 下载代码

&emsp;&emsp;链接：https://github.com/RT-Thread/rtthread-apps.git

  ![image-20220112201214628](doc/image-20220112201214628.png) 

- 移植coremark代码

1. 在examples路径下创建coremark文件夹(参考demo创建对应的工程文件)。

2. 将core_list_join.c core_main.c core_matrix.c core_portme.c core_state.c coremark.h移到example\coremark\c\src\目录下 

3. 运行build.bat.

&emsp;&emsp;运行结果如下所示，coremark代码已经参与编译了，但是还有很多错误

   ![image-20220112202359127](doc/image-20220112202359127.png) 

4. 添加rttread.h文件，并解决编译错误：(注：下方截图右边都是修改后的)

   - core_list_join.c core_matrix.c core_state.c core_util.c不做任何修改

   - core_main.c 修改如下:

     ![image-20220112203007304](doc/image-20220112203007304.png) 

   - coremark.h 修改如下:

   - ![image-20220112203327180](doc/image-20220112203327180.png)

   - 其余的所有适配都放到rttread.h. 结果如下所示

     ![image-20220112201731146](doc/image-20220112201731146.png) 

   - 再次编译start.bat文件，生成了user.lib 结果如下：

     ![image-20220112203838452](doc/image-20220112203838452.png) 

5. 在example\coremark\c\src目录下新建lua_coremark.c 将coremark接口封装成lua接口给脚本调用。代码如下所示：

```
#include "core_api.h"

int lua_coremask(void *L)
{
/*coremark入口函数*/
extern int core_mark(void);
core_mark();

return 0;
}

luaL_Reg rtt_lib[] = {
{"coremark",lua_coremask},
{NULL, NULL}
};

```

6. 在example\coremark\c\src\main.c中注册rtt_lib. 然后再次运行start.bat

```
#include "core_api.h"

/*入口函数*/
int user_main(void *L)
{

/*rtt coremark*/
extern luaL_Reg rtt_lib[];
luaI_openlib(L, "rtt", rtt_lib, 0);

}
```

7. 编写main.lua运行rtt.coremake()

```
PROJECT = "COREMARK"
VERSION = "1.0.0"

--加载日志功能模块，并且设置日志输出等级
--如果关闭调用log模块接口输出的日志，等级设置为log.LOG_SILENT即可
require "log"
LOG_LEVEL = log.LOGLEVEL_TRACE
require "sys"

--加个延迟防止开机太快log丢失
rtos.sleep(1000)
--通过dl.open接口加载user.lib文件，并执行user_main入口函数
--user_main入口函数会注册rtt coremark，然后使用rtt.coremark()进行接口调用
local handle = dl.open("/lua/user.lib","user_main")
if handle then  
rtt.coremark()
dl.close(handle)
end

--启动系统框架
sys.init(0, 0)
sys.run()
```

8. 参考3.2使用LuatIDE开发进行调试




# 五、调试说明

- **如何调试死机问题**

&emsp;&emsp;可以通过AT指令`AT*EXINFO?`查询死机信息，根据死机信息可以判定死机位置，便于调试和解决问题；测试demo中有添加了该AT指令，如果死机过程中没有死机信息上报，可手动发指令查询。

NDK死机信息：

```
AT*EXINFO?
*EXINFO:poweron=4,assert=func=/lua/user.lib,pc=5ba-line=0-ra=0
*EXINFO:poweron=4,assert=func=/lua/user.lib,pc=5ba-line=0-ra=0
OK
AT*EXINFO? true OK nil
```

&emsp;&emsp;如上示`assert=func=/lua/user.lib`信息表明，死机位置位于`user.lib`文件中，可以根据`pc=5ba-line=0-ra=0`信息，在`out/user.map`文件中找到`5ba`所指位置处，定位导致死机的代码。

CORE死机信息：

```
AT*EXINFO?
*EXINFO:poweron=4,assert=func=-line=0-ra=0
*EXINFO:poweron=4,assert=func=-line=0-ra=0
OK
AT*EXINFO? true OK nil
```

&emsp;&emsp;如上示未标明`/lua/user.lib`类似信息，即为底层死机

- **常见的异常信息**

1.  [E]-[coroutine.resume] /lua/main.lua:36: dl.open fail relocate_section 620 unknown name: '                     undefFun1'

   导致的原因: user.lib中undefFun1接口未定义

2.  [E]-[coroutine.resume]/lua/main.lua:36: dl.open fail 

   可能是dl.open 库的路径传入不对

3.  [E]-[coroutine.resume] /lua/main.lua:36: dl.sym fail 

   可能是dl.open 入口函数名传入不对



# 六、附件

[api接口介绍](doc/api.md)