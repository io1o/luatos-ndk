#include "core_api.h"

int math_add(void *L)
{
	int num1 = luaL_checkinteger(L, 1); //获取第1个参数,参数类型为number
	int num2 = luaL_checkinteger(L, 2); //获取第2个参数,参数类型为number
	int result = num1 + num2;
	lua_pushnumber(L, result); //压入参数
	return 1;				   //代表有1个返回值
}

int math_sub(void *L)
{
	int num1 = luaL_checkinteger(L, 1); //获取第1个参数,参数类型为number
	int num2 = luaL_checkinteger(L, 2); //获取第2个参数,参数类型为number
	int result = num1 - num2;
	lua_pushnumber(L, result); //压入参数
	return 1;				   //代表有1个返回值
}

int math_mul(void *L)
{
	int num1 = luaL_checkinteger(L, 1); //获取第1个参数,参数类型为number
	int num2 = luaL_checkinteger(L, 2); //获取第2个参数,参数类型为number
	int result = num1 * num2;
	lua_pushnumber(L, result); //压入参数
	return 1;				   //代表有1个返回值
}

int math_div(void *L)
{
	int num1 = luaL_checkinteger(L, 1); //获取第1个参数,参数类型为number
	int num2 = luaL_checkinteger(L, 2); //获取第2个参数,参数类型为number
	int result = num1 / num2;
	lua_pushnumber(L, result); //压入参数
	return 1;				   //代表有1个返回值
}

luaL_Reg user_lib[] = {
	{"math_add", math_add},
	{"math_sub", math_sub},
	{"math_mul", math_mul},
	{"math_div", math_div},
	{NULL, NULL}};

/*入口函数*/
int user_main(void *L)
{
	/*C函数注册*/
	luaI_openlib(L, "user", user_lib, 0);
	return 1;
}
