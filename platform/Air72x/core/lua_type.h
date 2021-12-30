#ifndef _LUA_TYPE_H_
#define _LUA_TYPE_H_


#define LUA_IDSIZE	60

/* type of numbers in Lua */
typedef long lua_Number;
/* type for integer functions */
typedef long lua_Integer;


typedef int (*lua_CFunction) (void *L);
typedef const char * (*lua_Reader) (void *L, void *ud, size_t *sz);
typedef int (*lua_Writer) (void *L, const void* p, size_t sz, void* ud);
typedef void * (*lua_Alloc) (void *ud, void *ptr, size_t osize, size_t nsize);
typedef struct lua_Debug lua_Debug;  /* activation record */
/* Functions to be called by the debuger in specific events */
typedef void (*lua_Hook) (void *L, lua_Debug *ar);

typedef struct luaL_Reg {
  const char *name;
  lua_CFunction func;
} luaL_Reg;

struct lua_Debug {
  int event;
  const char *name;	/* (n) */
  const char *namewhat;	/* (n) `global', `local', `field', `method' */
  const char *what;	/* (S) `Lua', `C', `main', `tail' */
  const char *source;	/* (S) */
  int currentline;	/* (l) */
  int nups;		/* (u) number of upvalues */
  int linedefined;	/* (S) */
  int lastlinedefined;	/* (S) */
  char short_src[LUA_IDSIZE]; /* (S) */
  /* private part */
  int i_ci;  /* active function */
};

#endif
