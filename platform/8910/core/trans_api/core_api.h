#include "cs_types.h"
#include "am_openat_drv.h"
#include "am_openat_system.h"
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
                            E_AMOPENAT_GPIO_PORT port,  /* GPIO��� */
                            T_AMOPENAT_GPIO_CFG *cfg    /* ��������� */
                       );
extern BOOL (*OPENAT_set_gpio)(                               
                            E_AMOPENAT_GPIO_PORT port,  /* GPIO��� */
                            UINT8 value                 /* 0 or 1 */
                    );
extern BOOL (*OPENAT_read_gpio)(                            
                            E_AMOPENAT_GPIO_PORT port,  /* GPIO��� */
                            UINT8* value                /* ��� 0 or 1 */
                      );
extern BOOL (*OPENAT_close_gpio)(                            
                            E_AMOPENAT_GPIO_PORT port/* GPIO��� */
                      );
extern BOOL (*OPENAT_gpioPulse)(E_AMOPENAT_GPIO_PORT port, unsigned high_us, unsigned low_us, unsigned count, unsigned idle);
extern BOOL (*OPENAT_config_uart)(
                            E_AMOPENAT_UART_PORT port,          /* UART ��� */
                            T_AMOPENAT_UART_PARAM *cfg          /* ��ʼ������ */
                       );
extern BOOL (*OPENAT_close_uart)(
                            E_AMOPENAT_UART_PORT port           /* UART ��� */
                       );
extern UINT32 (*OPENAT_read_uart)(                                        /* ʵ�ʶ�ȡ���� */
                            E_AMOPENAT_UART_PORT port,          /* UART ��� */
                            UINT8* buf,                         /* �洢���ݵ�ַ */
                            UINT32 bufLen,                      /* �洢�ռ䳤�� */
                            UINT32 timeoutMs                    /* ��ȡ��ʱ ms */
                       );
extern UINT32 (*OPENAT_write_uart)(                                       /* ʵ��д�볤�� */
                            E_AMOPENAT_UART_PORT port,          /* UART ��� */
                            UINT8* buf,                         /* д�����ݵ�ַ */
                            UINT32 bufLen                       /* д�����ݳ��� */
                        );
extern BOOL (*OPENAT_create_task)(                          /* �����߳̽ӿ� */
                            HANDLE* handlePtr,
                            PTASK_MAIN pTaskEntry,  /* �߳������� */
                            PVOID pParameter,       /* ��Ϊ�������ݸ��߳������� */
                            PVOID pStackAddr,       /* �߳�ջ��ַ����ǰ��֧�֣��봫��NULL */
                            UINT32 nStackSize,      /* �߳�ջ��С */
                            UINT8 nPriority,        /* �߳����ȼ����ò���Խ���߳����ȼ�Խ�� */
                            UINT16 nCreationFlags,  /* �߳�������ǣ� ��ο�E_AMOPENAT_OS_CREATION_FLAG */
                            UINT16 nTimeSlice,      /* ��ʱ��֧�֣��봫��0 */
                            PCHAR pTaskName         /* �߳����� */
                          );
extern VOID (*OPENAT_delete_task)(HANDLE         task);
extern HANDLE (*OPENAT_current_task)(                         /* ��ȡ��ǰ�߳̽ӿ� */
                            VOID
                          );
extern BOOL (*OPENAT_suspend_task)(                           /* �����߳̽ӿ� */
    HANDLE hTask            /* �߳̾����create_task�ӿڷ���ֵ */
);
extern BOOL (*OPENAT_resume_task)(                            /* �ָ��߳̽ӿ� */
    HANDLE hTask            /* �߳̾����create_task�ӿڷ���ֵ */
);
extern BOOL (*OPENAT_get_task_info)(                          /* ��ȡ��ǰ�̴߳�����Ϣ�ӿ� */
                            HANDLE hTask,           /* �߳̾����create_task�ӿڷ���ֵ */
                            T_AMOPENAT_TASK_INFO *pTaskInfo /* �߳���Ϣ�洢�ӿ� */
                         );
extern BOOL (*OPENAT_wait_message)(
                                     HANDLE   task,
                                     int* msg_id,
                                     void* * ppMessage,
                                     UINT32 nTimeOut
                                     );
extern BOOL (*OPENAT_send_message)(                           /* ������Ϣ�ӿڣ���ӵ���Ϣ����β�� */
                                      HANDLE   destTask,
                                      int msg_id,
                                      void* pMessage,          /* �洢��Ϣָ�� */
                                      int message_length);
extern BOOL (*OPENAT_SendHighPriorityMessage)(			   /* ���͸����ȼ���Ϣ�ӿڣ���ӵ���Ϣ����ͷ�� */
											  HANDLE   destTask,
											  int msg_id,
											  void* pMessage,		   /* �洢��Ϣָ�� */
											  int message_length);
extern BOOL (*OPENAT_available_message)(                      /* �����Ϣ�������Ƿ�����Ϣ */
                            HANDLE hTask            /* �߳̾����create_task�ӿڷ���ֵ */
                             );
extern BOOL (*OPENAT_send_internal_message)(                           /* ������Ϣ�ӿڣ���ӵ���Ϣ����β�� */
                                      int msg_id,
                                      void* pMessage,          /* �洢��Ϣָ�� */
                                      int message_length
                                      );
extern BOOL (*OPENAT_sleep)(                                  /* ϵͳ˯�߽ӿ� */
                            UINT32 nMillisecondes   /* ˯��ʱ�� */
                 );
extern HANDLE (*OPENAT_create_timer)(                         /* ������ʱ���ӿ� */
                            PTIMER_EXPFUNC pFunc,   /* ��ʱ����ʱ������ */
                            PVOID pParameter        /* ��Ϊ�������ݸ���ʱ����ʱ������ */
                          );
extern HANDLE (*OPENAT_create_timerTask)(                         /* ������ʱ���ӿ� */
                            PTIMER_EXPFUNC pFunc,   /* ��ʱ����ʱ������ */
                            PVOID pParameter        /* ��Ϊ�������ݸ���ʱ����ʱ������ */
                          );
extern HANDLE (*OPENAT_create_hir_timer)(						/* ������ʱ���ӿ� */
						PTIMER_EXPFUNC pFunc,	/* ��ʱ����ʱ������ */
						PVOID pParameter		/* ��Ϊ�������ݸ���ʱ����ʱ������ */
					  );
extern BOOL (*OPENAT_start_timer)(                            /* ������ʱ���ӿ� */
                            HANDLE hTimer,          /* ��ʱ�������create_timer�ӿڷ���ֵ */
                            UINT32 nMillisecondes   /* ��ʱ��ʱ�� */
                       );
extern BOOL (*OPENAT_loop_start_timer)(                            /* ����ѭ����ʱ���ӿ� */
                            HANDLE hTimer,          /* ��ʱ�������create_timer�ӿڷ���ֵ */
                            UINT32 nMillisecondes   /* ��ʱ��ʱ�� */
                       );
extern BOOL (*OPENAT_start_precise_timer)(                            /* ������ʱ���ӿ� */
                            HANDLE hTimer,          /* ��ʱ�������create_timer�ӿڷ���ֵ */
                            UINT32 nMillisecondes   /* ��ʱ��ʱ�� */
                       );
extern BOOL (*OPENAT_stop_timer)(                             /* ֹͣ��ʱ���ӿ� */
                            HANDLE hTimer           /* ��ʱ�������create_timer�ӿڷ���ֵ */
                      );
extern UINT64 (*OPENAT_timer_remaining)(
							HANDLE hTimer
						);
