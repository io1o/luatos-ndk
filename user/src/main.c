#include "core_api.h"

extern luaL_Reg user_lib[];
extern int luaopen_cjson(void *l);

/*入口函数*/
int user_main(void *L)
{
    /*C函数注册*/
    luaI_openlib(L, "user", user_lib, 0);

    /*其他初始化*/
    luaopen_cjson(L);

  return 1;
}
