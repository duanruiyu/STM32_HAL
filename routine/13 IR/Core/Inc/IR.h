#ifndef _IRROMTE_H_
#define _IRROMTE_H_

#include "main.h"


/*******************************************************
*
*�˴�Ϊ��������������룬���ں�̵Ŀ���
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

//����ȫ�ֱ���
extern uint32_t receive_Code;	  	//����һ��32λ���ݱ��������������
extern uint8_t  receive_Flag;   	//����һ��8λ���ݵı���������ָʾ���ձ�־


#endif
