#include "core_api.h"

extern luaL_Reg rtt_lib[];

/*入口函数*/
int user_main(void *L)
{
    /*其他初始化*/
    luaI_openlib(L, "rtt", rtt_lib, 0);

  return 1;
}
