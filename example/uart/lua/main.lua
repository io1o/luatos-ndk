-- 必须在这个位置定义PROJECT和VERSION变量
-- PROJECT：ascii string类型，可以随便定义，只要不使用,就行
-- VERSION：ascii string类型，如果使用Luat物联云平台固件升级的功能，必须按照"X.X.X"定义，X表示1位数字；否则可随便定义
PROJECT = "DL_TEST"
VERSION = "1.0.0"

-- 加载日志功能模块，并且设置日志输出等级
-- 如果关闭调用log模块接口输出的日志，等级设置为log.LOG_SILENT即可
require "log"
LOG_LEVEL = log.LOGLEVEL_TRACE
require "sys"
require "ril"

-- 打印死机信息
ril.request("AT*EXINFO?")
rtos.sleep(3000)
--[[
dl模块接口定义
函数：handle=dl.open(libpath,usermap)
功能：加载c编译的lib文件
  参数：
      --path:lib的路径,string类型
      --usermap:lua函数接口注册表
  返回值：
      --handle:成功返回句柄，失败返回nil

  函数： ret = dl.close(handle)
  功能：卸载lib
      参数：
          handle:dl.open的返回值
      返回值：nil
]]

-- 常规测试
sys.taskInit(function()
    local handle = dl.open("/lua/user.lib", "user_main")
    if handle then
        -- 添加测试demo
            sys.timerStart(user.test_uart,3000)
    end
end)

-- 启动系统框架
sys.init(0, 0)
sys.run()
