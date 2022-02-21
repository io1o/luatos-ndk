#ifndef RTTHREAD_H__
#define RTTHREAD_H__

#include "core_api.h"

#ifdef __cplusplus
extern "C" {
#endif

#define RT_USING_DFS
#define RT_USING_DEVICE
#define RT_TICK_PER_SECOND  100
#define RT_CONSOLEBUF_SIZE  256

#define RT_NULL          NULL
#define RT_ASSERT(EX)    

#define rt_vsnprintf        vsnprintf

typedef signed short ee_s16;
typedef unsigned short ee_u16;
typedef signed int ee_s32;
typedef double ee_f32;
typedef unsigned char ee_u8;
typedef unsigned int ee_u32;
typedef ee_u32 ee_ptr_int;
typedef unsigned int ee_size_t;
typedef unsigned int CORE_TICKS;
typedef unsigned int   rt_size_t;
typedef unsigned int rt_tick_t;
#define MEM_LOCATION "STACK"
#define COMPILER_VERSION "GCC"__VERSION__
#define COMPILER_FLAGS "" /* "Please put compiler flags here (e.g. -o3)" */
#define MSH_CMD_EXPORT(command, desc)
#define MAIN_HAS_NOARGC 1
#define MULTITHREAD 1
#define USE_PTHREAD 0
#define USE_FORK 0
#define USE_SOCKET 0
#define default_num_contexts MULTITHREAD 
#define rt_kprintf OPENAT_lua_print
#define ee_printf OPENAT_lua_print
#define rt_tick_get (unsigned int)OPENAT_get_system_tick
#define rt_malloc OPENAT_malloc
#define rt_free OPENAT_free
#define rt_hw_interrupt_disable 
#define rt_hw_interrupt_enable
#define time_in_secs(x) (x)
#define align_mem(x) (void *)(4 + (((ee_ptr_int)(x) - 1) & ~3))
#define core_portable int
#define portable_init
#define portable_fini
static unsigned int start_time_val = 0;
static unsigned int stop_time_val = 0;
static void start_time(void) {
	start_time_val =  rt_tick_get();
}
/* Function : stop_time
	This function will be called right after ending the timed portion of the benchmark.

	Implementation may be capturing a system timer (as implemented in the example code) 
	or other system parameters - e.g. reading the current value of cpu cycles counter.
*/
static void stop_time(void) {
	stop_time_val =  rt_tick_get();    
}
/* Function : get_time
	Return an abstract "ticks" number that signifies time on the system.
	
	Actual value returned may be cpu cycles, milliseconds or any other value,
	as long as it can be converted to seconds by <time_in_secs>.
	This methodology is taken to accomodate any hardware or simulated platform.
	The sample implementation returns millisecs by default, 
	and the resolution is controlled by <TIMER_RES_DIVIDER>
*/
#define MYTIMEDIFF(fin,ini) ((fin)-(ini))
static CORE_TICKS get_time(void) {
	CORE_TICKS elapsed=(CORE_TICKS)(MYTIMEDIFF(stop_time_val, start_time_val));
	
	return elapsed;
}
#ifdef __cplusplus
}
#endif

#endif
