VERSION = "1.0.0"
PROJECT = "DL_TEST"
--������־����ģ�飬����������־����ȼ�
--����رյ���logģ��ӿ��������־���ȼ�����Ϊlog.LOG_SILENT����
require "log"
LOG_LEVEL = log.LOGLEVEL_TRACE
require "sys"

--�Ӹ��ӳٷ�ֹ����̫��log��ʧ
rtos.sleep(1000)
--ͨ��dl.open�ӿڼ���user.lib�ļ�����ִ��user_main��ں���
--user_main��ں�����ע��rtt coremark��Ȼ��ʹ��rtt.coremark()���нӿڵ���
local handle = dl.open("/lua/user.lib","user_main")
if handle then  
    print("dl ready")
end
require"testJson"
--����ϵͳ���
sys.init(0, 0)
sys.run()