[TOC]

# API

<!--注：接口功能的测试，确定各个参数的使用边界，测试用例需要覆盖到所有支持的参数-->

## 静态库加载卸载接口

**注：静态库加载卸载接口是给lua使用**

### 1. dl.open

加载静态库并执行入口函数

- 语法

  `handle = dl.open(lib,main)`

- 参数

  | 传入值 | 释义                               |
  | ------ | ---------------------------------- |
  | lib    | lib库所在的路径。如：/lua/user.lib |
  | main   | lib库的入口函数                    |

- 返回值

  handle：库的句柄

### 2. dl.close

卸载动态库

- 语法

  `dl.close(handle)`

- 参数

  | 传入值 | 释义             |
  | ------ | ---------------- |
  | handle | 打开库返回的句柄 |

- 返回值

  nil

## 标准库接口

目前支持的标准库接口如下：

字符串操作相关接口:

size_t  strlen(const char *);

char*  strchr(const char *,int);

char*  strcpy(char *,const char *);

char*  strstr(const char *, const char *);

char*  strncpy(char *,const char *, size_t);

char*  strcat(char *restrict, const char *restrict);

int	   strcmp(const char *,const char *);

int 	  sprintf(char *, const char *, ...);

int  	 strncmp(const char *,const char *,size_t);

int 	  sscanf(const char * buf, const char * fmt, ...);

int   	snprintf(char * buf, size_t len, const char *fmt, ...);

void    OPENAT_lua_print(char * fmt, ...); /* lua日志打印*/

存储操作相关接口：

void * memset (void *, int, size_t);

void * memchr (const void *, int, size_t);

void * memmove (void *, const void *, size_t);

void * memcpy (void *restrict, const void *restrict, size_t);

int       memcmp (const void *, const void *, size_t);

void * OPENAT_malloc(size_t size);

void    OPENAT_free(void *ptr);

## GPIO接口

### 1. OPENAT_config_gpio

- 接口功能

  gpio配置接口

- 接口定义

  BOOL OPENAT_config_gpio(

  ​			  E_AMOPENAT_GPIO_PORT port, 

  ​              T_AMOPENAT_GPIO_CFG *cfg

  )

- 参数描述

  |            参数            |       解释       | 取值                                                         |
  | :------------------------: | :--------------: | ------------------------------------------------------------ |
  |            port            |     GPIO编号     |                                                              |
  |            cfg             |     GPIO配置     |                                                              |
  |         cfg->mode          |     GPIO模式     | OPENAT_GPIO_INVALID_MODE,<br/>OPENAT_GPIO_INPUT, <br/>OPENAT_GPIO_OUTPUT,<br/>OPENAT_GPIO_INPUT_INT,<br/>OPENAT_GPIO_INPUT_INT2 |
  |         cfg->param         |     GPIO参数     |                                                              |
  |  cfg->param.defaultState   | GPIO默认电平状态 | 0/1，低电平/高电平                                           |
  |     cfg->param.intCfg      |   GPIO中断配置   |                                                              |
  | cfg->param.intCfg.debounce |     防抖延时     | 单位ms                                                       |
  |    param.intCfg.intType    |     中断类型     | OPENAT_GPIO_NO_INT,<br/>OPENAT_GPIO_INT_HIGH_LEVEL,<br/>OPENAT_GPIO_INT_LOW_LEVEL,<br/>OPENAT_GPIO_INT_BOTH_EDGE,<br/>OPENAT_GPIO_INT_FALLING_EDGE,<br/>OPENAT_GPIO_INT_RAISING_EDGE, |
  |     param.intCfg.intCb     | 中断回调处理函数 | typedef void (*OPENAT_GPIO_EVT_HANDLE)(E_OPENAT_DRV_EVT evt, E_AMOPENAT_GPIO_PORT gpioPort,unsigned char state); |
  |    cfg->param.pullState    | GPIO配置上拉下拉 | OPENAT_GPIO_NO_PULL,<br/>OPENAT_GPIO_PULLDOWN, <br/>OPENAT_GPIO_PULLUP |

- 返回值


​		TRUE：成功

​		FALSE：失败

### 2. OPENAT_set_gpio

- 接口功能

  设置GPIO输出电平

- 接口定义

  BOOL OPENAT_set_gpio(

  ​              E_AMOPENAT_GPIO_PORT port,

  ​              UINT8 value

  )

- 参数描述

  | 参数  |        解释        | 取值               |
  | :---: | :----------------: | :----------------- |
  | port  |      GPIO编号      |                    |
  | value | 设置GPIO电平状态值 | 0/1，低电平/高电平 |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 3. OPENAT_read_gpio

- 接口功能

  读取GPIO输入电平

- 接口定义

  BOOL OPENAT_read_gpio(

  ​              E_AMOPENAT_GPIO_PORT port, 

  ​              UINT8* value

  )

- 参数描述

  | 参数  |           解释           | 取值               |
  | :---: | :----------------------: | :----------------- |
  | port  |         GPIO编号         |                    |
  | value | 读取GPIO电平状态值的结果 | 0/1，低电平/高电平 |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 4. OPENAT_gpioPulse

- 接口功能

  GPIO方波输出接口

- 接口定义

  BOOL OPENAT_gpioPulse(

  ​              E_AMOPENAT_GPIO_PORT port,

  ​              unsigned high_us,

  ​              unsigned low_us,

  ​              unsigned count,

  ​              unsigned idle

  )

- 参数描述

  |  参数   | 解释                     | 取值               |
  | :-----: | :----------------------- | :----------------- |
  |  port   | GPIO编号                 |                    |
  | high_us | 高电平持续时间           | 单位us             |
  | low_us  | 低电平持续时间           | 单位us             |
  |  count  | 高电平个数               |                    |
  |  idle   | 输出完成后，管脚电平状态 | 0/1，低电平/高电平 |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 5. OPENAT_close_gpio

- 接口功能

  关闭GPIO配置

- 接口定义

  BOOL OPENAT_close_gpio(

  ​              E_AMOPENAT_GPIO_PORT port

  )

- 参数描述.

  | 参数 |   解释   | 取值 |
  | :--: | :------: | :--- |
  | port | GPIO编号 |      |

- 返回值

​		TRUE：成功

​		FALSE：失败

## UART接口

### 1. OPENAT_config_uart

- 接口功能

  URAT配置接口

- 接口定义

  BOOL OPENAT_config_uart(

  ​              E_AMOPENAT_UART_PORT port,

  ​              T_AMOPENAT_UART_PARAM  *cfg

  )

- 参数描述

  |       参数        |          解释           | 取值                                                         |
  | :---------------: | :---------------------: | ------------------------------------------------------------ |
  |       port        |        URAT编号         | OPENAT_UART_1,<br/>OPENAT_UART_2,<br/>OPENAT_UART_3,<br/>OPENAT_UART_USB |
  |        cfg        |        URAT配置         |                                                              |
  |     cfg->baud     |         波特率          | OPENAT_UART_BAUD_1200 = 1200,<br/>  OPENAT_UART_BAUD_2400 = 2400,<br/>  OPENAT_UART_BAUD_4800 = 4800,<br/>  OPENAT_UART_BAUD_9600 = 9600,<br/>  OPENAT_UART_BAUD_14400 = 14400,<br/>  OPENAT_UART_BAUD_19200 = 19200,<br/>  OPENAT_UART_BAUD_28800 = 28800,<br/>  OPENAT_UART_BAUD_38400 = 38400,<br/>  OPENAT_UART_BAUD_57600 = 57600,<br/>  OPENAT_UART_BAUD_76800 = 76800,<br/>  OPENAT_UART_BAUD_115200 = 115200,<br/>  OPENAT_UART_BAUD_230400 = 230400,<br/>  OPENAT_UART_BAUD_460800 = 460800,<br/>  OPENAT_UART_BAUD_576000 = 576000,<br/>  OPENAT_UART_BAUD_921600 = 921600,<br/>  OPENAT_UART_BAUD_1152000 = 1152000,<br/>  OPENAT_UART_BAUD_4000000 = 4000000, |
  |   cfg->dataBits   |         数据位          | /* 6-8 */                                                    |
  |   cfg->stopBits   |         停止位          | /* 1-2 */                                                    |
  |    cfg->parity    |         校验位          | OPENAT_UART_NO_PARITY,<br/>  OPENAT_UART_ODD_PARITY,<br/>  OPENAT_UART_EVEN_PARITY |
  | cfg->flowControl  |          流控           | OPENAT_UART_FLOWCONTROL_NONE,<br/>  OPENAT_UART_FLOWCONTROL_HW,<br/>  OPENAT_UART_FLOWCONTROL_SW, |
  | cfg->uartMsgHande |        回调函数         | typedef void (\*PUART_MESSAGE)(T_AMOPENAT_UART_MESSAGE* evt); |
  | cfg->txDoneReport | 判断是否上报UART TXDONE | TRUE/FALSE                                                   |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 2. OPENAT_read_uart

- 接口功能

  读uart数据

- 接口定义

  UINT32 OPENAT_read_uart(

  ​              E_AMOPENAT_UART_PORT port

  ​              UINT8* buf,

  ​              UINT32 bufLen, 

  ​              UINT32 timeoutMs

  )

- 参数描述

  |   参数    |     解释     | 取值                                                         |
  | :-------: | :----------: | ------------------------------------------------------------ |
  |   port    |   URAT编号   | OPENAT_UART_1,<br/>OPENAT_UART_2,<br/>OPENAT_UART_3,<br/>OPENAT_UART_USB |
  |    buf    | 存储数据地址 |                                                              |
  |  bufLen   | 存储空间长度 |                                                              |
  | timeoutMs | 读取超时时间 | 单位ms                                                       |

- 返回值

​		返回读取数据的实际长度

### 3. OPENAT_write_uart

- 接口功能

  写入uart数据

- 接口定义

  UINT32 OPENAT_write_uart(

  ​              E_AMOPENAT_UART_PORT port,

  ​              UINT8* buf, 

  ​              UINT32 bufLen

  )

- 参数描述

  |  参数  |     解释     | 取值                                                         |
  | :----: | :----------: | ------------------------------------------------------------ |
  |  port  |   URAT编号   | OPENAT_UART_1,<br/>OPENAT_UART_2,<br/>OPENAT_UART_3,<br/>OPENAT_UART_USB |
  |  buf   | 写入数据地址 |                                                              |
  | bufLen | 写入数据长度 |                                                              |

- 返回值

​	返回实际写入长度

### 4. OPENAT_close_uart

- 接口功能

  关闭uart配置

- 接口定义

  BOOL OPENAT_close_uart(

  ​              E_AMOPENAT_UART_PORT port

  )

- 参数描述

  | 参数 |   解释   | 取值                                                         |
  | :--: | :------: | ------------------------------------------------------------ |
  | port | URAT编号 | OPENAT_UART_1,<br/>OPENAT_UART_2,<br/>OPENAT_UART_3,<br/>OPENAT_UART_USB |

- 返回值

​		TRUE：成功

​		FALSE：失败

## 系统接口

### 1. 线程

### 1.1 OPENAT_create_task

- 接口功能

  创建线程接口

- 接口定义

  BOOL OPENAT_create_task(

  ​              HANDLE* handlePtr,

  ​              PTASK_MAIN pTaskEntry,

  ​              PVOID pParameter,

  ​              PVOID pStackAddr, 

  ​              UINT32 nStackSize, 

  ​              UINT8 nPriority,  

  ​              UINT16 nCreationFlags,  

  ​              UINT16 nTimeSlice, 

  ​			  PCHAR pTaskName

  )

- 参数描述

  | 参数           | 解释                                                         |
  | -------------- | ------------------------------------------------------------ |
  | handlePtr      | 线程句柄                                                     |
  | pTaskEntry     | 线程主函数                                                   |
  | pParameter     | 作为参数传递给线程主函数                                     |
  | pStackAddr     | 线程栈地址，当前不支持，请传入NULL                           |
  | nStackSize     | 线程栈大小                                                   |
  | nPriority      | 线程优先级，该参数越大，线程优先级越低                       |
  | nCreationFlags | 线程启动标记<br>线程创建后，立即启动.<br/>线程创建后，先挂起./* 线程启动标记， 请参考E_AMOPENAT_OS_CREATION_FLAG */ |
  | nTimeSlice     | 暂时不支持，请传入0                                          |
  | pTaskName      | 线程名称                                                     |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 1.2 OPENAT_current_task

- 接口功能

  获取当前线程接口 

- 接口定义

  HANDLE OPENAT_current_task(

  ​			  VOID

  )

- 参数描述

  无
  
- 返回值

​		返回当前线程句柄

### 1.3 OPENAT_suspend_task

- 接口功能

  挂起线程接口

- 接口定义

  BOOL OPENAT_suspend_task(

  ​			  HANDLE hTask

  )

- 参数描述

  | 参数  |              解释               |
  | :---: | :-----------------------------: |
  | hTask | 线程句柄，create_task接口返回值 |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 1.4 OPENAT_resume_task

- 接口功能

  恢复线程接口

- 接口定义

  BOOL OPENAT_resume_task(

  ​			  HANDLE hTask 

  )

- 参数描述

  | 参数  |              解释               |
  | :---: | :-----------------------------: |
  | hTask | 线程句柄，create_task接口返回值 |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 1.5 OPENAT_get_task_info

- 接口功能

  获取当前线程创建信息接口

- 接口定义

  BOOL OPENAT_get_task_info(

  ​              HANDLE hTask,

  ​              T_AMOPENAT_TASK_INFO \*pTaskInfo

  )

- 参数描述

  |   参数    |              解释               |
  | :-------: | :-----------------------------: |
  |   hTask   | 线程句柄，create_task接口返回值 |
  | pTaskInfo |        线程信息存储接口         |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 1.6 OPENAT_sleep

- 接口功能

  系统睡眠接口

- 接口定义

  BOOL OPENAT_sleep(

  ​              UINT32 nMillisecondes

  )

- 参数描述

  |      参数      |   解释   | 取值   |
  | :------------: | :------: | :----- |
  | nMillisecondes | 睡眠时间 | 单位ms |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 1.7 OPENAT_delete_task

- 接口功能

  删除线程接口

- 接口定义

  VOID OPENAT_delete_task(

  ​			  HANDLE  task

  )

- 参数描述

  | 参数 |              解释               |
  | :--: | :-----------------------------: |
  | task | 线程句柄，create_task接口返回值 |

- 返回值

​		无

### 2. 消息

### 2.1 OPENAT_wait_message

- 接口功能

  等待线程消息接口

- 接口定义

  BOOL OPENAT_wait_message(

  ​                   HANDLE  task,

  ​                   int* msg_id,

  ​                   void* * ppMessage,

  ​                   UINT32 nTimeOut

  )

- 参数描述

  |   参数    |                解释                 |
  | :-------: | :---------------------------------: |
  |   task    | 当前线程句柄，create_task接口返回值 |
  |  msg_id   |               消息ID                |
  | ppMessage |          存储消息体的指针           |
  | nTimeOut  |         超时时间(单位：ms)          |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 2.2 OPENAT_send_message

- 接口功能

  发送消息接口，添加到消息队列尾部

- 接口定义

  BOOL OPENAT_send_message(

  ​                   HANDLE  destTask,

  ​                   int msg_id,

  ​                   void* pMessage, 

  ​                   int message_length

  )

- 参数描述

  |      参数      |       解释       |
  | :------------: | :--------------: |
  |    destTask    | 发送目标线程句柄 |
  |     msg_id     |      消息ID      |
  |   ppMessage    | 存储消息体的指针 |
  | message_length |    消息体长度    |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 2.3 OPENAT_SendHighPriorityMessage

- 接口功能

  发送高优先级消息接口，添加到消息队列头部

- 接口定义

  BOOL OPENAT_SendHighPriorityMessage(

  ​            HANDLE  destTask,

  ​            int msg_id,

  ​            void* pMessage, 

  ​            int message_length

  )

- 参数描述

  |      参数      |       解释       |
  | :------------: | :--------------: |
  |    destTask    | 发送目标线程句柄 |
  |     msg_id     |      消息ID      |
  |   ppMessage    | 存储消息体的指针 |
  | message_length |    消息体长度    |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 2.4 OPENAT_send_internal_message

- 接口功能

  发送线程内部消息接口，添加到消息队列尾部

- 接口定义

  BOOL OPENAT_send_internal_message(

  ​                   int msg_id,

  ​                   void* pMessage,

  ​                   int message_length

  )

- 参数描述

  |      参数      |       解释       |
  | :------------: | :--------------: |
  |     msg_id     |      消息ID      |
  |   ppMessage    | 存储消息体的指针 |
  | message_length |    消息体长度    |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 2.5 OPENAT_msg_to_lua

- 接口功能

  发送消息给lua虚拟机

- 接口定义

  bool OPENAT_msg_to_lua(

  ​              UINT8 msg_id,

  ​              BOOL result,

  ​              INT32 num,

  ​              CHAR* data,

  ​              UINT32 dataLen

  )

- 参数描述

  |  参数   |      解释      |
  | :-----: | :------------: |
  | msg_id  |     消息ID     |
  | result  |                |
  |   num   |                |
  |  data   | 消息体数据指针 |
  | dataLen | 消息体数据长度 |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 2.6 OPENAT_available_message

- 接口功能

  检测消息队列中是否有消息

- 接口定义

  BOOL OPENAT_available_message(

  ​              HANDLE hTask 

  )

- 参数描述

  | 参数  |              解释               |
  | :---: | :-----------------------------: |
  | hTask | 线程句柄，create_task接口返回值 |

- 返回值

​		TRUE：成功

​		FALSE：失败

### 3. 定时器

### 3.1 OPENAT_create_timer

- 接口功能

  创建定时器接口

- 接口定义

  HANDLE OPENAT_create_timer(

  ​              PTIMER_EXPFUNC pFunc, 

  ​              PVOID pParameter

  )

- 参数描述

  |    参数    |               解释               |
  | :--------: | :------------------------------: |
  |   pFunc    |        定时器到时处理函数        |
  | pParameter | 作为参数传递给定时器到时处理函数 |

- 返回值

​		定时器句柄

### 3.2 OPENAT_create_timerTask

- 接口功能

  创建定时器接口

- 接口定义

  HANDLE OPENAT_create_timerTask(

  ​              PTIMER_EXPFUNC pFunc,  

  ​              PVOID pParameter

  )

- 参数描述

  |    参数    |               解释               |
  | :--------: | :------------------------------: |
  |   pFunc    |        定时器到时处理函数        |
  | pParameter | 作为参数传递给定时器到时处理函数 |

- 返回值

​		定时器句柄

### 3.3 OPENAT_create_hir_timer

- 接口功能

  创建定时器接口

- 接口定义

  HANDLE OPENAT_create_hir_timer(

  ​              PTIMER_EXPFUNC pFunc,  

  ​              PVOID pParameter 

  )

- 参数描述

  |    参数    |               解释               |
  | :--------: | :------------------------------: |
  |   pFunc    |        定时器到时处理函数        |
  | pParameter | 作为参数传递给定时器到时处理函数 |

- 返回值

​		定时器句柄

### 3.4 OPENAT_start_timer

- 接口功能

  启动定时器接口

- 接口定义

  BOOL OPENAT_start_timer( 

  ​              HANDLE hTimer, 

  ​              UINT32 nMillisecondes 

  )

- 参数描述

  |      参数      |                解释                |
  | :------------: | :--------------------------------: |
  |     hTimer     | 定时器句柄，create_timer接口返回值 |
  | nMillisecondes |       定时器时间（单位：ms）       |

- 返回值

​		TRUE: 成功

​		FALSE: 失败

### 3.5 OPENAT_loop_start_timer

- 接口功能

  启动循环定时器接口

- 接口定义

  BOOL OPENAT_loop_start_timer(

  ​              HANDLE hTimer, 

  ​              UINT32 nMillisecondes

  )

- 参数描述

  |      参数      |                解释                |
  | :------------: | :--------------------------------: |
  |     hTimer     | 定时器句柄，create_timer接口返回值 |
  | nMillisecondes |       定时器时间（单位：ms）       |

- 返回值

​		TRUE: 成功

​		FALSE: 失败

### 3.6 OPENAT_start_precise_timer

- 接口功能

  启动硬件定时器接口

- 接口定义

  BOOL OPENAT_start_precise_timer(

  ​              HANDLE hTimer,

  ​              UINT32 nMillisecondes 

  )

- 参数描述

  |      参数      |                解释                |
  | :------------: | :--------------------------------: |
  |     hTimer     | 定时器句柄，create_timer接口返回值 |
  | nMillisecondes |       定时器时间（单位：ms）       |

- 返回值

​		TRUE: 成功

​		FALSE: 失败

### 3.7 OPENAT_timer_remaining

- 接口功能

  获取定时器剩余时间接口

- 接口定义

  UINT64 OPENAT_timer_remaining(

  ​       HANDLE hTimer

  )

- 参数描述

  |  参数  |                解释                |
  | :----: | :--------------------------------: |
  | hTimer | 定时器句柄，create_timer接口返回值 |

- 返回值

​		定时器剩余时间，单位ms;<br/>		如果定时器已经结束，返回0

### 3.8 OPENAT_stop_timer

- 接口功能

  停止定时器接口

- 接口定义

  BOOL OPENAT_stop_timer(

  ​              HANDLE hTimer

  )

- 参数描述

  |  参数  |                解释                |
  | :----: | :--------------------------------: |
  | hTimer | 定时器句柄，create_timer接口返回值 |

- 返回值

​		TRUE: 成功

​		FALSE: 失败

## lua虚拟机接口

> 如下接口说明仅为常用lua虚拟机接口说明，如您想更为详细的了解lua虚拟机的接口，可以参考[Lua 5.3 参考手册](https://www.bookstack.cn/books/lua-5.3)。

### 1. 打开 Lua库

### 1.1 luaI_openlib 

- 接口功能

  打开 Lua库

- 接口定义

  void luaI_openlib (void *L, 

  const char *libname, 

  const luaL_Reg *l, 

  int nup);

- 参数描述

  |  参数   |                 解释                 |
  | :-----: | :----------------------------------: |
  |    L    | `lua_state`对象，包含数据栈和调用栈  |
  | libname | 封装lua库名，用于调用该lua库中的函数 |
  |    l    |            函数注册表地址            |
  |   nup   |        upvalues个数，默认传0         |

- 返回值

​		无

### 2. 获取参数

### 2.1 lua_gettop

- 接口功能

  获取栈顶元素

- 接口定义

  int lua_gettop (

  void *L)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |

- 返回值

​		栈顶元素值

### 2.2 luaL_optinteger

- 接口功能

  获取整型可选参数，该参数是一个整数（或可以转换为一个整数）

- 接口定义

  int luaL_optinteger (

  void *L, 

  int nArg, 

  int def)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  | nArg |              参数序号               |
  | def  |   如果未传入该参数，设置的默认值    |

- 返回值

​		返回获取的整数值

### 2.3 luaL_optnumber

- 接口功能

  获取函数的第 `nArg` 个参数，该参数是一个数值

- 接口定义

  long luaL_optnumber (

  void *L, 

  int nArg, 

  long def)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  | nArg |              参数序号               |
  | def  |   如果未传入该参数，设置的默认值    |

- 返回值

​		返回获取到的数值

### 2.4 luaL_optlstring

- 接口功能

  获取函数的第 `nArg` 个参数，该参数是一个字符串

- 接口定义

  const char *luaL_optlstring (

  void *L, 

  int nArg, 

  const char *def, 

  size_t *l)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  | nArg |              参数序号               |
  | def  |   如果未传入该参数，设置的默认值    |
  |  l   |             字符串长度              |

- 返回值

​		`string`类型参数值

### 2.5 luaL_checktype

- 接口功能

  检查函数的第 `nArg` 个参数的类型是否是 `t`

- 接口定义

  void luaL_checktype (

  void *L, 

  int nArg, 

  int t)

- 参数描述

  | 参数 |                解释                 | 取值                                                         |
  | :--: | :---------------------------------: | :----------------------------------------------------------- |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |                                                              |
  | nArg |              参数序号               |                                                              |
  |  t   |            `lua`参数类型            | LUA_TNIL<br/>LUA_TBOOLEAN<br/>LUA_TLIGHTUSERDATA<br/>LUA_TNUMBER<br/>LUA_TSTRING<br/>LUA_TTABLE<br/>LUA_TFUNCTION<br/>LUA_TUSERDATA<br/>LUA_TTHREAD |

- 返回值

  无

### 2.6 luaL_checkinteger

- 接口功能

  检查函数的第 `nArg` 个参数是否是一个整数或是可以被转换为一个整数

- 接口定义

  int luaL_checkinteger (

  void *L, 

  int nArg)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  | nArg |              参数序号               |

- 返回值

​		返回这个(或转换后的)整数值

### 2.7 luaL_checknumber

- 接口功能

  检查函数的第 `nArg` 个参数是否是一个数字

- 接口定义

  long luaL_checknumber (

  void *L, 

  int nArg)

- 参数描述

  | 参数 |               解释                |
  | :--: | :-------------------------------: |
  |  L   | lua_state对象，包含数据栈和调用栈 |
  | nArg |             参数序号              |

- 返回值

​		返回这个数字

### 2.8 luaL_checklstring

- 接口功能

  检查函数的第 `nArg` 个参数是否是一个字符串

- 接口定义

  const char *luaL_checklstring (

  void *L,

  int nArg, 

  size_t *l)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  | nArg |              参数序号               |
  | def  |   如果未传入该参数，设置的默认值    |
  |  l   |             字符串长度              |

- 返回值

​		返回这个字符串

### 3. 表

### 3.1 lua_createtable

- 接口功能

  创建新的空表压栈。

- 接口定义

  void lua_createtable(

  void *L,

  int narray,

  int nrec)

- 参数描述

  |  参数  |                解释                 |
  | :----: | :---------------------------------: |
  |   L    | `lua_state`对象，包含数据栈和调用栈 |
  | narray |  该表作为序列使用时会有多少个元素   |
  |  nrec  |   该表可能拥有多少序列之外的元素    |

- 返回值

​		无

### 3.2 lua_gettable

- 接口功能

  获取idx的元表并压入栈顶

- 接口定义

  void lua_gettable (

  void *L, 

  int idx)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  | idx  |               索引值                |

- 返回值

​		无

### 3.3 setfieldInt

- 接口功能

  添加整型字段到表中

- 接口定义

  void setfieldInt(

  void *L, 

  const char *key,

  int value)

- 参数描述

  | 参数  |                解释                 |
  | :---: | :---------------------------------: |
  |   L   | `lua_state`对象，包含数据栈和调用栈 |
  |  key  |               字段名                |
  | value |           对应key字段的值           |

- 返回值

​		无

### 3.4 setfieldBool

- 接口功能

  添加布尔类型的字段到表中

- 接口定义

  void setfieldBool(

  void *L,

  const char *key, 

  int value)

- 参数描述

  | 参数  |                解释                 |
  | :---: | :---------------------------------: |
  |   L   | `lua_state`对象，包含数据栈和调用栈 |
  |  key  |               字段名                |
  | value |           对应key字段的值           |

- 返回值

  无

### 3.5 setfieldString

- 接口功能

  添加字符串类型的字段到表中

- 接口定义

  void setfieldString(

  void* L, 

  const char* key, 

  const char* str, 

  const size_t len)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  | key  |               字段名                |
  | str  |         对应key字段的字符串         |
  | len  |             字符串长度              |

- 返回值

​		无

### 4. 压栈

### 4.1 lua_pushinteger

- 接口功能

  把值为 `n` 的整数压栈

- 接口定义

  void lua_pushinteger (

  void *L, 

  int n)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  |  n   |           lua函数的返回值           |
  
- 返回值

​		无

### 4.2 lua_pushnumber

- 接口功能

  把值为 `n` 的数值压栈

- 接口定义

  void lua_pushnumber (

  void *L, 

  long n)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  |  n   |         number类型的返回值          |

- 返回值

​		无

### 4.3 lua_pushlstring

- 接口功能

  把长度为`len`的`s`字符串压栈

- 接口定义

  void lua_pushlstring (

  void *L, 

  const char *s,

  size_t len)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  |  s   |         string类型的返回值          |
  | len  |             字符串长度              |

- 返回值

​		无

### 4.4 lua_pushboolean

- 接口功能

  把boolean类型的b值压栈

- 接口定义

  void lua_pushboolean (

  void *L,

  int b)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  |  b   |         boolean类型的返回值         |

- 返回值

​		无

### 5. 类型判断

### 5.1 lua_isnumber

- 接口功能

  判断给定的索引值是否为数字，或可转换为数字的字符串

- 接口定义

  int lua_isnumber (

  void *L, 

  int idx)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  | idx  |               索引值                |

- 返回值

​		是返回 1 

​		否返回 0 

### 5.2 lua_isstring

- 接口功能

  判断索引值是否为一个字符串或是一个数字（数字总能转换成字符串）

- 接口定义

  int lua_isstring (

  void *L, 

  int idx)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  | idx  |               索引值                |

- 返回值

​		是返回 1 

​		否返回 0 

### 5.3 lua_iscfunction

- 接口功能

  判断索引值是否为一个 C 函数

- 接口定义

  int lua_iscfunction (

  void *L, 

  int idx)

- 参数描述

  | 参数 |                解释                 |
  | :--: | :---------------------------------: |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |
  | idx  |               索引值                |

- 返回值

​		是返回 1 

​		否返回 0 

### 5.4 lua_typename

- 接口功能

  获取`t` 的类型名

- 接口定义

  const char *lua_typename (

  void *L, 

  int t)

- 参数描述

  | 参数 |                解释                 | 取值                                                         |
  | :--: | :---------------------------------: | :----------------------------------------------------------- |
  |  L   | `lua_state`对象，包含数据栈和调用栈 |                                                              |
  |  t   |             类型索引值              | LUA_TNIL<br/>LUA_TBOOLEAN<br/>LUA_TLIGHTUSERDATA<br/>LUA_TNUMBER<br/>LUA_TSTRING<br/>LUA_TTABLE<br/>LUA_TFUNCTION<br/>LUA_TUSERDATA<br/>LUA_TTHREAD |

- 返回值

  字符串表示的类型名，如：

  | "nil", "boolean", "userdata", "number",<br/>"string", "table", "function", "userdata", <br/>"thread","proto", "upval" |
  | ------------------------------------------------------------ |

​		



