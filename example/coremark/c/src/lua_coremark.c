#include "core_api.h"

int lua_coremask(void *L)
{
    extern int core_mark(void);
    core_mark();

    return 0;
}

luaL_Reg rtt_lib[] = {
    {"coremark",lua_coremask},
    {NULL, NULL}
};


