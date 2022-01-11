/*********************************************************
 * Copyright (C), AirM2M Tech. Co., Ltd.
 * Hezhou Data:light_led_sample
 *
 * History:
 * Version     Date       Author       Notes
 * V0.1     2021-12-27    wang       the first version
 *********************************************************/
#include "core_api.h"

#define GPIO_1      18
#define LED    GPIO_1

UINT8 uartRxBuff[512];
struct PWM_CFG
{
  uint32 high_us;
  uint32 low_us;
  UINT16 freq;
  BOOL is_begin;
} pwm = {0};

int led_status = 0;
HANDLE g_hir_timer_handle = NULL;
VOID hir_timer_callback(VOID *pParameter){
  led_status = ~led_status;
  OPENAT_set_gpio(LED,led_status);

  if (!led_status)
  {
      OPENAT_start_precise_timer(g_hir_timer_handle, pwm.high_us);
  }else if(led_status)
  {
      OPENAT_start_precise_timer(g_hir_timer_handle, pwm.low_us);
  }
}

/*Uart 回调*/
void uart_Callback(T_AMOPENAT_UART_MESSAGE* evt)
{
	OPENAT_lua_print("Evt %d, dataLen %d",evt->evtId, evt->param.dataLen);
  int i;
  char *extent;
  T_AMOPENAT_GPIO_CFG cfg = {0};

  cfg.mode = OPENAT_GPIO_OUTPUT;
  cfg.param.defaultState = 1;

  OPENAT_config_gpio(LED,&cfg);
  if(g_hir_timer_handle == NULL)
  g_hir_timer_handle = OPENAT_create_hir_timer(hir_timer_callback,NULL);

	switch(evt->evtId)
	{
		case OPENAT_DRV_EVT_UART_RX_DATA_IND:
    {
      int len = OPENAT_read_uart(OPENAT_UART_2, uartRxBuff, evt->param.dataLen, 0);
      OPENAT_lua_print("uartRxData:%s",uartRxBuff);
      if(strstr(uartRxBuff,"openPWM") != NULL){
          pwm.is_begin =TRUE;
          if (uartRxBuff + 8 != NULL)
          {
            pwm.high_us = strtol(uartRxBuff + 8, &extent, 10);
            if (extent + 1 != NULL)
              pwm.low_us = strtol(extent + 1, &extent, 10);
            else{
                OPENAT_lua_print("Too few parameters");
                break;
            }
          }else{
                OPENAT_lua_print("Parameters Error");
                break;
          }
          OPENAT_lua_print("PWM_high_level_last:%d\nPWM_low_level_last:%d",pwm.high_us,pwm.low_us);
          OPENAT_start_precise_timer(g_hir_timer_handle, pwm.high_us);
      }
      if(strstr(uartRxBuff,"closePWM") != NULL){
          OPENAT_stop_timer(g_hir_timer_handle);
          OPENAT_close_gpio(LED);
      }
      break;
    }
    default:
      break;
  }
}


/*light led示例*/
int open_pwm_sample(void)
{
    pwm.is_begin = FALSE;

    T_AMOPENAT_UART_PARAM cfg;
    cfg.baud = OPENAT_UART_BAUD_115200;
    cfg.dataBits = 8;
    cfg.stopBits = 1;
    cfg.flowControl = OPENAT_UART_FLOWCONTROL_NONE;
    cfg.parity = OPENAT_UART_NO_PARITY;
    cfg.txDoneReport = TRUE;
    cfg.uartMsgHande = uart_Callback;

    OPENAT_config_uart(OPENAT_UART_2,&cfg);
    while(1){
        OPENAT_sleep(1000);
        if(pwm.is_begin) break;
        OPENAT_write_uart(OPENAT_UART_2,"wait openPWM",strlen("wait openPWM"));
    }

    return 1;
}

/*lua调用入口*/
int test_open_pwm(void* L)
{
    open_pwm_sample();
    return 0;
}
