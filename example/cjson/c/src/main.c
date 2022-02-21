#include "core_api.h"

extern int luaopen_cjson(void *l);

/*入口函数*/
int user_main(void *L)
{
    /*其他初始化*/
    luaopen_cjson(L);

  return 1;
}
