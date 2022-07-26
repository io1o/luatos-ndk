#include "cs_types.h"
#include "stdarg.h"
#include "am_openat_drv.h"
#include "am_openat_system.h"
#include "std_type.h"
#include "lua_type.h"
#include "ndk_math.h"
#include "lwip_types.h"
long (*CFW_TcpipGetLastError)(void) = (void*) 0xFFFFFFCC;
int (*lwip_accept)(int s, struct sockaddr *addr, socklen_t *addrlen) = (void*) 0xFFFFFFCC;
int (*lwip_bind)(int s, const struct sockaddr *name, socklen_t namelen) = (void*) 0xFFFFFFCC;
int (*lwip_shutdown)(int s, int how) = (void*) 0xFFFFFFCC;
int (*lwip_getpeername)(int s, struct sockaddr *name, socklen_t *namelen) = (void*) 0xFFFFFFCC;
int (*lwip_getsockname)(int s, struct sockaddr *name, socklen_t *namelen) = (void*) 0xFFFFFFCC;
int (*lwip_setsockopt)(int s, int level, int optname, const void *optval, socklen_t optlen) = (void*) 0xFFFFFFCC;
int (*lwip_getsockopt)(int s, int level, int optname, void *optval, socklen_t *optlen) = (void*) 0xFFFFFFCC;
int (*lwip_close)(int s) = (void*) 0xFFFFFFCC;
int (*lwip_connect)(int s, const struct sockaddr *name, socklen_t namelen) = (void*) 0xFFFFFFCC;
int (*lwip_listen)(int s, int backlog) = (void*) 0xFFFFFFCC;
ssize_t (*lwip_recv)(int s, void *mem, size_t len, int flags) = (void*) 0xFFFFFFCC;
ssize_t (*lwip_recvmsg)(int s, struct msghdr *message, int flags) = (void*) 0xFFFFFFCC;
ssize_t (*lwip_recvfrom)(int s, void *mem, size_t len, int flags, struct sockaddr *from, socklen_t *fromlen) = (void*) 0xFFFFFFCC;
ssize_t (*lwip_send)(int s, const void *dataptr, size_t size, int flags) = (void*) 0xFFFFFFCC;
ssize_t (*lwip_sendmsg)(int s, const struct msghdr *message, int flags) = (void*) 0xFFFFFFCC;
ssize_t (*lwip_sendto)(int s, const void *dataptr, size_t size, int flags, const struct sockaddr *to, socklen_t tolen) = (void*) 0xFFFFFFCC;
int (*lwip_socket)(int domain, int type, int protocol) = (void*) 0xFFFFFFCC;
int (*lwip_select)(int maxfdp1, fd_set *readset, fd_set *writeset, fd_set *exceptset, struct timeval *timeout) = (void*) 0xFFFFFFCC;
int (*lwip_ioctl)(int s, long cmd, void *argp) = (void*) 0xFFFFFFCC;
bool (*OPENAT_msg_to_lua)(UINT8 msg_id,BOOL result,INT32 num,CHAR* data,UINT32 dataLen) = (void*) 0xFFFFFFCC;
void (*stderr)(void) = (void*) 0xFFFFFFCC;
void (*stdin)(void) = (void*) 0xFFFFFFCC;
void (*stdout)(void) = (void*) 0xFFFFFFCC;
int (*atoi)(const char *str) = (void*) 0xFFFFFFCC;
size_t (*strlen)(const char *) = (void*) 0xFFFFFFCC;
char* (*strchr)(const char *,int) = (void*) 0xFFFFFFCC;
char* (*strcpy)(char *,const char *) = (void*) 0xFFFFFFCC;
char* (*strstr)(const char *, const char *) = (void*) 0xFFFFFFCC;
char* (*strncpy)(char *,const char *, size_t) = (void*) 0xFFFFFFCC;
char* (*strcat)(char *__restrict, const char *__restrict) = (void*) 0xFFFFFFCC;
long  (*strtol)(const char *, char **, int) = (void*) 0xFFFFFFCC;
int   (*strcmp)(const char *,const char *) = (void*) 0xFFFFFFCC;
int   (*sprintf)(char *, const char *, ...) = (void*) 0xFFFFFFCC;
int   (*strncmp)(const char *,const char *,size_t) = (void*) 0xFFFFFFCC;
int   (*strncasecmp)(const char *, const char *, size_t) = (void*) 0xFFFFFFCC;
int   (*sscanf)(const char * buf, const char * fmt, ...) = (void*) 0xFFFFFFCC;
int   (*snprintf)(char * buf, size_t len, const char *fmt, ...) = (void*) 0xFFFFFFCC;
int   (*fprintf)(void *err, const char *fmt, ...) = (void*) 0xFFFFFFCC;
int   (*vsnprintf)(char *buf, size_t size, const char *fmt, ...) = (void*) 0xFFFFFFCC;
int   (*printf)(const char *fmt, ...) = (void*) 0xFFFFFFCC;
void* (*memchr)(const void *, int, size_t) = (void*) 0xFFFFFFCC;
void* (*memmove)(void *, const void *, size_t) = (void*) 0xFFFFFFCC;
int   (*memcmp)(const void *, const void *, size_t) = (void*) 0xFFFFFFCC;
void* (*OPENAT_malloc)(size_t size) = (void*) 0xFFFFFFCC;
void* (*OPENAT_realloc)(PVOID ptr, UINT32 size) = (void*) 0xFFFFFFCC;
void  (*OPENAT_free)(void *ptr) = (void*) 0xFFFFFFCC;
VOID (*OPENAT_print)(const char * fmt, ...) = (void*) 0xFFFFFFCC;
VOID (*OPENAT_lua_print)(const char * fmt, ...) = (void*) 0xFFFFFFCC;
void  (*OPENAT_assert)( char condition,  char *func, unsigned int line) = (void*) 0xFFFFFFCC;
INT64 (*OPENAT_get_system_tick)(VOID) = (void*) 0xFFFFFFCC;
double (*atan)(double) = (void*) 0xFFFFFFCC;
double (*cos)(double) = (void*) 0xFFFFFFCC;
double (*sin)(double) = (void*) 0xFFFFFFCC;
double (*tan)(double) = (void*) 0xFFFFFFCC;
double (*tanh)(double) = (void*) 0xFFFFFFCC;
double (*frexp)(double, int *) = (void*) 0xFFFFFFCC;
double (*modf)(double, double *) = (void*) 0xFFFFFFCC;
double (*ceil)(double) = (void*) 0xFFFFFFCC;
double (*fabs)(double) = (void*) 0xFFFFFFCC;
double (*floor)(double) = (void*) 0xFFFFFFCC;
double (*acos)(double) = (void*) 0xFFFFFFCC;
double (*asin)(double) = (void*) 0xFFFFFFCC;
double (*atan2)(double, double) = (void*) 0xFFFFFFCC;
double (*cosh)(double) = (void*) 0xFFFFFFCC;
double (*sinh)(double) = (void*) 0xFFFFFFCC;
double (*exp)(double) = (void*) 0xFFFFFFCC;
double (*ldexp)(double, int) = (void*) 0xFFFFFFCC;
double (*log)(double) = (void*) 0xFFFFFFCC;
double (*log10)(double) = (void*) 0xFFFFFFCC;
double (*pow)(double, double) = (void*) 0xFFFFFFCC;
double (*sqrt)(double) = (void*) 0xFFFFFFCC;
double (*fmod)(double, double) = (void*) 0xFFFFFFCC;
int (*finite)(double) = (void*) 0xFFFFFFCC;
int (*finitef)(float) = (void*) 0xFFFFFFCC;
int (*finitel)(long double) = (void*) 0xFFFFFFCC;
int (*isinff)(float) = (void*) 0xFFFFFFCC;
int (*isnanf)(float) = (void*) 0xFFFFFFCC;
int (*isinf)(double) = (void*) 0xFFFFFFCC;
int (*isnan)(double) = (void*) 0xFFFFFFCC;
int (*__isinff)(float x) = (void*) 0xFFFFFFCC;
int (*__isinfd)(double x) = (void*) 0xFFFFFFCC;
int (*__isnanf)(float x) = (void*) 0xFFFFFFCC;
int (*__isnand)(double x) = (void*) 0xFFFFFFCC;
int (*__fpclassifyf)(float x) = (void*) 0xFFFFFFCC;
int (*__fpclassifyd)(double x) = (void*) 0xFFFFFFCC;
int (*__signbitf)(float x) = (void*) 0xFFFFFFCC;
int (*__signbitd)(double x) = (void*) 0xFFFFFFCC;
double (*infinity)(void) = (void*) 0xFFFFFFCC;
double (*nan)(const char *) = (void*) 0xFFFFFFCC;
double (*copysign)(double, double) = (void*) 0xFFFFFFCC;
double (*logb)(double) = (void*) 0xFFFFFFCC;
int (*ilogb)(double) = (void*) 0xFFFFFFCC;
double (*asinh)(double) = (void*) 0xFFFFFFCC;
double (*cbrt)(double) = (void*) 0xFFFFFFCC;
double (*nextafter)(double, double) = (void*) 0xFFFFFFCC;
double (*rint)(double) = (void*) 0xFFFFFFCC;
double (*scalbn)(double, int) = (void*) 0xFFFFFFCC;
double (*exp2)(double) = (void*) 0xFFFFFFCC;
double (*scalbln)(double, long int) = (void*) 0xFFFFFFCC;
double (*tgamma)(double) = (void*) 0xFFFFFFCC;
double (*nearbyint)(double) = (void*) 0xFFFFFFCC;
int (*lrint)(double) = (void*) 0xFFFFFFCC;
int (*llrint)(double) = (void*) 0xFFFFFFCC;
double (*round)(double) = (void*) 0xFFFFFFCC;
int (*lround)(double) = (void*) 0xFFFFFFCC;
int (*llround)(double) = (void*) 0xFFFFFFCC;
double (*trunc)(double) = (void*) 0xFFFFFFCC;
double (*remquo)(double, double, int *) = (void*) 0xFFFFFFCC;
double (*fdim)(double, double) = (void*) 0xFFFFFFCC;
double (*fmax)(double, double) = (void*) 0xFFFFFFCC;
double (*fmin)(double, double) = (void*) 0xFFFFFFCC;
double (*fma)(double, double, double) = (void*) 0xFFFFFFCC;
double (*log1p)(double) = (void*) 0xFFFFFFCC;
double (*expm1)(double) = (void*) 0xFFFFFFCC;
double (*acosh)(double) = (void*) 0xFFFFFFCC;
double (*atanh)(double) = (void*) 0xFFFFFFCC;
double (*remainder)(double, double) = (void*) 0xFFFFFFCC;
double (*gamma)(double) = (void*) 0xFFFFFFCC;
double (*lgamma)(double) = (void*) 0xFFFFFFCC;
double (*erf)(double) = (void*) 0xFFFFFFCC;
double (*erfc)(double) = (void*) 0xFFFFFFCC;
double (*log2)(double) = (void*) 0xFFFFFFCC;
double (*hypot)(double, double) = (void*) 0xFFFFFFCC;
float (*atanf)(float) = (void*) 0xFFFFFFCC;
float (*cosf)(float) = (void*) 0xFFFFFFCC;
float (*sinf)(float) = (void*) 0xFFFFFFCC;
float (*tanf)(float) = (void*) 0xFFFFFFCC;
float (*tanhf)(float) = (void*) 0xFFFFFFCC;
float (*frexpf)(float, int *) = (void*) 0xFFFFFFCC;
float (*modff)(float, float *) = (void*) 0xFFFFFFCC;
float (*ceilf)(float) = (void*) 0xFFFFFFCC;
float (*fabsf)(float) = (void*) 0xFFFFFFCC;
float (*floorf)(float) = (void*) 0xFFFFFFCC;
float (*acosf)(float) = (void*) 0xFFFFFFCC;
float (*asinf)(float) = (void*) 0xFFFFFFCC;
float (*atan2f)(float, float) = (void*) 0xFFFFFFCC;
float (*coshf)(float) = (void*) 0xFFFFFFCC;
float (*sinhf)(float) = (void*) 0xFFFFFFCC;
float (*expf)(float) = (void*) 0xFFFFFFCC;
float (*ldexpf)(float, int) = (void*) 0xFFFFFFCC;
float (*logf)(float) = (void*) 0xFFFFFFCC;
float (*log10f)(float) = (void*) 0xFFFFFFCC;
float (*powf)(float, float) = (void*) 0xFFFFFFCC;
float (*sqrtf)(float) = (void*) 0xFFFFFFCC;
float (*fmodf)(float, float) = (void*) 0xFFFFFFCC;
float (*exp2f)(float) = (void*) 0xFFFFFFCC;
float (*scalblnf)(float, long int) = (void*) 0xFFFFFFCC;
float (*tgammaf)(float) = (void*) 0xFFFFFFCC;
float (*nearbyintf)(float) = (void*) 0xFFFFFFCC;
int (*lrintf)(float) = (void*) 0xFFFFFFCC;
int (*llrintf)(float) = (void*) 0xFFFFFFCC;
float (*roundf)(float) = (void*) 0xFFFFFFCC;
int (*lroundf)(float) = (void*) 0xFFFFFFCC;
int (*llroundf)(float) = (void*) 0xFFFFFFCC;
float (*truncf)(float) = (void*) 0xFFFFFFCC;
float (*remquof)(float, float, int *) = (void*) 0xFFFFFFCC;
float (*fdimf)(float, float) = (void*) 0xFFFFFFCC;
float (*fmaxf)(float, float) = (void*) 0xFFFFFFCC;
float (*fminf)(float, float) = (void*) 0xFFFFFFCC;
float (*fmaf)(float, float, float) = (void*) 0xFFFFFFCC;
float (*infinityf)(void) = (void*) 0xFFFFFFCC;
float (*nanf)(const char *) = (void*) 0xFFFFFFCC;
float (*copysignf)(float, float) = (void*) 0xFFFFFFCC;
float (*logbf)(float) = (void*) 0xFFFFFFCC;
int (*ilogbf)(float) = (void*) 0xFFFFFFCC;
float (*asinhf)(float) = (void*) 0xFFFFFFCC;
float (*cbrtf)(float) = (void*) 0xFFFFFFCC;
float (*nextafterf)(float, float) = (void*) 0xFFFFFFCC;
float (*rintf)(float) = (void*) 0xFFFFFFCC;
float (*scalbnf)(float, int) = (void*) 0xFFFFFFCC;
float (*log1pf)(float) = (void*) 0xFFFFFFCC;
float (*expm1f)(float) = (void*) 0xFFFFFFCC;
float (*acoshf)(float) = (void*) 0xFFFFFFCC;
float (*atanhf)(float) = (void*) 0xFFFFFFCC;
float (*remainderf)(float, float) = (void*) 0xFFFFFFCC;
float (*gammaf)(float) = (void*) 0xFFFFFFCC;
float (*lgammaf)(float) = (void*) 0xFFFFFFCC;
float (*erff)(float) = (void*) 0xFFFFFFCC;
float (*erfcf)(float) = (void*) 0xFFFFFFCC;
float (*log2f)(float) = (void*) 0xFFFFFFCC;
float (*hypotf)(float, float) = (void*) 0xFFFFFFCC;
double (*atanl)(long double) = (void*) 0xFFFFFFCC;
double (*cosl)(long double) = (void*) 0xFFFFFFCC;
double (*sinl)(long double) = (void*) 0xFFFFFFCC;
double (*tanl)(long double) = (void*) 0xFFFFFFCC;
double (*tanhl)(long double) = (void*) 0xFFFFFFCC;
double (*frexpl)(long double, int *) = (void*) 0xFFFFFFCC;
double (*modfl)(long double, long double *) = (void*) 0xFFFFFFCC;
double (*ceill)(long double) = (void*) 0xFFFFFFCC;
double (*fabsl)(long double) = (void*) 0xFFFFFFCC;
double (*floorl)(long double) = (void*) 0xFFFFFFCC;
double (*log1pl)(long double) = (void*) 0xFFFFFFCC;
double (*expm1l)(long double) = (void*) 0xFFFFFFCC;
double (*acosl)(long double) = (void*) 0xFFFFFFCC;
double (*asinl)(long double) = (void*) 0xFFFFFFCC;
double (*atan2l)(long double, long double) = (void*) 0xFFFFFFCC;
double (*coshl)(long double) = (void*) 0xFFFFFFCC;
double (*sinhl)(long double) = (void*) 0xFFFFFFCC;
double (*expl)(long double) = (void*) 0xFFFFFFCC;
double (*ldexpl)(long double, int) = (void*) 0xFFFFFFCC;
double (*logl)(long double) = (void*) 0xFFFFFFCC;
double (*log10l)(long double) = (void*) 0xFFFFFFCC;
double (*powl)(long double, long double) = (void*) 0xFFFFFFCC;
double (*sqrtl)(long double) = (void*) 0xFFFFFFCC;
double (*fmodl)(long double, long double) = (void*) 0xFFFFFFCC;
double (*hypotl)(long double, long double) = (void*) 0xFFFFFFCC;
double (*copysignl)(long double, long double) = (void*) 0xFFFFFFCC;
double (*nanl)(const char *) = (void*) 0xFFFFFFCC;
int (*ilogbl)(long double) = (void*) 0xFFFFFFCC;
double (*asinhl)(long double) = (void*) 0xFFFFFFCC;
double (*cbrtl)(long double) = (void*) 0xFFFFFFCC;
double (*nextafterl)(long double, long double) = (void*) 0xFFFFFFCC;
float (*nexttowardf)(float, long double) = (void*) 0xFFFFFFCC;
double (*nexttoward)(double, long double) = (void*) 0xFFFFFFCC;
double (*nexttowardl)(long double, long double) = (void*) 0xFFFFFFCC;
double (*logbl)(long double) = (void*) 0xFFFFFFCC;
double (*log2l)(long double) = (void*) 0xFFFFFFCC;
double (*rintl)(long double) = (void*) 0xFFFFFFCC;
double (*scalbnl)(long double, int) = (void*) 0xFFFFFFCC;
double (*exp2l)(long double) = (void*) 0xFFFFFFCC;
double (*scalblnl)(long double, long) = (void*) 0xFFFFFFCC;
double (*tgammal)(long double) = (void*) 0xFFFFFFCC;
double (*nearbyintl)(long double) = (void*) 0xFFFFFFCC;
int (*lrintl)(long double) = (void*) 0xFFFFFFCC;
int (*llrintl)(long double) = (void*) 0xFFFFFFCC;
double (*roundl)(long double) = (void*) 0xFFFFFFCC;
long (*lroundl)(long double) = (void*) 0xFFFFFFCC;
int (*llroundl)(long double) = (void*) 0xFFFFFFCC;
double (*truncl)(long double) = (void*) 0xFFFFFFCC;
double (*remquol)(long double, long double, int *) = (void*) 0xFFFFFFCC;
double (*fdiml)(long double, long double) = (void*) 0xFFFFFFCC;
double (*fmaxl)(long double, long double) = (void*) 0xFFFFFFCC;
double (*fminl)(long double, long double) = (void*) 0xFFFFFFCC;
double (*fmal)(long double, long double, long double) = (void*) 0xFFFFFFCC;
double (*acoshl)(long double) = (void*) 0xFFFFFFCC;
double (*atanhl)(long double) = (void*) 0xFFFFFFCC;
double (*remainderl)(long double, long double) = (void*) 0xFFFFFFCC;
double (*lgammal)(long double) = (void*) 0xFFFFFFCC;
double (*erfl)(long double) = (void*) 0xFFFFFFCC;
double (*erfcl)(long double) = (void*) 0xFFFFFFCC;
double (*drem)(double, double) = (void*) 0xFFFFFFCC;
float (*dremf)(float, float) = (void*) 0xFFFFFFCC;
double (*gamma_r)(double, int *) = (void*) 0xFFFFFFCC;
double (*lgamma_r)(double, int *) = (void*) 0xFFFFFFCC;
float (*gammaf_r)(float, int *) = (void*) 0xFFFFFFCC;
float (*lgammaf_r)(float, int *) = (void*) 0xFFFFFFCC;
double (*y0)(double) = (void*) 0xFFFFFFCC;
double (*y1)(double) = (void*) 0xFFFFFFCC;
double (*yn)(int, double) = (void*) 0xFFFFFFCC;
double (*j0)(double) = (void*) 0xFFFFFFCC;
double (*j1)(double) = (void*) 0xFFFFFFCC;
double (*jn)(int, double) = (void*) 0xFFFFFFCC;
float (*y0f)(float) = (void*) 0xFFFFFFCC;
float (*y1f)(float) = (void*) 0xFFFFFFCC;
float (*ynf)(int, float) = (void*) 0xFFFFFFCC;
float (*j0f)(float) = (void*) 0xFFFFFFCC;
float (*j1f)(float) = (void*) 0xFFFFFFCC;
float (*jnf)(int, float) = (void*) 0xFFFFFFCC;
void (*sincos)(double, double *, double *) = (void*) 0xFFFFFFCC;
void (*sincosf)(float, float *, float *) = (void*) 0xFFFFFFCC;
double (*exp10)(double) = (void*) 0xFFFFFFCC;
double (*pow10)(double) = (void*) 0xFFFFFFCC;
float (*exp10f)(float) = (void*) 0xFFFFFFCC;
float (*pow10f)(float) = (void*) 0xFFFFFFCC;
int *(*__signgam)(void) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_config_gpio)(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO编号 */
                            T_AMOPENAT_GPIO_CFG *cfg            /* 输出或输入 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_set_gpio)(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO编号 */
                            UINT8 value                         /* 0 or 1 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_read_gpio)(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO编号 */
                            UINT8* value                        /* 结果 0 or 1 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_close_gpio)(
                            E_AMOPENAT_GPIO_PORT port           /* GPIO编号 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_gpioPulse)(
                            E_AMOPENAT_GPIO_PORT port,
                            unsigned high_us,
                            unsigned low_us,
                            unsigned count,
                            unsigned idle
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_config_uart)(
                            E_AMOPENAT_UART_PORT port,          /* UART 编号 */
                            T_AMOPENAT_UART_PARAM *cfg          /* 初始化参数 */
                            ) = (void*) 0xFFFFFFCC;
UINT32 (*OPENAT_read_uart)(                                        /* 实际读取长度 */
                            E_AMOPENAT_UART_PORT port,          /* UART 编号 */
                            UINT8* buf,                         /* 存储数据地址 */
                            UINT32 bufLen,                      /* 存储空间长度 */
                            UINT32 timeoutMs                    /* 读取超时 ms */
                            ) = (void*) 0xFFFFFFCC;
UINT32 (*OPENAT_write_uart)(                                       /* 实际写入长度 */
                            E_AMOPENAT_UART_PORT port,          /* UART 编号 */
                            UINT8* buf,                         /* 写入数据地址 */
                            UINT32 bufLen                       /* 写入数据长度 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_close_uart)(
                            E_AMOPENAT_UART_PORT port           /* UART 编号 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_open_i2c)(E_AMOPENAT_I2C_PORT port, 
                              T_AMOPENAT_I2C_PARAM *cfg) = (void*) 0xFFFFFFCC;
UINT32 (*OPENAT_read_i2c)(E_AMOPENAT_I2C_PORT port, 
                                UINT8 slaveAddr, 
                                CONST UINT16 *pRegAddr, 
                                UINT8* buf,
                                UINT32 bufLen) = (void*) 0xFFFFFFCC;
UINT32 (*OPENAT_write_i2c)(E_AMOPENAT_I2C_PORT port, 
                                UINT8 slaveAddr, 
                                CONST UINT16 *pRegAddr, 
                                CONST UINT8* buf,
                                UINT32 bufLen) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_close_i2c)(E_AMOPENAT_I2C_PORT port) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_OpenSPI)( E_AMOPENAT_SPI_PORT port, T_AMOPENAT_SPI_PARAM *cfg) = (void*) 0xFFFFFFCC;
UINT32 (*OPENAT_ReadSPI)(E_AMOPENAT_SPI_PORT port, CONST UINT8 * buf, UINT32 bufLen) = (void*) 0xFFFFFFCC;
UINT32 (*OPENAT_WriteSPI)(E_AMOPENAT_SPI_PORT port, CONST UINT8 * buf, UINT32 bufLen, BOOLEAN type) = (void*) 0xFFFFFFCC;
UINT32 (*OPENAT_RwSPI)(E_AMOPENAT_SPI_PORT port, CONST UINT8* txBuf, CONST UINT8* rxBuf,UINT32 bufLen) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_CloseSPI)( E_AMOPENAT_SPI_PORT port) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_InitADC)(
    E_AMOPENAT_ADC_CHANNEL channel  /* ADC编号 */,
    E_AMOPENAT_ADC_CFG_MODE mode) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_ReadADC)(
    E_AMOPENAT_ADC_CHANNEL channel,  /* ADC编号 */
    kal_uint32*               adcValue,   /* adc值 */
    kal_uint32*               voltage    /* 电压值*/) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_CloseADC)(
    E_AMOPENAT_ADC_CHANNEL channel  /* ADC编号 */) = (void*) 0xFFFFFFCC;
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
                            ) = (void*) 0xFFFFFFCC;
VOID (*OPENAT_delete_task)(                                        /* 删除线程接口 */
                            HANDLE task
                            ) = (void*) 0xFFFFFFCC;
HANDLE (*OPENAT_current_task)(                                     /* 获取当前线程接口 */
                            VOID
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_suspend_task)(                                       /* 挂起线程接口 */
                            HANDLE hTask                        /* 线程句柄，create_task接口返回值 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_resume_task)(                                        /* 恢复线程接口 */
                            HANDLE hTask                        /* 线程句柄，create_task接口返回值 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_get_task_info)(                                      /* 获取当前线程创建信息接口 */
                            HANDLE hTask,                       /* 线程句柄，create_task接口返回值 */
                            T_AMOPENAT_TASK_INFO *pTaskInfo     /* 线程信息存储接口 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_sleep)(                                              /* 系统睡眠接口 */
                            UINT32 nMillisecondes               /* 睡眠时间 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_wait_message)(                                       /* 阻塞等待消息接口*/
                            HANDLE task,
                            int* msg_id,
                            void* * ppMessage,
                            UINT32 nTimeOut
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_send_message)(                                       /* 发送消息接口，添加到消息队列尾部 */
                            HANDLE   destTask,
                            int msg_id,
                            void* pMessage,                     /* 存储消息指针 */
                            int message_length
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_SendHighPriorityMessage)(                            /* 发送高优先级消息接口，添加到消息队列头部 */
                            HANDLE   destTask,
                            int msg_id,
                            void* pMessage,                     /* 存储消息指针 */
                            int message_length
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_available_message)(                                  /* 检测消息队列中是否有消息 */
                            HANDLE hTask                        /* 线程句柄，create_task接口返回值 */
                            ) = (void*) 0xFFFFFFCC;
HANDLE (*OPENAT_create_timer)(                                     /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,               /* 定时器到时处理函数 */
                            PVOID pParameter                    /* 作为参数传递给定时器到时处理函数 */
                            ) = (void*) 0xFFFFFFCC;
HANDLE (*OPENAT_create_timerTask)(                                 /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,               /* 定时器到时处理函数 */
                            PVOID pParameter                    /* 作为参数传递给定时器到时处理函数 */
                            ) = (void*) 0xFFFFFFCC;
HANDLE (*OPENAT_create_hir_timer)(                                 /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,               /* 定时器到时处理函数 */
                            PVOID pParameter                    /* 作为参数传递给定时器到时处理函数 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_start_timer)(                                        /* 启动定时器接口 */
                            HANDLE hTimer,                      /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes               /* 定时器时间 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_loop_start_timer)(                                   /* 启动循环定时器接口 */
                            HANDLE hTimer,                      /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes               /* 定时器时间 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_start_precise_timer)(                                /* 启动定时器接口 */
                            HANDLE hTimer,                      /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes               /* 定时器时间 */
                            ) = (void*) 0xFFFFFFCC;
BOOL (*OPENAT_stop_timer)(                                         /* 停止定时器接口 */
                            HANDLE hTimer                       /* 定时器句柄，create_timer接口返回值 */
                            ) = (void*) 0xFFFFFFCC;
UINT64 (*OPENAT_timer_remaining)(
                            HANDLE hTimer
                            ) = (void*) 0xFFFFFFCC;
void (*luaI_openlib)(void *L, const char *libname, const luaL_Reg *l, int nup) = (void*) 0xFFFFFFCC;
int (*luaL_optinteger)(void *L, int nArg, int def) = (void*) 0xFFFFFFCC;
lua_Number (*luaL_optnumber)(void *L, int nArg, lua_Number def) = (void*) 0xFFFFFFCC;
char *(*luaL_optlstring)(void *L,                           /*获取参数，如果没有设置默认值*/
                        int nArg, const char *def, size_t *l) = (void*) 0xFFFFFFCC;
void (*luaL_checktype)(void *L, int nArg, int t) = (void*) 0xFFFFFFCC;
int (*luaL_checkinteger)(void *L, int nArg) = (void*) 0xFFFFFFCC;
lua_Number (*luaL_checknumber)(void *L, int nArg) = (void*) 0xFFFFFFCC;
char *(*luaL_checklstring)(void *L,int nArg, size_t *l) = (void*) 0xFFFFFFCC;
void (*luaL_checkstack)(void *L, int space, const char *mes) = (void*) 0xFFFFFFCC;
int (*luaL_checkoption)(void *L, int narg, const char *def,
                                 const char *const lst[]) = (void*) 0xFFFFFFCC;
int (*luaL_error)(void *L, const char *fmt, ...) = (void*) 0xFFFFFFCC;
int (*luaL_argerror)(void *L, int narg, const char *extramsg) = (void*) 0xFFFFFFCC;
void *(*lua_newstate)(lua_Alloc f, void *ud) = (void*) 0xFFFFFFCC;
void (*lua_close)(void *L) = (void*) 0xFFFFFFCC;
void *(*lua_newthread)(void *L) = (void*) 0xFFFFFFCC;
lua_CFunction (*lua_atpanic)(void *L, lua_CFunction panicf) = (void*) 0xFFFFFFCC;
int (*lua_gettop)(void *L) = (void*) 0xFFFFFFCC;
void (*lua_settop)(void *L, int idx) = (void*) 0xFFFFFFCC;
void (*lua_pushvalue)(void *L, int idx) = (void*) 0xFFFFFFCC;
void (*lua_remove)(void *L, int idx) = (void*) 0xFFFFFFCC;
void (*lua_insert)(void *L, int idx) = (void*) 0xFFFFFFCC;
void (*lua_replace)(void *L, int idx) = (void*) 0xFFFFFFCC;
int (*lua_checkstack)(void *L, int sz) = (void*) 0xFFFFFFCC;
void (*lua_xmove)(void *from, void *to, int n) = (void*) 0xFFFFFFCC;
int (*lua_isnumber)(void *L, int idx) = (void*) 0xFFFFFFCC;
int (*lua_isstring)(void *L, int idx) = (void*) 0xFFFFFFCC;
int (*lua_iscfunction)(void *L, int idx) = (void*) 0xFFFFFFCC;
int (*lua_isuserdata)(void *L, int idx) = (void*) 0xFFFFFFCC;
int (*lua_type)(void *L, int idx) = (void*) 0xFFFFFFCC;
char *(*lua_typename)(void *L, int tp) = (void*) 0xFFFFFFCC;
int (*lua_equal)(void *L, int idx1, int idx2) = (void*) 0xFFFFFFCC;
int (*lua_rawequal)(void *L, int idx1, int idx2) = (void*) 0xFFFFFFCC;
int (*lua_lessthan)(void *L, int idx1, int idx2) = (void*) 0xFFFFFFCC;
lua_Number (*lua_tonumber)(void *L, int idx) = (void*) 0xFFFFFFCC;
lua_Integer (*lua_tointeger)(void *L, int idx) = (void*) 0xFFFFFFCC;
int (*lua_toboolean)(void *L, int idx) = (void*) 0xFFFFFFCC;
char *(*lua_tolstring)(void *L, int idx, size_t *len) = (void*) 0xFFFFFFCC;
size_t (*lua_objlen)(void *L, int idx) = (void*) 0xFFFFFFCC;
lua_CFunction (*lua_tocfunction)(void *L, int idx) = (void*) 0xFFFFFFCC;
void *(*lua_touserdata)(void *L, int idx) = (void*) 0xFFFFFFCC;
void *(*lua_tothread)(void *L, int idx) = (void*) 0xFFFFFFCC;
void *(*lua_topointer)(void *L, int idx) = (void*) 0xFFFFFFCC;
void (*lua_pushnil)(void *L) = (void*) 0xFFFFFFCC;
void (*lua_pushnumber)(void *L, lua_Number n) = (void*) 0xFFFFFFCC;
void (*lua_pushinteger)(void *L, lua_Integer n) = (void*) 0xFFFFFFCC;
void (*lua_pushlstring)(void *L, const char *s, size_t l) = (void*) 0xFFFFFFCC;
void (*lua_pushstring)(void *L, const char *s) = (void*) 0xFFFFFFCC;
char *(*lua_pushfstring)(void *L, const char *fmt, ...) = (void*) 0xFFFFFFCC;
void (*lua_pushcclosure)(void *L, lua_CFunction fn, int n) = (void*) 0xFFFFFFCC;
void (*lua_pushboolean)(void *L, int b) = (void*) 0xFFFFFFCC;
void (*lua_pushlightuserdata)(void *L, void *p) = (void*) 0xFFFFFFCC;
int  (*lua_pushthread)(void *L) = (void*) 0xFFFFFFCC;
void (*lua_gettable)(void *L, int idx) = (void*) 0xFFFFFFCC;
void (*lua_getfield)(void *L, int idx, const char *k) = (void*) 0xFFFFFFCC;
void (*lua_rawget)(void *L, int idx) = (void*) 0xFFFFFFCC;
void (*lua_rawgeti)(void *L, int idx, int n) = (void*) 0xFFFFFFCC;
void (*lua_createtable)(void *L, int narr, int nrec) = (void*) 0xFFFFFFCC;
void *(*lua_newuserdata)(void *L, size_t sz) = (void*) 0xFFFFFFCC;
int  (*lua_getmetatable)(void *L, int objindex) = (void*) 0xFFFFFFCC;
void (*lua_getfenv)(void *L, int idx) = (void*) 0xFFFFFFCC;
void (*lua_settable)(void *L, int idx) = (void*) 0xFFFFFFCC;
void (*lua_setfield)(void *L, int idx, const char *k) = (void*) 0xFFFFFFCC;
void (*lua_rawset)(void *L, int idx) = (void*) 0xFFFFFFCC;
void (*lua_rawseti)(void *L, int idx, int n) = (void*) 0xFFFFFFCC;
int  (*lua_setmetatable)(void *L, int objindex) = (void*) 0xFFFFFFCC;
int  (*lua_setfenv)(void *L, int idx) = (void*) 0xFFFFFFCC;
void (*lua_call)(void *L, int nargs, int nresults) = (void*) 0xFFFFFFCC;
int  (*lua_pcall)(void *L, int nargs, int nresults, int errfunc) = (void*) 0xFFFFFFCC;
int  (*lua_cpcall)(void *L, lua_CFunction func, void *ud) = (void*) 0xFFFFFFCC;
int  (*lua_load)(void *L, lua_Reader reader, void *dt,
                                        const char *chunkname) = (void*) 0xFFFFFFCC;
int (*lua_dump)(void *L, lua_Writer writer, void *data) = (void*) 0xFFFFFFCC;
int (*lua_yield)(void *L, int nresults) = (void*) 0xFFFFFFCC;
int (*lua_resume)(void *L, int narg) = (void*) 0xFFFFFFCC;
int (*lua_status)(void *L) = (void*) 0xFFFFFFCC;
int (*lua_gc)(void *L, int what, int data) = (void*) 0xFFFFFFCC;
int (*lua_error)(void *L) = (void*) 0xFFFFFFCC;
int (*lua_next)(void *L, int idx) = (void*) 0xFFFFFFCC;
void (*lua_concat)(void *L, int n) = (void*) 0xFFFFFFCC;
lua_Alloc (*lua_getallocf)(void *L, void **ud) = (void*) 0xFFFFFFCC;
void (*lua_setallocf)(void *L, lua_Alloc f, void *ud) = (void*) 0xFFFFFFCC;
void (*setfieldInt)(void *L, const char *key,int value) = (void*) 0xFFFFFFCC;
void (*setfieldBool)(void *L,const char *key,int value) = (void*) 0xFFFFFFCC;
void (*setfieldString)(void* L, const char* key,const char* str, const size_t len) = (void*) 0xFFFFFFCC;
void (*lua_setlevel)(void *from, void *to) = (void*) 0xFFFFFFCC;
int (*lua_getstack)(void *L, int level, lua_Debug *ar) = (void*) 0xFFFFFFCC;
int (*lua_getinfo)(void *L, const char *what, lua_Debug *ar) = (void*) 0xFFFFFFCC;
char *(*lua_getlocal)(void *L, const lua_Debug *ar, int n) = (void*) 0xFFFFFFCC;
char *(*lua_setlocal)(void *L, const lua_Debug *ar, int n) = (void*) 0xFFFFFFCC;
char *(*lua_getupvalue)(void *L, int funcindex, int n) = (void*) 0xFFFFFFCC;
char *(*lua_setupvalue)(void *L, int funcindex, int n) = (void*) 0xFFFFFFCC;
int (*lua_sethook)(void *L, lua_Hook func, int mask, int count) = (void*) 0xFFFFFFCC;
lua_Hook (*lua_gethook)(void *L) = (void*) 0xFFFFFFCC;
int (*lua_gethookmask)(void *L) = (void*) 0xFFFFFFCC;
int (*lua_gethookcount)(void *L) = (void*) 0xFFFFFFCC;
