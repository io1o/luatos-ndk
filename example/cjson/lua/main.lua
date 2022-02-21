VERSION = "1.0.0"
PROJECT = "DL_TEST"
--加载日志功能模块，并且设置日志输出等级
--如果关闭调用log模块接口输出的日志，等级设置为log.LOG_SILENT即可
require "log"
LOG_LEVEL = log.LOGLEVEL_TRACE
require "sys"

--加个延迟防止开机太快log丢失
rtos.sleep(1000)
--通过dl.open接口加载user.lib文件，并执行user_main入口函数
--user_main入口函数会注册rtt coremark，然后使用rtt.coremark()进行接口调用
local handle = dl.open("/lua/user.lib","user_main")
if handle then  
    print("dl ready")
end
require"testJson"
--启动系统框架
sys.init(0, 0)
sys.run()