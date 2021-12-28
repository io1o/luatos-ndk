/*********************************************************
 * Copyright (C), AirM2M Tech. Co., Ltd.
 * Hezhou Data:task_sample
 *
 * History:
 * Version     Date       Author       Notes
 * V0.1     2021-12-27    wangzm       the first version
 *********************************************************/
#include "core_api.h"


HANDLE g_task_handle_1 = NULL;
HANDLE g_task_handle_2 = NULL;


/* Task1的入口函数 */
static void task1_entry(void *param)
{
    UINT32 count = 0;
    while(count < 1000)
    {
        OPENAT_sleep(500);
        OPENAT_lua_print("[lua_task] task1 count: %d", count++);

    }
}

/* Task2入口 */
static void task2_entry(void *param)
{
    UINT8 count = 0;

    /* Task2抢占执行 */
    for (count = 0; count < 10 ; count++)
    {
        OPENAT_lua_print("[lua_task] task2 count: %d", count);
    }
    OPENAT_lua_print("[lua_task] task2 exit");
}

/*Task示例*/
int task_sample(void)
{
    if (NULL == g_task_handle_1)
    {
        /*创建任务1,任务名为Task1,低优先级,入口函数task1_entry*/
        OPENAT_create_task(&g_task_handle_1, task1_entry, NULL, NULL,
                          4*1024, 24,
                           OPENAT_OS_CREATE_DEFAULT,
                           0,
                           "Task1");
        OPENAT_lua_print("[lua_task] Test_task1 start run!");
    }

    if (NULL == g_task_handle_2)
    {
        /*创建任务2,任务名为Task2,高优先级,入口函数task2_entry*/
        OPENAT_create_task(&g_task_handle_2, task2_entry, NULL, NULL,
                           4*1024, 30,
                           OPENAT_OS_CREATE_DEFAULT,
                           0,
                           "Task2");
        OPENAT_lua_print("[lua_task] Test_task2 start run!");
    }
    return 1;
}

/*lua调用入口*/
int test_task(void)
{
    task_sample();
    return 1;
}
