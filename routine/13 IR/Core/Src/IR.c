#include "IR.h"
#include "tim.h"

uint32_t receive_Code;	  //����һ��32λ���ݱ��������������
uint8_t  receive_Flag;   	//����һ��8λ���ݵı���������ָʾ���ձ�־



/*******************************************************************************
* �� �� ��         : IR_HighLevelPeriod
* ��������		   : �ߵ�ƽ����ʱ�䣬����¼��ʱ�䱣����t�з��أ�����һ�δ�Լ20us 
* ��    ��         : ��
* ��    ��         : t
*******************************************************************************/
uint8_t IR_HighLevelPeriod()
{
	uint8_t t=0;
	while(HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_15)==1)  //�ߵ�ƽ
	{
		t++;
		delay_us(20);
		if(t>=250) return t;		//��ʱ���
	}
	return t;
}

/******************************************************************************
*
*�˴�ΪPG15�ⲿ�жϵĻص����������ڽ����źű���
*
*******************************************************************************/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)	//����ң���ⲿ�ж�
{
	uint8_t Tim=0,Ok=0,Data,Num=0;

   while(1)
   {
	   	if(HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_15)==1)
		{
			 Tim = IR_HighLevelPeriod();//��ô˴θߵ�ƽʱ��

			 if(Tim>=250) break;//�������õ��ź�

			 if(Tim>=200 && Tim<250)
			 {
			 	Ok=1;//�յ���ʼ�ź�
			 }
			 else if(Tim>=60 && Tim<90)
			 {
			 	Data=1;//�յ����� 1
			 }
			 else if(Tim>=10 && Tim<50)
			 {
			 	Data=0;//�յ����� 0
			 }

			 if(Ok==1)
			 {
			 	receive_Code <<= 1;
				receive_Code += Data;

				if(Num>=32)
				{
					receive_Flag=1;
				  break;
				}
			 }

			 Num++;
		}
   }
}

