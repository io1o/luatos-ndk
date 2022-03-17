#include "cs_types.h"
#include "stdarg.h"
#include "am_openat_drv.h"
#include "am_openat_system.h"
#include "std_type.h"
#include "lua_type.h"
#include "ndk_math.h"
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
extern double (*atan)(double);
extern double (*cos)(double);
extern double (*sin)(double);
extern double (*tan)(double);
extern double (*tanh)(double);
extern double (*frexp)(double, int *);
extern double (*modf)(double, double *);
extern double (*ceil)(double);
extern double (*fabs)(double);
extern double (*floor)(double);
extern double (*acos)(double);
extern double (*asin)(double);
extern double (*atan2)(double, double);
extern double (*cosh)(double);
extern double (*sinh)(double);
extern double (*exp)(double);
extern double (*ldexp)(double, int);
extern double (*log)(double);
extern double (*log10)(double);
extern double (*pow)(double, double);
extern double (*sqrt)(double);
extern double (*fmod)(double, double);
extern int (*finite)(double);
extern int (*finitef)(float);
extern int (*finitel)(long double);
extern int (*isinff)(float);
extern int (*isnanf)(float);
extern int (*isinfl)(long double);
extern int (*isnanl)(long double);
extern int (*isinf)(double);
extern int (*isnan)(double);
extern int (*__isinff)(float x);
extern int (*__isinfd)(double x);
extern int (*__isnanf)(float x);
extern int (*__isnand)(double x);
extern int (*__fpclassifyf)(float x);
extern int (*__fpclassifyd)(double x);
extern int (*__signbitf)(float x);
extern int (*__signbitd)(double x);
extern double (*infinity)(void);
extern double (*nan)(const char *);
extern double (*copysign)(double, double);
extern double (*logb)(double);
extern int (*ilogb)(double);
extern double (*asinh)(double);
extern double (*cbrt)(double);
extern double (*nextafter)(double, double);
extern double (*rint)(double);
extern double (*scalbn)(double, int);
extern double (*exp2)(double);
extern double (*scalbln)(double, long int);
extern double (*tgamma)(double);
extern double (*nearbyint)(double);
extern int (*lrint)(double);
extern int (*llrint)(double);
extern double (*round)(double);
extern int (*lround)(double);
extern int (*llround)(double);
extern double (*trunc)(double);
extern double (*remquo)(double, double, int *);
extern double (*fdim)(double, double);
extern double (*fmax)(double, double);
extern double (*fmin)(double, double);
extern double (*fma)(double, double, double);
extern double (*log1p)(double);
extern double (*expm1)(double);
extern double (*acosh)(double);
extern double (*atanh)(double);
extern double (*remainder)(double, double);
extern double (*gamma)(double);
extern double (*lgamma)(double);
extern double (*erf)(double);
extern double (*erfc)(double);
extern double (*log2)(double);
extern double (*hypot)(double, double);
extern float (*atanf)(float);
extern float (*cosf)(float);
extern float (*sinf)(float);
extern float (*tanf)(float);
extern float (*tanhf)(float);
extern float (*frexpf)(float, int *);
extern float (*modff)(float, float *);
extern float (*ceilf)(float);
extern float (*fabsf)(float);
extern float (*floorf)(float);
extern float (*acosf)(float);
extern float (*asinf)(float);
extern float (*atan2f)(float, float);
extern float (*coshf)(float);
extern float (*sinhf)(float);
extern float (*expf)(float);
extern float (*ldexpf)(float, int);
extern float (*logf)(float);
extern float (*log10f)(float);
extern float (*powf)(float, float);
extern float (*sqrtf)(float);
extern float (*fmodf)(float, float);
extern float (*exp2f)(float);
extern float (*scalblnf)(float, long int);
extern float (*tgammaf)(float);
extern float (*nearbyintf)(float);
extern int (*lrintf)(float);
extern int (*llrintf)(float);
extern float (*roundf)(float);
extern int (*lroundf)(float);
extern int (*llroundf)(float);
extern float (*truncf)(float);
extern float (*remquof)(float, float, int *);
extern float (*fdimf)(float, float);
extern float (*fmaxf)(float, float);
extern float (*fminf)(float, float);
extern float (*fmaf)(float, float, float);
extern float (*infinityf)(void);
extern float (*nanf)(const char *);
extern float (*copysignf)(float, float);
extern float (*logbf)(float);
extern int (*ilogbf)(float);
extern float (*asinhf)(float);
extern float (*cbrtf)(float);
extern float (*nextafterf)(float, float);
extern float (*rintf)(float);
extern float (*scalbnf)(float, int);
extern float (*log1pf)(float);
extern float (*expm1f)(float);
extern float (*acoshf)(float);
extern float (*atanhf)(float);
extern float (*remainderf)(float, float);
extern float (*gammaf)(float);
extern float (*lgammaf)(float);
extern float (*erff)(float);
extern float (*erfcf)(float);
extern float (*log2f)(float);
extern float (*hypotf)(float, float);
extern double (*atanl)(long double);
extern double (*cosl)(long double);
extern double (*sinl)(long double);
extern double (*tanl)(long double);
extern double (*tanhl)(long double);
extern double (*frexpl)(long double, int *);
extern double (*modfl)(long double, long double *);
extern double (*ceill)(long double);
extern double (*fabsl)(long double);
extern double (*floorl)(long double);
extern double (*log1pl)(long double);
extern double (*expm1l)(long double);
extern double (*acosl)(long double);
extern double (*asinl)(long double);
extern double (*atan2l)(long double, long double);
extern double (*coshl)(long double);
extern double (*sinhl)(long double);
extern double (*expl)(long double);
extern double (*ldexpl)(long double, int);
extern double (*logl)(long double);
extern double (*log10l)(long double);
extern double (*powl)(long double, long double);
extern double (*sqrtl)(long double);
extern double (*fmodl)(long double, long double);
extern double (*hypotl)(long double, long double);
extern double (*copysignl)(long double, long double);
extern double (*nanl)(const char *);
extern int (*ilogbl)(long double);
extern double (*asinhl)(long double);
extern double (*cbrtl)(long double);
extern double (*nextafterl)(long double, long double);
extern float (*nexttowardf)(float, long double);
extern double (*nexttoward)(double, long double);
extern double (*nexttowardl)(long double, long double);
extern double (*logbl)(long double);
extern double (*log2l)(long double);
extern double (*rintl)(long double);
extern double (*scalbnl)(long double, int);
extern double (*exp2l)(long double);
extern double (*scalblnl)(long double, long);
extern double (*tgammal)(long double);
extern double (*nearbyintl)(long double);
extern int (*lrintl)(long double);
extern int (*llrintl)(long double);
extern double (*roundl)(long double);
extern long (*lroundl)(long double);
extern int (*llroundl)(long double);
extern double (*truncl)(long double);
extern double (*remquol)(long double, long double, int *);
extern double (*fdiml)(long double, long double);
extern double (*fmaxl)(long double, long double);
extern double (*fminl)(long double, long double);
extern double (*fmal)(long double, long double, long double);
extern double (*acoshl)(long double);
extern double (*atanhl)(long double);
extern double (*remainderl)(long double, long double);
extern double (*lgammal)(long double);
extern double (*erfl)(long double);
extern double (*erfcl)(long double);
extern double (*drem)(double, double);
extern float (*dremf)(float, float);
extern float (*dreml)(long double, long double);
extern double (*gamma_r)(double, int *);
extern double (*lgamma_r)(double, int *);
extern float (*gammaf_r)(float, int *);
extern float (*lgammaf_r)(float, int *);
extern double (*y0)(double);
extern double (*y1)(double);
extern double (*yn)(int, double);
extern double (*j0)(double);
extern double (*j1)(double);
extern double (*jn)(int, double);
extern float (*y0f)(float);
extern float (*y1f)(float);
extern float (*ynf)(int, float);
extern float (*j0f)(float);
extern float (*j1f)(float);
extern float (*jnf)(int, float);
extern void (*sincos)(double, double *, double *);
extern void (*sincosf)(float, float *, float *);
extern void (*sincosl)(long double, long double *, long double *);
extern double (*exp10)(double);
extern double (*pow10)(double);
extern float (*exp10f)(float);
extern float (*pow10f)(float);
extern float (*exp10l)(float);
extern float (*pow10l)(float);
extern int (*signgam)(void);
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
