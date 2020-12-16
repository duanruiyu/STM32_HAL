#ifndef _IRROMTE_H_
#define _IRROMTE_H_

#include "main.h"


/*******************************************************
*
*此处为定义各个按键编码，用于后继的开发
*
********************************************************/
#define key_0 00ff6897
#define key_1 00ff30cf
#define key_2 00ff18e7
#define key_3 00ff7a85
#define key_4 00ff10ef
#define key_5 00ff38c7
#define key_6 00ff5aa5
#define key_7 00ff42bd
#define key_8 00ff4ab5
#define key_9 00ff52ad
#define key_V_up 00ff906f
#define key_V_down 00ffa857
#define key_Power 00ffa25d
#define key_Mode 00ff629d
#define key_mute 00ffe21d
#define key_Left 00ff02fd
#define key_Right 00ffc23d
#define key_EQ 00ffe01f
#define key_RPT 00ff9867
#define key_U_OR_SD 00ffb04f
#define key_Speed 00ff22dd

uint8_t IR_HighLevelPeriod(void);

//定义全局变量
extern uint32_t receive_Code;	  	//定义一个32位数据变量，保存接收码
extern uint8_t  receive_Flag;   	//定义一个8位数据的变量，用于指示接收标志


#endif
