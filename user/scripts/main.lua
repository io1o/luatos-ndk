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

local function common_test()
  local handle = dl.open("/lua/user.lib","user_main")
  if handle then
      --添加测试demo
      local ret_number = user.test_fun3(21)
      local ret_string = user.test_fun4(21,"test")
      local ret1,ret2,ret3 = user.test_function(1000,"123456789")
      local t = user.test_table()

      print("ret_number", ret_number);
      print("ret_string", ret_string);
      print("ret1_string",ret1)
      print("ret2_number",ret2)
      print("ret3_boolean",ret3)
      print("table return: ",t.num,t.str,t.bool)

      print("---------------------")

      -- user.test_uart()
      -- user.send_msg_to_lua_test()
      -- user.test_msg(10000)
      -- user.test_timer()
      -- user.test_task()
      -- 点亮LTE灯,uart2发lightLED:2,1,10,启动LED,亮2秒，灭1秒，闪10次
      -- pmd.ldoset(1,pmd.LDO_VLCD)
      -- user.test_light_led()

      -- local a,b,c = user.test_function(1000,"123456789")
      -- local t = user.test_table()
      -- print("!!!!!!!!!! ",a,b,c)
      -- print("table return: ",t.num,t.str,t.bool)
      -- dl.close(handle1)
  end
end

-- 常规测试
common_test()
-- cjson测试
require "testJson"

local function dl_msg_pro(msg)
    print(msg.msg,msg.num,msg.data,msg.result)
end

rtos.on(rtos.MSG_DL_INFO, dl_msg_pro)

--启动系统框架
sys.init(0, 0)
sys.run()
