#include "core_api.h"


int helloworld(void *L)
{
	OPENAT_lua_print("ndk example:hello world!");
	return 0; //代表有0个返回值
}

luaL_Reg user_lib[] = {
	{"helloworld", helloworld},
	{NULL, NULL}};
	
/*入口函数*/
int user_main(void *L)
{
	/*C函数注册*/
	luaI_openlib(L, "user", user_lib, 0);
	return 1;
}
