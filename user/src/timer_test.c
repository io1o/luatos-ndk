/*********************************************************
 * Copyright (C), AirM2M Tech. Co., Ltd.
 * Hezhou Data:timer_sample
 *
 * History:
 * Version     Date       Author       Notes
 * V0.1     2021-12-27    wang       the first version
 *********************************************************/
#include "core_api.h"


UINT8 cnt = 0;
HANDLE g_timer_handle_1 = NULL;
HANDLE g_timer_handle_2 = NULL;

/* ��ʱ��1��ʱ���� */
static void timeout_cb_1(void *param)
{
    OPENAT_lua_print("timer1 is timerout");
    OPENAT_lua_print("timer2 has been stopped!");
}

/* ��ʱ��2��ʱ���� */
static void timeout_cb_2(void *param)
{
    OPENAT_lua_print("timer2 is timerout:%d",++cnt);
    /* ѭ�����е�10�Σ�ֹͣ��ʱ�� */
    if (cnt > 9)
    {
        OPENAT_stop_timer(g_timer_handle_2);
        OPENAT_lua_print("timer2 has been stopped!");
    }
}

/*timerʾ��*/
int timer_sample(void)
{
    /* ������������ʱ��1*/
    if(g_timer_handle_1 == NULL){
        g_timer_handle_1 = OPENAT_create_timer(timeout_cb_1, NULL);

        if (g_timer_handle_1 != NULL){
              OPENAT_start_timer(g_timer_handle_1,2000);
              OPENAT_lua_print("timer1 is start!");
         }

    }

    /* ����������ѭ����ʱ��2*/
    if(g_timer_handle_2 == NULL){
        g_timer_handle_2 = OPENAT_create_timer(timeout_cb_2, NULL);

        if (g_timer_handle_2 != NULL){
          OPENAT_loop_start_timer(g_timer_handle_2,1000);
          OPENAT_lua_print("timer2 is start!");
        }
    }
    return 0;
}

/*lua������ں���*/
int test_timer(void *L)
{
    timer_sample();
    return 0;
}
