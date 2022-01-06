/*********************************************************
 * Copyright (C), AirM2M Tech. Co., Ltd.
 * Hezhou Data:os_sample
 *
 * History:
 * Version     Date       Author       Notes
 * V0.1     2021-12-27    wang       the first version
 *********************************************************/
#include "core_api.h"
/*core 提供的接口, 后面NDK压缩包会有一个CORE_API包含所有CORE提供的接口*/

char buffer[50] = {0};

/*测试函数1，由lua直接调用*/
int test_fun3(void *L)
{
    /*获取第一个参数,参数类型为number*/
    lua_Number number = luaL_checknumber(L,1);
    if (sizeof(lua_Number) == 8){
      OPENAT_lua_print("fun3 exe number=%lf  %d", number, sizeof(lua_Number));
    }
    else{
      OPENAT_lua_print("fun3 exe number=%d  %d", number, sizeof(lua_Number));
    }

    /*第一个返回值为数值*/
    lua_pushnumber(L,number);
    return 1;
}

/*测试函数2, 由lua直接调用*/
int test_fun4(void *L)
{
    int str_size = 0;
    /*获取第一个参数,参数类型为string*/
    char *data = luaL_checklstring(L,2, &str_size);
    OPENAT_lua_print("fun4 exe string=%s", data);

    /*第一个返回值为字符串*/
    lua_pushstring(L,data);
    return 1;
}

/*测试函数：建立task并不断发送消息给lua虚拟机*/
HANDLE task_handle = 0;

void lua_msg_test_task(void *pParameter)
{
    int i = 0;
    while(1)
    {
        OPENAT_sleep(1000);


        OPENAT_msg_to_lua(1,TRUE,i,"send_msg_to_lua_test",strlen("send_msg_to_lua_test"));

        i++;
    }
}

int send_msg_to_lua_test(void *L)
{
    bool reg = OPENAT_create_task(&task_handle, lua_msg_test_task, NULL, NULL,
                                  4 * 1024, 50,
                                  0,
                                  0,
                                  "lua_msg_test_task");
    return 0;
}

