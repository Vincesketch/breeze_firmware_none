/*******************************************************************************
Copyright (C), 2016-2016, Team MicroDynamics. 

Filename:    stm32f10x_system_battery.h
Author:      maksyuki
Version:     1.0
Date:        2016.8.14
Description: declare the battery operation function
Others:      none
Function List:
             1. extern int  Battery_GetAD(void);
             2. extern int  Battery_GetTemp(void);
             3. extern void Battery_Check(void);
             4. extern void Battery_CheckInit(void);
             5. extern u16  Battery_GetADC(u8 ch);
             6. extern u16  Battery_GetADCAverage(u8 ch, u8 times);
History:     none
*******************************************************************************/

#ifndef __STM32F10X_SYSTEM_BATTERY_H__
#define __STM32F10X_SYSTEM_BATTERY_H__

#include "stm32f10x.h"

#define BAT_CHECK_PERIOD  5000     /*unit: ms*/
#define BAT_ALARM_VAL     3.65     /*这是电机未开启的报警电压值，开启电机之后，电池电压会下降0.3-0.4v左右*/
#define BAT_CHARGE_VAL    1.0      /*charge battery val unit :v*/
#define BAT_OVERDIS_VAL   3.15     /*过放保护电压值，持续低于该电压则自动降落，over discharge protect value*/

/*电压信息结构体*/
typedef struct
{
    int    ADVal;             /*电压AD值*/
    int    OverDischargeCnt;  /*过放保护计数，防止误判*/
    char   AlarmFlag;         /*报警位*/
    char   ChargeState;       /*充电状态*/
    float  RealVal;           /*电压实际值*/
    float  TestVal;           /*电池的实际测量电压值，用万用表测得*/
    float  ADRefVal;          /*AD参考源电压，这里是单片机供电电压，一般在3.3V左右，要实测*/
    float  ADInputVal;        /*AD采样输入电压--->R15和R17相连的焊盘电压*/
    float  Factor;            /*计算电压值系数，用于电压校准*/
}Bat_TypedefStructure;

extern Bat_TypedefStructure Battery;  /*实例化一个电压信息结构体*/

extern int  Battery_GetAD(void);
extern int  Battery_GetTemp(void);
extern void Battery_Check(void);
extern void Battery_CheckInit(void);
extern u16  Battery_GetADC(u8 ch);
extern u16  Battery_GetADCAverage(u8 ch, u8 times);

#endif