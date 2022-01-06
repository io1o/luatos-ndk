#ifndef _STD_TYPE_G_
#define _STD_TYPE_G_

#define INT_MAX                   0x7fffffff

typedef va_list  va_list;
#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)


#endif
