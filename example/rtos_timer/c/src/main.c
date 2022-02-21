#include "core_api.h"

UINT8 cnt = 0;
HANDLE g_timer_handle_1 = NULL;
HANDLE g_timer_handle_2 = NULL;

/* 定时器1超时函数 */
static void timeout_cb_1(void *param)
{
    OPENAT_lua_print("timer1 is timerout");
    OPENAT_lua_print("timer2 has been stopped!");
}

/* 定时器2超时函数 */
static void timeout_cb_2(void *param)
{
    OPENAT_lua_print("timer2 is timerout:%d",++cnt);
    /* 循环运行第10次，停止定时器 */
    if (cnt > 9)
    {
        OPENAT_stop_timer(g_timer_handle_2);
        OPENAT_lua_print("timer2 has been stopped!");
    }
}

/*timer示例*/
int timer_sample(void)
{
    /* 创建并启动定时器1*/
    if(g_timer_handle_1 == NULL){
        g_timer_handle_1 = OPENAT_create_timer(timeout_cb_1, NULL);

        if (g_timer_handle_1 != NULL){
              OPENAT_start_timer(g_timer_handle_1,2000);
              OPENAT_lua_print("timer1 is start!");
         }

    }

    /* 创建并启动循环定时器2*/
    if(g_timer_handle_2 == NULL){
        g_timer_handle_2 = OPENAT_create_timer(timeout_cb_2, NULL);

        if (g_timer_handle_2 != NULL){
          OPENAT_loop_start_timer(g_timer_handle_2,1000);
          OPENAT_lua_print("timer2 is start!");
        }
    }
    return 0;
}

/*lua调用入口函数*/
int test_timer(void *L)
{
    timer_sample();
    return 0;
}



luaL_Reg user_lib[] = {
	{"test_timer",test_timer},
	{NULL, NULL}};
	
/*入口函数*/
int user_main(void *L)
{
	/*C函数注册*/
	luaI_openlib(L, "user", user_lib, 0);
	return 1;
}
