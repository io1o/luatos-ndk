#include "cs_types.h"
#include "stdarg.h"
#include "am_openat_drv.h"
#include "am_openat_system.h"
#include "std_type.h"
#include "lua_type.h"
#include "ndk_math.h"



void OPENAT_lua_print(char * fmt,...);
bool OPENAT_msg_to_lua(UINT8 msg_id,BOOL result,INT32 num,CHAR* data,UINT32 dataLen);

/******************************** 标准库接口 ********************************/
void stderr(void);
void stdin(void);
void stdout(void);
size_t strlen (const char *);
char*  strchr(const char *,int);
char*  strcpy(char *,const char *);
char*  strstr (const char *, const char *);
char*  strncpy(char *,const char *, size_t);
char*  strcat (char *__restrict, const char *__restrict);
long   strtol(const char *, char **, int);
int    strcmp(const char *,const char *);
int    sprintf(char *, const char *, ...);
int    strncmp(const char *,const char *,size_t);
int    strncasecmp(const char *, const char *, size_t);

int    sscanf(const char * buf, const char * fmt, ...);
int    snprintf(char * buf, size_t len, const char *fmt, ...);
int    fprintf(void *err, const char *fmt, ...);
int    vsnprintf(char *buf, size_t size, const char *fmt, ...);
int    printf(const char *fmt, ...);

void*  memchr (const void *, int, size_t);
void*  memmove (void *, const void *, size_t);
int    memcmp (const void *, const void *, size_t);
void*  OPENAT_malloc(size_t size);
void*  OPENAT_realloc(PVOID ptr, UINT32 size);
void   OPENAT_free(void *ptr);
void   OPENAT_assert(                                           /* 断言接口 */
                            char condition,                     /* 条件 */
                            char *func,                         /* 函数名称 */
                            unsigned int line                   /* 行数 */
                            );
INT64 OPENAT_get_system_tick(                                   /* 获取系统tick接口 */
                            VOID
                            );

/*math操作相关接口*/
/* Reentrant ANSI C functions.	*/
double atan (double);
double cos (double);
double sin (double);
double tan (double);
double tanh (double);
double frexp (double, int *);
double modf (double, double *);
double ceil (double);
double fabs (double);
double floor (double);

/* Non reentrant ANSI C functions.	*/
double acos (double);
double asin (double);
double atan2 (double, double);
double cosh (double);
double sinh (double);
double exp (double);
double ldexp (double, int);
double log (double);
double log10 (double);
double pow (double, double);
double sqrt (double);
double fmod (double, double);


int finite (double);
int finitef (float);
int finitel (long double);
int isinff (float);
int isnanf (float);

int isinfl (long double);
int isnanl (long double);
int isinf (double);
int isnan (double);

int __isinff (float x);
int __isinfd (double x);
int __isnanf (float x);
int __isnand (double x);
int __fpclassifyf (float x);
int __fpclassifyd (double x);
int __signbitf (float x);
int __signbitd (double x);

/* Non ANSI double precision functions.  */

double infinity (void);
double nan (const char *);
double copysign (double, double);
double logb (double);
int ilogb (double);

double asinh (double);
double cbrt (double);
double nextafter (double, double);
double rint (double);
double scalbn (double, int);

double exp2 (double);
double scalbln (double, long int);
double tgamma (double);
double nearbyint (double);
long int lrint (double);
long long int llrint (double);
double round (double);
long int lround (double);
long long int llround (double);
double trunc (double);
double remquo (double, double, int *);
double fdim (double, double);
double fmax (double, double);
double fmin (double, double);
double fma (double, double, double);


double log1p (double);
double expm1 (double);



double acosh (double);
double atanh (double);
double remainder (double, double);
double gamma (double);
double lgamma (double);
double erf (double);
double erfc (double);
double log2 (double);


double hypot (double, double);

/* Single precision versions of ANSI functions.  */

float atanf (float);
float cosf (float);
float sinf (float);
float tanf (float);
float tanhf (float);
float frexpf (float, int *);
float modff (float, float *);
float ceilf (float);
float fabsf (float);
float floorf (float);

float acosf (float);
float asinf (float);
float atan2f (float, float);
float coshf (float);
float sinhf (float);
float expf (float);
float ldexpf (float, int);
float logf (float);
float log10f (float);
float powf (float, float);
float sqrtf (float);
float fmodf (float, float);

/* Other single precision functions.  */

float exp2f (float);
float scalblnf (float, long int);
float tgammaf (float);
float nearbyintf (float);
long int lrintf (float);
long long int llrintf (float);
float roundf (float);
long int lroundf (float);
long long int llroundf (float);
float truncf (float);
float remquof (float, float, int *);
float fdimf (float, float);
float fmaxf (float, float);
float fminf (float, float);
float fmaf (float, float, float);

float infinityf (void);
float nanf (const char *);
float copysignf (float, float);
float logbf (float);
int ilogbf (float);

float asinhf (float);
float cbrtf (float);
float nextafterf (float, float);
float rintf (float);
float scalbnf (float, int);
float log1pf (float);
float expm1f (float);


float acoshf (float);
float atanhf (float);
float remainderf (float, float);
float gammaf (float);
float lgammaf (float);
float erff (float);
float erfcf (float);
float log2f (float);
float hypotf (float, float);

long double atanl (long double);
long double cosl (long double);
long double sinl (long double);
long double tanl (long double);
long double tanhl (long double);
long double frexpl (long double, int *);
long double modfl (long double, long double *);
long double ceill (long double);
long double fabsl (long double);
long double floorl (long double);
long double log1pl (long double);
long double expm1l (long double);

long double acosl (long double);
long double asinl (long double);
long double atan2l (long double, long double);
long double coshl (long double);
long double sinhl (long double);
long double expl (long double);
long double ldexpl (long double, int);
long double logl (long double);
long double log10l (long double);
long double powl (long double, long double);
long double sqrtl (long double);
long double fmodl (long double, long double);
long double hypotl (long double, long double);

long double copysignl (long double, long double);
long double nanl (const char *);
int ilogbl (long double);
long double asinhl (long double);
long double cbrtl (long double);
long double nextafterl (long double, long double);
float nexttowardf (float, long double);
double nexttoward (double, long double);
long double nexttowardl (long double, long double);
long double logbl (long double);
long double log2l (long double);
long double rintl (long double);
long double scalbnl (long double, int);
long double exp2l (long double);
long double scalblnl (long double, long);
long double tgammal (long double);
long double nearbyintl (long double);
long int lrintl (long double);
long long int llrintl (long double);
long double roundl (long double);
long lroundl (long double);
long long int llroundl (long double);
long double truncl (long double);
long double remquol (long double, long double, int *);
long double fdiml (long double, long double);
long double fmaxl (long double, long double);
long double fminl (long double, long double);
long double fmal (long double, long double, long double);

long double acoshl (long double);
long double atanhl (long double);
long double remainderl (long double, long double);
long double lgammal (long double);
long double erfl (long double);
long double erfcl (long double);

double drem (double, double);
float dremf (float, float);
float dreml (long double, long double);

double gamma_r (double, int *);
double lgamma_r (double, int *);
float gammaf_r (float, int *);
float lgammaf_r (float, int *);


double y0 (double);
double y1 (double);
double yn (int, double);
double j0 (double);
double j1 (double);
double jn (int, double);


float y0f (float);
float y1f (float);
float ynf (int, float);
float j0f (float);
float j1f (float);
float jnf (int, float);


void sincos (double, double *, double *);
void sincosf (float, float *, float *);
void sincosl (long double, long double *, long double *);
double exp10 (double);


double pow10 (double);
float exp10f (float);
float pow10f (float);
float exp10l (float);
float pow10l (float);


/* The gamma functions use a global variable, signgam.	*/
int signgam (void);


/******************************** GPIO操作接口 ********************************/
BOOL OPENAT_config_gpio(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO编号 */
                            T_AMOPENAT_GPIO_CFG *cfg            /* 输出或输入 */
                            );

BOOL OPENAT_set_gpio(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO编号 */
                            UINT8 value                         /* 0 or 1 */
                            );

BOOL OPENAT_read_gpio(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO编号 */
                            UINT8* value                        /* 结果 0 or 1 */
                            );

BOOL OPENAT_close_gpio(
                            E_AMOPENAT_GPIO_PORT port           /* GPIO编号 */
                            );


BOOL OPENAT_gpioPulse(
                            E_AMOPENAT_GPIO_PORT port,
                            unsigned high_us,
                            unsigned low_us,
                            unsigned count,
                            unsigned idle
                            );

/******************************** UART操作接口 ********************************/
BOOL OPENAT_config_uart(
                            E_AMOPENAT_UART_PORT port,          /* UART 编号 */
                            T_AMOPENAT_UART_PARAM *cfg          /* 初始化参数 */
                            );


UINT32 OPENAT_read_uart(                                        /* 实际读取长度 */
                            E_AMOPENAT_UART_PORT port,          /* UART 编号 */
                            UINT8* buf,                         /* 存储数据地址 */
                            UINT32 bufLen,                      /* 存储空间长度 */
                            UINT32 timeoutMs                    /* 读取超时 ms */
                            );


UINT32 OPENAT_write_uart(                                       /* 实际写入长度 */
                            E_AMOPENAT_UART_PORT port,          /* UART 编号 */
                            UINT8* buf,                         /* 写入数据地址 */
                            UINT32 bufLen                       /* 写入数据长度 */
                            );

BOOL OPENAT_close_uart(
                            E_AMOPENAT_UART_PORT port           /* UART 编号 */
                            );

/*I2C*/
BOOL OPENAT_open_i2c(E_AMOPENAT_I2C_PORT port, 
                              T_AMOPENAT_I2C_PARAM *cfg);

UINT32 OPENAT_read_i2c(E_AMOPENAT_I2C_PORT port, 
                                UINT8 slaveAddr, 
                                CONST UINT16 *pRegAddr, 
                                UINT8* buf,
                                UINT32 bufLen);

UINT32 OPENAT_write_i2c(E_AMOPENAT_I2C_PORT port, 
                                UINT8 slaveAddr, 
                                CONST UINT16 *pRegAddr, 
                                CONST UINT8* buf,
                                UINT32 bufLen);
BOOL OPENAT_close_i2c(E_AMOPENAT_I2C_PORT port);


/*SPI*/
BOOL OPENAT_OpenSPI( E_AMOPENAT_SPI_PORT port, T_AMOPENAT_SPI_PARAM *cfg);
UINT32 OPENAT_ReadSPI(E_AMOPENAT_SPI_PORT port, CONST UINT8 * buf, UINT32 bufLen);
UINT32 OPENAT_WriteSPI(E_AMOPENAT_SPI_PORT port, CONST UINT8 * buf, UINT32 bufLen, BOOLEAN type);
UINT32 OPENAT_RwSPI(E_AMOPENAT_SPI_PORT port, CONST UINT8* txBuf, CONST UINT8* rxBuf,UINT32 bufLen);
BOOL OPENAT_CloseSPI( E_AMOPENAT_SPI_PORT port);

/*ADC*/
BOOL OPENAT_InitADC(
    E_AMOPENAT_ADC_CHANNEL channel  /* ADC编号 */,
    E_AMOPENAT_ADC_CFG_MODE mode);

BOOL OPENAT_ReadADC(
    E_AMOPENAT_ADC_CHANNEL channel,  /* ADC编号 */
    kal_uint32*               adcValue,   /* adc值 */
    kal_uint32*               voltage    /* 电压值*/);
    
BOOL OPENAT_CloseADC(
    E_AMOPENAT_ADC_CHANNEL channel  /* ADC编号 */);

/******************************** 任务接口 ********************************/
BOOL OPENAT_create_task(                                        /* 创建线程接口 */
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

VOID OPENAT_delete_task(                                        /* 删除线程接口 */
                            HANDLE task
                            );

HANDLE OPENAT_current_task(                                     /* 获取当前线程接口 */
                            VOID
                            );

BOOL OPENAT_suspend_task(                                       /* 挂起线程接口 */
                            HANDLE hTask                        /* 线程句柄，create_task接口返回值 */
                            );

BOOL OPENAT_resume_task(                                        /* 恢复线程接口 */
                            HANDLE hTask                        /* 线程句柄，create_task接口返回值 */
                            );

BOOL OPENAT_get_task_info(                                      /* 获取当前线程创建信息接口 */
                            HANDLE hTask,                       /* 线程句柄，create_task接口返回值 */
                            T_AMOPENAT_TASK_INFO *pTaskInfo     /* 线程信息存储接口 */
                            );

BOOL OPENAT_sleep(                                              /* 系统睡眠接口 */
                            UINT32 nMillisecondes               /* 睡眠时间 */
                            );


/******************************** 消息接口 ********************************/
BOOL OPENAT_wait_message(                                       /* 阻塞等待消息接口*/
                            HANDLE task,
                            int* msg_id,
                            void* * ppMessage,
                            UINT32 nTimeOut
                            );


BOOL OPENAT_send_message(                                       /* 发送消息接口，添加到消息队列尾部 */
                            HANDLE   destTask,
                            int msg_id,
                            void* pMessage,                     /* 存储消息指针 */
                            int message_length
                            );

BOOL OPENAT_SendHighPriorityMessage(                            /* 发送高优先级消息接口，添加到消息队列头部 */
                            HANDLE   destTask,
                            int msg_id,
                            void* pMessage,                     /* 存储消息指针 */
                            int message_length
                            );

BOOL OPENAT_available_message(                                  /* 检测消息队列中是否有消息 */
                            HANDLE hTask                        /* 线程句柄，create_task接口返回值 */
                            );


/****************************** 时间&定时器接口 ******************************/
HANDLE OPENAT_create_timer(                                     /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,               /* 定时器到时处理函数 */
                            PVOID pParameter                    /* 作为参数传递给定时器到时处理函数 */
                            );

HANDLE OPENAT_create_timerTask(                                 /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,               /* 定时器到时处理函数 */
                            PVOID pParameter                    /* 作为参数传递给定时器到时处理函数 */
                            );

HANDLE OPENAT_create_hir_timer(                                 /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,               /* 定时器到时处理函数 */
                            PVOID pParameter                    /* 作为参数传递给定时器到时处理函数 */
                            );


BOOL OPENAT_start_timer(                                        /* 启动定时器接口 */
                            HANDLE hTimer,                      /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes               /* 定时器时间 */
                            );

BOOL OPENAT_loop_start_timer(                                   /* 启动循环定时器接口 */
                            HANDLE hTimer,                      /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes               /* 定时器时间 */
                            );

BOOL OPENAT_start_precise_timer(                                /* 启动定时器接口 */
                            HANDLE hTimer,                      /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes               /* 定时器时间 */
                            );

BOOL OPENAT_stop_timer(                                         /* 停止定时器接口 */
                            HANDLE hTimer                       /* 定时器句柄，create_timer接口返回值 */
                            );

UINT64 OPENAT_timer_remaining(
                            HANDLE hTimer
                            );

/****************************** lua虚拟机操作接口 ******************************/
void luaI_openlib (void *L, const char *libname, const luaL_Reg *l, int nup);

int luaL_optinteger (void *L, int nArg, int def);               /*获取参数，如果没有设置默认值*/
lua_Number luaL_optnumber (void *L, int nArg, lua_Number def);              /*获取参数，如果没有设置默认值*/
const char *luaL_optlstring (void *L,                           /*获取参数，如果没有设置默认值*/
                        int nArg, const char *def, size_t *l);

void luaL_checktype (void *L, int nArg, int t);                 /*获取参数类型*/
int luaL_checkinteger (void *L, int nArg);                      /*设置表key为bool类型的值*/
lua_Number luaL_checknumber (void *L, int nArg);                      /*获取参数*/
const char *luaL_checklstring (void *L,int nArg, size_t *l);    /*获取参数*/

void luaL_checkstack (void *L, int space, const char *mes);
int luaL_checkoption (void *L, int narg, const char *def,
                                 const char *const lst[]);

int luaL_error (void *L, const char *fmt, ...);
int luaL_argerror (void *L, int narg, const char *extramsg);

/* state manipulation*/
void *lua_newstate(lua_Alloc f, void *ud);
void  lua_close(void *L);
void *lua_newthread(void *L);

lua_CFunction lua_atpanic(void *L, lua_CFunction panicf);


/* basic stack manipulation*/
int lua_gettop(void *L);
void lua_settop(void *L, int idx);
void lua_pushvalue(void *L, int idx);
void lua_remove(void *L, int idx);
void lua_insert(void *L, int idx);
void lua_replace(void *L, int idx);
int lua_checkstack(void *L, int sz);

void  lua_xmove(void *from, void *to, int n);

/* access functions   stack -> C*/
int lua_isnumber(void *L, int idx);
int lua_isstring(void *L, int idx);
int lua_iscfunction(void *L, int idx);
int lua_isuserdata(void *L, int idx);
int lua_type(void *L, int idx);
const char *lua_typename(void *L, int tp);

int lua_equal(void *L, int idx1, int idx2);
int lua_rawequal(void *L, int idx1, int idx2);
int lua_lessthan(void *L, int idx1, int idx2);

lua_Number lua_tonumber(void *L, int idx);
lua_Integer lua_tointeger(void *L, int idx);
int lua_toboolean(void *L, int idx);
const char *lua_tolstring(void *L, int idx, size_t *len);
size_t lua_objlen(void *L, int idx);
lua_CFunction lua_tocfunction(void *L, int idx);
void *lua_touserdata(void *L, int idx);
void *lua_tothread(void *L, int idx);
const void *lua_topointer(void *L, int idx);

/*push functions   C -> stack*/
void  lua_pushnil(void *L);
void  lua_pushnumber(void *L, lua_Number n);
void  lua_pushinteger(void *L, lua_Integer n);
void  lua_pushlstring(void *L, const char *s, size_t l);
void  lua_pushstring(void *L, const char *s);
const char *lua_pushfstring(void *L, const char *fmt, ...);
void  lua_pushcclosure(void *L, lua_CFunction fn, int n);
void  lua_pushboolean(void *L, int b);
void  lua_pushlightuserdata(void *L, void *p);
int   lua_pushthread(void *L);

/* get functions   Lua -> stack*/
void  lua_gettable(void *L, int idx);
void  lua_getfield(void *L, int idx, const char *k);
void  lua_rawget(void *L, int idx);
void  lua_rawgeti(void *L, int idx, int n);
void  lua_createtable(void *L, int narr, int nrec);
void *lua_newuserdata(void *L, size_t sz);
int   lua_getmetatable(void *L, int objindex);
void  lua_getfenv(void *L, int idx);

/* set functions   stack -> Lua*/
void  lua_settable(void *L, int idx);
void  lua_setfield(void *L, int idx, const char *k);
void  lua_rawset(void *L, int idx);
void  lua_rawseti(void *L, int idx, int n);
int   lua_setmetatable(void *L, int objindex);
int   lua_setfenv(void *L, int idx);

/*`load' and `call' functions   load and run Lua code*/
void  lua_call(void *L, int nargs, int nresults);
int   lua_pcall(void *L, int nargs, int nresults, int errfunc);
int   lua_cpcall(void *L, lua_CFunction func, void *ud);
int   lua_load(void *L, lua_Reader reader, void *dt,
                                        const char *chunkname);

int lua_dump(void *L, lua_Writer writer, void *data);

/* coroutine functions*/
int  lua_yield(void *L, int nresults);
int  lua_resume(void *L, int narg);
int  lua_status(void *L);

/* garbage-collection function and options*/
int lua_gc(void *L, int what, int data);

/* miscellaneous functions*/
int lua_error(void *L);
int lua_next(void *L, int idx);
void lua_concat(void *L, int n);

lua_Alloc lua_getallocf(void *L, void **ud);
void lua_setallocf(void *L, lua_Alloc f, void *ud);

void  setfieldInt(void *L, const char *key,int value);
void  setfieldBool(void *L,const char *key,int value);
void  setfieldString(void* L, const char* key,const char* str, const size_t len);


/* hack */
void lua_setlevel	(void *from, void *to);

int lua_getstack (void *L, int level, lua_Debug *ar);
int lua_getinfo (void *L, const char *what, lua_Debug *ar);
const char *lua_getlocal (void *L, const lua_Debug *ar, int n);
const char *lua_setlocal (void *L, const lua_Debug *ar, int n);
const char *lua_getupvalue (void *L, int funcindex, int n);
const char *lua_setupvalue (void *L, int funcindex, int n);

int lua_sethook (void *L, lua_Hook func, int mask, int count);
lua_Hook lua_gethook (void *L);
int lua_gethookmask (void *L);
int lua_gethookcount (void *L);

