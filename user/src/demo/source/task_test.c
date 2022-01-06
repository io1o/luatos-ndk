/*********************************************************
 * Copyright (C), AirM2M Tech. Co., Ltd.
 * Hezhou Data:task_sample
 *
 * History:
 * Version     Date       Author       Notes
 * V0.1     2021-12-27    wang       the first version
 *********************************************************/
#include "core_api.h"


HANDLE g_task_handle_1 = NULL;
HANDLE g_task_handle_2 = NULL;


/* Task1����ں��� */
static void test_task1_entry(void *param)
{
    UINT32 count = 0;
    while(count < 1000)
    {
        OPENAT_sleep(500);
        OPENAT_lua_print("[lua_task] task1 count: %d", count++);

    }
}

/* Task2��� */
static void test_task2_entry(void *param)
{
    UINT8 count = 0;

    /* Task2��ռִ�� */
    for (count = 0; count < 10 ; count++)
    {
        OPENAT_lua_print("[lua_task] task2 count: %d", count);
    }
    OPENAT_lua_print("[lua_task] task2 exit");
}

/*Taskʾ��*/
int task_sample(void)
{
    if (NULL == g_task_handle_1)
    {
        /*��������1,������ΪTask1,�����ȼ�,��ں���task1_entry*/
        int res = OPENAT_create_task(&g_task_handle_1, test_task1_entry, NULL, NULL,
                           4*1024, 24,
                           OPENAT_OS_CREATE_DEFAULT,
                           0,
                           "test_Task1");

        OPENAT_lua_print("[lua_task] Test_task1 start run! res:%d",res);
    }

    if (NULL == g_task_handle_2)
    {
        /*��������2,������ΪTask2,�����ȼ�,��ں���task2_entry*/
        int res = OPENAT_create_task(&g_task_handle_2, test_task2_entry, NULL, NULL,
                           4*1024, 30,
                           OPENAT_OS_CREATE_DEFAULT,
                           0,
                           "test_Task2");
        OPENAT_lua_print("[lua_task] Test_task2 start run! res:%d",res);
    }
    return 1;
}

/*lua�������*/
int test_task(void* L)
{
    task_sample();
    return 0;
}
