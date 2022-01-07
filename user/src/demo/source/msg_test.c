/*********************************************************
 * Copyright (C), AirM2M Tech. Co., Ltd.
 * Hezhou Data:msg_sample
 *
 * History:
 * Version     Date       Author       Notes
 * V0.1     2021-12-27    wang       the first version
 *********************************************************/
#include "core_api.h"


typedef enum
{
    EVT_TIMER_REQ,
    EVT_TIMER_REMAINING,
    EVT_TIMER_EXPIRY,
    EVT_MAX
}sTimerEvent;

typedef struct
{
    sTimerEvent evt;
    union
    {
        PdGpioStartIntTimerReq timereq;
        pdgpioTimerExpiry timerexpiry;
    }para;
}sMsgBuff,*pMsgBuff;

static INT16 period;
HANDLE g_msg_handle_1 = NULL;
HANDLE g_msg_handle_2 = NULL;
HANDLE g_timer_handle = NULL;

/*定时器超时处理*/
void timeout_callback(void *param)
{
    sMsgBuff msgBuff;
    msgBuff.evt = EVT_TIMER_EXPIRY;
    msgBuff.para.timerexpiry.timerId = *((INT32*)param);
    msgBuff.para.timerexpiry.userValue = 0;
    OPENAT_send_message(g_msg_handle_1, 2, &msgBuff, sizeof(pMsgBuff));
}

/* Task1入口函数 */
static void test_msg_task1_entry(void *param)
{
    char buf = 0;
    UINT8 cnt = 0;
    int msgId;
    pMsgBuff msg;

    while (1)
    {
        /* 阻塞等待消息到来 */
        OPENAT_wait_message(g_msg_handle_1, &msgId, (void* *)&msg, OPENAT_OS_SUSPENDED);
        OPENAT_lua_print("Task1 recvmsg, msgId:%d, event:%d", msgId, msg->evt);
        switch(msg->evt)
        {
          case EVT_TIMER_REQ:
          {
            /* 创建并启动定时器*/
            if (g_timer_handle == NULL)
            {
              g_timer_handle = OPENAT_create_timer(timeout_callback, &msg->para.timereq.timerId);
              OPENAT_lua_print("period:%d",msg->para.timereq.period);
              if (g_timer_handle != NULL)
                OPENAT_start_timer(g_timer_handle, msg->para.timereq.period);
            }
            break;
          }
          case EVT_TIMER_REMAINING:
          {
            UINT32 remTime = (UINT32)OPENAT_timer_remaining(g_timer_handle);
            OPENAT_lua_print("Timer has %d milliseconds left",remTime);
            OPENAT_send_message(g_msg_handle_2, 1, &remTime, sizeof(UINT32));
            break;
          }
          case EVT_TIMER_EXPIRY:
          {
            OPENAT_lua_print("Timer has been timerout!");
            break;
          }
          default:break;
        }
        if(msg->evt==EVT_TIMER_EXPIRY){
            OPENAT_lua_print("Task1 has been exit!");
            break;
        }
    }
}

/* Task2入口函数 */
static void test_msg_task2_entry(void *param)
{
    sMsgBuff msgBuff;
    msgBuff.evt = EVT_TIMER_REQ;
    msgBuff.para.timereq.timerId = 0;
    msgBuff.para.timereq.period = period;

    int msgId;
    UINT32 *remTime=NULL;
    /* 发送消息到task1消息队列中 */
    OPENAT_sleep(1000);
    OPENAT_send_message(g_msg_handle_1, 0, &msgBuff, sizeof(sMsgBuff));
    while (1)
    {
      OPENAT_sleep(1000);
      msgBuff.evt = EVT_TIMER_REMAINING;
      OPENAT_send_message(g_msg_handle_1, 1, &msgBuff, sizeof(sMsgBuff));

      OPENAT_wait_message(g_msg_handle_2, &msgId, (void **)&remTime, OPENAT_OS_SUSPENDED);
      if (*remTime == 0)
      {
            OPENAT_lua_print("Task2 has been exit!");
            break;
      }
    }
}

/*msg示例*/
static int msg_sample(INT16 number)
{
    period = number;
    if (NULL == g_msg_handle_1)
    {
        /*创建任务1,任务名为Task1,入口函数task1_entry*/
        OPENAT_create_task(&g_msg_handle_1, test_msg_task1_entry, NULL, NULL,
                           4 * 1024, 24,
                           OPENAT_OS_CREATE_DEFAULT,
                           0,
                           "msg_Task1");
    }

    if (NULL == g_msg_handle_2)
    {
        /*创建任务2,任务名为Task2,入口函数task2_entry*/
        OPENAT_create_task(&g_msg_handle_2, test_msg_task2_entry, NULL, NULL,
                           4 * 1024, 24,
                           OPENAT_OS_CREATE_DEFAULT,
                           0,
                           "msg_Task2");
    }
    return 0;
}

/*lua调用入口函数*/
int test_msg(void *L)
{
    lua_Number num = luaL_checknumber(L,1); //获取第一个参数,参数类型为number
    OPENAT_lua_print("period num:%d",num);
    msg_sample(num);
    return 0;
}
