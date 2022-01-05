#include "core_api.h"
#include "test.h"

extern int luaopen_cjson(void *l);

void test_print()
{
    OPENAT_lua_print("test_print is ok");
}

/*测试函数：封装lua库，供lua直接调用*/


int test_function(void *L)
{
    int str_size = 0;
    char temp[100];
    memset(temp,0,100);

    int num = luaL_checkinteger(L,1); //获取第一个参数,参数类型为number
    char *data = luaL_checklstring(L,2, &str_size); //获取第二个参数，参数类型为string

    test_print();

    sprintf(temp,"test user string param = %s %d",data,str_size);
    /*第一个返回值为字符串*/
    lua_pushlstring(L,temp, strlen(temp));
    /*第二个返回值为数值*/
    lua_pushnumber(L,1000); //压入参数
    /*第三个返回值为bool*/
    lua_pushboolean(L,1); //非0为true,0为false

    return 3; //代表有三个返回值
}

/*注意table作为返回值只能有一个*/
int test_table(void *L)
{
    lua_createtable(L,0,0);
    setfieldInt(L,"num",100);
    setfieldBool(L,"bool",0);
    setfieldString(L,"str","table return",strlen("table return"));
    return 1;
}

luaL_Reg user_lib[] = {
    {"test_function",test_function},
    {"test_table",test_table},

    {"test_fun3",test_fun3},
    {"test_fun4",test_fun4},
    {"test_uart",test_uart},
    {"test_task",test_task},
    {"test_timer",test_timer},
    {"test_msg",test_msg},

    {"test_light_led",test_light_led},
    {"send_msg_to_lua_test",send_msg_to_lua_test},
    {NULL,NULL}
};

/*入口函数*/
int user_main(void *L)
{
	/*C函数注册*/
	luaI_openlib(L, "user", user_lib, 0);

  /*其他初始化*/
  luaopen_cjson(L);

  return 1;
}
