/*********************************************************
 * Copyright (C), AirM2M Tech. Co., Ltd.
 * Hezhou Data:lightled_sample
 *
 * History:
 * Version     Date       Author       Notes
 * V0.1     2021-12-27    wangzm       the first version
 *********************************************************/
#include "core_api.h"


UINT8 uartRxBuff[512];
struct PWM_CFG
{
  uint16 highs;
  UINT16 lows;
  UINT16 freq;
  BOOL isbegin;
} pwm;

/*Uart 回调*/
void uartCallback(T_AMOPENAT_UART_MESSAGE* evt)
{
	OPENAT_lua_print("Evt %d, dataLen %d",evt->evtId, evt->param.dataLen);
  int i;
  T_AMOPENAT_GPIO_CFG cfg;

  cfg.mode = OPENAT_GPIO_OUTPUT;
  cfg.param.defaultState = 0;
  cfg.param.intCfg.intType = OPENAT_GPIO_NO_INT;
  cfg.param.intCfg.intCb = NULL;
  cfg.param.intCfg.debounce = 20;
  cfg.param.pullState = OPENAT_GPIO_PULLUP;

  OPENAT_config_gpio(1,&cfg);
	switch(evt->evtId)
	{
		case OPENAT_DRV_EVT_UART_RX_DATA_IND:
    {
      int len = OPENAT_read_uart(OPENAT_UART_2, uartRxBuff, evt->param.dataLen, 0);
      OPENAT_lua_print("uartRxData:%s",uartRxBuff);
      if(strstr(uartRxBuff,"lightled") != NULL){
          pwm.isbegin =TRUE;
          for(i=0;i<pwm.freq;i++){
            OPENAT_set_gpio(1,1);
            OPENAT_lua_print("on");
            OPENAT_sleep(pwm.highs*1000);
            OPENAT_set_gpio(1,0);
            OPENAT_lua_print("off");
            OPENAT_sleep(pwm.lows*1000);
          }
          OPENAT_lua_print("The lightLed's test stop here");
          OPENAT_close_gpio(1);
      }
			break;
    }
		default:
			break;
	}
}


/*light led示例*/
int lightled_sample(int highs,int lows,int freq)
{
    pwm.highs =highs;
    pwm.lows =lows;
    pwm.freq =freq;
    pwm.isbegin =FALSE;
    T_AMOPENAT_UART_PARAM cfg;

    cfg.baud = OPENAT_UART_BAUD_115200;
    cfg.dataBits = 8;
    cfg.stopBits = 1;
    cfg.flowControl = OPENAT_UART_FLOWCONTROL_NONE;
    cfg.parity = OPENAT_UART_NO_PARITY;
    cfg.txDoneReport = TRUE;
    cfg.uartMsgHande = uartCallback;

    OPENAT_config_uart(OPENAT_UART_2,&cfg);
    while(1){
        OPENAT_sleep(1000);
        if(pwm.isbegin) break;
        OPENAT_write_uart(OPENAT_UART_2,"wait lightled",strlen("wait lightled"));
    }

    return 1;
}

/*lua调用入口*/
int test_lightled(int highs,int lows,int freq)
{
    lightled_sample(highs,lows,freq);
    return 1;
}
