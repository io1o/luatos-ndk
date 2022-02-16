#include "cs_types.h"
#include "stdarg.h"
#include "am_openat_drv.h"
#include "am_openat_system.h"
#include "std_type.h"
#include "lua_type.h"
extern void (*OPENAT_lua_print)(char * fmt,...);
extern bool (*OPENAT_msg_to_lua)(UINT8 msg_id,BOOL result,INT32 num,CHAR* data,UINT32 dataLen);
extern void (*stderr)(void);
extern void (*stdin)(void);
extern void (*stdout)(void);
extern size_t (*strlen)(const char *);
extern char* (*strchr)(const char *,int);
extern char* (*strcpy)(char *,const char *);
extern char* (*strstr)(const char *, const char *);
extern char* (*strncpy)(char *,const char *, size_t);
extern char* (*strcat)(char *__restrict, const char *__restrict);
extern long  (*strtol)(const char *, char **, int);
extern int   (*strcmp)(const char *,const char *);
extern int   (*sprintf)(char *, const char *, ...);
extern int   (*strncmp)(const char *,const char *,size_t);
extern int   (*strncasecmp)(const char *, const char *, size_t);
extern int   (*sscanf)(const char * buf, const char * fmt, ...);
extern int   (*snprintf)(char * buf, size_t len, const char *fmt, ...);
extern int   (*fprintf)(void *err, const char *fmt, ...);
extern int   (*vsnprintf)(char *buf, size_t size, const char *fmt, ...);
extern int   (*printf)(const char *fmt, ...);
extern void* (*memchr)(const void *, int, size_t);
extern void* (*memmove)(void *, const void *, size_t);
extern int   (*memcmp)(const void *, const void *, size_t);
extern void* (*OPENAT_malloc)(size_t size);
extern void* (*OPENAT_realloc)(PVOID ptr, UINT32 size);
extern void  (*OPENAT_free)(void *ptr);
extern void  (*OPENAT_assert)(                                           /* 断言接口 */
                            char condition,                     /* 条件 */
                            char *func,                         /* 函数名称 */
                            unsigned int line                   /* 行数 */
                            );
extern INT64 (*OPENAT_get_system_tick)(                                   /* 获取系统tick接口 */
                            VOID
                            );
extern double (*floor)(double);
extern BOOL (*OPENAT_config_gpio)(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO编号 */
                            T_AMOPENAT_GPIO_CFG *cfg            /* 输出或输入 */
                            );
extern BOOL (*OPENAT_set_gpio)(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO编号 */
                            UINT8 value                         /* 0 or 1 */
                            );
extern BOOL (*OPENAT_read_gpio)(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO编号 */
                            UINT8* value                        /* 结果 0 or 1 */
                            );
extern BOOL (*OPENAT_close_gpio)(
                            E_AMOPENAT_GPIO_PORT port           /* GPIO编号 */
                            );
extern BOOL (*OPENAT_gpioPulse)(
                            E_AMOPENAT_GPIO_PORT port,
                            unsigned high_us,
                            unsigned low_us,
                            unsigned count,
                            unsigned idle
                            );
extern BOOL (*OPENAT_config_uart)(
                            E_AMOPENAT_UART_PORT port,          /* UART 编号 */
                            T_AMOPENAT_UART_PARAM *cfg          /* 初始化参数 */
                            );
extern UINT32 (*OPENAT_read_uart)(                                        /* 实际读取长度 */
                            E_AMOPENAT_UART_PORT port,          /* UART 编号 */
                            UINT8* buf,                         /* 存储数据地址 */
                            UINT32 bufLen,                      /* 存储空间长度 */
                            UINT32 timeoutMs                    /* 读取超时 ms */
                            );
extern UINT32 (*OPENAT_write_uart)(                                       /* 实际写入长度 */
                            E_AMOPENAT_UART_PORT port,          /* UART 编号 */
                            UINT8* buf,                         /* 写入数据地址 */
                            UINT32 bufLen                       /* 写入数据长度 */
                            );
extern BOOL (*OPENAT_close_uart)(
                            E_AMOPENAT_UART_PORT port           /* UART 编号 */
                            );
extern BOOL (*OPENAT_open_i2c)(E_AMOPENAT_I2C_PORT port, 
                              T_AMOPENAT_I2C_PARAM *cfg);
extern UINT32 (*OPENAT_read_i2c)(E_AMOPENAT_I2C_PORT port, 
                                UINT8 slaveAddr, 
                                CONST UINT16 *pRegAddr, 
                                UINT8* buf,
                                UINT32 bufLen);
extern UINT32 (*OPENAT_write_i2c)(E_AMOPENAT_I2C_PORT port, 
                                UINT8 slaveAddr, 
                                CONST UINT16 *pRegAddr, 
                                CONST UINT8* buf,
                                UINT32 bufLen);
extern BOOL (*OPENAT_close_i2c)(E_AMOPENAT_I2C_PORT port);
extern BOOL (*OPENAT_OpenSPI)( E_AMOPENAT_SPI_PORT port, T_AMOPENAT_SPI_PARAM *cfg);
extern UINT32 (*OPENAT_ReadSPI)(E_AMOPENAT_SPI_PORT port, CONST UINT8 * buf, UINT32 bufLen);
extern UINT32 (*OPENAT_WriteSPI)(E_AMOPENAT_SPI_PORT port, CONST UINT8 * buf, UINT32 bufLen, BOOLEAN type);
extern UINT32 (*OPENAT_RwSPI)(E_AMOPENAT_SPI_PORT port, CONST UINT8* txBuf, CONST UINT8* rxBuf,UINT32 bufLen);
extern BOOL (*OPENAT_CloseSPI)( E_AMOPENAT_SPI_PORT port);
extern BOOL (*OPENAT_InitADC)(
    E_AMOPENAT_ADC_CHANNEL channel  /* ADC编号 */,
    E_AMOPENAT_ADC_CFG_MODE mode);
extern BOOL (*OPENAT_ReadADC)(
    E_AMOPENAT_ADC_CHANNEL channel,  /* ADC编号 */
    kal_uint32*               adcValue,   /* adc值 */
    kal_uint32*               voltage    /* 电压值*/);
extern BOOL (*OPENAT_CloseADC)(
    E_AMOPENAT_ADC_CHANNEL channel  /* ADC编号 */);
extern BOOL (*OPENAT_create_task)(                                        /* 创建线程接口 */
                            HANDLE* handlePtr,
                            PTASK_MAIN pTaskEntry,              /* 线程主函数 */
                            PVOID pParameter,                   /* 作为参数传递给线程主函数 */
                            PVOID pStackAddr,                   /* 线程栈地址，当前不支持，请传入NULL */
                            UINT32 nStackSize,                  /* 线程栈大小 */
                            UINT8 nPriority,                    /* 线程优先级，该参数越大，线程优先级越低 */
                            UINT16 nCreationFlags,              /* 线程启动标记， 请参考E_AMOPENAT_OS_CREATION_FLAG */
                            UINT16 nTimeSlice,                  /* 暂时不支持，请传入0 */
                            PCHAR pTaskName                     /* 线程名称 */
                            );
extern VOID (*OPENAT_delete_task)(                                        /* 删除线程接口 */
                            HANDLE task
                            );
extern HANDLE (*OPENAT_current_task)(                                     /* 获取当前线程接口 */
                            VOID
                            );
extern BOOL (*OPENAT_suspend_task)(                                       /* 挂起线程接口 */
                            HANDLE hTask                        /* 线程句柄，create_task接口返回值 */
                            );
extern BOOL (*OPENAT_resume_task)(                                        /* 恢复线程接口 */
                            HANDLE hTask                        /* 线程句柄，create_task接口返回值 */
                            );
extern BOOL (*OPENAT_get_task_info)(                                      /* 获取当前线程创建信息接口 */
                            HANDLE hTask,                       /* 线程句柄，create_task接口返回值 */
                            T_AMOPENAT_TASK_INFO *pTaskInfo     /* 线程信息存储接口 */
                            );
extern BOOL (*OPENAT_sleep)(                                              /* 系统睡眠接口 */
                            UINT32 nMillisecondes               /* 睡眠时间 */
                            );
extern BOOL (*OPENAT_wait_message)(                                       /* 阻塞等待消息接口*/
                            HANDLE task,
                            int* msg_id,
                            void* * ppMessage,
                            UINT32 nTimeOut
                            );
extern BOOL (*OPENAT_send_message)(                                       /* 发送消息接口，添加到消息队列尾部 */
                            HANDLE   destTask,
                            int msg_id,
                            void* pMessage,                     /* 存储消息指针 */
                            int message_length
                            );
extern BOOL (*OPENAT_SendHighPriorityMessage)(                            /* 发送高优先级消息接口，添加到消息队列头部 */
                            HANDLE   destTask,
                            int msg_id,
                            void* pMessage,                     /* 存储消息指针 */
                            int message_length
                            );
extern BOOL (*OPENAT_available_message)(                                  /* 检测消息队列中是否有消息 */
                            HANDLE hTask                        /* 线程句柄，create_task接口返回值 */
                            );
extern HANDLE (*OPENAT_create_timer)(                                     /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,               /* 定时器到时处理函数 */
                            PVOID pParameter                    /* 作为参数传递给定时器到时处理函数 */
                            );
extern HANDLE (*OPENAT_create_timerTask)(                                 /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,               /* 定时器到时处理函数 */
                            PVOID pParameter                    /* 作为参数传递给定时器到时处理函数 */
                            );
extern HANDLE (*OPENAT_create_hir_timer)(                                 /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,               /* 定时器到时处理函数 */
                            PVOID pParameter                    /* 作为参数传递给定时器到时处理函数 */
                            );
extern BOOL (*OPENAT_start_timer)(                                        /* 启动定时器接口 */
                            HANDLE hTimer,                      /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes               /* 定时器时间 */
                            );
extern BOOL (*OPENAT_loop_start_timer)(                                   /* 启动循环定时器接口 */
                            HANDLE hTimer,                      /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes               /* 定时器时间 */
                            );
extern BOOL (*OPENAT_start_precise_timer)(                                /* 启动定时器接口 */
                            HANDLE hTimer,                      /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes               /* 定时器时间 */
                            );
extern BOOL (*OPENAT_stop_timer)(                                         /* 停止定时器接口 */
                            HANDLE hTimer                       /* 定时器句柄，create_timer接口返回值 */
                            );
extern UINT64 (*OPENAT_timer_remaining)(
                            HANDLE hTimer
                            );
extern void (*luaI_openlib)(void *L, const char *libname, const luaL_Reg *l, int nup);
extern int (*luaL_optinteger)(void *L, int nArg, int def);
extern lua_Number (*luaL_optnumber)(void *L, int nArg, lua_Number def);
extern char *(*luaL_optlstring)(void *L,                           /*获取参数，如果没有设置默认值*/
                        int nArg, const char *def, size_t *l);
extern void (*luaL_checktype)(void *L, int nArg, int t);
extern int (*luaL_checkinteger)(void *L, int nArg);
extern lua_Number (*luaL_checknumber)(void *L, int nArg);
extern char *(*luaL_checklstring)(void *L,int nArg, size_t *l);
extern void (*luaL_checkstack)(void *L, int space, const char *mes);
extern int (*luaL_checkoption)(void *L, int narg, const char *def,
                                 const char *const lst[]);
extern int (*luaL_error)(void *L, const char *fmt, ...);
extern int (*luaL_argerror)(void *L, int narg, const char *extramsg);
extern void *(*lua_newstate)(lua_Alloc f, void *ud);
extern void (*lua_close)(void *L);
extern void *(*lua_newthread)(void *L);
extern lua_CFunction (*lua_atpanic)(void *L, lua_CFunction panicf);
extern int (*lua_gettop)(void *L);
extern void (*lua_settop)(void *L, int idx);
extern void (*lua_pushvalue)(void *L, int idx);
extern void (*lua_remove)(void *L, int idx);
extern void (*lua_insert)(void *L, int idx);
extern void (*lua_replace)(void *L, int idx);
extern int (*lua_checkstack)(void *L, int sz);
extern void (*lua_xmove)(void *from, void *to, int n);
extern int (*lua_isnumber)(void *L, int idx);
extern int (*lua_isstring)(void *L, int idx);
extern int (*lua_iscfunction)(void *L, int idx);
extern int (*lua_isuserdata)(void *L, int idx);
extern int (*lua_type)(void *L, int idx);
extern char *(*lua_typename)(void *L, int tp);
extern int (*lua_equal)(void *L, int idx1, int idx2);
extern int (*lua_rawequal)(void *L, int idx1, int idx2);
extern int (*lua_lessthan)(void *L, int idx1, int idx2);
extern lua_Number (*lua_tonumber)(void *L, int idx);
extern lua_Integer (*lua_tointeger)(void *L, int idx);
extern int (*lua_toboolean)(void *L, int idx);
extern char *(*lua_tolstring)(void *L, int idx, size_t *len);
extern size_t (*lua_objlen)(void *L, int idx);
extern lua_CFunction (*lua_tocfunction)(void *L, int idx);
extern void *(*lua_touserdata)(void *L, int idx);
extern void *(*lua_tothread)(void *L, int idx);
extern void *(*lua_topointer)(void *L, int idx);
extern void (*lua_pushnil)(void *L);
extern void (*lua_pushnumber)(void *L, lua_Number n);
extern void (*lua_pushinteger)(void *L, lua_Integer n);
extern void (*lua_pushlstring)(void *L, const char *s, size_t l);
extern void (*lua_pushstring)(void *L, const char *s);
extern char *(*lua_pushfstring)(void *L, const char *fmt, ...);
extern void (*lua_pushcclosure)(void *L, lua_CFunction fn, int n);
extern void (*lua_pushboolean)(void *L, int b);
extern void (*lua_pushlightuserdata)(void *L, void *p);
extern int  (*lua_pushthread)(void *L);
extern void (*lua_gettable)(void *L, int idx);
extern void (*lua_getfield)(void *L, int idx, const char *k);
extern void (*lua_rawget)(void *L, int idx);
extern void (*lua_rawgeti)(void *L, int idx, int n);
extern void (*lua_createtable)(void *L, int narr, int nrec);
extern void *(*lua_newuserdata)(void *L, size_t sz);
extern int  (*lua_getmetatable)(void *L, int objindex);
extern void (*lua_getfenv)(void *L, int idx);
extern void (*lua_settable)(void *L, int idx);
extern void (*lua_setfield)(void *L, int idx, const char *k);
extern void (*lua_rawset)(void *L, int idx);
extern void (*lua_rawseti)(void *L, int idx, int n);
extern int  (*lua_setmetatable)(void *L, int objindex);
extern int  (*lua_setfenv)(void *L, int idx);
extern void (*lua_call)(void *L, int nargs, int nresults);
extern int  (*lua_pcall)(void *L, int nargs, int nresults, int errfunc);
extern int  (*lua_cpcall)(void *L, lua_CFunction func, void *ud);
extern int  (*lua_load)(void *L, lua_Reader reader, void *dt,
                                        const char *chunkname);
extern int (*lua_dump)(void *L, lua_Writer writer, void *data);
extern int (*lua_yield)(void *L, int nresults);
extern int (*lua_resume)(void *L, int narg);
extern int (*lua_status)(void *L);
extern int (*lua_gc)(void *L, int what, int data);
extern int (*lua_error)(void *L);
extern int (*lua_next)(void *L, int idx);
extern void (*lua_concat)(void *L, int n);
extern lua_Alloc (*lua_getallocf)(void *L, void **ud);
extern void (*lua_setallocf)(void *L, lua_Alloc f, void *ud);
extern void (*setfieldInt)(void *L, const char *key,int value);
extern void (*setfieldBool)(void *L,const char *key,int value);
extern void (*setfieldString)(void* L, const char* key,const char* str, const size_t len);
extern void (*lua_setlevel)(void *from, void *to);
extern int (*lua_getstack)(void *L, int level, lua_Debug *ar);
extern int (*lua_getinfo)(void *L, const char *what, lua_Debug *ar);
extern char *(*lua_getlocal)(void *L, const lua_Debug *ar, int n);
extern char *(*lua_setlocal)(void *L, const lua_Debug *ar, int n);
extern char *(*lua_getupvalue)(void *L, int funcindex, int n);
extern char *(*lua_setupvalue)(void *L, int funcindex, int n);
extern int (*lua_sethook)(void *L, lua_Hook func, int mask, int count);
extern lua_Hook (*lua_gethook)(void *L);
extern int (*lua_gethookmask)(void *L);
extern int (*lua_gethookcount)(void *L);
