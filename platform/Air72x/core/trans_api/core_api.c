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
void  (*OPENAT_assert)(                                           /* ���Խӿ� */
                            char condition,                     /* ���� */
                            char *func,                         /* �������� */
                            unsigned int line                   /* ���� */
                            ) = (void*) 0xFFFFFFFF;
INT64 (*OPENAT_get_system_tick)(                                   /* ��ȡϵͳtick�ӿ� */
                            VOID
                            ) = (void*) 0xFFFFFFFF;
double (*floor)(double) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_config_gpio)(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO��� */
                            T_AMOPENAT_GPIO_CFG *cfg            /* ��������� */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_set_gpio)(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO��� */
                            UINT8 value                         /* 0 or 1 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_read_gpio)(
                            E_AMOPENAT_GPIO_PORT port,          /* GPIO��� */
                            UINT8* value                        /* ��� 0 or 1 */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_close_gpio)(
                            E_AMOPENAT_GPIO_PORT port           /* GPIO��� */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_gpioPulse)(
                            E_AMOPENAT_GPIO_PORT port,
                            unsigned high_us,
                            unsigned low_us,
                            unsigned count,
                            unsigned idle
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_config_uart)(
                            E_AMOPENAT_UART_PORT port,          /* UART ��� */
                            T_AMOPENAT_UART_PARAM *cfg          /* ��ʼ������ */
                            ) = (void*) 0xFFFFFFFF;
UINT32 (*OPENAT_read_uart)(                                        /* ʵ�ʶ�ȡ���� */
                            E_AMOPENAT_UART_PORT port,          /* UART ��� */
                            UINT8* buf,                         /* �洢���ݵ�ַ */
                            UINT32 bufLen,                      /* �洢�ռ䳤�� */
                            UINT32 timeoutMs                    /* ��ȡ��ʱ ms */
                            ) = (void*) 0xFFFFFFFF;
UINT32 (*OPENAT_write_uart)(                                       /* ʵ��д�볤�� */
                            E_AMOPENAT_UART_PORT port,          /* UART ��� */
                            UINT8* buf,                         /* д�����ݵ�ַ */
                            UINT32 bufLen                       /* д�����ݳ��� */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_close_uart)(
                            E_AMOPENAT_UART_PORT port           /* UART ��� */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_create_task)(                                        /* �����߳̽ӿ� */
                            HANDLE* handlePtr,
                            PTASK_MAIN pTaskEntry,              /* �߳������� */
                            PVOID pParameter,                   /* ��Ϊ�������ݸ��߳������� */
                            PVOID pStackAddr,                   /* �߳�ջ��ַ����ǰ��֧�֣��봫��NULL */
                            UINT32 nStackSize,                  /* �߳�ջ��С */
                            UINT8 nPriority,                    /* �߳����ȼ����ò���Խ���߳����ȼ�Խ�� */
                            UINT16 nCreationFlags,              /* �߳�������ǣ� ��ο�E_AMOPENAT_OS_CREATION_FLAG */
                            UINT16 nTimeSlice,                  /* ��ʱ��֧�֣��봫��0 */
                            PCHAR pTaskName                     /* �߳����� */
                            ) = (void*) 0xFFFFFFFF;
VOID (*OPENAT_delete_task)(                                        /* ɾ���߳̽ӿ� */
                            HANDLE task
                            ) = (void*) 0xFFFFFFFF;
HANDLE (*OPENAT_current_task)(                                     /* ��ȡ��ǰ�߳̽ӿ� */
                            VOID
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_suspend_task)(                                       /* �����߳̽ӿ� */
                            HANDLE hTask                        /* �߳̾����create_task�ӿڷ���ֵ */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_resume_task)(                                        /* �ָ��߳̽ӿ� */
                            HANDLE hTask                        /* �߳̾����create_task�ӿڷ���ֵ */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_get_task_info)(                                      /* ��ȡ��ǰ�̴߳�����Ϣ�ӿ� */
                            HANDLE hTask,                       /* �߳̾����create_task�ӿڷ���ֵ */
                            T_AMOPENAT_TASK_INFO *pTaskInfo     /* �߳���Ϣ�洢�ӿ� */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_sleep)(                                              /* ϵͳ˯�߽ӿ� */
                            UINT32 nMillisecondes               /* ˯��ʱ�� */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_wait_message)(                                       /* �����ȴ���Ϣ�ӿ�*/
                            HANDLE task,
                            int* msg_id,
                            void* * ppMessage,
                            UINT32 nTimeOut
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_send_message)(                                       /* ������Ϣ�ӿڣ���ӵ���Ϣ����β�� */
                            HANDLE   destTask,
                            int msg_id,
                            void* pMessage,                     /* �洢��Ϣָ�� */
                            int message_length
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_SendHighPriorityMessage)(                            /* ���͸����ȼ���Ϣ�ӿڣ���ӵ���Ϣ����ͷ�� */
                            HANDLE   destTask,
                            int msg_id,
                            void* pMessage,                     /* �洢��Ϣָ�� */
                            int message_length
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_available_message)(                                  /* �����Ϣ�������Ƿ�����Ϣ */
                            HANDLE hTask                        /* �߳̾����create_task�ӿڷ���ֵ */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_send_internal_message)(                              /* ������Ϣ�ӿڣ���ӵ���Ϣ����β�� */
                            int msg_id,
                            void* pMessage,                     /* �洢��Ϣָ�� */
                            int message_length
                            ) = (void*) 0xFFFFFFFF;
HANDLE (*OPENAT_create_timer)(                                     /* ������ʱ���ӿ� */
                            PTIMER_EXPFUNC pFunc,               /* ��ʱ����ʱ������ */
                            PVOID pParameter                    /* ��Ϊ�������ݸ���ʱ����ʱ������ */
                            ) = (void*) 0xFFFFFFFF;
HANDLE (*OPENAT_create_timerTask)(                                 /* ������ʱ���ӿ� */
                            PTIMER_EXPFUNC pFunc,               /* ��ʱ����ʱ������ */
                            PVOID pParameter                    /* ��Ϊ�������ݸ���ʱ����ʱ������ */
                            ) = (void*) 0xFFFFFFFF;
HANDLE (*OPENAT_create_hir_timer)(                                 /* ������ʱ���ӿ� */
                            PTIMER_EXPFUNC pFunc,               /* ��ʱ����ʱ������ */
                            PVOID pParameter                    /* ��Ϊ�������ݸ���ʱ����ʱ������ */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_start_timer)(                                        /* ������ʱ���ӿ� */
                            HANDLE hTimer,                      /* ��ʱ�������create_timer�ӿڷ���ֵ */
                            UINT32 nMillisecondes               /* ��ʱ��ʱ�� */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_loop_start_timer)(                                   /* ����ѭ����ʱ���ӿ� */
                            HANDLE hTimer,                      /* ��ʱ�������create_timer�ӿڷ���ֵ */
                            UINT32 nMillisecondes               /* ��ʱ��ʱ�� */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_start_precise_timer)(                                /* ������ʱ���ӿ� */
                            HANDLE hTimer,                      /* ��ʱ�������create_timer�ӿڷ���ֵ */
                            UINT32 nMillisecondes               /* ��ʱ��ʱ�� */
                            ) = (void*) 0xFFFFFFFF;
BOOL (*OPENAT_stop_timer)(                                         /* ֹͣ��ʱ���ӿ� */
                            HANDLE hTimer                       /* ��ʱ�������create_timer�ӿڷ���ֵ */
                            ) = (void*) 0xFFFFFFFF;
UINT64 (*OPENAT_timer_remaining)(
                            HANDLE hTimer
                            ) = (void*) 0xFFFFFFFF;
void (*luaI_openlib)(void *L, const char *libname, const luaL_Reg *l, int nup) = (void*) 0xFFFFFFFF;
int (*luaL_optinteger)(void *L, int nArg, int def) = (void*) 0xFFFFFFFF;
lua_Number (*luaL_optnumber)(void *L, int nArg, lua_Number def) = (void*) 0xFFFFFFFF;
char *(*luaL_optlstring)(void *L,                           /*��ȡ���������û������Ĭ��ֵ*/
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
