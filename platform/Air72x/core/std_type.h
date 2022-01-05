#ifndef _STD_TYPE_G_
#define _STD_TYPE_G_

#define INT_MAX                   0x7fffffff

#define PRINTF(...) printf(__VA_ARGS__)
#define vfprintf(fd, ...) PRINTF(__VA_ARGS__)
#define assert(__e) ((__e) ? (void)0 : OPENAT_panic ())
#define ASSERT(cOND) {if (!(cOND)) {assert(__FILE__, (short)__LINE__);}}

#define exit(x) (OPENAT_panic ())
#define abort() (OPENAT_panic ())

typedef va_list  va_list;
#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)


#endif
