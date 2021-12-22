#include "cs_types.h"
#include "am_openat_drv.h"
#include "am_openat_system.h"
#include "lua_type.h"
extern void (*OPENAT_lua_print)(char * fmt,
...);
extern bool (*OPENAT_msg_to_lua)(UINT8 msg_id,BOOL result,INT32 num,CHAR* data,UINT32 dataLen);
extern char *(*strstr)(const char *, const char *);
extern size_t	(*strlen)(const char *);
extern char *(*strchr)(const char *,int);
extern char *(*strcpy)(char *,const char *);
extern char *(*strncpy)(char *,const char *, size_t);
extern int (*strcmp)(const char *,const char *);
extern int (*strncmp)(const char *,const char *,size_t);
extern char 	*(*strcat)(char *__restrict, const char *__restrict);
extern void *	(*memcpy)(void *__restrict, const void *__restrict, size_t);
extern int 	(*memcmp)(const void *, const void *, size_t);
extern void *	(*memmove)(void *, const void *, size_t);
extern void *	(*memset)(void *, int, size_t);
extern void *	(*memchr)(const void *, int, size_t);
extern void *(*OPENAT_malloc)(size_t size);
extern void (*OPENAT_free)(void *ptr);
extern int (*sprintf)(char *, const char *, ...);
extern int (*snprintf)(char * buf, size_t len, const char *fmt, ...);
extern int (*sscanf)(const char * buf, const char * fmt, ...);
extern BOOL (*OPENAT_config_gpio)(                          
                            E_AMOPENAT_GPIO_PORT port,  /* GPIO编号 */
                            T_AMOPENAT_GPIO_CFG *cfg    /* 输出或输入 */
                       );
extern BOOL (*OPENAT_set_gpio)(                               
                            E_AMOPENAT_GPIO_PORT port,  /* GPIO编号 */
                            UINT8 value                 /* 0 or 1 */
                    );
extern BOOL (*OPENAT_read_gpio)(                            
                            E_AMOPENAT_GPIO_PORT port,  /* GPIO编号 */
                            UINT8* value                /* 结果 0 or 1 */
                      );
extern BOOL (*OPENAT_close_gpio)(                            
                            E_AMOPENAT_GPIO_PORT port/* GPIO编号 */
                      );
extern BOOL (*OPENAT_gpioPulse)(E_AMOPENAT_GPIO_PORT port, unsigned high_us, unsigned low_us, unsigned count, unsigned idle);
extern BOOL (*OPENAT_config_uart)(
                            E_AMOPENAT_UART_PORT port,          /* UART 编号 */
                            T_AMOPENAT_UART_PARAM *cfg          /* 初始化参数 */
                       );
extern BOOL (*OPENAT_close_uart)(
                            E_AMOPENAT_UART_PORT port           /* UART 编号 */
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
extern BOOL (*OPENAT_create_task)(                          /* 创建线程接口 */
                            HANDLE* handlePtr,
                            PTASK_MAIN pTaskEntry,  /* 线程主函数 */
                            PVOID pParameter,       /* 作为参数传递给线程主函数 */
                            PVOID pStackAddr,       /* 线程栈地址，当前不支持，请传入NULL */
                            UINT32 nStackSize,      /* 线程栈大小 */
                            UINT8 nPriority,        /* 线程优先级，该参数越大，线程优先级越低 */
                            UINT16 nCreationFlags,  /* 线程启动标记， 请参考E_AMOPENAT_OS_CREATION_FLAG */
                            UINT16 nTimeSlice,      /* 暂时不支持，请传入0 */
                            PCHAR pTaskName         /* 线程名称 */
                          );
extern VOID (*OPENAT_delete_task)(HANDLE         task);
extern HANDLE (*OPENAT_current_task)(                         /* 获取当前线程接口 */
                            VOID
                          );
extern BOOL (*OPENAT_suspend_task)(                           /* 挂起线程接口 */
    HANDLE hTask            /* 线程句柄，create_task接口返回值 */
);
extern BOOL (*OPENAT_resume_task)(                            /* 恢复线程接口 */
    HANDLE hTask            /* 线程句柄，create_task接口返回值 */
);
extern BOOL (*OPENAT_get_task_info)(                          /* 获取当前线程创建信息接口 */
                            HANDLE hTask,           /* 线程句柄，create_task接口返回值 */
                            T_AMOPENAT_TASK_INFO *pTaskInfo /* 线程信息存储接口 */
                         );
extern BOOL (*OPENAT_wait_message)(
                                     HANDLE   task,
                                     int* msg_id,
                                     void* * ppMessage,
                                     UINT32 nTimeOut
                                     );
extern BOOL (*OPENAT_send_message)(                           /* 发送消息接口，添加到消息队列尾部 */
                                      HANDLE   destTask,
                                      int msg_id,
                                      void* pMessage,          /* 存储消息指针 */
                                      int message_length);
extern BOOL (*OPENAT_SendHighPriorityMessage)(			   /* 发送高优先级消息接口，添加到消息队列头部 */
											  HANDLE   destTask,
											  int msg_id,
											  void* pMessage,		   /* 存储消息指针 */
											  int message_length);
extern BOOL (*OPENAT_available_message)(                      /* 检测消息队列中是否有消息 */
                            HANDLE hTask            /* 线程句柄，create_task接口返回值 */
                             );
extern BOOL (*OPENAT_send_internal_message)(                           /* 发送消息接口，添加到消息队列尾部 */
                                      int msg_id,
                                      void* pMessage,          /* 存储消息指针 */
                                      int message_length
                                      );
extern BOOL (*OPENAT_sleep)(                                  /* 系统睡眠接口 */
                            UINT32 nMillisecondes   /* 睡眠时间 */
                 );
extern HANDLE (*OPENAT_create_timer)(                         /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,   /* 定时器到时处理函数 */
                            PVOID pParameter        /* 作为参数传递给定时器到时处理函数 */
                          );
extern HANDLE (*OPENAT_create_timerTask)(                         /* 创建定时器接口 */
                            PTIMER_EXPFUNC pFunc,   /* 定时器到时处理函数 */
                            PVOID pParameter        /* 作为参数传递给定时器到时处理函数 */
                          );
extern HANDLE (*OPENAT_create_hir_timer)(						/* 创建定时器接口 */
						PTIMER_EXPFUNC pFunc,	/* 定时器到时处理函数 */
						PVOID pParameter		/* 作为参数传递给定时器到时处理函数 */
					  );
extern BOOL (*OPENAT_start_timer)(                            /* 启动定时器接口 */
                            HANDLE hTimer,          /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes   /* 定时器时间 */
                       );
extern BOOL (*OPENAT_loop_start_timer)(                            /* 启动循环定时器接口 */
                            HANDLE hTimer,          /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes   /* 定时器时间 */
                       );
extern BOOL (*OPENAT_start_precise_timer)(                            /* 启动定时器接口 */
                            HANDLE hTimer,          /* 定时器句柄，create_timer接口返回值 */
                            UINT32 nMillisecondes   /* 定时器时间 */
                       );
extern BOOL (*OPENAT_stop_timer)(                             /* 停止定时器接口 */
                            HANDLE hTimer           /* 定时器句柄，create_timer接口返回值 */
                      );
extern UINT64 (*OPENAT_timer_remaining)(
							HANDLE hTimer
						);
extern int (*lua_gettop)(void *L);
extern int (*luaL_optinteger)(void *L, int narg, int def);
extern char *(*luaL_checklstring)(void *L, int numArg,
                                                          size_t *l);
extern char *(*luaL_optlstring)(void *L, int numArg,
                                          const char *def, size_t *l);
extern long (*luaL_checknumber)(void *L, int numArg);
extern long (*luaL_optnumber)(void *L, int nArg, long def);
extern int (*luaL_checkinteger)(void *L, int numArg);
extern void (*luaL_checktype)(void *L, int narg, int t);
extern void (*lua_createtable)(void *L, int narray, int nrec);
extern void (*setfieldInt)(void *L, const char *key, int value);
extern void (*setfieldBool)(void *L, const char *key, int value);
extern void (*setfieldString)(void* L, const char* key, const char* str, const size_t len);
extern void (*lua_pushinteger)(void *L, int n);
extern void (*lua_pushlstring)(void *L, const char *s, size_t len);
extern void (*lua_pushnumber)(void *L, long n);
extern void (*lua_pushboolean)(void *L, int b);
extern void (*lua_gettable)(void *L, int idx);
extern int (*lua_isnumber)(void *L, int idx);
extern int (*lua_isstring)(void *L, int idx);
extern int (*lua_iscfunction)(void *L, int idx);
extern char *(*lua_typename)(void *L, int t);
