/*********************************************************
  Copyright (C), AirM2M Tech. Co., Ltd.
  Author: brezen
  Description: AMOPENAT ����ƽ̨
  Others:
  History: 
    Version�� Date:       Author:   Modification:
    V0.1      2012.09.24  brezen    �����ļ�
    V0.2      2012.12.17  brezen    ���UART����
    V0.3      2012.12.27  brezen    ���pmd����
    V0.4      2012.12.27  brezen    ���spi���� 
    V0.5      2013.01.08  brezen    ��Ӵ���������
    V0.6      2013.01.11  brezen    ���spi���� 
    V0.7      2013.01.15  brezen    �޸�lcd frequenceΪuint32
    V0.8      2013.01.15  brezen    1�����gpo 2�����lcd gpio ����
    V0.9      2013.01.17  brezen    ���ldo
    V1.0      2013.01.28  brezen    ���psam
    V1.1      2013.02.06  Jack.li   ���camera�ӿ�
    V1.2      2013.02.09  Jack.li   �����Ƶ¼�ƽӿ�
    V1.3      2013.03.01  brezen    ��Ӵ���OPENAT_UART_3
	V1.4      2014.1.17   brezen    �������HFP����
	V1.5      2014.5.22   brezen    �����������̲���ģʽ
	V1.6      2014.6.9    brezen    ��������˯��ģʽ
	V1.7      2014.6.26   brezen    �������spp�ӿ�
	V1.8      2015.08.27  panjun    Simplify MMI's frame for Video.
	V1.9      2016.03.26  panjun    Add TTSPLY's API.
*********************************************************/

#ifndef __AM_OPENAT_DRV_H__
#define __AM_OPENAT_DRV_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/
#include <cs_types.h> 
/*----------------------------------------------*
 * �궨��                                       *
 *----------------------------------------------*/
/*+\NEW\RUFEI\2015.8.27\Add adc fuction*/
#define DEFAULT_VALUE 0xffff
/*-\NEW\RUFEI\2015.8.27\Add adc fuction*/ 


#if defined(A9188S_VER_A11) || defined (AM_A9189_VER_A10)
#define OPENAT_LCD_RST_GPIO 50
#elif defined (A9188S_VER_A10)
#define OPENAT_LCD_RST_GPIO 41
#else
#define OPENAT_LCD_RST_GPIO 50
#endif


typedef enum
{
  OPENAT_DRV_EVT_INVALID,
  /* charge plug in/out */
  OPENAT_DRV_EVT_CHR_PRESENT_IND,

  /* battery status */
  OPENAT_DRV_EVT_BAT_PRESENT_IND, //��ʱ��֧��
  OPENAT_DRV_EVT_BAT_LEVEL_IND,
  OPENAT_DRV_EVT_BAT_VOLT_LOW,
  OPENAT_DRV_EVT_BAT_OVERVOLT,    //��ʱ��֧��

  /* charging status */
  OPENAT_DRV_EVT_BAT_CHARGING,
  OPENAT_DRV_EVT_BAT_CHR_FULL,
/*+\BUG WM-1016\rufei\2013.11.19\ �޸�ƽ̨������*/
  OPENAT_DRV_EVT_BAT_RECHARGING,
  OPENAT_DRV_EVT_BAT_RECHR_FULL,
/*-\BUG WM-1016\rufei\2013.11.19\ �޸�ƽ̨������*/
  OPENAT_DRV_EVT_BAT_CHR_STOP,
  OPENAT_DRV_EVT_BAT_CHR_ERR,

  /* power on cause */
  OPENAT_DRV_EVT_PM_POWERON_ON_IND,

  /* GPIO interrupt */
  OPENAT_DRV_EVT_GPIO_INT_IND,
  
  /* LCD event */
  OPENAT_DRV_EVT_LCD_REFRESH_REQ,
  
  /* CAMERA event */
  OPENAT_DRV_EVT_VIDEORECORD_FINISH_IND,

  /*CAMERA DATA event*/
  /*+\NEW\zhuwangbin\2020.4.26\���openat cam�ӿ�*/
  OPENAT_DRV_EVT_CAMERA_DATA_IND,
  /*-\NEW\zhuwangbin\2020.4.26\���openat cam�ӿ�*/
  
  /* VIDEO event */
  OPENAT_DRV_EVT_VIDEO_PLAY_FINISH_IND,
  OPENAT_DRV_EVT_VIDEO_CURRENT_TIME_IND,

  /* UART event */
  OPENAT_DRV_EVT_UART_RX_DATA_IND,
/*+\NEW\zhuwangbin\2018.8.10\���OPENAT_DRV_EVT_UART_TX_DONE_IND�ϱ�*/
  OPENAT_DRV_EVT_UART_TX_DONE_IND,
/*-\NEW\zhuwangbin\2018.8.10\���OPENAT_DRV_EVT_UART_TX_DONE_IND�ϱ�*/
  /* ALARM event */
  OPENAT_DRV_EVT_ALARM_IND,

  /*app �����Զ�У��*/
  OPENAT_SW_AUTO_VERIFY_IND,
  
}E_OPENAT_DRV_EVT;

/*************************************************
* GPIO
*************************************************/
typedef UINT8 E_AMOPENAT_GPIO_PORT;

/*********************************************
* ����: GPIO�жϷ�ʽ
* ����: 
*********************************************/
typedef enum
{
    OPENAT_GPIO_NO_INT,
    OPENAT_GPIO_INT_HIGH_LEVEL,
    OPENAT_GPIO_INT_LOW_LEVEL,
    OPENAT_GPIO_INT_BOTH_EDGE,
    OPENAT_GPIO_INT_FALLING_EDGE,
    OPENAT_GPIO_INT_RAISING_EDGE,
}T_OPENAT_GPIO_INT_TYPE;


/*********************************************
* ����: PIN����ģʽ
* ����: 
*********************************************/
typedef enum
{
  OPENAT_GPIO_INVALID_MODE,
  OPENAT_GPIO_INPUT, //as gpio or gpo
  OPENAT_GPIO_OUTPUT,
  OPENAT_GPIO_INPUT_INT,
/*+\new\rww\2021.7.8\lua gpio ����*/
  OPENAT_GPIO_INPUT_INT2, // reserve
/*-\new\rww\2021.7.8\lua gpio ����*/
  OPENAT_GPIO_MODE_UNKNOWN
}T_OPENAT_GPIO_MODE;
  
/*+\BUG\wangyuan\2020.10.13\BUG_3249:8910-CSDK �� GPIO �������������ӿ�*/
typedef enum
{ 
  OPENAT_GPIO_NO_PULL = 0,
  OPENAT_GPIO_PULLDOWN = 1,
  OPENAT_GPIO_PULLUP = 2,
  OPENAT_GPIO_PULLMODE_UNKNOWN
}T_OPENAT_GPIO_PULLMODE;
/*-\BUG\wangyuan\2020.10.13\BUG_3249:8910-CSDK �� GPIO �������������ӿ�*/

/*+\BUG\AMOPENAT-13\brezen\2013.4.13\�޸�Openat������api����������ǿת*/
typedef void (*OPENAT_GPIO_EVT_HANDLE)(E_OPENAT_DRV_EVT evt, E_AMOPENAT_GPIO_PORT gpioPort,unsigned char state);
/*-\BUG\AMOPENAT-13\brezen\2013.4.13\�޸�Openat������api����������ǿת*/

/*********************************************
* ����: GPIO�жϲ���
* ����: 
*********************************************/
typedef struct
{
  unsigned int            debounce; //ms
  T_OPENAT_GPIO_INT_TYPE     intType;
  OPENAT_GPIO_EVT_HANDLE     intCb;
}T_OPENAT_GPIO_INT_CFG;

/*********************************************
* ����: GPIO����
* ����: 
*********************************************/
typedef struct
{
  unsigned char      defaultState;
  T_OPENAT_GPIO_INT_CFG   intCfg;
  /*+\BUG\wangyuan\2020.10.23\BUG_3249:8910-CSDK �� GPIO �������������ӿ�*/
  T_OPENAT_GPIO_PULLMODE  pullState;		/* 0: nopull, 1: pulldown, 2: pullup*/
  /*-\BUG\wangyuan\2020.10.23\BUG_3249:8910-CSDK �� GPIO �������������ӿ�*/
}T_OPENAT_GPIO_PARAM;

typedef struct T_AMOPENAT_GPIO_CFG_TAG
{
    /// Direction of the GPIO
    T_OPENAT_GPIO_MODE    mode;
    T_OPENAT_GPIO_PARAM   param;
}T_AMOPENAT_GPIO_CFG;

/*+\NEW \lijiaodi\2018.08.16\���GPIO�жϵ����������*/
typedef struct  GpioInterruptConfigTag
{
    T_OPENAT_GPIO_INT_TYPE intType;
    BOOL             ignoreFirstInterrupt;
}
GpioInterruptConfig;

typedef struct GpioIntDebounceTag
{
    INT16           debouncePrd;
    BOOL         oldLineState;
/*+:\BUG\AMOPENAT-24\brezen\2013.05.17\GPIO4�ڴ�绰ʱ�����ж���Ч����*/		
    INT16           debounceCount; /*debouncePrd/10*/
    INT16           checkedCount;  /*�Ѿ������ĸ���*/
    INT16           sucCheckCount; /*�����ɹ��ĸ���*/

    INT16           debounceFaildCount; /*����ʧ�ܼ�¼������ʹ��*/
    INT16           debounceSuccCount; /*�����ɹ���¼������ʹ��*/
    INT16           intCount;
	BOOL            inputState;
    /***************
    checkedCount  ÿ�η���++,���ΪdebounceCount*2;
    
    sucCheckCount �������ʧ�ܾͽ�sucCheck��0
    ***/
/*-:\BUG\AMOPENAT-24\brezen\2013.05.17\GPIO4�ڴ�绰ʱ�����ж���Ч����*/	    
}GpioIntDebounce;

typedef struct GpioIntTmrInfoTag
{
   const INT32       timerId;
   INT32             gpioNum;
   HANDLE            hTimer;
}
GpioIntTmrInfo;

typedef struct GpioIntConfigTag
{
    INT32                gpioNum;
    GpioInterruptConfig  intCfg;
    GpioIntDebounce      debounce;
    OPENAT_GPIO_EVT_HANDLE  gpiointcb;
    struct GpioIntConfigTag* prev;
    struct GpioIntConfigTag* next;
}
GpioIntConfig;

typedef struct gpioIntConfigQueue
{
  GpioIntConfig* head;
  GpioIntConfig* tail;
}GpioIntConfigQueue;


/*Internal Signal To The GPIO Module*/
typedef struct PdGpioStartIntTimerReqTag
{
  INT32       timerId;
  INT16           period;
}
PdGpioStartIntTimerReq;

typedef struct pdgpioTimerExpiryTag
{
    INT32                timerId;
    INT32                userValue;
}pdgpioTimerExpiry;
/*-\NEW \lijiaodi\2018.08.16\���GPIO�жϵ����������*/

/*************************************************
* ADC
*************************************************/
/*+\NEW\RUFEI\2015.8.27\Add adc fuction*/
typedef enum E_AMOPENAT_ADC_CHANNEL_TAG
{
	/*+\NEW\zhuwangbin\2020.2.11\���openat adc�ӿ�*/
    OPENAT_ADC_0,
    OPENAT_ADC_1,
    OPENAT_ADC_2,
	OPENAT_ADC_3,
	OPENAT_ADC_4,
	OPENAT_ADC_5,
	OPENAT_ADC_6,
	OPENAT_ADC_7,
	OPENAT_ADC_8,
	OPENAT_ADC_9,
	OPENAT_ADC_10,
	OPENAT_ADC_11,
	OPENAT_ADC_12,
	OPENAT_ADC_13,
    OPENAT_ADC_14,
    OPENAT_ADC_15,
    OPENAT_ADC_16,
    OPENAT_ADC_17,
    OPENAT_ADC_18,
    OPENAT_ADC_19,
    OPENAT_ADC_20,
    OPENAT_ADC_21,
	OPENAT_ADC_22,
	OPENAT_ADC_23,
    OPENAT_ADC_24,
    OPENAT_ADC_25,
    OPENAT_ADC_26,
    OPENAT_ADC_27,
    OPENAT_ADC_28,
    OPENAT_ADC_29,
    OPENAT_ADC_30,
    OPENAT_ADC_31,
    OPENAT_ADC_QTY
    /*-\NEW\zhuwangbin\2020.2.11\���openat adc�ӿ�*/
}E_AMOPENAT_ADC_CHANNEL;

/*+\bug3689\zhuwangbin\2020.11.25\adc��ӿ�ѡ����scale*/
typedef enum E_AMOPENAT_ADC_SCALE_TAG
{
	OPENAT_ADC_SCALE_DEFAULT, //5v
	OPENAT_ADC_SCALE_1V250, 
    OPENAT_ADC_SCALE_2V444,
    OPENAT_ADC_SCALE_3V233, 
    OPENAT_ADC_SCALE_5V000,
    OPENAT_ADC_SCALE_QTY,
}E_AMOPENAT_ADC_SCALE;
/*-\bug3689\zhuwangbin\2020.11.25\adc��ӿ�ѡ����scale*/



typedef enum E_AMOPENAT_ADC_CFG_MODE_TAG
{
    OPENAT_ADC_MODE_NULL = 0,/*Ĭ��ֵ*/
    OPENAT_ADC_MODE_1 = 1,  /*����1��*/
    /*����ֵ����ֱ��ǿת*/

    OPENAT_ADC_MODE_MAX = 0xff /*���ø��£��Թ�����һ��Ӱ��*/
}E_AMOPENAT_ADC_CFG_MODE;

typedef enum E_AMOPENAT_ADC_STATUS_TAG
{
    OPENAT_ADC_STATUS_NULL, /*Ĭ��״̬*/
    OPENAT_ADC_STATUS_INIT, /*��ʼ��*/
    OPENAT_ADC_STATUS_READING,/*�Ѹ���ֵ���Լ�������  */ 
    OPENAT_ADC_STATUS_READ_COMPLETE,/*��ɶ�ֵ*/
    
    OPENAT_ADC_STATUS_QTY
}E_AMOPENAT_ADC_STATUS;

typedef struct E_AMOPENAT_ADC_CONTEXT_TAG
{
    E_AMOPENAT_ADC_STATUS status;
    E_AMOPENAT_ADC_CFG_MODE adc_mode;
    E_AMOPENAT_ADC_CHANNEL channel;
    kal_uint32 adc_value;
    kal_uint32 volt;
    kal_uint32 adc_handle;
}E_AMOPENAT_ADC_CONTEXT;
/*-\NEW\RUFEI\2015.8.27\Add adc fuction*/

/*************************************************
* PM
*************************************************/
typedef enum
{
  OPENAT_PM_CHR_BY_DEFAULT, /* ϵͳ�Զ����Ƴ�� */
  OPENAT_PM_CHR_BY_CUST,    /* �û��Լ����Ƴ�� */
/*+\NEW WM-746\rufei\2013.3.30\����оƬIC���*/
  OPENAT_PM_CHR_BY_IC,
/*-\NEW WM-746\rufei\2013.3.30\����оƬIC���*/
  OPENAT_PM_CHR_INVALID_MODE
}E_AMOPENAT_PM_CHR_MODE;

/*+\BUG WM-771\rufei\2013.4.11\���Ƴ������*/
typedef enum
{
  OPENAT_PM_LI_BAT,
  OPENAT_PM_NICD_BAT
}E_AMOPENAT_BAT_TYPE;
/*-\BUG WM-771\rufei\2013.4.11\���Ƴ������*/

/*+\BUG WM-771\rufei\2013.5.20\���Ƴ������*/
typedef enum
{
    /// Charge is forced OFF
/*+\NEW\RUFEI\2015.5.8\���Ƴ�����*/
    OPENAT_PM_CHARGER_00MA,  /* ��֧�ָù���*/
    OPENAT_PM_CHARGER_20MA,  /*ֻ���ڳ�������ʹ��*/
    OPENAT_PM_CHARGER_30MA,  /*ֻ���ڳ�������ʹ��*/
    OPENAT_PM_CHARGER_40MA,  /*ֻ���ڳ�������ʹ��*/
    OPENAT_PM_CHARGER_50MA,
    OPENAT_PM_CHARGER_60MA,
    /// Charge with a  70 mA current
    OPENAT_PM_CHARGER_70MA,
    /// Charge with a 200 mA current
    OPENAT_PM_CHARGER_200MA,
    /// Charge with a 300 mA current
    OPENAT_PM_CHARGER_300MA,
    /// Charge with a 400 mA current
    OPENAT_PM_CHARGER_400MA,
    /// Charge with a 500 mA current
    OPENAT_PM_CHARGER_500MA,
    /// Charge with a 600 mA current
    OPENAT_PM_CHARGER_600MA,
    /// Charge with a 700 mA current
    OPENAT_PM_CHARGER_700MA,
    /// Charge with a 800 mA current
    OPENAT_PM_CHARGER_800MA,
    OPENAT_PM_CHARGER_900MA,
    OPENAT_PM_CHARGER_1000MA,
    OPENAT_PM_CHARGER_1100MA,
    OPENAT_PM_CHARGER_1200MA,
    OPENAT_PM_CHARGER_1300MA,
    OPENAT_PM_CHARGER_1400MA,
    OPENAT_PM_CHARGER_1500MA,
/*-\NEW\RUFEI\2015.5.8\���Ƴ�����*/

    OPENAT_PM_CHARGE_CURRENT_QTY
} E_OPENAT_CHARGE_CURRENT;
/*-\BUG WM-771\rufei\2013.5.20\���Ƴ������*/

/*+\NEW\RUFEI\2015.5.8\���Ƴ�����*/
typedef enum
{
    OPENAT_PM_VOLT_00_000V,
    OPENAT_PM_VOLT_01_800V,
    OPENAT_PM_VOLT_02_800V,
    OPENAT_PM_VOLT_03_000V,
    OPENAT_PM_VOLT_03_200V,
    OPENAT_PM_VOLT_03_400V,
    OPENAT_PM_VOLT_03_600V,
    OPENAT_PM_VOLT_03_800V,
    OPENAT_PM_VOLT_03_850V,
    OPENAT_PM_VOLT_03_900V,
    OPENAT_PM_VOLT_04_000V,
    OPENAT_PM_VOLT_04_050V,
    OPENAT_PM_VOLT_04_100V,
    OPENAT_PM_VOLT_04_120V,
    OPENAT_PM_VOLT_04_130V,
    OPENAT_PM_VOLT_04_150V,
    OPENAT_PM_VOLT_04_160V,
    OPENAT_PM_VOLT_04_170V,
    OPENAT_PM_VOLT_04_180V,
    OPENAT_PM_VOLT_04_200V,
    OPENAT_PM_VOLT_04_210V,
    OPENAT_PM_VOLT_04_220V,
    OPENAT_PM_VOLT_04_230V,
    OPENAT_PM_VOLT_04_250V,
    OPENAT_PM_VOLT_04_260V,
    OPENAT_PM_VOLT_04_270V,
    OPENAT_PM_VOLT_04_300V,
    OPENAT_PM_VOLT_04_320V,
    OPENAT_PM_VOLT_04_350V,
    OPENAT_PM_VOLT_04_370V,
    OPENAT_PM_VOLT_04_400V,
    OPENAT_PM_VOLT_04_420V,

    OPENAT_PM_VOLT_QTY
} E_OPENAT_PM_VOLT;
/*-\NEW\RUFEI\2015.5.8\���Ƴ�����*/

typedef union T_AMOPENAT_PMD_CFG_TAG
{
  struct{
  UINT8 pad;   /*�����壬Ŀǰ��֧�����ֳ��*/
/*+\BUG WM-771\rufei\2013.4.11\���Ƴ������*/
  E_AMOPENAT_BAT_TYPE batType; /*������չʹ��*/
  UINT16 batfullLevel;/*������չʹ�ã�mv*/
/*+\BUG WM-771\rufei\2013.5.20\���Ƴ������*/
  UINT16 batPreChargLevel;
/*-\BUG WM-771\rufei\2013.5.20\���Ƴ������*/
  UINT16 poweronLevel;/*�����Ժ���չʹ�ã�mv*/
  UINT16 poweroffLevel;/*�����Ժ���չʹ�ã�mv*/
/*-\BUG WM-771\rufei\2013.4.11\���Ƴ������*/
  }cust;/*Ŀǰ��֧�����ֳ��*/
  struct{
/*+\NEW\RUFEI\2015.5.8\���Ƴ�����*/
  BOOL batdetectEnable;/*�ݲ�֧��*/

  BOOL tempdetectEnable;/*�ݲ�֧��*/
  UINT16 templowLevel;
  UINT16 temphighLevel;

  E_AMOPENAT_BAT_TYPE batType;

  BOOL batLevelEnable;
  E_OPENAT_PM_VOLT ccLevel;/*�������׶�*/
  E_OPENAT_PM_VOLT cvLevel;/*��ѹ���׶Σ�������ѹ��*/
  E_OPENAT_PM_VOLT ovLevel;/*������Ƶ�ѹ*/
  E_OPENAT_PM_VOLT pvLevel;/*�س��ѹ*/
  E_OPENAT_PM_VOLT poweroffLevel;
  E_AMOPENAT_ADC_CHANNEL batAdc;/*�ݲ�֧��*/
  E_AMOPENAT_ADC_CHANNEL tempAdc;/*�ݲ�֧��*/
  
  BOOL currentControlEnable;
  E_OPENAT_CHARGE_CURRENT ccCurrent;
  E_OPENAT_CHARGE_CURRENT fullCurrent;/*�����������ĵ���ֵС�ڸ�ֵʱ����Ϊ����*/
  UINT16 ccOnTime;/*��λs,�ݲ�֧��*/
  UINT16 ccOffTime;/*��λs,�ݲ�֧��*/
    
  BOOL  chargTimeOutEnable;
  UINT16 TimeOutMinutes; /*��ʱ������*/

  BOOL disableCharginCall;/*�ݲ�֧��*/
/*-\NEW\RUFEI\2015.5.8\���Ƴ�����*/

  }deFault;
}T_AMOPENAT_PMD_CFG;


typedef enum
{
  PMD_MODULE_GPIO,
  PMD_MODULE_SPI,
  PMD_MODULE_UART,
  PMD_MODULE_I2C,
  PMD_MODULE_AUDIO,
  PMD_MODULE_TRACE,
  PMD_MODULE_APP,
  PMD_MOUDLE_MAX
}E_AMOPENAT_PMD_M;

typedef enum
{
  OPENAT_PM_BATT_NORMAL,
  OPENAT_PM_BATT_CHARGING,
  OPENAT_PM_BATT_ERR,
  OPENAT_PM_BATT_INVALID
}E_AMOPENAT_BAT_STATUS;

typedef enum
{
  OPENAT_PM_CHARGER_STATUS_ERR,
  OPENAT_PM_CHARGER_PLUG_IN,
  OPENAT_PM_CHARGER_PLUG_OUT,
  OPENAT_PM_CHARGER_STATUS_INVALID
}E_AMOPENAT_CHARGER_STATUS;

typedef enum
{
  OPENAT_PM_CHARGER_WALL,
  OPENAT_PM_CHARGER_USB,
  OPENAT_PM_CHARGER_INVALID
}E_AMOPENAT_CHARGER_TYPE;

typedef enum
{ 
	OPENAT_LDO_POWER_VLCD,
	OPENAT_LDO_POWER_MMC,
	/*+\new\wj\2020.4.14\��ӵ�ѹ��VSIM1����gpio29��30��31*/
	OPENAT_LDO_POWER_VSIM1,
	/*-\new\wj\2020.4.14\��ӵ�ѹ��VSIM1����gpio29��30��31*/
	/*+\new\shenyuanyuan\2020.5.21\ģ����VCAM���*/
	OPENAT_LDO_POWER_VCAMA,
	OPENAT_LDO_POWER_VCAMD,
	/*-\new\shenyuanyuan\2020.5.21\ģ����VCAM���*/
	/*+\BUG\wangyuan\2020.08.22\BUG_2883:lua����820GPS������������*/
	OPENAT_LDO_POWER_VIBR,
	/*-\BUG\wangyuan\2020.08.22\BUG_2883:lua����820GPS������������*/
	/*+\BUG3154\zhuwangbin\2020.10.10\���backlight����*/
	OPENAT_LDO_POWER_VBACKLIGHT_R,
	OPENAT_LDO_POWER_VBACKLIGHT_G,
	OPENAT_LDO_POWER_VBACKLIGHT_B,
	OPENAT_LDO_POWER_VBACKLIGHT_W,
	
	/*-\BUG3154\zhuwangbin\2020.10.10\���backlight����*/
	
	/*+\BUG3753\zhuwangbin\2020.12.4\���audio hmic bias ldo����*/
	/*
	*	level:0-15
	*	0 : �ر�
	*	1��2.2V
	*	2��2.4V
	*	3��2.5V
	*	4��2.6V
	*	5��2.7V
	*	6��2.8V
	*	7��2.9V
	*	8��3.0V
	*	����8��3.0V
	*/
	OPENAT_LDO_POWER_HMICBIAS,
	/*-\BUG3753\zhuwangbin\2020.12.4\���audio hmic bias ldo����*/
	
	OPENAT_LDO_POWER_INVALID
}E_AMOPENAT_PM_LDO;

typedef struct
{
  uint16              batteryTemp;        /* ����¶�ADCֵ*/
  uint16              batteryVolt;
/*+\BUG WM-771\rufei\2013.5.22\���Ƴ������3*/
  E_AMOPENAT_ADC_CHANNEL tempChannel;  
  E_AMOPENAT_ADC_CHANNEL batteryChannel;
/*-\BUG WM-771\rufei\2013.5.22\���Ƴ������3*/
  E_AMOPENAT_BAT_STATUS  batteryState;
}T_AMOPENAT_BAT_STATUS;

typedef struct
{
/*+\BUG WM-771\rufei\2013.5.22\���Ƴ������3*/
  uint16                    chargerVolt;
  E_AMOPENAT_ADC_CHANNEL    chargerChannel;
/*-\BUG WM-771\rufei\2013.5.22\���Ƴ������3*/
  E_AMOPENAT_CHARGER_TYPE   chargerType;   /* TODO ��ʱ��֧�� */
  E_AMOPENAT_CHARGER_STATUS chargerStatus;
}T_AMOPENAT_CHARGER_STATUS;

typedef enum
{
  OPENAT_PM_CHR_STOP_NO_REASON,
  OPENAT_PM_CHR_STOP_BAT_FULL,
  OPENAT_PM_CHR_STOP_BAT_ERR,
  OPENAT_PM_CHR_STOP_TIMEOUT,
/*+\BUG WM-771\rufei\2013.8.2\���Ƴ������*/
  OPENAT_PM_CHR_STOP_TEMP,
  OPENAT_PM_CHR_STOP_CHARGER_ERR,
/*-\BUG WM-771\rufei\2013.8.2\���Ƴ������*/
  OPENAT_PM_CHR_STOP_NO_CHARGER,
  OPENAT_PM_CHR_STOP_OTER_REASON,
/*+\BUG WM-1016\rufei\2013.11.19\ �޸�ƽ̨������*/
  OPENAT_PM_RECHR_STOP_BAT_FULL,
/*-\BUG WM-1016\rufei\2013.11.19\ �޸�ƽ̨������*/
  OPENAT_PM_CHR_STOP_INVALID_REASON
}E_AMOPENAT_CHR_STOP_REASON;

typedef enum
{
  OPENAT_PM_POWERON_BY_KEY,     /* �������� */
  OPENAT_PM_POWERON_BY_CHARGER, /* ��翪�� */
  OPENAT_PM_POWERON_BY_ALARM,   /* ���ӿ��� */
  OPENAT_PM_POWERON_BY_RESET,   /* ����������� */ 
  OPENAT_PM_POWERON_BY_EXCEPTION, /* �쳣���� */ 
  OPENAT_PM_POWERON_BY_PIN_RESET, /* reset ������ */ 
  OPENAT_PM_POWERON_BY_UNKOWN = 0xff
	
}E_AMOPENAT_POWERON_REASON;

/*+\NEW\lijiaodi\2019.12.29\task_087:����ԭ��ֵ�Ļ�ȡ */
typedef enum
{
	RESET_BY_ERR,
	RESET_BY_SW,
	RESET_BY_UNKOWN,
}reset_cause;
/*-\NEW\lijiaodi\2019.12.29\task_087:����ԭ��ֵ�Ļ�ȡ */

typedef enum
{
  OPENAT_PM_STARTUP_MODE_DEFAULT,              /* ��ϵͳ���� */
  OPENAT_PM_STARTUP_MODE_ON,                   /* ǿ�ƿ��� */
  OPENAT_PM_STARTUP_MODE_OFF                   /* ǿ�Ʋ����� */
}E_AMOPENAT_STARTUP_MODE;

/*+\NEW\RUFEI\2014.2.13\����OPENAT��ѯ�����HW״̬�ӿ�*/
typedef enum
{
    OPENAT_PM_CHR_HW_STATUS_UNKNOWN,
    OPENAT_PM_CHR_HW_STATUS_AC_OFF,
    OPENAT_PM_CHR_HW_STATUS_AC_ON
}E_AMOPENAT_CHR_HW_STATUS;
/*-\NEW\RUFEI\2014.2.13\����OPENAT��ѯ�����HW״̬�ӿ�*/

typedef struct 
{
  E_OPENAT_DRV_EVT evtId;
  union
  {
/*+\BUG WM-771\rufei\2013.4.11\���Ƴ������*/
    struct{
    BOOL present;
    }batpresentind,chrpresentind;
    struct{
    UINT8 pad; /*�գ�������*/
    }chrstartind,chargererrind;
/*+\BUG WM-1016\rufei\2013.11.19\ �޸�ƽ̨������*/
    struct{
    UINT8 batteryLevel;  /*0-100 %*/
    }batlevelind,batovervoltind,chargingind,chrfullind,rechargingind,rechrfullind;
/*-\BUG WM-1016\rufei\2013.11.19\ �޸�ƽ̨������*/
    struct{
    E_AMOPENAT_CHR_STOP_REASON chrStopReason;
    }chrstopind;
    struct{
    E_AMOPENAT_POWERON_REASON powerOnReason;
    }poweronind;
    struct
    {
     BOOL start;  //true :start false:end
     UINT8 mask;  //bit0:sw bit1:key bit2:pw1 bit3:pw2 
    }swAutoVerifyInd;
/*-\BUG WM-771\rufei\2013.4.11\���Ƴ������*/
  }param;

}T_AMOPENAT_PM_MSG;

typedef void (*PPM_MESSAGE)(T_AMOPENAT_PM_MSG* pmMessage);

/*************************************************
* KEYPAD
*************************************************/
typedef enum E_AMOPENAT_KEYPAD_TYPE_TAG
{
    OPENAT_KEYPAD_TYPE_MATRIX,      /* ���м��� */
    OPENAT_KEYPAD_TYPE_ADC,         /* ADC���� */
    OPENAT_KEYPAD_TYPE_GPIO,        /* GPIO���� */
    OPENAT_KEYPAD_TYPE_MAX
}E_AMOPENAT_KEYPAD_TYPE;

#define OPENAT_KEYPAD_ENABLE_DEBOUNCE (1 << ((OPENAT_KEYPAD_TYPE_MAX >> 1) + 1))

/*+\NEW WM-718\rufei\2013.3.21\ ����gpio���̼���ģʽ*/
typedef enum E_AMOPENAT_GPIOKEY_MODE_TAG
{
    OPENAT_GPIOKEY_IRQ, /*��ͨģʽ*/
    OPENAT_GPIOKEY_ENCRYPT, /*����ģʽ*/
        
    OPENAT_GPIOKEY_MAX
}E_AMOPENAT_GPIOKEY_MODE;
/*-\NEW WM-718\rufei\2013.3.21\ ����gpio���̼���ģʽ*/

typedef struct T_AMOPENAT_TOUCH_MESSAGE_TAG
{
    UINT8 type; /**/
    UINT16 x;
    UINT16 y;
}T_AMOPENAT_TOUCH_MESSAGE;

typedef VOID (*TOUCH_MESSAGE)(T_AMOPENAT_TOUCH_MESSAGE *pTouchMessage);


typedef struct T_AMOPENAT_KEYPAD_MESSAGE_TAG
{
    UINT8 nType; /**/
    BOOL bPressed; /* �Ƿ��ǰ�����Ϣ */
    union {
        struct {
            UINT8 r;
            UINT8 c;
        }matrix, gpio;

/*+\NEW OPENAT-771\rufei\2013.8.8\�ϱ�ADC���̲�������*/
        struct{
            UINT16  adcValue;
            UINT16* adcList; /*��T_AMOPENAT_KEYPAD_CONFIG �д�isreportData������Ҫfree  adcList*/
            UINT16  adcCount;
        }adc;
/*-\NEW OPENAT-771\rufei\2013.8.8\�ϱ�ADC���̲�������*/
    }data;
}T_AMOPENAT_KEYPAD_MESSAGE;

typedef VOID (*PKEYPAD_MESSAGE)(T_AMOPENAT_KEYPAD_MESSAGE *pKeypadMessage);

typedef struct T_AMOPENAT_KEYPAD_CONFIG_TAG
{
    E_AMOPENAT_KEYPAD_TYPE type;
    PKEYPAD_MESSAGE pKeypadMessageCallback;
    union {
        struct {
/*+\NEW WM-718\rufei\2013.3.21\ ����gpio���̼���ģʽ*/
            UINT8 keyInMask;
            UINT8 keyOutMask;
/*-\NEW WM-718\rufei\2013.3.21\ ����gpio���̼���ģʽ*/
        }matrix;
/*+\NEW WM-718\rufei\2013.3.21\ ����gpio���̼���ģʽ*/
        struct {
            UINT32 gpioInMask;
            UINT32 gpioOutMask;
            BOOL   gpiofirstcfg;
            E_AMOPENAT_GPIOKEY_MODE mode;
        }gpio;
/*-\NEW WM-718\rufei\2013.3.21\ ����gpio���̼���ģʽ*/

/*+\NEW OPENAT-771\rufei\2013.8.8\�ϱ�ADC���̲�������*/
        struct{
            BOOL isreportData; /*�ڿ��������ڰ������µĴ�����free  adcList*/
        }adc;
/*-\NEW OPENAT-771\rufei\2013.8.8\�ϱ�ADC���̲�������*/
    }config;
	UINT8 debounceTime;
}T_AMOPENAT_KEYPAD_CONFIG;

/*************************************************
* TOUCHSCREEN
*************************************************/
typedef enum E_AMOPENAT_TOUCHSCREEN_PEN_STATE_TAG
{
    OPENAT_TOUCHSCREEN_PEN_DOWN,    
    OPENAT_TOUCHSCREEN_PEN_RESSED,  
    OPENAT_TOUCHSCREEN_PEN_UP,

    NumOfOpenatTouchScreenStates
}E_AMOPENAT_TOUCHSCREEN_PEN_STATE;

typedef struct T_AMOPENAT_TOUCHSCREEN_MESSAGE_TAG
{
    UINT8 penState;  //��ǰ����״̬
    UINT16 x;
    UINT16 y;
}T_AMOPENAT_TOUCHSCREEN_MESSAGE;

typedef VOID (*PTOUCHSCREEN_MESSAGE)(T_AMOPENAT_TOUCHSCREEN_MESSAGE *pTouchScreenMessage);


/*************************************************
* UART
*************************************************/
typedef enum
{
  OPENAT_UART_1,
  OPENAT_UART_2,
  OPENAT_UART_3,
  OPENAT_UART_USB,
  OPENAT_UART_QTY
}E_AMOPENAT_UART_PORT;

typedef enum
{
/*�������Ҫ��ֵ��������MTKƽ̨�ϣ����������Զ������ö�����ĳ�������Ϊ2�ֽ�*/
  OPENAT_UART_BAUD_1200 = 1200,
  OPENAT_UART_BAUD_2400 = 2400,
  OPENAT_UART_BAUD_4800 = 4800,
  OPENAT_UART_BAUD_9600 = 9600,
  OPENAT_UART_BAUD_14400 = 14400,
  OPENAT_UART_BAUD_19200 = 19200,
  OPENAT_UART_BAUD_28800 = 28800,
  OPENAT_UART_BAUD_38400 = 38400,
  OPENAT_UART_BAUD_57600 = 57600,
  OPENAT_UART_BAUD_76800 = 76800,
  OPENAT_UART_BAUD_115200 = 115200,
  OPENAT_UART_BAUD_230400 = 230400,
  OPENAT_UART_BAUD_460800 = 460800,
  OPENAT_UART_BAUD_576000 = 576000,
  OPENAT_UART_BAUD_921600 = 921600,
  OPENAT_UART_BAUD_1152000 = 1152000,
  OPENAT_UART_BAUD_4000000 = 4000000,
  OPENAT_UART_NUM_OF_BAUD_RATES
}E_AMOPENAT_UART_BAUD;

typedef enum
{
  OPENAT_UART_NO_PARITY,
  OPENAT_UART_ODD_PARITY,
  OPENAT_UART_EVEN_PARITY
}E_AMOPENAT_UART_PARITY;

typedef enum
{
 /*��MTKƽ̨�ı���һ��*/
  OPENAT_UART_FLOWCONTROL_NONE = 1,
  OPENAT_UART_FLOWCONTROL_HW,
  OPENAT_UART_FLOWCONTROL_SW,
  OPENAT_UART_FLOWCONTROL_INVALID
} E_AMOPENAT_UART_FLOWCTL;

#define AMOPENAT_UART_READ_FOREVER  (0xFFFFFFFF)
#define AMOPENAT_UART_READ_TRY      (0)

typedef struct 
{
  E_OPENAT_DRV_EVT evtId;
  union
  {
    uint32  dataLen;
  }param;
  
}T_AMOPENAT_UART_MESSAGE;

typedef void (*PUART_MESSAGE)(T_AMOPENAT_UART_MESSAGE* evt);

typedef struct
{
  E_AMOPENAT_UART_BAUD     baud; 
  uint32                   dataBits; /*6-8*/
  uint32                   stopBits; /*1-2*/
  E_AMOPENAT_UART_PARITY   parity;
  E_AMOPENAT_UART_FLOWCTL  flowControl;
  PUART_MESSAGE            uartMsgHande; /*���ڽ��ܵ����������ϱ�������ΪNULL����ʹ��������ʽ��ȡ*/
/*+\NEW\zhuwangbin\2018.8.31\��Ӳ����ж��Ƿ��ϱ�UART TXDONE*/
  BOOL                     txDoneReport;
/*-\NEW\zhuwangbin\2018.8.31\��Ӳ����ж��Ƿ��ϱ�UART TXDONE*/
}T_AMOPENAT_UART_PARAM;

/*+\NEW\liweiqiang\2013.12.25\���host uart�������ݹ��� */
/************************************************
* HOST
************************************************/
typedef void (*PHOST_MESSAGE)(UINT8 *pData, UINT32 length);
/*-\NEW\liweiqiang\2013.12.25\���host uart�������ݹ��� */

/************************************************
* LCD
************************************************/
/*+\NEW\liweiqiang\2013.3.28\���Ӵ��ڲ����ӿ� */
typedef enum 
{
    OPENAT_LCD_SPI4LINE,
    OPENAT_LCD_PARALLEL_8800,
/*+\new\zhuwangbin\2021.5.19\���MIPI LCD*/
#ifdef AM_MIPI_LCD_SUPPORT
	OPENAT_LCD_MIPI,
#endif
/*-\new\zhuwangbin\2021.5.19\���MIPI LCD*/
    OPENAT_LCD_BUS_QTY
}E_AMOPENAT_LCD_BUS;
/*-\NEW\liweiqiang\2013.3.28\���Ӵ��ڲ����ӿ� */

typedef struct
{
  short  ltX;
  short  ltY;
  short  rbX;
  short  rbY;
}T_AMOPENAT_LCD_RECT_T;


#define OPENAT_COLOR_FORMAT_16         2       /* 16-bit, rgb 565 */
#define OPENAT_COLOR_FORMAT_24         3       /* 24-bit, B,G,R       8,8,8 */
#define OPENAT_COLOR_FORMAT_32         4       /* 32-bit, B,G,R,A  8,8,8,8 */


typedef struct OPENAT_LAYER_INFO_TAG
{
    U8  color_format;
    T_AMOPENAT_LCD_RECT_T clip_rect;        /* ��Ҫˢ�µ����� */
    T_AMOPENAT_LCD_RECT_T disp_rect;        /* ��Ҫˢ�µ����� */
    T_AMOPENAT_LCD_RECT_T src_rect;         /* ��Ҫˢ�µ����� */
    U8 *buffer;              /* ˢ�µĻ����� */
}OPENAT_LAYER_INFO;


typedef struct
{
  uint16     height;
  uint16     width;
  uint16     xoffset;   /* ˢ����ƫ���� */
  uint16     yoffset;   /* һ������Ϊ0��0x20�����������Ե���ʾʱʹ�� */
  uint32     frequence; /* SPI����Ƶ�� */
  UINT8*     fameBuffer;
  E_AMOPENAT_GPIO_PORT   csPort;  /* LCDƬѡGPIO�� */
  E_AMOPENAT_GPIO_PORT   rstPort; /* LCD��λGPIO�� */
  
  /*+\BUG WM-822\WZQ\2013.5.25\����128*128��4���Ҷ���*/
  uint16     pixelBits;
  /*-\BUG WM-822\WZQ\2013.5.25\����128*128��4���Ҷ���*/
  /*+\BUG:3316\czm\2020.10.16\LCD_SPI ������������ϣ������ǿ��������*/  
  UINT8       Driving;//lcd_spi�������������ֵΪ15
  /*-\BUG:3316\czm\2020.10.16\LCD_SPI ������������ϣ������ǿ��������*/  
}T_AMOPENAT_MONO_LCD_PARAM;

typedef struct T_AMOPENAT_LCD_REFRESH_REQ_TAG
{
    T_AMOPENAT_LCD_RECT_T rect;
    UINT16 *pFrameBuffer;
}T_AMOPENAT_LCD_REFRESH_REQ;

typedef struct 
{
  E_OPENAT_DRV_EVT evtId;
  union
  {
    T_AMOPENAT_LCD_REFRESH_REQ      refreshReq;
  }param;
}T_AMOPENAT_LCD_MESSAGE;

typedef void (*PLCD_MESSAGE)(T_AMOPENAT_LCD_MESSAGE *pMsg);

typedef struct 
{
    uint16     height;
    uint16     width;
    PLCD_MESSAGE    msgCallback; // ���camera ��Ƶ���ܵ�ˢ�»ص������
/*+\NEW\liweiqiang\2013.3.28\���Ӵ��ڲ����ӿ� */
    E_AMOPENAT_LCD_BUS bus;
    union{
        struct{
            uint32     frequence; /* SPI����Ƶ�� */
            E_AMOPENAT_GPIO_PORT   csPort;  /* LCDƬѡGPIO�� */
            E_AMOPENAT_GPIO_PORT   rstPort; /* LCD��λGPIO�� */
            /*+\BUG:3316\czm\2020.10.16\LCD_SPI ������������ϣ������ǿ��������*/  
            UINT8       Driving;//lcd_spi�������������ֵΪ15
            /*-\BUG:3316\czm\2020.10.16\LCD_SPI ������������ϣ������ǿ��������*/  
        }spi;
    /*+\NEW\liweiqiang\2013.10.12\���Ӳ��ڲ���cs,rst�ܽ�����*/
        struct{
            E_AMOPENAT_GPIO_PORT   csPort;  /* LCDƬѡGPIO�� */
            E_AMOPENAT_GPIO_PORT   rstPort; /* LCD��λGPIO�� */
        }parallel;
    /*-\NEW\liweiqiang\2013.10.12\���Ӳ��ڲ���cs,rst�ܽ�����*/
/*+\new\zhuwangbin\2021.5.19\���MIPI LCD*/
#ifdef AM_MIPI_LCD_SUPPORT
		struct{
			void *buf0;
			void *buf1;
/*+\new\zhuwangbin\2021.9.2\���MIPI CLK������*/
			uint32     frequence;
/*-\new\zhuwangbin\2021.9.2\���MIPI CLK������*/
			E_AMOPENAT_GPIO_PORT   rstPort; /* LCD��λGPIO�� */

/*+\BUG:0\zwb\2021.10.22\���mipi porch������continueMode����*/
			UINT32 porchVs;
			UINT32 porchVbp;
			UINT32 porchVfp;
			UINT32 porchHs;
			UINT32 porchHbp;
			UINT32 porchHfp;
			BOOL continueMode;
/*-\BUG:0\zwb\2021.10.22\���mipi porch������continueMode����*/

		}mipi;
#endif
/*-\new\zhuwangbin\2021.5.19\���MIPI LCD*/
    }lcdItf;
/*-\NEW\liweiqiang\2013.3.28\���Ӵ��ڲ����ӿ� */

    uint8 lcd_bpp;
}T_AMOPENAT_COLOR_LCD_PARAM;

// +panjun, 2015.04.21, Define some GPIOs for OLED.
extern const char gpio_oled_backlight_en;
extern const char gpio_oled_cs_pin;
extern const char gpio_oled_rs_pin;
extern const char gpio_oled_clk_pin;
extern const char gpio_oled_data_pin;

#define LCD_SPI_RS 		gpio_oled_rs_pin
#define LCD_SPI_CS0  	gpio_oled_cs_pin
#define LCD_SPI_SCLK 	gpio_oled_clk_pin
#define LCD_SPI_SDA 	gpio_oled_data_pin
#define LCD_SPI_RESET 	OPENAT_LCD_RST_GPIO
#define LCD_BACKLIGHT_EN 	gpio_oled_backlight_en

#define LCD_SPI_RS_DELAY 	10
#define LCD_SPI_CS1_DELAY  	10
#define LCD_SPI_SCLK_DELAY 	18
#define LCD_SPI_SDA_DELAY 	10

#define LCD_SPI_RS_LOW \
{\
	volatile kal_uint32 i;\
	GPIO_WriteIO(0,LCD_SPI_RS); \
	for (i=0; i<LCD_SPI_RS_DELAY; i++); \
}
#define LCD_SPI_RS_HIGH \
{\
	volatile kal_uint32 i;\
	GPIO_WriteIO(1,LCD_SPI_RS); \
	for (i=0; i<LCD_SPI_RS_DELAY; i++); \
}


#define LCD_SPI_CS1_LOW \
{\
	volatile kal_uint32 i;\
	GPIO_WriteIO(0,LCD_SPI_CS0); \
	for (i=0; i<LCD_SPI_CS1_DELAY; i++); \
}
#define LCD_SPI_CS1_HIGH \
{\
	volatile kal_uint32 i;\
	GPIO_WriteIO(1,LCD_SPI_CS0); \
	for (i=0; i<LCD_SPI_CS1_DELAY; i++); \
}

#define LCD_SPI_SCLK_LOW \
{\
	volatile kal_uint32 i;\
	GPIO_WriteIO(0,LCD_SPI_SCLK); \
	for (i=0; i<LCD_SPI_SCLK_DELAY; i++); \
}
#define LCD_SPI_SCLK_HIGH \
{\
	volatile kal_uint32 i;\
	GPIO_WriteIO(1,LCD_SPI_SCLK); \
	for (i=0; i<LCD_SPI_SCLK_DELAY; i++); \
}

#define LCD_SPI_SDA_LOW \
{\
	volatile kal_uint32 i;\
	GPIO_WriteIO(0,LCD_SPI_SDA); \
	for (i=0; i<LCD_SPI_SDA_DELAY; i++); \
}
#define LCD_SPI_SDA_HIGH \
{\
	volatile kal_uint32 i;\
	GPIO_WriteIO(1,LCD_SPI_SDA); \
	for (i=0; i<LCD_SPI_SDA_DELAY; i++); \
}
// -panjun, 2015.04.21, Define some GPIOs for OLED.

/************************************************
* SPI
*************************************************/
typedef enum
{
  OPENAT_SPI_1,
  OPENAT_SPI_2,
  OPENAT_SPI_QTY
}E_AMOPENAT_SPI_PORT;

typedef struct T_AMOPENAT_SPI_MESSAGE_TAG
{
  E_OPENAT_DRV_EVT evtId;
  uint32    dataLen;
}T_AMOPENAT_SPI_MESSAGE;

typedef VOID (*PSPI_MESSAGE)(T_AMOPENAT_SPI_MESSAGE* spiMessage);

typedef struct
{
  BOOL          fullDuplex;                  /*TRUE: DI/DO FALSE: DO only*/
  BOOL          cpol;                        /*FALSE: spi_clk idle״̬Ϊ0 TRUE: spi_clk idle״̬Ϊ 1*/
  uint8         cpha;                        /*0~1 0:��һ��clk�������ش������ݣ�1:�ڶ���clk�����ش������� ...*/
  uint8         dataBits;                    /*4~32*/
  uint32        clock;                       /*110k~13M*/
  PSPI_MESSAGE  spiMessage;                  /*��ʱ��֧��*/
  BOOL          withCS;                      /*CS����֧��*/
}T_AMOPENAT_SPI_PARAM;

/************************************************
* I2C
*************************************************/
typedef enum E_AMOPENAT_I2C_PORT_TAG
{
/*+\NEW\zhuwangbin\2020.2.11\���openat i2c�ӿ�*/
    OPENAT_I2C_1,
    OPENAT_I2C_2,
    OPENAT_I2C_3,
/*-\NEW\zhuwangbin\2020.2.11\���openat i2c�ӿ�*/
    OPENAT_I2C_QTY
}E_AMOPENAT_I2C_PORT;

typedef struct T_AMOPENAT_I2C_MESSAGE_TAG
{
    E_OPENAT_DRV_EVT evtId;
    uint32    dataLen;
}T_AMOPENAT_I2C_MESSAGE;

typedef VOID (*PI2C_MESSAGE)(T_AMOPENAT_I2C_MESSAGE* i2cMessage);

typedef struct
{
    uint32          freq;           /*i2c�������� 100KHz\400KHz*/
    //uint8           slaveAddr;      /*i2c���豸��ַ (7bit) ��read write��ʱ������豸��ַ*/
    uint8           regAddrBytes;    /*i2c����Ĵ�����ַ�ֽ���*/ //�ݲ�֧��������Ϊ0 = 1�ֽ�
    BOOL            noAck;          /*�Ƿ�ȷ��ack*/      //�ݲ�֧��������ΪFALSE
    BOOL            noStop;         /*�Ƿ�ȷ�Ϸ�ֹͣλ*/ //�ݲ�֧��������ΪFALSE
    PI2C_MESSAGE    i2cMessage;     /*��ʱ��֧��*/
	/*+\NEW\cjc\2021.6.18\���i2c 2.4k������*/
    BOOL isbuad;/* �Զ��岨���ʿ��� */
	/*-\NEW\cjc\2021.6.18\���i2c 2.4k������*/
}T_AMOPENAT_I2C_PARAM;


typedef struct
{
    E_AMOPENAT_I2C_PORT   scl_port; 
    E_AMOPENAT_I2C_PORT   sda_port;
    u16                   slaveAddr;
}T_AMOPENAT_GPIO_I2C_PARAM;

/************************************************
* camera
*************************************************/
#define AMOPENAT_CAMERA_DELAY_CMD 0xffff /* 0xffff��ʾ��������һ����ʱָ�� */

#define AMOPENAT_CAMERA_REG_ADDR_8BITS      (0<<0)
#define AMOPENAT_CAMERA_REG_ADDR_16BITS     (1<<0)
#define AMOPENAT_CAMERA_REG_DATA_8BITS      (0<<1)
#define AMOPENAT_CAMERA_REG_DATA_16BITS     (1<<1)

typedef struct T_AMOPENAT_CAMERA_REG_TAG
{
    UINT16      addr;
    UINT16      value;
}AMOPENAT_CAMERA_REG, *PAMOPENAT_CAMERA_REG;

typedef enum E_AMOPENAT_CAMERA_IMAGE_FORMAT_TAG
{
    CAMERA_IMAGE_FORMAT_YUV422,

    NumOfOpenatCameraImageFormats
}E_AMOPENAT_CAMERA_IMAGE_FORMAT;

/*+\NEW\zhuwangbin\2020.4.26\���openat cam�ӿ�*/
typedef struct 
{
    E_AMOPENAT_GPIO_PORT camPdn;
    E_AMOPENAT_GPIO_PORT camRst;
    BOOL enable;
}OPENAT_CAMERA_PIN_CONFIG;

typedef enum
{
    OPENAT_SPI_MODE_NO = 0,         // parallel sensor in use
    OPENAT_SPI_MODE_SLAVE ,        // SPI sensor as SPI slave
    OPENAT_SPI_MODE_MASTER1,     // SPI sensor as SPI master, 1 sdo output with SSN 
    OPENAT_SPI_MODE_MASTER2_1, // SPI sensor as SPI master, 1 sdo output without SSN
    OPENAT_SPI_MODE_MASTER2_2, // SPI sensor as SPI master, 2 sdos output 
    OPENAT_SPI_MODE_MASTER2_4, // SPI sensor as SPI master, 4 sdos output
    OPENAT_SPI_MODE_UNDEF,
} OPENAT_CAMERA_SPI_MODE_E;

typedef enum
{
    OPENAT_SPI_OUT_Y0_U0_Y1_V0 = 0,
    OPENAT_SPI_OUT_Y0_V0_Y1_U0,
    OPENAT_SPI_OUT_U0_Y0_V0_Y1,
    OPENAT_SPI_OUT_U0_Y1_V0_Y0,
    OPENAT_SPI_OUT_V0_Y1_U0_Y0,
    OPENAT_SPI_OUT_V0_Y0_U0_Y1,
    OPENAT_SPI_OUT_Y1_V0_Y0_U0,
    OPENAT_SPI_OUT_Y1_U0_Y0_V0,
} OPENAT_CAMERA_SPI_YUV_OUT_E;

typedef struct 
{
    UINT16 *data; 
    int dataLen;
    BOOL isDataChannel;
}T_AMOPENAT_CAMERA_DATA_PARAM;

/*+\NEW\zhuwangbin\2020.7.11\���cam spi speedģʽ����*/
typedef enum
{
	OPENAT_SPI_SPEED_DEFAULT,
	OPENAT_SPI_SPEED_SDR, /*��������*/
	OPENAT_SPI_SPEED_DDR, /*˫������*/
	OPENAT_SPI_SPEED_QDR, /*�ı����� �ݲ�֧��*/
}OPENAT_SPI_SPEED_MODE_E;
/*-\NEW\zhuwangbin\2020.7.11\���cam spi speedģʽ����*/
	
typedef struct 
{
  E_OPENAT_DRV_EVT evtId;
  union
  {
    UINT16 videorecordFinishResult;  //OPENAT_DRV_EVT_VIDEORECORD_FINISH_IND ¼�ƽ���ϱ�
  }param;

  T_AMOPENAT_CAMERA_DATA_PARAM dataParam; // OPENAT_DRV_EVT_CAMERA_DATA_IND camera�����ϱ�
}T_AMOPENAT_CAMERA_MESSAGE;
/*-\NEW\zhuwangbin\2020.4.26\���openat cam�ӿ�*/
typedef void (*PCAMERA_MESSAGE)(T_AMOPENAT_CAMERA_MESSAGE *pMsg);

typedef struct T_AMOPENAT_CAMERA_PARAM_TAG
{
    /* ����ͷ/��Ƶ��Ϣ������ */
    PCAMERA_MESSAGE messageCallback;
    
    /* ����ͷI2C���� */
    E_AMOPENAT_I2C_PORT i2cPort;            /* ����ͷʹ�õ�i2c����id */
    UINT8       i2cSlaveAddr;               /* ����ͷi2c���ʵ�ַ */
    UINT8       i2cAddrDataBits;            /* ����ͷ�Ĵ�����ַ�Լ�����λ�� */

    /* ����ͷ��Ҫ�ź�����Ч�������� */
    BOOL        RSTBActiveLow;              /* pin RSTB ����Ч */
    BOOL        PWDNActiveLow;              /* pin PWDN ����Ч */
    BOOL        VSYNCActiveLow;             /* pin VSYNC ����Ч */

    /* ����ͷͼ���� */
    UINT16      sensorWidth;
    UINT16      sensorHeight;

    E_AMOPENAT_CAMERA_IMAGE_FORMAT imageFormat; /* ����ͷͼ���ʽ */
    
    PAMOPENAT_CAMERA_REG initRegTable_p;  /* ����ͷ��ʼ��ָ��� */
    UINT16 initRegTableCount;          /* ����ͷ��ʼ��ָ���� */

    AMOPENAT_CAMERA_REG idReg;          /* ����ͷID�Ĵ�����ֵ */
/*+\NEW\zhuwangbin\2020.4.26\���openat cam�ӿ�*/
    OPENAT_CAMERA_PIN_CONFIG cameraPin;
    UINT8 camClkDiv;
    OPENAT_CAMERA_SPI_MODE_E       spi_mode;
    OPENAT_CAMERA_SPI_YUV_OUT_E  spi_yuv_out;
    /*+\new\zhuwangbin\2018.9.6\֧��camera���и������ʹ��*/
    BOOL jumpEnable;
    /*-\new\zhuwangbin\2018.9.6\֧��camera���и������ʹ��*/
	OPENAT_SPI_SPEED_MODE_E spi_speed;
/*-\NEW\zhuwangbin\2020.4.26\���openat cam�ӿ�*/
	UINT16   mClk; //MCLK,��λM, Ĭ��0Ϊ24M
}T_AMOPENAT_CAMERA_PARAM;

// T_AMOPENAT_CAM_PREVIEW_PARAM.encodeQuality video encoding quality
#define OPENAT_VID_REC_QTY_LOW          0
#define OPENAT_VID_REC_QTY_NORMAL       1
#define OPENAT_VID_REC_QTY_HIGH         2
#define OPENAT_VID_REC_QTY_FINE         3

typedef struct T_AMOPENAT_CAM_PREVIEW_PARAM_TAG
{
    UINT16      startX;
    UINT16      startY;
    UINT16      endX;
    UINT16      endY;

    /* ��Ƶ¼�ƵĲ���,����Ԥ������������Щ���� */
    UINT16      recordAudio;  /* �Ƿ�¼�� */
    UINT16      filesizePermit;  //��KΪ��λ
    UINT16      timePermit;
    UINT16      encodeQuality;
	/*+\NEW\zhuwangbin\2020.7.20\���camera ��ת��������*/
	int 		rotation; //��ת�Ƕ����� ��ʱֻ֧��0��90��
	int 		zoom; //��������, �����Ŵ�����С�����4����0������
	/*-\NEW\zhuwangbin\2020.7.20\���camera ��ת��������*/
}T_AMOPENAT_CAM_PREVIEW_PARAM;

typedef struct T_AMOPENAT_CAM_CAPTURE_PARAM_TAG
{
    UINT16      imageWidth;
    UINT16      imageHeight;
	UINT16      quality;
}T_AMOPENAT_CAM_CAPTURE_PARAM;

/************************************************
* video
*************************************************/
typedef enum E_AMOPENAT_VIDEO_TYPE_TAG
{
    OPENAT_VIDEO_TYPE_MJPG,
    OPENAT_VIDEO_TYPE_RM,
    OPENAT_VIDEO_TYPE_MP4,
    OPENAT_VIDEO_TYPE_3GP,
    OPENAT_VIDEO_TYPE_AVSTRM,

    NumOfOpenatVideoTypes
}E_AMOPENAT_VIDEO_TYPE;

typedef struct T_AMOPENAT_VIDEO_MESSAGE_TAG
{
    E_OPENAT_DRV_EVT evtId;
    union
    {
      UINT32 playFinishResult;
      UINT32 currentTime;  // ��msΪ��λ
    }param;
}T_AMOPENAT_VIDEO_MESSAGE;

typedef void (*PVIDEO_MESSAGE)(T_AMOPENAT_VIDEO_MESSAGE *pMsg); 

typedef struct T_AMOPENAT_VIDEO_INFO_TAG
{
    UINT16 imageWidth;
    UINT16 imageHeight;
    UINT32 totalTime;
}T_AMOPENAT_VIDEO_INFO;

typedef struct T_AMOPENAT_VIDEO_PARAM_TAG
{
    PVIDEO_MESSAGE                  msgCallback;    /* ��Ƶ��Ϣ�ص����� */    
    INT32                           iFd;            /* ��Ƶ�ļ���� */
    E_AMOPENAT_VIDEO_TYPE           videoType;
}T_AMOPENAT_VIDEO_PARAM;

/************************************************
* AUDIO
*************************************************/
typedef enum
{
  OPENAT_AUD_TONE_DTMF_0,
  OPENAT_AUD_TONE_DTMF_1,
  OPENAT_AUD_TONE_DTMF_2,
  OPENAT_AUD_TONE_DTMF_3,
  OPENAT_AUD_TONE_DTMF_4,
  OPENAT_AUD_TONE_DTMF_5,
  OPENAT_AUD_TONE_DTMF_6,
  OPENAT_AUD_TONE_DTMF_7,
  OPENAT_AUD_TONE_DTMF_8,
  OPENAT_AUD_TONE_DTMF_9,
  OPENAT_AUD_TONE_DTMF_A,
  OPENAT_AUD_TONE_DTMF_B,
  OPENAT_AUD_TONE_DTMF_C,
  OPENAT_AUD_TONE_DTMF_D,
  OPENAT_AUD_TONE_DTMF_HASH,
  OPENAT_AUD_TONE_DTMF_STAR,
  OPENAT_AUD_TONE_DTMF_END
}E_AMOPENAT_DTMF_TYPE;

/*+\BUG\wangyuan\2020.06.08\BUG_2163:CSDK�ṩaudio��Ƶ���Žӿ�*/
typedef enum
{
  OPENAT_AUD_TONE_DIAL,
  OPENAT_AUD_TONE_BUSY,
  
  OPENAT_AUD_TONE_PATH_ACKNOWLEGEMENT,
  OPENAT_AUD_TONE_CALL_DROPPED,
  OPENAT_AUD_TONE_SPECIAL_INFO,
  OPENAT_AUD_TONE_CALL_WAITING,
  OPENAT_AUD_TONE_RINGING,
  OPENAT_AUD_TONE_END,
}E_AMOPENAT_TONE_TYPE;
/*-\BUG\wangyuan\2020.06.08\BUG_2163:CSDK�ṩaudio��Ƶ���Žӿ�*/

typedef enum {
    OPENAT_AUD_SPK_GAIN_MUTE = 0,     /// MUTE
    OPENAT_AUD_SPK_GAIN_0dB,    
    OPENAT_AUD_SPK_GAIN_3dB,    
    OPENAT_AUD_SPK_GAIN_6dB,   
    OPENAT_AUD_SPK_GAIN_9dB,   
    OPENAT_AUD_SPK_GAIN_12dB,
    OPENAT_AUD_SPK_GAIN_15dB,
    OPENAT_AUD_SPK_GAIN_18dB,
    /*+\BUG\wangyuan\2020.08.10\����ѡ���ȥ��������*/
    OPENAT_AUD_SPK_GAIN_NOT_SET,
    /*-\BUG\wangyuan\2020.08.10\����ѡ���ȥ��������*/
    OPENAT_AUD_SPK_GAIN_END,
}E_AMOPENAT_SPEAKER_GAIN;


/*+\NEW\xiongjunqun\2015.05.28\����ͨ���е��������ӿ�*/
typedef enum {
    OPENAT_AUD_SPH_VOL0,
    OPENAT_AUD_SPH_VOL1,
    OPENAT_AUD_SPH_VOL2,
    OPENAT_AUD_SPH_VOL3,
    OPENAT_AUD_SPH_VOL4,
    OPENAT_AUD_SPH_VOL5,
    OPENAT_AUD_SPH_VOL6,
    NumOfAMOPENATAudSPHVols
}E_AMOPENAT_AUD_SPH_VOL;
/*-\NEW\xiongjunqun\2015.05.28\����ͨ���е��������ӿ�*/

/*+\NEW\zhuwangbin\2020.8.11\��Ӷ����������*/
typedef enum
{
    OPENAT_AUD_HEADSET_PLUGOUT,
    OPENAT_AUD_HEADSET_INSERT4P,
    OPENAT_AUD_HEADSET_INSERT3P,
    OPENAT_AUD_HEADSET_TYPE_QTY
} E_OPENAT_AUD_HEADSET_TYPE;
/*-\NEW\zhuwangbin\2020.8.11\��Ӷ����������*/



/*+\new\wj\2020.9.19\lua��Ӷ����Զ���⹦�ܣ���ӿ����Ͷ����ϱ���Ϣ*/
typedef enum
{
    OPENAT_AUD_HEADSET_TYPE_UNKNOWN_MIC_TYPE,
    OPENAT_AUD_HEADSET_TYPE_NO_MIC,
    OPENAT_AUD_HEADSET_TYPE_4POLE_NORMAL,
    OPENAT_AUD_HEADSET_TYPE_4POLE_NOT_NORMAL,
    OPENAT_AUD_HEADSET_TYPE_APPLE,
    OPENAT_AUD_HEADSET_TYPE_ERR
} E_OPENAT_AUD_HEADSET_MIC_TYPE;

typedef enum
{
    OPENAT_AUD_HEADSET_DISCONNECT = 0,
    OPENAT_AUD_HEADSET_CONNECT = 1,
} E_OPENAT_AUD_HEADSET_STATUS;

typedef enum
{
    OPENAT_AUD_MSG_HEADSET_PLUGIN = 1,
    OPENAT_AUD_MSG_HEADSET_PLUGOUT = 2,
    OPENAT_AUD_MSG_HEADSET_BTN_DOWN = 3,
    OPENAT_AUD_MSG_HEADSET_BTN_UP = 4,
} E_OPENAT_AUD_HEADSET_NOTIFY_MSG;

typedef struct
{
    E_OPENAT_AUD_HEADSET_STATUS isplugin;
    E_OPENAT_AUD_HEADSET_MIC_TYPE mictype;
} OPENAT_HEADSET_STATUS_T;


typedef void (*OPENAT_HEADSET_NOTIFY_CB)(void *ctx, E_OPENAT_AUD_HEADSET_NOTIFY_MSG id, uint32 param);
/*-\new\wj\2020.9.19\lua��Ӷ����Զ���⹦�ܣ���ӿ����Ͷ����ϱ���Ϣ*/

typedef enum 
{
    OPENAT_AUD_PLAY_ERR_NO,
    OPENAT_AUD_PLAY_ERR_UNKNOWN_FORMAT,
    OPENAT_AUD_PLAY_ERR_BUSY,
    OPENAT_AUD_PLAY_ERR_INVALID_PARAMETER,
    OPENAT_AUD_PLAY_ERR_ACTION_NOT_ALLOWED,
    OPENAT_AUD_PLAY_ERR_OUT_OF_MEMORY,
    OPENAT_AUD_PLAY_ERR_CANNOT_OPEN_FILE,         		           
    OPENAT_AUD_PLAY_ERR_END_OF_FILE,	     
    OPENAT_AUD_PLAY_ERR_TERMINATED,		   
    OPENAT_AUD_PLAY_ERR_BAD_FORMAT,	      
    OPENAT_AUD_PLAY_ERR_INVALID_FORMAT,   
    OPENAT_AUD_PLAY_ERR_ERROR,
	/*+\NEW\zhuwangbin\2020.05.15\����speex��ʽ��¼���Ͳ���*/
    OPENAT_AUD_SPX_ERR_DATA_LONG,
    OPENAT_AUD_SPX_ERR_DATA_FORMAT,
	/*-\NEW\zhuwangbin\2020.05.15\����speex��ʽ��¼���Ͳ���*/
} E_AMOPENAT_PLAY_ERROR;


typedef enum 
{
    OPENAT_AUD_REC_ERR_NONE = 0,
	OPENAT_AUD_REC_ERR_NOT_ALLOW ,
	OPENAT_AUD_REC_ERR_NO_MEMORY,
	OPENAT_AUD_REC_ERR_EXE_FAIL,
	OPENAT_AUD_REC_ERR_PARAM,	               
} E_AMOPENAT_RECORD_ERROR;

typedef enum
{
    OPENAT_AUD_PLAY_MODE_AMR475,
    OPENAT_AUD_PLAY_MODE_AMR515,
    OPENAT_AUD_PLAY_MODE_AMR59,
    OPENAT_AUD_PLAY_MODE_AMR67,
    OPENAT_AUD_PLAY_MODE_AMR74,
    OPENAT_AUD_PLAY_MODE_AMR795,
    OPENAT_AUD_PLAY_MODE_AMR102,
    OPENAT_AUD_PLAY_MODE_AMR122,
    OPENAT_AUD_PLAY_MODE_FR,
    OPENAT_AUD_PLAY_MODE_HR,
    OPENAT_AUD_PLAY_MODE_EFR,
    OPENAT_AUD_PLAY_MODE_PCM,
    OPENAT_AUD_PLAY_MODE_AMR_RING,
    OPENAT_AUD_PLAY_MODE_MP3,
    OPENAT_AUD_PLAY_MODE_AAC,
    OPENAT_AUD_PLAY_MODE_WAV,
    OPENAT_AUD_PLAY_MODE_STREAM_PCM, //for TTS stream play
    /*+\BUG WM-669\lifei\2013.06.09\[OpenAT] ֧��MIDI����*/
    OPENAT_AUD_PLAY_MODE_MIDI,
    /*-\BUG WM-669\lifei\2013.06.09\[OpenAT] ֧��MIDI����*/
    OPENAT_AUD_PLAY_MODE_QTY,
} E_AMOPENAT_PLAY_MODE;

typedef enum
{
    OPENAT_AUDIOHAL_ITF_RECEIVER =0,     
    OPENAT_AUDIOHAL_ITF_EARPIECE,    
	/*+\new\wj\2020.4.22\֧����Ƶͨ���л��ӿ�*/
    OPENAT_AUDIOHAL_ITF_LOUDSPEAKER, 
    OPENAT_AUD_CHANNEL_DUMMY_AUX_HANDSET
    #if 0
	OPENAT_AUDIOHAL_ITF_LOUDSPEAKER,   
	OPENAT_ITF_LOUDSPEAKER_AND_HEADPHONE, 
	
	OPENAT_AUDIOHAL_ITF_BLUETOOTH,       
	OPENAT_AUDIOHAL_ITF_FM,          
    OPENAT_AUDIOHAL_ITF_FM2SPK,    
    OPENAT_AUDIOHAL_ITF_TV, 
    
    OPENAT_AUDIOHAL_ITF_QTY,    												
	OPENAT_AUDIOHAL_ITF_NONE = 255,         
	OPENAT_AUD_CHANNEL_DUMMY_AUX_HANDSET,     
	#endif
	/*-\new\wj\2020.4.22\֧����Ƶͨ���л��ӿ�*/
}E_AMOPENAT_AUDIO_CHANNEL;

/*+\new\zhuwangbin\2020.6.2\�����Ƶ�����������ýӿ�*/
typedef enum
{
    OPENAT_SPKPA_TYPE_CLASSAB,
    OPENAT_INPUT_TYPE_CLASSD,
    OPENAT_INPUT_TYPE_CLASSK,
    OPENAT_SPKPA_INPUT_TYPE_QTY = 0xFF000000
} OPENAT_SPKPA_TYPE_T;
/*-\new\zhuwangbin\2020.6.2\�����Ƶ�����������ýӿ�*/

/*+\bug2767\zhuwangbin\2020.8.5\����ⲿpa���ýӿ�*/
typedef struct 
{
	BOOL enable;
	UINT16 gpio;
	UINT16 count;
	UINT16 us;
	E_AMOPENAT_AUDIO_CHANNEL outDev;
}OPENAT_EXPA_T;
/*-\bug2767\zhuwangbin\2020.8.5\����ⲿpa���ýӿ�*/
/*+\BUG\wangyuan\2020.11.27\BUG_3634����Luat�汾�Ͽ���������mic����ͨ�����Ľӿ�*/
typedef enum
{
    OPENAT_AUDEV_INPUT_MAINMIC = 0, ///< main mic
    OPENAT_AUDEV_INPUT_AUXMIC = 1,  ///< auxilary mic
    OPENAT_AUDEV_INPUT_DUALMIC = 2, ///< dual mic
    OPENAT_AUDEV_INPUT_HPMIC_L = 3, ///< headphone mic left
    OPENAT_AUDEV_INPUT_HPMIC_R = 4, ///< headphone mic right
} E_AMOPENAT_MIC_CHANNEL;
/*-\BUG\wangyuan\2020.11.27\BUG_3634����Luat�汾�Ͽ���������mic����ͨ�����Ľӿ�*/

typedef void (*AUD_PLAY_CALLBACK_T)(E_AMOPENAT_PLAY_ERROR result);

typedef void (*AUD_RECORD_CALLBACK_T)(E_AMOPENAT_RECORD_ERROR result);

/*+\NEW\shenyuanyuan\2019.12.11\���MP3����AT+PLAY��AT+STOP ��AT+SOUNDLVLָ��*/
typedef void (*MUSIC_PLAY_CALLBACK_T)(const char *file_name, int ret);
/*-\NEW\shenyuanyuan\2019.12.11\���MP3����AT+PLAY��AT+STOP ��AT+SOUNDLVLָ��*/
/*+\new\wj\2020.4.26\ʵ��¼���ӿ�*/
/*+\BUG\wangyuan\2020.07.31\BUG_2736:CSDK ���ƶԽ������� ֧����¼��*/
typedef void (*AUD_STREAM_RECORD_CALLBACK_T)(int ret, char *data, int len);
/*-\BUG\wangyuan\2020.07.31\BUG_2736:CSDK ���ƶԽ������� ֧����¼��*/
/*-\new\wj\2020.4.26\ʵ��¼���ӿ�*/
/*+\����\czm\2020.9.20\����:439 ����POC��Ŀ����:�����¼���������Žӿڣ�����Ҫ֧������������㷨*/
typedef enum
{
    /**
     * Placeholder for not in playing.
     */
    OPENAT_AUD_PLAY_TYPE_NONE = 0,
    /**
     * ���ű�����Ƶ·����
     */
    OPENAT_AUD_PLAY_TYPE_LOCAL,
    /**
     * ������ͨ���в��ŵ��Զˡ�
     */
    OPENAT_AUD_PLAY_TYPE_VOICE,
    /**
     * ��pocģʽ�²��ű�����Ƶ·����poc���벥�š�
     */
    OPENAT_AUD_PLAY_TYPE_POC,
}E_AMOPENAT_AUD_PLAY_TYPE;
/*-\����\czm\2020.9.20\����:439 ����POC��Ŀ����:�����¼���������Žӿڣ�����Ҫ֧������������㷨*/
/*+\NewReq WM-702\maliang\2013.3.15\������Ƶ�ļ��Ľӿ�����һ��������������ʾ�ļ�����*/
typedef enum E_AMOPENAT_AUD_FORMAT_TAG
{
    OPENAT_AUD_FORMAT_UNKNOWN, ///< placeholder for unknown format
    OPENAT_AUD_FORMAT_PCM,     ///< raw PCM data
    OPENAT_AUD_FORMAT_WAVPCM,  ///< WAV, PCM inside
    OPENAT_AUD_FORMAT_MP3,     ///< MP3
    OPENAT_AUD_FORMAT_AMRNB,   ///< AMR-NB
    OPENAT_AUD_FORMAT_AMRWB,   ///< AMR_WB
	/*+\NEW\zhuwangbin\2020.05.15\����speex��ʽ��¼���Ͳ���*/
    OPENAT_AUD_FORMAT_SPEEX,
	/*-\NEW\zhuwangbin\2020.05.15\����speex��ʽ��¼���Ͳ���*/
	/*+\wj\new\2020.10.16\���rtmp����ATָ���luaʹ�ýӿ�*/
	OPENAT_AUD_FORMAT_RTMP,
	/*-\wj\new\2020.10.16\���rtmp����ATָ���luaʹ�ýӿ�*/
    OPENAT_AUD_FORMAT_QTY,
}E_AMOPENAT_AUD_FORMAT;
/*-\NewReq WM-702\maliang\2013.3.15\������Ƶ�ļ��Ľӿ�����һ��������������ʾ�ļ�����*/

typedef enum E_AMOPENAT_RECORD_TYPE_TAG
{
    OPENAT_RECORD_TYPE_NONE, ///< ����δ֪��ʽ��ռλ��
    OPENAT_RECORD_TYPE_MIC,     ///����˷�¼�ơ� 
    OPENAT_RECORD_TYPE_VOICE,  ///¼������ͨ����¼�Ƶ�����������ͨ����
    OPENAT_RECORD_TYPE_VOICE_DUAL,     //¼������ͨ����¼�Ƶ����Ǵ��з����������·��������·�ŵ���
    OPENAT_RECORD_TYPE_DEBUG_DUMP, //PCMת���������ڵ��ԡ�
/*+\����\czm\2020.9.20\����:439 ����POC��Ŀ����:�����¼���������Žӿڣ�����Ҫ֧������������㷨*/
    OPENAT_RECORD_TYPE_POC,//��pocģʽ�´���˷�¼�ơ�
/*-\����\czm\2020.9.20\����:439 ����POC��Ŀ����:�����¼���������Žӿڣ�����Ҫ֧������������㷨*/
}E_AMOPENAT_RECORD_TYPE;

typedef enum E_AMOPENAT_RECORD_QUALITY_TAG
{
    OPENAT_RECORD_QUALITY_LOW,    ///< ������
    OPENAT_RECORD_QUALITY_MEDIUM, ///< ������
    OPENAT_RECORD_QUALITY_HIGH,   ///< ������
    OPENAT_RECORD_QUALITY_BEST,   ///< �������
} E_AMOPENAT_RECORD_QUALITY;

typedef enum 
{
	OPENAT_RECORD_FILE,
	OPENAT_RECORD_STREAM,
}OpenatRecordMode_t;

typedef struct
{
	char *fileName;//���ñ����ļ����ļ��������ʹ����������ʽ��ȡ���ݣ���������Ч
	int time_sec;//����¼���ĳ���ʱ�䡣ʱ��һ����ֹͣ
	OpenatRecordMode_t record_mode;//�������ݵĻ�ȡ��ʽ
	E_AMOPENAT_RECORD_QUALITY quality;//����¼��������
	E_AMOPENAT_RECORD_TYPE type;//����¼��������
	E_AMOPENAT_AUD_FORMAT format;//�������ݵĸ�ʽ
	AUD_STREAM_RECORD_CALLBACK_T stream_record_cb;//�����������ص�����
	/*+\bug2241\zhuwangbin\2020.6.20\��¼�������ûص����ȷ�ֵ*/
	int thresholdLength; //¼�����ݴﵽһ���ĳ��Ⱦ��ϱ�
	/*-\bug2241\zhuwangbin\2020.6.20\��¼�������ûص����ȷ�ֵ*/
	int buffLen;
}E_AMOPENAT_RECORD_PARAM;

typedef enum
{
    OPENAT_AUDEV_OUTPUT_RECEIVER = 0,  ///< receiver
    OPENAT_AUDEV_OUTPUT_HEADPHONE = 1, ///< headphone
    OPENAT_AUDEV_OUTPUT_SPEAKER = 2,   ///< speaker
} E_AMOPENAT_AUDIO_OUTPUT_T;

typedef struct T_AMOPENAT_PLAY_BUFFER_PARAM_TAG
{
    char *pBuffer;
    UINT32 len;
    UINT8 loop;
    AUD_PLAY_CALLBACK_T callback;
    E_AMOPENAT_AUD_FORMAT  format;
}T_AMOPENAT_PLAY_BUFFER_PARAM;


typedef struct T_AMOPENAT_PLAY_FILE_PARAM_TAG
{
/*+\BUG WM-719\maliang\2013.3.21\�ļ�ϵͳ�ӿںͲ�����Ƶ�ļ��ӿڵ��ļ�����Ϊunicode little ending����*/
    char* fileName;        /* �ļ���ʹ��unicode���� little endian��ʽ��ʾ */
/*-\BUG WM-719\maliang\2013.3.21\�ļ�ϵͳ�ӿںͲ�����Ƶ�ļ��ӿڵ��ļ�����Ϊunicode little ending����*/
/*+\NewReq WM-702\maliang\2013.3.15\������Ƶ�ļ��Ľӿ�����һ��������������ʾ�ļ�����*/
    E_AMOPENAT_AUD_FORMAT  fileFormat;
/*-\NewReq WM-702\maliang\2013.3.15\������Ƶ�ļ��Ľӿ�����һ��������������ʾ�ļ�����*/
    AUD_PLAY_CALLBACK_T callback;
}T_AMOPENAT_PLAY_FILE_PARAM;

typedef struct  T_AMOPENAT_PLAY_PARAM_TAG
{
      BOOL  playBuffer;/*�ǲ���buffer���ǲ����ļ�*/
      union
      {
           T_AMOPENAT_PLAY_BUFFER_PARAM       playBufferParam;
           T_AMOPENAT_PLAY_FILE_PARAM        playFileParam;
      };
}T_AMOPENAT_PLAY_PARAM;
/*-\NewReq WM-584\maliang\2013.2.21\[OpenAt]֧��T������MP3*/

/*+\NewReq WM-710\maliang\2013.3.18\ [OpenAt]���ӽӿ�����MP3���ŵ���Ч*/
typedef enum  E_AMOPENAT_AUDIO_SET_EQ_TAG
{
    OPENAT_AUD_EQ_NORMAL,     
    OPENAT_AUD_EQ_BASS,    
    OPENAT_AUD_EQ_DANCE,
    OPENAT_AUD_EQ_CLASSICAL,
    OPENAT_AUD_EQ_TREBLE,
    OPENAT_AUD_EQ_PARTY,
    OPENAT_AUD_EQ_POP,
    OPENAT_AUD_EQ_ROCK
}E_AMOPENAT_AUDIO_SET_EQ;
/*-\NewReq WM-710\maliang\2013.3.18\ [OpenAt]���ӽӿ�����MP3���ŵ���Ч*/

/*+\NewReq WM-711\maliang\2013.3.18\[OpenAt]���ӽӿڴ򿪻�ر���Ƶ�ػ�����*/
typedef enum  E_AMOPENAT_AUDIO_LOOPBACK_TYPE_TAG
{
    OPENAT_AUD_LOOPBACK_HANDSET,
    OPENAT_AUD_LOOPBACK_EARPIECE,
    OPENAT_AUD_LOOPBACK_LOUDSPEAKER,
/*+\NewReq WM-862\maliang\2013.7.2\ ����at+audlb������Ƶ�ػ�*/
    OPENAT_AUD_LOOPBACK_AUX_HANDSET,
    OPENAT_AUD_LOOPBACK_AUX_LOUDSPEAKER
/*-\NewReq WM-862\maliang\2013.7.2\ ����at+audlb������Ƶ�ػ�*/
}E_AMOPENAT_AUDIO_LOOPBACK_TYPE;
/*-\NewReq WM-711\maliang\2013.3.18\[OpenAt]���ӽӿڴ򿪻�ر���Ƶ�ػ�����*/

/*************************************************
* PSAM
*************************************************/
typedef enum
{
  OPENAT_PSAM_SUCCESS,                      /*�����ɹ�*/
  OPENAT_PSAM_ERR_EXTRA_RXATA,              /*���յ���������*/
  OPENAT_PSAM_ERR_BAT_ATR,                  /*��λATR����*/
  OPENAT_PSAM_ERR_RESET_TIMEOUT,            /*��λӦ��ʱ*/
  OPENAT_PSAM_ERR_PARITY,                   /*������żУ�����*/
  OPENAT_PSAM_ERR_WWT_TIMEOUT,              /*���ݴ���ʧ��*/
  OPENAT_PSAM_ERR_RCV_TIMEOUT,              /*���ݽ��ճ�ʱ*/
  OPENAT_PSAM_ERR_INVALID_PARAM,            /*�ӿڲ�������*/
  OPENAT_PSAM_ERR_DEV_BUSY,                 /*�豸æ*/
  OPENAT_PSAM_ERR_HW_SWITCH,                /*Ӳ���Ѿ��л�����Ŀ��Ϸ���*/
  OPENAT_PSAM_ERR_OTHER                     /*��������*/
}E_AMOPENAT_PSAM_OPER_RESULT;
typedef enum
{
  OPENAT_PSAM_ID_1,                         /* ����SIM0��ΪPSAM���ӿ� */
  OPENAT_PSAM_ID_2,                         /* ����SIM2��ΪPSAM���ӿ� */
  OPENAT_PSAM_ID_INVALID
}E_AMOPENAT_PSAM_ID;
typedef enum
{
  OPENAT_PSAM_VOLT_1_8V,                    /* 1.8V */
  OPENAT_PSAM_VOLT_3V,                      /* 3V */
  OPENAT_PSAM_VOLT_5V,                      /* 5V */
  OPENAT_PSAM_VOLT_INVALID
}E_AMOPENAT_PSAM_VOLT_CLASS;

/*+\BUG WM-690\rufei\2013.3.18\AT+SPWMû��ʵ��PWM1��PWM2*/
/*************************************************
* PWM
*************************************************/
/*+\bug\wj\2020.4.30\lua���pwm�ӿ�*/
typedef enum
{
    PWM_LGP_PER_125MS,
    PWM_LGP_PER_250MS,
    PWM_LGP_PER_500MS,
    PWM_LGP_PER_1000MS,
    PWM_LGP_PER_1500MS,
    PWM_LGP_PER_2000MS,
    PWM_LGP_PER_2500MS,
    PWM_LGP_PER_3000MS,
    OPENAT_PWM_LPG_PER_QTY
}E_OPENAT_PWM_LPG_PERIOD;

typedef enum 
{
    PWM_LGP_ONTIME_UNDEFINE,
    PWM_LGP_ONTIME_15_6MS,
    PWM_LGP_ONTIME_31_2MS,
    PWM_LGP_ONTIME_46_8MS,
    PWM_LGP_ONTIME_62MS,
    PWM_LGP_ONTIME_78MS,
    PWM_LGP_ONTIME_94MS,
    PWM_LGP_ONTIME_110MS,
    PWM_LGP_ONTIME_125MS,
    PWM_LGP_ONTIME_140MS,
    PWM_LGP_ONTIME_156MS,
    PWM_LGP_ONTIME_172MS,
    PWM_LGP_ONTIME_188MS,
    PWM_LGP_ONTIME_200MS,
    PWM_LGP_ONTIME_218MS,
    PWM_LGP_ONTIME_234MS,
    OPENAT_PWM_LPG_ON_QTY
}E_OPENAT_PWM_LPG_ON;


/*+\NEW\RUFEI\2015.9.8\Add pwm function */
typedef enum
{
	OPENAT_PWM_PWT_OUT, //gpio_5
	OPENAT_PWM_LPG_OUT, //gpio_13
	OPENAT_PWM_PWL_OUT0, //gpio_4
	OPENAT_PWM_PWL_OUT1, //gpio_7
	OPENAT_PWM_INVALID_PARAM
}E_AMOPENAT_PWM_PORT;
/*-\NEW\RUFEI\2015.9.8\Add pwm function */
/*+\BUG\wangyuan\2020.07.29\BUG_2663:��������ο�2G CSDK����iot_debug_set_fault_mode�ӿ�*/
typedef enum openatFaultModeE
{
	/*!< �쳣������Ĭ��״̬*/
	OPENAT_FAULT_RESET,
	/*!< �쳣����ģʽ*/
	OPENAT_FAULT_HANG
}E_OPENAT_FAULT_MODE;
/*-\BUG\wangyuan\2020.07.29\BUG_2663:��������ο�2G CSDK����iot_debug_set_fault_mode�ӿ�*/

typedef struct
{
    UINT32 onTimems; //0->forever
    E_AMOPENAT_PWM_PORT port;
    union
    {
        struct pwm_pwt{
        	UINT16  level;
        	UINT16  freq;
          UINT16 	clk_div ; /*pwm�ķ�Ƶϵ��*/
        }pwt,pwl;/*ע��:ʹ��PWLʵ�ַ�����ʱ��freqʵ����Ч��Χ:0-0xff*/
        struct pwm_lpg{
        	E_OPENAT_PWM_LPG_PERIOD period;
        	E_OPENAT_PWM_LPG_ON     onTime;
        }lpg;
    }cfg;
}T_AMOPENAT_PWM_CFG;
/*-\BUG WM-690\rufei\2013.3.18\AT+SPWMû��ʵ��PWM1��PWM2*/
/*-\bug\wj\2020.4.30\lua���pwm�ӿ�*/

typedef struct T_AMOPENAT_ALARM_MESSAGE_TAG
{
  E_OPENAT_DRV_EVT evtId;
  union
  {
    uint16  alarmIndex;/*mtkֻ��֧��1��alram��Ĭ��indexΪ0*/
  }param;  
}T_AMOPENAT_ALARM_MESSAGE;

typedef VOID (*PALARM_MESSAGE)(T_AMOPENAT_ALARM_MESSAGE *pAlarmMessage);

typedef struct T_AMOPENAT_ALARM_CONFIG_TAG
{
    PALARM_MESSAGE pAlarmMessageCallback;
}T_AMOPENAT_ALARM_CONFIG;


/*+\NewReq WM-725\xiongjunqun\2013.3.25\ [OpenAt]����FM�ӿ�*/
typedef enum
{
    /// 87.5-108 MHz    (US/Europe)
    OPENAT_FM_BAND_US_EUROPE = 0,
    /// 76-91 MHz       (Japan)
    OPENAT_FM_BAND_JAPAN,
    /// 76-108 MHz      (World Wide)
    OPENAT_FM_BAND_WORLD,
    /// 65-76 MHz       (East Europe)
    OPENAT_FM_BAND_EAST_EUROPE,

    OPENAT_FM_BAND_QTY
} E_AMOPENAT_FM_BAND;

typedef enum
{
    OPENAT_FM_MUTE = 0,
    OPENAT_FM_VOL_1,
    OPENAT_FM_VOL_2,
   	OPENAT_FM_VOL_3,
    OPENAT_FM_VOL_4,
    OPENAT_FM_VOL_5,
    OPENAT_FM_VOL_6,
   	OPENAT_FM_VOL_7,

    OPENAT_FM_VOL_QTY
} E_AMOPENAT_FM_VOL_LEVEL;


typedef struct
{
    /// FM Frequency(KHZ)
    UINT32              freqKHz;
    /// Volume
    E_AMOPENAT_FM_VOL_LEVEL     volume;
    /// Enable/Disable Bass Boost
    BOOL                bassBoost;
    /// Enable/Disable Mono output of stereo radios
    BOOL                forceMono;
} T_AMOPENAT_FM_INIT;

typedef struct 
{
  E_OPENAT_DRV_EVT evtId;
  struct
  {
  	UINT32 freqKHz; 
  	BOOL found;
  	BOOL stereo;
  }param;
}T_AMOPENAT_FM_MESSAGE;

typedef void (*PFM_MESSAGE)(UINT32 freq, BOOL found, BOOL stereoStatus);

typedef struct T_AMOPENAT_FM_PARAM_TAG
{

    PFM_MESSAGE messageCallback;
    E_AMOPENAT_FM_BAND fmBand;
	T_AMOPENAT_FM_INIT fmInit;
}T_AMOPENAT_FM_PARAM;
/*-\NewReq WM-725\xiongjunqun\2013.3.25\ [OpenAt]����FM�ӿ�*/


typedef VOID (*PINBANDINFO_CALLBACK)(void);

/*+\NEW\brezen\2013.12.30\��������ӿ�*/
#define OPENAT_BT_NAME_MAX_LEN (59)
#define OPENAT_BT_PB_LENGHT     (20)  
#define OPENAT_BT_MAX_SDAP_UUID_NO (15)
#define OPENAT_BT_MAX_PHONE_NUMBER 48

#define OPENAT_BT_SUPPORT_SPP_PROFILE (1<<0)
#define OPENAT_BT_SUPPORT_HFP_PROFILE (1<<1)
#define OPENAT_BT_SUPPORT_PBAP_PROFILE (1<<2)

/*app��������*/
typedef enum
{
  OPENAT_BT_MGR_DISCORY_REQ_CMD,
  OPENAT_BT_MGR_DISCORY_CANCEL_CMD,
  OPENAT_BT_MGR_SET_SCANNABLE_CMD,
  OPENAT_BT_MGR_READ_LOCAL_ADDR_CMD,
  OPENAT_BT_MGR_WRITE_LOCAL_NAME_CMD,
  OPENAT_BT_MGR_SLEEP_MODE_CMD,

  OPENAT_BT_BM_BONDING_REQ_CMD,
  OPENAT_BT_BM_DEBOND_REQ_CMD,
  OPENAT_BT_PBAP_CON_REQ_CMD,
  OPENAT_BT_PBAP_GET_NEXT_REQ_CMD,
  OPENAT_BT_PBAP_DISCON_REQ_CMD,

  OPENAT_BT_HFG_CONNECT_REQ,
  OPENAT_BT_HFG_DISCONNECT_REQ,
  OPENAT_BT_HFG_DIAL_REQ,
  OPENAT_BT_HFG_HUNGUP_REQ,
  OPENAT_BT_HFG_CALL_ANSWER_REQ,
  OPENAT_BT_HFG_SEND_DTMF_REQ,
  OPENAT_BT_HFG_PLAY_SCO_AUDIO_REQ,
  OPENAT_BT_HFG_CONNECT_SCO_AUDIO_REQ,
  OPENAT_BT_HFG_SET_MIC_GAIN_REQ,

  /*for cmu test*/
  OPENAT_BT_TEST_POWERON_REQ,
  OPENAT_BT_TEST_POWEROFF_REQ,
  OPENAT_BT_TEST_VOC_REQ,
  OPENAT_BT_TEST_DUT_REQ,
  OPENAT_BT_TEST_SINGLEHOP_REQ
  
  
}E_AMOPENAT_BT_CMD;
/*app��BT����Ӧ*/
typedef enum
{
  OPENAT_BT_MGR_LINK_ACCEPT_RSP,
  OPENAT_BT_MGR_PIN_CODE_RSP,

  OPENAT_BT_MAX_RSP
  
}E_AMOPENAT_BT_RSP;

/*BT�����ϱ�����BT��ӦAPP����*/
typedef enum
{
  OPENAT_BT_POWER_ON_IND,
  OPENAT_BT_BM_WRITE_SCANENABLE_MODE_CNF,
  OPENAT_BT_BM_READ_LOCAL_ADDR_CNF,
  OPENAT_BT_BM_WRITE_LOCAL_NAME_CNF,
  OPENAT_BT_BM_LINK_CONNECT_ACCEPT_IND,
  OPENAT_BT_BM_PIN_CODE_IND,
  OPENAT_BT_BM_BONDING_RESULT_IND,
  OPENAT_BT_BM_DEBOND_CNF,
  OPENAT_BT_BM_DISCOVERY_RESULT_IND,
  OPENAT_BT_BM_DISCOVERY_CNF,
  OPENAT_BM_BM_DISCOVERY_CANCEL_CNF,

  OPENAT_BT_PBAP_DATA_IND,
  OPENAT_BT_PBAP_DISCON_CNF,

  OPENAT_BT_HFG_CONNECT_IND,
  OPENAT_BT_HFG_CONNECT_CNF,
  OPENAT_BT_HFG_DISCONNECT_IND,
  OPENAT_BT_HFG_DISCONNECT_CNF,
  OPENAT_BT_HFG_SCO_CON_CNF,
  OPENAT_BT_HFG_SCO_DISCON_CNF,
  OPENAT_BT_PHONE_CALL_INFO_IND,
  OPENAT_BT_HFG_SCO_INFO_IND,

  OPENAT_BT_SPP_CONNECT,
  OPENAT_BT_SPP_DISCONNECT,
  OPENAT_BT_SPP_DISCONNECT_CNF,
  OPENAT_BT_SPP_CONNECT_CNF,
  OPENAT_BT_SPP_DATA_IND,
  OPENAT_BT_SPP_SEND_DATA_CNF,

  OPENAT_BT_POWER_OFF_IND,

  OPENAT_BT_DRV_EVENT_INVALID
}E_AMOPENAT_BT_EVENT;

typedef enum
{
  OPENAT_BTBM_ADP_P_OFF_I_OFF = 0,
  OPENAT_BTBM_ADP_P_OFF_I_ON,
  OPENAT_BTBM_ADP_P_ON_I_OFF,
  OPENAT_BTBM_ADP_P_ON_I_ON,
  OPENAT_BTBM_ADP_P_ON_I_ON_L
}E_AMOPENAT_BT_SCANNABLE;

typedef enum
{
	OPENAT_PBAP_DISCON_SUCCSEE,
	OPENAT_PBAP_DISCON_OPPER_UNSUPPORT,
	OPENAT_PBAP_DISCON_OPPER_NOT_ACCEPT
	
}E_AMOPENAT_BT_PBAP_DISCON_STATUS;


typedef struct
{
  UINT8	    name_len;
  UINT8	    name[OPENAT_BT_NAME_MAX_LEN];
}T_AMOPENAT_BT_NAME;
typedef struct
{
  UINT32   addrLap;
  UINT8    addrUap;
  UINT16   addrNap;
}T_AMOPENAT_BT_ADDR;


typedef struct
{
	UINT16 name[OPENAT_BT_PB_LENGHT];
	UINT8 name_length;

	UINT8 phone_num[OPENAT_BT_PB_LENGHT];
	UINT8 call_type;
	UINT8 data_time[17];

}T_AMOPENAT_BT_PBAP_CALL_HISTORY;

typedef struct
{
	UINT16 name[OPENAT_BT_PB_LENGHT];
	UINT8 name_length;
	UINT8 phone_num[3][OPENAT_BT_PB_LENGHT];

}T_AMOPENAT_BT_PBAP_INFO;

typedef union
{
	T_AMOPENAT_BT_PBAP_CALL_HISTORY history_info_array[10];
	T_AMOPENAT_BT_PBAP_INFO         pbap_info_array[10];

}U_AMOPENAT_BT_PBAP_ITEM_ARRAY;


/*BT_BM_WRITE_SCANENABLE_MODE_CNF*/
typedef struct
{
    UINT8	result;
}T_AMOPENAT_BT_WRITE_SCANNABLE_MODE_CNF;

/*BT_BM_READ_LOCAL_ADDR_CNF*/
typedef struct
{
    UINT8	         result;
    T_AMOPENAT_BT_ADDR  bd_addr;
}T_AMOPENAT_BT_READ_LOCAL_ADDR_CNF;

/*BT_BM_WRITE_LOCAL_NAME_CNF*/
typedef struct
{
    UINT8	result;
}T_AMOPENAT_BT_WRITE_LOCAL_NAME_CNF;

/*BT_BM_LINK_CONNECT_ACCEPT_IND*/
typedef struct
{
    T_AMOPENAT_BT_ADDR	bd_addr;
}T_AMOPENAT_BT_LINK_CONNECT_ACCEPT_IND;

/*BT_BM_PIN_CODE_IND*/
typedef struct
{
    T_AMOPENAT_BT_ADDR	bd_addr;
    UINT8	name_len;
    UINT8	name[OPENAT_BT_NAME_MAX_LEN];
}T_AMOPENAT_BT_BM_PIN_CODE_INT;

/*BT_BM_BONDING_RESULT_IND*/
typedef struct
{
    UINT8           result;
    T_AMOPENAT_BT_ADDR	bd_addr;
    UINT8	KeyType;
    UINT8  linkKey[0x10]; //support linkkey store in MMI	
    UINT32  cod;
}T_AMOPENAT_BT_BONDING_RESULT_IND;
typedef struct
{
  UINT8 result;
  T_AMOPENAT_BT_ADDR bd_addr;
}T_AMOPENAT_BT_DEBOND_CNF;
/*BT_PBAP_DATA_IND*/
typedef struct
{
	UINT8 	        con_type;//0 phone book; 1 combined call historys
	UINT32          tid;
	UINT8           status;
	UINT16          current_item_num;
	UINT16          all_item_num;
	U_AMOPENAT_BT_PBAP_ITEM_ARRAY  pbap_data_array;
	UINT8           is_spp_ind;
}T_AMOPENAT_BT_PBAP_BT_DATA_IND;

/*OPENAT_BT_PBAP_DISCON_CNF*/
typedef struct
{
	UINT8 con_type;//0 phone book; 1 combined call historys
	UINT32 tid;
	E_AMOPENAT_BT_PBAP_DISCON_STATUS status;
}T_AMOPENAT_BT_PBAP_CON_DISCON_INFO;

/*BT_BM_DISCOVERY_RESULT_IND*/
typedef struct  
{
    T_AMOPENAT_BT_ADDR bd_addr;
    UINT32	cod;
    UINT8	name_len;
    UINT8	name[OPENAT_BT_NAME_MAX_LEN];
}T_AMOPENAT_BT_BM_DISCOVERY_RESULT_IND;

/*BT_BM_DISCOVERY_CNF*/
typedef struct
{
    UINT8	result;
    UINT8	total_number;
}T_AMOPENAT_BT_BM_DISCOVERY_CNF;
/*BM_BM_DISCOVERY_CANCEL_CNF*/
typedef struct
{
    UINT8	result;
    UINT8	total_number;
}T_AMOPENAT_BT_BM_DISCOVERY_CANCEL_CNF;
/*BT_HFG_CONNECT_IND*/
typedef struct
{
    T_AMOPENAT_BT_ADDR bt_addr;
    UINT32   connection_id;    
    UINT8         profile; //handle if take earphone role
}T_AMOPENAT_BT_HFG_CONNECT_IND;
/*BT_HFG_CONNECT_CNF*/
typedef struct
{
    UINT16                 result;
    T_AMOPENAT_BT_ADDR     bt_addr;
    UINT32                 connection_id;
    UINT8                  profile; //handle if take earphone role
}T_AMOPENAT_BT_HFG_CONNECT_CNF;

typedef struct
{
    UINT16        result;
    T_AMOPENAT_BT_ADDR bt_addr;
    UINT32   connection_id;
}T_AMOPENAT_BT_HFG_DISCONNECT_CNF;

typedef struct
{
    T_AMOPENAT_BT_ADDR    bt_addr;
    UINT32   connection_id;
}T_AMOPENAT_BT_HFG_DISCONNECT_IND;

typedef struct
{
  UINT8 call_director;   // 1 is incoming call, 2 is out going call
	UINT8 call_status;    // 0 is no call,1 is setup,2 is active
	UINT8 call_number[OPENAT_BT_MAX_PHONE_NUMBER];
	UINT8 call_number_length;
}T_AMOPENAT_BT_PHONE_CALL_INFO;
typedef struct
{
	UINT16			result;
	UINT8 	    connection_id;
}T_AMOPENAT_BT_HFG_SCO_CON_CNF;
typedef struct
{
	UINT16 	       result;
	UINT8 	       connection_id;
}T_AMOPENAT_BT_HFG_SCO_DISCON_CNF;

typedef struct
{
  BOOL connect;
}T_AMOPENAT_BT_HFG_SCO_INFO_IND;

typedef struct
{
	UINT8	 port;	/* virtual port number*/
	UINT8        result;
	UINT16       maxFrameSize; /*һ�δ�������ֽ���*/
	T_AMOPENAT_BT_ADDR addr;
}T_AMOPENAT_BT_SPP_CONN_IND;

typedef struct
{
	UINT8	             port;	/* virtual port number*/
  UINT8              result;  /* This is result field of this returned cnf msg */
	T_AMOPENAT_BT_ADDR addr;

}T_AMOPENAT_BT_SPP_DISCONN_IND;

typedef struct
{
	UINT8	 port;	/* virtual port number*/
 	UINT8         result;  /* This is result field of this returned cnf msg */	
	T_AMOPENAT_BT_ADDR addr;
}T_AMOPENAT_BT_SPP_DISCONN_CNF;

typedef struct
{
	UINT8	 port;	/* virtual port number*/
	UINT8         result;  /* This is result field of this returned cnf msg */
	UINT16        maxFrameSize; /*һ�δ�������ֽ���*/
	T_AMOPENAT_BT_ADDR addr;
}T_AMOPENAT_BT_SPP_CONN_CNF;

typedef struct
{
	UINT8	       port;	 /* virtual port number*/
	UINT32       dataLen;
	T_AMOPENAT_BT_ADDR addr;
}T_AMOPENAT_BT_SPP_DATA_IND_T;

typedef struct
{
	T_AMOPENAT_BT_ADDR addr;
	UINT8	         port;	 /* virtual port number*/
	UINT8          result;  /* This is result field of this returned cnf msg */
}T_AMOPENAT_BT_SPP_SEND_DATA_CNF;
typedef union
{
  T_AMOPENAT_BT_WRITE_SCANNABLE_MODE_CNF writeScannableModeCnf;
  T_AMOPENAT_BT_READ_LOCAL_ADDR_CNF      readLocalAddrCnf;
  T_AMOPENAT_BT_WRITE_LOCAL_NAME_CNF     writeLocalNameCnf;
  T_AMOPENAT_BT_LINK_CONNECT_ACCEPT_IND  linkConnectAcceptInd;
  T_AMOPENAT_BT_BM_PIN_CODE_INT          pinCodeInd;
  T_AMOPENAT_BT_BONDING_RESULT_IND       bondingResultInd;
  T_AMOPENAT_BT_DEBOND_CNF               debondCnf;
  T_AMOPENAT_BT_PBAP_BT_DATA_IND         pbapBtDataInd;
  T_AMOPENAT_BT_PBAP_CON_DISCON_INFO     pbapDisconInfo;
  T_AMOPENAT_BT_BM_DISCOVERY_RESULT_IND  discoveryResultInd;
  T_AMOPENAT_BT_BM_DISCOVERY_CNF         discoveryCnf;
  T_AMOPENAT_BT_BM_DISCOVERY_CANCEL_CNF  discoveryCancelCnf;
  T_AMOPENAT_BT_HFG_CONNECT_IND          hfgConnectInd;
  T_AMOPENAT_BT_HFG_CONNECT_CNF          hfgConnectCnf;
  T_AMOPENAT_BT_HFG_DISCONNECT_IND       hfgDisconnectInd;
  T_AMOPENAT_BT_HFG_DISCONNECT_CNF       hfgDisconnectCnf;
  T_AMOPENAT_BT_PHONE_CALL_INFO          phoneCallInfo;
  T_AMOPENAT_BT_HFG_SCO_CON_CNF          hfgScoConCnf;
  T_AMOPENAT_BT_HFG_SCO_DISCON_CNF       hfgScoDisConCnf;
  T_AMOPENAT_BT_HFG_SCO_INFO_IND         hfgScoInfoInd;
  T_AMOPENAT_BT_SPP_CONN_IND             sppConnInd;
  T_AMOPENAT_BT_SPP_DISCONN_IND          sppDiscConInd;
  T_AMOPENAT_BT_SPP_DISCONN_CNF          sppDiscConCnf;
  T_AMOPENAT_BT_SPP_CONN_CNF             sppConnCnf;
  T_AMOPENAT_BT_SPP_DATA_IND_T           sppDataInd;
  T_AMOPENAT_BT_SPP_SEND_DATA_CNF        sppSendDataCnf;
}U_AMOPENAT_BT_EVENT_PARAM;

typedef VOID (*OPENAT_BLUETOOTH_EVT_HANDLE)(E_AMOPENAT_BT_EVENT event,U_AMOPENAT_BT_EVENT_PARAM* param);


typedef struct
{
	T_AMOPENAT_BT_ADDR	  bd_addr;
	UINT8         linkKey[0x10];
	UINT8         KeyType;
	UINT32   	      cod;
}T_AMOPENAT_BT_DEV_PAIRED;

typedef struct 
{
	UINT32 		                devNum;
	T_AMOPENAT_BT_DEV_PAIRED	devInfo_Array[10];
}T_AMOPENAT_BT_DEV_INFO_ARRAY;

typedef struct 
{
  E_AMOPENAT_BT_SCANNABLE scannable;
  T_AMOPENAT_BT_NAME      btName;
  UINT32                  supportProfile; /*OPENAT_BT_SUPPORT_SPP_PROFILE*/
  T_AMOPENAT_BT_DEV_INFO_ARRAY pairedDevices;
  OPENAT_BLUETOOTH_EVT_HANDLE pMessageHandle;
}T_AMOPENAT_BT_PARAM;


typedef union
{
  struct _mgr_discory_req
  {
    UINT32	                cod;              /**/
    UINT8	                  inquiry_timeoutms; /*��ѯ��ʱ*/
    UINT8	                  inquiry_max_count; /*����ѯ����*/
    BOOL                  	discovery_with_name;
  }mgrDiscoryReq;
  struct _mgr_discory_cancle
  {
    UINT8 nullParm;
  }mgrDiscoryCancle;
  struct _mgr_set_scannable
  {
    E_AMOPENAT_BT_SCANNABLE scannable;
  }mgrSetScannable;
  struct _mgr_read_local_addr
  {
    UINT8 nullParm;
  }mgrReadLocalAddr;
  struct _mgr_write_local_name
  {
    T_AMOPENAT_BT_NAME localName;
  }mgrWriteLocalName;
  struct _bm_bonding_req
  {
    T_AMOPENAT_BT_ADDR remoteAddr;
    UINT8             sdap_len;
    UINT32            sdap_uuid[OPENAT_BT_MAX_SDAP_UUID_NO];
  }bmBondingReq;
  struct _bm_debond_req
  {
    T_AMOPENAT_BT_ADDR remoteAddr;
  }bmDebondReq;
  struct _pbap_con_req
  {
    T_AMOPENAT_BT_ADDR remoteAddr;
  }pbapConReq;
  struct _pbap_get_next_req
  {
    UINT8 nullParm;
  }pbapGetNextReq;
  struct _pbap_con_cancel
  {
    UINT8 nullParm;
  }pbapConCancel;
  struct _hfp_con_req
  {
    T_AMOPENAT_BT_ADDR remoteAddr;
  }hfpConReq;
  struct _hfp_dial_req
  {
    UINT8 call_number[OPENAT_BT_MAX_PHONE_NUMBER];
    UINT8 call_number_length;
  }hfpDialReq;
  struct _hfp_hungup_req
  {
    UINT8 nullParm;
  }hfpHungUpReq;
  struct _hfp_call_answer
  {
    UINT8 nullParam;
  }hfpCallAnswer;
  struct _hfp_send_dtmf
  {
    UINT8 assicNum;
  }hfpSendDTMF;
  struct _hfp_sco_audio_open_req
  {
    BOOL open;
  }hfpScoAudoReq;
  struct _hfp_disconnect_req
  {
    T_AMOPENAT_BT_ADDR remoteAddr;
    UINT32 connectId;
  }hfpDisconnectReq;
  struct _hfp_connect_sco_req
  {
    BOOL connect;
    UINT32 connect_id;
  }hfpConnectSCOReq;
  struct _hfg_set_mic_gain_req
  {
    INT8 anaGain; /*0 ~ 21dB*/
    INT8 adcGain; /*-12 ~ 16dB*/
    INT8 nsGain; /*1 ~ 16*/
  }hfgSetMicGainReq;
  struct _hfg_set_sleep_mode_req
  {
    BOOL quickSleepMode;
  }hfgSetSleepModeReq;
}U_AMOPENAT_BT_CMD_PARAM;

typedef union
{
  struct _mgr_link_accept
  {
    BOOL       accept;
    T_AMOPENAT_BT_ADDR remote_bd_addr;
  }mgrLinkAccept;
  struct _mgr_pin_code
  {
    T_AMOPENAT_BT_ADDR	remote_bd_addr;
    UINT8	pin_len;
    UINT8	pin_code[16];
  }mgrPinCode;
  
}U_AMOPENAT_BT_RSP_PARAM;
/*-\NEW\brezen\2013.12.30\��������ӿ�*/

typedef enum
{
    /// No error occured
    OPENAT_MEMD_ERR_NO = 0,

    /// An error occurred during the erase operation
    OPENAT_MEMD_ERR_ERASE = -10,

    /// An error occurred during the write operation
    OPENAT_MEMD_ERR_WRITE,

    /// This error occurs when a command requiring 
    /// sector aligned addresses as parameters is called with unaligned addresses. 
    /// (Those are 
    /// #memd_FlashErrors memd_FlashErase, #memd_FlashLock and #memd_FlashUnlock)
    OPENAT_MEMD_ERR_ALIGN,

    /// An erase or write operation was attempted on a protected sector
    OPENAT_MEMD_ERR_PROTECT,
    /// erase suspend.
    OPENAT_MEMD_ERR_SUSPEND,
    /// device is busy.
    OPENAT_MEMD_ERR_BUSY,
    
}E_AMOPENAT_MEMD_ERR;

/*+\NEW\RUFEI\2014.4.4\�����ⲿ���Ź����ýӿ�*/
#ifdef DSS_CONFIG_EX_WATCH_DOG
/*CUSTOM*/
typedef enum
{
    OPENAT_CUST_EX_WATCH_DOG_MODE_DEFAULT,
    OPENAT_CUST_EX_WATCH_DOG_MODE_CUST,

    OPENAT_CUST_EX_WATCH_DOG_MODE_NUM
}E_OPEANT_CUST_EX_WATCH_DOG_MODE;

typedef void (*CUSHandle)(void);

typedef union
{
    struct _default_mode_cfg
    {
        E_AMOPENAT_GPIO_PORT port;
        CUSHandle                      handle; /*reset�ӿ�ʹ��*/
    }defaultModeCfg;
    struct _cust_mode_cfg
    {
        CUSHandle                      handle;/*reset�ӿ�ʹ��*/
    }custModeCfg;
}U_AMOPENAT_EX_WATCH_DOG_CFG;
#endif //DSS_CONFIG_EX_WATCH_DOG
/*-\NEW\RUFEI\2014.4.4\�����ⲿ���Ź����ýӿ�*/

/*+\NEW\RUFEI\2014.8.20\����gps�ӿ�ʵ��*/
typedef struct
{
    E_AMOPENAT_UART_PORT port;
    T_AMOPENAT_UART_PARAM cfg;
}T_AMOPENAT_RDAGPS_UART_CFG;

typedef struct
{
    E_AMOPENAT_I2C_PORT port;
}T_AMOPENAT_RDAGPS_I2C_CFG;

typedef struct
{
    E_AMOPENAT_GPIO_PORT pinPowerOnPort;
    E_AMOPENAT_GPIO_PORT pinResetPort;
    E_AMOPENAT_GPIO_PORT pinBpWakeupGpsPort;
    BOOL                             pinBpWakeupGpsPolarity;
    E_AMOPENAT_GPIO_PORT pinGpsWakeupBpPort;
    BOOL                             pinGpsWakeupBpPolarity;
}T_AMOPENAT_RDAGPS_GPS_CFG;
typedef struct
{
    T_AMOPENAT_RDAGPS_I2C_CFG    i2c;
    T_AMOPENAT_RDAGPS_GPS_CFG   gps;
}T_AMOPENAT_RDAGPS_PARAM;
/*-\NEW\RUFEI\2014.8.20\����gps�ӿ�ʵ��*/

/*+\NEW\RUFEI\2015.8.31\Update key init*/
/*cfg*/

typedef enum E_AMOPENAT_MOUDLE_TAG{
    KEY_MOUDLE,
    GPIO_MOUDLE,
    UART_MOUDLE,
    I2C_MOUDLE,
    SPI_MOUDLE,

    MOUDLE_MAX
}E_AMOPENAT_MOUDLE;


typedef union{
  struct pin_key{
    E_AMOPENAT_KEYPAD_TYPE keyMode;
    UINT32           row;
   //keyin 
    UINT32           col;
   //keyout
  }key;
}U_AMOPENAT_MOUDLE_CFG;
/*-\NEW\RUFEI\2015.8.31\Update key init*/

//+TTS, panjun 160326.
typedef enum enum_AMOPENAT_TTSPLY_STATE
{
    OPENAT_TTSPLY_STATE_IDLE = 0,
    OPENAT_TTSPLY_STATE_PLAY = 1,
    OPENAT_TTSPLY_STATE_PAUSE = 2,
    OPENAT_TTSPLY_STATE_STOP = 3,
    OPENAT_TTSPLY_STATE_END_PLAYING = 4,
    OPENAT_TTSPLY_STATE_ABNORMAL_EXIT = 5,
    OPENAT_TTSPLY_STATE_UNKOWN = 255
}AMOPENAT_TTSPLY_STATE;

typedef enum  enum_AMOPENAT_TTSPLY_ERROR {
    OPENAT_TTSPLY_ERR_NO = 0,
    OPENAT_TTSPLY_ERR_BUFFER_OVERFLOW = -1,
    OPENAT_TTSPLY_ERR_BUFFER_UNDERFLOW = -2,
    OPENAT_TTSPLY_ERR_EVENT_NONE = -3,
    OPENAT_TTSPLY_ERR_EVENT_DATA_REQUEST = -4,
    OPENAT_TTSPLY_ERR_EVENT_ERROR = -5,
    OPENAT_TTSPLY_ERR_RECOVER = -6,
    OPENAT_TTSPLY_ERR_FAILED = -7,
    OPENAT_TTSPLY_ERR_INVALID_RESOULTION = -8,
    OPENAT_TTSPLY_ERR_UNSUPPORTED_FORMAT = -9,
    OPENAT_TTSPLY_ERR_INVALID_BITSTREAM = -10,
    OPENAT_TTSPLY_ERR_MEMORY_INSUFFICIENT = -11,
    OPENAT_TTSPLY_ERR_INSUFFICIENT_MEMORY = -12,
    OPENAT_TTSPLY_ERR_INVALID_FORMAT = -13,
    OPENAT_TTSPLY_ERR_NOT_SUPPORTED = -14,
    OPENAT_TTSPLY_ERR_INVALID_PARAMETER = -15,
    OPENAT_TTSPLY_ERR_TIME_EXPIRED = -16,
    OPENAT_TTSPLY_ERR_LICENCE = -17,
    OPENAT_TTSPLY_ERR_INPUT_PARAM = -18,
    OPENAT_TTSPLY_ERR_TOO_MORE_TEXT = -19,
    OPENAT_TTSPLY_ERR_NOT_INIT = -20,
    OPENAT_TTSPLY_ERR_OPEN_DATA = -21,
    OPENAT_TTSPLY_ERR_NO_INPUT = -22,
    OPENAT_TTSPLY_ERR_MORE_TEXT = -23,
    OPENAT_TTSPLY_ERR_INPUT_MODE = -24,
    OPENAT_TTSPLY_ERR_ENGINE_BUSY = -25,
    OPENAT_TTSPLY_ERR_BE_INITIALIZED = -26,
    OPENAT_TTSPLY_ERR_PCM_OPEN_FAIL = -27,         		           
    OPENAT_TTSPLY_ERR_MEMORY = -28,	     
    OPENAT_TTSPLY_ERR_DONOTHING = -29,		   
    OPENAT_TTSPLY_ERR_PLAYING = -30,	      
    OPENAT_TTSPLY_ERR_AUDIO_DEVICE = -31,
    OPENAT_TTSPLY_ERR_RINGQUEUE_MEMORY = -32,
    OPENAT_TTSPLY_ERR_UNKOWN = -255,	               
} AMOPENAT_TTSPLY_ERROR;

typedef struct  tag_AMOPENAT_TTSPLY_PARAM
{
      INT16    volume;
      INT16    speed;
      INT16    pitch;
      UINT16  codepage;
      UINT8    digit_mode;
      UINT8    punc_mode;
      UINT8    tag_mode;
      UINT8    wav_format;
      UINT8    eng_mode;
}AMOPENAT_TTSPLY_PARAM;

typedef struct  tagAMOPENAT_TTSPLY
{
      WCHAR *text;
      UINT32  text_size;
      U8 spk_vol;
}AMOPENAT_TTSPLY;
//-TTS, panjun 160326.


typedef enum
{
    OPENAT_GPS_UART_MODE_RAW_DATA = 0,         /*Just need raw data*/
    OPENAT_GPS_UART_MODE_LOCATION,             /*Just need location*/
    OPENAT_GPS_UART_MODE_LOCATION_WITH_QOP     /*Need AGPS data with Qop*/
}E_AMOPENAT_GPS_WORK_MODE;

/*Data type for callback function of NMEA data or parserred data*/
typedef enum
{
    OPENAT_GPS_PARSER_RAW_DATA = 0,    /*Raw data of NMEA*/
    OPENAT_GPS_PARSER_NMEA_GGA,        /*Data structure of GGA info*/
    OPENAT_GPS_PARSER_NMEA_GLL,        /*Data structure of GLL info*/
    OPENAT_GPS_PARSER_NMEA_GSA,        /*Data structure of GSA info*/
    OPENAT_GPS_PARSER_NMEA_GSV,        /*Data structure of GSV info*/
    OPENAT_GPS_PARSER_NMEA_RMC,        /*Data structure of RMC info*/
    OPENAT_GPS_PARSER_NMEA_VTG,        /*Data structure of VTG info*/
    OPENAT_GPS_PARSER_NMEA_GAGSA,       /*Data structure of GAGSA info*/
    OPENAT_GPS_PARSER_NMEA_GAGSV,       /*Data structure of GAGSV info*/
    OPENAT_GPS_PARSER_NMEA_GLGSA,       /*Data structure of GLGSA info*/
    OPENAT_GPS_PARSER_NMEA_GLGSV,       /*Data structure of GLGSV info*/
    OPENAT_GPS_PARSER_NMEA_SENTENCE,
    OPENAT_GPS_UART_EVENT_VPORT_LOST,  /*Virtual port is lost, maybe bluetooth connection is break(not support current)*/
    OPENAT_GPS_SHOW_AGPS_ICON,
    OPENAT_GPS_HIDE_AGPS_ICON,
    OPENAT_GPS_PARSER_NMEA_ACC,        /*Data structure of ACCURACY info*/
    OPENAT_GPS_PARSER_NMEA_END,
    OPENAT_GPS_OPEN_IND,
    OPENAT_GPS_UART_RAW_DATA,
    OPENAT_GPS_PARSER_MA_STATUS = 255
}E_AMOPENAT_DATA_TYPE;
typedef void (*F_GPS_CB)(E_AMOPENAT_DATA_TYPE type, VOID *buffer, UINT32 length);

typedef enum
{
    OPENAT_GPS_UART_GPS_WARM_START = 0,        /*Let GPS do warm start*/
    OPENAT_GPS_UART_GPS_HOT_START,             /*Let GPS do hot start*/
    OPENAT_GPS_UART_GPS_COLD_START,            /*Let GPS do cold start*/
    OPENAT_GPS_UART_GPS_VERSION,
    OPENAT_GPS_UART_GPS_ENABLE_DEBUG_INFO,    
    OPENAT_GPS_UART_GPS_SWITCH_MODE_MA,
    OPENAT_GPS_UART_GPS_SWITCH_MODE_MB,
    OPENAT_GPS_UART_GPS_SWITCH_MODE_NORMAL,
    OPENAT_GPS_UART_GPS_QUERY_POS, //8
    OPENAT_GPS_UART_GPS_QUERY_MEAS, //9
    OPENAT_GPS_UART_GPS_CLEAR_NVRAM,           /*Clear GPS NVRAM*/
    OPENAT_GPS_UART_GPS_AGPS_START,            /*Clear GPS data*/
    OPENAT_GPS_UART_GPS_SLEEP,                 /*Let GPS chip goto sleep mode*/
    OPENAT_GPS_UART_GPS_STOP,                  /*Let GPS chip stop*/
    OPENAT_GPS_UART_GPS_WAKE_UP,               /*Let GPS chip wake up from sleep mode*/
    OPENAT_GPS_UART_GPS_DUMMY = -1
}T_OPENAT_GPS_CMD;

/*+\NEW \zhuwangbin\2020.01.06\����Զ������������*/
typedef enum
{
  OPENAT_UPGRADE_INVALID_URL = 1000,
  OPENAT_UPGRADE_NET_ERROR,
  OPENAT_UPGRADE_SERVER_CONNECT_ERROR,
  OPENAT_UPGRADE_INVALID_FILE,
  OPENAT_UPGRADE_SERVER_RESPONSE_ERROR,
  OPENAT_UPGRADE_WRITE_FLASH_ERROR,
  OPENAT_UPGRADE_ERROR,
  
}OPENAT_UPGRADE_ERR;
/*-\NEW \zhuwangbin\2020.01.06\����Զ������������*/

typedef enum
{
  OPENAT_OTA_SUCCESS = 0,
  OPENAT_OTA_ERROR_FLASH_NOT_SUPPORT = -100,
  OPENAT_OTA_ERROR_NO_MEMORY,
  OPENAT_OTA_ERROR_FBF_ERROR,
  OPENAT_OTA_ERROR_FW_NOT_ENOUGH,
  OPENAT_OTA_ERROR_VERIFY_ERROR,
  OPENAT_OTA_ERROR_WRITE,
}E_OPENAT_OTA_RESULT;

typedef enum
{
    OPENAT_OTP_SUCCESS,
    OPENAT_OTP_INVALID_PARAM,
    OPENAT_OTP_LOCKED,
    OPENAT_OTP_WRITE_ERROR,
    OPENAT_OTP_READ_ERROR,
    OPENAT_OTP_LOCK_ERROR,
    OPENAT_OPT_NULL_DATA,
    OPENAT_OPT_DATA_ERROR
}E_OPENAT_OTP_RET;


typedef enum
{
    OPENAT_MODULE_HW_AFF,
    OPENAT_MODULE_HW_A10,
    OPENAT_MODULE_HW_A11,
    OPENAT_MODULE_HW_A12,
    OPENAT_MODULE_HW_A13,
    OPENAT_MODULE_HW_A14,

}E_OPEANT_MODULE_HWVER;

typedef enum
{
    OPENAT_MODULE_Air720FF,        
    OPENAT_MODULE_Air720H,
    
    OPENAT_MODULE_Air720,
    OPENAT_MODULE_Air720D,
    OPENAT_MODULE_Air720T,
    OPENAT_MODULE_Air720U,
    OPENAT_MODULE_Air720M,
    OPENAT_MODULE_Air720G,
    OPENAT_MODULE_Air720GM,
    OPENAT_MODULE_Air720GL
}E_OPENAT_MODULE_TYPE;

typedef struct
{
    E_OPENAT_MODULE_TYPE type;
    E_OPEANT_MODULE_HWVER hw;
}T_OPENAT_MODULE;
/*+\wj\new\2020.10.16\���rtmp����ATָ���luaʹ�ýӿ�*/
typedef enum{
	OPNEAT_RTMP_PLAY_OK,
	OPNEAT_RTMP_PLAY_ERR,
	OPNEAT_RTMP_STOP_OK,
	OPNEAT_RTMP_STOP_ERR,
	OPNEAT_RTMP_RECEIVE_TIMEOUT,
}E_OPENAT_RTMP_RESULT_CODE;


typedef void (*OPENAT_RTMP_CB)(E_OPENAT_RTMP_RESULT_CODE result_code);
/*-\wj\new\2020.10.16\���rtmp����ATָ���luaʹ�ýӿ�*/
/*----------------------------------------------*
 * �ⲿ����˵��                                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �ⲿ����ԭ��˵��                             *
 *----------------------------------------------*/
extern void lua_fm_set_loopback(UINT32 on, void* arg );

// +panjun, 2015.09.16, Add some asynchronous flags for LUA task.
void lua_sync_mmi_wait_event(UINT32 evt);
void lua_sync_mmi_set_event(UINT32 evt);
// -panjun, 2015.09.16, Add some asynchronous flags for LUA task.

/*+\NEW\RUFEI\2015.8.31\Update key init*/
 BOOL OPENAT_CFGPIN(E_AMOPENAT_MOUDLE moudle, U_AMOPENAT_MOUDLE_CFG *cfg);
/*-\NEW\RUFEI\2015.8.31\Update key init*/

VOID OPENAT_InitGPS(VOID);

BOOL OPENAT_OpenGPS(E_AMOPENAT_GPS_WORK_MODE mode, F_GPS_CB cb);

BOOL OPENAT_CloseGPS(VOID);

BOOL OPENAT_WriteGPS(VOID* buffer, UINT32 length, UINT32 *write);
BOOL OPENAT_SendCmdGPS(T_OPENAT_GPS_CMD cmd);

E_OPENAT_OTP_RET OPENAT_muid_write(char* muidStr, UINT32 muidStrlen);
E_OPENAT_OTP_RET OPENAT_muid_read(char* muidStrOut);

T_OPENAT_MODULE OPENAT_GetModuleType(void);


/*----------------------------------------------*
 * �ڲ�����ԭ��˵��                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ȫ�ֱ���                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ģ�鼶����                                   *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ��������                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �궨��                                       *
 *----------------------------------------------*/


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif // __cplusplus

#endif // __AM_OPENAT_DRV_H__

