/*test.c*/
#include "core_api.h"

UINT8 uartTestBuff[1024];
UINT32 uartTestPort = OPENAT_UART_2;

void uartTestCb(T_AMOPENAT_UART_MESSAGE* evt)
{
	OPENAT_lua_print("evt %d, dataLen %d",evt->evtId, evt->param.dataLen);
	int len;
	
	switch(evt->evtId)
	{
		case OPENAT_DRV_EVT_UART_RX_DATA_IND:
			len = OPENAT_read_uart(uartTestPort, uartTestBuff, evt->param.dataLen, 0);

			OPENAT_write_uart(uartTestPort, uartTestBuff, len);
			break;
		default:
			break;
	}
}

int uart_test(void)
{
    T_AMOPENAT_UART_PARAM cfg;
	
	cfg.baud = OPENAT_UART_BAUD_115200;
	cfg.dataBits = 8;
	cfg.stopBits = 1;
	cfg.flowControl = OPENAT_UART_FLOWCONTROL_NONE;
	cfg.parity = OPENAT_UART_NO_PARITY;
	cfg.txDoneReport = TRUE;
	cfg.uartMsgHande = uartTestCb;

    OPENAT_config_uart(OPENAT_UART_2,&cfg);

    OPENAT_write_uart(OPENAT_UART_2,"test_uart",strlen("test_uart"));
    return 1;
}

