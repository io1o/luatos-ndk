/*test.c*/
#include "core_api.h"
/*core 提供的接口, 后面NDK压缩包会有一个CORE_API包含所有CORE提供的接口*/

char buffer[50] = {0};

/*测试函数1，由lua直接调用*/
int fun3(int number)
{
    OPENAT_lua_print("fun3 exe number=%d", number);
    return number;
}

/*测试函数2, 由lua直接调用*/
char* fun4(char *string)
{
    OPENAT_lua_print("fun4 exe string=%s", string);
    fun3(10000);
    return string;
}

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

int send_msg_to_lua_test(void)
{
     bool reg = OPENAT_create_task(&task_handle, lua_msg_test_task, NULL, NULL,
                                      4 * 1024, 50,
                                      0,
                                      0,
                                      "lua_msg_test_task"); 
    return 1;
}