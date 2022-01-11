#include "cs_types.h"
#include "stdarg.h"
#include "am_openat_drv.h"
#include "am_openat_system.h"
#include "std_type.h"
#include "lua_type.h"
void (*OPENAT_lua_print)(char * fmt,...) = (void*) 0xFFFFFFFF;
bool (*OPENAT_msg_to_lua)(UINT8 msg_id,BOOL result,INT32 num,CHAR* data,UINT32 dataLen) = (void*) 0xFFFFFFFF;
void (*stderr)(void) = (void*) 0xFFFFFFFF;
void (*stdin)(void) = (void*) 0xFFFFFFFF;
void (*stdout)(void) = (void*) 0xFFFFFFFF;
int (*__aeabi_idiv)(int a1, int a2) = (void*) 0xFFFFFFFF;
int (*__aeabi_idivmod)(int a1, int a2) = (void*) 0xFFFFFFFF;
int (*__divsi3)(signed int a1, int a2) = (void*) 0xFFFFFFFF;
size_t (*strlen)(const char *) = (void*) 0xFFFFFFFF;
char* (*strchr)(const char *,int) = (void*) 0xFFFFFFFF;
char* (*strcpy)(char *,const char *) = (void*) 0xFFFFFFFF;
char* (*strstr)(const char *, const char *) = (void*) 0xFFFFFFFF;
char* (*strncpy)(char *,const char *, size_t) = (void*) 0xFFFFFFFF;
char* (*strcat)(char *__restrict, const char *__restrict) = (void*) 0xFFFFFFFF;
long  (*strtol)(const char *, char **, int) = (void*) 0xFFFFFFFF;
int   (*strcmp)(const char *,const char *) = (void*) 0xFFFFFFFF;
int   (*sprintf)(char *, const char *, ...) = (void*) 0xFFFFFFFF;
int   (*strncmp)(const char *,const char *,size_t) = (void*) 0xFFFFFFFF;
int   (*strncasecmp)(const char *, const char *, size_t) = (void*) 0xFFFFFFFF;
int   (*sscanf)(const char * buf, const char * fmt, ...) = (void*) 0xFFFFFFFF;
int   (*snprintf)(char * buf, size_t len, const char *fmt, ...) = (void*) 0xFFFFFFFF;
int   (*fprintf)(void *err, const char *fmt, ...) = (void*) 0xFFFFFFFF;
int   (*vprintf)(const char *fmt, ...) = (void*) 0xFFFFFFFF;
int   (*vsnprintf)(char *buf, size_t size, const char *fmt, ...) = (void*) 0xFFFFFFFF;
int   (*printf)(const char *fmt, ...) = (void*) 0xFFFFFFFF;
void* (*memchr)(const void *, int, size_t) = (void*) 0xFFFFFFFF;
void* (*memmove)(void *, const void *, size_t) = (void*) 0xFFFFFFFF;
int   (*memcmp)(const void *, const void *, size_t) = (void*) 0xFFFFFFFF;
void* (*OPENAT_malloc)(size_t size) = (void*) 0xFFFFFFFF;
void* (*OPENAT_realloc)(PVOID ptr, UINT32 size) = (void*) 0xFFFFFFFF;
void  (*OPENAT_free)(void *ptr) = (void*) 0xFFFFFFFF;
void  (*OPENAT_assert)(                                           /* 断言接口 */
                            char condition,                     /* 条件 */
                            char *func,                         /* 函数名称 */
                            unsigned int line                   /* 行数 */
                            ) = (void*) 0xFFFFFFFF;
INT64 (*OPENAT_get_system_tick)(                                   /* 获取系统tick接口 */
                            VOID
                            ) = (void*) 0xFFFFFFFF;
double (*floor)(double) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_config_gpio)(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO编号 */
                            T_AMOPENAT_GPIO_CFG *cfg            /* 输出或输入 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_set_gpio)(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO编号 */
                            UINT8 value                         /* 0 or 1 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_read_gpio)(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO编号 */
                            UINT8* value                        /* 结果 0 or 1 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_close_gpio)(
                            E_AMOPENAT_GPIO_PORT port           /* GPIO编号 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_gpioPulse)(
                            E_AMOPENAT_GPIO_PORT port,
                            unsigned high_us,
                            unsigned low_us,
                            unsigned count,
                            unsigned idle
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_config_uart)(
                            E_AMOPENAT_UART_PORT port,          /* UART 编号 */
                            T_AMOPENAT_UART_PARAM *cfg          /* 初始化参数 */
                            ) = (void*) 0xFFFFFFFF;
UINT32 (*OPENAT_read_uart)(                                        /* 实际读取长度 */
                            E_AMOPENAT_UART_PORT port,          /* UART 编号 */
                            UINT8* buf,                         /* 存储数据地址 */
                            UINT32 bufLen,                      /* 存储空间长度 */
                            UINT32 timeoutMs                    /* 读取超时 ms */
                            ) = (void*) 0xFFFFFFFF;
UINT32 (*OPENAT_write_uart)(                                       /* 实际写入长度 */
                            E_AMOPENAT_UART_PORT port,          /* UART 编号 */
                            UINT8* buf,                         /* 写入数据地址 */
                            UINT32 bufLen                       /* 写入数据长度 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_close_uart)(
                            E_AMOPENAT_UART_PORT port           /* UART 编号 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_create_task)(                                        /* 创建线程接口 */
                            HANDLE* handlePtr,
                            PTASK_MAIN pTaskEntry,              /* 线程主函数 */
                            PVOID pParameter,                   /* 作为参数传递给线程主函数 */
                            PVOID pStackAddr,                   /* 线程栈地址，当前不支持，请传入NULL */
                            UINT32 nStackSize,                  /* 线程栈大小 */
                            UINT8 nPriority,                    /* 线程优先级，该参数越大，线程优先级越低 */
                            UINT16 nCreationFlags,              /* 线程启动标记， 请参考E_AMOPENAT_OS_CREATION_FLAG */
                            UINT16 nTimeSlice,                  /* 暂时不支持，请传入0 */
                            PCHAR pTaskName                     /* 线程名称 */
                            ) = (void*) 0xFFFFFFFF;
VOID (*OPENAT_delete_task)(                                        /* 删除线程接口 */
                            HANDLE task
                            ) = (void*) 0xFFFFFFFF;
HANDLE (*OPENAT_current_task)(                                     /* 获取当前线程接口 */
                            VOID
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_suspend_task)(                                       /* 挂起线程接口 */
                            HANDLE hTask                        /* 线程句柄，create_task接口返回值 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_resume_task)(                                        /* 恢复线程接口 */
                            HANDLE hTask                        /* 线程句柄，create_task接口返回值 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_get_task_info)(                                      /* 获取当前线程创建信息接口 */
                            HANDLE hTask,                       /* 线程句柄，create_task接口返回值 */
                            T_AMOPENAT_TASK_INFO *pTaskInfo     /* 线程信息存储接口 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_sleep)(                                              /* 系统睡眠接口 */
                            UINT32 nMillisecondes               /* 睡眠时间 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_wait_message)(                                       /* 阻塞等待消息接口*/
                            HANDLE task,
                            int* msg_id,
                            void* * ppMessage,
                            UINT32 nTimeOut
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_send_message)(                                       /* 发送消息接口，添加到消息队列尾部 */
                            HANDLE   destTask,
                            int msg_id,
                            void* pMessage,                     /* 存储消息指针 */
                            int message_length
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_SendHighPriorityMessage)(                            /* 发送高优先级消息接口，添加到消息队列头部 */
                            HANDLE   destTask,
                            int msg_id,
                            void* pMessage,                     /* 存储消息指针 */
                            int message_length
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_available_message)(                                  /* 检测消息队列中是否有消息 */
                            HANDLE hTask                        /* 线程句柄，create_task接口返回值 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_send_internal_message)(                              /* 发送消息接口，添加到消息队列尾部 */
                            int msg_id,
                            void* pMessage,                     /* 存储消息指针 */
                            int message_length
                            ) = (void*) 0xFFFFFFFF;
HANDLE (*OPENAT_create_timer)(                                     /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,               /* 定时器到时处理函数 */
                            PVOID pParameter                    /* 作为参数传递给定时器到时处理函数 */
                            ) = (void*) 0xFFFFFFFF;
HANDLE (*OPENAT_create_timerTask)(                                 /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,               /* 定时器到时处理函数 */
                            PVOID pParameter                    /* 作为参数传递给定时器到时处理函数 */
                            ) = (void*) 0xFFFFFFFF;
HANDLE (*OPENAT_create_hir_timer)(                                 /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,               /* 定时器到时处理函数 */
                            PVOID pParameter                    /* 作为参数传递给定时器到时处理函数 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_start_timer)(                                        /* 启动定时器接口 */
                            HANDLE hTimer,                      /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes               /* 定时器时间 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_loop_start_timer)(                                   /* 启动循环定时器接口 */
                            HANDLE hTimer,                      /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes               /* 定时器时间 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_start_precise_timer)(                                /* 启动定时器接口 */
                            HANDLE hTimer,                      /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes               /* 定时器时间 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_stop_timer)(                                         /* 停止定时器接口 */
                            HANDLE hTimer                       /* 定时器句柄，create_timer接口返回值 */
                            ) = (void*) 0xFFFFFFFF;
UINT64 (*OPENAT_timer_remaining)(
                            HANDLE hTimer
                            ) = (void*) 0xFFFFFFFF;
void (*luaI_openlib)(void *L, const char *libname, const luaL_Reg *l, int nup) = (void*) 0xFFFFFFFF;
int (*luaL_optinteger)(void *L, int nArg, int def) = (void*) 0xFFFFFFFF;
lua_Number (*luaL_optnumber)(void *L, int nArg, lua_Number def) = (void*) 0xFFFFFFFF;
char *(*luaL_optlstring)(void *L,                           /*获取参数，如果没有设置默认值*/
                        int nArg, const char *def, size_t *l) = (void*) 0xFFFFFFFF;
void (*luaL_checktype)(void *L, int nArg, int t) = (void*) 0xFFFFFFFF;
int (*luaL_checkinteger)(void *L, int nArg) = (void*) 0xFFFFFFFF;
lua_Number (*luaL_checknumber)(void *L, int nArg) = (void*) 0xFFFFFFFF;
char *(*luaL_checklstring)(void *L,int nArg, size_t *l) = (void*) 0xFFFFFFFF;
void (*luaL_checkstack)(void *L, int space, const char *mes) = (void*) 0xFFFFFFFF;
int (*luaL_checkoption)(void *L, int narg, const char *def,
                                 const char *const lst[]) = (void*) 0xFFFFFFFF;
int (*luaL_error)(void *L, const char *fmt, ...) = (void*) 0xFFFFFFFF;
int (*luaL_argerror)(void *L, int narg, const char *extramsg) = (void*) 0xFFFFFFFF;
void *(*lua_newstate)(lua_Alloc f, void *ud) = (void*) 0xFFFFFFFF;
void (*lua_close)(void *L) = (void*) 0xFFFFFFFF;
void *(*lua_newthread)(void *L) = (void*) 0xFFFFFFFF;
lua_CFunction (*lua_atpanic)(void *L, lua_CFunction panicf) = (void*) 0xFFFFFFFF;
int (*lua_gettop)(void *L) = (void*) 0xFFFFFFFF;
void (*lua_settop)(void *L, int idx) = (void*) 0xFFFFFFFF;
void (*lua_pushvalue)(void *L, int idx) = (void*) 0xFFFFFFFF;
void (*lua_remove)(void *L, int idx) = (void*) 0xFFFFFFFF;
void (*lua_insert)(void *L, int idx) = (void*) 0xFFFFFFFF;
void (*lua_replace)(void *L, int idx) = (void*) 0xFFFFFFFF;
int (*lua_checkstack)(void *L, int sz) = (void*) 0xFFFFFFFF;
void (*lua_xmove)(void *from, void *to, int n) = (void*) 0xFFFFFFFF;
int (*lua_isnumber)(void *L, int idx) = (void*) 0xFFFFFFFF;
int (*lua_isstring)(void *L, int idx) = (void*) 0xFFFFFFFF;
int (*lua_iscfunction)(void *L, int idx) = (void*) 0xFFFFFFFF;
int (*lua_isuserdata)(void *L, int idx) = (void*) 0xFFFFFFFF;
int (*lua_type)(void *L, int idx) = (void*) 0xFFFFFFFF;
char *(*lua_typename)(void *L, int tp) = (void*) 0xFFFFFFFF;
int (*lua_equal)(void *L, int idx1, int idx2) = (void*) 0xFFFFFFFF;
int (*lua_rawequal)(void *L, int idx1, int idx2) = (void*) 0xFFFFFFFF;
int (*lua_lessthan)(void *L, int idx1, int idx2) = (void*) 0xFFFFFFFF;
lua_Number (*lua_tonumber)(void *L, int idx) = (void*) 0xFFFFFFFF;
lua_Integer (*lua_tointeger)(void *L, int idx) = (void*) 0xFFFFFFFF;
int (*lua_toboolean)(void *L, int idx) = (void*) 0xFFFFFFFF;
char *(*lua_tolstring)(void *L, int idx, size_t *len) = (void*) 0xFFFFFFFF;
size_t (*lua_objlen)(void *L, int idx) = (void*) 0xFFFFFFFF;
lua_CFunction (*lua_tocfunction)(void *L, int idx) = (void*) 0xFFFFFFFF;
void *(*lua_touserdata)(void *L, int idx) = (void*) 0xFFFFFFFF;
void *(*lua_tothread)(void *L, int idx) = (void*) 0xFFFFFFFF;
void *(*lua_topointer)(void *L, int idx) = (void*) 0xFFFFFFFF;
void (*lua_pushnil)(void *L) = (void*) 0xFFFFFFFF;
void (*lua_pushnumber)(void *L, lua_Number n) = (void*) 0xFFFFFFFF;
void (*lua_pushinteger)(void *L, lua_Integer n) = (void*) 0xFFFFFFFF;
void (*lua_pushlstring)(void *L, const char *s, size_t l) = (void*) 0xFFFFFFFF;
void (*lua_pushstring)(void *L, const char *s) = (void*) 0xFFFFFFFF;
char *(*lua_pushfstring)(void *L, const char *fmt, ...) = (void*) 0xFFFFFFFF;
void (*lua_pushcclosure)(void *L, lua_CFunction fn, int n) = (void*) 0xFFFFFFFF;
void (*lua_pushboolean)(void *L, int b) = (void*) 0xFFFFFFFF;
void (*lua_pushlightuserdata)(void *L, void *p) = (void*) 0xFFFFFFFF;
int  (*lua_pushthread)(void *L) = (void*) 0xFFFFFFFF;
void (*lua_gettable)(void *L, int idx) = (void*) 0xFFFFFFFF;
void (*lua_getfield)(void *L, int idx, const char *k) = (void*) 0xFFFFFFFF;
void (*lua_rawget)(void *L, int idx) = (void*) 0xFFFFFFFF;
void (*lua_rawgeti)(void *L, int idx, int n) = (void*) 0xFFFFFFFF;
void (*lua_createtable)(void *L, int narr, int nrec) = (void*) 0xFFFFFFFF;
void *(*lua_newuserdata)(void *L, size_t sz) = (void*) 0xFFFFFFFF;
int  (*lua_getmetatable)(void *L, int objindex) = (void*) 0xFFFFFFFF;
void (*lua_getfenv)(void *L, int idx) = (void*) 0xFFFFFFFF;
void (*lua_settable)(void *L, int idx) = (void*) 0xFFFFFFFF;
void (*lua_setfield)(void *L, int idx, const char *k) = (void*) 0xFFFFFFFF;
void (*lua_rawset)(void *L, int idx) = (void*) 0xFFFFFFFF;
void (*lua_rawseti)(void *L, int idx, int n) = (void*) 0xFFFFFFFF;
int  (*lua_setmetatable)(void *L, int objindex) = (void*) 0xFFFFFFFF;
int  (*lua_setfenv)(void *L, int idx) = (void*) 0xFFFFFFFF;
void (*lua_call)(void *L, int nargs, int nresults) = (void*) 0xFFFFFFFF;
int  (*lua_pcall)(void *L, int nargs, int nresults, int errfunc) = (void*) 0xFFFFFFFF;
int  (*lua_cpcall)(void *L, lua_CFunction func, void *ud) = (void*) 0xFFFFFFFF;
int  (*lua_load)(void *L, lua_Reader reader, void *dt,
                                        const char *chunkname) = (void*) 0xFFFFFFFF;
int (*lua_dump)(void *L, lua_Writer writer, void *data) = (void*) 0xFFFFFFFF;
int (*lua_yield)(void *L, int nresults) = (void*) 0xFFFFFFFF;
int (*lua_resume)(void *L, int narg) = (void*) 0xFFFFFFFF;
int (*lua_status)(void *L) = (void*) 0xFFFFFFFF;
int (*lua_gc)(void *L, int what, int data) = (void*) 0xFFFFFFFF;
int (*lua_error)(void *L) = (void*) 0xFFFFFFFF;
int (*lua_next)(void *L, int idx) = (void*) 0xFFFFFFFF;
void (*lua_concat)(void *L, int n) = (void*) 0xFFFFFFFF;
lua_Alloc (*lua_getallocf)(void *L, void **ud) = (void*) 0xFFFFFFFF;
void (*lua_setallocf)(void *L, lua_Alloc f, void *ud) = (void*) 0xFFFFFFFF;
void (*setfieldInt)(void *L, const char *key,int value) = (void*) 0xFFFFFFFF;
void (*setfieldBool)(void *L,const char *key,int value) = (void*) 0xFFFFFFFF;
void (*setfieldString)(void* L, const char* key,const char* str, const size_t len) = (void*) 0xFFFFFFFF;
void (*lua_setlevel)(void *from, void *to) = (void*) 0xFFFFFFFF;
int (*lua_getstack)(void *L, int level, lua_Debug *ar) = (void*) 0xFFFFFFFF;
int (*lua_getinfo)(void *L, const char *what, lua_Debug *ar) = (void*) 0xFFFFFFFF;
char *(*lua_getlocal)(void *L, const lua_Debug *ar, int n) = (void*) 0xFFFFFFFF;
char *(*lua_setlocal)(void *L, const lua_Debug *ar, int n) = (void*) 0xFFFFFFFF;
char *(*lua_getupvalue)(void *L, int funcindex, int n) = (void*) 0xFFFFFFFF;
char *(*lua_setupvalue)(void *L, int funcindex, int n) = (void*) 0xFFFFFFFF;
int (*lua_sethook)(void *L, lua_Hook func, int mask, int count) = (void*) 0xFFFFFFFF;
lua_Hook (*lua_gethook)(void *L) = (void*) 0xFFFFFFFF;
int (*lua_gethookmask)(void *L) = (void*) 0xFFFFFFFF;
int (*lua_gethookcount)(void *L) = (void*) 0xFFFFFFFF;
