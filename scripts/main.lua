--必须在这个位置定义PROJECT和VERSION变量
--PROJECT：ascii string类型，可以随便定义，只要不使用,就行
--VERSION：ascii string类型，如果使用Luat物联云平台固件升级的功能，必须按照"X.X.X"定义，X表示1位数字；否则可随便定义
PROJECT = "DL_TEST"
VERSION = "1.0.0"

--加载日志功能模块，并且设置日志输出等级
--如果关闭调用log模块接口输出的日志，等级设置为log.LOG_SILENT即可
require "log"
LOG_LEVEL = log.LOGLEVEL_TRACE
require "sys"

rtos.sleep(3000)
--[[
dl模块接口定义
函数：handle=dl.open(libpath) 
功能：加载c编译的lib文件
参数：
    --path:lib的路径,string类型
返回值：
    --handle:成功返回句柄，失败返回nil
    
函数： ret = dl.sym(handle,fun,ret_type,arg1,arg2,arg3....) 
功能：运行c函数
    参数：
        handle:dl.open的返回值
        fun:c函数名
        ret_type:c接口的返回值dl.RETURN_NUMBER(可以返回一个bool，int, 句柄等)
                             dl.RETURN_STRING(返回一个字符串)
        arg1-arg10:c函数的参数，可以是number类型和string类型
    返回值：
        ret:更加ret_type类型返回number或者string    
        
 函数： ret = dl.close(handle)
 功能：卸载lib
    参数：
        handle:dl.open的返回值
    返回值：nil    
]]
local handle = dl.open("/lua/user.lib")
if handle then  
    local ret_number = dl.sym(handle, "uart_test", 1)

    local ret_number1 = dl.sym(handle, "fun3", 1, 40)
    local ret_string1 = dl.sym(handle, "fun4", 2, "world")
    dl.sym(handle, "send_msg_to_lua_test", 1)

    print("ret_number", ret_number);
    print("ret_string", ret_string);
    print("ret_number1", ret_number1);
    print("ret_string1", ret_string1);
    
    --dl.close(handle)
end

local function dl_msg_pro(msg)
    print(msg.msg,msg.num,msg.data,msg.result)
end

rtos.on(rtos.MSG_DL_INFO, dl_msg_pro)

--启动系统框架
sys.init(0, 0)
sys.run()
