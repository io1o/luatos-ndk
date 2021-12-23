#ifndef _LUA_TYPE_H_
#define _LUA_TYPE_H_



typedef int (*lua_CFunction) (void *L);

typedef struct luaL_Reg {
  const char *name;
  lua_CFunction func;
} luaL_Reg;



#endif
